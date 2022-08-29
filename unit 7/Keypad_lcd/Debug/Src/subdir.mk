################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/lcd_keypadmain.c \
../Src/syscalls.c \
../Src/sysmem.c 

OBJS += \
./Src/lcd_keypadmain.o \
./Src/syscalls.o \
./Src/sysmem.o 

C_DEPS += \
./Src/lcd_keypadmain.d \
./Src/syscalls.d \
./Src/sysmem.d 


# Each subdirectory must supply rules for building sources it contributes
Src/lcd_keypadmain.o: ../Src/lcd_keypadmain.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/Users/AM/STM32CubeIDE/workspace_1.4.0/Keypad_lcd/STM32f103c6_Drivers/Inc" -I"C:/Users/AM/STM32CubeIDE/workspace_1.4.0/Keypad_lcd/HAL/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/lcd_keypadmain.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Src/syscalls.o: ../Src/syscalls.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/Users/AM/STM32CubeIDE/workspace_1.4.0/Keypad_lcd/STM32f103c6_Drivers/Inc" -I"C:/Users/AM/STM32CubeIDE/workspace_1.4.0/Keypad_lcd/HAL/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/syscalls.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Src/sysmem.o: ../Src/sysmem.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/Users/AM/STM32CubeIDE/workspace_1.4.0/Keypad_lcd/STM32f103c6_Drivers/Inc" -I"C:/Users/AM/STM32CubeIDE/workspace_1.4.0/Keypad_lcd/HAL/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/sysmem.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

