/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <stdint.h>
#include <stddef.h>

#include "platform_error_codes.h"
#include "rse_get_rse_id.h"
#include "tfm_plat_otp.h"

/* Default implementation of rse_get_rse_id. Platforms should implement their own version of this function
 * when the RSE ID is not in the OTP */

enum tfm_plat_err_t rse_get_rse_id(uint32_t *rse_id)
{
    enum tfm_plat_err_t plat_err;

    plat_err = tfm_plat_otp_read(PLAT_OTP_ID_RSE_ID, sizeof(*rse_id), (uint8_t *)rse_id);
    if (plat_err != TFM_PLAT_ERR_SUCCESS) {
        return plat_err;
    }

    return TFM_PLAT_ERR_SUCCESS;
}
