/*******************************************************************************
 * Copyright (c) 2011 protos software gmbh (http://www.protos.de).
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * CONTRIBUTORS:
 * 		Thomas Schuetz (initial contribution)
 *
 *******************************************************************************/
#define _GNU_SOURCE

#include "etMessageService.h"
#include "base/etMemory.h"
#include <sched.h>
#include "etSystemProtocol.h"
#include "debugging/etLogger.h"
#include "debugging/etMSCLogger.h"
#include "modelbase/etActor.h"
#include "/home/eselab/eclipse-workspace/org.eclipse.etrice.template.c/src-gen/TemplateModel/ADASMessage.h"
static void etMessageService_timerCallback(void* data);
static void etMessageService_deliverAllMessages(etMessageService* self);
static void etMessageService_deliverAllMessages_kkr(etMessageService* self);

conveyMsg* cpuMsgServiceInfo[16];//added by kkr 19.03.14

/*
 * initialize message service with all needed data and initialize message queue and message pool
 *
 */
void conveyMsgService_init(void){//added by kkr for information on performing scenario for each core 19.03.14
	for(int i=0; i<8; i++){
		cpuMsgServiceInfo[i] = malloc(sizeof(conveyMsg));
		etMutex_construct(&(cpuMsgServiceInfo[i]->servermutex));//added by kkr 19.03.14
	}
}

void etMessageService_init(etMessageService* self, etUInt8* buffer,
		etUInt16 maxBlocks, etUInt16 blockSize, etStacksize stacksize,
		etPriority priority, etTime interval,
		etDispatcherReceiveMessage msgDispatcher,
		etMessageService_execmode execmode) {
	ET_MSC_LOGGER_SYNC_ENTRY("etMessageService", "init")

			/* copy init data to self */
	self->messageBuffer.buffer = buffer;
	self->messageBuffer.maxBlocks = maxBlocks;
	self->messageBuffer.blockSize = blockSize;
	self->msgDispatcher = msgDispatcher;
	self->execmode = execmode;
	/* init queue and pool */
	etMessageQueue_init(&(self->messagePool)); /* the pool is also a queue*/
	etMessageQueue_init(&(self->messageQueue));
	etMessageQueue_init(&(self->externalQueue));//added by kkr
	etMessageService_initMessagePool(self);

	/* init mutexes and spinlock and semaphores */
	etMutex_construct(&(self->poolMutex));
	etMutex_construct(&(self->queueMutex));

	eseSpinlock_construct(&(self->pooleseSpinlock));//added by kkr
	eseSpinlock_construct(&(self->queueeseSpinlock));//added by kkr
	etSema_construct(&(self->executionSemaphore));

	/* init high prio functions */
	self->highPrioFuncRoot = NULL;

	/* init thread */
	etThread_construct(&self->thread, stacksize, priority, "MessageService",
			(etThreadFunction) etMessageService_deliverAllMessages, self); //added cpunum by kkr 2018.06.30

	if (execmode == EXECMODE_POLLED || execmode == EXECMODE_MIXED) {
		/* init timer */
		etTimer_construct(&self->timer, &interval,
				etMessageService_timerCallback, self);
	}

	ET_MSC_LOGGER_SYNC_EXIT
}
void etMessageService_init_kkr(etMessageService* self, etUInt8* buffer,
		etUInt16 maxBlocks, etUInt16 blockSize, etStacksize stacksize,
		etPriority priority, etTime interval,
		etDispatcherReceiveMessage msgDispatcher,
		etMessageService_execmode execmode, etCpunum cpunum) { //added cpunum by kkr 2018.06.30
	ET_MSC_LOGGER_SYNC_ENTRY("etMessageService", "init")

			/* copy init data to self */
	self->messageBuffer.buffer = buffer;
	self->messageBuffer.maxBlocks = maxBlocks;
	self->messageBuffer.blockSize = blockSize;
	self->msgDispatcher = msgDispatcher;
	self->execmode = execmode;

	//self->thread.myMsgService=self;
	/* init queue and pool */
	etMessageQueue_init(&(self->messagePool)); /* the pool is also a queue*/
	etMessageQueue_init(&(self->messageQueue));
	etMessageQueue_init(&(self->externalQueue));//added by kkr
	etMessageService_initMessagePool(self);

	/* init mutexes and spinlock and semaphores */

	etMutex_construct(&(self->poolMutex));
	etMutex_construct(&(self->queueMutex));
	eseSpinlock_construct(&(self->pooleseSpinlock));//added by kkr
	eseSpinlock_construct(&(self->queueeseSpinlock));//added by kkr
	etSema_construct(&(self->executionSemaphore));

	/* init high prio functions */
	self->highPrioFuncRoot = NULL;

	/* init thread */
	etThread_construct_kkr(&self->thread, stacksize, priority, "MessageService",
			(etThreadFunction) etMessageService_deliverAllMessages_kkr, self,//revised etMessageService_deliverAllMessages_kkr by kkr
			cpunum); //added cpunum by kkr 2018.06.30

	if (execmode == EXECMODE_POLLED || execmode == EXECMODE_MIXED) {
		/* init timer */
		etTimer_construct(&self->timer, &interval,
				etMessageService_timerCallback, self);
	}

	ET_MSC_LOGGER_SYNC_EXIT
}
void etMessageService_start(etMessageService* self) {
	ET_MSC_LOGGER_SYNC_ENTRY("etMessageService", "start")
		etThread_start(&(self->thread));
	if (self->execmode == EXECMODE_POLLED || self->execmode == EXECMODE_MIXED) {
		etTimer_start(&self->timer);
	}
	ET_MSC_LOGGER_SYNC_EXIT
}
void etMessageService_start_kkr(etMessageService* self) { //added cpunum by kkr 2020.01.15
	ET_MSC_LOGGER_SYNC_ENTRY("etMessageService", "start")
		etThread_start_kkr(&(self->thread));
	if (self->execmode == EXECMODE_POLLED || self->execmode == EXECMODE_MIXED) {
		etTimer_start(&self->timer);
	}
	ET_MSC_LOGGER_SYNC_EXIT
}
void etMessageService_stop(etMessageService* self) {
	etSystemProtocolConjPort port;
	ET_MSC_LOGGER_SYNC_ENTRY("etMessageService", "stop")

	if (self->execmode == EXECMODE_POLLED || self->execmode == EXECMODE_MIXED) {
		etTimer_stop(&self->timer);
	}

	/* create a temporary port struct and send the terminate message */
	port.localId = 0;
	port.msgService = self;
	port.peerAddress = MESSAGESERVICE_ADDRESS;
	etSystemProtocolConjPort_terminate(&port);

	ET_MSC_LOGGER_SYNC_EXIT
}

void etMessageService_destroy(etMessageService* self) {
	ET_MSC_LOGGER_SYNC_ENTRY("etMessageService", "destroy")
			etMutex_destruct(&(self->poolMutex));
			etMutex_destruct(&(self->queueMutex));
			eseSpinlock_destruct(&(self->pooleseSpinlock));//added by kkr
			eseSpinlock_destruct(&(self->queueeseSpinlock));//added by kkr
		etSema_destruct(&(self->executionSemaphore));
	ET_MSC_LOGGER_SYNC_EXIT
}

/*
 * initialize message pool with block buffer
 * all blocks are added to pool
 */
void etMessageService_initMessagePool(etMessageService* self) {
	ET_MSC_LOGGER_SYNC_ENTRY("etMessageService", "initMessagePool")
		etInt16 i;

	for (i = 0; i < self->messageBuffer.maxBlocks; i++) {
		etMessage* block = (etMessage*) &self->messageBuffer.buffer[i* self->messageBuffer.blockSize];
		etMessageQueue_push(&self->messagePool, block);
	}
	etMessageQueue_resetLowWaterMark(&self->messagePool);
	ET_MSC_LOGGER_SYNC_EXIT
}
void etMessageService_pushMessage_kkr(etMessageService* self, etMessage* msg) { //added by kkr for internalQ
	ET_MSC_LOGGER_SYNC_ENTRY("etMessageService", "pushMessage")
	//call pthread_setparam only when the destination thread priority is lower than VAL prior(revise)
	struct timespec time;
	clock_gettime(CLOCK_MONOTONIC,&time);
	etMessageQueue_push(&self->messageQueue, msg);
	etSema_wakeup(&self->executionSemaphore);
	ET_MSC_LOGGER_SYNC_EXIT
}
void etMessageService_pushMessage(etMessageService* self, etMessage* msg) {
	ET_MSC_LOGGER_SYNC_ENTRY("etMessageService", "pushMessage")
	etMutex_enter(&self->queueMutex);
	struct timespec time;
	clock_gettime(CLOCK_MONOTONIC,&time);
	FILE *fp3 = fopen("externalQ.txt","a");//added by kkr for time tracing
	fprintf(fp3,"%d,instanceID,starttime,%.6f\n",(int)self->thread.osData,(((1.0e+9*time.tv_sec)+time.tv_nsec)/1.0e+6));
	fclose(fp3);
	etMessageQueue_push(&self->externalQueue,msg);
	etSema_wakeup(&self->executionSemaphore);
	etMutex_leave(&self->queueMutex);

	ET_MSC_LOGGER_SYNC_EXIT
}

etMessage* etMessageService_popMessage_kkr(etMessageService* self) {//added by kkr
	etMessage* msg;
	ET_MSC_LOGGER_SYNC_ENTRY("etMessageService", "popMessage")
	if(etMessageQueue_isNotEmpty(&self->messageQueue)){
		msg = etMessageQueue_pop(&self->messageQueue);
	}

	else {
		etMutex_enter(&self->queueMutex);
		msg = etMessageQueue_pop(&self->externalQueue);
		etMutex_leave(&self->queueMutex);
	}

	ET_MSC_LOGGER_SYNC_EXIT
	return msg;
}
etMessage* etMessageService_popMessage(etMessageService* self) {
	etMessage* msg;

	ET_MSC_LOGGER_SYNC_ENTRY("etMessageService", "popMessage")
	etMutex_enter(&self->queueMutex);
	msg = etMessageQueue_pop(&self->externalQueue);//revised by kkr
	etMutex_leave(&self->queueMutex);
	ET_MSC_LOGGER_SYNC_EXIT
	return msg;
}
etMessage* etMessageService_getMessageBuffer(etMessageService* self,
		etUInt16 size) {
	ET_MSC_LOGGER_SYNC_ENTRY("etMessageService", "getMessageBuffer")
					etMutex_enter(&self->poolMutex);


	if (size <= self->messageBuffer.blockSize) {
		if (self->messagePool.size > 0) {
			etMessage* msg = etMessageQueue_pop(&self->messagePool);
					etMutex_leave(&self->poolMutex);

			ET_MSC_LOGGER_SYNC_EXIT
			return msg;
		} else {
			etLogger_logErrorF("etMessageService_getMessageBuffer: message pool empty: %d",
					etMessageService_getMessagePoolLowWaterMark(self));
		}
	} else {
		etLogger_logErrorF(
				"etMessageService_getMessageBuffer: message too big: %d, blockSize: %d", size,
				self->messageBuffer.blockSize);
	}
			etMutex_leave(&self->poolMutex);

	ET_MSC_LOGGER_SYNC_EXIT
	return NULL;
}

void etMessageService_returnMessageBuffer(etMessageService* self,
		etMessage* buffer) {
	ET_MSC_LOGGER_SYNC_ENTRY("etMessageService", "returnMessageBuffer")
	etMutex_enter(&self->poolMutex);
	etMessageQueue_push(&self->messagePool, buffer);
	etMutex_leave(&self->poolMutex);
	ET_MSC_LOGGER_SYNC_EXIT
}

void etMessageService_registerHighPrioFunc(etMessageService* self,
		etHighPrioFunc *func) {
	ET_MSC_LOGGER_SYNC_ENTRY("etMessageService", "registerHighPrioFunc")
		func->next = self->highPrioFuncRoot;
	self->highPrioFuncRoot = func;
	ET_MSC_LOGGER_SYNC_EXIT
}

void etMessageService_unregisterHighPrioFunc(etMessageService* self,
		etHighPrioFunc *func) {
	ET_MSC_LOGGER_SYNC_ENTRY("etMessageService", "unregisterHighPrioFunc")
		etHighPrioFunc *highPrioFunc;
	if (self->highPrioFuncRoot == func) {
		self->highPrioFuncRoot = self->highPrioFuncRoot->next;
	} else {
		highPrioFunc = self->highPrioFuncRoot;
		while (highPrioFunc != NULL) {
			if (highPrioFunc->next == func) {
				highPrioFunc->next = highPrioFunc->next->next;
				break;
			}
			highPrioFunc = highPrioFunc->next;
		}
	}
	ET_MSC_LOGGER_SYNC_EXIT
}

static void etMessageService_callHighPrioFunc(etMessageService* self) {
	ET_MSC_LOGGER_SYNC_ENTRY("etMessageService", "callHighPrioFunc")
		etHighPrioFunc *highPrioFunc;
	highPrioFunc = self->highPrioFuncRoot;
	while (highPrioFunc != NULL) {
		(*(highPrioFunc->func))(highPrioFunc->param);
		highPrioFunc = highPrioFunc->next;
	}
	ET_MSC_LOGGER_SYNC_EXIT
}
static void etMessageService_deliverAllMessages(etMessageService* self) {//revised by kkr
	ET_MSC_LOGGER_SYNC_ENTRY("etMessageService", "deliverAllMessages")
		{
		etBool cont = ET_TRUE;
		while (cont) {
			etMessageService_callHighPrioFunc(self);

			while ((etMessageQueue_isNotEmpty(&self->externalQueue)) && cont) {
				etMessage* msg = etMessageService_popMessage(self);
				if(msg->globalcheck==1){
					eseSpinlock_enter(&self->queueeseSpinlock);
					if (!self->msgDispatcher(msg))
						cont = ET_FALSE;
					eseSpinlock_leave(&self->queueeseSpinlock);
				}
				else{
					etMutex_enter(&self->queueMutex);
					if (!self->msgDispatcher(msg))
						cont = ET_FALSE;
					etMutex_leave(&self->queueMutex);
				}
				etMessageService_returnMessageBuffer(self, msg);
				etMessageService_callHighPrioFunc(self);
			}
			if (cont)
				etSema_waitForWakeup(&self->executionSemaphore);
		}
		}
	ET_MSC_LOGGER_SYNC_EXIT
}
static void etMessageService_deliverAllMessages_kkr(etMessageService* self) {//added by kkr
	ET_MSC_LOGGER_SYNC_ENTRY("etMessageService", "deliverAllMessages")
		{
		etBool cont = ET_TRUE;
		while (cont) {
			etMessageService_callHighPrioFunc(self);
			while ((etMessageQueue_isNotEmpty(&self->messageQueue)||etMessageQueue_isNotEmpty(&self->externalQueue)) && cont) {

				etMessage* msg = etMessageService_popMessage_kkr(self);
				int index = sched_getcpu();

				if(msg->globalcheck==1){
					eseSpinlock_enter(&self->queueeseSpinlock);
					etMutex_enter(&cpuMsgServiceInfo[index]->servermutex);
					cpuMsgServiceInfo[index]->msgServiceData = self;

					if (!self->msgDispatcher(msg))
						cont = ET_FALSE;
					etMutex_leave(&cpuMsgServiceInfo[index]->servermutex);
					eseSpinlock_leave(&self->queueeseSpinlock);
				}
				else{

					etMutex_enter(&self->queueMutex);
					etMutex_enter(&cpuMsgServiceInfo[index]->servermutex);
					cpuMsgServiceInfo[index]->msgServiceData = self;
					if (!self->msgDispatcher(msg))
						cont = ET_FALSE;
					etMutex_leave(&cpuMsgServiceInfo[index]->servermutex);
					etMutex_leave(&self->queueMutex);
				}

				etMessageService_returnMessageBuffer(self, msg);
				etMessageService_callHighPrioFunc(self);
			}
			if (cont)
				etSema_waitForWakeup(&self->executionSemaphore);
		}
		}
	ET_MSC_LOGGER_SYNC_EXIT
}

etInt16 etMessageService_getMessagePoolLowWaterMark(etMessageService* self) {
	ET_MSC_LOGGER_SYNC_ENTRY("etMessageService", "getMessagePoolLowWaterMark")
		etInt16 lowWaterMark = etMessageQueue_getLowWaterMark(&self->messagePool);
	ET_MSC_LOGGER_SYNC_EXIT
	return lowWaterMark;
}

static void etMessageService_timerCallback(void* data) {
	ET_MSC_LOGGER_SYNC_ENTRY("etMessageService", "timerCallback")
		{
		etMessageService* self = (etMessageService*) data;

		/* create a temporary port struct and send the poll message */
		etSystemProtocolConjPort port;
		port.localId = 0;
		port.msgService = self;
		port.peerAddress = MESSAGESERVICE_ADDRESS;
		etSystemProtocolConjPort_poll(&port);
		}
	ET_MSC_LOGGER_SYNC_EXIT
}

