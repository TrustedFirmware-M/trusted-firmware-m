#-------------------------------------------------------------------------------
# Copyright (c) 2021-2022, Arm Limited. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

if (NOT TFM_PARTITION_FIRMWARE_UPDATE)
    return()
endif()

cmake_minimum_required(VERSION 3.21)

add_library(tfm_psa_rot_partition_fwu STATIC)

add_dependencies(tfm_psa_rot_partition_fwu manifest_tool)

target_include_directories(tfm_psa_rot_partition_fwu
    INTERFACE
        ${CMAKE_SOURCE_DIR}/secure_fw/include
    PRIVATE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
        ${CMAKE_BINARY_DIR}/generated/secure_fw/partitions/firmware_update
)
target_include_directories(tfm_partitions
    INTERFACE
        ${CMAKE_BINARY_DIR}/generated/secure_fw/partitions/firmware_update
)

target_sources(tfm_psa_rot_partition_fwu
    PRIVATE
        tfm_fwu_req_mngr.c
        ${CMAKE_BINARY_DIR}/generated/secure_fw/partitions/firmware_update/auto_generated/intermedia_tfm_firmware_update.c
)
target_sources(tfm_partitions
    INTERFACE
        ${CMAKE_BINARY_DIR}/generated/secure_fw/partitions/firmware_update/auto_generated/load_info_tfm_firmware_update.c
)

# The bootloader specific configuration.
if(TFM_FWU_BOOTLOADER_LIB STREQUAL "mcuboot")
    add_subdirectory(bootloader/${TFM_FWU_BOOTLOADER_LIB})
else()
    # Use platform specific bootloader configuration if present.
    if ((NOT TFM_FWU_BOOTLOADER_LIB) OR (NOT EXISTS ${TFM_FWU_BOOTLOADER_LIB}))
        message(FATAL_ERROR "TFM_FWU_BOOTLOADER_LIB invalid")
    endif()
    add_subdirectory(${TFM_FWU_BOOTLOADER_LIB} ${CMAKE_CURRENT_BINARY_DIR}/${TFM_FWU_BOOTLOADER_LIB})
endif()

target_link_libraries(tfm_psa_rot_partition_fwu
    PRIVATE
        platform_s
        tfm_config
        tfm_sprt
)


# Generate firmware update feature if FWU_DEVICE_CONFIG_FILE is not provided
if (NOT FWU_DEVICE_CONFIG_FILE)
    configure_file(${CMAKE_SOURCE_DIR}/interface/include/psa/fwu_config.h.in
                   ${CMAKE_BINARY_DIR}/generated/interface/include/psa/fwu_config.h
                   @ONLY)
    set(FWU_DEVICE_CONFIG_FILE "${CMAKE_BINARY_DIR}/generated/interface/include/psa/fwu_config.h")
endif()


target_compile_definitions(tfm_psa_rot_partition_fwu
    PRIVATE
        $<$<BOOL:${DEFAULT_MCUBOOT_FLASH_MAP}>:DEFAULT_MCUBOOT_FLASH_MAP>
        FWU_DEVICE_CONFIG_FILE="${FWU_DEVICE_CONFIG_FILE}"
        $<$<BOOL:${FWU_DEVICE_IMPL_INFO_DEF_FILE}>:FWU_DEVICE_IMPL_INFO_DEF_FILE="${FWU_DEVICE_IMPL_INFO_DEF_FILE}">
)

############################ Partition Defs ####################################

target_link_libraries(tfm_partitions
    INTERFACE
        tfm_psa_rot_partition_fwu
)

target_compile_definitions(tfm_config
    INTERFACE
    TFM_PARTITION_FIRMWARE_UPDATE
)

################ Display the configuration being applied #######################

include(utils)
dump_options("Firmware Update Partition config"
"
    TFM_FWU_BOOTLOADER_LIB;
    FWU_DEVICE_CONFIG_FILE
"
)
