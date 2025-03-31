/*
 * Copyright (c) 2025, Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "cc3xx_test_dpa.h"
#ifndef CC3XX_CONFIG_FILE
#include "cc3xx_config.h"
#else
#include CC3XX_CONFIG_FILE
#endif
#include "cc3xx_test_assert.h"

#include "cc3xx_test_utils.h"

#define MAX_WORD_COUNT_COPY 512

void dpa_copy_test(struct test_result_t *ret)
{
    cc3xx_err_t err;
    size_t idx;

    uint32_t src[MAX_WORD_COUNT_COPY];
    uint32_t dst[MAX_WORD_COUNT_COPY];
    size_t test_sizes[] = {1, 32, 33, 100, 256, MAX_WORD_COUNT_COPY};

    /* Fill src with random words */
    err = cc3xx_lowlevel_rng_get_random(src, MAX_WORD_COUNT_COPY * 4, CC3XX_RNG_FAST);
    TEST_ASSERT(err == CC3XX_ERR_SUCCESS, "Random generation failed");

    /* Verify src is not all zero */
    TEST_ASSERT(!!memcmp(src, 0, MAX_WORD_COUNT_COPY * 4), "Source rng is null");

    for(idx = 0; idx < ARRAY_SIZE(test_sizes); idx++) {
        size_t word_count = test_sizes[idx];

        memset(dst, 0, word_count * 4);

        cc3xx_dpa_hardened_word_copy(dst, src, word_count);

        TEST_ASSERT(!memcmp(dst, src, word_count * 4), "DPA copy failed");
    }

    ret->val = TEST_PASSED;
}

static struct test_t dpa_tests[] = {
    {
        &dpa_copy_test,
        "CC3XX_DPA_COPY_TEST",
        "CC3XX DPA COPY test",
    },
};

void add_cc3xx_dpa_tests_to_testsuite(struct test_suite_t *p_ts, uint32_t ts_size)
{
    cc3xx_add_tests_to_testsuite(dpa_tests, ARRAY_SIZE(dpa_tests), p_ts, ts_size);
}
