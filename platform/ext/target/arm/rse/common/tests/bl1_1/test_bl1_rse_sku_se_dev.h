/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __TEST_BL1_RSE_SKU_H__
#define __TEST_BL1_RSE_SKU_H__

#include "test_framework.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifdef RSE_SKU_ENABLED
void test_bl1_rse_sku_set_cm_policies(struct test_result_t *ret);
void test_bl1_rse_sku_feature_control(struct test_result_t *ret);
void test_bl1_rse_sku_ps_fc(struct test_result_t *ret);
#endif /* RSE_SKU_ENABLED */

#ifdef RSE_HAS_SE_DEV_SOFT_LCS
void test_bl1_rse_sku_se_dev(struct test_result_t *ret);
#endif /* RSE_HAS_SE_DEV_SOFT_LCS */

#ifdef __cplusplus
}
#endif

#endif /* __TEST_BL1_RSE_SKU_H__ */
