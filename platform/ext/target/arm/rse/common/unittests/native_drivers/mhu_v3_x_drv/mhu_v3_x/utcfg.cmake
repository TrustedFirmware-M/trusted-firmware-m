#-------------------------------------------------------------------------------
# Copyright (c) 2024, Arm Limited. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

set(PLATFORM_DIR ${TFM_ROOT_DIR}/platform)
set(RSE_COMMON_SOURCE_DIR ${PLATFORM_DIR}/ext/target/arm/rse/common)

#-------------------------------------------------------------------------------
# Unit under test
#-------------------------------------------------------------------------------
set(UNIT_UNDER_TEST ${RSE_COMMON_SOURCE_DIR}/native_drivers/mhu_v3_x.c)

#-------------------------------------------------------------------------------
# Test suite
#-------------------------------------------------------------------------------
set(UNIT_TEST_SUITE ${CMAKE_CURRENT_LIST_DIR}/test_mhu_v3_x.c)

#-------------------------------------------------------------------------------
# Dependencies
#-------------------------------------------------------------------------------

#-------------------------------------------------------------------------------
# Include dirs
#-------------------------------------------------------------------------------
list(APPEND UNIT_TEST_INCLUDE_DIRS ${RSE_COMMON_SOURCE_DIR}/native_drivers)

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