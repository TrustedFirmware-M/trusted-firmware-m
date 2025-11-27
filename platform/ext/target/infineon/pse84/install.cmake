#-------------------------------------------------------------------------------
# Copyright (c) 2023-2025 Cypress Semiconductor Corporation (an Infineon company)
# or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------


include(${IFX_COMMON_SOURCE_DIR}/install.cmake)

if (IFX_MTB_BUILD)
    install(FILES       ${IFX_COMMON_SOURCE_DIR}/mtb/config/PSE84.mk
            DESTINATION ${CMAKE_INSTALL_PREFIX}/config)
    if(EXISTS "${IFX_COMMON_SOURCE_DIR}/mtb/config/PSE84-EPC4.mk")
        install(FILES   ${IFX_COMMON_SOURCE_DIR}/mtb/config/PSE84-EPC4.mk
                DESTINATION ${CMAKE_INSTALL_PREFIX}/config)
    endif()
    if(EXISTS "${IFX_COMMON_SOURCE_DIR}/mtb/config/PSE84-EPC2.mk")
        install(FILES   ${IFX_COMMON_SOURCE_DIR}/mtb/config/PSE84-EPC2.mk
                DESTINATION ${CMAKE_INSTALL_PREFIX}/config)
    endif()
endif()

if (NOT PLATFORM_DEFAULT_CRYPTO_KEYS)
    # Platform specific key IDs header
    install(FILES       ${IFX_PLATFORM_SOURCE_DIR}/spe/services/crypto/tfm_builtin_key_ids.h
            DESTINATION ${INSTALL_INTERFACE_INC_DIR})
endif()

if (TEST_NS_IFX_CRYPTO_BENCHMARK OR TEST_NS_IFX_EPC_VALIDATION)
    install(FILES       ${IFX_PLATFORM_SOURCE_DIR}/spe/services/crypto/mbedtls_target_config_pse84.h
            DESTINATION ${INSTALL_PLATFORM_NS_DIR}/tests)
endif()

install(FILES       ${IFX_FAMILY_SOURCE_DIR}/nspe/CMakeLists.txt
                    ${IFX_FAMILY_SOURCE_DIR}/nspe/cpuarch.cmake
        DESTINATION ${INSTALL_PLATFORM_NS_DIR})

configure_file(${IFX_FAMILY_SOURCE_DIR}/nspe/config.cmake.in
               ${INSTALL_PLATFORM_NS_DIR}/config.cmake @ONLY)

install(DIRECTORY   ${IFX_FAMILY_SOURCE_DIR}/shared
        DESTINATION ${INSTALL_PLATFORM_NS_DIR}/pse84)

install(FILES       ${IFX_PLATFORM_SOURCE_DIR}/ifx_platform_config.h
        DESTINATION ${INSTALL_PLATFORM_NS_DIR}/include)
