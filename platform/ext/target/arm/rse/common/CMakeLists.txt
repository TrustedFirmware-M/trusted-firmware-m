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

find_package(Python3)

#========================= Platform region defs ===============================#

target_include_directories(platform_region_defs
    INTERFACE
        partition
        ${RSE_SUBPLATFORM_PAL_CONFIG_DIR}
        .
)

string(REPLACE "SHA" "PSA_ALG_SHA_" PSA_MEASUREMENT_HASH_ALG ${MEASURED_BOOT_HASH_ALG})

target_compile_definitions(platform_region_defs
    INTERFACE
        $<$<BOOL:${RSE_XIP}>:RSE_XIP>
        $<$<BOOL:${RSE_DEBUG_UART}>:RSE_DEBUG_UART>
        $<$<BOOL:${RSE_USE_HOST_UART}>:RSE_USE_HOST_UART>
        $<$<BOOL:${RSE_USE_LOCAL_UART}>:RSE_USE_LOCAL_UART>
        $<$<BOOL:${RSE_USE_HOST_FLASH}>:RSE_USE_HOST_FLASH>
        $<$<BOOL:${RSE_GPT_SUPPORT}>:RSE_GPT_SUPPORT>
        $<$<BOOL:${RSE_HAS_EXPANSION_PERIPHERALS}>:RSE_HAS_EXPANSION_PERIPHERALS>
        $<$<BOOL:${RSE_ENABLE_DCSU_PROVISIONING_COMMS}>:RSE_ENABLE_DCSU_PROVISIONING_COMMS>
        $<$<BOOL:${PLATFORM_HAS_PS_NV_OTP_COUNTERS}>:PLATFORM_HAS_PS_NV_OTP_COUNTERS>
        $<$<BOOL:${PLATFORM_ERROR_CODES}>:PLATFORM_ERROR_CODES>
        $<$<BOOL:${RSE_ENABLE_BRINGUP_HELPERS}>:RSE_ENABLE_BRINGUP_HELPERS>
        $<$<BOOL:${RSE_OTP_TRNG}>:RSE_OTP_TRNG>
        $<$<BOOL:${TFM_LOAD_NS_IMAGE}>:TFM_LOAD_NS_IMAGE>
        $<$<BOOL:${RSE_BIT_PROGRAMMABLE_OTP}>:RSE_BIT_PROGRAMMABLE_OTP>
        $<$<BOOL:${RSE_USE_OTP_EMULATION_IN_SRAM}>:RSE_USE_OTP_EMULATION_IN_SRAM>
        $<$<BOOL:${RSE_USE_ROM_LIB_FROM_SRAM}>:RSE_USE_ROM_LIB_FROM_SRAM>
        $<$<BOOL:${RSE_SUPPORT_ROM_LIB_RELOCATION}>:RSE_SUPPORT_ROM_LIB_RELOCATION>
        RSE_AMOUNT=${RSE_AMOUNT}
        RSE_COMMS_NUMBER_NODES=${RSE_COMMS_NUMBER_NODES}
        $<$<BOOL:${RSE_OTP_HAS_RSE_ID}>:RSE_OTP_HAS_RSE_ID>
        $<$<BOOL:${RSE_OTP_HAS_ROUTING_TABLES}>:RSE_OTP_HAS_ROUTING_TABLES>
        $<$<BOOL:${TFM_PARTITION_DELEGATED_ATTESTATION}>:RSE_BOOT_KEYS_CCA>
        $<$<BOOL:${TFM_PARTITION_DPE}>:RSE_BOOT_KEYS_DPE>
        TFM_UNIQUE_ERROR_CODES=1
        LCM_VERSION=0
        RSE_TP_MODE=LCM_TP_MODE_${RSE_TP_MODE}
        RSE_TESTS_TP_MODE=LCM_TP_MODE_${RSE_TESTS_TP_MODE}
        LCM_DCU_PARITY
        LCM_DCU_PAIR_COUNT=13
        $<$<BOOL:${PLAT_MHU_VERSION}>:PLAT_MHU_VERSION=${PLAT_MHU_VERSION}>
        $<$<BOOL:${RSE_BL1_TEST_BINARY}>:RSE_BL1_TEST_BINARY>
        $<$<BOOL:${RSE_TEST_BINARY_IN_SRAM}>:RSE_TEST_BINARY_IN_SRAM>
        $<$<BOOL:${TEST_BL1_2}>:TEST_BL1_2>
        MEASURED_BOOT_HASH_ALG=${PSA_MEASUREMENT_HASH_ALG}
        $<$<BOOL:${RSE_PROVISIONING_CURVE}>:RSE_PROVISIONING_CURVE=TFM_BL1_CURVE_${RSE_PROVISIONING_CURVE}>
        $<$<BOOL:${RSE_PROVISIONING_CURVE}>:RSE_PROVISIONING_CURVE_${RSE_PROVISIONING_CURVE}>
        $<$<BOOL:${RSE_PROVISIONING_HASH_ALG}>:RSE_PROVISIONING_HASH_ALG=TFM_BL1_HASH_ALG_${RSE_PROVISIONING_HASH_ALG}>
        $<$<BOOL:${RSE_PROVISIONING_ENABLE_ECDSA_SIGNATURES}>:RSE_PROVISIONING_ENABLE_ECDSA_SIGNATURES>
        $<$<BOOL:${RSE_PROVISIONING_ENABLE_AES_SIGNATURES}>:RSE_PROVISIONING_ENABLE_AES_SIGNATURES>
        $<$<BOOL:${RSE_PROVISIONING_CM_DEBUG_CLOSED}>:RSE_PROVISIONING_CM_DEBUG_CLOSED>
        $<$<BOOL:${RSE_PROVISIONING_REQUIRE_AUTHENTICATION_FOR_TCI}>:RSE_PROVISIONING_REQUIRE_AUTHENTICATION_FOR_TCI>
        $<$<BOOL:${RSE_BOOT_IN_DM_LCS}>:RSE_BOOT_IN_DM_LCS>
        $<$<BOOL:${RSE_NON_ENDORSED_DM_PROVISIONING}>:RSE_NON_ENDORSED_DM_PROVISIONING>
        $<$<BOOL:${RSE_ENDORSEMENT_CERTIFICATE_PROVISIONING}>:RSE_ENDORSEMENT_CERTIFICATE_PROVISIONING>
        $<$<BOOL:${RSE_PROVISIONING_DM_SIGN_KEY_CM_ROTPK_HASH_ALG}>:RSE_PROVISIONING_DM_SIGN_KEY_CM_ROTPK_HASH_ALG=RSE_ROTPK_HASH_ALG_${RSE_PROVISIONING_DM_SIGN_KEY_CM_ROTPK_HASH_ALG}>
        $<$<BOOL:${RSE_OTP_HAS_SOC_AREA}>:RSE_OTP_HAS_SOC_AREA>
        IC_CONFIG_DMA_CACHE_FLUSH_ENABLE
        $<$<BOOL:${TFM_CODE_COVERAGE}>:TFM_CODE_COVERAGE>
)

#========================= Platform common defs ===============================#

# Specify the location of platform specific build dependencies.
target_sources(tfm_s
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/device/source/startup_rse.c
)
target_add_scatter_file(tfm_s
        $<$<C_COMPILER_ID:ARMClang>:${CMAKE_BINARY_DIR}/generated/platform/ext/common/armclang/tfm_isolation_s.sct>
        $<$<C_COMPILER_ID:GNU>:${CMAKE_BINARY_DIR}/generated/platform/ext/common/gcc/tfm_isolation_s.ld>
        $<$<C_COMPILER_ID:Clang>:${CMAKE_BINARY_DIR}/generated/platform/ext/common/llvm/tfm_isolation_s.ld>
)

target_sources(bl2
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/device/source/startup_rse_bl.c
        $<$<BOOL:${PLATFORM_HAS_BOOT_DMA}>:${CMAKE_CURRENT_SOURCE_DIR}/bl2/boot_dma.c>
)

target_add_scatter_file(bl2
        $<$<C_COMPILER_ID:ARMClang>:${PLATFORM_DIR}/ext/common/armclang/tfm_common_bl2.sct>
        $<$<C_COMPILER_ID:GNU>:${PLATFORM_DIR}/ext/common/gcc/tfm_common_bl2.ld>
        $<$<C_COMPILER_ID:Clang>:${PLATFORM_DIR}/ext/common/llvm/tfm_common_bl2.ld>
)

target_compile_options(bl2_scatter
    PRIVATE
        $<$<BOOL:${PLATFORM_HAS_BOOT_DMA}>:${COMPILER_CMSE_FLAG}>
)

target_compile_definitions(bootutil
    PRIVATE
        MULTIPLE_EXECUTABLE_RAM_REGIONS
)

target_sources(bl1_1
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/device/source/startup_rse_bl1_1.c
)
target_add_scatter_file(bl1_1
        $<$<C_COMPILER_ID:ARMClang>:${CMAKE_CURRENT_SOURCE_DIR}/device/source/armclang/rse_bl1_1.sct>
        $<$<C_COMPILER_ID:GNU>:${CMAKE_CURRENT_SOURCE_DIR}/device/source/gcc/rse_bl1_1.ld>
        $<$<C_COMPILER_ID:Clang>:${CMAKE_CURRENT_SOURCE_DIR}/device/source/llvm/rse_bl1_1.ld>
)

target_sources(bl1_2
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/device/source/startup_rse_bl.c
)
target_add_scatter_file(bl1_2
        $<$<C_COMPILER_ID:ARMClang>:${CMAKE_CURRENT_SOURCE_DIR}/device/source/armclang/rse_bl1_2.sct>
        $<$<C_COMPILER_ID:GNU>:${CMAKE_CURRENT_SOURCE_DIR}/device/source/gcc/rse_bl1_2.ld>
        $<$<C_COMPILER_ID:Clang>:${CMAKE_CURRENT_SOURCE_DIR}/device/source/llvm/rse_bl1_2.ld>
)


install(FILES       tfm_builtin_key_ids.h
        DESTINATION ${INSTALL_INTERFACE_INC_DIR})

#========================= Platform Secure ====================================#

if (TFM_MULTI_CORE_TOPOLOGY)
    add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/rse_comms rse_comms)
    add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/rse_comms_psa_handler rse_comms_psa_handler)
endif()

if (RSE_AMOUNT GREATER 1)
    add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/rse_handshake rse_handshake)
endif()

add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/provisioning provisioning)

if (RSE_BL1_TEST_BINARY)
    add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/tests/rse_test_executable rse_test_executable)
endif()

# Set which PLATFORM dependency must be used by the CC3XX driver
set(CC3XX_PLATFORM_INTERFACE platform_bl1_1)
set(CC3XX_TARGET_PREFIX bl1_)

# BL1 code size is dimensioned for production hence we can't afford
# the variability required by building with different build type:
# Force the usage of RelWithDebInfo for the PSA crypto driver regardless
# of the specified build option
set(SAVED_BUILD_TYPE ${CMAKE_BUILD_TYPE})
set(CMAKE_BUILD_TYPE "RelWithDebInfo")
add_subdirectory(${PLATFORM_DIR}/ext/target/arm/drivers/cc3xx cc3xx)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/psa bl1_psa_crypto)
set(CMAKE_BUILD_TYPE ${SAVED_BUILD_TYPE})

target_include_directories(platform_s
    PUBLIC
        .
        ../common
        cmsis_drivers
        cmsis_drivers/config
        device
        device/config
        device/include
        device/source/armclang
        dpe
        native_drivers
        libraries
        partition
        services/src
        ${PLATFORM_DIR}/..
        ${PLATFORM_DIR}/ext/target/arm/drivers/counter/armv8m
        ${PLATFORM_DIR}/ext/target/arm/drivers/mpc_sie
        ${PLATFORM_DIR}/ext/target/arm/drivers/mpu/armv8m
        ${PLATFORM_DIR}/ext/target/arm/drivers/ppc
        ${PLATFORM_DIR}/ext/target/arm/drivers/sam
        ${PLATFORM_DIR}/ext/target/arm/drivers/timer/armv8m
        ${PLATFORM_DIR}/ext/target/arm/drivers/usart/cmsdk
        ${PLATFORM_DIR}/ext/target/arm/drivers/usart/common
        ${PLATFORM_DIR}/ext/target/arm/drivers/dma/dma350
        ${PLATFORM_DIR}/ext/target/arm/drivers/kmu
        ${PLATFORM_DIR}/ext/target/arm/drivers/lcm
        ${PLATFORM_DIR}/ext/target/arm/drivers/gpio/pl061
        ./bringup_helpers
        ./cc3xx
        ./runtime/cc3xx
        ${PLATFORM_DIR}/ext/target/arm/drivers/cc3xx/low_level_driver/include
        ${PLATFORM_DIR}/ext/target/arm/drivers/cc3xx/common
        soft_crc
        ${PLATFORM_DIR}/ext/target/arm/drivers/dcsu/include
        ${PLATFORM_DIR}/ext/target/arm/drivers/dcsu/default_config
)

target_sources(platform_s
    PRIVATE
        cmsis_drivers/Driver_MPC.c
        device/source/device_definition.c
        $<$<BOOL:${RSE_DEFAULT_CLOCK_CONFIG}>:${CMAKE_CURRENT_SOURCE_DIR}/device/source/rse_clocks.c>
        device/source/system_core_init.c
        $<$<BOOL:${TFM_PARTITION_DPE}>:${CMAKE_CURRENT_SOURCE_DIR}/dpe/dpe_plat.c>
        $<$<BOOL:${TFM_PARTITION_DPE}>:${CMAKE_CURRENT_SOURCE_DIR}/platform_locality.c>
        ${PLATFORM_DIR}/ext/target/arm/drivers/dma/dma350/dma350_lib.c
        $<$<BOOL:${RSE_USE_SDS_LIB}>:${CMAKE_CURRENT_SOURCE_DIR}/libraries/sds.c>
        native_drivers/atu_rse_drv.c
        native_drivers/atu_rse_lib.c
        device/source/atu_config.c
        ${PLATFORM_DIR}/ext/common/template/tfm_fih_platform.c
        ${PLATFORM_DIR}/ext/target/arm/drivers/dma/dma350/dma350_drv.c
        ${PLATFORM_DIR}/ext/target/arm/drivers/dma/dma350/dma350_ch_drv.c
        ${PLATFORM_DIR}/ext/target/arm/drivers/kmu/kmu_drv.c
        native_drivers/sic_drv.c
        $<$<EQUAL:${PLAT_MHU_VERSION},2>:${CMAKE_CURRENT_SOURCE_DIR}/native_drivers/mhu_v2_x.c>
        $<$<EQUAL:${PLAT_MHU_VERSION},2>:${CMAKE_CURRENT_SOURCE_DIR}/native_drivers/mhu_wrapper_v2_x.c>
        $<$<EQUAL:${PLAT_MHU_VERSION},3>:${CMAKE_CURRENT_SOURCE_DIR}/native_drivers/mhu_v3_x.c>
        $<$<EQUAL:${PLAT_MHU_VERSION},3>:${CMAKE_CURRENT_SOURCE_DIR}/native_drivers/mhu_wrapper_v3_x.c>
        native_drivers/integrity_checker_drv.c
        ${PLATFORM_DIR}/ext/target/arm/drivers/counter/armv8m/syscounter_armv8-m_cntrl_drv.c
        ${PLATFORM_DIR}/ext/target/arm/drivers/mpc_sie/mpc_sie_drv.c
        ${PLATFORM_DIR}/ext/target/arm/drivers/mpu/armv8m/mpu_armv8m_drv.c
        ${PLATFORM_DIR}/ext/target/arm/drivers/ppc/ppc_drv_sie200.c
        ${PLATFORM_DIR}/ext/target/arm/drivers/sam/sam_drv.c
        $<$<NOT:$<OR:$<BOOL:${TFM_PARTITION_SLIH_TEST}>,$<BOOL:${TFM_PARTITION_FLIH_TEST}>>>:${PLATFORM_DIR}/ext/target/arm/drivers/timer/armv8m/systimer_armv8-m_drv.c>
        $<$<BOOL:${RSE_DEBUG_UART}>:${CMAKE_CURRENT_SOURCE_DIR}/cmsis_drivers/Driver_USART_cmsdk.c>
        $<$<BOOL:${RSE_DEBUG_UART}>:${PLATFORM_DIR}/ext/target/arm/drivers/usart/cmsdk/uart_cmsdk_drv.c>
        tfm_peripherals_def.c
        $<$<OR:$<BOOL:${TEST_S_SCMI_COMMS}>,$<BOOL:${TFM_PARTITION_SLIH_TEST}>,$<BOOL:${TFM_PARTITION_FLIH_TEST}>>:${CMAKE_CURRENT_SOURCE_DIR}/plat_test.c>
        $<$<BOOL:${TFM_PARTITION_PLATFORM}>:${CMAKE_CURRENT_SOURCE_DIR}/services/src/tfm_platform_system.c>
        ${PLATFORM_DIR}/ext/target/arm/drivers/lcm/lcm_drv.c
        otp_lcm.c
        nv_counters.c
        $<$<BOOL:${RSE_SUBPLATFORM_PAL_DEFAULT_ROTPK}>:${CMAKE_CURRENT_SOURCE_DIR}/rse_rotpk_mapping.c>
        $<$<BOOL:${RSE_SUBPLATFORM_PAL_DEFAULT_NV_COUNTERS}>:${CMAKE_CURRENT_SOURCE_DIR}/rse_nv_counter_mapping.c>
        ./rse_rotpk_revocation.c
        $<$<BOOL:${TFM_PARTITION_INITIAL_ATTESTATION}>:${CMAKE_CURRENT_SOURCE_DIR}/attest_hal.c>
        tfm_hal_platform_reset.c
        $<$<BOOL:${PLATFORM_SVC_HANDLERS}>:${CMAKE_CURRENT_SOURCE_DIR}/platform_svc_handler.c>
        $<$<BOOL:${PLATFORM_SVC_HANDLERS}>:${PLATFORM_DIR}/ext/target/arm/drivers/dma/dma350/dma350_checker_layer.c>
        $<$<BOOL:${PLATFORM_SVC_HANDLERS}>:${CMAKE_CURRENT_SOURCE_DIR}/device/source/dma350_checker_device_defs.c>
        spm_dma_copy.c
        ${PLATFORM_DIR}/ext/target/arm/drivers/gpio/pl061/gpio_pl061_drv.c
        ./platform_fatal_error.c
        ./cc3xx/cc3xx_aes_external_key_loader.c
        ./rse_sam_config.c
        ./rse_attack_tracking_counter.c
        runtime_shared_data.c
        soft_crc/soft_crc.c
        $<$<BOOL:${PLATFORM_PSA_ADAC_SECURE_DEBUG}>:${CMAKE_CURRENT_SOURCE_DIR}/rse_debug_after_reset.c>
        ./rse_permanently_disable_device.c
        ./rse_zero_count.c
        ./rse_persistent_data.c
        ./dpa_hardened_word_copy.c
        $<$<BOOL:${RSE_ENABLE_DCSU_PROVISIONING_COMMS}>:${PLATFORM_DIR}/ext/target/arm/drivers/dcsu/src/dcsu_drv.c>
        $<$<BOOL:${RSE_ENABLE_DCSU_PROVISIONING_COMMS}>:${CMAKE_CURRENT_SOURCE_DIR}/rse_dcsu_hal.c>
        ./rse_soc_uid.c
        ./platform_shared_measurement_data.c
        $<$<BOOL:${RSE_OTP_HAS_RSE_ID}>:${CMAKE_CURRENT_SOURCE_DIR}/rse_get_rse_id_from_otp.c>
)

target_sources(tfm_sprt
    PRIVATE
        # SLIH test Partition and FLIH test Partition access the timer as ARoT Partitions.
        # Put the driver to SPRT so that both SLIH and FLIH tests can access it.
        $<$<OR:$<BOOL:${TFM_PARTITION_SLIH_TEST}>,$<BOOL:${TFM_PARTITION_FLIH_TEST}>>:${PLATFORM_DIR}/ext/target/arm/drivers/timer/armv8m/systimer_armv8-m_drv.c>
)

target_compile_definitions(platform_s
    INTERFACE
        ATTEST_KEY_BITS=${ATTEST_KEY_BITS}
        spm_memcpy=spm_dma_memcpy
    PRIVATE
        # Needed for DMA-350 library
        CMSIS_device_header="rse.h"
        $<$<BOOL:${PLATFORM_SVC_HANDLERS}>:PLATFORM_SVC_HANDLERS>
        $<$<BOOL:${RSE_USE_SDS_LIB}>:RSE_USE_SDS_LIB>
        RSE_SUBPLATFORM_PAL_DEFAULT_IOCTL=${RSE_SUBPLATFORM_PAL_DEFAULT_IOCTL}
)

target_compile_options(platform_s
    PUBLIC
        ${COMPILER_CMSE_FLAG}
)

#====================== SCMI hardware abstraction layer =======================#

if (TFM_PARTITION_SCMI_COMMS)
    add_library(scmi_hal INTERFACE)

    target_include_directories(scmi_hal
        INTERFACE
            scmi
    )

    target_sources(scmi_hal
        INTERFACE
            scmi/scmi_hal.c
            ${PLATFORM_DIR}/ext/common/scmi_hal_common.c
    )
endif()

#=============== Runtime provisioning hardware abstraction layer ==============#

if (TFM_PARTITION_RUNTIME_PROVISIONING)
    add_library(runtime_provisioning_hal INTERFACE)

    target_sources(runtime_provisioning_hal
        INTERFACE
            provisioning/runtime_provisioning_partition_hal.c
    )
endif()

#========================= Platform Crypto Keys ===============================#

if (TFM_PARTITION_CRYPTO)
    target_sources(platform_crypto_keys
        PRIVATE
            crypto_keys.c
    )

    target_include_directories(platform_crypto_keys
        PUBLIC
            .
            ./native_drivers
            ./device/include
            ./device/config
            ${RSE_SUBPLATFORM_PAL_CONFIG_DIR}
    )
endif()

#========================= Platform BL2 =======================================#

target_sources(platform_bl2
    PRIVATE
        tfm_hal_platform_reset.c
        device/source/device_definition.c
        $<$<BOOL:${RSE_DEFAULT_CLOCK_CONFIG}>:${CMAKE_CURRENT_SOURCE_DIR}/device/source/rse_clocks.c>
        device/source/system_core_init.c
        $<$<BOOL:${PLATFORM_HAS_NOC_S3}>:${CMAKE_CURRENT_SOURCE_DIR}/host_drivers/noc_s3/apu/noc_s3_apu_drv.c>
        $<$<BOOL:${PLATFORM_HAS_NOC_S3}>:${CMAKE_CURRENT_SOURCE_DIR}/host_drivers/noc_s3/discovery/noc_s3_discovery_drv.c>
        $<$<BOOL:${PLATFORM_HAS_NOC_S3}>:${CMAKE_CURRENT_SOURCE_DIR}/host_drivers/noc_s3/psam/noc_s3_psam_drv.c>
        $<$<BOOL:${PLATFORM_HAS_NOC_S3}>:${CMAKE_CURRENT_SOURCE_DIR}/host_drivers/noc_s3/util/noc_s3_util.c>
        $<$<BOOL:${PLATFORM_HAS_NOC_S3}>:${CMAKE_CURRENT_SOURCE_DIR}/host_drivers/noc_s3/noc_s3_rse_drv.c>
        $<$<BOOL:${PLATFORM_HAS_SMMU_V3}>:${CMAKE_CURRENT_SOURCE_DIR}/host_drivers/smmu_v3/smmu_v3_drv.c>
        $<$<OR:$<BOOL:${PLATFORM_HOST_HAS_MCP}>,$<BOOL:${PLATFORM_HOST_HAS_SCP}>>:${CMAKE_CURRENT_SOURCE_DIR}/host_drivers/mscp_drv/mscp_drv.c>
        $<$<BOOL:${PLATFORM_HAS_BOOT_DMA}>:${PLATFORM_DIR}/ext/target/arm/drivers/dma/dma350/dma350_lib.c>
        native_drivers/atu_rse_drv.c
        native_drivers/atu_rse_lib.c
        device/source/atu_config_bl2.c
        $<$<BOOL:${PLATFORM_HAS_BOOT_DMA}>:${PLATFORM_DIR}/ext/target/arm/drivers/dma/dma350/dma350_ch_drv.c>
        $<$<BOOL:${PLATFORM_HAS_BOOT_DMA}>:${PLATFORM_DIR}/ext/target/arm/drivers/dma/dma350/dma350_drv.c>
        ${PLATFORM_DIR}/ext/target/arm/drivers/kmu/kmu_drv.c
        native_drivers/sic_drv.c
        $<$<EQUAL:${PLAT_MHU_VERSION},2>:${CMAKE_CURRENT_SOURCE_DIR}/native_drivers/mhu_v2_x.c>
        $<$<EQUAL:${PLAT_MHU_VERSION},2>:${CMAKE_CURRENT_SOURCE_DIR}/native_drivers/mhu_wrapper_v2_x.c>
        $<$<EQUAL:${PLAT_MHU_VERSION},3>:${CMAKE_CURRENT_SOURCE_DIR}/native_drivers/mhu_v3_x.c>
        $<$<EQUAL:${PLAT_MHU_VERSION},3>:${CMAKE_CURRENT_SOURCE_DIR}/native_drivers/mhu_wrapper_v3_x.c>
        $<$<BOOL:${RSE_DEBUG_UART}>:${CMAKE_CURRENT_SOURCE_DIR}/cmsis_drivers/Driver_USART_cmsdk.c>
        $<$<BOOL:${RSE_DEBUG_UART}>:${PLATFORM_DIR}/ext/target/arm/drivers/usart/cmsdk/uart_cmsdk_drv.c>
        ${PLATFORM_DIR}/ext/target/arm/drivers/lcm/lcm_drv.c
        native_drivers/integrity_checker_drv.c
        otp_lcm.c
        nv_counters.c
        ./bl2/rse_bl2_rotpk.c
        ./bl2/rse_bl2_rotkw.c
        $<$<BOOL:${RSE_SUBPLATFORM_PAL_DEFAULT_ROTPK}>:${CMAKE_CURRENT_SOURCE_DIR}/rse_rotpk_mapping.c>
        $<$<BOOL:${RSE_SUBPLATFORM_PAL_DEFAULT_NV_COUNTERS}>:${CMAKE_CURRENT_SOURCE_DIR}/rse_nv_counter_mapping.c>
        $<$<BOOL:${RSE_XIP}>:${CMAKE_CURRENT_SOURCE_DIR}/bl2/sic_boot.c>
        ${PLATFORM_DIR}/ext/target/arm/drivers/gpio/pl061/gpio_pl061_drv.c
        ./platform_fatal_error.c
        ${PLATFORM_DIR}/ext/target/arm/drivers/sam/sam_drv.c
        ./rse_sam_config.c
        ./rse_attack_tracking_counter.c
        $<$<BOOL:${RSE_BL2_ENABLE_IMAGE_STAGING}>:${CMAKE_CURRENT_SOURCE_DIR}/bl2/staged_boot.c>
        $<$<BOOL:${RSE_BL2_ENABLE_IMAGE_STAGING}>:${CMAKE_CURRENT_SOURCE_DIR}/cmsis_drivers/Driver_Flash_memcpy.c>
        ./rse_permanently_disable_device.c
        ./rse_zero_count.c
        ./cc3xx/cc3xx_aes_external_key_loader.c
        ./dpa_hardened_word_copy.c
        ./rse_persistent_data.c
        ./platform_shared_measurement_data.c
        $<$<BOOL:${RSE_OTP_HAS_RSE_ID}>:${CMAKE_CURRENT_SOURCE_DIR}/rse_get_rse_id_from_otp.c>
)

target_include_directories(platform_bl2
    PUBLIC
        .
        bl2
        cmsis_drivers
        cmsis_drivers/config
        device
        device/config
        device/include
        device/source/armclang
        $<$<BOOL:${PLATFORM_HAS_NOC_S3}>:${CMAKE_CURRENT_SOURCE_DIR}/host_drivers/noc_s3>
        $<$<OR:$<BOOL:${PLATFORM_HOST_HAS_MCP}>,$<BOOL:${PLATFORM_HOST_HAS_SCP}>>:${CMAKE_CURRENT_SOURCE_DIR}/host_drivers/mscp_drv>
        $<$<BOOL:${PLATFORM_HAS_SMMU_V3}>:${CMAKE_CURRENT_SOURCE_DIR}/host_drivers/smmu_v3>
        native_drivers
        partition
        services/src
        libraries
        ${PLATFORM_DIR}/ext/target/arm/drivers/counter/armv8m
        ${PLATFORM_DIR}/ext/target/arm/drivers/mpc_sie
        ${PLATFORM_DIR}/ext/target/arm/drivers/ppc
        ${PLATFORM_DIR}/ext/target/arm/drivers/sam
        ${PLATFORM_DIR}/ext/target/arm/drivers/timer/armv8m
        ${PLATFORM_DIR}/ext/target/arm/drivers/usart/cmsdk
        ${PLATFORM_DIR}/ext/target/arm/drivers/usart/common
        ${PLATFORM_DIR}/ext/target/arm/drivers/dma/dma350
        ${PLATFORM_DIR}/ext/target/arm/drivers/kmu
        ${PLATFORM_DIR}/ext/target/arm/drivers/lcm
        ${PLATFORM_DIR}/ext/target/arm/drivers/gpio/pl061
        ${PLATFORM_DIR}/ext/target/arm/drivers/dcsu/include
        ${PLATFORM_DIR}/ext/target/arm/drivers/dcsu/default_config
        ./bringup_helpers
        ./cc3xx
        bl2/cc3xx
        ${RSE_SUBPLATFORM_PAL_CONFIG_DIR}
    PRIVATE
        ${PLATFORM_DIR}/..
)

target_compile_definitions(platform_bl2
    PUBLIC
        $<$<BOOL:${PLATFORM_HAS_BOOT_DMA}>:PLATFORM_HAS_BOOT_DMA>
        $<$<BOOL:${PLATFORM_BOOT_DMA_MIN_SIZE_REQ}>:BOOT_DMA_MIN_SIZE_REQ=${PLATFORM_BOOT_DMA_MIN_SIZE_REQ}>
    PRIVATE
        $<$<BOOL:${TFM_PARTITION_DELEGATED_ATTESTATION}>:RSE_BOOT_KEYS_CCA>
        $<$<BOOL:${TFM_PARTITION_DPE}>:RSE_BOOT_KEYS_DPE>
        # Needed for DMA-350 library
        $<$<BOOL:${PLATFORM_HAS_BOOT_DMA}>:CMSIS_device_header="rse.h">
        $<$<BOOL:${PLATFORM_HAS_NOC_S3}>:PLATFORM_HAS_NOC_S3>
        $<$<BOOL:${PLATFORM_HAS_SMMU_V3}>:PLATFORM_HAS_SMMU_V3>
        $<$<BOOL:${PLATFORM_HOST_HAS_MCP}>:PLATFORM_HOST_HAS_MCP>
        $<$<BOOL:${PLATFORM_HOST_HAS_SCP}>:PLATFORM_HOST_HAS_SCP>
        $<$<BOOL:${RSE_USE_SDS_LIB}>:RSE_USE_SDS_LIB>
        $<$<BOOL:${RSE_BL2_ENABLE_IMAGE_STAGING}>:RSE_BL2_ENABLE_IMAGE_STAGING>
        $<$<BOOL:${MCUBOOT_IMAGE_MULTI_SIG_SUPPORT}>:MCUBOOT_IMAGE_MULTI_SIG_SUPPORT>
        $<$<BOOL:${MCUBOOT_ROTPK_SIGN_POLICY}>:MCUBOOT_ROTPK_SIGN_POLICY>
        MCUBOOT_ROTPK_MAX_KEYS_PER_IMAGE=${MCUBOOT_ROTPK_MAX_KEYS_PER_IMAGE}
)

target_compile_options(platform_bl2
    PUBLIC
        $<$<BOOL:${PLATFORM_HAS_BOOT_DMA}>:${COMPILER_CMSE_FLAG}>
)

target_sources(bl2
    PRIVATE
        sam_interrupts.c
)

#========================= Platform bl1_1 =======================================#

target_sources(platform_bl1_1
    PRIVATE
        ./bl1/boot_hal_bl1_1.c
        ./device/source/device_definition.c
        $<$<BOOL:${RSE_DEFAULT_CLOCK_CONFIG}>:${CMAKE_CURRENT_SOURCE_DIR}/device/source/rse_clocks.c>
        ./device/source/system_core_init.c
        ./native_drivers/atu_rse_drv.c
        ./native_drivers/atu_rse_lib.c
        ./device/source/atu_config.c
        ${PLATFORM_DIR}/ext/target/arm/drivers/kmu/kmu_drv.c
        ${PLATFORM_DIR}/ext/target/arm/drivers/lcm/lcm_drv.c
        $<$<EQUAL:${PLAT_MHU_VERSION},2>:${CMAKE_CURRENT_SOURCE_DIR}/native_drivers/mhu_v2_x.c>
        $<$<EQUAL:${PLAT_MHU_VERSION},2>:${CMAKE_CURRENT_SOURCE_DIR}/native_drivers/mhu_wrapper_v2_x.c>
        $<$<EQUAL:${PLAT_MHU_VERSION},3>:${CMAKE_CURRENT_SOURCE_DIR}/native_drivers/mhu_v3_x.c>
        $<$<EQUAL:${PLAT_MHU_VERSION},3>:${CMAKE_CURRENT_SOURCE_DIR}/native_drivers/mhu_wrapper_v3_x.c>
        ./native_drivers/tram_drv.c
        ./native_drivers/integrity_checker_drv.c
        ./nv_counters.c
        ./bl1/rse_bl1_rotpk.c
        $<$<BOOL:${RSE_SUBPLATFORM_PAL_DEFAULT_ROTPK}>:${CMAKE_CURRENT_SOURCE_DIR}/rse_rotpk_mapping.c>
        $<$<BOOL:${RSE_SUBPLATFORM_PAL_DEFAULT_NV_COUNTERS}>:${CMAKE_CURRENT_SOURCE_DIR}/rse_nv_counter_mapping.c>
        ./otp_lcm.c
        ./tfm_hal_platform_reset.c
        $<$<BOOL:${RSE_DEBUG_UART}>:${CMAKE_CURRENT_SOURCE_DIR}/cmsis_drivers/Driver_USART_cmsdk.c>
        $<$<BOOL:${RSE_DEBUG_UART}>:${PLATFORM_DIR}/ext/target/arm/drivers/usart/cmsdk/uart_cmsdk_drv.c>
        ./dpa_hardened_word_copy.c
        ./cc3xx/cc3xx_aes_external_key_loader.c
        $<$<BOOL:${RSE_ENABLE_BRINGUP_HELPERS}>:${CMAKE_CURRENT_SOURCE_DIR}/bringup_helpers/rse_bringup_helpers.c>
        ./bl1/rse_kmu_keys.c
        ./rse_boot_state.c
        ${PLATFORM_DIR}/ext/target/arm/drivers/gpio/pl061/gpio_pl061_drv.c
        ./platform_fatal_error.c
        $<$<NOT:$<BOOL:${TFM_BL1_SOFTWARE_CRYPTO}>>:${CMAKE_CURRENT_SOURCE_DIR}/bl1/cc3xx/cc3xx_rom_crypto.c>
        ${CMAKE_CURRENT_SOURCE_DIR}/bl1/bl1_fih_platform.c
        ${CMAKE_CURRENT_SOURCE_DIR}/bl1/cc3xx/cc3xx_rom_random.c
        $<$<BOOL:${RSE_OTP_TRNG}>:${CMAKE_CURRENT_SOURCE_DIR}/rse_trng.c>
        ${PLATFORM_DIR}/ext/target/arm/drivers/sam/sam_drv.c
        ./rse_sam_config.c
        ./rse_attack_tracking_counter.c
        runtime_shared_data.c
        soft_crc/soft_crc.c
        ${PLATFORM_DIR}/ext/target/arm/drivers/lcm/lcm_drv.c
        ./device/source/device_definition.c
        ./bl1/bl1_1_debug.c
        ./rse_permanently_disable_device.c
        ./rse_zero_count.c
        ./rse_persistent_data.c
        $<$<BOOL:${RSE_ENABLE_DCSU_PROVISIONING_COMMS}>:${PLATFORM_DIR}/ext/target/arm/drivers/dcsu/src/dcsu_drv.c>
        $<$<BOOL:${RSE_ENABLE_DCSU_PROVISIONING_COMMS}>:${CMAKE_CURRENT_SOURCE_DIR}/rse_dcsu_hal.c>
        ./platform_shared_measurement_data.c
        ./rse_soc_uid.c
        ${PLATFORM_DIR}/ext/target/arm/drivers/mpu/armv8m/mpu_armv8m_drv.c
        $<$<BOOL:${RSE_OTP_HAS_RSE_ID}>:${CMAKE_CURRENT_SOURCE_DIR}/rse_get_rse_id_from_otp.c>
        $<$<BOOL:${RSE_ENABLE_ROM_SELF_TESTS}>:${CMAKE_CURRENT_SOURCE_DIR}/rse_boot_self_tests.c>
)

target_compile_definitions(platform_bl1_1
    PRIVATE
        $<$<BOOL:${PLATFORM_PSA_ADAC_SECURE_DEBUG}>:PLATFORM_PSA_ADAC_SECURE_DEBUG>
        $<$<BOOL:${RSE_ENABLE_FIH_SW_DELAY}>:RSE_ENABLE_FIH_SW_DELAY>
        $<$<BOOL:${RSE_ENABLE_ROM_SELF_TESTS}>:RSE_ENABLE_ROM_SELF_TESTS>
        $<$<BOOL:${RSE_ENABLE_ECDSA_SELF_TEST}>:RSE_ENABLE_ECDSA_SELF_TEST>
        $<$<BOOL:${RSE_ENABLE_KDF_CMAC_SELF_TEST}>:RSE_ENABLE_KDF_CMAC_SELF_TEST>
)

target_include_directories(platform_bl1_1_interface
    INTERFACE
        .
        ./cmsis_drivers
        ./cmsis_drivers/config
        ./device/config
        ./device/include
        ./native_drivers
        ${PLATFORM_DIR}/ext/target/arm/drivers/counter/armv8m
        ${PLATFORM_DIR}/ext/target/arm/drivers/mpc_sie
        ${PLATFORM_DIR}/ext/target/arm/drivers/ppc
        ${PLATFORM_DIR}/ext/target/arm/drivers/sam
        ${PLATFORM_DIR}/ext/target/arm/drivers/timer/armv8m
        ${PLATFORM_DIR}/ext/target/arm/drivers/mpu/armv8m
        ${PLATFORM_DIR}/ext/target/arm/drivers/usart/cmsdk
        ${PLATFORM_DIR}/ext/target/arm/drivers/usart/common
        ${PLATFORM_DIR}/ext/target/arm/drivers/dma/dma350
        ${PLATFORM_DIR}/ext/target/arm/drivers/kmu
        ${PLATFORM_DIR}/ext/target/arm/drivers/lcm
        ${PLATFORM_DIR}/ext/target/arm/drivers/cc3xx/low_level_driver/include
        ${PLATFORM_DIR}/ext/target/arm/drivers/cc3xx/common
        ${PLATFORM_DIR}/ext/target/arm/drivers/gpio/pl061
        ${PLATFORM_DIR}/ext/target/arm/drivers/dcsu/include
        ${PLATFORM_DIR}/ext/target/arm/drivers/dcsu/default_config
        ./bringup_helpers
        ./cc3xx
        ./bl1/cc3xx
        soft_crc
        ${RSE_SUBPLATFORM_PAL_CONFIG_DIR}
)

target_compile_definitions(platform_bl1_1_interface
    INTERFACE
        $<$<BOOL:${TFM_PARTITION_DELEGATED_ATTESTATION}>:RSE_BOOT_KEYS_CCA>
        $<$<BOOL:${TFM_PARTITION_DPE}>:RSE_BOOT_KEYS_DPE>
        KMU_CONFIG_EXTERNAL_SECURE_WORD_COPY
        $<$<BOOL:${RSE_ENCRYPTED_OTP_KEYS}>:RSE_ENCRYPTED_OTP_KEYS>
        $<$<BOOL:${RSE_ENABLE_TRAM}>:RSE_ENABLE_TRAM>
)

target_link_libraries(platform_bl1_1
    PRIVATE
        bl1_cc3xx
        bl1_psa_crypto
        bl1_1_shared_lib_interface
)

if(RSE_SUPPORT_ROM_LIB_RELOCATION)
    set(ROM_LIB_RELOCATION_COMPILE_FLAGS
            # Enable position independent code
            -fpic
            # Tell the compiler that it can't assume the offset between the data
            # and code sections doesn't change
            -mno-pic-data-is-text-relative
            # Set r9 as the register to use for the GOT. This register will not
            # be used for any other purpose. If this is changed, some of the ASM
            # setup functions will need to be changed.
            -mpic-register=r9
            # Tell the compiler it can assume that r9 will always contain the
            # address of the GOT, and that it doesn't need to try to set r9
            # itself (we do it in the initial setup).
            -msingle-pic-base
            # Force function calls through the GOT instead of short-range
            # BL instructions
            -mlong-calls
    )

    target_compile_options(platform_bl1_1
        PUBLIC
            ${ROM_LIB_RELOCATION_COMPILE_FLAGS}
    )

    target_compile_options(bl1_1_crypto_mbedcrypto
        PRIVATE
            ${ROM_LIB_RELOCATION_COMPILE_FLAGS}
    )

    target_compile_options(bl1_1_crypto_mbedtls
        PRIVATE
            ${ROM_LIB_RELOCATION_COMPILE_FLAGS}
    )

    target_compile_options(bl1_1_crypto_mbedx509
        PRIVATE
            ${ROM_LIB_RELOCATION_COMPILE_FLAGS}
    )
endif()

if (RSE_USE_ROM_LIB_FROM_SRAM)
    add_custom_target(bl1_1_shared_symbols_in_sram
        COMMAND ${CMAKE_OBJCOPY}
            ${CMAKE_BINARY_DIR}/bin/bl1_1${CODE_SHARING_OUTPUT_FILE_SUFFIX}
            --change-section-address .text\*${RSE_ROM_LIB_RELOCATION_OFFSET}
            ${CMAKE_BINARY_DIR}/bin/bl1_1${CODE_SHARING_INPUT_FILE_SUFFIX}
    )

    add_dependencies(bl1_1_shared_symbols_in_sram bl1_1 bl1_1_shared_symbols)
    add_dependencies(bl1_2 bl1_1_shared_symbols_in_sram)
endif()

target_sources(bl1_1_shared_lib
    PRIVATE
        $<$<NOT:$<BOOL:${TFM_BL1_SOFTWARE_CRYPTO}>>:${CMAKE_CURRENT_SOURCE_DIR}/bl1/cc3xx/cc3xx_rom_crypto.c>
        $<$<NOT:$<BOOL:${RSE_OTP_TRNG}>>:${CMAKE_CURRENT_SOURCE_DIR}/bl1/cc3xx/cc3xx_rom_random.c>
        $<$<BOOL:${RSE_OTP_TRNG}>:${CMAKE_CURRENT_SOURCE_DIR}/rse_trng.c>
)

target_sources(bl1_1
    PRIVATE
        sam_interrupts.c
)

#========================= Platform BL1_2 =====================================#

target_sources(platform_bl1_2
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/bl1/bl1_fih_platform.c
        $<$<BOOL:${RSE_DEFAULT_CLOCK_CONFIG}>:${CMAKE_CURRENT_SOURCE_DIR}/device/source/rse_clocks.c>
        device/source/system_core_init.c
        ./bl1/boot_hal_bl1_2.c
        ./bl1/bl1_2_debug.c
        ./sam_interrupts.c
        ./native_drivers/atu_rse_drv.c
        ./native_drivers/atu_rse_lib.c
        ./device/source/atu_config.c
)

add_dependencies(platform_bl1_2 bl1_1_shared_symbols)

target_include_directories(platform_bl1_2
    PRIVATE
        .
        ${PLATFORM_DIR}/ext/target/arm/drivers/dma/dma350
        ${PLATFORM_DIR}/ext/target/arm/drivers/kmu
        ${PLATFORM_DIR}/ext/target/arm/drivers/lcm
        ${PLATFORM_DIR}/ext/target/arm/drivers/dcsu/include
        ${PLATFORM_DIR}/ext/target/arm/drivers/dcsu/default_config
        ./tests/rse_test_executable
        ./native_drivers
)

target_compile_definitions(platform_bl1_2
    PUBLIC
        $<$<BOOL:${TFM_PARTITION_DELEGATED_ATTESTATION}>:RSE_BOOT_KEYS_CCA>
        $<$<BOOL:${TFM_PARTITION_DPE}>:RSE_BOOT_KEYS_DPE>
)

if(RSE_USE_HOST_FLASH)
    add_subdirectory(./fip_parser)
endif()

if(RSE_SUPPORT_ROM_LIB_RELOCATION)
    target_compile_options(platform_bl1_2
        PUBLIC
            # Prevent BL1_2 from using r9
            -ffixed-r9
            # Inlining causes gcc to generate reads and writes to r9. This is
            # probably a bug, but work around it by not inlining functions.
            -fno-inline
    )
endif()

#========================= ns_agent_mailbox ===================================#

if(TFM_MULTI_CORE_TOPOLOGY)
    target_sources(tfm_psa_rot_partition_ns_agent_mailbox
        PRIVATE
            ${CMAKE_CURRENT_SOURCE_DIR}/tfm_hal_multi_core.c
    )
endif()

#========================= tfm_spm ============================================#

target_sources(tfm_spm
    PRIVATE
        target_cfg.c
        ${PLATFORM_DIR}/ext/common/tfm_hal_isolation_v8m.c
        tfm_hal_isolation_rse.c
        tfm_hal_platform.c
        tfm_interrupts.c
)

# If this is not added to the tfm_s it will not correctly override the weak
# default handlers declared in assemebly, and will instead be discarded as they
# are not in use.
target_sources(tfm_s
    PRIVATE
        ${PLATFORM_DIR}/ext/common/mpc_ppc_faults.c
        sam_interrupts.c
)

############################### IMAGE SIGNING ##################################

if (MCUBOOT_ENCRYPT_KW)
    add_custom_command(OUTPUT ${MCUBOOT_KEY_ENC}
            DEPENDS ${CMAKE_BINARY_DIR}/bin/bl1_2_padded_hash.bin

            COMMAND ${Python3_EXECUTABLE}  ${CMAKE_CURRENT_SOURCE_DIR}/provisioning/bl2_key_derivation.py
                    --key_file "${CMAKE_SOURCE_DIR}/bl1/bl1_1/dummy_guk.bin"
                    --key_select "kce:cm"
                    --tp_mode "${RSE_TP_MODE}"
                    --output_key_file "enc_key_s.b64"
            COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_BINARY_DIR}/enc_key_s.b64 $<TARGET_FILE_DIR:bl2>
    )

    add_custom_command(OUTPUT ${MCUBOOT_KEY_ENC_NS}
            DEPENDS ${CMAKE_BINARY_DIR}/bin/bl1_2_padded_hash.bin

            COMMAND ${Python3_EXECUTABLE}  ${CMAKE_CURRENT_SOURCE_DIR}/provisioning/bl2_key_derivation.py
                    --key_file "${CMAKE_SOURCE_DIR}/bl1/bl1_1/dummy_guk.bin"
                    --key_select "kce:dm"
                    --tp_mode "${RSE_TP_MODE}"
                    --output_key_file "enc_key_ns.b64"
            COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_BINARY_DIR}/enc_key_ns.b64 $<TARGET_FILE_DIR:bl2>
    )

    add_custom_target(BL2_encryption_keys ALL
            SOURCES
                ${MCUBOOT_KEY_ENC}
                ${MCUBOOT_KEY_ENC_NS}
    )
endif()

if (RSE_XIP)
    add_custom_target(public_key ALL
        SOURCES
            image_s_signing_public_key.pem
            image_ns_signing_public_key.pem
    )
    add_custom_command(OUTPUT image_s_signing_public_key.pem
        # If MCUBOOT_GENERATE_SIGNING_KEYPAIR=ON then the command should depend on that
        # to make sure that the key is generated and copied to the MCUBOOT_KEY_S path.
        DEPENDS $<IF:$<BOOL:${MCUBOOT_GENERATE_SIGNING_KEYPAIR}>,generated_private_key,>
        COMMAND ${Python3_EXECUTABLE} ${MCUBOOT_PATH}/scripts/imgtool.py
            getpub
            -k ${MCUBOOT_KEY_S}
            -e pem
            -o image_s_signing_public_key.pem
        COMMAND ${CMAKE_COMMAND} -E copy image_s_signing_public_key.pem $<TARGET_FILE_DIR:bl2>
    )
    add_custom_command(OUTPUT image_ns_signing_public_key.pem
        # If MCUBOOT_GENERATE_SIGNING_KEYPAIR=ON then the command should depend on that
        # to make sure that the key is generated and copied to the MCUBOOT_KEY_NS path.
        DEPENDS $<IF:$<BOOL:${MCUBOOT_GENERATE_SIGNING_KEYPAIR}>,generated_private_key,>
        COMMAND ${Python3_EXECUTABLE} ${MCUBOOT_PATH}/scripts/imgtool.py
            getpub
            -k ${MCUBOOT_KEY_NS}
            -e pem
            -o image_ns_signing_public_key.pem
        COMMAND ${CMAKE_COMMAND} -E copy image_ns_signing_public_key.pem $<TARGET_FILE_DIR:bl2>
    )

    add_custom_target(tfm_s_sic_tables
        SOURCES tfm_s_sic_tables.bin
    )

    add_custom_command(OUTPUT tfm_s_sic_tables.bin
        OUTPUT tfm_s_encrypted.bin
        DEPENDS tfm_s_bin
        DEPENDS ${CMAKE_BINARY_DIR}/bin/bl1_2_padded_hash.bin
        COMMAND ${CMAKE_COMMAND} -E env PYTHONPATH=${CMAKE_SOURCE_DIR}/tools/modules
        ${Python3_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/bl2/create_xip_tables.py
            --input_image $<TARGET_FILE_DIR:tfm_s>/tfm_s.bin
            --table_output_file tfm_s_sic_tables.bin
            --encrypted_image_output_file tfm_s_encrypted.bin
            --image_version ${MCUBOOT_SECURITY_COUNTER_S}
            --label "RUNTIME_SECURE_ENCRYPTION_KEY"
        COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_BINARY_DIR}/tfm_s_sic_tables.bin $<TARGET_FILE_DIR:tfm_s>
        COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_BINARY_DIR}/tfm_s_encrypted.bin $<TARGET_FILE_DIR:tfm_s>
    )

    set(IMAGE_TYPE "S_IMAGE")
    set(FLASH_AREA_NUM ${MCUBOOT_S_IMAGE_FLASH_AREA_NUM})
    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/bl2/signing_layout_sic_tables.c.in signing_layout_s.c @ONLY)
    add_library(signing_layout_s OBJECT ${CMAKE_CURRENT_BINARY_DIR}/signing_layout_s.c)

    target_compile_options(signing_layout_s
        PRIVATE
            $<$<C_COMPILER_ID:GNU>:-E\;-xc>
            $<$<C_COMPILER_ID:ARMClang>:-E\;-xc>
            $<$<C_COMPILER_ID:IAR>:--preprocess=ns\;$<TARGET_OBJECTS:signing_layout_s>>
            $<$<C_COMPILER_ID:Clang>:-E\;-xc>
    )
    target_compile_definitions(signing_layout_s
        PRIVATE
            $<$<BOOL:${BL2}>:BL2>
            $<$<BOOL:${MCUBOOT_IMAGE_NUMBER}>:MCUBOOT_IMAGE_NUMBER=${MCUBOOT_IMAGE_NUMBER}>
            $<$<STREQUAL:${MCUBOOT_UPGRADE_STRATEGY},DIRECT_XIP>:IMAGE_ROM_FIXED>
    )
    target_link_libraries(signing_layout_s
        PRIVATE
            platform_bl2
    )

    add_custom_command(OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/tfm_s_sic_tables_signed.bin
        DEPENDS tfm_s_sic_tables
        DEPENDS tfm_s_bin signing_layout_s
        DEPENDS $<$<BOOL:${MCUBOOT_ENC_IMAGES}>:${MCUBOOT_KEY_ENC}>
        WORKING_DIRECTORY ${MCUBOOT_PATH}/scripts

        #Sign secure binary image with provided secret key
        COMMAND ${Python3_EXECUTABLE} ${CMAKE_SOURCE_DIR}/bl2/ext/mcuboot/scripts/wrapper.py
            -v ${MCUBOOT_IMAGE_VERSION_S}
            --layout $<TARGET_OBJECTS:signing_layout_s>
            -k ${MCUBOOT_KEY_S}
            --public-key-format $<IF:$<BOOL:${MCUBOOT_HW_KEY}>,full,hash>
            --align ${MCUBOOT_ALIGN_VAL}
            --pad
            --pad-header
            -H ${BL2_HEADER_SIZE}
            -s ${MCUBOOT_SECURITY_COUNTER_S}
            -L ${MCUBOOT_ENC_KEY_LEN}
            -d \"\(1,${MCUBOOT_NS_IMAGE_MIN_VER}\)\"
            $<$<STREQUAL:${MCUBOOT_UPGRADE_STRATEGY},OVERWRITE_ONLY>:--overwrite-only>
            $<$<BOOL:${MCUBOOT_ENC_IMAGES}>:-E${MCUBOOT_KEY_ENC}>
            $<$<BOOL:${MCUBOOT_MEASURED_BOOT}>:--measured-boot-record>
            $<TARGET_FILE_DIR:tfm_s>/tfm_s_sic_tables.bin
            ${CMAKE_CURRENT_BINARY_DIR}/tfm_s_sic_tables_signed.bin
        COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_BINARY_DIR}/tfm_s_sic_tables_signed.bin $<TARGET_FILE_DIR:bl2>
    )

    add_custom_target(signed_images
        ALL
        DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/tfm_s_sic_tables_signed.bin
    )

    set(IMAGE_TYPE "NS_IMAGE")
    set(FLASH_AREA_NUM ${MCUBOOT_NS_IMAGE_FLASH_AREA_NUM})
    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/bl2/signing_layout_sic_tables.c.in
                   ${CMAKE_CURRENT_BINARY_DIR}/signing_layout_sic_tables_ns.c @ONLY)

    install(FILES       ${CMAKE_CURRENT_BINARY_DIR}/signing_layout_sic_tables_ns.c
            DESTINATION ${INSTALL_IMAGE_SIGNING_DIR}/layout_files)

    install(FILES       bl2/create_xip_tables.py
            FILES       bl2/kce_dm_dummy_encryption_key.bin
            FILES       ${CMAKE_SOURCE_DIR}/bl1/bl1_1/dummy_guk.bin
            DESTINATION ${INSTALL_IMAGE_SIGNING_DIR}/scripts)

    install(DIRECTORY ${CMAKE_SOURCE_DIR}/tools/modules
            DESTINATION ${INSTALL_IMAGE_SIGNING_DIR}/scripts)

    install(DIRECTORY ${CMAKE_SOURCE_DIR}/bl2/ext/mcuboot/scripts
            DESTINATION ${INSTALL_IMAGE_SIGNING_DIR}
            PATTERN "scripts/*.py"
            PERMISSIONS OWNER_EXECUTE OWNER_WRITE OWNER_READ
            GROUP_EXECUTE GROUP_READ
            PATTERN "scripts/*.py"
            PERMISSIONS OWNER_EXECUTE OWNER_WRITE OWNER_READ
                        GROUP_EXECUTE GROUP_READ)

    install(DIRECTORY ${MCUBOOT_PATH}/scripts/imgtool
            DESTINATION ${INSTALL_IMAGE_SIGNING_DIR}/scripts)

    install(FILES ${MCUBOOT_KEY_NS}
            RENAME image_ns_signing_private_key.pem
            DESTINATION ${INSTALL_IMAGE_SIGNING_DIR}/keys/)
    install(FILES ${CMAKE_CURRENT_BINARY_DIR}/image_ns_signing_public_key.pem
            DESTINATION ${INSTALL_IMAGE_SIGNING_DIR}/keys)

    if (MCUBOOT_ENC_IMAGES)
        install(FILES ${MCUBOOT_KEY_ENC}
                RENAME image_enc_key.pem
                DESTINATION ${INSTALL_IMAGE_SIGNING_DIR}/keys)
    endif()
endif()

############################## BL1 DMA ###################################

set(bin_dir ${CMAKE_BINARY_DIR}/bin)

add_custom_target(dma_icses
    ALL
    SOURCES rom_dma_ics.bin ${bin_dir}/rom_dma_ics.bin
            rom_dma_ics.hex ${bin_dir}/rom_dma_ics.hex
            otp_dma_ics.bin ${bin_dir}/otp_dma_ics.bin
            otp_dma_ics.hex ${bin_dir}/otp_dma_ics.hex
)

add_custom_command(
    OUTPUT rom_dma_ics.bin
    OUTPUT otp_dma_ics.bin
    OUTPUT rom_dma_ics.hex
    OUTPUT otp_dma_ics.hex
    OUTPUT rom_dma_ics.csv
    OUTPUT otp_dma_ics.csv
    OUTPUT ${bin_dir}/rom_dma_ics.bin
    OUTPUT ${bin_dir}/otp_dma_ics.bin
    OUTPUT ${bin_dir}/rom_dma_ics.hex
    OUTPUT ${bin_dir}/otp_dma_ics.hex
    OUTPUT ${bin_dir}/rom_dma_ics.csv
    OUTPUT ${bin_dir}/otp_dma_ics.csv
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/bl1/scripts/create_bl1_1_dma_bin.py
    COMMAND ${Python3_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/bl1/scripts/create_bl1_1_dma_bin.py
                    --input_file ${RSE_DMA_ICS_CONFIG_PATH}
                    --output_dir ${CMAKE_CURRENT_BINARY_DIR}
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_BINARY_DIR}/rom_dma_ics.bin $<TARGET_FILE_DIR:bl1_1>
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_BINARY_DIR}/otp_dma_ics.bin $<TARGET_FILE_DIR:bl1_1>
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_BINARY_DIR}/rom_dma_ics.hex $<TARGET_FILE_DIR:bl1_1>
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_BINARY_DIR}/otp_dma_ics.hex $<TARGET_FILE_DIR:bl1_1>
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_BINARY_DIR}/rom_dma_ics.csv $<TARGET_FILE_DIR:bl1_1>
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_BINARY_DIR}/otp_dma_ics.csv $<TARGET_FILE_DIR:bl1_1>
)

############################## OTP Layout ######################################

file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/config)

add_custom_target(otp_config
    ALL
    SOURCES ${CMAKE_CURRENT_BINARY_DIR}/config/otp_config.pickle
)

add_custom_command(OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/config/otp_config.pickle
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/scripts/modules/otp_config.py
    DEPENDS ${RSE_SUBPLATFORM_PAL_CONFIG_DIR}/rse_otp_config.h
    DEPENDS ${PLATFORM_DIR}/ext/target/arm/drivers/lcm/lcm_otp_layout.h
    COMMAND ${CMAKE_COMMAND} -E env PYTHONPATH=${CMAKE_SOURCE_DIR}/tools/modules
        ${Python3_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/scripts/modules/otp_config.py
        --rse_otp_layout_h_file=${CMAKE_CURRENT_SOURCE_DIR}/rse_otp_layout.h
        --compile_commands_file=${CMAKE_BINARY_DIR}/compile_commands.json
        --otp_config_output_file=${CMAKE_CURRENT_BINARY_DIR}/config/otp_config.pickle
)

install(FILES       ${CMAKE_CURRENT_BINARY_DIR}/config/otp_config.pickle
        DESTINATION ${INSTALL_PLATFORM_NS_DIR}/config)

add_custom_target(otp_layout_specification
    ALL
    SOURCES ${CMAKE_CURRENT_BINARY_DIR}/config/otp_layout.csv
)

add_custom_command(OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/config/otp_layout.csv
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/scripts/create_otp_layout_specification.py
    DEPENDS ${RSE_SUBPLATFORM_PAL_CONFIG_DIR}/rse_otp_config.h
    DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/config/otp_config.pickle
    COMMAND ${CMAKE_COMMAND} -E env PYTHONPATH=${CMAKE_SOURCE_DIR}/tools/modules
        ${Python3_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/scripts/create_otp_layout_specification.py
            --otp_config=${CMAKE_CURRENT_BINARY_DIR}/config/otp_config.pickle
            --specification_output_file=${CMAKE_CURRENT_BINARY_DIR}/config/otp_layout.csv
)

install(FILES       ${CMAKE_CURRENT_BINARY_DIR}/config/otp_layout.csv
        DESTINATION ${INSTALL_PLATFORM_NS_DIR}/config)

############################## Routing tables ##################################

if (RSE_COMMS_NUMBER_NODES GREATER 1)
    target_sources(platform_bl1_1
        PRIVATE
            ./rse_get_routing_tables.c
    )

    target_sources(platform_s
        PRIVATE
            ./rse_get_routing_tables.c
    )

    add_custom_target(routing_tables_pickle
        ALL
        SOURCES ${CMAKE_CURRENT_BINARY_DIR}/config/routing_tables.pickle
    )

    add_custom_command(OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/config/routing_tables.pickle
        DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/rse_routing_tables.h
        DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/scripts/modules/routing_tables.py
        DEPENDS ${MULTI_RSE_TOPOLOGY_FILE}
        COMMAND ${CMAKE_COMMAND} -E env PYTHONPATH=${CMAKE_SOURCE_DIR}/tools/modules
            ${Python3_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/scripts/modules/routing_tables.py
                --rse_routing_tables_h_file=${CMAKE_CURRENT_SOURCE_DIR}/rse_routing_tables.h
                --compile_commands_file=${CMAKE_BINARY_DIR}/compile_commands.json
                --topology_graph_file=${MULTI_RSE_TOPOLOGY_FILE}
                --routing_tables_output_file=${CMAKE_CURRENT_BINARY_DIR}/config/routing_tables.pickle
    )

    if (NOT RSE_OTP_HAS_ROUTING_TABLES)
        add_custom_target(routing_tables_definition_source_file
            SOURCES ${CMAKE_CURRENT_BINARY_DIR}/rse_system_routing_tables_definition.c
        )

        add_custom_command(OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/rse_system_routing_tables_definition.c
            DEPENDS  ${CMAKE_CURRENT_SOURCE_DIR}/scripts/create_routing_tables_source_file.py
            DEPENDS  ${CMAKE_CURRENT_BINARY_DIR}/config/routing_tables.pickle
            COMMAND ${CMAKE_COMMAND} -E env PYTHONPATH=${CMAKE_SOURCE_DIR}/tools/modules
                ${Python3_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/scripts/create_routing_tables_source_file.py
                    --routing_tables=${CMAKE_CURRENT_BINARY_DIR}/config/routing_tables.pickle
                    --c_source_output_file ${CMAKE_CURRENT_BINARY_DIR}/rse_system_routing_tables_definition.c
        )

        add_dependencies(platform_bl1_1 routing_tables_definition_source_file)

        target_sources(platform_bl1_1
            PRIVATE
                ${CMAKE_CURRENT_BINARY_DIR}/rse_system_routing_tables_definition.c
        )

        add_dependencies(platform_s routing_tables_definition_source_file)

        target_sources(platform_s
            PRIVATE
                ${CMAKE_CURRENT_BINARY_DIR}/rse_system_routing_tables_definition.c
        )
    endif()
endif()

add_custom_target(error_codes_mapping
    ALL
    SOURCES ${CMAKE_CURRENT_BINARY_DIR}/config/error_codes_mapping.csv
)

add_custom_command(OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/config/error_codes_mapping.csv
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/scripts/error_codes_config.py
    DEPENDS ${RSE_SUBPLATFORM_PAL_CONFIG_DIR}/rse_otp_config.h
    COMMAND ${CMAKE_COMMAND} -E env PYTHONPATH=${CMAKE_SOURCE_DIR}/tools/modules
        ${Python3_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/scripts/error_codes_config.py
            --error_code_output_file=${CMAKE_CURRENT_BINARY_DIR}/config/error_codes_mapping.csv
            --compile_commands_file=${CMAKE_BINARY_DIR}/compile_commands.json
            --c_compiler=${CMAKE_C_COMPILER}
            ${CMAKE_CURRENT_SOURCE_DIR}/../../rse/common/platform_error_codes.h:tfm_plat_err_t
            ${CMAKE_CURRENT_SOURCE_DIR}/../../drivers/kmu/kmu_drv.h:kmu_error_t
            ${CMAKE_CURRENT_SOURCE_DIR}/../../drivers/lcm/lcm_drv.h:lcm_error_t
            ${CMAKE_CURRENT_SOURCE_DIR}/../../rse/common/native_drivers/mhu_v2_x.h:mhu_v2_x_error_t
            ${CMAKE_CURRENT_SOURCE_DIR}/../../rse/common/native_drivers/mhu_v3_x.h:mhu_v3_x_error_t
            ${CMAKE_CURRENT_SOURCE_DIR}/../../rse/common/native_drivers/mhu.h:mhu_error_t
            ${CMAKE_CURRENT_SOURCE_DIR}/../../rse/common/native_drivers/atu_rse_drv.h:atu_error_t
            ${CMAKE_CURRENT_SOURCE_DIR}/../../rse/common/native_drivers/integrity_checker_drv.h:integrity_checker_error_t
            ${CMAKE_CURRENT_SOURCE_DIR}/../../drivers/dcsu/include/dcsu_drv.h:dcsu_error_t
            ${CMAKE_CURRENT_SOURCE_DIR}/../../drivers/cc3xx/common/cc3xx_error.h:cc3xx_error
)

install(FILES       ${CMAKE_CURRENT_BINARY_DIR}/config/error_codes_mapping.csv
        DESTINATION ${INSTALL_PLATFORM_NS_DIR}/config)

#========================= Files for building NS side platform ================#

if (TFM_LOAD_NS_IMAGE)
    install(FILES       device/source/device_definition.c
                        device/source/atu_config.c
                        $<$<BOOL:${RSE_DEFAULT_CLOCK_CONFIG}>:${CMAKE_CURRENT_SOURCE_DIR}/device/source/rse_clocks.c>
                        device/source/startup_rse.c
                        device/source/system_core_init.c
            DESTINATION ${INSTALL_PLATFORM_NS_DIR}/device/source
    )

    install(FILES       $<$<BOOL:${TFM_PARTITION_NS_AGENT_MAILBOX}>:${CMAKE_CURRENT_SOURCE_DIR}/platform_ns_mailbox.c>
            DESTINATION ${INSTALL_PLATFORM_NS_DIR}/../interface/src/multi_core
    )

    install(FILES       ${PLATFORM_DIR}/ext/common/uart_stdout.c
                        $<$<BOOL:${RSE_DEBUG_UART}>:${PLATFORM_DIR}/ext/target/arm/drivers/usart/cmsdk/uart_cmsdk_drv.c>
                        $<$<BOOL:${RSE_DEBUG_UART}>:${CMAKE_CURRENT_SOURCE_DIR}/cmsis_drivers/Driver_USART_cmsdk.c>
            DESTINATION ${INSTALL_PLATFORM_NS_DIR}
    )

    install(DIRECTORY native_drivers
            DESTINATION ${INSTALL_PLATFORM_NS_DIR}
    )

    install(FILES       ${PLATFORM_DIR}/ext/target/arm/drivers/counter/armv8m/syscounter_armv8-m_cntrl_drv.c
                        ${PLATFORM_DIR}/ext/target/arm/drivers/counter/armv8m/syscounter_armv8-m_cntrl_drv.h
                        ${PLATFORM_DIR}/ext/target/arm/drivers/mpc_sie/mpc_sie_drv.c
                        ${PLATFORM_DIR}/ext/target/arm/drivers/mpu/armv8m/mpu_armv8m_drv.c
                        ${PLATFORM_DIR}/ext/target/arm/drivers/timer/armv8m/systimer_armv8-m_drv.c
                        ${PLATFORM_DIR}/ext/target/arm/drivers/gpio/pl061/gpio_pl061_drv.c
                        ${PLATFORM_DIR}/ext/target/arm/drivers/mpc_sie/mpc_sie_drv.h
                        ${PLATFORM_DIR}/ext/target/arm/drivers/mpu/armv8m/mpu_armv8m_drv.h
                        ${PLATFORM_DIR}/ext/target/arm/drivers/timer/armv8m/systimer_armv8-m_drv.h
                        ${PLATFORM_DIR}/ext/target/arm/drivers/gpio/pl061/gpio_pl061_drv.h
            DESTINATION ${INSTALL_PLATFORM_NS_DIR}/native_drivers
    )

    install(FILES       device/config/device_cfg_ns.h
            DESTINATION ${INSTALL_PLATFORM_NS_DIR}/device/config
            RENAME      device_cfg.h)

    install(DIRECTORY   device/include
            DESTINATION ${INSTALL_PLATFORM_NS_DIR}/device
    )

    install(DIRECTORY   cmsis_drivers
            DESTINATION ${INSTALL_PLATFORM_NS_DIR}
    )

    install(DIRECTORY   partition
            DESTINATION ${INSTALL_PLATFORM_NS_DIR}
    )

    install(DIRECTORY   ${RSE_SUBPLATFORM_PAL_CONFIG_DIR}/
            DESTINATION ${INSTALL_PLATFORM_NS_DIR}/subplatform_pal_config
    )

    install(DIRECTORY   ${BL1_1_CONFIG_DIR}/
            DESTINATION ${INSTALL_PLATFORM_NS_DIR}/bl1_1_config
    )

    install(DIRECTORY   ${BL1_2_CONFIG_DIR}/
            DESTINATION ${INSTALL_PLATFORM_NS_DIR}/bl1_2_config
    )

    install(FILES       rse_otp_check_config.h
            DESTINATION ${INSTALL_PLATFORM_NS_DIR}/subplatform_pal_config/
    )

    install(FILES       rse_rotpk_auto_generated_mappings.h
            DESTINATION ${INSTALL_PLATFORM_NS_DIR}/subplatform_pal_config/
    )

    install(FILES       target_cfg.h
                        tfm_peripherals_def.h
                        error_codes_mapping.h
                        platform_error_codes.h
                        ${PLATFORM_DIR}/include/tfm_plat_defs.h
                        ${PLATFORM_DIR}/ext/common/uart_stdout.h
                        $<$<BOOL:${TFM_PARTITION_DPE}>:${CMAKE_CURRENT_SOURCE_DIR}/platform_locality.h>
            DESTINATION ${INSTALL_PLATFORM_NS_DIR}/include)

    install(DIRECTORY   ns/
            DESTINATION ${INSTALL_PLATFORM_NS_DIR})

    install(FILES       cpuarch.cmake
            DESTINATION ${INSTALL_PLATFORM_NS_DIR}/config/common)

    install(FILES       tests/tfm_tests_config.cmake
            DESTINATION ${INSTALL_PLATFORM_NS_DIR}/tests/common)

    install(FILES       check_config.cmake
            DESTINATION ${INSTALL_PLATFORM_NS_DIR})

    install(FILES       config_tfm_target_rse_common.h
            DESTINATION ${INSTALL_PLATFORM_NS_DIR}/partition)

    # Install linker scripts
    install(FILES       ${PLATFORM_DIR}/ext/common/gcc/tfm_common_ns.ld
                        ${PLATFORM_DIR}/ext/common/armclang/tfm_common_ns.sct
                        ${PLATFORM_DIR}/ext/common/iar/tfm_common_ns.icf
            DESTINATION ${INSTALL_PLATFORM_NS_DIR}/linker_scripts)

    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/ns/config.cmake.in
                   ${INSTALL_PLATFORM_NS_DIR}/config.cmake @ONLY)
endif()
