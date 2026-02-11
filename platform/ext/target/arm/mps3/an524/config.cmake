#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
# Copyright (c) 2022 Cypress Semiconductor Corporation (an Infineon company)
# or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

set(MCUBOOT_IMAGE_NUMBER                1            CACHE STRING "Whether to combine S and NS into either 1 image, or sign each separately")
set(MCUBOOT_UPGRADE_STRATEGY            "DIRECT_XIP" CACHE STRING "Upgrade strategy for images")
if(NOT BL2)
    set(BL2_TRAILER_SIZE                0x800        CACHE STRING "Trailer size")
endif()

set(TF_PSA_CRYPTO_BUILD_TYPE            minsizerel  CACHE STRING "Build type of TF-PSA-Crypto library")

# Platform-specific configurations
set(CONFIG_TFM_USE_TRUSTZONE            ON)
set(TFM_MULTI_CORE_TOPOLOGY             OFF)

set(PROVISIONING_KEYS_CONFIG            ""        CACHE FILEPATH  "The config file which has the keys and seeds for provisioning")
set(PROVISIONING_CODE_PADDED_SIZE       "0x2000"  CACHE STRING    "")
set(PROVISIONING_VALUES_PADDED_SIZE     "0x400"   CACHE STRING    "")
set(PROVISIONING_DATA_PADDED_SIZE       "0x400"   CACHE STRING    "")

set(MCUBOOT_SIGNATURE_TYPE            "EC-P256"        CACHE STRING    "Algorithm to use for signature validation [RSA-2048, RSA-3072, EC-P256, EC-P384]")
set(MCUBOOT_HW_KEY                    OFF              CACHE BOOL      "Whether to embed the entire public key in the image metadata instead of the hash only")
set(MCUBOOT_BUILTIN_KEY               ON               CACHE BOOL      "Use builtin key(s) for validation, no public key data is embedded into the image metadata")
