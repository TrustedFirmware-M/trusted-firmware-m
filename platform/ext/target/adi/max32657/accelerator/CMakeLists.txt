#-------------------------------------------------------------------------------
# Copyright (C) 2025 Analog Devices, Inc. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

############################ Crypto Service ####################################

if(TFM_PARTITION_CRYPTO)
    target_sources(crypto_service_crypto_hw
        PUBLIC
            ${PLATFORM_DIR}/ext/target/${TFM_PLATFORM}/accelerator/src/adi_psa_random.c
            ${PLATFORM_DIR}/ext/target/${TFM_PLATFORM}/accelerator/src/adi_accelerator.c
        PRIVATE
            ${HAL_ADI_PERIPH_SRC_DIR}/TRNG/trng_me30.c
            ${HAL_ADI_PERIPH_SRC_DIR}/TRNG/trng_revb.c
    )

    target_include_directories(crypto_service_crypto_hw
        PUBLIC
            ${PLATFORM_DIR}/ext/target/${TFM_PLATFORM}/accelerator/include
            ${HAL_ADI_PERIPH_INC_DIR}
            ${HAL_ADI_CMSIS_INC_DIR}
    )

    target_include_directories(platform_s
        PUBLIC
            ${PLATFORM_DIR}/ext/target/${TFM_PLATFORM}/accelerator/include
    )

    target_link_libraries(crypto_service_crypto_hw
        PRIVATE
            crypto_service_mbedcrypto
            platform_s
    )
endif()
