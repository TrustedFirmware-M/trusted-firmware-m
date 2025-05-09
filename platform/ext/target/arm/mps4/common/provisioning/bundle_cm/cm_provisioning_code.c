/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "tfm_plat_otp.h"
#include "provisioning_bundle.h"
#include "bl1_random.h"

/* This is a stub to make the linker happy */
void __Vectors(){}

extern const struct cm_provisioning_data data;

enum tfm_plat_err_t __attribute__((section("DO_PROVISION"))) do_provision(void) {
    enum tfm_plat_err_t err;
    uint32_t new_lcs;
    uint32_t bl1_2_len = sizeof(data.bl1_2_image);
    uint8_t generated_key_buf[32];
    int32_t int_err;

    err = tfm_plat_otp_write(PLAT_OTP_ID_GUK,
                             sizeof(data.guk),
                             data.guk);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return err;
    }

    err = tfm_plat_otp_write(PLAT_OTP_ID_BL1_2_IMAGE_HASH,
                             sizeof(data.bl1_2_image_hash),
                             data.bl1_2_image_hash);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return err;
    }

    err = tfm_plat_otp_write(PLAT_OTP_ID_BL1_2_IMAGE,
                             sizeof(data.bl1_2_image),
                             data.bl1_2_image);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return err;
    }

    err = tfm_plat_otp_write(PLAT_OTP_ID_BL1_2_IMAGE_LEN,
                             sizeof(bl1_2_len),
                             (uint8_t *)&bl1_2_len);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return err;
    }

    err = tfm_plat_otp_write(PLAT_OTP_ID_SAM_CONFIG,
                             sizeof(data.sam_config),
                             (uint8_t*)&data.sam_config);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return err;
    }

    int_err = bl1_random_generate_secure(generated_key_buf,
                                         sizeof(generated_key_buf));
    if (int_err != 0) {
        return TFM_PLAT_ERR_SYSTEM_ERR;
    }

    err = tfm_plat_otp_write(PLAT_OTP_ID_HUK,
                             sizeof(generated_key_buf), generated_key_buf);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return err;
    }

    int_err = bl1_random_generate_secure(generated_key_buf,
                                         sizeof(generated_key_buf));
    if (int_err != 0) {
        return TFM_PLAT_ERR_SYSTEM_ERR;
    }

    new_lcs = PLAT_OTP_LCS_PSA_ROT_PROVISIONING;
    err = tfm_plat_otp_write(PLAT_OTP_ID_LCS, sizeof(new_lcs),
                             (uint8_t*)&new_lcs);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return err;
    }

    return err;
}
