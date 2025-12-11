#-------------------------------------------------------------------------------
# Copyright (c) 2023-2025 Cypress Semiconductor Corporation (an Infineon company)
# or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

##################################### FWU ######################################

# FWU is not supported for Infineon platforms
tfm_invalid_config(TFM_PARTITION_FIRMWARE_UPDATE)

#################################### Crypto ####################################

# IFX_CRYPTO_SE_RT must be enabled to support crypto keys in SE RT
tfm_invalid_config(NOT IFX_CRYPTO_SE_RT AND IFX_CRYPTO_KEYS_SE_RT)

tfm_invalid_config(IFX_MBEDTLS_ACCELERATION_ENABLED AND IFX_MBEDTLS_ACCELERATOR_VALID_TYPES
               AND NOT IFX_MBEDTLS_ACCELERATOR_TYPE IN_LIST IFX_MBEDTLS_ACCELERATOR_VALID_TYPES)

################################### Drivers ####################################

# Only FULL SE_RT service provides NV counters
tfm_invalid_config("SE_RT" IN_LIST IFX_NV_COUNTERS_VALID_TYPES
                   AND NOT IFX_SE_IPC_SERVICE_TYPE STREQUAL "FULL")

################################### Platform ###################################

# Default UART stdout driver is not supported
tfm_invalid_config(PLATFORM_DEFAULT_UART_STDOUT)

# IFX_UART_ENABLED must be enabled to support SPM log
tfm_invalid_config(NOT IFX_UART_ENABLED AND TFM_SPM_LOG_RAW_ENABLED)

tfm_invalid_config(IFX_BSP_DESIGN_FILE_VALID_NAMES
                   AND NOT IFX_BSP_DESIGN_FILE_NAME IN_LIST IFX_BSP_DESIGN_FILE_VALID_NAMES)

# MTB SRF is implemented through IFX Extensions Partition
tfm_invalid_config(IFX_MTB_SRF AND NOT IFX_EXT_SP)

# Masked and unmasked non-secure IRQ tests are mutually exclusive
tfm_invalid_config(TEST_NS_IFX_IRQ_TEST_MASKED AND TEST_NS_IFX_IRQ_TEST_UNMASKED)

# Mailbox partition is not supported for Infineon platforms
tfm_invalid_config(TFM_PARTITION_NS_AGENT_MAILBOX)

# Mailbox tests can not be executed when mailbox partition is disabled
tfm_invalid_config(TEST_NS_IFX_MAILBOX AND NOT TFM_PARTITION_NS_AGENT_MAILBOX)

# SRF tests require MTB SRF to be enabled
tfm_invalid_config(TEST_NS_IFX_MTB_SRF AND NOT IFX_MTB_SRF)

# IFX MTB mailbox is alternative to NS Agent Mailbox, thus both are not
# supported at the same time
tfm_invalid_config(IFX_MTB_MAILBOX AND TFM_PARTITION_NS_AGENT_MAILBOX)

# IFX MTB mailbox is alternative to multi-core topology, thus both are not
# supported at the same time
tfm_invalid_config(IFX_MTB_MAILBOX AND TFM_MULTI_CORE_TOPOLOGY)

# IFX MTB mailbox uses SRF Relay to recieve requests
tfm_invalid_config(IFX_MTB_MAILBOX AND NOT IFX_MTB_SRF)

# Coverage is only supported for GCC
tfm_invalid_config(TEST_NS_IFX_CODE_COVERAGE AND (NOT (CMAKE_C_COMPILER_ID STREQUAL "GNU")))

################################### Services ###################################

# Validate IFX_SE_IPC_SERVICE_TYPE
set(IFX_SE_IPC_SERVICE_VALID_TYPES "BASE;FULL")
tfm_invalid_config(IFX_SE_IPC_SERVICE_TYPE
                   AND NOT IFX_SE_IPC_SERVICE_TYPE IN_LIST IFX_SE_IPC_SERVICE_VALID_TYPES)

# SE IPC Service supports FULL type only
tfm_invalid_config(IFX_PARTITION_SE_IPC_SERVICE AND NOT IFX_SE_IPC_SERVICE_TYPE STREQUAL "FULL")
