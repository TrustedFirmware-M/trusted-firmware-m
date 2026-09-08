/*
 * Copyright (c) 2026, STMicroelectronics - All Rights Reserved
 * Author(s): Ludovic Barre, <ludovic.barre@st.com> for STMicroelectronics.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
/*
 * This driver allows to read/write/erase on devices which are directly
 * memory mapped like ddr/backupram/bkpregister/sram ...
 */
#include <string.h>
#include <stdint.h>
#include <lib/utils_def.h>
#include <Driver_Flash.h>
#include <clk.h>
#include <flash_layout.h>
#include <device.h>
#include <device_cfg.h>
#include <target_cfg.h>

#ifndef ARG_UNUSED
#define ARG_UNUSED(arg)  ((void)arg)
#endif

/* Driver version */
#define ARM_FLASH_DRV_VERSION      ARM_DRIVER_VERSION_MAJOR_MINOR(1, 1)

/* Chip erase capability values */
#define CHIP_ERASE_NOT_SUPPORTED    (0u)
#define CHIP_ERASE_SUPPORTED        (1u)

#define GET_MEM_ADDR_BIT0(x)        ((x) & 0x1)
#define GET_MEM_ADDR_BIT1(x)        ((x) & 0x2)

union mem_addr_t {
    uintptr_t uint_addr;        /* Address          */
    uint8_t *p_byte;            /* Byte copy        */
    uint16_t *p_dbyte;          /* Double byte copy */
    uint32_t *p_qbyte;          /* Quad byte copy   */
};

/* Flash busy values flash status  \ref ARM_FLASH_STATUS */
enum {
	DRIVER_STATUS_IDLE = 0u,
	DRIVER_STATUS_BUSY
};

/* Flash error values flash status  \ref ARM_FLASH_STATUS */
enum {
	DRIVER_STATUS_NO_ERROR = 0u,
	DRIVER_STATUS_ERROR
};

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
	ARM_FLASH_EVENT_READY,
	DATA_WIDTH_8BIT,
	CHIP_ERASE_SUPPORTED
};

/*
 * ARM FLASH device structure
 */
typedef struct {
	const uint32_t memory_base;   /*!< FLASH memory base address */
	const struct device *clk_dev;
	uint32_t clock_id;
	ARM_FLASH_INFO *data;         /*!< FLASH data */
	ARM_FLASH_STATUS status;
} arm_flash_dev_t;

/* Driver Version */
static const ARM_DRIVER_VERSION DriverVersion = {
	ARM_FLASH_API_VERSION,
	ARM_FLASH_DRV_VERSION
};

/*
 * mcuboot uses nano libc, its memcpy copies byte by byte.
 * For program unit > 1, the data sizeof must be respected.
 * example: bkreg must be written word by word (programme unit = 4),
 * its dest address and cnt is aligned on word -> copy by uint.
 * Caller check: modulo write (programm unit)
 */
static void *mm_memcpy(void *dest, const void *src, size_t n)
{
	union mem_addr_t p_dest, p_src;

	p_dest.uint_addr = (uintptr_t)dest;
	p_src.uint_addr = (uintptr_t)src;

	/* Byte copy check the last bit of address. */
	while (n && (GET_MEM_ADDR_BIT0(p_dest.uint_addr) ||
		     GET_MEM_ADDR_BIT0(p_src.uint_addr))) {
		*p_dest.p_byte++ = *p_src.p_byte++;
		n--;
	}

	/*
	 * Double byte copy for aligned address.
	 * Check the 2nd last bit of address.
	 */
	while (n >= sizeof(uint16_t) && (GET_MEM_ADDR_BIT1(p_dest.uint_addr) ||
					 GET_MEM_ADDR_BIT1(p_src.uint_addr))) {
		*(p_dest.p_dbyte)++ = *(p_src.p_dbyte)++;
		n -= sizeof(uint16_t);
	}

	/* Quad byte copy for aligned address. */
	while (n >= sizeof(uint32_t)) {
		*(p_dest.p_qbyte)++ = *(p_src.p_qbyte)++;
		n -= sizeof(uint32_t);
	}

	/* Byte copy for the remaining bytes. */
	while (n--) {
		*p_dest.p_byte++ = *p_src.p_byte++;
	}

	return dest;
}

void *mm_memset(void *s, int c, size_t n)
{
	union mem_addr_t p_mem;
	uint32_t quad_pattern;

	p_mem.p_byte = (uint8_t *)s;
	quad_pattern = (((uint8_t)c) << 24) | (((uint8_t)c) << 16) |
		(((uint8_t)c) << 8) | ((uint8_t)c);

	while (n && (p_mem.uint_addr & (sizeof(uint32_t) - 1))) {
		*p_mem.p_byte++ = (uint8_t)c;
		n--;
	}

	while (n >= sizeof(uint32_t)) {
		*p_mem.p_qbyte++ = quad_pattern;
		n -= sizeof(uint32_t);
	}

	while (n--) {
		*p_mem.p_byte++ = (uint8_t)c;
	}

	return s;
}

static __maybe_unused bool is_range_valid(arm_flash_dev_t *flash_dev,
					  uint32_t offset)
{
	uint32_t flash_sz = (flash_dev->data->sector_count * flash_dev->data->sector_size);

	return offset < flash_sz ? true : false;
}

static __maybe_unused ARM_DRIVER_VERSION ARM_Flash_GetVersion(void)
{
	return DriverVersion;
}

static __maybe_unused ARM_FLASH_CAPABILITIES ARM_Flash_GetCapabilities(void)
{
	return DriverCapabilities;
}

static __maybe_unused int32_t ARM_Flash_X_Initialize(arm_flash_dev_t *flash_dev,
						     ARM_Flash_SignalEvent_t cb_event)
{
	ARG_UNUSED(cb_event);
	ARG_UNUSED(flash_dev);

	/* Nothing to be done */
	return ARM_DRIVER_OK;
}

static __maybe_unused int32_t ARM_Flash_X_Uninitialize(arm_flash_dev_t *flash_dev)
{
	ARG_UNUSED(flash_dev);

	/* Nothing to be done */
	return ARM_DRIVER_OK;
}

static __maybe_unused int32_t ARM_Flash_X_PowerControl(arm_flash_dev_t *flash_dev,
						       ARM_POWER_STATE state)
{
	ARG_UNUSED(flash_dev);

	switch (state) {
	case ARM_POWER_FULL:
		/* Nothing to be done */
		return ARM_DRIVER_OK;
		break;

	case ARM_POWER_OFF:
	case ARM_POWER_LOW:
	default:
		return ARM_DRIVER_ERROR_UNSUPPORTED;
	}
}

static bool mm_clk_enable(arm_flash_dev_t *flash_dev)
{
	struct clk *clk = clk_get(flash_dev->clk_dev, (clk_subsys_t) flash_dev->clock_id);

	if (clk && !clk_is_enabled(clk)) {
		clk_enable(clk);
		return true;
	}

	return false;
}

static void mm_clk_disable(arm_flash_dev_t *flash_dev, bool clk_enabled)
{
	struct clk *clk = clk_get(flash_dev->clk_dev, (clk_subsys_t) flash_dev->clock_id);

	if (clk && clk_enabled)
		clk_disable(clk);
}

static __maybe_unused int32_t ARM_Flash_X_ReadData(arm_flash_dev_t *flash_dev,
						   uint32_t addr, void *data,
						   uint32_t cnt)
{
	uint32_t prog_unit = flash_dev->data->program_unit;
	uint32_t start_addr = flash_dev->memory_base + addr;
	uint32_t bytes = cnt * data_width_byte[DriverCapabilities.data_width];
	uint32_t last_ofst = addr + bytes - 1;
	bool clk_enabled;

	flash_dev->status.error = DRIVER_STATUS_NO_ERROR;

	/* checks write alignment on program_unit. */
	if ((addr % prog_unit) || (bytes % prog_unit))
		return ARM_DRIVER_ERROR_PARAMETER;

	/* Check flash memory boundaries */
	if (!is_range_valid(flash_dev, last_ofst)) {
		flash_dev->status.error = DRIVER_STATUS_ERROR;
		return ARM_DRIVER_ERROR_PARAMETER;
	}

	flash_dev->status.busy = DRIVER_STATUS_BUSY;
	clk_enabled = mm_clk_enable(flash_dev);

	mm_memcpy(data, (void *)start_addr, bytes);

	mm_clk_disable(flash_dev, clk_enabled);
	flash_dev->status.busy = DRIVER_STATUS_IDLE;

	return cnt;
}

static __maybe_unused int32_t ARM_Flash_X_ProgramData(arm_flash_dev_t *flash_dev,
						      uint32_t addr,
						      const void *data,
						      uint32_t cnt)
{
	uint32_t prog_unit = flash_dev->data->program_unit;
	uint32_t start_addr = flash_dev->memory_base + addr;
	uint32_t bytes = cnt * data_width_byte[DriverCapabilities.data_width];
	uint32_t last_ofst = addr + bytes - 1;
	bool clk_enabled;

	flash_dev->status.error = DRIVER_STATUS_NO_ERROR;

	/* checks write alignment on program_unit. */
	if ((addr % prog_unit) || (bytes % prog_unit))
		return ARM_DRIVER_ERROR_PARAMETER;

	/* Check flash memory boundaries */
	if (!is_range_valid(flash_dev, last_ofst)) {
		flash_dev->status.error = DRIVER_STATUS_ERROR;
		return ARM_DRIVER_ERROR_PARAMETER;
	}

	flash_dev->status.busy = DRIVER_STATUS_BUSY;
	clk_enabled = mm_clk_enable(flash_dev);

	mm_memcpy((void *)start_addr, data, bytes);

	mm_clk_disable(flash_dev, clk_enabled);
	flash_dev->status.busy = DRIVER_STATUS_IDLE;

	return cnt;
}

static __maybe_unused int32_t ARM_Flash_X_EraseSector(arm_flash_dev_t *flash_dev,
						      uint32_t addr)
{
	uint32_t start_addr = flash_dev->memory_base + addr;
	uint32_t last_ofst = addr + flash_dev->data->sector_size - 1;
	bool clk_enabled;

	flash_dev->status.error = DRIVER_STATUS_NO_ERROR;

	/* checks alignment on sector size. */
	if (addr % flash_dev->data->sector_size)
		return ARM_DRIVER_ERROR_PARAMETER;

	if (!is_range_valid(flash_dev, last_ofst)) {
		flash_dev->status.error = DRIVER_STATUS_ERROR;
		return ARM_DRIVER_ERROR_PARAMETER;
	}

	flash_dev->status.busy = DRIVER_STATUS_BUSY;
	clk_enabled = mm_clk_enable(flash_dev);

	mm_memset((void *)start_addr,
		  flash_dev->data->erased_value,
		  flash_dev->data->sector_size);

	mm_clk_disable(flash_dev, clk_enabled);
	flash_dev->status.busy = DRIVER_STATUS_IDLE;

	return ARM_DRIVER_OK;
}

static __maybe_unused int32_t ARM_Flash_X_EraseChip(arm_flash_dev_t *flash_dev)
{
	uint32_t i;
	uint32_t addr = flash_dev->memory_base;
	int32_t rc = ARM_DRIVER_ERROR_UNSUPPORTED;
	bool clk_enabled;

	flash_dev->status.busy = DRIVER_STATUS_BUSY;
	flash_dev->status.error = DRIVER_STATUS_NO_ERROR;
	clk_enabled = mm_clk_enable(flash_dev);

	/* Check driver capability erase_chip bit */
	if (DriverCapabilities.erase_chip == 1) {
		for (i = 0; i < flash_dev->data->sector_count; i++) {
			mm_memset((void *)addr,
				  flash_dev->data->erased_value,
				  flash_dev->data->sector_size);

			addr += flash_dev->data->sector_size;
			rc = ARM_DRIVER_OK;
		}
	}

	mm_clk_disable(flash_dev, clk_enabled);
	flash_dev->status.busy = DRIVER_STATUS_IDLE;

	return rc;
}

static __maybe_unused ARM_FLASH_STATUS ARM_Flash_X_GetStatus(arm_flash_dev_t *flash_dev)
{
	return flash_dev->status;
}

static __maybe_unused ARM_FLASH_INFO * ARM_Flash_X_GetInfo(arm_flash_dev_t *flash_dev)
{
	return flash_dev->data;
}

/* Per-FLASH macros */
/* Each instance must define:
 * - Driver_FLASH_XX
 * - FLASH_XX_CLK
 * - FLASH_XX_SIZE
 * - FLASH_XX_SECTOR_SIZE
 * - FLASH_XX_PROGRAM_UNIT
 */
#define DRIVER_FLASH_X(devname)									\
static ARM_FLASH_INFO FLASH_##devname##_DATA = {						\
	.sector_info  = NULL,                  /* Uniform sector layout */			\
	.sector_count = FLASH_##devname##_SIZE / FLASH_##devname##_SECTOR_SIZE,			\
	.sector_size  = FLASH_##devname##_SECTOR_SIZE,						\
	.program_unit = FLASH_##devname##_PROGRAM_UNIT,						\
	.erased_value = 0x0,									\
};												\
												\
static arm_flash_dev_t FLASH_##devname##_DEV = {						\
	.memory_base = FLASH_##devname##_BASE,							\
	.clk_dev = DEVICE_DT_GET(DT_NODELABEL(rcc)),						\
	.clock_id = FLASH_##devname##_CLK,							\
	.data = &(FLASH_##devname##_DATA),							\
	.status = {										\
		.busy = DRIVER_STATUS_IDLE,							\
		.error = DRIVER_STATUS_NO_ERROR,						\
		.reserved = 0,									\
	},											\
};												\
												\
static int32_t ARM_Flash_##devname##_Initialize(ARM_Flash_SignalEvent_t cb_event)		\
{												\
	return ARM_Flash_X_Initialize(&FLASH_##devname##_DEV, cb_event);			\
}												\
												\
static int32_t ARM_Flash_##devname##_Uninitialize(void)						\
{												\
	return ARM_Flash_X_Uninitialize(&FLASH_##devname##_DEV);				\
}												\
												\
static int32_t ARM_Flash_##devname##_PowerControl(ARM_POWER_STATE state)			\
{												\
	return ARM_Flash_X_PowerControl(&FLASH_##devname##_DEV, state);				\
}												\
												\
static int32_t ARM_Flash_##devname##_ReadData(uint32_t addr, void *data, uint32_t cnt)		\
{												\
	return ARM_Flash_X_ReadData(&FLASH_##devname##_DEV, addr, data, cnt);			\
}												\
												\
static int32_t ARM_Flash_##devname##_ProgramData(uint32_t addr,					\
						 const void *data, uint32_t cnt)		\
{												\
	return ARM_Flash_X_ProgramData(&FLASH_##devname##_DEV, addr, data, cnt);		\
}												\
												\
static int32_t ARM_Flash_##devname##_EraseSector(uint32_t addr)					\
{												\
	return ARM_Flash_X_EraseSector(&FLASH_##devname##_DEV, addr);				\
}												\
												\
static int32_t ARM_Flash_##devname##_EraseChip(void)						\
{												\
	return ARM_Flash_X_EraseChip(&FLASH_##devname##_DEV);					\
}												\
												\
static ARM_FLASH_STATUS ARM_Flash_##devname##_GetStatus(void)					\
{												\
	return ARM_Flash_X_GetStatus(&FLASH_##devname##_DEV);					\
}												\
												\
static ARM_FLASH_INFO * ARM_Flash_##devname##_GetInfo(void)					\
{												\
	return ARM_Flash_X_GetInfo(&FLASH_##devname##_DEV);					\
}												\
												\
extern ARM_DRIVER_FLASH Driver_FLASH_##devname;							\
ARM_DRIVER_FLASH Driver_FLASH_##devname = {							\
	ARM_Flash_GetVersion,									\
	ARM_Flash_GetCapabilities,								\
	ARM_Flash_##devname##_Initialize,							\
	ARM_Flash_##devname##_Uninitialize,							\
	ARM_Flash_##devname##_PowerControl,							\
	ARM_Flash_##devname##_ReadData,								\
	ARM_Flash_##devname##_ProgramData,							\
	ARM_Flash_##devname##_EraseSector,							\
	ARM_Flash_##devname##_EraseChip,							\
	ARM_Flash_##devname##_GetStatus,							\
	ARM_Flash_##devname##_GetInfo								\
}

#ifdef STM32_FLASH_DDR
DRIVER_FLASH_X(DDR);
#endif

#ifdef STM32_FLASH_BKPSRAM
DRIVER_FLASH_X(BKPSRAM);
#endif

#ifdef STM32_FLASH_BKPREG
DRIVER_FLASH_X(BKPREG);
#endif

#ifdef STM32_FLASH_RETRAM
DRIVER_FLASH_X(RETRAM);
#endif
