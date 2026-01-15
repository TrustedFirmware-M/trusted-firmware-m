#-------------------------------------------------------------------------------
# Copyright (c) 2020, Nordic Semiconductor ASA.
# Copyright (c) 2020-2023, Arm Limited. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

include(${PLATFORM_PATH}/common/nrf54l/config.cmake)

# Override UART instance for nRF54LM20B - it uses UART30, not UART20
set(NRF_SECURE_UART_INSTANCE            30         CACHE STRING    "The UART instance number to use for secure UART" FORCE)
