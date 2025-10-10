#-------------------------------------------------------------------------------
# Copyright (c) 2023-2024, Arm Limited. All rights reserved.
# Copyright 2025 NXP
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
        Device/Source/startup_frdmmcxn947.c
    PRIVATE
        board.c
        hardware_init.c
        clock_config.c
        pin_mux.c
        Driver_LPUART.c
        Driver_Flash_iap_n4a.c
        Native_Driver/system_MCXN947_cm33_core0.c
        Native_Driver/drivers/fsl_clock.c
        Native_Driver/drivers/fsl_reset.c
        Native_Driver/drivers/mcx_spc/fsl_spc.c
        Native_Driver/drivers/common/fsl_common.c
        Native_Driver/drivers/common/fsl_common_arm.c
        Native_Driver/drivers/lpflexcomm/fsl_lpflexcomm.c
        Native_Driver/drivers/lpflexcomm/lpuart/fsl_lpuart.c
        Native_Driver/drivers/ctimer/fsl_ctimer.c
        Native_Driver/drivers/gpio/fsl_gpio.c
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
        Native_Driver/drivers
        Native_Driver/drivers/common
        Native_Driver/drivers/romapi/flash/
        Native_Driver/drivers/lpflexcomm
        Native_Driver/drivers/lpflexcomm/lpuart
        Native_Driver/drivers/ctimer
        Native_Driver/drivers/gpio
        Native_Driver/drivers/mcx_spc
        Native_Driver/drivers/port
        Native_Driver/periph
        Native_Driver/components/uart
        Native_Driver/utilities/debug_console_lite
        Native_Driver/utilities/str
        Native_Driver/utilities/assert
        partition
)

# Include region_defs.h and flash_layout.h
target_include_directories(platform_region_defs
    INTERFACE
        partition
)
