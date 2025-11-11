#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

# Load the default extra configs about generated files and secure partitions
include(${CMAKE_SOURCE_DIR}/config/extra_build_config.cmake)

if(CONFIG_TFM_TEST_CONFIG_FILE)
    if(NOT IS_ABSOLUTE "${CONFIG_TFM_TEST_CONFIG_FILE}")
        message(SEND_ERROR "CONFIG_TFM_TEST_CONFIG_FILE is not an absolute path:")
        message(SEND_ERROR "${CONFIG_TFM_TEST_CONFIG_FILE}")
        message(SEND_ERROR "Configuration might fail.")
    endif()

    # Include platform specific regression tests preference at first
    include(${TARGET_PLATFORM_PATH}/tests/tfm_tests_config.cmake OPTIONAL)
    # Then include the test configuration specified by users
    include(${CONFIG_TFM_TEST_CONFIG_FILE})
endif()

if(CONFIG_PSA_ARCH_TESTS_CONFIG_FILE)
    if(NOT IS_ABSOLUTE "${CONFIG_PSA_ARCH_TESTS_CONFIG_FILE}")
        message(SEND_ERROR "CONFIG_PSA_ARCH_TESTS_CONFIG_FILE is not an absolute path:")
        message(SEND_ERROR "${CONFIG_PSA_ARCH_TESTS_CONFIG_FILE}")
        message(SEND_ERROR "Configuration might fail.")
    endif()

    # Include platform specific psa arch tests preference at first
    include(${TARGET_PLATFORM_PATH}/tests/psa_arch_tests_config.cmake OPTIONAL)
    # Then include the test configuration specified by users
    include(${CONFIG_PSA_ARCH_TESTS_CONFIG_FILE})
endif()

# Load defaults, setting options not already set
include(config/config_base.cmake)

# Build system log config
include(${CMAKE_SOURCE_DIR}/config/tfm_build_log_config.cmake)

# The library to collect compile definitions of config options.
add_library(tfm_config INTERFACE)

target_compile_definitions(tfm_config
    INTERFACE
        $<$<STREQUAL:${TEST_PSA_API},CRYPTO>:PSA_API_TEST_CRYPTO>
        $<$<STREQUAL:${TEST_PSA_API},IPC>:PSA_API_TEST_IPC>
)

# Set user defined TF-M config header file
if(PROJECT_CONFIG_HEADER_FILE)
    if(NOT EXISTS ${PROJECT_CONFIG_HEADER_FILE})
        message(FATAL_ERROR "${PROJECT_CONFIG_HEADER_FILE} does not exist! Please use absolute path.")
    endif()
    target_compile_definitions(tfm_config
        INTERFACE
            $<BUILD_INTERFACE:PROJECT_CONFIG_HEADER_FILE="${PROJECT_CONFIG_HEADER_FILE}">
    )
endif()

# Set platform defined TF-M config header file
set(TARGET_CONFIG_HEADER_FILE ${TARGET_PLATFORM_PATH}/config_tfm_target.h)
if(EXISTS ${TARGET_CONFIG_HEADER_FILE})
    target_compile_definitions(tfm_config
        INTERFACE
            $<BUILD_INTERFACE:TARGET_CONFIG_HEADER_FILE="${TARGET_CONFIG_HEADER_FILE}">
    )
endif()

target_include_directories(tfm_config
    INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}>
)
