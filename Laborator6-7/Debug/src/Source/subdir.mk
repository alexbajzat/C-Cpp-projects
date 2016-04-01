################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Source/Laborator6-7.cpp \
../src/Source/UI.cpp \
../src/Source/controller.cpp \
../src/Source/disciplineRepo.cpp \
../src/Source/domain.cpp 

OBJS += \
./src/Source/Laborator6-7.o \
./src/Source/UI.o \
./src/Source/controller.o \
./src/Source/disciplineRepo.o \
./src/Source/domain.o 

CPP_DEPS += \
./src/Source/Laborator6-7.d \
./src/Source/UI.d \
./src/Source/controller.d \
./src/Source/disciplineRepo.d \
./src/Source/domain.d 


# Each subdirectory must supply rules for building sources it contributes
src/Source/%.o: ../src/Source/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


