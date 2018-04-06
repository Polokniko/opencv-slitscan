################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/slitscan.cpp 

OBJS += \
./src/slitscan.o 

CPP_DEPS += \
./src/slitscan.d 


# Each subdirectory must supply rules for building sources it contributes
src/slitscan.o: ../src/slitscan.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/include/opencv -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"src/slitscan.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


