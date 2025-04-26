/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
#include "bl1_random.h"
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
#include "tfm_plat_nv_counters.h"

/* Non secret provisioning values are placed directly after the
 * blob code DATA section */
extern uint32_t Image$$DATA$$Limit[];

#ifndef RSE_COMBINED_PROVISIONING_BUNDLES
static const struct rse_non_secret_cm_provisioning_values_t *values =
    (const struct rse_non_secret_cm_provisioning_values_t *)Image$$DATA$$Limit;

static const struct rse_secret_cm_provisioning_values_t *secret_values =
    (const struct rse_secret_cm_provisioning_values_t *)PROVISIONING_BUNDLE_VALUES_START;

/* This is a stub to make the linker happy */
void __Vectors(){}
#else
static const struct rse_non_secret_cm_provisioning_values_t *values =
    &((const struct rse_non_secret_combined_provisioning_values_t *)Image$$DATA$$Limit)->cm;

static const struct rse_secret_cm_provisioning_values_t *secret_values =
    &((const struct rse_secret_combined_provisioning_values_t *)PROVISIONING_BUNDLE_VALUES_START)->cm;
#endif /* RSE_COMBINED_PROVISIONING_BUNDLES */

/*
 * The maximum possible value for the KRTL usage counter is 64. As per the current CC3XX
 * driver implementation, a key derivation reads from KRTL three times per derivation.
 * This define sets the acceptable number of derivations using KRTL to 2, i.e. sets the upper
 * limit of usages to 6 (2 x 3 reads each). And any CM provisoning on a chip with more than
 * this acceptable limit should raise an error. Platforms can override this value.
 *
 * Ideally, CM provisioning should be done on a chip with KRTL usage as zero.
 */
#ifndef RSE_ACCEPTABLE_MAX_KRTL_USAGE_VALUE
#define RSE_ACCEPTABLE_MAX_KRTL_USAGE_VALUE (6)
#endif /* RSE_ACCEPTABLE_MAX_KRTL_USAGE_VALUE */

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
    bl1_random_generate_fast((uint8_t *)key_buf, key_size);

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
    uint32_t zero_count;
    uint32_t krtl_usage_counter;

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

    /* Check the KRTL usage counter value against the acceptable range */
    err = tfm_plat_read_nv_counter(PLAT_NV_COUNTER_KRTL_USAGE,
                                   sizeof(krtl_usage_counter),
                                   (uint8_t *)&krtl_usage_counter);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return err;
    }

    if (krtl_usage_counter > RSE_ACCEPTABLE_MAX_KRTL_USAGE_VALUE) {
        ERROR("KRTL Usage counter %d above the limit of %d\r\n",
                krtl_usage_counter, RSE_ACCEPTABLE_MAX_KRTL_USAGE_VALUE);
        return TFM_PLAT_ERR_SET_OTP_COUNTER_MAX_VALUE;
    } else if (krtl_usage_counter > 0) {
        WARN("KTRL Usage counter expected to be 0, but read as %d", krtl_usage_counter);
    }

    INFO("Provisioning GUK\n");
#ifdef RSE_CM_PROVISION_GUK
    err = tfm_plat_otp_write(PLAT_OTP_ID_GUK,
                             sizeof(secret_values->guk),
                             secret_values->guk);
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
                             sizeof(secret_values->kp_cm),
                             secret_values->kp_cm);
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
        message_handling_status_report_error(PROVISIONING_REPORT_STEP_BL1_2_PROVISIONING, lcm_err);
        return (enum tfm_plat_err_t)lcm_err;
    }
    message_handling_status_report_continue(PROVISIONING_REPORT_STEP_BL1_2_PROVISIONING);

    INFO("Writing CM provisioning values\n");
    lcm_err = lcm_otp_write(&LCM_DEV_S, values->cm_area_info.offset,
                            sizeof(values->cm), (uint8_t *)(&values->cm));
    if (lcm_err != LCM_ERROR_NONE) {
        return (enum tfm_plat_err_t)lcm_err;
    }

    err = bl1_random_generate_secure((uint8_t *)generated_key_buf,
                                        sizeof(generated_key_buf));
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return err;
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
                             sizeof(secret_values->kce_cm),
                             secret_values->kce_cm);
#else
    err = provision_derived_key(0, generated_key_buf,
                                (uint8_t *)"KCE_CM", sizeof("KCE_CM"), NULL, 0,
                                PLAT_OTP_ID_CM_CODE_ENCRYPTION_KEY, 32);
#endif
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return err;
    }

    message_handling_status_report_continue(PROVISIONING_REPORT_STEP_CM_PROVISIONING);

    INFO("Transitioning to DM LCS\n");
    new_lcs = PLAT_OTP_LCS_PSA_ROT_PROVISIONING;
    err = tfm_plat_otp_write(PLAT_OTP_ID_LCS, sizeof(new_lcs),
                             (uint8_t *)&new_lcs);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return err;
    }

#ifndef RSE_COMBINED_PROVISIONING_BUNDLES
    message_provisioning_finished(PROVISIONING_REPORT_STEP_RUN_BLOB);
#endif

    return err;
}
