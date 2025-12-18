#-------------------------------------------------------------------------------
# Copyright (c) 2020-2023, Arm Limited. All rights reserved.
# Copyright 2021-2025 NXP
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

################################## Dependencies ################################
set(TFM_PLATFORM_NXP_HAL_FILE_PATH         "LOCAL"          CACHE STRING     "Path to the NXP SDK hal drivers")

############################ Platform ##########################################
set(PLATFORM_DEFAULT_ATTEST_HAL         ON              CACHE BOOL      "Use default attest hal implementation.")

############################ BL2 ########################################
set(BL2_S_IMAGE_START                   "0x8000"        CACHE STRING    "Base address of the secure image in configuration with BL2")
set(BL2_NS_IMAGE_START                  "0x30000"       CACHE STRING    "Base address of the non secure image in configuration with BL2")

# Platform-specific configurations
set(CONFIG_TFM_USE_TRUSTZONE            ON)
set(TFM_MULTI_CORE_TOPOLOGY             OFF)
set(CONFIG_TFM_INCLUDE_STDLIBC          ON               CACHE BOOL      "Include standard C libraries and startup code")
