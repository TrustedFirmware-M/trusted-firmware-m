#-------------------------------------------------------------------------------
# Copyright (c) 2024-2025 Cypress Semiconductor Corporation (an Infineon company)
# or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

#################################### IFX #######################################

set(IFX_MTB_BUILD             OFF         CACHE BOOL "Enable build of artifacts used by ModusToolBox")

################################# Dependencies #################################

set(IFX_LIB_BASE_DIR          "${CMAKE_BINARY_DIR}/lib/ext" CACHE PATH "Path to folder where libraries are downloaded to speed up build process by re-using sources")

set(IFX_CMSIS_LIB_PATH        "DOWNLOAD"  CACHE PATH "Path to CMSIS library maintained by Infineon (or DOWNLOAD to fetch automatically)")
set(IFX_CMSIS_LIB_GIT_REMOTE  "https://github.com/Infineon/cmsis.git" CACHE STRING "CMSIS library maintained by Infineon repo URL")
set(IFX_CMSIS_LIB_VERSION     "release-v6.1.0" CACHE STRING "The version of Infineon CMSIS library to use")

set(IFX_CORE_LIB_PATH         "DOWNLOAD"  CACHE PATH "Path to Infineon Core library (or DOWNLOAD to fetch automatically)")
set(IFX_CORE_LIB_GIT_REMOTE   "https://github.com/Infineon/core-lib.git" CACHE STRING "Infineon Core library repo URL")
set(IFX_CORE_LIB_VERSION      "release-v1.6.0" CACHE STRING "The version of Infineon Core library to use")
