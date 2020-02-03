def ScenarioEndTime(filename,actor):
    with open("./LinuxPosix/"+filename+".txt", "r") as f1:
        data = f1.read()
        line = data.split()
        EndListLine = []
        for i in line:
            if i.split(",")[4] != str(actor):
                continue
            EndListLine.append(i)
        # print(len(s1EndListLine))

        threadnum = EndListLine[0].split(",")[2]
        return EndListLine,threadnum

def ScenarioStartTime(threadnum):
    with open("./LinuxPosix/externalQ.txt", "r") as f1:
        startData = f1.read()
        startLine = startData.split()
        StartTimeList=[]
        for i in startLine:
            if i.split(",")[0]==threadnum:
                StartTimeList.append(i)
        return StartTimeList

def ScenarioTime(scenarionum,filename1,actor1,filename2="none",actor2="none"):
    Endtimelist, threadnum = ScenarioEndTime(filename1, actor1)
    StartTimeList = ScenarioStartTime(threadnum)
    rTimeList = []
    if scenarionum>=9:
        endlist = list(range(2, len(Endtimelist), 3))
        for i, j in zip(endlist, list(range(len(endlist)))):
            rTimeList.append(float(Endtimelist[i].split(",")[5]) - float(StartTimeList[j].split(",")[3]))
    else :
        for i in range(len(Endtimelist)):
            rTimeList.append(float(Endtimelist[i].split(",")[5]) - float(StartTimeList[i].split(",")[3]))
        if filename2 != "none":
            Endtimelist, threadnum = ScenarioEndTime(filename2, actor2)
            for i in range(len(Endtimelist)):
                rTimeList.append(float(Endtimelist[i].split(",")[5]) - float(StartTimeList[i].split(",")[3]))
    print("S"+str(scenarionum)+" worst response time : " + str(max(rTimeList)))

ScenarioTime(1,"pedalsensor","actor_5")
ScenarioTime(2,"throttlesensor", "actor_5")
ScenarioTime(3,"MassAir_inject", "actor_6","MassAir_ignition", "actor_7")
ScenarioTime(4,"Pedaldiag","actor_4")
ScenarioTime(5,"airsystem","actor_8")
ScenarioTime(6,"fuelingsystem","actor_9")
ScenarioTime(7,"ignitionsystem","actor_10")
ScenarioTime(8,"throttleactuator", "actor_8")
ScenarioTime(9,"injectionactuator", "actor_9")
ScenarioTime(10,"ignitionactuator", "actor_10")
