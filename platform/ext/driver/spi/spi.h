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
	unsigned int spi_mode;
	uint32_t spi_max_clock;
};

struct spi_priv;

struct spi_ops {
	int (*get_access)(struct spi_priv *context);
	void (*release_access)(struct spi_priv *context);
	void (*start)(struct spi_priv *context);
	void (*stop)(struct spi_priv *context);
	int (*xfer)(struct spi_priv *context, unsigned int bytes,
		    const void *dout, void *din);
};

struct spi_plat {
	struct spi_priv *priv;
	const struct spi_ops *ops;
};

struct spi_plat *spi_platform_init(struct spi_gpio_data *spi_config);

#endif /* SPI_H */
