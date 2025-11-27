#-------------------------------------------------------------------------------
# Copyright (c) 2024 Cypress Semiconductor Corporation (an Infineon company)
# or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

if(NS_BUILD)
    # Fetch CMSIS library
    fetch_remote_library(
        LIB_NAME                ifx_cmsis_lib
        LIB_SOURCE_PATH_VAR     IFX_CMSIS_LIB_PATH
        # By using ${IFX_LIB_BASE_DIR} as LIB_BASE_DIR repo will only be downloaded once
        # and then reused by subsequent builds. This speeds up the build.
        LIB_BASE_DIR            "${IFX_LIB_BASE_DIR}"
        FETCH_CONTENT_ARGS
            GIT_REPOSITORY      ${IFX_CMSIS_LIB_GIT_REMOTE}
            GIT_TAG             ${IFX_CMSIS_LIB_VERSION}
            GIT_SHALLOW         TRUE
            GIT_PROGRESS        TRUE
            GIT_SUBMODULES      ""
    )

    add_library(ifx_cmsis_lib INTERFACE)

    target_include_directories(ifx_cmsis_lib
        INTERFACE
            ${IFX_CMSIS_LIB_PATH}/Core/Include
    )

    target_link_libraries(tfm_api_ns
        INTERFACE
            ifx_cmsis_lib
    )
endif()
