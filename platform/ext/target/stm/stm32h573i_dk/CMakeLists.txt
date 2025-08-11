#-------------------------------------------------------------------------------
# Copyright (c) 2020-2024, Arm Limited. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

cmake_policy(SET CMP0076 NEW)

set(STM32H573I_DK_DIR ${CMAKE_CURRENT_LIST_DIR})
set(STM_COMMON_DIR ${STM32H573I_DK_DIR}/../common)

#def for stm32h5xx
include(${STM_COMMON_DIR}/stm32h5xx/CMakeLists.txt)
#========================= Platform defs ===============================#

# Specify the location of platform specific build dependencies.
target_sources(tfm_s
    PRIVATE
        ${STM_COMMON_DIR}/stm32h5xx/Device/Source/startup_stm32h5xx_s.c
)

if(NS)
    target_sources(platform_ns
        PRIVATE
            ${STM_COMMON_DIR}/stm32h5xx/Device/Source/startup_stm32h5xx_ns.c
    )
endif()

if(BL2)
    target_sources(bl2
        PRIVATE
            ${STM_COMMON_DIR}/stm32h5xx/Device/Source/startup_stm32h5xx_bl2.c
            ${STM_COMMON_DIR}/hal/provision/otp_provision.c
            ${STM_COMMON_DIR}/hal/provision/nvm_init.c
            ${STM_COMMON_DIR}/hal/provision/nvmcnt_init.c
    )
endif()

install(FILES
    ${STM32H573I_DK_DIR}/include/flash_layout.h
    ${STM32H573I_DK_DIR}/include/region_defs.h
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

install(DIRECTORY   ${STM_COMMON_DIR}/hal/accelerator/
        DESTINATION ${INSTALL_PLATFORM_NS_DIR}/include
        FILES_MATCHING PATTERN "*.h")

install(DIRECTORY   ${PLATFORM_DIR}/ext/common
        DESTINATION ${INSTALL_PLATFORM_NS_DIR}/ext)

# Install test configs
install(DIRECTORY   ${TARGET_PLATFORM_PATH}/tests
        DESTINATION ${INSTALL_PLATFORM_NS_DIR})
