#-------------------------------------------------------------------------------
# Copyright (c) 2020-2024, Arm Limited. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

cmake_minimum_required(VERSION 3.21)

project("Bootloader" VERSION 0.1.0 LANGUAGES C ASM)

add_executable(bl2
    src/flash_map.c
    $<$<BOOL:${DEFAULT_MCUBOOT_SECURITY_COUNTERS}>:src/security_cnt.c>
    $<$<BOOL:${DEFAULT_MCUBOOT_FLASH_MAP}>:src/default_flash_map.c>
    $<$<BOOL:${MCUBOOT_DATA_SHARING}>:src/shared_data.c>
    $<$<BOOL:${PLATFORM_DEFAULT_PROVISIONING}>:src/provisioning.c>
    $<$<BOOL:${MCUBOOT_USE_PSA_CRYPTO}>:src/thin_psa_crypto_core.c>
    $<$<BOOL:${CONFIG_GNU_SYSCALL_STUB_ENABLED}>:${CMAKE_SOURCE_DIR}/platform/ext/common/syscalls_stub.c>
)

add_subdirectory(ext/mcuboot)

set_target_properties(bl2
    PROPERTIES
        SUFFIX ".axf"
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
        ADDITIONAL_CLEAN_FILES "${CMAKE_BINARY_DIR}/generated;${CMAKE_BINARY_DIR}/bin/bl2.map"
)

target_include_directories(bl2
    PRIVATE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<BUILD_INTERFACE:${MCUBOOT_PATH}/boot/bootutil/src>
)

target_link_libraries(bl2
    PRIVATE
        tfm_boot_status
        $<$<BOOL:${TEST_BL2}>:mcuboot_tests>
        platform_bl2
)

target_compile_options(bl2
    PRIVATE
        ${BL2_COMPILER_CP_FLAG}
)

target_link_options(bl2
    PRIVATE
        $<$<C_COMPILER_ID:GNU>:-Wl,-Map=${CMAKE_BINARY_DIR}/bin/bl2.map>
        $<$<C_COMPILER_ID:ARMClang>:--map>
        $<$<C_COMPILER_ID:IAR>:--map\;${CMAKE_BINARY_DIR}/bin/bl2.map>
        ${BL2_LINKER_CP_OPTION}
)

target_compile_definitions(bl2
    PRIVATE
        $<$<BOOL:${DEFAULT_MCUBOOT_FLASH_MAP}>:DEFAULT_MCUBOOT_FLASH_MAP>
        $<$<BOOL:${PLATFORM_PSA_ADAC_SECURE_DEBUG}>:PLATFORM_PSA_ADAC_SECURE_DEBUG>
        $<$<BOOL:${TEST_BL2}>:TEST_BL2>
        $<$<BOOL:${TFM_PARTITION_FIRMWARE_UPDATE}>:TFM_PARTITION_FIRMWARE_UPDATE>
        $<$<AND:$<BOOL:${CONFIG_TFM_BOOT_STORE_MEASUREMENTS}>,$<NOT:$<BOOL:${CONFIG_TFM_BOOT_STORE_ENCODED_MEASUREMENTS}>>>:TFM_MEASURED_BOOT_API>
)

add_convert_to_bin_target(bl2)

############################### BOOT HAL # #####################################

add_library(bl2_hal INTERFACE)

target_include_directories(bl2_hal
    INTERFACE
        include
)

############################### MBEDCRYPTO #####################################

add_library(bl2_mbedcrypto_config INTERFACE)

if(NOT ${MCUBOOT_SIGNATURE_TYPE} STREQUAL "")
    string(REGEX MATCH "[0-9]*$" SIG_LEN ${MCUBOOT_SIGNATURE_TYPE})
    string(REGEX MATCH "^[A-Z]*" SIG_TYPE ${MCUBOOT_SIGNATURE_TYPE})
endif()

# FixMe: The MBEDTLS_CONFIG_FILE and MBEDTLS_PSA_CRYPTO_CONFIG_FILE should be
# put in a dedicated target that can be linked by other targets, for example
# bl2 provisioning related targets, to be able to include correctly psa/crypto.h
target_compile_definitions(bl2_mbedcrypto_config
    INTERFACE
        $<$<STREQUAL:${SIG_TYPE},RSA>:MCUBOOT_SIGN_RSA>
        $<$<STREQUAL:${SIG_TYPE},RSA>:MCUBOOT_SIGN_RSA_LEN=${SIG_LEN}>
        $<$<BOOL:${MCUBOOT_USE_PSA_CRYPTO}>:MCUBOOT_USE_PSA_CRYPTO>
        $<$<BOOL:${MCUBOOT_BUILTIN_KEY}>:MCUBOOT_BUILTIN_KEY>
        $<$<STREQUAL:${SIG_TYPE},EC>:MCUBOOT_SIGN_EC${SIG_LEN}>
        MBEDTLS_CONFIG_FILE="${MCUBOOT_MBEDCRYPTO_CONFIG_FILEPATH}"
        MBEDTLS_PSA_CRYPTO_CONFIG_FILE="${MCUBOOT_PSA_CRYPTO_CONFIG_FILEPATH}"
        $<$<BOOL:${CC312_LEGACY_DRIVER_API_ENABLED}>:CC312_LEGACY_DRIVER_API_ENABLED>
        # Specific option required on thin_psa_crypto_core.c
        $<$<BOOL:${MCUBOOT_BUILTIN_KEY}>:BLX_BUILTIN_KEY_LOADER>
)

set(CMAKE_POLICY_DEFAULT_CMP0077 NEW)
set(CMAKE_POLICY_DEFAULT_CMP0048 NEW)
set(ENABLE_TESTING OFF)
set(ENABLE_PROGRAMS OFF)
set(MBEDTLS_FATAL_WARNINGS OFF)
set(ENABLE_DOCS OFF)
set(INSTALL_MBEDTLS_HEADERS OFF)
set(LIB_INSTALL_DIR ${CMAKE_CURRENT_BINARY_DIR}/mbedcrypto/install)
set(GEN_FILES OFF)

# Set the prefix to be used by mbedTLS targets
set(MBEDTLS_TARGET_PREFIX bl2_)

# Mbedcrypto in Debug builds uses too much memory. As a compromise, if `Debug` build type
# is selected mbedcrypto will build under `RelWithDebInfo` which preserves debug
# symbols while optimizing space.
set(SAVED_BUILD_TYPE ${CMAKE_BUILD_TYPE})
set(CMAKE_BUILD_TYPE ${MBEDCRYPTO_BUILD_TYPE})
add_subdirectory(${MBEDCRYPTO_PATH} ${CMAKE_CURRENT_BINARY_DIR}/mbedcrypto EXCLUDE_FROM_ALL)
set(CMAKE_BUILD_TYPE ${SAVED_BUILD_TYPE})

if(NOT TARGET ${MBEDTLS_TARGET_PREFIX}mbedcrypto)
    message(FATAL_ERROR "Target ${MBEDTLS_TARGET_PREFIX}mbedcrypto does not exist. Have the patches in ${CMAKE_SOURCE_DIR}/lib/ext/mbedcrypto been applied to the mbedcrypto repo at ${MBEDCRYPTO_PATH} ?
    Hint: The command might be `cd ${MBEDCRYPTO_PATH} && git apply ${CMAKE_SOURCE_DIR}/lib/ext/mbedcrypto/*.patch`")
endif()

target_link_libraries(${MBEDTLS_TARGET_PREFIX}mbedcrypto
    PUBLIC
        bl2_mbedcrypto_config
)

target_link_libraries(${MBEDTLS_TARGET_PREFIX}p256m
    PUBLIC
        ${MBEDTLS_TARGET_PREFIX}mbedcrypto
)

target_include_directories(${MBEDTLS_TARGET_PREFIX}mbedcrypto
    PUBLIC
        ${MBEDCRYPTO_PATH}/library
)

target_compile_options(${MBEDTLS_TARGET_PREFIX}mbedcrypto
    PRIVATE
        ${BL2_COMPILER_CP_FLAG}
)

target_compile_options(${MBEDTLS_TARGET_PREFIX}p256m
    PRIVATE
        ${BL2_COMPILER_CP_FLAG}
)

############################### CODE SHARING ###################################

if (TFM_CODE_SHARING)
    target_share_symbols(bl2 ${CMAKE_CURRENT_SOURCE_DIR}/bl2_shared_symbols.txt)

    if (NOT EXISTS ${MBEDCRYPTO_PATH}/library/code_share.c)
        message(FATAL_ERROR "File ${MBEDCRYPTO_PATH}/library/code_share.c does not exist.
        Have the patch ${CMAKE_SOURCE_DIR}/lib/ext/mbedcrypto/0002-Enable-crypto-code-sharing-between-independent-binar.patch
        been applied to the mbedcrypto repo at ${MBEDCRYPTO_PATH}?
        Hint: The command might be `cd ${MBEDCRYPTO_PATH} && git apply ${CMAKE_SOURCE_DIR}/lib/ext/mbedcrypto/*.patch`")
    endif()
endif()
