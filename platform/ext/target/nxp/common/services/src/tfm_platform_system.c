/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 * Copyright 2026 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "tfm_platform_system.h"
#include "platform_description.h"
#include "device_definition.h"

void tfm_platform_hal_system_reset(void)
{
    /* Reset the system */
    NVIC_SystemReset();
}

/*
 * Board-specific IOCTL hook.
 * Each board that needs platform IOCTL support provides this function in its
 * own services. The weak default below is used by boards that have no 
 * board-specific IOCTL handlers.
 */
__attribute__((weak))
enum tfm_platform_err_t
tfm_platform_hal_ioctl_board(tfm_platform_ioctl_req_t request,
                              psa_invec  *in_vec,
                              psa_outvec *out_vec)
{
    (void)request;
    (void)in_vec;
    (void)out_vec;

    /* Not needed for this platform */
    return TFM_PLATFORM_ERR_NOT_SUPPORTED;
}

enum tfm_platform_err_t
tfm_platform_hal_ioctl(tfm_platform_ioctl_req_t request,
                       psa_invec  *in_vec,
                       psa_outvec *out_vec)
{
    return tfm_platform_hal_ioctl_board(request, in_vec, out_vec);
}
