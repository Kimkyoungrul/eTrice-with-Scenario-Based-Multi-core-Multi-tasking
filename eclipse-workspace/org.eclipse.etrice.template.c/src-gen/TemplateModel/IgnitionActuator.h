/**
 * @author generated by eTrice
 *
 * Header File of ActorClass IgnitionActuator
 *
 */

#ifndef _TEMPLATEMODEL_IGNITIONACTUATOR_H_
#define _TEMPLATEMODEL_IGNITIONACTUATOR_H_

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
struct timespec igniactstart,igniactstart2,igniactstart3,igniactend,igniactend2,ignisysstart,ignisysend;
FILE *fp9;
FILE *fp10;
/*--------------------- end user code ---------------------*/

typedef struct IgnitionActuator IgnitionActuator;

/* const part of ActorClass (ROM) */
typedef struct IgnitionActuator_const {
	const char* instName;

	/* simple ports */
	const SendDataPort ignitionPort;
	const SendDataConjPort cylinerData;
	const SendDataConjPort igntionactorInternalIn;
	const SendDataPort ignitionactorInternalOut;

	/* data receive ports */

	/* saps */
	const PTimerConjPort timer;

	/* replicated ports */

	/* services */
} IgnitionActuator_const;


/* constant for state machine data */
#define IGNITIONACTUATOR_HISTORY_SIZE 2

/* variable part of ActorClass (RAM) */
struct IgnitionActuator {
	const IgnitionActuator_const* const constData;

	/* data send ports */

	/*--------------------- attributes ---------------------*/
	 int32 recvscenarioID;
	 int32 recvinstanceID;
	 int32 recvemer;
	 int16 count;
	 int16 count2;
	 float64 recvairmasstime;
	 float64 recvignitiontiming;
	 float64 recvfirsttime;
	 float64 recvairflowsensetime;
	 float64 recvignitionsystemtime;
	 float64 recvignitionsystemtime2;
	 float64 recvcylinertime;
	 float64 recvbassfueltime;
	 float64 ignitionacttime;
	 float64 ignitionacttime2;
	 float64 ignitionacttime3;
	 float64 ignitionstarttime;
	 float64 recvignitiontimingtime;
	 int32 actor7_1_id;
	 int32 actor7_2_id;
	 int32 actor7_3_id;
	 int32 actor7_4_id;
	 int32 actor7_5_id;
	 int32 actor10_1_id;
	 int32 actor10_2_id;
	 int32 actor10_3_id;
	 int32 actor10_4_id;
	 int32 actor10_5_id;
	 int32 actor10_6_id;
	 int16 priority;
	 int16 priority2;


	/* state machine variables */
	etInt16 state;
	etInt16 history[IGNITIONACTUATOR_HISTORY_SIZE];
};

void IgnitionActuator_init(IgnitionActuator* self);

void IgnitionActuator_receiveMessage(void* self, const void* ifitem, const etMessage* msg);


/*--------------------- user constructor/destructor ---------------------*/

/*--------------------- operations ---------------------*/


#endif /* _TEMPLATEMODEL_IGNITIONACTUATOR_H_ */

