#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

if (NOT TFM_PARTITION_POWER_MGMT)
    return()
endif()

cmake_minimum_required(VERSION 3.21)

add_library(tfm_psa_rot_partition_power_mgmt STATIC)

add_dependencies(tfm_psa_rot_partition_power_mgmt manifest_tool)

target_include_directories(tfm_psa_rot_partition_power_mgmt
    PRIVATE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    PRIVATE
        ${CMAKE_BINARY_DIR}/generated/secure_fw/partitions/power_mgmt
)

target_link_libraries(tfm_partitions
    INTERFACE
        tfm_psa_rot_partition_power_mgmt
)
target_include_directories(tfm_partitions
    INTERFACE
        ${CMAKE_BINARY_DIR}/generated/secure_fw/partitions/power_mgmt
)

target_sources(tfm_psa_rot_partition_power_mgmt
    PRIVATE
        tfm_power_mgmt_sp.c
)

target_link_libraries(tfm_psa_rot_partition_power_mgmt
    PRIVATE
        secure_fw
        tfm_config
        tfm_sprt
)

if((TFM_SYSTEM_PROCESSOR MATCHES "cortex-m55") OR (TFM_SYSTEM_PROCESSOR MATCHES "cortex-m85"))
    set(TFM_POWER_MGMT_ARCH_SUPPORTED TRUE)
else()
    set(TFM_POWER_MGMT_ARCH_SUPPORTED FALSE)
endif()

target_compile_definitions(tfm_psa_rot_partition_power_mgmt
    INTERFACE
        $<$<BOOL:${TFM_POWER_MGMT_ARCH_SUPPORTED}>:TFM_POWER_MGMT_ARCH_SUPPORTED>
)

target_sources(tfm_psa_rot_partition_power_mgmt
    PRIVATE
        ${CMAKE_BINARY_DIR}/generated/secure_fw/partitions/power_mgmt/auto_generated/intermedia_tfm_power_mgmt.c
)
target_sources(tfm_partitions
    INTERFACE
        ${CMAKE_BINARY_DIR}/generated/secure_fw/partitions/power_mgmt/auto_generated/load_info_tfm_power_mgmt.c
)

############################ Partition Defs ####################################

target_link_libraries(tfm_partitions
    INTERFACE
        tfm_psa_rot_partition_power_mgmt
)

target_compile_definitions(tfm_config
    INTERFACE
        TFM_PARTITION_POWER_MGMT
)
