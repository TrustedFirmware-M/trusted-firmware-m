#-------------------------------------------------------------------------------
# (c) 2026, Infineon Technologies AG, or an affiliate of Infineon
# Technologies AG. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

################################### Platform ###################################

set(PLATFORM_HAS_ISOLATION_L3_SUPPORT       ON)
set(PLATFORM_HAS_FIRMWARE_UPDATE_SUPPORT    OFF)

################################# Dependencies #################################

set(IFX_DEV_SUPPORT_LIB_PATH        "DOWNLOAD" CACHE PATH "Path to Infineon device support library (or DOWNLOAD to fetch automatically)")
set(IFX_DEV_SUPPORT_LIB_GIT_REMOTE  "https://github.com/Infineon/mtb-dsl-psc3m6.git" CACHE STRING "Infineon device support library repo URL")
set(IFX_DEV_SUPPORT_LIB_PATCH_DIR   "${IFX_PLATFORM_SOURCE_DIR}/libs/ifx_pdl/patch" CACHE STRING "Path to device support library patches")
set(IFX_DEV_SUPPORT_LIB_VERSION     "release-v1.0.0" CACHE STRING "The version of Infineon device support library to use")

set(IFX_MTB_SRF_LIB_PATH            "DOWNLOAD"  CACHE PATH "Path to Infineon MTB SRF library (or DOWNLOAD to fetch automatically)")
set(IFX_MTB_SRF_LIB_GIT_REMOTE      "https://github.com/Infineon/mtb-srf.git" CACHE STRING "Infineon MTB SRF library repo URL")
set(IFX_MTB_SRF_LIB_PATCH_DIR       "${IFX_COMMON_SOURCE_DIR}/libs/ifx_mtb_srf/patch" CACHE STRING "Path to MTB SRF library patches")
set(IFX_MTB_SRF_LIB_VERSION         "release-v1.2.1" CACHE STRING "The version of Infineon MTB SRF library to use")
