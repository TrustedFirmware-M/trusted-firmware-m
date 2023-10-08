#-------------------------------------------------------------------------------
# Copyright (c) 2020-2023, Arm Limited. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

cmake_policy(SET CMP0076 NEW)

#========================= Platform region defs ===============================#

target_include_directories(platform_region_defs
    INTERFACE
        ${CORSTONE300_COMMON_DIR}/partition
        ${CMAKE_CURRENT_SOURCE_DIR}/partition
        ${CMAKE_CURRENT_SOURCE_DIR}
)

#========================= Platform common defs ===============================#
# Specify the location of platform specific build dependencies.
target_sources(tfm_s
    PRIVATE
    ${CORSTONE300_COMMON_DIR}/device/source/startup_corstone300.c
)
target_add_scatter_file(tfm_s
    $<$<C_COMPILER_ID:ARMClang>:${PLATFORM_DIR}/ext/common/armclang/tfm_common_s.sct>
    $<$<C_COMPILER_ID:GNU>:${PLATFORM_DIR}/ext/common/gcc/tfm_common_s.ld>
    $<$<C_COMPILER_ID:IAR>:${PLATFORM_DIR}/ext/common/iar/tfm_common_s.icf>
)

if(NS)
    target_sources(tfm_ns
        PRIVATE
            ${CORSTONE300_COMMON_DIR}/device/source/startup_corstone300.c
    )
    if(DEFAULT_NS_SCATTER)
    target_add_scatter_file(tfm_ns
        $<$<C_COMPILER_ID:ARMClang>:${PLATFORM_DIR}/ext/common/armclang/tfm_common_ns.sct>
        $<$<C_COMPILER_ID:GNU>:${PLATFORM_DIR}/ext/common/gcc/tfm_common_ns.ld>
        $<$<C_COMPILER_ID:IAR>:${PLATFORM_DIR}/ext/common/iar/tfm_common_ns.icf>
    )
    endif()
    target_link_libraries(CMSIS_5_tfm_ns
        INTERFACE
            $<$<C_COMPILER_ID:ARMClang>:CMSIS_5_RTX_V8MMN>
            $<$<AND:$<C_COMPILER_ID:GNU>,$<OR:$<BOOL:${CONFIG_TFM_ENABLE_FP}>,$<BOOL:${CONFIG_TFM_ENABLE_MVE_FP}>>>:CMSIS_5_RTX_V8MMFN>
            $<$<AND:$<C_COMPILER_ID:GNU>,$<NOT:$<OR:$<BOOL:${CONFIG_TFM_ENABLE_FP}>,$<BOOL:${CONFIG_TFM_ENABLE_MVE_FP}>>>>:CMSIS_5_RTX_V8MMN>
            $<$<C_COMPILER_ID:IAR>:CMSIS_5_RTX_V81MMN>
    )
    target_link_options(tfm_ns
        PUBLIC
            ${LINKER_CP_OPTION}
    )
endif()

if(BL2)
    target_sources(bl2
        PRIVATE
            ${CORSTONE300_COMMON_DIR}/device/source/startup_corstone300.c
    )
    target_add_scatter_file(bl2
            $<$<C_COMPILER_ID:ARMClang>:${PLATFORM_DIR}/ext/common/armclang/tfm_common_bl2.sct>
            $<$<C_COMPILER_ID:GNU>:${PLATFORM_DIR}/ext/common/gcc/tfm_common_bl2.ld>
            $<$<C_COMPILER_ID:IAR>:${PLATFORM_DIR}/ext/common/iar/tfm_common_bl2.icf>
    )
endif()

#========================= Device definition lib ===============================#

add_library(device_definition INTERFACE)
target_include_directories(device_definition
    INTERFACE
        ${CORSTONE300_COMMON_DIR}/device/config
        ${CORSTONE300_COMMON_DIR}/device/include
        ${CORSTONE300_COMMON_DIR}/native_drivers
        ${CORSTONE300_COMMON_DIR}/partition
        ${CMAKE_CURRENT_SOURCE_DIR}/partition
        ${PLATFORM_DIR}/ext/target/arm/drivers/flash/common
        ${PLATFORM_DIR}/ext/target/arm/drivers/usart/cmsdk
        ${PLATFORM_DIR}/ext/target/arm/drivers/usart/common
        ${PLATFORM_DIR}/ext/target/arm/drivers/mpc_sie
        ${PLATFORM_DIR}/ext/target/arm/drivers/mpu/armv8m
        ${PLATFORM_DIR}/ext/target/arm/drivers/counter/armv8m
        ${PLATFORM_DIR}/ext/target/arm/drivers/timer/armv8m
        ${CMAKE_SOURCE_DIR}
)

add_library(device_definition_s STATIC)
target_sources(device_definition_s
    PUBLIC
        ${CORSTONE300_COMMON_DIR}/device/source/platform_s_device_definition.c
)

target_compile_options(device_definition_s
    PRIVATE
        ${COMPILER_CMSE_FLAG}
)

add_library(device_definition_ns STATIC)
target_sources(device_definition_ns
    PUBLIC
        ${CORSTONE300_COMMON_DIR}/device/source/platform_ns_device_definition.c
)

#========================= CMSIS lib ===============================#

add_library(cmsis_includes INTERFACE)
target_include_directories(cmsis_includes
    INTERFACE
        ${CORSTONE300_COMMON_DIR}/device/include
        ${CORSTONE300_COMMON_DIR}/cmsis_drivers
        ${PLATFORM_DIR}/ext/cmsis
        ${CORSTONE300_COMMON_DIR}/partition
        ${CMAKE_CURRENT_SOURCE_DIR}/partition
)

add_library(cmsis_includes_s INTERFACE)
target_link_libraries(cmsis_includes_s INTERFACE cmsis_includes)
target_include_directories(cmsis_includes_s
    INTERFACE
        ${CORSTONE300_COMMON_DIR}/cmsis_drivers/config/secure
)

target_compile_options(cmsis_includes_s
    INTERFACE
        ${COMPILER_CMSE_FLAG}
)


add_library(cmsis_includes_ns INTERFACE)
target_link_libraries(cmsis_includes_ns INTERFACE cmsis_includes)
target_include_directories(cmsis_includes_ns
    INTERFACE
        ${CORSTONE300_COMMON_DIR}/cmsis_drivers/config/non_secure
)

#========================= Linking ===============================#

target_link_libraries(device_definition_s PUBLIC device_definition)
target_link_libraries(device_definition_s PRIVATE cmsis_includes_s)
target_link_libraries(device_definition_ns PUBLIC device_definition)
target_link_libraries(device_definition_ns PRIVATE cmsis_includes_ns)

target_link_libraries(platform_bl2
    PUBLIC
        cmsis_includes
    PRIVATE
        device_definition_s
        cmsis_includes_s
)

target_link_libraries(platform_s
    PUBLIC
        cmsis_includes_s
    INTERFACE
        device_definition
    PRIVATE
        device_definition_s
)

target_link_libraries(platform_ns
    PUBLIC
        cmsis_includes_ns
    PRIVATE
        device_definition_ns
)
#========================= Platform Secure ====================================#

target_include_directories(platform_s
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CORSTONE300_COMMON_DIR}
    PRIVATE
        ${CORSTONE300_COMMON_DIR}
        ${CORSTONE300_COMMON_DIR}/device
        ${CORSTONE300_COMMON_DIR}/services/src
        ${PLATFORM_DIR}/ext/common
)

target_sources(platform_s
    PRIVATE
        ${CORSTONE300_COMMON_DIR}/cmsis_drivers/Driver_MPC.c
        ${CORSTONE300_COMMON_DIR}/cmsis_drivers/Driver_TGU.c
        ${CORSTONE300_COMMON_DIR}/cmsis_drivers/Driver_SSE300_PPC.c
        ${CORSTONE300_COMMON_DIR}/cmsis_drivers/Driver_USART.c
        ${CORSTONE300_COMMON_DIR}/device/source/system_core_init.c
        ${CORSTONE300_COMMON_DIR}/native_drivers/ppc_sse300_drv.c
        ${CORSTONE300_COMMON_DIR}/native_drivers/tgu_armv8_m_drv.c
        ${CORSTONE300_COMMON_DIR}/tfm_peripherals_def.c
        ${PLATFORM_DIR}/ext/target/arm/drivers/usart/cmsdk/uart_cmsdk_drv.c
        ${PLATFORM_DIR}/ext/target/arm/drivers/mpc_sie/mpc_sie_drv.c
        ${PLATFORM_DIR}/ext/target/arm/drivers/mpu/armv8m/mpu_armv8m_drv.c
        ${PLATFORM_DIR}/ext/target/arm/drivers/counter/armv8m/syscounter_armv8-m_cntrl_drv.c
        $<$<OR:$<BOOL:${TEST_NS_SLIH_IRQ}>,$<BOOL:${TEST_NS_FLIH_IRQ}>>:${CORSTONE300_COMMON_DIR}/plat_test.c>
        $<$<BOOL:${TFM_PARTITION_PLATFORM}>:${CORSTONE300_COMMON_DIR}/services/src/tfm_platform_system.c>
)

target_sources(tfm_sprt
    PRIVATE
        # SLIH test Partition and FLIH test Partition access the timer as ARoT Partitions.
        # Put the driver to SPRT so that both SLIH and FLIH tests can access it.
        $<$<OR:$<BOOL:${TEST_NS_SLIH_IRQ}>,$<BOOL:${TEST_NS_FLIH_IRQ}>>:${PLATFORM_DIR}/ext/target/arm/drivers/timer/armv8m/systimer_armv8-m_drv.c>
)

target_compile_options(platform_s
    PUBLIC
        ${COMPILER_CMSE_FLAG}
)

# To configure S and NS timer in S side for FP interrupt test
target_compile_definitions(platform_s
    PUBLIC
        $<$<BOOL:${TEST_NS_FPU}>:TEST_NS_FPU>
        $<$<BOOL:${TEST_S_FPU}>:TEST_S_FPU>
)

#========================= Platform Non-Secure ================================#

target_sources(platform_ns
    PRIVATE
        ${CORSTONE300_COMMON_DIR}/cmsis_drivers/Driver_USART.c
        ${CORSTONE300_COMMON_DIR}/device/source/system_core_init.c
        ${PLATFORM_DIR}/ext/target/arm/drivers/usart/cmsdk/uart_cmsdk_drv.c
        ${PLATFORM_DIR}/ext/target/arm/drivers/timer/armv8m/systimer_armv8-m_drv.c
    INTERFACE
        $<$<BOOL:${TEST_NS_FPU}>:${CORSTONE300_COMMON_DIR}/device/source/corstone300_ns_init.c>
)

target_include_directories(platform_ns
    PUBLIC
        ${CORSTONE300_COMMON_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CORSTONE300_COMMON_DIR}/device/config
    PRIVATE
        ${CORSTONE300_COMMON_DIR}/device
        ${PLATFORM_DIR}/ext/common
)

#========================= Platform BL2 =======================================#

if(BL2)
    target_sources(platform_bl2
        PRIVATE
            ${CORSTONE300_COMMON_DIR}/cmsis_drivers/Driver_USART.c
            ${CORSTONE300_COMMON_DIR}/device/source/system_core_init.c
            ${PLATFORM_DIR}/ext/target/arm/drivers/usart/cmsdk/uart_cmsdk_drv.c
            ${PLATFORM_DIR}/ext/target/arm/drivers/flash/emulated/emulated_flash_drv.c
    )

    target_include_directories(platform_bl2
        PRIVATE
            ${CORSTONE300_COMMON_DIR}/device
            ${CORSTONE300_COMMON_DIR}/services/src
            ${CORSTONE300_COMMON_DIR}/device/config
            ${CORSTONE300_COMMON_DIR}
    )
endif()

#========================= tfm_spm ============================================#

target_sources(tfm_spm
    PRIVATE
        ${CORSTONE300_COMMON_DIR}/target_cfg.c
        ${CORSTONE300_COMMON_DIR}/tfm_hal_platform.c
        ${PLATFORM_DIR}/ext/common/mpc_ppc_faults.c
        ${PLATFORM_DIR}/ext/common/tfm_hal_platform_v8m.c
        ${PLATFORM_DIR}/ext/common/tfm_hal_isolation_v8m.c
        $<$<OR:$<BOOL:${CONFIG_TFM_FLIH_API}>,$<BOOL:${CONFIG_TFM_SLIH_API}>>:${PLATFORM_DIR}/ext/common/tfm_interrupts.c>
)

if(NOT PLATFORM_DEFAULT_PROVISIONING)
    add_subdirectory(${PLATFORM_DIR}/ext/target/arm/mps3/common/provisioning provisioning)
endif()

#========================= platform_region_defs ===============================#
target_compile_definitions(platform_region_defs
    INTERFACE
        FLASH_S_PARTITION_SIZE=${FLASH_S_PARTITION_SIZE}
        FLASH_NS_PARTITION_SIZE=${FLASH_NS_PARTITION_SIZE}
        PROVISIONING_CODE_PADDED_SIZE=${PROVISIONING_CODE_PADDED_SIZE}
        PROVISIONING_VALUES_PADDED_SIZE=${PROVISIONING_VALUES_PADDED_SIZE}
        PROVISIONING_DATA_PADDED_SIZE=${PROVISIONING_DATA_PADDED_SIZE}
)