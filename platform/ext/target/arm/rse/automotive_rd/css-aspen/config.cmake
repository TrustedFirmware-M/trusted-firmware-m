#-------------------------------------------------------------------------------
# SPDX-License-Identifier: BSD-3-Clause
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
#-------------------------------------------------------------------------------

# Note: Cached varaibles always take the first value set, while normal
# variables always take the last.

set(CONFIG_TFM_SPM_BACKEND              IPC      CACHE STRING  "The SPM backend")
set(MCUBOOT_IMAGE_NUMBER                4        CACHE STRING  "Number of images supported by MCUBoot")
set(MULTI_RSE_TOPOLOGY_FILE             ${CMAKE_CURRENT_LIST_DIR}/rse_comms/rse_comms_topology.tgf CACHE STRING "Topology file for RSE to RSE BL1 communication")
set(PLATFORM_HAS_BOOT_DMA               OFF      CACHE BOOL    "Enable dma support for memory transactions for bootloader")
set(PLATFORM_HAS_PS_NV_OTP_COUNTERS     ON       CACHE BOOL    "Platform supports nvm counters for PS in OTP")
set(PLATFORM_HOST_HAS_SI_CL0            ON       CACHE BOOL    "Enable SI CL0 support")
set(PLATFORM_RSE_HAS_ATU_OWNERSHIP      ON       CACHE BOOL    "Enable RSE ATU ownership")
set(PLAT_MHU_VERSION                    3        CACHE STRING  "Supported MHU version by platform")
set(RSE_HAS_EXPANSION_PERIPHERALS       ON       CACHE BOOL    "Whether RSE has sub-platform specific peripherals in the expansion layer")
set(RSE_USE_HOST_FLASH                  OFF      CACHE BOOL    "Enable RSE using the host flash.")
set(RSE_USE_HOST_UART                   ON       CACHE BOOL    "Whether RSE should use the UART from the host system (opposed to dedicated UART private to RSE)")
set(RSE_USE_LOCAL_UART                  OFF      CACHE BOOL    "Whether RSE should use the local UART dedicated to RSE")
set(TFM_ATTESTATION_SCHEME              OFF      CACHE STRING  "Attestation scheme to use [OFF, PSA, CCA, DPE]")
set(TFM_BL1_MEMORY_MAPPED_FLASH         OFF      CACHE BOOL    "Whether BL1 can directly access flash content")
set(TFM_LOAD_NS_IMAGE                   OFF      CACHE BOOL    "Whether to load an NS image")
set(TFM_MANIFEST_LIST                   "${CMAKE_CURRENT_LIST_DIR}/manifest/tfm_manifest_list.yaml" CACHE PATH "Platform specific Secure Partition manifests file")
set(TFM_MBEDCRYPTO_PLATFORM_EXTRA_CONFIG_PATH "" CACHE PATH    "Config to append to standard Mbed Crypto config, used by platforms to configure feature support")
set(TFM_MBEDCRYPTO_PSA_CRYPTO_PLATFORM_EXTRA_CONFIG_PATH  ""    CACHE PATH      "Config to append to standard PSA Crypto setting for Mbed Crypto, used by platforms to configure cryptographic feature support.")
set(TFM_PARTITION_INTERNAL_TRUSTED_STORAGE ON    CACHE BOOL    "Enable Internal Trusted Storage partition")
set(TFM_PARTITION_PROTECTED_STORAGE     ON       CACHE BOOL    "Enable Protected Storage partition")
set(RSE_COMMS_NUMBER_NODES              3        CACHE STRING  "Amount of nodes in the RSE comms system, by default equal to number of RSEs")

# Once all cache options are set, set common options as fallback
include(${CMAKE_CURRENT_LIST_DIR}/../../common/config.cmake)
