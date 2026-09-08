/*
 * Copyright (c) 2026, STMicroelectronics - All Rights Reserved
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef  TFM_IOCTL_WDT_API_H
#define  TFM_IOCTL_WDT_API_H

/**
 * enum wdt_state_t - watchdog states
 * @WDT_DISABLED:	watchdog system is disabled
 * @WDT_ENABLED:	watchdog system is enabled
  */
enum wdt_state_t {
	WDT_DISABLED = 0,
	WDT_ENABLED,
};

/**
 * enum tfm_cpu_service_type_t - watchdog services
 * @TFM_WDT_SERVICE_TYPE_SET:	set watchdog timeout
 * @TFM_WDT_SERVICE_TYPE_START:	start watchdog
 * @TFM_WDT_SERVICE_TYPE_STOP:	stop watchdog
 * @TFM_WDT_SERVICE_TYPE_PING:	ping watchdog to refresh counter
 * @TFM_WDT_SERVICE_TYPE_INFO:	get watchdog status
 */
enum tfm_wdt_service_type_t {
	TFM_WDT_SERVICE_TYPE_SET = 0,
	TFM_WDT_SERVICE_TYPE_START,
	TFM_WDT_SERVICE_TYPE_STOP,
	TFM_WDT_SERVICE_TYPE_PING,
	TFM_WDT_SERVICE_TYPE_INFO,
};

struct tfm_wdt_service_args_t {
	enum tfm_wdt_service_type_t type;
	union {
		/* TFM_WDT_SERVICE_TYPE_SET */
		struct wdt_timeout_cfg {
			uint32_t timeout; /* timeout in ms */
		} cfg;
	};
};

struct tfm_wdt_service_out_t {
	union {
		struct wdt_info  {
			int32_t status;
		} info;
	};
};

/**
 * @brief set watchdog timeout.
 *
 * @param[in] cfg	watchdog timeout configuration
 *
 * @return Returns values as specified by the tfm_platform_err_t
 */
enum tfm_platform_err_t tfm_platform_wdt_set(struct wdt_timeout_cfg *cfg);

/**
 * @brief start watchdog.
 *
 * @return Returns values as specified by the tfm_platform_err_t
 */
enum tfm_platform_err_t tfm_platform_wdt_start(void);

/**
 * @brief stop watchdog.
 *
 * @return Returns values as specified by the tfm_platform_err_t
 */
enum tfm_platform_err_t tfm_platform_wdt_stop(void);

/**
 * @brief start watchdog.
 *
 * @return Returns values as specified by the tfm_platform_err_t
 */
enum tfm_platform_err_t tfm_platform_wdt_ping(void);

/**
 * @brief get watchdog information.
 *
 * @param[out] info	watchdog information structure
 *
 * @return Returns values as specified by the tfm_platform_err_t
 */
enum tfm_platform_err_t tfm_platform_wdt_info(struct wdt_info *info);
#endif /* TFM_IOCTL_WDT_API_H */
