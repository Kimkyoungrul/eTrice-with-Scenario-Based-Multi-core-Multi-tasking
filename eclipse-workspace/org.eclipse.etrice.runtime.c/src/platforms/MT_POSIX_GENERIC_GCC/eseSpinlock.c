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
 * etSpinlock.c POSIX implementation of etSpinlock
 *
 */

#include "osal/eteseSpinlock.h"

#include "debugging/etLogger.h"
#include "debugging/etMSCLogger.h"

void eseSpinlock_construct(eteseSpinlock* self){
	ET_MSC_LOGGER_SYNC_ENTRY("etSpinlock", "construct")
	self->osData=0;
	ET_MSC_LOGGER_SYNC_EXIT
}
void eseSpinlock_destruct(eteseSpinlock* self){
	ET_MSC_LOGGER_SYNC_ENTRY("etSpinlock", "destruct")

	ET_MSC_LOGGER_SYNC_EXIT
}

void eseSpinlock_enter(eteseSpinlock* self){
	ET_MSC_LOGGER_SYNC_ENTRY("etSpinlock", "enter")
	struct sched_param param;
	int sched_policy;
	pthread_getschedparam(pthread_self(),&sched_policy,&param);
	self->prior=param.__sched_priority;
	while (1) {
		if (__sync_bool_compare_and_swap(&self->osData, 0, 1)) {
			param.__sched_priority=99;
			pthread_setschedparam(pthread_self(),sched_policy,&param);
			break;
		}
	}

	ET_MSC_LOGGER_SYNC_EXIT
}
void eseSpinlock_leave(eteseSpinlock* self){
	ET_MSC_LOGGER_SYNC_ENTRY("etSpinlock", "leave")

	__sync_bool_compare_and_swap(&self->osData, 1, 0);
	struct sched_param param;
	int sched_policy;
	pthread_getschedparam(pthread_self(),&sched_policy,&param);
	param.__sched_priority=self->prior;
	pthread_setschedparam(pthread_self(),sched_policy,&param);
	ET_MSC_LOGGER_SYNC_EXIT
}
