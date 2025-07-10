/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

/* RSE does not have ITS */
#undef MBEDTLS_PSA_CRYPTO_STORAGE_C

/* Static keyslots are used so that the footprint of MbedTLS can be kept under control. */
#define MBEDTLS_PSA_STATIC_KEY_SLOTS
