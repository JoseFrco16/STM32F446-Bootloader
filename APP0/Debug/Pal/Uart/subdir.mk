################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Pal/Uart/Uart.c \
../Pal/Uart/Uart_Irq.c 

OBJS += \
./Pal/Uart/Uart.o \
./Pal/Uart/Uart_Irq.o 

C_DEPS += \
./Pal/Uart/Uart.d \
./Pal/Uart/Uart_Irq.d 


# Each subdirectory must supply rules for building sources it contributes
Pal/Uart/%.o: ../Pal/Uart/%.c Pal/Uart/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Hal/Stm32_Drivers/STM32F4xx_HAL_Driver/Inc -I../Hal/Stm32_Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Hal/Stm32_Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Hal/Stm32_Drivers/CMSIS/Include -I"../Pal/Uart" -I"../Pal/Timer" -I"../App/Main" -I"../App/Boot" -I"../Pal/Gpio" -I"../Pal/Pal_Mngr" -I"../Pal/Mcu" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Pal-2f-Uart

clean-Pal-2f-Uart:
	-$(RM) ./Pal/Uart/Uart.d ./Pal/Uart/Uart.o ./Pal/Uart/Uart.su ./Pal/Uart/Uart_Irq.d ./Pal/Uart/Uart_Irq.o ./Pal/Uart/Uart_Irq.su

.PHONY: clean-Pal-2f-Uart

