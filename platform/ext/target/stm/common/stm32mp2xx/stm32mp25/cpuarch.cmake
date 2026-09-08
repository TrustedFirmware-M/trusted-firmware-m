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

# Set architecture and CPU
set(STM_SOC_DIR ${CMAKE_CURRENT_LIST_DIR})
include(${STM_SOC_DIR}/../cpuarch.cmake)

# Set specific stm32mp25 architecture
add_compile_definitions(
	STM32MP25xxxx
)
