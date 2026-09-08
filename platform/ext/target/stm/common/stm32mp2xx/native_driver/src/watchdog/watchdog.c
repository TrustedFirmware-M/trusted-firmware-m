/* SPDX-License-Identifier: BSD-3-Clause */
/*
 * Copyright (c) 2026, STMicroelectronics - All Rights Reserved
 * Author(s): Ludovic Barre, <ludovic.barre@foss.st.com> for STMicroelectronics.
 */
#include <errno.h>
#include <stdint.h>
#include <device.h>
#include <watchdog.h>

static const struct device *const watchdog_dev = DEVICE_DT_GET_OR_NULL(DT_CHOSEN(tfm_watchdog));

static const struct device *_wdt_get_dev(const struct device *dev)
{
	if (!dev)
		dev = watchdog_dev;

	if (!device_is_ready(dev))
		return NULL;

	return dev;
}

int watchdog_setup(const struct device *dev, const struct watchdog_timeout_cfg *cfg)
{
	const struct watchdog_driver_api *api;
	const struct device *wdt_dev;

	wdt_dev = _wdt_get_dev(dev);
	if (!wdt_dev)
		return -ENODEV;

	if (!cfg)
		return -EINVAL;

	api = wdt_dev->api;

	return api->setup(wdt_dev, cfg);
}

int watchdog_status(const struct device *dev)
{
	const struct watchdog_driver_api *api;
	const struct device *wdt_dev;

	wdt_dev = _wdt_get_dev(dev);
	if (!wdt_dev)
		return -ENODEV;

	api = wdt_dev->api;

	return api->status(wdt_dev);
}

int watchdog_start(const struct device *dev)
{
	const struct watchdog_driver_api *api;
	const struct device *wdt_dev;

	wdt_dev = _wdt_get_dev(dev);
	if (!wdt_dev)
		return -ENODEV;

	api = wdt_dev->api;

	return api->start(wdt_dev);
}

int watchdog_stop(const struct device *dev)
{
	const struct watchdog_driver_api *api;
	const struct device *wdt_dev;

	wdt_dev = _wdt_get_dev(dev);
	if (!wdt_dev)
		return -ENODEV;

	api = wdt_dev->api;

	return api->stop(wdt_dev);
}

int watchdog_ping(const struct device *dev)
{
	const struct watchdog_driver_api *api;
	const struct device *wdt_dev;

	wdt_dev = _wdt_get_dev(dev);
	if (!wdt_dev)
		return -ENODEV;

	api = wdt_dev->api;

	return api->ping(wdt_dev);
}
