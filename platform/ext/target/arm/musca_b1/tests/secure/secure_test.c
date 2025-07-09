/*
 * Copyright (c) 2025, Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <stdint.h>
#include <string.h>
#include <assert.h>

#include "cc3xx_tests.h"

#define ARRAY_SIZE(arr) (sizeof(arr)/sizeof((arr)[0]))

static struct test_t secure_extra_tests[100];

void register_testsuite_extra_s_interface(struct test_suite_t *p_test_suite)
{
    set_testsuite("MUSCA_B1 Tests", secure_extra_tests, 0, p_test_suite);

    add_cc3xx_tests_to_testsuite(p_test_suite, ARRAY_SIZE(secure_extra_tests));
}
