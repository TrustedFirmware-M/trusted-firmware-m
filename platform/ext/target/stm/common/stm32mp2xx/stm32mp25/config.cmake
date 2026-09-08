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

# set specific stm32mp25 config
#========================= STM32 ==============================================#
set(STM32_BOARD_MODEL           "stm32mp25xxxx" CACHE STRING   "Define board model name" FORCE)
set(STM32_STM32MP25_SOC_REV     "revY"          CACHE STRING   "Set soc revision: revY, revX")
