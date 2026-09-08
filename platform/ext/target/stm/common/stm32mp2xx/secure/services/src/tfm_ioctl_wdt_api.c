/*
 * Copyright (c) 2026, STMicroelectronics - All Rights Reserved
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#include <string.h>

#include <tfm_platform_api.h>
#include <uapi/tfm_ioctl_api.h>

enum tfm_platform_err_t tfm_platform_wdt_set(struct wdt_timeout_cfg *cfg)
{
	struct tfm_wdt_service_args_t args;
	enum tfm_platform_err_t ret;
	psa_invec in_vec;

	in_vec.base = (const void *)&args;
	in_vec.len = sizeof(args);

	args.type = TFM_WDT_SERVICE_TYPE_SET;

	memcpy(&args.cfg, cfg, sizeof(struct wdt_timeout_cfg));
	ret = tfm_platform_ioctl(TFM_PLATFORM_IOCTL_WDT_SERVICE, &in_vec, NULL);

	return ret;
}

static enum tfm_platform_err_t _wdt_cmd(enum tfm_wdt_service_type_t type)
{
	struct tfm_wdt_service_args_t args;
	enum tfm_platform_err_t ret;
	psa_invec in_vec;

	in_vec.base = (const void *)&args;
	in_vec.len = sizeof(args);

	args.type = type;

	ret = tfm_platform_ioctl(TFM_PLATFORM_IOCTL_WDT_SERVICE, &in_vec, NULL);

	return ret;
}

enum tfm_platform_err_t tfm_platform_wdt_start(void)
{
	return _wdt_cmd(TFM_WDT_SERVICE_TYPE_START);
}

enum tfm_platform_err_t tfm_platform_wdt_stop(void)
{
	return _wdt_cmd(TFM_WDT_SERVICE_TYPE_STOP);
}

enum tfm_platform_err_t tfm_platform_wdt_ping(void)
{
	return _wdt_cmd(TFM_WDT_SERVICE_TYPE_PING);
}

enum tfm_platform_err_t tfm_platform_wdt_info(struct wdt_info *info)
{
	struct tfm_wdt_service_args_t args;
	struct tfm_wdt_service_out_t out;
	enum tfm_platform_err_t ret;
	psa_outvec out_vec;
	psa_invec in_vec;

	in_vec.base = (const void *)&args;
	in_vec.len = sizeof(args);

	out_vec.base = (void *)&out;
	out_vec.len = sizeof(out);

	args.type = TFM_WDT_SERVICE_TYPE_INFO;

	ret = tfm_platform_ioctl(TFM_PLATFORM_IOCTL_WDT_SERVICE, &in_vec, &out_vec);
	memcpy(info, &out.info, sizeof(struct wdt_info));

	return ret;
}
