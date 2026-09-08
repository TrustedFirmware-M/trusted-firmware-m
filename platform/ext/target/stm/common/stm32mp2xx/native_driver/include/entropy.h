/* SPDX-License-Identifier: BSD-3-Clause */
/*
 * Copyright (c) 2026, STMicroelectronics - All Rights Reserved
 * Author(s): Ludovic Barre, <ludovic.barre@foss.st.com> for STMicroelectronics.
 */
#ifndef _INCLUDE_ENTROPY_H_
#define _INCLUDE_ENTROPY_H_

#include <errno.h>
#include <stdint.h>
#include <device.h>

/**
 * @brief entropy driver API structure.
 *
 * @get_entropy: generate the necessary random data
 */

typedef int (*entropy_api_get_entropy_t)(const struct device *dev, uint8_t *buf, uint32_t len);

struct entropy_driver_api {
	entropy_api_get_entropy_t get_entropy;
};

#define DT_ENTROPY_CTRL(node_id) \
	DT_PHANDLE(node_id, entropy)

#define DT_INST_ENTROPY_CTLR(inst) \
	DT_ENTROPY_CTRL(DT_DRV_INST(inst))

/**
 * @brief Fills a buffer with entropy. Blocks if required in order to
 *        generate the necessary random data.
 *
 * @param if NULL take system entropy device defined by tfm,entropy in chosen node
 *        else take specific dev Pointer to the entropy device.
 *
 * @param buffer Buffer to fill with entropy.
 * @param length Buffer length.
 *
 * @retval 0 on success.
 * @retval -ERRNO errno code on error.
 */
int entropy_get_entropy(const struct device *dev, uint8_t *buf, uint32_t len);

#endif /* _INCLUDE_ENTROPY_H_ */
