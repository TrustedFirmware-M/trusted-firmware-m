/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef BL1_1_OTP_H
#define BL1_1_OTP_H

#include <stdint.h>
#include <stddef.h>

#include "fih.h"
#include "crypto.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifndef TFM_OTP_NV_COUNTER_NUMBER
#define TFM_OTP_NV_COUNTER_NUMBER 4u
#endif /* !TFM_OTP_NV_COUNTER_NUMBER */

#ifndef TFM_OTP_NV_COUNTER_SIZE_IN_BITS
#define TFM_OTP_NV_COUNTER_SIZE_IN_BITS 32u
#endif /* !TFM_OTP_NV_COUNTER_SIZE_IN_BITS */

/* Use ceiling division so we always have at least the correct amount of bits */
#define TFM_OTP_NV_COUNTER_BYTES ((TFM_OTP_NV_COUNTER_SIZE_IN_BITS + 7) / 8)

enum tfm_bl1_nv_counter_id_t {
    BL1_NV_COUNTER_ID_BL2_IMAGE,
};

/* Load the key with the given ID into the key buf */
fih_ret bl1_otp_read_key(enum tfm_bl1_key_id_t key_id, uint8_t *key_buf, size_t key_buf_len, size_t *key_size);

/* Get the type of the key with the given key ID */
fih_ret bl1_otp_get_key_type(enum tfm_bl1_key_id_t key_id, enum tfm_bl1_key_type_t *key_type);

/* Get the policy of the key with the given key ID */
fih_ret bl1_otp_get_key_policy(enum tfm_bl1_key_id_t key_id, enum tfm_bl1_key_policy_t *key_policy);

/* Get the ROTPK hash alg of the key with the given key ID */
fih_ret bl1_otp_get_key_hash_alg(enum tfm_bl1_key_id_t key_id, enum tfm_bl1_hash_alg_t *key_hash_alg);


#ifdef __cplusplus
}
#endif

#endif /* BL1_1_OTP_H */
