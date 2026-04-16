################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Pal/Flash/Flash.c 

OBJS += \
./Pal/Flash/Flash.o 

C_DEPS += \
./Pal/Flash/Flash.d 


# Each subdirectory must supply rules for building sources it contributes
Pal/Flash/%.o: ../Pal/Flash/%.c Pal/Flash/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Hal/Stm32_Drivers/STM32F4xx_HAL_Driver/Inc -I../Hal/Stm32_Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Hal/Stm32_Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Hal/Stm32_Drivers/CMSIS/Include -I"../Pal/Uart" -I"../Pal/Timer" -I"../Pal/Main" -I"../Pal/Flash" -I"../Pal/Gpio" -I"../Pal/Pal_Mngr" -I"../Pal/Mcu" -I"../Pal/Flash -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Pal-2f-Flash

clean-Pal-2f-Flash:
	-$(RM) ./Pal/Flash/Flash.d ./Pal/Flash/Flash.o ./Pal/Flash/Flash.su

.PHONY: clean-Pal-2f-Flash

