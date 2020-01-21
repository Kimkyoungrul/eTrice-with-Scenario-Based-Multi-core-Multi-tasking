def scenario1time():
    with open("./org.eclipse.etrice.template.c/LinuxPosix/externalQ.txt","r") as f1:
        with open("./org.eclipse.etrice.template.c/LinuxPosix/pedalsensor.txt","r") as f2:
            data = f2.read()
            line = data.split()
            s1EndListLine=[]
            for i in line:
                if i.split(",")[4]=="actor_1":
                    continue
                s1EndListLine.append(i)
            # print(len(s1EndListLine))

            threadnum = s1EndListLine[0].split(",")[2]
            startData = f1.read()
            startLine = startData.split()
            s1StartListLine=[]
            for i in startLine:
                if i.split(",")[0]==threadnum:
                    s1StartListLine.append(i)
            # print(len(s1StartListLine))
            rTimeList=[]
            for i in range(len(s1EndListLine)):
                rTimeList.append(float(s1EndListLine[i].split(",")[5])-float(s1StartListLine[i].split(",")[3]))
            # print(rTimeList)
            print("S1 worst response time : "+str(max(rTimeList)))
def scenario2time():
    with open("./org.eclipse.etrice.template.c/LinuxPosix/externalQ.txt","r") as f1:
        with open("./org.eclipse.etrice.template.c/LinuxPosix/throttlesensor.txt","r") as f2:
            data = f2.read()
            line = data.split()
            s2EndListLine=[]
            for i in line:
                if i.split(",")[4]=="actor_2":
                    continue
                s2EndListLine.append(i)
            # print(len(s2EndListLine))

            threadnum = s2EndListLine[0].split(",")[2]
            startData = f1.read()
            startLine = startData.split()
            s2StartListLine=[]
            for i in startLine:
                if i.split(",")[0]==threadnum:
                    s2StartListLine.append(i)
            # print(len(s2StartListLine))
            rTimeList=[]
            for i in range(len(s2EndListLine)):
                rTimeList.append(float(s2EndListLine[i].split(",")[5])-float(s2StartListLine[i].split(",")[3]))
            # print(rTimeList)
            print("S2 worst response time : "+str(max(rTimeList)))
def scenario3time():
    with open("./org.eclipse.etrice.template.c/LinuxPosix/externalQ.txt","r") as f1:
        startData = f1.read()
        startLine = startData.split()
        s3StartListLine = []
        rTimeList = []
        with open("./org.eclipse.etrice.template.c/LinuxPosix/MassAir_ignition.txt","r") as f2:
            data = f2.read()
            line = data.split()
            s3EndListLine=[]
            for i in line:
                if i.split(",")[4]=="actor_3":
                    continue
                s3EndListLine.append(i)
            # print(len(s3EndListLine))

            threadnum = s3EndListLine[0].split(",")[2]
            for i in startLine:
                if i.split(",")[0]==threadnum:
                    s3StartListLine.append(i)
            # print(len(s3StartListLine))
            for i in range(len(s3EndListLine)):
                rTimeList.append(float(s3EndListLine[i].split(",")[5])-float(s3StartListLine[i].split(",")[3]))
        with open("./org.eclipse.etrice.template.c/LinuxPosix/MassAir_inject.txt","r") as f2:
            data = f2.read()
            line = data.split()
            s3EndListLine=[]
            for i in line:
                if i.split(",")[4]=="actor_3":
                    continue
                s3EndListLine.append(i)
            # print(len(s3EndListLine))
            for i in range(len(s3EndListLine)):
                rTimeList.append(float(s3EndListLine[i].split(",")[5])-float(s3StartListLine[i].split(",")[3]))
            # print(rTimeList)
            print("S3 worst response time : "+str(max(rTimeList)))


def scenario4time():
    with open("./org.eclipse.etrice.template.c/LinuxPosix/externalQ.txt", "r") as f1:
        with open("./org.eclipse.etrice.template.c/LinuxPosix/Pedaldiag.txt",
                  "r") as f2:
            data = f2.read()
            line = data.split()
            s4EndListLine = []
            for i in line:
                s4EndListLine.append(i)
            # print(len(s4EndListLine))

            threadnum = s4EndListLine[0].split(",")[2]
            startData = f1.read()
            startLine = startData.split()
            s4StartListLine = []
            for i in startLine:
                if i.split(",")[0] == threadnum:
                    s4StartListLine.append(i)
            # print(len(s4StartListLine))
            rTimeList = []
            for i in range(len(s4EndListLine)):
                rTimeList.append(float(s4EndListLine[i].split(",")[5]) - float(s4StartListLine[i].split(",")[3]))
            # print(rTimeList)
            print("S4 worst response time : " + str(max(rTimeList)))
def scenario5time():
    with open("./org.eclipse.etrice.template.c/LinuxPosix/externalQ.txt", "r") as f1:
        with open("./org.eclipse.etrice.template.c/LinuxPosix/airsystem.txt",
                  "r") as f2:
            data = f2.read()
            line = data.split()
            s5EndListLine = []
            for i in line:
                if i.split(",")[4] != "actor_8":
                    continue
                s5EndListLine.append(i)
            # print(len(s5EndListLine))

            threadnum = s5EndListLine[0].split(",")[2]
            startData = f1.read()
            startLine = startData.split()
            s5StartListLine = []
            for i in startLine:
                if i.split(",")[0] == threadnum:
                    s5StartListLine.append(i)
            # print(len(s5StartListLine))
            rTimeList = []
            for i in range(len(s5EndListLine)):
                rTimeList.append(float(s5EndListLine[i].split(",")[5]) - float(s5StartListLine[i].split(",")[3]))
            # print(rTimeList)
            print("S5 worst response time : " + str(max(rTimeList)))

def scenario6time():
    with open("./org.eclipse.etrice.template.c/LinuxPosix/externalQ.txt", "r") as f1:
        with open("./org.eclipse.etrice.template.c/LinuxPosix/fuelingsystem.txt",
                  "r") as f2:
            data = f2.read()
            line = data.split()
            s6EndListLine = []
            for i in line:
                if i.split(",")[4] != "actor_9":
                    continue
                s6EndListLine.append(i)
            # print(len(s6EndListLine))

            threadnum = s6EndListLine[0].split(",")[2]
            startData = f1.read()
            startLine = startData.split()
            s6StartListLine = []
            for i in startLine:
                if i.split(",")[0] == threadnum:
                    s6StartListLine.append(i)
            # print(len(s6StartListLine))
            rTimeList = []
            for i in range(len(s6EndListLine)):
                rTimeList.append(float(s6EndListLine[i].split(",")[5]) - float(s6StartListLine[i].split(",")[3]))
            # print(rTimeList)
            print("S6 worst response time : " + str(max(rTimeList)))

def scenario7time():
    with open("./org.eclipse.etrice.template.c/LinuxPosix/externalQ.txt", "r") as f1:
        with open("./org.eclipse.etrice.template.c/LinuxPosix/ignitionsystem.txt",
                  "r") as f2:
            data = f2.read()
            line = data.split()
            s7EndListLine = []
            for i in line:
                if i.split(",")[4] != "actor_10":
                    continue
                s7EndListLine.append(i)
            # print(len(s7EndListLine))

            threadnum = s7EndListLine[0].split(",")[2]
            startData = f1.read()
            startLine = startData.split()
            s7StartListLine = []
            for i in startLine:
                if i.split(",")[0] == threadnum:
                    s7StartListLine.append(i)
            # print(len(s7StartListLine))
            rTimeList = []
            for i in range(len(s7EndListLine)):
                rTimeList.append(float(s7EndListLine[i].split(",")[5]) - float(s7StartListLine[i].split(",")[3]))
            # print(rTimeList)
            print("S7 worst response time : " + str(max(rTimeList)))
def scenario8time():
    with open("./org.eclipse.etrice.template.c/LinuxPosix/externalQ.txt", "r") as f1:
        with open("./org.eclipse.etrice.template.c/LinuxPosix/throttleactuator.txt",
                  "r") as f2:
            data = f2.read()
            line = data.split()
            s8EndListLine = []
            for i in line:
                s8EndListLine.append(i)
            # print(len(s8EndListLine))

            threadnum = s8EndListLine[0].split(",")[2]
            startData = f1.read()
            startLine = startData.split()
            s8StartListLine = []
            for i in startLine:
                if i.split(",")[0] == threadnum:
                    s8StartListLine.append(i)
            # print(len(s8StartListLine))
            rTimeList = []
            for i in range(len(s8EndListLine)):
                rTimeList.append(float(s8EndListLine[i].split(",")[5]) - float(s8StartListLine[i].split(",")[3]))
            # print(rTimeList)
            print("S8 worst response time : " + str(max(rTimeList)))
def scenario9time():
    with open("./org.eclipse.etrice.template.c/LinuxPosix/externalQ.txt", "r") as f1:
        with open("./org.eclipse.etrice.template.c/LinuxPosix/injectionactuator.txt",
                  "r") as f2:
            data = f2.read()
            line = data.split()
            s9EndListLine = []
            count=0
            for i in line:
                if i.split(",")[4] != "actor_9":
                    continue
                if count!=2:
                    count+=1
                    continue
                s9EndListLine.append(i)
                count=0
            # print(len(s9EndListLine))

            threadnum = s9EndListLine[0].split(",")[2]
            startData = f1.read()
            startLine = startData.split()
            s9StartListLine = []
            for i in startLine:
                if i.split(",")[0] == threadnum:
                    s9StartListLine.append(i)
            # print(len(s9StartListLine))
            rTimeList = []
            for i in range(len(s9EndListLine)):
                rTimeList.append(float(s9EndListLine[i].split(",")[5]) - float(s9StartListLine[i].split(",")[3]))
            # print(rTimeList)
            print("S9 worst response time : " + str(max(rTimeList)))
def scenario10time():
    with open("./org.eclipse.etrice.template.c/LinuxPosix/externalQ.txt", "r") as f1:
        with open("./org.eclipse.etrice.template.c/LinuxPosix/ignitionactuator.txt",
                  "r") as f2:
            data = f2.read()
            line = data.split()
            s10EndListLine = []
            count=0
            for i in line:
                if i.split(",")[4] != "actor_10":
                    continue
                if count!=2:
                    count+=1
                    continue
                s10EndListLine.append(i)
                count=0
            # print(len(s10EndListLine))

            threadnum = s10EndListLine[0].split(",")[2]
            startData = f1.read()
            startLine = startData.split()
            s10StartListLine = []
            for i in startLine:
                if i.split(",")[0] == threadnum:
                    s10StartListLine.append(i)
            # print(len(s10StartListLine))
            rTimeList = []
            for i in range(len(s10EndListLine)):
                rTimeList.append(float(s10EndListLine[i].split(",")[5]) - float(s10StartListLine[i].split(",")[3]))
            # print(rTimeList)
            print("S10 worst response time : " + str(max(rTimeList)))

scenario1time()
scenario2time()
scenario3time()
scenario4time()
scenario5time()
scenario6time()
scenario7time()
scenario8time()
scenario9time()
scenario10time()
