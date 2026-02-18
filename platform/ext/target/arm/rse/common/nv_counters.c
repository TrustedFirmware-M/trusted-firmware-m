/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

/* NOTE: For the security of the protected storage system, the bootloader
 * rollback protection, and the protection of cryptographic material  it is
 * CRITICAL to use a internal (in-die) persistent memory for the implementation
 * of the OTP_NV_COUNTERS flash area (see flash_otp_nv_layout.c).
 */

#include "tfm_plat_nv_counters.h"

#include "device_definition.h"
#include "tfm_plat_otp.h"
#include "psa_manifest/pid.h"

#include "rse_nv_counter_mapping.h"
#include "rse_otp_layout.h"
#include "rse_permanently_disable_device.h"
#include "rse_zero_count.h"

#include <limits.h>
#include <string.h>

#define MAX(x,y) ((x) > (y) ? (x) : (y))

#define OTP_COUNTER_MAX_SIZE    MAX(COUNTER_BYTES(RSE_OTP_NV_COUNTERS_BANK_0_MAX_VALUE), \
                                MAX(COUNTER_BYTES(RSE_OTP_NV_COUNTERS_BANK_1_MAX_VALUE), \
                                MAX(COUNTER_BYTES(RSE_OTP_NV_COUNTERS_BANK_2_MAX_VALUE), \
                                MAX(COUNTER_BYTES(RSE_OTP_NV_COUNTERS_BANK_3_MAX_VALUE), \
                                0))))


#define OTP_COUNTER_MAGIC       0x3333CAFE
#define NV_COUNTER_SIZE         sizeof(uint32_t)

enum tfm_plat_err_t tfm_plat_init_nv_counter(void)
{
    return TFM_PLAT_ERR_SUCCESS;
}

#ifdef RSE_BIT_PROGRAMMABLE_OTP
static enum tfm_plat_err_t read_otp_counter(enum tfm_otp_element_id_t id,
                                            uint8_t *val)
{
    size_t counter_size;
    enum tfm_plat_err_t err;
    uint32_t counter_value[OTP_COUNTER_MAX_SIZE / sizeof(uint32_t)] = {0};
    uint32_t count;

    err = tfm_plat_otp_get_size(id, &counter_size);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return err;
    }

    counter_size = counter_size > OTP_COUNTER_MAX_SIZE ? OTP_COUNTER_MAX_SIZE
                                                       : counter_size;

    err = tfm_plat_otp_read(id, counter_size, (uint8_t *)counter_value);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return err;
    }

    err = rse_count_zero_bits((uint8_t *)counter_value, counter_size, &count);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return err;
    }

    count = (counter_size * 8) - count;
    memcpy(val, &count, NV_COUNTER_SIZE);

    return TFM_PLAT_ERR_SUCCESS;
}
#else
static enum tfm_plat_err_t read_otp_counter(enum tfm_otp_element_id_t id,
                                            uint8_t *val)
{
    size_t counter_size;
    enum tfm_plat_err_t err;
    size_t idx;
    uint32_t counter_value[OTP_COUNTER_MAX_SIZE / sizeof(uint32_t)] = {0};
    uint32_t count;

    err = tfm_plat_otp_get_size(id, &counter_size);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return err;
    }

    counter_size = counter_size > OTP_COUNTER_MAX_SIZE ? OTP_COUNTER_MAX_SIZE
                                                       : counter_size;

    err = tfm_plat_otp_read(id, counter_size, (uint8_t *)counter_value);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return err;
    }

    count = 0;
    for (idx = 0; idx < counter_size / sizeof(uint32_t); idx++) {
        if (counter_value[idx] == OTP_COUNTER_MAGIC) {
            count += 1;
        } else if (counter_value[idx] == 0) {
            break;
        } else {
            return TFM_PLAT_ERR_READ_OTP_COUNTER_SYSTEM_ERR;
        }
    }

    memcpy(val, &count, NV_COUNTER_SIZE);

    return TFM_PLAT_ERR_SUCCESS;
}
#endif /* RSE_BIT_PROGRAMMABLE_OTP */

static enum tfm_plat_err_t get_otp_id(enum tfm_nv_counter_t counter_id,
                                      enum tfm_otp_element_id_t *otp_id)
{
    *otp_id = PLAT_OTP_ID_INVALID;

#if RSE_NV_COUNTER_BL1_AMOUNT > 0
    if (counter_id >= PLAT_NV_COUNTER_BL1_0 && counter_id < PLAT_NV_COUNTER_BL1_MAX) {
        *otp_id = rse_get_bl1_counter(counter_id - PLAT_NV_COUNTER_BL1_0);
    }
#endif /* RSE_NV_COUNTER_BL1_AMOUNT > 0 */

#if RSE_NV_COUNTER_BL2_AMOUNT > 0
    if (counter_id >= PLAT_NV_COUNTER_BL2_0 && counter_id < PLAT_NV_COUNTER_BL2_MAX) {
        *otp_id = rse_get_bl2_counter(counter_id - PLAT_NV_COUNTER_BL2_0);
    }
#endif /* RSE_NV_COUNTER_BL2_AMOUNT > 0 */

#ifdef TFM_PARTITION_PROTECTED_STORAGE
    if (counter_id >= PLAT_NV_COUNTER_PS_0 && counter_id <= PLAT_NV_COUNTER_PS_2) {
        *otp_id = rse_get_ps_counter(counter_id - PLAT_NV_COUNTER_PS_0);
    }
#endif /* TFM_PARTITION_PROTECTED_STORAGE */

#if RSE_NV_COUNTER_HOST_AMOUNT > 0
    if (counter_id >= PLAT_NV_COUNTER_HOST_0 && counter_id < PLAT_NV_COUNTER_HOST_MAX) {
        *otp_id = rse_get_host_counter(counter_id - PLAT_NV_COUNTER_HOST_0);
    }
#endif /* RSE_NV_COUNTER_HOST_AMOUNT > 0 */

#if RSE_NV_COUNTER_SUBPLATFORM_AMOUNT > 0
    if (counter_id >= PLAT_NV_COUNTER_SUBPLATFORM_0 && counter_id < PLAT_NV_COUNTER_SUBPLATFORM_MAX) {
        *otp_id = rse_get_subplatform_counter(counter_id - PLAT_NV_COUNTER_SUBPLATFORM_0);
    }
#endif /* RSE_NV_COUNTER_SUBPLATFORM_AMOUNT > 0 */

    if (counter_id == PLAT_NV_COUNTER_LFT) {
        *otp_id = PLAT_OTP_ID_LFT_COUNTER;
    }

    if (counter_id == PLAT_NV_COUNTER_KRTL_USAGE) {
        *otp_id = PLAT_OTP_ID_KRTL_USAGE_COUNTER;
    }

    if (counter_id == PLAT_NV_COUNTER_CM_ROTPK_REPROVISIONING) {
        *otp_id = PLAT_OTP_ID_CM_ROTPK_REPROVISIONING;
    }

    if (counter_id == PLAT_NV_COUNTER_DM_ROTPK_REPROVISIONING) {
        *otp_id = PLAT_OTP_ID_DM_ROTPK_REPROVISIONING;
    }

    if (*otp_id == PLAT_OTP_ID_INVALID) {
        return TFM_PLAT_ERR_READ_NV_COUNTER_UNSUPPORTED;
    }

    return TFM_PLAT_ERR_SUCCESS;
}

enum tfm_plat_err_t tfm_plat_read_nv_counter(enum tfm_nv_counter_t counter_id,
                                             uint32_t size, uint8_t *val)
{
    enum tfm_otp_element_id_t otp_id;
    enum tfm_plat_err_t err;

    if (size != NV_COUNTER_SIZE) {
        return TFM_PLAT_ERR_READ_NV_COUNTER_INVALID_COUNTER_SIZE;
    }

    err = get_otp_id(counter_id, &otp_id);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return err;
    }

    return read_otp_counter(otp_id, val);
}


#ifdef RSE_BIT_PROGRAMMABLE_OTP
static enum tfm_plat_err_t set_otp_counter(enum tfm_otp_element_id_t id,
                                           uint32_t val)
{
    size_t counter_size;
    enum tfm_plat_err_t err;
    size_t idx;
    uint32_t counter_value[OTP_COUNTER_MAX_SIZE / sizeof(uint32_t)] = {0};

    err = tfm_plat_otp_get_size(id, &counter_size);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return err;
    }

    counter_size = counter_size > OTP_COUNTER_MAX_SIZE ? OTP_COUNTER_MAX_SIZE
                                                       : counter_size;

    if (val > counter_size * 8) {
        rse_permanently_disable_device(RSE_PERMANENT_ERROR_SECURITY_COUNTER_EXCEEDED);
        return TFM_PLAT_ERR_SET_OTP_COUNTER_MAX_VALUE;
    }

    for (idx = 0; idx < val / 32; idx++) {
        counter_value[idx] = 0xFFFFFFFFu;
    }

    if (val % 32 != 0) {
        counter_value[idx] = (1 << (val % 32)) - 1;
    }

    err = tfm_plat_otp_write(id, counter_size,
                             (uint8_t *)counter_value);

    return err;
}
#else
static enum tfm_plat_err_t set_otp_counter(enum tfm_otp_element_id_t id,
                                           uint32_t val)
{
    size_t counter_size;
    enum tfm_plat_err_t err;
    size_t idx;
    uint32_t counter_value[OTP_COUNTER_MAX_SIZE / sizeof(uint32_t)] = {0};

    err = tfm_plat_otp_get_size(id, &counter_size);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return err;
    }

    counter_size = counter_size > OTP_COUNTER_MAX_SIZE ? OTP_COUNTER_MAX_SIZE
                                                       : counter_size;

    if (val > (counter_size / sizeof(uint32_t))) {
        rse_permanently_disable_device(RSE_PERMANENT_ERROR_SECURITY_COUNTER_EXCEEDED);
        return TFM_PLAT_ERR_SET_OTP_COUNTER_MAX_VALUE;
    }

    for (idx = 0; idx < val; idx++) {
        counter_value[idx] = OTP_COUNTER_MAGIC;
    }

    err = tfm_plat_otp_write(id, counter_size,
                             (uint8_t *)counter_value);

    return err;
}
#endif /* RSE_BIT_PROGRAMMABLE_OTP */

enum tfm_plat_err_t tfm_plat_set_nv_counter(enum tfm_nv_counter_t counter_id,
                                            uint32_t value)
{
    enum tfm_otp_element_id_t otp_id;
    enum tfm_plat_err_t err;

    err = get_otp_id(counter_id, &otp_id);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return err;
    }

    return set_otp_counter(otp_id, value);
}

enum tfm_plat_err_t tfm_plat_increment_nv_counter(
                                           enum tfm_nv_counter_t counter_id)
{
    uint32_t security_cnt;
    enum tfm_plat_err_t err;

    err = tfm_plat_read_nv_counter(counter_id,
                                   sizeof(security_cnt),
                                   (uint8_t *)&security_cnt);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return err;
    }

    return tfm_plat_set_nv_counter(counter_id, security_cnt + 1u);
}

enum tfm_plat_err_t tfm_plat_nv_counter_permissions_check(int32_t client_id,
                                                          enum tfm_nv_counter_t nv_counter_no,
                                                          bool is_read)
{
    (void)is_read;

#ifdef TFM_PARTITION_PROTECTED_STORAGE
    if (nv_counter_no >= PLAT_NV_COUNTER_PS_0 && nv_counter_no <= PLAT_NV_COUNTER_PS_2) {
        if (client_id == TFM_SP_PS) {
            return TFM_PLAT_ERR_SUCCESS;
        } else {
            return TFM_PLAT_ERR_UNSUPPORTED;
        }
    }
#endif /* TFM_PARTITION_PROTECTED_STORAGE */

    if (nv_counter_no >= PLAT_NV_COUNTER_HOST_0 && nv_counter_no < PLAT_NV_COUNTER_HOST_MAX) {
        /* TODO how does this interact with the ns_ctx extension? */
        if (client_id < 0) {
            return TFM_PLAT_ERR_SUCCESS;
        } else {
            return TFM_PLAT_ERR_UNSUPPORTED;
        }
    }

    return TFM_PLAT_ERR_UNSUPPORTED;
}

enum tfm_plat_err_t tfm_plat_ns_counter_idx_to_nv_counter(uint32_t ns_counter_idx,
                                                          enum tfm_nv_counter_t *counter_id)
{
    if ((ns_counter_idx >= RSE_NV_COUNTER_HOST_AMOUNT) || (counter_id == NULL)) {
        return TFM_PLAT_ERR_INVALID_INPUT;
    }

    *counter_id = PLAT_NV_COUNTER_HOST_0 + ns_counter_idx;

    return TFM_PLAT_ERR_SUCCESS;
}
