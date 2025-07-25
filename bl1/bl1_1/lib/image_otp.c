/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "image.h"

#include "region_defs.h"
#include "tfm_plat_otp.h"

fih_ret bl1_read_bl1_2_image(uint8_t *image)
{
    FIH_DECLARE(fih_rc, FIH_FAILURE);
    enum tfm_plat_err_t plat_err;
    uint32_t bl1_2_len;

    plat_err = tfm_plat_otp_read(PLAT_OTP_ID_BL1_2_IMAGE_LEN, sizeof(bl1_2_len),
                                 (uint8_t *)&bl1_2_len);
    fih_rc = fih_ret_encode_zero_equality(plat_err);
    if (FIH_NOT_EQ(fih_rc, FIH_SUCCESS)) {
        FIH_RET(fih_rc);
    }

    plat_err = tfm_plat_otp_read(PLAT_OTP_ID_BL1_2_IMAGE, bl1_2_len, image);
    fih_rc = fih_ret_encode_zero_equality(plat_err);

    FIH_RET(fih_rc);
}
