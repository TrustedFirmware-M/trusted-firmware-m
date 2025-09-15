/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "platform_error_codes.h"
#include "rse_get_rse_id.h"

enum tfm_plat_err_t rse_get_rse_id(uint32_t *rse_id)
{
    /* Only 1 RSE in the system */
    *rse_id = 0;

    return TFM_PLAT_ERR_SUCCESS;
}
