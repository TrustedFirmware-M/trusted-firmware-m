/*
 * Copyright (c) 2025, Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef SPI_H
#define SPI_H

#include <stdint.h>

struct spi_gpio_data {
	uint8_t cs_gpio, sclk_gpio, mosi_gpio, miso_gpio, reset_gpio;
	uint32_t spi_delay_us;
	unsigned int spi_mode;
};

struct spi_ops {
	void (*get_access)(void);
	void (*start)(void);
	void (*stop)(void);
	int (*xfer)(unsigned int bitlen, const void *dout, void *din);
};

struct spi_plat {
	struct spi_gpio_data gpio_data;
	const struct spi_ops *ops;
};

struct spi_plat *spi_platform_init(struct spi_gpio_data *gpio_spi_data);

#endif /* SPI_H */
