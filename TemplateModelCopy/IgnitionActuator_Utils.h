/**
 * @author generated by eTrice
 *
 * Utils File of ActorClass IgnitionActuator
 *
 */

#ifndef _TEMPLATEMODEL_IGNITIONACTUATOR_UTILS_H_
#define _TEMPLATEMODEL_IGNITIONACTUATOR_UTILS_H_

#include "TemplateModel/IgnitionActuator.h"

/*
 * access macros for ports, operations and attributes
*/

/* simple event ports */
#define ignitionPort_recursive2(data) SendDataPort_recursive2(&self->constData->ignitionPort, data)
#define ignitionPort_recvchangestate() SendDataPort_recvchangestate(&self->constData->ignitionPort)
#define cylinerData_sendData(data) SendDataConjPort_sendData(&self->constData->cylinerData, data)
#define cylinerData_sendchangestate() SendDataConjPort_sendchangestate(&self->constData->cylinerData)
#define igntionactorInternalIn_sendData(data) SendDataConjPort_sendData(&self->constData->igntionactorInternalIn, data)
#define igntionactorInternalIn_sendchangestate() SendDataConjPort_sendchangestate(&self->constData->igntionactorInternalIn)
#define ignitionactorInternalOut_recursive2(data) SendDataPort_recursive2(&self->constData->ignitionactorInternalOut, data)
#define ignitionactorInternalOut_recvchangestate() SendDataPort_recvchangestate(&self->constData->ignitionactorInternalOut)

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
#define recvscenarioID (self->recvscenarioID)
#define recvinstanceID (self->recvinstanceID)
#define recvemer (self->recvemer)
#define count (self->count)
#define count2 (self->count2)
#define recvairmasstime (self->recvairmasstime)
#define recvignitiontiming (self->recvignitiontiming)
#define recvfirsttime (self->recvfirsttime)
#define recvairflowsensetime (self->recvairflowsensetime)
#define recvignitionsystemtime (self->recvignitionsystemtime)
#define recvignitionsystemtime2 (self->recvignitionsystemtime2)
#define recvcylinertime (self->recvcylinertime)
#define recvbassfueltime (self->recvbassfueltime)
#define ignitionacttime (self->ignitionacttime)
#define ignitionacttime2 (self->ignitionacttime2)
#define ignitionacttime3 (self->ignitionacttime3)
#define ignitionstarttime (self->ignitionstarttime)
#define recvignitiontimingtime (self->recvignitiontimingtime)
#define actor7_1_id (self->actor7_1_id)
#define actor7_2_id (self->actor7_2_id)
#define actor7_3_id (self->actor7_3_id)
#define actor7_4_id (self->actor7_4_id)
#define actor7_5_id (self->actor7_5_id)
#define actor10_1_id (self->actor10_1_id)
#define actor10_2_id (self->actor10_2_id)
#define actor10_3_id (self->actor10_3_id)
#define actor10_4_id (self->actor10_4_id)
#define actor10_5_id (self->actor10_5_id)
#define actor10_6_id (self->actor10_6_id)
#define priority (self->priority)
#define priority2 (self->priority2)

/* port operations */

#endif /* _TEMPLATEMODEL_IGNITIONACTUATOR_UTILS_H_ */

