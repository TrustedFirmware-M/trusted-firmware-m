/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "tfm_plat_otp.h"
#include "rse_provisioning_values.h"
#include "device_definition.h"
#include "rse_otp_dev.h"
#include "region_defs.h"
#include "cc3xx_drv.h"
#include "tfm_log.h"
#include "rse_zero_count.h"
#include "rse_permanently_disable_device.h"
#include "rse_provisioning_message_handler.h"

#ifndef RSE_COMBINED_PROVISIONING_BUNDLES
static const struct rse_cm_provisioning_values_t *values =
    (const struct rse_cm_provisioning_values_t *)PROVISIONING_BUNDLE_VALUES_START;

/* This is a stub to make the linker happy */
void __Vectors(){}
#else

static const struct rse_cm_provisioning_values_t *values =
    &((const struct rse_combined_provisioning_values_t *)PROVISIONING_BUNDLE_VALUES_START)->cm;
#endif

#if !defined(RSE_CM_PROVISION_GUK) || !defined(RSE_CM_PROVISION_KP_CM) || !defined(RSE_CM_PROVISION_KCE_CM)
static enum tfm_plat_err_t provision_derived_key(enum kmu_hardware_keyslot_t input_key,
                                                 uint32_t *input_key_buf,
                                                 uint8_t *label, size_t label_len,
                                                 uint8_t *context, size_t context_len,
                                                 enum tfm_otp_element_id_t otp_id,
                                                 size_t key_size)
{
    uint32_t key_buf[key_size / sizeof(uint32_t)];
    enum tfm_plat_err_t err;
    cc3xx_err_t cc_err;
    enum lcm_tp_mode_t tp_mode;
    uint32_t all_zero_key[32 / sizeof(uint32_t)] = {0};
    enum lcm_error_t lcm_err;

    /* In TCI mode the KRTL isn't available, so substitute for the all-zero key
     */
    lcm_err = lcm_get_tp_mode(&LCM_DEV_S, &tp_mode);
    if (lcm_err != LCM_ERROR_NONE) {
        return (enum tfm_plat_err_t)lcm_err;
    }

    if (input_key == KMU_HW_SLOT_KRTL
     && tp_mode == LCM_TP_MODE_TCI
     && input_key_buf == NULL) {
        input_key_buf = all_zero_key;
    }

    cc_err = cc3xx_lowlevel_kdf_cmac(input_key, input_key_buf, CC3XX_AES_KEYSIZE_256,
                                     label, label_len, context, context_len, key_buf,
                                     sizeof(key_buf));
    if (cc_err != CC3XX_ERR_SUCCESS) {
        err = (enum tfm_plat_err_t)cc_err;
        goto out;
    }

    err = tfm_plat_otp_write(otp_id, key_size, (uint8_t *)key_buf);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        goto out;
    }

    err = TFM_PLAT_ERR_SUCCESS;

out:
    (void)cc3xx_lowlevel_rng_get_random((uint8_t *)key_buf, key_size, CC3XX_RNG_FAST);

    return err;
}
#endif /* !RSE_CM_PROVISION_GUK || !RSE_CM_PROVISION_KP_CM || ! !RSE_CM_PROVISION_KCE_CM */

#ifndef RSE_COMBINED_PROVISIONING_BUNDLES
__attribute__((section("DO_PROVISION"))) enum tfm_plat_err_t do_provision(void) {
#else
enum tfm_plat_err_t do_cm_provision(void) {
#endif
    enum tfm_plat_err_t err;
    uint32_t new_lcs;
    uint32_t generated_key_buf[32 / sizeof(uint32_t)];
    enum lcm_error_t lcm_err;
    cc3xx_err_t cc_err;
    uint32_t zero_count;

    if (P_RSE_OTP_HEADER->device_status != 0) {
        rse_permanently_disable_device(RSE_PERMANENT_ERROR_OTP_MODIFIED_BEFORE_CM_PROVISIONING);
        return TFM_PLAT_ERR_PROVISIONING_DEVICE_STATUS_TAMPERING_DETECTED;
    }

    zero_count = 8 * values->cm_area_info.size;
    err = rse_check_zero_bit_count((uint8_t *)(OTP_BASE_S + values->cm_area_info.offset),
                                   values->cm_area_info.size, zero_count);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        rse_permanently_disable_device(RSE_PERMANENT_ERROR_OTP_MODIFIED_BEFORE_CM_PROVISIONING);
        return TFM_PLAT_ERR_PROVISIONING_CM_TAMPERING_DETECTED;
    }

    INFO("Provisioning GUK\n");
#ifdef RSE_CM_PROVISION_GUK
    err = tfm_plat_otp_write(PLAT_OTP_ID_GUK,
                             sizeof(values->guk),
                             values->guk);
#else
    err = provision_derived_key(KMU_HW_SLOT_KRTL, NULL,
                                (uint8_t *)"GUK", sizeof("GUK"), NULL, 0,
                                PLAT_OTP_ID_GUK, 32);
#endif
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return err;
    }

    INFO("Provisioning KP_CM\n");
#ifdef RSE_CM_PROVISION_KP_CM
    err = tfm_plat_otp_write(PLAT_OTP_ID_CM_PROVISIONING_KEY,
                             sizeof(values->kp_cm),
                             values->kp_cm);
#else
    err = provision_derived_key(KMU_HW_SLOT_KRTL, NULL,
                                (uint8_t *)"KP_CM", sizeof("KP_CM"), NULL, 0,
                                PLAT_OTP_ID_CM_PROVISIONING_KEY, 32);
#endif
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return err;
    }

    INFO("Provisioning DMA ICS\n");
    err = tfm_plat_otp_write(PLAT_OTP_ID_DMA_ICS,
                             values->otp_dma_ics_size,
                             (uint8_t*)&values->otp_dma_ics);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return err;
    }

    /* The OTP system hasn't got the area_infos set up yet, so this has to
     * bypass the OTP HAL and directly use the LCM.
     */

    INFO("Writing CM area info\n");
    lcm_err = lcm_otp_write(&LCM_DEV_S,
                            offsetof(struct rse_otp_header_area_t, cm_area_info),
                            sizeof(values->cm_area_info),
                            (uint8_t *)&values->cm_area_info.raw_data);
    if (lcm_err != LCM_ERROR_NONE) {
        return (enum tfm_plat_err_t)lcm_err;
    }

    INFO("Writing BL1_2 area info\n");
    lcm_err = lcm_otp_write(&LCM_DEV_S,
                            offsetof(struct rse_otp_header_area_t, bl1_2_area_info),
                            sizeof(values->bl1_2_area_info),
                            (uint8_t *)&values->bl1_2_area_info);
    if (lcm_err != LCM_ERROR_NONE) {
        return (enum tfm_plat_err_t)lcm_err;
    }

    INFO("Writing SOC area info\n");
    struct rse_otp_area_info_t soc_area_info = {
        .offset = RSE_OTP_SIZE - sizeof(struct rse_otp_soc_area_t),
        .size = sizeof(struct rse_otp_soc_area_t)
    };
    lcm_err = lcm_otp_write(&LCM_DEV_S,
                            offsetof(struct rse_otp_header_area_t, soc_area_info),
                            sizeof(soc_area_info),
                            (uint8_t *)&soc_area_info);
    if (lcm_err != LCM_ERROR_NONE) {
        return (enum tfm_plat_err_t)lcm_err;
    }

#ifndef OTP_CONFIG_DM_SETS_DM_AND_DYNAMIC_AREA_SIZE
    INFO("Writing DM area info\n");
    lcm_err = lcm_otp_write(&LCM_DEV_S,
                            offsetof(struct rse_otp_header_area_t, dm_area_info),
                            sizeof(values->dm_area_info),
                            (uint8_t *)&values->dm_area_info);
    if (lcm_err != LCM_ERROR_NONE) {
        return (enum tfm_plat_err_t)lcm_err;
    }

    INFO("Writing dynamic area info\n");
    lcm_err = lcm_otp_write(&LCM_DEV_S,
                            offsetof(struct rse_otp_header_area_t, dynamic_area_info),
                            sizeof(values->dynamic_area_info),
                            (uint8_t *)&values->dynamic_area_info);
    if (lcm_err != LCM_ERROR_NONE) {
        return (enum tfm_plat_err_t)lcm_err;
    }
#endif /* OTP_CONFIG_DM_SETS_DM_AND_DYNAMIC_AREA_SIZE */

    INFO("Writing BL1_2 provisioning values\n");
    lcm_err = lcm_otp_write(&LCM_DEV_S, values->bl1_2_area_info.offset,
                            sizeof(values->bl1_2), (uint8_t *)(&values->bl1_2));
    if (lcm_err != LCM_ERROR_NONE) {
        blob_handling_status_report_error(PROVISIONING_REPORT_STEP_BL1_2_PROVISIONING, lcm_err);
        return (enum tfm_plat_err_t)lcm_err;
    }
    blob_handling_status_report_continue(PROVISIONING_REPORT_STEP_BL1_2_PROVISIONING);

    INFO("Writing CM provisioning values\n");
    lcm_err = lcm_otp_write(&LCM_DEV_S, values->cm_area_info.offset,
                            sizeof(values->cm), (uint8_t *)(&values->cm));
    if (lcm_err != LCM_ERROR_NONE) {
        return (enum tfm_plat_err_t)lcm_err;
    }

    cc_err = cc3xx_lowlevel_rng_get_random((uint8_t *)generated_key_buf,
                                      sizeof(generated_key_buf),
                                      CC3XX_RNG_DRBG);
    if (cc_err != CC3XX_ERR_SUCCESS) {
        return (enum tfm_plat_err_t)cc_err;
    }

    INFO("Provisioning HUK\n");
    err = tfm_plat_otp_write(PLAT_OTP_ID_HUK,
                             sizeof(generated_key_buf), (uint8_t *)generated_key_buf);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return err;
    }

#ifdef RSE_CM_PROVISION_KCE_CM
    INFO("Provisioning KCE_CM\n");
    err = tfm_plat_otp_write(PLAT_OTP_ID_CM_CODE_ENCRYPTION_KEY,
                             sizeof(values->kce_cm),
                             values->kce_cm);
#else
    err = provision_derived_key(0, generated_key_buf,
                                (uint8_t *)"KCE_CM", sizeof("KCE_CM"), NULL, 0,
                                PLAT_OTP_ID_CM_CODE_ENCRYPTION_KEY, 32);
#endif
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return err;
    }

    blob_handling_status_report_continue(PROVISIONING_REPORT_STEP_CM_PROVISIONING);

    INFO("Transitioning to DM LCS\n");
    new_lcs = PLAT_OTP_LCS_PSA_ROT_PROVISIONING;
    err = tfm_plat_otp_write(PLAT_OTP_ID_LCS, sizeof(new_lcs),
                             (uint8_t *)&new_lcs);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return err;
    }

#ifndef RSE_COMBINED_PROVISIONING_BUNDLES
    blob_provisioning_finished();
#endif

    return err;
}
