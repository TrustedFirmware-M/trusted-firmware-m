#-------------------------------------------------------------------------------
# Copyright (c) 2026, STMicroelectronics - All Rights Reserved
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------
project(stm32mp2xx_hal_driver VERSION 1.0 LANGUAGES CXX)

if (TARGET stm32mp2xx_hal_driver_header)
    return()
endif()

set(STM32MP2XX_HAL_DRIVER_PATH "${CMAKE_CURRENT_SOURCE_DIR}")

add_library(stm32mp2xx_hal_driver_header INTERFACE)

target_include_directories(stm32mp2xx_hal_driver_header
    INTERFACE
        $<BUILD_INTERFACE:${STM32MP2XX_HAL_DRIVER_PATH}/Inc>
)

add_library(stm32mp2xx_hal_driver::header ALIAS stm32mp2xx_hal_driver_header)

find_package(Git)
if(Git_FOUND)
    execute_process(
        COMMAND ${GIT_EXECUTABLE} describe --tags --always --match "v[0-9]*\.[0-9]*\.[0-9]*"
        WORKING_DIRECTORY ${STM32MP2XX_HAL_DRIVER_PATH}
        OUTPUT_VARIABLE HAL_VERSION
        OUTPUT_STRIP_TRAILING_WHITESPACE
    )

    set(STM32MP2_HAL_DRIVERS_VERSION ${HAL_VERSION} PARENT_SCOPE)
endif()

include(utils)

dump_options("HAL drivers version"
    "
        HAL_VERSION;
    "
)
