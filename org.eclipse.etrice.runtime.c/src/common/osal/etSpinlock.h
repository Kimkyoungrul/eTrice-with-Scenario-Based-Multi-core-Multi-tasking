/*******************************************************************************
 * Copyright (c) 2013 protos software gmbh (http://www.protos.de).
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * CONTRIBUTORS:
 * 		Thomas Schuetz, Thomas Jung (initial contribution)
 *
 *
 *******************************************************************************/

/**
 * \file etMSpinlock.h
 *
 * etMutex.h defines a generic interface for platform specific implementations of a Spinlock
 *
 * \author Thomas Schuetz, Thomas Jung
 */
#ifdef __cplusplus
extern "C" {
#endif

#ifndef _ETSPINLOCK_H_
#define _ETSPINLOCK_H_
#include "etDatatypes.h"
typedef pthread_spinlock_t etOSSpinlockData;
/**
 * etMutex holds the object data for a Spinlock (for self pointer)
 */
typedef struct etSpinlock {
	etOSSpinlockData osData;
} etSpinlock;

/**
 * initializes the spinlock
 * \param self the 'this' pointer of the spinlock
 */
void etSpinlock_construct(etSpinlock* self);

/**
 * destroys the spinlock
 * \param self the 'this' pointer of the spinlock
 */
void etSpinlock_destruct(etSpinlock* self);

/**
 * lock the spinlock
 * \param self the 'this' pointer of the spinlock
 */
void etSpinlock_enter(etSpinlock* self);

/**
 * unlock the spinlock
 * \param self the 'this' pointer of the spinlock
 */
void etSpinlock_leave(etSpinlock* self);

#endif /* _ETSPINLOCK_H_ */

#ifdef __cplusplus
}
#endif
