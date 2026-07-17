#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------
if (TFM_S_REG_TEST)
    # Test configuration: host images are not needed and work only with isolation level 1
    set(MCUBOOT_IMAGE_NUMBER                1          CACHE STRING   "Whether to combine S and NS into either 1 image, or sign each separately" FORCE)
    set(TFM_ISOLATION_LEVEL                 1          CACHE STRING   "Isolation level" FORCE)
endif()

set(TFM_CRYPTO_TEST_ALG_RSASSA_PSS_VERIFICATION OFF        CACHE BOOL     "Test RSASSA-PSS signature verification algorithm")
set(TFM_CRYPTO_TEST_ALG_OFB                     OFF        CACHE BOOL     "Test OFB cryptography mode")
set(TFM_CRYPTO_TEST_ALG_SHA_224                 OFF        CACHE BOOL     "Test SHA-224 hash algorithm")