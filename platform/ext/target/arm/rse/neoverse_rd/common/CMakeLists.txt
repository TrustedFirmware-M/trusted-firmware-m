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
        $<$<BOOL:${PLAT_SHARED_LCP}>:PLAT_SHARED_LCP>
)

#========================= Platform Secure ====================================#

target_include_directories(platform_s
    PUBLIC
        cmsis_drivers
        device
        ${PLATFORM_DIR}/ext/target/arm/drivers/flash/common
        ${PLATFORM_DIR}/ext/target/arm/drivers/flash/cfi
        ${PLATFORM_DIR}/ext/target/arm/drivers/flash/strata
        ${PLATFORM_DIR}/ext/target/arm/drivers/usart/pl011
)

target_sources(platform_s
    PRIVATE
        ${PLATFORM_DIR}/ext/target/arm/drivers/flash/cfi/cfi_drv.c
        ${PLATFORM_DIR}/ext/target/arm/drivers/flash/strata/spi_strataflashj3_flash_lib.c
        ${PLATFORM_DIR}/ext/target/arm/drivers/usart/pl011/uart_pl011_drv.c
        $<$<EQUAL:${PLAT_MHU_VERSION},0>:${CMAKE_CURRENT_SOURCE_DIR}/../../common/native_drivers/mhu_v3_x.c>
        $<$<EQUAL:${PLAT_MHU_VERSION},0>:${CMAKE_CURRENT_SOURCE_DIR}/../../common/native_drivers/mhu_wrapper_v3_x.c>
        cmsis_drivers/Driver_Flash.c
        cmsis_drivers/Driver_USART.c
        device/host_device_definition.c
        device/rse_expansion_device_definition.c
        rse_expansion_peripherals_def.c
        $<$<BOOL:${TFM_MULTI_CORE_TOPOLOGY}>:${CMAKE_CURRENT_SOURCE_DIR}/rse_comms/rse_comms_platform.c>
)

#========================= Platform BL2 =======================================#

target_sources(platform_bl2
    PRIVATE
        ${PLATFORM_DIR}/ext/target/arm/drivers/flash/cfi/cfi_drv.c
        ${PLATFORM_DIR}/ext/target/arm/drivers/flash/strata/spi_strataflashj3_flash_lib.c
        ${PLATFORM_DIR}/ext/target/arm/drivers/usart/pl011/uart_pl011_drv.c
        $<$<EQUAL:${PLAT_MHU_VERSION},0>:${CMAKE_CURRENT_SOURCE_DIR}/../../common/native_drivers/mhu_v3_x.c>
        $<$<EQUAL:${PLAT_MHU_VERSION},0>:${CMAKE_CURRENT_SOURCE_DIR}/../../common/native_drivers/mhu_wrapper_v3_x.c>
        cmsis_drivers/Driver_Flash.c
        cmsis_drivers/Driver_USART.c
        device/host_device_definition.c
        device/rse_expansion_device_definition.c
)

target_include_directories(platform_bl2
    PUBLIC
        cmsis_drivers
        device
        host_drivers
        ${PLATFORM_DIR}/ext/target/arm/drivers/flash/common
        ${PLATFORM_DIR}/ext/target/arm/drivers/flash/cfi
        ${PLATFORM_DIR}/ext/target/arm/drivers/flash/strata
        ${PLATFORM_DIR}/ext/target/arm/drivers/usart/pl011
)

target_compile_definitions(platform_bl2
    PRIVATE
        $<$<CONFIG:Debug>:NOC_S3_PRETTY_PRINT_LOG_ENABLED>
        PLAT_LCP_COUNT=${PLAT_LCP_COUNT}
)

target_link_libraries(platform_bl2
    PUBLIC
        bl2_crypto_config
)

#========================= Platform BL1_1 =====================================#

target_sources(platform_bl1_1
    PRIVATE
        ${PLATFORM_DIR}/ext/target/arm/drivers/flash/cfi/cfi_drv.c
        ${PLATFORM_DIR}/ext/target/arm/drivers/flash/strata/spi_strataflashj3_flash_lib.c
        ${PLATFORM_DIR}/ext/target/arm/drivers/usart/pl011/uart_pl011_drv.c
        $<$<EQUAL:${PLAT_MHU_VERSION},0>:${CMAKE_CURRENT_SOURCE_DIR}/../../common/native_drivers/mhu_v2_x.c>
        $<$<EQUAL:${PLAT_MHU_VERSION},0>:${CMAKE_CURRENT_SOURCE_DIR}/../../common/native_drivers/mhu_wrapper_v2_x.c>
        cmsis_drivers/Driver_Flash.c
        cmsis_drivers/Driver_USART.c
        device/host_device_definition.c
        device/rse_expansion_device_definition.c
)

if (TFM_MULTI_CORE_TOPOLOGY AND (RSE_AMOUNT GREATER 1))
    target_sources(platform_bl1_1
        PRIVATE
            ${CMAKE_CURRENT_SOURCE_DIR}/rse_comms/rse_comms_platform.c
    )
endif()

target_include_directories(platform_bl1_1_interface
    INTERFACE
        cmsis_drivers
        device
        ${PLATFORM_DIR}/ext/target/arm/drivers/flash/common
        ${PLATFORM_DIR}/ext/target/arm/drivers/flash/cfi
        ${PLATFORM_DIR}/ext/target/arm/drivers/flash/strata
        ${PLATFORM_DIR}/ext/target/arm/drivers/usart/pl011
)

#========================= Platform BL1_2 =====================================#

target_include_directories(platform_bl1_2
    PUBLIC
        ${PLATFORM_DIR}/ext/target/arm/drivers/flash/common
        ${PLATFORM_DIR}/ext/target/arm/drivers/flash/cfi
        ${PLATFORM_DIR}/ext/target/arm/drivers/flash/strata
        ${PLATFORM_DIR}/ext/target/arm/drivers/usart/pl011
        cmsis_drivers
        device
)

#==================== Files for building NS side platform =====================#

install(FILES       ${PLATFORM_DIR}/ext/target/arm/drivers/usart/pl011/uart_pl011_drv.c
                    ${PLATFORM_DIR}/ext/target/arm/drivers/usart/pl011/uart_pl011_drv.h
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
