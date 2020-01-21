/**
 * @author generated by eTrice
 *
 * Source File of ActorClass pedalfeel
 *
 */

#include "pedalfeel.h"

#include "modelbase/etActor.h"
#include "debugging/etLogger.h"
#include "debugging/etMSCLogger.h"
#include "etUnit/etUnit.h"
#include "base/etMemory.h"

#include "TemplateModel/SendData.h"

#include "pedalfeel_Utils.h"


/* interface item IDs */
enum interface_items {
	IFITEM_feeldata = 1,
	IFITEM_feeldatasend = 2
};

/* state IDs */
enum state_ids {
	NO_STATE = 0,
	STATE_TOP = 1,
	STATE_waitingData = 2,
	STATE_MAX = 3
};

/* transition chains */
enum ChainIDs {
	CHAIN_TRANS_INITIAL_TO__waitingData = 1,
	CHAIN_TRANS_tr0_FROM_waitingData_TO_waitingData_BY_sendDatafeeldata_tr0 = 2
};

/* triggers */
enum triggers {
	POLLING = 0,
	TRIG_feeldata__sendData = IFITEM_feeldata + EVT_SHIFT*SendData_IN_sendData,
	TRIG_feeldata__sendchangestate = IFITEM_feeldata + EVT_SHIFT*SendData_IN_sendchangestate,
	TRIG_feeldatasend__recursive2 = IFITEM_feeldatasend + EVT_SHIFT*SendData_OUT_recursive2,
	TRIG_feeldatasend__recvchangestate = IFITEM_feeldatasend + EVT_SHIFT*SendData_OUT_recvchangestate
};

/* state names */
static char* stateStrings[] = {"<no state>","<top>","waitingData"
};

static void setState(pedalfeel* self, etInt16 new_state) {
	self->state = new_state;
	ET_MSC_LOGGER_CHANGE_STATE(self->constData->instName, stateStrings[new_state])
}

static etInt16 getState(pedalfeel* self) {
	return self->state;
}

/* Entry and Exit Codes */

/* Action Codes */
static void action_TRANS_tr0_FROM_waitingData_TO_waitingData_BY_sendDatafeeldata_tr0(pedalfeel* self, const InterfaceItemBase* ifitem, ADASMessage* data) {
    ADASMessage ADASmessage;
    if(CHECKTIME==6||CHECKTIME==31){
    clock_gettime(CLOCK_MONOTONIC,&feelstart);
    ADASmessage.actor_3 = ((1.0e+9*(feelstart.tv_sec))+(feelstart.tv_nsec))/1.0e+6;
    pthread_t id;
    id=pthread_self();
    ADASmessage.actor_3_id=(int)id;
    }
    ADASmessage.instanceID = data->instanceID;
    ADASmessage.actor_1 = data->actor_1;
    ADASmessage.actor_2=data->actor_2;
    ADASmessage.actor_1_id=data->actor_1_id;
    ADASmessage.actor_2_id=data->actor_2_id;
    //ADASmessage.prior=2;
    for(int i =0;i<ONE_Milli_SEC_CONUT*0.783*MULCCS;i++){
    }
    feeldatasend_sendData(&ADASmessage);
}

/* State Switch Methods */
/**
 * calls exit codes while exiting from the current state to one of its
 * parent states while remembering the history
 * @param current__et - the current state
 * @param to - the final parent state
 */
static void exitTo(pedalfeel* self, etInt16 current__et, etInt16 to) {
	while (current__et!=to) {
		switch (current__et) {
			case STATE_waitingData:
				self->history[STATE_TOP] = STATE_waitingData;
				current__et = STATE_TOP;
				break;
			default:
				/* should not occur */
				break;
		}
	}
}

/**
 * calls action, entry and exit codes along a transition chain. The generic data are cast to typed data
 * matching the trigger of this chain. The ID of the final state is returned
 * @param chain__et - the chain ID
 * @param generic_data__et - the generic data pointer
 * @return the +/- ID of the final state either with a positive sign, that indicates to execute the state's entry code, or a negative sign vice versa
 */
static etInt16 executeTransitionChain(pedalfeel* self, int chain__et, const InterfaceItemBase* ifitem, void* generic_data__et) {
	switch (chain__et) {
		case CHAIN_TRANS_INITIAL_TO__waitingData:
		{
			return STATE_waitingData;
		}
		case CHAIN_TRANS_tr0_FROM_waitingData_TO_waitingData_BY_sendDatafeeldata_tr0:
		{
			ADASMessage* data = ((ADASMessage*) generic_data__et);
			action_TRANS_tr0_FROM_waitingData_TO_waitingData_BY_sendDatafeeldata_tr0(self, ifitem, data);
			return STATE_waitingData;
		}
			default:
				/* should not occur */
				break;
	}
	return NO_STATE;
}

/**
 * calls entry codes while entering a state's history. The ID of the final leaf state is returned
 * @param state__et - the state which is entered
 * @return - the ID of the final leaf state
 */
static etInt16 enterHistory(pedalfeel* self, etInt16 state__et) {
	if (state__et >= STATE_MAX) {
		state__et = (etInt16) (state__et - STATE_MAX);
	}
	while (ET_TRUE) {
		switch (state__et) {
			case STATE_waitingData:
				/* in leaf state: return state id */
				return STATE_waitingData;
			case STATE_TOP:
				state__et = self->history[STATE_TOP];
				break;
			default:
				/* should not occur */
				break;
		}
	}
	/* return NO_STATE; // required by CDT but detected as unreachable by JDT because of while (true) */
}

static void pedalfeel_executeInitTransition(pedalfeel* self) {
	int chain__et = CHAIN_TRANS_INITIAL_TO__waitingData;
	etInt16 next__et = executeTransitionChain(self, chain__et, NULL, NULL);
	next__et = enterHistory(self, next__et);
	setState(self, next__et);
}

/* receiveEvent contains the main implementation of the FSM */
static void pedalfeel_receiveEventInternal(pedalfeel* self, InterfaceItemBase* ifitem, int localId, int evt, void* generic_data__et) {
	int trigger__et = localId + EVT_SHIFT*evt;
	int chain__et = NOT_CAUGHT;
	etInt16 catching_state__et = NO_STATE;
	((void)trigger__et);	/* avoids unused warning */

	if (!handleSystemEvent(ifitem, evt, generic_data__et)) {
		switch (getState(self)) {
		    case STATE_waitingData:
		        switch(trigger__et) {
		                case TRIG_feeldata__sendData:
		                    {
		                        chain__et = CHAIN_TRANS_tr0_FROM_waitingData_TO_waitingData_BY_sendDatafeeldata_tr0;
		                        catching_state__et = STATE_TOP;
		                    }
		                break;
		                default:
		                    /* should not occur */
		                    break;
		        }
		        break;
		    default:
		        /* should not occur */
		        break;
		}
	}
	if (chain__et != NOT_CAUGHT) {
		exitTo(self, getState(self), catching_state__et);
		{
			etInt16 next__et = executeTransitionChain(self, chain__et, ifitem, generic_data__et);
			next__et = enterHistory(self, next__et);
			setState(self, next__et);
		}
	}
}
static void pedalfeel_receiveEvent(pedalfeel* self, InterfaceItemBase* ifitem, int evt, void* generic_data__et) {
	int localId = (ifitem==NULL)? 0 : ifitem->localId;
	pedalfeel_receiveEventInternal(self, ifitem, localId, evt, generic_data__et);
}

void pedalfeel_init(pedalfeel* self){
	ET_MSC_LOGGER_SYNC_ENTRY("pedalfeel", "init")
	self->state = STATE_TOP;
	{
		int i;
		for (i=0; i<PEDALFEEL_HISTORY_SIZE; ++i)
			self->history[i] = NO_STATE;
	}
	pedalfeel_executeInitTransition(self);
	ET_MSC_LOGGER_SYNC_EXIT
}


void pedalfeel_receiveMessage(void* self, const void* ifitem, const etMessage* msg){
	ET_MSC_LOGGER_SYNC_ENTRY("pedalfeel", "_receiveMessage")
	pedalfeel_receiveEvent(self, (etPort*)ifitem, msg->evtID, (void*)(((char*)msg)+MEM_CEIL(sizeof(etMessage))));

	ET_MSC_LOGGER_SYNC_EXIT
}


/*--------------------- user constructor/destructor ---------------------*/

/*--------------------- operations ---------------------*/

