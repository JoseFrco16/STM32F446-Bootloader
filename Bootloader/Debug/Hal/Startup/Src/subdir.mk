################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../Hal/Startup/Src/startup_stm32f446retx.s 

OBJS += \
./Hal/Startup/Src/startup_stm32f446retx.o 

S_DEPS += \
./Hal/Startup/Src/startup_stm32f446retx.d 


# Each subdirectory must supply rules for building sources it contributes
Hal/Startup/Src/%.o: ../Hal/Startup/Src/%.s Hal/Startup/Src/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m4 -g3 -DDEBUG -c -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"

clean: clean-Hal-2f-Startup-2f-Src

clean-Hal-2f-Startup-2f-Src:
	-$(RM) ./Hal/Startup/Src/startup_stm32f446retx.d ./Hal/Startup/Src/startup_stm32f446retx.o

.PHONY: clean-Hal-2f-Startup-2f-Src

