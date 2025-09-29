#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

add_library(bl1_psa_crypto STATIC)
add_library(bl1_psa_crypto_config INTERFACE)

target_compile_definitions(bl1_psa_crypto_config
    INTERFACE
        #Configure settings related to Mbed TLS cryptographic accelerators.
        MBEDTLS_ACCELERATOR_CONFIG_FILE="${CMAKE_CURRENT_SOURCE_DIR}/mbedtls_accelerator_config.h"

        # PSA Crypto-specific configuration file.
        MBEDTLS_PSA_CRYPTO_CONFIG_FILE="${CMAKE_CURRENT_SOURCE_DIR}/psa_crypto_config.h"
        # PSA Crypto accelerator configurations.
        MBEDTLS_ACCELERATOR_PSA_CRYPTO_CONFIG_FILE="${CMAKE_CURRENT_SOURCE_DIR}/psa_accelerator_config.h"
)

target_include_directories(bl1_psa_crypto_config
    INTERFACE
        ${CMAKE_SOURCE_DIR}/interface/include
        ${CMAKE_SOURCE_DIR}/interface/include/psa
        ${MBEDCRYPTO_PATH}/library
        ${CMAKE_CURRENT_SOURCE_DIR}/../cc3xx/opaque-keys
)

target_sources(bl1_psa_crypto
    PRIVATE
        ${CMAKE_SOURCE_DIR}/lib/ext/thin-psa-crypto-core/thin_psa_crypto_core.c
        ${CMAKE_CURRENT_SOURCE_DIR}/../cc3xx/opaque-keys/crypto_opaque_keys.c
)

target_link_libraries(bl1_psa_crypto
    PUBLIC
        bl1_cc3xx_psa_driver_api
        platform_bl1_1
)

target_link_libraries(bl1_cc3xx_psa_driver_api
    PUBLIC
        bl1_psa_crypto_config
)

target_sources(platform_bl2 PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/../cc3xx/opaque-keys/crypto_opaque_keys.c
)

target_include_directories(platform_bl2 PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}
    INTERFACE
        ${CMAKE_SOURCE_DIR}/interface/include
        ${CMAKE_SOURCE_DIR}/interface/include/psa
        ${MBEDCRYPTO_PATH}/library
)

target_sources(platform_s PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/../cc3xx/opaque-keys/crypto_opaque_keys.c
)
