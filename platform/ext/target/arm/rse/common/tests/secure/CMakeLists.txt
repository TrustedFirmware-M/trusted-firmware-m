#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
# Copyright (c) 2022 Cypress Semiconductor Corporation (an Infineon company)
# or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

cmake_policy(SET CMP0079 NEW)

target_sources(tfm_test_suite_extra_s
    PRIVATE
        ./secure_test.c
        ../rse_test_common.c
)

target_include_directories(tfm_test_suite_extra_s
    PRIVATE
        .
        ..
)

target_link_libraries(tfm_test_suite_extra_s
    PRIVATE
        $<$<BOOL:${TEST_CC3XX}>:crypto_service_cc3xx_tests>
)
