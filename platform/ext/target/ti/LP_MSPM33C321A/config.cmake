#-------------------------------------------------------------------------------
# SPDX-License-Identifier: BSD-3-Clause
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
# Copyright (c) 2026 Texas Instruments Incorporated
#
# TF-M Configuration for LP_MSPM33C321A
#
# Platform: LP_MSPM33C321A (MSPM33 Cortex-M33 microcontroller)
# Memory Layout: Defined in platform/ext/target/ti/LP_MSPM33C321A/partition/
#                (See flash_layout.h and region_defs.h)
# Security: TrustZone-M, SAU, ARMv8-M MPU
#
#-------------------------------------------------------------------------------

################################## Dependencies ################################
set(TFM_PLATFORM_TI_HAL_FILE_PATH   "LOCAL"          CACHE STRING
    "Path to TI MSP SDK driverlib sources. Use LOCAL to use the bundled Native_Driver sources.")

#========================= Security Configuration =============================#

# Enable TrustZone-M (required for MSPM33C321A)
set(CONFIG_TFM_USE_TRUSTZONE          ON)

# TFM isolation level (2 = TrustZone-M + MPU)
set(TFM_ISOLATION_LEVEL               1)

#========================= Memory Layout ======================================#
# Memory boundaries and partition offsets are managed in:
# - flash_layout.h (Flash/SRAM sizes and base addresses)
# - region_defs.h (Secure/Non-Secure partition offsets)
#=============================================================================#

#========================= Bootloader Configuration ===========================#


# BL2 (MCUboot) not used on MSPM33C321A
# Direct code execution starts at 0x0 without a bootloader
set(BL2                                  OFF)

if(BL2)
    set(BL2_TRAILER_SIZE 0x10000 CACHE STRING "BL2 trailer size with bootloader")
else()
    set(BL2_TRAILER_SIZE 0x0 CACHE STRING "BL2 trailer size without bootloader")
endif()

#========================= Topology Configuration =============================#

# Single-core platform (no multi-core support)
set(TFM_MULTI_CORE_TOPOLOGY           OFF)

#========================= Optional Services =================================#

# TFM Partitions to enable (can be customized)
# These are the default PSA services provided

# Crypto service (uses tf-psa-crypto library with MSPM33 hardware acceleration)
set(TFM_PARTITION_CRYPTO              ON)

# Internal Trusted Storage (flash-based)
set(TFM_PARTITION_INTERNAL_TRUSTED_STORAGE ON)

# Protected Storage (external storage, optional)
set(TFM_PARTITION_PROTECTED_STORAGE   ON)

# Initial Attestation (device identity and boot state)
set(TFM_PARTITION_INITIAL_ATTESTATION ON)

# Platform service (optional, for platform-specific operations)
set(TFM_PARTITION_PLATFORM            ON)

#========================= Logging Configuration =============================#

# SPM logging level (debug, info, notice, warning, error, none)
set(TFM_SPM_LOG_LEVEL                 INFO CACHE STRING "SPM log level")

# Partition logging level
set(TFM_PARTITION_LOG_LEVEL           INFO CACHE STRING "Partition log level")

#========================= Code Optimization =================================#

# Build type: Debug, Release, MinSizeRel, RelWithDebInfo
set(CMAKE_BUILD_TYPE                  Release CACHE STRING "Build type")

# Optimization flags (Release builds use -Os for size)
# Debug builds use -O0 for debuggability

#========================= Compiler Settings =================================#

# Compiler: GNU ARM, ARMClang, or IAR
# Default: GNU ARM Embedded
# To use TI Clang: set(CMAKE_C_COMPILER "ticlang")


# Define the platform
add_compile_definitions(
    __MSPM33C321A__
    MSPM33C321A
    __SAUREGION_PRESENT=1
)

# Use platform-specific linker script template that adds ALIGN(16) at the end
# of .TFM_SP_LOAD_LIST. Required because MSPM33C321A has a 128-bit (16-byte)
# flash word width — all flash program addresses must be 16-byte aligned.
