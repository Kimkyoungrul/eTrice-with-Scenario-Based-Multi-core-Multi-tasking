/**
 * @author generated by eTrice
 *
 * Utils File of ActorClass InjectionTimingActuatorEntity
 *
 */

#ifndef _TEMPLATEMODEL_INJECTIONTIMINGACTUATORENTITY_UTILS_H_
#define _TEMPLATEMODEL_INJECTIONTIMINGACTUATORENTITY_UTILS_H_

#include "TemplateModel/InjectionTimingActuatorEntity.h"

/*
 * access macros for ports, operations and attributes
*/

/* simple event ports */
#define Injectionactordata_recursive2(data) SendDataPort_recursive2(&self->constData->Injectionactordata, data)
#define Injectionactordata_recvchangestate() SendDataPort_recvchangestate(&self->constData->Injectionactordata)
#define Injectionactordatasend_sendData(data) SendDataConjPort_sendData(&self->constData->Injectionactordatasend, data)
#define Injectionactordatasend_sendchangestate() SendDataConjPort_sendchangestate(&self->constData->Injectionactordatasend)

/* data receive ports */

/* data send ports */

/* saps */

/* replicated event ports */

/* services */

/* operations */

/* attributes */

/* port operations */

#endif /* _TEMPLATEMODEL_INJECTIONTIMINGACTUATORENTITY_UTILS_H_ */

