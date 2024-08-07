/*
 * Copyright (c) 2024, Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __RSE_TEST_COMMON_H__
#define __RSE_TEST_COMMON_H__

#include <stdint.h>
#include <stdbool.h>

#include "test_framework.h"
#include "device_definition.h"

#ifdef __cplusplus
extern "C" {
#endif

struct conditional_test_t {
    bool any_tp_mode;
    enum lcm_tp_mode_t tp_mode;
    bool any_lcs;
    enum lcm_lcs_t lcs;
    bool any_sp_state;
    enum lcm_bool_t sp_enabled;
    struct test_t test;
};

void add_tests_to_testsuite(struct test_t *test_list, uint32_t test_am,
                            struct test_suite_t *p_ts, uint32_t ts_size);

void add_conditional_tests_to_testsuite(struct conditional_test_t *tests, uint32_t test_am,
                                        struct test_suite_t *p_ts, uint32_t ts_size);
#ifdef __cplusplus
}
#endif

#endif /* __RSE_TEST_COMMON_H__ */
