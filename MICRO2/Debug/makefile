################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include NewNewMc.2/SERV_UART/subdir.mk
-include NewNewMc.2/MCAL/UART/subdir.mk
-include NewNewMc.2/MCAL/TIMER0/subdir.mk
-include NewNewMc.2/MCAL/SPI/subdir.mk
-include NewNewMc.2/MCAL/External_interrupt/subdir.mk
-include NewNewMc.2/MCAL/DIO/subdir.mk
-include NewNewMc.2/HAL/MOTOR/subdir.mk
-include NewNewMc.2/HAL/LED/subdir.mk
-include NewNewMc.2/HAL/LCD/subdir.mk
-include NewNewMc.2/Debug/SERV_UART/subdir.mk
-include NewNewMc.2/Debug/MCAL/UART/subdir.mk
-include NewNewMc.2/Debug/MCAL/TIMER0/subdir.mk
-include NewNewMc.2/Debug/MCAL/SPI/subdir.mk
-include NewNewMc.2/Debug/MCAL/External_interrupt/subdir.mk
-include NewNewMc.2/Debug/MCAL/DIO/subdir.mk
-include NewNewMc.2/Debug/HAL/LED/subdir.mk
-include NewNewMc.2/Debug/HAL/LCD/subdir.mk
-include NewNewMc.2/Debug/HAL/KEYPAD/subdir.mk
-include NewNewMc.2/Debug/APP/subdir.mk
-include NewNewMc.2/APP/subdir.mk
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
MICRO2.lss \

FLASH_IMAGE += \
MICRO2.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: MICRO2.elf secondary-outputs

# Tool invocations
MICRO2.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,MICRO2.map -mmcu=atmega32 -o "MICRO2.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

MICRO2.lss: MICRO2.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S MICRO2.elf  >"MICRO2.lss"
	@echo 'Finished building: $@'
	@echo ' '

MICRO2.hex: MICRO2.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex MICRO2.elf  "MICRO2.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: MICRO2.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 MICRO2.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) MICRO2.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents

-include ../makefile.targets
