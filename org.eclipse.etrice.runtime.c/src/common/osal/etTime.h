/*******************************************************************************
 * Copyright (c) 2013 protos software gmbh (http://www.protos.de).
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * CONTRIBUTORS:
 * 		Thomas Schuetz (initial contribution)
 *
 *******************************************************************************/

/**
 * \file etTime.h
 *
 * defines a generic interface for platform specific implementations of services around time
 *
 * \author Thomas Schuetz
 */

#ifdef __cplusplus
extern "C" {
#endif

#ifndef _ETTIME_H_
#define _ETTIME_H_

#include "etDatatypes.h"

/**
 * time definition composed by the number of seconds and the number of nano seconds
 * negative values have only negative sec, nSec is always positive
 * for nSec always holds and 0 <= nSec < 1E9 (1 second in nano seconds)
 * all functions in etTimeHelpers also have those preconditions
 */
typedef struct etTime {
	etInt32 sec; /**< seconds */
	etInt32 nSec; /**< nanoseconds */
} etTime;

/**
 * get current time from target hardware
 * this is no real world clock time and date
 * should be used only for relative time measurement
 * \param current target time as etTime*
 */
void getTimeFromTarget(etTime *t);

#endif /* _ETTIME_H_ */

#ifdef __cplusplus
}
#endif
