/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
#include "rse_test_common.h"

#include "rse_zero_count.h"
#include "device_definition.h"

/* device header */
#include "integrity_checker_drv.h"

#define TEST_VALUE {10496458194827692257, 4393878607423357066}

/* retieve the software zero counter implementation */
enum tfm_plat_err_t software_zero_count_compute(uint8_t *buf, size_t buf_len,
                                                uint32_t *zero_count);
enum tfm_plat_err_t software_zero_count_check(uint8_t *buf, size_t buf_len,
                                              uint32_t expected_zero_count);

static void test_common_rse_zero_count_software_verify(struct test_result_t *ret)
{
    enum tfm_plat_err_t            software_err;
    enum integrity_checker_error_t hardware_err;

    uint64_t input[2] = TEST_VALUE;
    uint32_t software_out, hardware_out;

    software_err = software_zero_count_compute((uint8_t *)input, sizeof(input), &software_out);
    TEST_ASSERT(software_err == TFM_PLAT_ERR_SUCCESS, "Failed to calculate zero count");

    software_err = software_zero_count_check((uint8_t *)input, sizeof(input), software_out);
    TEST_ASSERT(software_err == TFM_PLAT_ERR_SUCCESS, "Failed to verify(check) zero count");

    /* compute the output buffers */
    hardware_err = integrity_checker_compute_value(&INTEGRITY_CHECKER_DEV_S,
                                                   INTEGRITY_CHECKER_MODE_ZERO_COUNT,
                                                   (const uint32_t *)input, sizeof(input),
                                                   &hardware_out, sizeof(hardware_out), NULL);
    if (hardware_err == INTEGRITY_CHECKER_ERROR_UNSUPPORTED_MODE) {
        /* if there is no hardware version to validate with,
         * and the software calc and check pass skip the test */
        TEST_SKIPPED;
    }
    TEST_ASSERT(hardware_err == INTEGRITY_CHECKER_ERROR_NONE,
                "Could not compute value for ZERO_COUNT mode");

    /* check with expected value */
    hardware_err = integrity_checker_check_value(&INTEGRITY_CHECKER_DEV_S,
                                                 INTEGRITY_CHECKER_MODE_ZERO_COUNT,
                                                 (const uint32_t *)input, sizeof(input),
                                                 &hardware_out, sizeof(hardware_out));
    /* explicitly check for the comparison failure */
    TEST_ASSERT(hardware_err != INTEGRITY_CHECKER_ERROR_CHECK_VALUE_COMPARISON_FAILED,
                "Failed integrity check");
    TEST_ASSERT(hardware_err == INTEGRITY_CHECKER_ERROR_NONE,
                "Could not check value for ZERO_COUNT mode");

    TEST_ASSERT(software_out == hardware_out,
        "Hardware accelarated calculations and software implemented calculations do not match!");

    ret->val=TEST_PASSED;
}

static struct conditional_test_t tests[] = {
    {
        .any_tp_mode  = true,
        .any_sp_state = true,
        .any_lcs      = true,
        .test         = {
            &test_common_rse_zero_count_software_verify,
            "RSE_ZERO_COUNT_TEST_0001",
            "Validate software zero count, comparing to integrity checker"
        },
    },
};

void add_common_rse_zero_counter_tests(struct test_suite_t *p_ts, uint32_t ts_size)
{
    add_conditional_tests_to_testsuite(tests, ARRAY_SIZE(tests), p_ts, ts_size);
}
