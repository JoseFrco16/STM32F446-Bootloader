################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Hal/Stm32_System/Src/System/syscalls.c \
../Hal/Stm32_System/Src/System/sysmem.c \
../Hal/Stm32_System/Src/System/system_stm32f4xx.c 

OBJS += \
./Hal/Stm32_System/Src/System/syscalls.o \
./Hal/Stm32_System/Src/System/sysmem.o \
./Hal/Stm32_System/Src/System/system_stm32f4xx.o 

C_DEPS += \
./Hal/Stm32_System/Src/System/syscalls.d \
./Hal/Stm32_System/Src/System/sysmem.d \
./Hal/Stm32_System/Src/System/system_stm32f4xx.d 


# Each subdirectory must supply rules for building sources it contributes
Hal/Stm32_System/Src/System/%.o Hal/Stm32_System/Src/System/%.su Hal/Stm32_System/Src/System/%.cyclo: ../Hal/Stm32_System/Src/System/%.c Hal/Stm32_System/Src/System/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Hal/Stm32_Drivers/STM32F4xx_HAL_Driver/Inc -I../Hal/Stm32_Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Hal/Stm32_Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Hal/Stm32_Drivers/CMSIS/Include -I"../Pal/Uart" -I"../App/Header" -I"../App/Main" -I"../App/Verif" -I"../App/Boot" -I"../Pal/Gpio" -I"../Pal/Pal_Mngr" -I"../Pal/Mcu" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Hal-2f-Stm32_System-2f-Src-2f-System

clean-Hal-2f-Stm32_System-2f-Src-2f-System:
	-$(RM) ./Hal/Stm32_System/Src/System/syscalls.cyclo ./Hal/Stm32_System/Src/System/syscalls.d ./Hal/Stm32_System/Src/System/syscalls.o ./Hal/Stm32_System/Src/System/syscalls.su ./Hal/Stm32_System/Src/System/sysmem.cyclo ./Hal/Stm32_System/Src/System/sysmem.d ./Hal/Stm32_System/Src/System/sysmem.o ./Hal/Stm32_System/Src/System/sysmem.su ./Hal/Stm32_System/Src/System/system_stm32f4xx.cyclo ./Hal/Stm32_System/Src/System/system_stm32f4xx.d ./Hal/Stm32_System/Src/System/system_stm32f4xx.o ./Hal/Stm32_System/Src/System/system_stm32f4xx.su

.PHONY: clean-Hal-2f-Stm32_System-2f-Src-2f-System

