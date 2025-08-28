/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
#include "rse_test_common.h"
#include "dpa_hardened_word_copy.h"

static void test_common_dpa_hardened_word_copy_singlechunk(struct test_result_t *ret)
{
    /* create source and destination buffers (1-24 word chunk) */
    volatile uint32_t dst[24], src[24] = {
        1254748092,  455015731, 1388912787, 2029487105,
        1675780816,  816999272,   80056982,  430681497,
        4166163592, 3280565493, 1140898130, 2431713977,
        1605799427, 2182655628,   89824123, 1330772355,
        2600559730,  644584247,  799127045, 1395143296,
        2544333802,  943961945, 1765103661,  993019046,
    };

    /* copy the words */
    dpa_hardened_word_copy(src, dst, 24);

    /* compare source and destination buffers */
    for (uint32_t i = 0; i < 24; i++) {
        TEST_ASSERT(dst[i] == src[i], "Failed copy");
    }

    ret->val = TEST_PASSED;
}

static void test_common_dpa_hardened_word_copy_multichunk(struct test_result_t *ret)
{
    /* create source and destination buffers (2-32 word chunks) */
    volatile uint32_t dst[64], src[64] = {
        1254748092,  455015731, 1388912787, 2029487105,
        1675780816,  816999272,   80056982,  430681497,
        4166163592, 3280565493, 1140898130, 2431713977,
        1605799427, 2182655628,   89824123, 1330772355,
        2600559730,  644584247,  799127045, 1395143296,
        2544333802,  943961945, 1765103661,  993019046,
        1609331248,  706641133, 3125730010,  353750085,
        1669018959,  133177818, 1656817719,  744328853,
        2890619722, 1167978057, 4133057633,   96766198,
        2648196381, 1743699672, 3644581383, 3247710634,
        1334208867, 3496435266, 1719768759, 1362487667,
        2185701365,  170491009, 3868407030,   15237864,
        2875977877, 2063207004, 1280494703, 2654793783,
        1040304126,  127974041, 2324320332, 1158444580,
        2352827531, 3709623423, 1166549869,  756472765,
        2689199841,  279261825, 3594632903, 2616901521,
    };

    /* copy the words */
    dpa_hardened_word_copy(src, dst, 64);

    /* compare source and destination buffers */
    for (uint32_t i = 0; i < 64; i++) {
        TEST_ASSERT(dst[i] == src[i], "Failed copy");
    }

    ret->val = TEST_PASSED;
}

static struct conditional_test_t tests[] =
{
    {
        .any_tp_mode = true,
        .any_sp_state = true,
        .any_lcs = true,
        .test = {
            &test_common_dpa_hardened_word_copy_singlechunk,
            "DPA_HARDEND_WORD_COPY_TEST_1",
            "Verify single chunk word copy"
        },
    },
    {
        .any_tp_mode = true,
        .any_sp_state = true,
        .any_lcs = true,
        .test = {
            &test_common_dpa_hardened_word_copy_multichunk,
            "DPA_HARDEND_WORD_COPY_TEST_2",
            "Verify multi chunk word copy"
        },
    },
};
void add_common_dpa_hardened_word_copy_tests(struct test_suite_t *p_ts, uint32_t ts_size)
{
    add_conditional_tests_to_testsuite(tests, ARRAY_SIZE(tests), p_ts, ts_size);
}
