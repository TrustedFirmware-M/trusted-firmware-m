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
add_library(ifx_tfm_sp_meta STATIC)

target_compile_options(ifx_tfm_sp_meta
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
        $<$<BOOL:${IFX_CM55_NS_PRESENT}>:IFX_CM55_NS_PRESENT=1>
)

target_include_directories(tfm_config
    INTERFACE
        $<BUILD_INTERFACE:${IFX_FAMILY_SOURCE_DIR}/config>
        $<BUILD_INTERFACE:${IFX_PLATFORM_SOURCE_DIR}>
)

############################### Platform Secure ###############################

add_subdirectory(spe)
add_subdirectory(${IFX_EPC})

################################ Code coverage #################################

# Code coverage flags must be added after all platform files have been added
# to the build

if(TEST_NS_IFX_CODE_COVERAGE)
    include(${IFX_COMMON_SOURCE_DIR}/cmake/code_coverage.cmake)

    set(IFX_COVERAGE_IGNORE_LIST "")

    # Exclude test (we measure coverage of the secure code, not the code that tests it)
    list(APPEND IFX_COVERAGE_IGNORE_LIST "platform/ext/target/infineon/pse84/tests")

    ifx_add_code_coverage(
        EXCLUDE ${IFX_COVERAGE_IGNORE_LIST}
        FILTER_FILE "${IFX_COMMON_SOURCE_DIR}/deploy/tfm_files_to_deploy.txt"
    )
endif()

################################################################################

include(./install.cmake)
