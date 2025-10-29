#-------------------------------------------------------------------------------
# Copyright (C) 2025 Analog Devices, Inc. All rights reserved.
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

include(${PLATFORM_DIR}/ext/target/${TFM_PLATFORM}/accelerator/CMakeLists.txt)
if(BL2)
    target_compile_definitions(bl2_crypto_config
        INTERFACE
            TF_PSA_CRYPTO_ACCELERATOR_CONFIG_FILE="${PLATFORM_DIR}/ext/target/${TFM_PLATFORM}/accelerator/include/tf_psa_crypto_accelerator_config.h"
    )
endif()

if (TFM_PARTITION_CRYPTO)
    target_link_libraries(crypto_service_tfpsacrypto
        PUBLIC
            crypto_service_crypto_hw
    )

    target_compile_definitions(crypto_service_tfpsacrypto
        PUBLIC
            CRYPTO_HW_ACCELERATOR
    )

    target_compile_options(crypto_service_tfpsacrypto
        PRIVATE
            $<$<C_COMPILER_ID:GNU>:-Wno-unused-parameter>
    )
endif()
