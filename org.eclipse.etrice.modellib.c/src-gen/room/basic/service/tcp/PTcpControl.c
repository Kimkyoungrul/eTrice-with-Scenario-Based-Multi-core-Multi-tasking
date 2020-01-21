/**
 * @author generated by eTrice
 *
 * Source File of ProtocolClass PTcpControl
 * 
 */

#include "PTcpControl.h"
#include "debugging/etMSCLogger.h"
#include "PTcpControl_Utils.h"


/*--------------------- port methods */

void PTcpControlPort_connected(const PTcpControlPort* self) {
	ET_MSC_LOGGER_SYNC_ENTRY("PTcpControlPort", "connected")
		etPort_sendMessage(self, PTcpControl_OUT_connected, 0, NULL);
		ET_MSC_LOGGER_ASYNC_OUT(self->myInstName, "connected", self->peerInstName)
	ET_MSC_LOGGER_SYNC_EXIT
}

void PTcpControlReplPort_connected_broadcast(const PTcpControlReplPort* self) {
	int i;
	ET_MSC_LOGGER_SYNC_ENTRY("PTcpControlReplPort", "connected")
	for (i=0; i<((etReplPort*)self)->size; ++i) {
		etPort_sendMessage((&((etReplPort*)self)->ports[i].port), PTcpControl_OUT_connected, 0, NULL);
		ET_MSC_LOGGER_ASYNC_OUT(((etReplPort*)self)->ports[i].port.myInstName, "connected", ((etReplPort*)self)->ports[i].port.peerInstName)
	}
	ET_MSC_LOGGER_SYNC_EXIT
}

void PTcpControlReplPort_connected(const PTcpControlReplPort* self, int idx__et) {
	ET_MSC_LOGGER_SYNC_ENTRY("PTcpControlReplPort", "connected")
	if (0<=idx__et && idx__et<((etReplPort*)self)->size) {
		etPort_sendMessage((&((etReplPort*)self)->ports[idx__et].port), PTcpControl_OUT_connected, 0, NULL);
		ET_MSC_LOGGER_ASYNC_OUT(((etReplPort*)self)->ports[idx__et].port.myInstName, "connected", ((etReplPort*)self)->ports[idx__et].port.peerInstName)
	}
	ET_MSC_LOGGER_SYNC_EXIT
}


void PTcpControlPort_disconnected(const PTcpControlPort* self) {
	ET_MSC_LOGGER_SYNC_ENTRY("PTcpControlPort", "disconnected")
		etPort_sendMessage(self, PTcpControl_OUT_disconnected, 0, NULL);
		ET_MSC_LOGGER_ASYNC_OUT(self->myInstName, "disconnected", self->peerInstName)
	ET_MSC_LOGGER_SYNC_EXIT
}

void PTcpControlReplPort_disconnected_broadcast(const PTcpControlReplPort* self) {
	int i;
	ET_MSC_LOGGER_SYNC_ENTRY("PTcpControlReplPort", "disconnected")
	for (i=0; i<((etReplPort*)self)->size; ++i) {
		etPort_sendMessage((&((etReplPort*)self)->ports[i].port), PTcpControl_OUT_disconnected, 0, NULL);
		ET_MSC_LOGGER_ASYNC_OUT(((etReplPort*)self)->ports[i].port.myInstName, "disconnected", ((etReplPort*)self)->ports[i].port.peerInstName)
	}
	ET_MSC_LOGGER_SYNC_EXIT
}

void PTcpControlReplPort_disconnected(const PTcpControlReplPort* self, int idx__et) {
	ET_MSC_LOGGER_SYNC_ENTRY("PTcpControlReplPort", "disconnected")
	if (0<=idx__et && idx__et<((etReplPort*)self)->size) {
		etPort_sendMessage((&((etReplPort*)self)->ports[idx__et].port), PTcpControl_OUT_disconnected, 0, NULL);
		ET_MSC_LOGGER_ASYNC_OUT(((etReplPort*)self)->ports[idx__et].port.myInstName, "disconnected", ((etReplPort*)self)->ports[idx__et].port.peerInstName)
	}
	ET_MSC_LOGGER_SYNC_EXIT
}


void PTcpControlPort_error(const PTcpControlPort* self) {
	ET_MSC_LOGGER_SYNC_ENTRY("PTcpControlPort", "error")
		etPort_sendMessage(self, PTcpControl_OUT_error, 0, NULL);
		ET_MSC_LOGGER_ASYNC_OUT(self->myInstName, "error", self->peerInstName)
	ET_MSC_LOGGER_SYNC_EXIT
}

void PTcpControlReplPort_error_broadcast(const PTcpControlReplPort* self) {
	int i;
	ET_MSC_LOGGER_SYNC_ENTRY("PTcpControlReplPort", "error")
	for (i=0; i<((etReplPort*)self)->size; ++i) {
		etPort_sendMessage((&((etReplPort*)self)->ports[i].port), PTcpControl_OUT_error, 0, NULL);
		ET_MSC_LOGGER_ASYNC_OUT(((etReplPort*)self)->ports[i].port.myInstName, "error", ((etReplPort*)self)->ports[i].port.peerInstName)
	}
	ET_MSC_LOGGER_SYNC_EXIT
}

void PTcpControlReplPort_error(const PTcpControlReplPort* self, int idx__et) {
	ET_MSC_LOGGER_SYNC_ENTRY("PTcpControlReplPort", "error")
	if (0<=idx__et && idx__et<((etReplPort*)self)->size) {
		etPort_sendMessage((&((etReplPort*)self)->ports[idx__et].port), PTcpControl_OUT_error, 0, NULL);
		ET_MSC_LOGGER_ASYNC_OUT(((etReplPort*)self)->ports[idx__et].port.myInstName, "error", ((etReplPort*)self)->ports[idx__et].port.peerInstName)
	}
	ET_MSC_LOGGER_SYNC_EXIT
}

etInt32 PTcpControlReplPort_getReplication(const PTcpControlReplPort* self) {
	return ((etReplPort*)self)->size;
}



void PTcpControlConjPort_connect(const PTcpControlConjPort* self, DTcpControl* data__et) {
	ET_MSC_LOGGER_SYNC_ENTRY("PTcpControlConjPort", "connect")
		etPort_sendMessage(self, PTcpControl_IN_connect, sizeof(DTcpControl), data__et);
		ET_MSC_LOGGER_ASYNC_OUT(self->myInstName, "connect", self->peerInstName)
	ET_MSC_LOGGER_SYNC_EXIT
}

void PTcpControlConjReplPort_connect_broadcast(const PTcpControlConjReplPort* self, DTcpControl* data__et) {
	int i;
	ET_MSC_LOGGER_SYNC_ENTRY("PTcpControlConjReplPort", "connect")
	for (i=0; i<((etReplPort*)self)->size; ++i) {
		etPort_sendMessage((&((etReplPort*)self)->ports[i].port), PTcpControl_IN_connect, sizeof(DTcpControl), data__et);
		ET_MSC_LOGGER_ASYNC_OUT(((etReplPort*)self)->ports[i].port.myInstName, "connect", ((etReplPort*)self)->ports[i].port.peerInstName)
	}
	ET_MSC_LOGGER_SYNC_EXIT
}

void PTcpControlConjReplPort_connect(const PTcpControlConjReplPort* self, int idx__et, DTcpControl* data__et) {
	ET_MSC_LOGGER_SYNC_ENTRY("PTcpControlConjReplPort", "connect")
	if (0<=idx__et && idx__et<((etReplPort*)self)->size) {
		etPort_sendMessage((&((etReplPort*)self)->ports[idx__et].port), PTcpControl_IN_connect, sizeof(DTcpControl), data__et);
		ET_MSC_LOGGER_ASYNC_OUT(((etReplPort*)self)->ports[idx__et].port.myInstName, "connect", ((etReplPort*)self)->ports[idx__et].port.peerInstName)
	}
	ET_MSC_LOGGER_SYNC_EXIT
}


void PTcpControlConjPort_disconnect(const PTcpControlConjPort* self) {
	ET_MSC_LOGGER_SYNC_ENTRY("PTcpControlConjPort", "disconnect")
		etPort_sendMessage(self, PTcpControl_IN_disconnect, 0, NULL);
		ET_MSC_LOGGER_ASYNC_OUT(self->myInstName, "disconnect", self->peerInstName)
	ET_MSC_LOGGER_SYNC_EXIT
}

void PTcpControlConjReplPort_disconnect_broadcast(const PTcpControlConjReplPort* self) {
	int i;
	ET_MSC_LOGGER_SYNC_ENTRY("PTcpControlConjReplPort", "disconnect")
	for (i=0; i<((etReplPort*)self)->size; ++i) {
		etPort_sendMessage((&((etReplPort*)self)->ports[i].port), PTcpControl_IN_disconnect, 0, NULL);
		ET_MSC_LOGGER_ASYNC_OUT(((etReplPort*)self)->ports[i].port.myInstName, "disconnect", ((etReplPort*)self)->ports[i].port.peerInstName)
	}
	ET_MSC_LOGGER_SYNC_EXIT
}

void PTcpControlConjReplPort_disconnect(const PTcpControlConjReplPort* self, int idx__et) {
	ET_MSC_LOGGER_SYNC_ENTRY("PTcpControlConjReplPort", "disconnect")
	if (0<=idx__et && idx__et<((etReplPort*)self)->size) {
		etPort_sendMessage((&((etReplPort*)self)->ports[idx__et].port), PTcpControl_IN_disconnect, 0, NULL);
		ET_MSC_LOGGER_ASYNC_OUT(((etReplPort*)self)->ports[idx__et].port.myInstName, "disconnect", ((etReplPort*)self)->ports[idx__et].port.peerInstName)
	}
	ET_MSC_LOGGER_SYNC_EXIT
}

etInt32 PTcpControlConjReplPort_getReplication(const PTcpControlConjReplPort* self) {
	return ((etReplPort*)self)->size;
}



/*--------------------- debug helpers */

/* message names as strings for debugging (generate MSC) */
static const char* const PTcpControl_messageStrings[] = {"MIN", "connected","disconnected","error","connect", "disconnect", "MAX"};

const char* PTcpControl_getMessageString(int msg_id) {
	if (msg_id<PTcpControl_MSG_MIN || msg_id>PTcpControl_MSG_MAX+1){
		/* id out of range */
		return "Message ID out of range";
	}
	else{
		return PTcpControl_messageStrings[msg_id];
	}
}
