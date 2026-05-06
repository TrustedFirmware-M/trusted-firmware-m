/**
  ******************************************************************************
  * @file    low_level_device.c
  * @author  MCD Application Team
  * @brief   This file contains device definition for low_level_device
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
#include "region_defs.h"
#include "low_level_flash.h"
static struct flash_range write_vect[] =
{
  { FLASH_OTP_NV_COUNTERS_AREA_OFFSET, FLASH_OTP_NV_COUNTERS_AREA_OFFSET + FLASH_OTP_NV_COUNTERS_AREA_SIZE},
  { FLASH_PS_AREA_OFFSET, FLASH_PS_AREA_OFFSET + FLASH_PS_AREA_SIZE - 1},
  { FLASH_ITS_AREA_OFFSET, FLASH_ITS_AREA_OFFSET + FLASH_ITS_AREA_SIZE - 1},

#if (MCUBOOT_S_DATA_IMAGE_NUMBER == 1)
  { S_DATA_IMAGE_PRIMARY_PARTITION_OFFSET + FLASH_S_DATA_PARTITION_SIZE - 32, S_DATA_IMAGE_PRIMARY_PARTITION_OFFSET + FLASH_S_DATA_PARTITION_SIZE - 16 - 1},
#endif /* (MCUBOOT_S_DATA_IMAGE_NUMBER == 1) */
};
static struct flash_range erase_vect[] =
{
  { FLASH_OTP_NV_COUNTERS_AREA_OFFSET, FLASH_OTP_NV_COUNTERS_AREA_OFFSET + FLASH_OTP_NV_COUNTERS_AREA_SIZE},
  { FLASH_PS_AREA_OFFSET, FLASH_PS_AREA_OFFSET + FLASH_PS_AREA_SIZE - 1},
  { FLASH_ITS_AREA_OFFSET, FLASH_ITS_AREA_OFFSET + FLASH_ITS_AREA_SIZE - 1},
};


static struct flash_range secure_vect[] =
{
  { FLASH_OTP_NV_COUNTERS_AREA_OFFSET, FLASH_OTP_NV_COUNTERS_AREA_OFFSET + FLASH_OTP_NV_COUNTERS_AREA_SIZE},
  { FLASH_PS_AREA_OFFSET, FLASH_PS_AREA_OFFSET + FLASH_PS_AREA_SIZE - 1},
  { FLASH_ITS_AREA_OFFSET, FLASH_ITS_AREA_OFFSET + FLASH_ITS_AREA_SIZE - 1},
};

struct low_level_device FLASH0_DEV =
{
  .erase = { .nb = sizeof(erase_vect) / sizeof(struct flash_range), .range = erase_vect},
  .write = { .nb = sizeof(write_vect) / sizeof(struct flash_range), .range = write_vect},
  .secure ={ .nb = sizeof(secure_vect) / sizeof(struct flash_range), .range = secure_vect}
};
