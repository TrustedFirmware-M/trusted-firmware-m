#-------------------------------------------------------------------------------
# Copyright (c) 2023, Nordic Semiconductor ASA.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

cmake_policy(SET CMP0076 NEW)
set(CMAKE_CURRENT_SOURCE_DIR ${CMAKE_CURRENT_LIST_DIR})
set(NRF_BOARD_SELECTED True)

add_subdirectory(../common/nrf91 nrf91)

target_include_directories(platform_region_defs
    INTERFACE
        ../common/nrf91/partition
)

target_sources(platform_s
    PRIVATE
        $<$<BOOL:${TFM_PARTITION_PLATFORM}>:${CMAKE_CURRENT_SOURCE_DIR}/services/src/tfm_platform_system.c>
)

target_include_directories(platform_s
    PUBLIC
        .
        ../common/nrf91/partition
        services/include
)

if(BL2)
    target_include_directories(platform_bl2
        PUBLIC
            ../common/nrf91/partition
        PRIVATE
            .
    )
endif()

#========================= tfm_spm ============================================#

target_sources(tfm_spm
    PRIVATE
        tfm_hal_platform.c
)

#========================= Files for building NS side platform ================#

install(FILES       ../common/nrf9120/cpuarch.cmake
        DESTINATION ${INSTALL_PLATFORM_NS_DIR}/common/nrf9120
)

install(FILES       ${CMAKE_CURRENT_LIST_DIR}/ns/cpuarch_ns.cmake
        DESTINATION ${INSTALL_PLATFORM_NS_DIR}
        RENAME      cpuarch.cmake
)

if (TFM_PARTITION_PLATFORM)
    install(FILES       services/include/tfm_ioctl_api.h
            DESTINATION ${INSTALL_INTERFACE_INC_DIR}
    )
endif()

install(FILES       RTE_Device.h
                    device_cfg.h
                    ns/CMakeLists.txt
                    config.cmake
        DESTINATION ${INSTALL_PLATFORM_NS_DIR}
)

install(DIRECTORY   ../common/nrf91/partition
                    tests
        DESTINATION ${INSTALL_PLATFORM_NS_DIR}
)
