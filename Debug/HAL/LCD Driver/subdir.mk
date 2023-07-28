################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/LCD\ Driver/STM32F103C6_LCD.c 

OBJS += \
./HAL/LCD\ Driver/STM32F103C6_LCD.o 

C_DEPS += \
./HAL/LCD\ Driver/STM32F103C6_LCD.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/LCD\ Driver/STM32F103C6_LCD.o: ../HAL/LCD\ Driver/STM32F103C6_LCD.c HAL/LCD\ Driver/subdir.mk
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -c -I../Inc -I"D:/Embedded Systems Labs Solution/STM32 Cube IDE Projects/STM32F103C6/HAL/Keypad Driver" -I"D:/Embedded Systems Labs Solution/STM32 Cube IDE Projects/STM32F103C6/HAL/LCD Driver" -I"D:/Embedded Systems Labs Solution/STM32 Cube IDE Projects/STM32F103C6/MCAL/External Interrupts Driver" -I"D:/Embedded Systems Labs Solution/STM32 Cube IDE Projects/STM32F103C6/MCAL/GPIO Driver" -I"D:/Embedded Systems Labs Solution/STM32 Cube IDE Projects/STM32F103C6/MCAL/includes" -I"D:/Embedded Systems Labs Solution/STM32 Cube IDE Projects/STM32F103C6/MCAL/External Interrupts Driver" -I"D:/Embedded Systems Labs Solution/STM32 Cube IDE Projects/STM32F103C6/MCAL/GPIO Driver" -I"D:/Embedded Systems Labs Solution/STM32 Cube IDE Projects/STM32F103C6/MCAL/includes" -I"D:/Embedded Systems Labs Solution/STM32 Cube IDE Projects/STM32F103C6/MCAL/includes" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"HAL/LCD Driver/STM32F103C6_LCD.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-HAL-2f-LCD-20-Driver

clean-HAL-2f-LCD-20-Driver:
	-$(RM) ./HAL/LCD\ Driver/STM32F103C6_LCD.cyclo ./HAL/LCD\ Driver/STM32F103C6_LCD.d ./HAL/LCD\ Driver/STM32F103C6_LCD.o ./HAL/LCD\ Driver/STM32F103C6_LCD.su

.PHONY: clean-HAL-2f-LCD-20-Driver

