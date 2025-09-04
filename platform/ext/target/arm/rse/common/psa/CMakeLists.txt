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
        ${MBEDCRYPTO_PATH}/library
        ${MBEDCRYPTO_PATH}/include/psa
)

target_sources(bl1_psa_crypto
    PRIVATE
        ${CMAKE_SOURCE_DIR}/lib/ext/thin-psa-crypto-core/thin_psa_crypto_core.c
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
