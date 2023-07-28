################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/Keypad\ Driver/STM32F103C6_KEYPAD.c 

OBJS += \
./HAL/Keypad\ Driver/STM32F103C6_KEYPAD.o 

C_DEPS += \
./HAL/Keypad\ Driver/STM32F103C6_KEYPAD.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/Keypad\ Driver/STM32F103C6_KEYPAD.o: ../HAL/Keypad\ Driver/STM32F103C6_KEYPAD.c HAL/Keypad\ Driver/subdir.mk
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -c -I../Inc -I"D:/Embedded Systems Labs Solution/STM32 Cube IDE Projects/STM32F103C6/HAL/Keypad Driver" -I"D:/Embedded Systems Labs Solution/STM32 Cube IDE Projects/STM32F103C6/HAL/LCD Driver" -I"D:/Embedded Systems Labs Solution/STM32 Cube IDE Projects/STM32F103C6/MCAL/External Interrupts Driver" -I"D:/Embedded Systems Labs Solution/STM32 Cube IDE Projects/STM32F103C6/MCAL/GPIO Driver" -I"D:/Embedded Systems Labs Solution/STM32 Cube IDE Projects/STM32F103C6/MCAL/includes" -I"D:/Embedded Systems Labs Solution/STM32 Cube IDE Projects/STM32F103C6/MCAL/External Interrupts Driver" -I"D:/Embedded Systems Labs Solution/STM32 Cube IDE Projects/STM32F103C6/MCAL/GPIO Driver" -I"D:/Embedded Systems Labs Solution/STM32 Cube IDE Projects/STM32F103C6/MCAL/includes" -I"D:/Embedded Systems Labs Solution/STM32 Cube IDE Projects/STM32F103C6/MCAL/includes" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"HAL/Keypad Driver/STM32F103C6_KEYPAD.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-HAL-2f-Keypad-20-Driver

clean-HAL-2f-Keypad-20-Driver:
	-$(RM) ./HAL/Keypad\ Driver/STM32F103C6_KEYPAD.cyclo ./HAL/Keypad\ Driver/STM32F103C6_KEYPAD.d ./HAL/Keypad\ Driver/STM32F103C6_KEYPAD.o ./HAL/Keypad\ Driver/STM32F103C6_KEYPAD.su

.PHONY: clean-HAL-2f-Keypad-20-Driver

