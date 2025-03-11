#-------------------------------------------------------------------------------
# Portions Copyright (C) 2025 Analog Devices, Inc.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

set(ADI_NS_PRPH_GCR         ON         CACHE BOOL "")
set(ADI_NS_PRPH_SIR         ON         CACHE BOOL "")
set(ADI_NS_PRPH_FCR         ON         CACHE BOOL "")
set(ADI_NS_PRPH_WDT         ON         CACHE BOOL "")
set(ADI_NS_PRPH_AES         ON         CACHE BOOL "")
set(ADI_NS_PRPH_AESKEY      ON         CACHE BOOL "")
set(ADI_NS_PRPH_CRC         ON         CACHE BOOL "")
set(ADI_NS_PRPH_GPIO0       ON         CACHE BOOL "")
set(ADI_NS_PRPH_TIMER0      ON         CACHE BOOL "")
set(ADI_NS_PRPH_TIMER1      ON         CACHE BOOL "")
set(ADI_NS_PRPH_TIMER2      ON         CACHE BOOL "")
set(ADI_NS_PRPH_TIMER3      ON         CACHE BOOL "")
set(ADI_NS_PRPH_TIMER4      ON         CACHE BOOL "")
set(ADI_NS_PRPH_TIMER5      ON         CACHE BOOL "")
set(ADI_NS_PRPH_I3C         ON         CACHE BOOL "")
set(ADI_NS_PRPH_UART        ON         CACHE BOOL "")
set(ADI_NS_PRPH_SPI         ON         CACHE BOOL "")
set(ADI_NS_PRPH_TRNG        ON         CACHE BOOL "")
set(ADI_NS_PRPH_BTLE_DBB    ON         CACHE BOOL "")
set(ADI_NS_PRPH_BTLE_RFFE   ON         CACHE BOOL "")
set(ADI_NS_PRPH_RSTZ        ON         CACHE BOOL "")
set(ADI_NS_PRPH_BOOST       ON         CACHE BOOL "")
set(ADI_NS_PRPH_BBSIR       ON         CACHE BOOL "")
set(ADI_NS_PRPH_BBFCR       ON         CACHE BOOL "")
set(ADI_NS_PRPH_RTC         ON         CACHE BOOL "")
set(ADI_NS_PRPH_WUT0        ON         CACHE BOOL "")
set(ADI_NS_PRPH_WUT1        ON         CACHE BOOL "")
set(ADI_NS_PRPH_PWR         ON         CACHE BOOL "")
set(ADI_NS_PRPH_MCR         ON         CACHE BOOL "")

# SRAMs
set(ADI_NS_SRAM_0           OFF        CACHE BOOL "Size: 32KB")
set(ADI_NS_SRAM_1           OFF        CACHE BOOL "Size: 32KB")
set(ADI_NS_SRAM_2           ON         CACHE BOOL "Size: 64KB")
set(ADI_NS_SRAM_3           ON         CACHE BOOL "Size: 64KB")
set(ADI_NS_SRAM_4           ON         CACHE BOOL "Size: 64KB")

#
# Allow user set S-NS resources ownership by overlay file
#
if(EXISTS "${CMAKE_BINARY_DIR}/../../s_ns_access_overlay.cmake")
    include(${CMAKE_BINARY_DIR}/../../s_ns_access_overlay.cmake)
endif()

target_compile_definitions(platform_region_defs
    INTERFACE
        # SRAMs
        $<$<BOOL:${ADI_NS_SRAM_0}>:ADI_NS_SRAM_0>
        $<$<BOOL:${ADI_NS_SRAM_1}>:ADI_NS_SRAM_1>
        $<$<BOOL:${ADI_NS_SRAM_2}>:ADI_NS_SRAM_2>
        $<$<BOOL:${ADI_NS_SRAM_3}>:ADI_NS_SRAM_3>
        $<$<BOOL:${ADI_NS_SRAM_4}>:ADI_NS_SRAM_4>
)
