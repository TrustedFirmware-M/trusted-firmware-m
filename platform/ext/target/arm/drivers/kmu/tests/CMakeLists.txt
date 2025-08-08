#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------
add_library(driver_kmu_tests INTERFACE)

target_sources(driver_kmu_tests
    INTERFACE
        ./test_drivers_kmu.c
)
target_include_directories(driver_kmu_tests
    INTERFACE
        ./
)
