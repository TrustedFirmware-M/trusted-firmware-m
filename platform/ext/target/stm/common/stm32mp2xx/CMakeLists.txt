#-------------------------------------------------------------------------------
# Copyright (c) 2026, STMicroelectronics - All Rights Reserved
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------
cmake_policy(SET CMP0076 NEW)

# fetch cmsis-core for soc header files
include(${STM_FAMILY_DIR}/lib/cmsis-core/cmsis_core.cmake)

# fetch cmsis-device-mp2 for STM32MP2 device header files
include(${STM_FAMILY_DIR}/lib/cmsis-device-mp2/cmsis_device_mp2.cmake)

# fetch stm32mp2xx-hal-driver for HAL drivers header files
include(${STM_FAMILY_DIR}/lib/stm32mp2xx-hal-driver/stm32mp2xx_hal_driver.cmake)

#========================= Device tree ========================================#
include(${DEVICETREE_DIR}/gen_dt.cmake)

#========================= Platform region defs ===============================#
# these flags are includes in bl2, tfm_s and tfm_ns
target_compile_definitions(platform_region_defs
    INTERFACE
        $<$<STREQUAL:${STM32_BOOT_DEV},ospi>:STM32_BOOT_DEV_OSPI>
        $<$<STREQUAL:${STM32_BOOT_DEV},sdmmc1>:STM32_BOOT_DEV_SDMMC1>
        $<$<STREQUAL:${STM32_BOOT_DEV},sdmmc2>:STM32_BOOT_DEV_SDMMC2>
        $<$<BOOL:${STM32_M33TDCID}>:STM32_M33TDCID>
        # this flag is not defined in tfm_s and needed by stm32_bsec3
        $<$<BOOL:${TFM_DUMMY_PROVISIONING}>:TFM_DUMMY_PROVISIONING>
)

target_include_directories(platform_region_defs
    INTERFACE
        include
        ${STM_FAMILY_DIR}
        ${STM_FAMILY_DIR}/flash_layout/include
        ${STM_FAMILY_DIR}/cmsis_driver/include
        ${STM_FAMILY_DIR}/secure
        ${STM_FAMILY_DIR}/secure/services/include
)

target_link_libraries(platform_region_defs
    INTERFACE
        native_drivers_header
)

#========================= Tfm config =========================================#
target_compile_definitions(tfm_config
    INTERFACE
        $<$<BOOL:${STM32_OVERRIDE_OTP}>:STM32_OVERRIDE_OTP>
        $<$<BOOL:${STM32_CACHE_ENABLED}>:STM32_CACHE_ENABLED>
        $<$<BOOL:${TFM_PLATFORM_WDT_API}>:TFM_PLATFORM_WDT_API>
)

target_include_directories(tfm_config
    INTERFACE
        $<BUILD_INTERFACE:${STM_FAMILY_DIR}>
        $<BUILD_INTERFACE:${STM_SOC_DIR}>
)

target_link_libraries(tfm_config
    INTERFACE
        $<BUILD_INTERFACE:platform_region_defs>
        $<BUILD_INTERFACE:cmsis_core::header>
        $<BUILD_INTERFACE:cmsis_device_mp2::header>
        $<BUILD_INTERFACE:stm32mp2xx_hal_driver::header>
)

#========================= Native driver header ===============================#
add_library(native_drivers_header INTERFACE)

target_include_directories(native_drivers_header
    INTERFACE
        $<BUILD_INTERFACE:${STM_FAMILY_DIR}/native_driver/include>
)

#========================= Platform Secure ====================================#
add_subdirectory(${STM_FAMILY_DIR}/lib/qsort qsort)

target_add_scatter_file(tfm_s
    $<$<C_COMPILER_ID:GNU>:${STM_FAMILY_DIR}/linker_scripts/gcc/stm32mp2_s.ld>
)

add_devicetree_target(TARGET tfm_s
    DTS_BOARD ${DTS_BOARD_S}
)

add_dependencies(tfm_s_scatter dt_tfm_s_gen_h)

target_link_libraries(tfm_s_scatter
    dt_tfm_s_header
)

target_include_directories(platform_s
    PUBLIC
        ${CMAKE_BINARY_DIR}/generated
)

target_sources(platform_s
    PRIVATE
        ${STM_FAMILY_DIR}/system_stm32mp2xx.c
        ${STM_FAMILY_DIR}/secure/target_cfg.c
        ${STM_FAMILY_DIR}/secure/tfm_hal_isolation.c
        ${STM_FAMILY_DIR}/secure/provisioning.c
        ${STM_FAMILY_DIR}/secure/tfm_hal_platform.c
        ${STM_FAMILY_DIR}/cmsis_driver/src/driver_spi_flash.c
        ${STM_FAMILY_DIR}/cmsis_driver/src/driver_flash_mm.c
        $<$<BOOL:${TFM_PARTITION_PLATFORM}>:${STM_FAMILY_DIR}/secure/services/src/tfm_platform_system.c>
        $<$<NOT:$<BOOL:${OTP_NV_COUNTERS_RAM_EMULATION}>>:${STM_FAMILY_DIR}/secure/nv_counters.c>
        $<$<NOT:$<BOOL:${PLATFORM_DEFAULT_ATTEST_HAL}>>:${STM_FAMILY_DIR}/secure/attest_hal.c>
        $<$<NOT:$<BOOL:${PLATFORM_DEFAULT_OTP}>>:${STM_FAMILY_DIR}/secure/otp.c>
        $<$<BOOL:${TFM_PLATFORM_WDT_API}>:${STM_FAMILY_DIR}/secure/services/src/tfm_ioctl_wdt_api.c>
        $<$<BOOL:${TFM_PLATFORM_WDT_API}>:${STM_FAMILY_DIR}/secure/services/src/wdt.c>
)

target_compile_options(platform_s
    PUBLIC
        ${COMPILER_CMSE_FLAG}
)

target_compile_definitions(platform_s
    PUBLIC
        STM32_SEC=1
)

target_link_libraries(platform_s
    INTERFACE
        dt_tfm_s_libs
    PRIVATE
        platform_region_defs
        tfm_sprt
)

target_sources(dt_tfm_s_libs
    PRIVATE
        ${STM_FAMILY_DIR}/native_driver/src/core/sau_armv8m_drv.c
        ${STM_FAMILY_DIR}/native_driver/src/entropy/entropy.c
        ${STM_FAMILY_DIR}/native_driver/src/entropy/stm32_rng.c
        ${STM_FAMILY_DIR}/native_driver/src/watchdog/watchdog.c
        ${STM_FAMILY_DIR}/native_driver/src/watchdog/stm32_iwdg.c
        ${STM_FAMILY_DIR}/native_driver/src/bsec/stm32_bsec3.c
        ${STM_FAMILY_DIR}/native_driver/src/nvmem/nvmem.c
        ${STM_FAMILY_DIR}/native_driver/src/syscfg/stm32_syscfg.c
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
        ${STM_FAMILY_DIR}/native_driver/src/spi/stm32_ospi.c
        ${STM_FAMILY_DIR}/native_driver/src/spi/stm32_omm.c
        ${STM_FAMILY_DIR}/native_driver/src/mtd/spi-mem/spi_mem.c
        ${STM_FAMILY_DIR}/native_driver/src/mtd/nor/spi_nor.c
        ${STM_FAMILY_DIR}/native_driver/src/rif/stm32_rif.c
        ${STM_FAMILY_DIR}/native_driver/src/rif/stm32_rcc_rif.c
        ${STM_FAMILY_DIR}/native_driver/src/interrupt-controller/interrupt.c
        ${STM_FAMILY_DIR}/native_driver/src/interrupt-controller/arm_nvic.c
        ${STM_FAMILY_DIR}/native_driver/src/i2c/stm32_i2c.c
        ${STM_FAMILY_DIR}/native_driver/src/power/stm32mp2_pwr.c
        ${STM_FAMILY_DIR}/native_driver/src/rif/stm32mp2_pwr_rif.c
        $<$<BOOL:$<VERSION_GREATER:${TFM_ISOLATION_LEVEL},1>>:${STM_FAMILY_DIR}/native_driver/src/core/mpu_armv8m_drv.c>
        $<$<BOOL:${STM32_CACHE_ENABLED}>:${STM_FAMILY_DIR}/native_driver/src/core/stm32_dcache.c>
        $<$<BOOL:${STM32_M33TDCID}>:${STM_FAMILY_DIR}/native_driver/src/interrupt-controller/stm32mp2_pwr_intc.c>
        $<$<BOOL:${STM32_M33TDCID}>:${STM_FAMILY_DIR}/native_driver/src/rif/stm32_rifsc.c>
        $<$<BOOL:${STM32_M33TDCID}>:${STM_FAMILY_DIR}/native_driver/src/rif/stm32_risaf.c>
        $<$<BOOL:${STM32_M33TDCID}>:${STM_FAMILY_DIR}/native_driver/src/rif/stm32_risab.c>
        $<$<BOOL:${STM32_M33TDCID}>:${STM_FAMILY_DIR}/native_driver/src/rif/stm32_iac.c>
        $<$<BOOL:${STM32_M33TDCID}>:${STM_FAMILY_DIR}/native_driver/src/rif/stm32_serc.c>
        $<$<BOOL:${STM32_M33TDCID}>:${STM_FAMILY_DIR}/native_driver/src/crypto/stm32_saes.c>
        $<$<BOOL:${STM32_M33TDCID}>:${STM_FAMILY_DIR}/native_driver/src/regulator/regulator_common.c>
        $<$<BOOL:${STM32_M33TDCID}>:${STM_FAMILY_DIR}/native_driver/src/regulator/stm32mp2_pmic.c>
        $<$<BOOL:${STM32_M33TDCID}>:${STM_FAMILY_DIR}/native_driver/src/regulator/stm32mp25_pwr_regu.c>
        $<$<BOOL:${STM32_M33TDCID}>:${STM_FAMILY_DIR}/native_driver/src/rtc/stm32_rtc.c>
        $<$<BOOL:${STM32_M33TDCID}>:${STM_FAMILY_DIR}/native_driver/src/memc/stm32_fmc.c>
        $<$<BOOL:${STM32_M33TDCID}>:${STM_FAMILY_DIR}/native_driver/src/memc/stm32mp2_ramcfg.c>
        $<$<BOOL:${STM32_M33TDCID}>:${STM_FAMILY_DIR}/native_driver/src/dma/stm32_hpdma.c>
        $<$<BOOL:${STM32_M33TDCID}>:${STM_FAMILY_DIR}/native_driver/src/interrupt-controller/stm32_exti.c>
        $<$<BOOL:${STM32_M33TDCID}>:${STM_FAMILY_DIR}/native_driver/src/tamper/stm32_tamp.c>
        $<$<BOOL:${STM32_M33TDCID}>:${STM_FAMILY_DIR}/native_driver/src/tamper/stm32_tamp_nvram.c>
)

target_link_libraries(dt_tfm_s_libs
    PUBLIC
        native_drivers_header
        platform_region_defs
        tfm_config
    PRIVATE
        lib_qsort
)

if(TFM_PARTITION_CRYPTO)
    target_include_directories(platform_crypto_keys
        PUBLIC
            ${STM_FAMILY_DIR}/accelerator
            ${STM_FAMILY_DIR}/secure
    )

    target_sources(platform_crypto_keys
        PRIVATE
            $<$<NOT:$<BOOL:${PLATFORM_DEFAULT_CRYPTO_KEYS}>>:${STM_FAMILY_DIR}/secure/crypto_keys.c>
    )

    target_link_libraries(platform_crypto_keys
        PUBLIC
            dt_tfm_s_header
            platform_region_defs
            platform_s
    )
endif()

#========================= Platform BL2 =======================================#
if(BL2)

    add_subdirectory(${STM_FAMILY_DIR}/native_driver/src/ddr native_driver/src/ddr)

    target_add_scatter_file(bl2
        $<$<C_COMPILER_ID:GNU>:${STM_FAMILY_DIR}/linker_scripts/gcc/stm32mp2_bl2.ld>
    )

    add_devicetree_target(TARGET bl2
        DTS_BOARD ${DTS_BOARD_BL2}
    )

    add_dependencies(bl2_scatter dt_bl2_gen_h)

    target_link_libraries(bl2_scatter
        dt_bl2_header
    )

    target_compile_definitions(bootutil
        PRIVATE
            MULTIPLE_EXECUTABLE_RAM_REGIONS
    )

    target_include_directories(platform_bl2
        PUBLIC
            ${CMAKE_BINARY_DIR}/generated
    )

    target_sources(platform_bl2
        PRIVATE
            ${STM_FAMILY_DIR}/system_stm32mp2xx.c
            ${STM_FAMILY_DIR}/bl2/flash_map_bl2.c
            ${STM_FAMILY_DIR}/cmsis_driver/src/driver_flash_mm.c
            ${STM_FAMILY_DIR}/secure/provisioning.c
            $<$<STREQUAL:${STM32_BOOT_DEV},ospi>:${STM_FAMILY_DIR}/cmsis_driver/src/driver_spi_flash.c>
            $<$<NOT:$<BOOL:${OTP_NV_COUNTERS_RAM_EMULATION}>>:${STM_FAMILY_DIR}/secure/nv_counters.c>
            $<$<NOT:$<BOOL:${PLATFORM_DEFAULT_OTP}>>:${STM_FAMILY_DIR}/secure/otp.c>
    )

    target_compile_options(platform_bl2
        PUBLIC
            ${COMPILER_CMSE_FLAG}
    )

    target_compile_definitions(platform_bl2
        PUBLIC
            STM32_BL2=1
    )

    target_link_libraries(platform_bl2
        INTERFACE
            dt_bl2_libs
        PRIVATE
            platform_region_defs
    )

    target_sources(dt_bl2_libs
        PRIVATE
            ${STM_FAMILY_DIR}/bl2/boot_hal.c
            ${STM_FAMILY_DIR}/bl2/banner.c
            ${STM_FAMILY_DIR}/native_driver/src/core/mpu_armv8m_drv.c
            ${STM_FAMILY_DIR}/native_driver/src/entropy/entropy.c
            ${STM_FAMILY_DIR}/native_driver/src/ddr/stm32mp2_ram.c
            ${STM_FAMILY_DIR}/native_driver/src/entropy/stm32_rng.c
            ${STM_FAMILY_DIR}/native_driver/src/watchdog/watchdog.c
            ${STM_FAMILY_DIR}/native_driver/src/watchdog/stm32_iwdg.c
            ${STM_FAMILY_DIR}/native_driver/src/power/stm32mp2_pwr.c
            ${STM_FAMILY_DIR}/native_driver/src/bsec/stm32_bsec3.c
            ${STM_FAMILY_DIR}/native_driver/src/nvmem/nvmem.c
            ${STM_FAMILY_DIR}/native_driver/src/syscfg/stm32_syscfg.c
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
            ${STM_FAMILY_DIR}/native_driver/src/rif/stm32_rif.c
            ${STM_FAMILY_DIR}/native_driver/src/rif/stm32_risaf.c
            ${STM_FAMILY_DIR}/native_driver/src/rif/stm32_risab.c
            ${STM_FAMILY_DIR}/native_driver/src/rif/stm32_rifsc.c
            ${STM_FAMILY_DIR}/native_driver/src/rif/stm32_rcc_rif.c
            ${STM_FAMILY_DIR}/native_driver/src/rif/stm32mp2_pwr_rif.c
            ${STM_FAMILY_DIR}/native_driver/src/tamper/stm32_tamp.c
            ${STM_FAMILY_DIR}/native_driver/src/tamper/stm32_tamp_nvram.c
            ${STM_FAMILY_DIR}/native_driver/src/i2c/stm32_i2c.c
            ${STM_FAMILY_DIR}/native_driver/src/regulator/regulator_common.c
            ${STM_FAMILY_DIR}/native_driver/src/regulator/stm32mp2_pmic.c
            ${STM_FAMILY_DIR}/native_driver/src/regulator/stm32mp25_pwr_regu.c
            ${STM_FAMILY_DIR}/native_driver/src/power/stm32mp2_pwr.c
            $<$<BOOL:${STM32_CACHE_ENABLED}>:${STM_FAMILY_DIR}/native_driver/src/core/stm32_dcache.c>
            $<$<STREQUAL:${STM32_BOOT_DEV},ospi>:${STM_FAMILY_DIR}/native_driver/src/spi/stm32_ospi.c>
            $<$<STREQUAL:${STM32_BOOT_DEV},ospi>:${STM_FAMILY_DIR}/native_driver/src/spi/stm32_omm.c>
            $<$<STREQUAL:${STM32_BOOT_DEV},ospi>:${STM_FAMILY_DIR}/native_driver/src/mtd/spi-mem/spi_mem.c>
            $<$<STREQUAL:${STM32_BOOT_DEV},ospi>:${STM_FAMILY_DIR}/native_driver/src/mtd/nor/spi_nor.c>
            $<$<OR:$<STREQUAL:${STM32_BOOT_DEV},sdmmc1>,$<STREQUAL:${STM32_BOOT_DEV},sdmmc2>>:${STM_FAMILY_DIR}/native_driver/src/mmc/mmc.c>
            $<$<OR:$<STREQUAL:${STM32_BOOT_DEV},sdmmc1>,$<STREQUAL:${STM32_BOOT_DEV},sdmmc2>>:${STM_FAMILY_DIR}/native_driver/src/mmc/stm32_sdmmc2.c>
            $<$<OR:$<STREQUAL:${STM32_BOOT_DEV},sdmmc1>,$<STREQUAL:${STM32_BOOT_DEV},sdmmc2>>:${STM_FAMILY_DIR}/native_driver/src/mmc/soft_crc.c>
            $<$<OR:$<STREQUAL:${STM32_BOOT_DEV},sdmmc1>,$<STREQUAL:${STM32_BOOT_DEV},sdmmc2>>:${STM_FAMILY_DIR}/native_driver/src/mmc/partition.c>
            $<$<OR:$<STREQUAL:${STM32_BOOT_DEV},sdmmc1>,$<STREQUAL:${STM32_BOOT_DEV},sdmmc2>>:${STM_FAMILY_DIR}/cmsis_driver/src/driver_mmc_flash.c>
    )

    target_link_libraries(dt_bl2_libs
        PUBLIC
            native_drivers_header
            platform_region_defs
        PRIVATE
            lib_qsort
    )

    # Add stm32 header at bl2 binary (needed for bootrom)
    get_target_property(bl2_bin_dir bl2 RUNTIME_OUTPUT_DIRECTORY)

    add_custom_target(bl2_stm32
        ALL
        SOURCES ${bl2_bin_dir}/bl2.stm32
    )

    add_custom_command(
        OUTPUT ${bl2_bin_dir}/bl2.stm32
        DEPENDS bl2 bl2_bin
        COMMENT "STM32 image tool for bl2"
        COMMAND ${PYTHON_EXECUTABLE} ${STM_FAMILY_DIR}/tools/stm32_imgtool.py
        -e $<TARGET_FILE_DIR:bl2>/bl2.elf
        -b $<TARGET_FILE_DIR:bl2>/bl2.bin
        -o $<TARGET_FILE_DIR:bl2>/bl2.stm32
        -bt 0x30
        -v_maj ${STM32_HEADER_MAJOR_VER}
        -v_min ${STM32_HEADER_MINOR_VER}
    )
endif()

#========================= Generate board model ===============================#
include(${STM_FAMILY_DIR}/stm_version.cmake)

#========================= Generate profile definition ========================#
configure_file(${STM_FAMILY_DIR}/stm_profile.h.in
    ${CMAKE_BINARY_DIR}/generated/stm_profile.h)

#========================= Files for building NS side platform ================#
configure_file(${STM_FAMILY_DIR}/spe_export-stm32.cmake.in
    ${INSTALL_CMAKE_DIR}/spe_export-stm32.cmake @ONLY)

install(DIRECTORY
    ${DEVICETREE_DIR}
    DESTINATION ${INSTALL_PLATFORM_NS_DIR}/../common
)

install(DIRECTORY
    ${STM_FAMILY_DIR}/native_driver
    ${STM_FAMILY_DIR}/cmsis_driver
    ${STM_FAMILY_DIR}/ns
    DESTINATION ${INSTALL_PLATFORM_NS_DIR}/../common/stm32mp2xx
)

install(DIRECTORY
    ${STM_FAMILY_DIR}/lib/qsort
    DESTINATION ${INSTALL_PLATFORM_NS_DIR}/../common/stm32mp2xx/lib
)

install(DIRECTORY
    ${STM_FAMILY_DIR}/secure/services/include
    DESTINATION ${INSTALL_PLATFORM_NS_DIR}/../common/stm32mp2xx/secure/services
)

install(DIRECTORY
    ${STM_FAMILY_DIR}/flash_layout/include
    DESTINATION ${INSTALL_PLATFORM_NS_DIR}/../common/stm32mp2xx/flash_layout
)

install(FILES
    ${STM_FAMILY_DIR}/config.cmake
    ${STM_FAMILY_DIR}/cpuarch.cmake
    ${STM_FAMILY_DIR}/CMakeLists.txt
    ${STM_FAMILY_DIR}/config_tfm_stm32mp2.h
    ${STM_FAMILY_DIR}/system_stm32mp2xx.c
    DESTINATION ${INSTALL_PLATFORM_NS_DIR}/../common/stm32mp2xx
)

install(FILES
    ${STM_FAMILY_DIR}/secure/services/src/tfm_ioctl_wdt_api.c
    DESTINATION ${INSTALL_PLATFORM_NS_DIR}/../common/stm32mp2xx/secure/services/src
)

install(FILES
    ${STM_FAMILY_DIR}/accelerator/include/tf_psa_crypto_accelerator_config.h
    DESTINATION ${INSTALL_PLATFORM_NS_DIR}/accelerator/include
)

install(FILES
    ${PLATFORM_DIR}/ext/common/uart_stdout.h
    ${PLATFORM_DIR}/ext/common/tfm_s_linker_alignments.h
    ${STM_FAMILY_DIR}/secure/tfm_builtin_key_ids.h
    DESTINATION ${INSTALL_PLATFORM_NS_DIR}/include
)

install(FILES
    ${STM_FAMILY_DIR}/linker_scripts/gcc/stm32mp2_ns.ld
    DESTINATION ${INSTALL_PLATFORM_NS_DIR}/linker_scripts
)

