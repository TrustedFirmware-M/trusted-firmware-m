#-------------------------------------------------------------------------------
# Copyright (c) 2023-2024, Arm Limited. All rights reserved.
# Copyright 2023-2025 NXP
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

# This file is exported to NS side during CMake installation phase and renamed
# to CMakeLists.txt. It instructs how to build a platform on non-secture side.
# The structure and sources list are fully platform specific.

add_library(platform_ns)

target_sources(platform_ns
    PUBLIC
        Device/Source/startup_lpcxpresso55s69.c
    PRIVATE
        board.c
        hardware_init.c
        clock_config.c
        pin_mux.c
        Driver_USART.c
        Native_Driver/system_LPC55S69_cm33_core0.c
        Native_Driver/drivers/fsl_clock.c
        Native_Driver/drivers/fsl_power.c
        Native_Driver/drivers/fsl_reset.c
        Native_Driver/components/lists/fsl_component_generic_list.c
        Native_Driver/components/serial_manager/fsl_component_serial_manager.c
        Native_Driver/components/serial_manager/fsl_component_serial_port_uart.c
        Native_Driver/components/uart/fsl_adapter_usart.c
        Native_Driver/drivers/common/fsl_common.c
        Native_Driver/drivers/common/fsl_common_arm.c
        Native_Driver/drivers/ctimer/fsl_ctimer.c
        Native_Driver/drivers/flexcomm/fsl_flexcomm.c
        Native_Driver/drivers/flexcomm/usart/fsl_usart.c
        Native_Driver/drivers/lpc_gpio/fsl_gpio.c
        Native_Driver/drivers/iap1/fsl_iap.c
        Native_Driver/utilities/assert/fsl_assert.c
        Native_Driver/utilities/debug_console/fsl_debug_console.c
        Native_Driver/utilities/str/fsl_str.c
        $<$<BOOL:${TFM_PARTITION_PLATFORM}>:plat_test.c>
)


target_include_directories(platform_ns
    PUBLIC
        include
        ext/cmsis/Include
        ext/cmsis/Include/m-profile
        ext/common
        Native_Driver
        Device/Include
        Device/Config
        Native_Driver/drivers
        Native_Driver/drivers/common
        Native_Driver/drivers/ctimer
        Native_Driver/drivers/iap1
        Native_Driver/drivers/lpc_gpio
        Native_Driver/drivers/lpc_iocon
        Native_Driver/drivers/flexcomm
        Native_Driver/drivers/flexcomm/usart
        Native_Driver/components/lists
        Native_Driver/components/serial_manager
        Native_Driver/components/uart
        Native_Driver/utilities/debug_console
        Native_Driver/utilities/str
        Native_Driver/utilities/assert
        Native_Driver/periph
        partition
)

# Include region_defs.h and flash_layout.h
target_include_directories(platform_region_defs
    INTERFACE
        partition
)
