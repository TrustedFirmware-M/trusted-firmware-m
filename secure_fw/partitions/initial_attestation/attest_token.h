/*
 * attest_token.h
 *
 * Copyright (c) 2018-2019, Laurence Lundblade.
 *
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 * See BSD-3-Clause license in README.md
 */

#ifndef __ATTEST_TOKEN_H__
#define __ATTEST_TOKEN_H__

#include <stdint.h>
#include "qcbor/qcbor.h"
#ifdef SYMMETRIC_INITIAL_ATTESTATION
#include "t_cose/t_cose_mac_compute.h"
#else
#include "t_cose/t_cose_sign1_sign.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \file attest_token.h
 *
 * \brief Attestation Token Creation Interface
 *
 * The context and functions here are the way to create an attestation
 * token. The steps are roughly:
 *
 *   -# Create and initialize an attest_token_encode_ctx indicating the
 *   key, algorithm and such using attest_token_encode_start().
 *
 *   -# Use various add methods to fill in the payload with claims. The
 *   encoding context can also be borrowed for more rich payloads.
 *
 *   -# Call attest_token_encode_finish() to create the signature and finish
 *   formatting the COSE signed output.
 */

/**
 Error codes returned from attestation token creation.
 */
enum attest_token_err_t {
    /** Success */
    ATTEST_TOKEN_ERR_SUCCESS = 0,
    /** The buffer passed in to receive the output is too small. */
    ATTEST_TOKEN_ERR_TOO_SMALL,
    /** Something went wrong formatting the CBOR, most likely the
     payload has maps or arrays that are not closed. */
    ATTEST_TOKEN_ERR_CBOR_FORMATTING,
    /** A general, unspecific error when creating or decoding the
        token. */
    ATTEST_TOKEN_ERR_GENERAL,
    /** A hash function that is needed to make the token is not
        available. */
    ATTEST_TOKEN_ERR_HASH_UNAVAILABLE,
    /** CBOR Syntax not well-formed -- a CBOR syntax error. */
    ATTEST_TOKEN_ERR_CBOR_NOT_WELL_FORMED,
    /** Bad CBOR structure, for example not a map when was is
        required. */
    ATTEST_TOKEN_ERR_CBOR_STRUCTURE,
    /** Bad CBOR type, for example an not a text string, when a text
        string is required. */
    ATTEST_TOKEN_ERR_CBOR_TYPE,
    /** Integer too large, for example an \c int32_t is required, but
        value only fits in \c int64_t */
    ATTEST_TOKEN_ERR_INTEGER_VALUE,
    /** Something is wrong with the COSE message structure, missing
        headers or such. */
    ATTEST_TOKEN_ERR_COSE_FORMAT,
    /** COSE signature or authentication tag is invalid, data
        is corrupted. */
    ATTEST_TOKEN_ERR_COSE_VALIDATION,
    /** The signing algorithm is not supported. */
    ATTEST_TOKEN_ERR_UNSUPPORTED_SIG_ALG,
    /** Out of memory. */
    ATTEST_TOKEN_ERR_INSUFFICIENT_MEMORY,
    /** Tampering detected in cryptographic function. */
    ATTEST_TOKEN_ERR_TAMPERING_DETECTED,
    /** Signing key is not found or of wrong type. */
    ATTEST_TOKEN_ERR_SIGNING_KEY,
    /** Verification key is not found or of wrong type. */
    ATTEST_TOKEN_ERR_VERIFICATION_KEY,
    /** No token was given or validated */
    ATTEST_TOKEN_ERR_NO_VALID_TOKEN,
    /** Data item with label wasn't found. */
    ATTEST_TOKEN_ERR_NOT_FOUND,
    /** SW Components absence not correctly indicated. */
    ATTEST_TOKEN_ERR_SW_COMPONENTS_MISSING
};

/**
 * The context for creating an attestation token.  The caller of
 * attest_token_encode must create one of these and pass it to the functions
 * here. It is small enough that it can go on the stack. It is most of
 * the memory needed to create a token except the output buffer and
 * any memory requirements for the cryptographic operations.
 *
 * The structure is opaque for the caller.
 *
 * This is roughly 148 + 4 + 32 = 184 bytes
 */
struct attest_token_encode_ctx {
    /* Private data structure */
    QCBOREncodeContext           cbor_enc_ctx;
    int32_t                      key_select;
#ifdef SYMMETRIC_INITIAL_ATTESTATION
    struct t_cose_mac_calculate_ctx  mac_ctx;
#else
    struct t_cose_sign1_sign_ctx     signer_ctx;
#endif
};

/**
 * \brief Initialize a token creation context.
 *
 * \param[in] me          The token creation context to be initialized.
 * \param[in] key_select  Selects which attestation key to sign with.
 * \param[in] cose_alg_id The algorithm to sign with. The IDs are
 *                        defined in [COSE (RFC 8152)]
 *                        (https://tools.ietf.org/html/rfc8152) or
 *                        in the [IANA COSE Registry]
 *                        (https://www.iana.org/assignments/cose/cose.xhtml).
 * \param[out] out_buf    The output buffer to write the encoded token into.
 *
 * \return one of the \ref attest_token_err_t errors.
 *
 * The size of the buffer in \c out_buf->len
 * determines the size of the token that can be created. It must be
 * able to hold the final encoded and signed token. The data encoding
 * overhead is just that of CBOR. The signing overhead depends on the
 * signing key size. It is about 150 bytes for 256-bit ECDSA.
 *
 * If \c out_buf->ptr is \c NULL and \c out_buf->len is
 * large like \c UINT32_MAX no token will be created but the length of
 * the token that would be created will be in \c completed_token as
 * returned by attest_token_encode_finish(). None of the cryptographic
 * functions run during this, but the sizes of what they would output
 * is taken into account.
 */
enum attest_token_err_t
attest_token_encode_start(struct attest_token_encode_ctx *me,
                          int32_t key_select,
                          int32_t cose_alg_id,
                          const struct q_useful_buf *out_buf);

/**
 * \brief Get a copy of the CBOR encoding context
 *
 * \param[in] me     Token creation context.
 *
 * \return The CBOR encoding context
 *
 * Allows the caller to encode CBOR right into the output buffer using
 * any of the \c QCBOREncode_AddXXXX() methods. Anything added here
 * will be part of the payload that gets hashed. This can be used to
 * make complex CBOR structures. All open arrays and maps must be
 * close before calling any other \c attest_token_encode methods.  \c
 * QCBOREncode_Finish() should not be closed on this context.
 */
QCBOREncodeContext *
attest_token_encode_borrow_cbor_cntxt(struct attest_token_encode_ctx *me);

/**
 * \brief Add a 64-bit signed integer claim
 *
 * \param[in] me     Token creation context.
 * \param[in] label  Integer label for claim.
 * \param[in] value  The integer claim data.
 */
void attest_token_encode_add_integer(struct attest_token_encode_ctx *me,
                                     int32_t label,
                                     int64_t value);

/**
 * \brief Add a binary string claim
 *
 * \param[in] me     Token creation context.
 * \param[in] label  Integer label for claim.
 * \param[in] bstr   The binary claim data.
 */
void attest_token_encode_add_bstr(struct attest_token_encode_ctx *me,
                                  int32_t label,
                                  const struct q_useful_buf_c *bstr);

/**
 * \brief Add a text string claim
 *
 * \param[in] me     Token creation context.
 * \param[in] label  Integer label for claim.
 * \param[in] tstr   The text claim data.
 */
void attest_token_encode_add_tstr(struct attest_token_encode_ctx *me,
                                  int32_t label,
                                  const struct q_useful_buf_c *tstr);

/**
 * \brief Add some already-encoded CBOR to payload
 *
 * \param[in] me       Token creation context.
 * \param[in] label    Integer label for claim.
 * \param[in] encoded  The already-encoded CBOR.
 *
 * Encoded CBOR must be a full map or full array or a non-aggregate
 * type. It cannot be a partial map or array. It can be nested maps
 * and arrays, but they must all be complete.
 */
void attest_token_encode_add_cbor(struct attest_token_encode_ctx *me,
                                  int32_t label,
                                  const struct q_useful_buf_c *encoded);

/**
 * \brief Finish the token, complete the signing and get the result
 *
 * \param[in] me                Token Creation Context.
 * \param[out] completed_token  Pointer and length to completed token.
 *
 * \return one of the \ref attest_token_err_t errors.
 *
 * This completes the token after the payload has been added. When
 * this is called the signing algorithm is run and the final
 * formatting of the token is completed.
 */
enum attest_token_err_t
attest_token_encode_finish(struct attest_token_encode_ctx *me,
                           struct q_useful_buf_c *completed_token);

#ifdef __cplusplus
}
#endif

#endif /* __ATTEST_TOKEN_H__ */
