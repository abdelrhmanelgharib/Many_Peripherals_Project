################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../NewNewMc.1/HAL/Ultrasonic/Ultrasonic_prog.c 

OBJS += \
./NewNewMc.1/HAL/Ultrasonic/Ultrasonic_prog.o 

C_DEPS += \
./NewNewMc.1/HAL/Ultrasonic/Ultrasonic_prog.d 


# Each subdirectory must supply rules for building sources it contributes
NewNewMc.1/HAL/Ultrasonic/%.o: ../NewNewMc.1/HAL/Ultrasonic/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


