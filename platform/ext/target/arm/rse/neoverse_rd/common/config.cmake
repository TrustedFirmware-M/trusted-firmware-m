#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

# Note: Cached variables always take the first value set, while normal
# variables always take the last.

set(TFM_BL1_MEMORY_MAPPED_FLASH         OFF      CACHE BOOL    "Whether BL1 can directly access flash content")
set(TFM_ATTESTATION_SCHEME              "CCA"    CACHE STRING  "Attestation scheme to use [OFF, PSA, CCA, DPE]")

set(PLATFORM_HAS_BOOT_DMA               OFF      CACHE BOOL    "Enable dma support for memory transactions for bootloader")
set(PLATFORM_HOST_HAS_SCP               ON       CACHE BOOL    "Enable SCP support")
set(PLATFORM_HOST_HAS_MCP               ON       CACHE BOOL    "Enable MCP support")
set(PLATFORM_HAS_NOC_S3                 ON       CACHE BOOL    "Enable NoC S3 support")
set(PLATFORM_HAS_SMMU_V3                ON       CACHE BOOL    "Enable SMMU V3 support")

# This sub-platform uses a mix of MHUv2 in BL1 and MHUv3 in other firmware.
# Because of this, PLAT_MHU_VERSION cannot be set to 2 or 3, which would add
# either MHUv2 or MHUv3 for all firmware. To work around this, set
# PLAT_MHU_VERSION to 0 so neither gets added by the common cmake and
# sub-platform specific cmake can be used to handle the mix of MHUv2 and MHUv3.
set(PLAT_MHU_VERSION                    0        CACHE STRING  "Supported MHU version by platform")
set(PLAT_SHARED_LCP                     FALSE    CACHE BOOL    "Whether shared LCP is enabled where LCP cores are mapped to AP cores in 1:N mapping opposed to 1:1")
set(MCUBOOT_IMAGE_NUMBER                6        CACHE STRING  "Number of images supported by MCUBoot")
set(RSE_USE_HOST_UART                   OFF      CACHE BOOL    "Whether RSE should use the UART from the host system (opposed to dedicated UART private to RSE)")
set(RSE_USE_HOST_FLASH                  OFF      CACHE BOOL    "Enable RSE using the host flash.")
set(RSE_HAS_EXPANSION_PERIPHERALS       ON       CACHE BOOL    "Whether RSE has sub-platform specific peripherals in the expansion layer")
set(TFM_LOAD_NS_IMAGE                   OFF      CACHE BOOL    "Whether to load an NS image")
set(CONFIG_TFM_SPM_BACKEND              IPC      CACHE STRING  "The SPM backend")
set(TFM_MANIFEST_LIST                   "${CMAKE_CURRENT_LIST_DIR}/manifest/tfm_manifest_list.yaml" CACHE PATH "Platform specific Secure Partition manifests file")

set(RSE_OTP_HAS_RSE_ID                  ON       CACHE BOOL    "Use RSE ID")

math(EXPR RSE_COMMS_NUMBER_NODES_EXPR "${RSE_AMOUNT} + 2")
set(RSE_COMMS_NUMBER_NODES ${RSE_COMMS_NUMBER_NODES_EXPR} CACHE STRING "Amount of nodes in the RSE comms system, by default equal to number of RSEs")

# Once all cache options are set, set common options as fallback
include(${CMAKE_CURRENT_LIST_DIR}/../../common/config.cmake)
