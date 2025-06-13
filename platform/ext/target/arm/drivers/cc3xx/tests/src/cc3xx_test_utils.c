/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */


#include "cc3xx_test_utils.h"

#include <string.h>
#include <assert.h>

void cc3xx_add_tests_to_testsuite(struct test_t *test_list, uint32_t test_am,
                                  struct test_suite_t *p_ts, uint32_t ts_size)
{
    assert(p_ts->list_size + test_am <= ts_size);

    memcpy(&(p_ts->test_list[p_ts->list_size]), test_list, test_am * sizeof(struct test_t));
    p_ts->list_size += test_am;
}
