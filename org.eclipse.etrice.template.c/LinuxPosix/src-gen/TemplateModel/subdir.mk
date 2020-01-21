################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src-gen/TemplateModel/ACC.c \
../src-gen/TemplateModel/ADASMessage.c \
../src-gen/TemplateModel/ADAS_Controller.c \
../src-gen/TemplateModel/AEB.c \
../src-gen/TemplateModel/ALK.c \
../src-gen/TemplateModel/Accel.c \
../src-gen/TemplateModel/Brake.c \
../src-gen/TemplateModel/ColliderSensor.c \
../src-gen/TemplateModel/DDataBuffer.c \
../src-gen/TemplateModel/Gateway.c \
../src-gen/TemplateModel/Handle.c \
../src-gen/TemplateModel/PSendData.c \
../src-gen/TemplateModel/SendData.c \
../src-gen/TemplateModel/SteeringSensor.c \
../src-gen/TemplateModel/TopActor.c \
../src-gen/TemplateModel/TrafficlightSensor.c \
../src-gen/TemplateModel/VelocitySensor.c \
../src-gen/TemplateModel/node_subSystemRef.c \
../src-gen/TemplateModel/node_subSystemRef_Runner.c 

OBJS += \
./src-gen/TemplateModel/ACC.o \
./src-gen/TemplateModel/ADASMessage.o \
./src-gen/TemplateModel/ADAS_Controller.o \
./src-gen/TemplateModel/AEB.o \
./src-gen/TemplateModel/ALK.o \
./src-gen/TemplateModel/Accel.o \
./src-gen/TemplateModel/Brake.o \
./src-gen/TemplateModel/ColliderSensor.o \
./src-gen/TemplateModel/DDataBuffer.o \
./src-gen/TemplateModel/Gateway.o \
./src-gen/TemplateModel/Handle.o \
./src-gen/TemplateModel/PSendData.o \
./src-gen/TemplateModel/SendData.o \
./src-gen/TemplateModel/SteeringSensor.o \
./src-gen/TemplateModel/TopActor.o \
./src-gen/TemplateModel/TrafficlightSensor.o \
./src-gen/TemplateModel/VelocitySensor.o \
./src-gen/TemplateModel/node_subSystemRef.o \
./src-gen/TemplateModel/node_subSystemRef_Runner.o 

C_DEPS += \
./src-gen/TemplateModel/ACC.d \
./src-gen/TemplateModel/ADASMessage.d \
./src-gen/TemplateModel/ADAS_Controller.d \
./src-gen/TemplateModel/AEB.d \
./src-gen/TemplateModel/ALK.d \
./src-gen/TemplateModel/Accel.d \
./src-gen/TemplateModel/Brake.d \
./src-gen/TemplateModel/ColliderSensor.d \
./src-gen/TemplateModel/DDataBuffer.d \
./src-gen/TemplateModel/Gateway.d \
./src-gen/TemplateModel/Handle.d \
./src-gen/TemplateModel/PSendData.d \
./src-gen/TemplateModel/SendData.d \
./src-gen/TemplateModel/SteeringSensor.d \
./src-gen/TemplateModel/TopActor.d \
./src-gen/TemplateModel/TrafficlightSensor.d \
./src-gen/TemplateModel/VelocitySensor.d \
./src-gen/TemplateModel/node_subSystemRef.d \
./src-gen/TemplateModel/node_subSystemRef_Runner.d 


# Each subdirectory must supply rules for building sources it contributes
src-gen/TemplateModel/%.o: ../src-gen/TemplateModel/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -I"/home/eselab/eclipse-workspace/org.eclipse.etrice.modellib.c" -I"/home/eselab/eclipse-workspace/org.eclipse.etrice.modellib.c/src-gen" -I"/home/eselab/eclipse-workspace/org.eclipse.etrice.runtime.c" -I"/home/eselab/eclipse-workspace/org.eclipse.etrice.runtime.c/src/common" -I"/home/eselab/eclipse-workspace/org.eclipse.etrice.runtime.c/src/config" -I"/home/eselab/eclipse-workspace/org.eclipse.etrice.runtime.c/src/platforms/MT_POSIX_GENERIC_GCC" -I"/home/eselab/eclipse-workspace/org.eclipse.etrice.runtime.c/src/util" -I"/home/eselab/eclipse-workspace/org.eclipse.etrice.template.c/src-gen" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


