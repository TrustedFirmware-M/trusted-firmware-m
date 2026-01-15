#-------------------------------------------------------------------------------
# Copyright (c) 2020-2022, Arm Limited. All rights reserved.
# Copyright (c) 2020, Nordic Semiconductor ASA.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------
cmake_policy(SET CMP0076 NEW)
set(CMAKE_CURRENT_SOURCE_DIR ${CMAKE_CURRENT_LIST_DIR})

set(target nrf54l)
add_subdirectory(../core nrf_common)

#========================= Platform Secure ====================================#

target_include_directories(platform_s
    PUBLIC
        .
	../nrf54l
)

if(NOT NRF_DIR)
    target_include_directories(platform_s
        PUBLIC
            memory_service_ranges
)
endif()

target_sources(platform_s
    PRIVATE
        ${HAL_NORDIC_PATH}/nrfx/bsp/stable/mdk/system_nrf54l.c
        ../nrf54l/nrf54l_init.c
)

target_compile_definitions(platform_s
    PUBLIC
        NRF_SKIP_FICR_NS_COPY_TO_RAM
)

#========================= tfm_spm ============================================#

target_sources(tfm_spm
    PRIVATE
        $<$<OR:$<BOOL:${CONFIG_TFM_FLIH_API}>,$<BOOL:${CONFIG_TFM_SLIH_API}>>:${CMAKE_CURRENT_SOURCE_DIR}/../nrf54l/tfm_interrupts.c>
)

#========================= Files for building NS side platform ================#

install(FILES       ../nrf54l/config.cmake
                    ns/CMakeLists.txt
                    cpuarch.cmake
        DESTINATION ${INSTALL_PLATFORM_NS_DIR}/common/nrf54lm20b
)

install(DIRECTORY    partition
                     tests
        DESTINATION  ${INSTALL_PLATFORM_NS_DIR}/common/nrf54lm20b
)
