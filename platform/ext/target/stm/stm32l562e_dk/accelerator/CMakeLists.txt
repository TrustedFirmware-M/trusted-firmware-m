#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
# Copyright (c) 2021 STMicroelectronics. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

############################ Crypto Service ####################################

if(TFM_PARTITION_CRYPTO)
    target_sources(crypto_service_crypto_hw
        PRIVATE
            ${PLATFORM_DIR}/ext/target/stm/common/hal/accelerator/stm.c
            ${PLATFORM_DIR}/ext/target/stm/common/hal/accelerator/rng.c
    )

    target_include_directories(crypto_service_crypto_hw
        PRIVATE
            ${PLATFORM_DIR}/ext/target/${TFM_PLATFORM}/accelerator/include
            ${PLATFORM_DIR}/ext/target/stm/common/hal/accelerator/
            ${PLATFORM_DIR}/ext/target/${TFM_PLATFORM}/include/
            ${PLATFORM_DIR}/ext/target/stm/common/hal/Native_Driver/
            ${PLATFORM_DIR}/ext/target/stm/common/stm32l5xx/hal/Inc/
            ${PLATFORM_DIR}/ext/target/stm/common/stm32l5xx/Device/Include/
    )

    target_include_directories(platform_s
        PUBLIC
            ${PLATFORM_DIR}/ext/target/stm/common/hal/accelerator/include
    )

    target_link_libraries(crypto_service_crypto_hw
        PRIVATE
            crypto_service_tfpsacrypto
            platform_s
            cmsis
    )

    target_link_libraries(crypto_service_tfpsacrypto
        PUBLIC
            cmsis
    )

    # The config files need to access crypto accelerator configurations.
    target_include_directories(psa_crypto_library_config
        INTERFACE
            ${PLATFORM_DIR}/ext/target/${TFM_PLATFORM}/accelerator/include
    )
endif()
