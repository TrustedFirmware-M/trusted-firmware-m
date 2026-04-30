#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

# Define what is being unit tested and by what
set(UNIT_UNDER_TEST ${TFM_ROOT_DIR}/lib/gpt/src/gpt.c)
set(UNIT_TEST_SUITE ${CMAKE_CURRENT_LIST_DIR}/test_gpt.c)

# Dependencies for the UUT, that get linked into the executable
list(APPEND UNIT_TEST_DEPS ${TFM_ROOT_DIR}/lib/tfm_log/src/tfm_log.c)
list(APPEND UNIT_TEST_DEPS ${TFM_ROOT_DIR}/lib/tfm_vprintf/src/tfm_vprintf.c)
list(APPEND UNIT_TEST_DEPS ${TFM_ROOT_DIR}/lib/gpt/src/io/gpt_io.c)
list(APPEND UNIT_TEST_DEPS ${TFM_ROOT_DIR}/lib/gpt/src/io/gpt_io_read.c)
list(APPEND UNIT_TEST_DEPS ${TFM_ROOT_DIR}/lib/gpt/src/io/gpt_io_read_rw.c)
list(APPEND UNIT_TEST_DEPS ${TFM_ROOT_DIR}/lib/gpt/src/io/gpt_io_write.c)
list(APPEND UNIT_TEST_DEPS ${TFM_ROOT_DIR}/lib/gpt/src/gpt_defs.c)

# Include directories for compilation
list(APPEND UNIT_TEST_INCLUDE_DIRS ${TFM_ROOT_DIR}/lib/gpt/unittests/include)
list(APPEND UNIT_TEST_INCLUDE_DIRS ${TFM_ROOT_DIR}/interface/include)
list(APPEND UNIT_TEST_INCLUDE_DIRS ${TFM_ROOT_DIR}/lib/efi_guid/inc)
list(APPEND UNIT_TEST_INCLUDE_DIRS ${TFM_ROOT_DIR}/lib/gpt/inc)
list(APPEND UNIT_TEST_INCLUDE_DIRS ${TFM_ROOT_DIR}/lib/gpt/src)
list(APPEND UNIT_TEST_INCLUDE_DIRS ${TFM_ROOT_DIR}/lib/ext/efi_soft_crc/inc)
list(APPEND UNIT_TEST_INCLUDE_DIRS ${TFM_ROOT_DIR}/lib/tfm_log/inc)
list(APPEND UNIT_TEST_INCLUDE_DIRS ${TFM_ROOT_DIR}/lib/tfm_vprintf/inc)

# Headers to be mocked
list(APPEND MOCK_HEADERS ${TFM_ROOT_DIR}/lib/efi_guid/inc/efi_guid.h)
list(APPEND MOCK_HEADERS ${TFM_ROOT_DIR}/lib/ext/efi_soft_crc/inc/efi_soft_crc.h)

# Compile-time definitions
list(APPEND UNIT_TEST_COMPILE_DEFS LOG_LEVEL=LOG_LEVEL_VERBOSE)
list(APPEND UNIT_TEST_COMPILE_DEFS TFM_GPT_BLOCK_SIZE=512)
