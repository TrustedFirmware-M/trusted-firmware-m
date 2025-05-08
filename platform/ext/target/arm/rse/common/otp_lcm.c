/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <assert.h>

#include "lcm_drv.h"
#include "rse_otp_dev.h"
#include "tfm_plat_otp.h"
#include "tfm_hal_platform.h"
#include "fatal_error.h"
#include "rse_permanently_disable_device.h"
#include "rse_zero_count.h"

#ifdef RSE_ENCRYPTED_OTP_KEYS
#include "cc3xx_drv.h"
#endif

static const __ALIGNED(4) struct rse_otp_area_info_t lcm_hardware_area_info = {
    .offset = offsetof(struct rse_otp_header_area_t, lcm_hardware_area),
    .size = sizeof(struct lcm_otp_layout_t)
};

static const __ALIGNED(4) struct rse_otp_area_info_t header_area_info = {
    .offset = lcm_hardware_area_info.offset + lcm_hardware_area_info.size,
    .size = sizeof(struct rse_otp_header_area_t)
};

#ifdef RSE_OTP_HAS_CM_AREA
struct __ALIGNED(4) rse_otp_area_info_t cm_area_info = {0};
struct __ALIGNED(4) rse_otp_area_info_t cm_rotpk_area_info = {0};
#endif
#ifdef RSE_OTP_HAS_BL1_2
struct __ALIGNED(4) rse_otp_area_info_t bl1_2_area_info = {0};
#endif
#ifdef RSE_OTP_HAS_DM_AREA
struct __ALIGNED(4) rse_otp_area_info_t dm_area_info = {0};
struct __ALIGNED(4) rse_otp_area_info_t dm_rotpk_area_info = {0};
#endif
#ifdef RSE_OTP_HAS_DYNAMIC_AREA
struct __ALIGNED(4) rse_otp_area_info_t dynamic_area_info = {0};
#endif
#ifdef RSE_OTP_HAS_SOC_AREA
const struct __ALIGNED(4) rse_otp_area_info_t soc_area_info = {
    .offset = RSE_OTP_SIZE - sizeof(struct rse_otp_soc_area_t),
    .size = sizeof(struct rse_otp_soc_area_t),
};
#endif

#define OTP_MAPPING(item) \
    { \
        (struct rse_otp_area_info_t *)&lcm_hardware_area_info, \
        offsetof(struct lcm_otp_layout_t, item), \
        sizeof(((struct lcm_otp_layout_t *)(0))-> item), \
    }

#define HEADER_MAPPING(item) \
    { \
        (struct rse_otp_area_info_t *)&header_area_info, \
        offsetof(struct rse_otp_header_area_t, item) - sizeof(struct lcm_otp_layout_t), \
        sizeof(((struct rse_otp_header_area_t *)(0))-> item), \
    }

#define USER_AREA_MAPPING(area, item) \
    { \
        & area ## _area_info, \
        offsetof(struct rse_otp_ ## area ## _area_t, item), \
        sizeof(((struct rse_otp_ ## area ## _area_t *)(0)) -> item), \
    }

#define ENCRYPTED_USER_AREA_MAPPING(area, item, key) \
    { \
        & area ## _area_info, \
        offsetof(struct rse_otp_ ## area ## _area_t, item), \
        sizeof(((struct rse_otp_ ## area ## _area_t *)(0)) -> item), \
        true, \
        key, \
    }

#define ROTPK_AREA_MAPPING(cm_or_dm, item) \
    { \
        & cm_or_dm ## _rotpk_area_info, \
        offsetof(struct rse_otp_ ## cm_or_dm ## _rotpk_area_t, item), \
        sizeof(((struct rse_otp_ ## cm_or_dm ## _rotpk_area_t *)(0)) -> item), \
    }

struct otp_mapping_t{
    struct rse_otp_area_info_t *info;
    uint16_t offset;
    uint16_t size;
    bool is_encrypted;
    uint16_t key_id;
} otp_mapping[PLAT_OTP_ID_MAX] = {
    [PLAT_OTP_ID_HUK] = OTP_MAPPING(huk),
    [PLAT_OTP_ID_GUK] = OTP_MAPPING(guk),

#ifdef RSE_OTP_HAS_KRTL_USAGE_COUNTER
    [PLAT_OTP_ID_KRTL_USAGE_COUNTER] = HEADER_MAPPING(krtl_usage_counter),
#endif
#ifdef RSE_OTP_HAS_LFT_COUNTER
    [PLAT_OTP_ID_LFT_COUNTER] = HEADER_MAPPING(lft_counter),
#endif

    [PLAT_OTP_ID_CM_CONFIG_FLAGS] = USER_AREA_MAPPING(cm, config_flags),
    [PLAT_OTP_ID_DM_CONFIG_FLAGS] = USER_AREA_MAPPING(dm, config_flags),

    [PLAT_OTP_ID_CM_ROTPK_POLICIES] = ROTPK_AREA_MAPPING(cm, cm_rotpk_policies),
    [PLAT_OTP_ID_DM_ROTPK_POLICIES] = ROTPK_AREA_MAPPING(dm, dm_rotpk_policies),

    [PLAT_OTP_ID_BL1_2_IMAGE] = USER_AREA_MAPPING(bl1_2, bl1_2),
    [PLAT_OTP_ID_BL1_2_IMAGE_LEN] = USER_AREA_MAPPING(bl1_2, bl1_2_size),
    [PLAT_OTP_ID_BL1_2_IMAGE_HASH] = USER_AREA_MAPPING(bl1_2, bl1_2_hash),

    [PLAT_OTP_ID_REPROVISIONING_BITS] = USER_AREA_MAPPING(dynamic, cm_reprovisioning),
    [PLAT_OTP_ID_CM_ROTPK_REPROVISIONING] = USER_AREA_MAPPING(dynamic, cm_rotpk_revocation),
    [PLAT_OTP_ID_DM_ROTPK_REPROVISIONING] = USER_AREA_MAPPING(dynamic, dm_rotpk_revocation),

    [PLAT_OTP_ID_DMA_ICS] = HEADER_MAPPING(dma_ics),

    [PLAT_OTP_ID_CM_CODE_ENCRYPTION_KEY] = OTP_MAPPING(kce_cm),
    [PLAT_OTP_ID_CM_PROVISIONING_KEY] = OTP_MAPPING(kp_cm),

    [PLAT_OTP_ID_DM_CODE_ENCRYPTION_KEY] = OTP_MAPPING(kce_dm),
    [PLAT_OTP_ID_DM_PROVISIONING_KEY] = OTP_MAPPING(kp_dm),

    [PLAT_OTP_ID_DEVICE_STATUS] = HEADER_MAPPING(device_status),

#ifdef RSE_OTP_HAS_RSE_ID
    [PLAT_OTP_ID_RSE_ID] = USER_AREA_MAPPING(cm, rse_id),
#endif
#ifdef RSE_OTP_HAS_ROUTING_TABLES
    [PLAT_OTP_ID_RSE_TO_RSE_SENDER_ROUTING_TABLE] = USER_AREA_MAPPING(cm, rse_to_rse_sender_routing_table),
    [PLAT_OTP_ID_RSE_TO_RSE_RECEIVER_ROUTING_TABLE] = USER_AREA_MAPPING(cm, rse_to_rse_receiver_routing_table),
#endif
};

static enum tfm_plat_err_t get_bit_counter_counter_value(uint32_t *counter,
                                                         size_t counter_size,
                                                         uint32_t *value)
{
    enum tfm_plat_err_t err;
    uint32_t zero_count;

    err = rse_count_zero_bits((uint8_t*)counter, counter_size, &zero_count);

    *value = counter_size * 8 - zero_count;

    return err;
}

static enum tfm_plat_err_t otp_read(uint32_t offset, uint32_t len,
                                    uint32_t buf_len, uint8_t *buf)
{
    enum lcm_error_t lcm_err;

    if (buf_len < len) {
        len = buf_len;
    }

    lcm_err = lcm_otp_read(&LCM_DEV_S, offset, len, buf);
    if (lcm_err != LCM_ERROR_NONE) {
        return (enum tfm_plat_err_t)lcm_err;
    } else {
        return TFM_PLAT_ERR_SUCCESS;
    }
}

static enum tfm_plat_err_t otp_read_encrypted(uint32_t offset, uint32_t len,
                                              uint32_t buf_len, uint8_t *buf,
                                              enum kmu_hardware_keyslot_t key)
{
#ifndef RSE_ENCRYPTED_OTP_KEYS
    return otp_read(offset, len, buf_len, buf);
#else
    /* This is designed for keys, so 32 is a sane limit */
    uint32_t iv[4] = {offset, 0, 0, 0};
    cc3xx_err_t cc_err;

    if (buf_len < len) {
        len = buf_len;
    }

    cc_err = cc3xx_lowlevel_aes_init(CC3XX_AES_DIRECTION_DECRYPT, CC3XX_AES_MODE_CTR,
                                     (cc3xx_aes_key_id_t)key, NULL, CC3XX_AES_KEYSIZE_256,
                                     iv, sizeof(iv));
    if (cc_err != CC3XX_ERR_SUCCESS) {
        return (enum tfm_plat_err_t)cc_err;
    }

    cc3xx_lowlevel_aes_set_output_buffer(buf, buf_len);

    cc_err = cc3xx_lowlevel_aes_update((void *)(OTP_BASE_S + offset), len);
    if (cc_err != CC3XX_ERR_SUCCESS) {
        cc3xx_lowlevel_aes_uninit();
        return (enum tfm_plat_err_t)cc_err;
    }

    cc3xx_lowlevel_aes_finish(NULL, NULL);

    return TFM_PLAT_ERR_SUCCESS;
#endif
}

static enum tfm_plat_err_t otp_write(uint32_t offset, uint32_t len,
                                     uint32_t buf_len, const uint8_t *buf)
{
    enum lcm_error_t err;

    if (buf_len > len) {
        return TFM_PLAT_ERR_OTP_WRITE_INVALID_INPUT;
    }

    err = lcm_otp_write(&LCM_DEV_S, offset, buf_len, buf);
    if (err != LCM_ERROR_NONE) {
        return (enum tfm_plat_err_t)err;
    }

    return TFM_PLAT_ERR_SUCCESS;
}

static enum tfm_plat_err_t otp_write_encrypted(uint32_t offset, uint32_t len,
                                               uint32_t buf_len,
                                               const uint8_t *buf,
                                               enum kmu_hardware_keyslot_t key)
{
#ifndef RSE_ENCRYPTED_OTP_KEYS
    return otp_write(offset, len, buf_len, buf);
#else
    /* This is designed for keys, so 32 is a sane limit */
    uint32_t iv[4] = {offset, 0, 0, 0};
    cc3xx_err_t cc_err;

    cc_err = cc3xx_lowlevel_aes_init(CC3XX_AES_DIRECTION_ENCRYPT, CC3XX_AES_MODE_CTR,
                            (cc3xx_aes_key_id_t)key, NULL, CC3XX_AES_KEYSIZE_256,
                            iv, sizeof(iv));
    if (cc_err != CC3XX_ERR_SUCCESS) {
        return (enum tfm_plat_err_t)cc_err;
    }

    cc3xx_lowlevel_aes_set_output_buffer((void *)(OTP_BASE_S + offset), buf_len);

    cc_err = cc3xx_lowlevel_aes_update(buf, len);
    if (cc_err != CC3XX_ERR_SUCCESS) {
        cc3xx_lowlevel_aes_uninit();
        return (enum tfm_plat_err_t)cc_err;
    }

    cc3xx_lowlevel_aes_finish(NULL, NULL);

    return TFM_PLAT_ERR_SUCCESS;
#endif
}

static enum tfm_plat_err_t load_area_info(enum lcm_lcs_t lcs)
{
    uint32_t zero_count;
    enum tfm_plat_err_t err;

#ifdef RSE_OTP_HAS_SOC_AREA
    if (P_RSE_OTP_HEADER->soc_area_info.raw_data != soc_area_info.raw_data) {
        err = otp_write(OTP_OFFSET(P_RSE_OTP_HEADER->soc_area_info),
                  sizeof(P_RSE_OTP_HEADER->soc_area_info),
                  sizeof(soc_area_info), (uint8_t *)&soc_area_info);
        if (err != TFM_PLAT_ERR_SUCCESS) {
            return err;
        }

        err = rse_count_zero_bits((uint8_t *)&soc_area_info, sizeof(soc_area_info),
                                  &zero_count);
        if (err != TFM_PLAT_ERR_SUCCESS) {
            return err;
        }

        err = otp_write(OTP_OFFSET(P_RSE_OTP_HEADER->soc_area_info_zero_count),
                  sizeof(P_RSE_OTP_HEADER->soc_area_info_zero_count),
                  sizeof(zero_count), (uint8_t *)&zero_count);
        if (err != TFM_PLAT_ERR_SUCCESS) {
            return err;
        }
    }
#endif

    /* In CM mode, we don't have these provisioned
     */
    if (lcs == LCM_LCS_CM) {
        return TFM_PLAT_ERR_SUCCESS;
    }

#ifdef RSE_OTP_HAS_CM_AREA
    cm_area_info = P_RSE_OTP_HEADER->cm_area_info;

    err = rse_count_zero_bits((uint8_t *)&cm_area_info, sizeof(cm_area_info), &zero_count);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return err;
    }
    if (zero_count != P_RSE_OTP_HEADER->cm_area_info_zero_count) {
        FATAL_ERR(TFM_PLAT_ERR_OTP_INIT_CM_ZERO_COUNT_ERR);
        rse_permanently_disable_device(RSE_PERMANENT_ERROR_OTP_INTEGRITY_CHECK_FAILURE);
        return TFM_PLAT_ERR_OTP_INIT_CM_ZERO_COUNT_ERR;
    }
#endif

#ifdef RSE_OTP_HAS_BL1_2
    bl1_2_area_info = P_RSE_OTP_HEADER->bl1_2_area_info;

    err = rse_count_zero_bits((uint8_t *)&bl1_2_area_info, sizeof(bl1_2_area_info), &zero_count);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return err;
    }
    if (zero_count != P_RSE_OTP_HEADER->bl1_2_area_info_zero_count) {
        FATAL_ERR(TFM_PLAT_ERR_OTP_INIT_BL1_2_ZERO_COUNT_ERR);
        rse_permanently_disable_device(RSE_PERMANENT_ERROR_OTP_INTEGRITY_CHECK_FAILURE);
        return TFM_PLAT_ERR_OTP_INIT_BL1_2_ZERO_COUNT_ERR;
    }
#endif

#ifdef RSE_OTP_HAS_SOC_AREA
    err = rse_count_zero_bits((uint8_t *)&soc_area_info, sizeof(soc_area_info), &zero_count);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return err;
    }
    if (zero_count != P_RSE_OTP_HEADER->soc_area_info_zero_count) {
        FATAL_ERR(TFM_PLAT_ERR_OTP_INIT_SOC_ZERO_COUNT_ERR);
        rse_permanently_disable_device(RSE_PERMANENT_ERROR_OTP_INTEGRITY_CHECK_FAILURE);
        return TFM_PLAT_ERR_OTP_INIT_SOC_ZERO_COUNT_ERR;
    }
#endif

    /* If the DM is setting the size of the DM area then we don't know the size
     * of this (and the dynamic area) during the DM provisioning LCS, so don't
     * check them.
     */
#ifdef DM_SETS_DM_AND_DYNAMIC_AREA_SIZE
    if (lcs == LCM_LCS_DM) {
        return TFM_PLAT_ERR_SUCCESS;
    }
#endif

#ifdef RSE_OTP_HAS_DM_AREA
    dm_area_info = P_RSE_OTP_HEADER->dm_area_info;

    err = rse_count_zero_bits((uint8_t *)&dm_area_info, sizeof(dm_area_info), &zero_count);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return err;
    }
    if (zero_count != P_RSE_OTP_HEADER->dm_area_info_zero_count) {
        FATAL_ERR(TFM_PLAT_ERR_OTP_INIT_DM_ZERO_COUNT_ERR);
        rse_permanently_disable_device(RSE_PERMANENT_ERROR_OTP_INTEGRITY_CHECK_FAILURE);
        return TFM_PLAT_ERR_OTP_INIT_DM_ZERO_COUNT_ERR;
    }
#endif

#ifdef RSE_OTP_HAS_DYNAMIC_AREA
    dynamic_area_info = P_RSE_OTP_HEADER->dynamic_area_info;

    err = rse_count_zero_bits((uint8_t *)&dynamic_area_info, sizeof(dynamic_area_info), &zero_count);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return err;
    }
    if (zero_count != P_RSE_OTP_HEADER->dynamic_area_info_zero_count) {
        FATAL_ERR(TFM_PLAT_ERR_OTP_INIT_DYNAMIC_ZERO_COUNT_ERR);
        rse_permanently_disable_device(RSE_PERMANENT_ERROR_OTP_INTEGRITY_CHECK_FAILURE);
        return TFM_PLAT_ERR_OTP_INIT_DYNAMIC_ZERO_COUNT_ERR;
    }
#endif

    return TFM_PLAT_ERR_SUCCESS;
}

static enum tfm_plat_err_t setup_rotpk_info(enum lcm_lcs_t lcs) {
    enum tfm_plat_err_t err;
    uint32_t cm_rotpk_area_index;
    uint32_t dm_rotpk_area_index;

    if (lcs == LCM_LCS_CM) {
        return TFM_PLAT_ERR_SUCCESS;
    }

#ifdef RSE_OTP_DM_SETS_DM_AND_DYNAMIC_AREA_SIZE
    if (lcs == LCM_LCS_DM) {
        return TFM_PLAT_ERR_SUCCESS;
    }
#endif

    assert(IS_RSE_OTP_AREA_VALID(DYNAMIC));

#ifdef RSE_OTP_HAS_CM_AREA
#if RSE_OTP_CM_ROTPK_MAX_REVOCATIONS > 0
    err = get_bit_counter_counter_value((uint32_t *)P_RSE_OTP_DYNAMIC->cm_rotpk_revocation,
                                        sizeof(P_RSE_OTP_DYNAMIC->cm_rotpk_revocation),
                                        &cm_rotpk_area_index);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return err;
    }
#else
    cm_rotpk_area_index = 0;
#endif

    if (cm_rotpk_area_index >= RSE_OTP_CM_ROTPK_MAX_REVOCATIONS + 1) {
        FATAL_ERR(TFM_PLAT_ERR_OTP_INIT_CM_ROTPK_REPROVISIONING_COUNTER_EXCEEDED);
        rse_permanently_disable_device(RSE_PERMANENT_ERROR_ROTPK_REVOCATIONS_EXCEEDED);
        return TFM_PLAT_ERR_OTP_INIT_CM_ROTPK_REPROVISIONING_COUNTER_EXCEEDED;
    }

    cm_rotpk_area_info.offset = cm_area_info.offset + offsetof(struct rse_otp_cm_area_t, rotpk_areas)
                                + cm_rotpk_area_index * sizeof(struct rse_otp_cm_rotpk_area_t);
    cm_rotpk_area_info.size = sizeof(struct rse_otp_cm_rotpk_area_t);

    err = rse_check_zero_bit_count((uint8_t *)&P_RSE_OTP_CM_ROTPK->zero_count + sizeof(uint32_t),
                                   cm_rotpk_area_info.size - sizeof(uint32_t),
                                   P_RSE_OTP_CM_ROTPK->zero_count);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        cm_rotpk_area_info.raw_data = 0;
    } else {
        for (uint32_t idx = 0; idx < RSE_OTP_CM_ROTPK_AMOUNT; idx++) {
            struct otp_mapping_t mapping = ROTPK_AREA_MAPPING(cm, rotpk[idx]);

            otp_mapping[PLAT_OTP_ID_CM_ROTPK + idx] = mapping;
        }
    }
#endif

#ifdef RSE_OTP_HAS_DM_AREA
#if RSE_OTP_DM_ROTPK_MAX_REVOCATIONS > 0
    err = get_bit_counter_counter_value((uint32_t *)P_RSE_OTP_DYNAMIC->dm_rotpk_revocation,
                                        sizeof(P_RSE_OTP_DYNAMIC->dm_rotpk_revocation),
                                        &dm_rotpk_area_index);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return err;
    }
#else
    dm_rotpk_area_index = 0;
#endif

    if (dm_rotpk_area_index >= RSE_OTP_DM_ROTPK_MAX_REVOCATIONS + 1) {
        FATAL_ERR(TFM_PLAT_ERR_OTP_INIT_DM_ROTPK_REPROVISIONING_COUNTER_EXCEEDED);
        rse_permanently_disable_device(RSE_PERMANENT_ERROR_ROTPK_REVOCATIONS_EXCEEDED);
        return TFM_PLAT_ERR_OTP_INIT_DM_ROTPK_REPROVISIONING_COUNTER_EXCEEDED;
    }

    dm_rotpk_area_info.offset = dm_area_info.offset + offsetof(struct rse_otp_dm_area_t, rotpk_areas)
                                + dm_rotpk_area_index * sizeof(struct rse_otp_dm_rotpk_area_t);
    dm_rotpk_area_info.size = sizeof(struct rse_otp_dm_rotpk_area_t);

    err = rse_check_zero_bit_count(((uint8_t *)&P_RSE_OTP_DM_ROTPK->zero_count) + sizeof(uint32_t),
                                   dm_rotpk_area_info.size - sizeof(uint32_t),
                                   P_RSE_OTP_DM_ROTPK->zero_count);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        dm_rotpk_area_info.raw_data = 0;
    } else {
        for (uint32_t idx = 0; idx < RSE_OTP_DM_ROTPK_AMOUNT; idx++) {
            struct otp_mapping_t mapping = ROTPK_AREA_MAPPING(dm, rotpk[idx]);

            otp_mapping[PLAT_OTP_ID_DM_ROTPK + idx] = mapping;
        }
    }
#endif

    return TFM_PLAT_ERR_SUCCESS;
}

static void setup_nv_counter_info(void) {
    for (uint32_t idx = 0; idx < RSE_OTP_NV_COUNTERS_BANK_0_AMOUNT; idx++) {
        struct otp_mapping_t mapping =
            USER_AREA_MAPPING(dynamic, security_version_counters_bank_0[idx]);

        otp_mapping[PLAT_OTP_ID_NV_COUNTER_BANK_0_COUNTER + idx] = mapping;
    }

    for (uint32_t idx = 0; idx < RSE_OTP_NV_COUNTERS_BANK_1_AMOUNT; idx++) {
        struct otp_mapping_t mapping =
            USER_AREA_MAPPING(dynamic, security_version_counters_bank_1[idx]);

        otp_mapping[PLAT_OTP_ID_NV_COUNTER_BANK_1_COUNTER + idx] = mapping;
    }

    for (uint32_t idx = 0; idx < RSE_OTP_NV_COUNTERS_BANK_2_AMOUNT; idx++) {
        struct otp_mapping_t mapping =
            USER_AREA_MAPPING(dynamic, security_version_counters_bank_2[idx]);

        otp_mapping[PLAT_OTP_ID_NV_COUNTER_BANK_2_COUNTER + idx] = mapping;
    }

    for (uint32_t idx = 0; idx < RSE_OTP_NV_COUNTERS_BANK_3_AMOUNT; idx++) {
        struct otp_mapping_t mapping =
            USER_AREA_MAPPING(dynamic, security_version_counters_bank_3[idx]);

        otp_mapping[PLAT_OTP_ID_NV_COUNTER_BANK_3_COUNTER + idx] = mapping;
    }
}

static enum tfm_plat_err_t check_areas_for_tampering(enum lcm_lcs_t lcs)
{
    enum tfm_plat_err_t err;

    if (lcs == LCM_LCS_CM || lcs == LCM_LCS_RMA) {
        return TFM_PLAT_ERR_SUCCESS;
    }

#ifdef RSE_OTP_HAS_CM_AREA
    err = rse_check_zero_bit_count((uint8_t *)&P_RSE_OTP_CM->zero_count + sizeof(uint32_t),
                                   cm_area_info.size - sizeof(uint32_t) - sizeof(P_RSE_OTP_CM->rotpk_areas),
                                   P_RSE_OTP_CM->zero_count);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        rse_permanently_disable_device(RSE_PERMANENT_ERROR_OTP_INTEGRITY_CHECK_FAILURE);
        FATAL_ERR(TFM_PLAT_ERR_OTP_INIT_CM_ZERO_COUNT_ERR);
        return err;
    }
#endif

#ifdef RSE_OTP_HAS_BL1_2
    err = rse_check_zero_bit_count((uint8_t *)&P_RSE_OTP_BL1_2->zero_count + sizeof(uint32_t),
                                   bl1_2_area_info.size - sizeof(uint32_t),
                                   P_RSE_OTP_BL1_2->zero_count);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        rse_permanently_disable_device(RSE_PERMANENT_ERROR_OTP_INTEGRITY_CHECK_FAILURE);
        FATAL_ERR(TFM_PLAT_ERR_OTP_INIT_BL1_2_ZERO_COUNT_ERR);
        return err;
    }
#endif

#ifdef RSE_OTP_HAS_SOC_AREA
    err = rse_check_zero_bit_count((uint8_t *)&P_RSE_OTP_SOC->unique_id,
                                   sizeof(P_RSE_OTP_SOC->unique_id),
                                   P_RSE_OTP_SOC->zero_count);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        rse_permanently_disable_device(RSE_PERMANENT_ERROR_OTP_INTEGRITY_CHECK_FAILURE);
        FATAL_ERR(TFM_PLAT_ERR_OTP_INIT_SOC_ZERO_COUNT_ERR);
        return err;
    }
#endif

    /* If we are in DM LCS, don't check the DM area */
    if (lcs == LCM_LCS_DM) {
        return TFM_PLAT_ERR_SUCCESS;
    }

#ifdef RSE_OTP_HAS_DM_AREA
    err = rse_check_zero_bit_count((uint8_t *)&P_RSE_OTP_DM->zero_count + sizeof(uint32_t),
                                   dm_area_info.size - sizeof(uint32_t) - sizeof(P_RSE_OTP_DM->rotpk_areas),
                                   P_RSE_OTP_DM->zero_count);
    if ((err != TFM_PLAT_ERR_SUCCESS)
        && (P_RSE_OTP_DM->zero_count != 8 * sizeof(uint32_t))) {
        rse_permanently_disable_device(RSE_PERMANENT_ERROR_OTP_INTEGRITY_CHECK_FAILURE);
        FATAL_ERR(TFM_PLAT_ERR_OTP_INIT_DM_ZERO_COUNT_ERR);
        return err;
    }
#endif

    return TFM_PLAT_ERR_SUCCESS;
}

static enum lcm_lcs_t map_otp_lcs_to_lcm_lcs(enum plat_otp_lcs_t lcs)
{
    switch (lcs) {
    case PLAT_OTP_LCS_ASSEMBLY_AND_TEST:
        return LCM_LCS_CM;
    case PLAT_OTP_LCS_PSA_ROT_PROVISIONING:
        return LCM_LCS_DM;
    case PLAT_OTP_LCS_SECURED:
        return LCM_LCS_SE;
    case PLAT_OTP_LCS_DECOMMISSIONED:
        return LCM_LCS_RMA;
    default:
        return LCM_LCS_INVALID;
    }
}

static enum plat_otp_lcs_t map_lcm_lcs_to_otp_lcs(enum lcm_lcs_t lcs)
{
    switch (lcs) {
    case LCM_LCS_CM:
        return PLAT_OTP_LCS_ASSEMBLY_AND_TEST;
    case LCM_LCS_DM:
        return PLAT_OTP_LCS_PSA_ROT_PROVISIONING;
    case LCM_LCS_SE:
        return PLAT_OTP_LCS_SECURED;
    case LCM_LCS_RMA:
        return PLAT_OTP_LCS_DECOMMISSIONED;
    default:
        return PLAT_OTP_LCS_UNKNOWN;
    }
}

static enum tfm_plat_err_t otp_read_lcs(size_t out_len, uint8_t *out)
{
    enum lcm_error_t lcm_err;
    enum lcm_lcs_t lcm_lcs;
    enum plat_otp_lcs_t *lcs = (enum plat_otp_lcs_t*) out;

    lcm_err = lcm_get_lcs(&LCM_DEV_S, &lcm_lcs);
    if (lcm_err != LCM_ERROR_NONE) {
        return (enum tfm_plat_err_t)lcm_err;
    }

    if (out_len != sizeof(uint32_t)) {
        FATAL_ERR(TFM_PLAT_ERR_OTP_READ_LCS_INVALID_INPUT);
        return TFM_PLAT_ERR_OTP_READ_LCS_INVALID_INPUT;
    }

    *lcs = map_lcm_lcs_to_otp_lcs(lcm_lcs);

    return TFM_PLAT_ERR_SUCCESS;
}

static enum tfm_plat_err_t calc_write_zero_count(uintptr_t buf, size_t buf_len,
                                                 uintptr_t otp_zero_count_ptr)
{
    enum tfm_plat_err_t err;
    enum lcm_error_t lcm_err;
    uint32_t zero_count;

    err = rse_count_zero_bits((uint8_t *)buf, buf_len, &zero_count);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return err;
    }

    lcm_err = lcm_otp_write(&LCM_DEV_S, otp_zero_count_ptr - OTP_BASE_S, sizeof(zero_count),
                            (uint8_t *)&zero_count);
    if (lcm_err != LCM_ERROR_NONE) {
        return (enum tfm_plat_err_t)lcm_err;
    }

    return TFM_PLAT_ERR_SUCCESS;
}

static enum tfm_plat_err_t write_zero_counts(enum lcm_lcs_t new_lcs)
{
    enum tfm_plat_err_t err;
    enum lcm_lcs_t dm_dynamic_area_lcs;

    if (new_lcs == LCM_LCS_DM) {
#if defined(RSE_OTP_HAS_CM_AREA)
        err = calc_write_zero_count((uintptr_t)&P_RSE_OTP_HEADER->cm_area_info.raw_data,
                                    sizeof(P_RSE_OTP_HEADER->cm_area_info.raw_data),
                                    (uintptr_t)&P_RSE_OTP_HEADER->cm_area_info_zero_count);
        if (err != TFM_PLAT_ERR_SUCCESS) {
            return err;
        }

        cm_area_info.raw_data = P_RSE_OTP_HEADER->cm_area_info.raw_data;
        err = calc_write_zero_count((uintptr_t)&P_RSE_OTP_CM->zero_count + sizeof(uint32_t),
                                    cm_area_info.size - sizeof(uint32_t) -
                                        sizeof(P_RSE_OTP_CM->rotpk_areas),
                                    (uintptr_t)&P_RSE_OTP_CM->zero_count);
        if (err != TFM_PLAT_ERR_SUCCESS) {
            return err;
        }

        cm_rotpk_area_info.offset = cm_area_info.offset + offsetof(struct rse_otp_cm_area_t, rotpk_areas);
        cm_rotpk_area_info.size = sizeof(struct rse_otp_cm_rotpk_area_t);
        err = calc_write_zero_count((uintptr_t)&P_RSE_OTP_CM_ROTPK->zero_count + sizeof(uint32_t),
                                    cm_rotpk_area_info.size - sizeof(uint32_t),
                                    (uintptr_t)&P_RSE_OTP_CM_ROTPK->zero_count);
        if (err != TFM_PLAT_ERR_SUCCESS) {
            return err;
        }
#endif /* RSE_OTP_HAS_CM_AREA */

#if defined(RSE_OTP_HAS_BL1_2)
        err = calc_write_zero_count((uintptr_t)&P_RSE_OTP_HEADER->bl1_2_area_info.raw_data,
                                    sizeof(P_RSE_OTP_HEADER->bl1_2_area_info.raw_data),
                                    (uintptr_t)&P_RSE_OTP_HEADER->bl1_2_area_info_zero_count);
        if (err != TFM_PLAT_ERR_SUCCESS) {
            return err;
        }

        bl1_2_area_info.raw_data = P_RSE_OTP_HEADER->bl1_2_area_info.raw_data;
        err = calc_write_zero_count((uintptr_t)&P_RSE_OTP_BL1_2->zero_count + sizeof(uint32_t),
                                    bl1_2_area_info.size - sizeof(uint32_t),
                                    (uintptr_t)&P_RSE_OTP_BL1_2->zero_count);
        if (err != TFM_PLAT_ERR_SUCCESS) {
            return err;
        }
#endif /* RSE_OTP_HAS_BL1_2 */

#if defined(RSE_OTP_HAS_SOC_AREA)
        err = calc_write_zero_count((uintptr_t)&P_RSE_OTP_HEADER->soc_area_info.raw_data,
                                    sizeof(P_RSE_OTP_HEADER->soc_area_info.raw_data),
                                    (uintptr_t)&P_RSE_OTP_HEADER->soc_area_info_zero_count);
        if (err != TFM_PLAT_ERR_SUCCESS) {
            return err;
        }
#endif /* RSE_OTP_HAS_SOC_AREA */
    }

    /* If the DM is setting the size of the DM area then we don't know the size
     * of this (and the dynamic area) during the DM provisioning LCS, so don't
     * check them.
     */
#ifdef DM_SETS_DM_AND_DYNAMIC_AREA_SIZE
    dm_dynamic_area_lcs = LCM_LCS_SE;
#else
    dm_dynamic_area_lcs = LCM_LCS_DM;
#endif

    if (new_lcs == dm_dynamic_area_lcs) {
#if defined(RSE_OTP_HAS_DM_AREA)
        err = calc_write_zero_count((uintptr_t)&P_RSE_OTP_HEADER->dm_area_info.raw_data,
                                    sizeof(P_RSE_OTP_HEADER->dm_area_info.raw_data),
                                    (uintptr_t)&P_RSE_OTP_HEADER->dm_area_info_zero_count);
        if (err != TFM_PLAT_ERR_SUCCESS) {
            return err;
        }
#endif /* RSE_OTP_HAS_DM_AREA */

#if defined(RSE_OTP_HAS_DYNAMIC_AREA)
        err = calc_write_zero_count((uintptr_t)&P_RSE_OTP_HEADER->dynamic_area_info.raw_data,
                                    sizeof(P_RSE_OTP_HEADER->dynamic_area_info.raw_data),
                                    (uintptr_t)&P_RSE_OTP_HEADER->dynamic_area_info_zero_count);
        if (err != TFM_PLAT_ERR_SUCCESS) {
            return err;
        }

        dynamic_area_info.raw_data = P_RSE_OTP_HEADER->dynamic_area_info.raw_data;
#endif /* RSE_OTP_HAS_DYNAMIC_AREA */
    }


    if (new_lcs == LCM_LCS_SE) {
#if defined(RSE_OTP_HAS_DM_AREA)
        dm_area_info.raw_data = P_RSE_OTP_HEADER->dm_area_info.raw_data;
        err = calc_write_zero_count((uintptr_t)&P_RSE_OTP_DM->zero_count + sizeof(uint32_t),
                                    dm_area_info.size - sizeof(uint32_t) -
                                        sizeof(P_RSE_OTP_DM->rotpk_areas),
                                    (uintptr_t)&P_RSE_OTP_DM->zero_count);
        if (err != TFM_PLAT_ERR_SUCCESS) {
            return err;
        }

        dm_rotpk_area_info.offset = dm_area_info.offset + offsetof(struct rse_otp_dm_area_t, rotpk_areas);
        dm_rotpk_area_info.size = sizeof(struct rse_otp_dm_rotpk_area_t);
        err = calc_write_zero_count((uintptr_t)&P_RSE_OTP_DM_ROTPK->zero_count + sizeof(uint32_t),
                                    dm_rotpk_area_info.size - sizeof(uint32_t),
                                    (uintptr_t)&P_RSE_OTP_DM_ROTPK->zero_count);
        if (err != TFM_PLAT_ERR_SUCCESS) {
            return err;
        }
#endif /* RSE_OTP_HAS_DM_AREA */
    }

    return TFM_PLAT_ERR_SUCCESS;
}

static enum tfm_plat_err_t otp_write_lcs(size_t in_len, const uint8_t *in)
{
    enum tfm_plat_err_t err;
    enum lcm_error_t lcm_err;
    enum plat_otp_lcs_t new_lcs = *(enum plat_otp_lcs_t *)in;
    enum lcm_lcs_t lcm_lcs = map_otp_lcs_to_lcm_lcs(new_lcs);

    err = write_zero_counts(lcm_lcs);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return err;
    }

    lcm_err = lcm_set_lcs(&LCM_DEV_S, lcm_lcs, 0);

    return (enum tfm_plat_err_t)lcm_err;
}

#ifdef RSE_OTP_HAS_LFT_COUNTER
static enum tfm_plat_err_t check_lft_counter(enum lcm_lcs_t lcs) {
    enum tfm_plat_err_t plat_err;
    uint32_t counter_value;

    if (lcs == LCM_LCS_CM) {
        return TFM_PLAT_ERR_SUCCESS;
    }

    /* If the LFT counter should not cause bricking of the device we just return */
    if (!rse_otp_policy_check(P_RSE_OTP_CM->config_flags, CM_POLICIES_LFT_COUNTER_MAX_BRICKS_DEVICE)) {
        return TFM_PLAT_ERR_SUCCESS;
    }

    plat_err = get_bit_counter_counter_value((uint32_t *)P_RSE_OTP_HEADER->lft_counter,
                                             sizeof(P_RSE_OTP_HEADER->lft_counter),
                                             &counter_value);

    if (counter_value > RSE_OTP_LFT_COUNTER_MAX_VALUE) {
        FATAL_ERR(TFM_PLAT_ERR_OTP_INIT_LFT_COUNTER_EXCEEDED);
        rse_permanently_disable_device(RSE_PERMANENT_ERROR_LFT_COUNTER_LIMIT_EXCEEDED);
        return TFM_PLAT_ERR_OTP_INIT_LFT_COUNTER_EXCEEDED;
    }

    return TFM_PLAT_ERR_SUCCESS;
}
#endif /* RSE_OTP_HAS_LFT_COUNTER */

#ifdef RSE_OTP_HAS_KRTL_USAGE_COUNTER
static enum tfm_plat_err_t check_krtl_counter(void) {
    enum tfm_plat_err_t plat_err;
    uint32_t counter_value;

    plat_err = get_bit_counter_counter_value((uint32_t *)P_RSE_OTP_HEADER->krtl_usage_counter,
                                             sizeof(P_RSE_OTP_HEADER->krtl_usage_counter),
                                             &counter_value);

    if (counter_value > RSE_OTP_KRTL_COUNTER_MAX_VALUE) {
        FATAL_ERR(TFM_PLAT_ERR_OTP_INIT_KRTL_COUNTER_EXCEEDED);
        return TFM_PLAT_ERR_OTP_INIT_KRTL_COUNTER_EXCEEDED;
    }

    return TFM_PLAT_ERR_SUCCESS;
}
#endif /* RSE_OTP_HAS_KRTL_USAGE_COUNTER */

static enum tfm_plat_err_t check_device_status(void) {
    /* device_status[31:17] if non-zero describes a bricked device */
    if (P_RSE_OTP_HEADER->device_status >> 17 != 0) {
        FATAL_ERR(TFM_PLAT_ERR_OTP_INIT_INVALID_DEVICE_STATUS);
        return TFM_PLAT_ERR_OTP_INIT_INVALID_DEVICE_STATUS;
    }

    return TFM_PLAT_ERR_SUCCESS;
}

enum tfm_plat_err_t tfm_plat_otp_init(void)
{
    enum tfm_plat_err_t err;
    enum lcm_error_t lcm_err;
    enum lcm_lcs_t lcs;

    lcm_err = lcm_init(&LCM_DEV_S);
    if (lcm_err != LCM_ERROR_NONE) {
        return (enum tfm_plat_err_t)lcm_err;
    }

    lcm_err = lcm_get_lcs(&LCM_DEV_S, &lcs);
    if (lcm_err != LCM_ERROR_NONE) {
        return (enum tfm_plat_err_t)lcm_err;
    }

    /* Offsets and sizes for each zone are cached to avoid unnecessary OTP wear */
    err = load_area_info(lcs);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return err;
    }

    err = check_areas_for_tampering(lcs);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return err;
    }

    err = setup_rotpk_info(lcs);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return err;
    }

    setup_nv_counter_info();

#ifdef RSE_OTP_HAS_LFT_COUNTER
    err = check_lft_counter(lcs);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return err;
    }
#endif

#ifdef RSE_OTP_HAS_KRTL_USAGE_COUNTER
    err = check_krtl_counter();
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return err;
    }
#endif

    err = check_device_status();
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return err;
    }

    return TFM_PLAT_ERR_SUCCESS;
}

static inline bool otp_mapping_is_valid(enum tfm_otp_element_id_t id)
{
    return otp_mapping[id].size != 0;
}

static inline uint32_t otp_offset_from_mapping(enum tfm_otp_element_id_t id)
{
    struct otp_mapping_t mapping = otp_mapping[id];

    return mapping.info->offset + mapping.offset;
}

enum tfm_plat_err_t tfm_plat_otp_read(enum tfm_otp_element_id_t id,
                                      size_t out_len, uint8_t *out)
{
    if (out == NULL) {
        FATAL_ERR(TFM_PLAT_ERR_OTP_READ_INVALID_INPUT);
        return TFM_PLAT_ERR_OTP_READ_INVALID_INPUT;
    }

    if (id > PLAT_OTP_ID_MAX) {
        FATAL_ERR(TFM_PLAT_ERR_OTP_READ_INVALID_ID);
        return TFM_PLAT_ERR_OTP_READ_INVALID_ID;
    }

    switch (id) {
    case PLAT_OTP_ID_LCS:
        return otp_read_lcs(out_len, out);

    default:
        if (!otp_mapping_is_valid(id)) {
            FATAL_ERR(TFM_PLAT_ERR_OTP_ID_NOT_SET_UP);
            return TFM_PLAT_ERR_OTP_ID_NOT_SET_UP;
        }

        if (otp_mapping[id].is_encrypted) {
            return otp_read_encrypted(otp_offset_from_mapping(id),
                                      otp_mapping[id].size, out_len, out,
                                      otp_mapping[id].key_id);
        } else {
            return otp_read(otp_offset_from_mapping(id),
                            otp_mapping[id].size, out_len, out);
        }
    }
}

enum tfm_plat_err_t tfm_plat_otp_write(enum tfm_otp_element_id_t id,
                                       size_t in_len, const uint8_t *in)
{
    if (in == NULL) {
        FATAL_ERR(TFM_PLAT_ERR_OTP_WRITE_INVALID_INPUT);
        return TFM_PLAT_ERR_OTP_WRITE_INVALID_INPUT;
    }

    if (id > PLAT_OTP_ID_MAX) {
        FATAL_ERR(TFM_PLAT_ERR_OTP_WRITE_INVALID_ID);
        return TFM_PLAT_ERR_OTP_WRITE_INVALID_ID;
    }

    switch (id) {
    case PLAT_OTP_ID_LCS:
        return otp_write_lcs(in_len, in);

    default:
        if (!otp_mapping_is_valid(id)) {
            FATAL_ERR(TFM_PLAT_ERR_OTP_WRITE_ID_NOT_SET_UP);
            return TFM_PLAT_ERR_OTP_WRITE_ID_NOT_SET_UP;
        }

        if (otp_mapping[id].is_encrypted) {
            return otp_write_encrypted(otp_offset_from_mapping(id),
                                      otp_mapping[id].size, in_len, in,
                                      otp_mapping[id].key_id);
        } else {
            return otp_write(otp_offset_from_mapping(id),
                             otp_mapping[id].size, in_len, in);
        }
    }
}

enum tfm_plat_err_t tfm_plat_otp_get_size(enum tfm_otp_element_id_t id,
                                          size_t *size)
{

    if (id > PLAT_OTP_ID_MAX) {
        FATAL_ERR(TFM_PLAT_ERR_PLAT_OTP_GET_SIZE_INVALID_ID);
        return TFM_PLAT_ERR_PLAT_OTP_GET_SIZE_INVALID_ID;
    }

    if (!otp_mapping_is_valid(id)) {
        FATAL_ERR(TFM_PLAT_ERR_PLAT_OTP_GET_SIZE_ID_NOT_SET_UP);
        return TFM_PLAT_ERR_PLAT_OTP_GET_SIZE_ID_NOT_SET_UP;
    }

    *size = otp_mapping[id].size;

    return TFM_PLAT_ERR_SUCCESS;
}

enum tfm_plat_err_t tfm_plat_otp_secure_provisioning_start(void)
{
    enum lcm_bool_t sp_enabled;
    enum lcm_error_t lcm_err;

    lcm_err = lcm_get_sp_enabled(&LCM_DEV_S, &sp_enabled);
    if (lcm_err != LCM_ERROR_NONE) {
        return (enum tfm_plat_err_t)lcm_err;
    }

    if (sp_enabled != LCM_TRUE) {
        lcm_set_sp_enabled(&LCM_DEV_S);
    }

    return TFM_PLAT_ERR_SUCCESS;
}

enum tfm_plat_err_t tfm_plat_otp_secure_provisioning_finish(void)
{
    tfm_hal_system_reset();

    /* We'll never get here */
    return TFM_PLAT_ERR_SUCCESS;
}
