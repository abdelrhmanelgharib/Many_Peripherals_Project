################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include NewNewMc.1/SERV_UART/subdir.mk
-include NewNewMc.1/MCAL/UART/subdir.mk
-include NewNewMc.1/MCAL/TIMER1/subdir.mk
-include NewNewMc.1/MCAL/TIMER0/subdir.mk
-include NewNewMc.1/MCAL/SPI/subdir.mk
-include NewNewMc.1/MCAL/External_interrupt/subdir.mk
-include NewNewMc.1/MCAL/DIO/subdir.mk
-include NewNewMc.1/MCAL/ADC/subdir.mk
-include NewNewMc.1/HAL/sensors/subdir.mk
-include NewNewMc.1/HAL/Ultrasonic/subdir.mk
-include NewNewMc.1/HAL/KEYPAD/subdir.mk
-include NewNewMc.1/APP/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
MICRO1.lss \

FLASH_IMAGE += \
MICRO1.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: MICRO1.elf secondary-outputs

# Tool invocations
MICRO1.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,MICRO1.map -mmcu=atmega32 -o "MICRO1.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

MICRO1.lss: MICRO1.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S MICRO1.elf  >"MICRO1.lss"
	@echo 'Finished building: $@'
	@echo ' '

MICRO1.hex: MICRO1.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex MICRO1.elf  "MICRO1.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: MICRO1.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 MICRO1.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) MICRO1.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents

-include ../makefile.targets
