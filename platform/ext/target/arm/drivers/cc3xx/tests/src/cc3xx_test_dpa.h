/*
 * Copyright (c) 2023, Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef CC3XX_TEST_PKA_H
#define CC3XX_TEST_PKA_H

#include "cc3xx_stdlib.h"
#include "cc3xx_rng.h"

#include "test_framework.h"

#ifdef __cplusplus
extern "C" {
#endif

void add_cc3xx_dpa_tests_to_testsuite(struct test_suite_t *p_ts, uint32_t ts_size);

#ifdef __cplusplus
}
#endif

#endif /* CC3XX_TEST_PKA_H */
