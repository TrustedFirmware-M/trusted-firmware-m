#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

set(CC3XX_TEST_TARGET_NAME ${CC3XX_TARGET_NAME}_tests)

add_library(${CC3XX_TEST_TARGET_NAME} INTERFACE)

target_sources(${CC3XX_TEST_TARGET_NAME}
    INTERFACE
        ./src/cc3xx_test_main.c
        ./src/cc3xx_test_hash.c
        ./src/low_level_driver/test_lowlevel_hash.c
        ./src/cc3xx_test_aes.c
        ./src/low_level_driver/test_lowlevel_aes.c
        ./src/cc3xx_test_chacha.c
        ./src/low_level_driver/test_lowlevel_chacha.c
        ./src/cc3xx_test_pka.c
        ./src/cc3xx_test_ecc.c
        ./src/cc3xx_test_ecdsa.c
        ./src/cc3xx_test_drbg.c
        ./src/cc3xx_test_dpa.c
        ./src/cc3xx_test_utils.c
)

target_include_directories(${CC3XX_TEST_TARGET_NAME}
    INTERFACE
        ./include
        ./src
        ./src/low_level_driver
)

target_compile_definitions(${CC3XX_TEST_TARGET_NAME}
    INTERFACE
        $<$<BOOL:${TEST_CC3XX}>:TEST_CC3XX>
        $<$<BOOL:${TEST_CC3XX_HASH}>:TEST_CC3XX_HASH>
        $<$<BOOL:${TEST_CC3XX_AES}>:TEST_CC3XX_AES>
        $<$<BOOL:${TEST_CC3XX_CHACHA}>:TEST_CC3XX_CHACHA>
        $<$<BOOL:${TEST_CC3XX_PKA}>:TEST_CC3XX_PKA>
        $<$<BOOL:${TEST_CC3XX_ECC}>:TEST_CC3XX_ECC>
        $<$<BOOL:${TEST_CC3XX_ECDSA}>:TEST_CC3XX_ECDSA>
        $<$<BOOL:${TEST_CC3XX_DRBG}>:TEST_CC3XX_DRBG>
        $<$<BOOL:${TEST_CC3XX_DPA}>:TEST_CC3XX_DPA>
)

target_link_libraries(${CC3XX_TEST_TARGET_NAME}
    INTERFACE
        ${CC3XX_TARGET_NAME}
)
