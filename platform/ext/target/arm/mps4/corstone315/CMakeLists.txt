#-------------------------------------------------------------------------------
# Copyright (c) 2022-2024, Arm Limited. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

cmake_policy(SET CMP0076 NEW)

#========================= Platform common defs ===============================#

# Specify the location of platform specific build dependencies.
target_sources(tfm_s
    PRIVATE
        device/source/startup_corstone315.c
)
target_add_scatter_file(tfm_s
    $<$<C_COMPILER_ID:ARMClang>:${PLATFORM_DIR}/ext/common/armclang/tfm_common_s.sct>
    $<$<C_COMPILER_ID:GNU>:${PLATFORM_DIR}/ext/common/gcc/tfm_common_s.ld>
    $<$<C_COMPILER_ID:IAR>:${PLATFORM_DIR}/ext/common/iar/tfm_common_s.icf>
)

if(BL2)
    target_sources(bl2
        PRIVATE
            device/source/startup_corstone315.c
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
        device/include
        native_drivers
        partition
        libraries
        ${PLATFORM_DIR}/ext/target/arm/drivers/flash/common
        ${PLATFORM_DIR}/ext/target/arm/drivers/usart/cmsdk
        ${PLATFORM_DIR}/ext/target/arm/drivers/usart/common
        ${PLATFORM_DIR}/ext/target/arm/drivers/mpc_sie
        ${PLATFORM_DIR}/ext/target/arm/drivers/mpu/armv8m
        ${PLATFORM_DIR}/ext/target/arm/drivers/counter/armv8m
        ${PLATFORM_DIR}/ext/target/arm/drivers/timer/armv8m
        ${PLATFORM_DIR}/ext/target/arm/drivers/sam
        ${PLATFORM_DIR}/ext/target/arm/drivers/watchdog
        ${PLATFORM_DIR}/include
        ${ETHOS_DRIVER_PATH}/src
        ${ETHOS_DRIVER_PATH}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/device/config
        ${CMAKE_SOURCE_DIR}
)

add_library(device_definition_s STATIC)
target_sources(device_definition_s
    PUBLIC
        device/source/platform_s_device_definition.c
)

target_compile_options(device_definition_s
    PRIVATE
        ${COMPILER_CMSE_FLAG}
)

add_library(device_definition_bl2 STATIC)
target_sources(device_definition_bl2
    PUBLIC
        device/source/platform_s_device_definition.c
)

#========================= CMSIS lib ===============================#

add_library(cmsis_includes INTERFACE)
target_include_directories(cmsis_includes
    INTERFACE
        device/include
        cmsis_drivers
        partition
)

add_library(cmsis_includes_s INTERFACE)
add_library(cmsis_includes_bl1 INTERFACE)
add_library(cmsis_includes_bl2 INTERFACE)
target_link_libraries(cmsis_includes_s INTERFACE cmsis_includes cmsis)
target_link_libraries(cmsis_includes_bl1 INTERFACE cmsis_includes cmsis)
target_link_libraries(cmsis_includes_bl2 INTERFACE cmsis_includes cmsis)
target_include_directories(cmsis_includes_bl2
    INTERFACE
        cmsis_drivers/config/secure
)

target_compile_options(cmsis_includes_bl2
    INTERFACE
        ${BL2_COMPILER_CP_FLAG}
)

target_link_options(cmsis_includes_bl2
    INTERFACE
        ${BL2_LINKER_CP_OPTION}
)


target_include_directories(cmsis_includes_s
    INTERFACE
        cmsis_drivers/config/secure
)

target_compile_options(cmsis_includes_s
    INTERFACE
        ${COMPILER_CMSE_FLAG}
        ${COMPILER_CP_FLAG}
)

target_link_options(cmsis_includes_s
    INTERFACE
        ${LINKER_CP_OPTION}
)

target_include_directories(cmsis_includes_bl1
    INTERFACE
        cmsis_drivers/config/secure
)

target_compile_options(cmsis_includes_bl1
    INTERFACE
        ${COMPILER_CP_FLAG}
)

target_link_options(cmsis_includes_bl1
    INTERFACE
        ${LINKER_CP_OPTION}
)
#========================= Linking ===============================#

target_link_libraries(device_definition_s PUBLIC device_definition)
target_link_libraries(device_definition_bl2 PUBLIC device_definition)

target_link_libraries(device_definition_s PRIVATE cmsis_includes_s)
target_link_libraries(device_definition_bl2 PRIVATE cmsis_includes_bl2)

target_link_libraries(platform_bl2
    PUBLIC
        cmsis_includes
        cmsis
    PRIVATE
        device_definition_bl2
        cmsis_includes_bl2
        $<$<AND:$<BOOL:${CONFIG_TFM_BOOT_STORE_MEASUREMENTS}>,$<BOOL:${TFM_PARTITION_MEASURED_BOOT}>>:tfm_boot_status>
)

target_link_libraries(platform_s
    PUBLIC
        cmsis_includes_s
    INTERFACE
        device_definition
    PRIVATE
        device_definition_s
        tfm_sprt # For tfm_strnlen in attest HAL
)

#========================= Platform Secure ====================================#

target_include_directories(platform_s
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
    PRIVATE
        device
        services/src
        ${PLATFORM_DIR}/ext/common
)

target_sources(platform_s
    PRIVATE
        tfm_peripherals_def.c
        attest_hal.c
        otp_lcm.c
        nv_counters.c
        cmsis_drivers/Driver_MPC.c
        cmsis_drivers/Driver_TGU.c
        cmsis_drivers/Driver_PPC.c
        cmsis_drivers/Driver_USART.c
        device/source/system_core_init.c
        native_drivers/ppc_corstone315_drv.c
        native_drivers/tgu_armv8_m_drv.c
        native_drivers/kmu_drv.c
        native_drivers/lcm_drv.c
        ${PLATFORM_DIR}/ext/common/tfm_hal_reset_halt.c
        ${PLATFORM_DIR}/ext/target/arm/drivers/usart/cmsdk/uart_cmsdk_drv.c
        ${PLATFORM_DIR}/ext/target/arm/drivers/mpc_sie/mpc_sie_drv.c
        ${PLATFORM_DIR}/ext/target/arm/drivers/mpu/armv8m/mpu_armv8m_drv.c
        ${PLATFORM_DIR}/ext/target/arm/drivers/counter/armv8m/syscounter_armv8-m_cntrl_drv.c
        ${ETHOS_DRIVER_PATH}/src/ethosu_device_u55_u65.c
        $<$<BOOL:${TFM_PARTITION_PLATFORM}>:${CMAKE_CURRENT_SOURCE_DIR}/services/src/tfm_platform_system.c>
        $<$<OR:$<BOOL:${TFM_PARTITION_SLIH_TEST}>,$<BOOL:${TFM_PARTITION_FLIH_TEST}>>:${CMAKE_CURRENT_SOURCE_DIR}/plat_test.c>

        # DMA350 files
        native_drivers/dma350_ch_drv.c
        native_drivers/dma350_drv.c
        libraries/dma350_lib.c
        $<$<BOOL:${PLATFORM_SVC_HANDLERS}>:${CMAKE_CURRENT_SOURCE_DIR}/platform_svc_handler.c>
        $<$<BOOL:${PLATFORM_SVC_HANDLERS}>:${CMAKE_CURRENT_SOURCE_DIR}/libraries/dma350_checker_layer.c>
        $<$<BOOL:${PLATFORM_SVC_HANDLERS}>:${CMAKE_CURRENT_SOURCE_DIR}/device/source/dma350_checker_device_defs.c>
        $<$<BOOL:${PLATFORM_SVC_HANDLERS}>:${CMAKE_CURRENT_SOURCE_DIR}/device/source/dma350_address_remap.c>
)

target_sources(tfm_sprt
    PRIVATE
        # SLIH test Partition and FLIH test Partition access the timer as ARoT Partitions.
        # Put the driver to SPRT so that both SLIH and FLIH tests can access it.
        $<$<OR:$<BOOL:${TFM_PARTITION_SLIH_TEST}>,$<BOOL:${TFM_PARTITION_FLIH_TEST}>>:${PLATFORM_DIR}/ext/target/arm/drivers/timer/armv8m/systimer_armv8-m_drv.c>
)

# To configure S and NS timer in S side for FP interrupt test
target_compile_definitions(platform_s
    PUBLIC
        $<$<BOOL:${TEST_NS_FPU}>:TEST_NS_FPU>
        $<$<BOOL:${TEST_S_FPU}>:TEST_S_FPU>
)

target_compile_definitions(platform_s
    PUBLIC
        ETHOSU_ARCH=$<LOWER_CASE:${ETHOSU_ARCH}>
        ETHOS$<UPPER_CASE:${ETHOSU_ARCH}>
        ETHOSU_LOG_SEVERITY=${ETHOSU_LOG_SEVERITY}
)

target_compile_definitions(platform_s
    INTERFACE
        ATTEST_KEY_BITS=${ATTEST_KEY_BITS}
    PRIVATE
        # Needed for DMA-350 library
        CMSIS_device_header=<corstone315.h>
        $<$<BOOL:${PLATFORM_SVC_HANDLERS}>:PLATFORM_SVC_HANDLERS>
)

#========================= Platform BL2 =======================================#

if(BL2)
    # boot_hal_bl2.c is compiled as part of 'bl2' target and not inside
    # 'platform_bl2' where it suppose to be. This is due to
    # platform_init/quit* apis symbol collision in bl1.
    target_sources(bl2
        PRIVATE
            bl2/boot_hal_bl2.c
    )

    target_sources(platform_bl2
        PRIVATE
            nv_counters.c
            otp_lcm.c
            native_drivers/lcm_drv.c
            cmsis_drivers/Driver_USART.c
            device/source/system_core_init.c
            ${PLATFORM_DIR}/ext/common/tfm_hal_reset_halt.c
            ${PLATFORM_DIR}/ext/target/arm/drivers/flash/emulated/emulated_flash_drv.c
            ${PLATFORM_DIR}/ext/target/arm/drivers/usart/cmsdk/uart_cmsdk_drv.c
    )

    target_include_directories(platform_bl2
        PRIVATE
            .
            device
            services/src
            ${CMAKE_CURRENT_SOURCE_DIR}/device/config
    )

    target_compile_definitions(platform_bl2
        PUBLIC
            $<$<AND:$<BOOL:${CONFIG_TFM_BOOT_STORE_MEASUREMENTS}>,$<BOOL:${TFM_PARTITION_MEASURED_BOOT}>>:MEASURED_BOOT_API>
    )

endif()

#========================= tfm_spm ============================================#

target_sources(tfm_spm
    PRIVATE
        target_cfg.c
        tfm_hal_platform.c
        ${PLATFORM_DIR}/ext/common/mpc_ppc_faults.c
        ${PLATFORM_DIR}/ext/common/tfm_hal_platform_v8m.c
        ${PLATFORM_DIR}/ext/common/tfm_hal_isolation_v8m.c
        ${CMAKE_CURRENT_SOURCE_DIR}/dma_init.c
        $<$<OR:$<BOOL:${CONFIG_TFM_FLIH_API}>,$<BOOL:${CONFIG_TFM_SLIH_API}>>:${PLATFORM_DIR}/ext/common/tfm_interrupts.c>
)

add_library(tfm_platform_config INTERFACE)

#========================= platform_region_defs ===============================#
target_compile_definitions(platform_region_defs
    INTERFACE
        FLASH_S_PARTITION_SIZE=${FLASH_S_PARTITION_SIZE}
        FLASH_NS_PARTITION_SIZE=${FLASH_NS_PARTITION_SIZE}
        PROVISIONING_CODE_PADDED_SIZE=${PROVISIONING_CODE_PADDED_SIZE}
        PROVISIONING_VALUES_PADDED_SIZE=${PROVISIONING_VALUES_PADDED_SIZE}
        PROVISIONING_DATA_PADDED_SIZE=${PROVISIONING_DATA_PADDED_SIZE}
        $<$<BOOL:${PLATFORM_HAS_PS_NV_OTP_COUNTERS}>:PLATFORM_HAS_PS_NV_OTP_COUNTERS>
)

target_include_directories(platform_region_defs
    INTERFACE
        partition
        ${CMAKE_CURRENT_SOURCE_DIR}
)

#========================= Flash driver library ===============================#
add_library(flash_drivers_s STATIC)
add_library(flash_drivers_bl2 STATIC)
add_library(flash_drivers INTERFACE)

target_include_directories(flash_drivers
    INTERFACE
        ${PLATFORM_DIR}/ext/driver
        partition
        ${PLATFORM_DIR}/ext/target/arm/drivers/flash/common
        ${PLATFORM_DIR}/ext/target/arm/drivers/flash/emulated
)

target_sources(flash_drivers
    INTERFACE
        cmsis_drivers/Driver_Flash.c
        ${PLATFORM_DIR}/ext/target/arm/drivers/flash/emulated/emulated_flash_drv.c
)

include(libflash_drivers.cmake)

#========================= Platform BL1_1 =======================================#

target_add_scatter_file(bl1_1
    $<$<C_COMPILER_ID:ARMClang>:${CMAKE_CURRENT_SOURCE_DIR}/device/source/armclang/corstone315_bl1_1.sct>
    $<$<C_COMPILER_ID:GNU>:${CMAKE_CURRENT_SOURCE_DIR}/device/source/gcc/corstone315_bl1_1.ld>
)

target_sources(platform_bl1_1
    PRIVATE
        nv_counters.c
        otp_lcm.c
        bl1/boot_hal_bl1_1.c
        cmsis_drivers/Driver_USART.c
        device/source/system_core_init.c
        device/source/startup_corstone315.c
        native_drivers/kmu_drv.c
        native_drivers/lcm_drv.c
        ${PLATFORM_DIR}/ext/common/tfm_hal_reset_halt.c
        ${PLATFORM_DIR}/ext/target/arm/drivers/usart/cmsdk/uart_cmsdk_drv.c
        ${PLATFORM_DIR}/ext/target/arm/drivers/watchdog/arm_watchdog_drv.c
)

target_link_libraries(platform_bl1_1
    PUBLIC
        device_definition_s
        flash_drivers_s
    PRIVATE
        bl1_1_shared_lib_interface
        cmsis_includes_bl1
)

#========================= Platform BL1_2 =====================================#

target_add_scatter_file(bl1_2
    $<$<C_COMPILER_ID:ARMClang>:${CMAKE_CURRENT_SOURCE_DIR}/device/source/armclang/corstone315_bl1_2.sct>
    $<$<C_COMPILER_ID:GNU>:${CMAKE_CURRENT_SOURCE_DIR}/device/source/gcc/corstone315_bl1_2.ld>
)

target_sources(platform_bl1_2
    PUBLIC
        device/source/startup_corstone315.c
    PRIVATE
        bl1/boot_hal_bl1_2.c
        ${PLATFORM_DIR}/ext/target/arm/drivers/mpu/armv8m/mpu_armv8m_drv.c

)

target_compile_definitions(platform_bl1_2
    PUBLIC
        $<$<AND:$<BOOL:${CONFIG_TFM_BOOT_STORE_MEASUREMENTS}>,$<BOOL:${TFM_PARTITION_MEASURED_BOOT}>>:MEASURED_BOOT_API>
)

target_link_libraries(platform_bl1_2
    PUBLIC
        device_definition
)

#========================= Platform Crypto Keys ===============================#

if (TFM_PARTITION_CRYPTO)
    target_sources(platform_crypto_keys
        PRIVATE
            crypto_keys.c
    )
    target_link_libraries(platform_crypto_keys
        PRIVATE
            platform_s
    )
endif()

#========================= Provisioning =======================================#
add_subdirectory(${TARGET_PLATFORM_PATH}/provisioning provisioning)

#========================= Files for building NS side platform ================#
target_compile_definitions(tfm_config
    INTERFACE
        FLASH_S_PARTITION_SIZE=${FLASH_S_PARTITION_SIZE}
        FLASH_NS_PARTITION_SIZE=${FLASH_NS_PARTITION_SIZE}
        PROVISIONING_CODE_PADDED_SIZE=${PROVISIONING_CODE_PADDED_SIZE}
        PROVISIONING_VALUES_PADDED_SIZE=${PROVISIONING_VALUES_PADDED_SIZE}
        PROVISIONING_DATA_PADDED_SIZE=${PROVISIONING_DATA_PADDED_SIZE}
)

install(FILES       ${TARGET_PLATFORM_PATH}/ns/cpuarch_ns.cmake
        DESTINATION ${INSTALL_PLATFORM_NS_DIR}
        RENAME      cpuarch.cmake)

install(FILES       cmsis_drivers/Driver_USART.c
                    cmsis_drivers/config/non_secure/cmsis_driver_config.h
                    cmsis_drivers/config/non_secure/RTE_Device.h
        DESTINATION ${INSTALL_PLATFORM_NS_DIR}/cmsis_drivers)

install(DIRECTORY   device
                    native_drivers
                    cmsis_drivers
                    partition
                    libraries
        DESTINATION ${INSTALL_PLATFORM_NS_DIR})

install(DIRECTORY   ${PLATFORM_DIR}/ext/target/arm/drivers
        DESTINATION ${INSTALL_PLATFORM_NS_DIR}/ext/target/arm)

install(FILES       ${PLATFORM_DIR}/ext/driver/Driver_USART.h
                    ${PLATFORM_DIR}/ext/driver/Driver_Common.h
        DESTINATION ${INSTALL_PLATFORM_NS_DIR}/ext/driver)

install(FILES       target_cfg.h
                    tfm_peripherals_def.h
                    ${PLATFORM_DIR}/include/tfm_plat_defs.h
        DESTINATION ${INSTALL_PLATFORM_NS_DIR}/include)

install(FILES       cpuarch.cmake
                    config.cmake
                    check_config.cmake
                    target_cfg.h
                    tfm_builtin_key_ids.h
        DESTINATION ${INSTALL_PLATFORM_NS_DIR})

install(FILES       tfm_builtin_key_ids.h
        DESTINATION ${INSTALL_INTERFACE_INC_DIR})

install(DIRECTORY   tests
        DESTINATION ${INSTALL_PLATFORM_NS_DIR})

install(DIRECTORY   ${TARGET_PLATFORM_PATH}/ns/
        DESTINATION ${INSTALL_PLATFORM_NS_DIR})

if(DEFAULT_NS_SCATTER)
    # Install linker scripts
    install(FILES       ${PLATFORM_DIR}/ext/common/armclang/tfm_common_ns.sct
                        ${PLATFORM_DIR}/ext/common/gcc/tfm_common_ns.ld
                        ${PLATFORM_DIR}/ext/common/iar/tfm_common_ns.icf
            DESTINATION ${INSTALL_PLATFORM_NS_DIR}/linker_scripts)
endif()
