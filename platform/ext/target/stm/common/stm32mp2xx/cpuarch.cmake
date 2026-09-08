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
set(TFM_SYSTEM_PROCESSOR cortex-m33)
set(TFM_SYSTEM_ARCHITECTURE armv8-m.main)
set(CONFIG_TFM_ENABLE_CP10CP11 ON)
set(STM_COMMON_DIR ${STM_DIR}/common)
set(STM_DEVICETREE_DIR ${STM_COMMON_DIR}/devicetree)
set(STM_FAMILY_DIR ${CMAKE_CURRENT_LIST_DIR})
set(CRYPTO_HW_ACCELERATOR_TYPE stm32mp2)

add_compile_definitions(
	STM32MP2
	CORE_CM33
)
