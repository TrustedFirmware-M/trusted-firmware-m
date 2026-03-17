/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <inttypes.h>

#include "io_gpt.h"

#include "Driver_Flash.h"
#include "gpt_flash.h"
#include "flash_layout.h"

/* Check if globals in module have been initialised */
#define CHECK_INIT                      \
    do {                                \
        if (!flash_driver) {            \
            return GPT_FLASH_NOT_INIT;  \
        }                               \
    } while (0)

/* Check the given flash access is valid */
#define CHECK_BOUNDS(addr, size)                                          \
    do {                                                                  \
        if (size > FLASH_TOTAL_SIZE || addr > FLASH_TOTAL_SIZE - size) {  \
            return GPT_FLASH_BAD_PARAM;                                   \
        }                                                                 \
    } while (0)

/* Aligns address to flash sector sizes */
#define ALIGN_TO_SECTOR(addr) (((addr) / FLASH_SECTOR_SIZE) * FLASH_SECTOR_SIZE)

/* Number of LBAs per sector of flash */
#define LBAS_PER_SECTOR (FLASH_SECTOR_SIZE / TFM_GPT_BLOCK_SIZE)

/* Returns the offset within a sector for the given lba */
static inline uint64_t sector_offset(uint64_t lba)
{
    return (lba % LBAS_PER_SECTOR) * TFM_GPT_BLOCK_SIZE;
}

/* The actual flash driver under the hood */
static ARM_DRIVER_FLASH *flash_driver = NULL;

/* Buffer used to store sector of flash data */
static uint8_t sector_buf[FLASH_SECTOR_SIZE];

/* From io_gpt.h - the driver given to the GPT library */
struct gpt_flash_driver_t io_gpt_flash_driver = {0};

/* Read the bytes that need to be erased. If they are already erased_value,
 * report that an erase is not required. This is to reduce the number of flash
 * erase cyles. If the read fails in any way, report erase required.
 */
static bool erase_required(uint32_t erase_addr,
                           size_t   num_bytes)
{
    if (num_bytes > FLASH_SECTOR_SIZE) {
        return true;
    }

    int32_t ret = flash_driver->ReadData(erase_addr, sector_buf, num_bytes);
    if (ret < 0 || (uint32_t)ret != num_bytes) {
        return true;
    }

    uint8_t erased_value = flash_driver->GetInfo()->erased_value;
    for (size_t offset = 0; offset < num_bytes; ++offset) {
        if (sector_buf[offset] != erased_value) {
            return true;
        }
    }

    return false;
}

/* Erases TFM_GPT_BLOCK_SIZE bytes from offset within the sector beginning at
 * sector_addr. This is done via a read-erase-write pattern whereby data is read,
 * the sector is erased, and data written back to the parts of the sector that
 * shouldn't have been erased
 */
static gpt_flash_err_t partially_erase_sector(uint32_t sector_addr,
                                              uint32_t offset)
{
    if (!erase_required(sector_addr + offset, TFM_GPT_BLOCK_SIZE)) {
        return GPT_FLASH_SUCCESS;
    }

    if (flash_driver->ReadData(
                sector_addr,
                sector_buf,
                FLASH_SECTOR_SIZE) != FLASH_SECTOR_SIZE)
    {
        return GPT_FLASH_GENERIC_ERROR;
    }

    if (flash_driver->EraseSector(sector_addr) != ARM_DRIVER_OK) {
        return GPT_FLASH_GENERIC_ERROR;
    }

    memset(sector_buf + offset, flash_driver->GetInfo()->erased_value, TFM_GPT_BLOCK_SIZE);
    if (flash_driver->ProgramData(
                sector_addr,
                sector_buf,
                FLASH_SECTOR_SIZE) != FLASH_SECTOR_SIZE)
    {
        return GPT_FLASH_GENERIC_ERROR;
    }

    return GPT_FLASH_SUCCESS;
}

/* Reads the requested LBA into the given buffer */
static ssize_t flash_read(uint64_t lba, void *buf)
{
    CHECK_INIT;

    uint64_t read_addr = lba * TFM_GPT_BLOCK_SIZE;
    CHECK_BOUNDS(read_addr, TFM_GPT_BLOCK_SIZE);

    if (flash_driver->ReadData(read_addr, buf, TFM_GPT_BLOCK_SIZE) != TFM_GPT_BLOCK_SIZE) {
        return GPT_FLASH_GENERIC_ERROR;
    }

    return TFM_GPT_BLOCK_SIZE;
}

/* Writes the given buffer to the requested LBA */
static ssize_t flash_write(uint64_t lba, const void *buf)
{
    CHECK_INIT;

    uint64_t write_addr = lba * TFM_GPT_BLOCK_SIZE;
    CHECK_BOUNDS(write_addr, TFM_GPT_BLOCK_SIZE);

    if (flash_driver->ProgramData(write_addr, buf, TFM_GPT_BLOCK_SIZE) != TFM_GPT_BLOCK_SIZE) {
        return GPT_FLASH_GENERIC_ERROR;
    }

    return TFM_GPT_BLOCK_SIZE;
}

/* Erases a consecutive number of blocks, beginning with the given LBA */
static ssize_t flash_erase(uint64_t lba, size_t num_blocks)
{
    CHECK_INIT;

    if (num_blocks == 0) {
        return GPT_FLASH_BAD_PARAM;
    }

    /* Convert blocks to sectors. The first and final sectors may be partially erased */
    size_t num_sectors = num_blocks / LBAS_PER_SECTOR;
    if (num_sectors == 0) {
        /* Partially erase first sector and thats it */
        num_sectors = 1;
    }

    uint64_t erase_addr = ALIGN_TO_SECTOR(lba * TFM_GPT_BLOCK_SIZE);
    CHECK_BOUNDS(erase_addr, FLASH_SECTOR_SIZE);

    uint64_t last_erase_addr = erase_addr + ((num_sectors - 1) * FLASH_SECTOR_SIZE);
    CHECK_BOUNDS(last_erase_addr, FLASH_SECTOR_SIZE);

    /* Whole sector erases until last sector */
    for (size_t i = 0; i < num_sectors - 1; ++i) {
        if (!erase_required(erase_addr + i * FLASH_SECTOR_SIZE, FLASH_SECTOR_SIZE)) {
            continue;
        }

        int32_t ret = flash_driver->EraseSector(erase_addr + i * FLASH_SECTOR_SIZE);
        if (ret != ARM_DRIVER_OK) {
            return i;
        }
    }

    if (num_blocks % LBAS_PER_SECTOR == 0 && lba % LBAS_PER_SECTOR == 0) {
        /* Fully erase final sector if required */
        if (erase_required(last_erase_addr, FLASH_SECTOR_SIZE)) {
            if (flash_driver->EraseSector(last_erase_addr) != ARM_DRIVER_OK) {
                return (num_sectors - 1) * LBAS_PER_SECTOR;
            }
        }
    } else {
        /* Partial erase of final sector */
        if (partially_erase_sector(
                    last_erase_addr,
                    sector_offset(lba)) != GPT_FLASH_SUCCESS)
        {
            return num_sectors == 0 ? GPT_FLASH_GENERIC_ERROR : (num_sectors - 1) * LBAS_PER_SECTOR;
        }
    }

    return num_blocks;
}

int register_flash_io_gpt(ARM_DRIVER_FLASH *driver)
{
    /* Initialise the driver */
    driver->Initialize(NULL);

    /* Store everything needed */
    flash_driver = driver;

    io_gpt_flash_driver.read = flash_read;
    io_gpt_flash_driver.write = flash_write;
    io_gpt_flash_driver.erase = flash_erase;

    return 0;
}
