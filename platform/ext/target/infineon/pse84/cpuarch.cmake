#-------------------------------------------------------------------------------
# Copyright (c) 2023-2026 Cypress Semiconductor Corporation (an Infineon company)
# or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

# Validate EPC level
tfm_invalid_config(NOT IFX_EPC STREQUAL "epc2" AND NOT IFX_EPC STREQUAL "epc4")

# This variable points to the root folder of the PSE84 EPC2/EPC4 platform
set(IFX_PLATFORM_SOURCE_DIR ${CMAKE_CURRENT_LIST_DIR}/${IFX_EPC})

# This variable points to the root folder of the PSE84 family
set(IFX_FAMILY_SOURCE_DIR ${CMAKE_CURRENT_LIST_DIR})
set(IFX_COMMON_SOURCE_DIR ${CMAKE_CURRENT_LIST_DIR}/../common)

include(${IFX_COMMON_SOURCE_DIR}/shared/core_defs.cmake)

set(IFX_CORE ${IFX_CM33})

include(${IFX_COMMON_SOURCE_DIR}/spe/cpuarch.cmake)
