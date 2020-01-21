/**
 * @author generated by eTrice
 *
 * Utils File of ActorClass AirSystem
 *
 */

#ifndef _TEMPLATEMODEL_AIRSYSTEM_UTILS_H_
#define _TEMPLATEMODEL_AIRSYSTEM_UTILS_H_

#include "TemplateModel/AirSystem.h"

/*
 * access macros for ports, operations and attributes
*/

/* simple event ports */
#define throttlePort_recursive2(data) SendDataPort_recursive2(&self->constData->throttlePort, data)
#define throttlePort_recvchangestate() SendDataPort_recvchangestate(&self->constData->throttlePort)
#define throttledata_sendData(data) SendDataConjPort_sendData(&self->constData->throttledata, data)
#define throttledata_sendchangestate() SendDataConjPort_sendchangestate(&self->constData->throttledata)
#define padalPort_recursive2(data) SendDataPort_recursive2(&self->constData->padalPort, data)
#define padalPort_recvchangestate() SendDataPort_recvchangestate(&self->constData->padalPort)
#define internalpedal_sendData(data) SendDataConjPort_sendData(&self->constData->internalpedal, data)
#define internalpedal_sendchangestate() SendDataConjPort_sendchangestate(&self->constData->internalpedal)
#define Internalthrottle_recursive2(data) SendDataPort_recursive2(&self->constData->Internalthrottle, data)
#define Internalthrottle_recvchangestate() SendDataPort_recvchangestate(&self->constData->Internalthrottle)

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
#define recvthrottlesensetime (self->recvthrottlesensetime)
#define recvthrottlesensefirsttime (self->recvthrottlesensefirsttime)
#define recvpedalfirsttime (self->recvpedalfirsttime)
#define recvpedalsensetime (self->recvpedalsensetime)
#define pedalscen (self->pedalscen)
#define pedalins (self->pedalins)
#define throttlescen (self->throttlescen)
#define throttleins (self->throttleins)
#define pedalemer (self->pedalemer)
#define throttleemer (self->throttleemer)
#define count2 (self->count2)
#define count3 (self->count3)
#define count4 (self->count4)
#define actor1_1_id (self->actor1_1_id)
#define actor1_2_id (self->actor1_2_id)
#define actor2_1_id (self->actor2_1_id)
#define actor2_2_id (self->actor2_2_id)

/* port operations */

#endif /* _TEMPLATEMODEL_AIRSYSTEM_UTILS_H_ */
