################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../STM32f103c6_Drivers/Src/EXTI.c \
../STM32f103c6_Drivers/Src/GPIO.c 

OBJS += \
./STM32f103c6_Drivers/Src/EXTI.o \
./STM32f103c6_Drivers/Src/GPIO.o 

C_DEPS += \
./STM32f103c6_Drivers/Src/EXTI.d \
./STM32f103c6_Drivers/Src/GPIO.d 


# Each subdirectory must supply rules for building sources it contributes
STM32f103c6_Drivers/Src/EXTI.o: ../STM32f103c6_Drivers/Src/EXTI.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/Users/AM/workspace/Embedded_Systems_Online_Diploma/unit 7/lesson4_EXTI/HAL/Inc" -I"C:/Users/AM/workspace/Embedded_Systems_Online_Diploma/unit 7/lesson4_EXTI/STM32f103c6_Drivers/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32f103c6_Drivers/Src/EXTI.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
STM32f103c6_Drivers/Src/GPIO.o: ../STM32f103c6_Drivers/Src/GPIO.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/Users/AM/workspace/Embedded_Systems_Online_Diploma/unit 7/lesson4_EXTI/HAL/Inc" -I"C:/Users/AM/workspace/Embedded_Systems_Online_Diploma/unit 7/lesson4_EXTI/STM32f103c6_Drivers/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32f103c6_Drivers/Src/GPIO.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

