#-------------------------------------------------------------------------------
# Copyright (c) 2021-2026, Arm Limited. All rights reserved.
# Copyright (c) 2022 Cypress Semiconductor Corporation (an Infineon company)
# or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

cmake_policy(SET CMP0079 NEW)

####################### Secure #################################################

target_sources(tfm_test_suite_extra_s
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/s_test.c
        ${CMAKE_CURRENT_SOURCE_DIR}/s_io_storage_test.c
        ../Native_Driver/firewall.c
)

target_include_directories(tfm_test_suite_extra_s
    PRIVATE
        ../Device/Include
        ../Native_Driver
)

target_link_libraries(tfm_test_suite_extra_s
    PRIVATE
        tfm_sprt
)

target_compile_definitions(tfm_test_suite_extra_s
    PRIVATE
        $<$<BOOL:${PLATFORM_IS_FVP}>:PLATFORM_IS_FVP>
)

target_compile_options(tfm_test_suite_extra_s PRIVATE -Wno-int-conversion)
