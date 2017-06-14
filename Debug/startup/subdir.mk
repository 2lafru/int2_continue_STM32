################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../startup/startup_stm32f103xb.s 

OBJS += \
./startup/startup_stm32f103xb.o 


# Each subdirectory must supply rules for building sources it contributes
startup/%.o: ../startup/%.s
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Assembler'
	@echo $(PWD)
	arm-none-eabi-as -mcpu=cortex-m3 -mthumb -mfloat-abi=soft -I"/home/elafru/workspace/nucleo-f103rb_hal_lib" -I"/home/elafru/workspace/pedago/inc" -I"/home/elafru/workspace/nucleo-f103rb_hal_lib/HAL_Driver/Inc" -I"/home/elafru/workspace/nucleo-f103rb_hal_lib/HAL_Driver/Inc/Legacy" -I"/home/elafru/workspace/nucleo-f103rb_hal_lib/Utilities/STM32F1xx_Nucleo" -I"/home/elafru/workspace/nucleo-f103rb_hal_lib/CMSIS/device" -I"/home/elafru/workspace/nucleo-f103rb_hal_lib/CMSIS/core" -g -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


