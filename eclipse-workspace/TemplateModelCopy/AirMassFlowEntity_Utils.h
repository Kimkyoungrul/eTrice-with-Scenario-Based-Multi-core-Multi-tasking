/**
 * @author generated by eTrice
 *
 * Utils File of ActorClass AirMassFlowEntity
 *
 */

#ifndef _TEMPLATEMODEL_AIRMASSFLOWENTITY_UTILS_H_
#define _TEMPLATEMODEL_AIRMASSFLOWENTITY_UTILS_H_

#include "TemplateModel/AirMassFlowEntity.h"

/*
 * access macros for ports, operations and attributes
*/

/* simple event ports */
#define massflowdata_recursive2(data) SendDataPort_recursive2(&self->constData->massflowdata, data)
#define massflowdata_recvchangestate() SendDataPort_recvchangestate(&self->constData->massflowdata)
#define massflowdatasend_sendData(data) SendDataConjPort_sendData(&self->constData->massflowdatasend, data)
#define massflowdatasend_sendchangestate() SendDataConjPort_sendchangestate(&self->constData->massflowdatasend)

/* data receive ports */

/* data send ports */

/* saps */

/* replicated event ports */

/* services */

/* operations */

/* attributes */

/* port operations */

#endif /* _TEMPLATEMODEL_AIRMASSFLOWENTITY_UTILS_H_ */
