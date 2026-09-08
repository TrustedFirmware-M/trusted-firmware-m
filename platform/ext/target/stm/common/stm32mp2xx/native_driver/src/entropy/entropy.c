/* SPDX-License-Identifier: BSD-3-Clause */
/*
 * Copyright (c) 2026, STMicroelectronics - All Rights Reserved
 * Author(s): Ludovic Barre, <ludovic.barre@foss.st.com> for STMicroelectronics.
 */
#include <errno.h>
#include <stdint.h>
#include <device.h>
#include <entropy.h>

static const struct device *const entropy_dev = DEVICE_DT_GET_OR_NULL(DT_CHOSEN(tfm_entropy));

int entropy_get_entropy(const struct device *dev, uint8_t *buf, uint32_t len)
{
	const struct entropy_driver_api *api;

	if (!dev)
		dev = entropy_dev;

	if ((!dev) || !device_is_ready(dev))
		return -ENODEV;

	api = dev->api;

	return api->get_entropy(dev, buf, len);
}
