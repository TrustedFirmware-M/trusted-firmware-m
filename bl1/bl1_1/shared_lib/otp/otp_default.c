/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "otp.h"

#include <stdint.h>

#include "region_defs.h"
#include "tfm_plat_otp.h"
#include "tfm_plat_nv_counters.h"
#include "util.h"

#ifdef TEST_BL1_1
extern uint8_t tfm_bl1_key_test_1_buf[];
extern uint8_t tfm_bl1_key_test_2_buf[];
#endif /* TEST_BL1_1 */

fih_ret bl1_otp_read(uint8_t *dst, uint8_t *src, size_t size);
fih_ret bl1_otp_write(uint8_t *dst, uint8_t *src, size_t size);

fih_ret bl1_otp_read_key(enum tfm_bl1_key_id_t key_id, uint8_t *key_buf,
                         size_t key_buf_len, size_t *key_size)
{
    FIH_DECLARE(fih_rc, FIH_FAILURE);
    enum tfm_plat_err_t plat_err;
    enum tfm_otp_element_id_t otp_id;

    switch (key_id) {
    case TFM_BL1_KEY_HUK:
        otp_id = PLAT_OTP_ID_HUK;
        break;
    case TFM_BL1_KEY_GUK:
        otp_id = PLAT_OTP_ID_GUK;
        break;
    case TFM_BL1_KEY_BL2_ENCRYPTION:
        otp_id = PLAT_OTP_ID_KEY_BL2_ENCRYPTION;
        break;
    case TFM_BL1_KEY_ROTPK_0:
        otp_id = PLAT_OTP_ID_BL1_ROTPK_0;
        break;
    default:
        FIH_RET(FIH_FAILURE);
    }

    if (key_size != NULL) {
        tfm_plat_otp_get_size(otp_id, key_size);
    }

    plat_err = tfm_plat_otp_read(otp_id, key_buf_len, key_buf);
    fih_rc = fih_ret_encode_zero_equality(plat_err);

    FIH_RET(fih_rc);
}
