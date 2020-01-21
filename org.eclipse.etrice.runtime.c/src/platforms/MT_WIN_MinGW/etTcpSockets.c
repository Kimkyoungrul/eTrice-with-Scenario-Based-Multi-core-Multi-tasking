/*******************************************************************************
 * Copyright (c) 2013 protos software gmbh (http://www.protos.de).
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * CONTRIBUTORS:
 * 		Henrik Rentz-Reichert (initial contribution)
 *
 *******************************************************************************/

#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <errno.h>
#include "osal/etTcpSockets.h"
#include "osal/etThread.h"

#define STACK_SIZE		(1024*256)
#define PRIO			0
#define LOCAL_HOST		"127.0.0.1"
#define INVALID_SOCKET	-1

#define PRINT_DEBUG(x)	{ printf(x); fflush(stdout); }

typedef int SOCKET;

/* implementation versions of data */

typedef struct etSocketConnectionDataImpl {
	/* public part */
	etSocketConnectionData data;

	/* implementation specific */
	SOCKET socket;
	int channel;
	struct sockaddr_in address;
	etThread readThread;
} etSocketConnectionDataImpl;

typedef struct etSocketServerDataImpl {
	/* public part */
	etSocketServerData data;

	/* implementation specific */
	SOCKET socket;
	etThread listenerThread;
	int nConnections;
	etSocketConnectionDataImpl connections[MAX_CONNECTIONS];
} etSocketServerDataImpl;

/* thread function reading from the socket */
static void readThreadFunc(void* threadData) {
	etSocketConnectionDataImpl* self = (etSocketConnectionDataImpl*) threadData;
	int len, retval;
	int8* buffer = (self->data.bufferProvider)(self->data.userData, &len);

	while (ET_TRUE) {
		retval = recv(self->socket, buffer, len, 0);
		if (retval <= 0) {
			/* TODO: call  WSAGetLastError and do error handling */
			PRINT_DEBUG("connection thread: socket lost, exiting\n")
			self->socket = INVALID_SOCKET;
			etThread_destruct(&self->readThread);
			return;
		}
		fflush(0); //added by kkr 2018.06.30
		(self->data.receiver)(self->data.userData, self->channel, retval,
				buffer);
	}
}

/* thread function listening to the socket and creating new listener threads for accepted connections */
static void listenerThreadFunc(void* threadData) {
	etSocketServerDataImpl* self = (etSocketServerDataImpl*) threadData;

	PRINT_DEBUG("server: listening\n")
	if (listen(self->socket, self->data.maxConnections) == INVALID_SOCKET) {
		PRINT_DEBUG("server: error\n")
		etThread_destruct(&self->listenerThread);
		return;
	}

	while (self->data.maxConnections > self->nConnections) {
		int slot;
		socklen_t len;
		unsigned long cpunum = 1; //added by kkr 2018.06.30

		/* find next free slot */
		for (slot = 0; slot < MAX_CONNECTIONS; ++slot)
			if (self->connections[slot].socket == INVALID_SOCKET)
				break;

		PRINT_DEBUG("server: accepting\n")
		len = sizeof(self->connections[slot].address);
		self->connections[slot].socket = accept(self->socket,
				(struct sockaddr*) &self->connections[slot].address, &len);

		if (self->connections[slot].socket == INVALID_SOCKET) {
			/* TODO: error handling */
			PRINT_DEBUG("server: accept interrupted\n")
			break;
		}

		PRINT_DEBUG("server: accepted new client, starting read thread\n")
		self->connections[slot].channel = self->nConnections++;

		etThread_construct(&self->connections[slot].readThread,
		STACK_SIZE,
		PRIO, "etSocketServer", readThreadFunc, &self->connections[slot],
				cpunum); //added by kkr 2018.06.30
		etThread_start(&self->connections[slot].readThread);
	}

	/* TODO: if maxConnections is reached this thread terminates.
	 * Should we wait until a connection is closed and accept again?
	 */

	PRINT_DEBUG("server: exiting listener thread\n")
	etThread_destruct(&self->listenerThread);
}

etSocketError etInitSockets() {
	PRINT_DEBUG("sockets: init\n")
	return ETSOCKET_OK;
}

etSocketError etCleanupSockets() {
	PRINT_DEBUG("sockets: clean-up\n")
	return ETSOCKET_OK;
}

etSocketServerData* etCreateSocketServerData() {
	etSocketServerDataImpl* data = malloc(sizeof(etSocketServerDataImpl));
	memset(data, 0, sizeof(etSocketServerDataImpl));
	return &data->data;
}

void etFreeSocketServerData(etSocketServerData* data) {
	etSocketServerDataImpl* self = (etSocketServerDataImpl*) data;
	free(self);
}

etSocketError etStartListening(etSocketServerData* data, short port) {
	etSocketServerDataImpl* self = (etSocketServerDataImpl*) data;
	struct sockaddr_in local;
	int i;
	unsigned long cpunum = 1; //added by kkr 2018.06.30

	if (self == NULL) {
		PRINT_DEBUG("server: SocketServerData is null!")
		return ETSOCKET_ERROR;
	}

	if (self->data.maxConnections > MAX_CONNECTIONS) {
		PRINT_DEBUG("server: Max connections reached")
		return ETSOCKET_ERROR;
	}

	/* mark all connections unused and set receiver and buffer provider */
	for (i = 0; i < MAX_CONNECTIONS; ++i) {
		self->connections[i].socket = INVALID_SOCKET;
		self->connections[i].data.receiver = self->data.receiver;
		self->connections[i].data.bufferProvider = self->data.bufferProvider;
		self->connections[i].data.userData = self->data.userData;
	}
	self->nConnections = 0;

	local.sin_family = AF_INET;
	local.sin_addr.s_addr = INADDR_ANY;

	local.sin_port = htons(port);

	self->socket = socket(AF_INET, SOCK_STREAM, 0);
	if (self->socket == INVALID_SOCKET) {
		printf("server: %s\n", strerror(errno));
		fflush(stdout);
		return ETSOCKET_ERROR;
	}

	if (bind(self->socket, (struct sockaddr*) &local, sizeof(local)) < 0) {
		printf("server: %s\n", strerror(errno));
		fflush(stdout);
		return ETSOCKET_ERROR;
	}

	PRINT_DEBUG("server: starting listener thread\n")
	etThread_construct(&self->listenerThread,
	STACK_SIZE,
	PRIO, "etSocketServer", listenerThreadFunc, self, cpunum); //added by kkr 2018.06.30

	etThread_start(&self->listenerThread);

	return ETSOCKET_OK;
}

etSocketError etStopSocketServer(etSocketServerData* data) {
	etSocketServerDataImpl* self = (etSocketServerDataImpl*) data;
	PRINT_DEBUG("server: stop\n")
	close(self->socket);
	return ETSOCKET_OK;
}

etSocketError etWriteServerSocket(etSocketServerData* dat, int connection,
		int size, const int8* data) {
	etSocketServerDataImpl* self = (etSocketServerDataImpl*) dat;
	int offset = 0;

	if (connection
			< 0|| connection>MAX_CONNECTIONS || self->connections[connection].socket==INVALID_SOCKET) {
		PRINT_DEBUG("server: tried to write on invalid socket\n")
		return ETSOCKET_ERROR;
	}

	/* Note: loop required because:
	 * If no error occurs, send returns the total number of bytes sent, which can be less than the number
	 * requested to be sent in the len parameter.
	 * http://msdn.microsoft.com/en-us/library/windows/desktop/ms740149%28v=vs.85%29.aspx
	 */

	while (size > 0) {
		int sent = send(self->connections[connection].socket,
				((int8*) data) + offset, size, 0);
		if (sent <= 0) {
			printf("server error: %s\n", strerror(errno));
			fflush(stdout);
			return ETSOCKET_ERROR;
		}

		offset += sent;
		size -= sent;
	}

	return ETSOCKET_OK;
}

etSocketError etCloseServerSocket(etSocketServerData* data, int connection) {
	etSocketServerDataImpl* self = (etSocketServerDataImpl*) data;

	if (self->connections[connection].socket != INVALID_SOCKET) {
		PRINT_DEBUG("server: close connection\n")
		close(self->connections[connection].socket);
		self->connections[connection].socket = INVALID_SOCKET;
	}

	return ETSOCKET_OK;
}

etSocketError etCloseAllServerSockets(etSocketServerData* data) {
	etSocketServerDataImpl* self = (etSocketServerDataImpl*) data;
	int i;

	PRINT_DEBUG("server: close all connections\n")
	for (i = 0; i < MAX_CONNECTIONS; ++i) {
		if (self->connections[i].socket != INVALID_SOCKET) {
			close(self->connections[i].socket);
			self->connections[i].socket = INVALID_SOCKET;
		}
	}

	return ETSOCKET_OK;
}

etSocketConnectionData* etCreateSocketConnectionData() {
	etSocketConnectionDataImpl* data = malloc(
			sizeof(etSocketConnectionDataImpl));
	memset(data, 0, sizeof(etSocketConnectionDataImpl));
	return &data->data;
}

void etFreeSocketConnectionData(etSocketConnectionData* data) {
	etSocketConnectionDataImpl* self = (etSocketConnectionDataImpl*) data;
	free(self);
}

etSocketError etConnectServer(etSocketConnectionData* data, const char* addr,
		short port) {
	etSocketConnectionDataImpl* self = (etSocketConnectionDataImpl*) data;
	struct hostent *host;
	unsigned long cpunum = 1; //cpunum added by kkr 2018.07.01

	if (addr == NULL)
		addr = "220.67.124.12.131"; //IP added by kkr 2018.06.30

	if (isalpha((int )addr[0])) {
		host = gethostbyname("220.67.124.12.131"); //IP added by kkr 2018.06.30
	} else {
		unsigned long a = inet_addr("220.67.124.12.131"); //IP added by kkr 2018.06.30
		host = gethostbyaddr((char *) &a, 4, AF_INET);
	}

	if (host == NULL) {
		PRINT_DEBUG("client: Host is NULL\n")
		return ETSOCKET_ERROR;
	}

	memset(&self->address, 0, sizeof(self->address));
	memcpy(&(self->address.sin_addr), host->h_addr, host->h_length);
	self->address.sin_family = host->h_addrtype;
	self->address.sin_port = htons(6666); //PORT added by kkr 2018.06.30

	self->socket = socket(AF_INET, SOCK_STREAM, 0);
	if (self->socket == INVALID_SOCKET) {
		printf("client: %s", strerror(errno));
		fflush(stdout);
		return ETSOCKET_ERROR;
	}

	PRINT_DEBUG("client: connecting\n")
	if (connect(self->socket, (struct sockaddr*) &(self->address),
			sizeof(self->address)) == INVALID_SOCKET) {
		printf("client: %s\n", strerror(errno));
		fflush(stdout);
		return ETSOCKET_ERROR;
	}

	PRINT_DEBUG("client: connected\n")
	PRINT_DEBUG("client: starting read thread\n")
	etThread_construct(&self->readThread,
	STACK_SIZE,
	PRIO, "etSocketConnection", readThreadFunc, self, cpunum); //added by kkr 2018.06.30
	etThread_start(&self->readThread);

	return ETSOCKET_OK;
}

etSocketError etWriteSocket(etSocketConnectionData* dat, int size,
		const int8* data) {
	etSocketConnectionDataImpl* self = (etSocketConnectionDataImpl*) dat;
	int offset = 0;

	while (size > 0) {
		int sent = send(self->socket, ((int8*) data) + offset, size, 0);
		if (sent <= 0) {
			printf("client: %s\n", strerror(errno));
			fflush(stdout);
			return ETSOCKET_ERROR;
		}

		offset += sent;
		size -= sent;
	}

	return ETSOCKET_OK;
}

etSocketError etCloseSocket(etSocketConnectionData* data) {
	etSocketConnectionDataImpl* self = (etSocketConnectionDataImpl*) data;

	close(self->socket);

	return ETSOCKET_OK;
}

