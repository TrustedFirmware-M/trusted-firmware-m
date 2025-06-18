#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

set(PLATFORM_DIR ${TFM_ROOT_DIR}/platform)
set(RSE_COMMON_SOURCE_DIR ${PLATFORM_DIR}/ext/target/arm/rse/common)
set(GENERATED_FILES ${CMAKE_BINARY_DIR}/generated)

#-------------------------------------------------------------------------------
# Unit under test
#-------------------------------------------------------------------------------
set(UNIT_UNDER_TEST ${RSE_COMMON_SOURCE_DIR}/nv_counters.c)

#-------------------------------------------------------------------------------
# Test suite
#-------------------------------------------------------------------------------

set(UNIT_TEST_SUITE ${CMAKE_CURRENT_LIST_DIR}/test_nv_counters.c)

#-------------------------------------------------------------------------------
# Dependencies
#-------------------------------------------------------------------------------
execute_process(
    COMMAND ${CMAKE_COMMAND}
            -S ${TFM_ROOT_DIR}/tools
            -B ${GENERATED_FILES}
            -DTFM_MANIFEST_LIST=${TFM_ROOT_DIR}/tools/tfm_manifest_list.yaml
            -DTFM_ISOLATION_LEVEL=2
            -DCONFIG_TFM_SPM_BACKEND=IPC
    RESULT_VARIABLE result
)

if(NOT result EQUAL 0)
    message(FATAL_ERROR "Failed to configure TFM tools project")
endif()

#-------------------------------------------------------------------------------
# Include dirs
#-------------------------------------------------------------------------------
list(APPEND UNIT_TEST_INCLUDE_DIRS ${RSE_COMMON_SOURCE_DIR}/subplatform_pal_default_config)
list(APPEND UNIT_TEST_INCLUDE_DIRS ${RSE_COMMON_SOURCE_DIR}/unittests/include)
list(APPEND UNIT_TEST_INCLUDE_DIRS ${RSE_COMMON_SOURCE_DIR})
list(APPEND UNIT_TEST_INCLUDE_DIRS ${PLATFORM_DIR}/ext/target/arm/drivers/lcm)
list(APPEND UNIT_TEST_INCLUDE_DIRS ${PLATFORM_DIR}/include)
list(APPEND UNIT_TEST_INCLUDE_DIRS ${TFM_ROOT_DIR}/interface/include)
list(APPEND UNIT_TEST_INCLUDE_DIRS ${GENERATED_FILES}/generated/interface/include)

#-------------------------------------------------------------------------------
# Compiledefs for UUT
#-------------------------------------------------------------------------------
list(APPEND UNIT_TEST_COMPILE_DEFS PLATFORM_ERROR_CODES)
list(APPEND UNIT_TEST_COMPILE_DEFS MCUBOOT_HW_KEY)
list(APPEND UNIT_TEST_COMPILE_DEFS TFM_BL1_2_EMBED_ROTPK_IN_IMAGE)
list(APPEND UNIT_TEST_COMPILE_DEFS MCUBOOT_IMAGE_NUMBER=4)
list(APPEND UNIT_TEST_COMPILE_DEFS PLATFORM_HAS_PS_NV_OTP_COUNTERS)
list(APPEND UNIT_TEST_COMPILE_DEFS TFM_BL1_2_ROTPK_HASH_ALG=0) # sha256
list(APPEND UNIT_TEST_COMPILE_DEFS MCUBOOT_ROTPK_HASH_ALG=0)
list(APPEND UNIT_TEST_COMPILE_DEFS RSE_AMOUNT=1)
# TODO: add a test flavor
# list(APPEND UNIT_TEST_COMPILE_DEFS RSE_BIT_PROGRAMMABLE_OTP)

#-------------------------------------------------------------------------------
# Link libs for UUT
#-------------------------------------------------------------------------------

#-------------------------------------------------------------------------------
# Mocks for UUT
#-------------------------------------------------------------------------------
list(APPEND MOCK_HEADERS ${PLATFORM_DIR}/include/tfm_plat_otp.h)
list(APPEND MOCK_HEADERS ${RSE_COMMON_SOURCE_DIR}/rse_permanently_disable_device.h)
list(APPEND MOCK_HEADERS ${RSE_COMMON_SOURCE_DIR}/rse_nv_counter_mapping.h)

#-------------------------------------------------------------------------------
# Labels for UT (Optional, tests can be grouped by labels)
#-------------------------------------------------------------------------------
list(APPEND UT_LABELS "COMMON")
