/**
 * @author generated by eTrice
 *
 * Utils File of ActorClass IgnitionTimingActuatorEntity
 *
 */

#ifndef _TEMPLATEMODEL_IGNITIONTIMINGACTUATORENTITY_UTILS_H_
#define _TEMPLATEMODEL_IGNITIONTIMINGACTUATORENTITY_UTILS_H_

#include "TemplateModel/IgnitionTimingActuatorEntity.h"

/*
 * access macros for ports, operations and attributes
*/

/* simple event ports */
#define ignitionactordata_recursive2(data) SendDataPort_recursive2(&self->constData->ignitionactordata, data)
#define ignitionactordata_recvchangestate() SendDataPort_recvchangestate(&self->constData->ignitionactordata)
#define ignitionactordatasend_sendData(data) SendDataConjPort_sendData(&self->constData->ignitionactordatasend, data)
#define ignitionactordatasend_sendchangestate() SendDataConjPort_sendchangestate(&self->constData->ignitionactordatasend)

/* data receive ports */

/* data send ports */

/* saps */

/* replicated event ports */

/* services */

/* operations */

/* attributes */

/* port operations */

#endif /* _TEMPLATEMODEL_IGNITIONTIMINGACTUATORENTITY_UTILS_H_ */

