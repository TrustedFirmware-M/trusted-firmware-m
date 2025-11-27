#-------------------------------------------------------------------------------
# Copyright (c) 2023-2025 Cypress Semiconductor Corporation (an Infineon company)
# or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

cmake_minimum_required(VERSION 3.27.7)

include(../cmake/remote_library)

include(${IFX_COMMON_SOURCE_DIR}/cmake/utils.cmake)

# Validate core configuration
tfm_invalid_config(NOT IFX_CM33_NS_PRESENT AND (IFX_CORE STREQUAL ${IFX_CM33}))
tfm_invalid_config(NOT IFX_CM55_NS_PRESENT AND (IFX_CORE STREQUAL ${IFX_CM55}))

if(IFX_NS_INTERFACE_TZ)
    # Disable NS Agent mailbox by removing compilation flags
    ifx_target_regex_replace_list_item(tfm_config INTERFACE_COMPILE_DEFINITIONS
                                       "TFM_PARTITION_NS_AGENT_MAILBOX" "")
else()
    # Disable NS Agent TZ by removing compilation flags
    ifx_target_regex_replace_list_item(tfm_config INTERFACE_COMPILE_DEFINITIONS
                                       "TFM_PARTITION_NS_AGENT_TZ" "")
    ifx_target_regex_replace_list_item(psa_interface INTERFACE_COMPILE_DEFINITIONS
                                       "\\\$<\\\$<BOOL:ON>:CONFIG_TFM_USE_TRUSTZONE>" "")
endif()

# Vendor's common build of non-secure image
add_subdirectory(${IFX_COMMON_SOURCE_DIR} ifx)

# Common libraries
add_subdirectory(${IFX_COMMON_SOURCE_DIR}/libs libs)

# Board
add_subdirectory(${IFX_COMMON_SOURCE_DIR}/board board)

############################# Platform Non-Secure #############################

target_include_directories(tfm_config
    INTERFACE
        include
)

target_include_directories(platform_ns
    PUBLIC
        ext/common
        include
        ${IFX_FAMILY_SOURCE_DIR}/shared
        ${IFX_FAMILY_SOURCE_DIR}/shared/device/config
        ${IFX_FAMILY_SOURCE_DIR}/shared/device/include
)

target_link_libraries(platform_ns
    PUBLIC
        ifx_cmsis_lib
)

