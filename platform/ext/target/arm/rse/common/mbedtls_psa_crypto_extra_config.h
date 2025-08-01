/*
 * SPDX-License-Identifier: BSD-3-Clause
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 */

#ifndef __MBEDTLS_PSA_CRYPTO_EXTRA_CONFIG_H__
#define __MBEDTLS_PSA_CRYPTO_EXTRA_CONFIG_H__

/* Disable all RSA-related cryptographic functionalities as RSE does not support it. */
#ifdef PSA_WANT_ALG_RSA_OAEP
#undef PSA_WANT_ALG_RSA_OAEP
#endif

#ifdef PSA_WANT_ALG_RSA_PKCS1V15_CRYPT
#undef PSA_WANT_ALG_RSA_PKCS1V15_CRYPT
#endif

#ifdef PSA_WANT_ALG_RSA_PKCS1V15_SIGN
#undef PSA_WANT_ALG_RSA_PKCS1V15_SIGN
#endif

#ifdef PSA_WANT_ALG_RSA_PSS
#undef PSA_WANT_ALG_RSA_PSS
#endif

#ifdef PSA_WANT_KEY_TYPE_RSA_PUBLIC_KEY
#undef PSA_WANT_KEY_TYPE_RSA_PUBLIC_KEY
#endif

#ifdef PSA_WANT_KEY_TYPE_RSA_KEY_PAIR_BASIC
#undef PSA_WANT_KEY_TYPE_RSA_KEY_PAIR_BASIC
#endif

#ifdef PSA_WANT_KEY_TYPE_RSA_KEY_PAIR_IMPORT
#undef PSA_WANT_KEY_TYPE_RSA_KEY_PAIR_IMPORT
#endif

#ifdef PSA_WANT_KEY_TYPE_RSA_KEY_PAIR_EXPORT
#undef PSA_WANT_KEY_TYPE_RSA_KEY_PAIR_EXPORT
#endif

#ifdef PSA_WANT_KEY_TYPE_RSA_KEY_PAIR_GENERATE
#undef PSA_WANT_KEY_TYPE_RSA_KEY_PAIR_GENERATE
#endif

#endif /* __MBEDTLS_PSA_CRYPTO_EXTRA_CONFIG_H__ */
