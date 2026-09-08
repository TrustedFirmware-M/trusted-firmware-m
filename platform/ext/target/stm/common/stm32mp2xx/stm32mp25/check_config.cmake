#-------------------------------------------------------------------------------
# Copyright (c) 2026, STMicroelectronics - All Rights Reserved
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

# set family platform config
if (EXISTS ${STM_FAMILY_DIR}/check_config.cmake)
	include(${STM_FAMILY_DIR}/check_config.cmake)
endif()

# STM32MP25 restriction
tfm_invalid_config((NOT STM32_STM32MP25_SOC_REV STREQUAL "revX") AND (NOT STM32_STM32MP25_SOC_REV STREQUAL "revY"))
