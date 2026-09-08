/* SPDX-License-Identifier: BSD-3-Clause */
/*
 * Copyright (c) 2026, STMicroelectronics - All Rights Reserved
 */

#include <nvmem.h>

int nvmem_get_cell_size(const struct device *dev, size_t *size)
{
	const struct nvmem_driver_api *api;

	if (!device_is_ready(dev))
		return -ENODEV;

	api = dev->api;

	return api->get_cell_size(dev, size);
}

int nvmem_read_cell(const struct device *dev, size_t out_len, uint8_t *out, size_t *read_len)
{
	const struct nvmem_driver_api *api;

	if (!device_is_ready(dev))
		return -ENODEV;

	api = dev->api;

	return api->read_cell(dev, out_len, out, read_len);
}

int nvmem_write_cell(const struct device *dev, size_t in_len, const uint8_t *in)
{
	const struct nvmem_driver_api *api;

	if (!device_is_ready(dev))
		return -ENODEV;

	api = dev->api;

	return api->write_cell(dev, in_len, in);
}
