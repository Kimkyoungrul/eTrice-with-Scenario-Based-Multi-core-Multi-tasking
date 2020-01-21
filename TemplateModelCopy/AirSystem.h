/**
 * @author generated by eTrice
 *
 * Header File of ActorClass AirSystem
 *
 */

#ifndef _TEMPLATEMODEL_AIRSYSTEM_H_
#define _TEMPLATEMODEL_AIRSYSTEM_H_

#include "etDatatypes.h"
#include "messaging/etMessage.h"

/* include all referenced room classes */
#include "room/basic/service/timing/PTimer.h"
#include "TemplateModel/SendData.h"

/*--------------------- begin user code ---------------------*/
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
struct timespec airsysstart2,airsysstart,airsysend,throsensestart,throsenseend,pedalsensestart,pedalsenseend;
FILE *fp1;
FILE *fp2;
/*--------------------- end user code ---------------------*/

typedef struct AirSystem AirSystem;

/* const part of ActorClass (ROM) */
typedef struct AirSystem_const {
	const char* instName;

	/* simple ports */
	const SendDataPort throttlePort;
	const SendDataConjPort throttledata;
	const SendDataPort padalPort;
	const SendDataConjPort internalpedal;
	const SendDataPort Internalthrottle;

	/* data receive ports */

	/* saps */
	const PTimerConjPort timer;

	/* replicated ports */

	/* services */
} AirSystem_const;


/* constant for state machine data */
#define AIRSYSTEM_HISTORY_SIZE 2

/* variable part of ActorClass (RAM) */
struct AirSystem {
	const AirSystem_const* const constData;

	/* data send ports */

	/*--------------------- attributes ---------------------*/
	 float64 recvthrottlesensetime;
	 float64 recvthrottlesensefirsttime;
	 float64 recvpedalfirsttime;
	 float64 recvpedalsensetime;
	 int64 pedalscen;
	 int64 pedalins;
	 int64 throttlescen;
	 int64 throttleins;
	 int32 pedalemer;
	 int32 throttleemer;
	 int32 count2;
	 int32 count3;
	 int32 count4;
	 int32 actor1_1_id;
	 int32 actor1_2_id;
	 int32 actor2_1_id;
	 int32 actor2_2_id;


	/* state machine variables */
	etInt16 state;
	etInt16 history[AIRSYSTEM_HISTORY_SIZE];
};

void AirSystem_init(AirSystem* self);

void AirSystem_receiveMessage(void* self, const void* ifitem, const etMessage* msg);


/*--------------------- user constructor/destructor ---------------------*/

/*--------------------- operations ---------------------*/


#endif /* _TEMPLATEMODEL_AIRSYSTEM_H_ */

