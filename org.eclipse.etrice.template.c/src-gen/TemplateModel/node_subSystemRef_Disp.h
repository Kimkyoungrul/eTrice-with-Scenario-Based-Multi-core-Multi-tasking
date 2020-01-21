/* modified by kkr*/
#include "messaging/etMessageReceiver.h"
#include "debugging/etLogger.h"
#include "debugging/etMSCLogger.h"
static void MsgDispatcher_DefaultPhysicalThread_poll(void){
	ET_MSC_LOGGER_SYNC_ENTRY("MsgDispatcher_DefaultPhysicalThread", "execute")
	ATimingService_execute((void*)&_LogSys_subSystemRef_timingService);
	ET_MSC_LOGGER_SYNC_EXIT
}

static etBool MsgDispatcher_AllThread_receiveMessage(const etMessage* msg){
	ET_MSC_LOGGER_SYNC_ENTRY("MsgDispatcher_AllThread", "receiveMessage")
	switch(msg->address){
		case MESSAGESERVICE_ADDRESS:
			if (msg->evtID == etSystemProtocol_IN_poll) {
				MsgDispatcher_DefaultPhysicalThread_poll();
			}
			else if(msg->evtID == etSystemProtocol_IN_terminate)
				return ET_FALSE;
			break;
		case 89+BASE_ADDRESS:
			ET_MSC_LOGGER_ASYNC_IN(
				_LogSys_subSystemRef_timingService_const.timer.ports[0].port.peerInstName,
				PTimer_getMessageString(msg->evtID),
				_LogSys_subSystemRef_timingService_const.timer.ports[0].port.myInstName
				)
			ATimingService_receiveMessage((void*)&_LogSys_subSystemRef_timingService,&_LogSys_subSystemRef_timingService_const.timer.ports[0].port, msg);
		break;
		case 90+BASE_ADDRESS:
			ET_MSC_LOGGER_ASYNC_IN(
				_LogSys_subSystemRef_timingService_const.timer.ports[1].port.peerInstName,
				PTimer_getMessageString(msg->evtID),
				_LogSys_subSystemRef_timingService_const.timer.ports[1].port.myInstName
				)
			ATimingService_receiveMessage((void*)&_LogSys_subSystemRef_timingService,&_LogSys_subSystemRef_timingService_const.timer.ports[1].port, msg);
		break;
		case 91+BASE_ADDRESS:
			ET_MSC_LOGGER_ASYNC_IN(
				_LogSys_subSystemRef_timingService_const.timer.ports[2].port.peerInstName,
				PTimer_getMessageString(msg->evtID),
				_LogSys_subSystemRef_timingService_const.timer.ports[2].port.myInstName
				)
			ATimingService_receiveMessage((void*)&_LogSys_subSystemRef_timingService,&_LogSys_subSystemRef_timingService_const.timer.ports[2].port, msg);
		break;
		case 92+BASE_ADDRESS:
			ET_MSC_LOGGER_ASYNC_IN(
				_LogSys_subSystemRef_timingService_const.timer.ports[3].port.peerInstName,
				PTimer_getMessageString(msg->evtID),
				_LogSys_subSystemRef_timingService_const.timer.ports[3].port.myInstName
				)
			ATimingService_receiveMessage((void*)&_LogSys_subSystemRef_timingService,&_LogSys_subSystemRef_timingService_const.timer.ports[3].port, msg);
		break;
		case 93+BASE_ADDRESS:
			ET_MSC_LOGGER_ASYNC_IN(
				_LogSys_subSystemRef_timingService_const.timer.ports[4].port.peerInstName,
				PTimer_getMessageString(msg->evtID),
				_LogSys_subSystemRef_timingService_const.timer.ports[4].port.myInstName
				)
			ATimingService_receiveMessage((void*)&_LogSys_subSystemRef_timingService,&_LogSys_subSystemRef_timingService_const.timer.ports[4].port, msg);
		break;
		case 94+BASE_ADDRESS:
			ET_MSC_LOGGER_ASYNC_IN(
				_LogSys_subSystemRef_timingService_const.timer.ports[5].port.peerInstName,
				PTimer_getMessageString(msg->evtID),
				_LogSys_subSystemRef_timingService_const.timer.ports[5].port.myInstName
				)
			ATimingService_receiveMessage((void*)&_LogSys_subSystemRef_timingService,&_LogSys_subSystemRef_timingService_const.timer.ports[5].port, msg);
		break;
		case 95+BASE_ADDRESS:
			ET_MSC_LOGGER_ASYNC_IN(
				_LogSys_subSystemRef_timingService_const.timer.ports[6].port.peerInstName,
				PTimer_getMessageString(msg->evtID),
				_LogSys_subSystemRef_timingService_const.timer.ports[6].port.myInstName
				)
			ATimingService_receiveMessage((void*)&_LogSys_subSystemRef_timingService,&_LogSys_subSystemRef_timingService_const.timer.ports[6].port, msg);
		break;
		case 96+BASE_ADDRESS:
			ET_MSC_LOGGER_ASYNC_IN(
				_LogSys_subSystemRef_timingService_const.timer.ports[7].port.peerInstName,
				PTimer_getMessageString(msg->evtID),
				_LogSys_subSystemRef_timingService_const.timer.ports[7].port.myInstName
				)
			ATimingService_receiveMessage((void*)&_LogSys_subSystemRef_timingService,&_LogSys_subSystemRef_timingService_const.timer.ports[7].port, msg);
		break;
		case 97+BASE_ADDRESS:
			ET_MSC_LOGGER_ASYNC_IN(
				_LogSys_subSystemRef_timingService_const.timer.ports[8].port.peerInstName,
				PTimer_getMessageString(msg->evtID),
				_LogSys_subSystemRef_timingService_const.timer.ports[8].port.myInstName
				)
			ATimingService_receiveMessage((void*)&_LogSys_subSystemRef_timingService,&_LogSys_subSystemRef_timingService_const.timer.ports[8].port, msg);
		break;
		case 98+BASE_ADDRESS:
			ET_MSC_LOGGER_ASYNC_IN(
				_LogSys_subSystemRef_timingService_const.timer.ports[9].port.peerInstName,
				PTimer_getMessageString(msg->evtID),
				_LogSys_subSystemRef_timingService_const.timer.ports[9].port.myInstName
				)
			ATimingService_receiveMessage((void*)&_LogSys_subSystemRef_timingService,&_LogSys_subSystemRef_timingService_const.timer.ports[9].port, msg);
		break;
		case 99+BASE_ADDRESS:
			ET_MSC_LOGGER_ASYNC_IN(
				_LogSys_subSystemRef_timingService_const.timer.ports[10].port.peerInstName,
				PTimer_getMessageString(msg->evtID),
				_LogSys_subSystemRef_timingService_const.timer.ports[10].port.myInstName
				)
			ATimingService_receiveMessage((void*)&_LogSys_subSystemRef_timingService,&_LogSys_subSystemRef_timingService_const.timer.ports[10].port, msg);
		break;
		case 10+BASE_ADDRESS:
			ET_MSC_LOGGER_ASYNC_IN(
				((etPort*)&_LogSys_subSystemRef_topActor_FuelingSystem_AirMassFlow_const.airmassdatasend)->peerInstName,
				SendData_getMessageString(msg->evtID),
				((etPort*)&_LogSys_subSystemRef_topActor_FuelingSystem_AirMassFlow_const.airmassdatasend)->myInstName
				)
			AirMassFlowChanger_receiveMessage((void*)&_LogSys_subSystemRef_topActor_FuelingSystem_AirMassFlow,(etPort*)&_LogSys_subSystemRef_topActor_FuelingSystem_AirMassFlow_const.airmassdatasend, msg);
			break;
		case 12+BASE_ADDRESS:
			ET_MSC_LOGGER_ASYNC_IN(
				((etPort*)&_LogSys_subSystemRef_topActor_FuelingSystem_BassFuelMass_const.bassfueldata)->peerInstName,
				SendData_getMessageString(msg->evtID),
				((etPort*)&_LogSys_subSystemRef_topActor_FuelingSystem_BassFuelMass_const.bassfueldata)->myInstName
				)
			BassFuelMassEntity_receiveMessage((void*)&_LogSys_subSystemRef_topActor_FuelingSystem_BassFuelMass,(etPort*)&_LogSys_subSystemRef_topActor_FuelingSystem_BassFuelMass_const.bassfueldata, msg);
			break;
		case 13+BASE_ADDRESS:
			ET_MSC_LOGGER_ASYNC_IN(
				((etPort*)&_LogSys_subSystemRef_topActor_FuelingSystem_BassFuelMass_const.bassfueldatasend)->peerInstName,
				SendData_getMessageString(msg->evtID),
				((etPort*)&_LogSys_subSystemRef_topActor_FuelingSystem_BassFuelMass_const.bassfueldatasend)->myInstName
				)
			BassFuelMassEntity_receiveMessage((void*)&_LogSys_subSystemRef_topActor_FuelingSystem_BassFuelMass,(etPort*)&_LogSys_subSystemRef_topActor_FuelingSystem_BassFuelMass_const.bassfueldatasend, msg);
			break;
		case 15+BASE_ADDRESS:
			ET_MSC_LOGGER_ASYNC_IN(
				((etPort*)&_LogSys_subSystemRef_topActor_FuelingSystem_TransientFurlingCompensation_const.transientfueldata)->peerInstName,
				SendData_getMessageString(msg->evtID),
				((etPort*)&_LogSys_subSystemRef_topActor_FuelingSystem_TransientFurlingCompensation_const.transientfueldata)->myInstName
				)
			TransientFuelingCompensationEntity_receiveMessage((void*)&_LogSys_subSystemRef_topActor_FuelingSystem_TransientFurlingCompensation,(etPort*)&_LogSys_subSystemRef_topActor_FuelingSystem_TransientFurlingCompensation_const.transientfueldata, msg);
			break;
		case 16+BASE_ADDRESS:
			ET_MSC_LOGGER_ASYNC_IN(
				((etPort*)&_LogSys_subSystemRef_topActor_FuelingSystem_TransientFurlingCompensation_const.transientfueldatasend)->peerInstName,
				SendData_getMessageString(msg->evtID),
				((etPort*)&_LogSys_subSystemRef_topActor_FuelingSystem_TransientFurlingCompensation_const.transientfueldatasend)->myInstName
				)
			TransientFuelingCompensationEntity_receiveMessage((void*)&_LogSys_subSystemRef_topActor_FuelingSystem_TransientFurlingCompensation,(etPort*)&_LogSys_subSystemRef_topActor_FuelingSystem_TransientFurlingCompensation_const.transientfueldatasend, msg);
			break;
		case 18+BASE_ADDRESS:
			ET_MSC_LOGGER_ASYNC_IN(
				((etPort*)&_LogSys_subSystemRef_topActor_AirSystem_const.throttlePort)->peerInstName,
				SendData_getMessageString(msg->evtID),
				((etPort*)&_LogSys_subSystemRef_topActor_AirSystem_const.throttlePort)->myInstName
				)
			AirSystem_receiveMessage((void*)&_LogSys_subSystemRef_topActor_AirSystem,(etPort*)&_LogSys_subSystemRef_topActor_AirSystem_const.throttlePort, msg);
			break;
		case 19+BASE_ADDRESS:
			ET_MSC_LOGGER_ASYNC_IN(
				((etPort*)&_LogSys_subSystemRef_topActor_AirSystem_const.throttledata)->peerInstName,
				SendData_getMessageString(msg->evtID),
				((etPort*)&_LogSys_subSystemRef_topActor_AirSystem_const.throttledata)->myInstName
				)
			AirSystem_receiveMessage((void*)&_LogSys_subSystemRef_topActor_AirSystem,(etPort*)&_LogSys_subSystemRef_topActor_AirSystem_const.throttledata, msg);
			break;
		case 20+BASE_ADDRESS:
			ET_MSC_LOGGER_ASYNC_IN(
				((etPort*)&_LogSys_subSystemRef_topActor_AirSystem_const.padalPort)->peerInstName,
				SendData_getMessageString(msg->evtID),
				((etPort*)&_LogSys_subSystemRef_topActor_AirSystem_const.padalPort)->myInstName
				)
			AirSystem_receiveMessage((void*)&_LogSys_subSystemRef_topActor_AirSystem,(etPort*)&_LogSys_subSystemRef_topActor_AirSystem_const.padalPort, msg);
			break;
		case 21+BASE_ADDRESS:
			ET_MSC_LOGGER_ASYNC_IN(
				((etPort*)&_LogSys_subSystemRef_topActor_AirSystem_const.internalpedal)->peerInstName,
				SendData_getMessageString(msg->evtID),
				((etPort*)&_LogSys_subSystemRef_topActor_AirSystem_const.internalpedal)->myInstName
				)
			AirSystem_receiveMessage((void*)&_LogSys_subSystemRef_topActor_AirSystem,(etPort*)&_LogSys_subSystemRef_topActor_AirSystem_const.internalpedal, msg);
			break;
		case 22+BASE_ADDRESS:
			ET_MSC_LOGGER_ASYNC_IN(
				((etPort*)&_LogSys_subSystemRef_topActor_AirSystem_const.Internalthrottle)->peerInstName,
				SendData_getMessageString(msg->evtID),
				((etPort*)&_LogSys_subSystemRef_topActor_AirSystem_const.Internalthrottle)->myInstName
				)
			AirSystem_receiveMessage((void*)&_LogSys_subSystemRef_topActor_AirSystem,(etPort*)&_LogSys_subSystemRef_topActor_AirSystem_const.Internalthrottle, msg);
			break;
		case 25+BASE_ADDRESS:
			ET_MSC_LOGGER_ASYNC_IN(
				((etPort*)&_LogSys_subSystemRef_topActor_AirSystem_pedalvoter_const.pedalvoterdata)->peerInstName,
				SendData_getMessageString(msg->evtID),
				((etPort*)&_LogSys_subSystemRef_topActor_AirSystem_pedalvoter_const.pedalvoterdata)->myInstName
				)
			pedalvoter_receiveMessage((void*)&_LogSys_subSystemRef_topActor_AirSystem_pedalvoter,(etPort*)&_LogSys_subSystemRef_topActor_AirSystem_pedalvoter_const.pedalvoterdata, msg);
			break;
		case 26+BASE_ADDRESS:
			ET_MSC_LOGGER_ASYNC_IN(
				((etPort*)&_LogSys_subSystemRef_topActor_AirSystem_pedalvoter_const.feeldata)->peerInstName,
				SendData_getMessageString(msg->evtID),
				((etPort*)&_LogSys_subSystemRef_topActor_AirSystem_pedalvoter_const.feeldata)->myInstName
				)
			pedalvoter_receiveMessage((void*)&_LogSys_subSystemRef_topActor_AirSystem_pedalvoter,(etPort*)&_LogSys_subSystemRef_topActor_AirSystem_pedalvoter_const.feeldata, msg);
			break;
		case 28+BASE_ADDRESS:
			ET_MSC_LOGGER_ASYNC_IN(
				((etPort*)&_LogSys_subSystemRef_topActor_AirSystem_pedalfeel_const.feeldata)->peerInstName,
				SendData_getMessageString(msg->evtID),
				((etPort*)&_LogSys_subSystemRef_topActor_AirSystem_pedalfeel_const.feeldata)->myInstName
				)
			pedalfeel_receiveMessage((void*)&_LogSys_subSystemRef_topActor_AirSystem_pedalfeel,(etPort*)&_LogSys_subSystemRef_topActor_AirSystem_pedalfeel_const.feeldata, msg);
			break;
		case 29+BASE_ADDRESS:
			ET_MSC_LOGGER_ASYNC_IN(
				((etPort*)&_LogSys_subSystemRef_topActor_AirSystem_pedalfeel_const.feeldatasend)->peerInstName,
				SendData_getMessageString(msg->evtID),
				((etPort*)&_LogSys_subSystemRef_topActor_AirSystem_pedalfeel_const.feeldatasend)->myInstName
				)
			pedalfeel_receiveMessage((void*)&_LogSys_subSystemRef_topActor_AirSystem_pedalfeel,(etPort*)&_LogSys_subSystemRef_topActor_AirSystem_pedalfeel_const.feeldatasend, msg);
			break;
		case 3+BASE_ADDRESS:
			ET_MSC_LOGGER_ASYNC_IN(
				((etPort*)&_LogSys_subSystemRef_topActor_FuelingSystem_const.airflowPort)->peerInstName,
				SendData_getMessageString(msg->evtID),
				((etPort*)&_LogSys_subSystemRef_topActor_FuelingSystem_const.airflowPort)->myInstName
				)
			FuelingSystem_receiveMessage((void*)&_LogSys_subSystemRef_topActor_FuelingSystem,(etPort*)&_LogSys_subSystemRef_topActor_FuelingSystem_const.airflowPort, msg);
			break;
		case 31+BASE_ADDRESS:
			ET_MSC_LOGGER_ASYNC_IN(
				((etPort*)&_LogSys_subSystemRef_topActor_AirSystem_throttlecontroller_const.throttledata)->peerInstName,
				SendData_getMessageString(msg->evtID),
				((etPort*)&_LogSys_subSystemRef_topActor_AirSystem_throttlecontroller_const.throttledata)->myInstName
				)
			throttlecontroller_receiveMessage((void*)&_LogSys_subSystemRef_topActor_AirSystem_throttlecontroller,(etPort*)&_LogSys_subSystemRef_topActor_AirSystem_throttlecontroller_const.throttledata, msg);
			break;
		case 32+BASE_ADDRESS:
			ET_MSC_LOGGER_ASYNC_IN(
				((etPort*)&_LogSys_subSystemRef_topActor_AirSystem_throttlecontroller_const.throttledatasend)->peerInstName,
				SendData_getMessageString(msg->evtID),
				((etPort*)&_LogSys_subSystemRef_topActor_AirSystem_throttlecontroller_const.throttledatasend)->myInstName
				)
			throttlecontroller_receiveMessage((void*)&_LogSys_subSystemRef_topActor_AirSystem_throttlecontroller,(etPort*)&_LogSys_subSystemRef_topActor_AirSystem_throttlecontroller_const.throttledatasend, msg);
			break;
		case 34+BASE_ADDRESS:
			ET_MSC_LOGGER_ASYNC_IN(
				((etPort*)&_LogSys_subSystemRef_topActor_IgnitionSystem_const.airflowPort)->peerInstName,
				SendData_getMessageString(msg->evtID),
				((etPort*)&_LogSys_subSystemRef_topActor_IgnitionSystem_const.airflowPort)->myInstName
				)
			IgnitionSystem_receiveMessage((void*)&_LogSys_subSystemRef_topActor_IgnitionSystem,(etPort*)&_LogSys_subSystemRef_topActor_IgnitionSystem_const.airflowPort, msg);
			break;
		case 35+BASE_ADDRESS:
			ET_MSC_LOGGER_ASYNC_IN(
				((etPort*)&_LogSys_subSystemRef_topActor_IgnitionSystem_const.ignitiondata)->peerInstName,
				SendData_getMessageString(msg->evtID),
				((etPort*)&_LogSys_subSystemRef_topActor_IgnitionSystem_const.ignitiondata)->myInstName
				)
			IgnitionSystem_receiveMessage((void*)&_LogSys_subSystemRef_topActor_IgnitionSystem,(etPort*)&_LogSys_subSystemRef_topActor_IgnitionSystem_const.ignitiondata, msg);
			break;
		case 36+BASE_ADDRESS:
			ET_MSC_LOGGER_ASYNC_IN(
				((etPort*)&_LogSys_subSystemRef_topActor_IgnitionSystem_const.ignitionInternalIn)->peerInstName,
				SendData_getMessageString(msg->evtID),
				((etPort*)&_LogSys_subSystemRef_topActor_IgnitionSystem_const.ignitionInternalIn)->myInstName
				)
			IgnitionSystem_receiveMessage((void*)&_LogSys_subSystemRef_topActor_IgnitionSystem,(etPort*)&_LogSys_subSystemRef_topActor_IgnitionSystem_const.ignitionInternalIn, msg);
			break;
		case 37+BASE_ADDRESS:
			ET_MSC_LOGGER_ASYNC_IN(
				((etPort*)&_LogSys_subSystemRef_topActor_IgnitionSystem_const.ignitionInternalOut)->peerInstName,
				SendData_getMessageString(msg->evtID),
				((etPort*)&_LogSys_subSystemRef_topActor_IgnitionSystem_const.ignitionInternalOut)->myInstName
				)
			IgnitionSystem_receiveMessage((void*)&_LogSys_subSystemRef_topActor_IgnitionSystem,(etPort*)&_LogSys_subSystemRef_topActor_IgnitionSystem_const.ignitionInternalOut, msg);
			break;
		case 4+BASE_ADDRESS:
			ET_MSC_LOGGER_ASYNC_IN(
				((etPort*)&_LogSys_subSystemRef_topActor_FuelingSystem_const.injectiondata)->peerInstName,
				SendData_getMessageString(msg->evtID),
				((etPort*)&_LogSys_subSystemRef_topActor_FuelingSystem_const.injectiondata)->myInstName
				)
			FuelingSystem_receiveMessage((void*)&_LogSys_subSystemRef_topActor_FuelingSystem,(etPort*)&_LogSys_subSystemRef_topActor_FuelingSystem_const.injectiondata, msg);
			break;
		case 40+BASE_ADDRESS:
			ET_MSC_LOGGER_ASYNC_IN(
				((etPort*)&_LogSys_subSystemRef_topActor_IgnitionSystem_AirMassFlow_const.massflowdata)->peerInstName,
				SendData_getMessageString(msg->evtID),
				((etPort*)&_LogSys_subSystemRef_topActor_IgnitionSystem_AirMassFlow_const.massflowdata)->myInstName
				)
			AirMassFlowEntity_receiveMessage((void*)&_LogSys_subSystemRef_topActor_IgnitionSystem_AirMassFlow,(etPort*)&_LogSys_subSystemRef_topActor_IgnitionSystem_AirMassFlow_const.massflowdata, msg);
			break;
		case 41+BASE_ADDRESS:
			ET_MSC_LOGGER_ASYNC_IN(
				((etPort*)&_LogSys_subSystemRef_topActor_IgnitionSystem_AirMassFlow_const.massflowdatasend)->peerInstName,
				SendData_getMessageString(msg->evtID),
				((etPort*)&_LogSys_subSystemRef_topActor_IgnitionSystem_AirMassFlow_const.massflowdatasend)->myInstName
				)
			AirMassFlowEntity_receiveMessage((void*)&_LogSys_subSystemRef_topActor_IgnitionSystem_AirMassFlow,(etPort*)&_LogSys_subSystemRef_topActor_IgnitionSystem_AirMassFlow_const.massflowdatasend, msg);
			break;
		case 43+BASE_ADDRESS:
			ET_MSC_LOGGER_ASYNC_IN(
				((etPort*)&_LogSys_subSystemRef_topActor_IgnitionSystem_BassFuelMass2_const.bassfueldata2)->peerInstName,
				SendData_getMessageString(msg->evtID),
				((etPort*)&_LogSys_subSystemRef_topActor_IgnitionSystem_BassFuelMass2_const.bassfueldata2)->myInstName
				)
			BassFuelMassEntity2_receiveMessage((void*)&_LogSys_subSystemRef_topActor_IgnitionSystem_BassFuelMass2,(etPort*)&_LogSys_subSystemRef_topActor_IgnitionSystem_BassFuelMass2_const.bassfueldata2, msg);
			break;
		case 44+BASE_ADDRESS:
			ET_MSC_LOGGER_ASYNC_IN(
				((etPort*)&_LogSys_subSystemRef_topActor_IgnitionSystem_BassFuelMass2_const.bassfueldatasend2)->peerInstName,
				SendData_getMessageString(msg->evtID),
				((etPort*)&_LogSys_subSystemRef_topActor_IgnitionSystem_BassFuelMass2_const.bassfueldatasend2)->myInstName
				)
			BassFuelMassEntity2_receiveMessage((void*)&_LogSys_subSystemRef_topActor_IgnitionSystem_BassFuelMass2,(etPort*)&_LogSys_subSystemRef_topActor_IgnitionSystem_BassFuelMass2_const.bassfueldatasend2, msg);
			break;
		case 46+BASE_ADDRESS:
			ET_MSC_LOGGER_ASYNC_IN(
				((etPort*)&_LogSys_subSystemRef_topActor_AccelPedalSensor_const.pedaldata)->peerInstName,
				SendData_getMessageString(msg->evtID),
				((etPort*)&_LogSys_subSystemRef_topActor_AccelPedalSensor_const.pedaldata)->myInstName
				)
			AccelPedalSensor_receiveMessage((void*)&_LogSys_subSystemRef_topActor_AccelPedalSensor,(etPort*)&_LogSys_subSystemRef_topActor_AccelPedalSensor_const.pedaldata, msg);
			break;
		case 49+BASE_ADDRESS:
			ET_MSC_LOGGER_ASYNC_IN(
				((etPort*)&_LogSys_subSystemRef_topActor_ThrottleActuator_const.throttlePort)->peerInstName,
				SendData_getMessageString(msg->evtID),
				((etPort*)&_LogSys_subSystemRef_topActor_ThrottleActuator_const.throttlePort)->myInstName
				)
			ThrottleActuator_receiveMessage((void*)&_LogSys_subSystemRef_topActor_ThrottleActuator,(etPort*)&_LogSys_subSystemRef_topActor_ThrottleActuator_const.throttlePort, msg);
			break;
		case 5+BASE_ADDRESS:
			ET_MSC_LOGGER_ASYNC_IN(
				((etPort*)&_LogSys_subSystemRef_topActor_FuelingSystem_const.fuelingInternalIn)->peerInstName,
				SendData_getMessageString(msg->evtID),
				((etPort*)&_LogSys_subSystemRef_topActor_FuelingSystem_const.fuelingInternalIn)->myInstName
				)
			FuelingSystem_receiveMessage((void*)&_LogSys_subSystemRef_topActor_FuelingSystem,(etPort*)&_LogSys_subSystemRef_topActor_FuelingSystem_const.fuelingInternalIn, msg);
			break;
		case 52+BASE_ADDRESS:
			ET_MSC_LOGGER_ASYNC_IN(
				((etPort*)&_LogSys_subSystemRef_topActor_InjectionActuator_const.injectionPort)->peerInstName,
				SendData_getMessageString(msg->evtID),
				((etPort*)&_LogSys_subSystemRef_topActor_InjectionActuator_const.injectionPort)->myInstName
				)
			InjectionActuator_receiveMessage((void*)&_LogSys_subSystemRef_topActor_InjectionActuator,(etPort*)&_LogSys_subSystemRef_topActor_InjectionActuator_const.injectionPort, msg);
			break;
		case 53+BASE_ADDRESS:
			ET_MSC_LOGGER_ASYNC_IN(
				((etPort*)&_LogSys_subSystemRef_topActor_InjectionActuator_const.cylinerData)->peerInstName,
				SendData_getMessageString(msg->evtID),
				((etPort*)&_LogSys_subSystemRef_topActor_InjectionActuator_const.cylinerData)->myInstName
				)
			InjectionActuator_receiveMessage((void*)&_LogSys_subSystemRef_topActor_InjectionActuator,(etPort*)&_LogSys_subSystemRef_topActor_InjectionActuator_const.cylinerData, msg);
			break;
		case 54+BASE_ADDRESS:
			ET_MSC_LOGGER_ASYNC_IN(
				((etPort*)&_LogSys_subSystemRef_topActor_InjectionActuator_const.injectionactorInternalIn)->peerInstName,
				SendData_getMessageString(msg->evtID),
				((etPort*)&_LogSys_subSystemRef_topActor_InjectionActuator_const.injectionactorInternalIn)->myInstName
				)
			InjectionActuator_receiveMessage((void*)&_LogSys_subSystemRef_topActor_InjectionActuator,(etPort*)&_LogSys_subSystemRef_topActor_InjectionActuator_const.injectionactorInternalIn, msg);
			break;
		case 55+BASE_ADDRESS:
			ET_MSC_LOGGER_ASYNC_IN(
				((etPort*)&_LogSys_subSystemRef_topActor_InjectionActuator_const.injectionactorInternalOut)->peerInstName,
				SendData_getMessageString(msg->evtID),
				((etPort*)&_LogSys_subSystemRef_topActor_InjectionActuator_const.injectionactorInternalOut)->myInstName
				)
			InjectionActuator_receiveMessage((void*)&_LogSys_subSystemRef_topActor_InjectionActuator,(etPort*)&_LogSys_subSystemRef_topActor_InjectionActuator_const.injectionactorInternalOut, msg);
			break;
		case 58+BASE_ADDRESS:
			ET_MSC_LOGGER_ASYNC_IN(
				((etPort*)&_LogSys_subSystemRef_topActor_InjectionActuator_InjectionTimeActuator_const.Injectionactordata)->peerInstName,
				SendData_getMessageString(msg->evtID),
				((etPort*)&_LogSys_subSystemRef_topActor_InjectionActuator_InjectionTimeActuator_const.Injectionactordata)->myInstName
				)
			InjectionTimingActuatorEntity_receiveMessage((void*)&_LogSys_subSystemRef_topActor_InjectionActuator_InjectionTimeActuator,(etPort*)&_LogSys_subSystemRef_topActor_InjectionActuator_InjectionTimeActuator_const.Injectionactordata, msg);
			break;
		case 59+BASE_ADDRESS:
			ET_MSC_LOGGER_ASYNC_IN(
				((etPort*)&_LogSys_subSystemRef_topActor_InjectionActuator_InjectionTimeActuator_const.Injectionactordatasend)->peerInstName,
				SendData_getMessageString(msg->evtID),
				((etPort*)&_LogSys_subSystemRef_topActor_InjectionActuator_InjectionTimeActuator_const.Injectionactordatasend)->myInstName
				)
			InjectionTimingActuatorEntity_receiveMessage((void*)&_LogSys_subSystemRef_topActor_InjectionActuator_InjectionTimeActuator,(etPort*)&_LogSys_subSystemRef_topActor_InjectionActuator_InjectionTimeActuator_const.Injectionactordatasend, msg);
			break;
		case 6+BASE_ADDRESS:
			ET_MSC_LOGGER_ASYNC_IN(
				((etPort*)&_LogSys_subSystemRef_topActor_FuelingSystem_const.fuelingInternalOut)->peerInstName,
				SendData_getMessageString(msg->evtID),
				((etPort*)&_LogSys_subSystemRef_topActor_FuelingSystem_const.fuelingInternalOut)->myInstName
				)
			FuelingSystem_receiveMessage((void*)&_LogSys_subSystemRef_topActor_FuelingSystem,(etPort*)&_LogSys_subSystemRef_topActor_FuelingSystem_const.fuelingInternalOut, msg);
			break;
		case 61+BASE_ADDRESS:
			ET_MSC_LOGGER_ASYNC_IN(
				((etPort*)&_LogSys_subSystemRef_topActor_InjectionActuator_TotalFueling_const.totalfueldata)->peerInstName,
				SendData_getMessageString(msg->evtID),
				((etPort*)&_LogSys_subSystemRef_topActor_InjectionActuator_TotalFueling_const.totalfueldata)->myInstName
				)
			TotalFuelingEntity_receiveMessage((void*)&_LogSys_subSystemRef_topActor_InjectionActuator_TotalFueling,(etPort*)&_LogSys_subSystemRef_topActor_InjectionActuator_TotalFueling_const.totalfueldata, msg);
			break;
		case 62+BASE_ADDRESS:
			ET_MSC_LOGGER_ASYNC_IN(
				((etPort*)&_LogSys_subSystemRef_topActor_InjectionActuator_TotalFueling_const.totalfueldatasend)->peerInstName,
				SendData_getMessageString(msg->evtID),
				((etPort*)&_LogSys_subSystemRef_topActor_InjectionActuator_TotalFueling_const.totalfueldatasend)->myInstName
				)
			TotalFuelingEntity_receiveMessage((void*)&_LogSys_subSystemRef_topActor_InjectionActuator_TotalFueling,(etPort*)&_LogSys_subSystemRef_topActor_InjectionActuator_TotalFueling_const.totalfueldatasend, msg);
			break;
		case 64+BASE_ADDRESS:
			ET_MSC_LOGGER_ASYNC_IN(
				((etPort*)&_LogSys_subSystemRef_topActor_IgnitionActuator_const.ignitionPort)->peerInstName,
				SendData_getMessageString(msg->evtID),
				((etPort*)&_LogSys_subSystemRef_topActor_IgnitionActuator_const.ignitionPort)->myInstName
				)
			IgnitionActuator_receiveMessage((void*)&_LogSys_subSystemRef_topActor_IgnitionActuator,(etPort*)&_LogSys_subSystemRef_topActor_IgnitionActuator_const.ignitionPort, msg);
			break;
		case 65+BASE_ADDRESS:
			ET_MSC_LOGGER_ASYNC_IN(
				((etPort*)&_LogSys_subSystemRef_topActor_IgnitionActuator_const.cylinerData)->peerInstName,
				SendData_getMessageString(msg->evtID),
				((etPort*)&_LogSys_subSystemRef_topActor_IgnitionActuator_const.cylinerData)->myInstName
				)
			IgnitionActuator_receiveMessage((void*)&_LogSys_subSystemRef_topActor_IgnitionActuator,(etPort*)&_LogSys_subSystemRef_topActor_IgnitionActuator_const.cylinerData, msg);
			break;
		case 66+BASE_ADDRESS:
			ET_MSC_LOGGER_ASYNC_IN(
				((etPort*)&_LogSys_subSystemRef_topActor_IgnitionActuator_const.igntionactorInternalIn)->peerInstName,
				SendData_getMessageString(msg->evtID),
				((etPort*)&_LogSys_subSystemRef_topActor_IgnitionActuator_const.igntionactorInternalIn)->myInstName
				)
			IgnitionActuator_receiveMessage((void*)&_LogSys_subSystemRef_topActor_IgnitionActuator,(etPort*)&_LogSys_subSystemRef_topActor_IgnitionActuator_const.igntionactorInternalIn, msg);
			break;
		case 67+BASE_ADDRESS:
			ET_MSC_LOGGER_ASYNC_IN(
				((etPort*)&_LogSys_subSystemRef_topActor_IgnitionActuator_const.ignitionactorInternalOut)->peerInstName,
				SendData_getMessageString(msg->evtID),
				((etPort*)&_LogSys_subSystemRef_topActor_IgnitionActuator_const.ignitionactorInternalOut)->myInstName
				)
			IgnitionActuator_receiveMessage((void*)&_LogSys_subSystemRef_topActor_IgnitionActuator,(etPort*)&_LogSys_subSystemRef_topActor_IgnitionActuator_const.ignitionactorInternalOut, msg);
			break;
		case 70+BASE_ADDRESS:
			ET_MSC_LOGGER_ASYNC_IN(
				((etPort*)&_LogSys_subSystemRef_topActor_IgnitionActuator_IgnitionTimeActuator_const.ignitionactordata)->peerInstName,
				SendData_getMessageString(msg->evtID),
				((etPort*)&_LogSys_subSystemRef_topActor_IgnitionActuator_IgnitionTimeActuator_const.ignitionactordata)->myInstName
				)
			IgnitionTimingActuatorEntity_receiveMessage((void*)&_LogSys_subSystemRef_topActor_IgnitionActuator_IgnitionTimeActuator,(etPort*)&_LogSys_subSystemRef_topActor_IgnitionActuator_IgnitionTimeActuator_const.ignitionactordata, msg);
			break;
		case 71+BASE_ADDRESS:
			ET_MSC_LOGGER_ASYNC_IN(
				((etPort*)&_LogSys_subSystemRef_topActor_IgnitionActuator_IgnitionTimeActuator_const.ignitionactordatasend)->peerInstName,
				SendData_getMessageString(msg->evtID),
				((etPort*)&_LogSys_subSystemRef_topActor_IgnitionActuator_IgnitionTimeActuator_const.ignitionactordatasend)->myInstName
				)
			IgnitionTimingActuatorEntity_receiveMessage((void*)&_LogSys_subSystemRef_topActor_IgnitionActuator_IgnitionTimeActuator,(etPort*)&_LogSys_subSystemRef_topActor_IgnitionActuator_IgnitionTimeActuator_const.ignitionactordatasend, msg);
			break;
		case 73+BASE_ADDRESS:
			ET_MSC_LOGGER_ASYNC_IN(
				((etPort*)&_LogSys_subSystemRef_topActor_IgnitionActuator_IgnitionTiming_const.ignitiontimingdata)->peerInstName,
				SendData_getMessageString(msg->evtID),
				((etPort*)&_LogSys_subSystemRef_topActor_IgnitionActuator_IgnitionTiming_const.ignitiontimingdata)->myInstName
				)
			IgnitionTimingEntity_receiveMessage((void*)&_LogSys_subSystemRef_topActor_IgnitionActuator_IgnitionTiming,(etPort*)&_LogSys_subSystemRef_topActor_IgnitionActuator_IgnitionTiming_const.ignitiontimingdata, msg);
			break;
		case 74+BASE_ADDRESS:
			ET_MSC_LOGGER_ASYNC_IN(
				((etPort*)&_LogSys_subSystemRef_topActor_IgnitionActuator_IgnitionTiming_const.ignitiontimingdatasend)->peerInstName,
				SendData_getMessageString(msg->evtID),
				((etPort*)&_LogSys_subSystemRef_topActor_IgnitionActuator_IgnitionTiming_const.ignitiontimingdatasend)->myInstName
				)
			IgnitionTimingEntity_receiveMessage((void*)&_LogSys_subSystemRef_topActor_IgnitionActuator_IgnitionTiming,(etPort*)&_LogSys_subSystemRef_topActor_IgnitionActuator_IgnitionTiming_const.ignitiontimingdatasend, msg);
			break;
		case 76+BASE_ADDRESS:
			ET_MSC_LOGGER_ASYNC_IN(
				((etPort*)&_LogSys_subSystemRef_topActor_ThrottleSensor_const.throttledata)->peerInstName,
				SendData_getMessageString(msg->evtID),
				((etPort*)&_LogSys_subSystemRef_topActor_ThrottleSensor_const.throttledata)->myInstName
				)
			ThrottleSensor_receiveMessage((void*)&_LogSys_subSystemRef_topActor_ThrottleSensor,(etPort*)&_LogSys_subSystemRef_topActor_ThrottleSensor_const.throttledata, msg);
			break;
		case 79+BASE_ADDRESS:
			ET_MSC_LOGGER_ASYNC_IN(
				((etPort*)&_LogSys_subSystemRef_topActor_MassAirFlowSensor_const.airflowdata)->peerInstName,
				SendData_getMessageString(msg->evtID),
				((etPort*)&_LogSys_subSystemRef_topActor_MassAirFlowSensor_const.airflowdata)->myInstName
				)
			MassAirFlowSensor_receiveMessage((void*)&_LogSys_subSystemRef_topActor_MassAirFlowSensor,(etPort*)&_LogSys_subSystemRef_topActor_MassAirFlowSensor_const.airflowdata, msg);
			break;
		case 80+BASE_ADDRESS:
			ET_MSC_LOGGER_ASYNC_IN(
				((etPort*)&_LogSys_subSystemRef_topActor_MassAirFlowSensor_const.airflowdata2)->peerInstName,
				SendData_getMessageString(msg->evtID),
				((etPort*)&_LogSys_subSystemRef_topActor_MassAirFlowSensor_const.airflowdata2)->myInstName
				)
			MassAirFlowSensor_receiveMessage((void*)&_LogSys_subSystemRef_topActor_MassAirFlowSensor,(etPort*)&_LogSys_subSystemRef_topActor_MassAirFlowSensor_const.airflowdata2, msg);
			break;
		case 83+BASE_ADDRESS:
			ET_MSC_LOGGER_ASYNC_IN(
				((etPort*)&_LogSys_subSystemRef_topActor_CylinerNumObserver_const.cylinernum1Port)->peerInstName,
				SendData_getMessageString(msg->evtID),
				((etPort*)&_LogSys_subSystemRef_topActor_CylinerNumObserver_const.cylinernum1Port)->myInstName
				)
			CylinerNumObserver_receiveMessage((void*)&_LogSys_subSystemRef_topActor_CylinerNumObserver,(etPort*)&_LogSys_subSystemRef_topActor_CylinerNumObserver_const.cylinernum1Port, msg);
			break;
		case 84+BASE_ADDRESS:
			ET_MSC_LOGGER_ASYNC_IN(
				((etPort*)&_LogSys_subSystemRef_topActor_CylinerNumObserver_const.cylinernum2Port)->peerInstName,
				SendData_getMessageString(msg->evtID),
				((etPort*)&_LogSys_subSystemRef_topActor_CylinerNumObserver_const.cylinernum2Port)->myInstName
				)
			CylinerNumObserver_receiveMessage((void*)&_LogSys_subSystemRef_topActor_CylinerNumObserver,(etPort*)&_LogSys_subSystemRef_topActor_CylinerNumObserver_const.cylinernum2Port, msg);
			break;
		case 9+BASE_ADDRESS:
			ET_MSC_LOGGER_ASYNC_IN(
				((etPort*)&_LogSys_subSystemRef_topActor_FuelingSystem_AirMassFlow_const.airmassdata)->peerInstName,
				SendData_getMessageString(msg->evtID),
				((etPort*)&_LogSys_subSystemRef_topActor_FuelingSystem_AirMassFlow_const.airmassdata)->myInstName
				)
			AirMassFlowChanger_receiveMessage((void*)&_LogSys_subSystemRef_topActor_FuelingSystem_AirMassFlow,(etPort*)&_LogSys_subSystemRef_topActor_FuelingSystem_AirMassFlow_const.airmassdata, msg);
			break;
		case 23+BASE_ADDRESS:
			switch (msg->evtID){
				case PTimer_OUT_timeout:
					PTimerConjPort_timeout_receiveHandler((etPort *)&_LogSys_subSystemRef_topActor_AirSystem_const.timer,msg,(void*)&_LogSys_subSystemRef_topActor_AirSystem,AirSystem_receiveMessage);
					break;
				default: AirSystem_receiveMessage((void*)&_LogSys_subSystemRef_topActor_AirSystem,(etPort*)&_LogSys_subSystemRef_topActor_AirSystem_const.timer, msg);
					break;
			}
			break;
		case 38+BASE_ADDRESS:
			switch (msg->evtID){
				case PTimer_OUT_timeout:
					PTimerConjPort_timeout_receiveHandler((etPort *)&_LogSys_subSystemRef_topActor_IgnitionSystem_const.timer,msg,(void*)&_LogSys_subSystemRef_topActor_IgnitionSystem,IgnitionSystem_receiveMessage);
					break;
				default: IgnitionSystem_receiveMessage((void*)&_LogSys_subSystemRef_topActor_IgnitionSystem,(etPort*)&_LogSys_subSystemRef_topActor_IgnitionSystem_const.timer, msg);
					break;
			}
			break;
		case 47+BASE_ADDRESS:
			switch (msg->evtID){
				case PTimer_OUT_timeout:
					PTimerConjPort_timeout_receiveHandler((etPort *)&_LogSys_subSystemRef_topActor_AccelPedalSensor_const.timer,msg,(void*)&_LogSys_subSystemRef_topActor_AccelPedalSensor,AccelPedalSensor_receiveMessage);
					break;
				default: AccelPedalSensor_receiveMessage((void*)&_LogSys_subSystemRef_topActor_AccelPedalSensor,(etPort*)&_LogSys_subSystemRef_topActor_AccelPedalSensor_const.timer, msg);
					break;
			}
			break;
		case 50+BASE_ADDRESS:
			switch (msg->evtID){
				case PTimer_OUT_timeout:
					PTimerConjPort_timeout_receiveHandler((etPort *)&_LogSys_subSystemRef_topActor_ThrottleActuator_const.timer,msg,(void*)&_LogSys_subSystemRef_topActor_ThrottleActuator,ThrottleActuator_receiveMessage);
					break;
				default: ThrottleActuator_receiveMessage((void*)&_LogSys_subSystemRef_topActor_ThrottleActuator,(etPort*)&_LogSys_subSystemRef_topActor_ThrottleActuator_const.timer, msg);
					break;
			}
			break;
		case 56+BASE_ADDRESS:
			switch (msg->evtID){
				case PTimer_OUT_timeout:
					PTimerConjPort_timeout_receiveHandler((etPort *)&_LogSys_subSystemRef_topActor_InjectionActuator_const.timer,msg,(void*)&_LogSys_subSystemRef_topActor_InjectionActuator,InjectionActuator_receiveMessage);
					break;
				default: InjectionActuator_receiveMessage((void*)&_LogSys_subSystemRef_topActor_InjectionActuator,(etPort*)&_LogSys_subSystemRef_topActor_InjectionActuator_const.timer, msg);
					break;
			}
			break;
		case 68+BASE_ADDRESS:
			switch (msg->evtID){
				case PTimer_OUT_timeout:
					PTimerConjPort_timeout_receiveHandler((etPort *)&_LogSys_subSystemRef_topActor_IgnitionActuator_const.timer,msg,(void*)&_LogSys_subSystemRef_topActor_IgnitionActuator,IgnitionActuator_receiveMessage);
					break;
				default: IgnitionActuator_receiveMessage((void*)&_LogSys_subSystemRef_topActor_IgnitionActuator,(etPort*)&_LogSys_subSystemRef_topActor_IgnitionActuator_const.timer, msg);
					break;
			}
			break;
		case 7+BASE_ADDRESS:
			switch (msg->evtID){
				case PTimer_OUT_timeout:
					PTimerConjPort_timeout_receiveHandler((etPort *)&_LogSys_subSystemRef_topActor_FuelingSystem_const.timer,msg,(void*)&_LogSys_subSystemRef_topActor_FuelingSystem,FuelingSystem_receiveMessage);
					break;
				default: FuelingSystem_receiveMessage((void*)&_LogSys_subSystemRef_topActor_FuelingSystem,(etPort*)&_LogSys_subSystemRef_topActor_FuelingSystem_const.timer, msg);
					break;
			}
			break;
		case 77+BASE_ADDRESS:
			switch (msg->evtID){
				case PTimer_OUT_timeout:
					PTimerConjPort_timeout_receiveHandler((etPort *)&_LogSys_subSystemRef_topActor_ThrottleSensor_const.timer,msg,(void*)&_LogSys_subSystemRef_topActor_ThrottleSensor,ThrottleSensor_receiveMessage);
					break;
				default: ThrottleSensor_receiveMessage((void*)&_LogSys_subSystemRef_topActor_ThrottleSensor,(etPort*)&_LogSys_subSystemRef_topActor_ThrottleSensor_const.timer, msg);
					break;
			}
			break;
		case 81+BASE_ADDRESS:
			switch (msg->evtID){
				case PTimer_OUT_timeout:
					PTimerConjPort_timeout_receiveHandler((etPort *)&_LogSys_subSystemRef_topActor_MassAirFlowSensor_const.timer,msg,(void*)&_LogSys_subSystemRef_topActor_MassAirFlowSensor,MassAirFlowSensor_receiveMessage);
					break;
				default: MassAirFlowSensor_receiveMessage((void*)&_LogSys_subSystemRef_topActor_MassAirFlowSensor,(etPort*)&_LogSys_subSystemRef_topActor_MassAirFlowSensor_const.timer, msg);
					break;
			}
			break;
		case 85+BASE_ADDRESS:
			switch (msg->evtID){
				case PTimer_OUT_timeout:
					PTimerConjPort_timeout_receiveHandler((etPort *)&_LogSys_subSystemRef_topActor_CylinerNumObserver_const.timer,msg,(void*)&_LogSys_subSystemRef_topActor_CylinerNumObserver,CylinerNumObserver_receiveMessage);
					break;
				default: CylinerNumObserver_receiveMessage((void*)&_LogSys_subSystemRef_topActor_CylinerNumObserver,(etPort*)&_LogSys_subSystemRef_topActor_CylinerNumObserver_const.timer, msg);
					break;
			}
			break;
		case 87+BASE_ADDRESS:
			switch (msg->evtID){
				case PTimer_OUT_timeout:
					PTimerConjPort_timeout_receiveHandler((etPort *)&_LogSys_subSystemRef_topActor_PadelDiag_const.timer,msg,(void*)&_LogSys_subSystemRef_topActor_PadelDiag,AccelPedalDiagEntity_receiveMessage);
					break;
				default: AccelPedalDiagEntity_receiveMessage((void*)&_LogSys_subSystemRef_topActor_PadelDiag,(etPort*)&_LogSys_subSystemRef_topActor_PadelDiag_const.timer, msg);
					break;
			}
			break;
		default:
			etLogger_logErrorF("MessageService_AllThread_receiveMessage: address %d does not exist ", msg->address);
			break;
	}
	ET_MSC_LOGGER_SYNC_EXIT
	return ET_TRUE;
}