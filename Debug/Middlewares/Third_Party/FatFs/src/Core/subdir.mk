################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/Third_Party/FatFs/src/Core/diskio.c \
../Middlewares/Third_Party/FatFs/src/Core/ff.c \
../Middlewares/Third_Party/FatFs/src/Core/ff_gen_drv.c 

OBJS += \
./Middlewares/Third_Party/FatFs/src/Core/diskio.o \
./Middlewares/Third_Party/FatFs/src/Core/ff.o \
./Middlewares/Third_Party/FatFs/src/Core/ff_gen_drv.o 

C_DEPS += \
./Middlewares/Third_Party/FatFs/src/Core/diskio.d \
./Middlewares/Third_Party/FatFs/src/Core/ff.d \
./Middlewares/Third_Party/FatFs/src/Core/ff_gen_drv.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/Third_Party/FatFs/src/Core/diskio.o: ../Middlewares/Third_Party/FatFs/src/Core/diskio.c Middlewares/Third_Party/FatFs/src/Core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F411xE -DDEBUG -c -I../Drivers/BSP/STM32F4xx-Nucleo -I../Drivers/STM32F4xx_HAL_Driver/Inc -IDrivers/CMSIS/Include -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -IDrivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/BSP/Adafruit_Shield -I../Middlewares/Third_Party/FatFs/src/drivers -IDrivers/STM32F4xx_HAL_Driver/Inc/Legacy -IMiddlewares/Third_Party/FatFs/src -I../Inc -I../Middlewares/Third_Party/FatFs/src/Core -I../Drivers/CMSIS/Include -IDrivers/STM32F4xx_HAL_Driver/Inc -I../Middlewares/Third_Party/FatFs/src -IInc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Middlewares/Third_Party/FatFs/src/Core/diskio.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Middlewares/Third_Party/FatFs/src/Core/ff.o: ../Middlewares/Third_Party/FatFs/src/Core/ff.c Middlewares/Third_Party/FatFs/src/Core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F411xE -DDEBUG -c -I../Drivers/BSP/STM32F4xx-Nucleo -I../Drivers/STM32F4xx_HAL_Driver/Inc -IDrivers/CMSIS/Include -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -IDrivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/BSP/Adafruit_Shield -I../Middlewares/Third_Party/FatFs/src/drivers -IDrivers/STM32F4xx_HAL_Driver/Inc/Legacy -IMiddlewares/Third_Party/FatFs/src -I../Inc -I../Middlewares/Third_Party/FatFs/src/Core -I../Drivers/CMSIS/Include -IDrivers/STM32F4xx_HAL_Driver/Inc -I../Middlewares/Third_Party/FatFs/src -IInc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Middlewares/Third_Party/FatFs/src/Core/ff.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Middlewares/Third_Party/FatFs/src/Core/ff_gen_drv.o: ../Middlewares/Third_Party/FatFs/src/Core/ff_gen_drv.c Middlewares/Third_Party/FatFs/src/Core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F411xE -DDEBUG -c -I../Drivers/BSP/STM32F4xx-Nucleo -I../Drivers/STM32F4xx_HAL_Driver/Inc -IDrivers/CMSIS/Include -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -IDrivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/BSP/Adafruit_Shield -I../Middlewares/Third_Party/FatFs/src/drivers -IDrivers/STM32F4xx_HAL_Driver/Inc/Legacy -IMiddlewares/Third_Party/FatFs/src -I../Inc -I../Middlewares/Third_Party/FatFs/src/Core -I../Drivers/CMSIS/Include -IDrivers/STM32F4xx_HAL_Driver/Inc -I../Middlewares/Third_Party/FatFs/src -IInc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Middlewares/Third_Party/FatFs/src/Core/ff_gen_drv.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

