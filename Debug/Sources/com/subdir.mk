################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/com/lpuart0.c \
../Sources/com/term.c \
../Sources/com/uart0.c \
../Sources/com/uart1.c 

OBJS += \
./Sources/com/lpuart0.o \
./Sources/com/term.o \
./Sources/com/uart0.o \
./Sources/com/uart1.o 

C_DEPS += \
./Sources/com/lpuart0.d \
./Sources/com/term.d \
./Sources/com/uart0.d \
./Sources/com/uart1.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/com/%.o: ../Sources/com/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"../Sources" -I"../Sources/com" -I"../Sources/drive" -I"../Sources/sound" -I"../Sources/utils" -I"../Includes" -std=c99 -Wa,-adhlns="$@.lst" -v -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


