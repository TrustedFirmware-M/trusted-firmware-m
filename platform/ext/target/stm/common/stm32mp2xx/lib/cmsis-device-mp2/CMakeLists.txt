#-------------------------------------------------------------------------------
# Copyright (c) 2026, STMicroelectronics - All Rights Reserved
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------
project(cmsis_device_mp2 VERSION 1.0 LANGUAGES CXX)

if (TARGET cmsis_device_mp2_header)
    return()
endif()

set(CMSIS_DEVICE_MP2_PATH "${CMAKE_CURRENT_SOURCE_DIR}")

add_library(cmsis_device_mp2_header INTERFACE)

target_include_directories(cmsis_device_mp2_header
    INTERFACE
        $<BUILD_INTERFACE:${CMSIS_DEVICE_MP2_PATH}/Include>
)

add_library(cmsis_device_mp2::header ALIAS cmsis_device_mp2_header)

find_package(Git)
if(Git_FOUND)
    execute_process(
        COMMAND ${GIT_EXECUTABLE} describe --tags --always --match "v[0-9]*\.[0-9]*\.[0-9]*"
        WORKING_DIRECTORY ${CMSIS_DEVICE_MP2_PATH}
        OUTPUT_VARIABLE CMSIS_VERSION
        OUTPUT_STRIP_TRAILING_WHITESPACE
    )

    set(STM32MP2_CMSIS_VERSION ${CMSIS_VERSION} PARENT_SCOPE)
endif()

include(utils)
    dump_options("CMSIS version"
    "
        CMSIS_VERSION;
    "
    )
