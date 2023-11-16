################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/button.c \
../Core/Src/ds3231.c \
../Core/Src/fsm.c \
../Core/Src/fsm_alarm.c \
../Core/Src/fsmc.c \
../Core/Src/global.c \
../Core/Src/gpio.c \
../Core/Src/i2c.c \
../Core/Src/lcd.c \
../Core/Src/led_7seg.c \
../Core/Src/main.c \
../Core/Src/picture.c \
../Core/Src/software_timer.c \
../Core/Src/spi.c \
../Core/Src/stm32f4xx_hal_msp.c \
../Core/Src/stm32f4xx_it.c \
../Core/Src/syscalls.c \
../Core/Src/sysmem.c \
../Core/Src/system_stm32f4xx.c \
../Core/Src/tim.c \
../Core/Src/utils.c 

OBJS += \
./Core/Src/button.o \
./Core/Src/ds3231.o \
./Core/Src/fsm.o \
./Core/Src/fsm_alarm.o \
./Core/Src/fsmc.o \
./Core/Src/global.o \
./Core/Src/gpio.o \
./Core/Src/i2c.o \
./Core/Src/lcd.o \
./Core/Src/led_7seg.o \
./Core/Src/main.o \
./Core/Src/picture.o \
./Core/Src/software_timer.o \
./Core/Src/spi.o \
./Core/Src/stm32f4xx_hal_msp.o \
./Core/Src/stm32f4xx_it.o \
./Core/Src/syscalls.o \
./Core/Src/sysmem.o \
./Core/Src/system_stm32f4xx.o \
./Core/Src/tim.o \
./Core/Src/utils.o 

C_DEPS += \
./Core/Src/button.d \
./Core/Src/ds3231.d \
./Core/Src/fsm.d \
./Core/Src/fsm_alarm.d \
./Core/Src/fsmc.d \
./Core/Src/global.d \
./Core/Src/gpio.d \
./Core/Src/i2c.d \
./Core/Src/lcd.d \
./Core/Src/led_7seg.d \
./Core/Src/main.d \
./Core/Src/picture.d \
./Core/Src/software_timer.d \
./Core/Src/spi.d \
./Core/Src/stm32f4xx_hal_msp.d \
./Core/Src/stm32f4xx_it.d \
./Core/Src/syscalls.d \
./Core/Src/sysmem.d \
./Core/Src/system_stm32f4xx.d \
./Core/Src/tim.d \
./Core/Src/utils.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o Core/Src/%.su: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src

clean-Core-2f-Src:
	-$(RM) ./Core/Src/button.d ./Core/Src/button.o ./Core/Src/button.su ./Core/Src/ds3231.d ./Core/Src/ds3231.o ./Core/Src/ds3231.su ./Core/Src/fsm.d ./Core/Src/fsm.o ./Core/Src/fsm.su ./Core/Src/fsm_alarm.d ./Core/Src/fsm_alarm.o ./Core/Src/fsm_alarm.su ./Core/Src/fsmc.d ./Core/Src/fsmc.o ./Core/Src/fsmc.su ./Core/Src/global.d ./Core/Src/global.o ./Core/Src/global.su ./Core/Src/gpio.d ./Core/Src/gpio.o ./Core/Src/gpio.su ./Core/Src/i2c.d ./Core/Src/i2c.o ./Core/Src/i2c.su ./Core/Src/lcd.d ./Core/Src/lcd.o ./Core/Src/lcd.su ./Core/Src/led_7seg.d ./Core/Src/led_7seg.o ./Core/Src/led_7seg.su ./Core/Src/main.d ./Core/Src/main.o ./Core/Src/main.su ./Core/Src/picture.d ./Core/Src/picture.o ./Core/Src/picture.su ./Core/Src/software_timer.d ./Core/Src/software_timer.o ./Core/Src/software_timer.su ./Core/Src/spi.d ./Core/Src/spi.o ./Core/Src/spi.su ./Core/Src/stm32f4xx_hal_msp.d ./Core/Src/stm32f4xx_hal_msp.o ./Core/Src/stm32f4xx_hal_msp.su ./Core/Src/stm32f4xx_it.d ./Core/Src/stm32f4xx_it.o ./Core/Src/stm32f4xx_it.su ./Core/Src/syscalls.d ./Core/Src/syscalls.o ./Core/Src/syscalls.su ./Core/Src/sysmem.d ./Core/Src/sysmem.o ./Core/Src/sysmem.su ./Core/Src/system_stm32f4xx.d ./Core/Src/system_stm32f4xx.o ./Core/Src/system_stm32f4xx.su ./Core/Src/tim.d ./Core/Src/tim.o ./Core/Src/tim.su ./Core/Src/utils.d ./Core/Src/utils.o ./Core/Src/utils.su

.PHONY: clean-Core-2f-Src

