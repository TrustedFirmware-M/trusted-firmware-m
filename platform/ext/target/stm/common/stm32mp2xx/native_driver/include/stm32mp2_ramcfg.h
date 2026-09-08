/* SPDX-License-Identifier: BSD-3-Clause */
/*
 * Copyright (c) 2026, STMicroelectronics - All Rights Reserved
 */

#include <stddef.h>
#include <stdint.h>
#include <device.h>

/* CRC block size */
#define RETRAM_BUF_SZ	(16 * 1024)
#define LPSRAM1_BUF_SZ	(1 * 1024)

#define DT_RAMCFG_DEVICE(sram) \
	DEVICE_GET(DEVICE_DT_DEV_ID(DT_NODELABEL(ramcfg_ ## sram)))

int stm32_ramcfg_crc_compute(const struct device *dev, size_t buf_size);
void stm32_ramcfg_crc_enable(const struct device *dev);
void stm32_ramcfg_crc_disable(const struct device *dev);
