#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

cmake_minimum_required(VERSION 3.21)

add_library(tfm_fih_headers INTERFACE)
add_library(tfm_fih INTERFACE)

target_sources(tfm_fih
    INTERFACE
        src/fih.c
)

target_include_directories(tfm_fih_headers
    INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/inc>
)

target_link_libraries(tfm_fih
    INTERFACE
        tfm_fih_headers
        platform_common_interface
        cmsis
)

target_compile_options(tfm_fih_headers
    INTERFACE
        $<$<C_COMPILER_ID:GNU>:-Wno-unused-value>
)
