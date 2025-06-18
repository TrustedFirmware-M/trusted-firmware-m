/*
 * Copyright (c) 2024, Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "unity.h"

#include "platform_nv_counters_ids.h"
#include "platform_otp_ids.h"
#include "tfm_plat_defs.h"
#include "tfm_plat_nv_counters.h"

#include "mock_tfm_plat_otp.h"

void test_init_nv_counter(void)
{
    TEST_ASSERT_EQUAL(TFM_PLAT_ERR_SUCCESS, tfm_plat_init_nv_counter());
}

static enum tfm_otp_element_id_t
otpid_from_counterid(enum tfm_nv_counter_t id)
{

    switch (id) {
    case (PLAT_NV_COUNTER_PS_0):
        return PLAT_OTP_ID_NV_COUNTER_PS_0;
    case (PLAT_NV_COUNTER_PS_1):
        return PLAT_OTP_ID_NV_COUNTER_PS_1;
    case (PLAT_NV_COUNTER_PS_2):
        return PLAT_OTP_ID_NV_COUNTER_PS_2;
    case (PLAT_NV_COUNTER_NS_0):
        return PLAT_OTP_ID_NV_COUNTER_NS_0;
    case (PLAT_NV_COUNTER_NS_1):
        return PLAT_OTP_ID_NV_COUNTER_NS_1;
    case (PLAT_NV_COUNTER_NS_2):
        return PLAT_OTP_ID_NV_COUNTER_NS_2;
    case (PLAT_NV_COUNTER_BL1_0):
        return PLAT_OTP_ID_NV_COUNTER_BL1_0;
    case (PLAT_NV_COUNTER_ATTACK_TRACKING):
        return PLAT_OTP_ID_ATTACK_TRACKING_BITS;
    case (PLAT_NV_COUNTER_BL2_0):
        return PLAT_OTP_ID_NV_COUNTER_BL2_0;
    case (PLAT_NV_COUNTER_BL2_1):
        return PLAT_OTP_ID_NV_COUNTER_BL2_1;
    case (PLAT_NV_COUNTER_BL2_2):
        return PLAT_OTP_ID_NV_COUNTER_BL2_2;
    case (PLAT_NV_COUNTER_BL2_3):
        return PLAT_OTP_ID_NV_COUNTER_BL2_3;
    default:
        TEST_FAIL_MESSAGE("Invalid ID");
    }

    TEST_ABORT();
    __builtin_unreachable();
}

TEST_MATRIX(
    [
        PLAT_NV_COUNTER_PS_0,
        PLAT_NV_COUNTER_PS_1,
        PLAT_NV_COUNTER_PS_2,
        PLAT_NV_COUNTER_BL2_0,
        PLAT_NV_COUNTER_BL1_0,
        PLAT_NV_COUNTER_MAX,
        PLAT_NV_COUNTER_BOUNDARY,
    ],
    [ 0, 3, 9, 16, 32, 48, 4 ])
void test_tfm_plat_read_otp_counter(enum tfm_nv_counter_t id, uint32_t size)
{
    /* Prepare */
    enum tfm_plat_err_t aerr, eerr;
    size_t sz = 16;
    uint8_t val[4];
    eerr = size != 4 ? TFM_PLAT_ERR_READ_NV_COUNTER_INVALID_COUNTER_SIZE
           : id >= PLAT_NV_COUNTER_MAX
               ? TFM_PLAT_ERR_READ_NV_COUNTER_UNSUPPORTED
               : TFM_PLAT_ERR_SUCCESS;
    if (eerr == TFM_PLAT_ERR_SUCCESS) {
        tfm_plat_otp_get_size_ExpectAndReturn(otpid_from_counterid(id), NULL,
                                              TFM_PLAT_ERR_SUCCESS);
        tfm_plat_otp_get_size_IgnoreArg_size();
        tfm_plat_otp_get_size_ReturnThruPtr_size(&sz);
        tfm_plat_otp_read_ExpectAndReturn(otpid_from_counterid(id), sz, NULL,
                                          TFM_PLAT_ERR_SUCCESS);
        tfm_plat_otp_read_IgnoreArg_out();
    }

    /* Act */
    aerr = tfm_plat_read_nv_counter(id, size, val);

    /* Assert */

    TEST_ASSERT_EQUAL(eerr, aerr);
}

void test_tfm_read_nvc_fail_get_otp_size(void)
{
    /* Prepare */
    enum tfm_plat_err_t aerr;
    tfm_plat_otp_get_size_ExpectAndReturn(
        otpid_from_counterid(PLAT_NV_COUNTER_BL1_0), NULL,
        TFM_PLAT_ERR_UNSUPPORTED);
    tfm_plat_otp_get_size_IgnoreArg_size();

    /* Act */
    aerr = tfm_plat_read_nv_counter(PLAT_NV_COUNTER_BL1_0, 4, NULL);

    /* Assert */

    TEST_ASSERT_EQUAL(TFM_PLAT_ERR_UNSUPPORTED, aerr);
}

void test_tfm_read_invalid_nvc(void)
{

#ifndef RSE_BIT_PROGRAMMABLE_OTP
    enum tfm_plat_err_t aerr;
    size_t sz = 16;
    uint32_t counter_value[4] = {
        0x3333CAFE,
        0xdeadbeef,
        0x3333CAFE,
        0x3333CAFE,
    };
    uint32_t security_cnt;
    tfm_plat_otp_get_size_ExpectAndReturn(
        otpid_from_counterid(PLAT_NV_COUNTER_BL1_0), NULL,
        TFM_PLAT_ERR_SUCCESS);
    tfm_plat_otp_get_size_IgnoreArg_size();
    tfm_plat_otp_get_size_ReturnThruPtr_size(&sz);
    tfm_plat_otp_read_ExpectAndReturn(PLAT_OTP_ID_NV_COUNTER_BL1_0, sz, NULL,
                                      TFM_PLAT_ERR_SUCCESS);
    tfm_plat_otp_read_IgnoreArg_out();
    tfm_plat_otp_read_ReturnMemThruPtr_out((uint8_t *)counter_value, 0x40);

    /* Act */
    aerr = tfm_plat_read_nv_counter(PLAT_NV_COUNTER_BL1_0, 4,
                                    (uint8_t *)&security_cnt);

    /* Assert */

    TEST_ASSERT_EQUAL(TFM_PLAT_ERR_READ_OTP_COUNTER_SYSTEM_ERR, aerr);
#endif /* RSE_BIT_PROGRAMMABLE_OTP */
}

TEST_MATRIX(
    [
        PLAT_NV_COUNTER_PS_0,
        PLAT_NV_COUNTER_PS_1,
        PLAT_NV_COUNTER_PS_2,
        PLAT_NV_COUNTER_BL2_0,
        PLAT_NV_COUNTER_BL1_0,
        PLAT_NV_COUNTER_MAX,
        PLAT_NV_COUNTER_BOUNDARY,
    ],
    [ 0, 3, 9, 16, 32, 48, 4 ])
void test_tfm_set_nv_counter(enum tfm_nv_counter_t id, uint32_t val)
{
    /* Prepare */
    enum tfm_plat_err_t aerr, eerr;
    size_t sz = 16;
    eerr = id >= PLAT_NV_COUNTER_MAX ?
    TFM_PLAT_ERR_SET_NV_COUNTER_UNSUPPORTED
                                     : TFM_PLAT_ERR_SUCCESS;
    if (eerr == TFM_PLAT_ERR_SUCCESS) {
        tfm_plat_otp_get_size_ExpectAndReturn(otpid_from_counterid(id), NULL,
                                              TFM_PLAT_ERR_SUCCESS);
        tfm_plat_otp_get_size_IgnoreArg_size();
        tfm_plat_otp_get_size_ReturnThruPtr_size(&sz);
#ifdef RSE_BIT_PROGRAMMABLE_OTP
        if (val > (sz*8)) {
#else
        if (val > (sz/4)) {
#endif
            eerr = TFM_PLAT_ERR_SET_OTP_COUNTER_MAX_VALUE;
        } else {
            tfm_plat_otp_write_ExpectAndReturn(otpid_from_counterid(id),
            0x10,
                                               NULL, TFM_PLAT_ERR_SUCCESS);
            tfm_plat_otp_write_IgnoreArg_in();
        }
    }

    /* Act */
    aerr = tfm_plat_set_nv_counter(id, val);

    /* Assert */

    TEST_ASSERT_EQUAL(eerr, aerr);
}

void test_tfm_set_nvc_fail_get_otp_size(void)
{
    /* Prepare */
    enum tfm_plat_err_t aerr;
    tfm_plat_otp_get_size_ExpectAndReturn(
        otpid_from_counterid(PLAT_NV_COUNTER_BL1_0), NULL,
        TFM_PLAT_ERR_UNSUPPORTED);
    tfm_plat_otp_get_size_IgnoreArg_size();

    /* Act */
    aerr = tfm_plat_set_nv_counter(PLAT_NV_COUNTER_BL1_0, 200);

    /* Assert */

    TEST_ASSERT_EQUAL(TFM_PLAT_ERR_UNSUPPORTED, aerr);
}

void test_tfm_increment_nvc_readfail(void)
{

    enum tfm_plat_err_t aerr;
    tfm_plat_otp_get_size_ExpectAndReturn(
        otpid_from_counterid(PLAT_NV_COUNTER_BL1_0), NULL,
        TFM_PLAT_ERR_UNSUPPORTED);
    tfm_plat_otp_get_size_IgnoreArg_size();

    /* Act */
    aerr = tfm_plat_increment_nv_counter(PLAT_NV_COUNTER_BL1_0);

    /* Assert */

    TEST_ASSERT_EQUAL(TFM_PLAT_ERR_UNSUPPORTED, aerr);
}

void test_tfm_increment_nvc_writefail(void)
{

    enum tfm_plat_err_t aerr;
    size_t sz = 16;
    tfm_plat_otp_get_size_ExpectAndReturn(
        otpid_from_counterid(PLAT_NV_COUNTER_BL1_0), NULL,
        TFM_PLAT_ERR_SUCCESS);
    tfm_plat_otp_get_size_IgnoreArg_size();
    tfm_plat_otp_get_size_ReturnThruPtr_size(&sz);
    tfm_plat_otp_read_ExpectAndReturn(PLAT_OTP_ID_NV_COUNTER_BL1_0, sz, NULL,
                                      TFM_PLAT_ERR_SUCCESS);
    tfm_plat_otp_read_IgnoreArg_out();
    tfm_plat_otp_get_size_ExpectAndReturn(
        otpid_from_counterid(PLAT_NV_COUNTER_BL1_0), NULL,
        TFM_PLAT_ERR_UNSUPPORTED);
    tfm_plat_otp_get_size_IgnoreArg_size();

    /* Act */
    aerr = tfm_plat_increment_nv_counter(PLAT_NV_COUNTER_BL1_0);

    /* Assert */

    TEST_ASSERT_EQUAL(TFM_PLAT_ERR_UNSUPPORTED, aerr);
}

void test_tfm_increment_nvc_max(void)
{

    enum tfm_plat_err_t aerr;
    size_t sz = 16;
    uint32_t counter_value[16] = {
#ifdef RSE_BIT_PROGRAMMABLE_OTP
        0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
        0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
        0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
#else
        0x3333CAFE,
        0x3333CAFE,
        0x3333CAFE,
        0x3333CAFE,
#endif /* RSE_BIT_PROGRAMMABLE_OTP */
    };
    tfm_plat_otp_get_size_ExpectAndReturn(
        otpid_from_counterid(PLAT_NV_COUNTER_BL1_0), NULL,
        TFM_PLAT_ERR_SUCCESS);
    tfm_plat_otp_get_size_IgnoreArg_size();
    tfm_plat_otp_get_size_ReturnThruPtr_size(&sz);
    tfm_plat_otp_read_ExpectAndReturn(PLAT_OTP_ID_NV_COUNTER_BL1_0, sz, NULL,
                                      TFM_PLAT_ERR_SUCCESS);
    tfm_plat_otp_read_IgnoreArg_out();
    tfm_plat_otp_read_ReturnMemThruPtr_out((uint8_t *)counter_value, 0x40);
    tfm_plat_otp_get_size_ExpectAndReturn(
        otpid_from_counterid(PLAT_NV_COUNTER_BL1_0), NULL,
        TFM_PLAT_ERR_SUCCESS);
    tfm_plat_otp_get_size_IgnoreArg_size();
    tfm_plat_otp_get_size_ReturnThruPtr_size(&sz);

    /* Act */
    aerr = tfm_plat_increment_nv_counter(PLAT_NV_COUNTER_BL1_0);

    /* Assert */

    TEST_ASSERT_EQUAL(TFM_PLAT_ERR_SET_OTP_COUNTER_MAX_VALUE, aerr);
}

void test_tfm_increment_nvc_ok(void)
{

    enum tfm_plat_err_t aerr;
    size_t sz = 16;
    tfm_plat_otp_get_size_ExpectAndReturn(
        otpid_from_counterid(PLAT_NV_COUNTER_BL1_0), NULL,
        TFM_PLAT_ERR_SUCCESS);
    tfm_plat_otp_get_size_IgnoreArg_size();
    tfm_plat_otp_get_size_ReturnThruPtr_size(&sz);
    tfm_plat_otp_read_ExpectAndReturn(PLAT_OTP_ID_NV_COUNTER_BL1_0, sz, NULL,
                                      TFM_PLAT_ERR_SUCCESS);
    tfm_plat_otp_read_IgnoreArg_out();

    tfm_plat_otp_get_size_ExpectAndReturn(
        otpid_from_counterid(PLAT_NV_COUNTER_BL1_0), NULL,
        TFM_PLAT_ERR_UNSUPPORTED);
    tfm_plat_otp_get_size_IgnoreArg_size();

    /* Act */
    aerr = tfm_plat_increment_nv_counter(PLAT_NV_COUNTER_BL1_0);

    /* Assert */

    TEST_ASSERT_EQUAL(TFM_PLAT_ERR_UNSUPPORTED, aerr);
}
