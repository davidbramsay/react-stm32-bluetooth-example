################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
Z:/Documents/STM32CubeWB/Projects/P-NUCLEO-WB55.Nucleo/Applications/BLE/BLE_p2pServer/STM32_WPAN/App/app_ble.c \
Z:/Documents/STM32CubeWB/Projects/P-NUCLEO-WB55.Nucleo/Applications/BLE/BLE_p2pServer/STM32_WPAN/App/p2p_server_app.c 

OBJS += \
./Application/User/STM32_WPAN/App/app_ble.o \
./Application/User/STM32_WPAN/App/p2p_server_app.o 

C_DEPS += \
./Application/User/STM32_WPAN/App/app_ble.d \
./Application/User/STM32_WPAN/App/p2p_server_app.d 


# Each subdirectory must supply rules for building sources it contributes
Application/User/STM32_WPAN/App/app_ble.o: Z:/Documents/STM32CubeWB/Projects/P-NUCLEO-WB55.Nucleo/Applications/BLE/BLE_p2pServer/STM32_WPAN/App/app_ble.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_STM32WBXX_NUCLEO -DUSE_HAL_DRIVER -DSTM32WB55xx -c -I../../../Core/Inc -I../../../STM32_WPAN/App -I../../../../../../../../Drivers/STM32WBxx_HAL_Driver/Inc -I../../../../../../../../Drivers/STM32WBxx_HAL_Driver/Inc/Legacy -I../../../../../../../../Middlewares/ST/STM32_WPAN -I../../../../../../../../Middlewares/ST/STM32_WPAN/interface/patterns/ble_thread -I../../../../../../../../Middlewares/ST/STM32_WPAN/interface/patterns/ble_thread/tl -I../../../../../../../../Middlewares/ST/STM32_WPAN/interface/patterns/ble_thread/shci -I../../../../../../../../Middlewares/ST/STM32_WPAN/utilities -I../../../../../../../../Utilities/lpm/tiny_lpm -I../../../../../../../../Utilities/sequencer -I../../../../../../../../Middlewares/ST/STM32_WPAN/ble -I../../../../../../../../Middlewares/ST/STM32_WPAN/ble/core/template -I../../../../../../../../Middlewares/ST/STM32_WPAN/ble/core -I../../../../../../../../Drivers/CMSIS/Device/ST/STM32WBxx/Include -I../../../../../../../../Drivers/CMSIS/Include -I../../../../../../../../Drivers/BSP/P-NUCLEO-WB55.Nucleo -Os -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"Application/User/STM32_WPAN/App/app_ble.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/STM32_WPAN/App/p2p_server_app.o: Z:/Documents/STM32CubeWB/Projects/P-NUCLEO-WB55.Nucleo/Applications/BLE/BLE_p2pServer/STM32_WPAN/App/p2p_server_app.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_STM32WBXX_NUCLEO -DUSE_HAL_DRIVER -DSTM32WB55xx -c -I../../../Core/Inc -I../../../STM32_WPAN/App -I../../../../../../../../Drivers/STM32WBxx_HAL_Driver/Inc -I../../../../../../../../Drivers/STM32WBxx_HAL_Driver/Inc/Legacy -I../../../../../../../../Middlewares/ST/STM32_WPAN -I../../../../../../../../Middlewares/ST/STM32_WPAN/interface/patterns/ble_thread -I../../../../../../../../Middlewares/ST/STM32_WPAN/interface/patterns/ble_thread/tl -I../../../../../../../../Middlewares/ST/STM32_WPAN/interface/patterns/ble_thread/shci -I../../../../../../../../Middlewares/ST/STM32_WPAN/utilities -I../../../../../../../../Utilities/lpm/tiny_lpm -I../../../../../../../../Utilities/sequencer -I../../../../../../../../Middlewares/ST/STM32_WPAN/ble -I../../../../../../../../Middlewares/ST/STM32_WPAN/ble/core/template -I../../../../../../../../Middlewares/ST/STM32_WPAN/ble/core -I../../../../../../../../Drivers/CMSIS/Device/ST/STM32WBxx/Include -I../../../../../../../../Drivers/CMSIS/Include -I../../../../../../../../Drivers/BSP/P-NUCLEO-WB55.Nucleo -Os -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"Application/User/STM32_WPAN/App/p2p_server_app.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

