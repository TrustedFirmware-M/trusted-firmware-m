#-------------------------------------------------------------------------------
# Copyright (c) 2023, Nordic Semiconductor ASA.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

cmake_policy(SET CMP0076 NEW)
set(CMAKE_CURRENT_SOURCE_DIR ${CMAKE_CURRENT_LIST_DIR})
set(NRF_BOARD_SELECTED True)

add_library(platform_ns STATIC)

# Get the value of HAL_NORDIC_PATH
include(${CMAKE_CURRENT_LIST_DIR}/common/core/config_nordic_nrf_spe.cmake)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/common/nrf91 nrf91)

target_include_directories(platform_region_defs
    INTERFACE
        ${CMAKE_CURRENT_LIST_DIR}/common/nrf91/partition
)

target_include_directories(platform_ns
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
)

target_link_libraries(platform_ns
    PUBLIC
        platform_region_defs
)
