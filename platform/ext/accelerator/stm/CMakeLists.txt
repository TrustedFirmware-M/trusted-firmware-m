#-------------------------------------------------------------------------------
# Copyright (c) 2020, Arm Limited. All rights reserved.
# Copyright (c) 2021 STMicroelectronics. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------
# Allow linking to things 'upwards' in the directory tree (in this case bl2 / tfm_partition_crypto)
cmake_policy(SET CMP0079 NEW)
# Allow relative paths
cmake_policy(SET CMP0076 NEW)

if(NOT DEFINED PLATFORM_DIR)
    set(PLATFORM_DIR ../../.. CACHE PATH "Path to platform dir")
endif()

if(BL2)
target_compile_definitions(platform_bl2
    PRIVATE
        CRYPTO_HW_ACCELERATOR
)
endif()

if(BL2)
target_compile_definitions(platform_bl2
    PRIVATE
        CRYPTO_HW_ACCELERATOR
)
endif()

if (PLATFORM_DEFAULT_PROVISIONING)
    # mbedtls_accelerator_config.h is included from the profile config files and must
    # be visible in the platform_s always, due to the compilation of provisioning.c
    target_include_directories(platform_s
        PUBLIC
            ${PLATFORM_DIR}/ext/target/${TFM_PLATFORM}/accelerator/
            ${PLATFORM_DIR}/ext/target/${CRYPTO_HW_ACCELERATOR_TYPE}/common/hal/accelerator/
    )

    # Same for platform_bl2
    if(BL2)
    target_include_directories(platform_bl2
        PUBLIC
            ${PLATFORM_DIR}/ext/target/${TFM_PLATFORM}/accelerator/
            ${PLATFORM_DIR}/ext/target/${CRYPTO_HW_ACCELERATOR_TYPE}/common/hal/accelerator/
    )
    endif()
endif()

################################ BL2 ###########################################
if (BL2)

    target_compile_definitions(platform_bl2
        PRIVATE
            CRYPTO_HW_ACCELERATOR
    )

    target_link_libraries(platform_bl2
        PUBLIC
            bl2_crypto_config
    )

    target_compile_definitions(bl2_crypto
        PUBLIC
            # Uncomment when BL2 specific accelerator config files are provided, which
            # don't enable any _ALT feature which are going to be deprecated
            # MBEDTLS_ACCELERATOR_CONFIG_FILE="${PLATFORM_DIR}/ext/target/${TFM_PLATFORM}/accelerator/mbedtls_accelerator_config.h"
            # MBEDTLS_ACCELERATOR_PSA_CRYPTO_CONFIG_FILE="${PLATFORM_DIR}/ext/target/${TFM_PLATFORM}/accelerator/crypto_accelerator_config.h"
    )
endif()
include(${PLATFORM_DIR}/ext/target/${TFM_PLATFORM}/accelerator/CMakeLists.txt)

if (TFM_PARTITION_CRYPTO)
    set(STM_LIB_TARGET crypto_service_crypto_hw)

    target_link_libraries(crypto_service_mbedcrypto
        PUBLIC
            crypto_service_crypto_hw
    )

    target_compile_definitions(crypto_service_mbedcrypto
        PUBLIC
            CRYPTO_HW_ACCELERATOR
            LEGACY_DRIVER_API_ENABLED
    )

    target_compile_options(crypto_service_mbedcrypto
        PRIVATE
            $<$<C_COMPILER_ID:GNU>:-Wno-unused-parameter>
            $<$<C_COMPILER_ID:ARMClang>:-Wno-unused-parameter>
    )
endif()
