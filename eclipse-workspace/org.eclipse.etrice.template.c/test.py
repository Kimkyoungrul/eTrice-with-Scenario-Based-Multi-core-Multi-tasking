import re
with open("./src-gen/TemplateModel/node_subSystemRef.c", "r") as f1:
    #reg=re.compile(complietext)
    data=f1.read()
    # data=re.sub(r"(etMessageService_init_kkr)","etMessageService_init",data)
    # reg = re.compile("(etMessageService_init[(]\s{4}[&]msgService_)(\w+)")
    # threadlist=[row[1] for row in reg.findall(data)]
    # print(threadlist)
    # for i in threadlist:
    #     if str(i)!="DefaultPhysicalThread":
    #         data = re.sub(r"(etMessageService_init)(?P<a>[(]\s{4}[&]msgService)_(?P<b>"+str(i)+")",
    #                 r"etMessageService_init_kkr\g<a>_\g<b>",data)
    # print(data)
    data = re.sub(r"(etMessageService_start_kkr)", "etMessageService_start", data)
    reg = re.compile("(etMessageService_start[(][&]msgService_)(\w+)")
    threadlist = [row[1] for row in reg.findall(data)]
    print(threadlist)
    for i in threadlist:
        if i!="DefaultPhysicalThread":
            data = re.sub(r"(etMessageService_start)(?P<a>[(][&]msgService)_(?P<b>"+str(i)+")",
                    r"etMessageService_start_kkr\g<a>_\g<b>",data)
    print(data)
# with open("./src-gen/TemplateModel/node_subSystemRef1.c","w") as f1:
#     f1.write(data)

