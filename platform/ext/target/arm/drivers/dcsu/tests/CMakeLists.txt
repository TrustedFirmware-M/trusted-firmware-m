#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

add_library(bl1_dcsu_drv_tests INTERFACE)

target_sources(bl1_dcsu_drv_tests
    INTERFACE
        ./test_dcsu_drv.c
)

target_compile_definitions(bl1_dcsu_drv_tests
    INTERFACE
        TEST_DCSU_DRV
)

target_include_directories(bl1_dcsu_drv_tests
    INTERFACE
        ./include
)
