/*
 * Copyright (c) 2026, STMicroelectronics - All Rights Reserved
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
/*
 * Allow to overwrite functions defined in platform/ext/common/boot_hal.c
 * for specific needs of stm32mp2
 */
#include <stdio.h>
#include <stdbool.h>
#include <errno.h>

#include <boot_hal.h>
#include <cmsis.h>
#include <device.h>
#include <region.h>
#include <region_defs.h>
#include <Driver_Flash.h>
#include <bootutil/bootutil_log.h>
#include <init.h>
#include <debug.h>
#include <partition.h>
#include "flash_map/flash_map.h"
#include <lib/utils_def.h>

#include <stm32mp2_ddr.h>
#include <stm32_bsec3.h>
#include <stm32_dcache.h>
#include <stm32_tamp.h>
#include <stm_version.h>
#include <watchdog.h>

#ifdef CRYPTO_HW_ACCELERATOR
#include "crypto_hw.h"
#endif /* CRYPTO_HW_ACCELERATOR */

extern ARM_DRIVER_FLASH FLASH_DEV_NAME_0;
extern ARM_DRIVER_FLASH FLASH_DEV_NAME_1;
extern ARM_DRIVER_FLASH FLASH_DEV_NAME_2;
extern ARM_DRIVER_FLASH FLASH_DEV_NAME_3;
#if (MCUBOOT_IMAGE_NUMBER == 3)
extern ARM_DRIVER_FLASH FLASH_DEV_NAME_4;
extern ARM_DRIVER_FLASH FLASH_DEV_NAME_5;
#endif /* (MCUBOOT_IMAGE_NUMBER == 3) */

int flash_device_base(uint8_t fd_id, uintptr_t *ret)
{
	/* Only primary and secondary TFM_S_NS slots are allowed */
	if ((fd_id != FLASH_DEVICE_ID_0) && (fd_id != FLASH_DEVICE_ID_2)) {
		BOOT_LOG_ERR("invalid flash ID %d; expected %d or %d",
			     fd_id, FLASH_DEVICE_ID_0, FLASH_DEVICE_ID_2);
		return -1;
	}
	*ret = FLASH_DEVICE_BASE;
	return 0;
}

int stm32mp2_init_debug(void)
{
#if defined(DAUTH_NONE)
	stm32_bsec_write_debug_conf(DBG_PERM_MASK_NONE);
#elif defined(DAUTH_NS_ONLY)
	stm32_bsec_write_debug_conf(DBG_PERM_MASK_NS_ONLY);
#elif defined(DAUTH_FULL)
	BOOT_LOG_WRN("\033[1;31m*******************************\033[0m");
	BOOT_LOG_WRN("\033[1;31m* The debug port is full open *\033[0m");
	BOOT_LOG_WRN("\033[1;31m* wait debugger interrupt     *\033[0m");
	BOOT_LOG_WRN("\033[1;31m*******************************\033[0m");
	stm32_bsec_write_debug_conf(DBG_PERM_MASK_FULL);
	__WFI();
#else
#if !defined(DAUTH_CHIP_DEFAULT)
#error "No debug authentication setting is provided."
#endif
#endif
	return 0;
}
SYS_INIT(stm32mp2_init_debug, CORE, 11);

#if defined(STM32_BOOT_DEV_SDMMC1) || defined(STM32_BOOT_DEV_SDMMC2)
extern struct flash_area flash_map[];

static int stm32mp2_prepare_fw(void)
{
	const partition_entry_t *tfm_entry;

        tfm_entry = get_partition_entry("m33fw-a");
	if (tfm_entry == NULL) {
		BOOT_LOG_ERR("Could not find partition tfm primary partition");
		return -EINVAL;
	}

	flash_map[0].fa_off = tfm_entry->start;
	flash_map[0].fa_size = tfm_entry->length;

	tfm_entry = get_partition_entry("m33fw-b");
	if (tfm_entry == NULL) {
		BOOT_LOG_ERR("Could not find partition tfm secondary partition");
		return -EINVAL;
	}

	flash_map[1].fa_off = tfm_entry->start;
	flash_map[1].fa_size = tfm_entry->length;

	tfm_entry = get_partition_entry("m33ddr-a");
	if (tfm_entry == NULL) {
		BOOT_LOG_ERR("Could not find partition ddr fw primary partition");
		return -EINVAL;
	}

	flash_map[2].fa_off = tfm_entry->start;
	flash_map[2].fa_size = tfm_entry->length;

	tfm_entry = get_partition_entry("m33ddr-b");
	if (tfm_entry == NULL) {
		BOOT_LOG_ERR("Could not find partition ddr fw secondary partition");
		return -EINVAL;
	}

	flash_map[3].fa_off = tfm_entry->start;
	flash_map[3].fa_size = tfm_entry->length;

	return 0;
}
SYS_INIT(stm32mp2_prepare_fw, CORE, 15);
#endif /* defined(STM32_BOOT_DEV_SDMMC1) || defined(STM32_BOOT_DEV_SDMMC2) */

#if (DT_NODE_EXISTS(DT_NODELABEL(ca35_cube_fw))) && (MCUBOOT_IMAGE_NUMBER == 3)
static int stm32mp2_prep_a35_fw(void) {
	const struct device *dev = DEVICE_DT_GET(DT_NODELABEL(tamp));
	int err = 0;
#if defined(STM32_BOOT_DEV_SDMMC1) || defined(STM32_BOOT_DEV_SDMMC2)
	const partition_entry_t *tfm_entry = NULL;

	tfm_entry = get_partition_entry("a35fw-a");
	if (tfm_entry == NULL) {
		BOOT_LOG_ERR("Could not find cortex A35 firmware partition");
		return -EINVAL;
	}

	flash_map[4].fa_off = tfm_entry->start;
	flash_map[4].fa_size = tfm_entry->length;

	/* TODO: remove*/
	flash_map[5].fa_off = tfm_entry->start;
	flash_map[5].fa_size = tfm_entry->length;
#endif /* defined(STM32_BOOT_DEV_SDMMC1) || defined(STM32_BOOT_DEV_SDMMC2) */

	/* Fill the backup register 72 with the load address of the firmware */
	err = stm32_tamp_bkpreg_write(dev, 72, CA35_FW_DEST_ADDR + BL2_HEADER_SIZE);
	if (err)
		BOOT_LOG_ERR("Error while writing CA35 load address in backup register 72");

	return err;
}
SYS_INIT(stm32mp2_prep_a35_fw, CORE, 30);
#endif /* (DT_NODE_EXISTS(DT_NODELABEL(ca35_cube_fw))) */

static int __unused stm32mp2_watchdog_init(void)
{
	int err;

	err = watchdog_start(NULL);
	if (err)
		BOOT_LOG_ERR("watchdog start fail:%d", err);

	return err;
}
#if DT_NODE_HAS_STATUS_OKAY(DT_CHOSEN(tfm_watchdog))
/*
 * If "tfm,watchdog" is defined in chosen node (DT) the system watchdog
 * is started at bootime. the timout must be defined in watchdog device node.
 */
SYS_INIT(stm32mp2_watchdog_init, POST_CORE, 1);
#endif

/**
  * @brief  Platform init
  * @param  None
  * @retval status
  */
int32_t boot_platform_init(void)
{
	sys_init_run_level(INIT_LEVEL_PRE_CORE);

	if (IS_ENABLED(STM32_CACHE_ENABLED)) {
		int err;

		err = stm32_dcache_enable(true, true);
		if (err)
			return err;
	}

	sys_init_run_level(INIT_LEVEL_CORE);

	return 0;
}

int32_t boot_platform_post_init(void)
{
	sys_init_run_level(INIT_LEVEL_POST_CORE);
	sys_init_run_level(INIT_LEVEL_REST);

	return 0;
}

void boot_platform_quit(struct boot_arm_vector_table *vt)
{
	/*
	 * Clang at O0, stores variables on the stack with SP relative addressing.
	 * When manually set the SP then the place of reset vector is lost.
	 * Static variables are stored in 'data' or 'bss' section, change of SP has
	 * no effect on them.
	 */
	static struct boot_arm_vector_table *vt_cpy;
	int32_t result;

	#ifdef CRYPTO_HW_ACCELERATOR
	result = crypto_hw_accelerator_finish();
	if (result) {
		while (1){}
	}
	#endif /* CRYPTO_HW_ACCELERATOR */

	#ifdef FLASH_DEV_NAME_0
	result = FLASH_DEV_NAME_0.Uninitialize();
	if (result != ARM_DRIVER_OK) {
		while(1) {}
	}
	#endif /* FLASH_DEV_NAME */
	#ifdef FLASH_DEV_NAME_1
	result = FLASH_DEV_NAME_1.Uninitialize();
	if (result != ARM_DRIVER_OK) {
		while(1) {}
	}
	#endif /* FLASH_DEV_NAME */
	#ifdef FLASH_DEV_NAME_2
	result = FLASH_DEV_NAME_2.Uninitialize();
	if (result != ARM_DRIVER_OK) {
		while(1) {}
	}
	#endif /* FLASH_DEV_NAME_2 */
	#ifdef FLASH_DEV_NAME_3
	result = FLASH_DEV_NAME_3.Uninitialize();
	if (result != ARM_DRIVER_OK) {
		while(1) {}
	}
	#endif /* FLASH_DEV_NAME_3 */
#if (MCUBOOT_IMAGE_NUMBER == 3)
	#ifdef FLASH_DEV_NAME_4
	result = FLASH_DEV_NAME_4.Uninitialize();
	if (result != ARM_DRIVER_OK) {
		while(1) {}
	}
	#endif /* FLASH_DEV_NAME_4 */
	#ifdef FLASH_DEV_NAME_5
	result = FLASH_DEV_NAME_5.Uninitialize();
	if (result != ARM_DRIVER_OK) {
		while(1) {}
	}
	#endif /* FLASH_DEV_NAME_5 */
#endif /* (MCUBOOT_IMAGE_NUMBER == 3)*/
	#ifdef FLASH_DEV_NAME_SCRATCH
	result = FLASH_DEV_NAME_SCRATCH.Uninitialize();
	if (result != ARM_DRIVER_OK) {
		while(1) {}
	}
	#endif /* FLASH_DEV_NAME_SCRATCH */

	if(stm32_bsec_increment_hdpl()){
		EMSG("failed to increment HDPL\n");
		panic();
	}

	vt_cpy = vt;
	#if defined(__ARM_ARCH_8M_MAIN__) || defined(__ARM_ARCH_8M_BASE__) \
	|| defined(__ARM_ARCH_8_1M_MAIN__)
	/*
	 * Restore the Main Stack Pointer Limit register's reset value
	 * before passing execution to runtime firmware to make the
	 * bootloader transparent to it.
	 */
	__set_MSPLIM(0);
	#endif /* defined(__ARM_ARCH_8M_MAIN__) || defined(__ARM_ARCH_8M_BASE__) \
	|| defined(__ARM_ARCH_8_1M_MAIN__) */

	if (IS_ENABLED(STM32_CACHE_ENABLED)){
		/* Invalidate all the memory range accessible by the M-33 */
		if (stm32_dcache_clean(0x0, 0xFFFFFFFF))
			panic();
		if (stm32_dcache_full_inv())
			panic();
		if (stm32_dcache_disable())
			panic();
	}

	__set_MSP(vt_cpy->msp);
	__DSB();
	__ISB();

	boot_jump_to_next_image(vt_cpy->reset);
}

int boot_platform_post_load(uint32_t image_id)
{
	if (image_id == DDR_FIRMWARE_ID) {
		BOOT_LOG_INF("BL2: image %d, enable DDR-FW", image_id);
		stm32mp2_ddr_dt_init();
	}
	return 0;
}
