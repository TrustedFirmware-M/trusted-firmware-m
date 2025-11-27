#-------------------------------------------------------------------------------
# Copyright (c) 2023-2025 Cypress Semiconductor Corporation (an Infineon company)
# or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

include(${IFX_PLATFORM_SOURCE_DIR}/check_config.cmake OPTIONAL)
include(${IFX_COMMON_SOURCE_DIR}/check_config.cmake)

################################## Isolation ###################################

# Isolation Level 1 is not supported
tfm_invalid_config(TFM_ISOLATION_LEVEL EQUAL 1)

########################## Platform ############################################

# Don't use OTP implementation provided by TF-M and IFX at the same time
tfm_invalid_config(PLATFORM_DEFAULT_OTP AND IFX_PLATFORM_DEFAULT_OTP)

# PSE84 doesn't support code sharing between MCUboot and secure firmware
tfm_invalid_config(TFM_CODE_SHARING)

# PSE84 doesn't support SFN backend
tfm_invalid_config(CONFIG_TFM_SPM_BACKEND_SFN)

# PSE84 supports build of SPE image for CM33 only
tfm_invalid_config(S_BUILD AND NOT (IFX_CORE STREQUAL ${IFX_CM33}))

# NSPE image for CM33 is building while it has been disabled
tfm_invalid_config((NOT IFX_CM33_NS_PRESENT) AND NS_BUILD AND (IFX_CORE STREQUAL ${IFX_CM33}))

# NSPE image for CM55 is building while it has been disabled
tfm_invalid_config((NOT IFX_CM55_NS_PRESENT) AND NS_BUILD AND (IFX_CORE STREQUAL ${IFX_CM55}))

# At least one NSPE must be present
tfm_invalid_config((NOT IFX_CM33_NS_PRESENT) AND (NOT IFX_CM55_NS_PRESENT))

# CM55 image requires either NS Agent Mailbox partition or IFX MTB Mailbox
tfm_invalid_config(S_BUILD AND IFX_CM55_NS_PRESENT
                   AND ((NOT TFM_PARTITION_NS_AGENT_MAILBOX) AND (NOT IFX_MTB_MAILBOX)))

# IFX MTB Mailbox uses CM33 NSPE to forward CM55 NSPE requests to TFM
tfm_invalid_config(IFX_MTB_MAILBOX AND (NOT IFX_CM33_NS_PRESENT))

# Masked and unmasked non-secure IRQ tests must be tested without CM55 to avoid mailbox interrupts
tfm_invalid_config((TEST_NS_IFX_IRQ_TEST_MASKED OR TEST_NS_IFX_IRQ_TEST_UNMASKED)
                   AND IFX_CM55_NS_PRESENT)

# FLASH is not present on the PSE84 device
tfm_invalid_config(IFX_FLASH_DRIVER_ENABLED)
