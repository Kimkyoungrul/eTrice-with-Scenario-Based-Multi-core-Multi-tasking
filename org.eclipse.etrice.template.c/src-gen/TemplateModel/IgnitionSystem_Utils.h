/**
 * @author generated by eTrice
 *
 * Utils File of ActorClass IgnitionSystem
 *
 */

#ifndef _TEMPLATEMODEL_IGNITIONSYSTEM_UTILS_H_
#define _TEMPLATEMODEL_IGNITIONSYSTEM_UTILS_H_

#include "TemplateModel/IgnitionSystem.h"

/*
 * access macros for ports, operations and attributes
*/

/* simple event ports */
#define airflowPort_recursive2(data) SendDataPort_recursive2(&self->constData->airflowPort, data)
#define airflowPort_recvchangestate() SendDataPort_recvchangestate(&self->constData->airflowPort)
#define ignitiondata_sendData(data) SendDataConjPort_sendData(&self->constData->ignitiondata, data)
#define ignitiondata_sendchangestate() SendDataConjPort_sendchangestate(&self->constData->ignitiondata)
#define ignitionInternalIn_sendData(data) SendDataConjPort_sendData(&self->constData->ignitionInternalIn, data)
#define ignitionInternalIn_sendchangestate() SendDataConjPort_sendchangestate(&self->constData->ignitionInternalIn)
#define ignitionInternalOut_recursive2(data) SendDataPort_recursive2(&self->constData->ignitionInternalOut, data)
#define ignitionInternalOut_recvchangestate() SendDataPort_recvchangestate(&self->constData->ignitionInternalOut)

/* data receive ports */

/* data send ports */

/* saps */
#define timer_startTimer(data) PTimerConjPort_startTimer(&self->constData->timer, data)
#define timer_startTimeout(data) PTimerConjPort_startTimeout(&self->constData->timer, data)
#define timer_kill() PTimerConjPort_kill(&self->constData->timer)

/* replicated event ports */

/* services */

/* operations */

/* attributes */
#define priority (self->priority)
#define priority2 (self->priority2)
#define recvfirsttime (self->recvfirsttime)
#define recvairflowsensetime (self->recvairflowsensetime)
#define airflowemer (self->airflowemer)
#define airflowscen (self->airflowscen)
#define airflowins (self->airflowins)
#define actor3_1_id (self->actor3_1_id)
#define actor3_2_id (self->actor3_2_id)
#define count (self->count)

/* port operations */

#endif /* _TEMPLATEMODEL_IGNITIONSYSTEM_UTILS_H_ */

