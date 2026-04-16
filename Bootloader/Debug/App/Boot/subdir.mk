################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../App/Boot/Boot.c \
../App/Boot/Boot_Handlers.c \
../App/Boot/Boot_Protocol.c 

OBJS += \
./App/Boot/Boot.o \
./App/Boot/Boot_Handlers.o \
./App/Boot/Boot_Protocol.o 

C_DEPS += \
./App/Boot/Boot.d \
./App/Boot/Boot_Handlers.d \
./App/Boot/Boot_Protocol.d 


# Each subdirectory must supply rules for building sources it contributes
App/Boot/%.o: ../App/Boot/%.c App/Boot/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Hal/Stm32_Drivers/STM32F4xx_HAL_Driver/Inc -I../Hal/Stm32_Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Hal/Stm32_Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Hal/Stm32_Drivers/CMSIS/Include -I"../Pal/Uart" -I"../App/Header" -I"../App/Main" -I"../App/Verif" -I"../App/Boot" -I"../Pal/Gpio" -I"../Pal/Pal_Mngr" -I"../Pal/Mcu" -I"../Pal/Flash" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-App-2f-Boot

clean-App-2f-Boot:
	-$(RM) ./App/Boot/Boot.d ./App/Boot/Boot.o ./App/Boot/Boot.su ./App/Boot/Boot_Handlers.d ./App/Boot/Boot_Handlers.o ./App/Boot/Boot_Handlers.su ./App/Boot/Boot_Protocol.d ./App/Boot/Boot_Protocol.o ./App/Boot/Boot_Protocol.su

.PHONY: clean-App-2f-Boot

