/* SPDX-License-Identifier: BSD-3-Clause */
/*
 * Copyright (c) 2026, STMicroelectronics - All Rights Reserved
 */

#ifndef DRIVERS_SPI_NOR_H
#define DRIVERS_SPI_NOR_H

#include <stdbool.h>
#include <stdint.h>
#include <device.h>

struct spi_nor_ops {
	/*
	 * Read on a SPI NOR flash memory a size at a given offset
	 *
	 * @dev: The SPI NOR flash device.
	 * @offset: The start offset of the read request.
	 * @buffer: The buffer used to store the read data.
	 * @length: The requested length to read.
	 * @length_read: The length read.
	 * Returns: 0 if the bus was claimed successfully, or a negative value
	 * if it wasn't.
	 */
	int (*read)(const struct device *dev, unsigned int offset,
		    uintptr_t buffer, size_t length, size_t *length_read);

	/*
	 * Write on a SPI NOR flash memory a size at a given offset
	 *
	 * @dev: The SPI NOR flash device.
	 * @offset: The start offset of the write request.
	 * @buffer: The buffer used to store the data to write.
	 * @length: The requested length to write.
	 * @length_read: The length written.
	 * Returns: 0 if the bus was claimed successfully, or a negative value
	 * if it wasn't.
	 */
	int (*write)(const struct device *dev, unsigned int offset,
		     uintptr_t buffer, size_t length, size_t *length_write);

	/*
	 * Erase on a SPI NOR flash memory a block or a sector
	 *
	 * @dev: The SPI NOR flash device.
	 * @offset: The start offset of the erase request.
	 * Returns: 0 if the bus was claimed successfully, or a negative value
	 * if it wasn't.
	 */
	int (*erase)(const struct device *dev, unsigned int offset);
};

#endif /* DRIVERS_SPI_NOR_H */
