/*
 * Copyright (c) 2026, STMicroelectronics - All Rights Reserved
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#include <cmsis.h>
#include <tfm_hal_platform.h>
#include <tfm_platform_system.h>
#include <uapi/tfm_ioctl_api.h>

#include <wdt.h>

void tfm_platform_hal_system_reset(void)
{
	tfm_hal_system_reset(TFM_PLAT_SWSYN_DEFAULT);
}

enum tfm_platform_err_t tfm_platform_hal_ioctl(tfm_platform_ioctl_req_t request,
					       psa_invec  *in_vec,
					       psa_outvec *out_vec)
{
	switch(request) {
#ifdef TFM_PLATFORM_WDT_API
	case TFM_PLATFORM_IOCTL_WDT_SERVICE:
		return watchdog_service(in_vec, out_vec);
#endif
	default:
		return TFM_PLATFORM_ERR_NOT_SUPPORTED;
	}

	return TFM_PLATFORM_ERR_NOT_SUPPORTED;
}
