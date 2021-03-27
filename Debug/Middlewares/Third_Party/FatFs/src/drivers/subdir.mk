################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/Third_Party/FatFs/src/drivers/sd_diskio.c 

OBJS += \
./Middlewares/Third_Party/FatFs/src/drivers/sd_diskio.o 

C_DEPS += \
./Middlewares/Third_Party/FatFs/src/drivers/sd_diskio.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/Third_Party/FatFs/src/drivers/sd_diskio.o: ../Middlewares/Third_Party/FatFs/src/drivers/sd_diskio.c Middlewares/Third_Party/FatFs/src/drivers/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F411xE -DDEBUG -c -I../Drivers/BSP/STM32F4xx-Nucleo -I../Drivers/STM32F4xx_HAL_Driver/Inc -IDrivers/CMSIS/Include -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -IDrivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/BSP/Adafruit_Shield -I../Middlewares/Third_Party/FatFs/src/drivers -IDrivers/STM32F4xx_HAL_Driver/Inc/Legacy -IMiddlewares/Third_Party/FatFs/src -I../Inc -I../Middlewares/Third_Party/FatFs/src/Core -I../Drivers/CMSIS/Include -IDrivers/STM32F4xx_HAL_Driver/Inc -I../Middlewares/Third_Party/FatFs/src -IInc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Middlewares/Third_Party/FatFs/src/drivers/sd_diskio.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

