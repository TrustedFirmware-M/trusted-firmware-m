/*
 * Copyright (c) 2013-2022 ARM Limited. All rights reserved.
 * Copyright 2019-2022, 2025-2026 NXP
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
#include "fsl_flash.h"
#include "fsl_flash_ffr.h"

#define TARGET_DEBUG_LOG 0
#if TARGET_DEBUG_LOG
#include "tfm_spm_log.h"
#endif

#ifndef ARG_UNUSED
#define ARG_UNUSED(arg)  ((void)arg)
#endif

/* Below CMDs apply to both C040HDATFC and C040HDFC flash */
#define FLASH_CMD_INIT 0
#define FLASH_CMD_READ_SINGLE_WORD 3

/* INT_STATUS - Interrupt status bits - taken from LPC5588_cm33_core0.h */

#define FLASH_INT_STATUS_OVL_MASK                (0x10U)

/* Alignment macros - taken from bootloader_common.h */
#ifndef ALIGN_DOWN
#define ALIGN_DOWN(x, a) ((x) & -(a))
#endif

/* Flash property defines */

/* Mask the number of bits required to select the 32-bit data word (DATAW) from the flash line */
#define FLASH_DATAW_IDX_MAX 3    /* Max DATAW index, 3 for a 128-bit flash line, 7 for 256-bit. */

#define FLASH_READMODE_REG          (FLASH->DATAW[0])
#define FLASH_READMODE_ECC_MASK     (0x4U)
#define FLASH_READMODE_ECC_SHIFT    (2U)
#define FLASH_READMODE_ECC(x)       (((uint32_t)(((uint32_t)(x)) << FLASH_READMODE_ECC_SHIFT)) & FLASH_READMODE_ECC_MASK)
#define FLASH_READMODE_MARGIN_MASK  (0xC00U)
#define FLASH_READMODE_MARGIN_SHIFT (10U)
#define FLASH_READMODE_MARGIN(x)    (((uint32_t)(((uint32_t)(x)) << FLASH_READMODE_MARGIN_SHIFT)) & FLASH_READMODE_MARGIN_MASK)
#define FLASH_READMODE_DMACC_MASK   (0x8000U)
#define FLASH_READMODE_DMACC_SHIFT  (15U)
#define FLASH_READMODE_DMACC(x)     (((uint32_t)(((uint32_t)(x)) << FLASH_READMODE_DMACC_SHIFT)) & FLASH_READMODE_DMACC_MASK)

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
    flash_config_t flashInstance; /*!< FLASH config*/
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

/* Prototypes */
static bool is_range_valid(struct arm_flash_dev_t *flash_dev,
                           uint32_t offset);
static bool is_write_aligned(struct arm_flash_dev_t *flash_dev,
                             uint32_t param);

/* Functions */

static ARM_DRIVER_VERSION ARM_Flash_GetVersion(void)
{
    return DriverVersion;
}

static ARM_FLASH_CAPABILITIES ARM_Flash_GetCapabilities(void)
{
    return DriverCapabilities;
}

static bool flash_init_is_done = false;
static int32_t ARM_Flash_Initialize(ARM_Flash_SignalEvent_t cb_event)
{
    ARG_UNUSED(cb_event);
    status_t status;

    if (flash_init_is_done == false)
    {
        /* Call initialization from Flash API */
        status = FLASH_Init(&FLASH0_DEV->flashInstance);
        if(status != kStatus_Success){
            return ARM_DRIVER_ERROR;
        }

        /* Disable Error Detection functionality */
        FLASH0_DEV->flashInstance.modeConfig.readSingleWord.readWithEccOff = 0x1;
        flash_init_is_done = true;
    }

    return ARM_DRIVER_OK;
}

static int32_t ARM_Flash_Uninitialize(void)
{
    flash_init_is_done = false;
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
    static uint32_t status;

    /* Conversion between data items and bytes */
    cnt *= data_width_byte[DriverCapabilities.data_width];

    /* Check Flash memory boundaries */
    status = is_range_valid(FLASH0_DEV, addr + cnt);
    if(status != kStatus_Success) {
        return ARM_DRIVER_ERROR_PARAMETER;
    }

    /* Read Data */
    if(cnt) {
        /* Read Data */
        (void)memcpy(data, (void *)(FLASH_BASE_ADDRESS + addr), cnt);
    }

    cnt /= data_width_byte[DriverCapabilities.data_width];
    return cnt;
}

static int32_t ARM_Flash_ProgramData(uint32_t addr, const void *data, uint32_t cnt)
{
    static uint32_t status;
#if defined(FLASH_DEBUG)
    uint32_t failedAddress, failedData;
#endif
    /* Conversion between data items and bytes */
    cnt *= data_width_byte[DriverCapabilities.data_width];

    /* Check Flash memory boundaries */
    status = is_range_valid(FLASH0_DEV, addr);
    status |= is_write_aligned(FLASH0_DEV, addr);
    status |= is_write_aligned(FLASH0_DEV, cnt);
    if(status != kStatus_Success) {
        return ARM_DRIVER_ERROR_PARAMETER;
    }

    status = FLASH_Program(&FLASH0_DEV->flashInstance, addr, (uint8_t *)data, cnt);
    if (status != kStatus_Success) {
        return ARM_DRIVER_ERROR;
    }

#if defined(FLASH_DEBUG) /*Disabled flash program verify*/
    status = FLASH_VerifyProgram(&FLASH0_DEV->flashInstance, addr, cnt, (const uint8_t *)data,
                                 &failedAddress, &failedData);
    if (status != kStatus_Success) {
        return ARM_DRIVER_ERROR;
    }
#endif

    cnt /= data_width_byte[DriverCapabilities.data_width];
    return cnt;
}

static int32_t ARM_Flash_EraseSector(uint32_t addr)
{
    static uint32_t status;

    status = is_range_valid(FLASH0_DEV, addr);
    status |= is_write_aligned(FLASH0_DEV, addr);
    if(status != kStatus_Success) {
        return ARM_DRIVER_ERROR_PARAMETER;
    }

    status = FLASH_Erase(&FLASH0_DEV->flashInstance, addr, FLASH0_DEV->data->sector_size, kFLASH_ApiEraseKey);
    if (status != kStatus_Success) {
        return ARM_DRIVER_ERROR;
    }

    return ARM_DRIVER_OK;
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

/* Check if the Flash memory boundaries are not violated. */
static bool is_range_valid(struct arm_flash_dev_t *flash_dev,
                           uint32_t offset)
{

    uint32_t flash_limit = FLASH_TOTAL_SIZE - 1;

    return (offset > flash_limit) ? (kStatus_Fail) : (kStatus_Success) ;
}

/* Check if the parameter is aligned to program_unit. */
static bool is_write_aligned(struct arm_flash_dev_t *flash_dev,
                             uint32_t param)
{
    return ((param % flash_dev->data->program_unit) != 0) ? (kStatus_Fail) : (kStatus_Success);
}
