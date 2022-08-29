################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/Src/Keypad.c \
../HAL/Src/LCD.c 

OBJS += \
./HAL/Src/Keypad.o \
./HAL/Src/LCD.o 

C_DEPS += \
./HAL/Src/Keypad.d \
./HAL/Src/LCD.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/Src/Keypad.o: ../HAL/Src/Keypad.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/Users/AM/STM32CubeIDE/workspace_1.4.0/unit7_lesson3/STM32f103c6_Drivers/Inc" -I"C:/Users/AM/STM32CubeIDE/workspace_1.4.0/unit7_lesson3/HAL/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"HAL/Src/Keypad.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
HAL/Src/LCD.o: ../HAL/Src/LCD.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/Users/AM/STM32CubeIDE/workspace_1.4.0/unit7_lesson3/STM32f103c6_Drivers/Inc" -I"C:/Users/AM/STM32CubeIDE/workspace_1.4.0/unit7_lesson3/HAL/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"HAL/Src/LCD.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

