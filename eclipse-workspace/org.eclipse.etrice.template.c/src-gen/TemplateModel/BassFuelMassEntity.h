/**
 * @author generated by eTrice
 *
 * Header File of ActorClass BassFuelMassEntity
 *
 */

#ifndef _TEMPLATEMODEL_BASSFUELMASSENTITY_H_
#define _TEMPLATEMODEL_BASSFUELMASSENTITY_H_

#include "etDatatypes.h"
#include "messaging/etMessage.h"

/* include all referenced room classes */
#include "TemplateModel/SendData.h"

/*--------------------- begin user code ---------------------*/
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
struct timespec bassfuelstart,bassfuelend;
/*--------------------- end user code ---------------------*/

typedef struct BassFuelMassEntity BassFuelMassEntity;

/* const part of ActorClass (ROM) */
typedef struct BassFuelMassEntity_const {
	const char* instName;

	/* simple ports */
	const SendDataPort bassfueldata;
	const SendDataConjPort bassfueldatasend;

	/* data receive ports */

	/* saps */

	/* replicated ports */

	/* services */
} BassFuelMassEntity_const;


/* constant for state machine data */
#define BASSFUELMASSENTITY_HISTORY_SIZE 2

/* variable part of ActorClass (RAM) */
struct BassFuelMassEntity {
	const BassFuelMassEntity_const* const constData;

	/* data send ports */

	/*--------------------- attributes ---------------------*/


	/* state machine variables */
	etInt16 state;
	etInt16 history[BASSFUELMASSENTITY_HISTORY_SIZE];
};

void BassFuelMassEntity_init(BassFuelMassEntity* self);

void BassFuelMassEntity_receiveMessage(void* self, const void* ifitem, const etMessage* msg);


/*--------------------- user constructor/destructor ---------------------*/

/*--------------------- operations ---------------------*/


#endif /* _TEMPLATEMODEL_BASSFUELMASSENTITY_H_ */
