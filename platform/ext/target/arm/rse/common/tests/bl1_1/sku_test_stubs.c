/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <stdint.h>

#include "platform_error_codes.h"
#include "sku_se_dev.h"

uint8_t sku_ps_fc_called[3] = { 0 };

enum tfm_plat_err_t product_specific_feature_control_handler_0(void)
{
    sku_ps_fc_called[0] = 1;
    return TFM_PLAT_ERR_SUCCESS;
}

enum tfm_plat_err_t product_specific_feature_control_handler_1(void)
{
    sku_ps_fc_called[1] = 1;
    return TFM_PLAT_ERR_SUCCESS;
}

enum tfm_plat_err_t product_specific_feature_control_handler_2(void)
{
    sku_ps_fc_called[2] = 1;
    return TFM_PLAT_ERR_SUCCESS;
}
