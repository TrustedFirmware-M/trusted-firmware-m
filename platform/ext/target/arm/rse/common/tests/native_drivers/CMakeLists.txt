#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

add_library(bl1_native_driver_tests INTERFACE)

target_sources(bl1_native_driver_tests
    INTERFACE
        ./test_integrity_checker_drv.c
)

target_include_directories(bl1_native_driver_tests
    INTERFACE
        .
)
