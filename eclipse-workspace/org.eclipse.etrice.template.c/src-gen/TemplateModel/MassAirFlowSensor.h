/**
 * @author generated by eTrice
 *
 * Header File of ActorClass MassAirFlowSensor
 *
 */

#ifndef _TEMPLATEMODEL_MASSAIRFLOWSENSOR_H_
#define _TEMPLATEMODEL_MASSAIRFLOWSENSOR_H_

#include "etDatatypes.h"
#include "messaging/etMessage.h"

/* include all referenced room classes */
#include "room/basic/service/timing/PTimer.h"
#include "TemplateModel/SendData.h"

/*--------------------- begin user code ---------------------*/
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
struct timespec airflowstart,airflowend;
/*--------------------- end user code ---------------------*/

typedef struct MassAirFlowSensor MassAirFlowSensor;

/* const part of ActorClass (ROM) */
typedef struct MassAirFlowSensor_const {
	const char* instName;

	/* simple ports */
	const SendDataConjPort airflowdata;
	const SendDataConjPort airflowdata2;

	/* data receive ports */

	/* saps */
	const PTimerConjPort timer;

	/* replicated ports */

	/* services */
} MassAirFlowSensor_const;


/* constant for state machine data */
#define MASSAIRFLOWSENSOR_HISTORY_SIZE 2

/* variable part of ActorClass (RAM) */
struct MassAirFlowSensor {
	const MassAirFlowSensor_const* const constData;

	/* data send ports */

	/*--------------------- attributes ---------------------*/
	 int64 count;


	/* state machine variables */
	etInt16 state;
	etInt16 history[MASSAIRFLOWSENSOR_HISTORY_SIZE];
};

void MassAirFlowSensor_init(MassAirFlowSensor* self);

void MassAirFlowSensor_receiveMessage(void* self, const void* ifitem, const etMessage* msg);


/*--------------------- user constructor/destructor ---------------------*/

/*--------------------- operations ---------------------*/


#endif /* _TEMPLATEMODEL_MASSAIRFLOWSENSOR_H_ */

