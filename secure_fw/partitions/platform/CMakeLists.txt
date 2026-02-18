#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

if (NOT TFM_PARTITION_PLATFORM)
    return()
endif()

cmake_minimum_required(VERSION 3.21)

add_library(tfm_psa_rot_partition_platform STATIC
    tfm_platform_sp.c
)

add_dependencies(tfm_psa_rot_partition_platform manifest_tool)

# The generated sources
target_sources(tfm_psa_rot_partition_platform
    PRIVATE
        ${CMAKE_BINARY_DIR}/generated/secure_fw/partitions/platform/auto_generated/intermedia_tfm_platform.c
)
target_sources(tfm_partitions
    INTERFACE
        ${CMAKE_BINARY_DIR}/generated/secure_fw/partitions/platform/auto_generated/load_info_tfm_platform.c
)

# Set include directory
target_include_directories(tfm_psa_rot_partition_platform
    PRIVATE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
        ${CMAKE_BINARY_DIR}/generated/secure_fw/partitions/platform
)
target_include_directories(tfm_partitions
    INTERFACE
        ${CMAKE_BINARY_DIR}/generated/secure_fw/partitions/platform
)

target_link_libraries(tfm_psa_rot_partition_platform
    PRIVATE
        platform_s
        tfm_config
        tfm_sprt
)

############################ Partition Defs ####################################

target_link_libraries(tfm_partitions
    INTERFACE
        tfm_psa_rot_partition_platform
)

target_compile_definitions(tfm_config
    INTERFACE
        TFM_PARTITION_PLATFORM
)
