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
        ./test_bl1_rse_kmu_keys.c
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

        driver_kmu_tests

        bl1_common_tests
        bl1_native_driver_tests
)

add_subdirectory(
    ${CMAKE_CURRENT_SOURCE_DIR}/../native_drivers/
    ${CMAKE_CURRENT_BINARY_DIR}/native_drivers/tests
)

add_subdirectory(
    ${CMAKE_CURRENT_SOURCE_DIR}/../common/
    ${CMAKE_CURRENT_BINARY_DIR}/common/tests
)

add_subdirectory(
    ${CMAKE_SOURCE_DIR}/platform/ext/target/arm/drivers/kmu/tests
    ${CMAKE_CURRENT_BINARY_DIR}/drivers/tests
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
