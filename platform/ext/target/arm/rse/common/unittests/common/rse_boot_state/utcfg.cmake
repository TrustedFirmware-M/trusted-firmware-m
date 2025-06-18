#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

set(PLATFORM_DIR ${TFM_ROOT_DIR}/platform)
set(RSE_COMMON_SOURCE_DIR ${PLATFORM_DIR}/ext/target/arm/rse/common)
set(CC3XX_SOURCE_DIR ${PLATFORM_DIR}/ext/target/arm/drivers/cc3xx)

#-------------------------------------------------------------------------------
# Unit under test
#-------------------------------------------------------------------------------
set(UNIT_UNDER_TEST ${RSE_COMMON_SOURCE_DIR}/rse_boot_state.c)

#-------------------------------------------------------------------------------
# Test suite
#-------------------------------------------------------------------------------

set(UNIT_TEST_SUITE ${CMAKE_CURRENT_LIST_DIR}/test_rse_boot_state.c)

#-------------------------------------------------------------------------------
# Dependencies
#-------------------------------------------------------------------------------

#-------------------------------------------------------------------------------
# Include dirs
#-------------------------------------------------------------------------------
list(APPEND UNIT_TEST_INCLUDE_DIRS ${RSE_COMMON_SOURCE_DIR}/subplatform_pal_default_config)
list(APPEND UNIT_TEST_INCLUDE_DIRS ${RSE_COMMON_SOURCE_DIR}/unittests/include)
list(APPEND UNIT_TEST_INCLUDE_DIRS ${RSE_COMMON_SOURCE_DIR}/partition)
list(APPEND UNIT_TEST_INCLUDE_DIRS ${RSE_COMMON_SOURCE_DIR}/bl1/cc3xx)
list(APPEND UNIT_TEST_INCLUDE_DIRS ${RSE_COMMON_SOURCE_DIR})
list(APPEND UNIT_TEST_INCLUDE_DIRS ${CC3XX_SOURCE_DIR}/low_level_driver/include)
list(APPEND UNIT_TEST_INCLUDE_DIRS ${CC3XX_SOURCE_DIR}/common)
list(APPEND UNIT_TEST_INCLUDE_DIRS ${PLATFORM_DIR}/ext/target/arm/drivers/lcm)
list(APPEND UNIT_TEST_INCLUDE_DIRS ${PLATFORM_DIR}/include)
list(APPEND UNIT_TEST_INCLUDE_DIRS ${TFM_ROOT_DIR}/bl1/bl1_1/shared_lib/interface)
list(APPEND UNIT_TEST_INCLUDE_DIRS ${TFM_ROOT_DIR}/lib/fih/inc)
list(APPEND UNIT_TEST_INCLUDE_DIRS ${TFM_ROOT_DIR}/interface/include)

#-------------------------------------------------------------------------------
# Compiledefs for UUT
#-------------------------------------------------------------------------------
list(APPEND UNIT_TEST_COMPILE_DEFS PLATFORM_ERROR_CODES)
list(APPEND UNIT_TEST_COMPILE_DEFS LCM_S)
list(APPEND UNIT_TEST_COMPILE_DEFS MCUBOOT_HW_KEY)
list(APPEND UNIT_TEST_COMPILE_DEFS TFM_BL1_2_EMBED_ROTPK_IN_IMAGE)
list(APPEND UNIT_TEST_COMPILE_DEFS MCUBOOT_IMAGE_NUMBER=2)
list(APPEND UNIT_TEST_COMPILE_DEFS TFM_BL1_2_SIGNER_AMOUNT=1)
list(APPEND UNIT_TEST_COMPILE_DEFS BL1_2_HASH_SIZE=32)
list(APPEND UNIT_TEST_COMPILE_DEFS MBEDTLS_CONFIG_FILE="${TFM_ROOT_DIR}/bl1/bl1_1/shared_lib/crypto/mbedcrypto_config.h")

#-------------------------------------------------------------------------------
# Link libs for UUT
#-------------------------------------------------------------------------------

#-------------------------------------------------------------------------------
# Mocks for UUT
#-------------------------------------------------------------------------------
list(APPEND MOCK_HEADERS ${CC3XX_SOURCE_DIR}/low_level_driver/include/cc3xx_hash.h)
list(APPEND MOCK_HEADERS ${PLATFORM_DIR}/ext/target/arm/drivers/lcm/lcm_drv.h)
list(APPEND MOCK_HEADERS ${PLATFORM_DIR}/include/tfm_plat_otp.h)

#-------------------------------------------------------------------------------
# Labels for UT (Optional, tests can be grouped by labels)
#-------------------------------------------------------------------------------
list(APPEND UT_LABELS "COMMON")
