/*******************************************************************************
 * Copyright (c) 2011 protos software gmbh (http://www.protos.de).
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
 * \file etMessageQueue.h
 *
 * this component implements a message queue (fifo)
 *
 * \author Thomas Schuetz
 */

#ifndef _ETMESSAGEQUEUE_H_
#define _ETMESSAGEQUEUE_H_

#include "messaging/etMessage.h"
#include <stddef.h>

/**
 * the message queue data structure
 */
typedef struct etMessageQueue {

//	etMessage* fir_first;				/**< the head of the first list *//added by kkr
//	etMessage* fir_last;				/**< the tail of the first list *//added by kkr
//	etInt16 fir_highWaterMark;			/**< first list high water mark for statistical purposes *//added by kkr
//	etInt16 fir_lowWaterMark;			/**< fisrt list low water mark for statistical purposes *//added by kkr
//	etInt16 fir_size;					/**< fisrt list the size of the list *//added by kkr

	etMessage* first; /**< the head of the second list */
	etMessage* last; /**< the tail of the second list */
	etInt16 highWaterMark; /**< second list high water mark for statistical purposes */
	etInt16 lowWaterMark; /**< second list low water mark for statistical purposes */
	etInt16 size; /**< the second list size of the list */
} etMessageQueue;


/**
 * initializes the queue data fields ("constructor")
 *
 * \param self the this pointer
 */
void etMessageQueue_init(etMessageQueue* self);
/**
 * appends a new message to the queue
 *
 * \param self the this pointer
 */
void etMessageQueue_push(etMessageQueue* self, etMessage* msg);
/**
 * removes the first message from the queue
 *
 * \param self the this pointer
 * \return the removed message
 */
etMessage* etMessageQueue_pop(etMessageQueue* self);
/**
 * returns the first message without removing it
 *
 * \param self the this pointer
 * \return the first message without removing it
 */
etMessage* etMessageQueue_getFirst(etMessageQueue* self);
/**
 * returns the last message without removing it
 *
 * \param self the this pointer
 * \return the last message without removing it
 */
etMessage* etMessageQueue_getLast(etMessageQueue* self);

/**
 * returns <code>true</code> if the message queue is not empty
 *
 * \param self the this pointer
 * \return <code>true</code> if the message queue is not empty
 */
etBool etMessageQueue_isNotEmpty(etMessageQueue* self);

/**
 * returns the size of the message queue
 *
 * \param self the this pointer
 * \return the size of the message queue
 */
etInt16 etMessageQueue_getSize(etMessageQueue* self);
/**
 * returns the high water mark of the message queue
 *
 * \param self the this pointer
 * \return the high water mark of the message queue
 */
etInt16 etMessageQueue_getHighWaterMark(etMessageQueue* self);
/**
 * returns the low water mark of the message queue
 *
 * \param self the this pointer
 * \return the low water mark of the message queue
 */
etInt16 etMessageQueue_getLowWaterMark(etMessageQueue* self);
/**
 * resets the low water mark of the message queue to the current
 * position (size) of the queue
 *
 * \param self the this pointer
 */
void etMessageQueue_resetLowWaterMark(etMessageQueue* self);

#endif /* _RMESSAGEQUEUE_H_ */
