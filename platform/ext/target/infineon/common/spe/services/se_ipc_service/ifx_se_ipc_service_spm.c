/*
 * Copyright (c) 2023-2025 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "ifx_se_platform.h"
#include "ifx_se_tfm_utils.h"
#include "ifx_tfm_log_shim.h"
#include "ifx_se_ipc_service_spm.h"

enum tfm_plat_err_t ifx_se_ipc_service_spm_init(void)
{
    ifx_se_status_t status;

    /* Enable SE RT Service */
    status = ifx_se_enable(IFX_SE_TFM_SYSCALL_CONTEXT);
    if (IFX_SE_IS_STATUS_SUCCESS(status)) {
        INFO_RAW("SE RT Services enabled\n");
        return TFM_PLAT_ERR_SUCCESS;
    }

    ERROR_RAW("SE RT Services not detected 0x%08x\n", ifx_se_fih_uint_decode(status));
    return TFM_PLAT_ERR_SYSTEM_ERR;
}

enum tfm_plat_err_t ifx_se_ipc_service_spm_shutdown(void)
{
    ifx_se_status_t status;

    /* Shutdown SE RT Service */
    status = ifx_se_disable(IFX_SE_TFM_SYSCALL_CONTEXT);
    if (IFX_SE_IS_STATUS_SUCCESS(status)) {
        return TFM_PLAT_ERR_SUCCESS;
    }

    return TFM_PLAT_ERR_SYSTEM_ERR;
}
