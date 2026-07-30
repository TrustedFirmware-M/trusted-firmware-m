#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

set(PLATFORM_DIR ${TFM_ROOT_DIR}/platform)
set(RSE_COMMON_SOURCE_DIR ${PLATFORM_DIR}/ext/target/arm/rse/common)

set(UNIT_UNDER_TEST ${RSE_COMMON_SOURCE_DIR}/fip_parser/gpt.c)
set(UNIT_TEST_SUITE ${CMAKE_CURRENT_LIST_DIR}/test_gpt.c)

list(APPEND UNIT_TEST_INCLUDE_DIRS ${RSE_COMMON_SOURCE_DIR}/unittests/include)
list(APPEND UNIT_TEST_INCLUDE_DIRS ${RSE_COMMON_SOURCE_DIR}/fip_parser)
list(APPEND UNIT_TEST_INCLUDE_DIRS ${RSE_COMMON_SOURCE_DIR})
list(APPEND UNIT_TEST_INCLUDE_DIRS ${PLATFORM_DIR}/include)
list(APPEND UNIT_TEST_INCLUDE_DIRS ${TFM_ROOT_DIR}/lib/tfm_helper_lib)

list(APPEND UNIT_TEST_COMPILE_DEFS PLATFORM_ERROR_CODES)
list(APPEND UNIT_TEST_COMPILE_DEFS FLASH_BASE_ADDRESS=0)
list(APPEND UNIT_TEST_COMPILE_DEFS FLASH_LBA_SIZE=512)

list(APPEND UT_LABELS "FIP_PARSER")
