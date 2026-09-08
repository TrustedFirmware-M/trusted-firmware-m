/*
 * Copyright (c) 2026, STMicroelectronics - All Rights Reserved
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef  TFM_IOCTL_API_H
#define  TFM_IOCTL_API_H

#include <stdint.h>
#include <limits.h>

#include <tfm_platform_api.h>
#include <uapi/tfm_ioctl_wdt_api.h>

/*
 * Supported request types.
 */
enum tfm_platform_ioctl_request_t {
	TFM_PLATFORM_IOCTL_WDT_SERVICE = 1,
};

#endif /* TFM_IOCTL_API_H */
