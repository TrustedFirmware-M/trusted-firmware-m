#-------------------------------------------------------------------------------
# Copyright (c) 2025 Cypress Semiconductor Corporation (an Infineon company)
# or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

# MTB IPC is needed in NS build for MTB SRF
if(NS_BUILD AND IFX_MTB_MAILBOX)
    fetch_remote_library(
        LIB_NAME                ifx_mtb_ipc
        LIB_SOURCE_PATH_VAR     IFX_MTB_IPC_LIB_PATH
        # By using ${IFX_LIB_BASE_DIR} as LIB_BASE_DIR repo will only be downloaded once
        # and then reused by subsequent builds. This speeds up the build.
        LIB_BASE_DIR            "${IFX_LIB_BASE_DIR}"
        LIB_PATCH_DIR           ${IFX_MTB_IPC_LIB_PATCH_DIR}
        LIB_FORCE_PATCH         ON
        FETCH_CONTENT_ARGS
            GIT_REPOSITORY      ${IFX_MTB_IPC_LIB_GIT_REMOTE}
            GIT_TAG             ${IFX_MTB_IPC_LIB_VERSION}
            GIT_SHALLOW         TRUE
            GIT_PROGRESS        TRUE
            GIT_SUBMODULES      ""
    )

    add_library(ifx_mtb_ipc STATIC EXCLUDE_FROM_ALL)

    target_sources(ifx_mtb_ipc
        PRIVATE
            ${IFX_MTB_IPC_LIB_PATH}/source/mtb_ipc.c
    )

    target_include_directories(ifx_mtb_ipc
        PUBLIC
            ${IFX_MTB_IPC_LIB_PATH}/include
    )

    target_compile_definitions(ifx_mtb_ipc
        PUBLIC
            COMPONENT_MW_MTB_IPC
    )

    target_link_libraries(ifx_mtb_ipc
        PRIVATE
            ifx_abstraction_rtos
            ifx_mtb_hal
            ifx_pdl_inc_ns
    )
endif()
