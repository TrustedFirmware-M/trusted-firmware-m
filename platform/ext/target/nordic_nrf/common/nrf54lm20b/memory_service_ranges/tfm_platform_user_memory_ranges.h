/*
 * Copyright (c) 2021 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef TFM_PLATFORM_USER_MEMORY_RANGES_H__
#define TFM_PLATFORM_USER_MEMORY_RANGES_H__

#include <tfm_ioctl_core_api.h>

#include <nrfx.h>


static const struct tfm_read_service_range ranges[] = {
	{ .start = 0xFFFFFFFF, .size = 0x0},
};

static const struct tfm_write32_service_address tfm_write32_service_addresses[] = {
	/* This is a dummy value because this table cannot be empty */
	{.addr = 0xFFFFFFFF, .mask = 0x0, .allowed_values = NULL, .allowed_values_array_size = 0},
};

#endif /* TFM_PLATFORM_USER_MEMORY_RANGES_H__ */
