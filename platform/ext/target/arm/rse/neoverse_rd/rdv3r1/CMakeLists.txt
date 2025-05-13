#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

cmake_policy(SET CMP0076 NEW)
set(CMAKE_CURRENT_SOURCE_DIR ${CMAKE_CURRENT_LIST_DIR})

add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/../common common)

# TFM_PLATFORM_VARIANT value for supported RD-V3-R1 platform variants:
# - '0' for RD-V3-R1 platform
# - '1' for RD-V3-R1-Cfg1 platform

if (TFM_PLATFORM_VARIANT STREQUAL "0")
      target_compile_definitions(platform_common_interface
                                 INTERFACE PLATFORM_VARIANT=0)
elseif (TFM_PLATFORM_VARIANT STREQUAL "1")
      target_compile_definitions(platform_common_interface
                                 INTERFACE PLATFORM_VARIANT=1)
else()
      message(FATAL_ERROR "Please set TFM_PLATFORM_VARIANT to \n"
                                "'0' for RD-V3-R1\n"
                                "'1' for RD-V3-R1-Cfg1\n")
endif()

#========================= Platform Region Defs ===============================#

target_include_directories(platform_region_defs
    INTERFACE
        .
        ../common/host_nrd4
)

#========================= Platform Secure ====================================#

target_sources(platform_s
    PRIVATE
        host_system.c
        $<$<BOOL:${TFM_MULTI_CORE_TOPOLOGY}>:${CMAKE_CURRENT_SOURCE_DIR}/rse_comms/rse_comms_permissions_hal.c>
)

#========================= Platform BL2 =======================================#

target_sources(platform_bl2
    PRIVATE
        bl2/boot_hal_bl2.c
        bl2/flash_map_bl2.c
        bl2/interrupts_bl2.c
        host_system.c
        noc_s3_periph_lib.c
        noc_s3_sysctrl_lib.c
)

target_include_directories(platform_bl2
    PUBLIC
        bl2
)

target_compile_definitions(platform_bl2
    INTERFACE
        $<$<BOOL:${TFM_S_REG_TEST}>:TFM_S_REG_TEST>
)

#========================= Platform BL1_1 =====================================#

target_sources(platform_bl1_1
    PRIVATE
        $<$<BOOL:${RSE_ENABLE_BRINGUP_HELPERS}>:${CMAKE_CURRENT_SOURCE_DIR}/bl1/rse_bringup_helpers_hal.c>
)
