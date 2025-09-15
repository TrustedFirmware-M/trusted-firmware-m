#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
# Copyright (c) 2022 Cypress Semiconductor Corporation (an Infineon company)
# or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

set(BL1                                 ON         CACHE BOOL     "Whether to build BL1")
set(PLATFORM_DEFAULT_BL1                ON         CACHE STRING   "Whether to use default BL1 or platform-specific one")
set(PLATFORM_DEFAULT_OTP                OFF        CACHE BOOL     "Use trusted on-chip flash to implement OTP memory")
set(PLATFORM_DEFAULT_MEASUREMENT_SLOTS  ON         CACHE BOOL     "Use default Measured Boot slots")

set(TFM_BL1_DEFAULT_PROVISIONING        OFF        CACHE BOOL     "Whether BL1_1 will use default provisioning")
set(TFM_BL1_SOFTWARE_CRYPTO             OFF        CACHE BOOL     "Whether BL1_1 will use software crypto")
set(TFM_BL1_MEMORY_MAPPED_FLASH         OFF        CACHE BOOL     "Whether BL1 can directly access flash content")
set(BL1_1_SHARED_SYMBOLS_PATH           ${CMAKE_CURRENT_LIST_DIR}/bl1/bl1_1_shared_symbols.txt CACHE FILEPATH "Path to list of symbols that BL1_1 will share with BL1_2")

set(TFM_BL2_IMAGE_FLASH_AREA_NUM        0          CACHE STRING   "Which flash area BL2 is stored in")
set(MCUBOOT_S_IMAGE_FLASH_AREA_NUM      2          CACHE STRING   "ID of the flash area containing the primary Secure image")

set(BL2                                 ON         CACHE BOOL     "Whether to build BL2")
set(BL2_TRAILER_SIZE                    0x800      CACHE STRING   "Trailer size")
set(DEFAULT_MCUBOOT_FLASH_MAP           OFF        CACHE BOOL     "Whether to use the default flash map defined by TF-M project")
set(MCUBOOT_UPGRADE_STRATEGY            "RAM_LOAD" CACHE STRING   "Upgrade strategy when multiple boot images are loaded")
set(MCUBOOT_SECURITY_COUNTER_S          "1"      CACHE STRING    "Security counter for S image. auto sets it to IMAGE_VERSION_S")

set(MCUBOOT_IMAGE_NUMBER                2          CACHE STRING   "Whether to combine S and NS into either 1 image, or sign each separately")
set(TFM_ISOLATION_LEVEL                 2          CACHE STRING   "Isolation level")

set(TFM_PLAT_SPECIFIC_MULTI_CORE_COMM   ON         CACHE BOOL     "Whether to use a platform specific inter core communication instead of mailbox in dual-cpu topology")

set(CRYPTO_HW_ACCELERATOR               ON         CACHE BOOL      "Whether to enable the crypto hardware accelerator on supported platforms")

set(TFM_CRYPTO_TEST_ALG_CFB             OFF        CACHE BOOL     "Test CFB cryptography mode" FORCE)
set(NS                                  FALSE      CACHE BOOL     "Whether to build NS app")
set(EXTERNAL_SYSTEM_SUPPORT             OFF        CACHE BOOL     "Whether to include external system support.")

if (${PLATFORM_IS_FVP})
    set(PLATFORM_PSA_ADAC_SECURE_DEBUG      FALSE        CACHE BOOL      "Whether to use psa-adac secure debug.")
else()
    set(PLATFORM_PSA_ADAC_SECURE_DEBUG      FALSE        CACHE BOOL      "Whether to use psa-adac secure debug.")
endif()

set(DEFAULT_MCUBOOT_SECURITY_COUNTERS       OFF          CACHE BOOL      "Whether to use the default security counter configuration defined by TF-M project")

# LOG LEVEL
set(TFM_SPM_LOG_LEVEL                   LOG_LEVEL_INFO          CACHE STRING    "Set default SPM log level as INFO level")
set(TFM_PARTITION_LOG_LEVEL             LOG_LEVEL_INFO          CACHE STRING    "Set default Secure Partition log level as INFO level")

# Partition
set(TFM_PARTITION_PLATFORM              ON          CACHE BOOL      "Enable Platform partition")
set(TFM_PARTITION_PROTECTED_STORAGE     ON          CACHE BOOL      "Enable Protected Storage partition")
set(TFM_PARTITION_CRYPTO                ON          CACHE BOOL      "Enable Crypto partition")
set(TFM_PARTITION_INITIAL_ATTESTATION   ON          CACHE BOOL      "Enable Initial Attestation partition")
set(TFM_PARTITION_INTERNAL_TRUSTED_STORAGE ON       CACHE BOOL      "Enable Internal Trusted Storage partition")

set(TFM_PARTITION_FIRMWARE_UPDATE         ON         CACHE BOOL      "Enable firmware update partition")
set(PLATFORM_HAS_FIRMWARE_UPDATE_SUPPORT  ON         CACHE BOOL      "Whether the platform has firmware update support")
set(MCUBOOT_DATA_SHARING                  ON         CACHE BOOL      "Enable Data Sharing")
set(TFM_FWU_BOOTLOADER_LIB                "${CMAKE_CURRENT_LIST_DIR}/bootloader/mcuboot"   CACHE STRING    "Bootloader configuration file for Firmware Update partition")
set(TFM_CONFIG_FWU_MAX_MANIFEST_SIZE      0          CACHE STRING    "The maximum permitted size for manifest in psa_fwu_start(), in bytes.")
set(TFM_CONFIG_FWU_MAX_WRITE_SIZE         4096       CACHE STRING    "The maximum permitted size for block in psa_fwu_write, in bytes.")
set(FWU_SUPPORT_TRIAL_STATE               ON         CACHE BOOL      "Device support TRIAL component state.")

if (${CMAKE_BUILD_TYPE} STREQUAL Debug OR ${CMAKE_BUILD_TYPE} STREQUAL RelWithDebInfo)
  set(ENABLE_FWU_AGENT_DEBUG_LOGS     TRUE          CACHE BOOL      "Enable Firmware update agent debug logs.")
  set(PLAT_LOG_LEVEL                    4           CACHE STRING    "Set platform log level.")
else()
  set(ENABLE_FWU_AGENT_DEBUG_LOGS     FALSE         CACHE BOOL      "Enable Firmware update agent debug logs.")
  set(PLAT_LOG_LEVEL                    0           CACHE STRING    "Set platform log level.")
endif()

set(TFM_DEBUG_OPTIMISATION              ON         CACHE BOOL      "Add basic -Og optimisation when CMAKE_BUILD_TYPE is Debug. Note that non Debug builds specify their own optimisation")

# Platform-specific configurations
set(CONFIG_TFM_USE_TRUSTZONE            OFF)
set(TFM_MULTI_CORE_TOPOLOGY             ON)

set(MCUBOOT_USE_PSA_CRYPTO            ON               CACHE BOOL      "Enable the cryptographic abstraction layer to use PSA Crypto APIs")
set(MCUBOOT_SIGNATURE_TYPE            "EC-P256"        CACHE STRING    "Algorithm to use for signature validation [RSA-2048, RSA-3072, EC-P256, EC-P384]")
set(MCUBOOT_HW_KEY                    OFF              CACHE BOOL      "Whether to embed the entire public key in the image metadata instead of the hash only")
set(MCUBOOT_BUILTIN_KEY               ON               CACHE BOOL      "Use builtin key(s) for validation, no public key data is embedded into the image metadata")
set(CONFIG_BOOT_RAM_LOAD              ON               CACHE BOOL      "Whether to enable RAM load support")

if (PLATFORM_PSA_ADAC_SECURE_DEBUG)
  # Disable ADAC as TF-M runtime service by default when secure debug is enabled
  set(PSA_ADAC_AS_TFM_RUNTIME_SERVICE     OFF          CACHE BOOL      "Integrate ADAC as TF-M runtime service")
endif()

if (PSA_ADAC_AS_TFM_RUNTIME_SERVICE)
    set(TFM_PARTITION_ADAC                  ON      CACHE BOOL   "Enable Authenticated Debug partition")
    set(TFM_EXTRAS_REPO_EXTRA_PARTITIONS    "adac"  CACHE STRING "List of extra secure partition directory name(s)")
    # Below TFM_EXTRAS_REPO_EXTRA_MANIFEST_LIST path is relative to tf-m-extras repo
    set(TFM_EXTRAS_REPO_EXTRA_MANIFEST_LIST "partitions/adac/adac_manifest_list.yaml" CACHE STRING "List of extra secure partition manifests")
endif()
