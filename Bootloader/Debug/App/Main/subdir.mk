################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../App/Main/App_main.c \
../App/Main/Ver.c 

OBJS += \
./App/Main/App_main.o \
./App/Main/Ver.o 

C_DEPS += \
./App/Main/App_main.d \
./App/Main/Ver.d 


# Each subdirectory must supply rules for building sources it contributes
App/Main/%.o: ../App/Main/%.c App/Main/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Hal/Stm32_Drivers/STM32F4xx_HAL_Driver/Inc -I../Hal/Stm32_Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Hal/Stm32_Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Hal/Stm32_Drivers/CMSIS/Include -I"../Pal/Uart" -I"../App/Header" -I"../App/Main" -I"../App/Verif" -I"../App/Boot" -I"../Pal/Gpio" -I"../Pal/Pal_Mngr" -I"../Pal/Mcu" -I"../Pal/Flash" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-App-2f-Main

clean-App-2f-Main:
	-$(RM) ./App/Main/App_main.d ./App/Main/App_main.o ./App/Main/App_main.su ./App/Main/Ver.d ./App/Main/Ver.o ./App/Main/Ver.su

.PHONY: clean-App-2f-Main

