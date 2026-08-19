#-------------------------------------------------------------------------------
# Copyright (c) 2020, Nordic Semiconductor ASA.
# Copyright (c) 2020-2023, Arm Limited. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

set(HAS_NVMC 1)

include(${PLATFORM_PATH}/common/core/config.cmake)

set(NRF_SECURE_UART_INSTANCE            1         CACHE STRING    "The UART instance number to use for secure UART")