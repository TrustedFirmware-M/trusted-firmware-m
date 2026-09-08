#-------------------------------------------------------------------------------
# Copyright (c) 2026, STMicroelectronics - All Rights Reserved
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

# This file is exported to NS side during CMake installation phase and renamed
# to CMakeLists.txt. It instructs how to build a platform on non-secture side.
# The structure and sources list are fully platform specific.
list(APPEND CMAKE_MODULE_PATH "${PLATFORM_NS_API_DIR}/config")

add_library(platform_ns)

include(cmsis_core_config)
add_subdirectory(${CMSIS_CORE_PATH} cmsis-core)

include(cmsis_device_mp2_config)
add_subdirectory(${CMSIS_DEVICE_MP2_PATH} cmsis-device-mp2)

include(stm32mp2xx_hal_driver_config)
add_subdirectory(${STM32MP2XX_HAL_DRIVER_PATH} stm32mp2xx-hal-driver)

#========================= Device tree ========================================#
include(${DEVICETREE_DIR}/gen_dt.cmake)

#========================= Platform region defs ===============================#
target_include_directories(platform_region_defs
    INTERFACE
        partition
        ${PLATFORM_NS_API_DIR}/include
        ${STM_FAMILY_DIR}/flash_layout/include
        ${STM_FAMILY_DIR}/cmsis_driver/include
)

target_link_libraries(platform_region_defs
    INTERFACE
        native_drivers_header
)

#========================= Tfm config =========================================#
target_include_directories(tfm_config
    INTERFACE
        $<BUILD_INTERFACE:${STM_FAMILY_DIR}>
        $<BUILD_INTERFACE:${STM_SOC_DIR}>
)

target_link_libraries(tfm_config
    INTERFACE
        $<BUILD_INTERFACE:cmsis_core_header>
        $<BUILD_INTERFACE:cmsis_device_mp2_header>
        $<BUILD_INTERFACE:stm32mp2xx_hal_driver_header>
)

#========================= Native driver header ===============================#
add_library(native_drivers_header INTERFACE)

target_include_directories(native_drivers_header
    INTERFACE
        $<BUILD_INTERFACE:${STM_FAMILY_DIR}/native_driver/include>
)

#======================= Platform Non-Secure ==================================#
add_subdirectory(${STM_FAMILY_DIR}/lib/qsort qsort)

add_devicetree_target(TARGET tfm_ns
    DTS_BOARD ${DTS_BOARD_NS}
    DTC_FLAGS -Wno-simple_bus_reg
)

# tfm_ns_scatter is created later (target_add_scatter_file() in tests_reg),
# so it cannot be referenced here yet. Propagate the devicetree headers
# through platform_region_defs instead, since tfm_ns_scatter links it.
add_dependencies(platform_region_defs dt_tfm_ns_gen_h)

target_link_libraries(platform_region_defs
    INTERFACE
        dt_tfm_ns_header
)

target_include_directories(platform_ns
    PUBLIC
        ${CMAKE_BINARY_DIR}/generated
        ${STM_FAMILY_DIR}/cmsis_driver/include
        ${STM_FAMILY_DIR}/secure/services/include
        ${STM_FAMILY_DIR}/ns/include
        ${PLATFORM_NS_API_DIR}/include
        ${PLATFORM_NS_API_DIR}/ext/cmsis/Include
        ${PLATFORM_NS_API_DIR}/ext/cmsis/Include/m-profile
)

target_sources(platform_ns
    PRIVATE
        ${STM_FAMILY_DIR}/system_stm32mp2xx.c
        ${STM_FAMILY_DIR}/ns/src/fault_info.c
        ${STM_FAMILY_DIR}/ns/src/tfm_ns_plat_init.c
        $<$<BOOL:${TFM_PLATFORM_WDT_API}>:${STM_FAMILY_DIR}/secure/services/src/tfm_ioctl_wdt_api.c>
)

target_compile_definitions(platform_ns
    PUBLIC
        STM32_NSEC=1
)

target_link_libraries(platform_ns
    INTERFACE
        dt_tfm_ns_libs
    PUBLIC
        platform_region_defs
        tfm_config
        tfm_ns_log
)

target_sources(dt_tfm_ns_libs
    PRIVATE
        ${STM_FAMILY_DIR}/native_driver/src/clk/clk.c
        ${STM_FAMILY_DIR}/native_driver/src/clk/clk-stm32-core.c
        ${STM_FAMILY_DIR}/native_driver/src/clk/stm32mp_clkfunc.c
        ${STM_FAMILY_DIR}/native_driver/src/reset/core.c
        ${STM_FAMILY_DIR}/native_driver/src/reset/stm32_reset.c
        ${STM_FAMILY_DIR}/native_driver/src/timer/systick.c
        ${STM_FAMILY_DIR}/native_driver/src/pinctrl/common.c
        ${STM_FAMILY_DIR}/native_driver/src/pinctrl/stm32_pinctrl.c
        ${STM_FAMILY_DIR}/native_driver/src/uart/console.c
        ${STM_FAMILY_DIR}/native_driver/src/uart/stm32_uart.c
        ${STM_FAMILY_DIR}/native_driver/src/interrupt-controller/interrupt.c
        ${STM_FAMILY_DIR}/native_driver/src/interrupt-controller/arm_nvic.c
        ${STM_FAMILY_DIR}/native_driver/src/interrupt-controller/stm32_exti.c
)

target_link_libraries(dt_tfm_ns_libs
    PUBLIC
        native_drivers_header
        platform_region_defs
        tfm_config
    PRIVATE
        lib_qsort
)

target_sources(tfm_ns
    PRIVATE
        ${STM_SOC_DIR}/src/startup_stm32mp2_ns.c
)
