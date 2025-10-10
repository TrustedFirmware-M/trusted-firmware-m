#-------------------------------------------------------------------------------
# Copyright (c) 2020-2023, Arm Limited. All rights reserved.
# Copyright 2025 NXP
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

################################## Dependencies ################################
set(TFM_PLATFORM_NXP_HAL_FILE_PATH         "LOCAL"      CACHE STRING     "Path to the NXP SDK hal")

############################# Platform ##########################################
set(CONFIG_TFM_USE_TRUSTZONE               ON           CACHE BOOL      "Use TrustZone")
set(TFM_MULTI_CORE_TOPOLOGY                OFF          CACHE BOOL      "Platform has multi core")

############################ Platform features ##########################################
set(MCUX_PSA_CRYPTO_DRIVER_ELS_PKC         OFF          CACHE BOOL      "Use psa-crypto-driver to use HW acceleration via driver wrappers")
set(USE_TFM_LPUART_FEATURE                 ON           CACHE BOOL      "LPUART enabled")
set(USE_ELS_PKC_HUK                        OFF          CACHE BOOL      "Use HUK via els_pkc")
set(USE_ELS_PKC_IAK                        OFF          CACHE BOOL      "Use IAK via els_pkc")
set(USE_HARDENED_PLATFORM_INIT             ON           CACHE BOOL      "Use hardening macros for frdmmcxn947 platform")

################################## LOG LEVEL #############################################################
set(TFM_SPM_LOG_LEVEL             LOG_LEVEL_INFO       CACHE STRING     "Set default SPM log level as INFO level" FORCE)
set(TFM_PARTITION_LOG_LEVEL       LOG_LEVEL_INFO       CACHE STRING     "Set default Secure Partition log level as INFO level" FORCE)
