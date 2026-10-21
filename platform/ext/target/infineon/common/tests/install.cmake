#-------------------------------------------------------------------------------
# (c) 2025-2026, Infineon Technologies AG, or an affiliate of Infineon
# Technologies AG. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------


################################# Tests install ################################

if (TFM_NS_REG_TEST OR TEST_PSA_API)
    install(FILES       $<$<OR:$<BOOL:${TFM_NS_REG_TEST}>,$<BOOL:${TEST_PSA_API}>>:${IFX_COMMON_SOURCE_DIR}/nspe/test/plat_test_ns.c>
            DESTINATION ${INSTALL_PLATFORM_NS_DIR}/ifx/tests)

    install(FILES       $<$<BOOL:${IFX_FAMILY_SOURCE_DIR}>:${IFX_FAMILY_SOURCE_DIR}/tests/tfm_tests_config.cmake>
                        ${IFX_PLATFORM_SOURCE_DIR}/tests/tfm_tests_config.cmake
            DESTINATION ${INSTALL_PLATFORM_NS_DIR}/tests
            OPTIONAL)
endif()

if (TEST_NS_FPU)
    install(FILES   ${IFX_COMMON_SOURCE_DIR}/nspe/test/ifx_fpu_ns.c
                    ${CMAKE_SOURCE_DIR}/platform/ext/common/test_interrupt.c
                    ${CMAKE_SOURCE_DIR}/platform/ext/common/test_interrupt.h
            DESTINATION ${INSTALL_PLATFORM_NS_DIR}/ifx/tests)
endif()
