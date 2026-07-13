#-------------------------------------------------------------------------------
# SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

# The tf-m-tests repository enables these algorithm tests by default. Override
# those defaults here because the CC3XX driver used on Musca-B1 does not
# support the corresponding algorithms.
set(TFM_CRYPTO_TEST_ALG_CFB                     OFF        CACHE BOOL     "Test CFB cryptography mode")
set(TFM_CRYPTO_TEST_ALG_RSASSA_PSS_VERIFICATION OFF        CACHE BOOL     "Test RSASSA-PSS signature verification algorithm")
set(TFM_CRYPTO_TEST_ALG_SHA_224                 OFF        CACHE BOOL     "Test SHA-224 hash algorithm")
set(TFM_CRYPTO_TEST_ALG_OFB                     OFF        CACHE BOOL     "Test OFB cryptography mode")

set(PLATFORM_SLIH_IRQ_TEST_SUPPORT    ON)
