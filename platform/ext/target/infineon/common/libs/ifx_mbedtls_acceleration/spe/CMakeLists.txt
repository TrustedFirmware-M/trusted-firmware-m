#-------------------------------------------------------------------------------
# (c) 2024-2026, Infineon Technologies AG, or an affiliate of Infineon
# Technologies AG. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

if (NOT IFX_MBEDTLS_ACCELERATION_ENABLED)
    return()
endif()

cmake_policy(SET CMP0076 NEW)
cmake_policy(SET CMP0079 NEW)

########################## IFX_MBEDTLS_ACCELERATION_S_TARGET ##########################

target_compile_definitions(tfm_config
    INTERFACE
        IFX_MBEDTLS_ACCELERATION_ENABLED=1
)

add_library(ifx_mbedtls_acceleration STATIC EXCLUDE_FROM_ALL)

target_compile_options(ifx_mbedtls_acceleration
    PRIVATE
        ${COMPILER_CP_FLAG}
)

if (IFX_MBEDTLS_ACCELERATOR_TYPE STREQUAL "CRYPTOLITE")
    include(${IFX_COMMON_SOURCE_DIR}/libs/ifx_mbedtls_acceleration/spe/cryptolite.cmake)
elseif(IFX_MBEDTLS_ACCELERATOR_TYPE STREQUAL "MXCRYPTO")
    include(${IFX_COMMON_SOURCE_DIR}/libs/ifx_mbedtls_acceleration/spe/mxcrypto.cmake)
else()
    message(FATAL_ERROR "Unsupported accelerator type: ${IFX_MBEDTLS_ACCELERATOR_TYPE}")
endif()

if(IFX_CRYPTOSUITE_ENABLED AND S_BUILD)
    include(${IFX_COMMON_SOURCE_DIR}/libs/ifx_mbedtls_acceleration/spe/cryptosuite.cmake)
endif()

target_compile_definitions(ifx_mbedtls_acceleration
    PUBLIC
        MBEDTLS_PSA_CRYPTO_DRIVERS
        # Select the tf-psa-crypto v1.1.0+ header locations
        # (tf-psa-crypto/build_info.h, mbedtls/private/*, psa/error.h) in the patched
        # acceleration sources. When this macro is not defined the sources fall back to
        # the classic mbedtls header layout, so the library can still be consumed by
        # projects built against pre-v1.1.0 mbedtls.
        IFX_TF_PSA_CRYPTO_INCLUDES
)

target_include_directories(ifx_mbedtls_acceleration
    PUBLIC
        ${TF_PSA_CRYPTO_PATH}/include
        ${TF_PSA_CRYPTO_PATH}/core
    PRIVATE
        ${TF_PSA_CRYPTO_PATH}/drivers/builtin/src
        ${CMAKE_SOURCE_DIR}/interface/include
)

target_link_libraries(ifx_mbedtls_acceleration
    PUBLIC
        ifx_pdl_s
    PRIVATE
        crypto_service_tfpsacrypto_config
        psa_crypto_library_config
        platform_common_interface
        ifx_pdl_mbedtls_acceleration
)

target_link_libraries(ifx_pdl_mbedtls_acceleration
    PRIVATE
        # Use crypto service options to build PDL crypto drivers for mbedtls acceleration library
        crypto_service_tfpsacrypto_config
)

target_link_libraries(crypto_service_tfpsacrypto
    PUBLIC
        ifx_mbedtls_acceleration
)
