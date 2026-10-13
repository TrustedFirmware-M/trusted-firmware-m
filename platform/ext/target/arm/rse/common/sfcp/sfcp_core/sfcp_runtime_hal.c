/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "sfcp_runtime_hal.h"
#include "sfcp.h"
#include "sfcp_interrupt_handler.h"

enum tfm_plat_err_t tfm_multi_core_hal_receive(sfcp_link_id_t link_id, uint32_t source)
{
    return (enum tfm_plat_err_t)sfcp_interrupt_handler(link_id);
}

enum tfm_plat_err_t tfm_multi_core_hal_init(void)
{
    enum sfcp_error_t sfcp_err;

    sfcp_err = sfcp_init();
    if (sfcp_err != SFCP_ERROR_SUCCESS) {
        return (enum tfm_plat_err_t)sfcp_err;
    }

    return TFM_PLAT_ERR_SUCCESS;
}
