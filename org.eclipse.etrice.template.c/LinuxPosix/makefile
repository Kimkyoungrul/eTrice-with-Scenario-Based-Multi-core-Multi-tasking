################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src-gen/TemplateModel/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: org.eclipse.etrice.template.c.exe

dependents:
	-cd /home/eselab/eclipse-workspace/org.eclipse.etrice.runtime.c/LinuxPosix && $(MAKE) clean all
	-cd /home/eselab/eclipse-workspace/org.eclipse.etrice.modellib.c/LinuxPosix && $(MAKE) clean all

# Tool invocations
org.eclipse.etrice.template.c.exe: $(OBJS) $(USER_OBJS) /home/eselab/eclipse-workspace/org.eclipse.etrice.runtime.c/LinuxPosix/liborg.eclipse.etrice.runtime.c.a /home/eselab/eclipse-workspace/org.eclipse.etrice.modellib.c/LinuxPosix/liborg.eclipse.etrice.modellib.c.a
	@echo 'Building target: $@'
	@echo 'Invoking: GCC C Linker'
	gcc -L"/home/eselab/eclipse-workspace/org.eclipse.etrice.modellib.c/LinuxPosix" -L"/home/eselab/eclipse-workspace/org.eclipse.etrice.runtime.c/LinuxPosix" -o "org.eclipse.etrice.template.c.exe" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(C_DEPS) org.eclipse.etrice.template.c.exe
	-@echo ' '

.PHONY: all clean dependents
/home/eselab/eclipse-workspace/org.eclipse.etrice.runtime.c/LinuxPosix/liborg.eclipse.etrice.runtime.c.a:
/home/eselab/eclipse-workspace/org.eclipse.etrice.modellib.c/LinuxPosix/liborg.eclipse.etrice.modellib.c.a:

-include ../makefile.targets
