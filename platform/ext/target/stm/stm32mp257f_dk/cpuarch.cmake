#-------------------------------------------------------------------------------
# Copyright (c) 2026, STMicroelectronics - All Rights Reserved
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

# cpuarch.cmake is used to set things that related to the cpu architecture that are both
# immutable and global, which is to say they should apply to any kind of project
# that uses this platform. In practise this is normally compiler definitions and
# variables related to hardware.

# set platform directory
set(STM_BOARD_DIR ${CMAKE_CURRENT_LIST_DIR})
if (TARGET_PATH)
set(STM_DIR ${TARGET_PATH}/stm)
else()
set(STM_DIR ${STM_BOARD_DIR}/..)
endif()

set(STM32_SOC_NAME  STM32MP257Fxx           CACHE STRING    "Define SoC model name" FORCE)

include(${STM_DIR}/common/stm32mp2xx/stm32mp25/cpuarch.cmake)

add_compile_definitions(
    ${STM32_SOC_NAME}
)
