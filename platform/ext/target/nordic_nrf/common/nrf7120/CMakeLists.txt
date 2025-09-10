#-------------------------------------------------------------------------------
# Copyright (c) 2020-2022, Arm Limited. All rights reserved.
# Copyright (c) 2025, Nordic Semiconductor ASA.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------
cmake_policy(SET CMP0076 NEW)
set(CMAKE_CURRENT_SOURCE_DIR ${CMAKE_CURRENT_LIST_DIR})

set(target nrf7120)
add_subdirectory(../core nrf_common)

#========================= Platform Secure ====================================#

target_include_directories(platform_s
    PUBLIC
        .
)

target_sources(platform_s
    PRIVATE
        ${HAL_NORDIC_PATH}/nrfx/mdk/system_nrf7120_enga.c
        ./nrf71_init.c
)

target_compile_definitions(platform_s
    PUBLIC
        NRF_SKIP_FICR_NS_COPY_TO_RAM
)

#========================= tfm_spm ============================================#

target_sources(tfm_spm
    PRIVATE
        $<$<OR:$<BOOL:${CONFIG_TFM_FLIH_API}>,$<BOOL:${CONFIG_TFM_SLIH_API}>>:${CMAKE_CURRENT_SOURCE_DIR}/tfm_interrupts.c>
)

#========================= Files for building NS side platform ================#

install(FILES       ./nrfx_config_nrf71.h
                    ./config.cmake
                    ns/CMakeLists.txt
                    cpuarch.cmake
        DESTINATION ${INSTALL_PLATFORM_NS_DIR}/common/nrf7120
)

install(DIRECTORY    partition
                     tests
        DESTINATION  ${INSTALL_PLATFORM_NS_DIR}/common/nrf7120
)
