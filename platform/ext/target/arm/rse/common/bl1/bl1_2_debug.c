/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <stdbool.h>
#include "bl1_2_debug.h"
#include "device_definition.h"
#include "lcm_drv.h"
#include "platform_dcu.h"
#include "tfm_plat_otp.h"

static int32_t debug_preconditions_check(bool *valid_debug_conditions)
{
    enum tfm_plat_err_t plat_err;
    enum plat_otp_lcs_t lcs;

    /* Read LCS from OTP */
    plat_err = tfm_plat_otp_read(PLAT_OTP_ID_LCS, sizeof(lcs), (uint8_t*)&lcs);
    if (plat_err != TFM_PLAT_ERR_SUCCESS) {
        return plat_err;
    }

    *valid_debug_conditions = (lcs == PLAT_OTP_LCS_SECURED) ? true : false;

    return 0;
}

static int32_t tfm_plat_lock_rse_debug(void)
{
    enum lcm_error_t lcm_err;
    uint32_t dcu_lock_reg_val[LCM_DCU_WIDTH_IN_BYTES / sizeof(uint32_t)];

    lcm_err = lcm_dcu_get_locked(&LCM_DEV_S, (uint8_t *)dcu_lock_reg_val);
    if (lcm_err != LCM_ERROR_NONE) {
        return -1;
    }

    /* 32 Least significant (First word) LCM dcu_en signals are assigned for RSE */
    dcu_lock_reg_val[0] = PLAT_RSE_DCU_LOCK0_VALUE;

    return lcm_dcu_set_locked(&LCM_DEV_S, (uint8_t*)dcu_lock_reg_val);
}

static int32_t tfm_plat_lock_non_rse_debug(void)
{
    enum lcm_error_t lcm_err;
    uint32_t dcu_lock_reg_val[LCM_DCU_WIDTH_IN_BYTES / sizeof(uint32_t)];

    lcm_err = lcm_dcu_get_locked(&LCM_DEV_S, (uint8_t *)dcu_lock_reg_val);
    if (lcm_err != LCM_ERROR_NONE) {
        return -1;
    }

    /* Words 1-3 LCM dcu_en signals are all Non-RSE */
    /* Please insert platform specific values, i.e. whether or not to lock
     * certain domain
     */
    dcu_lock_reg_val[1] = PLAT_NOT_RSE_DCU_LOCK1_VALUE;
    dcu_lock_reg_val[2] = PLAT_NOT_RSE_DCU_LOCK2_VALUE;
    dcu_lock_reg_val[3] = PLAT_NOT_RSE_DCU_LOCK3_VALUE;

    return lcm_dcu_set_locked(&LCM_DEV_S, (uint8_t*)dcu_lock_reg_val);
}

int32_t b1_2_platform_debug_init(void)
{
    int32_t rc;
    bool valid_debug_conditions;

    rc = tfm_plat_lock_rse_debug();
    if (rc != 0) {
        return rc;
    }

    rc = debug_preconditions_check(&valid_debug_conditions);
    if (rc != 0) {
        return rc;
    }

    if (valid_debug_conditions) {
        /* Apply platform specific locks to rest of SoC (not RSE) */
        rc = tfm_plat_lock_non_rse_debug();
    }

    return rc;
}
