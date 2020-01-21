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
#ifdef __cplusplus
extern "C" {
#endif

#ifndef _ETSEMA_H_
#define _ETSEMA_H_

/**
 * \file etSema.h
 *
 * etSema.h defines a generic interface for platform specific implementations of a semaphore
 *
 * \author Thomas Schuetz
 */

#include "etDatatypes.h"

/**
 * etSema holds the object data for a semaphore (for self pointer)
 */
typedef struct etSema {
	etOSSemaData osData;
} etSema;

/**
 * initializes the semaphore
 * \param self the 'this' pointer of the semaphore
 */
void etSema_construct(etSema* self);

/**
 * destroys the semaphore
 * \param self the 'this' pointer of the semaphore
 */
void etSema_destruct(etSema* self);

/**
 * wakes up the semaphore
 * \param self the 'this' pointer of the semaphore
 */
void etSema_wakeup(etSema* self);
void etSema_wakeupFromISR(etSema* self);

/**
 * make the semaphore waiting for a wakeup
 * \param self the 'this' pointer of the semaphore
 */
void etSema_waitForWakeup(etSema* self);

#endif /* _ETSEMA_H_ */

#ifdef __cplusplus
}
#endif
