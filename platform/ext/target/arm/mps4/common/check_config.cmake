#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

## test incompatible compiler
tfm_invalid_config(CMAKE_C_COMPILER MATCHES "armclang" AND CMAKE_C_COMPILER_VERSION VERSION_LESS 6.18.0)

tfm_invalid_config(TFM_BL1_2_SIGNER_AMOUNT GREATER 1)
tfm_invalid_config(NOT TFM_BL1_2_CM_SIGNING_ALG STREQUAL "LMS")
