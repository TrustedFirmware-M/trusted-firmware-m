#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------
cmake_minimum_required(VERSION 3.21)

add_library(tfm_fwu_mcuboot_util INTERFACE)

target_sources(tfm_fwu_mcuboot_util
    INTERFACE
        ${MCUBOOT_PATH}/boot/bootutil/src/bootutil_public.c
        ${MCUBOOT_PATH}/boot/bootutil/src/tlv.c
        ${CMAKE_SOURCE_DIR}/bl2/src/flash_map.c
        ${CMAKE_SOURCE_DIR}/bl2/ext/mcuboot/flash_map_extended.c
        ./tfm_mcuboot_fwu.c
        ./uefi_fmp.c
        $<$<BOOL:${DEFAULT_MCUBOOT_FLASH_MAP}>:${CMAKE_SOURCE_DIR}/bl2/src/default_flash_map.c>
)

target_include_directories(tfm_fwu_mcuboot_util
    INTERFACE
        ${CMAKE_BINARY_DIR}/bl2/ext/mcuboot
        ${CMAKE_SOURCE_DIR}/bl2/ext/mcuboot/include
        ${MCUBOOT_PATH}/boot/bootutil/include
        ${MCUBOOT_PATH}/boot/bootutil/src
        ${CMAKE_CURRENT_SOURCE_DIR}/../
        ${MBEDCRYPTO_PATH}/include
)

target_link_libraries(tfm_fwu_mcuboot_util
    INTERFACE
        platform_region_defs
)

target_link_libraries(tfm_psa_rot_partition_fwu
    PRIVATE
        tfm_fwu_mcuboot_util
)

configure_file(${CMAKE_SOURCE_DIR}/platform/ext/target/arm/corstone1000/bootloader/fwu_config.h.in
               ${CMAKE_BINARY_DIR}/platform/ext/target/arm/corstone1000/bootloader/fwu_config.h
               @ONLY)
set(FWU_DEVICE_CONFIG_FILE "${CMAKE_BINARY_DIR}/platform/ext/target/arm/corstone1000/bootloader/fwu_config.h")

target_compile_definitions(tfm_psa_rot_partition_fwu
    PRIVATE
        MCUBOOT_${MCUBOOT_UPGRADE_STRATEGY}
        $<$<BOOL:${MCUBOOT_DIRECT_XIP_REVERT}>:MCUBOOT_DIRECT_XIP_REVERT>
	FWU_DEVICE_CONFIG_FILE="${FWU_DEVICE_CONFIG_FILE}"
)
