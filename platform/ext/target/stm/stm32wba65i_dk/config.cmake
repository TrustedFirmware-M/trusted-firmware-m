#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
# Copyright (c) 2021 STMicroelectronics. All rights reserved.
# Copyright (c) 2022 Cypress Semiconductor Corporation (an Infineon company)
# or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

################################## Dependencies #######################################################
set(TFM_PARTITION_INTERNAL_TRUSTED_STORAGE ON           CACHE BOOL      "Enable Internal Trusted Storage partition")
set(TFM_PARTITION_CRYPTO                   ON           CACHE BOOL      "Enable Crypto partition")
set(TFM_PARTITION_PROTECTED_STORAGE        ON           CACHE BOOL        "Enable Protected Storage partition")
set(TFM_PARTITION_INITIAL_ATTESTATION      ON           CACHE BOOL      "Disable Initial Attestation partition")
set(CRYPTO_HW_ACCELERATOR                  ON           CACHE BOOL      "Whether to enable the crypto hardware accelerator on supported platforms")
set(MBEDCRYPTO_BUILD_TYPE                  minsizerel   CACHE STRING    "Build type of Mbed Crypto library")
set(TFM_DUMMY_PROVISIONING                 ON           CACHE BOOL      "Provision with dummy values. NOT to be used in production")
set(PLATFORM_DEFAULT_OTP_WRITEABLE         ON           CACHE BOOL      "Use on chip flash with write support")
set(PLATFORM_DEFAULT_NV_COUNTERS           ON           CACHE BOOL      "Use default nv counter implementation.")
set(PLATFORM_DEFAULT_OTP                   ON           CACHE BOOL      "Use trusted on-chip flash to implement OTP memory")
set(PS_CRYPTO_AEAD_ALG                     PSA_ALG_GCM  CACHE STRING    "The AEAD algorithm to use for authenticated encryption in Protected Storage")
set(TFM_PARTITION_PLATFORM                ON)
set(DEFAULT_MCUBOOT_FLASH_MAP             ON           CACHE BOOL     "Whether to use the default flash map defined by TF-M project")
set(MCUBOOT_IMAGE_NUMBER                2           CACHE STRING    "Whether to combine S and NS into either 1 image, or sign each seperately")
################################## Platform-specific configurations ####################################
set(BL2                                    OFF          CACHE BOOL      "Whether to build BL2")
set(CONFIG_TFM_USE_TRUSTZONE               ON           CACHE BOOL      "Use TrustZone")
set(TFM_MULTI_CORE_TOPOLOGY                OFF          CACHE BOOL      "Platform has multi core")
set(PLATFORM_HAS_FIRMWARE_UPDATE_SUPPORT   ON           CACHE BOOL      "Wheter the platform has firmware update support")
set(TFM_OTP_DEFAULT_PROVIONNING            ON           CACHE BOOL      "OTP AREA provisionning by TFM")
set(DEFAULT_SHARED_DATA                    ON           CACHE BOOL       "SHARED_DATA provisionning by TFM")
################################## LOG LEVEL #############################################################
set(TFM_SPM_LOG_LEVEL                      LOG_LEVEL_VERBOSE         CACHE STRING    "Set default SPM log level as INFO level")
set(TFM_PARTITION_LOG_LEVEL                LOG_LEVEL_VERBOSE         CACHE STRING    "Set default Secure Partition log level as INFO level")
################################## FIRMWARE_UPDATE #############################################################
set(TFM_PARTITION_FIRMWARE_UPDATE          ON          CACHE BOOL "Enable firmware update partition")
set(TFM_FWU_BOOTLOADER_LIB                 "mcuboot"   CACHE STRING    "Bootloader configure file for Firmware Update partition")
set(TFM_CONFIG_FWU_MAX_WRITE_SIZE          1024        CACHE STRING    "The maximum permitted size for block in psa_fwu_write, in bytes.")
set(TFM_CONFIG_FWU_MAX_MANIFEST_SIZE       0           CACHE STRING    "The maximum permitted size for manifest in psa_fwu_start(), in bytes.")
set(FWU_DEVICE_CONFIG_FILE                 ""          CACHE STRING    "The device configuration file for Firmware Update partition")
set(DMCUBOOT_UPGRADE_STRATEGY              SWAP_USING_MOVE)
set(MCUBOOT_DATA_SHARING                  ON           CACHE BOOL      "Add sharing of application specific data using the same shared data area as for the measured boot")
