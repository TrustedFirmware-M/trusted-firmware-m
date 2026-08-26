#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

cmake_minimum_required(VERSION 3.21)

# Default configuration of CMSIS repository
set(CMSIS_PATH     "DOWNLOAD"       CACHE PATH      "Path to cmsis (or DOWNLOAD to fetch automatically")
set(CMSIS_TAG      "v6.2.0"         CACHE STRING    "The version of cmsis to use")
set(CMSIS_GIT_REMOTE "https://github.com/ARM-software/CMSIS_6.git" CACHE STRING "The URL to retrieve cmsis from.")
set(CMSIS_PATCH_DIR "${CMAKE_CURRENT_LIST_DIR}" CACHE PATH "Path to local folder which contains CMSIS patches")
set(CMSIS_SOURCE_SUBDIR "CMSIS" CACHE STRING "Path to CMSIS components relative to CMSIS_PATH")

fetch_remote_library(
    LIB_NAME                cmsis
    LIB_SOURCE_PATH_VAR     CMSIS_PATH
    LIB_PATCH_DIR           ${CMSIS_PATCH_DIR}
    LIB_BASE_DIR            "${CMAKE_BINARY_DIR}/lib/ext"
    FETCH_CONTENT_ARGS
        GIT_REPOSITORY      ${CMSIS_GIT_REMOTE}
        GIT_TAG             ${CMSIS_TAG}
        GIT_SHALLOW         TRUE
        GIT_PROGRESS        TRUE
)

set(CMSIS_SOURCE_ROOT "${CMSIS_PATH}/${CMSIS_SOURCE_SUBDIR}" CACHE PATH "Path to the CMSIS source root")

add_library(cmsis INTERFACE)

set_target_properties(cmsis PROPERTIES EXCLUDE_FROM_ALL TRUE)

target_include_directories(cmsis
    INTERFACE
    $<BUILD_INTERFACE:${CMSIS_SOURCE_ROOT}/Core/Include>
    $<BUILD_INTERFACE:${CMSIS_SOURCE_ROOT}/Core/Include/m-profile>
    $<BUILD_INTERFACE:${CMSIS_SOURCE_ROOT}/Driver/Include>
)
