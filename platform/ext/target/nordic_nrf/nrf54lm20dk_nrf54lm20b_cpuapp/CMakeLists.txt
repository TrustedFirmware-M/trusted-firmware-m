#-------------------------------------------------------------------------------
# Copyright (c) 2020, Nordic Semiconductor ASA.
# Copyright (c) 2022, Arm Limited. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

cmake_policy(SET CMP0076 NEW)
set(CMAKE_CURRENT_SOURCE_DIR ${CMAKE_CURRENT_LIST_DIR})
set(NRF_BOARD_SELECTED True)

add_subdirectory(../common/nrf54lm20b nrf54lm20b)

target_include_directories(platform_region_defs
    BEFORE INTERFACE
        ../common/nrf54lm20b/partition
)

target_sources(platform_s
    PRIVATE
        $<$<BOOL:${TFM_PARTITION_PLATFORM}>:${CMAKE_CURRENT_SOURCE_DIR}/services/src/tfm_platform_system.c>
)

target_include_directories(platform_s
    PUBLIC
        .
        ../common/nrf54lm20b/partition
        services/include
)

#========================= tfm_spm ============================================#

target_sources(tfm_spm
    PRIVATE
        tfm_hal_platform.c
)

#========================= Files for building NS side platform ================#

install(FILES       ${CMAKE_CURRENT_LIST_DIR}/ns/cpuarch_ns.cmake
        DESTINATION ${INSTALL_PLATFORM_NS_DIR}
        RENAME      cpuarch.cmake)

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

install(DIRECTORY   tests
        DESTINATION ${INSTALL_PLATFORM_NS_DIR}
)
