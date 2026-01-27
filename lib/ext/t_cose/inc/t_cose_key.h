/*
 * t_cose_key.h
 *
 * Copyright 2019-2023, Laurence Lundblade
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * Created by Laurence Lundblade on 2/6/23.
 *
 * See BSD-3-Clause license in README.md
 */

#ifndef __T_COSE_KEY_H__
#define __T_COSE_KEY_H__

#include <stdbool.h>
#include <stdint.h>
#include "q_useful_buf.h"
#include "t_cose_common.h"
#include "t_cose_standard_constants.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \brief Decode a CBOR serialized COSE_Key object and turn it to a t_cose_key.
 *
 * \param[in]  cbor_encoded  A buffer which holds a COSE_Key object.
 * \param[out] key           A pointer to a t_cose_key structure.
 */
enum t_cose_err_t
t_cose_key_decode(struct q_useful_buf_c cbor_encoded,
                  struct t_cose_key     *key);


/**
 * \brief Encode a t_cose_key as a CBOR serialized COSE_Key object
 *
 * \param[in]  key           A t_cose_key to encode it as a COSE_Key.
 * \param[in]  key_buf       A buffer to hold the COSE_Key.
 * \param[out] cbor_encoded  Place to return pointer and length of
 *                           COSE_Key.
 *
 * The t_cose_key must be imported to the crypto library before this call.
 */
enum t_cose_err_t
t_cose_key_encode(struct t_cose_key      key,
                  struct q_useful_buf    key_buf,
                  struct q_useful_buf_c *cbor_encoded);


#ifdef __cplusplus
}
#endif

#endif /* __T_COSE_KEY_H__ */
