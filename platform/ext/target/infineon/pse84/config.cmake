#-------------------------------------------------------------------------------
# Copyright (c) 2023-2025 Cypress Semiconductor Corporation (an Infineon company)
# or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

################################### Platform ###################################

include(${IFX_PLATFORM_SOURCE_DIR}/config.cmake)
include(${IFX_FAMILY_SOURCE_DIR}/shared/config.cmake)

################################################################################

set(IFX_GENERATED_DIR "${CMAKE_BINARY_DIR}/generated" CACHE PATH "Path to the root directory of files generated during the build of SPE")

################################ Board support #################################

set(IFX_BOARD_PATH        "${IFX_FAMILY_SOURCE_DIR}/board/KIT_PSOCE84_EVK"   CACHE PATH    "Path to board config, override it to support custom board")

set(IFX_BSP_S_COMPONENTS  "CM33;SECURE_DEVICE" CACHE PATH    "List of BSP components used to build secure image")
set(IFX_BSP_S_EXCLUDE     ".+/cycfg_qspi_memslot\.c" # QSPI configuration can be used by multiple partitions
                          ".+/s_start_pse84\.c" # TFM uses own startup files as for now
                          ".+/cycfg_ppc\.c" # cycfg_ppc.c has protection settings, thus is linked to tfm_spm
                          ".+/cycfg_mpc\.c" # cycfg_mpc.c has functions to apply protection settings, TFM has own functions
                          ".+/cycfg_system\.c" # cycfg_system.c has protection settings, thus is linked to tfm_spm
                          ".+/s_system_pse84\.c" # s_system_pse84.c has data that are shared and linked into ${IFX_SHARED_RO_DATA_TARGET} library
                          ".+/tfm_config/.+" # tfm_config folder contains files that are added to the build manually (e.g. custom partitions)
                          CACHE PATH      "List of sources excluded from build of secure BSP target")

set(IFX_BSP_DEVICE_SUPPORT_LIBS "${IFX_COMMON_SOURCE_DIR}/deploy/mtb-personalities/props.json" CACHE STRING "List of additional device support libraries")

################################################################################

set(BL2                                OFF    CACHE BOOL    "Whether to build BL2")
# Even tho BL2 is disabled, BL2 header and trailer information is still needed
# for platform_region_defs to calculate image offsets
set(BL2_HEADER_SIZE                    0x400  CACHE STRING  "BL2 Header size")
# BL2_TRAILER_SIZE is handled in design.nodus file
set(BL2_TRAILER_SIZE                   0x0    CACHE STRING  "BL2 Trailer size")

# As there may be more than 2 images on PSE84, attestation token size may be bigger
set(PSA_INITIAL_ATTEST_MAX_TOKEN_SIZE  0x600  CACHE STRING  "The maximum possible size of a token")

set(TFM_PXN_ENABLE                     OFF    CACHE BOOL    "Use Privileged execute never (PXN)")

# Enable building se-rt services utils source files
set(IFX_SE_RT_SERVICES_UTILS_ENABLED   ON)

################################### Profile ####################################

if((TEST_PSA_API STREQUAL "CRYPTO") OR (TEST_NS_IFX_CRYPTO_BENCHMARK))
    # psa-arch-tests doesn't support profile_medium crypto tests.
    # TEST_NS_IFX_CRYPTO_BENCHMARK requires profile_large to benchmark different functions
    set(TFM_PROFILE                    profile_large CACHE STRING "Profile to use")
else()
    set(TFM_PROFILE                    profile_medium CACHE STRING "Profile to use")
endif()

#################################### IFX #######################################

set(IFX_CM33_NS_PRESENT                     ON   CACHE BOOL  "Enable CM33 NSPE for IFX platform")
set(IFX_CM55_NS_PRESENT                     OFF  CACHE BOOL  "Enable CM55 NSPE for IFX platform")

set(IFX_MPC_DRIVER_HW_MPC_V2                ON) # Use MPC driver v2
set(IFX_PPC_DRIVER_V2                       ON) # Use PPC driver v2
set(IFX_PPC_DOMAIN_CONFIGURATOR             ON) # Edge Configurator provides PPC domain configuration

set(IFX_SE_RT_SERVICES_UTILS_PATH           "DOWNLOAD"  CACHE PATH  "Path to Infineon SE RT Services Utils library (or DOWNLOAD to fetch automatically)")
set(IFX_SE_RT_SERVICES_UTILS_GIT_REMOTE     "https://github.com/Infineon/se-rt-services-utils.git" CACHE STRING "Infineon SE RT Services Utils library repo URL")
set(IFX_SE_RT_SERVICES_UTILS_VERSION        "release-v1.2.0" CACHE STRING  "The version of Infineon SE RT Services Utils library to use")
set(IFX_SE_RT_SERVICES_UTILS_S_TARGET       "ifx_se_rt_services_utils_s"  CACHE STRING  "Infineon SE RT Services Utils library target for S image used by Infineon platform")

set(IFX_MBEDTLS_ACCELERATION_LIB_PATH       "DOWNLOAD"  CACHE PATH  "Path to Infineon MBEDTLS Acceleration library (or DOWNLOAD to fetch automatically)")
set(IFX_MBEDTLS_ACCELERATION_LIB_GIT_REMOTE "https://github.com/Infineon/cy-mbedtls-acceleration" CACHE STRING "The URL (or path) to retrieve MBEDTLS Acceleration from.")
set(IFX_MBEDTLS_ACCELERATION_LIB_VERSION    "release-v3.0.0" CACHE STRING "The version of Infineon MBEDTLS Acceleration library to use")
set(IFX_MBEDTLS_ACCELERATOR_VALID_TYPES     "MXCRYPTO")
set(IFX_MBEDTLS_ACCELERATOR_TYPE            "MXCRYPTO"  CACHE STRING  "Specifies type of accelerator for a project")
set(IFX_MBEDTLS_ACCELERATION_ENABLED        OFF         CACHE BOOL  "Enable crypto accelerator")
set(IFX_MBEDTLS_ACCELERATION_PATCH_DIR      "${IFX_COMMON_SOURCE_DIR}/libs/ifx_mbedtls_acceleration/patch/mxcrypto" CACHE STRING "Path to mbedtls patches")

################################### Drivers ####################################

set(IFX_PLATFORM_DRIVERS_LIST               "SMIF_MMIO;RRAM")
set(IFX_ITS_VALID_TYPES                     "RRAM")
set(IFX_PS_VALID_TYPES                      "SMIF_MMIO;RRAM")

set(IFX_MTB_SRF                             ON          CACHE BOOL  "Enable MTB SRF functionality")

################################### Platform ###################################

set(CONFIG_TFM_USE_TRUSTZONE            ${IFX_CM33_NS_PRESENT}  CACHE BOOL  "Enable use of TrustZone to transition between NSPE and SPE")

set(IFX_MTB_MAILBOX                     ${IFX_CM55_NS_PRESENT}  CACHE BOOL  "Whether to use Infineon MTB mailbox implementation")

if(IFX_MTB_MAILBOX)
    set(TFM_MULTI_CORE_TOPOLOGY             OFF                     CACHE BOOL  "Whether to build for a dual-cpu architecture")
else()
    set(TFM_MULTI_CORE_TOPOLOGY             ${IFX_CM55_NS_PRESENT}  CACHE BOOL  "Whether to build for a dual-cpu architecture")
endif()

# CM33 managing NSID is only supported through shared data
if(TFM_NS_MANAGE_NSID AND ${IFX_CM33_NS_PRESENT})
    set(PLATFORM_NSID_IN_SHARED_DATA        ON)
endif()
set(NUM_MAILBOX_QUEUE_SLOT                  4U          CACHE STRING  "Number of mailbox queue slots")

set(MCUBOOT_DATA_SHARING                    ON          CACHE BOOL  "Add sharing of application specific data using the same shared data area as for the measured boot")
set(PS_CRYPTO_AEAD_ALG                      PSA_ALG_CCM CACHE STRING  "The AEAD algorithm to use for authenticated encryption in Protected Storage")

set(TFM_PARTITION_CRYPTO                    ON          CACHE BOOL  "Enable Crypto partition")
set(TFM_PARTITION_INTERNAL_TRUSTED_STORAGE  ON          CACHE BOOL  "Enable Internal Trusted Storage partition")
set(TFM_PARTITION_PROTECTED_STORAGE         ON          CACHE BOOL  "Enable Protected Storage partition")
set(TFM_PARTITION_PLATFORM                  ON          CACHE BOOL  "Enable Platform partition")
set(TFM_PARTITION_FIRMWARE_UPDATE           OFF         CACHE BOOL  "Enable firmware update partition")
set(TFM_PARTITION_INITIAL_ATTESTATION       ON          CACHE BOOL  "Enable Initial Attestation partition")

###################################################################################

include(${IFX_COMMON_SOURCE_DIR}/config.cmake)

include(${IFX_COMMON_SOURCE_DIR}/cmake/generate_sources.cmake)
