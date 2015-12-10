################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Priority_queue.cpp \
../Success_array.cpp \
../Task.cpp \
../main.cpp 

OBJS += \
./Priority_queue.o \
./Success_array.o \
./Task.o \
./main.o 

CPP_DEPS += \
./Priority_queue.d \
./Success_array.d \
./Task.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


