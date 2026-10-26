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

# STM32MP21 restriction
