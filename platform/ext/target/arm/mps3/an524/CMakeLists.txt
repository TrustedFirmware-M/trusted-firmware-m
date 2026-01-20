#-------------------------------------------------------------------------------
# Copyright (c) 2020-2024, Arm Limited. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

cmake_policy(SET CMP0076 NEW)
set(CMAKE_CURRENT_SOURCE_DIR ${CMAKE_CURRENT_LIST_DIR})

#========================= Platform region defs ===============================#

target_include_directories(platform_region_defs
    INTERFACE
        partition
)

#========================= Platform common defs ===============================#

# Specify the location of platform specific build dependencies.
target_sources(tfm_s
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/device/source/startup_an524.c
)

target_add_scatter_file(tfm_s
    $<$<C_COMPILER_ID:ARMClang>:${CMAKE_BINARY_DIR}/generated/platform/ext/common/armclang/tfm_isolation_s.sct>
    $<$<C_COMPILER_ID:GNU>:${CMAKE_BINARY_DIR}/generated/platform/ext/common/gcc/tfm_isolation_s.ld>
    $<$<C_COMPILER_ID:IAR>:${CMAKE_BINARY_DIR}/generated/platform/ext/common/iar/tfm_isolation_s.icf>
    $<$<C_COMPILER_ID:Clang>:${CMAKE_BINARY_DIR}/generated/platform/ext/common/atfe/tfm_isolation_s.ld>
)

if(BL2)
    target_sources(bl2
        PRIVATE
            ${CMAKE_CURRENT_SOURCE_DIR}/device/source/startup_an524.c
            ${MBEDCRYPTO_PATH}/library/constant_time.c
            ${MBEDCRYPTO_PATH}/library/cipher.c
            ${MBEDCRYPTO_PATH}/library/cipher_wrap.c
            ${MBEDCRYPTO_PATH}/library/psa_crypto_cipher.c
    )
    target_add_scatter_file(bl2
            $<$<C_COMPILER_ID:ARMClang>:${PLATFORM_DIR}/ext/common/armclang/tfm_common_bl2.sct>
            $<$<C_COMPILER_ID:GNU>:${PLATFORM_DIR}/ext/common/gcc/tfm_common_bl2.ld>
            $<$<C_COMPILER_ID:IAR>:${PLATFORM_DIR}/ext/common/iar/tfm_common_bl2.icf>
            $<$<C_COMPILER_ID:Clang>:${PLATFORM_DIR}/ext/common/atfe/tfm_common_bl2.ld>
    )
endif()

#========================= Platform Secure ====================================#

target_include_directories(platform_s
    PUBLIC
        .
        ../common
        cmsis_drivers
        cmsis_drivers/config
        native_drivers
        partition
        device/include
        device/config
        ${CMAKE_SOURCE_DIR}
        ${PLATFORM_DIR}/ext/target/arm/drivers/usart/cmsdk
        ${PLATFORM_DIR}/ext/target/arm/drivers/usart/common
        ${PLATFORM_DIR}/ext/target/arm/drivers/mpc_sie
        ${PLATFORM_DIR}/ext/target/arm/drivers/timer/cmsdk
        ${PLATFORM_DIR}/ext/target/arm/drivers/mpu/armv8m
)

target_sources(platform_s
    PRIVATE
        device/source/system_core_init.c
        device/source/device_definition.c
        cmsis_drivers/Driver_Flash.c
        cmsis_drivers/Driver_MPC.c
        cmsis_drivers/Driver_PPC.c
        cmsis_drivers/Driver_USART.c
        native_drivers/ppc_sse200_drv.c
        ${PLATFORM_DIR}/ext/target/arm/drivers/mpc_sie/mpc_sie_drv.c
        ${PLATFORM_DIR}/ext/target/arm/drivers/mpu/armv8m/mpu_armv8m_drv.c
        ${PLATFORM_DIR}/ext/target/arm/drivers/usart/cmsdk/uart_cmsdk_drv.c
        ${PLATFORM_DIR}/ext/target/arm/drivers/timer/cmsdk/timer_cmsdk_drv.c
        $<$<BOOL:${TFM_PARTITION_PLATFORM}>:${CMAKE_CURRENT_SOURCE_DIR}/plat_test.c>
        $<$<BOOL:${TFM_PARTITION_PLATFORM}>:${CMAKE_CURRENT_SOURCE_DIR}/services/src/tfm_platform_system.c>
)

target_compile_options(platform_s
    PUBLIC
        ${COMPILER_CMSE_FLAG}
)

#========================= Platform BL2 =======================================#

if(BL2)
    target_sources(platform_bl2
        PRIVATE
            device/source/system_core_init.c
            device/source/device_definition.c
            cmsis_drivers/Driver_Flash.c
            cmsis_drivers/Driver_USART.c
            ${PLATFORM_DIR}/ext/target/arm/drivers/usart/cmsdk/uart_cmsdk_drv.c
    )

    target_include_directories(platform_bl2
        PUBLIC
            partition
            device/include
            device/config
            cmsis_drivers/config
            ${PLATFORM_DIR}/ext/target/arm/drivers/usart/cmsdk
            ${PLATFORM_DIR}/ext/target/arm/drivers/usart/common
            ${PLATFORM_DIR}/ext/target/arm/drivers/mpc_sie
            ${PLATFORM_DIR}/ext/target/arm/drivers/timer/cmsdk
        PRIVATE
            .
            ${CMAKE_SOURCE_DIR}
            native_drivers
            ${PLATFORM_DIR}/ext/common
    )
endif()

#========================= tfm_spm ============================================#

target_sources(tfm_spm
    PRIVATE
        target_cfg.c
        tfm_hal_platform.c
        tfm_peripherals_def.c
        ${PLATFORM_DIR}/ext/common/tfm_hal_platform_v8m.c
        ${PLATFORM_DIR}/ext/common/tfm_hal_isolation_v8m.c
        $<$<OR:$<BOOL:${CONFIG_TFM_FLIH_API}>,$<BOOL:${CONFIG_TFM_SLIH_API}>>:${PLATFORM_DIR}/ext/common/tfm_interrupts.c>
)

# If this is not added to the tfm_s it will not correctly override the weak
# default handlers declared in assemebly, and will instead be discarded as they
# are not in use.
target_sources(tfm_s
    PRIVATE
        ${PLATFORM_DIR}/ext/common/mpc_ppc_faults.c
)

target_compile_definitions(platform_region_defs
    INTERFACE
        PROVISIONING_CODE_PADDED_SIZE=${PROVISIONING_CODE_PADDED_SIZE}
        PROVISIONING_VALUES_PADDED_SIZE=${PROVISIONING_VALUES_PADDED_SIZE}
        PROVISIONING_DATA_PADDED_SIZE=${PROVISIONING_DATA_PADDED_SIZE}
        $<$<BOOL:${MCUBOOT_BUILTIN_KEY}>:MCUBOOT_BUILTIN_KEY>
)

if(NOT PLATFORM_DEFAULT_PROVISIONING)
    add_subdirectory(${PLATFORM_DIR}/ext/common/provisioning_bundle provisioning)
endif()

#========================= Files for building NS side platform ================#

install(FILES       ${TARGET_PLATFORM_PATH}/cmsis_drivers/Driver_USART.c
                    ${TARGET_PLATFORM_PATH}/device/source/device_definition.c
                    ${TARGET_PLATFORM_PATH}/device/source/system_core_init.c
                    ${PLATFORM_DIR}/ext/target/arm/drivers/usart/cmsdk/uart_cmsdk_drv.c
                    ${PLATFORM_DIR}/ext/target/arm/drivers/timer/cmsdk/timer_cmsdk_drv.c
        DESTINATION ${INSTALL_PLATFORM_NS_DIR})

install(DIRECTORY   ${TARGET_PLATFORM_PATH}/device
        DESTINATION ${INSTALL_PLATFORM_NS_DIR})

install(FILES       ${TARGET_PLATFORM_PATH}/device/include/platform_base_address.h
                    ${PLATFORM_DIR}/ext/target/arm/drivers/usart/cmsdk/uart_cmsdk_drv.h
                    ${PLATFORM_DIR}/ext/target/arm/drivers/usart/cmsdk/uart_cmsdk_reg_map.h
                    ${PLATFORM_DIR}/ext/target/arm/drivers/timer/cmsdk/timer_cmsdk_drv.h
                    ${TARGET_PLATFORM_PATH}/target_cfg.h
                    ${TARGET_PLATFORM_PATH}/device/config/device_cfg.h
                    ${TARGET_PLATFORM_PATH}/tfm_peripherals_def.h
                    ${TARGET_PLATFORM_PATH}/cmsis_drivers/config/cmsis_driver_config.h
                    ${TARGET_PLATFORM_PATH}/cmsis_drivers/config/RTE_Device.h
                    ${TARGET_PLATFORM_PATH}/native_drivers/ppc_sse200_drv.h
                    ${PLATFORM_DIR}/ext/target/arm/drivers/usart/cmsdk/Driver_USART_CMSDK.h
                    ${PLATFORM_DIR}/ext/target/arm/drivers/usart/common/Driver_USART_Common.h
                    ${PLATFORM_DIR}/include/tfm_plat_defs.h
                    ${PLATFORM_DIR}/ext/target/arm/drivers/mpc_sie/mpc_sie_drv.h
                    ${PLATFORM_DIR}/ext/target/arm/drivers/mpu/armv8m/mpu_armv8m_drv.h
        DESTINATION ${INSTALL_PLATFORM_NS_DIR}/include)

install(DIRECTORY   ${TARGET_PLATFORM_PATH}/partition
        DESTINATION ${INSTALL_PLATFORM_NS_DIR})

install(FILES       ${PLATFORM_DIR}/ext/common/gcc/tfm_common_ns.ld
                    ${PLATFORM_DIR}/ext/common/armclang/tfm_common_ns.sct
                    ${PLATFORM_DIR}/ext/common/iar/tfm_common_ns.icf
                    ${PLATFORM_DIR}/ext/common/atfe/tfm_common_ns.ldc
        DESTINATION ${INSTALL_PLATFORM_NS_DIR}/linker_scripts)

# copy all files from active platform directory
install(DIRECTORY   ${TARGET_PLATFORM_PATH}/ns/
        DESTINATION ${INSTALL_PLATFORM_NS_DIR})

install(FILES       ${TARGET_PLATFORM_PATH}/cpuarch.cmake
                    ${TARGET_PLATFORM_PATH}/config.cmake
        DESTINATION ${INSTALL_PLATFORM_NS_DIR})
