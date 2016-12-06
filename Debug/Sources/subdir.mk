################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/Events.c \
../Sources/main.c 

ASM_SRCS += \
../Sources/helper.asm 

OBJS += \
./Sources/Events.o \
./Sources/helper.o \
./Sources/main.o 

C_DEPS += \
./Sources/Events.d \
./Sources/main.d 

ASM_DEPS += \
./Sources/helper.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/%.o: ../Sources/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"M:/Users/cetho/workspace.kds/Lab 3/Static_Code/PDD" -I"M:/Users/cetho/workspace.kds/Lab 3/Static_Code/IO_Map" -I"M:/Users/cetho/workspace.kds/Lab 3/Sources" -I"M:/Users/cetho/workspace.kds/Lab 3/Generated_Code" -I"M:/Users/cetho/workspace.kds/Lab 3/Sources/TSS" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Sources/%.o: ../Sources/%.asm
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU Assembler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


