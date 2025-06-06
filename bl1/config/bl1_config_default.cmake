#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

set(BL1_1_CONFIG_DIR ${CMAKE_SOURCE_DIR}/bl1/bl1_1/default_config)
set(BL1_2_CONFIG_DIR ${CMAKE_SOURCE_DIR}/bl1/bl1_2/default_config)

set(TFM_BL2_ENCRYPTION_KEY_PATH         ${CMAKE_SOURCE_DIR}/bl1/bl1_2/bl2_dummy_encryption_key.bin CACHE FILEPATH "Path to binary key to use for encrypting BL2")
set(TFM_GUK_PATH                        ${CMAKE_SOURCE_DIR}/bl1/bl1_1/dummy_guk.bin                CACHE FILEPATH "Path to binary GUK key file to provision")
set(TFM_BL2_IMAGE_FLASH_AREA_NUM        0                                                          CACHE STRING   "Which flash area BL2 is stored in")

set(TFM_GENERATE_BL1_2_CM_SIGNING_KEY OFF CACHE BOOL "Generate bl2 signing CM key")
set(TFM_GENERATE_BL1_2_DM_SIGNING_KEY OFF CACHE BOOL "Generate bl2 signing DM key")

set(TFM_BL1_2_CM_SIGNING_ALG           "LMS"       CACHE STRING "Algorithm to use for BL2 signing")
if (TFM_BL1_2_CM_SIGNING_ALG STREQUAL "LMS")
    set(TFM_BL1_2_CM_SIGNING_KEY_PATH "${CMAKE_SOURCE_DIR}/bl1/bl1_2/bl1_dummy_rotpk.pub" CACHE FILEPATH "Path to binary BL2 signing private key")
else()
    set(TFM_BL1_2_ECDSA_CURVE          "P256" CACHE STRING "Curve to use for BL1_2 ECDSA validation")
    set(TFM_BL1_2_CM_SIGNING_KEY_PATH   "${CMAKE_SOURCE_DIR}/bl2/ext/mcuboot/root-EC-${TFM_BL1_2_ECDSA_CURVE}.pem" CACHE FILEPATH "Path to binary BL2 signing private key")
endif()

set(TFM_BL1_2_DM_SIGNING_ALG           "LMS"       CACHE STRING "Algorithm to use for BL2 signing")
if (TFM_BL1_2_DM_SIGNING_ALG STREQUAL "LMS")
    set(TFM_BL1_2_DM_SIGNING_KEY_PATH "${CMAKE_SOURCE_DIR}/bl1/bl1_2/bl1_dummy_rotpk_1.pub" CACHE FILEPATH "Path to binary BL2 signing private key")
else()
    set(TFM_BL1_2_ECDSA_CURVE          "P256" CACHE STRING "Curve to use for BL1_2 ECDSA validation")
    set(TFM_BL1_2_DM_SIGNING_KEY_PATH   "${CMAKE_SOURCE_DIR}/bl2/ext/mcuboot/root-EC-${TFM_BL1_2_ECDSA_CURVE}_1.pem" CACHE FILEPATH "Path to binary BL2 signing private key")
endif()

set(TFM_BL1_1_MEASUREMENT_HASH_ALG "SHA256" CACHE STRING "Algorithm to use for measurement")

if (TFM_BL1_2_ECDSA_CURVE STREQUAL "P384")
    set(TFM_BL1_2_MEASUREMENT_HASH_ALG "SHA384" CACHE STRING "Algorithm to use for measurement")
else()
    set(TFM_BL1_2_MEASUREMENT_HASH_ALG "SHA256" CACHE STRING "Algorithm to use for measurement")
endif()

set(TFM_BL1_MEMORY_MAPPED_FLASH         ON          CACHE BOOL      "Whether BL1 can directly access flash content")

set(TFM_BL1_LOG_LEVEL                   LOG_LEVEL_INFO CACHE STRING "The level of BL1 logging to uart")
set(TFM_BL1_DEFAULT_OTP                 ON          CACHE BOOL      "Whether BL1_1 will use default OTP memory")
set(TFM_BL1_DEFAULT_PROVISIONING        ON          CACHE BOOL      "Whether BL1_1 will use default provisioning")
set(TFM_BL1_SOFTWARE_CRYPTO             ON          CACHE BOOL      "Whether BL1_1 will use software crypto")
set(TFM_BL1_FIH_ENABLE                  OFF         CACHE BOOL      "Whether BL1 enables FIH config items from bl1_fih_config.h")

if (TFM_BL1_2_CM_SIGNING_ALG STREQUAL "LMS")
    set(TFM_BL1_2_ENABLE_LMS                ON          CACHE BOOL      "Enable ECDSA crypto for BL2 verification")
else()
    set(TFM_BL1_2_ENABLE_ECDSA              ON          CACHE BOOL      "Enable LMS PQ crypto for BL2 verification")
endif()

if (TFM_BL1_2_DM_SIGNING_ALG STREQUAL "LMS")
    set(TFM_BL1_2_ENABLE_LMS                ON          CACHE BOOL      "Enable ECDSA crypto for BL2 verification")
else()
    set(TFM_BL1_2_ENABLE_ECDSA              ON          CACHE BOOL      "Enable LMS PQ crypto for BL2 verification")
endif()

set(TFM_BL1_2_ENABLE_LMS                OFF         CACHE BOOL      "Enable ECDSA crypto for BL2 verification")
set(TFM_BL1_2_ENABLE_ECDSA              OFF         CACHE BOOL      "Enable LMS PQ crypto for BL2 verification")

set(TFM_BL1_2_EMBED_ROTPK_IN_IMAGE      OFF         CACHE STRING    "Whether to embed ROTPK in image and then verify against stored hash")
set(TFM_BL1_2_IMAGE_ENCRYPTION          ON          CACHE STRING    "Whether to encrypt images loaded by BL1_2")
set(TFM_BL1_2_SIGNER_AMOUNT             1           CACHE STRING    "Maximum amount of possible signatures on BL1_2 image")
set(TFM_BL1_2_ENABLE_ROTPK_POLICIES     OFF         CACHE STRING    "Whether to allow individual key signing policies for BL1_2 image")

if (TFM_BL1_2_EMBED_ROTPK_IN_IMAGE)
    set(TFM_BL1_2_ROTPK_HASH_ALG       SHA256      CACHE STRING "Algorithm to use for ROTPK comparision")
endif()

set(TFM_BL1_IMAGE_VERSION_BL2           "1.9.0+0"   CACHE STRING    "Image version of BL2 image")
set(TFM_BL1_IMAGE_SECURITY_COUNTER_BL2  1           CACHE STRING    "Security counter value to include with BL2 image")

set(TFM_BL1_2_IN_OTP                    TRUE        CACHE BOOL      "Whether BL1_2 is stored in OTP")
set(TFM_BL1_2_IN_FLASH                  FALSE       CACHE BOOL      "Whether BL1_2 is stored in FLASH")

set(BL1_2_BUILD_TYPE                    ${CMAKE_BUILD_TYPE} CACHE STRING "Build type of BL1_2")

set(BL1_1_SHARED_SYMBOLS_PATH ${CMAKE_SOURCE_DIR}/bl1/bl1_1/bl1_1_shared_symbols.txt CACHE FILEPATH "Path to list of symbols that BL1_1 that can be referenced from BL1_2")

set(PLATFORM_DEFAULT_BL1_TEST_EXECUTION ON         CACHE BOOL "Whether to use platform-specific mechanism to run BL1 tests")
set(PLATFORM_DEFAULT_BL1_1_TESTS        ON         CACHE BOOL "Whether to use platform-specific BL1_1 testsuite")
set(PLATFORM_DEFAULT_BL1_2_TESTS        ON         CACHE BOOL "Whether to use platform-specific BL1_2 testsuite")
set(EXTRA_BL1_1_TEST_SUITE_PATH         ""         CACHE STRING "path to extra BL1_1 testsuite")
set(EXTRA_BL1_2_TEST_SUITE_PATH         ""         CACHE STRING "path to extra BL1_2 testsuite")
