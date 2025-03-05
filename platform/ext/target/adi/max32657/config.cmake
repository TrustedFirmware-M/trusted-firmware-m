#-------------------------------------------------------------------------------
# Portions Copyright (C) 2024-2025 Analog Devices, Inc.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

set(BL1                                 OFF         CACHE BOOL      "Enable/disable ADI Secure Boot ROM, BL2 image will be signed")
set(PLATFORM_DEFAULT_BL1                OFF         CACHE STRING    "ADI provides Secure Boot ROM so that disable default BL1")
set(TFM_BL2_SIGNING_KEY_PATH            ""          CACHE FILEPATH  "")

set(BL2                                 ON         CACHE BOOL     "Whether to build BL2")
set(CONFIG_TFM_USE_TRUSTZONE            ON)
set(TFM_PARTITION_PROTECTED_STORAGE     ON           CACHE BOOL      "Enable Protected Stroage partition")
set(TFM_PARTITION_PLATFORM              ON           CACHE BOOL      "Enable Platform partition")
set(TFM_PARTITION_CRYPTO                ON          CACHE BOOL      "Enable Crypto partition")
set(TFM_PARTITION_INTERNAL_TRUSTED_STORAGE ON       CACHE BOOL      "Enable Internal Trusted Storage partition")
set(TFM_PARTITION_NS_AGENT_TZ           ON         CACHE BOOL      "Enable Non-Secure Agent in Secure partition")
set(CONFIG_TFM_BOOT_STORE_MEASUREMENTS          ON   CACHE BOOL      "Store measurement values from all the boot stages. Used for initial attestation token.")
set(CONFIG_TFM_BOOT_STORE_ENCODED_MEASUREMENTS  ON   CACHE BOOL      "Enable storing of encoded measurements in boot.")
set(TFM_PARTITION_INITIAL_ATTESTATION           ON   CACHE BOOL      "Enable Initial Attestation partition")
set(CONFIG_TFM_HALT_ON_CORE_PANIC               ON   CACHE BOOL      "On fatal errors in the secure firmware, halt instead of rebooting.")
set(PLATFORM_DEFAULT_OTP                OFF          CACHE BOOL      "Use trusted on-chip flash to implement OTP memory")

set(ITS_ENCRYPTION                      OFF          CACHE BOOL      "Enable authenticated encryption of ITS files using platform specific APIs")
set(ITS_CRYPTO_AEAD_ALG                 ITS_AES_GCM  CACHE STRING    "The AEAD algorithm to use for authenticated encryption in Internal Storage")

set(PLATFORM_DEFAULT_PROVISIONING       ON        CACHE BOOL      "Use default provisioning implementation")
set(PROVISIONING_DATA_PADDED_SIZE       "0x400"   CACHE STRING    "")
set(PROVISIONING_KEYS_CONFIG            ""        CACHE FILEPATH  "The config file which has the keys and seeds for provisioning")
set(PROVISIONING_CODE_PADDED_SIZE       "0x2000"  CACHE STRING    "")
set(PROVISIONING_VALUES_PADDED_SIZE     "0x400"   CACHE STRING    "")

set(HAL_ADI_PATH                        "DOWNLOAD"  CACHE PATH      "Path to hal_adi (or DOWNLOAD to fetch automatically")
set(HAL_ADI_VERSION                     "dd1c525"   CACHE STRING    "The version of hal_adi to use")

set(MCUBOOT_USE_PSA_CRYPTO             ON          CACHE BOOL      "Use PSA Crypto for MCUBOOT")

set(CRYPTO_HW_ACCELERATOR              ON          CACHE BOOL      "Enable hardware crypto accelerator")
set(CRYPTO_HW_ACCELERATOR_TYPE         "adi"       CACHE STRING    "The hardware accelerator platform")

if (TFM_PROFILE STREQUAL "profile_small")
    # Static Buffer size for MBEDTLS allocations - Has been increased from the default value of small profile
    # to ensure that initial attestation testcases in regression build passes and generate random number successfully.
    add_compile_definitions(CRYPTO_ENGINE_BUF_SIZE=0x800)
endif()

if(TFM_PARTITION_PROTECTED_STORAGE)
    # Enable single part functions in crypto library needed for PS Encryption
    set(CRYPTO_SINGLE_PART_FUNCS_DISABLED OFF CACHE BOOL "Disable single part functions in crypto library")
endif()
