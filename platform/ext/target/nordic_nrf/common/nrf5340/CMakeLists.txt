#-------------------------------------------------------------------------------
# Copyright (c) 2020-2022, Arm Limited. All rights reserved.
# Copyright (c) 2020, Nordic Semiconductor ASA.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

cmake_policy(SET CMP0076 NEW)
set(CMAKE_CURRENT_SOURCE_DIR ${CMAKE_CURRENT_LIST_DIR})

set(target nrf5340)
add_subdirectory(../core nrf_common)

#========================= Platform Secure ====================================#

target_include_directories(platform_s
    PUBLIC
        .
)

if(NOT NRF_DIR)
target_include_directories(platform_s
    PUBLIC
        memory_service_ranges
)
endif()

target_sources(platform_s
    PRIVATE
        ${HAL_NORDIC_PATH}/nrfx/mdk/system_nrf5340_application.c
)

target_compile_definitions(platform_s
    PUBLIC
        NRF_SKIP_FICR_NS_COPY_TO_RAM
)

if(BL2)
    target_include_directories(platform_bl2
        PRIVATE
            .
    )

    target_sources(platform_bl2
        PRIVATE
            ${HAL_NORDIC_PATH}/nrfx/mdk/system_nrf5340_application.c
    )

    target_compile_definitions(platform_bl2
        PUBLIC
            NRF_SKIP_FICR_NS_COPY_TO_RAM
    )
endif()

#========================= tfm_spm ============================================#

target_sources(tfm_spm
    PRIVATE
        $<$<OR:$<BOOL:${CONFIG_TFM_FLIH_API}>,$<BOOL:${CONFIG_TFM_SLIH_API}>>:${CMAKE_CURRENT_SOURCE_DIR}/tfm_interrupts.c>
)

#========================= Files for building NS side platform ================#

install(FILES       nrfx_config_nrf5340_application.h
                    ns/CMakeLists.txt
                    config.cmake
                    cpuarch.cmake
        DESTINATION ${INSTALL_PLATFORM_NS_DIR}/common/nrf5340
)

install(DIRECTORY    tests
                     partition
        DESTINATION  ${INSTALL_PLATFORM_NS_DIR}/common/nrf5340
)
