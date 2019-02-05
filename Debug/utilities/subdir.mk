################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../utilities/ArrayUtilities.cpp \
../utilities/FileInputOutput.cpp 

OBJS += \
./utilities/ArrayUtilities.o \
./utilities/FileInputOutput.o 

CPP_DEPS += \
./utilities/ArrayUtilities.d \
./utilities/FileInputOutput.d 


# Each subdirectory must supply rules for building sources it contributes
utilities/%.o: ../utilities/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


