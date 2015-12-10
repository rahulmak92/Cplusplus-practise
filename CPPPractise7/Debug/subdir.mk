################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../FinalExam.cpp \
../GradeActivity.cpp \
../PassFailActivity.cpp \
../PassFailExam.cpp \
../main.cpp 

OBJS += \
./FinalExam.o \
./GradeActivity.o \
./PassFailActivity.o \
./PassFailExam.o \
./main.o 

CPP_DEPS += \
./FinalExam.d \
./GradeActivity.d \
./PassFailActivity.d \
./PassFailExam.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


