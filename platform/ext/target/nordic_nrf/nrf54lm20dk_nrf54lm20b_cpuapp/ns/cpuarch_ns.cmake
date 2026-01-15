#-------------------------------------------------------------------------------
# Copyright (c) 2024, Nordic Semiconductor ASA.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

set(PLATFORM_DIR  ${CMAKE_CURRENT_LIST_DIR})
set(PLATFORM_PATH ${CMAKE_CURRENT_LIST_DIR})

add_compile_definitions(NRF_CONFIG_CPU_FREQ_MHZ=128)

include(${CMAKE_CURRENT_LIST_DIR}/common/nrf54lm20b/cpuarch.cmake)
