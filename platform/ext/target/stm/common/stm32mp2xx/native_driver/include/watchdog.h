/* SPDX-License-Identifier: BSD-3-Clause */
/*
 * Copyright (c) 2026, STMicroelectronics - All Rights Reserved
 * Author(s): Ludovic Barre, <ludovic.barre@foss.st.com> for STMicroelectronics.
 */
#ifndef _INCLUDE_WATCHDOG_H_
#define _INCLUDE_WATCHDOG_H_

#include <errno.h>
#include <stdint.h>
#include <device.h>

struct watchdog_timeout_cfg {
	/** Lower limit of watchdog timeout in milliseconds. */
	uint32_t pretimeout;
	/** Upper limit of watchdog timeout in milliseconds. */
	uint32_t timeout;
};

enum watchdog_state_t {
	WATCHDOG_DISABLED,
	WATCHDOG_ENABLED,
};

/**
 * @brief Callback API for setting up watchdog device.
 */
typedef int (*watchdog_api_setup_t)(const struct device *dev,
				    const struct watchdog_timeout_cfg *cfg);

/**
 * @brief Callback API that shows the status of the watchdog device.
 */
typedef int (*watchdog_api_status_t)(const struct device *dev);

/**
 * @brief Callback API for starting watchdog device.
 */
typedef int (*watchdog_api_start_t)(const struct device *dev);

/**
 * @brief Callback API for stopping watchdog device.
 */
typedef int (*watchdog_api_stop_t)(const struct device *dev);

/**
 * @brief Callback API that sends a keepalive ping to the watchdog device.
 */
typedef int (*watchdog_api_ping_t)(const struct device *dev);

struct watchdog_driver_api {
	watchdog_api_setup_t setup;
	watchdog_api_status_t status;
	watchdog_api_start_t start;
	watchdog_api_stop_t stop;
	watchdog_api_ping_t ping;
};

/**
 * @brief Setup watchdog instance.
 *
 * @param dev Watchdog device instance.
 *            If NULL take system watchdog device defined by
 *            tfm,watchdog (chosen node)
 * @param cfg configuration timeout
 *
 * @return 0 on success, negative errno on failure.
 */
int watchdog_setup(const struct device *dev,
		   const struct watchdog_timeout_cfg *cfg);

/**
 * @brief return watchdog status.
 *
 * @param dev Watchdog device instance.
 *            If NULL take system watchdog device defined by
 *            tfm,watchdog (chosen node)
 *
 * @return watchdog's status (watchdog_state_t) on success, negative errno on failure.
 */
int watchdog_status(const struct device *dev);

/**
 * @brief Start watchdog instance.
 *
 * @param dev Watchdog device instance.
 *            If NULL take system watchdog device defined by
 *            tfm,watchdog (chosen node)
 *
 * @return 0 on success, negative errno on failure.
 */
int watchdog_start(const struct device *dev);

/**
 * @brief Stop watchdog instance.
 *
 * @param dev Watchdog device instance.
 *            If NULL take system watchdog device defined by
 *            tfm,watchdog (chosen node)
 *
 * @return 0 on success, negative errno on failure.
 */
int watchdog_stop(const struct device *dev);

/**
 * @brief ping watchdog instance.
 *
 * @param dev Watchdog device instance.
 *            If NULL take system watchdog device defined by
 *            tfm,watchdog (chosen node)
 *
 * @return 0 on success, negative errno on failure.
 */
int watchdog_ping(const struct device *dev);

#endif /* _INCLUDE_WATCHDOG_H_ */
