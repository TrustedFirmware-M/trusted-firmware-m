#-------------------------------------------------------------------------------
# Copyright (c) 2020-2022, Arm Limited. All rights reserved.
# Copyright (c) 2020, Nordic Semiconductor ASA.
# Copyright (c) 2021, Laird Connectivity.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

cmake_policy(SET CMP0076 NEW)
set(CMAKE_CURRENT_SOURCE_DIR ${CMAKE_CURRENT_LIST_DIR})

set(NRF_FOLDER_PATH ${NRF_PLATFORM_PATH}/common/core)
set(NRF5340_FOLDER_PATH ${NRF_PLATFORM_PATH}/common/nrf5340)

#========================= Platform dependencies ===============================#

include(${NRF_FOLDER_PATH}/hal_nordic.cmake)

#========================= Platform common defs ===============================#

# Specify the location of platform specific build dependencies.

target_add_scatter_file(tfm_s
    $<$<C_COMPILER_ID:GNU>:${CMAKE_BINARY_DIR}/generated/platform/ext/common/gcc/tfm_common_s.ld>
)

target_sources(tfm_s
    PRIVATE
    ${NRF_FOLDER_PATH}/startup.c
)

if(NS)
    target_add_scatter_file(tfm_ns
        $<$<C_COMPILER_ID:GNU>:${PLATFORM_DIR}/ext/common/gcc/tfm_common_ns.ld>
    )
    target_link_libraries(CMSIS_5_tfm_ns
        INTERFACE
            CMSIS_5_RTX_V8MMN
    )
    target_sources(tfm_ns
        PRIVATE
            ${NRF_FOLDER_PATH}/startup.c
    )
endif()

if(BL2)
    target_add_scatter_file(bl2
        $<$<C_COMPILER_ID:GNU>:${PLATFORM_DIR}/ext/common/gcc/tfm_common_bl2.ld>
    )
endif()

#========================= Platform Secure ====================================#

target_include_directories(platform_s
    PUBLIC
        .
        ${NRF5340_FOLDER_PATH}
        ${NRF_FOLDER_PATH}/native_drivers
        ${HAL_NORDIC_PATH}/nrfx
        ${HAL_NORDIC_PATH}/nrfx/mdk
        ${HAL_NORDIC_PATH}/nrfx/drivers/include
        ${NRF_FOLDER_PATH}/common
        ${NRF_FOLDER_PATH}/services/include
        ${PLATFORM_DIR}/..
)

target_sources(platform_s
    PRIVATE
        ${NRF_FOLDER_PATH}/cmsis_drivers/Driver_Flash.c
        cmsis_drivers/Driver_QSPI.c
        ${HAL_NORDIC_PATH}/nrfx/drivers/src/nrfx_nvmc.c
        ${HAL_NORDIC_PATH}/nrfx/drivers/src/nrfx_twim.c
        ${HAL_NORDIC_PATH}/nrfx/drivers/src/nrfx_twi_twim.c
        ${HAL_NORDIC_PATH}/nrfx/drivers/src/nrfx_qspi.c
        ${NRF_FOLDER_PATH}/nrfx_glue.c
        ${NRF_FOLDER_PATH}/native_drivers/mpu_armv8m_drv.c
        ${NRF_FOLDER_PATH}/native_drivers/spu.c
        $<$<OR:$<BOOL:${TFM_S_REG_TEST}>,$<BOOL:${TFM_NS_REG_TEST}>>:${CMAKE_CURRENT_SOURCE_DIR}/plat_test.c>
)

if(TFM_PARTITION_PLATFORM)
    target_sources(platform_s
        PRIVATE
            ${NRF_FOLDER_PATH}/services/src/tfm_platform_hal_ioctl.c
            ${NRF_FOLDER_PATH}/services/src/tfm_ioctl_core_s_api.c
    )

    target_sources(platform_ns
        PRIVATE
            ${NRF_FOLDER_PATH}/services/src/tfm_ioctl_core_ns_api.c
    )
endif()

if(SECURE_UART1)
    target_sources(platform_s
        PRIVATE
            ${NRF_FOLDER_PATH}/cmsis_drivers/Driver_USART.c
            ${HAL_NORDIC_PATH}/nrfx/drivers/src/nrfx_uarte.c
    )
endif()

target_compile_options(platform_s
    PUBLIC
        ${COMPILER_CMSE_FLAG}
)

target_compile_definitions(platform_s
    PUBLIC
        $<$<BOOL:${TEST_PSA_API}>:PSA_API_TEST_ENABLED>
)

#========================= Platform Non-Secure ================================#

target_include_directories(platform_ns
    PUBLIC
        .
        ${NRF5340_FOLDER_PATH}
        ${HAL_NORDIC_PATH}/nrfx
        ${HAL_NORDIC_PATH}/nrfx/mdk
        ${HAL_NORDIC_PATH}/nrfx/drivers/include
        ${NRF_FOLDER_PATH}/common
        ${PLATFORM_DIR}/..
        ${NRF_FOLDER_PATH}/services/include
    PRIVATE
        ${PLATFORM_DIR}/../interface/include
)

target_sources(platform_ns
    PRIVATE
        ${NRF_FOLDER_PATH}/cmsis_drivers/Driver_USART.c
        ${HAL_NORDIC_PATH}/nrfx/drivers/src/nrfx_uarte.c
        ${HAL_NORDIC_PATH}/nrfx/drivers/src/nrfx_twim.c
        ${HAL_NORDIC_PATH}/nrfx/drivers/src/nrfx_twi_twim.c
        ${NRF_FOLDER_PATH}/nrfx_glue.c
        plat_test.c
)

#========================= Platform BL2 =======================================#

if(BL2)
    target_include_directories(platform_bl2
        PUBLIC
            .
            ${NRF5340_FOLDER_PATH}
            ${HAL_NORDIC_PATH}/nrfx
            ${HAL_NORDIC_PATH}/nrfx/mdk
            ${HAL_NORDIC_PATH}/nrfx/drivers/include
            ${NRF_FOLDER_PATH}/common
        PRIVATE
            ${PLATFORM_DIR}/..
    )
    target_sources(bl2
        PRIVATE
            ${NRF_FOLDER_PATH}/startup.c
    )

    target_sources(platform_bl2
        PRIVATE
            ${NRF_FOLDER_PATH}/cmsis_drivers/Driver_Flash.c
            cmsis_drivers/Driver_QSPI.c
            ${NRF_FOLDER_PATH}/cmsis_drivers/Driver_USART.c
            ${HAL_NORDIC_PATH}/nrfx/drivers/src/nrfx_uarte.c
            ${HAL_NORDIC_PATH}/nrfx/drivers/src/nrfx_nvmc.c
            ${HAL_NORDIC_PATH}/nrfx/drivers/src/nrfx_twim.c
            ${HAL_NORDIC_PATH}/nrfx/drivers/src/nrfx_twi_twim.c
            ${HAL_NORDIC_PATH}/nrfx/drivers/src/nrfx_qspi.c
            ${NRF_FOLDER_PATH}/nrfx_glue.c
    )
endif()

if (TFM_PARTITION_PLATFORM)
install(FILES       ${NRF_FOLDER_PATH}/services/include/tfm_ioctl_core_api.h
        DESTINATION ${INSTALL_INTERFACE_INC_DIR})

install(FILES       ${NRF_FOLDER_PATH}/services/src/tfm_ioctl_core_ns_api.c
        DESTINATION ${INSTALL_INTERFACE_SRC_DIR})

endif()

#========================= tfm_spm ============================================#

target_sources(tfm_spm
    PRIVATE
        ${NRF_FOLDER_PATH}/faults.c
        ${NRF_FOLDER_PATH}/tfm_hal_isolation.c
        ${NRF_FOLDER_PATH}/tfm_hal_platform_common.c
        ${NRF_FOLDER_PATH}/target_cfg.c
)
