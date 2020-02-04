import os
import sys
import re
import argparse
import shutil

def defaultset():
    senddatasetting()
def coreinitialize():#Thread core initialize
    with open("./src-gen/TemplateModel/node_subSystemRef.c","r") as f1:
        #reg=re.compile(complietext)
        data=f1.read()
        reg = re.compile("(\w+)_(\w+Thread)_(\w+),(\s{4}EXECMODE)_(\w+),(\s{4}\d)")
        if (reg.findall(data)==[]):
            data = re.sub(r"(\w+)_(\w+Thread)_(\w+),(\s{4}EXECMODE)_(\w+)",
                    r"\1_\2_\3,\4_\5,\n\t\t\t"+"1",data)
        else:
            data = re.sub(r"(\w+)_(\w+Thread)_(\w+),(\s{4}EXECMODE)_(\w+),(\s{4}\d)",
                        r"\1_\2_\3,\4_\5,\n\t\t\t" + "1", data)
        timersec = input("input timer interval (5000000==5ms):")
        reg = re.compile("(interval.nSec = )(\d+[;])(\s{3})(conveyMsgService_init[(][)][;])")
        if(reg.findall(data)==[]):
            data=re.sub(r"(interval.nSec = )(\d+[;])",r"interval.nSec = "+str(timersec)+r";\n\t\t"+"conveyMsgService_init();",data)#5ms
        else:
            data = re.sub(r"(interval.nSec = )(\d+)", r"interval.nSec = " + str(timersec),data)
        data = re.sub(r"(etMessageService_start_kkr)", "etMessageService_start", data)
        reg = re.compile("(etMessageService_start[(][&]msgService_)(\w+)")
        threadlist = [row[1] for row in reg.findall(data)]
        for i in threadlist:
            if i != "DefaultPhysicalThread":
                data = re.sub(r"(etMessageService_start)(?P<a>[(][&]msgService)_(?P<b>" + str(i) + ")",
                              r"etMessageService_start_kkr\g<a>_\g<b>", data)
    #print(data)
    with open("./src-gen/TemplateModel/node_subSystemRef.c","w") as f1:
        f1.write(data)
def instinitialize():#Threea core initialize
    with open("./src-gen/TemplateModel/node_subSystemRef_Inst.h", "r") as f1:
        # reg=re.compile(complietext)
        data = f1.read()
        reg = re.compile("(PTimerConjPort_var )(\S*)(\s{2}\d,\s{2})(\d)")
        # print(reg.findall(data))
        if (reg.findall(data) == []):
            data = re.sub(r"(PTimerConjPort_var )(\S*)(\s{2}\d)(\s{2}[/][*] \w+ [*][/]\s{2})",
                          r"\1\2\3,\n\t" + "0\n", data)
        else:
            data = re.sub(r"(PTimerConjPort_var \S*\s{2}\d,\s{2})(\d)",
                          r"\g<0>" + "0", data)
        # data=re.sub(r"(interval.nSec = )(\d+)",r"interval.nSec = "+str(timersec),data)#5ms
        # print(data)
    with open("./src-gen/TemplateModel/node_subSystemRef_Inst.h","w") as f1:
        f1.write(data)
    with open("./src-gen/TemplateModel/node_subSystemRef.c", "r") as f1:
        # reg=re.compile(complietext)
        data = f1.read()
        data = re.sub(r"(etMessageService_init_kkr)", "etMessageService_init", data)
        reg = re.compile("(etMessageService_init[(]\s{4}[&]msgService_)(\w+)")
        threadlist = [row[1] for row in reg.findall(data)]
        for i in threadlist:
            if str(i) != "DefaultPhysicalThread":
                data = re.sub(r"(etMessageService_init)(?P<a>[(]\s{4}[&]msgService)_(?P<b>" + str(i) + ")",
                              r"etMessageService_init_kkr\g<a>_\g<b>", data)
    with open("./src-gen/TemplateModel/node_subSystemRef.c", "w") as f1:
        f1.write(data)
def copyfile():#etrice code copy
    shutil.copytree("./src-gen/TemplateModel","../TemplateModelCopy")
    #with open("C:/Users/kyoun/Desktop/"+filename, "r") as f1:
    #   with open("C:/Users/kyoun/Desktop/kkr/"+filename, "w") as f2:
    #       data = f1.read()
    #       f2.write(data)
def coreGenerator():#Thread core generator
    with open("./src-gen/TemplateModel/node_subSystemRef.c","r") as f1:
        #reg=re.compile(complietext)
        data=f1.read()
        reg = re.compile("(msgBuffer)_(\w+)")
        threadlist=[row[1] for row in reg.findall(data)]
        threadlist.sort()
        print("Thread List :")
        passdefaultflag=0
        for num,threadname in enumerate(threadlist):
            if threadname=="DefaultPhysicalThread":
                passdefaultflag=1
                continue
            if passdefaultflag==0:
                print(" {}.{}".format(num + 1,threadname))
            else:
                print(" {}.{}".format(num, threadname))
        print()
        corenumlist=input("map each thread to Core no. (core starts from 1)(ex: 1 2, which maps two threads to different core):").split()
        prioritylist = input("assign priority no.to each thread (99 to 0 where 0 is the lowest priority)(ex: 99 91 for two thread):").split()
        for i in range(0, len(corenumlist)):
            if threadlist[i]=="DefaultPhysicalThread":
                data = re.sub(r"(?P<a>msgBuffer)_(?P<b>" + threadlist[
                    i] + "),(?P<c>\s{4}\S*\s{4}\S*\s{4}\S*\s{4})(\S*)(?P<d>\s{4}\S*\s{4}\S*\s{4}\S*),(\s{4})(\d)",
                              r"\g<a>_\g<b>,\g<c>" + "99" + ",\g<d>",
                              data)
                continue
            data = re.sub(r"(?P<a>msgBuffer)_(?P<b>"+threadlist[i]+"),(?P<c>\s{4}\S*\s{4}\S*\s{4}\S*\s{4})(\S*)(?P<d>\s{4}\S*\s{4}\S*\s{4}\S*\s{4})(\d)",
                    r"\g<a>_\g<b>,\g<c>"+prioritylist[i]+",\g<d>"+str(1<<(int(corenumlist[i])-1)),data)
    # print(data)
    with open("./src-gen/TemplateModel/node_subSystemRef.c","w") as f1:
        f1.write(data)
        #while True:
        #    data=f1.read().splitlines()
        #   for i in data:
        #       print(i)
def instGenerator():#Thread core generator
    with open("./src-gen/TemplateModel/node_subSystemRef_Inst.h", "r") as f1:
        # reg=re.compile(complietext)
        data = f1.read()
        reg = re.compile("(_LogSys_subSystemRef)_(\w+)_(\w+)_(timer_var={\s{2}\d,\s{2})(\d)")
        timerlist = [row[2] for row in reg.findall(data)]
        timerlist.sort()
        print("TimedActor List:")
        for num,timername in enumerate(timerlist):    print(" {}.{}".format(num+1,timername))
        print()
        gtimerlist=input("enumerate timedactors that use global resources, which means their accesing thread are not mapped to a single core:").split()
        for i in range(0, len(gtimerlist)):
            data = re.sub(r"(_LogSys_subSystemRef)_(\w+)_("+timerlist[int(gtimerlist[i])-1]+")_(timer_var={\s{2}\d),(\s{2})(\d)",
                          r"\1_\2_\3_\4,\n\t" + "1", data)
        # data=re.sub(r"(interval.nSec = )(\d+)",r"interval.nSec = "+str(timersec),data)#5ms
        # print(data)
    with open("./src-gen/TemplateModel/node_subSystemRef_Inst.h","w") as f1:
        f1.write(data)
def actGenerator():
    with open("./src-gen/TemplateModel/node_subSystemRef_Disp.h", "r") as f1:
        data = f1.read()
        reg = re.compile("(\w+)_receiveMessage")
        actorlist = reg.findall(data)
        actorlist = list(set(actorlist))
        actorlist.remove('MsgDispatcher_AllThread')
        actorlist.remove('ATimingService')
        actorlist.sort()
        print("Total Actor List:")
        for num, actname in enumerate(actorlist):    print(" {}.{}".format(num + 1, actname))
        gactorlist = input("enumerate any actors that use global resources, which means their accesing thread are not mapped to a single core::").split()
        portlist = []
        for actor in gactorlist:
            reg = re.compile(
                "case (\d*)[+](BASE_ADDRESS):\s{4}\S*\s{5}[(][(]\w+[*][)][&]\w+.\w+Port\S*\s{5}\S*\s{5}\S*\s{5}\S*\s{4}" +
                actorlist[int(actor) - 1])
            portlist.extend(reg.findall(data))
            reg = re.compile(
                "case (\d*)[+](BASE_ADDRESS):\s{4}\S*\s{5}[(][(]\w+[*][)][&]\w+.\w+InternalOut\S*\s{5}\S*\s{5}\S*\s{5}\S*\s{4}" +
                actorlist[int(actor) - 1])
            portlist.extend(reg.findall(data))
    with open("./src-gen/TemplateModel/node_subSystemRef_Inst.h", "r") as f1:
        data = f1.read()
        for PL in portlist:
            mold = "/\w+"
            count = 0
            reg = re.compile(", " + PL[0] + "[+]" + PL[1] + ", \S*\s{2}\S*\s{1}\S*\s{2},[\"]" + mold * count)
            actordata = reg.findall(data)
            while (actordata != []):
                predata = actordata
                count += 1
                reg = re.compile(", " + PL[0] + "[+]" + PL[1] + ", \S*\s{2}\S*\s{1}\S*\s{2},[\"]" + mold * count)
                actordata = reg.findall(data)
            actoradr = predata[0].split('"')[-1].replace("/", "_")
            reg = re.compile("static (\w+) " + actoradr + " [=] [{]")
            actorname = reg.findall(data)[0]
            reg = re.compile(
                ", " + PL[0] + "[+]" + PL[1] + ", \S*\s{2}\S*\s{1}\S*\s{2}\S*\s{2}\S*\s{2}\S* /[*] Port (\w+)")
            portname = reg.findall(data)[0]
            with open("./src-gen/TemplateModel/" + actorname + ".c", "r") as f1:
                actortext = f1.read()
                reg = re.compile("//added by kkr for global actor\n    " + portname + "_sendData")
                if reg.findall(actortext) == []:
                    reg = re.compile(portname + "_sendData[(][&](\w+)")
                    messageN = reg.findall(actortext)[0]
                    actortext = re.sub(portname + "_sendData[(]",
                                       messageN + ".staticcheck = 1;\t//added by kkr for global actor\n    " + portname + "_sendData(",
                                       actortext)
            with open("./src-gen/TemplateModel/" + actorname + ".c", "w") as f1:
                f1.write(actortext)

def senddatasetting():
    with open("../default/SendData.c","r") as f1:
        data=f1.read()
    with open("./src-gen/TemplateModel/SendData.c","w") as f2:
        f2.write(data)
def node_subSystemRef_Disp_setting():
    with open("./src-gen/TemplateModel/node_subSystemRef_Disp.h", "r") as f1:
        # reg=re.compile(complietext)
        data = f1.read()
        text = "/* modified by kkr*/\n#include \"messaging/etMessageReceiver.h\"\n#include \"debugging/etLogger.h\"\n#include \"debugging/etMSCLogger.h\"\nstatic void MsgDispatcher_DefaultPhysicalThread_poll(void){\n\tET_MSC_LOGGER_SYNC_ENTRY(\"MsgDispatcher_DefaultPhysicalThread\", \"execute\")\n\tATimingService_execute((void*)&_LogSys_subSystemRef_timingService);\n\tET_MSC_LOGGER_SYNC_EXIT\n}\n\nstatic etBool MsgDispatcher_AllThread_receiveMessage(const etMessage* msg){\n\tET_MSC_LOGGER_SYNC_ENTRY(\"MsgDispatcher_AllThread\", \"receiveMessage\")\n\tswitch(msg->address){\n\t\tcase MESSAGESERVICE_ADDRESS:\n\t\t\tif (msg->evtID == etSystemProtocol_IN_poll) {\n\t\t\t\tMsgDispatcher_DefaultPhysicalThread_poll();\n\t\t\t}\n\t\t\telse if(msg->evtID == etSystemProtocol_IN_terminate)\n\t\t\t\treturn ET_FALSE;\n\t\t\tbreak;"
        reg = re.compile(
            "(case \d*[+]BASE_ADDRESS:\s{4}\S*\s{5}\S*\s{5}\S*\s{5}\S*\s{5}\S*\s{4}\S*\s{1}\S*\s{3}break;)")
        timerlist = reg.findall(data)
        timerlist.sort()
        for row in timerlist:
            text += "\n\t\t" + row
        reg = re.compile("(case \d*[+]BASE_ADDRESS:\s{4}\S*\s{5}\S*\s{5}\S*\s{5}\S*\s{5}\S*\s{4}\S*\s{1}\S*\s{4}\S*)")
        timerlist = reg.findall(data)
        timerlist.sort()
        for row in timerlist:
            text += "\n\t\t" + row
        reg = re.compile(
            "(case \d*[+]BASE_ADDRESS:\s{4}\S*\s{1}\S*\s{5}\S*\s{1}\S*\s{6}\S*\s{1}\S*\s{6}\S*\s{5}\S*\s{1}\S*\s{1}\S*\s{6}\S*\s{4}\S*\s{4}\S*)")
        timerlist = reg.findall(data)
        timerlist.sort()
        for row in timerlist:
            text += "\n\t\t" + row
        text += "\n\t\tdefault:\n\t\t\tetLogger_logErrorF(\"MessageService_AllThread_receiveMessage: address %d does not exist \", msg->address);\n\t\t\tbreak;\n\t}\n\tET_MSC_LOGGER_SYNC_EXIT\n\treturn ET_TRUE;\n}"
        # print(text)
    with open("./src-gen/TemplateModel/node_subSystemRef_Disp.h", "w") as f1:
        f1.write(text)
    with open("./src-gen/TemplateModel/node_subSystemRef.c", "r") as f1:
        data = f1.read()
        data = re.sub(r"(\w+)_(\w+Thread)_(\w+),",
                      r"\1_AllThread_\3,", data)
    with open("./src-gen/TemplateModel/node_subSystemRef.c", "w") as f1:
        f1.write(data)
if __name__=="__main__":
    os.system('rm -rf ../TemplateModelCopy')
    os.system('rmdir ../TemplateModelCopy')
    copyfile()
    defaultset()
    coreinitialize()
    coreGenerator()
    instinitialize()
    instGenerator()
    node_subSystemRef_Disp_setting()
    actGenerator()
