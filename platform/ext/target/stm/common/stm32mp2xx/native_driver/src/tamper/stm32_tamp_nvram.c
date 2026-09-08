/* SPDX-License-Identifier: BSD-3-Clause */
/*
 * Copyright (c) 2026, STMicroelectronics - All Rights Reserved
 */

#include <debug.h>
#include <device.h>
#include <errno.h>
#include <inttypes.h>
#include <lib/mmio.h>
#include <lib/utils_def.h>
#include <nvmem.h>
#include <stdbool.h>
#include <stdint.h>
#include <stm32_rif.h>
#include <stm32_tamp.h>
#include <string.h>

/* TAMP offset register */
#define _TAMP_BKPxR(x)		(0x4 * (x))

struct nvmem_cell {
	const char *cell_label;
	uint32_t id;
	const struct device *parent;
};

struct stm32_tamp_nvram_config {
	uintptr_t base;
	uint32_t max_id;
	const struct nvmem_cell *bkup_cell;
	int n_bkup_cell;
};

static int stm32_tamp_nvmem_get_cell_size(const struct device *dev, size_t *size)
{
	const struct nvmem_cell *cell = dev_get_config(dev);
	const struct stm32_tamp_nvram_config *nvram;

	if (!cell)
		return -EINVAL;

	nvram = dev_get_config(cell->parent);
	if (!nvram || cell->id > nvram->max_id)
		return -EINVAL;

	*size = sizeof(uint32_t);

	return 0;
}

static int stm32_tamp_nvmem_read_cell(const struct device *dev, size_t len,
				      uint8_t *out, size_t *read_len)
{
	const struct nvmem_cell *cell = dev_get_config(dev);
	const struct stm32_tamp_nvram_config *nvram;
	uint32_t value;

	if (!cell || len != sizeof(uint32_t))
		return -EINVAL;

	nvram = dev_get_config(cell->parent);
	if (!nvram || cell->id > nvram->max_id)
		return -EINVAL;

	value = io_read32(nvram->base + _TAMP_BKPxR(cell->id));
	memcpy(out, &value, len);
	if (read_len)
		*read_len = len;

	return 0;
}

static int stm32_tamp_nvmem_write_cell(const struct device *dev, size_t len, const uint8_t *in)
{
	const struct nvmem_cell *cell = dev_get_config(dev);
	const struct stm32_tamp_nvram_config *nvram;
	uint32_t value;

	if (!cell || len != sizeof(uint32_t))
		return -EINVAL;

	nvram = dev_get_config(cell->parent);
	if (!nvram || cell->id > nvram->max_id)
		return -EINVAL;

	memcpy(&value, in, len);
	io_write32(nvram->base + _TAMP_BKPxR(cell->id), value);

	return 0;
}

static const struct nvmem_driver_api __maybe_unused stm32_tamp_nvmem_api = {
	.get_cell_size = stm32_tamp_nvmem_get_cell_size,
	.read_cell = stm32_tamp_nvmem_read_cell,
	.write_cell = stm32_tamp_nvmem_write_cell,
};

#define NVMEM_CELL_CHILD_DEFINE(node_id)					\
static const char * const stm32_bkup_label_##node_id[] =			\
	DT_NODELABEL_STRING_ARRAY(node_id);					\
										\
static const struct nvmem_cell stm32_bkup_cell_##node_id = {			\
	.cell_label = stm32_bkup_label_##node_id[0],				\
	.id = (DT_REG_ADDR(node_id) / sizeof(uint32_t)),			\
	.parent	= DEVICE_DT_GET(DT_GPARENT(node_id)),				\
};										\
										\
DEVICE_DT_DEFINE(node_id, NULL, NULL,						\
		 NULL,								\
		 &stm32_bkup_cell_##node_id,					\
		 CORE, 8,							\
		 &stm32_tamp_nvmem_api);

#define NVMEM_CELL_CHILD_GET(node_id) stm32_bkup_cell_##node_id,

#define STM32_TAMP_SRAM_INIT(n)							\
										\
DT_FOREACH_CHILD(DT_INST_CHILD(n, nvmem_layout), NVMEM_CELL_CHILD_DEFINE)	\
										\
static const struct nvmem_cell stm32_bkup_cells_##n[] = {			\
	COND_CODE_1(DT_NODE_EXISTS(DT_INST_CHILD(n, nvmem_layout)),		\
		    (DT_FOREACH_CHILD(DT_INST_CHILD(n, nvmem_layout),		\
				      NVMEM_CELL_CHILD_GET)),			\
		    ())								\
};										\
										\
static const struct stm32_tamp_nvram_config nvram_cfg##n = {			\
	.base = DT_INST_REG_ADDR(n),						\
	.max_id = DT_INST_REG_SIZE(n) / sizeof(uint32_t) - 1,			\
	.bkup_cell = stm32_bkup_cells_##n,					\
	.n_bkup_cell = ARRAY_SIZE(stm32_bkup_cells_##n),			\
};										\
										\
DEVICE_DT_INST_DEFINE(n, NULL, NULL, NULL,			\
		      &nvram_cfg##n,  CORE, 7, NULL);

#define DT_DRV_COMPAT		st_stm32mp25_tamp_nvram

DT_INST_FOREACH_STATUS_OKAY(STM32_TAMP_SRAM_INIT)
