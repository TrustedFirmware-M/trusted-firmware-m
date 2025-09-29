/*
 *  Context structure declaration of the Mbed TLS software-based PSA drivers
 *  called through the PSA Crypto driver dispatch layer.
 *  This file contains the context structures of key derivation algorithms
 *  which need to rely on other algorithms.
 *
 * \note This file may not be included directly. Applications must
 * include psa/crypto.h.
 *
 * \note This header and its content are not part of the Mbed TLS API and
 * applications must not depend on it. Its main purpose is to define the
 * multi-part state objects of the Mbed TLS software-based PSA drivers. The
 * definitions of these objects are then used by crypto_struct.h to define the
 * implementation-defined types of PSA multi-part state objects.
 */
/*
 *  Copyright The Mbed TLS Contributors
 *  SPDX-License-Identifier: Apache-2.0 OR GPL-2.0-or-later
 */

#ifndef PSA_CRYPTO_BUILTIN_KEY_DERIVATION_H
#define PSA_CRYPTO_BUILTIN_KEY_DERIVATION_H
#include "mbedtls/private_access.h"

#include <psa/crypto_driver_common.h>

#if defined(MBEDTLS_PSA_BUILTIN_ALG_HKDF) || \
    defined(MBEDTLS_PSA_BUILTIN_ALG_HKDF_EXTRACT) || \
    defined(MBEDTLS_PSA_BUILTIN_ALG_HKDF_EXPAND)
typedef struct {
    uint8_t *MBEDTLS_PRIVATE(info);
    size_t MBEDTLS_PRIVATE(info_length);
#if PSA_HASH_MAX_SIZE > 0xff
#error "PSA_HASH_MAX_SIZE does not fit in uint8_t"
#endif
    uint8_t MBEDTLS_PRIVATE(offset_in_block);
    uint8_t MBEDTLS_PRIVATE(block_number);
    unsigned int MBEDTLS_PRIVATE(state) : 2;
    unsigned int MBEDTLS_PRIVATE(info_set) : 1;
    uint8_t MBEDTLS_PRIVATE(output_block)[PSA_HASH_MAX_SIZE];
    uint8_t MBEDTLS_PRIVATE(prk)[PSA_HASH_MAX_SIZE];
    struct psa_mac_operation_s MBEDTLS_PRIVATE(hmac);
} psa_hkdf_key_derivation_t;
#endif /* MBEDTLS_PSA_BUILTIN_ALG_HKDF ||
          MBEDTLS_PSA_BUILTIN_ALG_HKDF_EXTRACT ||
          MBEDTLS_PSA_BUILTIN_ALG_HKDF_EXPAND */
#if defined(MBEDTLS_PSA_BUILTIN_ALG_TLS12_ECJPAKE_TO_PMS)
typedef struct {
    uint8_t MBEDTLS_PRIVATE(data)[PSA_TLS12_ECJPAKE_TO_PMS_DATA_SIZE];
} psa_tls12_ecjpake_to_pms_t;
#endif /* MBEDTLS_PSA_BUILTIN_ALG_TLS12_ECJPAKE_TO_PMS */

#if defined(MBEDTLS_PSA_BUILTIN_ALG_TLS12_PRF) || \
    defined(MBEDTLS_PSA_BUILTIN_ALG_TLS12_PSK_TO_MS)
typedef enum {
    PSA_TLS12_PRF_STATE_INIT,             /* no input provided */
    PSA_TLS12_PRF_STATE_SEED_SET,         /* seed has been set */
    PSA_TLS12_PRF_STATE_OTHER_KEY_SET,    /* other key has been set - optional */
    PSA_TLS12_PRF_STATE_KEY_SET,          /* key has been set */
    PSA_TLS12_PRF_STATE_LABEL_SET,        /* label has been set */
    PSA_TLS12_PRF_STATE_OUTPUT            /* output has been started */
} psa_tls12_prf_key_derivation_state_t;

typedef struct psa_tls12_prf_key_derivation_s {
#if PSA_HASH_MAX_SIZE > 0xff
#error "PSA_HASH_MAX_SIZE does not fit in uint8_t"
#endif

    /* Indicates how many bytes in the current HMAC block have
     * not yet been read by the user. */
    uint8_t MBEDTLS_PRIVATE(left_in_block);

    /* The 1-based number of the block. */
    uint8_t MBEDTLS_PRIVATE(block_number);

    psa_tls12_prf_key_derivation_state_t MBEDTLS_PRIVATE(state);

    uint8_t *MBEDTLS_PRIVATE(secret);
    size_t MBEDTLS_PRIVATE(secret_length);
    uint8_t *MBEDTLS_PRIVATE(seed);
    size_t MBEDTLS_PRIVATE(seed_length);
    uint8_t *MBEDTLS_PRIVATE(label);
    size_t MBEDTLS_PRIVATE(label_length);
#if defined(MBEDTLS_PSA_BUILTIN_ALG_TLS12_PSK_TO_MS)
    uint8_t *MBEDTLS_PRIVATE(other_secret);
    size_t MBEDTLS_PRIVATE(other_secret_length);
#endif /* MBEDTLS_PSA_BUILTIN_ALG_TLS12_PSK_TO_MS */

    uint8_t MBEDTLS_PRIVATE(Ai)[PSA_HASH_MAX_SIZE];

    /* `HMAC_hash( prk, A( i ) + seed )` in the notation of RFC 5246, Sect. 5. */
    uint8_t MBEDTLS_PRIVATE(output_block)[PSA_HASH_MAX_SIZE];
} psa_tls12_prf_key_derivation_t;
#endif /* MBEDTLS_PSA_BUILTIN_ALG_TLS12_PRF) ||
        * MBEDTLS_PSA_BUILTIN_ALG_TLS12_PSK_TO_MS */
#if defined(PSA_HAVE_SOFT_PBKDF2)
typedef enum {
    PSA_PBKDF2_STATE_INIT,             /* no input provided */
    PSA_PBKDF2_STATE_INPUT_COST_SET,   /* input cost has been set */
    PSA_PBKDF2_STATE_SALT_SET,         /* salt has been set */
    PSA_PBKDF2_STATE_PASSWORD_SET,     /* password has been set */
    PSA_PBKDF2_STATE_OUTPUT            /* output has been started */
} psa_pbkdf2_key_derivation_state_t;

typedef struct {
    psa_pbkdf2_key_derivation_state_t MBEDTLS_PRIVATE(state);
    uint64_t MBEDTLS_PRIVATE(input_cost);
    uint8_t *MBEDTLS_PRIVATE(salt);
    size_t MBEDTLS_PRIVATE(salt_length);
    uint8_t MBEDTLS_PRIVATE(password)[PSA_HMAC_MAX_HASH_BLOCK_SIZE];
    size_t MBEDTLS_PRIVATE(password_length);
    uint8_t MBEDTLS_PRIVATE(output_block)[PSA_HASH_MAX_SIZE];
    uint8_t MBEDTLS_PRIVATE(bytes_used);
    uint32_t MBEDTLS_PRIVATE(block_number);
} psa_pbkdf2_key_derivation_t;
#endif /* PSA_HAVE_SOFT_PBKDF2 */

#if defined(MBEDTLS_PSA_BUILTIN_ALG_SP800_108_COUNTER_CMAC)
#define SP800_108_INTERATION_COUNTER_SIZE   4

#ifndef SP800_108_LABEL_MAX_SIZE
#define SP800_108_LABEL_MAX_SIZE            48
#endif

#define SP800_108_NULL_BYTE_SIZE            1

#ifndef SP800_108_CONTEXT_MAX_SIZE
#define SP800_108_CONTEXT_MAX_SIZE          48
#endif

#define SP800_108_ENCODED_LENGTH_SIZE       4
#define SP800_108_K0_SIZE                   PSA_AEAD_TAG_MAX_SIZE

#define SP800_108_TOTAL_INPUT_MAX_SIZE \
    (SP800_108_INTERATION_COUNTER_SIZE + \
     SP800_108_LABEL_MAX_SIZE + \
     SP800_108_NULL_BYTE_SIZE + \
     SP800_108_CONTEXT_MAX_SIZE + \
     SP800_108_ENCODED_LENGTH_SIZE + \
     SP800_108_K0_SIZE)

#define SP800_108_INPUT_INTERATION_COUNTER_OFFSET(ctx) (0)

#define SP800_108_INPUT_LABEL_OFFSET(ctx) \
    (SP800_108_INTERATION_COUNTER_SIZE)

#define SP800_108_INPUT_CONTEXT_OFFSET(ctx) \
    (SP800_108_INPUT_LABEL_OFFSET(x) + \
     ctx->label_length + \
     SP800_108_NULL_BYTE_SIZE)

#define SP800_108_INPUT_ENCODED_LENGTH_OFFSET(ctx) \
    (SP800_108_INPUT_CONTEXT_OFFSET(ctx) + \
     ctx->context_length)

#define SP800_108_INPUT_K0_OFFSET(ctx) \
    (SP800_108_INPUT_ENCODED_LENGTH_OFFSET(ctx) + \
     SP800_108_ENCODED_LENGTH_SIZE)

#define SP800_108_INPUT_LENGTH(ctx) \
    (SP800_108_INPUT_K0_OFFSET(ctx) + \
     SP800_108_K0_SIZE)

typedef struct
{
    uint8_t inputs[SP800_108_TOTAL_INPUT_MAX_SIZE];

    /* The key must be a block-cipher that is compatible with the CMAC algorithm */
    psa_key_id_t MBEDTLS_PRIVATE(key);
    bool MBEDTLS_PRIVATE(key_provided);

    /* Label, unless omitted, must be passed after the key */
    bool MBEDTLS_PRIVATE(label_provided);
    size_t MBEDTLS_PRIVATE(label_length);

    /* Context, unless omitted, must be passed after the label */
    bool MBEDTLS_PRIVATE(context_provided);
    size_t MBEDTLS_PRIVATE(context_length);

    /* Derivation state */
    size_t MBEDTLS_PRIVATE(L_bits); /* total output length in bits */
    size_t MBEDTLS_PRIVATE(counter); /* 1-based */
} psa_sp800_108_cmac_key_derivation_t;
#endif /* MBEDTLS_PSA_BUILTIN_ALG_SP800_108_COUNTER_CMAC */

#endif /* PSA_CRYPTO_BUILTIN_KEY_DERIVATION_H */
