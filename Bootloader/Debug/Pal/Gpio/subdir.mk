################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Pal/Gpio/Gpio.c 

OBJS += \
./Pal/Gpio/Gpio.o 

C_DEPS += \
./Pal/Gpio/Gpio.d 


# Each subdirectory must supply rules for building sources it contributes
Pal/Gpio/%.o: ../Pal/Gpio/%.c Pal/Gpio/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Hal/Stm32_Drivers/STM32F4xx_HAL_Driver/Inc -I../Hal/Stm32_Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Hal/Stm32_Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Hal/Stm32_Drivers/CMSIS/Include -I"../Pal/Uart" -I"../App/Header" -I"../App/Main" -I"../App/Verif" -I"../App/Boot" -I"../Pal/Gpio" -I"../Pal/Pal_Mngr" -I"../Pal/Mcu" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Pal-2f-Gpio

clean-Pal-2f-Gpio:
	-$(RM) ./Pal/Gpio/Gpio.d ./Pal/Gpio/Gpio.o ./Pal/Gpio/Gpio.su

.PHONY: clean-Pal-2f-Gpio

