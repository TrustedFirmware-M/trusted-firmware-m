/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 * Copyright (c) 2026 Texas Instruments Incorporated. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 * CMSIS ARM_DRIVER_FLASH for MSPM33C321A — single driver, address-based dispatch.
 *
 * addr >= DATA_FLASH_BASE_ADDRESS (0x80000000) → data flash (Bank 2, 32 KB)
 * addr <  DATA_FLASH_BASE_ADDRESS              → main flash (Bank 0, 1 MB)
 *
 * Secure peripheral aliases (FLASHCTL_S, GSC_S) are used throughout because:
 * - SAU marks 0x4xxxxxxx as NS, forcing bus transactions to SEC=0
 * - DL_FlashCTL_executeClearStatus() has a hardcoded NS alias for STATCMD polling
 *   which causes FLC_MMR_ACCESS_ERROR when the semaphore is owned as Secure
 * - Using Secure aliases ensures semaphore ownership and bus transactions match
 */


#include <string.h>

#include "Driver_Flash.h"
#include "flash_layout.h"
#include <ti/driverlib/dl_flashctl.h>
#include <ti/driverlib/dl_gsc.h>
#include <ti/devices/msp/msp.h>

#ifndef ARG_UNUSED
#define ARG_UNUSED(arg)  ((void)(arg))
#endif

#define ARM_FLASH_DRV_VERSION   ARM_DRIVER_VERSION_MAJOR_MINOR(1, 0)

#define FLASHCTL_SECURE         FLASHCTL_S       /* 0x50042000 */
#define GSC_SECURE              GSC_S
#define MAIN_FLASH_READ_BASE    S_ROM_ALIAS_BASE /* 0x10000000 */
#define DATA_FLASH_READ_BASE    DATA_FLASH_BASE_ADDRESS_S /* 0x90000000 */

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

static const ARM_DRIVER_VERSION DriverVersion = {
    ARM_FLASH_API_VERSION,
    ARM_FLASH_DRV_VERSION
};

static const ARM_FLASH_CAPABILITIES DriverCapabilities = {
    0,               /* event_ready  */
    DATA_WIDTH_8BIT, /* data_width   */
    0                /* erase_chip   */
};

/*
 * sector_count covers both main flash and data flash combined so TF-M
 * range checks pass for any valid address. GetInfo is informational only.
 */
static ARM_FLASH_INFO ARM_FLASH0_DEV_DATA = {
    .sector_info  = NULL,
    .sector_count = (FLASH_TOTAL_SIZE + DATA_FLASH_TOTAL_SIZE) /
                    FLASH_AREA_IMAGE_SECTOR_SIZE,
    .sector_size  = FLASH_AREA_IMAGE_SECTOR_SIZE,
    .page_size    = FLASH_AREA_IMAGE_SECTOR_SIZE,
    .program_unit = TFM_HAL_FLASH_PROGRAM_UNIT,
    .erased_value = 0xFF
};

/* Returns true if addr is in data flash address space */
static bool is_data_flash(uint32_t addr)
{
    return (addr >= DATA_FLASH_BASE_ADDRESS);
}

static bool is_range_valid(uint32_t addr, uint32_t length)
{
    if (is_data_flash(addr)) {
        uint32_t offset = addr - DATA_FLASH_BASE_ADDRESS;
        if (offset >= DATA_FLASH_TOTAL_SIZE) {
            return false;
        }
        if (length > (DATA_FLASH_TOTAL_SIZE - offset)) {
            return false;
        }
    } else {
        if (addr >= FLASH_TOTAL_SIZE) {
            return false;
        }
        if (length > (FLASH_TOTAL_SIZE - addr)) {
            return false;
        }
    }
    return true;
}

static bool is_write_aligned(uint32_t param)
{
    return ((param % ARM_FLASH0_DEV_DATA.program_unit) == 0);
}

/*
 * flash_clear_status_s — Secure-safe clear-status using FLASHCTL_S.
 * DL_FlashCTL_executeClearStatus() uses hardcoded NS alias for STATCMD polling
 * which triggers FLC_MMR_ACCESS_ERROR. This function uses FLASHCTL_S throughout.
 */
static void flash_clear_status_s(void)
{
    FLASHCTL_SECURE->GEN.CMDTYPE = FLASHCTL_CMDTYPE_COMMAND_CLEARSTATUS;
    FLASHCTL_SECURE->GEN.CMDEXEC = FLASHCTL_CMDEXEC_VAL_EXECUTE;
    while ((FLASHCTL_SECURE->GEN.STATCMD & FLASHCTL_STATCMD_CMDINPROGRESS_MASK) ==
           FLASHCTL_STATCMD_CMDINPROGRESS_STATINPROGRESS) {
        ;
    }
}

/*
 * flash_program_blocking_s — Secure-safe 128-bit program loop.
 * DL_FlashCTL_programMemoryBlocking calls executeClearStatus internally which
 * uses the hardcoded NS alias. This replicates the same logic using FLASHCTL_S.
 */
static bool flash_program_blocking_s(uint32_t abs_addr, const uint32_t *data,
                                     uint32_t num_words,
                                     DL_FLASHCTL_REGION_SELECT region)
{
    uint32_t remaining = num_words;
    const uint32_t *d  = data;
    uint32_t addr      = abs_addr;

    while (remaining >= 4U) {
        flash_clear_status_s();
        DL_FlashCTL_unprotectSector(FLASHCTL_SECURE, addr, region);
        DL_FlashCTL_programMemory128WithECCGenerated(FLASHCTL_SECURE, addr, d);
        if (!DL_FlashCTL_waitForCmdDone(FLASHCTL_SECURE)) {
            return false;
        }
        remaining -= 4U;
        d         += 4U;
        addr      += 16U;
    }
    return true;
}

static ARM_DRIVER_VERSION ARM_Flash_GetVersion(void)    { return DriverVersion; }
static ARM_FLASH_CAPABILITIES ARM_Flash_GetCapabilities(void) { return DriverCapabilities; }
static ARM_FLASH_STATUS ARM_Flash_GetStatus(void)       { ARM_FLASH_STATUS s = {0,0,0}; return s; }
static ARM_FLASH_INFO *ARM_Flash_GetInfo(void)          { return &ARM_FLASH0_DEV_DATA; }

static bool flash_init_is_done = false;
static int32_t ARM_Flash_Initialize(ARM_Flash_SignalEvent_t cb_event)
{
    ARG_UNUSED(cb_event);

    if (!flash_init_is_done) {
        /* Force-clear semaphore — may be left held by DSLite after programming */
        DL_GSC_clearFlashSemaphore(GSC_SECURE);
        DL_GSC_acquireFlashSemaphore(GSC_SECURE);
        flash_clear_status_s();
        DL_GSC_clearFlashSemaphore(GSC_SECURE);
        flash_init_is_done = true;
    }

    return ARM_DRIVER_OK;
}

static int32_t ARM_Flash_Uninitialize(void)
{
    flash_init_is_done = false;
    return ARM_DRIVER_OK;
}

static int32_t ARM_Flash_PowerControl(ARM_POWER_STATE state)
{
    if (state == ARM_POWER_FULL) {
        return ARM_DRIVER_OK;
    }
    return ARM_DRIVER_ERROR_UNSUPPORTED;
}

/*
 * ARM_Flash_ReadData
 *
 * Main flash: code regions have valid ECC — direct memcpy via Secure alias.
 * Data flash: may be erased (no valid ECC) — blank-verify per 128-bit word,
 *             return 0xFF for erased words to avoid FRI_DED NMI.
 */
static int32_t ARM_Flash_ReadData(uint32_t addr, void *data, uint32_t cnt)
{
    uint32_t bytes = cnt * data_width_byte[DriverCapabilities.data_width];

    if (!is_range_valid(addr, bytes) || bytes == 0) {
        return (bytes == 0) ? 0 : ARM_DRIVER_ERROR_PARAMETER;
    }

    if (!is_data_flash(addr)) {
        /* Main flash — code always has valid ECC */
        (void)memcpy(data, (const void *)(MAIN_FLASH_READ_BASE + addr), bytes);
    } else {
        uint32_t offset = addr - DATA_FLASH_BASE_ADDRESS;

        /* OTP/NV counter area (0x80000000–0x80001FFF) always has valid ECC
         * after provisioning — read directly. Reading 0xFF from this area
         * would be interpreted as NV counter at max value, corrupting state. */
        if (addr < (DATA_FLASH_BASE_ADDRESS + FLASH_OTP_NV_COUNTERS_AREA_SIZE)) {
            (void)memcpy(data, (const void *)(DATA_FLASH_READ_BASE + offset), bytes);
        } else {
            /* ITS/PS area — erased words have no valid ECC and trigger FRI_DED
             * NMI (e.g. ITS metadata compaction reading an erased metablock).
             * Disable ECC checking so erased words return 0xFF safely.
             * FRI_S ECC_ENABLE: 0xA = enabled, any other value = disabled. */
            FRI_S->FLASH_CTRL_REGS.ECC_ENABLE = 0x0U;
            (void)memcpy(data, (const void *)(DATA_FLASH_READ_BASE + offset), bytes);
            FRI_S->FLASH_CTRL_REGS.ECC_ENABLE = 0xAU;
        }
    }

    return (int32_t)(bytes / data_width_byte[DriverCapabilities.data_width]);
}

static int32_t ARM_Flash_ProgramData(uint32_t addr, const void *data,
                                     uint32_t cnt)
{
    uint32_t bytes = cnt * data_width_byte[DriverCapabilities.data_width];
    bool prog_ok;

    if (!is_range_valid(addr, bytes)) {
        return ARM_DRIVER_ERROR_PARAMETER;
    }
    if (!is_write_aligned(addr) || !is_write_aligned(bytes)) {
        return ARM_DRIVER_ERROR_PARAMETER;
    }
    if (bytes == 0) {
        return 0;
    }

    DL_FLASHCTL_REGION_SELECT region = DL_FLASHCTL_REGION_SELECT_MAIN;

    uint32_t abs_addr = is_data_flash(addr)
        ? DATA_FLASH_BASE_ADDRESS + (addr - DATA_FLASH_BASE_ADDRESS)
        : FLASH_BASE_ADDRESS + addr;

    DL_GSC_acquireFlashSemaphore(GSC_SECURE);
    flash_clear_status_s();

    prog_ok = flash_program_blocking_s(abs_addr, (const uint32_t *)data,
                                       bytes / sizeof(uint32_t), region);

    DL_GSC_clearFlashSemaphore(GSC_SECURE);

    return prog_ok ? (int32_t)(bytes / data_width_byte[DriverCapabilities.data_width])
                   : ARM_DRIVER_ERROR;
}

static int32_t ARM_Flash_EraseSector(uint32_t addr)
{
    DL_FLASHCTL_COMMAND_STATUS status;

    if (!is_range_valid(addr, ARM_FLASH0_DEV_DATA.sector_size)) {
        return ARM_DRIVER_ERROR_PARAMETER;
    }
    if ((addr % ARM_FLASH0_DEV_DATA.sector_size) != 0) {
        return ARM_DRIVER_ERROR_PARAMETER;
    }

    DL_FLASHCTL_REGION_SELECT region = DL_FLASHCTL_REGION_SELECT_MAIN;

    uint32_t abs_addr = is_data_flash(addr)
        ? DATA_FLASH_BASE_ADDRESS + (addr - DATA_FLASH_BASE_ADDRESS)
        : FLASH_BASE_ADDRESS + addr;

    DL_GSC_acquireFlashSemaphore(GSC_SECURE);
    flash_clear_status_s();

    DL_FlashCTL_unprotectSector(FLASHCTL_SECURE, abs_addr, region);
    status = DL_FlashCTL_eraseMemoryFromRAM(
                 FLASHCTL_SECURE, abs_addr, DL_FLASHCTL_COMMAND_SIZE_SECTOR);
    DL_FlashCTL_protectSector(FLASHCTL_SECURE, abs_addr, region);

    DL_GSC_clearFlashSemaphore(GSC_SECURE);

    return (status == DL_FLASHCTL_COMMAND_STATUS_PASSED)
        ? ARM_DRIVER_OK : ARM_DRIVER_ERROR;
}

ARM_DRIVER_FLASH Driver_FLASH0 = {
    .GetVersion      = ARM_Flash_GetVersion,
    .GetCapabilities = ARM_Flash_GetCapabilities,
    .Initialize      = ARM_Flash_Initialize,
    .Uninitialize    = ARM_Flash_Uninitialize,
    .PowerControl    = ARM_Flash_PowerControl,
    .ReadData        = ARM_Flash_ReadData,
    .ProgramData     = ARM_Flash_ProgramData,
    .EraseSector     = ARM_Flash_EraseSector,
    .EraseChip       = NULL,
    .GetStatus       = ARM_Flash_GetStatus,
    .GetInfo         = ARM_Flash_GetInfo
};
