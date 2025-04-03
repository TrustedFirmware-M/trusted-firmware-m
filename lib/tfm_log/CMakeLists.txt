#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

cmake_minimum_required(VERSION 3.21)

add_library(tfm_log_headers INTERFACE)
add_library(tfm_log INTERFACE)

target_sources(tfm_log
    INTERFACE
        src/tfm_log.c
)

target_include_directories(tfm_log_headers
    INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/inc>
)

target_link_libraries(tfm_log_headers
    INTERFACE
        tfm_vprintf_headers
)

target_link_libraries(tfm_log
    INTERFACE
        tfm_log_headers
)
