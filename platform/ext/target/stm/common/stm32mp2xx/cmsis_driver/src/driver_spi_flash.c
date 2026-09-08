/*
 * Copyright (c) 2020, Arm Limited. All rights reserved.
 * Copyright (c) 2026, STMicroelectronics - All Rights Reserved
 *
 * SPDX-License-Identifier: Apache-2.0
 */
#include <stdbool.h>
#include <Driver_Flash.h>
#include <flash_layout.h>
#include <spi_nor.h>

#define DT_DRV_COMPAT fixed_partitions

#ifndef ARG_UNUSED
#define ARG_UNUSED(arg)  ((void)arg)
#endif

/* Driver version */
#define ARM_FLASH_DRV_VERSION		ARM_DRIVER_VERSION_MAJOR_MINOR(1, 0)

static const ARM_DRIVER_VERSION DriverVersion = {
	ARM_FLASH_API_VERSION,  /* Defined in the CMSIS Flash Driver header file */
	ARM_FLASH_DRV_VERSION
};

/**
 * \brief Flash driver capability macro definitions \ref ARM_FLASH_CAPABILITIES
 */
/* Flash Ready event generation capability values */
#define EVENT_READY_NOT_AVAILABLE	(0u)
#define EVENT_READY_AVAILABLE		(1u)
/* Chip erase capability values */
#define CHIP_ERASE_NOT_SUPPORTED	(0u)
#define CHIP_ERASE_SUPPORTED		(1u)

/**
 * Data width values for ARM_FLASH_CAPABILITIES::data_width
 * \ref ARM_FLASH_CAPABILITIES
 */
enum {
	DATA_WIDTH_8BIT   = 0u,
	DATA_WIDTH_16BIT,
	DATA_WIDTH_32BIT,
	DATA_WIDTH_ENUM_SIZE
};

static const uint32_t data_width_byte[DATA_WIDTH_ENUM_SIZE] = {
	sizeof(uint8_t),
	sizeof(uint16_t),
	sizeof(uint32_t),
};

/* Driver Capabilities */
static const ARM_FLASH_CAPABILITIES DriverCapabilities = {
	EVENT_READY_NOT_AVAILABLE,
	DATA_WIDTH_8BIT,
	CHIP_ERASE_SUPPORTED
};

/**
 * \brief Flash status macro definitions \ref ARM_FLASH_STATUS
 */
/* Busy status values of the Flash driver */
#define DRIVER_STATUS_IDLE		(0u)
#define DRIVER_STATUS_BUSY		(1u)

/* Error status values of the Flash driver */
#define DRIVER_STATUS_NO_ERROR		(0u)
#define DRIVER_STATUS_ERROR		(1u)

/*
 * ARM PARTITION device structure
 */
typedef struct {
	const struct device *dev_flash;
	uint32_t offset;
	uint32_t size;
	ARM_FLASH_INFO *data;
	ARM_FLASH_STATUS status;
} arm_part_dev_t;

static bool is_range_valid(arm_part_dev_t *dev, uint32_t offset)
{
	return (offset >= dev->offset) && (offset < dev->offset + dev->size) ?
	       true : false;
}

static bool is_write_aligned(arm_part_dev_t *dev, uint32_t value)
{
	return value % dev->data->program_unit ? false : true;
}

static __maybe_unused ARM_DRIVER_VERSION ARM_Part_GetVersion(void)
{
	return DriverVersion;
}

static __maybe_unused ARM_FLASH_CAPABILITIES ARM_Part_GetCapabilities(void)
{
	return DriverCapabilities;
}

static __maybe_unused int32_t ARM_Part_X_Initialize(arm_part_dev_t *dev,
				     ARM_Flash_SignalEvent_t cb_event)
{
	return ARM_DRIVER_OK;
}

static __maybe_unused int32_t ARM_Part_X_Uninitialize(arm_part_dev_t *dev)
{
	return ARM_DRIVER_OK;
}

static __maybe_unused int32_t ARM_Part_X_PowerControl(arm_part_dev_t *dev,
				       ARM_POWER_STATE state)
{
	switch(state) {
	case ARM_POWER_FULL:
		/* Nothing to be done */
		return ARM_DRIVER_OK;
	case ARM_POWER_OFF:
	case ARM_POWER_LOW:
		return ARM_DRIVER_ERROR_UNSUPPORTED;
	default:
		return ARM_DRIVER_ERROR_PARAMETER;
	}
}

static __maybe_unused int32_t ARM_Part_X_ReadData(arm_part_dev_t *dev, uint32_t addr,
				   void *data, uint32_t cnt)
{
	const struct spi_nor_ops *ops = dev->dev_flash->api;
	uint32_t bytes = cnt * data_width_byte[DriverCapabilities.data_width];
	size_t length_read;
	int ret;

	dev->status.error = DRIVER_STATUS_NO_ERROR;

	/* Check Flash memory boundaries */
	if (!is_range_valid(dev, addr + bytes - 1)) {
		dev->status.error = DRIVER_STATUS_ERROR;
		return ARM_DRIVER_ERROR_PARAMETER;
	}

	dev->status.busy = DRIVER_STATUS_BUSY;

	ret = ops->read(dev->dev_flash, addr, (uintptr_t)data,
			bytes, &length_read);

	dev->status.busy = DRIVER_STATUS_IDLE;

	if (ret || (length_read != bytes)) {
		dev->status.error = DRIVER_STATUS_ERROR;
		return ARM_DRIVER_ERROR;
	}

	return cnt;
}

static __maybe_unused int32_t ARM_Part_X_ProgramData(arm_part_dev_t *dev, uint32_t addr,
				      const void *data, uint32_t cnt)
{
	const struct spi_nor_ops *ops = dev->dev_flash->api;
	uint32_t bytes = cnt * data_width_byte[DriverCapabilities.data_width];
	size_t length_write;
	int ret;

	dev->status.error = DRIVER_STATUS_NO_ERROR;

	/* Check Flash memory boundaries */
	if (!(is_range_valid(dev, addr + bytes - 1) &&
	    is_write_aligned(dev, addr) &&
	    is_write_aligned(dev, bytes))) {
		dev->status.error = DRIVER_STATUS_ERROR;
		return ARM_DRIVER_ERROR_PARAMETER;
	}

	dev->status.busy = DRIVER_STATUS_BUSY;

	ret = ops->write(dev->dev_flash, addr, (uintptr_t)data,
			 bytes, &length_write);

	dev->status.busy = DRIVER_STATUS_IDLE;

	if (ret || (length_write != bytes)) {
		dev->status.error = DRIVER_STATUS_ERROR;
		return ARM_DRIVER_ERROR;
	}

	return cnt;
}

static __maybe_unused int32_t ARM_Part_X_EraseSector(arm_part_dev_t *dev, uint32_t addr)
{
	const struct spi_nor_ops *ops = dev->dev_flash->api;
	int ret;

	dev->status.error = DRIVER_STATUS_NO_ERROR;
	dev->status.busy = DRIVER_STATUS_BUSY;

	ret = ops->erase(dev->dev_flash, addr);

	dev->status.busy = DRIVER_STATUS_IDLE;

	if (ret) {
		dev->status.error = DRIVER_STATUS_ERROR;
		return ARM_DRIVER_ERROR;
	}

	return ARM_DRIVER_OK;
}

static __maybe_unused int32_t ARM_Part_X_EraseChip(arm_part_dev_t *dev)
{
	return ARM_DRIVER_ERROR_UNSUPPORTED;
}

static __maybe_unused ARM_FLASH_STATUS ARM_Part_X_GetStatus(arm_part_dev_t *dev)
{
	return dev->status;
}

static __maybe_unused ARM_FLASH_INFO * ARM_Part_X_GetInfo(arm_part_dev_t *dev)
{
	return dev->data;
}

#define PARTITION(n)									\
static ARM_FLASH_INFO PART_DATA_##n = {							\
	.sector_info  = NULL, /* Uniform sector layout */				\
	.sector_count = DT_REG_SIZE(n) / DT_PROP(DT_GPARENT(n), erase_size),		\
	.sector_size  = DT_PROP(DT_GPARENT(n), erase_size),				\
	.page_size  = DT_PROP(DT_GPARENT(n), write_size),				\
	.program_unit = 1u,								\
	.erased_value = 0xFF,								\
};											\
											\
static arm_part_dev_t PART_DEV_##n = {							\
	.dev_flash = DEVICE_DT_GET(DT_GPARENT(n)),					\
	.offset = DT_REG_ADDR(n),							\
	.size = DT_REG_SIZE(n),								\
	.data = &(PART_DATA_##n),							\
	.status = {									\
		.busy = DRIVER_STATUS_IDLE,						\
		.error = DRIVER_STATUS_NO_ERROR,					\
		.reserved = 0u,								\
	},										\
};											\
											\
static int32_t ARM_Part_##n##_Initialize(ARM_Flash_SignalEvent_t cb_event)		\
{											\
	return ARM_Part_X_Initialize(&PART_DEV_##n, cb_event);				\
}											\
											\
static int32_t ARM_Part_##n##_Uninitialize(void)					\
{											\
	return ARM_Part_X_Uninitialize(&PART_DEV_##n);					\
}											\
											\
static int32_t ARM_Part_##n##_PowerControl(ARM_POWER_STATE state)			\
{											\
	return ARM_Part_X_PowerControl(&PART_DEV_##n, state);				\
}											\
											\
static int32_t ARM_Part_##n##_ReadData(uint32_t addr, void *data, uint32_t cnt)		\
{											\
	return ARM_Part_X_ReadData(&PART_DEV_##n, addr, data, cnt);			\
}											\
											\
static int32_t ARM_Part_##n##_ProgramData(uint32_t addr,				\
						const void *data, uint32_t cnt)		\
{											\
	return ARM_Part_X_ProgramData(&PART_DEV_##n, addr, data, cnt);			\
}											\
											\
static int32_t ARM_Part_##n##_EraseSector(uint32_t addr)				\
{											\
	return ARM_Part_X_EraseSector(&PART_DEV_##n, addr);				\
}											\
											\
static int32_t ARM_Part_##n##_EraseChip(void)						\
{											\
	return ARM_Part_X_EraseChip(&PART_DEV_##n);					\
}											\
											\
static ARM_FLASH_STATUS ARM_Part_##n##_GetStatus(void)					\
{											\
	return ARM_Part_X_GetStatus(&PART_DEV_##n);					\
}											\
											\
static ARM_FLASH_INFO * ARM_Part_##n##_GetInfo(void)					\
{											\
	return ARM_Part_X_GetInfo(&PART_DEV_##n);					\
}											\
											\
extern ARM_DRIVER_FLASH Driver_##n;							\
ARM_DRIVER_FLASH Driver_##n = {								\
	ARM_Part_GetVersion,								\
	ARM_Part_GetCapabilities,							\
	ARM_Part_##n##_Initialize,							\
	ARM_Part_##n##_Uninitialize,							\
	ARM_Part_##n##_PowerControl,							\
	ARM_Part_##n##_ReadData,							\
	ARM_Part_##n##_ProgramData,							\
	ARM_Part_##n##_EraseSector,							\
	ARM_Part_##n##_EraseChip,							\
	ARM_Part_##n##_GetStatus,							\
	ARM_Part_##n##_GetInfo								\
};

#define FOREACH_PARTITION(n) DT_INST_FOREACH_CHILD(n, PARTITION)

DT_INST_FOREACH_STATUS_OKAY(FOREACH_PARTITION)
