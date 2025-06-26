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
            ${PLATFORM_DIR}/ext/target/stm/common/hal/accelerator/rsa_alt.c
            ${PLATFORM_DIR}/ext/target/stm/common/hal/accelerator/ecdsa_alt.c
            ${PLATFORM_DIR}/ext/target/stm/common/hal/accelerator/aes_alt.c
            ${PLATFORM_DIR}/ext/target/stm/common/hal/accelerator/gcm_alt.c
            ${PLATFORM_DIR}/ext/target/stm/common/hal/accelerator/ccm_alt.c
            ${PLATFORM_DIR}/ext/target/stm/common/hal/accelerator/ecp_alt.c
            ${PLATFORM_DIR}/ext/target/stm/common/hal/accelerator/ecp_curves_alt.c
            ${PLATFORM_DIR}/ext/target/stm/common/hal/accelerator/sha1_alt.c
            ${PLATFORM_DIR}/ext/target/stm/common/hal/accelerator/sha256_alt.c
            ${PLATFORM_DIR}/ext/target/stm/common/hal/accelerator/stm.c
    )

    target_include_directories(crypto_service_crypto_hw
        PRIVATE
            ${PLATFORM_DIR}/ext/target/${TFM_PLATFORM}/accelerator/
            ${PLATFORM_DIR}/ext/target/stm/common/hal/accelerator/
            ${PLATFORM_DIR}/ext/target/${TFM_PLATFORM}/include/
            ${PLATFORM_DIR}/ext/target/stm/common/stm32l5xx/hal/Inc/
            ${PLATFORM_DIR}/ext/target/stm/common/stm32l5xx/Device/Include/
            ${PLATFORM_DIR}/include
    )

    target_include_directories(crypto_service_tfpsacrypto
        PUBLIC
            ${PLATFORM_DIR}/ext/target/${TFM_PLATFORM}/accelerator/
            ${PLATFORM_DIR}/ext/target/stm/common/hal/accelerator/
            ${PLATFORM_DIR}/ext/target/${TFM_PLATFORM}/include/
            ${PLATFORM_DIR}/ext/target/stm/common/stm32l5xx/hal/Inc/
            ${PLATFORM_DIR}/ext/target/stm/common/stm32l5xx/Device/Include/
    )


    target_include_directories(psa_crypto_config
        INTERFACE
            $<BUILD_INTERFACE:${PLATFORM_DIR}/ext/target/${TFM_PLATFORM}/accelerator/>
    )

    target_compile_definitions(crypto_service_crypto_hw
        PRIVATE
            ST_HW_CONTEXT_SAVING
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

    target_link_libraries(platform_s
        PRIVATE
            crypto_service_crypto_hw
    )
endif()
