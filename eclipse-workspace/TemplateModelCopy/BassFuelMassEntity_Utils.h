/**
 * @author generated by eTrice
 *
 * Utils File of ActorClass BassFuelMassEntity
 *
 */

#ifndef _TEMPLATEMODEL_BASSFUELMASSENTITY_UTILS_H_
#define _TEMPLATEMODEL_BASSFUELMASSENTITY_UTILS_H_

#include "TemplateModel/BassFuelMassEntity.h"

/*
 * access macros for ports, operations and attributes
*/

/* simple event ports */
#define bassfueldata_recursive2(data) SendDataPort_recursive2(&self->constData->bassfueldata, data)
#define bassfueldata_recvchangestate() SendDataPort_recvchangestate(&self->constData->bassfueldata)
#define bassfueldatasend_sendData(data) SendDataConjPort_sendData(&self->constData->bassfueldatasend, data)
#define bassfueldatasend_sendchangestate() SendDataConjPort_sendchangestate(&self->constData->bassfueldatasend)

/* data receive ports */

/* data send ports */

/* saps */

/* replicated event ports */

/* services */

/* operations */

/* attributes */

/* port operations */

#endif /* _TEMPLATEMODEL_BASSFUELMASSENTITY_UTILS_H_ */

