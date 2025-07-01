################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Libraries/terminal/terminal.c 

OBJS += \
./Libraries/terminal/terminal.o 

C_DEPS += \
./Libraries/terminal/terminal.d 


# Each subdirectory must supply rules for building sources it contributes
Libraries/terminal/%.o Libraries/terminal/%.su Libraries/terminal/%.cyclo: ../Libraries/terminal/%.c Libraries/terminal/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/oguzhan.caglar/Desktop/Hardware/STM32-Projects/STM32F407-DISCO/Libraries/terminal" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Libraries-2f-terminal

clean-Libraries-2f-terminal:
	-$(RM) ./Libraries/terminal/terminal.cyclo ./Libraries/terminal/terminal.d ./Libraries/terminal/terminal.o ./Libraries/terminal/terminal.su

.PHONY: clean-Libraries-2f-terminal

