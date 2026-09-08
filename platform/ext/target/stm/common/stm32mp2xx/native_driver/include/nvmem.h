/* SPDX-License-Identifier: BSD-3-Clause */
/*
 * Copyright (c) 2026, STMicroelectronics - All Rights Reserved
 */

#ifndef NVMEM_H
#define NVMEM_H

#include <errno.h>
#include <device.h>

#ifdef __cplusplus
extern "C" {
#endif

/** @brief Driver-specific API functions to support non-volatile memory */

/**
 * @brief Callback API to get the size of an NVMEM cell
 *
 * @param dev NVMEM device instance
 * @param size NVMEM cell size read
 *
 * @return See the return values for nvmem_get_cell_size()
 * @see nvmem_get_cell_size()
 */
typedef int (*nvmem_get_cell_size_t)(const struct device *dev, size_t *size);

/**
 * @brief Callback API to read the content of an NVMEM cell
 *
 * @param dev NVMEM device instance
 * @param out_len size of data to read (size of the cell)
 * @param out pointer to collect NVMEM cell content
 * @param read_len size of data read from NVMEM cell
 *
 * @return See the return values for nvmem_read_cell()
 * @see nvmem_read_cell()
 */
typedef int (*nvmem_read_cell_t)(const struct device *dev, size_t out_len, uint8_t *out,
				 size_t *read_len);

/**
 * @brief Callback API to write content to an NVMEM cell
 *
 * @param dev NVMEM device instance
 * @param in_len size of data to write
 * @param in pointer to data to write
 *
 * @return See the return values for nvmem_write_cell()
 * @see nvmem_write_cell()
 */
typedef int (*nvmem_write_cell_t)(const struct device *dev, size_t in_len, const uint8_t *in);

struct nvmem_driver_api {
	nvmem_get_cell_size_t get_cell_size;
	nvmem_read_cell_t read_cell;
	nvmem_write_cell_t write_cell;
};

/**
 * @brief Get the size of an NVMEM cell
 *
 * @param dev NVMEM device instance
 * @param size NVMEM cell size read
 *
 * @retval 0      On success.
 * @retval -errno Negative errno on error.
 */
int nvmem_get_cell_size(const struct device *dev, size_t *size);

/**
 * @brief Read the content of an NVMEM cell
 *
 * @param dev NVMEM device instance
 * @param out_len size of data to read (size of the cell)
 * @param out pointer to collect NVMEM cell content
 * @param read_len size of data read from NVMEM cell
 *
 * @retval 0      On success.
 * @retval -errno Negative errno on error.
 */
int nvmem_read_cell(const struct device *dev, size_t out_len, uint8_t *out, size_t *read_len);

/**
 * @brief Write content to an NVMEM cell
 *
 * @param dev NVMEM device instance
 * @param in_len size of data to write
 * @param in pointer to data to write
 *
 * @retval 0      On success.
 * @retval -errno Negative errno on error.
 */

int nvmem_write_cell(const struct device *dev, size_t in_len, const uint8_t *in);

/** @} */

#ifdef __cplusplus
}
#endif

#endif /* NVMEM_H */
