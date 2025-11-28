/*
 * Copyright (c) 2013-2022 ARM Limited. All rights reserved.
 * Copyright 2025 NXP
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "Driver_Flash.h"
#include "platform_base_address.h"
#include "flash_layout.h"
#include "fsl_cache.h"

#ifndef ARG_UNUSED
#define ARG_UNUSED(arg)  ((void)arg)
#endif

/* Driver version */
#define ARM_FLASH_DRV_VERSION    ARM_DRIVER_VERSION_MAJOR_MINOR(1, 0)

/**
 * \brief Flash driver capability macro definitions \ref ARM_FLASH_CAPABILITIES
 */
/* Flash Ready event generation capability values */
#define EVENT_READY_NOT_AVAILABLE   (0u)
#define EVENT_READY_AVAILABLE       (1u)

/* Data access size values */
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

/* Chip erase capability values */
#define CHIP_ERASE_NOT_SUPPORTED    (0u)
#define CHIP_ERASE_SUPPORTED        (1u)

/* ARM FLASH device structure */
struct arm_flash_dev_t {
    ARM_FLASH_INFO *data;         /*!< FLASH data */
    FLEXSPI_Type *base;
};

/* Flash Status */
static ARM_FLASH_STATUS FlashStatus = {0, 0, 0};

/* Driver Version */
static const ARM_DRIVER_VERSION DriverVersion = {
    ARM_FLASH_API_VERSION,
    ARM_FLASH_DRV_VERSION
};

/* Driver Capabilities */
static const ARM_FLASH_CAPABILITIES DriverCapabilities = {
    EVENT_READY_NOT_AVAILABLE,
    DATA_WIDTH_8BIT,
    CHIP_ERASE_NOT_SUPPORTED
};

static ARM_FLASH_INFO ARM_FLASH0_DEV_DATA = {
    .sector_info  = NULL,                  /* Uniform sector layout */
    .sector_count = FLASH0_SIZE / FLASH0_SECTOR_SIZE,
    .sector_size  = FLASH0_SECTOR_SIZE,
    .page_size    = FLASH0_PAGE_SIZE,
    .program_unit = FLASH0_PROGRAM_UNIT,
    .erased_value = 0xFF};

static struct arm_flash_dev_t ARM_FLASH0_DEV = {
    .data        = &(ARM_FLASH0_DEV_DATA)};

static struct arm_flash_dev_t *FLASH0_DEV = &ARM_FLASH0_DEV;

/* Functions */

static ARM_DRIVER_VERSION ARM_Flash_GetVersion(void)
{
    return DriverVersion;
}

static ARM_FLASH_CAPABILITIES ARM_Flash_GetCapabilities(void)
{
    return DriverCapabilities;
}

static int32_t ARM_Flash_Initialize(ARM_Flash_SignalEvent_t cb_event)
{
    ARG_UNUSED(cb_event);
    status_t status;

	/* This is a dummy placeholder */
    return ARM_DRIVER_OK;
}

static int32_t ARM_Flash_Uninitialize(void)
{
    /* Nothing to be done */
    return ARM_DRIVER_OK;
}

static int32_t ARM_Flash_PowerControl(ARM_POWER_STATE state)
{
    switch (state) {
    case ARM_POWER_FULL:
        /* Nothing to be done */
        return ARM_DRIVER_OK;

    case ARM_POWER_OFF:
    case ARM_POWER_LOW:
    default:
        return ARM_DRIVER_ERROR_UNSUPPORTED;
    }
}

static int32_t ARM_Flash_ReadData(uint32_t addr, void *data, uint32_t cnt)
{
    return ARM_DRIVER_ERROR_UNSUPPORTED;
}

static int32_t ARM_Flash_ProgramData(uint32_t addr, const void *data, uint32_t cnt)
{
    return ARM_DRIVER_ERROR_UNSUPPORTED;
}

static int32_t ARM_Flash_EraseSector(uint32_t addr)
{
    return ARM_DRIVER_ERROR_UNSUPPORTED;
}

static ARM_FLASH_STATUS ARM_Flash_GetStatus(void)
{
    return FlashStatus;
}

static ARM_FLASH_INFO * ARM_Flash_GetInfo(void)
{
    return FLASH0_DEV->data;
}

ARM_DRIVER_FLASH Driver_EFLASH0 = {
    .GetVersion = ARM_Flash_GetVersion,
    .GetCapabilities = ARM_Flash_GetCapabilities,
    .Initialize = ARM_Flash_Initialize,
    .Uninitialize = ARM_Flash_Uninitialize,
    .PowerControl = ARM_Flash_PowerControl,
    .ReadData = ARM_Flash_ReadData,
    .ProgramData = ARM_Flash_ProgramData,
    .EraseSector = ARM_Flash_EraseSector,
    .GetStatus = ARM_Flash_GetStatus,
    .GetInfo = ARM_Flash_GetInfo
};
