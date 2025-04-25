#-------------------------------------------------------------------------------
# Copyright (c) 2024, Arm Limited. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

cmake_minimum_required(VERSION 3.21)

# Default configuration of CMSIS repository
set(CMSIS_PATH     "DOWNLOAD"       CACHE PATH      "Path to cmsis (or DOWNLOAD to fetch automatically")
set(CMSIS_TAG      "v6.1.0"         CACHE STRING    "The version of cmsis to use")

fetch_remote_library(
    LIB_NAME                cmsis
    LIB_SOURCE_PATH_VAR     CMSIS_PATH
    LIB_PATCH_DIR           ${CMAKE_CURRENT_LIST_DIR}
    LIB_BASE_DIR            "${CMAKE_BINARY_DIR}/lib/ext"
    FETCH_CONTENT_ARGS
        GIT_REPOSITORY      https://github.com/ARM-software/CMSIS_6.git
        GIT_TAG             ${CMSIS_TAG}
        GIT_SHALLOW         TRUE
        GIT_PROGRESS        TRUE
)

add_library(cmsis INTERFACE)

set_target_properties(cmsis PROPERTIES EXCLUDE_FROM_ALL TRUE)

target_include_directories(cmsis
    INTERFACE
    $<BUILD_INTERFACE:${CMSIS_PATH}/CMSIS/Core/Include>
    $<BUILD_INTERFACE:${CMSIS_PATH}/CMSIS/Core/Include/m-profile>
    $<BUILD_INTERFACE:${CMSIS_PATH}/CMSIS/Driver/Include>
)
