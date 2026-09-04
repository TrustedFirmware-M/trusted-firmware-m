#-------------------------------------------------------------------------------
# (c) 2026, Infineon Technologies AG, or an affiliate of Infineon
# Technologies AG. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

set(IFX_PDL_PART_NUMBER           "PSC3M6GES3AHQ1" CACHE STRING "Part number, see PDL for more details")

set(IFX_BSP_LIB_PATH              "DOWNLOAD"       CACHE PATH   "Path to target BSP library (or DOWNLOAD to fetch automatically)")
set(IFX_BSP_LIB_GIT_REMOTE        "https://github.com/Infineon/TARGET_KIT_PSC3M6_EVAL.git" CACHE STRING "Target BSP library repo URL")
set(IFX_BSP_LIB_VERSION           "release-v1.0.0"    CACHE STRING "The version of target BSP library to use")
set(IFX_BSP_LIB_PATCH_DIR         "${IFX_PLATFORM_SOURCE_DIR}/libs/ifx_bsp/patch" CACHE STRING "Path to ifx-bsp patches")

set(IFX_DEVICE_DB_LIB_PATH        "DOWNLOAD"       CACHE PATH   "Path to target Device DB library (or DOWNLOAD to fetch automatically)")
set(IFX_DEVICE_DB_LIB_GIT_REMOTE  "https://github.com/Infineon/device-db.git" CACHE STRING "Target Device DB library repo URL")
set(IFX_DEVICE_DB_LIB_VERSION     "release-v4.39.0"   CACHE STRING "The version of target Device DB library to use")

set(IFX_BSP_DESIGN_FILE_PATH      "${CMAKE_CURRENT_LIST_DIR}/shared/design/${IFX_BSP_DESIGN_FILE_NAME}/design.modus" CACHE FILEPATH "Path to design.modus file to use for BSP code generation by Device Configurator.")

# Memory configuration specific config
include(${CMAKE_CURRENT_LIST_DIR}/shared/design/${IFX_BSP_DESIGN_FILE_NAME}/config.cmake OPTIONAL)
