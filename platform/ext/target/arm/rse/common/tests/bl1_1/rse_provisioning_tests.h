/*
 * Copyright (c) 2024-2025, Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __RSE_PROVISIONING_TESTS_H__
#define __RSE_PROVISIONING_TESTS_H__

#include "test_framework.h"

#ifdef __cplusplus
extern "C" {
#endif

void rse_bl1_provisioning_test_0001(struct test_result_t *ret);
void rse_bl1_provisioning_test_0002(struct test_result_t *ret);
void rse_bl1_provisioning_test_0003(struct test_result_t *ret);
void rse_bl1_provisioning_test_0004(struct test_result_t *ret);
void rse_bl1_provisioning_test_0005(struct test_result_t *ret);

void rse_bl1_provisioning_test_0101(struct test_result_t *ret);

void rse_bl1_provisioning_test_0201(struct test_result_t *ret);
void rse_bl1_provisioning_test_0202(struct test_result_t *ret);

void rse_bl1_provisioning_test_0301(struct test_result_t *ret);
void rse_bl1_provisioning_test_0302(struct test_result_t *ret);

void rse_bl1_provisioning_test_0401(struct test_result_t *ret);
void rse_bl1_provisioning_test_0402(struct test_result_t *ret);
void rse_bl1_provisioning_test_0403(struct test_result_t *ret);
void rse_bl1_provisioning_test_0404(struct test_result_t *ret);
void rse_bl1_provisioning_test_0405(struct test_result_t *ret);
void rse_bl1_provisioning_test_0415(struct test_result_t *ret);
#ifdef RSE_NON_ENDORSED_DM_PROVISIONING
void rse_bl1_provisioning_test_0425(struct test_result_t *ret);
#endif
void rse_bl1_provisioning_test_0406(struct test_result_t *ret);
void rse_bl1_provisioning_test_0407(struct test_result_t *ret);
void rse_bl1_provisioning_test_0408(struct test_result_t *ret);
void rse_bl1_provisioning_test_0409(struct test_result_t *ret);

void rse_bl1_provisioning_test_0501(struct test_result_t *ret);
void rse_bl1_provisioning_test_0502(struct test_result_t *ret);
void rse_bl1_provisioning_test_0510(struct test_result_t *ret);
void rse_bl1_provisioning_test_0511(struct test_result_t *ret);

#ifdef RSE_ROTPK_REVOCATION
void rse_bl1_provisioning_test_0600(struct test_result_t *ret);
void rse_bl1_provisioning_test_0601(struct test_result_t *ret);
void rse_bl1_provisioning_test_0602(struct test_result_t *ret);
void rse_bl1_provisioning_test_0603(struct test_result_t *ret);
void rse_bl1_provisioning_test_0604(struct test_result_t *ret);
void rse_bl1_provisioning_test_0605(struct test_result_t *ret);
void rse_bl1_provisioning_test_0606(struct test_result_t *ret);
void rse_bl1_provisioning_test_0607(struct test_result_t *ret);
void rse_bl1_provisioning_test_0610(struct test_result_t *ret);
void rse_bl1_provisioning_test_0611(struct test_result_t *ret);
#endif

#ifdef RSE_NON_ENDORSED_DM_PROVISIONING
void rse_bl1_provisioning_test_0700(struct test_result_t *ret);
void rse_bl1_provisioning_test_0701(struct test_result_t *ret);
void rse_bl1_provisioning_test_0702(struct test_result_t *ret);
#ifdef RSE_ROTPK_REVOCATION
void rse_bl1_provisioning_test_0703(struct test_result_t *ret);
void rse_bl1_provisioning_test_0704(struct test_result_t *ret);
#endif
#endif

#ifdef __cplusplus
}
#endif

#endif /* __RSE_PROVISIONING_TESTS_H__ */
