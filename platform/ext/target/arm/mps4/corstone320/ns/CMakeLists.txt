#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

cmake_policy(SET CMP0076 NEW)

set(PLATFORM_DIR    ${CMAKE_CURRENT_LIST_DIR})

add_library(platform_ns STATIC)

set(CONFIG_TFM_FP_ARCH "fpv5-d16")
set(CONFIG_TFM_FP_ARCH_ASM "FPv5_D16")

#========================= Platform region defs ===============================#

target_include_directories(platform_region_defs
    INTERFACE
        partition
        ${CMAKE_CURRENT_SOURCE_DIR}
        bl1_2_config
)

#========================= Platform common defs ===============================#

target_sources(platform_ns
    PRIVATE
        device/source/startup_mps4_corstone320.c
        device/source/system_core_init.c
)

#========================= Device definition lib ===============================#

add_library(device_definition INTERFACE)
target_include_directories(device_definition
    INTERFACE
        .
        device/include
        native_drivers
        partition
        native_drivers
        ${PLATFORM_DIR}/ext/target/arm/drivers/flash/common
        ${PLATFORM_DIR}/ext/target/arm/drivers/usart/cmsdk
        ${PLATFORM_DIR}/ext/target/arm/drivers/usart/common
        ${PLATFORM_DIR}/ext/target/arm/drivers/mpc_sie
        ${PLATFORM_DIR}/ext/target/arm/drivers/mpu/armv8m
        ${PLATFORM_DIR}/ext/target/arm/drivers/counter/armv8m
        ${PLATFORM_DIR}/ext/target/arm/drivers/timer/armv8m
        ${CMAKE_CURRENT_SOURCE_DIR}/device/config
)

#========================= Platform Non-Secure ================================#

target_sources(platform_ns
    PRIVATE
        device/source/platform_ns_device_definition.c
        cmsis_drivers/Driver_USART.c
        ${PLATFORM_DIR}/ext/target/arm/drivers/usart/cmsdk/uart_cmsdk_drv.c
        $<$<BOOL:${TEST_NS_FPU}>:${PLATFORM_DIR}/device/source/mps4_corstone3xx_ns_init.c>
        $<$<BOOL:${TEST_NS_FPU}>:${PLATFORM_DIR}/ext/common/test_interrupt.c>
)

target_include_directories(platform_ns
    PUBLIC
        cmsis_drivers
        ${PLATFORM_DIR}/ext/cmsis/Include
        ${PLATFORM_DIR}/ext/cmsis/Include/m-profile
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/ext/common
        cmsis_drivers/config/non_secure
)

target_compile_definitions(platform_ns
    PUBLIC
        $<$<BOOL:${TEST_NS_FPU}>:TEST_NS_FPU>
)

target_link_libraries(platform_ns
    PUBLIC
        device_definition
)
