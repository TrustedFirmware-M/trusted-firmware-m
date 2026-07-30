/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <stdint.h>

#include "Driver_Flash.h"
#include "gpt.h"
#include "tfm_plat_defs.h"
#include "unity.h"

static uint32_t flash_read_count;
static uint32_t flash_read_item_count;
static uint32_t flash_data_width;
static int32_t flash_read_result;

enum lookup_type {
    LOOKUP_BY_NAME,
    LOOKUP_BY_IMAGE_UUID,
    LOOKUP_BY_TYPE_UUID,
};

static ARM_FLASH_CAPABILITIES UNITTEST_Flash_GetCapabilities(void)
{
    const ARM_FLASH_CAPABILITIES capabilities = {
        .data_width = flash_data_width,
    };

    return capabilities;
}

static int32_t UNITTEST_Flash_ReadData(uint32_t addr, void *data, uint32_t cnt)
{
    (void)addr;
    (void)data;
    flash_read_count++;
    flash_read_item_count = cnt;

    return flash_read_result;
}

ARM_DRIVER_FLASH UNITTEST_FLASH_DEV = {
    .GetCapabilities = UNITTEST_Flash_GetCapabilities,
    .ReadData = UNITTEST_Flash_ReadData,
};

void setUp(void)
{
    flash_read_count = 0;
    flash_read_item_count = 0;
    flash_data_width = 0;
    flash_read_result = ARM_DRIVER_ERROR;
}

void tearDown(void)
{
}

TEST_CASE(0, 0)
TEST_CASE(0, 1)
TEST_CASE(0, 2)
TEST_CASE(1, 0)
TEST_CASE(1, 1)
TEST_CASE(1, 2)
TEST_CASE(2, 0)
TEST_CASE(2, 1)
TEST_CASE(2, 2)

void test_gpt_entry_lookup_uses_flash_item_count(
    uint32_t lookup, uint32_t data_width)
{
    const size_t data_width_byte[] = {
        sizeof(uint8_t),
        sizeof(uint16_t),
        sizeof(uint32_t),
    };
    const uint32_t expected_item_count =
        sizeof(gpt_entry_t) / data_width_byte[data_width];
    const uuid_t uuid = { .time_low = { 1 } };
    gpt_entry_t entries[2] = {0};
    enum tfm_plat_err_t err;

    flash_data_width = data_width;
    flash_read_result = expected_item_count;

    switch (lookup) {
    case LOOKUP_BY_NAME:
        err = gpt_get_list_entry_by_name(
            0, 1, sizeof(gpt_entry_t), "test", sizeof("test"),
            sizeof(gpt_entry_t), &entries[0]);
        break;
    case LOOKUP_BY_IMAGE_UUID:
        err = gpt_get_list_entry_by_image_uuid(
            0, 1, sizeof(gpt_entry_t), uuid, sizeof(gpt_entry_t),
            &entries[0]);
        break;
    case LOOKUP_BY_TYPE_UUID:
        err = gpt_get_list_entry_by_type_uuid(
            0, 1, sizeof(gpt_entry_t), uuid, sizeof(gpt_entry_t), entries);
        break;
    default:
        TEST_FAIL_MESSAGE("Unknown GPT lookup type");
    }

    TEST_ASSERT_EQUAL(TFM_PLAT_ERR_GPT_ENTRY_NOT_FOUND, err);
    TEST_ASSERT_EQUAL_UINT32(1, flash_read_count);
    TEST_ASSERT_EQUAL_UINT32(expected_item_count, flash_read_item_count);
}
