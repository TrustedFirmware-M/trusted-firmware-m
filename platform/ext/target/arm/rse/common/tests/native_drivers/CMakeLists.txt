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
        ./test_atu_rse_common.c
        ./test_atu_rse_drv.c
        ./test_atu_rse_lib.c
)

target_include_directories(bl1_native_driver_tests
    INTERFACE
        .
        ../../device/include
)
