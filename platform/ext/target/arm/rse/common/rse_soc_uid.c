/*
 * SPDX-License-Identifier: BSD-3-Clause
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 */

#include "rse_soc_uid.h"

#include "platform_error_codes.h"
#include "rse_zero_count.h"
#include "rse_otp_dev.h"
#include "cc3xx_rng.h"
#include "device_definition.h"
#include "fatal_error.h"

#include <string.h>

static bool rse_soc_uid_is_generated(void)
{
    uint32_t all_zero_uid[sizeof(P_RSE_OTP_SOC->soc_id_area.unique_id) / sizeof(uint32_t)] = {0};

    for (uint32_t idx = 0; idx < sizeof(all_zero_uid) / sizeof(uint32_t); idx++) {
        if (all_zero_uid[idx] != ((uint32_t *)P_RSE_OTP_SOC->soc_id_area.unique_id)[idx]) {
            return true;
        }
    }

    return false;
}

enum tfm_plat_err_t rse_generate_soc_uid(void)
{
    uint8_t soc_uid[sizeof(P_RSE_OTP_SOC->soc_id_area.unique_id)];
    cc3xx_err_t cc_err;
    enum lcm_error_t lcm_err;

    if (rse_soc_uid_is_generated()) {
        return TFM_PLAT_ERR_SUCCESS;
    }

    cc_err = cc3xx_lowlevel_rng_get_random(soc_uid, sizeof(soc_uid),
                                           CC3XX_RNG_CRYPTOGRAPHICALLY_SECURE);
    if (cc_err != CC3XX_ERR_SUCCESS) {
        return (enum tfm_plat_err_t)cc_err;
    }

    lcm_err = lcm_otp_write(&LCM_DEV_S, OTP_OFFSET(P_RSE_OTP_SOC->soc_id_area.unique_id),
                            sizeof(P_RSE_OTP_SOC->soc_id_area.unique_id), (uint8_t *)&soc_uid);
    if (lcm_err != LCM_ERROR_NONE) {
        return (enum tfm_plat_err_t)lcm_err;
    }

    return rse_lock_soc_uid();
}

enum tfm_plat_err_t rse_lock_soc_uid(void)
{
    enum tfm_plat_err_t err;
    uint32_t zero_count;

    if (!rse_soc_uid_is_generated()) {
        FATAL_ERR(TFM_PLAT_ERR_SOC_UID_NOT_GENERATED);
        return TFM_PLAT_ERR_SOC_UID_NOT_GENERATED;
    }

    if (P_RSE_OTP_SOC->soc_id_area.zero_count_unique_id == 0) {
        err = rse_count_zero_bits((uint8_t *)&P_RSE_OTP_SOC->soc_id_area.unique_id,
                                  sizeof(P_RSE_OTP_SOC->soc_id_area.unique_id),
                                  &zero_count);
        if (err != TFM_PLAT_ERR_SUCCESS) {
            return err;
        }

        return (enum tfm_plat_err_t)lcm_otp_write(&LCM_DEV_S,
                                                  OTP_OFFSET(P_RSE_OTP_SOC->soc_id_area.zero_count_unique_id),
                                                  sizeof(zero_count),
                                                  (uint8_t *)&zero_count);
    } else {
        return rse_check_zero_bit_count((uint8_t *)&P_RSE_OTP_SOC->soc_id_area.unique_id,
                                        sizeof(P_RSE_OTP_SOC->soc_id_area.unique_id),
                                        (uint32_t *)&P_RSE_OTP_SOC->soc_id_area.zero_count_unique_id);
    }
}
