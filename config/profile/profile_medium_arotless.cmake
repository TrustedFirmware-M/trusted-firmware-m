#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

set(TFM_PROFILE                profile_medium_arotless CACHE STRING    "Profile to use")
set(PROJECT_CONFIG_HEADER_FILE "${CMAKE_SOURCE_DIR}/config/profile/config_profile_medium_arotless.h" CACHE FILEPATH "User defined header file for TF-M config")

############################ SPM CONFIGURATION  ################################

set(CONFIG_TFM_SPM_BACKEND              "SFN"       CACHE STRING    "The SPM backend [IPC, SFN]")
set(TFM_ISOLATION_LEVEL                 1           CACHE STRING    "Isolation level")

############################ Partitions ########################################

set(TFM_PARTITION_INTERNAL_TRUSTED_STORAGE ON       CACHE BOOL      "Enable Internal Trusted Storage partition")
set(TFM_PARTITION_CRYPTO                ON          CACHE BOOL      "Enable Crypto partition")
set(TFM_PARTITION_PLATFORM              ON          CACHE BOOL      "Enable the TF-M Platform partition")
set(TFM_PARTITION_INITIAL_ATTESTATION   ON          CACHE BOOL      "Enable Initial Attestation partition")
set(TFM_PARTITION_FIRMWARE_UPDATE       ON          CACHE BOOL      "Enable firmware update partition")
set(TFM_PARTITION_PROTECTED_STORAGE     OFF         CACHE BOOL      "Enable Protected Storage partition")

################################## Dependencies ################################

set(TFM_TF_PSA_CRYPTO_CONFIG_PATH       "${CMAKE_SOURCE_DIR}/lib/ext/tf-psa-crypto/tfpsacrypto_config/crypto_config_profile_medium.h"
                                                    CACHE PATH "Config to use for TF-PSA-Crypto")
