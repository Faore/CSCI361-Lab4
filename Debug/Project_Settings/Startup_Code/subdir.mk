################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Project_Settings/Startup_Code/startup.c 

OBJS += \
./Project_Settings/Startup_Code/startup.o 

C_DEPS += \
./Project_Settings/Startup_Code/startup.d 


# Each subdirectory must supply rules for building sources it contributes
Project_Settings/Startup_Code/%.o: ../Project_Settings/Startup_Code/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"C:/Users/Miriam/workspace.kds/CSCI361-Lab4/Static_Code/PDD" -I"C:/Users/Miriam/workspace.kds/CSCI361-Lab4/Static_Code/IO_Map" -I"C:/Users/Miriam/workspace.kds/CSCI361-Lab4/Sources" -I"C:/Users/Miriam/workspace.kds/CSCI361-Lab4/Generated_Code" -I"C:/Users/Miriam/workspace.kds/CSCI361-Lab4/Sources/TSS" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


