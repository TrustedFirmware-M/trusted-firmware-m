#-------------------------------------------------------------------------------
# Copyright (c) 2024-2026 Cypress Semiconductor Corporation (an Infineon company)
# or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
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
)

target_include_directories(ifx_mbedtls_acceleration
    PUBLIC
        ${MBEDCRYPTO_PATH}/include
        ${MBEDCRYPTO_PATH}/library
)

target_link_libraries(ifx_mbedtls_acceleration
    PUBLIC
        ifx_pdl_s
    PRIVATE
        crypto_service_tfpsacrypto
        psa_crypto_library_config
        platform_common_interface
        ifx_pdl_mbedtls_acceleration
)

target_link_libraries(ifx_pdl_mbedtls_acceleration
    PRIVATE
        # Use crypto service options to build PDL crypto drivers for mbedtls acceleration library
        crypto_service_tfpsacrypto
)

target_link_libraries(crypto_service_mbedcrypto
    PUBLIC
        ifx_mbedtls_acceleration
)
