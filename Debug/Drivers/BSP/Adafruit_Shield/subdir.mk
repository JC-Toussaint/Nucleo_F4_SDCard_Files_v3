################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/BSP/Adafruit_Shield/stm32_adafruit_lcd.c \
../Drivers/BSP/Adafruit_Shield/stm32_adafruit_sd.c 

OBJS += \
./Drivers/BSP/Adafruit_Shield/stm32_adafruit_lcd.o \
./Drivers/BSP/Adafruit_Shield/stm32_adafruit_sd.o 

C_DEPS += \
./Drivers/BSP/Adafruit_Shield/stm32_adafruit_lcd.d \
./Drivers/BSP/Adafruit_Shield/stm32_adafruit_sd.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/BSP/Adafruit_Shield/stm32_adafruit_lcd.o: ../Drivers/BSP/Adafruit_Shield/stm32_adafruit_lcd.c Drivers/BSP/Adafruit_Shield/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F411xE -DDEBUG -c -I../Drivers/BSP/STM32F4xx-Nucleo -I../Drivers/STM32F4xx_HAL_Driver/Inc -IDrivers/CMSIS/Include -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -IDrivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/BSP/Adafruit_Shield -I../Middlewares/Third_Party/FatFs/src/drivers -IDrivers/STM32F4xx_HAL_Driver/Inc/Legacy -IMiddlewares/Third_Party/FatFs/src -I../Inc -I../Middlewares/Third_Party/FatFs/src/Core -I../Drivers/CMSIS/Include -IDrivers/STM32F4xx_HAL_Driver/Inc -I../Middlewares/Third_Party/FatFs/src -IInc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/BSP/Adafruit_Shield/stm32_adafruit_lcd.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/BSP/Adafruit_Shield/stm32_adafruit_sd.o: ../Drivers/BSP/Adafruit_Shield/stm32_adafruit_sd.c Drivers/BSP/Adafruit_Shield/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F411xE -DDEBUG -c -I../Drivers/BSP/STM32F4xx-Nucleo -I../Drivers/STM32F4xx_HAL_Driver/Inc -IDrivers/CMSIS/Include -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -IDrivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/BSP/Adafruit_Shield -I../Middlewares/Third_Party/FatFs/src/drivers -IDrivers/STM32F4xx_HAL_Driver/Inc/Legacy -IMiddlewares/Third_Party/FatFs/src -I../Inc -I../Middlewares/Third_Party/FatFs/src/Core -I../Drivers/CMSIS/Include -IDrivers/STM32F4xx_HAL_Driver/Inc -I../Middlewares/Third_Party/FatFs/src -IInc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/BSP/Adafruit_Shield/stm32_adafruit_sd.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

