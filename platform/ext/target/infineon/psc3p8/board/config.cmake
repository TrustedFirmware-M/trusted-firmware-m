#-------------------------------------------------------------------------------
# (c) 2025-2026, Infineon Technologies AG, or an affiliate of Infineon
# Technologies AG. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

set(IFX_PDL_PART_NUMBER           "PSC3M8GFS3PAHQ1" CACHE STRING "Part number, see PDL for more details")

set(IFX_BSP_LIB_PATH              "DOWNLOAD"        CACHE PATH   "Path to target BSP library (or DOWNLOAD to fetch automatically)")
set(IFX_BSP_LIB_GIT_REMOTE        "https://github.com/Infineon/TARGET_KIT_PSC3M8_EVK.git" CACHE STRING "Target BSP library repo URL")
set(IFX_BSP_LIB_VERSION           "release-v2.2.0"  CACHE STRING "The version of target BSP library to use")

set(IFX_DEVICE_DB_LIB_PATH        "DOWNLOAD"        CACHE PATH   "Path to target Device DB library (or DOWNLOAD to fetch automatically)")
set(IFX_DEVICE_DB_LIB_GIT_REMOTE  "https://github.com/Infineon/device-db.git" CACHE STRING "Target Device DB library repo URL")
set(IFX_DEVICE_DB_LIB_VERSION     "release-v4.41.0" CACHE STRING "The version of target Device DB library to use")

set(IFX_BSP_DESIGN_FILE_PATH      "${CMAKE_CURRENT_LIST_DIR}/shared/design/${IFX_BSP_DESIGN_FILE_NAME}/design.modus" CACHE FILEPATH "Path to design.modus file to use for BSP code generation by Device Configurator.")

# Building with -DIFX_GENERATE_BSP_SOURCES=OFF uses the pregenerated BSP
# sources provided with the design (unless IFX_BSP_GENERATED_FILES_OUTPUT_PATH
# is provided, e.g. by ModusToolbox), so ModusToolbox is not required
if(DEFINED IFX_GENERATE_BSP_SOURCES AND NOT IFX_GENERATE_BSP_SOURCES
   AND NOT DEFINED IFX_BSP_GENERATED_FILES_OUTPUT_PATH)
    set(IFX_BSP_GENERATED_FILES_OUTPUT_PATH "${CMAKE_CURRENT_LIST_DIR}/shared/design/${IFX_BSP_DESIGN_FILE_NAME}/GeneratedSource")
    if(NOT EXISTS ${IFX_BSP_GENERATED_FILES_OUTPUT_PATH})
        message(FATAL_ERROR "BSP design '${IFX_BSP_DESIGN_FILE_NAME}' has no pregenerated sources, IFX_GENERATE_BSP_SOURCES must be ON")
    endif()
endif()

# Memory configuration specific config
include(${CMAKE_CURRENT_LIST_DIR}/shared/design/${IFX_BSP_DESIGN_FILE_NAME}/config.cmake OPTIONAL)
