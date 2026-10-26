#-------------------------------------------------------------------------------
# Copyright (c) 2026, STMicroelectronics - All Rights Reserved
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

# set family platform config
if (EXISTS ${STM_FAMILY_DIR}/config.cmake)
	include(${STM_FAMILY_DIR}/config.cmake)
endif()

# set specific stm32mp21 config
#========================= STM32 ==============================================#
set(STM32_BOARD_MODEL           "stm32mp21xxxx" CACHE STRING   "Define board model name" FORCE)

set(STM32_HEADER_MINOR_VER      3               CACHE STRING    "Define stm32 header minor version: 0,3" FORCE)
