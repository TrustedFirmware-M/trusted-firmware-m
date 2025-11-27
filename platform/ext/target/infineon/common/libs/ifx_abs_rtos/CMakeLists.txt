#-------------------------------------------------------------------------------
# Copyright (c) 2025 Cypress Semiconductor Corporation (an Infineon company)
# or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

# Abstraction RTOS is needed in NS build for MTB SRF
if(NS_BUILD AND IFX_MTB_SRF)
    fetch_remote_library(
        LIB_NAME                ifx_abs_rtos
        LIB_SOURCE_PATH_VAR     IFX_ABSTRACTION_RTOS_LIB_PATH
        # By using ${IFX_LIB_BASE_DIR} as LIB_BASE_DIR repo will only be downloaded once
        # and then reused by subsequent builds. This speeds up the build.
        LIB_BASE_DIR            "${IFX_LIB_BASE_DIR}"
        LIB_PATCH_DIR           ${IFX_ABSTRACTION_RTOS_LIB_PATCH_DIR}
        LIB_FORCE_PATCH         ON
        FETCH_CONTENT_ARGS
            GIT_REPOSITORY      ${IFX_ABSTRACTION_RTOS_LIB_GIT_REMOTE}
            GIT_TAG             ${IFX_ABSTRACTION_RTOS_LIB_VERSION}
            GIT_SHALLOW         TRUE
            GIT_PROGRESS        TRUE
            GIT_SUBMODULES      ""
    )

    # Tests repo uses CMSIS RTOS (a.k.a. RTX), thus ifx_abstraction_rtos
    # is built with RTX support
    add_library(ifx_abstraction_rtos STATIC EXCLUDE_FROM_ALL)

    target_sources(ifx_abstraction_rtos
        PRIVATE
            ${IFX_ABSTRACTION_RTOS_LIB_PATH}/source/COMPONENT_RTX/cyabs_rtos_rtxv5.c
    )

    target_include_directories(ifx_abstraction_rtos
        PUBLIC
            ${IFX_ABSTRACTION_RTOS_LIB_PATH}/include
            ${IFX_ABSTRACTION_RTOS_LIB_PATH}/include/COMPONENT_RTX
    )

    target_link_libraries(ifx_abstraction_rtos
        PRIVATE
            ifx_core_lib
        PUBLIC
            RTX_OS
    )

    target_compile_definitions(ifx_abstraction_rtos
        PUBLIC
            COMPONENT_RTX
            CY_RTOS_AWARE
    )
endif()
