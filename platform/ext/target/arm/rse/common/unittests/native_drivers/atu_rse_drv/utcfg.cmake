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
list(APPEND UNIT_UNDER_TEST ${RSE_COMMON_SOURCE_DIR}/native_drivers/atu_rse_drv.c)

#-------------------------------------------------------------------------------
# Test suite
#-------------------------------------------------------------------------------
set(UNIT_TEST_SUITE ${CMAKE_CURRENT_LIST_DIR}/test_atu_rse_drv.c)

#-------------------------------------------------------------------------------
# Dependencies
#-------------------------------------------------------------------------------
list(APPEND UNIT_TEST_DEPS ${RSE_COMMON_SOURCE_DIR}/native_drivers/atu_rse_lib.c)
list(APPEND UNIT_TEST_DEPS ${CMAKE_CURRENT_LIST_DIR}/test_atu_config.c)

#-------------------------------------------------------------------------------
# Include dirs
#-------------------------------------------------------------------------------
list(APPEND UNIT_TEST_INCLUDE_DIRS ${PLATFORM_DIR}/ext/target/arm/rse/tc/common)
list(APPEND UNIT_TEST_INCLUDE_DIRS ${PLATFORM_DIR}/include)
list(APPEND UNIT_TEST_INCLUDE_DIRS ${RSE_COMMON_SOURCE_DIR}/device/include)
list(APPEND UNIT_TEST_INCLUDE_DIRS ${RSE_COMMON_SOURCE_DIR}/native_drivers)
list(APPEND UNIT_TEST_INCLUDE_DIRS ${RSE_COMMON_SOURCE_DIR}/partition)
list(APPEND UNIT_TEST_INCLUDE_DIRS ${CMAKE_CURRENT_LIST_DIR})

#-------------------------------------------------------------------------------
# Compiledefs for UUT
#-------------------------------------------------------------------------------

#-------------------------------------------------------------------------------
# Mocks for UUT
#-------------------------------------------------------------------------------

#-------------------------------------------------------------------------------
# Labels for UT (Optional, tests can be grouped by labels)
#-------------------------------------------------------------------------------
list(APPEND UT_LABELS "DRIVER")
