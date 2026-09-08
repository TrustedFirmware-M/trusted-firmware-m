#-------------------------------------------------------------------------------
# Copyright (c) 2026, STMicroelectronics - All Rights Reserved
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

execute_process(
    COMMAND git describe --tags --always
    WORKING_DIRECTORY ${STM_SOC_DIR}
    OUTPUT_VARIABLE STM32_VERSION_FULL
    OUTPUT_STRIP_TRAILING_WHITESPACE)

if(BL2)
    get_filename_component(STM32_VER_BL2_DTS ${bl2_DTS_BOARD} NAME)
endif()

get_filename_component(STM32_VER_S_DTS ${tfm_s_DTS_BOARD} NAME)

# Generate board model
dump_options("model"
    "
    STM32_VERSION_FULL;
    STM32_VER_BL2_DTS;
    STM32_VER_S_DTS;
    STM32_BOARD_MODEL;
    STM32_BOOT_DEV
    "
)

if(NOT "${STM32_VERSION_FULL}" STREQUAL "${STM32_GIT_VERSION}")
    file(REMOVE ${CMAKE_BINARY_DIR}/generated/stm_version.h)
endif()

configure_file(${STM_FAMILY_DIR}/stm_version.h.in
               ${CMAKE_BINARY_DIR}/generated/stm_version.h)

set(STM32_GIT_VERSION        "${STM32_VERSION_FULL}"        CACHE STRING  "stm32 git version")
