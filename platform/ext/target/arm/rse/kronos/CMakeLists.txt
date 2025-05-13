#-------------------------------------------------------------------------------
# Copyright (c) 2022-2024, Arm Limited. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

cmake_policy(SET CMP0076 NEW)
set(CMAKE_CURRENT_SOURCE_DIR ${CMAKE_CURRENT_LIST_DIR})

add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/../common common)

#========================= Platform region defs ===============================#

target_include_directories(platform_region_defs
    INTERFACE
        .
)

#========================= Platform_s =========================================#

target_sources(platform_s
    PRIVATE
        cmsis_drivers/Driver_Flash.c
        device/host_device_definition.c
        ${PLATFORM_DIR}/ext/target/arm/drivers/flash/cfi/cfi_drv.c
        ${PLATFORM_DIR}/ext/target/arm/drivers/flash/strata/spi_strataflashj3_flash_lib.c
        $<$<NOT:$<BOOL:${RSE_DEBUG_UART}>>:${CMAKE_CURRENT_SOURCE_DIR}/cmsis_drivers/Driver_USART.c>
        $<$<NOT:$<BOOL:${RSE_DEBUG_UART}>>:${PLATFORM_DIR}/ext/target/arm/drivers/usart/pl011/uart_pl011_drv.c>
        $<$<BOOL:${TFM_MULTI_CORE_TOPOLOGY}>:${CMAKE_CURRENT_SOURCE_DIR}/rse_comms/rse_comms_permissions_hal.c>
)

target_include_directories(platform_s
    PUBLIC
        ./cmsis_drivers
        ./device
        ${PLATFORM_DIR}/ext/target/arm/drivers/flash/common
        ${PLATFORM_DIR}/ext/target/arm/drivers/flash/cfi
        ${PLATFORM_DIR}/ext/target/arm/drivers/flash/strata
        $<$<NOT:$<BOOL:${RSE_DEBUG_UART}>>:${PLATFORM_DIR}/ext/target/arm/drivers/usart/pl011>
)

#========================= Platform BL2 =======================================#

target_sources(platform_bl2
    PRIVATE
        bl2/boot_hal_bl2.c
        bl2/flash_map_bl2.c
        cmsis_drivers/Driver_Flash.c
        cmsis_drivers/Driver_Flash.c
        device/host_device_definition.c
        ${PLATFORM_DIR}/ext/target/arm/drivers/flash/cfi/cfi_drv.c
        ${PLATFORM_DIR}/ext/target/arm/drivers/flash/strata/spi_strataflashj3_flash_lib.c
        $<$<NOT:$<BOOL:${RSE_DEBUG_UART}>>:${CMAKE_CURRENT_SOURCE_DIR}/cmsis_drivers/Driver_USART.c>
        $<$<NOT:$<BOOL:${RSE_DEBUG_UART}>>:${PLATFORM_DIR}/ext/target/arm/drivers/usart/pl011/uart_pl011_drv.c>
)

target_include_directories(platform_bl2
    PUBLIC
        ./cmsis_drivers
        ./device
        ./bl2
        ${PLATFORM_DIR}/ext/target/arm/drivers/flash/common
        ${PLATFORM_DIR}/ext/target/arm/drivers/flash/cfi
        ${PLATFORM_DIR}/ext/target/arm/drivers/flash/strata
        $<$<NOT:$<BOOL:${RSE_DEBUG_UART}>>:${PLATFORM_DIR}/ext/target/arm/drivers/usart/pl011>
)

#========================= Platform BL1 =======================================#

target_sources(platform_bl1_1
    PRIVATE
        ${PLATFORM_DIR}/ext/target/arm/drivers/flash/cfi/cfi_drv.c
        cmsis_drivers/Driver_Flash.c
        ${PLATFORM_DIR}/ext/target/arm/drivers/flash/strata/spi_strataflashj3_flash_lib.c
        $<$<NOT:$<BOOL:${RSE_DEBUG_UART}>>:${CMAKE_CURRENT_SOURCE_DIR}/cmsis_drivers/Driver_USART.c>
        $<$<NOT:$<BOOL:${RSE_DEBUG_UART}>>:${PLATFORM_DIR}/ext/target/arm/drivers/usart/pl011/uart_pl011_drv.c>
        ${PLATFORM_DIR}/ext/target/arm/drivers/flash/strata/spi_strataflashj3_flash_lib.c
        device/host_device_definition.c
        $<$<BOOL:${RSE_ENABLE_BRINGUP_HELPERS}>:${CMAKE_CURRENT_SOURCE_DIR}/bl1/rse_bringup_helpers_hal.c>
)

target_include_directories(platform_bl1_1_interface
    INTERFACE
        ./cmsis_drivers
        ./device
        ${PLATFORM_DIR}/ext/target/arm/drivers/flash/common
        ${PLATFORM_DIR}/ext/target/arm/drivers/flash/cfi
        ${PLATFORM_DIR}/ext/target/arm/drivers/flash/strata
        $<$<NOT:$<BOOL:${RSE_DEBUG_UART}>>:${PLATFORM_DIR}/ext/target/arm/drivers/usart/pl011>
)

target_include_directories(platform_bl1_2
    PUBLIC
        ${PLATFORM_DIR}/ext/target/arm/drivers/flash/common
        ${PLATFORM_DIR}/ext/target/arm/drivers/flash/cfi
        ${PLATFORM_DIR}/ext/target/arm/drivers/flash/strata
        $<$<NOT:$<BOOL:${RSE_DEBUG_UART}>>:${PLATFORM_DIR}/ext/target/arm/drivers/usart/pl011>
)

#========================= Files for building NS side platform ================#

install(FILES       $<$<NOT:$<BOOL:${RSE_DEBUG_UART}>>:${PLATFORM_DIR}/ext/target/arm/drivers/usart/pl011/uart_pl011_drv.c>
                    $<$<NOT:$<BOOL:${RSE_DEBUG_UART}>>:${PLATFORM_DIR}/ext/target/arm/drivers/usart/pl011/uart_pl011_drv.h>
                    ${PLATFORM_DIR}/ext/target/arm/drivers/flash/strata/spi_strataflashj3_flash_lib.c
                    ${PLATFORM_DIR}/ext/target/arm/drivers/flash/strata/spi_strataflashj3_flash_lib.h
                    ${PLATFORM_DIR}/ext/target/arm/drivers/flash/cfi/cfi_drv.c
                    ${PLATFORM_DIR}/ext/target/arm/drivers/flash/cfi/cfi_drv.h
        DESTINATION ${INSTALL_PLATFORM_NS_DIR}/native_drivers
)

install(DIRECTORY   cmsis_drivers
        DESTINATION ${INSTALL_PLATFORM_NS_DIR}
)

install(DIRECTORY   device
        DESTINATION ${INSTALL_PLATFORM_NS_DIR}
)

install(FILES       rse_memory_sizes.h
                    flash_layout.h
                    host_base_address.h
        DESTINATION ${INSTALL_PLATFORM_NS_DIR}/partition)

install(DIRECTORY   ns/
        DESTINATION ${INSTALL_PLATFORM_NS_DIR})

install(FILES       tests/tfm_tests_ns_config.cmake
        DESTINATION ${INSTALL_PLATFORM_NS_DIR}/tests
        RENAME      tfm_tests_config.cmake)
