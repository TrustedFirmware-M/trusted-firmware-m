#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

set(TF_PSA_CRYPTO_BUILD_TYPE            relwithdebinfo CACHE STRING "Build type of TF-PSA-Crypto library")
set(BL1_2_BUILD_TYPE                    relwithdebinfo CACHE STRING "Build type of BL1_2")
set(TFM_SPM_LOG_LEVEL                   LOG_LEVEL_VERBOSE CACHE STRING "Set debug SPM log level as Debug level")
set(TFM_PARTITION_LOG_LEVEL             LOG_LEVEL_VERBOSE CACHE STRING "Set debug SP log level as Debug level")

set(CONFIG_TFM_HALT_ON_CORE_PANIC       ON         CACHE BOOL      "On fatal errors in the secure firmware, halt instead of rebooting.")
