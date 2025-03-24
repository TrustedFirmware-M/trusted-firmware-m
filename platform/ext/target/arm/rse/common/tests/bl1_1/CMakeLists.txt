#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

cmake_policy(SET CMP0079 NEW)

target_sources(tfm_test_suite_extra_bl1_1
    PRIVATE
        ./bl1_1_test.c
        ./rse_provisioning_tests.c
        ./test_state_transitions.c
        ../rse_test_common.c
)

target_include_directories(tfm_test_suite_extra_bl1_1
    PRIVATE
        .
        ..
)

target_link_libraries(tfm_test_suite_extra_bl1_1
    PRIVATE
        bl1_cc3xx_tests
        bl1_1_shared_lib_interface
)

if (TEST_DCSU_DRV)
    add_subdirectory(
        ${CMAKE_SOURCE_DIR}/platform/ext/target/arm/drivers/dcsu/tests
        ${CMAKE_CURRENT_BINARY_DIR}/dcsu/tests
    )

    target_link_libraries(tfm_test_suite_extra_bl1_1
        PRIVATE
            bl1_dcsu_drv_tests
    )
endif()
