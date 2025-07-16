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

target_compile_definitions(platform_region_defs
    INTERFACE
        $<$<BOOL:${PLATFORM_PSA_ADAC_SECURE_DEBUG}>:PLATFORM_PSA_ADAC_SECURE_DEBUG>
)

#========================= Platform common defs ===============================#

# Specify the location of platform specific build dependencies.
target_sources(tfm_s
    PRIVATE
        Device/Source/startup_musca.c
)

# Use the common scatter file for Isolation L1 to L3
target_add_scatter_file(tfm_s
    $<$<C_COMPILER_ID:ARMClang>:${CMAKE_BINARY_DIR}/generated/platform/ext/common/armclang/tfm_isolation_s.sct>
    $<$<C_COMPILER_ID:GNU>:${CMAKE_BINARY_DIR}/generated/platform/ext/common/gcc/tfm_isolation_s.ld>
    $<$<C_COMPILER_ID:IAR>:${CMAKE_BINARY_DIR}/generated/platform/ext/common/iar/tfm_isolation_s.icf>
    $<$<C_COMPILER_ID:Clang>:${CMAKE_BINARY_DIR}/generated/platform/ext/common/llvm/tfm_isolation_s.ld>
)

if(BL2)
    target_sources(bl2
        PRIVATE
            Device/Source/startup_musca.c
    )
    target_add_scatter_file(bl2
            $<$<C_COMPILER_ID:ARMClang>:Device/Source/armclang/musca_bl2.sct>
            $<$<C_COMPILER_ID:GNU>:Device/Source/gcc/musca_bl2.ld>
            $<$<C_COMPILER_ID:IAR>:Device/Source/iar/musca_bl2.icf>
            $<$<C_COMPILER_ID:Clang>:Device/Source/llvm/musca_bl2.ld>
    )
endif()

#========================= Platform Secure ====================================#

target_include_directories(platform_s
    PUBLIC
        .
        CMSIS_Driver
        CMSIS_Driver/Config
        Device/Config
        Device/Include
        Native_Driver
        partition
        services/include
        Libraries
        ${PLATFORM_DIR}/ext/target/arm/drivers/usart/common
        ${PLATFORM_DIR}/ext/target/arm/drivers/usart/pl011
        ${PLATFORM_DIR}/ext/target/arm/drivers/timer/cmsdk
    INTERFACE
        cc312
)

target_sources(platform_s
    INTERFACE
        $<$<STREQUAL:"${TFM_FIH_PROFILE}","HIGH">:${PLATFORM_DIR}/ext/common/template/tfm_fih_platform.c>
    PRIVATE
        tfm_peripherals_def.c
        CMSIS_Driver/Driver_QSPI_Flash.c
        CMSIS_Driver/Driver_MPC.c
        CMSIS_Driver/Driver_PPC.c
        CMSIS_Driver/Driver_USART.c
        Device/Source/device_definition.c
        Device/Source/system_core_init.c
        Native_Driver/mpc_sie200_drv.c
        Native_Driver/gpio_cmsdk_drv.c
        Libraries/mt25ql_flash_lib.c
        Native_Driver/qspi_ip6514e_drv.c
        Native_Driver/musca_b1_scc_drv.c
        Native_Driver/ppc_sse200_drv.c
        ${CMAKE_SOURCE_DIR}/secure_fw/shared/crt_strcmp.c
        ${PLATFORM_DIR}/ext/target/arm/drivers/usart/pl011/uart_pl011_drv.c
        $<$<NOT:$<BOOL:${TFM_PARTITION_SLIH_TEST}>>:${PLATFORM_DIR}/ext/target/arm/drivers/timer/cmsdk/timer_cmsdk_drv.c>
        $<$<OR:$<BOOL:${TFM_S_REG_TEST}>,$<BOOL:${TFM_NS_REG_TEST}>>:${CMAKE_CURRENT_SOURCE_DIR}/plat_test.c>
        $<$<BOOL:${TFM_PARTITION_PLATFORM}>:${CMAKE_CURRENT_SOURCE_DIR}/services/src/tfm_platform_system.c>
)

target_compile_options(platform_s
    PUBLIC
        ${COMPILER_CMSE_FLAG}
)

target_sources(tfm_sprt
    PRIVATE
        # The SLIH test Partition accesses the timer as ARoT Partitions.
        # Put the driver to SPRT so that the SLIH tests can access it.
        $<$<BOOL:${TFM_PARTITION_SLIH_TEST}>:${PLATFORM_DIR}/ext/target/arm/drivers/timer/cmsdk/timer_cmsdk_drv.c>
)

#========================= Platform BL2 =======================================#

if(BL2)
    target_sources(platform_bl2
        PRIVATE
            Device/Source/system_core_init.c
            Device/Source/device_definition.c
            ${PLATFORM_DIR}/ext/target/arm/drivers/usart/pl011/uart_pl011_drv.c
            CMSIS_Driver/Driver_USART.c
            Native_Driver/musca_b1_scc_drv.c
    )

    target_include_directories(platform_bl2
        PUBLIC
            partition
            Device/Include
        INTERFACE
            cc312
        PRIVATE
            .
            CMSIS_Driver/Config
            Device/Config
            Native_Driver
            ${PLATFORM_DIR}/ext/target/arm/drivers/usart/common
            ${PLATFORM_DIR}/ext/target/arm/drivers/usart/pl011
            ${PLATFORM_DIR}/ext/target/arm/drivers/timer/cmsdk
            ${CMAKE_SOURCE_DIR}/bl2/ext/mcuboot/include # for fih.h interop only
            ${MCUBOOT_PATH}/boot/bootutil/include # for fault_injection_hardening.h only
            ${CMAKE_BINARY_DIR}/bl2/ext/mcuboot # for mcuboot_config.h only
            Libraries
    )

endif()

#========================= tfm_adac ============================================#

if (${PLATFORM_PSA_ADAC_SECURE_DEBUG})
    target_sources(platform_bl2
        PRIVATE
            systick_microsecond_timer.c
            bl2/boot_hal_bl2.c
    )

    target_compile_definitions(platform_bl2
        PRIVATE
            PLATFORM_PSA_ADAC_SECURE_DEBUG
    )

    target_link_libraries(platform_bl2
        PRIVATE
            trusted-firmware-m-psa-adac
    )

    # For microsecond_timer.h
    target_include_directories(trusted-firmware-m-psa-adac
        PRIVATE
            ${CMAKE_CURRENT_SOURCE_DIR}
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

#========================= Flash driver definition ===========================#

add_library(flash_drivers STATIC)

target_include_directories(flash_drivers
    PRIVATE
        ${PLATFORM_DIR}/ext/target/arm/drivers/usart/common
        ${PLATFORM_DIR}/ext/target/arm/drivers/usart/pl011
        ${PLATFORM_DIR}/ext/target/arm/drivers/timer/cmsdk
        ${PLATFORM_DIR}/ext/common
        ${PLATFORM_DIR}/include
        Native_Driver
        CMSIS_Driver/Config
        Device/Config
        Device/Include
        Libraries
        .
)

target_sources(flash_drivers
    PRIVATE
        CMSIS_Driver/Driver_GFC100_EFlash.c
        Native_Driver/gfc100_eflash_drv.c
        Native_Driver/musca_b1_eflash_drv.c
        Device/Source/gfc100_eflash_definition.c
)

target_link_libraries(flash_drivers
    PRIVATE
        cmsis
)

if(BL2)
    target_link_libraries(platform_bl2
        PRIVATE
            flash_drivers
    )
endif()

target_link_libraries(platform_s
    PRIVATE
        flash_drivers
)

#========================= Files for building NS side platform ================#
install(FILES       Device/Source/startup_musca.c
                    Device/Source/system_core_init.c
                    Device/Source/device_definition.c
        DESTINATION ${INSTALL_PLATFORM_NS_DIR}/Device/Source
)

install(FILES       ${PLATFORM_DIR}/ext/target/arm/drivers/usart/pl011/uart_pl011_drv.c
                    ${PLATFORM_DIR}/ext/target/arm/drivers/timer/cmsdk/timer_cmsdk_drv.c
                    CMSIS_Driver/Driver_USART.c
                    Libraries/mt25ql_flash_lib.c
        DESTINATION ${INSTALL_PLATFORM_NS_DIR}
)

install(DIRECTORY   CMSIS_Driver/Config
        DESTINATION ${INSTALL_PLATFORM_NS_DIR}/CMSIS_Driver
)

install(DIRECTORY   Device/Config
                    Device/Include
        DESTINATION ${INSTALL_PLATFORM_NS_DIR}/Device
)

install(DIRECTORY   partition
                    Native_Driver
        DESTINATION ${INSTALL_PLATFORM_NS_DIR}
)

install(FILES       target_cfg.h
                    Libraries/mt25ql_flash_lib.h
                    tfm_peripherals_def.h
                    ${PLATFORM_DIR}/include/tfm_plat_defs.h
                    ${PLATFORM_DIR}/ext/common/common_target_cfg.h
                    ${PLATFORM_DIR}/ext/target/arm/drivers/usart/pl011/uart_pl011_drv.h
                    ${PLATFORM_DIR}/ext/target/arm/drivers/usart/common/Driver_USART_Common.h
                    ${PLATFORM_DIR}/ext/target/arm/drivers/usart/pl011/Driver_USART_PL011.h
                    ${PLATFORM_DIR}/ext/target/arm/drivers/timer/cmsdk/timer_cmsdk_drv.h
        DESTINATION ${INSTALL_PLATFORM_NS_DIR}/include)

# copy all files from active platform directory
install(DIRECTORY   ${TARGET_PLATFORM_PATH}/ns/
        DESTINATION ${INSTALL_PLATFORM_NS_DIR})

install(FILES       ${TARGET_PLATFORM_PATH}/cpuarch.cmake
                    ${TARGET_PLATFORM_PATH}/config.cmake
        DESTINATION ${INSTALL_PLATFORM_NS_DIR})

# Install linker scripts
install(FILES       Device/Source/armclang/musca_ns.sct
                    Device/Source/gcc/musca_ns.ld
                    Device/Source/iar/musca_ns.icf
                    Device/Source/llvm/musca_ns.ldc
        DESTINATION ${INSTALL_PLATFORM_NS_DIR}/linker_scripts)

# Install test configs
install(DIRECTORY   ${TARGET_PLATFORM_PATH}/tests
        DESTINATION ${INSTALL_PLATFORM_NS_DIR})
