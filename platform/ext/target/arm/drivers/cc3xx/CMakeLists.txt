#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

set(CC3XX_TARGET_NAME ${CC3XX_TARGET_PREFIX}cc3xx)

add_subdirectory(low_level_driver)
add_subdirectory(psa_driver_api)

if (TEST_CC3XX)
    add_subdirectory(tests)
endif()
