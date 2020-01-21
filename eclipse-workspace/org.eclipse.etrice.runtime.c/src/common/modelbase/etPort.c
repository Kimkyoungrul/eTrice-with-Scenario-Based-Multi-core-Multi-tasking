/*******************************************************************************
 * Copyright (c) 2012 protos software gmbh (http://www.protos.de).
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
#include "modelbase/etPort.h"
#include "/home/eselab/eclipse-workspace/org.eclipse.etrice.modellib.c/src-gen/room/basic/service/timing/PTimer.h"
#include "debugging/etMSCLogger.h"
#include "base/etMemory.h"
#include "/home/eselab/eclipse-workspace/org.eclipse.etrice.template.c/src-gen/TemplateModel/ADASMessage.h"
#include <string.h>
#include <sched.h>
#define global (((PTimerConjPort_var*)(self->varData))->globalcheck) //added by kkr (for global actor check)
extern conveyMsg* cpuMsgServiceInfo[8];//added by kkr
/*
 void etPort_receive(const etPort* self, const etMessage* msg) {
 ET_MSC_LOGGER_SYNC_ENTRY("etPort", "receive")
 if (self->receiveMessageFunc!=NULL)
 (self->receiveMessageFunc)(self->myActor, (void*)self, msg);
 ET_MSC_LOGGER_SYNC_EXIT
 }
 */

void etPort_sendMessage(const etPort* self, etInt16 evtId, int size, void* data) {
	int offset = MEM_CEIL(sizeof(etMessage));
	int totalSize = offset + size;

	etMessage* msg = NULL;
	ET_MSC_LOGGER_SYNC_ENTRY("etPort", "sendMessage")
	if (self->msgService == NULL)
		return;


	msg = etMessageService_getMessageBuffer(self->msgService, totalSize);
	if (msg != NULL) {
		msg->address = self->peerAddress;
		msg->evtID = evtId;
		if(self->varData != NULL)//added by kkr (for global actor check)
			if(global==1)
				msg->globalcheck=1;
		if (size > 0 && data != NULL) {
			memcpy(((char*) msg) + offset, data, size);
		}

		etMessageService_pushMessage(self->msgService, msg);
	}

	ET_MSC_LOGGER_SYNC_EXIT
}
void etPort_sendMessage_kkr(const etPort* self, etInt16 evtId, int size,
		void* data) {//added by kkr
	int offset = MEM_CEIL(sizeof(etMessage));
	int totalSize = offset + size;
	int index = sched_getcpu();
	etMessage* msg = NULL;
	ET_MSC_LOGGER_SYNC_ENTRY("etPort", "sendMessage")
	if (cpuMsgServiceInfo[index]->msgServiceData == NULL)
		return;
	msg = etMessageService_getMessageBuffer(cpuMsgServiceInfo[index]->msgServiceData, totalSize);
	if (msg != NULL) {
		msg->address = self->peerAddress;
		msg->evtID = evtId;
		ADASMessage* bringdata=((ADASMessage*)data); //added by kkr (for global actor check)
		if(bringdata->staticcheck==1)
			msg->globalcheck=1;
		if (size > 0 && data != NULL) {
			memcpy(((char*) msg) + offset, data, size);
		}

		etMessageService_pushMessage_kkr(cpuMsgServiceInfo[index]->msgServiceData, msg);

	}
	ET_MSC_LOGGER_SYNC_EXIT
}
