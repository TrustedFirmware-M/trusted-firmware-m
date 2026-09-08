#-------------------------------------------------------------------------------
# Copyright (c) 2026, STMicroelectronics - All Rights Reserved
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

#========================= Crypto Service =====================================#
if(TFM_PARTITION_CRYPTO)
    target_sources(crypto_service_crypto_hw
        PRIVATE
            ${STM_FAMILY_DIR}/accelerator/stm32mp2.c
    )

    target_include_directories(crypto_service_crypto_hw
        PRIVATE
            ${STM_FAMILY_DIR}/accelerator/include
    )

    target_include_directories(platform_s
        PUBLIC
            ${STM_FAMILY_DIR}/accelerator/include
    )

    target_link_libraries(crypto_service_crypto_hw
        PRIVATE
            crypto_service_tfpsacrypto
            platform_s
            cmsis
    )

    # The config files need to access crypto accelerator configurations.
    target_include_directories(psa_crypto_library_config
        INTERFACE
            ${STM_FAMILY_DIR}/accelerator/include
    )

endif()
