#-------------------------------------------------------------------------------
# Copyright (c) 2024, Arm Limited. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

cmake_minimum_required(VERSION 3.21)

add_library(tfm_vprintf_headers INTERFACE)
add_library(tfm_vprintf INTERFACE)

target_sources(tfm_vprintf
    INTERFACE
        src/tfm_vprintf.c
)

target_include_directories(tfm_vprintf_headers
    INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/inc>
)

target_link_libraries(tfm_vprintf
    INTERFACE
        tfm_vprintf_headers
)
