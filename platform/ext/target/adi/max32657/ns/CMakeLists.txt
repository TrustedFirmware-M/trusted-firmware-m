#-------------------------------------------------------------------------------
# Copyright (C) 2024-2025 Analog Devices, Inc.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

# This file is exported to NS side during CMake installation phase and renamed
# to CMakeLists.txt. It instructs how to build a platform on non-secture side.
# The structure and sources list are fully platform specific.
list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/../../trusted-firmware-m/cmake)
include(remote_library)

add_library(platform_ns)

# Fetch hal_adi repository
fetch_remote_library(
    LIB_NAME                hal_adi
    LIB_SOURCE_PATH_VAR     HAL_ADI_PATH
    FETCH_CONTENT_ARGS
        GIT_REPOSITORY      https://github.com/analogdevicesinc/hal_adi
        GIT_TAG             ${HAL_ADI_VERSION}
        GIT_PROGRESS        TRUE
)

set(TARGET_LC "max32657")
string(TOUPPER ${TARGET_LC} TARGET_UC)

set(HAL_ADI_LIBRARY_DIR     ${HAL_ADI_PATH}/MAX/Libraries)

set(HAL_ADI_CMSIS_DIR       ${HAL_ADI_LIBRARY_DIR}/CMSIS/Device/Maxim/${TARGET_UC})
set(HAL_ADI_CMSIS_INC_DIR   ${HAL_ADI_CMSIS_DIR}/Include)
set(HAL_ADI_CMSIS_SRC_DIR   ${HAL_ADI_CMSIS_DIR}/Source)

set(HAL_ADI_PERIPH_DIR      ${HAL_ADI_LIBRARY_DIR}/PeriphDrivers)
set(HAL_ADI_PERIPH_INC_DIR  ${HAL_ADI_PERIPH_DIR}/Include/${TARGET_UC})
set(HAL_ADI_PERIPH_SRC_DIR  ${HAL_ADI_PERIPH_DIR}/Source)

target_compile_definitions(platform_ns
    PUBLIC
        TARGET=${TARGET_UC}
        TARGET_REV=0x4131
        CMSIS_device_header="${TARGET_LC}.h"
)

target_compile_options(platform_ns
    PUBLIC
        -mno-unaligned-access
)

target_sources(platform_ns
    PRIVATE
        Driver_USART.c
        device/src/startup_${TARGET_LC}.c
        device/src/system_${TARGET_LC}.c

        ${HAL_ADI_PERIPH_SRC_DIR}/UART/uart_common.c
        ${HAL_ADI_PERIPH_SRC_DIR}/UART/uart_me30.c
        ${HAL_ADI_PERIPH_SRC_DIR}/UART/uart_revb.c
        ${HAL_ADI_PERIPH_SRC_DIR}/SYS/sys_me30.c
        ${HAL_ADI_PERIPH_SRC_DIR}/SYS/mxc_delay.c
        ${HAL_ADI_PERIPH_SRC_DIR}/GPIO/gpio_me30.c
        ${HAL_ADI_PERIPH_SRC_DIR}/GPIO/gpio_reva.c
        ${HAL_ADI_PERIPH_SRC_DIR}/GPIO/gpio_common.c
        ${HAL_ADI_PERIPH_SRC_DIR}/SYS/pins_me30.c
)

target_include_directories(platform_ns
    PRIVATE
        retarget
    PUBLIC
        include
        include/${TARGET_UC}
        ${HAL_ADI_CMSIS_INC_DIR}
        ${HAL_ADI_PERIPH_INC_DIR}
        ext/cmsis/Include
        ext/cmsis/Include/m-profile
        device/inc
        ext/common
        accelerator/include
)

# Include region_defs.h and flash_layout.h
target_include_directories(platform_region_defs
    INTERFACE
        include
)

# Get S - NS peripheral and memory access
include(s_ns_access.cmake)
