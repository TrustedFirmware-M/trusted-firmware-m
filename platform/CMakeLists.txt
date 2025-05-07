#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
# Copyright (c) 2022 Cypress Semiconductor Corporation (an Infineon company)
# or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------
cmake_minimum_required(VERSION 3.21)

add_library(platform_s STATIC)
add_library(platform_region_defs INTERFACE)
add_library(platform_common_interface INTERFACE)

if (BL2)
    add_library(platform_bl2 STATIC)
endif()

if (BL1 AND PLATFORM_DEFAULT_BL1)
    add_library(platform_bl1_1 STATIC)
    add_library(platform_bl1_2 STATIC)
    add_library(platform_bl1_1_interface INTERFACE)
endif()

if (TFM_PARTITION_CRYPTO)
    add_library(platform_crypto_keys STATIC)
endif()

set(PLATFORM_DIR ${CMAKE_CURRENT_LIST_DIR} CACHE PATH "Path to platform directory")

add_subdirectory(ext/target/${TFM_PLATFORM} target)

#====================== CMSIS stack override interface ========================#

# NS linker scripts using the default CMSIS style naming conventions, while the
# secure and bl2 linker scripts remain untouched (region.h compatibility).
# To be compatible with the untouched files (which using ARMCLANG naming style),
# we have to override __INITIAL_SP and __STACK_LIMIT labels.

set(CMSIS_OVERRIDE_HEADER "${CMAKE_CURRENT_LIST_DIR}/include/cmsis_override.h")
add_library(cmsis_stack_override INTERFACE)
target_compile_options(cmsis_stack_override
    INTERFACE
        "$<$<C_COMPILER_ID:GNU>:SHELL:-include ${CMSIS_OVERRIDE_HEADER}>"
        "$<$<AND:$<OR:$<COMPILE_LANGUAGE:C>,$<COMPILE_LANGUAGE:CXX>>,$<C_COMPILER_ID:IAR>>:SHELL:--preinclude ${CMSIS_OVERRIDE_HEADER}>"
        "$<$<C_COMPILER_ID:Clang>:SHELL:-include ${CMSIS_OVERRIDE_HEADER}>"
)

#========================= Platform Common interface ==========================#

target_include_directories(platform_common_interface
    INTERFACE
        ext
        ext/common
        ext/driver
        include
)

#========================= Platform Secure ====================================#

target_include_directories(platform_s
    PUBLIC
        $<$<BOOL:${CRYPTO_HW_ACCELERATOR}>:${CMAKE_CURRENT_SOURCE_DIR}/ext/accelerator/interface>
)

target_sources(platform_s
    PRIVATE
        $<$<AND:$<BOOL:${TFM_PARTITION_PROTECTED_STORAGE}>,$<BOOL:${PLATFORM_DEFAULT_PS_HAL}>>:${CMAKE_CURRENT_SOURCE_DIR}/ext/common/tfm_hal_ps.c>
        $<$<AND:$<BOOL:${TFM_PARTITION_INTERNAL_TRUSTED_STORAGE}>,$<BOOL:${PLATFORM_DEFAULT_ITS_HAL}>>:${CMAKE_CURRENT_SOURCE_DIR}/ext/common/tfm_hal_its.c>
        $<$<BOOL:${PLATFORM_DEFAULT_SYSTEM_RESET_HALT}>:${CMAKE_CURRENT_SOURCE_DIR}/ext/common/tfm_hal_reset_halt.c>
        $<$<BOOL:${PLATFORM_DEFAULT_UART_STDOUT}>:${CMAKE_CURRENT_SOURCE_DIR}/ext/common/uart_stdout.c>
        $<$<BOOL:${TFM_SPM_LOG_RAW_ENABLED}>:ext/common/tfm_hal_spm_logdev_peripheral.c>
        $<$<BOOL:${TFM_EXCEPTION_INFO_DUMP}>:ext/common/exception_info.c>
        $<$<BOOL:${PLATFORM_DEFAULT_ATTEST_HAL}>:ext/common/template/attest_hal.c>
        $<$<BOOL:${PLATFORM_DEFAULT_NV_COUNTERS}>:ext/common/template/nv_counters.c>
        $<$<BOOL:${PLATFORM_DEFAULT_ROTPK}>:ext/common/template/tfm_rotpk.c>
        $<$<BOOL:${PLATFORM_DEFAULT_NV_SEED}>:ext/common/template/crypto_nv_seed.c>
        $<$<BOOL:${PLATFORM_DEFAULT_SHARED_MEASUREMENT_DATA}>:ext/common/template/tfm_shared_measurement_data.c>
        $<$<OR:$<AND:$<BOOL:${PLATFORM_DEFAULT_NV_COUNTERS}>,$<BOOL:${TFM_PARTITION_PROTECTED_STORAGE}>>,$<BOOL:${PLATFORM_DEFAULT_OTP}>>:ext/common/template/flash_otp_nv_counters_backend.c>
        $<$<BOOL:${PLATFORM_DEFAULT_OTP}>:ext/common/template/otp_flash.c>
        $<$<BOOL:${PLATFORM_DEFAULT_PROVISIONING}>:ext/common/provisioning.c>
        $<$<OR:$<BOOL:${TEST_S_FPU}>,$<BOOL:${TEST_NS_FPU}>>:${CMAKE_SOURCE_DIR}/platform/ext/common/test_interrupt.c>
        $<$<BOOL:${TFM_SANITIZE}>:ext/common/tfm_sanitize_handlers.c>
        ./ext/common/tfm_fatal_error.c
)

# If this is not added to the tfm_s it will not correctly override the weak
# default handlers declared in assemebly, and will instead be discarded as they
# are not in use.
target_sources(tfm_s
    PRIVATE
        ext/common/faults.c
)

target_link_libraries(platform_s
    PUBLIC
        platform_common_interface
        platform_region_defs
        tfm_fih_headers
        cmsis_stack_override
        cmsis
        tfm_log_headers
        $<$<BOOL:${CONFIG_TFM_BACKTRACE_ON_CORE_PANIC}>:tfm_log_unpriv>
        $<$<BOOL:${CONFIG_TFM_BACKTRACE_ON_CORE_PANIC}>:tfm_log>
        $<$<BOOL:${CONFIG_TFM_BACKTRACE_ON_CORE_PANIC}>:tfm_backtrace>
    PRIVATE
        tfm_config
        tfm_spm_defs
        $<$<BOOL:${TFM_PARTITION_CRYPTO}>:platform_crypto_keys>
        $<$<BOOL:${PLATFORM_DEFAULT_ATTEST_HAL}>:tfm_sprt>
        $<$<BOOL:${TFM_PARTITION_CRYPTO}>:crypto_service_mbedcrypto>
        $<$<BOOL:${TFM_PARTITION_INITIAL_ATTESTATION}>:tfm_attestation_defs>
        $<$<NOT:$<STREQUAL:${TFM_FIH_PROFILE},OFF>>:tfm_fih>
        tfm_log
        psa_crypto_library_config
)

target_compile_definitions(platform_s
    PUBLIC
        LOG_LEVEL=${TFM_SPM_LOG_LEVEL}
        $<$<BOOL:${TFM_SPM_LOG_RAW_ENABLED}>:TFM_SPM_LOG_RAW_ENABLED>
        $<$<BOOL:${CONFIG_TFM_BACKTRACE_ON_CORE_PANIC}>:CONFIG_TFM_BACKTRACE_ON_CORE_PANIC>
        $<$<BOOL:${CONFIG_TFM_BACKTRACE_ON_CORE_PANIC}>:LOG_LEVEL=LOG_LEVEL_ERROR>
        $<$<BOOL:${CONFIG_TFM_BACKTRACE_ON_CORE_PANIC}>:LOG_LEVEL_UNPRIV=LOG_LEVEL_ERROR>
        $<$<BOOL:${OTP_NV_COUNTERS_RAM_EMULATION}>:OTP_NV_COUNTERS_RAM_EMULATION=1>
        $<$<BOOL:${TFM_EXCEPTION_INFO_DUMP}>:TFM_EXCEPTION_INFO_DUMP>
        $<$<OR:$<VERSION_GREATER:${TFM_ISOLATION_LEVEL},1>,$<STREQUAL:"${TEST_PSA_API}","IPC">>:CONFIG_TFM_ENABLE_MEMORY_PROTECT>
        $<$<BOOL:${TFM_PXN_ENABLE}>:TFM_PXN_ENABLE>
        $<$<STREQUAL:${CONFIG_TFM_FLOAT_ABI},hard>:CONFIG_TFM_FLOAT_ABI=2>
        $<$<STREQUAL:${CONFIG_TFM_FLOAT_ABI},soft>:CONFIG_TFM_FLOAT_ABI=0>
        $<$<BOOL:${CONFIG_TFM_LAZY_STACKING}>:CONFIG_TFM_LAZY_STACKING>
        $<$<BOOL:${CONFIG_TFM_DISABLE_CP10CP11}>:CONFIG_TFM_DISABLE_CP10CP11>
        $<$<BOOL:${CONFIG_TFM_ENABLE_CP10CP11}>:CONFIG_TFM_ENABLE_CP10CP11>
        $<$<BOOL:${PLATFORM_DEFAULT_CRYPTO_KEYS}>:PLATFORM_DEFAULT_CRYPTO_KEYS>
        $<$<BOOL:${PLATFORM_DEFAULT_OTP}>:PLATFORM_DEFAULT_OTP>
        $<$<BOOL:${PLATFORM_DEFAULT_ROTPK}>:PLATFORM_DEFAULT_ROTPK>
        $<$<BOOL:${PLATFORM_DEFAULT_NV_COUNTERS}>:PLATFORM_DEFAULT_NV_COUNTERS>
        $<$<AND:$<BOOL:${TFM_LOG_FATAL_ERRORS}>,$<NOT:$<STREQUAL:${TFM_SPM_LOG_LEVEL},"LOG_LEVEL_NONE">>>:LOG_FATAL_ERRORS>
        $<$<AND:$<BOOL:${TFM_LOG_NONFATAL_ERRORS}>,$<NOT:$<STREQUAL:${TFM_SPM_LOG_LEVEL},"LOG_LEVEL_NONE">>>:LOG_NONFATAL_ERRORS>
    PRIVATE
        $<$<BOOL:${SYMMETRIC_INITIAL_ATTESTATION}>:SYMMETRIC_INITIAL_ATTESTATION>
        $<$<BOOL:${TFM_DUMMY_PROVISIONING}>:TFM_DUMMY_PROVISIONING>
        $<$<BOOL:${PLATFORM_DEFAULT_OTP_WRITEABLE}>:OTP_WRITEABLE>
)

target_compile_options(platform_s
    PUBLIC
        ${COMPILER_CP_FLAG}
        $<$<BOOL:${TFM_SANITIZE}>:-fsanitize=${TFM_SANITIZE}>
)

#========================= Platform Crypto Keys ===============================#


if(TFM_PARTITION_CRYPTO)
    target_sources(platform_crypto_keys
        PRIVATE
            $<$<BOOL:${PLATFORM_DEFAULT_CRYPTO_KEYS}>:ext/common/template/crypto_keys.c>
    )

    target_link_libraries(platform_crypto_keys
        PRIVATE
            crypto_service_mbedcrypto
            tfm_psa_rot_partition_crypto
            platform_region_defs
            tfm_config
    )

    target_include_directories(platform_crypto_keys
        PRIVATE
            $<$<BOOL:${PLATFORM_DEFAULT_CRYPTO_KEYS}>:${CMAKE_SOURCE_DIR}/interface/include/crypto_keys>
            ${CMAKE_BINARY_DIR}/generated/interface/include
    )

    target_compile_definitions(platform_crypto_keys
        PRIVATE
            $<$<BOOL:${SYMMETRIC_INITIAL_ATTESTATION}>:SYMMETRIC_INITIAL_ATTESTATION>
            $<$<BOOL:${PLATFORM_DEFAULT_OTP}>:PLATFORM_DEFAULT_OTP>
            $<$<BOOL:${TEST_S_ATTESTATION}>:TEST_S_ATTESTATION>
            $<$<BOOL:${TEST_NS_ATTESTATION}>:TEST_NS_ATTESTATION>
    )

    target_compile_options(platform_crypto_keys
        PUBLIC
            ${COMPILER_CP_FLAG}
    )
endif()

#========================= Platform BL2 =======================================#
if(BL2)
    #TODO import policy
    target_include_directories(platform_bl2
        PUBLIC
            $<$<BOOL:${CRYPTO_HW_ACCELERATOR}>:${CMAKE_CURRENT_SOURCE_DIR}/ext/accelerator/interface>
            ${MCUBOOT_PATH}/boot/bootutil/include
            ${CMAKE_SOURCE_DIR}/bl2/ext/mcuboot/include
    )

    target_sources(platform_bl2
        PRIVATE
            ext/common/boot_hal_bl2.c
            $<$<BOOL:${PLATFORM_DEFAULT_UART_STDOUT}>:${CMAKE_CURRENT_SOURCE_DIR}/ext/common/uart_stdout.c>
            $<$<BOOL:${PLATFORM_DEFAULT_NV_COUNTERS}>:ext/common/template/nv_counters.c>
            $<$<BOOL:${PLATFORM_DEFAULT_ROTPK}>:ext/common/template/tfm_rotpk.c>
            $<$<OR:$<BOOL:${PLATFORM_DEFAULT_NV_COUNTERS}>,$<BOOL:${PLATFORM_DEFAULT_OTP}>>:ext/common/template/flash_otp_nv_counters_backend.c>
            $<$<BOOL:${PLATFORM_DEFAULT_OTP}>:ext/common/template/otp_flash.c>
            $<$<BOOL:${PLATFORM_DEFAULT_SHARED_MEASUREMENT_DATA}>:ext/common/template/tfm_shared_measurement_data.c>
            $<$<BOOL:${BL2_SANITIZE}>:ext/common/tfm_sanitize_handlers.c>
            ./ext/common/tfm_fatal_error.c
            ./ext/common/tfm_assert.c
    )

    target_link_libraries(platform_bl2
        PUBLIC
            platform_common_interface
            platform_region_defs
            cmsis_stack_override
            cmsis
            tfm_log_headers
        PRIVATE
            bl2_crypto
            bl2_hal
            tfm_log
            tfm_vprintf
            mcuboot_config
            $<$<AND:$<BOOL:${CONFIG_TFM_BOOT_STORE_MEASUREMENTS}>,$<NOT:$<BOOL:${CONFIG_TFM_BOOT_STORE_ENCODED_MEASUREMENTS}>>>:tfm_boot_status>
    )

    target_compile_definitions(platform_bl2
        PUBLIC
            BL2
            MCUBOOT_${MCUBOOT_UPGRADE_STRATEGY}
            $<$<BOOL:${MCUBOOT_DIRECT_XIP_REVERT}>:MCUBOOT_DIRECT_XIP_REVERT>
            $<$<BOOL:${SYMMETRIC_INITIAL_ATTESTATION}>:SYMMETRIC_INITIAL_ATTESTATION>
            MCUBOOT_FIH_PROFILE_${MCUBOOT_FIH_PROFILE}
            $<$<BOOL:${PLATFORM_DEFAULT_OTP}>:PLATFORM_DEFAULT_OTP>
            $<$<BOOL:${OTP_NV_COUNTERS_RAM_EMULATION}>:OTP_NV_COUNTERS_RAM_EMULATION=1>
            $<$<BOOL:${TFM_DUMMY_PROVISIONING}>:TFM_DUMMY_PROVISIONING>
            $<$<BOOL:${PLATFORM_DEFAULT_NV_COUNTERS}>:PLATFORM_DEFAULT_NV_COUNTERS>
            $<$<BOOL:${PLATFORM_DEFAULT_OTP_WRITEABLE}>:OTP_WRITEABLE>
            $<$<BOOL:${PLATFORM_DEFAULT_ROTPK}>:PLATFORM_DEFAULT_ROTPK>
            $<$<AND:$<BOOL:${CONFIG_TFM_BOOT_STORE_MEASUREMENTS}>,$<NOT:$<BOOL:${CONFIG_TFM_BOOT_STORE_ENCODED_MEASUREMENTS}>>>:TFM_MEASURED_BOOT_API>
            $<$<AND:$<BOOL:${TFM_LOG_FATAL_ERRORS}>,$<NOT:$<STREQUAL:${TFM_BL2_LOG_LEVEL},"LOG_LEVEL_NONE">>>:LOG_FATAL_ERRORS>
            $<$<AND:$<BOOL:${TFM_LOG_FATAL_ERRORS}>,$<NOT:$<STREQUAL:${TFM_BL2_LOG_LEVEL},"LOG_LEVEL_NONE">>>:LOG_NONFATAL_ERRORS>
            LOG_LEVEL=${TFM_BL2_LOG_LEVEL}
    )

    target_compile_options(platform_bl2
        PUBLIC
            ${BL2_COMPILER_CP_FLAG}
            $<$<BOOL:${BL2_SANITIZE}>:-fsanitize=${BL2_SANITIZE}>
    )

    # If BL2 uses builtin keys, then it requires to access platform
    # related functionalities from the platform_bl2 to retrieve keys
    target_link_libraries(bl2_crypto
        PRIVATE
            $<$<BOOL:${MCUBOOT_BUILTIN_KEY}>:platform_bl2>
    )
endif()

#========================= Platform BL1_1 =====================================#

if(BL1 AND PLATFORM_DEFAULT_BL1)
    target_include_directories(platform_bl1_1_interface
        INTERFACE
            .
            include
    )

    target_link_libraries(platform_bl1_1_interface
        INTERFACE
            platform_region_defs
            platform_common_interface
            cmsis_stack_override
            cmsis
    )

    target_compile_definitions(platform_bl1_1_interface
        INTERFACE
            $<$<BOOL:${CRYPTO_HW_ACCELERATOR}>:CRYPTO_HW_ACCELERATOR>
            LOG_LEVEL=${TFM_BL1_LOG_LEVEL}
            $<$<BOOL:${PLATFORM_DEFAULT_OTP}>:PLATFORM_DEFAULT_OTP>
            $<$<BOOL:${OTP_NV_COUNTERS_RAM_EMULATION}>:OTP_NV_COUNTERS_RAM_EMULATION=1>
            $<$<BOOL:${TFM_DUMMY_PROVISIONING}>:TFM_DUMMY_PROVISIONING>
            $<$<BOOL:${PLATFORM_DEFAULT_NV_COUNTERS}>:PLATFORM_DEFAULT_NV_COUNTERS>
            $<$<BOOL:${PLATFORM_DEFAULT_OTP_WRITEABLE}>:OTP_WRITEABLE>
            $<$<BOOL:${TFM_BL1_MEMORY_MAPPED_FLASH}>:TFM_BL1_MEMORY_MAPPED_FLASH>
            $<$<BOOL:${TFM_BL1_2_IN_OTP}>:TFM_BL1_2_IN_OTP>
            $<$<AND:$<BOOL:${CONFIG_TFM_BOOT_STORE_MEASUREMENTS}>,$<NOT:$<BOOL:${CONFIG_TFM_BOOT_STORE_ENCODED_MEASUREMENTS}>>>:TFM_MEASURED_BOOT_API>
            $<$<AND:$<BOOL:${TFM_LOG_FATAL_ERRORS}>,$<NOT:$<STREQUAL:${TFM_BL1_LOG_LEVEL},"LOG_LEVEL_NONE">>>:LOG_FATAL_ERRORS>
            $<$<AND:$<BOOL:${TFM_LOG_NONFATAL_ERRORS}>,$<NOT:$<STREQUAL:${TFM_BL1_LOG_LEVEL},"LOG_LEVEL_NONE">>>:LOG_NONFATAL_ERRORS>
            $<$<BOOL:${TFM_BL1_EMBED_ROTPK_IN_IMAGE}>:TFM_BL1_EMBED_ROTPK_IN_IMAGE>
            $<$<BOOL:${TFM_BL1_MAX_SIGNERS}>:TFM_BL1_MAX_SIGNERS=${TFM_BL1_MAX_SIGNERS}>
    )

    target_compile_options(platform_bl1_1
        PUBLIC
            $<$<BOOL:${BL1_1_SANITIZE}>:-fsanitize=${BL1_1_SANITIZE}>
            ${BL1_COMPILER_CP_FLAG}
    )

    target_link_options(platform_bl1_1
        PUBLIC
            ${BL1_LINKER_CP_OPTION}
    )

    target_sources(platform_bl1_1
        PRIVATE
            ext/common/boot_hal_bl1_1.c
            ext/common/uart_stdout.c
            $<$<BOOL:${PLATFORM_DEFAULT_OTP}>:ext/common/template/flash_otp_nv_counters_backend.c>
            $<$<BOOL:${PLATFORM_DEFAULT_OTP}>:ext/common/template/otp_flash.c>
            $<$<BOOL:${PLATFORM_DEFAULT_SHARED_MEASUREMENT_DATA}>:ext/common/template/tfm_shared_measurement_data.c>
            $<$<OR:$<BOOL:${BL1_1_SANITIZE}>,$<BOOL:${TFM_BL1_2_SANITIZE}>>:ext/common/tfm_sanitize_handlers.c>
            ./ext/common/tfm_fatal_error.c
            ./ext/common/tfm_assert.c
    )

    target_link_libraries(platform_bl1_1
        PUBLIC
            platform_bl1_1_interface
            bl1_1_shared_lib_interface
            platform_region_defs
        PRIVATE
            tfm_fih
            tfm_log
            tfm_vprintf
            tfm_fih_headers
            tfm_boot_status
    )
endif()

#========================= Platform BL1_2 =====================================#

if(BL1 AND PLATFORM_DEFAULT_BL1)
    target_include_directories(platform_bl1_2
        PRIVATE
            .
            include
            ext/driver
    )

    target_link_libraries(platform_bl1_2
        INTERFACE
            platform_region_defs
            platform_common_interface
            cmsis_stack_override
            cmsis
    )

    target_compile_definitions(platform_bl1_2
        INTERFACE
            $<$<BOOL:${CRYPTO_HW_ACCELERATOR}>:CRYPTO_HW_ACCELERATOR>
            $<$<BOOL:${PLATFORM_DEFAULT_OTP}>:PLATFORM_DEFAULT_OTP>
            $<$<BOOL:${OTP_NV_COUNTERS_RAM_EMULATION}>:OTP_NV_COUNTERS_RAM_EMULATION=1>
            $<$<BOOL:${TFM_DUMMY_PROVISIONING}>:TFM_DUMMY_PROVISIONING>
            $<$<BOOL:${PLATFORM_DEFAULT_NV_COUNTERS}>:PLATFORM_DEFAULT_NV_COUNTERS>
            $<$<BOOL:${PLATFORM_DEFAULT_OTP_WRITEABLE}>:OTP_WRITEABLE>
            $<$<BOOL:${TFM_BL1_MEMORY_MAPPED_FLASH}>:TFM_BL1_MEMORY_MAPPED_FLASH>
            $<$<BOOL:${TFM_BL1_2_IN_OTP}>:TFM_BL1_2_IN_OTP>
            $<$<AND:$<BOOL:${CONFIG_TFM_BOOT_STORE_MEASUREMENTS}>,$<NOT:$<BOOL:${CONFIG_TFM_BOOT_STORE_ENCODED_MEASUREMENTS}>>>:TFM_MEASURED_BOOT_API>
            $<$<AND:$<BOOL:${TFM_LOG_FATAL_ERRORS}>,$<NOT:$<STREQUAL:${TFM_BL1_LOG_LEVEL},"LOG_LEVEL_NONE">>>:LOG_FATAL_ERRORS>
            $<$<AND:$<BOOL:${TFM_LOG_NONFATAL_ERRORS}>,$<NOT:$<STREQUAL:${TFM_BL1_LOG_LEVEL},"LOG_LEVEL_NONE">>>:LOG_NONFATAL_ERRORS>
    )

    target_sources(platform_bl1_2
        PRIVATE
            ext/common/boot_hal_bl1_2.c
            $<$<BOOL:${PLATFORM_DEFAULT_NV_COUNTERS}>:ext/common/template/nv_counters.c>
            $<$<OR:$<BOOL:${PLATFORM_DEFAULT_NV_COUNTERS}>,$<BOOL:${PLATFORM_DEFAULT_OTP}>>:ext/common/template/flash_otp_nv_counters_backend.c>
            $<$<BOOL:${PLATFORM_DEFAULT_OTP}>:ext/common/template/otp_flash.c>
            $<$<BOOL:${PLATFORM_DEFAULT_SHARED_MEASUREMENT_DATA}>:ext/common/template/tfm_shared_measurement_data.c>
    )

    target_link_libraries(platform_bl1_2
        PUBLIC
            platform_bl1_1_interface
        PRIVATE
            tfm_fih
            tfm_fih_headers
            tfm_log
            tfm_vprintf
            tfm_boot_status
            platform_region_defs
            bl1_1_shared_lib_interface
    )

    target_compile_options(platform_bl1_2
        PUBLIC
            $<$<BOOL:${BL1_2_SANITIZE}>:-fsanitize=${BL1_2_SANITIZE}>
            ${BL1_COMPILER_CP_FLAG}
    )

    target_link_options(platform_bl1_2
        PUBLIC
            ${BL1_LINKER_CP_OPTION}
    )
endif()

#========================= Platform region defs ===============================#

if(NOT ${MCUBOOT_SIGNATURE_TYPE} STREQUAL "")
    string(REGEX MATCH "[0-9]*$" SIG_LEN ${MCUBOOT_SIGNATURE_TYPE})
    string(REGEX MATCH "^[A-Z]*" SIG_TYPE ${MCUBOOT_SIGNATURE_TYPE})
endif()

#TODO maybe just link the other platforms to this
target_compile_definitions(platform_region_defs
    INTERFACE
        $<$<BOOL:${BL1}>:BL1>
        $<$<BOOL:${BL2}>:BL2>
        BL2_HEADER_SIZE=${BL2_HEADER_SIZE}
        BL2_TRAILER_SIZE=${BL2_TRAILER_SIZE}
        $<$<BOOL:${PLATFORM_DEFAULT_BL1}>:PLATFORM_DEFAULT_BL1>
        $<$<BOOL:${SECURE_UART1}>:SECURE_UART1>
        DAUTH_${DEBUG_AUTHENTICATION}
        $<$<BOOL:${MCUBOOT_IMAGE_NUMBER}>:MCUBOOT_IMAGE_NUMBER=${MCUBOOT_IMAGE_NUMBER}>
        $<$<BOOL:${MCUBOOT_BUILTIN_KEY}>:MCUBOOT_BUILTIN_KEY>
        $<$<STREQUAL:${SIG_TYPE},RSA>:MCUBOOT_SIGN_RSA>
        $<$<STREQUAL:${SIG_TYPE},RSA>:MCUBOOT_SIGN_RSA_LEN=${SIG_LEN}>
        $<$<STREQUAL:${SIG_TYPE},EC>:MCUBOOT_SIGN_EC${SIG_LEN}>
        $<$<STREQUAL:${MCUBOOT_EXECUTION_SLOT},2>:LINK_TO_SECONDARY_PARTITION>
        $<$<BOOL:${TEST_PSA_API}>:PSA_API_TEST_${TEST_PSA_API}>
        $<$<BOOL:${TFM_CODE_SHARING}>:CODE_SHARING>
        $<$<OR:$<CONFIG:Debug>,$<CONFIG:relwithdebinfo>>:ENABLE_HEAP>
        PLATFORM_NS_NV_COUNTERS=${TFM_NS_NV_COUNTER_AMOUNT}
        $<$<BOOL:${TFM_HALT_ON_FATAL_ERRORS}>:HALT_ON_FATAL_ERROR>
        $<$<BOOL:${TFM_LOG_ERR_FILE_AND_LINE}>:FATAL_ERR_LOG_FILE_AND_LINE>
        $<$<BOOL:${PLATFORM_DEFAULT_BL1_TEST_EXECUTION}>:PLATFORM_DEFAULT_BL1_TEST_EXECUTION>
        $<$<BOOL:${PLATFORM_DEFAULT_BL1_1_TESTS}>:PLATFORM_DEFAULT_BL1_1_TESTS>
        $<$<BOOL:${PLATFORM_DEFAULT_BL1_2_TESTS}>:PLATFORM_DEFAULT_BL1_2_TESTS>
        $<$<BOOL:${TFM_BL1_2_IMAGE_ENCRYPTION}>:TFM_BL1_2_IMAGE_ENCRYPTION>
        $<$<BOOL:${TFM_BL1_2_EMBED_ROTPK_IN_IMAGE}>:TFM_BL1_2_EMBED_ROTPK_IN_IMAGE>
        $<$<BOOL:${TFM_BL1_2_IMAGE_ENCRYPTION}>:TFM_BL1_2_IMAGE_ENCRYPTION>
        $<$<BOOL:${TFM_BL1_2_SIGNER_AMOUNT}>:TFM_BL1_2_SIGNER_AMOUNT=${TFM_BL1_2_SIGNER_AMOUNT}>
        $<$<BOOL:${TFM_BL1_2_ECDSA_CURVE}>:TFM_BL1_2_ECDSA_CURVE=TFM_BL1_CURVE_${TFM_BL1_2_ECDSA_CURVE}>
        $<$<BOOL:${TFM_BL1_2_MEASUREMENT_HASH_ALG}>:TFM_BL1_2_MEASUREMENT_HASH_ALG=TFM_BL1_HASH_ALG_${TFM_BL1_2_MEASUREMENT_HASH_ALG}>
        $<$<BOOL:${TFM_BL1_2_MEASUREMENT_HASH_ALG}>:TFM_BL1_ENABLE_${TFM_BL1_2_ROTPK_HASH_ALG}>
        $<$<BOOL:${TFM_BL1_2_ROTPK_HASH_ALG}>:TFM_BL1_ENABLE_${TFM_BL1_2_ROTPK_HASH_ALG}>
        $<$<BOOL:${TFM_BL1_2_ROTPK_HASH_ALG}>:TFM_BL1_2_ROTPK_HASH_ALG=RSE_ROTPK_HASH_ALG_${TFM_BL1_2_ROTPK_HASH_ALG}>
        $<$<BOOL:${MCUBOOT_ROTPK_HASH_ALG}>:MCUBOOT_ROTPK_HASH_ALG=RSE_ROTPK_HASH_ALG_${MCUBOOT_ROTPK_HASH_ALG}>
        $<$<BOOL:${TFM_BL1_1_MEASUREMENT_HASH_ALG}>:TFM_BL1_1_MEASUREMENT_HASH_ALG=TFM_BL1_HASH_ALG_${TFM_BL1_1_MEASUREMENT_HASH_ALG}>
        $<$<BOOL:${TFM_BL1_1_MEASUREMENT_HASH_ALG}>:TFM_BL1_ENABLE_${TFM_BL1_1_ROTPK_HASH_ALG}>
        $<$<BOOL:${MCUBOOT_HW_KEY}>:MCUBOOT_HW_KEY>
)

target_include_directories(platform_region_defs
    INTERFACE
        ${CMAKE_CURRENT_LIST_DIR}/ext/common
        $<$<BOOL:${BL1}>:${BL1_1_CONFIG_DIR}>
        $<$<BOOL:${BL1}>:${BL1_2_CONFIG_DIR}>
)

target_link_libraries(platform_region_defs
    INTERFACE
        tfm_config
)
