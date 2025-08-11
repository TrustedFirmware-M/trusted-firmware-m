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
set(B_U585I_IOT02A_DIR ${CMAKE_CURRENT_LIST_DIR})
set(STM_COMMON_DIR ${B_U585I_IOT02A_DIR}/../common)

#def for stm32u5xx
include(${STM_COMMON_DIR}/stm32u5xx/CMakeLists.txt)
#========================= Platform defs ===============================#

# Specify the location of platform specific build dependencies.
target_sources(tfm_s
    PRIVATE
        ${STM_COMMON_DIR}/stm32u5xx/Device/Source/startup_stm32u5xx_s.c
        ${STM_COMMON_DIR}/stm32u5xx/bl2/low_level_ospi_device.c
        ${STM_COMMON_DIR}/hal/CMSIS_Driver/low_level_ospi_flash.c
        ${STM_COMMON_DIR}/hal/Components/mx25lm51245g/mx25lm51245g.c
        ${B_U585I_IOT02A_DIR}/src/b_u585i_iot02a_ospi.c
)

if(STSAFEA)
    set(STSAFEA_INTERFACE_SRC_DIR ${B_U585I_IOT02A_DIR}/src/)
    include(${STM_COMMON_DIR}/secure_element/CMakeLists.txt)
endif()

# cpuarch.cmake is used to set things that related to the platform that are both
install(FILES
    ${TARGET_PLATFORM_PATH}/cpuarch.cmake
    DESTINATION ${INSTALL_PLATFORM_NS_DIR}
)

install(FILES
    ${STM_COMMON_DIR}/stm32u5xx/Device/Source/startup_stm32u5xx_ns.c
    DESTINATION ${INSTALL_PLATFORM_NS_DIR}/Device/Source
)

install(DIRECTORY
    ${TARGET_PLATFORM_PATH}/ns/
    DESTINATION ${INSTALL_PLATFORM_NS_DIR}
)

install(DIRECTORY
    ${TARGET_PLATFORM_PATH}/include
    DESTINATION ${INSTALL_PLATFORM_NS_DIR}
)

install(DIRECTORY
    ${STM_COMMON_DIR}/hal/accelerator/
    DESTINATION ${INSTALL_PLATFORM_NS_DIR}/include
    FILES_MATCHING PATTERN "*.h"
)

install(FILES
    ${B_U585I_IOT02A_DIR}/partition/flash_layout.h
    ${B_U585I_IOT02A_DIR}/partition/region_defs.h
    DESTINATION ${INSTALL_PLATFORM_NS_DIR}/partition
)

if(BL2)
    target_sources(bl2
        PRIVATE
            ${STM_COMMON_DIR}/stm32u5xx/Device/Source/startup_stm32u5xx_bl2.c
            ${STM_COMMON_DIR}/stm32u5xx/bl2/low_level_ospi_device.c
            ${STM_COMMON_DIR}/hal/CMSIS_Driver/low_level_ospi_flash.c
            ${STM_COMMON_DIR}/hal/Components/mx25lm51245g/mx25lm51245g.c
            ${STM_COMMON_DIR}/hal/provision/otp_provision.c
            ${STM_COMMON_DIR}/hal/provision/nvm_init.c
            ${STM_COMMON_DIR}/hal/provision/nvmcnt_init.c
            ${B_U585I_IOT02A_DIR}/src/b_u585i_iot02a_ospi.c
    )
endif()
#install flash layout for postbuild.sh
install(FILES
    ${B_U585I_IOT02A_DIR}/partition/flash_layout.h
    ${B_U585I_IOT02A_DIR}/partition/region_defs.h
    DESTINATION ${CMAKE_INSTALL_PREFIX}
)
set (BL2_FILE_TO_PREPROCESS ${CMAKE_CURRENT_BINARY_DIR}/image_macros_to_preprocess_bl2.c)
file(WRITE ${BL2_FILE_TO_PREPROCESS} ${BL2_PREPROCESSING})

install(FILES
    ${BL2_FILE_TO_PREPROCESS}
    DESTINATION ${CMAKE_INSTALL_PREFIX}
)
