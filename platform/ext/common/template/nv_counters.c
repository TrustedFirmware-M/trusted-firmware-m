/*
 * Copyright (c) 2018-2022, Arm Limited. All rights reserved.
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
#include <string.h>
#include <limits.h>
#include "Driver_Flash.h"
#include "flash_layout.h"
#include "tfm_plat_otp.h"
#include "cmsis_compiler.h"
#ifdef TFM_PARTITION_PROTECTED_STORAGE
#include "flash_otp_nv_counters_backend.h"
#endif
#include "psa_manifest/pid.h"

#define OTP_COUNTER_MAX_SIZE    128u
#define NV_COUNTER_SIZE         4

#ifdef TFM_PARTITION_PROTECTED_STORAGE
enum flash_nv_counter_id_t {
    FLASH_NV_COUNTER_ID_PS_0 = 0,
    FLASH_NV_COUNTER_ID_PS_1,
    FLASH_NV_COUNTER_ID_PS_2,
    FLASH_NV_COUNTER_ID_MAX,
};
#endif

enum tfm_plat_err_t tfm_plat_init_nv_counter(void)
{
#ifdef TFM_PARTITION_PROTECTED_STORAGE
    if (FLASH_NV_COUNTER_ID_MAX > FLASH_NV_COUNTER_AM) {
        return TFM_PLAT_ERR_SYSTEM_ERR;
    }

    return init_otp_nv_counters_flash();
#else
    return TFM_PLAT_ERR_SUCCESS;
#endif
}

#if defined(BL2) || defined(BL1)
static enum tfm_plat_err_t read_nv_counter_otp(enum tfm_otp_element_id_t id,
                                               uint32_t size, uint8_t *val)
{
    size_t counter_size;
    enum tfm_plat_err_t err;
    size_t byte_idx;
    uint8_t bit_idx;
    uint8_t counter_value[OTP_COUNTER_MAX_SIZE];
    uint32_t count;

    err = tfm_plat_otp_get_size(id, &counter_size);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return err;
    }

    counter_size = (counter_size > OTP_COUNTER_MAX_SIZE) ? OTP_COUNTER_MAX_SIZE : counter_size;

    err = tfm_plat_otp_read(id, counter_size, counter_value);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return err;
    }

    count = 0;
    for (byte_idx = 0; byte_idx < counter_size; byte_idx++) {
        for (bit_idx = 0; bit_idx < 8; bit_idx++) {
            count += (counter_value[byte_idx] >> bit_idx) & 1;
        }
    }

    memcpy(val, &count, NV_COUNTER_SIZE);

    return TFM_PLAT_ERR_SUCCESS;
}
#endif /* BL2 || BL1 */

#ifdef TFM_PARTITION_PROTECTED_STORAGE
static enum tfm_plat_err_t read_nv_counter_flash(enum flash_nv_counter_id_t counter_id,
                                                 uint32_t size, uint8_t *val)
{
    enum tfm_plat_err_t err = TFM_PLAT_ERR_SUCCESS;

    if (size != NV_COUNTER_SIZE) {
        return TFM_PLAT_ERR_INVALID_INPUT;
    }

    err = read_otp_nv_counters_flash(offsetof(struct flash_otp_nv_counters_region_t,
                                              flash_nv_counters)
                                     + counter_id * sizeof(uint32_t),
                                     val, size);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return err;
    }

    return TFM_PLAT_ERR_SUCCESS;
}
#endif /* TFM_PARTITION_PROTECTED_STORAGE */

enum tfm_plat_err_t tfm_plat_read_nv_counter(enum tfm_nv_counter_t counter_id,
                                             uint32_t size, uint8_t *val)
{
    if (size != NV_COUNTER_SIZE) {
        return TFM_PLAT_ERR_SYSTEM_ERR;
    }

    switch(counter_id) {
#ifdef TFM_PARTITION_PROTECTED_STORAGE
    case (PLAT_NV_COUNTER_PS_0):
        return read_nv_counter_flash(FLASH_NV_COUNTER_ID_PS_0, size, val);
    case (PLAT_NV_COUNTER_PS_1):
        return read_nv_counter_flash(FLASH_NV_COUNTER_ID_PS_1, size, val);
    case (PLAT_NV_COUNTER_PS_2):
        return read_nv_counter_flash(FLASH_NV_COUNTER_ID_PS_2, size, val);
#endif /* TFM_PARTITION_PROTECTED_STORAGE */

#ifdef BL2
    case (PLAT_NV_COUNTER_BL2_0):
        return read_nv_counter_otp(PLAT_OTP_ID_NV_COUNTER_BL2_0, size, val);
    case (PLAT_NV_COUNTER_BL2_1):
        return read_nv_counter_otp(PLAT_OTP_ID_NV_COUNTER_BL2_1, size, val);
    case (PLAT_NV_COUNTER_BL2_2):
        return read_nv_counter_otp(PLAT_OTP_ID_NV_COUNTER_BL2_2, size, val);
    case (PLAT_NV_COUNTER_BL2_3):
        return read_nv_counter_otp(PLAT_OTP_ID_NV_COUNTER_BL2_3, size, val);
#endif /* BL2 */

#if defined(BL1) && defined(PLATFORM_DEFAULT_BL1)
    case (PLAT_NV_COUNTER_BL1_0):
        return read_nv_counter_otp(PLAT_OTP_ID_NV_COUNTER_BL1_0, size, val);
#endif /* BL1 && PLATFORM_DEFAULT_BL1 */

#if (PLATFORM_NS_NV_COUNTERS > 0)
    case (PLAT_NV_COUNTER_NS_0):
        return read_nv_counter_otp(PLAT_OTP_ID_NV_COUNTER_NS_0, size, val);
#endif
#if (PLATFORM_NS_NV_COUNTERS > 1)
    case (PLAT_NV_COUNTER_NS_1):
        return read_nv_counter_otp(PLAT_OTP_ID_NV_COUNTER_NS_1, size, val);
#endif
#if (PLATFORM_NS_NV_COUNTERS > 2)
    case (PLAT_NV_COUNTER_NS_2):
        return read_nv_counter_otp(PLAT_OTP_ID_NV_COUNTER_NS_2, size, val);
#endif

    default:
        return TFM_PLAT_ERR_UNSUPPORTED;
    }
}

#if defined(BL2) || defined(BL1)
static enum tfm_plat_err_t set_nv_counter_otp(enum tfm_otp_element_id_t id,
                                              uint32_t value)
{
    size_t counter_size;
    enum tfm_plat_err_t err;
    size_t byte_idx;
    uint8_t counter_value[OTP_COUNTER_MAX_SIZE];

    err = tfm_plat_otp_get_size(id, &counter_size);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return err;
    }

    counter_size = (counter_size > OTP_COUNTER_MAX_SIZE) ? OTP_COUNTER_MAX_SIZE : counter_size;

    if (value > (8 * counter_size)) {
        return TFM_PLAT_ERR_MAX_VALUE;
    }

    memset(counter_value, 0, OTP_COUNTER_MAX_SIZE);
    for (byte_idx = 0; byte_idx < (value / 8); byte_idx++) {
        counter_value[byte_idx] = UINT8_MAX;
    }
    counter_value[byte_idx] = (1 << (value % 8)) - 1;

    err = tfm_plat_otp_write(id, counter_size, counter_value);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return err;
    }

    return TFM_PLAT_ERR_SUCCESS;
}
#endif /* BL2 || BL1 */

#ifdef TFM_PARTITION_PROTECTED_STORAGE
static enum tfm_plat_err_t set_nv_counter_flash(enum flash_nv_counter_id_t counter_id,
                                                uint32_t value)
{
    enum tfm_plat_err_t err = TFM_PLAT_ERR_SUCCESS;
    uint32_t counter_value;

    err = read_otp_nv_counters_flash(offsetof(struct flash_otp_nv_counters_region_t,
                                              flash_nv_counters)
                                     + counter_id * sizeof(uint32_t),
                                     &counter_value, sizeof(counter_value));
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return err;
    }

    if (counter_value == UINT32_MAX) {
        return TFM_PLAT_ERR_MAX_VALUE;
    }

    if (counter_value > value) {
        return TFM_PLAT_ERR_INVALID_INPUT;
    }

    counter_value = value;

    err = write_otp_nv_counters_flash(offsetof(struct flash_otp_nv_counters_region_t,
                                               flash_nv_counters)
                                      + counter_id * sizeof(uint32_t),
                                      &counter_value, sizeof(counter_value));
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return err;
    }

    return TFM_PLAT_ERR_SUCCESS;
}
#endif /* TFM_PARTITION_PROTECTED_STORAGE */

enum tfm_plat_err_t tfm_plat_set_nv_counter(enum tfm_nv_counter_t counter_id,
                                            uint32_t value)
{
    uint32_t new_value;
    enum tfm_plat_err_t err;

    switch(counter_id) {
#ifdef TFM_PARTITION_PROTECTED_STORAGE
    case (PLAT_NV_COUNTER_PS_0):
        err = set_nv_counter_flash(FLASH_NV_COUNTER_ID_PS_0, value);
        break;
    case (PLAT_NV_COUNTER_PS_1):
        err = set_nv_counter_flash(FLASH_NV_COUNTER_ID_PS_1, value);
        break;
    case (PLAT_NV_COUNTER_PS_2):
        err = set_nv_counter_flash(FLASH_NV_COUNTER_ID_PS_2, value);
        break;
#endif /* TFM_PARTITION_PROTECTED_STORAGE */

#ifdef BL2
    case (PLAT_NV_COUNTER_BL2_0):
        err = set_nv_counter_otp(PLAT_OTP_ID_NV_COUNTER_BL2_0, value);
        break;
    case (PLAT_NV_COUNTER_BL2_1):
        err = set_nv_counter_otp(PLAT_OTP_ID_NV_COUNTER_BL2_1, value);
        break;
    case (PLAT_NV_COUNTER_BL2_2):
        err = set_nv_counter_otp(PLAT_OTP_ID_NV_COUNTER_BL2_2, value);
        break;
    case (PLAT_NV_COUNTER_BL2_3):
        err = set_nv_counter_otp(PLAT_OTP_ID_NV_COUNTER_BL2_3, value);
        break;
#endif /* BL2 */

#if defined(BL1) && defined(PLATFORM_DEFAULT_BL1)
    case (PLAT_NV_COUNTER_BL1_0):
        err = set_nv_counter_otp(PLAT_OTP_ID_NV_COUNTER_BL1_0, value);
        break;
#endif /* BL1 && PLATFORM_DEFAULT_BL1 */

#if (PLATFORM_NS_NV_COUNTERS > 0)
    case (PLAT_NV_COUNTER_NS_0):
        err = set_nv_counter_otp(PLAT_OTP_ID_NV_COUNTER_NS_0, value);
        break;
#endif
#if (PLATFORM_NS_NV_COUNTERS > 1)
    case (PLAT_NV_COUNTER_NS_1):
        err = set_nv_counter_otp(PLAT_OTP_ID_NV_COUNTER_NS_1, value);
        break;
#endif
#if (PLATFORM_NS_NV_COUNTERS > 2)
    case (PLAT_NV_COUNTER_NS_2):
        err = set_nv_counter_otp(PLAT_OTP_ID_NV_COUNTER_NS_2, value);
        break;
#endif

    default:
        return TFM_PLAT_ERR_UNSUPPORTED;
    }
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return err;
    }

    /* Check that the NV counter write hasn't failed (in case the driver doesn't
     * have a check.
     */
    err = tfm_plat_read_nv_counter(counter_id, sizeof(new_value),
                                   (uint8_t *)&new_value);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return err;
    }

    if(new_value != value) {
        return TFM_PLAT_ERR_SYSTEM_ERR;
    }

    return TFM_PLAT_ERR_SUCCESS;
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

    if (security_cnt == UINT32_MAX) {
        return TFM_PLAT_ERR_MAX_VALUE;
    }

    return tfm_plat_set_nv_counter(counter_id, security_cnt + 1u);
}

enum tfm_plat_err_t tfm_plat_nv_counter_permissions_check(int32_t client_id,
                                                          enum tfm_nv_counter_t nv_counter_no,
                                                          bool is_read)
{
    (void)is_read;

    switch (nv_counter_no) {
#ifdef TFM_PARTITION_PROTECTED_STORAGE
    case PLAT_NV_COUNTER_PS_0:
    case PLAT_NV_COUNTER_PS_1:
    case PLAT_NV_COUNTER_PS_2:
        if (client_id == TFM_SP_PS) {
            return TFM_PLAT_ERR_SUCCESS;
        } else {
            return TFM_PLAT_ERR_UNSUPPORTED;
        }
#endif /* TFM_PARTITION_PROTECTED_STORAGE */
    case PLAT_NV_COUNTER_NS_0:
    case PLAT_NV_COUNTER_NS_1:
    case PLAT_NV_COUNTER_NS_2:
        /* TODO how does this interact with the ns_ctx extension? */
        if (client_id < 0) {
            return TFM_PLAT_ERR_SUCCESS;
        } else {
            return TFM_PLAT_ERR_UNSUPPORTED;
        }
    default:
        return TFM_PLAT_ERR_UNSUPPORTED;
    }
}

enum tfm_plat_err_t tfm_plat_ns_counter_idx_to_nv_counter(uint32_t ns_counter_idx,
                                                          enum tfm_nv_counter_t *counter_id)
{
    /* Default NV counters only have PLAT_NV_COUNTERS_NS_0, _1 and _2 */
    if ((ns_counter_idx > 2) || (counter_id == NULL)) {
        return TFM_PLAT_ERR_INVALID_INPUT;
    }

    *counter_id = PLAT_NV_COUNTER_NS_0 + ns_counter_idx;

    return TFM_PLAT_ERR_SUCCESS;
}
