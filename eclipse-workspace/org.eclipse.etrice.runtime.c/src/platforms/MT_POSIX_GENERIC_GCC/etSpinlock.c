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

#include "osal/etSpinlock.h"

#include "debugging/etLogger.h"
#include "debugging/etMSCLogger.h"

void etSpinlock_construct(etSpinlock* self){
	ET_MSC_LOGGER_SYNC_ENTRY("etSpinlock", "construct")
	pthread_spin_init(&(self->osData), NULL);
	ET_MSC_LOGGER_SYNC_EXIT
}
void etSpinlock_destruct(etSpinlock* self){
	ET_MSC_LOGGER_SYNC_ENTRY("etSpinlock", "destruct")
	pthread_spin_destroy(&(self->osData));
	ET_MSC_LOGGER_SYNC_EXIT
}

void etSpinlock_enter(etSpinlock* self){
	ET_MSC_LOGGER_SYNC_ENTRY("etSpinlock", "enter")
	pthread_spin_lock(&(self->osData));

	ET_MSC_LOGGER_SYNC_EXIT
}
void etSpinlock_leave(etSpinlock* self){
	ET_MSC_LOGGER_SYNC_ENTRY("etSpinlock", "leave")
	pthread_spin_unlock(&(self->osData));
	//printf("%d\n",j);
	ET_MSC_LOGGER_SYNC_EXIT
}
