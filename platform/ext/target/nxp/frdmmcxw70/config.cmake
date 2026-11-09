#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
# Copyright 2026 NXP
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

################################## Dependencies ##########################
set(TFM_PLATFORM_NXP_HAL_FILE_PATH  "LOCAL"    CACHE STRING     "Path to the NXP SDK hal")
set(TFM_PLATFORM_NXP_HW_ACCEL_SOURCE_PATH  "LOCAL"    CACHE STRING     "Path to the NXP SDK hal")

############################# Platform ###################################
set(CONFIG_TFM_USE_TRUSTZONE        ON         CACHE BOOL      "Use TrustZone")
set(TFM_MULTI_CORE_TOPOLOGY         OFF        CACHE BOOL      "Platform has multi core")

if(BL2)
############################ BL2 ########################################
set(BL2_S_IMAGE_START               "0x10000"   CACHE STRING    "Base address of the secure image in configuration with BL2")
set(BL2_NS_IMAGE_START              "0x40000"  CACHE STRING    "Base address of the non secure image in configuration with BL2")
endif()

############################ Platform features ##########################
set(USE_TFM_LPUART_FEATURE              ON         CACHE BOOL      "LPUART enabled")
set(USE_HARDENED_PLATFORM_INIT          ON         CACHE BOOL      "Use hardening macros for frdmmcxw70 platform")
set(PLATFORM_NO_FLASH                   ON         CACHE BOOL      "Platform has no flash for its/ps/otp")
set(PLATFORM_RAM_FS                     ON         CACHE BOOL      "Enables the use of RAM instead of the persistent storage device to store the FS in Secure Storage services")
set(TFM_LPUART_FEATURE                  ON         CACHE BOOL "Enable LPUART support for TF-M platform")
set(PLATFORM_DEFAULT_NV_COUNTERS        ON         CACHE BOOL "Enable default platform NV counters backend")

set(TFM_PARTITION_PROTECTED_STORAGE     OFF        CACHE BOOL      "Enable Protected Storage partition" FORCE)
set(TFM_PARTITION_INITIAL_ATTESTATION   OFF        CACHE BOOL      "Enable Initial Attestation partition" FORCE)
set(OTP_NV_COUNTERS_RAM_EMULATION       ON         CACHE BOOL      "nv counters in ram emulation")

option(MCU_SDK_REGRESSION "Enable larger RAM layout for TF-M regression build" OFF)

############################ TF-M Profile #############################

# enable once sgi-pkc is ported and available
#set(CRYPTO_HW_ACCELERATOR              ON          CACHE BOOL        "Enable crypto hardware accelerator")

# HW acceleration related configs managed below
if(CRYPTO_HW_ACCELERATOR)
set(TFM_PROFILE                        "profile_medium"    CACHE STRING "The TF-M profile" FORCE)
set(CRYPTO_HW_ACCELERATOR_TYPE      "nxp"       CACHE STRING    "The hardware accelerator platform")
set(CONFIG_PSA_CRYPTO_DRIVER_SGI_PKC ON         CACHE BOOL      "Use psa-crypto-driver to use HW acceleration via driver wrappers")
set(CONFIG_SGI_PKC                   ON         CACHE BOOL      "HW accelration ON")
set(CONFIG_SGI_PKC_PLATFORM_MCXW     ON         CACHE BOOL      "HW accelration ON for MCXA Platform")
set(CONFIG_BUILD_WITH_TFM            ON         CACHE BOOL      "Introduced configuration flag to be used in HW accel libs cmake")
set(USE_SGI_HUK                      ON         CACHE BOOL      "Use HUK for frdmmcxw70 platform via sgi")
set(PLATFORM_DEFAULT_CRYPTO_KEYS     OFF        CACHE BOOL      "Use default crypto keys implementation in turned off")
endif()

################################## LOG LEVEL #########################
set(TFM_SPM_LOG_LEVEL          LOG_LEVEL_INFO  CACHE STRING     "Set default SPM log level as INFO level" FORCE)
set(TFM_PARTITION_LOG_LEVEL    LOG_LEVEL_INFO  CACHE STRING     "Set default Secure Partition log level as INFO level" FORCE)