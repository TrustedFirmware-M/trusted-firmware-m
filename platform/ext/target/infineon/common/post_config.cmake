#-------------------------------------------------------------------------------
# Copyright (c) 2023-2024 Cypress Semiconductor Corporation (an Infineon company)
# or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

# Set platform specific configs that depend on default configs provided by TF-M.

#################################### IFX #######################################

if(IFX_MTB_BUILD AND (NOT TFM_SPM_LOG_RAW_ENABLED) AND (NOT TFM_SP_LOG_RAW_ENABLED))
    set(IFX_UART_ENABLED  OFF  CACHE BOOL  "Enable UART used by SPM log, partition log and/or platform service")
else()
    set(IFX_UART_ENABLED  ON   CACHE BOOL  "Enable UART used by SPM log, partition log and/or platform service")
endif()
