#-------------------------------------------------------------------------------
# Copyright (c) 2023-2024 Cypress Semiconductor Corporation (an Infineon company)
# or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

fetch_remote_library(
    LIB_NAME                ifx_core_lib
    LIB_SOURCE_PATH_VAR     IFX_CORE_LIB_PATH
    # By using ${IFX_LIB_BASE_DIR} as LIB_BASE_DIR repo will only be downloaded once
    # and then reused by subsequent builds. This speeds up the build.
    LIB_BASE_DIR            "${IFX_LIB_BASE_DIR}"
    FETCH_CONTENT_ARGS
        GIT_REPOSITORY      ${IFX_CORE_LIB_GIT_REMOTE}
        GIT_TAG             ${IFX_CORE_LIB_VERSION}
        GIT_SHALLOW         TRUE
        GIT_PROGRESS        TRUE
        GIT_SUBMODULES      ""
)

#-------------------------------------------------------------------------------

project("Infineon Core Library" LANGUAGES C ASM)

cmake_policy(SET CMP0076 NEW)
cmake_policy(SET CMP0079 NEW)

add_library(ifx_core_lib INTERFACE)

target_include_directories(ifx_core_lib
    INTERFACE
        ${IFX_CORE_LIB_PATH}/include
)
