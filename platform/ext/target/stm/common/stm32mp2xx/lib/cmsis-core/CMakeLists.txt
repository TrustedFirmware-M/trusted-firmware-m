#-------------------------------------------------------------------------------
# Copyright (c) 2026, STMicroelectronics - All Rights Reserved
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------
project(cmsis_core VERSION 1.0 LANGUAGES CXX)

if (TARGET cmsis_core_header)
    return()
endif()

set(CMSIS_CORE_PATH "${CMAKE_CURRENT_SOURCE_DIR}")

add_library(cmsis_core_header INTERFACE)

target_include_directories(cmsis_core_header
    INTERFACE
        $<BUILD_INTERFACE:${CMSIS_CORE_PATH}/Include>
)

add_library(cmsis_core::header ALIAS cmsis_core_header)
