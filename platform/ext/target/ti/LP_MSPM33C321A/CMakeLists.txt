#-------------------------------------------------------------------------------
# SPDX-License-Identifier: BSD-3-Clause
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
# Copyright (c) 2026 Texas Instruments Incorporated
#
# Trusted Firmware-M platform configuration for LP_MSPM33C321A
#
# CMake build configuration for MSPM33C321A Cortex-M33 microcontroller.
# Pattern follows NXP LPCXpresso55S69 platform implementation.
#
#-------------------------------------------------------------------------------

cmake_policy(SET CMP0076 NEW)

# Resolve TI driverlib sources — use bundled Native_Driver or an external SDK path
if(TFM_PLATFORM_TI_HAL_FILE_PATH STREQUAL "LOCAL")
    set(TI_HAL_FILE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/Native_Driver/ti/driverlib)
    set(TI_DEVICE_FILE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/Native_Driver/ti/devices/msp)
else()
    set(TI_HAL_FILE_PATH ${TFM_PLATFORM_TI_HAL_FILE_PATH}/source/ti/driverlib)
    set(TI_DEVICE_FILE_PATH ${TFM_PLATFORM_TI_HAL_FILE_PATH}/source/ti/devices/msp)
endif()

# Platform name
set(TFM_PLATFORM_MSPM33C321A TRUE CACHE BOOL "MSPM33C321A platform" FORCE)

#========================= Platform region defs ===============================#

target_include_directories(platform_region_defs
    INTERFACE
        partition
)

#========================= Platform common defs ===============================#

# Startup file for secure image
target_sources(tfm_s
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/Device/Source/startup_mspm33c321a_s.c
)

# Linker script for secure image (compiler-specific)
# Use tfm_isolation_s.ld for Isolation Level 2 (defines Image$$PT_*$$Base symbols)
# gcc/tfm_s_mspm33.ld is appended to pad the last flash segment to 16 bytes
# (required by CCS Flash Programmer which writes in 128-bit / 16-byte blocks)
target_add_scatter_file(tfm_s
    $<$<C_COMPILER_ID:ARMClang>:${CMAKE_BINARY_DIR}/generated/platform/ext/common/armclang/tfm_isolation_s.sct>
    $<$<C_COMPILER_ID:GNU>:${CMAKE_BINARY_DIR}/generated/platform/ext/target/ti/LP_MSPM33C321A/gcc/tfm_isolation_s.ld>
    $<$<C_COMPILER_ID:IAR>:${CMAKE_BINARY_DIR}/generated/platform/ext/common/iar/tfm_isolation_s.icf>
)



#========================= Platform Secure ====================================#

# Include directories for secure platform
target_include_directories(platform_s
    PUBLIC
        .
        src
        Device/Include
        project_template/s
        partition
        ../../arm/drivers/mpu/armv8m
        ${PLATFORM_DIR}/ext/common
        ${CMAKE_CURRENT_SOURCE_DIR}/Native_Driver
        ${TI_DEVICE_FILE_PATH}/m33
    PRIVATE
        include
)

# Secure platform source files
target_sources(platform_s
    INTERFACE
        # Fault injection hardening (optional, for security-critical builds)
        $<$<STREQUAL:"${TFM_FIH_PROFILE}","HIGH">:${PLATFORM_DIR}/ext/common/template/tfm_fih_platform.c>
    PRIVATE
        # Device startup and configuration
        ${CMAKE_CURRENT_SOURCE_DIR}/Device/Source/startup_mspm33c321a_s.c

        # Security configuration (SAU, MPU, security boundaries)
        ${CMAKE_CURRENT_SOURCE_DIR}/src/target_cfg.c
        ${CMAKE_CURRENT_SOURCE_DIR}/src/tfm_hal_platform.c

        # CMSIS driver wrappers
        ${CMAKE_CURRENT_SOURCE_DIR}/cmsis_drivers/Driver_Flash.c
        ${CMAKE_CURRENT_SOURCE_DIR}/cmsis_drivers/Driver_USART.c

        # Board support (clock, pins, UART initialization)
        ${CMAKE_CURRENT_SOURCE_DIR}/project_template/s/board.c
        ${CMAKE_CURRENT_SOURCE_DIR}/project_template/s/clock_config.c
        ${CMAKE_CURRENT_SOURCE_DIR}/project_template/s/pin_mux.c

        # MPU driver (shared with ARM platforms)
        ../../arm/drivers/mpu/armv8m/mpu_armv8m_drv.c

        # TI driverlib — only the modules needed by the secure platform
        ${TI_HAL_FILE_PATH}/dl_flashctl.c
        ${TI_HAL_FILE_PATH}/dl_gsc.c
        ${TI_HAL_FILE_PATH}/dl_unicommuart.c
        ${TI_HAL_FILE_PATH}/dl_gpio.c
        ${TI_HAL_FILE_PATH}/m33/sysctl/dl_sysctl_mspm33c321x.c

)

# CMSIS device header — points TF-M's tfm_hal_device_header.h to the MSPM33 device header
target_compile_definitions(platform_s
    PUBLIC
        CMSIS_device_header="mspm33c321x.h"
)

# Link libraries for secure platform
target_link_libraries(platform_s
    PRIVATE
        # SPM runtime library
        tfm_sprt
)

# Compiler options for secure platform
target_compile_options(platform_s
    PUBLIC
        # CMSE flag required for Secure image (ARMv8-M TrustZone support)
        ${COMPILER_CMSE_FLAG}
)

# Secure image sources (added to tfm_s binary)
# Note: Some files must be linked as object files due to weak symbol handling in GNU ld
target_sources(tfm_s
    PRIVATE
        # Common security fault handlers (from common platform code)
        ${PLATFORM_DIR}/ext/common/tfm_hal_platform_v8m.c
        ${PLATFORM_DIR}/ext/common/tfm_hal_isolation_v8m.c
)




#========================= NS side platform files =============================#

# Install NS CMakeLists.txt — defines platform_ns library for NS test app builds
install(FILES
        ${TARGET_PLATFORM_PATH}/ns/CMakeLists.txt
    DESTINATION ${INSTALL_PLATFORM_NS_DIR}
    RENAME CMakeLists.txt)

# Install bundled Native_Driver alongside the NS platform files so that
# ns/CMakeLists.txt can locate driverlib via CMAKE_CURRENT_LIST_DIR/Native_Driver
install(DIRECTORY
        ${TARGET_PLATFORM_PATH}/Native_Driver
    DESTINATION ${INSTALL_PLATFORM_NS_DIR})

# Files to be installed for Non-Secure side (for NS user projects)
install(FILES
        ${TARGET_PLATFORM_PATH}/project_template/ns/board.c
        ${TARGET_PLATFORM_PATH}/project_template/ns/board.h
        ${TARGET_PLATFORM_PATH}/project_template/ns/clock_config.c
        ${TARGET_PLATFORM_PATH}/project_template/ns/clock_config.h
        ${TARGET_PLATFORM_PATH}/project_template/ns/pin_mux.c
        ${TARGET_PLATFORM_PATH}/project_template/ns/pin_mux.h
    DESTINATION ${INSTALL_PLATFORM_NS_DIR})

# CMSIS driver sources for NS side
install(FILES
        ${TARGET_PLATFORM_PATH}/cmsis_drivers/Driver_USART.c
    DESTINATION ${INSTALL_PLATFORM_NS_DIR}/cmsis_drivers)

# Device startup for NS side
install(FILES
        ${TARGET_PLATFORM_PATH}/Device/Source/startup_mspm33c321a_s.c
    DESTINATION ${INSTALL_PLATFORM_NS_DIR}/Device/Source)

# Platform headers for NS side
install(FILES
        ${TARGET_PLATFORM_PATH}/Device/Include/device_cfg.h
        ${TARGET_PLATFORM_PATH}/Device/Include/platform_base_address.h
        ${TARGET_PLATFORM_PATH}/src/target_cfg.h
        ${TARGET_PLATFORM_PATH}/tfm_peripherals_def.h
    DESTINATION ${INSTALL_PLATFORM_NS_DIR}/include)

# Partition definitions
install(DIRECTORY
        ${TARGET_PLATFORM_PATH}/partition
    DESTINATION ${INSTALL_PLATFORM_NS_DIR})

# Linker scripts for NS side
# Use platform-specific GCC NS linker script that pads sections to 16-byte
# boundaries (MSPM33C321A flash word width = 128 bits = 16 bytes).
install(FILES
        ${TARGET_PLATFORM_PATH}/gcc/tfm_common_ns.ld
        ${PLATFORM_DIR}/ext/common/armclang/tfm_common_ns.sct
        ${PLATFORM_DIR}/ext/common/iar/tfm_common_ns.icf
    DESTINATION ${INSTALL_PLATFORM_NS_DIR}/linker_scripts)

# Device headers (for reference by NS side)
install(DIRECTORY
        ${TARGET_PLATFORM_PATH}/Device/Include
    DESTINATION ${INSTALL_PLATFORM_NS_DIR}/Device)

# CMSIS driver headers
install(DIRECTORY
        ${TARGET_PLATFORM_PATH}/cmsis_drivers
    DESTINATION ${INSTALL_PLATFORM_NS_DIR}
    FILES_MATCHING PATTERN "*.h")

# Platform configuration files
install(FILES
        ${TARGET_PLATFORM_PATH}/cpuarch.cmake
        ${TARGET_PLATFORM_PATH}/config.cmake
    DESTINATION ${INSTALL_PLATFORM_NS_DIR})
