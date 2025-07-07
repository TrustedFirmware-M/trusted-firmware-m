/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "tfm_platform_system.h"
#include "tfm_hal_device_header.h"
#include "tfm_hal_platform.h"

void tfm_platform_hal_system_reset(void)
{
    /* Reset the system */
    tfm_hal_system_reset(TFM_PLAT_SWSYN_DEFAULT);
}

#if !(RSE_SUBPLATFORM_PAL_DEFAULT_IOCTL)
enum tfm_platform_err_t tfm_platform_hal_ioctl(tfm_platform_ioctl_req_t request,
                                               psa_invec  *in_vec,
                                               psa_outvec *out_vec)
{
    (void)request;
    (void)in_vec;
    (void)out_vec;

    /* Not needed for this platform */
    return TFM_PLATFORM_ERR_NOT_SUPPORTED;
}
#endif /* !(RSE_SUBPLATFORM_PAL_DEFAULT_IOCTL) */
