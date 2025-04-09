#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

cmake_minimum_required(VERSION 3.21)

find_package(Python3)

project("Bootloader" VERSION 0.1.0 LANGUAGES C ASM)

############################### BL2_CRYPTO_CONFIG ##############################

if(NOT ${MCUBOOT_SIGNATURE_TYPE} STREQUAL "")
    string(REGEX MATCH "[0-9]*$" SIG_LEN ${MCUBOOT_SIGNATURE_TYPE})
    string(REGEX MATCH "^[A-Z]*" SIG_TYPE ${MCUBOOT_SIGNATURE_TYPE})
endif()

set(is_ec_signature  "$<STREQUAL:${SIG_TYPE},EC>")
set(is_rsa_signature "$<STREQUAL:${SIG_TYPE},RSA>")

add_library(bl2_crypto_config INTERFACE)

target_compile_definitions(bl2_crypto_config
    INTERFACE
        MBEDTLS_CONFIG_FILE="${MCUBOOT_MBEDCRYPTO_CONFIG_FILEPATH}"
        MBEDTLS_PSA_CRYPTO_CONFIG_FILE="${MCUBOOT_PSA_CRYPTO_CONFIG_FILEPATH}"
        # The config files have conditional includes based on these four definitions
        $<${is_rsa_signature}:MCUBOOT_SIGN_RSA>
        $<${is_rsa_signature}:MCUBOOT_SIGN_RSA_LEN=${SIG_LEN}>
        $<${is_ec_signature}:MCUBOOT_SIGN_EC${SIG_LEN}>
        $<$<BOOL:${MCUBOOT_USE_PSA_CRYPTO}>:MCUBOOT_USE_PSA_CRYPTO>
)

target_include_directories(bl2_crypto_config
    INTERFACE
        ${CMAKE_SOURCE_DIR}/interface/include
)

# Check if the p256m driver is enabled in the config file, as that will require
# to build some 3rd party specific source code in addition to Mbed TLS source.
# Note that 0 means SUCCESS here, 1 means FAILURE
set(MBEDTLS_P256M_NOT_FOUND 1)
execute_process(COMMAND
    ${Python3_EXECUTABLE}
    ${MBEDCRYPTO_PATH}/scripts/config.py -f "${MCUBOOT_MBEDCRYPTO_CONFIG_FILEPATH}" get MBEDTLS_PSA_P256M_DRIVER_ENABLED
    RESULT_VARIABLE MBEDTLS_P256M_NOT_FOUND)

# If the enablement is conditional, the script would still mark it as found
if (${MBEDTLS_P256M_NOT_FOUND} EQUAL 0)
    set(MBEDTLS_P256M_ENABLED true)
else()
    set(MBEDTLS_P256M_ENABLED false)
endif()

############################### BL2_CRYPTO #####################################

set(is_384_bit_curve "$<STREQUAL:${SIG_LEN},384>")
set(is_256_bit_curve "$<STREQUAL:${SIG_LEN},256>")
set(build_sha_384    "$<AND:${is_ec_signature},${is_384_bit_curve}>")
set(build_sha_256    "$<NOT:${build_sha_384}>")
set(build_p256m      "$<IF:$<BOOL:${MBEDTLS_P256M_ENABLED}>,$<AND:${is_ec_signature},${is_256_bit_curve}>,0>")

list(APPEND BL2_CRYPTO_SRC
    $<$<BOOL:${MCUBOOT_USE_PSA_CRYPTO}>:src/thin_psa_crypto_core.c>
    ${MBEDCRYPTO_PATH}/library/platform.c
    ${MBEDCRYPTO_PATH}/library/platform_util.c
    ${MBEDCRYPTO_PATH}/library/memory_buffer_alloc.c
    ${MBEDCRYPTO_PATH}/library/psa_crypto_hash.c
    $<${build_sha_256}:${MBEDCRYPTO_PATH}/library/sha256.c>
    $<${build_sha_384}:${MBEDCRYPTO_PATH}/library/sha512.c>
    $<$<AND:${is_ec_signature},$<NOT:${build_p256m}>>:${MBEDCRYPTO_PATH}/library/psa_crypto_ecp.c>
    $<$<AND:${is_ec_signature},$<NOT:${build_p256m}>>:${MBEDCRYPTO_PATH}/library/ecp.c>
    $<$<AND:${is_ec_signature},$<NOT:${build_p256m}>>:${MBEDCRYPTO_PATH}/library/ecp_curves.c>
    $<$<AND:${is_ec_signature},$<NOT:${build_p256m}>>:${MBEDCRYPTO_PATH}/library/ecdsa.c>
    $<$<AND:${is_ec_signature},$<NOT:${build_p256m}>>:${MBEDCRYPTO_PATH}/library/bignum.c>
    $<$<AND:${is_ec_signature},$<NOT:${build_p256m}>>:${MBEDCRYPTO_PATH}/library/bignum_core.c>
    $<$<AND:${is_ec_signature},$<NOT:${build_p256m}>>:${MBEDCRYPTO_PATH}/library/constant_time.c>
    $<${is_rsa_signature}:${MBEDCRYPTO_PATH}/library/psa_crypto_rsa.c>
    $<${is_rsa_signature}:${MBEDCRYPTO_PATH}/library/rsa.c>
    $<${is_rsa_signature}:${MBEDCRYPTO_PATH}/library/rsa_alt_helpers.c>
    $<${is_rsa_signature}:${MBEDCRYPTO_PATH}/library/bignum.c>
    $<${is_rsa_signature}:${MBEDCRYPTO_PATH}/library/bignum_core.c>
    $<${is_rsa_signature}:${MBEDCRYPTO_PATH}/library/constant_time.c>
    $<${is_rsa_signature}:${MBEDCRYPTO_PATH}/library/asn1parse.c>
    $<${is_rsa_signature}:${MBEDCRYPTO_PATH}/library/asn1write.c>
    $<${is_rsa_signature}:${MBEDCRYPTO_PATH}/library/md.c>
    $<$<AND:${is_ec_signature},${build_p256m}>:${MBEDCRYPTO_PATH}/3rdparty/p256-m/p256-m_driver_entrypoints.c>
    $<$<AND:${is_ec_signature},${build_p256m}>:${MBEDCRYPTO_PATH}/3rdparty/p256-m/p256-m/p256-m.c>
    ${MBEDCRYPTO_PATH}/library/aes.c
)

add_library(bl2_crypto STATIC ${BL2_CRYPTO_SRC})

target_include_directories(bl2_crypto
    PUBLIC
        ${MBEDCRYPTO_PATH}/library
)

target_compile_options(bl2_crypto
    PRIVATE
        ${BL2_COMPILER_CP_FLAG}
)

target_link_libraries(bl2_crypto
    PUBLIC
        bl2_crypto_config
)

string(TOLOWER "${CMAKE_BUILD_TYPE}" BUILD_TYPE_LOWER)
# IAR only allows 1 optimization option for the compilation unit
if (${BUILD_TYPE_LOWER} STREQUAL "debug" AND NOT ${CMAKE_C_COMPILER_ID} STREQUAL "IAR")
    set_source_files_properties(${BL2_CRYPTO_SRC}
        PROPERTIES COMPILE_FLAGS -Os
    )
endif()

############################### BL2 ############################################

add_executable(bl2
    src/flash_map.c
    src/crt_exit.c
    $<$<BOOL:${DEFAULT_MCUBOOT_SECURITY_COUNTERS}>:src/security_cnt.c>
    $<$<BOOL:${DEFAULT_MCUBOOT_FLASH_MAP}>:src/default_flash_map.c>
    $<$<BOOL:${MCUBOOT_DATA_SHARING}>:src/shared_data.c>
    $<$<BOOL:${PLATFORM_DEFAULT_PROVISIONING}>:src/provisioning.c>
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
    PUBLIC
        bl2_crypto
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
        $<$<C_COMPILER_ID:Clang>:LINKER:-Map=${CMAKE_BINARY_DIR}/bin/bl2.map>
        ${BL2_LINKER_CP_OPTION}
)

target_compile_definitions(bl2
    PRIVATE
        $<$<BOOL:${DEFAULT_MCUBOOT_FLASH_MAP}>:DEFAULT_MCUBOOT_FLASH_MAP>
        $<$<BOOL:${PLATFORM_PSA_ADAC_SECURE_DEBUG}>:PLATFORM_PSA_ADAC_SECURE_DEBUG>
        $<$<BOOL:${TEST_BL2}>:TEST_BL2>
        $<$<BOOL:${TFM_PARTITION_FIRMWARE_UPDATE}>:TFM_PARTITION_FIRMWARE_UPDATE>
        $<$<AND:$<BOOL:${CONFIG_TFM_BOOT_STORE_MEASUREMENTS}>,$<NOT:$<BOOL:${CONFIG_TFM_BOOT_STORE_ENCODED_MEASUREMENTS}>>>:TFM_MEASURED_BOOT_API>
        $<$<BOOL:${MCUBOOT_BUILTIN_KEY}>:MCUBOOT_BUILTIN_KEY>
)

add_convert_to_bin_target(bl2)

############################### BOOT HAL # #####################################

add_library(bl2_hal INTERFACE)

target_include_directories(bl2_hal
    INTERFACE
        include
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
