/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "otp.h"

#include "region_defs.h"
#include "tfm_plat_otp.h"
#include "tfm_plat_nv_counters.h"
#include "rse_rotpk_mapping.h"
#include "fatal_error.h"
#include "crypto.h"

#include <stdbool.h>
#include <stdint.h>

#ifdef TEST_BL1_1
extern uint8_t tfm_bl1_key_test_1_buf[];
extern uint8_t tfm_bl1_key_test_2_buf[];
#endif /* TEST_BL1_1 */

static enum tfm_otp_element_id_t bl1_key_id_to_otp_id(enum tfm_bl1_key_id_t key_id)
{
    switch (key_id) {
    case TFM_BL1_KEY_ROTPK_0:
        return rse_cm_get_bl1_rotpk();
#if TFM_BL1_2_SIGNER_AMOUNT == 2
    case TFM_BL1_KEY_ROTPK_0 + 1:
        return rse_dm_get_bl1_rotpk();
#endif
    default:
        return PLAT_OTP_ID_INVALID;
    }
}

fih_int bl1_otp_read_key(enum tfm_bl1_key_id_t key_id, uint8_t *key_buf,
                         size_t key_buf_len, size_t *key_size)
{
    enum tfm_plat_err_t err;
    enum tfm_otp_element_id_t otp_id = bl1_key_id_to_otp_id(key_id);

    if (key_size != NULL) {
        err = tfm_plat_otp_get_size(otp_id, key_size);
        if (err != TFM_PLAT_ERR_SUCCESS) {
            FIH_RET(fih_int_encode_zero_equality(err));
        }
    }

    err = tfm_plat_otp_read(otp_id, key_buf_len, key_buf);

    FIH_RET(fih_int_encode_zero_equality(err));
}

static enum tfm_bl1_key_type_t rse_type_to_bl1_type(enum rse_rotpk_type type)
{
    switch(type) {
    case RSE_ROTPK_TYPE_ECDSA:
        return TFM_BL1_KEY_TYPE_ECDSA;
    case RSE_ROTPK_TYPE_LMS:
        return TFM_BL1_KEY_TYPE_LMS;
    default:
        return (enum tfm_bl1_key_type_t)type;
    }
}

fih_int bl1_otp_get_key_type(enum tfm_bl1_key_id_t key_id,
                             enum tfm_bl1_key_type_t *key_type)
{
    enum tfm_plat_err_t err;
    enum tfm_otp_element_id_t otp_id = bl1_key_id_to_otp_id(key_id);
    enum rse_rotpk_type rse_type;

    err = rse_rotpk_get_type(otp_id, &rse_type);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        FIH_RET(fih_int_encode_zero_equality(err));
    }

    *key_type = rse_type_to_bl1_type(rse_type);

    FIH_RET(FIH_SUCCESS);
}

static enum tfm_bl1_key_policy_t rse_policy_to_bl1_policy(enum rse_rotpk_policy policy)
{
    switch(policy) {
    case RSE_ROTPK_POLICY_SIG_OPTIONAL:
        return TFM_BL1_KEY_MIGHT_SIGN;
    case RSE_ROTPK_POLICY_SIG_REQUIRED:
        return TFM_BL1_KEY_MUST_SIGN;
    default:
        return (enum tfm_bl1_key_policy_t)policy;
    }
}

fih_int bl1_otp_get_key_policy(enum tfm_bl1_key_id_t key_id,
                             enum tfm_bl1_key_policy_t *key_policy)
{
    enum tfm_plat_err_t err;
    enum tfm_otp_element_id_t otp_id = bl1_key_id_to_otp_id(key_id);
    enum rse_rotpk_policy rse_policy;

    err = rse_rotpk_get_policy(otp_id, &rse_policy);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        FIH_RET(fih_int_encode_zero_equality(err));
    }

    *key_policy = rse_policy_to_bl1_policy(rse_policy);

    FIH_RET(FIH_SUCCESS);
}

static enum tfm_bl1_hash_alg_t rse_hash_alg_to_bl1_hash_alg(enum rse_rotpk_hash_alg hash_alg)
{
    switch(hash_alg) {
    case RSE_ROTPK_HASH_ALG_SHA256:
        return TFM_BL1_HASH_ALG_SHA256;
    case RSE_ROTPK_HASH_ALG_SHA384:
        return TFM_BL1_HASH_ALG_SHA384;
    default:
        return (enum tfm_bl1_hash_alg_t)hash_alg;
    }
}

fih_int bl1_otp_get_key_hash_alg(enum tfm_bl1_key_id_t key_id,
                             enum tfm_bl1_hash_alg_t *key_hash_alg)
{
    enum tfm_plat_err_t err;
    enum tfm_otp_element_id_t otp_id = bl1_key_id_to_otp_id(key_id);
    enum rse_rotpk_hash_alg rse_hash_alg;

    err = rse_rotpk_get_hash_alg(otp_id, &rse_hash_alg);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        FIH_RET(fih_int_encode_zero_equality(err));
    }

    *key_hash_alg = rse_hash_alg_to_bl1_hash_alg(rse_hash_alg);

    FIH_RET(FIH_SUCCESS);
}
