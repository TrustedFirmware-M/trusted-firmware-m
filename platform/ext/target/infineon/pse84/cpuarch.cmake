#-------------------------------------------------------------------------------
# Copyright (c) 2023-2025 Cypress Semiconductor Corporation (an Infineon company)
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

# secure image
add_compile_definitions(DOMAIN_S=1)
add_compile_definitions(COMPONENT_SECURE_DEVICE)

set(S_BUILD ON)

set(IFX_CORE "cm33")

include(${IFX_FAMILY_SOURCE_DIR}/shared/cpuarch.cmake OPTIONAL)
