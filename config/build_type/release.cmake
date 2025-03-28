#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

set(MBEDCRYPTO_BUILD_TYPE               minsizerel CACHE STRING    "Build type of Mbed Crypto library")
set(BL1_2_BUILD_TYPE                    minsizerel CACHE STRING    "Build type of BL1_2")
set(TFM_BL2_LOG_LEVEL                   LOG_LEVEL_NONE CACHE STRING "Level of logging to use for BL2: LOG_LEVEL_[NONE, ERROR, WARNING, INFO, VERBOSE]")
set(TFM_SPM_LOG_LEVEL                   LOG_LEVEL_NONE CACHE STRING "Set release SPM log level as Silence level")
set(TFM_PARTITION_LOG_LEVEL             LOG_LEVEL_NONE CACHE STRING "Set release SP log level as Silence level")
set(TFM_BL1_LOG_LEVEL                   LOG_LEVEL_NONE CACHE STRING  "The level of BL1 logging to uart")
