/**
  ******************************************************************************
  * @file    low_level_device.c
  * @author  MCD Application Team
  * @brief   This file contains device definition for low_level_device
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */

#include "flash_layout.h"
#include "low_level_flash.h"

/* Marker for flash drivers located on internal flash */
#define TFM_Driver_FLASH0_IS_INTERNAL_FLASH 1

/* Helper to test at compile time whether a given flash driver is the internal SOC flash driver:
 * An unknown driver token expands to 0 (undefined identifier) in #if.
 */
#define _FLASH_DRIVER_CONCAT(a, b) a ## b
#define _FLASH_DRIVER_EXPAND(a, b) _FLASH_DRIVER_CONCAT(a, b)
#define FLASH_DRIVER_IS_INTERNAL(drv) (_FLASH_DRIVER_EXPAND(drv, _IS_INTERNAL_FLASH) == 1)

/* When undefined FLASH_DEV_NAME_0 or FLASH_DEVICE_ID_0, default */
#if !defined(FLASH_DEV_NAME_0) || !defined(FLASH_DEVICE_ID_0)
#define FLASH_DEV_NAME_0  FLASH_DEV_NAME
#define FLASH_DEVICE_ID_0 FLASH_DEVICE_ID
#endif

/* When undefined FLASH_DEV_NAME_1 or FLASH_DEVICE_ID_1, default */
#if !defined(FLASH_DEV_NAME_1) || !defined(FLASH_DEVICE_ID_1)
#define FLASH_DEV_NAME_1  FLASH_DEV_NAME
#define FLASH_DEVICE_ID_1 FLASH_DEVICE_ID
#endif

/* When undefined FLASH_DEV_NAME_2 or FLASH_DEVICE_ID_2, default */
#if !defined(FLASH_DEV_NAME_2) || !defined(FLASH_DEVICE_ID_2)
#define FLASH_DEV_NAME_2  FLASH_DEV_NAME
#define FLASH_DEVICE_ID_2 FLASH_DEVICE_ID
#endif

/* When undefined FLASH_DEV_NAME_3 or FLASH_DEVICE_ID_3, default */
#if !defined(FLASH_DEV_NAME_3) || !defined(FLASH_DEVICE_ID_3)
#define FLASH_DEV_NAME_3  FLASH_DEV_NAME
#define FLASH_DEVICE_ID_3 FLASH_DEVICE_ID
#endif

/* When undefined FLASH_DEV_NAME_SCRATCH or FLASH_DEVICE_ID_SCRATCH, default */
#if !defined(FLASH_DEV_NAME_SCRATCH) || !defined(FLASH_DEVICE_ID_SCRATCH)
#define FLASH_DEV_NAME_SCRATCH  FLASH_DEV_NAME
#define FLASH_DEVICE_ID_SCRATCH FLASH_DEVICE_ID
#endif

/* Flash area 0 (secure firmware) can only be located on internal flash */
#if !FLASH_DRIVER_IS_INTERNAL(FLASH_DEV_NAME_0)
#error "FLASH_DEV_NAME_0 must be the internal flash driver"
#endif

/* Partitions on SoC flash allowed to be written by TF-M */
static struct flash_range write_vect[] = {
#if FLASH_OTP_NV_COUNTERS_AREA_SIZE > 0
	{ FLASH_OTP_NV_COUNTERS_AREA_OFFSET, FLASH_OTP_NV_COUNTERS_AREA_OFFSET + FLASH_OTP_NV_COUNTERS_AREA_SIZE - 1 },
#endif
#if FLASH_AREA_SCRATCH_SIZE > 0 && FLASH_DRIVER_IS_INTERNAL(FLASH_DEV_NAME_SCRATCH)
	{ FLASH_AREA_SCRATCH_OFFSET, FLASH_AREA_SCRATCH_OFFSET + FLASH_AREA_SCRATCH_SIZE - 1 },
#endif
#if FLASH_AREA_0_SIZE > 0
	{ FLASH_AREA_0_OFFSET, FLASH_AREA_0_OFFSET + FLASH_AREA_0_SIZE - 1 },
#endif
#if FLASH_AREA_1_SIZE > 0 && FLASH_DRIVER_IS_INTERNAL(FLASH_DEV_NAME_1)
	{ FLASH_AREA_1_OFFSET, FLASH_AREA_1_OFFSET + FLASH_AREA_1_SIZE - 1 },
#endif
#if FLASH_AREA_2_SIZE > 0 && FLASH_DRIVER_IS_INTERNAL(FLASH_DEV_NAME_2)
	{ FLASH_AREA_2_OFFSET, FLASH_AREA_2_OFFSET + FLASH_AREA_2_SIZE - 1 },
#endif
#if FLASH_AREA_3_SIZE > 0 && FLASH_DRIVER_IS_INTERNAL(FLASH_DEV_NAME_3)
	{ FLASH_AREA_3_OFFSET, FLASH_AREA_3_OFFSET + FLASH_AREA_3_SIZE - 1 },
#endif
};

/* Partitions on SoC flash allowed to be erased by TF-M */
static struct flash_range erase_vect[] = {
#if FLASH_OTP_NV_COUNTERS_AREA_SIZE > 0
	{ FLASH_OTP_NV_COUNTERS_AREA_OFFSET, FLASH_OTP_NV_COUNTERS_AREA_OFFSET + FLASH_OTP_NV_COUNTERS_AREA_SIZE - 1 },
#endif
#if FLASH_AREA_SCRATCH_SIZE > 0 && FLASH_DRIVER_IS_INTERNAL(FLASH_DEV_NAME_SCRATCH)
	{ FLASH_AREA_SCRATCH_OFFSET, FLASH_AREA_SCRATCH_OFFSET + FLASH_AREA_SCRATCH_SIZE - 1 },
#endif
#if FLASH_AREA_0_SIZE > 0
	{ FLASH_AREA_0_OFFSET, FLASH_AREA_0_OFFSET + FLASH_AREA_0_SIZE - 1 },
#endif
#if FLASH_AREA_1_SIZE > 0 && FLASH_DRIVER_IS_INTERNAL(FLASH_DEV_NAME_1)
	{ FLASH_AREA_1_OFFSET, FLASH_AREA_1_OFFSET + FLASH_AREA_1_SIZE - 1 },
#endif
#if FLASH_AREA_2_SIZE > 0 && FLASH_DRIVER_IS_INTERNAL(FLASH_DEV_NAME_2)
	{ FLASH_AREA_2_OFFSET, FLASH_AREA_2_OFFSET + FLASH_AREA_2_SIZE - 1 },
#endif
#if FLASH_AREA_3_SIZE > 0 && FLASH_DRIVER_IS_INTERNAL(FLASH_DEV_NAME_3)
	{ FLASH_AREA_3_OFFSET, FLASH_AREA_3_OFFSET + FLASH_AREA_3_SIZE - 1 },
#endif
};

/* Partitions on SoC flash mapped to secure address range */
static struct flash_range secure_vect[] = {
#if FLASH_OTP_NV_COUNTERS_AREA_SIZE > 0
	{ FLASH_OTP_NV_COUNTERS_AREA_OFFSET, FLASH_OTP_NV_COUNTERS_AREA_OFFSET + FLASH_OTP_NV_COUNTERS_AREA_SIZE - 1 },
#endif
#if FLASH_AREA_SCRATCH_SIZE > 0 && FLASH_DRIVER_IS_INTERNAL(FLASH_DEV_NAME_SCRATCH)
	{ FLASH_AREA_SCRATCH_OFFSET, FLASH_AREA_SCRATCH_OFFSET + FLASH_AREA_SCRATCH_SIZE - 1 },
#endif
#if FLASH_AREA_0_SIZE > 0
	{ FLASH_AREA_0_OFFSET, FLASH_AREA_0_OFFSET + FLASH_AREA_0_SIZE - 1 },
#endif
};

struct low_level_device FLASH0_DEV = {
	.erase = { .nb = sizeof(erase_vect) / sizeof(struct flash_range), .range = erase_vect },
	.write = { .nb = sizeof(write_vect) / sizeof(struct flash_range), .range = write_vect },
	.secure = { .nb = sizeof(secure_vect) / sizeof(struct flash_range), .range = secure_vect },
	.read_error = 1
};
