#-------------------------------------------------------------------------------
# Copyright (c) 2025 Cypress Semiconductor Corporation (an Infineon company)
# or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

fetch_remote_library(
    LIB_NAME                ifx_dev_support
    LIB_SOURCE_PATH_VAR     IFX_DEV_SUPPORT_LIB_PATH
    # By using ${IFX_LIB_BASE_DIR} as LIB_BASE_DIR repo will only be downloaded once
    # and then reused by subsequent builds. This speeds up the build.
    LIB_BASE_DIR            "${IFX_LIB_BASE_DIR}"
    LIB_PATCH_DIR           ${IFX_DEV_SUPPORT_LIB_PATCH_DIR}
    LIB_FORCE_PATCH         ON
    FETCH_CONTENT_ARGS
        GIT_REPOSITORY      ${IFX_DEV_SUPPORT_LIB_GIT_REMOTE}
        GIT_TAG             ${IFX_DEV_SUPPORT_LIB_VERSION}
        GIT_SHALLOW         TRUE
        GIT_PROGRESS        TRUE
        GIT_SUBMODULES      ""
)

# Update path to libraries integrated into device support library
set(IFX_PDL_LIB_PATH  "${IFX_DEV_SUPPORT_LIB_PATH}/pdl"  CACHE PATH  "Path to Infineon PDL library (or DOWNLOAD to fetch automatically)")

# MTB HAL is needed in NS build for MTB SRF
if(NS_BUILD AND IFX_MTB_SRF)
    add_library(ifx_mtb_hal STATIC EXCLUDE_FROM_ALL)

    target_sources(ifx_mtb_hal
        PRIVATE
            ${IFX_DEV_SUPPORT_LIB_PATH}/hal/source/mtb_hal_lptimer_common.c
            ${IFX_DEV_SUPPORT_LIB_PATH}/hal/source/mtb_hal_lptimer.c
            ${IFX_DEV_SUPPORT_LIB_PATH}/hal/source/mtb_hal_syspm.c
            ${IFX_DEV_SUPPORT_LIB_PATH}/hal/source/mtb_hal_system.c
    )

    target_include_directories(ifx_mtb_hal
        PUBLIC
            ${IFX_DEV_SUPPORT_LIB_PATH}/hal/include
    )

    target_link_libraries(ifx_mtb_hal
        PRIVATE
            ifx_core_lib
            ifx_pdl_inc_ns
    )

    target_link_libraries(platform_ns
        PRIVATE
            ifx_mtb_hal
    )
endif()
