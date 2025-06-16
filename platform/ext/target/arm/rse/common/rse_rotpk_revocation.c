/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "rse_rotpk_revocation.h"

#include "rse_otp_layout.h"
#include "tfm_plat_nv_counters.h"
#include "tfm_plat_otp.h"
#include "fatal_error.h"
#include "rse_otp_dev.h"
#include "rse_zero_count.h"

static enum tfm_plat_err_t revoke_rotpks(enum tfm_nv_counter_t counter_id, uint32_t *new_idx)
{
    enum tfm_plat_err_t err;
    uint32_t current_revocation_idx;

    err = tfm_plat_read_nv_counter(counter_id, sizeof(current_revocation_idx),
                                   (uint8_t *)&current_revocation_idx);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return err;
    }

    err = tfm_plat_increment_nv_counter(counter_id);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return err;
    }

    *new_idx = current_revocation_idx + 1;

    /* Now reinit the OTP so that it picks up the new ROTPK area */
    return tfm_plat_otp_init();
}

static enum tfm_plat_err_t rse_revoke_cm_rotpks_get_idx(uint32_t *new_idx)
{
    return revoke_rotpks(PLAT_NV_COUNTER_CM_ROTPK_REPROVISIONING, new_idx);
}

enum tfm_plat_err_t rse_revoke_cm_rotpks(void)
{
    uint32_t new_idx;

    return rse_revoke_cm_rotpks_get_idx(&new_idx);
}

static enum tfm_plat_err_t rse_revoke_dm_rotpks_get_idx(uint32_t *new_idx)
{
    return revoke_rotpks(PLAT_NV_COUNTER_DM_ROTPK_REPROVISIONING, new_idx);
}

enum tfm_plat_err_t rse_revoke_dm_rotpks(void)
{
    uint32_t new_idx;

    return rse_revoke_dm_rotpks_get_idx(&new_idx);
}

enum tfm_plat_err_t rse_update_cm_rotpks(uint32_t policies, uint8_t *rotpks, size_t rotpks_len)
{
    enum tfm_plat_err_t err;
    enum lcm_error_t lcm_err;
    uint32_t zero_count;
    uint32_t new_idx;

    if (rotpks_len != RSE_OTP_CM_ROTPK_AMOUNT * RSE_OTP_CM_ROTPK_SIZE) {
        return TFM_PLAT_ERR_CM_ROTPK_UPDATE_INVALID_SIZE;
    }

    /* If they're not already revoked, revoke them */
    if (IS_RSE_OTP_AREA_VALID(CM_ROTPK) && (P_RSE_OTP_CM_ROTPK->zero_count != 0)) {
        err = rse_revoke_cm_rotpks_get_idx(&new_idx);
        if (err != TFM_PLAT_ERR_SUCCESS) {
            return err;
        }
    } else {
        new_idx = 0;
    }

    /* We expect the current CM ROTPK area not to be valid as that indicates that no ROTPKs
     * in this area have yet been written. If they have, we cannot overwrite them */
    if (IS_RSE_OTP_AREA_VALID(CM_ROTPK)) {
        return TFM_PLAT_ERR_CM_ROTPK_UPDATE_INVALID_AREA;
    }

    lcm_err = lcm_otp_write(&LCM_DEV_S,
                            OTP_OFFSET(P_RSE_OTP_CM->rotpk_areas[new_idx].cm_rotpk_policies),
                            sizeof(policies), (uint8_t *)&policies);
    if (lcm_err != LCM_ERROR_NONE) {
        return (enum tfm_plat_err_t)lcm_err;
    }

    lcm_err = lcm_otp_write(&LCM_DEV_S, OTP_OFFSET(P_RSE_OTP_CM->rotpk_areas[new_idx].rotpk),
                            rotpks_len, rotpks);
    if (lcm_err != LCM_ERROR_NONE) {
        return (enum tfm_plat_err_t)lcm_err;
    }

    err = rse_count_zero_bits(
        (uint8_t *)((uint8_t *)&P_RSE_OTP_CM->rotpk_areas[new_idx].zero_count + sizeof(uint32_t)),
        sizeof(struct rse_otp_cm_rotpk_area_t) - sizeof(uint32_t), &zero_count);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return err;
    }

    lcm_err = lcm_otp_write(&LCM_DEV_S, OTP_OFFSET(P_RSE_OTP_CM->rotpk_areas[new_idx].zero_count),
                            sizeof(zero_count), (uint8_t *)&zero_count);
    if (lcm_err != LCM_ERROR_NONE) {
        return (enum tfm_plat_err_t)lcm_err;
    }

    /* Now reinit the OTP so that it picks up new keys */
    return tfm_plat_otp_init();
}

enum tfm_plat_err_t rse_update_dm_rotpks(uint32_t policies, uint8_t *rotpks, size_t rotpks_len)
{
    enum tfm_plat_err_t err;
    enum lcm_error_t lcm_err;
    uint32_t new_idx;
    uint32_t zero_count;

    if (rotpks_len != RSE_OTP_DM_ROTPK_AMOUNT * RSE_OTP_DM_ROTPK_SIZE) {
        return TFM_PLAT_ERR_DM_ROTPK_UPDATE_INVALID_SIZE;
    }

    /* If they're not already revoked, revoke them */
    if (IS_RSE_OTP_AREA_VALID(DM_ROTPK) && (P_RSE_OTP_DM_ROTPK->zero_count != 0)) {
        err = rse_revoke_dm_rotpks_get_idx(&new_idx);
        if (err != TFM_PLAT_ERR_SUCCESS) {
            return err;
        }
    } else {
        new_idx = 0;
    }

    /* We expect the current DM ROTPK area not to be valid as that indicates that no ROTPKs
     * in this area have yet been written. If they have, we cannot overwrite them */
     if (IS_RSE_OTP_AREA_VALID(DM_ROTPK)) {
        return TFM_PLAT_ERR_DM_ROTPK_UPDATE_INVALID_AREA;
    }

    lcm_err = lcm_otp_write(&LCM_DEV_S,
                            OTP_OFFSET(P_RSE_OTP_DM->rotpk_areas[new_idx].dm_rotpk_policies),
                            sizeof(policies), (uint8_t *)&policies);
    if (lcm_err != LCM_ERROR_NONE) {
        return (enum tfm_plat_err_t)lcm_err;
    }

    lcm_err = lcm_otp_write(&LCM_DEV_S, OTP_OFFSET(P_RSE_OTP_DM->rotpk_areas[new_idx].rotpk),
                            rotpks_len, rotpks);
    if (lcm_err != LCM_ERROR_NONE) {
        return (enum tfm_plat_err_t)lcm_err;
    }

    err = rse_count_zero_bits(
        (uint8_t *)((uint8_t *)&P_RSE_OTP_DM->rotpk_areas[new_idx].zero_count + sizeof(uint32_t)),
        sizeof(struct rse_otp_dm_rotpk_area_t) - sizeof(uint32_t), &zero_count);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return err;
    }

    lcm_err = lcm_otp_write(&LCM_DEV_S, OTP_OFFSET(P_RSE_OTP_DM->rotpk_areas[new_idx].zero_count),
                            sizeof(zero_count), (uint8_t *)&zero_count);
    if (lcm_err != LCM_ERROR_NONE) {
        return (enum tfm_plat_err_t)lcm_err;
    }

    /* Now reinit the OTP so that it picks up new keys */
    return tfm_plat_otp_init();
}
