#-------------------------------------------------------------------------------
# Copyright (c) 2021-2024, Arm Limited. All rights reserved.
# Copyright (c) 2022 Cypress Semiconductor Corporation (an Infineon company)
# or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

set(DEFAULT_NS_SCATTER           ON         CACHE BOOL      "Use default NS scatter files for target")
set(PROVISIONING_KEYS_CONFIG     ""         CACHE FILEPATH  "The config file which has the keys and seeds for provisioning")

set(S_DATA_OVERALL_SIZE      "0x20000"    CACHE STRING    "Secure data size")
set(FLASH_S_PARTITION_SIZE   "0x80000"    CACHE STRING    "Secure code size")
set(FLASH_NS_PARTITION_SIZE  "0x300000"   CACHE STRING    "Non-secure code size")

if(BL2)
    set(BL2_TRAILER_SIZE 0x800 CACHE STRING "Trailer size")
else()
    #No header if no bootloader, but keep IMAGE_CODE_SIZE the same
    set(BL2_TRAILER_SIZE 0xC00 CACHE STRING "Trailer size")
endif()

set(TFM_PXN_ENABLE                    ON    CACHE BOOL    "Use Privileged execute never (PXN)")

# Platform-specific configurations
set(CONFIG_TFM_USE_TRUSTZONE          ON)
set(TFM_MULTI_CORE_TOPOLOGY           OFF)

# Ethos-U NPU configurations
set(ETHOSU_ARCH                       "U55"            CACHE STRING    "Ethos-U NPU type [U55,U65]")
set(ETHOS_DRIVER_PATH                 "DOWNLOAD"       CACHE PATH      "Path to Ethos-U Core Driver (or DOWNLOAD to fetch automatically")
set(ETHOSU_LOG_SEVERITY               "-1"             CACHE STRING    "Ethos-U Core Driver log severity")

set(MCUBOOT_SIGNATURE_TYPE            "EC-P256"        CACHE STRING    "Algorithm to use for signature validation [RSA-2048, RSA-3072, EC-P256, EC-P384]")
set(MCUBOOT_HW_KEY                    OFF              CACHE BOOL      "Whether to embed the entire public key in the image metadata instead of the hash only")
set(MCUBOOT_BUILTIN_KEY               ON               CACHE BOOL      "Use builtin key(s) for validation, no public key data is embedded into the image metadata")
