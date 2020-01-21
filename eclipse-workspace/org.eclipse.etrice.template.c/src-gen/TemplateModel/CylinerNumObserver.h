/**
 * @author generated by eTrice
 *
 * Header File of ActorClass CylinerNumObserver
 *
 */

#ifndef _TEMPLATEMODEL_CYLINERNUMOBSERVER_H_
#define _TEMPLATEMODEL_CYLINERNUMOBSERVER_H_

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
struct timespec cylinerstart,cylinerend,cylinerstart2,cylinerend2;
/*--------------------- end user code ---------------------*/

typedef struct CylinerNumObserver CylinerNumObserver;

/* const part of ActorClass (ROM) */
typedef struct CylinerNumObserver_const {
	const char* instName;

	/* simple ports */
	const SendDataPort cylinernum1Port;
	const SendDataPort cylinernum2Port;

	/* data receive ports */

	/* saps */
	const PTimerConjPort timer;

	/* replicated ports */

	/* services */
} CylinerNumObserver_const;


/* constant for state machine data */
#define CYLINERNUMOBSERVER_HISTORY_SIZE 2

/* variable part of ActorClass (RAM) */
struct CylinerNumObserver {
	const CylinerNumObserver_const* const constData;

	/* data send ports */

	/*--------------------- attributes ---------------------*/


	/* state machine variables */
	etInt16 state;
	etInt16 history[CYLINERNUMOBSERVER_HISTORY_SIZE];
};

void CylinerNumObserver_init(CylinerNumObserver* self);

void CylinerNumObserver_receiveMessage(void* self, const void* ifitem, const etMessage* msg);


/*--------------------- user constructor/destructor ---------------------*/

/*--------------------- operations ---------------------*/


#endif /* _TEMPLATEMODEL_CYLINERNUMOBSERVER_H_ */

