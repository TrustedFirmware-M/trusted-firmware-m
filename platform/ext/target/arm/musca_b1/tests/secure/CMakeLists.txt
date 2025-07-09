#-------------------------------------------------------------------------------
# Copyright (c) 2025, Arm Limited. All rights reserved.
# Copyright (c) 2022 Cypress Semiconductor Corporation (an Infineon company)
# or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

cmake_policy(SET CMP0079 NEW)

if(NOT TFM_PARTITION_CRYPTO)
    return()
endif()

message(STATUS "Enabling MUSCA_B1 Tests in the Secure tests")

target_sources(tfm_test_suite_extra_s
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/secure_test.c
)

target_include_directories(tfm_test_suite_extra_s
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(tfm_test_suite_extra_s
    PRIVATE
        crypto_service_cc3xx_tests
)
