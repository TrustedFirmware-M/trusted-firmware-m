#-------------------------------------------------------------------------------
# Copyright (c) 2024-2025 Cypress Semiconductor Corporation (an Infineon company)
# or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

#################################### IFX #######################################

# PDL sysclk and syspm version
set(IFX_PDL_CY_SYSCLK_VERSION               "v2")
set(IFX_PDL_CY_SYSPM_VERSION                "v4")

set(IFX_MULTICORE_CM55                      ON) # Use multicore HAL for CM55 non-secure core

################################### Platform ###################################

set(PLATFORM_HAS_FIRMWARE_UPDATE_SUPPORT    OFF)
set(PLATFORM_HAS_ISOLATION_L3_SUPPORT       ON)

################################# Dependencies #################################

set(IFX_DEV_SUPPORT_LIB_PATH        "DOWNLOAD"        CACHE PATH "Path to Infineon device support library (or DOWNLOAD to fetch automatically)")
set(IFX_DEV_SUPPORT_LIB_GIT_REMOTE  "https://github.com/Infineon/mtb-dsl-pse8xxgp.git" CACHE STRING "Infineon device support library repo URL")
set(IFX_DEV_SUPPORT_LIB_PATCH_DIR   "${IFX_FAMILY_SOURCE_DIR}/libs/ifx_dev_support/patch" CACHE STRING "Path to device support library patches")
set(IFX_DEV_SUPPORT_LIB_VERSION     "release-v1.1.0"  CACHE STRING "The version of Infineon device support library to use")

set(IFX_MTB_SRF_LIB_PATH            "DOWNLOAD"  CACHE PATH "Path to Infineon MTB SRF library (or DOWNLOAD to fetch automatically)")
set(IFX_MTB_SRF_LIB_GIT_REMOTE      "https://github.com/Infineon/mtb-srf.git" CACHE STRING "Infineon MTB SRF library repo URL")
set(IFX_MTB_SRF_LIB_PATCH_DIR       "${IFX_COMMON_SOURCE_DIR}/libs/ifx_mtb_srf/patch" CACHE STRING "Path to MTB SRF library patches")
set(IFX_MTB_SRF_LIB_VERSION         "release-v1.1.0" CACHE STRING "The version of Infineon MTB SRF library to use")
