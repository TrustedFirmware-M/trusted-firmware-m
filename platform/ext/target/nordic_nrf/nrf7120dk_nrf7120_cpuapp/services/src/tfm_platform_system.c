/*
 * Copyright (c) 2019-2024, Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "platform/include/tfm_platform_system.h"
#include "tfm_hal_device_header.h"
#include "tfm_platform_hal_ioctl.h"
#include "tfm_ioctl_core_api.h"

void tfm_platform_hal_system_reset(void)
{
	/* Reset the system */
	NVIC_SystemReset();
}

enum tfm_platform_err_t tfm_platform_hal_ioctl(tfm_platform_ioctl_req_t request,
                                               psa_invec  *in_vec,
                                               psa_outvec *out_vec)
{
	/* Core IOCTL services */
	switch (request) {
	/* Not a supported IOCTL service.*/
	default:
		return TFM_PLATFORM_ERR_NOT_SUPPORTED;
	}

}
