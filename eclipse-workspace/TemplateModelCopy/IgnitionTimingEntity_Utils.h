/**
 * @author generated by eTrice
 *
 * Utils File of ActorClass IgnitionTimingEntity
 *
 */

#ifndef _TEMPLATEMODEL_IGNITIONTIMINGENTITY_UTILS_H_
#define _TEMPLATEMODEL_IGNITIONTIMINGENTITY_UTILS_H_

#include "TemplateModel/IgnitionTimingEntity.h"

/*
 * access macros for ports, operations and attributes
*/

/* simple event ports */
#define ignitiontimingdata_recursive2(data) SendDataPort_recursive2(&self->constData->ignitiontimingdata, data)
#define ignitiontimingdata_recvchangestate() SendDataPort_recvchangestate(&self->constData->ignitiontimingdata)
#define ignitiontimingdatasend_sendData(data) SendDataConjPort_sendData(&self->constData->ignitiontimingdatasend, data)
#define ignitiontimingdatasend_sendchangestate() SendDataConjPort_sendchangestate(&self->constData->ignitiontimingdatasend)

/* data receive ports */

/* data send ports */

/* saps */

/* replicated event ports */

/* services */

/* operations */

/* attributes */

/* port operations */

#endif /* _TEMPLATEMODEL_IGNITIONTIMINGENTITY_UTILS_H_ */

