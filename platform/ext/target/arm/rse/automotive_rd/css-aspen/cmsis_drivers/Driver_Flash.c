/*
 * SPDX-License-Identifier: BSD-3-Clause
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 */

#include "cmsis_driver_config.h"
#include "Driver_Flash_Strata.h"
#include "RTE_Device.h"

static ARM_FLASH_INFO ARM_FLASH0_DEV_DATA = {
    .sector_info    = NULL,     /* Uniform sector layout */
    .sector_count   = BOOT_FLASH_SIZE / 0x1000,
    .sector_size    = 0x1000,
    .page_size      = 256U,
    .program_unit   = 1U,
    .erased_value   = ARM_FLASH_DRV_ERASE_VALUE
};

static struct arm_strata_flash_dev_t ARM_FLASH0_DEV = {
    .dev    = &FLASH0_DEV,
    .data   = &ARM_FLASH0_DEV_DATA
};

static ARM_FLASH_INFO ARM_FLASH1_DEV_DATA = {
    .sector_info    = NULL,     /* Uniform sector layout */
    .sector_count   = AP_BOOT_FLASH_SIZE / 0x1000,
    .sector_size    = 0x1000,
    .page_size      = 256U,
    .program_unit   = 1U,
    .erased_value   = ARM_FLASH_DRV_ERASE_VALUE
};

static struct arm_strata_flash_dev_t ARM_FLASH1_DEV = {
    .dev    = &FLASH1_DEV,
    .data   = &ARM_FLASH1_DEV_DATA
};

ARM_FLASH_STRATA(ARM_FLASH0_DEV, Driver_FLASH0);
ARM_FLASH_STRATA(ARM_FLASH1_DEV, Driver_FLASH1);
