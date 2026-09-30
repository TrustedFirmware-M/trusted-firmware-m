/*
 * Copyright (c) 2026, STMicroelectronics - All Rights Reserved
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#include <debug.h>
#include <errno.h>
#include <string.h>

#include <watchdog.h>
#include <wdt.h>

static enum tfm_platform_err_t _wdt_set_cfg(struct wdt_timeout_cfg *wdt_cfg)
{
	struct watchdog_timeout_cfg watchdog_cfg;
	int err;

	watchdog_cfg.timeout = wdt_cfg->timeout;
	err = watchdog_setup(NULL, &watchdog_cfg);

	return err ? TFM_PLATFORM_ERR_SYSTEM_ERROR : TFM_PLATFORM_ERR_SUCCESS;
}

static enum tfm_platform_err_t _wdt_start(void)
{
	int err;

	err = watchdog_start(NULL);

	return err ? TFM_PLATFORM_ERR_SYSTEM_ERROR : TFM_PLATFORM_ERR_SUCCESS;
}

static enum tfm_platform_err_t _wdt_stop(void)
{
	int err;

	err = watchdog_stop(NULL);

	return err ? TFM_PLATFORM_ERR_SYSTEM_ERROR : TFM_PLATFORM_ERR_SUCCESS;
}

static enum tfm_platform_err_t _wdt_ping(void)
{
	int err;

	err = watchdog_ping(NULL);

	return err ? TFM_PLATFORM_ERR_SYSTEM_ERROR : TFM_PLATFORM_ERR_SUCCESS;
}

static enum tfm_platform_err_t _wdt_get_info(struct wdt_info *info)
{
	uint32_t timeout = 0;
	int err, status;

	status = watchdog_status(NULL);
	err = watchdog_get_timeout(NULL, &timeout);

	if (err || status < 0)
		return TFM_PLATFORM_ERR_SYSTEM_ERROR;

	info->timeout = timeout;
	info->status = (status == WATCHDOG_ENABLED) ? WDT_ENABLED : WDT_DISABLED;

	return TFM_PLATFORM_ERR_SUCCESS;
}

enum tfm_platform_err_t watchdog_service(const psa_invec *in_vec, const psa_outvec *out_vec)
{
	enum tfm_platform_err_t ret = TFM_PLATFORM_ERR_NOT_SUPPORTED;
	struct tfm_wdt_service_args_t *args;
	struct tfm_wdt_service_out_t *out;

	if (in_vec->len != sizeof(struct tfm_wdt_service_args_t))
		return TFM_PLATFORM_ERR_INVALID_PARAM;

	args = (struct tfm_wdt_service_args_t *)in_vec->base;

	switch (args->type) {
	case TFM_WDT_SERVICE_TYPE_SET:
		ret = _wdt_set_cfg(&args->cfg);
		break;
	case TFM_WDT_SERVICE_TYPE_START:
		ret = _wdt_start();
		break;
	case TFM_WDT_SERVICE_TYPE_STOP:
		ret = _wdt_stop();
		break;
	case TFM_WDT_SERVICE_TYPE_PING:
		ret = _wdt_ping();
		break;
	case TFM_WDT_SERVICE_TYPE_INFO:
		if (!out_vec || out_vec->len != sizeof(struct tfm_wdt_service_out_t))
			return TFM_PLATFORM_ERR_INVALID_PARAM;

		out = (struct tfm_wdt_service_out_t *)out_vec->base;
		ret = _wdt_get_info(&out->info);
		break;
	default:
		break;
	}

	return ret;
}
