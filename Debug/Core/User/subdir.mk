################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/User/ankle_motors.c \
../Core/User/hip_motors.c \
../Core/User/mpu6050.c 

OBJS += \
./Core/User/ankle_motors.o \
./Core/User/hip_motors.o \
./Core/User/mpu6050.o 

C_DEPS += \
./Core/User/ankle_motors.d \
./Core/User/hip_motors.d \
./Core/User/mpu6050.d 


# Each subdirectory must supply rules for building sources it contributes
Core/User/%.o Core/User/%.su Core/User/%.cyclo: ../Core/User/%.c Core/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H723xx -c -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I"C:/Users/MATTH/code/TR-001/User" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-User

clean-Core-2f-User:
	-$(RM) ./Core/User/ankle_motors.cyclo ./Core/User/ankle_motors.d ./Core/User/ankle_motors.o ./Core/User/ankle_motors.su ./Core/User/hip_motors.cyclo ./Core/User/hip_motors.d ./Core/User/hip_motors.o ./Core/User/hip_motors.su ./Core/User/mpu6050.cyclo ./Core/User/mpu6050.d ./Core/User/mpu6050.o ./Core/User/mpu6050.su

.PHONY: clean-Core-2f-User

