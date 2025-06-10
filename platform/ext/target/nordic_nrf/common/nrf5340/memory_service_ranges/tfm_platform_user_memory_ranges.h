/*
 * Copyright (c) 2021 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef TFM_PLATFORM_USER_MEMORY_RANGES_H__
#define TFM_PLATFORM_USER_MEMORY_RANGES_H__

#include <tfm_ioctl_core_api.h>

#include "nrf.h"

#define FICR_BASE               NRF_FICR_S_BASE

#define FICR_INFO_ADDR          (FICR_BASE + offsetof(NRF_FICR_Type, INFO))
#define FICR_INFO_SIZE          (sizeof(FICR_INFO_Type))

#define FICR_NFC_ADDR           (FICR_BASE + offsetof(NRF_FICR_Type, NFC))
#define FICR_NFC_SIZE           (sizeof(FICR_NFC_Type))

#define FICR_XOSC32MTRIM_ADDR   (FICR_BASE + offsetof(NRF_FICR_Type, XOSC32MTRIM))
#define FICR_XOSC32MTRIM_SIZE   (sizeof(uint32_t))

/* Used by nrf_erratas.h */
#define FICR_RESTRICTED_ADDR    (FICR_BASE + 0x130)
#define FICR_RESTRICTED_SIZE    0x8

static const struct tfm_read_service_range ranges[] = {
	{ .start = FICR_INFO_ADDR, .size = FICR_INFO_SIZE },
	{ .start = FICR_NFC_ADDR, .size = FICR_NFC_SIZE },
	{ .start = FICR_RESTRICTED_ADDR, .size = FICR_RESTRICTED_SIZE },
	{ .start = FICR_XOSC32MTRIM_ADDR, .size = FICR_XOSC32MTRIM_SIZE },
};

static const struct tfm_write32_service_address tfm_write32_service_addresses[] = {
	/* This is a dummy value because this table cannot be empty */
	{.addr = 0xFFFFFFFF, .mask = 0x0, .allowed_values = NULL, .allowed_values_array_size = 0},
};

#endif /* TFM_PLATFORM_USER_MEMORY_RANGES_H__ */
