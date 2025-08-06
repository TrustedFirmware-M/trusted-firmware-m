#-------------------------------------------------------------------------------
# SPDX-License-Identifier: BSD-3-Clause
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
#
#-------------------------------------------------------------------------------

set(PROVISIONING_KEYS_CONFIG      ""        CACHE FILEPATH  "The config file which has the keys and seeds for provisioning")

if(BL2)
    set(BL2_TRAILER_SIZE 0x800 CACHE STRING "Trailer size")
else()
    #No header if no bootloader, but keep IMAGE_CODE_SIZE the same
    set(BL2_TRAILER_SIZE 0xC00 CACHE STRING "Trailer size")
endif()

# Platform-specific configurations
set(TFM_MULTI_CORE_TOPOLOGY           OFF  CACHE BOOL "Enable Multicore topology")
if (TFM_MULTI_CORE_TOPOLOGY)
    set(TFM_NS_MAILBOX_API                ON)
    set(TFM_PARTITION_NS_AGENT_MAILBOX    ON)
    set(TFM_NS_CUSTOM_API                 ON)
else()
    set(TFM_NS_MAILBOX_API                OFF)
    set(TFM_PARTITION_NS_AGENT_MAILBOX    OFF)
    set(TFM_NS_CUSTOM_API                 OFF)
endif()

set(MCUBOOT_USE_PSA_CRYPTO            ON               CACHE BOOL      "Enable the cryptographic abstraction layer to use PSA Crypto APIs")
set(MCUBOOT_SIGNATURE_TYPE            "EC-P256"        CACHE STRING    "Algorithm to use for signature validation [RSA-2048, RSA-3072, EC-P256, EC-P384]")
set(MCUBOOT_HW_KEY                    OFF              CACHE BOOL      "Whether to embed the entire public key in the image metadata instead of the hash only")
set(MCUBOOT_BUILTIN_KEY               ON               CACHE BOOL      "Use builtin key(s) for validation, no public key data is embedded into the image metadata")

set(PROVISIONING_CODE_PADDED_SIZE       "0x2000"  CACHE STRING    "")
set(PROVISIONING_VALUES_PADDED_SIZE     "0x400"   CACHE STRING    "")
set(PROVISIONING_DATA_PADDED_SIZE       "0x400"   CACHE STRING    "")

set(PICO_SDK_FETCH_FROM_GIT_TAG         "2.1.1"   CACHE STRING       "Use the define Pico SDK tag for the build")

set(TFM_MBEDCRYPTO_PLATFORM_EXTRA_CONFIG_PATH ${CMAKE_CURRENT_LIST_DIR}/mbedtls_extra_config.h CACHE PATH "Config to append to standard Mbed Crypto config, used by platforms to cnfigure feature support")

set(PLATFORM_DEFAULT_PROV_LINKER_SCRIPT OFF          CACHE BOOL      "Use default provisioning linker script")
set(ITS_ENCRYPTION                      ON           CACHE BOOL      "Enable authenticated encryption of ITS files using platform specific APIs")
set(PLATFORM_DEFAULT_NV_SEED            OFF          CACHE BOOL      "Use default NV seed implementation.")
set(PLATFORM_DEFAULT_OTP                OFF          CACHE BOOL      "Use trusted on-chip flash to implement OTP memory")
set(PLATFORM_DEFAULT_MEASUREMENT_SLOTS  OFF          CACHE BOOL      "Use default Measured Boot slots")
set(PLATFORM_DEFAULT_NV_COUNTERS        OFF          CACHE BOOL      "Use default nv counter implementation.")
set(PLATFORM_DEFAULT_ATTEST_HAL         OFF          CACHE BOOL      "Use default attest hal implementation.")
set(TFM_LOAD_NS_IMAGE                   ON           CACHE BOOL      "Whether to load an NS image")

if (TFM_LOAD_NS_IMAGE)
    set(CONFIG_TFM_USE_TRUSTZONE          ON)
else()
    set(CONFIG_TFM_USE_TRUSTZONE         OFF)
endif()

set(PLATFORM_DEFAULT_CRYPTO_KEYS        OFF          CACHE BOOL      "Use default crypto keys implementation.")

set(PS_NS_NV_COUNTER_IN_ITS             ON           CACHE BOOL      "Use ITS for PS and NS NV counters.")

set(TFM_PARTITION_DTPM_CLIENT           OFF          CACHE BOOL      "Enable dTPM client partition")

set(TFM_PARTITION_INITIAL_ATTESTATION   ON           CACHE BOOL  "Enable Initial Attestation partition")

set(TFM_PARTITION_MEASURED_BOOT         OFF          CACHE BOOL  "Enable Measured Boot partition")

if (TFM_PARTITION_INITIAL_ATTESTATION)
    set(TFM_PARTITION_MEASURED_BOOT         ON)
endif()

if (TFM_PARTITION_MEASURED_BOOT)
    set(CONFIG_TFM_BOOT_STORE_ENCODED_MEASUREMENTS  OFF     CACHE BOOL  "Enable storing of encoded measurements in boot.")
    set(MCUBOOT_DATA_SHARING                        ON      CACHE BOOL  "Enable Data Sharing")
    set(CONFIG_TFM_BOOT_STORE_MEASUREMENTS          ON      CACHE BOOL  "Store measurement values from all the boot stages. Used for initial attestation token.")
endif()

if (TFM_PARTITION_DTPM_CLIENT)
    set(TFM_PARTITION_MEASURED_BOOT         ON)
    set(CS_GPIO       25  CACHE STRING "CS GPIO pin number")
    set(MISO_GPIO     23  CACHE STRING "MISO GPIO pin number")
    set(MOSI_GPIO     20  CACHE STRING "MOSI GPIO pin number")
    set(SCLK_GPIO     22  CACHE STRING "SCLK GPIO pin number")
    set(RESET_GPIO    5   CACHE STRING "RESET GPIO pin number")
    set(SPI_MODE      0   CACHE STRING "SPI mode")
    set(SPI_DELAY_US 1000 CACHE STRING "SPI delay (us)")
endif()

set(MEASURED_BOOT_HASH_ALG              SHA256     CACHE STRING "Hash algorithm used by Measured boot services")

if (PS_NS_NV_COUNTER_IN_ITS)
    # Config to append to standard TFM_SP_PLATFORM, to add dependency on ITS partition
    set(TFM_RP2350_MANIFEST_LIST ${CMAKE_CURRENT_LIST_DIR}/manifest/tfm_manifest_list.yaml)
else()
    set(TFM_RP2350_MANIFEST_LIST ${CMAKE_SOURCE_DIR}/tools/tfm_manifest_list.yaml)
endif()
set(TFM_MANIFEST_LIST                   ${TFM_RP2350_MANIFEST_LIST} CACHE PATH "Platform specific Secure Partition manifests file" FORCE)

set(TFM_EXTRAS_REPO_EXTRA_MANIFEST_LIST "partitions/measured_boot/measured_boot_manifest_list.yaml;partitions/dtpm_client/dtpm_client_manifest_list.yaml" CACHE STRING "List of extra secure partition manifests")

set(TFM_EXTRAS_REPO_EXTRA_PARTITIONS    "measured_boot;dtpm_client" CACHE STRING "List of extra secure partition directory name(s)")
