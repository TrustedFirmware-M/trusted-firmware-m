#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

cmake_minimum_required(VERSION 3.21)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
include(version)
include(remote_library)
include(utils)

if(EXISTS ${CMAKE_SOURCE_DIR}/localrepos.cmake)
    message(WARNING "Building using local repositories from \"" ${CMAKE_SOURCE_DIR}/localrepos.cmake "\"")
    include(${CMAKE_SOURCE_DIR}/localrepos.cmake)
endif()

############################ CONFIGURATION #####################################

set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE BOOL "" FORCE)

include(config/pre_config.cmake)

if(USE_KCONFIG_TOOL)
    include(${CMAKE_SOURCE_DIR}/config/kconfig.cmake)
else()
    include(${CMAKE_SOURCE_DIR}/config/set_config.cmake)
endif()

include(config/post_config.cmake)

############################### Compiler configuration #########################

include(${TFM_TOOLCHAIN_FILE})

project("Trusted Firmware M" VERSION ${TFM_VERSION} LANGUAGES C CXX ASM)

add_subdirectory(lib/ext)

if(BL2)
    add_subdirectory(bl2)
endif()

add_subdirectory(lib/backtrace)

add_subdirectory(lib/fih)
add_subdirectory(lib/tfm_log)
add_subdirectory(lib/tfm_log_unpriv)
add_subdirectory(lib/tfm_vprintf)
add_subdirectory(lib/tfm_helper_lib)
add_subdirectory(tools)
add_subdirectory(secure_fw)
add_subdirectory(interface)

if(BL1 AND PLATFORM_DEFAULT_BL1)
    add_subdirectory(bl1/bl1_2)
    add_subdirectory(bl1/bl1_1)
endif()

add_subdirectory(platform)

if(CRYPTO_HW_ACCELERATOR)
    add_subdirectory(platform/ext/accelerator)
endif()

if(IS_DIRECTORY ${CONFIG_TFM_TEST_DIR})
    add_subdirectory(${CONFIG_TFM_TEST_DIR} ${CMAKE_CURRENT_BINARY_DIR}/tf-m-tests)
endif()

############################ Config Check ######################################

include(${CMAKE_SOURCE_DIR}/config/check_config.cmake)

################################################################################

include(install)
