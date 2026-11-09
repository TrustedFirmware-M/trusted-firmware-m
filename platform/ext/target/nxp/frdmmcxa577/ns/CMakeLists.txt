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
if(USE_TFM_ROMAPI_FLASH_SERVICE)
target_compile_definitions(platform_ns
    PUBLIC
        NXP_NS_STORAGE
        MCUX_ROMAPI_TFM_INTERFACE
)
endif()

target_sources(platform_ns
    PUBLIC
        Device/Source/startup_frdmmcxa577.c
    PRIVATE
        board.c
        hardware_init.c
        clock_config.c
        pin_mux.c
        Driver_LPUART.c
        Native_Driver/system_MCXA577.c
        Native_Driver/drivers/fsl_clock.c
        Native_Driver/drivers/fsl_reset.c
        Native_Driver/drivers/mcx_spc/fsl_spc.c
        Native_Driver/drivers/common/fsl_common.c
        Native_Driver/drivers/common/fsl_common_arm.c
        Native_Driver/drivers/crc/fsl_crc.c
        Native_Driver/drivers/inputmux/fsl_inputmux.c
        Native_Driver/drivers/trng/fsl_trng.c
        Native_Driver/drivers/glikey/fsl_glikey.c
        Native_Driver/drivers/lpuart/fsl_lpuart.c
        Native_Driver/drivers/ctimer/fsl_ctimer.c
        Native_Driver/drivers/gpio/fsl_gpio.c
        Native_Driver/utilities/assert/fsl_assert.c
        Native_Driver/utilities/debug_console_lite/fsl_debug_console.c
        Native_Driver/utilities/str/fsl_str.c
        Native_Driver/components/uart/fsl_adapter_lpuart.c
        $<$<BOOL:${TFM_PARTITION_PLATFORM}>:plat_test.c>
        $<$<BOOL:${USE_TFM_ROMAPI_FLASH_SERVICE}>:tfm_ioctl_ns_api.c>

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
        Native_Driver/drivers/romapi
        Native_Driver/drivers/romapi/nboot
        Native_Driver/drivers/romapi/runbootloader
        Native_Driver/drivers/romapi/flash
        Native_Driver/drivers/romapi/kbapi
        Native_Driver/drivers/crc
        Native_Driver/drivers/inputmux
        Native_Driver/drivers/trng
        Native_Driver/drivers/glikey
        Native_Driver/drivers/lpuart
        Native_Driver/drivers/ctimer
        Native_Driver/drivers/gpio
        Native_Driver/drivers/mcx_spc
        Native_Driver/drivers/lpuart
        Native_Driver/drivers/port
        Native_Driver/periph4
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

# Include interface headers exported by TF-M
target_include_directories(tfm_api_ns
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${INTERFACE_INC_DIR}
        Native_Driver/drivers
)