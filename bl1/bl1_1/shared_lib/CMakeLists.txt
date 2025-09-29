#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

add_library(bl1_1_shared_lib STATIC)
add_library(bl1_1_shared_lib_interface INTERFACE)

target_include_directories(bl1_1_shared_lib_interface
    INTERFACE
        interface
        ${CMAKE_SOURCE_DIR}/interface/include
        $<$<BOOL:${TFM_BL1_DEFAULT_OTP}>:${CMAKE_CURRENT_SOURCE_DIR}/otp>
        $<$<BOOL:${TFM_BL1_2_ENABLE_LMS}>:${CMAKE_CURRENT_SOURCE_DIR}/pq_crypto>
)

target_link_libraries(bl1_1_shared_lib_interface
    INTERFACE
        psa_interface
        tfm_fih_headers
        tfm_log_headers
        bl1_1_crypto_mbedcrypto
)

target_sources(bl1_1_shared_lib
    PRIVATE
        $<$<BOOL:${TFM_BL1_SOFTWARE_CRYPTO}>:crypto/crypto_mbedcrypto.c>
        ./util.c
        $<$<BOOL:${TFM_BL1_DEFAULT_OTP}>:./otp/otp_default.c>
        $<$<BOOL:${TFM_BL1_2_ENABLE_LMS}>:./pq_crypto/pq_crypto_psa.c>
)

target_link_libraries(bl1_1_shared_lib
    PUBLIC
        bl1_1_shared_lib_interface
        tfm_log
        tfm_vprintf
    PRIVATE
        platform_bl1_1
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

set(CMAKE_POLICY_DEFAULT_CMP0077 NEW)
set(CMAKE_POLICY_DEFAULT_CMP0048 NEW)
set(ENABLE_TESTING OFF)
set(ENABLE_PROGRAMS OFF)
set(MBEDTLS_FATAL_WARNINGS OFF)
set(ENABLE_DOCS OFF)
set(INSTALL_MBEDTLS_HEADERS OFF)
set(LIB_INSTALL_DIR ${CMAKE_CURRENT_BINARY_DIR}/mbedcrypto/install)

set(lib_target bl1_1_crypto_mbedcrypto_libs)
set(mbedcrypto_target bl1_1_crypto_mbedcrypto)
set(mbedtls_target bl1_1_crypto_mbedtls)
set(mbedx509_target bl1_1_crypto_mbedx509)
set(MBEDTLS_TARGET_PREFIX bl1_1_crypto_)

# Mbedcrypto is quite a large lib, and it uses too much memory for it to be
# reasonable to build it in debug info. As a compromise, if `debug` build type
# is selected mbedcrypto will build under `relwithdebinfo` which preserved debug
# symbols whild optimizing space.
set(SAVED_BUILD_TYPE ${CMAKE_BUILD_TYPE})
set(CMAKE_BUILD_TYPE ${MBEDCRYPTO_BUILD_TYPE})
add_subdirectory(${MBEDCRYPTO_PATH} ${CMAKE_CURRENT_BINARY_DIR}/mbedcrypto)
set(CMAKE_BUILD_TYPE ${SAVED_BUILD_TYPE})

if(NOT TARGET bl1_1_crypto_mbedcrypto)
    message(FATAL_ERROR "Target bl1_1_crypto_mbedcrypto does not exist. Have the patches in ${CMAKE_SOURCE_DIR}/lib/ext/mbedcrypto been applied to the mbedcrypto repo at ${MBEDCRYPTO_PATH} ?
    Hint: The command might be `cd ${MBEDCRYPTO_PATH} && git apply ${CMAKE_SOURCE_DIR}/lib/ext/mbedcrypto/*.patch`")
endif()

target_include_directories(bl1_1_crypto_mbedcrypto
    PUBLIC
        ./crypto
)

target_compile_definitions(bl1_1_crypto_mbedcrypto
    PUBLIC
        MBEDTLS_CONFIG_FILE="mbedcrypto_config.h"
        # Workaround for https://github.com/ARMmbed/mbedtls/issues/1077
        $<$<OR:$<STREQUAL:${CMAKE_SYSTEM_ARCHITECTURE},armv8-m.base>,$<STREQUAL:${CMAKE_SYSTEM_ARCHITECTURE},armv6-m>>:MULADDC_CANNOT_USE_R7>
)

target_compile_options(bl1_1_crypto_mbedcrypto
    PRIVATE
        $<$<C_COMPILER_ID:GNU>:-Wno-unused-parameter>
        $<$<C_COMPILER_ID:ARMClang>:-Wno-unused-parameter>
)

target_compile_options(bl1_1_crypto_mbedcrypto
    PRIVATE
        ${BL1_COMPILER_CP_FLAG}
)

target_link_options(bl1_1_crypto_mbedcrypto
    PUBLIC
        ${BL1_LINKER_CP_OPTION}
)

target_compile_options(bl1_1_crypto_mbedtls
    PRIVATE
        ${BL1_COMPILER_CP_FLAG}
)

target_link_options(bl1_1_crypto_mbedtls
    PUBLIC
        ${BL1_LINKER_CP_OPTION}
)

target_compile_options(bl1_1_crypto_mbedx509
    PRIVATE
        ${BL1_COMPILER_CP_FLAG}
)

target_link_options(bl1_1_crypto_mbedx509
    PUBLIC
        ${BL1_LINKER_CP_OPTION}
)
