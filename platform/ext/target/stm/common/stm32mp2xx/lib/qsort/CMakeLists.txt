#-------------------------------------------------------------------------------
# Copyright (c) 2026, STMicroelectronics - All Rights Reserved
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------
cmake_minimum_required(VERSION 3.21)

add_library(lib_qsort_headers INTERFACE)
add_library(lib_qsort STATIC)

target_sources(lib_qsort
    PRIVATE
        src/qsort.c
        src/qsort_helpers.c
)

target_include_directories(lib_qsort_headers
    INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

target_link_libraries(lib_qsort
    PUBLIC
        lib_qsort_headers
)
