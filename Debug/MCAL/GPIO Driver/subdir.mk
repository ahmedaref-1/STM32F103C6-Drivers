################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/GPIO\ Driver/STM32F103C6_GPIO.c 

OBJS += \
./MCAL/GPIO\ Driver/STM32F103C6_GPIO.o 

C_DEPS += \
./MCAL/GPIO\ Driver/STM32F103C6_GPIO.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/GPIO\ Driver/STM32F103C6_GPIO.o: ../MCAL/GPIO\ Driver/STM32F103C6_GPIO.c MCAL/GPIO\ Driver/subdir.mk
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -c -I../Inc -I"D:/Embedded Systems Labs Solution/STM32 Cube IDE Projects/STM32F103C6/HAL/Keypad Driver" -I"D:/Embedded Systems Labs Solution/STM32 Cube IDE Projects/STM32F103C6/HAL/LCD Driver" -I"D:/Embedded Systems Labs Solution/STM32 Cube IDE Projects/STM32F103C6/MCAL/External Interrupts Driver" -I"D:/Embedded Systems Labs Solution/STM32 Cube IDE Projects/STM32F103C6/MCAL/GPIO Driver" -I"D:/Embedded Systems Labs Solution/STM32 Cube IDE Projects/STM32F103C6/MCAL/includes" -I"D:/Embedded Systems Labs Solution/STM32 Cube IDE Projects/STM32F103C6/MCAL/External Interrupts Driver" -I"D:/Embedded Systems Labs Solution/STM32 Cube IDE Projects/STM32F103C6/MCAL/GPIO Driver" -I"D:/Embedded Systems Labs Solution/STM32 Cube IDE Projects/STM32F103C6/MCAL/includes" -I"D:/Embedded Systems Labs Solution/STM32 Cube IDE Projects/STM32F103C6/MCAL/includes" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"MCAL/GPIO Driver/STM32F103C6_GPIO.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-MCAL-2f-GPIO-20-Driver

clean-MCAL-2f-GPIO-20-Driver:
	-$(RM) ./MCAL/GPIO\ Driver/STM32F103C6_GPIO.cyclo ./MCAL/GPIO\ Driver/STM32F103C6_GPIO.d ./MCAL/GPIO\ Driver/STM32F103C6_GPIO.o ./MCAL/GPIO\ Driver/STM32F103C6_GPIO.su

.PHONY: clean-MCAL-2f-GPIO-20-Driver

