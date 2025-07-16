#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

# IAR is currently not supported for RSE due to a lack of scatter files
tfm_invalid_config(${CMAKE_C_COMPILER_ID} STREQUAL IAR)

# CPU (Cortex-M55) is only supported in Armclang version 6.14 or newer
tfm_invalid_config(${CMAKE_C_COMPILER_ID} STREQUAL ARMClang AND ${CMAKE_C_COMPILER_VERSION} VERSION_LESS "6.14")

# Only GCC is supported for using ROM library from SRAM
tfm_invalid_config(RSE_SUPPORT_ROM_LIB_RELOCATION AND NOT ${CMAKE_C_COMPILER_ID} STREQUAL "GNU")
tfm_invalid_config(RSE_USE_ROM_LIB_FROM_SRAM AND NOT RSE_SUPPORT_ROM_LIB_RELOCATION)

# RSE requires BL1 and BL2
tfm_invalid_config(NOT BL1)
tfm_invalid_config(NOT BL2)

# RSE requires crypto accelerator
tfm_invalid_config(NOT CRYPTO_HW_ACCELERATOR)

# RSE uses MCUBOOT_BUILTIN_KEY to enable having full keys in OTP.
tfm_invalid_config(NOT MCUBOOT_HW_KEY AND NOT MCUBOOT_BUILTIN_KEY)
tfm_invalid_config(MCUBOOT_BUILTIN_KEY AND TFM_BL1_2_EMBED_ROTPK_IN_IMAGE)
tfm_invalid_config(NOT MCUBOOT_BUILTIN_KEY AND NOT TFM_BL1_2_EMBED_ROTPK_IN_IMAGE)

tfm_invalid_config(MEASURED_BOOT_HASH_ALG STREQUAL SHA384 AND NOT MCUBOOT_SIGNATURE_TYPE STREQUAL EC-P384)

# Provisioning features which require the provisioning comms to receive messages
tfm_invalid_config((RSE_DM_CHAINED_PROVISIONING OR TFM_PARTITION_RUNTIME_PROVISIONING
                    OR RSE_NON_ENDORSED_DM_PROVISIONING OR RSE_ENDORSEMENT_CERTIFICATE_PROVISIONING)
                    AND NOT RSE_ENABLE_DCSU_PROVISIONING_COMMS)

# Provisioning features which require asymmetric signature verification
tfm_invalid_config((RSE_NON_ENDORSED_DM_PROVISIONING OR RSE_ENDORSEMENT_CERTIFICATE_PROVISIONING
                    OR RSE_DM_CHAINED_PROVISIONING)
                    AND RSE_SYMMETRIC_PROVISIONING)
########################## Attestation #########################################

get_property(TFM_ATTESTATION_SCHEME_LIST CACHE TFM_ATTESTATION_SCHEME PROPERTY STRINGS)
tfm_invalid_config(NOT TFM_ATTESTATION_SCHEME IN_LIST TFM_ATTESTATION_SCHEME_LIST)

########################## Tests ###############################################

# The SCMI comms tests use the same timer interrupt as the IRQ tests
tfm_invalid_config(TEST_S_SCMI_COMMS AND (TEST_NS_SLIH_IRQ OR TEST_NS_FLIH_IRQ))

# Test TP mode must be either TCI or PCI
tfm_invalid_config(DEFINED RSE_TESTS_TP_MODE AND NOT (RSE_TESTS_TP_MODE STREQUAL "TCI"
                                                    OR RSE_TESTS_TP_MODE STREQUAL "PCI"))
