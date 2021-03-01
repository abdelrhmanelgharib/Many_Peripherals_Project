################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../NewNewMc.1/MCAL/External_interrupt/ex_int.c 

OBJS += \
./NewNewMc.1/MCAL/External_interrupt/ex_int.o 

C_DEPS += \
./NewNewMc.1/MCAL/External_interrupt/ex_int.d 


# Each subdirectory must supply rules for building sources it contributes
NewNewMc.1/MCAL/External_interrupt/%.o: ../NewNewMc.1/MCAL/External_interrupt/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


