/*
 * Copyright (c) 2023-2024, The TrustedFirmware-M Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

/** @file cc3xx_crypto_primitives_private.h
 *
 * This file contains the definition of types associated
 * to the CC3XX driver, based on the refactored cc3xx-rom driver
 * only. Once the migration of the PSA driver API is completed,
 * this will be become the only private type definition header.
 * Private in this context means that the header contains the
 * implementation details of the types required by the driver
 */

#ifndef __CC3XX_CRYPTO_PRIMITIVES_PRIVATE_H__
#define __CC3XX_CRYPTO_PRIMITIVES_PRIVATE_H__

#include "cc3xx_psa_api_config.h"
#include "psa/crypto.h"

/* Include for the refactored low level driver components */
#include "cc3xx_hash.h"
#include "cc3xx_drbg.h"
#include "cc3xx_hmac.h"
#include "cc3xx_chacha.h"
#include "cc3xx_aes.h"

#ifdef __cplusplus
extern "C" {
#endif

/** \defgroup internal_types These types are required only by the internal cipher module
 *
 *  Type definitions required by the internal cipher module
 *
 *  @{
 */

typedef cc3xx_err_t (*block_cipher_update_t)(const uint8_t* in, size_t in_len);
typedef void (*block_cipher_set_output_buffer_t)(uint8_t *out, size_t out_len);

/**
 * @brief When an underlying block cipher is used as a stream cipher (AES-CTR or CHACHA-20)
 *        it possible to use multipart operations and avoid lagging the output by up to
 *        1 block size, by keeping track of the keystream
 *
 * @note  This adds more complexity to the driver layer and increases size requirements of
 *        the multipart contexts, so it is recommended to disable it when not needed
 */
struct cc3xx_internal_cipher_stream_t {
    uint8_t buf[64]; /*!< This supports only Chacha20, i.e. CC3XX_CHACHA_BLOCK_SIZE */
    uint8_t idx; /*!< valid range: [0, sizeof(buf)-1], sizeof(buf) means empty */
    block_cipher_update_t update; /*!< Function pointer to trigger an update using the underlying block cipher */
    block_cipher_set_output_buffer_t set_output_buffer; /*!<  Function pointer to set the output buffer for the underlying block cipher */
};
/** @} */ // end of internal_types

/*!
 * @struct cc3xx_hash_operation_s
 *
 * @brief A structure holding state information for an Hash operation
 */
struct cc3xx_hash_operation_s {
    struct cc3xx_hash_state_t ctx; /*!< Low-level hash context */
};

/*!
 * @struct cc3xx_random_context_s
 *
 * @brief A structure holding the state information associated to a DRBG
 */
struct cc3xx_random_context_s {
    struct cc3xx_drbg_state_t state; /* State of the generic DRBG interface for CC3XX */
};

/*!
 * \struct cc3xx_mac_operation_s
 *
 * \brief A structure holding state information for a MAC operation
 */
struct cc3xx_mac_operation_s {
    union {
        struct cc3xx_hmac_state_t hmac; /*!< Underlying state of HMAC */
        struct cc3xx_aes_state_t cmac;  /*!< Underlying state of AES configured in CMAC mode */
    };
    psa_algorithm_t alg; /*!< MAC algorithm used in this context */
};

#if defined(CC3XX_CONFIG_CBC_PKCS7_DECRYPT_ARBITRARY_LENGTHS)
/**
 * @brief The size of the ring buffer used in the. Must be enough
 *        to hold up to two AES blocks while buffering when used
 *        in AES-CBC with PKCS#7 padding
 */
#define RING_BUF_SIZE (32)

/**
 * @brief A generic ring buffer structure to be used for PKCS#7 related buffering
 *
 */
typedef struct {
    uint8_t buffer[RING_BUF_SIZE]; /*!< Ring buffer */
    size_t write_offset;           /*!< Next write position */
    size_t read_offset;            /*!< Next read position (for blocks) */
    size_t count;                  /*!< Number of bytes in buffer */
} ring_buffer_t;
#endif /* CC3XX_CONFIG_CBC_PKCS7_DECRYPT_ARBITRARY_LENGTHS */

/*!
 * \struct cc3xx_cipher_operation_s
 *
 * \brief A structure holding state information for a Cipher operation
 */
struct cc3xx_cipher_operation_s {
    union {
        struct cc3xx_aes_state_t aes; /*!< Underlying state of AES related cipher modes */
        struct cc3xx_chacha_state_t chacha; /*!< Underlying state of CHACHA related cipher modes */
    };

#if defined(CC3XX_CONFIG_ENABLE_STREAM_CIPHER)
    struct cc3xx_internal_cipher_stream_t stream; /*!< Holds the keystream if alg is PSA_ALG_STREAM_CIPHER */
#endif /* CC3XX_CONFIG_ENABLE_STREAM_CIPHER */

#if defined(PSA_WANT_ALG_CBC_PKCS7)
    uint8_t pkcs7_last_block[AES_BLOCK_SIZE]; /*!< In multipart decryption, PKCS#7 needs to cache the last block */
    size_t pkcs7_last_block_size; /*!< Size of data currently held in ::cc3xx_cipher_operation_s.pkcs7_last_block */
#if defined(CC3XX_CONFIG_CBC_PKCS7_DECRYPT_ARBITRARY_LENGTHS)
    ring_buffer_t pkcs7_ring_buf; /*!< Ring buffer to support caching for arbitrary updates during PKCS#7 decryption */
#endif
#endif /* PSA_WANT_ALG_CBC_PKCS7 */

    psa_algorithm_t alg; /*!< Cipher algorithm used in this context */
    psa_key_type_t key_type; /*!< The key type identifies if it's Chacha or AES */
    size_t key_bits; /*!< Size in bits of the key used on this context */
    size_t last_output_num_bytes; /*!< Number of bytes produced at the time of the last API call */
    bool cipher_is_initialized; /*!< Track if the cipher state has been configured or not yet */
    size_t iv_length; /* Generic IV length passed from the PSA API layer */
};

/*! @typedef cc3xx_hash_operation_t
 *
 * @brief A concise way to refer to \ref cc3xx_hash_operation_s
 *
 */
typedef struct cc3xx_hash_operation_s cc3xx_hash_operation_t;

/*! @typedef cc3xx_cipher_operation_t
 *
 * @brief A concise way to refer to \ref cc3xx_cipher_operation_s
 *
 */
typedef struct cc3xx_cipher_operation_s cc3xx_cipher_operation_t;

/*! @typedef cc3xx_mac_operation_t
 *
 * @brief A concise way to refer to \ref cc3xx_mac_operation_s
 *
 */
typedef struct cc3xx_mac_operation_s cc3xx_mac_operation_t;

/*! @typedef cc3xx_aead_operation_t
 *
 * @brief A AEAD operation is completely described by the underlying
 *        cipher operation object, i.e. it acts as an alias
 *
 */
typedef struct cc3xx_cipher_operation_s cc3xx_aead_operation_t;

/*! @typedef cc3xx_random_context_t
 *
 * @brief A concise way to refer to \ref cc3xx_random_context_s
 *
 */
typedef struct cc3xx_random_context_s cc3xx_random_context_t;

#ifdef __cplusplus
}
#endif

#endif /* __CC3XX_CRYPTO_PRIMITIVES_PRIVATE_H__ */
