/* SPDX-License-Identifier: BSD-3-Clause */
/*
 * Copyright (c) 2026, STMicroelectronics - All Rights Reserved
 */

#include <reset.h>

static inline int _is_valid_dev(const struct reset_control *rstc)
{
	if(!rstc || !device_is_ready(rstc->dev))
		return -ENODEV;

	if (!rstc->dev->api)
		return -ENOTSUP;

	return 0;
}

static inline int _status(const struct device *dev, uint32_t id)
{
	const struct reset_driver_api *api = dev->api;

	if (api->status == NULL)
		return -ENOSYS;

	return api->status(dev, id);
}

int reset_control_status(const struct reset_control *rstc)
{
	int dev_err = _is_valid_dev(rstc);

	if (dev_err)
		return dev_err;

	return _status(rstc->dev, rstc->id);
}

static inline int _assert(const struct device *dev, uint32_t id)
{
	const struct reset_driver_api *api = dev->api;

	if (api->assert_level == NULL)
		return -ENOSYS;

	return api->assert_level(dev, id);
}

int reset_control_assert(const struct reset_control *rstc)
{
	int dev_err = _is_valid_dev(rstc);

	if (dev_err)
		return dev_err;

	return _assert(rstc->dev, rstc->id);
}

static inline int _deassert(const struct device *dev, uint32_t id)
{
	const struct reset_driver_api *api = dev->api;

	if (api->deassert_level == NULL)
		return -ENOSYS;

	return api->deassert_level(dev, id);
}

int reset_control_deassert(const struct reset_control *rstc)
{
	int dev_err = _is_valid_dev(rstc);

	if (dev_err)
		return dev_err;

	return _deassert(rstc->dev, rstc->id);
}

static inline int _reset(const struct device *dev, uint32_t id)
{
	const struct reset_driver_api *api = dev->api;

	if (api->reset == NULL) {
		return -ENOSYS;
	}

	return api->reset(dev, id);
}

int reset_control_reset(const struct reset_control *rstc)
{
	int dev_err = _is_valid_dev(rstc);

	if (dev_err)
		return dev_err;

	return _reset(rstc->dev, rstc->id);
}
