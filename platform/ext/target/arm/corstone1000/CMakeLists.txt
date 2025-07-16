#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
# Copyright (c) 2022 Cypress Semiconductor Corporation (an Infineon company)
# or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

cmake_policy(SET CMP0076 NEW)
set(CMAKE_CURRENT_SOURCE_DIR ${CMAKE_CURRENT_LIST_DIR})

#========================= Platform region defs ===============================#

target_include_directories(platform_region_defs
    INTERFACE
        partition
        cc312
)

target_compile_definitions(platform_region_defs
    INTERFACE
        $<$<BOOL:${TFM_S_REG_TEST}>:TFM_S_REG_TEST>
        $<$<BOOL:${PLATFORM_PSA_ADAC_SECURE_DEBUG}>:PLATFORM_PSA_ADAC_SECURE_DEBUG>
)

# The Armv6-M MPU requires that the MPU regions be aligned to the region sizes.
# The minimal region size is 0x100 bytes.
#
# The alignments have to be a power of two and ideally bigger than the section size (which
# can be checked in the map file).
# In some cases the alignment value is smaller than the actual section
# size to save memory. In that case, multiple MPU region has to be configured to cover it.
#
# To save memory, the attributes are set to XN_EXEC_OK and AP_RO_PRIV_UNPRIV for
# the SRAM so the PT_UNPRIV_CODE, PT_APP_ROT_CODE and PT_PSA_ROT_CODE don't have to
# be aligned. The higher-priority regions will overwrite these attributes if needed.
# The RAM is also located in the SRAM so it has to be configured to overwrite these default
# attributes.
target_compile_definitions(platform_region_defs
    INTERFACE
        TFM_LINKER_PT_APP_ROT_DATA_ALIGNMENT=0x2000

        # The RAM MPU Region block sizes are calculated manually. The RAM has to be covered
        # with the MPU regions. These regions also have to be the power of 2 and
        # the start addresses have to be aligned to these sizes. The sizes can be calculated
        # from the S_DATA_START and S_DATA_SIZE defines the following way:
        # S_DATA_SIZE = RAM_MPU_REGION_BLOCK_1_SIZE + RAM_MPU_REGION_BLOCK_2_SIZE
        # And the following constraints have to be taken:
        # S_DATA_START % RAM_MPU_REGION_BLOCK_1_SIZE = 0
        # (S_DATA_START + RAM_MPU_REGION_BLOCK_1_SIZE) % RAM_MPU_REGION_BLOCK_2_SIZE = 0
        RAM_MPU_REGION_BLOCK_1_SIZE=0x10000
        RAM_MPU_REGION_BLOCK_2_SIZE=0x20000
)
#========================= Platform common defs ===============================#

# Specify the location of platform specific build dependencies.
target_sources(tfm_s
    PRIVATE
    $<$<C_COMPILER_ID:GNU>:${CMAKE_CURRENT_SOURCE_DIR}/Device/Source/startup_corstone1000.c>
)
target_add_scatter_file(tfm_s
    $<$<C_COMPILER_ID:GNU>:${CMAKE_BINARY_DIR}/generated/platform/ext/common/gcc/tfm_isolation_s.ld>
)

target_sources(bl2
    PRIVATE
        $<$<C_COMPILER_ID:GNU>:${CMAKE_CURRENT_SOURCE_DIR}/Device/Source/startup_corstone1000.c>
)
target_add_scatter_file(bl2
        $<$<C_COMPILER_ID:GNU>:${PLATFORM_DIR}/ext/common/gcc/tfm_common_bl2.ld>
)

target_sources(bl1_1
PRIVATE
    $<$<C_COMPILER_ID:GNU>:${CMAKE_CURRENT_SOURCE_DIR}/Device/Source/startup_corstone1000.c>
)

target_add_scatter_file(bl1_1
    $<$<C_COMPILER_ID:GNU>:${CMAKE_CURRENT_SOURCE_DIR}/Device/Source/gcc/corstone1000_bl1_1.ld>
)

target_sources(bl1_2
PRIVATE
    $<$<C_COMPILER_ID:GNU>:${CMAKE_CURRENT_SOURCE_DIR}/Device/Source/startup_corstone1000.c>
)
target_add_scatter_file(bl1_2
    $<$<C_COMPILER_ID:GNU>:${CMAKE_CURRENT_SOURCE_DIR}/Device/Source/gcc/corstone1000_bl1_2.ld>
)

#========================= Platform Secure ====================================#

add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/rse_comms rse_comms)

# Set which PLATFORM depedency must be used by the CC3XX driver
set(CC3XX_PLATFORM_INTERFACE platform_bl1_1_interface)
add_subdirectory(${PLATFORM_DIR}/ext/target/arm/drivers/cc3xx cc3xx)

target_include_directories(platform_s
    PUBLIC
        .
        CMSIS_Driver
        CMSIS_Driver/Config
        Device/Config
        Device/Include
        Native_Driver
        partition
        services/include
        ${PLATFORM_DIR}/ext/target/arm/drivers/flash/common
        ${PLATFORM_DIR}/ext/target/arm/drivers/flash/cfi
        ${PLATFORM_DIR}/ext/target/arm/drivers/flash/strata
        ${PLATFORM_DIR}/ext/target/arm/drivers/qspi/xilinx_pg153_axi
        ${PLATFORM_DIR}/ext/target/arm/drivers/flash/n25q256a
        ${PLATFORM_DIR}/ext/target/arm/drivers/flash/sst26vf064b
        ${PLATFORM_DIR}/ext/target/arm/drivers/usart/pl011
    INTERFACE
        cc312
        bootloader
        soft_crc
        io
        partition
)

target_sources(platform_s
    INTERFACE
        $<$<STREQUAL:"${TFM_FIH_PROFILE}","HIGH">:${PLATFORM_DIR}/ext/common/template/tfm_fih_platform.c>
    PRIVATE
        CMSIS_Driver/Driver_Flash.c
        CMSIS_Driver/Driver_USART.c
        Device/Source/device_definition.c
        Device/Source/system_core_init.c
        ${PLATFORM_DIR}/ext/target/arm/drivers/usart/pl011/uart_pl011_drv.c
        Native_Driver/mhu_v2_x.c
        Native_Driver/mhu_wrapper_v2_x.c
        Native_Driver/watchdog.c
        Native_Driver/arm_watchdog_drv.c
        $<$<BOOL:TFM_PARTITION_PLATFORM>:${CMAKE_CURRENT_SOURCE_DIR}/services/src/tfm_platform_system.c>
        bootloader/mcuboot/tfm_mcuboot_fwu.c
        bootloader/mcuboot/uefi_fmp.c
        soft_crc/soft_crc.c
        io/io_block.c
        io/io_flash.c
        io/io_storage.c
        partition/partition.c
        partition/gpt.c
        $<$<NOT:$<BOOL:${PLATFORM_DEFAULT_OTP}>>:${PLATFORM_DIR}/ext/accelerator/cc312/otp_cc312.c>
        rse_comms_permissions_hal.c
        mem_check_v6m_v7m_hal.c
        ${PLATFORM_DIR}/ext/common/mem_check_v6m_v7m.c
	 platform.c
)

if (PLATFORM_IS_FVP)
target_sources(platform_s
    PRIVATE
        ${PLATFORM_DIR}/ext/target/arm/drivers/flash/strata/spi_strataflashj3_flash_lib.c
        ${PLATFORM_DIR}/ext/target/arm/drivers/flash/cfi/cfi_drv.c
)
else()
target_sources(platform_s
    PRIVATE
        ${PLATFORM_DIR}/ext/target/arm/drivers/qspi/xilinx_pg153_axi/xilinx_pg153_axi_qspi_controller_drv.c
        ${PLATFORM_DIR}/ext/target/arm/drivers/flash/n25q256a/spi_n25q256a_flash_lib.c
        ${PLATFORM_DIR}/ext/target/arm/drivers/flash/sst26vf064b/spi_sst26vf064b_flash_lib.c
)
endif()

target_compile_definitions(platform_s
    PUBLIC
        $<$<BOOL:${EXTERNAL_SYSTEM_SUPPORT}>:EXTERNAL_SYSTEM_SUPPORT>
        $<$<BOOL:${PLATFORM_IS_FVP}>:PLATFORM_IS_FVP>
    PRIVATE
        $<$<BOOL:${TFM_S_REG_TEST}>:TFM_S_REG_TEST>
        $<$<BOOL:${ENABLE_FWU_AGENT_DEBUG_LOGS}>:ENABLE_FWU_AGENT_DEBUG_LOGS>
)

if (TFM_PARTITION_CRYPTO)
    target_include_directories(platform_crypto_keys
        PUBLIC
            .
    )
endif()

#========================= Platform BL1 =======================================#

target_sources(platform_bl1_1
    PRIVATE
        ./CMSIS_Driver/Driver_Flash.c
        ./CMSIS_Driver/Driver_USART.c
        ./Device/Source/device_definition.c
        ./Device/Source/system_core_init.c
        ./Native_Driver/arm_watchdog_drv.c
        ./Native_Driver/firewall.c
        ${PLATFORM_DIR}/ext/target/arm/drivers/usart/pl011/uart_pl011_drv.c
        $<$<BOOL:${PLATFORM_IS_FVP}>:${PLATFORM_DIR}/ext/target/arm/drivers/flash/cfi/cfi_drv.c>
        $<$<BOOL:${PLATFORM_IS_FVP}>:${PLATFORM_DIR}/ext/target/arm/drivers/flash/strata/spi_strataflashj3_flash_lib.c>
        $<$<NOT:$<BOOL:${PLATFORM_IS_FVP}>>:${PLATFORM_DIR}/ext/target/arm/drivers/qspi/xilinx_pg153_axi/xilinx_pg153_axi_qspi_controller_drv.c>
        $<$<NOT:$<BOOL:${PLATFORM_IS_FVP}>>:${PLATFORM_DIR}/ext/target/arm/drivers/flash/n25q256a/spi_n25q256a_flash_lib.c>
        $<$<NOT:$<BOOL:${PLATFORM_IS_FVP}>>:${PLATFORM_DIR}/ext/target/arm/drivers/flash/sst26vf064b/spi_sst26vf064b_flash_lib.c>
        ./Native_Driver/watchdog.c
        ./bl1/boot_hal_bl1_1.c
        ./bl1/provisioning.c
        ./bootloader/mcuboot/tfm_mcuboot_fwu.c
        ./bootloader/mcuboot/uefi_fmp.c
        ./soft_crc/soft_crc.c
        $<$<NOT:$<BOOL:${PLATFORM_DEFAULT_OTP}>>:${PLATFORM_DIR}/ext/accelerator/cc312/otp_cc312.c>
        $<$<NOT:$<BOOL:${TFM_BL1_SOFTWARE_CRYPTO}>>:${CMAKE_CURRENT_SOURCE_DIR}/bl1/cc312_rom_crypto.c>
        $<$<NOT:$<BOOL:${TFM_BL1_SOFTWARE_CRYPTO}>>:${CMAKE_CURRENT_SOURCE_DIR}/bl1/cc312_rom_random.c>
)

target_compile_definitions(platform_bl1_1
    PUBLIC
        $<$<BOOL:${PLATFORM_IS_FVP}>:PLATFORM_IS_FVP>
        $<$<BOOL:${PLATFORM_DEFAULT_OTP_WRITEABLE}>:OTP_WRITEABLE>
        $<$<BOOL:${CRYPTO_HW_ACCELERATOR}>:CRYPTO_HW_ACCELERATOR>
        $<$<BOOL:${CRYPTO_HW_ACCELERATOR_OTP_PROVISIONING}>:CRYPTO_HW_ACCELERATOR_OTP_PROVISIONING>
        MBEDTLS_CONFIG_FILE="${CMAKE_SOURCE_DIR}/lib/ext/mbedcrypto/mbedcrypto_config/tfm_mbedcrypto_config_default.h"
        MBEDTLS_PSA_CRYPTO_CONFIG_FILE="${CMAKE_SOURCE_DIR}/lib/ext/mbedcrypto/mbedcrypto_config/crypto_config_default.h"

        # This definition is only added to the bl1_main target. There are
        # files that are shared between the BL1 and TFM_S targets. This flag
        # can be used if the BL1 target needs different implementation than
        # the TFM_S target.
        BL1_BUILD
)

target_include_directories(platform_bl1_1_interface
    INTERFACE
        .
        ./Device/Include
        ./Device/Config
        ./Native_Driver
        ./CMSIS_Driver/Config
        ./bootloader
        ./soft_crc
        ${PLATFORM_DIR}/ext/target/arm/drivers/flash/cfi
        ${PLATFORM_DIR}/ext/target/arm/drivers/flash/common
        ${PLATFORM_DIR}/ext/target/arm/drivers/flash/strata
        ${PLATFORM_DIR}/ext/target/arm/drivers/qspi/xilinx_pg153_axi/
        ${PLATFORM_DIR}/ext/target/arm/drivers/flash/n25q256a/
        ${PLATFORM_DIR}/ext/target/arm/drivers/flash/sst26vf064b/
        ${CMAKE_SOURCE_DIR}/bl1/bl1_1/shared_lib/interface/
        ${PLATFORM_DIR}/ext/target/arm/drivers/usart/pl011
        $<$<BOOL:${CRYPTO_HW_ACCELERATOR}>:${CMAKE_SOURCE_DIR}/platform/ext/accelerator/interface>
        ${PLATFORM_DIR}/ext/accelerator/cc312/
	${CMAKE_SOURCE_DIR}/lib/fih/inc/
)

target_link_libraries(platform_bl1_1
    PRIVATE
        $<$<NOT:$<BOOL:${TFM_BL1_SOFTWARE_CRYPTO}>>:cc3xx>
)

target_include_directories(platform_bl1_1
    PRIVATE
    ${CMAKE_SOURCE_DIR}/interface/include # for psa/error.h
)

target_sources(platform_bl1_2
    PRIVATE
        ./bl1/boot_hal_bl1_2.c
)

target_compile_definitions(platform_bl1_2
    PUBLIC
        $<$<BOOL:${PLATFORM_IS_FVP}>:PLATFORM_IS_FVP>
        $<$<BOOL:${PLATFORM_DEFAULT_OTP_WRITEABLE}>:OTP_WRITEABLE>
        $<$<BOOL:${CRYPTO_HW_ACCELERATOR}>:CRYPTO_HW_ACCELERATOR>
        $<$<BOOL:${CRYPTO_HW_ACCELERATOR_OTP_PROVISIONING}>:CRYPTO_HW_ACCELERATOR_OTP_PROVISIONING>
        MBEDTLS_CONFIG_FILE="${CMAKE_SOURCE_DIR}/lib/ext/mbedcrypto/mbedcrypto_config/tfm_mbedcrypto_config_default.h"
        MBEDTLS_PSA_CRYPTO_CONFIG_FILE="${CMAKE_SOURCE_DIR}/lib/ext/mbedcrypto/mbedcrypto_config/crypto_config_default.h"
)

target_include_directories(platform_bl1_2
    PRIVATE
        $<$<BOOL:${CRYPTO_HW_ACCELERATOR}>:${PLATFORM_DIR}/ext/target/arm/drivers/cc3xx/low_level_driver/include>
        $<$<BOOL:${CRYPTO_HW_ACCELERATOR}>:${PLATFORM_DIR}/ext/target/arm/drivers/cc3xx/common>
    INTERFACE
        .
        ./Device/Include
        ./Device/Config
        ./Native_Driver
        ./CMSIS_Driver/Config
        ./bootloader
        ./soft_crc
        ${PLATFORM_DIR}/ext/target/arm/drivers/flash/common
        ${PLATFORM_DIR}/ext/target/arm/drivers/flash/cfi
        ${PLATFORM_DIR}/ext/target/arm/drivers/flash/strata
        ${PLATFORM_DIR}/ext/target/arm/drivers/qspi/xilinx_pg153_axi/
        ${PLATFORM_DIR}/ext/target/arm/drivers/flash/n25q256a/
        ${PLATFORM_DIR}/ext/target/arm/drivers/flash/sst26vf064b/
        ${PLATFORM_DIR}/ext/accelerator/cc312/
	${CMAKE_SOURCE_DIR}/interface/include # for psa/error.h
)

#========================= Platform BL2 =======================================#

set(BL2_SOURCE ${CMAKE_SOURCE_DIR}/bl2)

target_sources(platform_bl2
    PRIVATE
        CMSIS_Driver/Driver_Flash.c
        CMSIS_Driver/Driver_USART.c
        Device/Source/device_definition.c
        Device/Source/system_core_init.c
        ${PLATFORM_DIR}/ext/target/arm/drivers/usart/pl011/uart_pl011_drv.c
        Native_Driver/watchdog.c
        Native_Driver/arm_watchdog_drv.c
        fip_parser/fip_parser.c
        bootloader/mcuboot/tfm_mcuboot_fwu.c
        bl2/security_cnt_bl2.c
        $<$<NOT:$<BOOL:${PLATFORM_DEFAULT_OTP}>>:${PLATFORM_DIR}/ext/accelerator/cc312/otp_cc312.c>
        io/io_block.c
        io/io_flash.c
        io/io_storage.c
        soft_crc/soft_crc.c
        partition/partition.c
        partition/gpt.c
        platform.c
)

if (PLATFORM_IS_FVP)
target_sources(platform_bl2
    PRIVATE
        ${PLATFORM_DIR}/ext/target/arm/drivers/flash/strata/spi_strataflashj3_flash_lib.c
        ${PLATFORM_DIR}/ext/target/arm/drivers/flash/cfi/cfi_drv.c
)
else()
target_sources(platform_bl2
    PRIVATE
        ${PLATFORM_DIR}/ext/target/arm/drivers/qspi/xilinx_pg153_axi/xilinx_pg153_axi_qspi_controller_drv.c
        ${PLATFORM_DIR}/ext/target/arm/drivers/flash/n25q256a/spi_n25q256a_flash_lib.c
        ${PLATFORM_DIR}/ext/target/arm/drivers/flash/sst26vf064b/spi_sst26vf064b_flash_lib.c
)
endif()

target_compile_definitions(platform_bl2
    PRIVATE
        $<$<BOOL:${PLATFORM_IS_FVP}>:PLATFORM_IS_FVP>
        $<$<BOOL:${TFM_S_REG_TEST}>:TFM_S_REG_TEST>
        $<$<BOOL:${ENABLE_FWU_AGENT_DEBUG_LOGS}>:ENABLE_FWU_AGENT_DEBUG_LOGS>
        PLAT_LOG_LEVEL=${PLAT_LOG_LEVEL}
)

# boot_hal_bl2.c is compiled as part of 'bl2' target and not inside
# 'platform_bl2' where it suppose to be. This is due to
# platform_init/quit* apis symbol collision in bl1.
target_sources(bl2
    PRIVATE
        bl2/flash_map_bl2.c
        bl2/boot_hal_bl2.c
)

target_link_libraries(bl2
    PRIVATE
        $<$<AND:$<BOOL:${PLATFORM_PSA_ADAC_SECURE_DEBUG}>,$<NOT:$<BOOL:${PSA_ADAC_AS_TFM_RUNTIME_SERVICE}>>>:trusted-firmware-m-psa-adac>
)

target_compile_definitions(bl2
    PRIVATE
        $<$<BOOL:${CRYPTO_HW_ACCELERATOR}>:CRYPTO_HW_ACCELERATOR>
        $<$<BOOL:${CRYPTO_HW_ACCELERATOR_OTP_PROVISIONING}>:CRYPTO_HW_ACCELERATOR_OTP_PROVISIONING>
        $<$<BOOL:${PLATFORM_PSA_ADAC_SECURE_DEBUG}>:PLATFORM_PSA_ADAC_SECURE_DEBUG>
)

target_include_directories(bl2
    PRIVATE
       ${CMAKE_SOURCE_DIR}/interface/include # for psa/error.h
)

target_compile_definitions(bootutil
    PRIVATE
        MULTIPLE_EXECUTABLE_RAM_REGIONS
)

target_include_directories(platform_bl2
    PUBLIC
        partition
        Device/Include
        fip_parser
        Native_Driver
        bootloader
        soft_crc
        io
        ${PLATFORM_DIR}/ext/target/arm/drivers/flash/common
        ${PLATFORM_DIR}/ext/target/arm/drivers/flash/cfi
        ${PLATFORM_DIR}/ext/target/arm/drivers/flash/strata
        ${PLATFORM_DIR}/ext/target/arm/drivers/qspi/xilinx_pg153_axi
        ${PLATFORM_DIR}/ext/target/arm/drivers/flash/n25q256a
        ${PLATFORM_DIR}/ext/target/arm/drivers/flash/sst26vf064b
        ${PLATFORM_DIR}/ext/target/arm/drivers/usart/pl011
        .
    INTERFACE
        cc312
    PRIVATE
        CMSIS_Driver/Config
        Device/Config
        ${MCUBOOT_PATH}/boot/bootutil/include # for fault_injection_hardening.h only
        ${CMAKE_BINARY_DIR}/bl2/ext/mcuboot # for mcuboot_config.h only
        $<BUILD_INTERFACE:${BL2_SOURCE}/ext/mcuboot/include>
	${CMAKE_SOURCE_DIR}/interface/include # for psa/error.h
)

#========================= ns_agent_mailbox ===================================#

target_sources(tfm_psa_rot_partition_ns_agent_mailbox
    PRIVATE
        tfm_hal_multi_core.c
)

if (PLATFORM_IS_FVP)
target_compile_definitions(tfm_psa_rot_partition_ns_agent_mailbox
    PUBLIC
       $<$<BOOL:${ENABLE_MULTICORE}>:CORSTONE1000_FVP_MULTICORE>
)
endif()
#========================= tfm_spm ============================================#

target_sources(tfm_spm
    PRIVATE
        tfm_interrupts.c
        tfm_hal_isolation.c
        tfm_hal_platform.c
        $<$<BOOL:${TFM_S_REG_TEST}>:${CMAKE_CURRENT_SOURCE_DIR}/target_cfg.c>
)

#========================= tfm_adac ============================================#

if (${PLATFORM_PSA_ADAC_SECURE_DEBUG} AND NOT ${PSA_ADAC_AS_TFM_RUNTIME_SERVICE})
    target_compile_definitions(platform_bl2
        PRIVATE
            PLATFORM_PSA_ADAC_SECURE_DEBUG
    )

    target_link_libraries(platform_bl2
        PRIVATE
            trusted-firmware-m-psa-adac
    )
endif()


find_package(Python3)

add_custom_target(bl1_provisioning_bundle
    ALL
    SOURCES bl1_provisioning_bundle.bin
)

add_custom_command(OUTPUT bl1_provisioning_bundle.bin
    DEPENDS ${TFM_BL2_ENCRYPTION_KEY_PATH}
    DEPENDS ${TFM_GUK_PATH}
    DEPENDS $<TARGET_FILE_DIR:bl1_2>/bl1_2_padded_hash.bin
    DEPENDS $<TARGET_FILE_DIR:bl1_2>/bl1_2_padded.bin
    bl1_2_padded_bin bl2_signed_bin
    COMMAND bl1_1_create_provisioning_bundle
                    --bl2_encryption_key_input_file ${TFM_BL2_ENCRYPTION_KEY_PATH}
                    --bl2_signing_key_input_file ${TFM_BL1_2_CM_SIGNING_KEY_PATH}
                    --guk_input_file ${TFM_GUK_PATH}
                    --bl1_2_padded_hash_input_file $<TARGET_FILE_DIR:bl1_2>/bl1_2_padded_hash.bin
                    --bl1_2_input_file $<TARGET_FILE_DIR:bl1_2>/bl1_2_padded.bin
                    --bundle_output_file bl1_provisioning_bundle.bin
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_BINARY_DIR}/bl1_provisioning_bundle.bin $<TARGET_FILE_DIR:bl1_1>
)
