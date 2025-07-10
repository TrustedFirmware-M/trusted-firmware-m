#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

set(is_v8.1m    "$<STREQUAL:${TFM_SYSTEM_ARCHITECTURE},armv8.1-m.main>")
set(is_v8m_base "$<STREQUAL:${TFM_SYSTEM_ARCHITECTURE},armv8-m.base>")
set(is_v8m_main "$<STREQUAL:${TFM_SYSTEM_ARCHITECTURE},armv8-m.main>")
set(is_v8.0m    "$<OR:${is_v8m_main},${is_v8m_base}>")
set(is_v8.xm    "$<OR:${is_v8.1m},${is_v8.0m}>")

############################### PSA CRYPTO CONFIG ##############################
# Make sure these are available even if the TFM_PARTITION_CRYPTO is not defined

add_library(psa_crypto_config INTERFACE)
target_compile_definitions(psa_crypto_config
    INTERFACE
        MBEDTLS_PSA_CRYPTO_CONFIG_FILE="${TFM_MBEDCRYPTO_PSA_CRYPTO_CONFIG_PATH}"
        MBEDTLS_CONFIG_FILE="${TFM_MBEDCRYPTO_CONFIG_CLIENT_PATH}"
)
# The following is required for tfm_plat_crypto_nv_seed.h
target_include_directories(psa_crypto_config
    INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../../platform/include>
)
# This defines the configuration files for the users of the library directly
add_library(psa_crypto_library_config INTERFACE)
target_compile_definitions(psa_crypto_library_config
    INTERFACE
        MBEDTLS_PSA_CRYPTO_CONFIG_FILE="${TFM_MBEDCRYPTO_PSA_CRYPTO_CONFIG_PATH}"
        MBEDTLS_CONFIG_FILE="${TFM_MBEDCRYPTO_CONFIG_PATH}"
)

if (NOT TFM_PARTITION_CRYPTO)
    return()
endif()

find_package(Python3)

cmake_minimum_required(VERSION 3.21)

add_library(tfm_psa_rot_partition_crypto STATIC)

add_dependencies(tfm_psa_rot_partition_crypto manifest_tool)

target_sources(tfm_psa_rot_partition_crypto
    PRIVATE
        crypto_init.c
        crypto_alloc.c
        crypto_cipher.c
        crypto_hash.c
        crypto_mac.c
        crypto_aead.c
        crypto_asymmetric.c
        crypto_key_derivation.c
        crypto_key_management.c
        crypto_rng.c
        crypto_library.c
        $<$<BOOL:${CRYPTO_TFM_BUILTIN_KEYS_DRIVER}>:psa_driver_api/tfm_builtin_key_loader.c>
)

# The generated sources
target_sources(tfm_psa_rot_partition_crypto
    PRIVATE
        ${CMAKE_BINARY_DIR}/generated/secure_fw/partitions/crypto/auto_generated/intermedia_tfm_crypto.c
)

target_sources(tfm_partitions
    INTERFACE
        ${CMAKE_BINARY_DIR}/generated/secure_fw/partitions/crypto/auto_generated/load_info_tfm_crypto.c
)

# Set include directory
target_include_directories(tfm_psa_rot_partition_crypto
    PRIVATE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
        ${CMAKE_BINARY_DIR}/generated/secure_fw/partitions/crypto
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../../interface/include>
)

target_include_directories(tfm_partitions
    INTERFACE
        ${CMAKE_BINARY_DIR}/generated/secure_fw/partitions/crypto
)

# Linking to external interfaces
target_link_libraries(tfm_psa_rot_partition_crypto
    PRIVATE
        platform_s
        crypto_service_mbedcrypto
        tfm_config
        tfm_log_headers
)

target_compile_definitions(tfm_psa_rot_partition_crypto
    PRIVATE
        $<$<STREQUAL:${CRYPTO_HW_ACCELERATOR_TYPE},cc312>:CRYPTO_HW_ACCELERATOR_CC312>
)

############################ Partition Defs ####################################

target_link_libraries(tfm_partitions
    INTERFACE
        tfm_psa_rot_partition_crypto
)

target_compile_definitions(tfm_config
    INTERFACE
        TFM_PARTITION_CRYPTO
)

############################### MBEDCRYPTO #####################################
add_library(crypto_service_mbedcrypto_config INTERFACE)

target_compile_definitions(crypto_service_mbedcrypto_config
    INTERFACE
        $<$<BOOL:${TFM_MBEDCRYPTO_PLATFORM_EXTRA_CONFIG_PATH}>:MBEDTLS_USER_CONFIG_FILE="${TFM_MBEDCRYPTO_PLATFORM_EXTRA_CONFIG_PATH}">
        $<$<BOOL:${TFM_MBEDCRYPTO_PSA_CRYPTO_PLATFORM_EXTRA_CONFIG_PATH}>:MBEDTLS_PSA_CRYPTO_USER_CONFIG_FILE="${TFM_MBEDCRYPTO_PSA_CRYPTO_PLATFORM_EXTRA_CONFIG_PATH}">
        $<$<BOOL:${PLATFORM_DEFAULT_NV_SEED}>:PLATFORM_DEFAULT_NV_SEED>
        $<$<BOOL:${PLATFORM_DEFAULT_CRYPTO_KEYS}>:PLATFORM_DEFAULT_CRYPTO_KEYS>
        $<$<BOOL:${CRYPTO_TFM_BUILTIN_KEYS_DRIVER}>:PSA_CRYPTO_DRIVER_TFM_BUILTIN_KEY_LOADER>
)

target_link_libraries(crypto_service_mbedcrypto_config
    INTERFACE
        tfm_config
        psa_crypto_library_config
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
set(MBEDTLS_TARGET_PREFIX crypto_service_)

# Check if the p256m driver is enabled in the config file, as that will require a
# dedicated target to be linked in. Note that 0 means SUCCESS here, 1 means FAILURE
set(MBEDTLS_P256M_NOT_FOUND 1)
if(TFM_MBEDCRYPTO_PLATFORM_EXTRA_CONFIG_PATH)
    execute_process(COMMAND
        ${Python3_EXECUTABLE}
        ${MBEDCRYPTO_PATH}/scripts/config.py -f "${TFM_MBEDCRYPTO_CONFIG_PATH}" get MBEDTLS_PSA_P256M_DRIVER_ENABLED
        RESULT_VARIABLE MBEDTLS_P256M_NOT_FOUND)
    if (${MBEDTLS_P256M_NOT_FOUND} EQUAL 1)
        execute_process(COMMAND
            ${Python3_EXECUTABLE}
            ${MBEDCRYPTO_PATH}/scripts/config.py -f "${TFM_MBEDCRYPTO_PLATFORM_EXTRA_CONFIG_PATH}" get MBEDTLS_PSA_P256M_DRIVER_ENABLED
            RESULT_VARIABLE MBEDTLS_P256M_NOT_FOUND)
    endif()

else()
    execute_process(COMMAND
        ${Python3_EXECUTABLE}
        ${MBEDCRYPTO_PATH}/scripts/config.py -f "${TFM_MBEDCRYPTO_CONFIG_PATH}" get MBEDTLS_PSA_P256M_DRIVER_ENABLED
        RESULT_VARIABLE MBEDTLS_P256M_NOT_FOUND)
endif()

if (${MBEDTLS_P256M_NOT_FOUND} EQUAL 0)
    message(STATUS "[Crypto service] Using P256M software driver in PSA Crypto backend")
    set(MBEDTLS_P256M_ENABLED true)
else()
    set(MBEDTLS_P256M_ENABLED false)
endif()

# If the project is configured with CMAKE_BUILD_TYPE="Debug", the value of
# MBEDCRYPTO_BUILD_TYPE will be set "RelWithDebInfo" to optimize the space
# of the Debug build. If the goal is to debug Mbed TLS code itself, the
# MBEDCRYPTO_BUILD_TYPE must be set manually here
set(SAVED_BUILD_TYPE ${CMAKE_BUILD_TYPE})
set(CMAKE_BUILD_TYPE ${MBEDCRYPTO_BUILD_TYPE})
add_subdirectory(${MBEDCRYPTO_PATH} ${CMAKE_CURRENT_BINARY_DIR}/mbedcrypto EXCLUDE_FROM_ALL)
set(CMAKE_BUILD_TYPE ${SAVED_BUILD_TYPE})

if(NOT TARGET ${MBEDTLS_TARGET_PREFIX}mbedcrypto)
    message(FATAL_ERROR "[Crypto service] Target ${MBEDTLS_TARGET_PREFIX}mbedcrypto does not exist. Have the patches in ${CMAKE_SOURCE_DIR}/lib/ext/mbedcrypto been applied to the mbedcrypto repo at ${MBEDCRYPTO_PATH} ?
    Hint: The command might be `cd ${MBEDCRYPTO_PATH} && git apply ${CMAKE_SOURCE_DIR}/lib/ext/mbedcrypto/*.patch`")
endif()

target_include_directories(${MBEDTLS_TARGET_PREFIX}mbedcrypto
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/psa_driver_api
        # The following is required for psa/error.h
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../../interface/include>
)

# Fix platform_s and crypto_service_mbedcrypto libraries cyclic linking
set_target_properties(${MBEDTLS_TARGET_PREFIX}mbedcrypto PROPERTIES LINK_INTERFACE_MULTIPLICITY 3)

target_sources(${MBEDTLS_TARGET_PREFIX}mbedcrypto
    PRIVATE
        $<$<NOT:$<BOOL:${CRYPTO_HW_ACCELERATOR}>>:${CMAKE_CURRENT_SOURCE_DIR}/tfm_mbedcrypto_alt.c>
)

target_compile_options(${MBEDTLS_TARGET_PREFIX}mbedcrypto
    PRIVATE
        $<$<C_COMPILER_ID:GNU>:-Wno-unused-const-variable>
        $<$<C_COMPILER_ID:GNU>:-Wno-unused-parameter>
        $<$<C_COMPILER_ID:ARMClang>:-Wno-unused-const-variable>
        $<$<C_COMPILER_ID:ARMClang>:-Wno-unused-parameter>
        $<$<C_COMPILER_ID:Clang>:-Wno-unused-parameter>
)

if(MBEDTLS_P256M_ENABLED)
    # FixMe: The p256m CmakeLists.txt in version 3.5.0 has an issue with target
    # names and for this reason we need to force those defines at this stage
    target_compile_definitions(${MBEDTLS_TARGET_PREFIX}p256m
        PRIVATE
            MBEDTLS_PSA_P256M_DRIVER_ENABLED
            MBEDTLS_PSA_CRYPTO_SPM
            # Code is branchless but UMLAL might take a variable amount of cycles
            # depedening on inputs if ${is_v8.1m} is false. We don't aim to protect
            # against side channel so this is a acknowledged behaviour
            MUL64_IS_CONSTANT_TIME
            MULADD64_IGNORE_ASM
    )

    # The crypto_spe.h to be passed to p256m is here
    target_include_directories(${MBEDTLS_TARGET_PREFIX}p256m
        PRIVATE
            ${CMAKE_CURRENT_SOURCE_DIR}
    )

    # FPU flags for p256m
    target_compile_options(${MBEDTLS_TARGET_PREFIX}p256m
        PRIVATE
            ${COMPILER_CP_FLAG}
    )
endif()

target_link_libraries(${MBEDTLS_TARGET_PREFIX}mbedcrypto
    PRIVATE
        platform_s
        $<$<BOOL:${MBEDTLS_P256M_ENABLED}>:${MBEDTLS_TARGET_PREFIX}p256m>
    PUBLIC
        crypto_service_mbedcrypto_config
    INTERFACE
        platform_common_interface
)
