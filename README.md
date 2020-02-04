# eTrice with Scenario Based Multi-core Multi-tasking
Engine Control Unit (ECU) eTrice Project using Scenario based Multi-core Multi-tasking

## What is the Scenario Based Multi-core Multi-tasking
The paper will be updated later.

## eTrice Project with Scenario Based Multi-core Multi-tasking

In this project, I specially used Engine Control Unit (ECU) Model.  
This project provides reconfigured eTrice runtime system and code modification tool for scenario-based multi-core multi-tasking.   
   
### Requirments    
    
OS : Linux   
eclipse version : oxygen   
eTrice version : 1.1.3    
eTrice language : C    
Python : 3.6    
gcc : 5.5.0
g++ : 5.5.0
java : java8    

### How to configure and use tools    
#### 1. Generating code and executable
     
<img src="/img/eTriceSystem.JPG" width="500px" height="400px"></img><br/>    
(eTrice System with Scenario Based Multi-core Multi-tasking)    
    
If you run "generate_Template.launch" of eTrice, then eTrice will generate source code.    
Code modification tool is a program that modifies multiple code files created by eTrice.    
    
So, if you want use scenario based multi-core multi-tasking. You have to follow this step.    
1. Run "generate_Template.launch" of eTrice.    
2. Run "generator.py" --> path : eclipse-workspace/org.eclipse.etrice.template.c/generator.py    
<img src="/img/generatorimage.JPG" width="800px" height="700px"></img><br/>    
3. Complete code modify     
4. Run "run_Template_Lnux.launch" (eTrice make "eclipse-workspace/org.eclipse.etrice.template.c/LinuxPosix/org.eclipse.etrice.template.c.exe")    
5. Run the exe file("eclipse-workspace/org.eclipse.etrice.template.c/LinuxPosix/org.eclipse.etrice.template.c.exe") in root mode. because the pthread library is available in root mode.    
6. If you want to make sure it's working properly, check the time-tracing text file that is created when you run it. If time tracing information is written in a text file, it is working properly. (Time tracing text file path : eclipse-workspace/org.eclipse.etrice.template.c/LinuxPosix)        
     
***
#### 2. Timetracing
This project performs a time tracing for all scenarios.    
when you run this project then it make 11 txt files.    
     
pedalsensor.txt --> Scenario 1 (End time)    
throttlesensor.txt --> Scenario 2 (End time)    
MassAir_inject.txt, MassAir_ignition.txt --> Scenario 3 (End time)    
Pedaldiag.txt --> Scenario 4 (End time)    
airsystem.txt --> Scenario 5 (End time)    
fuelingsystem.txt --> Scenario 6 (End time)    
ignitionsystem.txt --> Scenario 7 (End time)    
throttleactuator.txt --> Scenario 8 (End time)    
injectionactuator.txt --> Scenario 9 (End time)    
ignitionactuator.txt --> Scenario 10 (End time)    
externalQ.txt --> All Scenario (Start time)     
    
However, calculating response times through these text files is repetitive and difficult.    
Therefore, I provide Python file that are easy to do.    
    
Path : eclipse-workspace/org.eclipse.etrice.template.c/timetrace.py    
    
You just run this file. then you will get worst-case response time of each scenario    
    
***
#### 3. Configuration of the timing constraints of each actor
As shown in the figure below, you can modify the time consuming code of each actor behavior diagram.    
If you double click transition name, you can see "Edit transition"    
The unit of time used in this model is ms.     
<img src="/img/Timemodify.JPG" width="900px" height="300px"></img><br/>    
    
***
#### 4. Configuration of time scaling factor
Path : eclipse-workspace/org.eclipse.etrice.runtime.c/src/common/debugging/etMSCLogger.h      
Line 26     
    
<pre><code>
#define MULCCS 0.75 // Now, It is performing at three-quarters of the basic constraints. You can modify it to the level you want.
</code></pre>    
    
***
