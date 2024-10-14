#-------------------------------------------------------------------------------
# SPDX-License-Identifier: BSD-3-Clause
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
#-------------------------------------------------------------------------------

# Note: Cached varaibles always take the first value set, while normal
# variables always take the last.

set(CONFIG_TFM_SPM_BACKEND              IPC      CACHE STRING  "The SPM backend")
set(MCUBOOT_IMAGE_NUMBER                4        CACHE STRING  "Number of images supported by MCUBoot")
set(PLATFORM_HAS_BOOT_DMA               OFF      CACHE BOOL    "Enable dma support for memory transactions for bootloader")
set(PLAT_MHU_VERSION                    3        CACHE STRING  "Supported MHU version by platform")
set(RSE_HAS_EXPANSION_PERIPHERALS       ON       CACHE BOOL    "Whether RSE has sub-platform specific peripherals in the expansion layer")
set(RSE_USE_HOST_FLASH                  OFF      CACHE BOOL    "Enable RSE using the host flash.")
set(RSE_USE_HOST_UART                   ON       CACHE BOOL    "Whether RSE should use the UART from the host system (opposed to dedicated UART private to RSE)")
set(RSE_USE_LOCAL_UART                  OFF      CACHE BOOL    "Whether RSE should use the local UART dedicated to RSE")
set(TFM_ATTESTATION_SCHEME              OFF      CACHE STRING  "Attestation scheme to use [OFF, PSA, CCA, DPE]")
set(TFM_BL1_MEMORY_MAPPED_FLASH         OFF      CACHE BOOL    "Whether BL1 can directly access flash content")
set(TFM_LOAD_NS_IMAGE                   OFF      CACHE BOOL    "Whether to load an NS image")
set(TFM_MBEDCRYPTO_PSA_CRYPTO_PLATFORM_EXTRA_CONFIG_PATH  ""    CACHE PATH      "Config to append to standard PSA Crypto setting for Mbed Crypto, used by platforms to configure cryptographic feature support.")
set(TFM_PLAT_SPECIFIC_MULTI_CORE_COMM   OFF      CACHE BOOL    "Whether to use a platform specific inter-core communication instead of mailbox in dual-cpu topology")

# Once all cache options are set, set common options as fallback
include(${CMAKE_CURRENT_LIST_DIR}/../../common/config.cmake)

set(TFM_MULTI_CORE_TOPOLOGY             OFF)
