#-------------------------------------------------------------------------------
# Copyright (c) 2023-2025 Cypress Semiconductor Corporation (an Infineon company)
# or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

cmake_minimum_required(VERSION 3.27.7)

# Set CMP0118: The GENERATED source file property is now visible in all
# directories for all targets created in this file
cmake_policy(SET CMP0118 NEW)

# Library with shared read-only data, only SPM can write it
set(IFX_SHARED_RO_DATA_TARGET "ifx_tfm_sp_meta")
add_library(${IFX_SHARED_RO_DATA_TARGET} STATIC)

target_compile_options(${IFX_SHARED_RO_DATA_TARGET}
    PRIVATE
        ${COMPILER_CMSE_FLAG}
)

add_subdirectory(${IFX_COMMON_SOURCE_DIR}/libs libs)

add_subdirectory(${IFX_COMMON_SOURCE_DIR}/board board)

############################# Platform region defs #############################

target_include_directories(platform_region_defs
    INTERFACE
        shared/partition
)

############################## TF-M configuration ##############################

target_compile_definitions(tfm_config
    INTERFACE
        $<$<BOOL:${IFX_CM33_NS_PRESENT}>:IFX_CM33_NS_PRESENT=1>
        $<$<BOOL:${IFX_CM55_NS_PRESENT}>:IFX_CM55_NS_PRESENT=0>
)

target_include_directories(tfm_config
    INTERFACE
        $<BUILD_INTERFACE:${IFX_FAMILY_SOURCE_DIR}/config>
        $<BUILD_INTERFACE:${IFX_PLATFORM_SOURCE_DIR}>
)

############################### Platform Secure ###############################

add_subdirectory(spe)
add_subdirectory(${IFX_EPC})

################################################################################

include(./install.cmake)
