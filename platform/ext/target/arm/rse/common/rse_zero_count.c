/*
 * SPDX-License-Identifier: BSD-3-Clause
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 */


#include "rse_zero_count.h"

#include "device_definition.h"
#include "platform_base_address.h"
#include "fatal_error.h"
#include "rse_otp_dev.h"

static uint32_t calc_value_zero_count(uint32_t val, size_t size)
{
    uint32_t zero_bits = 0;

    for (uint32_t bit_index = 0; bit_index < size * 8; bit_index++) {
        zero_bits += 1 - ((val >> bit_index) & 1);
    }

    return zero_bits;
}

static uint32_t calc_uint8_zero_count(uint32_t val)
{
    return calc_value_zero_count(val, sizeof(uint8_t));
}

static uint32_t calc_uint32_zero_count(uint32_t val)
{
    return calc_value_zero_count(val, sizeof(uint32_t));
}

static enum tfm_plat_err_t software_zero_count_compute(uint8_t *buf, size_t buf_len,
                                                       uint32_t *zero_count)
{
    if ((zero_count == NULL) || ((buf_len > 0) && (buf == NULL))) {
        return TFM_PLAT_ERR_ZERO_COUNT_INVALID_ARGUMENT;
    }

    *zero_count = 0;

#ifdef RSE_ZERO_COUNT_STRICT_ALIGNMENT
    while (buf_len & (sizeof(uint32_t) - 1)) {
        *zero_count += calc_uint8_zero_count(*buf);
        buf_len -= 1;
        buf += 1;
    }
#endif

    while (buf_len >= sizeof(uint32_t)) {
        *zero_count += calc_uint32_zero_count(*((uint32_t *)buf));
        buf_len -= sizeof(uint32_t);
        buf += sizeof(uint32_t);
    }

    while (buf_len > 0) {
        *zero_count += calc_uint8_zero_count(*buf);
        buf_len -= 1;
        buf += 1;
    }

    return TFM_PLAT_ERR_SUCCESS;
}

static enum tfm_plat_err_t software_zero_count_check(uint8_t *buf, size_t buf_len,
                                                       uint32_t expected_zero_count)
{
    uint32_t zero_count;
    enum tfm_plat_err_t err;

    err = software_zero_count_compute(buf, buf_len, &zero_count);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return err;
    }

    if (zero_count == expected_zero_count) {
        return TFM_PLAT_ERR_SUCCESS;
    } else {
        NONFATAL_ERR(TFM_PLAT_ERR_ZERO_COUNT_MISMATCH);
        return TFM_PLAT_ERR_ZERO_COUNT_MISMATCH;
    }
}

#ifdef INTEGRITY_CHECKER_S
static bool is_in_sram(uintptr_t buf)
{
    return (((buf > VM0_BASE_S) && (buf < VM0_BASE_S + VM0_SIZE + VM1_SIZE))
         || ((buf > VM0_BASE_NS) && (buf < VM0_BASE_NS + VM0_SIZE + VM1_SIZE)));
}

static bool is_in_tcm(uintptr_t buf)
{
    return (((buf > DTCM_BASE_S) && (buf < DTCM_BASE_S + DTCM_SIZE))
         || ((buf > DTCM_BASE_NS) && (buf < DTCM_BASE_NS + DTCM_SIZE))
         || ((buf > ITCM_BASE_S) && (buf < ITCM_BASE_S + ITCM_SIZE))
         || ((buf > ITCM_BASE_NS) && (buf < ITCM_BASE_NS + ITCM_SIZE)));
}

static bool is_in_otp(uintptr_t buf)
{
    return ((buf > OTP_BASE_S) && (buf < OTP_BASE_S + RSE_OTP_SIZE));
}

static bool is_aligned(uintptr_t buf)
{
    return (buf & (INTEGRITY_CHECKER_REQUIRED_ALIGNMENT - 1)) == 0;
}
#endif

enum tfm_plat_err_t rse_count_zero_bits(uint8_t *buf, size_t buf_len,
                                        uint32_t *zero_count)
{
#ifdef INTEGRITY_CHECKER_S
    if (is_aligned((uintptr_t)buf) && is_aligned(buf_len) &&
        (is_in_sram((uintptr_t)buf) || is_in_tcm((uintptr_t)buf) || is_in_otp((uintptr_t)buf))) {
        return (enum tfm_plat_err_t)integrity_checker_compute_value(&INTEGRITY_CHECKER_DEV_S,
                                                                    INTEGRITY_CHECKER_MODE_ZERO_COUNT,
                                                                    (uint32_t *)buf, buf_len,
                                                                    zero_count, sizeof(uint32_t), NULL);
    }
#endif

    return software_zero_count_compute(buf, buf_len, zero_count);
}

enum tfm_plat_err_t rse_check_zero_bit_count(uint8_t *buf, size_t buf_len,
                                             uint32_t expected_zero_count)
{
#ifdef INTEGRITY_CHECKER_S
    if (is_aligned((uintptr_t)buf) && is_aligned(buf_len) &&
        (is_in_sram((uintptr_t)buf) || is_in_tcm((uintptr_t)buf) || is_in_otp((uintptr_t)buf))) {
        return (enum tfm_plat_err_t)integrity_checker_check_value(&INTEGRITY_CHECKER_DEV_S,
                                                                  INTEGRITY_CHECKER_MODE_ZERO_COUNT,
                                                                  (uint32_t *)buf, buf_len,
                                                                  &expected_zero_count, sizeof(expected_zero_count));
    }
#endif

    return software_zero_count_check(buf, buf_len, expected_zero_count);
}

