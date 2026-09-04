#-------------------------------------------------------------------------------
# (c) 2026, Infineon Technologies AG, or an affiliate of Infineon
# Technologies AG. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

include(${IFX_COMMON_SOURCE_DIR}/install.cmake)

install(FILES       ${IFX_PLATFORM_SOURCE_DIR}/nspe/CMakeLists.txt
                    ${IFX_PLATFORM_SOURCE_DIR}/nspe/cpuarch.cmake
        DESTINATION ${INSTALL_PLATFORM_NS_DIR})

configure_file(${IFX_PLATFORM_SOURCE_DIR}/nspe/config.cmake.in
               ${CMAKE_BINARY_DIR}/generated/platform/cmake/config.cmake @ONLY)
install(FILES       ${CMAKE_BINARY_DIR}/generated/platform/cmake/config.cmake
        DESTINATION ${INSTALL_PLATFORM_NS_DIR})

install(DIRECTORY   ${IFX_PLATFORM_SOURCE_DIR}/shared
        DESTINATION ${INSTALL_PLATFORM_NS_DIR})

if (NOT PLATFORM_DEFAULT_CRYPTO_KEYS)
    # Platform specific key IDs header
    install(FILES       ${IFX_PLATFORM_SOURCE_DIR}/spe/services/crypto/tfm_builtin_key_ids.h
            DESTINATION ${INSTALL_INTERFACE_INC_DIR})
endif()
