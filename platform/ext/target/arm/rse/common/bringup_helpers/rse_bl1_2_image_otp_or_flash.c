/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */


#include "region_defs.h"
#include "tfm_plat_otp.h"
#include "Driver_Flash.h"
#include "flash_layout.h"
#include "region_defs.h"
#include "fih.h"
#include "device_definition.h"

/* Flash device name must be specified by target */
extern ARM_DRIVER_FLASH FLASH_DEV_NAME;

fih_ret bl1_read_bl1_2_image(uint8_t *image)
{
    int data_read;
    fih_int fih_rc;
    enum tfm_plat_err_t plat_err;
    uint32_t bl1_2_len;

    plat_err = tfm_plat_otp_read(PLAT_OTP_ID_BL1_2_IMAGE_LEN, sizeof(bl1_2_len),
                                 (uint8_t *)&bl1_2_len);
    fih_rc = fih_ret_encode_zero_equality(plat_err);
    if (FIH_NOT_EQ(fih_rc, FIH_SUCCESS)) {
        FIH_RET(fih_rc);
    }

    plat_err = tfm_plat_otp_read(PLAT_OTP_ID_BL1_2_IMAGE, bl1_2_len, image);
    if (plat_err == TFM_PLAT_ERR_OTP_EMULATION_UNSUPPORTED) {
        /* If this returns unsupported, then the OTP emulation isn't large
         * enough to contain the BL1_2 image.
         */
        data_read = FLASH_DEV_NAME_BL1.ReadData(BL1_2_IMAGE_FLASH_OFFSET,
                                                image,
                                                bl1_2_len);
        if (data_read != bl1_2_len) {
            FIH_SET(fih_rc, TFM_PLAT_ERR_READ_BL1_2_IMAGE_FLASH_INVALID_READ);
        }
        else {
            fih_rc = FIH_SUCCESS;
        }
    } else {
        fih_rc = fih_ret_encode_zero_equality(plat_err);
    }

    FIH_RET(fih_rc);
}
