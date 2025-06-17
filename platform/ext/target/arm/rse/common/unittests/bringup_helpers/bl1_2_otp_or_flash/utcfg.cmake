#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

set(PLATFORM_DIR ${TFM_ROOT_DIR}/platform)
set(RSE_COMMON_SOURCE_DIR ${PLATFORM_DIR}/ext/target/arm/rse/common)

#-------------------------------------------------------------------------------
# Unit under test
#-------------------------------------------------------------------------------
set(UNIT_UNDER_TEST ${RSE_COMMON_SOURCE_DIR}/bringup_helpers/rse_bl1_2_image_otp_or_flash.c)

#-------------------------------------------------------------------------------
# Test suite
#-------------------------------------------------------------------------------
set(UNIT_TEST_SUITE ${CMAKE_CURRENT_LIST_DIR}/test_rse_bl1_2_image_otp_or_flash.c)

#-------------------------------------------------------------------------------
# Dependencies
#-------------------------------------------------------------------------------

#-------------------------------------------------------------------------------
# Include dirs
#-------------------------------------------------------------------------------
list(APPEND UNIT_TEST_INCLUDE_DIRS ${RSE_COMMON_SOURCE_DIR})
list(APPEND UNIT_TEST_INCLUDE_DIRS ${RSE_COMMON_SOURCE_DIR}/unittests/include)
list(APPEND UNIT_TEST_INCLUDE_DIRS ${RSE_COMMON_SOURCE_DIR}/partition)
list(APPEND UNIT_TEST_INCLUDE_DIRS ${RSE_COMMON_SOURCE_DIR}/subplatform_pal_default_config)
list(APPEND UNIT_TEST_INCLUDE_DIRS ${TFM_ROOT_DIR}/bl1/bl1_1/lib/interface)
list(APPEND UNIT_TEST_INCLUDE_DIRS ${TFM_ROOT_DIR}/bl1/bl1_2/default_config)
list(APPEND UNIT_TEST_INCLUDE_DIRS ${TFM_ROOT_DIR}/lib/fih/inc)
list(APPEND UNIT_TEST_INCLUDE_DIRS ${PLATFORM_DIR}/include)

#-------------------------------------------------------------------------------
# Compiledefs for UUT
#-------------------------------------------------------------------------------
list(APPEND UNIT_TEST_COMPILE_DEFS PLATFORM_ERROR_CODES)
list(APPEND UNIT_TEST_COMPILE_DEFS MCUBOOT_HW_KEY)
list(APPEND UNIT_TEST_COMPILE_DEFS TFM_BL1_2_EMBED_ROTPK_IN_IMAGE)
list(APPEND UNIT_TEST_COMPILE_DEFS MCUBOOT_IMAGE_NUMBER=2)
list(APPEND UNIT_TEST_COMPILE_DEFS TFM_PLAT_ERR_OTP_EMULATION_UNSUPPORTED=0xAB)
list(APPEND UNIT_TEST_COMPILE_DEFS TFM_PLAT_ERR_OTP_READ_UNSUPPORTED=0xCD)
list(APPEND UNIT_TEST_COMPILE_DEFS ROM_DMA_ICS_SIZE=0x1000)
list(APPEND UNIT_TEST_COMPILE_DEFS VM1_SIZE=0x00020000)
list(APPEND UNIT_TEST_COMPILE_DEFS FLASH_NS_PARTITION_SIZE=0x10000)
list(APPEND UNIT_TEST_COMPILE_DEFS FLASH_BL2_PARTITION_SIZE=0x10000)

#-------------------------------------------------------------------------------
# Mocks for UUT
#-------------------------------------------------------------------------------
list(APPEND MOCK_HEADERS ${PLATFORM_DIR}/include/tfm_plat_otp.h)

#-------------------------------------------------------------------------------
# Labels for UT (Optional, tests can be grouped by labels)
#-------------------------------------------------------------------------------
list(APPEND UT_LABELS "BRINGUP_HELPERS")
