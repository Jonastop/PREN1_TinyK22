################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/utils/ftm0.c \
../Sources/utils/ftm3.c \
../Sources/utils/led.c \
../Sources/utils/util.c 

OBJS += \
./Sources/utils/ftm0.o \
./Sources/utils/ftm3.o \
./Sources/utils/led.o \
./Sources/utils/util.o 

C_DEPS += \
./Sources/utils/ftm0.d \
./Sources/utils/ftm3.d \
./Sources/utils/led.d \
./Sources/utils/util.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/utils/%.o: ../Sources/utils/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"../Sources" -I"../Sources/com" -I"../Sources/drive" -I"../Sources/sound" -I"../Sources/utils" -I"../Includes" -std=c99 -Wa,-adhlns="$@.lst" -v -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


