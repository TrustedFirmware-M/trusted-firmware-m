/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <assert.h>
#include "rse_rotpk_mapping.h"
#include "rse_otp_dev.h"
#include "fatal_error.h"

#include "rse_rotpk_config.h"

/* Possible errors when looking up policy_word and rotpk_index */
enum get_policy_and_rotpk_err_t {
    SUCCESSFUL_LOOKUP,
    INVALID_AREA_POINTER,
    OUT_OF_RANGE_OTP_ID,
};

/* Possible properties to return per OTP ID */
enum items_to_get_t {
    TYPE,
    POLICY,
    HASH_ALG,
    __ITEMS_TO_GET_MAX
};

static const enum tfm_plat_err_t err[__ITEMS_TO_GET_MAX][3] = {
    {TFM_PLAT_ERR_ROTPK_GET_TYPE_INVALID_ARGUMENT,
     TFM_PLAT_ERR_ROTPK_GET_TYPE_ROTPK_AREA_INVALID,
     TFM_PLAT_ERR_ROTPK_GET_TYPE_INVALID_ID},
    {TFM_PLAT_ERR_ROTPK_GET_POLICY_INVALID_ARGUMENT,
     TFM_PLAT_ERR_ROTPK_GET_POLICY_ROTPK_AREA_INVALID,
     TFM_PLAT_ERR_ROTPK_GET_POLICY_INVALID_ID},
    {TFM_PLAT_ERR_ROTPK_GET_HASH_ALG_INVALID_ARGUMENT,
     TFM_PLAT_ERR_ROTPK_GET_HASH_ALG_ROTPK_AREA_INVALID,
     TFM_PLAT_ERR_ROTPK_GET_HASH_ALG_INVALID_ID},
};

#define LOOKUP_ERROR_CODE(item, err_type) err[item][err_type]

static enum get_policy_and_rotpk_err_t get_policy_word_and_rotpk_index(
    enum tfm_otp_element_id_t otp_id, uint32_t *policy_word, uint32_t *rotpk_index)
{
    enum tfm_otp_element_id_t rotpk_base;

    if ((otp_id >= PLAT_OTP_ID_CM_ROTPK) && (otp_id < PLAT_OTP_ID_CM_ROTPK_MAX)) {
        rotpk_base = PLAT_OTP_ID_CM_ROTPK;
        if (!IS_RSE_OTP_AREA_VALID(CM_ROTPK)) {
            return INVALID_AREA_POINTER;
        }
        *policy_word = P_RSE_OTP_CM_ROTPK->cm_rotpk_policies;
    } else if ((otp_id >= PLAT_OTP_ID_DM_ROTPK) && (otp_id < PLAT_OTP_ID_DM_ROTPK_MAX)) {
        rotpk_base = PLAT_OTP_ID_DM_ROTPK;
        if (!IS_RSE_OTP_AREA_VALID(DM_ROTPK)) {
            return INVALID_AREA_POINTER;
        }
        *policy_word = P_RSE_OTP_DM_ROTPK->dm_rotpk_policies;
    } else {
        return OUT_OF_RANGE_OTP_ID;
    }

    *rotpk_index = otp_id - rotpk_base;

    return SUCCESSFUL_LOOKUP;
}

static enum tfm_plat_err_t rse_rotpk_mapping_get(
    enum tfm_otp_element_id_t otp_id, enum items_to_get_t item, void *out)
{
    if (out == NULL) {
        return LOOKUP_ERROR_CODE(item, 0);
    }

    uint32_t policy_word, rotpk_index;
    const enum get_policy_and_rotpk_err_t ret =
        get_policy_word_and_rotpk_index(otp_id, &policy_word, &rotpk_index);

    if (ret == SUCCESSFUL_LOOKUP) {

        switch (item) {
        case TYPE:
            *((enum rse_rotpk_type *)out) = (policy_word >> (2 * rotpk_index)) & 0b11;
            break;
        case POLICY:
            *((enum rse_rotpk_policy *)out) = (policy_word >> (18 + rotpk_index)) & 0b1;
            break;
        case HASH_ALG:
            *((enum rse_rotpk_hash_alg *)out) = (policy_word >> (12 + rotpk_index)) & 0b1;
            break;
        default:
            assert(0);
        }
        return TFM_PLAT_ERR_SUCCESS;

    } else if ((ret == INVALID_AREA_POINTER) || (ret == OUT_OF_RANGE_OTP_ID)) {

        FATAL_ERR(LOOKUP_ERROR_CODE(item, ret));
        return LOOKUP_ERROR_CODE(item, ret);

    } else {
        assert(0);
        return LOOKUP_ERROR_CODE(item, 0);
    }
}

enum tfm_plat_err_t rse_rotpk_get_type(
    enum tfm_otp_element_id_t otp_id, enum rse_rotpk_type *type)
{
    return rse_rotpk_mapping_get(otp_id, TYPE, type);
}

enum tfm_plat_err_t rse_rotpk_get_policy(
    enum tfm_otp_element_id_t otp_id, enum rse_rotpk_policy *policy)
{
    return rse_rotpk_mapping_get(otp_id, POLICY, policy);
}

enum tfm_plat_err_t rse_rotpk_get_hash_alg(
    enum tfm_otp_element_id_t otp_id, enum rse_rotpk_hash_alg *hash_alg)
{
    return rse_rotpk_mapping_get(otp_id, HASH_ALG, hash_alg);
}

enum tfm_otp_element_id_t rse_cm_get_bl1_rotpk(void)
{
    return PLAT_OTP_ID_CM_ROTPK + RSE_CM_OTP_ID_FOR_BL1_IMAGE();
}

enum tfm_otp_element_id_t rse_cm_get_bl2_rotpk(uint32_t image_id)
{
    return PLAT_OTP_ID_CM_ROTPK + RSE_CM_OTP_ID_FOR_BL2_IMAGE(image_id);
}

enum tfm_otp_element_id_t rse_cm_get_host_rotpk(uint32_t host_rotpk_id)
{
    return PLAT_OTP_ID_CM_ROTPK + RSE_CM_OTP_ID_FOR_HOST(host_rotpk_id);
}

enum tfm_otp_element_id_t rse_cm_get_secure_debug_rotpk(void)
{
    return PLAT_OTP_ID_CM_ROTPK + RSE_CM_OTP_ID_FOR_SECURE_DEBUG();
}

enum tfm_otp_element_id_t rse_cm_get_subplatform_rotpk(uint32_t subplatform_rotpk_id)
{
    return PLAT_OTP_ID_CM_ROTPK + RSE_CM_OTP_ID_FOR_SUBPLATFORM(subplatform_rotpk_id);
}

enum tfm_otp_element_id_t rse_dm_get_bl1_rotpk(void)
{
    return PLAT_OTP_ID_DM_ROTPK + RSE_DM_OTP_ID_FOR_BL1_IMAGE();
}

enum tfm_otp_element_id_t rse_dm_get_bl2_rotpk(uint32_t image_id)
{
    return PLAT_OTP_ID_DM_ROTPK + RSE_DM_OTP_ID_FOR_BL2_IMAGE(image_id);
}

enum tfm_otp_element_id_t rse_dm_get_host_rotpk(uint32_t host_rotpk_id)
{
    return PLAT_OTP_ID_DM_ROTPK + RSE_DM_OTP_ID_FOR_HOST(host_rotpk_id);
}

enum tfm_otp_element_id_t rse_dm_get_secure_debug_rotpk(void)
{
    return PLAT_OTP_ID_DM_ROTPK + RSE_DM_OTP_ID_FOR_SECURE_DEBUG();
}

enum tfm_otp_element_id_t rse_dm_get_subplatform_rotpk(uint32_t subplatform_rotpk_id)
{
    return PLAT_OTP_ID_DM_ROTPK + RSE_DM_OTP_ID_FOR_SUBPLATFORM(subplatform_rotpk_id);
}
