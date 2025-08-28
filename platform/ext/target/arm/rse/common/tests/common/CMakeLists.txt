#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

add_library(bl1_common_tests INTERFACE)

target_sources(bl1_common_tests
    INTERFACE
        ./test_nv_counters.c
        ./test_rse_zero_count.c
        ./test_otp_lcm.c
        ./test_dpa_hardened_word_copy.c
)

target_include_directories(bl1_common_tests
    INTERFACE
        .
)
