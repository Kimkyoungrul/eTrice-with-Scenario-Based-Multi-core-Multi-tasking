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

#include "debugging/etLogger.h"
#include "debugging/etMSCLogger.h"

void etMutex_construct(etMutex* self) {
	ET_MSC_LOGGER_SYNC_ENTRY("etMutex", "construct")
	int i=pthread_mutex_init(&(self->osData), NULL);
	FILE *f1 = fopen("debug3.txt","a");//debug kkr
	fprintf(f1,"msginit : %d\n",i);
	fclose(f1);
ET_MSC_LOGGER_SYNC_EXIT
}
void etMutex_destruct(etMutex* self) {
ET_MSC_LOGGER_SYNC_ENTRY("etMutex", "destruct")
pthread_mutex_destroy(&(self->osData));
ET_MSC_LOGGER_SYNC_EXIT
}

void etMutex_enter(etMutex* self) {
ET_MSC_LOGGER_SYNC_ENTRY("etMutex", "enter")
pthread_mutex_lock(&(self->osData));
ET_MSC_LOGGER_SYNC_EXIT
}
void etMutex_leave(etMutex* self) {
ET_MSC_LOGGER_SYNC_ENTRY("etMutex", "leave")
pthread_mutex_unlock(&(self->osData));
ET_MSC_LOGGER_SYNC_EXIT
}
