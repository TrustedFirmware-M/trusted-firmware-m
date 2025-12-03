/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __SKU_SE_DEV_H__
#define __SKU_SE_DEV_H__

#include "platform_error_codes.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \brief Product-specific feature handler (0).
 *
 * This function is implemented by the platform and is responsible for
 * handling feature-specific initialization or configuration.
 *
 * \return TFM_PLAT_ERR_SUCCESS on success, platform-defined error otherwise.
 */
enum tfm_plat_err_t product_specific_feature_control_handler_0(void);

/**
 * \brief See product_specific_feature_control_handler_0().
 * \see product_specific_feature_control_handler_0
 */
enum tfm_plat_err_t product_specific_feature_control_handler_1(void);

/**
 * \brief See product_specific_feature_control_handler_0().
 * \see product_specific_feature_control_handler_0
 */
enum tfm_plat_err_t product_specific_feature_control_handler_2(void);

/**
 * \brief Configure the SE-DEV LCS, feature control and product-specific
 *        feature control
 *
 * \return Returns error code as specified in \ref tfm_plat_err_t
 */
enum tfm_plat_err_t rse_apply_sku_se_dev_overrides(void);

#ifdef __cplusplus
}
#endif

#endif /* __SKU_SE_DEV_H__ */
