#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
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
        ${CMAKE_CURRENT_SOURCE_DIR}/cmsis_core/startup_an519.c
)
target_add_scatter_file(tfm_s
    $<$<C_COMPILER_ID:ARMClang>:${CMAKE_BINARY_DIR}/generated/platform/ext/common/armclang/tfm_isolation_s.sct>
    $<$<C_COMPILER_ID:GNU>:${CMAKE_BINARY_DIR}/generated/platform/ext/common/gcc/tfm_isolation_s.ld>
    $<$<C_COMPILER_ID:IAR>:${CMAKE_BINARY_DIR}/generated/platform/ext/common/iar/tfm_isolation_s.icf>
    $<$<C_COMPILER_ID:Clang>:${CMAKE_BINARY_DIR}/generated/platform/ext/common/llvm/tfm_isolation_s.ld>
)

if(BL2)
    target_sources(bl2
        PRIVATE
            ${CMAKE_CURRENT_SOURCE_DIR}/cmsis_core/startup_an519.c
    )
    target_add_scatter_file(bl2
            $<$<C_COMPILER_ID:ARMClang>:${PLATFORM_DIR}/ext/common/armclang/tfm_common_bl2.sct>
            $<$<C_COMPILER_ID:GNU>:${PLATFORM_DIR}/ext/common/gcc/tfm_common_bl2.ld>
            $<$<C_COMPILER_ID:IAR>:${PLATFORM_DIR}/ext/common/iar/tfm_common_bl2.icf>
            $<$<C_COMPILER_ID:Clang>:${PLATFORM_DIR}/ext/common/llvm/tfm_common_bl2.ld>
    )
endif()

#========================= Platform Secure ====================================#

target_include_directories(platform_s
    PUBLIC
        .
        ../common
        cmsis_drivers
        native_drivers
        partition
        retarget
        cmsis_core
        native_drivers/timer_cmsdk
        ${PLATFORM_DIR}/..
)

target_sources(platform_s
    INTERFACE
        $<$<STREQUAL:"${TFM_FIH_PROFILE}","HIGH">:${PLATFORM_DIR}/ext/common/template/tfm_fih_platform.c>
    PRIVATE
        tfm_peripherals_def.c
        cmsis_drivers/Driver_Flash.c
        cmsis_drivers/Driver_MPC.c
        cmsis_drivers/Driver_PPC.c
        cmsis_drivers/Driver_USART.c
        retarget/platform_retarget_dev.c
        cmsis_core/system_core_init.c
        native_drivers/mpc_sie200_drv.c
        native_drivers/ppc_sse200_drv.c
        native_drivers/ppc_sse200_drv.c
        native_drivers/arm_uart_drv.c
        $<$<AND:$<NOT:$<BOOL:${TFM_PARTITION_SLIH_TEST}>>,$<NOT:$<BOOL:${TFM_PARTITION_FLIH_TEST}>>>:${CMAKE_CURRENT_SOURCE_DIR}/native_drivers/timer_cmsdk/timer_cmsdk.c>
        $<$<OR:$<BOOL:${TFM_S_REG_TEST}>,$<BOOL:${TFM_NS_REG_TEST}>>:${CMAKE_CURRENT_SOURCE_DIR}/plat_test.c>
        $<$<BOOL:${TFM_PARTITION_PLATFORM}>:${CMAKE_CURRENT_SOURCE_DIR}/services/src/tfm_platform_system.c>
)

target_sources(tfm_sprt
    PRIVATE
        # SLIH test Partition and FLIH test Partition access the timer as ARoT Partitions.
        # Put the driver to SPRT so that both SLIH and FLIH tests can access it.
        $<$<OR:$<BOOL:${TFM_PARTITION_SLIH_TEST}>,$<BOOL:${TFM_PARTITION_FLIH_TEST}>>:${CMAKE_CURRENT_SOURCE_DIR}/native_drivers/timer_cmsdk/timer_cmsdk.c>
)

target_compile_options(platform_s
    PUBLIC
        ${COMPILER_CMSE_FLAG}
)

#========================= Platform BL2 =======================================#

if(BL2)
    target_sources(platform_bl2
        PRIVATE
            retarget/platform_retarget_dev.c
            cmsis_core/system_core_init.c
            cmsis_drivers/Driver_Flash.c
            native_drivers/arm_uart_drv.c
            cmsis_drivers/Driver_USART.c
    )

    target_include_directories(platform_bl2
        PUBLIC
            partition
            cmsis_core
            retarget
        PRIVATE
            .
            ${PLATFORM_DIR}/..
            native_drivers
            native_drivers/timer_cmsdk
    )
endif()

#========================= tfm_spm ============================================#

target_sources(tfm_spm
    PRIVATE
        target_cfg.c
        ${PLATFORM_DIR}/ext/common/tfm_hal_isolation_v8m.c
        tfm_hal_platform.c
        faults.c
        $<$<OR:$<BOOL:${CONFIG_TFM_FLIH_API}>,$<BOOL:${CONFIG_TFM_SLIH_API}>>:${CMAKE_CURRENT_SOURCE_DIR}/tfm_interrupts.c>
)

#========================= Files for building NS platform =====================#

install(FILES       ${TARGET_PLATFORM_PATH}/native_drivers/arm_uart_drv.c
                    ${TARGET_PLATFORM_PATH}/native_drivers/timer_cmsdk/timer_cmsdk.c
                    ${TARGET_PLATFORM_PATH}/cmsis_drivers/Driver_USART.c
                    ${TARGET_PLATFORM_PATH}/retarget/platform_retarget_dev.c
        DESTINATION ${INSTALL_PLATFORM_NS_DIR})

install(DIRECTORY   ${TARGET_PLATFORM_PATH}/cmsis_core
                    ${TARGET_PLATFORM_PATH}/retarget
        DESTINATION ${INSTALL_PLATFORM_NS_DIR})

install(FILES       ${TARGET_PLATFORM_PATH}/native_drivers/arm_uart_drv.h
                    ${TARGET_PLATFORM_PATH}/native_drivers/timer_cmsdk/timer_cmsdk.h
                    ${TARGET_PLATFORM_PATH}/native_drivers/mpc_sie200_drv.h
                    ${TARGET_PLATFORM_PATH}/native_drivers/ppc_sse200_drv.h
                    ${TARGET_PLATFORM_PATH}/retarget/platform_retarget.h
                    ${TARGET_PLATFORM_PATH}/retarget/platform_retarget_pins.h
                    ${TARGET_PLATFORM_PATH}/target_cfg.h
                    ${TARGET_PLATFORM_PATH}/device_cfg.h
                    ${TARGET_PLATFORM_PATH}/tfm_peripherals_def.h
                    ${TARGET_PLATFORM_PATH}/cmsis_driver_config.h
                    ${TARGET_PLATFORM_PATH}/RTE_Device.h
                    ${PLATFORM_DIR}/ext/common/common_target_cfg.h
                    ${PLATFORM_DIR}/include/tfm_plat_defs.h
                    ${CMAKE_SOURCE_DIR}/lib/fih/inc/fih.h
        DESTINATION ${INSTALL_PLATFORM_NS_DIR}/include)

install(DIRECTORY   ${TARGET_PLATFORM_PATH}/partition
        DESTINATION ${INSTALL_PLATFORM_NS_DIR})

# copy all files from active platform directory
install(DIRECTORY   ${TARGET_PLATFORM_PATH}/ns/
        DESTINATION ${INSTALL_PLATFORM_NS_DIR})

install(FILES       ${TARGET_PLATFORM_PATH}/cpuarch.cmake
                    ${TARGET_PLATFORM_PATH}/config.cmake
        DESTINATION ${INSTALL_PLATFORM_NS_DIR})

install(FILES       ${PLATFORM_DIR}/ext/common/gcc/tfm_common_ns.ld
                    ${PLATFORM_DIR}/ext/common/armclang/tfm_common_ns.sct
                    ${PLATFORM_DIR}/ext/common/iar/tfm_common_ns.icf
                    ${PLATFORM_DIR}/ext/common/llvm/tfm_common_ns.ldc
        DESTINATION ${INSTALL_PLATFORM_NS_DIR}/linker_scripts)

# Install test configs
install(DIRECTORY   ${TARGET_PLATFORM_PATH}/tests
        DESTINATION ${INSTALL_PLATFORM_NS_DIR})
