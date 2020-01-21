/**
 * @author generated by eTrice
 *
 * Utils File of ActorClass MassAirFlowSensor
 *
 */

#ifndef _TEMPLATEMODEL_MASSAIRFLOWSENSOR_UTILS_H_
#define _TEMPLATEMODEL_MASSAIRFLOWSENSOR_UTILS_H_

#include "TemplateModel/MassAirFlowSensor.h"

/*
 * access macros for ports, operations and attributes
*/

/* simple event ports */
#define airflowdata_sendData(data) SendDataConjPort_sendData(&self->constData->airflowdata, data)
#define airflowdata_sendchangestate() SendDataConjPort_sendchangestate(&self->constData->airflowdata)
#define airflowdata2_sendData(data) SendDataConjPort_sendData(&self->constData->airflowdata2, data)
#define airflowdata2_sendchangestate() SendDataConjPort_sendchangestate(&self->constData->airflowdata2)

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
#define count (self->count)

/* port operations */

#endif /* _TEMPLATEMODEL_MASSAIRFLOWSENSOR_UTILS_H_ */

