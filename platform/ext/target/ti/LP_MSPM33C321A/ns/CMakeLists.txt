#-------------------------------------------------------------------------------
# SPDX-License-Identifier: BSD-3-Clause
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
# Copyright (c) 2026 Texas Instruments Incorporated
#
# This file is exported to NS side during CMake installation phase and renamed
# to CMakeLists.txt. It instructs how to build the platform_ns library for
# the LP_MSPM33C321A Non-Secure application.
#-------------------------------------------------------------------------------

add_library(platform_ns)

target_sources(platform_ns
    PRIVATE
        board.c
        clock_config.c
        pin_mux.c
        cmsis_drivers/Driver_USART.c
        Device/Source/startup_mspm33c321a_s.c
)

target_include_directories(platform_ns
    PUBLIC
        .
        Device/Include
        include
        partition
        cmsis_drivers
        ext/cmsis/Include
        ext/cmsis/Include/m-profile
        ext/common
)

target_compile_definitions(platform_ns
    PUBLIC
        __MSPM33C321A__
        MSPM33C321A
        __SAUREGION_PRESENT=1
        __DSP_PRESENT=1
        __FPU_PRESENT=0
        CMSIS_device_header="mspm33c321x.h"
)

# Resolve TI driverlib sources — use bundled Native_Driver or an external SDK path.
# TFM_PLATFORM_TI_HAL_FILE_PATH is set to LOCAL by default (see config.cmake).
# When installed, Native_Driver is copied alongside this file in api_ns/platform/.
if(NOT DEFINED TFM_PLATFORM_TI_HAL_FILE_PATH OR TFM_PLATFORM_TI_HAL_FILE_PATH STREQUAL "LOCAL")
    set(TI_HAL_FILE_PATH ${CMAKE_CURRENT_LIST_DIR}/Native_Driver/ti/driverlib)
    set(TI_NATIVE_DRIVER_ROOT ${CMAKE_CURRENT_LIST_DIR}/Native_Driver)
else()
    set(TI_HAL_FILE_PATH ${TFM_PLATFORM_TI_HAL_FILE_PATH}/source/ti/driverlib)
    set(TI_NATIVE_DRIVER_ROOT ${TFM_PLATFORM_TI_HAL_FILE_PATH}/source)
endif()

# TI driverlib for NS side UART
target_sources(platform_ns
    PRIVATE
        ${TI_HAL_FILE_PATH}/dl_unicommuart.c
        ${TI_HAL_FILE_PATH}/dl_gpio.c
)

target_include_directories(platform_ns
    PUBLIC
        ${TI_NATIVE_DRIVER_ROOT}
        ${TI_NATIVE_DRIVER_ROOT}/ti/devices/msp/m33
)

# Include region_defs.h and flash_layout.h
target_include_directories(platform_region_defs
    INTERFACE
        partition
)
