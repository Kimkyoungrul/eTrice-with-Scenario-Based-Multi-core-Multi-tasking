/*******************************************************************************
 * Copyright (c) 2013 protos software gmbh (http://www.protos.de).
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * CONTRIBUTORS:
 * 		Henrik Rentz-Reichert (initial contribution)
 *
 *******************************************************************************/

/**
 *
 * etThread.c POSIX implementation of etThread
 *
 */
#include "/home/eselab/eclipse-workspace/org.eclipse.etrice.template.c/src-gen/TemplateModel/ADASMessage.h"
#include "osal/etThread.h"
#include "base/etMemory.h"
#include "messaging/etMessage.h"
#include "messaging/etMessageService.h"
#include "debugging/etLogger.h"
#include "debugging/etMSCLogger.h"
#define SCHED_RR		2
#define PTHREAD_STACK_MIN 16384
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/unistd.h>
#include <errno.h>
unsigned long pro=10;
typedef void *(*threadFunc)(void *);
void* etThread_execute(etThread* self);

void etThread_construct(
		etThread* self,
		etStacksize stacksize,
		etPriority priority,
		etThreadname threadName,
		etThreadFunction threadFunction,
		void* threadFunctionData
		)
{
	ET_MSC_LOGGER_SYNC_ENTRY("etThread", "construct")

	/* fill in data */
	self->stacksize = stacksize;
	self->priority = priority;
	self->threadName = threadName;
	self->threadFunction = threadFunction;
	self->threadFunctionData = threadFunctionData;

	ET_MSC_LOGGER_SYNC_EXIT
}
void etThread_construct_kkr(
		etThread* self,
		etStacksize stacksize,
		etPriority priority,
		etThreadname threadName,
		etThreadFunction threadFunction,
		void* threadFunctionData,
		etCpunum cpunum)//added by kkr 2018.06.30
{
	ET_MSC_LOGGER_SYNC_ENTRY("etThread", "construct")

	/* fill in data */
	self->stacksize = stacksize;
	self->priority = priority;
	self->threadName = threadName;
	self->threadFunction = threadFunction;
	self->threadFunctionData = threadFunctionData;
	self->cpunum = cpunum;//added by kkr 2018.06.30

	ET_MSC_LOGGER_SYNC_EXIT
}
void etThread_start(etThread* self) {
	ET_MSC_LOGGER_SYNC_ENTRY("etThread", "start")
	{

		struct sched_param param,param2;
		pthread_attr_t attr;
		const int policy = SCHED_FIFO;

		int minPriority = sched_get_priority_min(policy);
		int maxPriority = sched_get_priority_max(policy);

		if (self->priority<minPriority)
			self->priority = minPriority;
		if (self->priority>maxPriority)
			self->priority = maxPriority;

		param.sched_priority = self->priority;
		pthread_attr_init(&attr);
		int s1=pthread_attr_setschedpolicy(&attr, policy);

		int s2= pthread_attr_setschedparam(&attr, &param);//setschedparam,setschedpolicy order revised kkr 18.09.10

		if(self->stacksize<PTHREAD_STACK_MIN){//setstacksize need minvalue(16kb) revised kkr 18.09.10
			self->stacksize=PTHREAD_STACK_MIN;
		}
		pthread_attr_setstacksize(&attr, self->stacksize);
		int s3=pthread_attr_setinheritsched(&attr, PTHREAD_EXPLICIT_SCHED);//when does pthread_create use attr that need setinheritsched(PTHREAD_EXPLICIT_SCHED) added kkr 18.09.10

		int s4=pthread_create(&(self->osData), &attr, (threadFunc) etThread_execute, self);

		pthread_attr_destroy(&attr);


	}
	ET_MSC_LOGGER_SYNC_EXIT
}
void etThread_start_kkr(etThread* self) {
	ET_MSC_LOGGER_SYNC_ENTRY("etThread", "start")
	{

		struct sched_param param,param2;
		pthread_attr_t attr;
		const int policy = SCHED_FIFO;

		int minPriority = sched_get_priority_min(policy);
		int maxPriority = sched_get_priority_max(policy);
//		void* temp; //kkr Bring Message's data
//		etMessageService* messageservice=((etMessageService*)self->threadFunctionData);
//		etBool cont = ET_TRUE;
//		while (etMessageQueue_isNotEmpty(&messageservice->messageQueue) && cont) {
//			self->msg = etMessageService_topMessage(messageservice);
//			temp=(void *)(((char *)self->msg)+MEM_CEIL(sizeof(etMessage)));
//			ADASMessage* data=((ADASMessage*)temp);
//			self->priority = data->prior;
//			FILE *fp1 = fopen("conveypriority.txt","a");
//			fprintf(fp1,"%d\n",self->priority);
//			fclose(fp1);
//			if (!messageservice->msgDispatcher(self->msg))
//				cont = ET_FALSE;
//		}
		if (self->priority<minPriority)
			self->priority = minPriority;
		if (self->priority>maxPriority)
			self->priority = maxPriority;

		param.sched_priority = self->priority;
		pthread_attr_init(&attr);
		int s1=pthread_attr_setschedpolicy(&attr, policy);

		int s2= pthread_attr_setschedparam(&attr, &param);//setschedparam,setschedpolicy order revised kkr 18.09.10

		if(self->stacksize<PTHREAD_STACK_MIN){//setstacksize need minvalue(16kb) revised kkr 18.09.10
			self->stacksize=PTHREAD_STACK_MIN;
		}
		pthread_attr_setstacksize(&attr, self->stacksize);
		int s3=pthread_attr_setinheritsched(&attr, PTHREAD_EXPLICIT_SCHED);//when does pthread_create use attr that need setinheritsched(PTHREAD_EXPLICIT_SCHED) added kkr 18.09.10

		int s4=pthread_create(&(self->osData), &attr, (threadFunc) etThread_execute, self);

		pthread_attr_destroy(&attr);
		int num=0;
		if(pthread_setaffinity_np(self->osData,sizeof(self->cpunum),(cpu_set_t *)&self->cpunum)<0){//added by kkr 2018.06.30
			perror("pthread_setaffinity_np");
		}

	}
	ET_MSC_LOGGER_SYNC_EXIT
}
void* etThread_execute(etThread* self){
	ET_MSC_LOGGER_SYNC_ENTRY("etThread", "execute")
	/* etThread_execute redirects the call from the thread to the execute function in the eTrice runtime to enable correct synchronous MSC logging */
	self->threadFunction(self->threadFunctionData);
	ET_MSC_LOGGER_SYNC_EXIT
	return NULL;
}

void etThread_destruct(etThread* self){
	ET_MSC_LOGGER_SYNC_ENTRY("etThread", "destruct")
	pthread_detach(self->osData);
	ET_MSC_LOGGER_SYNC_EXIT
}

void etThread_sleep(etInt32 millis){
	ET_MSC_LOGGER_SYNC_ENTRY("etThread", "sleep")
	{
		struct timespec time;
		time.tv_sec = millis / 1000;
		time.tv_nsec = (millis - time.tv_sec * 1000) * 1000*1000;
		while(nanosleep(&time, &time) != 0) {
			if(errno != EINTR)
				break;
		}
	}
	ET_MSC_LOGGER_SYNC_EXIT
}

etOSThreadData etThread_self(void){
	return pthread_self();
}

etOSThreadId etThread_self_id(void){
	return pthread_self();
}

