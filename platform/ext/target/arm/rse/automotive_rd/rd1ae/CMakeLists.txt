#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

cmake_policy(SET CMP0076 NEW)
set(CMAKE_CURRENT_SOURCE_DIR ${CMAKE_CURRENT_LIST_DIR})

add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/../../common common)

#========================= Platform Region Defs ===============================#

target_include_directories(platform_region_defs
    INTERFACE
        .
)

target_compile_definitions(platform_region_defs
    INTERFACE
        $<$<BOOL:${RSE_USE_LOCAL_UART}>:RSE_USE_LOCAL_UART>
)

#========================= Platform BL1_1 =====================================#

target_sources(platform_bl1_1
    PRIVATE
        cmsis_drivers/Driver_Flash.c
        device/rse_expansion_device_definition.c
        ${PLATFORM_DIR}/ext/target/arm/drivers/flash/cfi/cfi_drv.c
        ${PLATFORM_DIR}/ext/target/arm/drivers/flash/strata/spi_strataflashj3_flash_lib.c
        $<$<BOOL:${RSE_USE_LOCAL_UART}>:${PLATFORM_DIR}/ext/target/arm/drivers/usart/pl011/uart_pl011_drv.c>
        $<$<BOOL:${RSE_USE_LOCAL_UART}>:${CMAKE_CURRENT_SOURCE_DIR}/cmsis_drivers/Driver_USART_pl011.c>
)

target_include_directories(platform_bl1_1_interface
    INTERFACE
        cmsis_drivers
        device
        ${PLATFORM_DIR}/ext/target/arm/drivers/flash/cfi
        ${PLATFORM_DIR}/ext/target/arm/drivers/flash/common
        ${PLATFORM_DIR}/ext/target/arm/drivers/flash/strata
        $<$<BOOL:${RSE_USE_LOCAL_UART}>:${PLATFORM_DIR}/ext/target/arm/drivers/usart/pl011>
)

#========================= Platform BL1_2 =====================================#

target_include_directories(platform_bl1_2
    PUBLIC
        cmsis_drivers
        device
        ${PLATFORM_DIR}/ext/target/arm/drivers/flash/cfi
        ${PLATFORM_DIR}/ext/target/arm/drivers/flash/common
        ${PLATFORM_DIR}/ext/target/arm/drivers/flash/strata
        $<$<BOOL:${RSE_USE_LOCAL_UART}>:${PLATFORM_DIR}/ext/target/arm/drivers/usart/pl011>
)

#========================= Platform BL2 =======================================#

target_sources(platform_bl2
    PRIVATE
        bl2/boot_hal_bl2.c
        bl2/flash_map_bl2.c
        bl2/interrupts_bl2.c
        cmsis_drivers/Driver_Flash.c
        device/host_device_definition.c
        device/rse_expansion_device_definition.c
        gic_720ae_lib.c
        host_drivers/gic_720ae_drv.c
        host_system.c
        noc_s3_periph_lib.c
        noc_s3_sysctrl_lib.c
        ${PLATFORM_DIR}/ext/target/arm/drivers/flash/cfi/cfi_drv.c
        ${PLATFORM_DIR}/ext/target/arm/drivers/flash/strata/spi_strataflashj3_flash_lib.c
        ${PLATFORM_DIR}/ext/target/arm/rse/common/fip_parser/fip_parser.c
        $<$<BOOL:${RSE_USE_LOCAL_UART}>:${PLATFORM_DIR}/ext/target/arm/drivers/usart/pl011/uart_pl011_drv.c>
        $<$<BOOL:${RSE_USE_LOCAL_UART}>:${CMAKE_CURRENT_SOURCE_DIR}/cmsis_drivers/Driver_USART_pl011.c>
)

target_include_directories(platform_bl2
    PUBLIC
        bl2
        cmsis_drivers
        device
        host_drivers
        ${PLATFORM_DIR}/ext/target/arm/drivers/flash/cfi
        ${PLATFORM_DIR}/ext/target/arm/drivers/flash/common
        ${PLATFORM_DIR}/ext/target/arm/drivers/flash/strata
        ${PLATFORM_DIR}/ext/target/arm/rse/common/fip_parser
        $<$<BOOL:${RSE_USE_LOCAL_UART}>:${PLATFORM_DIR}/ext/target/arm/drivers/usart/pl011>
)

#========================= Platform Secure ====================================#

target_include_directories(platform_s
    PUBLIC
        cmsis_drivers
        device
        ${PLATFORM_DIR}/ext/target/arm/drivers/flash/cfi
        ${PLATFORM_DIR}/ext/target/arm/drivers/flash/common
        ${PLATFORM_DIR}/ext/target/arm/drivers/flash/strata
        $<$<BOOL:${RSE_USE_LOCAL_UART}>:${PLATFORM_DIR}/ext/target/arm/drivers/usart/pl011>
)

target_sources(platform_s
    PRIVATE
        cmsis_drivers/Driver_Flash.c
        device/host_device_definition.c
        device/rse_expansion_device_definition.c
        $<$<BOOL:${TFM_MULTI_CORE_TOPOLOGY}>:${CMAKE_CURRENT_SOURCE_DIR}/rse_comms/rse_get_rse_id.c>
        $<$<BOOL:${TFM_MULTI_CORE_TOPOLOGY}>:${CMAKE_CURRENT_SOURCE_DIR}/rse_comms/rse_comms_platform.c>
        $<$<BOOL:${TFM_MULTI_CORE_TOPOLOGY}>:${CMAKE_CURRENT_SOURCE_DIR}/rse_comms/rse_comms_permissions_hal.c>
        rse_expansion_peripherals_def.c
        ${PLATFORM_DIR}/ext/target/arm/drivers/flash/cfi/cfi_drv.c
        ${PLATFORM_DIR}/ext/target/arm/drivers/flash/strata/spi_strataflashj3_flash_lib.c
        $<$<BOOL:${RSE_USE_LOCAL_UART}>:${PLATFORM_DIR}/ext/target/arm/drivers/usart/pl011/uart_pl011_drv.c>
        $<$<BOOL:${RSE_USE_LOCAL_UART}>:${CMAKE_CURRENT_SOURCE_DIR}/cmsis_drivers/Driver_USART_pl011.c>
)
