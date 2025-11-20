/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <stdint.h>
#include <string.h>
#include <assert.h>

#include "rse_test_common.h"
#include "tfm_utils.h"

#ifdef TEST_CC3XX
#include "cc3xx_tests.h"
#endif


static struct test_t secure_extra_tests[100];

void register_testsuite_extra_s_interface(struct test_suite_t *p_test_suite)
{
    set_testsuite("RSE Tests", secure_extra_tests, 0, p_test_suite);

#ifdef TEST_CC3XX
    add_cc3xx_tests_to_testsuite(p_test_suite, ARRAY_SIZE(secure_extra_tests));
#endif
}
