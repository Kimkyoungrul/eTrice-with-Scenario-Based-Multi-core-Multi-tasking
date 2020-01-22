# eTrice with Scenario Based Multi-core Multi-tasking
Engine Control Unit (ECU) eTrice Project using Scenario based Multi-core Multi-tasking

## What is the Scenario Based Multi-core Multi-tasking
The paper will be updated later

## eTrice Project with Scenario Based Multi-core Multi-tasking

In this project, I specially used Engine Control Unit (ECU) Model   
This project also provides reconfigured eTrice runtime system and code modification tool for scenario-based multi-core multi-tasking.   
   
### Requirments    
    
OS : Linux   
eclipse version : oxygen   
eTrice version : 1.1.3   
Python : 3.5   
   
### How to use and modify
#### 1. Do you want to change the time constraints of each actor?
As shown in the figure below, you can modify the time consuming code of each actor behavior diagram.    
The unit of time used in this model is ms.     
<img src="/img/Timemodify.JPG" width="900px" height="300px"></img><br/>    
    
#### 2. Multiplication of time constraints
Path : eclipse-workspace/org.eclipse.etrice.runtime.c/src/common/debugging/etMSCLogger.h      
Line 26     
    
<pre><code>
#define MULCCS 0.75 //It is now performing at three-quarters of the basic constraints. You can modify it to the level you want.
</code></pre>    
    
#### 3. Timetracing.txt
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
    
However, calculating response times through these text files is repetitive and difficult. Therefore, I provide Python file that are easy to do.    
    
Path : eclipse-workspace/timetrace.py    
    
    
