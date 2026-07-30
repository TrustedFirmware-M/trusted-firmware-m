/*
 * Copyright (c) 2021 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef TFM_PLATFORM_USER_MEMORY_RANGES_H__
#define TFM_PLATFORM_USER_MEMORY_RANGES_H__

#include <tfm_ioctl_core_api.h>

#include <nrfx.h>

#define FICR_INFO_ADDR          (NRF_FICR_S_BASE + offsetof(NRF_FICR_Type, INFO))
#define FICR_INFO_SIZE          (sizeof(FICR_INFO_Type))

static const struct tfm_read_service_range ranges[] = {
	{ .start = FICR_INFO_ADDR, .size = FICR_INFO_SIZE },
};

static const struct tfm_write32_service_address tfm_write32_service_addresses[] = {
	/* This is a dummy value because this table cannot be empty */
	{.addr = 0xFFFFFFFF, .mask = 0x0, .allowed_values = NULL, .allowed_values_array_size = 0},
};

#endif /* TFM_PLATFORM_USER_MEMORY_RANGES_H__ */
