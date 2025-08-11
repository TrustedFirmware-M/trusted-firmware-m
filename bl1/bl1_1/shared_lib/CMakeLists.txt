#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

add_library(bl1_1_shared_lib STATIC)
add_library(bl1_1_shared_lib_interface INTERFACE)
add_library(bl1_1_psa_crypto STATIC)
add_library(bl1_1_psa_crypto_interface INTERFACE)

target_include_directories(bl1_1_shared_lib_interface
    INTERFACE
        interface
        ${CMAKE_SOURCE_DIR}/interface/include
        ${CMAKE_SOURCE_DIR}/platform/include
        $<$<BOOL:${TFM_BL1_DEFAULT_OTP}>:${CMAKE_CURRENT_SOURCE_DIR}/otp>
        $<$<BOOL:${TFM_BL1_2_ENABLE_LMS}>:${CMAKE_CURRENT_SOURCE_DIR}/pq_crypto>
)

target_link_libraries(bl1_1_shared_lib_interface
    INTERFACE
        psa_interface
        tfm_fih_headers
        tfm_log_headers
        bl1_1_psa_crypto_interface
)


target_sources(bl1_1_shared_lib
    PRIVATE
        ./util.c
        $<$<BOOL:${TFM_BL1_DEFAULT_OTP}>:./otp/otp_default.c>
)

target_compile_options(bl1_1_shared_lib_interface
    INTERFACE
        #Prevents warnings caused by C99 static assert workaround
        $<$<C_COMPILER_ID:GNU>:-Wno-unused-local-typedefs>
        $<$<C_COMPILER_ID:ARMClang>:-Wno-unused-local-typedefs>
)

target_compile_definitions(bl1_1_shared_lib_interface
    INTERFACE
        $<$<BOOL:${TEST_BL1_1}>:TEST_BL1_1>
        $<$<BOOL:${TFM_BL1_FIH_ENABLE}>:TFM_FIH_PROFILE_ON>
        $<$<BOOL:${TFM_BL1_FIH_ENABLE}>:TFM_FIH_PROFILE_CUSTOM_FILE="bl1_fih_config.h">
)

target_compile_definitions(bl1_1_shared_lib_interface
    INTERFACE
        $<$<BOOL:${TFM_BL1_2_ENABLE_LMS}>:TFM_BL1_2_ENABLE_LMS>
)

target_link_libraries(bl1_1_shared_lib
    PUBLIC
        bl1_1_shared_lib_interface
        bl1_1_psa_crypto
        tfm_log
        tfm_vprintf
    PRIVATE
        platform_bl1_1
)

target_include_directories(bl1_1_psa_crypto_interface
    INTERFACE
        ./crypto
        ${CMAKE_SOURCE_DIR}/interface/include
        ${CMAKE_SOURCE_DIR}/interface/include/psa
        ${TF_PSA_CRYPTO_PATH}/core
        ${TF_PSA_CRYPTO_PATH}/drivers/builtin/src
        ${TF_PSA_CRYPTO_PATH}/drivers/builtin/include
)

target_compile_definitions(bl1_1_psa_crypto_interface
    INTERFACE
        # This is the base TF-PSA-Crypto configuration file for all platforms,
        # platforms may extend or override it by setting TF_PSA_CRYPTO_USER_CONFIG_FILE
        # to the platform-specific configuration file.
        TF_PSA_CRYPTO_CONFIG_FILE="${CMAKE_CURRENT_SOURCE_DIR}/crypto/tf_psa_crypto_base_config.h"

        # Workaround for https://github.com/ARMmbed/mbedtls/issues/1077
        $<$<OR:$<STREQUAL:${CMAKE_SYSTEM_ARCHITECTURE},armv8-m.base>,$<STREQUAL:${CMAKE_SYSTEM_ARCHITECTURE},armv6-m>>:MULADDC_CANNOT_USE_R7>
)

target_sources(bl1_1_psa_crypto
    PRIVATE
        ${CMAKE_SOURCE_DIR}/lib/ext/thin-psa-crypto-core/thin_psa_crypto_core.c
        ${TF_PSA_CRYPTO_PATH}/drivers/builtin/src/platform_util.c
        ${TF_PSA_CRYPTO_PATH}/drivers/builtin/src/psa_util.c

        # CryptoCell does not support sha384 and sha512
        ${TF_PSA_CRYPTO_PATH}/drivers/builtin/src/psa_crypto_hash.c
        ${TF_PSA_CRYPTO_PATH}/drivers/builtin/src/sha512.c

        # LMS-specific
        $<$<BOOL:${TFM_BL1_2_ENABLE_LMS}>:${CMAKE_CURRENT_SOURCE_DIR}/pq_crypto/pq_crypto_psa.c>
        $<$<BOOL:${TFM_BL1_2_ENABLE_LMS}>:${TF_PSA_CRYPTO_PATH}/drivers/builtin/src/lmots.c>
        $<$<BOOL:${TFM_BL1_2_ENABLE_LMS}>:${TF_PSA_CRYPTO_PATH}/drivers/builtin/src/lms.c>
)

target_link_libraries(bl1_1_psa_crypto
    PUBLIC
        bl1_1_shared_lib_interface
)

target_compile_options(bl1_1_psa_crypto
    PUBLIC
        ${BL1_COMPILER_CP_FLAG}
)
