################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Generated_Code/Cpu.c \
../Generated_Code/GPIO1.c \
../Generated_Code/GPIO2.c \
../Generated_Code/LED_GREEN.c \
../Generated_Code/LED_RED.c \
../Generated_Code/PE_LDD.c \
../Generated_Code/PTC.c \
../Generated_Code/SegLCD1.c \
../Generated_Code/TI1.c \
../Generated_Code/TSS1.c \
../Generated_Code/TU1.c \
../Generated_Code/Vectors.c 

OBJS += \
./Generated_Code/Cpu.o \
./Generated_Code/GPIO1.o \
./Generated_Code/GPIO2.o \
./Generated_Code/LED_GREEN.o \
./Generated_Code/LED_RED.o \
./Generated_Code/PE_LDD.o \
./Generated_Code/PTC.o \
./Generated_Code/SegLCD1.o \
./Generated_Code/TI1.o \
./Generated_Code/TSS1.o \
./Generated_Code/TU1.o \
./Generated_Code/Vectors.o 

C_DEPS += \
./Generated_Code/Cpu.d \
./Generated_Code/GPIO1.d \
./Generated_Code/GPIO2.d \
./Generated_Code/LED_GREEN.d \
./Generated_Code/LED_RED.d \
./Generated_Code/PE_LDD.d \
./Generated_Code/PTC.d \
./Generated_Code/SegLCD1.d \
./Generated_Code/TI1.d \
./Generated_Code/TSS1.d \
./Generated_Code/TU1.d \
./Generated_Code/Vectors.d 


# Each subdirectory must supply rules for building sources it contributes
Generated_Code/%.o: ../Generated_Code/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"M:/Users/cetho/workspace.kds/Lab 3/Static_Code/PDD" -I"M:/Users/cetho/workspace.kds/Lab 3/Static_Code/IO_Map" -I"M:/Users/cetho/workspace.kds/Lab 3/Sources" -I"M:/Users/cetho/workspace.kds/Lab 3/Generated_Code" -I"M:/Users/cetho/workspace.kds/Lab 3/Sources/TSS" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


