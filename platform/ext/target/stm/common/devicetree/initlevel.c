/*
 * Copyright (c) 2026, STMicroelectronics - All Rights Reserved
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#include <device.h>
#include <debug.h>
#include <iterable_sections.h>

#pragma GCC push_options
#pragma GCC optimize ("O0")

extern const struct init_entry __init_start[];
extern const struct init_entry __init_EARLY_start[];
extern const struct init_entry __init_ARCH_start[];
extern const struct init_entry __init_PRE_CORE_start[];
extern const struct init_entry __init_CORE_start[];
extern const struct init_entry __init_POST_CORE_start[];
extern const struct init_entry __init_REST_start[];
extern const struct init_entry __init_end[];

void sys_init_run_level(enum init_level level)
{
	static const struct init_entry *levels[] = {
		__init_EARLY_start,
		__init_ARCH_start,
		__init_PRE_CORE_start,
		__init_CORE_start,
		__init_POST_CORE_start,
		__init_REST_start,
		/* End marker */
		__init_end,
	};
	const struct init_entry *entry;

	for (entry = levels[level]; entry < levels[level + 1]; entry++) {
		const struct device *dev = entry->dev;

		/*
		 * If the init entry belongs to a device, run init function
		 * with its reference, otherwise it is a system init.
		 */
		if (dev == NULL) {
			int err;

			err = entry->init_fn.sys();
			if (err)
				EMSG("oops sysinit\n");
			continue;
		}

		/*
		 * Mark device initialized. If initialization
		 * failed, record the error condition.
		 */
		if (!entry->init_fn.dev) {
			// device has no init func but is ready
			dev->state->init_res = 0;
			dev->state->initialized = true;
		} else {
			dev->state->init_res = entry->init_fn.dev(dev);
			dev->state->initialized = true;
			if (dev->state->init_res)
				EMSG("device:%s err:%d\n",
				     dev->name, dev->state->init_res);
		}
	}
}

bool device_is_ready(const struct device *dev)
{
	/*
	 * if an invalid device pointer is passed as argument, this call
	 * reports the `device` as not ready for usage.
	 */
	if (dev == NULL) {
		return false;
	}

	return dev->state->initialized && (dev->state->init_res == 0U);
}

size_t device_get_all(struct device const **devices)
{
	size_t cnt;

	STRUCT_SECTION_GET(device, 0, devices);
	STRUCT_SECTION_COUNT(device, &cnt);

	return cnt;
}

#pragma GCC pop_options
