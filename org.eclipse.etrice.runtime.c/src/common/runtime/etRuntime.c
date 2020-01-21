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

#include "runtime/etRuntime.h"

static etSema terminateSemaphore;

etSema* etRuntime_getTerminateSemaphore() {
	static etBool initialized = ET_FALSE;

	if (!initialized) {
		initialized = ET_TRUE;
		etSema_construct(&terminateSemaphore);
	}

	return &terminateSemaphore;
}
