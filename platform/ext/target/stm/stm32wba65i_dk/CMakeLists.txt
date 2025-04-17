#-------------------------------------------------------------------------------
# Copyright (c) 2020, Arm Limited. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

cmake_policy(SET CMP0076 NEW)

if(POLICY CMP0115)
    cmake_policy(SET CMP0115 OLD)
endif()
set(STM32WBA65I_DK_DIR ${CMAKE_CURRENT_LIST_DIR})
set(STM_COMMON_DIR ${STM32WBA65I_DK_DIR}/../common)

#def for stm32wbaxx
include(${STM_COMMON_DIR}/stm32wbaxx/CMakeLists.txt)
#========================= Platform defs ===============================#

# Specify the location of platform specific build dependencies.
target_sources(tfm_s
    PRIVATE
        ${STM_COMMON_DIR}/stm32wbaxx/Device/Source/startup_stm32wbaxx_s.c
)

if(NS)
target_sources(${NS_TARGET_NAME}
        PRIVATE
            ${STM_COMMON_DIR}/stm32wbaxx/Device/Source/startup_stm32wbaxx_ns.c
    )
endif()

install(FILES
    ${STM32WBA65I_DK_DIR}/partition/flash_layout.h
    ${STM32WBA65I_DK_DIR}/partition/region_defs.h
    DESTINATION ${CMAKE_INSTALL_PREFIX}
)

set (BL2_FILE_TO_PREPROCESS ${CMAKE_CURRENT_BINARY_DIR}/image_macros_to_preprocess_bl2.c)
file(WRITE ${BL2_FILE_TO_PREPROCESS} ${BL2_PREPROCESSING})

install(FILES
    ${BL2_FILE_TO_PREPROCESS}
    DESTINATION ${CMAKE_INSTALL_PREFIX}
)
################# Install platform files for NS build #################

# cpuarch.cmake is used to set things that related to the platform that are both
install(FILES       ${TARGET_PLATFORM_PATH}/cpuarch.cmake
        DESTINATION ${INSTALL_PLATFORM_NS_DIR})

install(DIRECTORY   ${TARGET_PLATFORM_PATH}/ns/
        DESTINATION ${INSTALL_PLATFORM_NS_DIR})

install(DIRECTORY   ${TARGET_PLATFORM_PATH}/include
        DESTINATION ${INSTALL_PLATFORM_NS_DIR})

install(FILES       ${TARGET_PLATFORM_PATH}/accelerator/crypto_accelerator_config.h
DESTINATION ${INSTALL_PLATFORM_NS_DIR}/include)

install(DIRECTORY   ${STM_COMMON_DIR}/hal/accelerator/
        DESTINATION ${INSTALL_PLATFORM_NS_DIR}/include
        FILES_MATCHING PATTERN "*.h")

install(FILES
    ${STM32WBA65I_DK_DIR}/partition/flash_layout.h
    ${STM32WBA65I_DK_DIR}/partition/region_defs.h
    DESTINATION ${INSTALL_PLATFORM_NS_DIR}/partition
)

install(DIRECTORY   ${PLATFORM_DIR}/ext/common
                    ${PLATFORM_DIR}/ext/driver
        DESTINATION ${INSTALL_PLATFORM_NS_DIR}/ext)

# Install test configs
install(DIRECTORY   ${TARGET_PLATFORM_PATH}/tests
        DESTINATION ${INSTALL_PLATFORM_NS_DIR})