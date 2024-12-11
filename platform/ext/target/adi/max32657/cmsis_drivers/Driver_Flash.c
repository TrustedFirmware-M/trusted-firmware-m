/*
 * Copyright (c) 2013-2022 ARM Limited. All rights reserved.
 * Copyright (C) 2024 Analog Devices, Inc.
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

#include <stdint.h>
#include "Driver_Flash.h"
#include "platform_retarget.h"
#include "RTE_Device.h"
#include "mxc_errors.h"
#include "flc.h"

#ifndef ARG_UNUSED
#define ARG_UNUSED(arg)  ((void)arg)
#endif

/* Driver version */
#define ARM_FLASH_DRV_VERSION      ARM_DRIVER_VERSION_MAJOR_MINOR(1, 1)

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

struct arm_flash_dev_t {
    const uint32_t memory_base;   /*!< FLASH memory base address */
    ARM_FLASH_INFO *data;         /*!< FLASH data */
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
    0, /* event_ready */
    0, /* data_width = 0:8-bit, 1:16-bit, 2:32-bit */
    1  /* erase_chip */
};

#if (RTE_FLASH0)
static ARM_FLASH_INFO ARM_FLASH0_DEV_DATA = {
    .sector_info  = NULL,  /* Uniform sector layout */
    .sector_count = FLASH0_SIZE / FLASH0_SECTOR_SIZE,
    .sector_size  = FLASH0_SECTOR_SIZE,
    .page_size    = FLASH0_PAGE_SIZE,
    .program_unit = FLASH0_PROGRAM_UNIT,
    .erased_value = 0xFF
};

static struct arm_flash_dev_t ARM_FLASH0_DEV = {
#if (__DOMAIN_NS == 1)
    .memory_base = FLASH0_BASE_NS,
#else
    .memory_base = FLASH0_BASE_S,
#endif /* __DOMAIN_NS == 1 */
    .data        = &(ARM_FLASH0_DEV_DATA)};

struct arm_flash_dev_t *FLASH0_DEV = &ARM_FLASH0_DEV;

/*
 * Functions
 */

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

static int32_t ARM_Flash_ReadData(uint32_t offset, void *data, uint32_t cnt)
{
    /* Check flash memory boundaries */
    if ((offset + cnt) >= FLASH0_SIZE) {
		return ARM_DRIVER_ERROR_PARAMETER;
	}

    /* CMSIS ARM_FLASH_ReadData API requires the offset data type size aligned.
     * Data type size is specified by the data_width in ARM_FLASH_CAPABILITIES.
     */
    if (offset % data_width_byte[DriverCapabilities.data_width] != 0) {
        return ARM_DRIVER_ERROR_PARAMETER;
    }

    /* Conversion between data items and bytes */
    uint32_t addr = FLASH0_DEV->memory_base + offset;
    int num_of_bytes = cnt * data_width_byte[DriverCapabilities.data_width];

    MXC_FLC_Read(addr, data, num_of_bytes);

    return cnt;
}

static int32_t ARM_Flash_ProgramData(uint32_t offset, const void *data, uint32_t cnt)
{
    /* Check flash memory boundaries */
    if ((offset + cnt) >= FLASH0_SIZE) {
		return ARM_DRIVER_ERROR_PARAMETER;
	}

    uint32_t addr = FLASH0_DEV->memory_base + offset;

    if(MXC_FLC_Write(addr, cnt, (uint32_t *)data) != E_NO_ERROR) {
        return ARM_DRIVER_ERROR_PARAMETER;
    }

    return cnt;
}

static int32_t ARM_Flash_EraseSector(uint32_t offset)
{
    /* Check flash memory boundaries */
    if (offset >= FLASH0_SIZE) {
		return ARM_DRIVER_ERROR_PARAMETER;
	}

    /* Sector shall be aligned, check it */
    if ((offset % FLASH0_DEV->data->sector_size) != 0) {
        return ARM_DRIVER_ERROR_PARAMETER;
    }

    uint32_t addr = FLASH0_DEV->memory_base + offset;

    if (MXC_FLC_PageErase(addr) != E_NO_ERROR) {
        return ARM_DRIVER_ERROR_PARAMETER;
    }

    return ARM_DRIVER_OK;
}

static int32_t ARM_Flash_EraseChip(void)
{
    if (DriverCapabilities.erase_chip == 1) {
        if(MXC_FLC_MassErase() != E_NO_ERROR) {
            return ARM_DRIVER_ERROR_PARAMETER;
        }
    } else {
        return ARM_DRIVER_ERROR_UNSUPPORTED;
    }

    return ARM_DRIVER_OK;
}

static ARM_FLASH_STATUS ARM_Flash_GetStatus(void)
{
    return FlashStatus;
}

static ARM_FLASH_INFO* ARM_Flash_GetInfo(void)
{
    return FLASH0_DEV->data;
}

ARM_DRIVER_FLASH Driver_FLASH0 = {
    ARM_Flash_GetVersion,
    ARM_Flash_GetCapabilities,
    ARM_Flash_Initialize,
    ARM_Flash_Uninitialize,
    ARM_Flash_PowerControl,
    ARM_Flash_ReadData,
    ARM_Flash_ProgramData,
    ARM_Flash_EraseSector,
    ARM_Flash_EraseChip,
    ARM_Flash_GetStatus,
    ARM_Flash_GetInfo
};
#endif /* RTE_FLASH0 */
