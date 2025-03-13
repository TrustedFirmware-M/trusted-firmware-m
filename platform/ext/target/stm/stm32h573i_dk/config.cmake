#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
# Copyright (c) 2021 STMicroelectronics. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

################################## BL2 #################################################
set(MCUBOOT_IMAGE_NUMBER                   2           CACHE STRING    "Whether to combine S and NS into either 1 image, or sign each seperately")
set(BL2_HEADER_SIZE                        0x400       CACHE STRING    "Header size")
set(BL2_TRAILER_SIZE                       0x2000      CACHE STRING    "Trailer size")
set(MCUBOOT_ALIGN_VAL                      16          CACHE STRING    "Align option to build image with imgtool")
set(MCUBOOT_UPGRADE_STRATEGY        "SWAP_USING_SCRATCH"      CACHE STRING    "Upgrade strategy for images")
set(TFM_PARTITION_PLATFORM                 ON          CACHE BOOL      "Enable platform partition")
set(MCUBOOT_DATA_SHARING                   ON          CACHE BOOL      "Enable Data Sharing")
set(MCUBOOT_BOOTSTRAP                      ON          CACHE BOOL      "Allow initial state with images in secondary slots(empty primary slots)")
set(MCUBOOT_ENC_IMAGES                     ON          CACHE BOOL      "Enable encrypted image upgrade support")
set(MCUBOOT_ENCRYPT_RSA                    ON          CACHE BOOL      "Use RSA for encrypted image upgrade support")
################################## Dependencies ########################################
set(TFM_PARTITION_INTERNAL_TRUSTED_STORAGE ON          CACHE BOOL      "Enable Internal Trusted Storage partition")
set(TFM_PARTITION_CRYPTO                   ON          CACHE BOOL      "Enable Crypto partition")
set(CRYPTO_HW_ACCELERATOR                  ON          CACHE BOOL      "Whether to enable the crypto hardware accelerator on supported platforms")
set(MBEDCRYPTO_BUILD_TYPE                  minsizerel  CACHE STRING    "Build type of Mbed Crypto library")
set(PS_CRYPTO_AEAD_ALG                     PSA_ALG_GCM CACHE STRING    "The AEAD algorithm to use for authenticated encryption in Protected Storage")
set(MCUBOOT_FIH_PROFILE                    LOW         CACHE STRING    "Fault injection hardening profile [OFF, LOW, MEDIUM, HIGH]")
################################## LOG LEVEL ###########################################
set(TFM_SPM_LOG_LEVEL             LOG_LEVEL_INFO       CACHE STRING    "Set default SPM log level as INFO level")
set(TFM_PARTITION_LOG_LEVEL       LOG_LEVEL_INFO       CACHE STRING    "Set default Secure Partition log level as INFO level")
set(MCUBOOT_HW_ROLLBACK_PROT            ON          CACHE BOOL      "Enable security counter validation against non-volatile HW counters")
################################## Platform-specific configurations ####################################
set(CONFIG_TFM_USE_TRUSTZONE               ON           CACHE BOOL      "Use TrustZone")
set(TFM_PARTITION_PROTECTED_STORAGE        ON           CACHE BOOL      "Disable Protected Storage partition")
set(TFM_PARTITION_INITIAL_ATTESTATION      ON           CACHE BOOL      "Disable Initial Attestation partition")
set(PLATFORM_HAS_FIRMWARE_UPDATE_SUPPORT   ON           CACHE BOOL      "Wheter the platform has firmware update support")
################################## FIRMWARE_UPDATE #############################################################
set(TFM_PARTITION_FIRMWARE_UPDATE          ON           CACHE BOOL      "Enable firmware update partition")
set(TFM_FWU_BOOTLOADER_LIB                 "mcuboot"    CACHE STRING    "Bootloader configure file for Firmware Update partition")
set(TFM_CONFIG_FWU_MAX_WRITE_SIZE          1024         CACHE STRING    "The maximum permitted size for block in psa_fwu_write, in bytes.")
set(TFM_CONFIG_FWU_MAX_MANIFEST_SIZE       0            CACHE STRING    "The maximum permitted size for manifest in psa_fwu_start(), in bytes.")
set(FWU_DEVICE_CONFIG_FILE                 ""           CACHE STRING    "The device configuration file for Firmware Update partition")
set(DMCUBOOT_UPGRADE_STRATEGY              SWAP_USING_MOVE)
set(DEFAULT_MCUBOOT_FLASH_MAP             ON            CACHE BOOL     "Whether to use the default flash map defined by TF-M project")
