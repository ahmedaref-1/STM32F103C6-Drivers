################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/STM32F103C6_EXTERNALINTERRUPTS.c \
../MCAL/STM32F103C6_GPIO.c 

OBJS += \
./MCAL/STM32F103C6_EXTERNALINTERRUPTS.o \
./MCAL/STM32F103C6_GPIO.o 

C_DEPS += \
./MCAL/STM32F103C6_EXTERNALINTERRUPTS.d \
./MCAL/STM32F103C6_GPIO.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/%.o MCAL/%.su MCAL/%.cyclo: ../MCAL/%.c MCAL/subdir.mk
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -c -I../Inc -I"D:/Embedded Systems Labs Solution/STM32 Cube IDE Projects/STM32F103C6/HAL/includes" -I"D:/Embedded Systems Labs Solution/STM32 Cube IDE Projects/STM32F103C6/MCAL/includes" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-MCAL

clean-MCAL:
	-$(RM) ./MCAL/STM32F103C6_EXTERNALINTERRUPTS.cyclo ./MCAL/STM32F103C6_EXTERNALINTERRUPTS.d ./MCAL/STM32F103C6_EXTERNALINTERRUPTS.o ./MCAL/STM32F103C6_EXTERNALINTERRUPTS.su ./MCAL/STM32F103C6_GPIO.cyclo ./MCAL/STM32F103C6_GPIO.d ./MCAL/STM32F103C6_GPIO.o ./MCAL/STM32F103C6_GPIO.su

.PHONY: clean-MCAL

