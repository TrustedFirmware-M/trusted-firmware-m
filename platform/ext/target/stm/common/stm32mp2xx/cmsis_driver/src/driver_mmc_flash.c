/*
 * Copyright (c) 2026, STMicroelectronics - All Rights Reserved
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#include <stdbool.h>
#include <errno.h>
#include <string.h>
#include <Driver_Flash.h>
#include <flash_layout.h>
#include <mmc.h>

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
	DATA_WIDTH_8BIT = 0u,
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
	uint8_t buf[MMC_BLOCK_SIZE];
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

/*
 * This function allows the caller to read any number of bytes
 * from any position. It hides from the caller that the low level
 * driver only can read aligned blocks of data. For this reason
 * we need to handle the use case where the first byte to be read is not
 * aligned to start of the block, the last byte to be read is also not
 * aligned to the end of a block, and there are zero or more blocks-worth
 * of data in between.
 *
 * In such a case we need to read more bytes than requested (i.e. full
 * blocks) and strip-out the leading bytes (aka skip) and the trailing
 * bytes (aka padding). See diagram below
 *
 * pos --------------------
 *                          |
 * base                     |
 *  |                       |
 *  v                       v<----  length   ---->
 *  --------------------------------------------------------------
 * |           |         block#1    |        |   block#n          |
 * |  block#0  |            +       |   ...  |     +              |
 * |           | <- skip -> +       |        |     + <- padding ->|
 *  ------------------------+----------------------+--------------
 *             ^                                                  ^
 *             |                                                  |
 *             v    iteration#1                iteration#n        v
 *              --------------------------------------------------
 *             |                    |        |                    |
 *             |<----  request ---->|  ...   |<----- request ---->|
 *             |                    |        |                    |
 *              --------------------------------------------------
 *            /                   /          |                    |
 *           /                   /           |                    |
 *          /                   /            |                    |
 *         /                   /             |                    |
 *        /                   /              |                    |
 *       /                   /               |                    |
 *      /                   /                |                    |
 *     /                   /                 |                    |
 *    /                   /                  |                    |
 *   /                   /                   |                    |
 *  <---- request ------>                    <------ request  ----->
 *  ---------------------                    -----------------------
 *  |        |          |                    |          |           |
 *  |<-skip->|<-nbytes->|           -------->|<-nbytes->|<-padding->|
 *  |        |          |           |        |          |           |
 *  ---------------------           |        -----------------------
 *  ^        \           \          |        |          |
 *  |         \           \         |        |          |
 *  |          \           \        |        |          |
 *  buf         \           \   buf          |          |
 *               \           \               |          |
 *                \           \              |          |
 *                 \           \             |          |
 *                  \           \            |          |
 *                   \           \           |          |
 *                    \           \          |          |
 *                     \           \         |          |
 *                      --------------------------------
 *                      |           |        |         |
 * buffer-------------->|           | ...    |         |
 *                      |           |        |         |
 *                      --------------------------------
 *                      <-count#1->|                   |
 *                      <----------  count#n   -------->
 *                      <----------  length  ---------->
 *
 * Additionally, the IO driver has an underlying buffer that is at least
 * one block-size and may be big enough to allow.
 */
static int block_read(arm_part_dev_t *dev, uint32_t addr, uintptr_t buffer,
		      size_t length, size_t *length_read)
{
	uintptr_t buf;
	int lba;
	uint32_t base;
	size_t pos;
	size_t left;
	size_t nbytes;  /* number of bytes read in one iteration */
	size_t request; /* number of requested bytes in one iteration */
	size_t count;   /* number of bytes already read */
	/*
	 * number of leading bytes from start of the block
	 * to the first byte to be read
	 */
	size_t skip;
	/*
	 * number of trailing bytes between the last byte
	 * to be read and the end of the block
	 */
	size_t padding;

	/*
	 * We don't know the number of bytes that we are going
	 * to read in every iteration, because it will depend
	 * on the low level driver.
	 */
	count = 0U;
	pos = addr & MMC_BLOCK_MASK;
	base = addr - pos;
	for (left = length; left > 0U; left -= nbytes) {
		/*
		 * We must only request operations aligned to the block
		 * size. Therefore if pos is not block-aligned,
		 * we have to request the operation to start at the
		 * previous block boundary and skip the leading bytes. And
		 * similarly, the number of bytes requested must be a
		 * block size multiple
		 */
		skip = pos & MMC_BLOCK_MASK;

		/*
		 * Calculate the block number containing pos
		 * - e.g. block 3.
		 */
		lba = (pos + base) / MMC_BLOCK_SIZE;

		buf = (uintptr_t)dev->buf;
		request = MMC_BLOCK_SIZE;
		if ((((buffer + count) % MMC_BLOCK_SIZE) == 0U) &&
		    (left >= MMC_BLOCK_SIZE)) {
			/*
			 * The underlying read buffer can be used to
			 * read most of the data. Calculate the
			 * number of bytes to read to align with the
			 * block size.
			 */
			request = skip + left;
			request = request & ~(MMC_BLOCK_SIZE - 1U);
			buf = buffer + count;
		}

		request = mmc_read_blocks(dev->dev_flash, lba, buf, request);
		if (request <= skip) {
			/*
			 * We couldn't read enough bytes to jump over
			 * the skip bytes, so we should have to read
			 * again the same block, thus generating
			 * the same error.
			 */
			return -EIO;
		}

		/*
		 * Need to remove skip and padding bytes, if any, from
		 * the read data when copying to the user buffer.
		 */
		nbytes = request - skip;
		padding = (nbytes > left) ? nbytes - left : 0U;
		nbytes -= padding;

		if ((buffer + count) != (buf + skip)) {
			memcpy((void *)(buffer + count), (void *)(buf + skip), nbytes);
		}

		pos += nbytes;
		count += nbytes;
	}

	*length_read = count;

	return 0;
}

/*
 * This function allows the caller to write any number of bytes
 * from any position. It hides from the caller that the low level
 * driver only can write aligned blocks of data.
 * See comments for block_read for more details.
 */
static int block_write(arm_part_dev_t *dev, uint32_t addr,
		       const uintptr_t buffer, size_t length,
		       size_t *length_written)
{
	uintptr_t buf = (uintptr_t)dev->buf;
	int lba;
	uint32_t base;
	size_t pos;
	size_t left;
	size_t nbytes;  /* number of bytes read in one iteration */
	size_t request; /* number of requested bytes in one iteration */
	size_t count;   /* number of bytes already read */
	/*
	 * number of leading bytes from start of the block
	 * to the first byte to be read
	 */
	size_t skip;

	/*
	 * number of trailing bytes between the last byte
	 * to be read and the end of the block
	 */
	size_t padding;

	/*
	 * We don't know the number of bytes that we are going
	 * to write in every iteration, because it will depend
	 * on the low level driver.
	 */
	count = 0;
	pos = addr & MMC_BLOCK_MASK;
	base = addr - pos;
	for (left = length; left > 0U; left -= nbytes) {
		/*
		 * We must only request operations aligned to the block
		 * size. Therefore if pos is not block-aligned,
		 * we have to request the operation to start at the
		 * previous block boundary and skip the leading bytes. And
		 * similarly, the number of bytes requested must be a
		 * block size multiple
		 */
		skip = pos & MMC_BLOCK_MASK;

		/*
		 * Calculate the block number containing pos
		 * - e.g. block 3.
		 */
		lba = (pos + base) / MMC_BLOCK_SIZE;
		request = MMC_BLOCK_SIZE;

		/*
		 * The number of bytes that we are going to write
		 * from the user buffer will depend of the size
		 * of the current request.
		 */
		nbytes = request - skip;
		padding = (nbytes > left) ? nbytes - left : 0U;
		nbytes -= padding;

		/*
		 * If we have skip or padding bytes then we have to preserve
		 * some content and it means that we have to read before
		 * writing
		 */
		if ((skip > 0U) || (padding > 0U)) {
			request = mmc_read_blocks(dev->dev_flash, lba, buf,
						  MMC_BLOCK_SIZE);

			/*
			 * The read may return size less than
			 * requested. Round down to the nearest block
			 * boundary
			 */
			request &= ~MMC_BLOCK_MASK;
			if (request <= skip) {
				/*
				 * We couldn't read enough bytes to jump over
				 * the skip bytes, so we should have to read
				 * again the same block, thus generating
				 * the same error.
				 */
				return -EIO;
			}

			nbytes = request - skip;
			padding = (nbytes > left) ? nbytes - left : 0U;
			nbytes -= padding;
		}

		memcpy((void *)(buf + skip), (void *)(buffer + count), nbytes);

		request = mmc_write_blocks(dev->dev_flash, lba, buf,
					   MMC_BLOCK_SIZE);
		if (request <= skip) {
			return -EIO;
		}

		/*
		 * And the previous write operation may modify the size
		 * of the request, so again, we have to calculate the
		 * number of bytes that we consumed from the user
		 * buffer
		 */
		nbytes = request - skip;
		padding = (nbytes > left) ? nbytes - left : 0U;
		nbytes -= padding;

		pos += nbytes;
		count += nbytes;
	}

	*length_written = count;

	return 0;
}

static ARM_DRIVER_VERSION ARM_Part_GetVersion(void)
{
	return DriverVersion;
}

static ARM_FLASH_CAPABILITIES ARM_Part_GetCapabilities(void)
{
	return DriverCapabilities;
}

static int32_t ARM_Part_X_Initialize(arm_part_dev_t *dev,
				     ARM_Flash_SignalEvent_t cb_event)
{
	return ARM_DRIVER_OK;
}

static int32_t ARM_Part_X_Uninitialize(arm_part_dev_t *dev)
{
	return ARM_DRIVER_OK;
}

static int32_t ARM_Part_X_PowerControl(arm_part_dev_t *dev,
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

static int32_t ARM_Part_X_ReadData(arm_part_dev_t *dev, uint32_t addr,
				   void *data, uint32_t cnt)
{
	uint32_t bytes = cnt * data_width_byte[DriverCapabilities.data_width];
	size_t length_read;
	int ret;

	dev->status.error = DRIVER_STATUS_NO_ERROR;

	/* Check Flash memory boundaries */
	if (!is_range_valid(dev, addr + bytes - 1U)) {
		dev->status.error = DRIVER_STATUS_ERROR;
		return ARM_DRIVER_ERROR_PARAMETER;
	}

	dev->status.busy = DRIVER_STATUS_BUSY;

	ret = block_read(dev, addr, (uintptr_t)data, bytes, &length_read);

	dev->status.busy = DRIVER_STATUS_IDLE;

	if (ret || (length_read != bytes)) {
		dev->status.error = DRIVER_STATUS_ERROR;
		return ARM_DRIVER_ERROR;
	}

	return cnt;
}

static int32_t ARM_Part_X_ProgramData(arm_part_dev_t *dev, uint32_t addr,
				      const void *data, uint32_t cnt)
{
	uint32_t bytes = cnt * data_width_byte[DriverCapabilities.data_width];
	size_t length_write;
	int ret;

	dev->status.error = DRIVER_STATUS_NO_ERROR;

	/* Check Flash memory boundaries */
	if (!(is_range_valid(dev, addr + bytes - 1U) &&
	    is_write_aligned(dev, addr) &&
	    is_write_aligned(dev, bytes))) {
		dev->status.error = DRIVER_STATUS_ERROR;
		return ARM_DRIVER_ERROR_PARAMETER;
	}

	dev->status.busy = DRIVER_STATUS_BUSY;

	ret = block_write(dev, addr, (uintptr_t)data, bytes, &length_write);

	dev->status.busy = DRIVER_STATUS_IDLE;

	if (ret || (length_write != bytes)) {
		dev->status.error = DRIVER_STATUS_ERROR;
		return ARM_DRIVER_ERROR;
	}

	return cnt;
}

static int32_t ARM_Part_X_EraseSector(arm_part_dev_t *dev, uint32_t addr)
{
	size_t length_erase;
	int lba;

	dev->status.error = DRIVER_STATUS_NO_ERROR;
	dev->status.busy = DRIVER_STATUS_BUSY;
	lba = addr / MMC_BLOCK_SIZE;

	length_erase = mmc_erase_blocks(dev->dev_flash, lba, MMC_BLOCK_SIZE);

	dev->status.busy = DRIVER_STATUS_IDLE;

	if (length_erase != MMC_BLOCK_SIZE) {
		dev->status.error = DRIVER_STATUS_ERROR;
		return ARM_DRIVER_ERROR;
	}

	return ARM_DRIVER_OK;
}

static int32_t ARM_Part_X_EraseChip(arm_part_dev_t *dev)
{
	return ARM_DRIVER_ERROR_UNSUPPORTED;
}

static ARM_FLASH_STATUS ARM_Part_X_GetStatus(arm_part_dev_t *dev)
{
	return dev->status;
}

static ARM_FLASH_INFO * ARM_Part_X_GetInfo(arm_part_dev_t *dev)
{
	return dev->data;
}

static int ARM_Part_X_Init(arm_part_dev_t *dev)
{
	dev->size = mmc_get_device_size(dev->dev_flash);

	return 0;
}

#define DRIVER_FLASH_MMC(name)								\
static ARM_FLASH_INFO PART_DATA_##name = {						\
	.sector_info  = NULL, /* Uniform sector layout */				\
	.sector_size = MMC_BLOCK_SIZE,							\
	.page_size = MMC_BLOCK_SIZE,							\
	.program_unit = 1U,								\
	.erased_value = 0xFFU,								\
};											\
											\
static arm_part_dev_t PART_DEV_##name = {						\
	.dev_flash = DEVICE_DT_GET(DT_NODELABEL(name)),					\
	.data = &(PART_DATA_##name),							\
	.status = {									\
		.busy = DRIVER_STATUS_IDLE,						\
		.error = DRIVER_STATUS_NO_ERROR,					\
		.reserved = 0U,								\
	},										\
};											\
											\
static int32_t ARM_Part_##name##_Initialize(ARM_Flash_SignalEvent_t cb_event)		\
{											\
	return ARM_Part_X_Initialize(&PART_DEV_##name, cb_event);			\
}											\
											\
static int32_t ARM_Part_##name##_Uninitialize(void)					\
{											\
	return ARM_Part_X_Uninitialize(&PART_DEV_##name);				\
}											\
											\
static int32_t ARM_Part_##name##_PowerControl(ARM_POWER_STATE state)			\
{											\
	return ARM_Part_X_PowerControl(&PART_DEV_##name, state);			\
}											\
											\
static int32_t ARM_Part_##name##_ReadData(uint32_t addr, void *data, uint32_t cnt)	\
{											\
	return ARM_Part_X_ReadData(&PART_DEV_##name, addr, data, cnt);			\
}											\
											\
static int32_t ARM_Part_##name##_ProgramData(uint32_t addr,				\
					     const void *data, uint32_t cnt)		\
{											\
	return ARM_Part_X_ProgramData(&PART_DEV_##name, addr, data, cnt);		\
}											\
											\
static int32_t ARM_Part_##name##_EraseSector(uint32_t addr)				\
{											\
	return ARM_Part_X_EraseSector(&PART_DEV_##name, addr);				\
}											\
											\
static int32_t ARM_Part_##name##_EraseChip(void)					\
{											\
	return ARM_Part_X_EraseChip(&PART_DEV_##name);					\
}											\
											\
static ARM_FLASH_STATUS ARM_Part_##name##_GetStatus(void)				\
{											\
	return ARM_Part_X_GetStatus(&PART_DEV_##name);					\
}											\
											\
static ARM_FLASH_INFO * ARM_Part_##name##_GetInfo(void)					\
{											\
	return ARM_Part_X_GetInfo(&PART_DEV_##name);					\
}											\
											\
static int ARM_Part_##name##_Init(void)							\
{											\
	return ARM_Part_X_Init(&PART_DEV_##name);					\
}											\
											\
extern ARM_DRIVER_FLASH Driver_##name;							\
ARM_DRIVER_FLASH Driver_##name = {							\
	ARM_Part_GetVersion,								\
	ARM_Part_GetCapabilities,							\
	ARM_Part_##name##_Initialize,							\
	ARM_Part_##name##_Uninitialize,							\
	ARM_Part_##name##_PowerControl,							\
	ARM_Part_##name##_ReadData,							\
	ARM_Part_##name##_ProgramData,							\
	ARM_Part_##name##_EraseSector,							\
	ARM_Part_##name##_EraseChip,							\
	ARM_Part_##name##_GetStatus,							\
	ARM_Part_##name##_GetInfo							\
};

#ifdef STM32_FLASH_SDMMC1
DRIVER_FLASH_MMC(sdmmc1);
SYS_INIT(ARM_Part_sdmmc1_Init, CORE, 13);
#endif

#ifdef STM32_FLASH_SDMMC2
DRIVER_FLASH_MMC(sdmmc2);
SYS_INIT(ARM_Part_sdmmc2_Init, CORE, 13);
#endif
