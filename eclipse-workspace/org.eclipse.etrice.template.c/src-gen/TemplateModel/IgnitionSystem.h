/**
 * @author generated by eTrice
 *
 * Header File of ActorClass IgnitionSystem
 *
 */

#ifndef _TEMPLATEMODEL_IGNITIONSYSTEM_H_
#define _TEMPLATEMODEL_IGNITIONSYSTEM_H_

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
struct timespec ignistart2,ignistart,igniend,airflowstart,airflowend;
FILE *fp8;
/*--------------------- end user code ---------------------*/

typedef struct IgnitionSystem IgnitionSystem;

/* const part of ActorClass (ROM) */
typedef struct IgnitionSystem_const {
	const char* instName;

	/* simple ports */
	const SendDataPort airflowPort;
	const SendDataConjPort ignitiondata;
	const SendDataConjPort ignitionInternalIn;
	const SendDataPort ignitionInternalOut;

	/* data receive ports */

	/* saps */
	const PTimerConjPort timer;

	/* replicated ports */

	/* services */
} IgnitionSystem_const;


/* constant for state machine data */
#define IGNITIONSYSTEM_HISTORY_SIZE 2

/* variable part of ActorClass (RAM) */
struct IgnitionSystem {
	const IgnitionSystem_const* const constData;

	/* data send ports */

	/*--------------------- attributes ---------------------*/
	 int32 priority;
	 int32 priority2;
	 float64 recvfirsttime;
	 float64 recvairflowsensetime;
	 int32 airflowemer;
	 int32 airflowscen;
	 int32 airflowins;
	 int32 actor3_1_id;
	 int32 actor3_2_id;
	 int64 count;


	/* state machine variables */
	etInt16 state;
	etInt16 history[IGNITIONSYSTEM_HISTORY_SIZE];
};

void IgnitionSystem_init(IgnitionSystem* self);

void IgnitionSystem_receiveMessage(void* self, const void* ifitem, const etMessage* msg);


/*--------------------- user constructor/destructor ---------------------*/

/*--------------------- operations ---------------------*/


#endif /* _TEMPLATEMODEL_IGNITIONSYSTEM_H_ */

