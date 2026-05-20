#-------------------------------------------------------------------------------
# Copyright (c) 2026 Cypress Semiconductor Corporation (an Infineon company)
# or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

target_sources(ifx_mbedtls_acceleration
    PRIVATE
        ${IFX_MBEDTLS_ACCELERATION_LIB_PATH}/mbedtls_PSA/mbedtls_psa_MXCryptosuite/ifx_cryptosuite_common.c
        ${IFX_MBEDTLS_ACCELERATION_LIB_PATH}/mbedtls_PSA/mbedtls_psa_MXCryptosuite/ifx_cryptosuite_transparent_aead.c
        ${IFX_MBEDTLS_ACCELERATION_LIB_PATH}/mbedtls_PSA/mbedtls_psa_MXCryptosuite/ifx_cryptosuite_transparent_cipher.c
        ${IFX_MBEDTLS_ACCELERATION_LIB_PATH}/mbedtls_PSA/mbedtls_psa_MXCryptosuite/ifx_cryptosuite_transparent_mac.c
)

# Determine CS.lib variant path based on compiler and FP settings.
# Enum settings are derived from each toolchain's hardcoded flags.
if(CMAKE_C_COMPILER_ID STREQUAL "GNU")
    # GNU: -fshort-enums
    set(_IFX_CS_ENUM "shortenum")
else()
    # ARMClang, Clang, IAR: -fno-short-enums
    set(_IFX_CS_ENUM "noshortenum")
endif()

if(CONFIG_TFM_FLOAT_ABI STREQUAL "hard")
    set(_IFX_CS_FP "hard")
else()
    set(_IFX_CS_FP "softfp")
endif()

target_link_libraries(ifx_mbedtls_acceleration
    PRIVATE
        # TF-M builds with -fno-short-wchar
        ${IFX_CRYPTOSUITE_LIB_PATH}/lib/${_IFX_CS_ENUM}-noshortchar-${_IFX_CS_FP}/CS.lib
        ${IFX_CRYPTOSUITE_LIB_PATH}/lib/${_IFX_CS_ENUM}-noshortchar-${_IFX_CS_FP}/CS-Secure.lib
)

target_include_directories(ifx_mbedtls_acceleration
    PUBLIC
        ${IFX_CRYPTOSUITE_LIB_PATH}/include/api
        ${IFX_MBEDTLS_ACCELERATION_LIB_PATH}/mbedtls_PSA/mbedtls_psa_MXCryptosuite
        ${MBEDCRYPTO_PATH}/target/infineon/mbedtls
)
