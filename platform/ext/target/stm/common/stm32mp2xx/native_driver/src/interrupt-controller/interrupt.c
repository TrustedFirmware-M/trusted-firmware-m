/* SPDX-License-Identifier: BSD-3-Clause */
/*
 * Copyright (c) 2026, STMicroelectronics - All Rights Reserved
 * Author(s): Ludovic Barre, <ludovic.barre@foss.st.com> for STMicroelectronics.
 */
#include <errno.h>
#include <stdint.h>
#include <stdbool.h>

#include <device.h>
#include <irq.h>

static int _irq_spec_is_valid(const struct irq_spec *spec)
{
	if (!spec || !spec->irq_hdl)
		return -EINVAL;

	if (!device_is_ready(spec->dev))
		return -ENODEV;

	return 0;
}

int interrupt_request(const struct irq_spec *spec, void *data, irq_handler_t cb, uint32_t flags)
{
	const struct interrupt_controller_api *api;
	int err = _irq_spec_is_valid(spec);

	if (err)
		return err;

	api = spec->dev->api;

	if (!api || !api->request)
		return -ENOTSUP;

	spec->irq_hdl->data = data;
	spec->irq_hdl->callback = cb;
	spec->irq_hdl->flags = flags;

	err = api->request(spec);
	if (!err && !(spec->irq_hdl->flags & IRQF_NO_AUTOEN)) {
		if (!api->enable)
			return -ENOTSUP;

		err = api->enable(spec);
	}

	return err;
}

int interrupt_enable(const struct irq_spec *spec)
{
	const struct interrupt_controller_api *api;
	int err = _irq_spec_is_valid(spec);

	if (err)
		return err;

	api = spec->dev->api;

	if (!api || !api->enable)
		return -ENOTSUP;

	return api->enable(spec);
}

int interrupt_disable(const struct irq_spec *spec)
{
	const struct interrupt_controller_api *api;
	int err = _irq_spec_is_valid(spec);

	if (err)
		return err;

	api = spec->dev->api;

	if (!api || !api->disable)
		return -ENOTSUP;

	return api->disable(spec);
}

int interrupt_mask(const struct irq_spec *spec)
{
	const struct interrupt_controller_api *api;
	int err = _irq_spec_is_valid(spec);

	if (err)
		return err;

	api = spec->dev->api;

	if (!api || !api->mask)
		return -ENOTSUP;

	return api->mask(spec);
}

int interrupt_unmask(const struct irq_spec *spec)
{
	const struct interrupt_controller_api *api;
	int err = _irq_spec_is_valid(spec);

	if (err)
		return err;

	api = spec->dev->api;

	if (!api || !api->unmask)
		return -ENOTSUP;

	return api->unmask(spec);
}
