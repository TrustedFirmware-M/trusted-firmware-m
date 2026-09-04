#-------------------------------------------------------------------------------
# (c) 2026, Infineon Technologies AG, or an affiliate of Infineon
# Technologies AG. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

include(${IFX_COMMON_SOURCE_DIR}/check_config.cmake)

################################## Isolation ###################################

# Isolation Level 1 is not supported
tfm_invalid_config(TFM_ISOLATION_LEVEL EQUAL 1)

########################## Platform ############################################

# RRAM is not present on this device
tfm_invalid_config(IFX_RRAM_DRIVER_ENABLED)

# SMIF XIP is not present on this device
tfm_invalid_config(IFX_SMIF_MMIO_DRIVER_ENABLED)
tfm_invalid_config(IFX_SMIF_XIP_DRIVER_ENABLED)
