/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

/* framework headers */
#include "rse_test_common.h"

/* device header */
#include "device_definition.h"
#include "integrity_checker_drv.h"

#define TEST_VALUE { 7, 8 }

static void test_natdrv_compute_value_zero_count(struct test_result_t *ret)
{
    enum integrity_checker_error_t err;

    /* define input and output buffers */
    uint32_t output;
    uint64_t input[2] = TEST_VALUE;

    /* compute the output buffers */
    err = integrity_checker_compute_value(&INTEGRITY_CHECKER_DEV_S, INTEGRITY_CHECKER_MODE_ZERO_COUNT,
                                          (const uint32_t *) input, sizeof(input),
                                                           &output, sizeof(output), NULL);
    if (err == INTEGRITY_CHECKER_ERROR_UNSUPPORTED_MODE) {
        ret->val = TEST_SKIPPED;
        return;
    }

    TEST_ASSERT(err == INTEGRITY_CHECKER_ERROR_NONE, "Could not compute value for ZERO_COUNT mode");

    /* check with expected value */
    err = integrity_checker_check_value(&INTEGRITY_CHECKER_DEV_S, INTEGRITY_CHECKER_MODE_ZERO_COUNT,
                                        (const uint32_t *) input, sizeof(input),
                                                         &output, sizeof(output));
    /* explicitly check for the comparison failure */
    TEST_ASSERT(err != INTEGRITY_CHECKER_ERROR_CHECK_VALUE_COMPARISON_FAILED, "Failed integrity check");
    TEST_ASSERT(err == INTEGRITY_CHECKER_ERROR_NONE, "Could not check value for ZERO_COUNT mode");

    ret->val = TEST_PASSED;
}

static void test_natdrv_compute_value_crc32(struct test_result_t *ret)
{
    enum integrity_checker_error_t err;

    /* define input and output buffers */
    uint32_t output;
    uint64_t input[2] = TEST_VALUE;

    /* compute the output */
    err = integrity_checker_compute_value(&INTEGRITY_CHECKER_DEV_S, INTEGRITY_CHECKER_MODE_CRC32,
                                          (const uint32_t *) input, sizeof(input),
                                                           &output, sizeof(output), NULL);
    if (err == INTEGRITY_CHECKER_ERROR_UNSUPPORTED_MODE) {
        ret->val = TEST_SKIPPED;
        return;
    }
    TEST_ASSERT(err == INTEGRITY_CHECKER_ERROR_NONE, "Could not compute value for CRC32 mode");

    /* check with expected value */
    err = integrity_checker_check_value(&INTEGRITY_CHECKER_DEV_S, INTEGRITY_CHECKER_MODE_CRC32,
                                        (const uint32_t *) input, sizeof(input),
                                                         &output, sizeof(output));
    /* explicitly check for the comparison failure */
    TEST_ASSERT(err != INTEGRITY_CHECKER_ERROR_CHECK_VALUE_COMPARISON_FAILED, "Failed integrity check");
    TEST_ASSERT(err == INTEGRITY_CHECKER_ERROR_NONE, "Could not check value for CRC32 mode");


    ret->val = TEST_PASSED;
}

static void test_natdrv_compute_value_sha256(struct test_result_t *ret)
{
    enum integrity_checker_error_t err;

    /* define input and output buffers */
    uint32_t output;
    uint64_t input[2] = TEST_VALUE;

    /* compute the output */
    err = integrity_checker_compute_value(&INTEGRITY_CHECKER_DEV_S, INTEGRITY_CHECKER_MODE_SHA256,
                                          (const uint32_t *) input, sizeof(input),
                                                           &output, sizeof(output), NULL);
    if (err == INTEGRITY_CHECKER_ERROR_UNSUPPORTED_MODE) {
        ret->val = TEST_SKIPPED;
        return;
    }
    TEST_ASSERT(err == INTEGRITY_CHECKER_ERROR_NONE, "Could not compute value for SHA256 mode");

    /* check with expected value */
    err = integrity_checker_check_value(&INTEGRITY_CHECKER_DEV_S, INTEGRITY_CHECKER_MODE_SHA256,
                                        (const uint32_t *) input, sizeof(input),
                                                         &output, sizeof(output));
    /* explicitly check for the comparison failure */
    TEST_ASSERT(err != INTEGRITY_CHECKER_ERROR_CHECK_VALUE_COMPARISON_FAILED, "Failed integrity check");
    TEST_ASSERT(err == INTEGRITY_CHECKER_ERROR_NONE, "Could not check value for SHA256 mode");

    ret->val = TEST_PASSED;
}

static void test_natdrv_compute_value_input_buffer_too_small(struct test_result_t *ret)
{
    enum integrity_checker_error_t err;

    /* define input and output buffers */
    uint32_t output;
    uint64_t input[2] = TEST_VALUE;

    /* test input length too small */
    err = integrity_checker_compute_value(&INTEGRITY_CHECKER_DEV_S, INTEGRITY_CHECKER_MODE_ZERO_COUNT,
                                          (const uint32_t *) input, sizeof(input),
                                                           &output, 0,
                                          NULL);
    TEST_ASSERT(err == INTEGRITY_CHECKER_ERROR_COMPUTE_VALUE_BUFFER_TOO_SMALL, "Failed compute buffer size check");

    /* check with expected value */
    err = integrity_checker_check_value(&INTEGRITY_CHECKER_DEV_S, INTEGRITY_CHECKER_MODE_ZERO_COUNT,
                                        (const uint32_t *) input, sizeof(input),
                                                         &output, 0);
    TEST_ASSERT(err == INTEGRITY_CHECKER_ERROR_CHECK_VALUE_BUFFER_TOO_SMALL, "Failed compute buffer size check");

    ret->val = TEST_PASSED;
}

static void test_natdrv_compute_value_input_buffer_alignment(struct test_result_t *ret)
{
    enum integrity_checker_error_t err;

    /* define input and output buffers */
    uint32_t output;
    uint64_t input[2] = TEST_VALUE;

    /* test input alignment invalid */
    uint32_t input_align_fail;
    err = integrity_checker_compute_value(&INTEGRITY_CHECKER_DEV_S, INTEGRITY_CHECKER_MODE_ZERO_COUNT,
                                          &input_align_fail,  sizeof(input),
                                          &output,            sizeof(output), NULL);
    TEST_ASSERT(err == INTEGRITY_CHECKER_ERROR_COMPUTE_VALUE_INVALID_ALIGNMENT, "Failed compute input data alignment check");

    err = integrity_checker_compute_value(&INTEGRITY_CHECKER_DEV_S, INTEGRITY_CHECKER_MODE_ZERO_COUNT,
                                          (const uint32_t *) input, 9,
                                                           &output, sizeof(output), NULL);
    TEST_ASSERT(err == INTEGRITY_CHECKER_ERROR_COMPUTE_VALUE_INVALID_LENGTH, "Failed compute input data length check");

    ret->val = TEST_PASSED;
}

static struct conditional_test_t tests[] =
{
    {
        .any_tp_mode  = true,
        .any_sp_state = true,
        .any_lcs      = true,
        .test         = {
            &test_natdrv_compute_value_zero_count,
            "INTEGRITY_CHECKER_TEST_0001",
            "Compute and Check for ZERO_COUNT mode"
        },
    },
    {
        .any_tp_mode  = true,
        .any_sp_state = true,
        .any_lcs      = true,
        .test         = {
            &test_natdrv_compute_value_crc32,
            "INTEGRITY_CHECKER_TEST_0002",
            "Compute and Check for CRC32 mode"
        },
    },
    {
        .any_tp_mode  = true,
        .any_sp_state = true,
        .any_lcs      = true,
        .test         = {
            &test_natdrv_compute_value_sha256,
            "INTEGRITY_CHECKER_TEST_0003",
            "Compute and Check for SHA256 mode"
        },
    },
    {
        .any_tp_mode  = true,
        .any_sp_state = true,
        .any_lcs      = true,
        .test         = {
            &test_natdrv_compute_value_input_buffer_too_small,
            "INTEGRITY_CHECKER_TEST_0004",
            "Check buffer size"
        },
    },
    {
        .any_tp_mode  = true,
        .any_sp_state = true,
        .any_lcs      = true,
        .test         = {
            &test_natdrv_compute_value_input_buffer_alignment,
            "INTEGRITY_CHECKER_TEST_0005",
            "Check buffer alignment"
        },
    },
};

void add_natdrv_integrity_checker_tests(struct test_suite_t *p_ts, uint32_t ts_size) {
    add_conditional_tests_to_testsuite(tests, ARRAY_SIZE(tests), p_ts, ts_size);
}
