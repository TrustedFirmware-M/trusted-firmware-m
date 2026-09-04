#-------------------------------------------------------------------------------
# (c) 2026, Infineon Technologies AG, or an affiliate of Infineon
# Technologies AG. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

# BSP config.cmake uses IFX_BSP_DESIGN_FILE_NAME, thus it must be
# defined before BSP config.cmake is included
set(IFX_BSP_DESIGN_FILE_NAME "flash"     CACHE STRING "Name of BSP design file to use")

#################################### Board #####################################

# Include board specific configuration at the beginning to allow override configuration provided by platform
set(IFX_CONFIG_BSP_PATH   "${CMAKE_CURRENT_LIST_DIR}/board" CACHE PATH "Path to individual BSP configurations")
include(${IFX_CONFIG_BSP_PATH}/config.cmake)

set(IFX_BOARD_PATH        ${IFX_CONFIG_BSP_PATH}   CACHE PATH    "Path to board config, override it to support custom board")

set(IFX_BSP_S_COMPONENTS  "CM33;SECURE_DEVICE" CACHE PATH    "List of BSP components used to build secure image")
set(IFX_BSP_S_EXCLUDE     ".+/cybsp_dsram\.c" # Power Management (e.g. DSRAM callbacks) is not supported
                          ".+/cybsp_pm_.+\.c" ".+/cybsp_pm\.c" # Power management is not supported
                          ".+/startup_cat1b_cm33\.c" # TFM uses own startup files as for now
                          ".+/system_psc3_x6\.c" # system_psc3_x6.c has data that are shared and linked into ifx_tfm_sp_meta library
                          ".+/tfm_config/.+" # tfm_config folder contains files that are added to the build manually (e.g. custom partitions)
                          CACHE PATH      "List of sources excluded from build of secure BSP target")

################################################################################

# Configurations shared by both secure and non-secure images
include(${IFX_PLATFORM_SOURCE_DIR}/shared/config.cmake)

set(IFX_GENERATED_DIR ${CMAKE_BINARY_DIR}/generated CACHE PATH "Path to the root directory of files generated during the build of SPE")

################################## Isolation ###################################

set(TFM_ISOLATION_LEVEL                     3           CACHE STRING    "Isolation level")

# Use single Protection Context for isolation
set(IFX_ISOLATION_PC_SWITCHING              OFF) # Disable Protection Context switching

################################### Profile ####################################

set(TFM_FIH_PROFILE                         HIGH        CACHE STRING    "Fault injection hardening profile [OFF, LOW, MEDIUM, HIGH]")

##################################### BL2 ######################################
set(BL2                                     OFF         CACHE BOOL      "Whether to build BL2")
set(BL2_HEADER_SIZE                         0x400       CACHE STRING    "BL2 Header size")
set(BL2_TRAILER_SIZE                        0x0         CACHE STRING    "BL2 Trailer size")

#################################### IFX #######################################

# Unsure PC3 is used even if it may have been set by bootloader
set(IFX_SET_PC3_MANUALLY                    ON)

set(IFX_MPC_DRIVER_HW_MPC                   ON) # Use HW MPC driver
set(IFX_PPC_DRIVER_V2                       ON) # Use PPC driver v2
set(IFX_PPC_DOMAIN_CONFIGURATOR             ON) # Edge Configurator provides PPC domain configuration
set(IFX_SE_RT_SERVICES_UTILS_ENABLED        OFF)

set(IFX_MBEDTLS_ACCELERATION_LIB_PATH       "DOWNLOAD"  CACHE PATH      "Path to Infineon MBEDTLS Acceleration library (or DOWNLOAD to fetch automatically)")
set(IFX_MBEDTLS_ACCELERATION_LIB_GIT_REMOTE "https://github.com/Infineon/cy-mbedtls-acceleration" CACHE STRING "The URL (or path) to retrieve MBEDTLS Acceleration from.")
set(IFX_MBEDTLS_ACCELERATION_LIB_VERSION    "release-v3.1.0" CACHE STRING "The version of Infineon MBEDTLS Acceleration library to use")
set(IFX_MBEDTLS_ACCELERATOR_VALID_TYPES     "CRYPTOLITE")
set(IFX_MBEDTLS_ACCELERATOR_TYPE            "CRYPTOLITE" CACHE STRING   "Specifies type of accelerator for a project")
set(IFX_MBEDTLS_ACCELERATION_ENABLED        ON           CACHE BOOL     "Enable crypto accelerator")
set(IFX_MBEDTLS_ACCELERATION_PATCH_DIR      "${IFX_PLATFORM_SOURCE_DIR}/libs/ifx_mbedtls_acceleration/patch" CACHE STRING "Path to mbedtls patches")
set(IFX_CRYPTOLITE_PSA_PATH                 "mbedtls_PSA/mbedtls_psa_MXCryptolite" CACHE STRING "Path to Cryptolite PSA implementation")
set(IFX_CRYPTOLITE_INCLUDE_SHA              ON)

if(IFX_MBEDTLS_ACCELERATION_ENABLED)
    set(IFX_CRYPTOSUITE_ENABLED             ON           CACHE BOOL      "Enable cryptosuite accelerator")
endif()
set(IFX_CRYPTOSUITE_LIB_PATH                "DOWNLOAD"   CACHE PATH      "Path to Infineon crypto-suite-psc3 Services Utils library (or DOWNLOAD to fetch automatically)")
set(IFX_CRYPTOSUITE_GIT_REMOTE              "https://github.com/Infineon/crypto-suite-psc3.git" CACHE STRING "Infineon crypto-suite-psc3x8 Services Utils library repo URL")
set(IFX_CRYPTOSUITE_VERSION                 "release-v6.1.2" CACHE STRING   "The version of Infineon crypto-suite-psc3x8 Services Utils library to use")

set(IFX_BSP_DESIGN_FILE_VALID_NAMES         "flash;test;coverage")

################################### Drivers ####################################

set(IFX_PLATFORM_DRIVERS_LIST               "FLASH")
set(IFX_NV_COUNTERS_VALID_TYPES             "FLASH")
set(IFX_ITS_VALID_TYPES                     "FLASH")
set(IFX_PS_VALID_TYPES                      "FLASH")

set(IFX_MTB_SRF                             ON  CACHE BOOL     "Enable MTB SRF functionality")

################################### Platform ###################################
set(CONFIG_TFM_USE_TRUSTZONE                ON  CACHE BOOL     "Use TrustZone to transition between NSPE and SPE on the same CPU")
set(TFM_MULTI_CORE_TOPOLOGY                 OFF CACHE BOOL     "NSPE runs on a separate CPU to SPE")

set(IFX_CRYPTO_KEYS_FLASH                   ON) # Crypto key storage in FLASH, platform provides configuration (location and layout)

set(PSA_INITIAL_ATTEST_MAX_TOKEN_SIZE       0x600 CACHE STRING    "The maximum possible size of a token in bytes")

set(CRYPTO_TFM_BUILTIN_KEYS_DRIVER          ON    CACHE BOOL      "Whether to allow crypto service to store builtin keys. Without this, ALL builtin keys must be stored in a platform-specific location")

################################### Partition ##################################
set(TFM_PARTITION_CRYPTO                    ON    CACHE BOOL "Enable Crypto partition")
set(TFM_PARTITION_INTERNAL_TRUSTED_STORAGE  ON    CACHE BOOL "Enable Internal Trusted Storage partition")
set(TFM_PARTITION_PLATFORM                  ON    CACHE BOOL "Enable the TF-M Platform partition")
set(TFM_PARTITION_PROTECTED_STORAGE         ON    CACHE BOOL "Enable Protected Storage partition")
set(TFM_PARTITION_INITIAL_ATTESTATION       ON    CACHE BOOL "Enable Initial Attestation partition")
set(SYMMETRIC_INITIAL_ATTESTATION           ON    CACHE BOOL "Use symmetric crypto for inital attestation")
set(TFM_PARTITION_FIRMWARE_UPDATE           OFF   CACHE BOOL "Enable firmware update partition")

################################## Advanced options #############################
set(TFM_TF_PSA_CRYPTO_PLATFORM_EXTRA_CONFIG_PATH "${IFX_PLATFORM_SOURCE_DIR}/spe/services/crypto/mbedtls_target_config.h"     CACHE PATH      "Config to append to standard TF-PSA-Crypto config, used by platforms to configure feature support")

set(TFM_PROFILE                             profile_medium CACHE STRING    "Profile to use")

set(IFX_CRYPTOLITE_USER_CONFIG_FILE         "${IFX_PLATFORM_SOURCE_DIR}/spe/services/crypto/ifx_pdl_cryptolite_config.h" CACHE PATH "Config to use for Cryptolite accelerator")
if(IFX_CRYPTOSUITE_ENABLED)
    set(IFX_PSA_CRYPTOLITE_USER_CONFIG_FILE     "${IFX_PLATFORM_SOURCE_DIR}/spe/services/crypto/ifx_pdl_psa_cryptolite_config.h" CACHE PATH "PSA config to use for Cryptolite accelerator")
    set(IFX_PSA_CRYPTOSUITE_USER_CONFIG_FILE    "${IFX_PLATFORM_SOURCE_DIR}/spe/services/crypto/ifx_pdl_cryptosuite_config.h" CACHE PATH "Config to use for Cryptosuite accelerator")
endif()


###################################################################################

include(${IFX_COMMON_SOURCE_DIR}/config.cmake)

include(${IFX_COMMON_SOURCE_DIR}/cmake/generate_sources.cmake)
