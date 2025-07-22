/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <stdbool.h>
#include <string.h>

#include "s_io_storage_test.h"
#include "Driver_Flash.h"
#include "flash_layout.h"
#include "io_gpt.h"

#define TEST_FLASH_SIZE (2 * FLASH_SECTOR_SIZE)
#define BLOCKS_PER_SECTOR (FLASH_SECTOR_SIZE / TFM_GPT_BLOCK_SIZE)
#define TEST_FIRST_BLOCK (BLOCKS_PER_SECTOR - 1)
#define EMULATED_FLASH_FILL 0xa5

extern ARM_DRIVER_FLASH Driver_FLASH0;

/* Match the geometry expected by the platform's GPT flash adapter. */
static uint8_t emulated_flash[TEST_FLASH_SIZE];
static ARM_FLASH_INFO emulated_flash_info = {
    .sector_count = 2,
    .sector_size = FLASH_SECTOR_SIZE,
    .page_size = TFM_GPT_BLOCK_SIZE,
    .program_unit = 1,
    .erased_value = 0xff,
};

static int32_t emulated_initialize(ARM_Flash_SignalEvent_t callback)
{
    (void)callback;
    return ARM_DRIVER_OK;
}

static int32_t emulated_read(uint32_t addr, void *data, uint32_t count)
{
    if (count > sizeof(emulated_flash) || addr > sizeof(emulated_flash) - count) {
        return ARM_DRIVER_ERROR_PARAMETER;
    }
    memcpy(data, emulated_flash + addr, count);
    return count;
}

static int32_t emulated_program(uint32_t addr, const void *data, uint32_t count)
{
    const uint8_t *bytes = data;

    if (count > sizeof(emulated_flash) || addr > sizeof(emulated_flash) - count) {
        return ARM_DRIVER_ERROR_PARAMETER;
    }
    for (uint32_t i = 0; i < count; i++) {
        if ((emulated_flash[addr + i] & bytes[i]) != bytes[i]) {
            return ARM_DRIVER_ERROR;
        }
    }
    for (uint32_t i = 0; i < count; i++) {
        emulated_flash[addr + i] &= bytes[i];
    }
    return count;
}

static int32_t emulated_erase(uint32_t addr)
{
    if (addr % FLASH_SECTOR_SIZE != 0 ||
        addr > sizeof(emulated_flash) - FLASH_SECTOR_SIZE) {
        return ARM_DRIVER_ERROR_PARAMETER;
    }
    memset(emulated_flash + addr, emulated_flash_info.erased_value, FLASH_SECTOR_SIZE);
    return ARM_DRIVER_OK;
}

static ARM_FLASH_INFO *emulated_get_info(void)
{
    return &emulated_flash_info;
}

/* Only the callbacks used by io_gpt are needed by this fixture. */
static ARM_DRIVER_FLASH emulated_driver = {
    .Initialize = emulated_initialize,
    .ReadData = emulated_read,
    .ProgramData = emulated_program,
    .EraseSector = emulated_erase,
    .GetInfo = emulated_get_info,
};

void s_test_io_storage_multiple_flash_simultaneous(struct test_result_t *ret)
{
    static uint8_t saved_flash[TEST_FLASH_SIZE];
    static uint8_t test_data[2][2 * TFM_GPT_BLOCK_SIZE];
    static uint8_t actual[TFM_GPT_BLOCK_SIZE];
    static uint8_t expected[TFM_GPT_BLOCK_SIZE];
    ARM_DRIVER_FLASH *drivers[] = {&Driver_FLASH0, &emulated_driver};
    const uint32_t offsets[] = {BANK_1_PARTITION_OFFSET, 0};
    bool flash_modified = false;

    ret->val = TEST_FAILED;
    if (Driver_FLASH0.Initialize(NULL) != ARM_DRIVER_OK ||
        Driver_FLASH0.GetInfo()->sector_size != FLASH_SECTOR_SIZE ||
        Driver_FLASH0.GetCapabilities().data_width != 0) {
        TEST_FAIL("Unexpected flash geometry or initialization failure");
        return;
    }
    /* Keep the secondary image intact, including bytes outside the test blocks. */
    if (Driver_FLASH0.ReadData(offsets[0], saved_flash, sizeof(saved_flash)) !=
        sizeof(saved_flash)) {
        TEST_FAIL("Cannot save flash contents before the storage test");
        return;
    }

    memset(emulated_flash, EMULATED_FLASH_FILL, sizeof(emulated_flash));
    for (size_t device = 0; device < 2; device++) {
        for (size_t i = 0; i < sizeof(test_data[device]); i++) {
            test_data[device][i] = (uint8_t)(i * 17 + device * 91);
        }
    }

    /* The current adapter selects one device at a time. Alternate devices
     * between the blocks on either side of the erase-sector boundary.
     */
    for (size_t block = 0; block < 2; block++) {
        for (size_t device = 0; device < 2; device++) {
            uint64_t lba = offsets[device] / TFM_GPT_BLOCK_SIZE + TEST_FIRST_BLOCK + block;

            if (register_flash_io_gpt(drivers[device]) != 0) {
                TEST_FAIL("Cannot select flash device");
                goto cleanup;
            }
            if (device == 0) {
                flash_modified = true;
            }
            if (io_gpt_flash_driver.erase(lba, 1) != 1) {
                TEST_FAIL("GPT flash block erase failed");
                goto cleanup;
            }
            if (io_gpt_flash_driver.write(lba, test_data[device] + block * TFM_GPT_BLOCK_SIZE) !=
                TFM_GPT_BLOCK_SIZE) {
                TEST_FAIL("GPT flash block write failed or was short");
                goto cleanup;
            }
        }
    }

    for (size_t device = 0; device < 2; device++) {
        if (register_flash_io_gpt(drivers[device]) != 0) {
            TEST_FAIL("Cannot reselect flash device");
            goto cleanup;
        }
        for (size_t block = 0; block < TEST_FLASH_SIZE / TFM_GPT_BLOCK_SIZE; block++) {
            uint64_t lba = offsets[device] / TFM_GPT_BLOCK_SIZE + block;

            if (block == TEST_FIRST_BLOCK || block == TEST_FIRST_BLOCK + 1) {
                size_t offset = (block - TEST_FIRST_BLOCK) * TFM_GPT_BLOCK_SIZE;

                memcpy(expected, test_data[device] + offset, sizeof(expected));
            } else if (device == 0) {
                memcpy(expected, saved_flash + block * TFM_GPT_BLOCK_SIZE, sizeof(expected));
            } else {
                memset(expected, EMULATED_FLASH_FILL, sizeof(expected));
            }
            if (io_gpt_flash_driver.read(lba, actual) != sizeof(actual)) {
                TEST_FAIL("GPT flash block read failed or was short");
                goto cleanup;
            }
            if (memcmp(actual, expected, sizeof(actual)) != 0) {
                TEST_FAIL("Wrong flash data or neighboring bytes changed");
                goto cleanup;
            }
        }
    }
    ret->val = TEST_PASSED;

cleanup:
    /* Restore both sectors even if an I/O assertion above failed. */
    if (flash_modified) {
        for (size_t sector = 0; sector < 2; sector++) {
            uint32_t addr = offsets[0] + sector * FLASH_SECTOR_SIZE;

            if (Driver_FLASH0.EraseSector(addr) != ARM_DRIVER_OK ||
                Driver_FLASH0.ProgramData(addr, saved_flash + sector * FLASH_SECTOR_SIZE,
                                         FLASH_SECTOR_SIZE) != FLASH_SECTOR_SIZE) {
                TEST_FAIL("Cannot restore flash contents after the storage test");
                continue;
            }
            for (size_t block = 0; block < BLOCKS_PER_SECTOR; block++) {
                size_t offset = sector * FLASH_SECTOR_SIZE + block * TFM_GPT_BLOCK_SIZE;

                if (Driver_FLASH0.ReadData(offsets[0] + offset, actual, sizeof(actual)) !=
                    sizeof(actual) || memcmp(actual, saved_flash + offset, sizeof(actual)) != 0) {
                    TEST_FAIL("Restored flash contents do not match the original");
                    break;
                }
            }
        }
    }
    if (register_flash_io_gpt(&Driver_FLASH0) != 0) {
        TEST_FAIL("Cannot restore the platform flash device");
    }
}
