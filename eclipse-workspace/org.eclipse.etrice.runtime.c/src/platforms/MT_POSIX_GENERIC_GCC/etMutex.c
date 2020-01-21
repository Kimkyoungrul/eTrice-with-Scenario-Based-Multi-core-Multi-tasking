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
 * etMutex.c POSIX implementation of etMutex
 *
 */

#include "osal/etMutex.h"
#include <time.h>
#include "debugging/etLogger.h"
#include "debugging/etMSCLogger.h"
struct timespec start,end,unstart,unend;
void etMutex_construct(etMutex* self){
	ET_MSC_LOGGER_SYNC_ENTRY("etMutex", "construct")
	pthread_mutexattr_t attr;									//added by kkr 19.02.02
	pthread_mutexattr_setprotocol(&attr,PTHREAD_PRIO_INHERIT); 	//added by kkr 19.02.02 for IIP(SRP)
	int i=pthread_mutex_init(&(self->osData), &attr);   				//added by kkr 19.02.02
	pthread_mutexattr_destroy(&attr);    						//added by kkr 19.02.02
	self->time=0; 												//added by kkr 19.02.02
	ET_MSC_LOGGER_SYNC_EXIT
}
void etMutex_destruct(etMutex* self){
	ET_MSC_LOGGER_SYNC_ENTRY("etMutex", "destruct")
	pthread_mutex_destroy(&(self->osData));
	ET_MSC_LOGGER_SYNC_EXIT
}

void etMutex_enter(etMutex* self){
	ET_MSC_LOGGER_SYNC_ENTRY("etMutex", "enter")
	pthread_mutex_lock(&(self->osData));
	ET_MSC_LOGGER_SYNC_EXIT
}
void etMutex_leave(etMutex* self){
	ET_MSC_LOGGER_SYNC_ENTRY("etMutex", "leave")
	pthread_mutex_unlock(&(self->osData));
	ET_MSC_LOGGER_SYNC_EXIT
}
