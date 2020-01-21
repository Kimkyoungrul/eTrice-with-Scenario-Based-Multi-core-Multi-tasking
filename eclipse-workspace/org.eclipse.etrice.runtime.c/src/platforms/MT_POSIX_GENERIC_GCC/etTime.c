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
 * etTime.c POSIX implementation of etTime
 *
 */

#include "osal/etTime.h"

#include <sys/time.h>

void getTimeFromTarget(etTime *t){
	struct timeval currentTime;
	gettimeofday(&currentTime, NULL);
	t->sec = currentTime.tv_sec;
	t->nSec = currentTime.tv_usec*1000;
}


/* TODO: remove old API functions
uint64 getTargetTimeUs(void){
	struct timeval currentTime;
	gettimeofday(&currentTime, NULL);

	return currentTime.tv_sec * 1000000L + currentTime.tv_usec;
}

etBool etTimer_executeNeeded(void){

	static uint64 lastTime = 0L;

	uint64 currentTime = getTargetTimeUs();

	uint64 timestep = 1000000L/FREQUENCY;

	if (currentTime >= lastTime +  timestep) {
		lastTime = currentTime;
		return TRUE;
	}
	else {
		return FALSE;
	}
}

*/


