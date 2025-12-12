#-------------------------------------------------------------------------------
# Copyright (c) 2023-2025 Cypress Semiconductor Corporation (an Infineon company)
# or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

#################################### Board #####################################

# BSP config.cmake uses IFX_BSP_DESIGN_FILE_NAME, thus it must be
# defined before BSP config.cmake is included
set(IFX_BSP_DESIGN_FILE_NAME         "default"       CACHE STRING "Name of BSP design file to use")
set(IFX_BSP_DESIGN_FILE_VALID_NAMES  "sram_load;xip;rram;test;default")

# Include board specific configuration at the beginning to allow override configuration provided by platform
set(IFX_CONFIG_BSP_PATH              "${IFX_PLATFORM_SOURCE_DIR}/board/KIT_PSOCE84_EVK" CACHE FILEPATH "Path to individual BSP configurations")
include(${IFX_CONFIG_BSP_PATH}/config.cmake)

################################## Isolation ###################################

set(TFM_ISOLATION_LEVEL              2           CACHE STRING    "Isolation level")

# Use single Protection Context for isolation
set(IFX_ISOLATION_PC_SWITCHING       OFF) # Disable Protection Context switching

################################### Profile ####################################

set(TFM_FIH_PROFILE                  OFF         CACHE STRING    "Fault injection hardening profile [OFF, LOW, MEDIUM, HIGH]")

###################################################################################

set(IFX_CRYPTO_KEYS_RRAM             ON) # Crypto key storage in RRAM, platform provides configuration (location and layout)

set(IFX_SE_IPC_SERVICE_TYPE          BASE) # Infineon SE IPC Service with limited set of functions

set(TFM_MBEDCRYPTO_PLATFORM_EXTRA_CONFIG_PATH "${CMAKE_CURRENT_LIST_DIR}/spe/services/crypto/mbedtls_target_config_pse84.h"    CACHE PATH      "Config to append to standard Mbed Crypto config, used by platforms to configure feature support")

################################### Drivers ####################################

set(IFX_NV_COUNTERS_VALID_TYPES      "RRAM")
