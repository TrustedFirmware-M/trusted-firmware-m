/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
#include "rse_test_common.h"

#include "tfm_plat_nv_counters.h"
#include "platform_nv_counters_ids.h"

/* find original defintion in nv_counter.c */
#define NV_COUNTER_SIZE sizeof(uint32_t)

struct test_nv_counter_info {
    const char *name;
    enum tfm_nv_counter_t id;

    uint32_t min;
    uint32_t max;
};

static struct test_nv_counter_info read_test_data[] = {
    { "BL1_0", PLAT_NV_COUNTER_BL1_0, 0, 8 },
    { "BL2_0", PLAT_NV_COUNTER_BL2_0, 0, 8 },
    { "LFT", PLAT_NV_COUNTER_LFT, 0, 256 },
    { "KRTL", PLAT_NV_COUNTER_KRTL_USAGE, 0, 64 },
    { "HOST_0", PLAT_NV_COUNTER_HOST_0, 0, 8 },
    { "CM_ROTPK_REPROVISIONING", PLAT_NV_COUNTER_CM_ROTPK_REPROVISIONING, 0, 8 },
    { "DM_ROTPK_REPROVISIONING", PLAT_NV_COUNTER_DM_ROTPK_REPROVISIONING, 0, 8 },
};
static const uint32_t read_test_data_len = ARRAY_SIZE(read_test_data);

static struct test_nv_counter_info write_test_data[] = {
    { "LFT", PLAT_NV_COUNTER_LFT, 0, 256 },
    { "KRTL", PLAT_NV_COUNTER_KRTL_USAGE, 0, 64 },
};
static const uint32_t write_test_data_len = ARRAY_SIZE(write_test_data);

static void test_common_nv_counter_init(struct test_result_t *ret)
{
    TEST_ASSERT(tfm_plat_init_nv_counter() == TFM_PLAT_ERR_SUCCESS,
                "Could not initialise NV COUNTERS");

    ret->val = TEST_PASSED;
}

static void test_common_nv_counter_unsupported_counter(struct test_result_t *ret)
{
    enum tfm_plat_err_t err;

    uint32_t value;

    err = tfm_plat_read_nv_counter(PLAT_NV_COUNTER_MAX, sizeof(value), (uint8_t *)&value);

    TEST_ASSERT(err == TFM_PLAT_ERR_READ_NV_COUNTER_UNSUPPORTED,
                "Failed un-supported counter check");

    ret->val = TEST_PASSED;
}

static void test_common_nv_counter_read(struct test_result_t *ret)
{
    enum tfm_plat_err_t err;

    uint32_t value;

    for (uint32_t i = 0; i < read_test_data_len; i++) {
        err = tfm_plat_read_nv_counter(read_test_data[i].id, sizeof(value), (uint8_t *)&value);

        TEST_FMT_ASSERT(err == TFM_PLAT_ERR_SUCCESS, " > counter: %s -- Failed read\r\n",
                        read_test_data[i].name);
    }

    ret->val = TEST_PASSED;
}

static void test_common_nv_counter_increment(struct test_result_t *ret)
{
    enum tfm_plat_err_t err;

    for (uint32_t i = 0; i < write_test_data_len; i++) {
        err = tfm_plat_increment_nv_counter(write_test_data[i].id);

        TEST_FMT_ASSERT(err == TFM_PLAT_ERR_SUCCESS, " > counter: %s -- Failed increment\r\n",
                        write_test_data[i].name);
    }

    ret->val = TEST_PASSED;
}

static void test_common_nv_counter_set(struct test_result_t *ret)
{
    enum tfm_plat_err_t err;

    uint32_t value;

    for (uint32_t i = 0; i < write_test_data_len; i++) {
        err = tfm_plat_read_nv_counter(write_test_data[i].id, sizeof(value), (uint8_t *)&value);

        TEST_FMT_ASSERT(err == TFM_PLAT_ERR_SUCCESS, " > counter: %s -- Failed read\r\n",
                        write_test_data[i].name);

        err = tfm_plat_set_nv_counter(write_test_data[i].id, value + 1);

        TEST_FMT_ASSERT(err == TFM_PLAT_ERR_SUCCESS, " > counter: %s | value=%d -- Failed set\r\n",
                        write_test_data[i].name, (write_test_data[i].max - 1));
    }

    ret->val = TEST_PASSED;
}

static void test_common_nv_counter_max_value(struct test_result_t *ret)
{
    enum tfm_plat_err_t err;

    uint32_t value = write_test_data[0].max * 8;

    err = tfm_plat_set_nv_counter(write_test_data[0].id, value + 1);

    TEST_ASSERT(err == TFM_PLAT_ERR_SET_OTP_COUNTER_MAX_VALUE, "Failed max counter check");

    ret->val = TEST_PASSED;
}

static void test_common_nv_counter_invalid_counter_size(struct test_result_t *ret)
{
    enum tfm_plat_err_t err;

    err = tfm_plat_read_nv_counter(write_test_data[0].id, 0, NULL);

    TEST_ASSERT(err == TFM_PLAT_ERR_READ_NV_COUNTER_INVALID_COUNTER_SIZE,
                "Failed invalid counter size check");

    ret->val = TEST_PASSED;
}

static struct conditional_test_t tests[] = {
    {
        .any_tp_mode = true,
        .any_sp_state = true,
        .any_lcs = true,
        .test = {
            &test_common_nv_counter_init,
            "NV_COUNTER_TEST_0001",
            "Check NV Counter initialisation"
        },
    },
    {
        .any_tp_mode = true,
        .any_sp_state = true,
        .any_lcs = true,
        .test = {
            &test_common_nv_counter_init,
            "NV_COUNTER_TEST_0001",
            "Check NV Counter initialisation"
        },
    },
    {
        .any_tp_mode = true,
        .any_sp_state = true,
        .any_lcs = true,
        .test = {
            &test_common_nv_counter_read,
            "NV_COUNTER_TEST_0002",
            "Check NV Counter read"
        },
    },
    {
        .any_tp_mode = true,
        .any_sp_state = true,
        .any_lcs = true,
        .test = {
            &test_common_nv_counter_increment,
            "NV_COUNTER_TEST_0003",
            "Check NV Counter increment"
        },
    },
    {
        .any_tp_mode = true,
        .any_sp_state = true,
        .any_lcs = true,
        .test = {
            &test_common_nv_counter_set,
            "NV_COUNTER_TEST_0004",
            "Check NV Counter set"
        },
    },
    {
        .any_tp_mode = true,
        .any_sp_state = true,
        .any_lcs = true,
        .test = {
            &test_common_nv_counter_unsupported_counter,
            "NV_COUNTER_TEST_0006",
            "Check NV Counter unsupported counter check"
        },
    },
    {
        .any_tp_mode = true,
        .any_sp_state = true,
        .any_lcs = true,
        .test = {
            &test_common_nv_counter_invalid_counter_size,
            "NV_COUNTER_TEST_0007",
            "Check NV Counter invalid counter size check"
        },
    },
    {
        .any_tp_mode = true,
        .any_sp_state = true,
        .lcs = LCM_LCS_RMA,
        .test = {
            &test_common_nv_counter_max_value,
            "NV_COUNTER_TEST_0008",
            "Check NV Counter max value check"
        },
    },
};

void add_common_nv_counter_tests(struct test_suite_t *p_ts, uint32_t ts_size)
{
    add_conditional_tests_to_testsuite(tests, ARRAY_SIZE(tests), p_ts, ts_size);
}
