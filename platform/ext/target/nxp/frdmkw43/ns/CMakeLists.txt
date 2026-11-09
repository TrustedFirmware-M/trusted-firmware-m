#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
# Copyright 2026 NXP
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

# This file is exported to NS side during CMake installation phase and renamed
# to CMakeLists.txt. It instructs how to build a platform on non-secure side.
# The structure and sources list are fully platform specific.

add_library(platform_ns)

target_compile_definitions(platform_ns
    PUBLIC
        TFM_LPUART_FEATURE=1
        ${HARDENING_COMPILE_DEFINITION}
)

target_sources(platform_ns
    PUBLIC
        Device/Source/startup_frdmkw43.c
    PRIVATE
        board.c
        hardware_init.c
        clock_config.c
        pin_mux.c
        Driver_LPUART.c
        Native_Driver/KW43B43ZC7/system_KW43B43ZC7.c
        Native_Driver/drivers/fsl_clock.c
        Native_Driver/drivers/spc/fsl_spc.c
        Native_Driver/drivers/common/fsl_common.c
        Native_Driver/drivers/common/fsl_common_arm.c
        Native_Driver/drivers/lpuart/fsl_lpuart.c
        Native_Driver/drivers/gpio/fsl_gpio.c
        Native_Driver/drivers/ccm32k/fsl_ccm32k.c
        Native_Driver/drivers/lptmr/fsl_lptmr.c
        Native_Driver/utilities/assert/fsl_assert.c
        Native_Driver/utilities/debug_console_lite/fsl_debug_console.c
        Native_Driver/utilities/str/fsl_str.c
        Native_Driver/components/uart/fsl_adapter_lpuart.c
        $<$<BOOL:${TFM_PARTITION_PLATFORM}>:plat_test.c>
)


target_include_directories(platform_ns
    PUBLIC
        include
        ext/cmsis/Include
        ext/cmsis/Include/m-profile
        ext/common
        Native_Driver
        Device/Include
        Device/Config
        Native_Driver/KW43B43ZC7
        Native_Driver/drivers
        Native_Driver/drivers/common
        Native_Driver/drivers/lpuart
        Native_Driver/drivers/ctimer
        Native_Driver/drivers/gpio
        Native_Driver/drivers/spc
        Native_Driver/drivers/port
        Native_Driver/drivers/ccm32k
        Native_Driver/drivers/lptmr
        Native_Driver/periph8
        Native_Driver/components/uart
        Native_Driver/utilities/debug_console_lite
        Native_Driver/utilities/str
        Native_Driver/utilities/assert
        Native_Driver/drivers/trdc_1
        partition
)

# Include region_defs.h and flash_layout.h
target_include_directories(platform_region_defs
    INTERFACE
        partition
)
