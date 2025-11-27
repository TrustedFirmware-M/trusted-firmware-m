#-------------------------------------------------------------------------------
# Copyright (c) 2023-2024 Cypress Semiconductor Corporation (an Infineon company)
# or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

fetch_remote_library(
    LIB_NAME                ifx_se_rt_services
    LIB_SOURCE_PATH_VAR     IFX_SE_RT_SERVICES_UTILS_PATH
    # By using ${IFX_LIB_BASE_DIR} as LIB_BASE_DIR repo will only be downloaded once
    # and then reused by subsequent builds. This speeds up the build.
    LIB_BASE_DIR            "${IFX_LIB_BASE_DIR}"
    LIB_PATCH_DIR           ${IFX_SE_RT_SERVICES_UTILS_PATCH_DIR}
    FETCH_CONTENT_ARGS
        GIT_REPOSITORY      ${IFX_SE_RT_SERVICES_UTILS_GIT_REMOTE}
        GIT_TAG             ${IFX_SE_RT_SERVICES_UTILS_VERSION}
        GIT_SHALLOW         TRUE
        GIT_PROGRESS        TRUE
        GIT_SUBMODULES      ""
)

#-------------------------------------------------------------------------------

add_subdirectory(spe)
