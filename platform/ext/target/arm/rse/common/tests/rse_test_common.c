/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
#include "rse_test_common.h"

#include <assert.h>
#include <string.h>

#define FUNNEL_LCS LCM_LCS_CM

static void add_tests_to_testsuite(struct test_t *test_list, uint32_t test_am,
                                   struct test_suite_t *p_ts, uint32_t ts_size)
{
    assert(p_ts->list_size + test_am <= ts_size);
    memcpy(&(p_ts->test_list[p_ts->list_size]), test_list, test_am * sizeof(struct test_t));
    p_ts->list_size += test_am;
}

void add_conditional_tests_to_testsuite(struct conditional_test_t *tests, uint32_t test_am,
                                        struct test_suite_t *p_ts, uint32_t ts_size)
{
    enum lcm_tp_mode_t tp_mode;
    enum lcm_bool_t sp_enabled;
    enum lcm_lcs_t lcs;
    enum lcm_error_t lcm_err;
    struct conditional_test_t *test;

    lcm_err = lcm_get_tp_mode(&LCM_DEV_S, &tp_mode);
    if (lcm_err != LCM_ERROR_NONE) {
        return;
    }

    lcm_err = lcm_get_sp_enabled(&LCM_DEV_S, &sp_enabled);
    if (lcm_err != LCM_ERROR_NONE) {
        return;
    }

    lcm_err = lcm_get_lcs(&LCM_DEV_S, &lcs);
    if (lcm_err != LCM_ERROR_NONE) {
        return;
    }

    for (uint32_t idx = 0; idx < test_am; idx++) {
        test = &tests[idx];
#ifdef TFM_CODE_COVERAGE
        /*
         * Ensures that all tests that have no
         * specific LCM conditions are run only
         * once. For generating code coverage reports
         * rigorous testing in each mode is
         * not required.
         */
        if ((test->any_lcs)) {
            test->any_lcs = false;
            test->lcs = FUNNEL_LCS;
        }

        if ((test->any_sp_state)) {
            test->any_sp_state = false;
            test->sp_enabled = LCM_FALSE;
        }

        if ((test->any_tp_mode) && tp_mode == LCM_TP_MODE_VIRGIN) {
            /* don't run any tests in VIRGIN TP MODE
             * unless explicitly specified */
            test->any_tp_mode = false;
        }
#endif /* TFM_CODE_COVERAGE */
        if ((test->any_tp_mode || (tp_mode == test->tp_mode)) &&
            (test->any_sp_state || (sp_enabled == test->sp_enabled)) &&
            (test->any_lcs || (lcs == test->lcs))) {
            add_tests_to_testsuite(&(test->test), 1, p_ts, ts_size);
        }
    }
}
