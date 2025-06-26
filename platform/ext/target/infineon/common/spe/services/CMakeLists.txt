#-------------------------------------------------------------------------------
# Copyright (c) 2023-2025 Cypress Semiconductor Corporation (an Infineon company)
# or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

# SE IPC Service to handle se-rt-services-utils requests
add_subdirectory(se_ipc_service)

target_compile_definitions(tfm_config
    INTERFACE
        IFX_DRIVER_FLASH_PROG_BUF_ON_STACK=$<BOOL:${IFX_DRIVER_FLASH_PROG_BUF_ON_STACK}>
        IFX_DRIVER_FLASH_SINGLE_INSTANCE=$<BOOL:${IFX_DRIVER_FLASH_SINGLE_INSTANCE}>
)

################################### Drivers ####################################

target_include_directories(tfm_sprt
    PUBLIC
        ${IFX_COMMON_SOURCE_DIR}/drivers/flash/flash
        ${IFX_COMMON_SOURCE_DIR}/drivers/flash/rram
        ${IFX_COMMON_SOURCE_DIR}/drivers/flash/smif
        ${IFX_COMMON_SOURCE_DIR}/drivers/flash
)

target_sources(tfm_sprt
    PRIVATE
        $<$<BOOL:${IFX_FLASH_DRIVER_ENABLED}>:${IFX_COMMON_SOURCE_DIR}/drivers/flash/flash/ifx_driver_flash.c>
        $<$<BOOL:${IFX_RRAM_DRIVER_ENABLED}>:${IFX_COMMON_SOURCE_DIR}/drivers/flash/rram/ifx_driver_rram.c>
        $<$<OR:$<BOOL:${IFX_FLASH_DRIVER_ENABLED}>,$<BOOL:${IFX_RRAM_DRIVER_ENABLED}>>:${IFX_COMMON_SOURCE_DIR}/drivers/flash/ifx_driver_private.c>
        $<$<BOOL:${IFX_SMIF_MMIO_DRIVER_ENABLED}>:${IFX_COMMON_SOURCE_DIR}/drivers/flash/smif/ifx_driver_smif_mmio.c>
        $<$<BOOL:${IFX_SMIF_XIP_DRIVER_ENABLED}>:${IFX_COMMON_SOURCE_DIR}/drivers/flash/smif/ifx_driver_smif_xip.c>
        $<$<OR:$<BOOL:${IFX_SMIF_MMIO_DRIVER_ENABLED}>,$<BOOL:${IFX_SMIF_XIP_DRIVER_ENABLED}>>:${IFX_COMMON_SOURCE_DIR}/drivers/flash/smif/ifx_driver_smif.c>
)

################################################################################

if (TFM_PARTITION_CRYPTO)
    # Overwrite CRYPTO_ENGINE_BUF_SIZE in .h files if CRYPTO_ENGINE_BUF_SIZE is specified in CMake
    # This makes it possible to set CRYPTO_ENGINE_BUF_SIZE through CMake
    if(DEFINED CRYPTO_ENGINE_BUF_SIZE)
        target_compile_definitions(tfm_config
            INTERFACE
                CRYPTO_ENGINE_BUF_SIZE=${CRYPTO_ENGINE_BUF_SIZE}
        )
    endif()

    if(DEFINED IFX_MBEDTLS_CONFIG_PATH)
        target_compile_definitions(tfm_config
            INTERFACE
                $<BUILD_INTERFACE:IFX_MBEDTLS_CONFIG_PATH="${IFX_MBEDTLS_CONFIG_PATH}">
        )
    endif()

    target_compile_definitions(platform_crypto_keys
        PRIVATE
            $<$<BOOL:${MBEDTLS_PSA_CRYPTO_PLATFORM_FILE}>:MBEDTLS_PSA_CRYPTO_PLATFORM_FILE="${MBEDTLS_PSA_CRYPTO_PLATFORM_FILE}">
    )

    # Our mbedcrypto patch adds #include "tfm_builtin_key_loader.h" to psa_crypto_driver_wrappers.h file.
    # In turn, psa_crypto.c file from mbedcrypto includes psa_crypto_driver_wrappers.h file,
    # so we need to link platform_crypto_keys to crypto_service_tfpsacrypto_config
    target_link_libraries(crypto_service_tfpsacrypto_config
        INTERFACE
            platform_crypto_keys
    )

    if (IFX_CRYPTO_SE_RT)
        target_sources(crypto_service_tfpsacrypto
            PRIVATE
                crypto/crypto_rnd_se_rt.c
        )

        target_compile_definitions(${IFX_SE_RT_SERVICES_UTILS_S_TARGET}
            PUBLIC
                MBEDTLS_PSA_CRYPTO_DRIVERS
        )
    endif()

    if (IFX_CRYPTO_KEYS_FLASH)
        target_sources(platform_crypto_keys
            PRIVATE
                crypto/crypto_keys_flash.c
        )
    endif()

    if (IFX_CRYPTO_KEYS_RRAM)
        # psa_interface is linked to tfm_sprt, thus when tfm_sprt is linked to
        # platform_crypto_keys, types from psa_interface conflict with MbedTLS
        # native types. Because of this tfm_plat_nvm_read_asset function can not
        # be added to platform_crypto_keys using tfm_sprt, instead they have to
        # be added to platform_crypto_keys directly.
        target_include_directories(platform_crypto_keys
            PRIVATE
                ${IFX_COMMON_SOURCE_DIR}/drivers/assets
                ${IFX_COMMON_SOURCE_DIR}/drivers/flash
                ${IFX_COMMON_SOURCE_DIR}/drivers/flash/rram
                ${MBEDTLS_PSA_CRYPTO_PLATFORM_PATH}
        )

        target_sources(platform_crypto_keys
            PRIVATE
                crypto/crypto_keys_rram.c
                ${IFX_COMMON_SOURCE_DIR}/drivers/assets/ifx_assets_rram.c
        )

        target_link_libraries(platform_crypto_keys
            PUBLIC
                $<$<BOOL:${IFX_SE_RT_SERVICES_UTILS_ENABLED}>:${IFX_SE_RT_SERVICES_UTILS_S_TARGET}>
        )
    endif()

    if (IFX_CRYPTO_KEYS_SE_RT)
        target_include_directories(platform_crypto_keys
            PRIVATE
                ${MBEDTLS_PSA_CRYPTO_PLATFORM_PATH}
        )

        target_sources(platform_crypto_keys
            PRIVATE
                crypto/crypto_keys_se_rt.c
        )

        target_link_libraries(platform_crypto_keys
            PUBLIC
                ${IFX_SE_RT_SERVICES_UTILS_S_TARGET}
            PRIVATE
                psa_interface
        )

        target_link_libraries(crypto_service_tfpsacrypto
            PUBLIC
                ${IFX_SE_RT_SERVICES_UTILS_S_TARGET}
        )
    endif()

    target_sources(platform_s
        PRIVATE
            $<$<NOT:$<BOOL:${PLATFORM_DEFAULT_NV_SEED}>>:${IFX_COMMON_SOURCE_DIR}/spe/services/crypto/crypto_nv_seed.c>
    )
endif()

if (TFM_PARTITION_INITIAL_ATTESTATION)
    target_sources(tfm_psa_rot_partition_attestation
        PRIVATE
            attestation/ifx_attest_hal.c
            $<$<BOOL:${IFX_PLATFORM_DEFAULT_DEVICE_ID}>:${CMAKE_CURRENT_SOURCE_DIR}/attestation/ifx_plat_device_id.c>
            $<$<BOOL:${IFX_INITIAL_ATTESTATION_SE_RT}>:${CMAKE_CURRENT_SOURCE_DIR}/attestation/ifx_attest_hal_se_rt.c>
    )

    target_compile_definitions(tfm_psa_rot_partition_attestation
        PRIVATE
            PLATFORM_CREATES_ATTEST_TOKEN=$<BOOL:${IFX_INITIAL_ATTESTATION_SE_RT}>
            IFX_INITIAL_ATTESTATION_SE_RT=$<BOOL:${IFX_INITIAL_ATTESTATION_SE_RT}>
    )

    target_include_directories(tfm_psa_rot_partition_attestation
        PRIVATE
            ${IFX_COMMON_SOURCE_DIR}/spe/provisioning
            ${IFX_COMMON_SOURCE_DIR}/drivers/assets # For ifx_assets_rram.h
    )

    target_link_libraries(tfm_psa_rot_partition_attestation
        PRIVATE
            $<$<BOOL:${IFX_SE_RT_SERVICES_UTILS_ENABLED}>:${IFX_SE_RT_SERVICES_UTILS_S_TARGET}>
    )
endif()

if (TFM_PARTITION_INTERNAL_TRUSTED_STORAGE)
    target_sources(tfm_psa_rot_partition_its
        PRIVATE
            "$<$<IN_LIST:FLASH,${IFX_ITS_VALID_TYPES}>:${IFX_COMMON_SOURCE_DIR}/spe/services/its/drivers/its_flash_driver.c>"
            "$<$<IN_LIST:RRAM,${IFX_ITS_VALID_TYPES}>:${IFX_COMMON_SOURCE_DIR}/spe/services/its/drivers/its_rram_driver.c>"
            ${IFX_COMMON_SOURCE_DIR}/spe/services/its/its_hal.c
    )

    target_include_directories(tfm_psa_rot_partition_its
        PRIVATE
            ${IFX_COMMON_SOURCE_DIR}/drivers/flash/rram
            ${IFX_COMMON_SOURCE_DIR}/drivers/flash/smif
            ${IFX_COMMON_SOURCE_DIR}/drivers/flash
            ${IFX_COMMON_SOURCE_DIR}/spe/services/its
    )

    target_link_libraries(tfm_psa_rot_partition_its
        PRIVATE
            psa_interface
    	psa_crypto_config
    )
endif()

if (TFM_PARTITION_NS_AGENT_MAILBOX)
    target_sources(tfm_psa_rot_partition_ns_agent_mailbox
        PRIVATE
            mailbox/platform_spe_mailbox.c
            mailbox/tfm_hal_multi_core.c
            mailbox/tfm_interrupts.c
            ${IFX_COMMON_SOURCE_DIR}/shared/mailbox/platform_multicore.c
    )

    target_include_directories(tfm_psa_rot_partition_ns_agent_mailbox
        PRIVATE
            mailbox
            ${IFX_COMMON_SOURCE_DIR}/shared/mailbox/
            ${IFX_GENERATED_DIR}/interface/include
            ${CMAKE_SOURCE_DIR}/interface/include/multi_core
    )

    target_sources(tfm_psa_rot_partition_ns_agent_mailbox
        PRIVATE
            $<$<BOOL:${IFX_MULTICORE_CM55}>:${CMAKE_CURRENT_LIST_DIR}/mailbox/platform_hal_multi_core_cm55.c>
    )
endif()

if (TFM_PARTITION_PLATFORM)
    target_sources(tfm_psa_rot_partition_platform
        PRIVATE
            ${CMAKE_CURRENT_SOURCE_DIR}/platform/nv_counters_common.c
            "$<$<IN_LIST:SE_RT,${IFX_NV_COUNTERS_VALID_TYPES}>:${CMAKE_CURRENT_SOURCE_DIR}/platform/nv_counters_se_rt.c>"
            "$<$<IN_LIST:FLASH,${IFX_NV_COUNTERS_VALID_TYPES}>:${CMAKE_CURRENT_SOURCE_DIR}/platform/nv_counters_flash.c>"
            "$<$<IN_LIST:FLASH,${IFX_NV_COUNTERS_VALID_TYPES}>:${CMAKE_CURRENT_SOURCE_DIR}/platform/drivers/nv_counters_flash_driver.c>"
            "$<$<IN_LIST:RRAM,${IFX_NV_COUNTERS_VALID_TYPES}>:${CMAKE_CURRENT_SOURCE_DIR}/platform/nv_counters_rram.c>"
            "$<$<IN_LIST:RRAM,${IFX_NV_COUNTERS_VALID_TYPES}>:${CMAKE_CURRENT_SOURCE_DIR}/platform/drivers/nv_counters_rram_driver.c>"
            $<$<NOT:$<BOOL:${IFX_SE_RT_SERVICES_UTILS_ENABLED}>>:${IFX_COMMON_SOURCE_DIR}/utils/se/ifx_se_crc32.c>

            platform/tfm_platform_system.c
    )

    target_include_directories(tfm_psa_rot_partition_platform
        PRIVATE
            platform
            platform/drivers
            ${IFX_COMMON_SOURCE_DIR}/interface/include
            ${IFX_COMMON_SOURCE_DIR}/interface/src
            ${IFX_COMMON_SOURCE_DIR}/drivers/flash/rram
            ${IFX_COMMON_SOURCE_DIR}/drivers/flash
            $<$<NOT:$<BOOL:${IFX_SE_RT_SERVICES_UTILS_ENABLED}>>:${IFX_COMMON_SOURCE_DIR}/utils/se>
    )

    target_link_libraries(tfm_psa_rot_partition_platform
        PRIVATE
            $<$<BOOL:${IFX_SE_RT_SERVICES_UTILS_ENABLED}>:${IFX_SE_RT_SERVICES_UTILS_S_TARGET}>
            tfm_spm
    )
endif()

if (TFM_PARTITION_PROTECTED_STORAGE)
    target_sources(tfm_app_rot_partition_ps
        PRIVATE
            $<$<AND:$<BOOL:${IFX_CRYPTO_SE_RT}>,$<BOOL:${IFX_PARTITION_SE_IPC_SERVICE}>>:${IFX_COMMON_SOURCE_DIR}/spe/services/ps/ps_keys_se_rt.c>
    )

    target_sources(tfm_psa_rot_partition_its
        PRIVATE
            ${IFX_COMMON_SOURCE_DIR}/spe/services/ps/ps_hal.c
            "$<$<IN_LIST:SMIF_MMIO,${IFX_PS_VALID_TYPES}>:${IFX_COMMON_SOURCE_DIR}/spe/services/ps/drivers/ps_smif_driver.c>"
            "$<$<IN_LIST:RRAM,${IFX_PS_VALID_TYPES}>:${IFX_COMMON_SOURCE_DIR}/spe/services/ps/drivers/ps_rram_driver.c>"
    )
endif()

################################# TF-M Tests ##################################

if (TFM_S_REG_TEST OR TFM_NS_REG_TEST)
    target_sources(platform_s
        PRIVATE
            tfm_tests/plat_test.c
    )
endif()

if(TEST_NS_SLIH_IRQ)
    target_sources(tfm_app_rot_partition_slih_test
        PRIVATE
            tfm_tests/plat_test_secure_timer.c
    )
elseif(TEST_NS_FLIH_IRQ)
    target_sources(tfm_app_rot_partition_flih_test
        PRIVATE
            tfm_tests/plat_test_secure_timer.c
    )
endif()

if (TEST_PSA_API STREQUAL IPC)
    target_sources(platform_s
        PRIVATE
            tfm_tests/plat_test_secure_timer.c
            tfm_tests/plat_test.c
    )
endif()

target_sources(tfm_spm
    PRIVATE
        tfm_tests/tfm_interrupts_test_s.c
)
