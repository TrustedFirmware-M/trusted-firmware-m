/*
 * Copyright (c) 2017 Linaro Limited
 * Copyright (c) 2023, STMicroelectronics
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * fork from zephyr
 */

#ifndef _I2C_PRIV_H_
#define _I2C_PRIV_H_

#include <i2c.h>
#include <dt-bindings/i2c/i2c.h>
#include <debug.h>

static inline uint32_t i2c_map_dt_bitrate(uint32_t bitrate)
{
	switch (bitrate) {
	case I2C_BITRATE_STANDARD:
		return I2C_SPEED_STANDARD << I2C_SPEED_SHIFT;
	case I2C_BITRATE_FAST:
		return I2C_SPEED_FAST << I2C_SPEED_SHIFT;
	case I2C_BITRATE_FAST_PLUS:
		return I2C_SPEED_FAST_PLUS << I2C_SPEED_SHIFT;
	case I2C_BITRATE_HIGH:
		return I2C_SPEED_HIGH << I2C_SPEED_SHIFT;
	case I2C_BITRATE_ULTRA:
		return I2C_SPEED_ULTRA << I2C_SPEED_SHIFT;
	}

	EMSG("Invalid I2C bit rate value\n");

	return 0;
}

#endif /* _I2C_PRIV_H_ */
