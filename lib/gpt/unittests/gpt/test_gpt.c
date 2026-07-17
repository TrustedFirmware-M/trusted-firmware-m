/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <string.h>
#include <inttypes.h>

#include "unity.h"

#include "mock_efi_guid.h"
#include "mock_efi_soft_crc.h"

#include "efi_guid_structs.h"
#include "gpt_flash.h"
#include "gpt.h"
#include "psa/error.h"

#include "gpt_defs.h"

/* Basic mocked flash layout and number of partitions */
#define TEST_BLOCK_SIZE 512
#define TEST_FLASH_NUM_BLOCKS 128
#define TEST_FLASH_ERASE_VALUE 0xFF
#define TEST_MAX_PARTITIONS 4
#define TEST_DEFAULT_NUM_PARTITIONS TEST_MAX_PARTITIONS - 1

/* Master Boot Record (MBR) definitions for test */
#define TEST_MBR_SIG 0xAA55
#define TEST_MBR_TYPE_GPT 0xEE
#define TEST_MBR_CHS_ADDRESS_LEN 3
#define TEST_MBR_NUM_PARTITIONS 4
#define TEST_MBR_UNUSED_BYTES 446

/* GUID Partition Table (GPT) header values */
#define TEST_GPT_SIG_LEN 8
#define TEST_GPT_SIG_INITIALISER {'E', 'F', 'I', ' ', 'P', 'A', 'R', 'T'}
#define TEST_GPT_REVISION 0x00010000
#define TEST_GPT_HEADER_SIZE 92
#define TEST_GPT_CRC32 42
#define TEST_GPT_PRIMARY_LBA 1
#define TEST_GPT_BACKUP_LBA (TEST_FLASH_NUM_BLOCKS - 1)
#define TEST_GPT_PRIMARY_ARRAY_LBA (TEST_GPT_PRIMARY_LBA + 1)
#define TEST_GPT_BACKUP_ARRAY_LBA (TEST_GPT_BACKUP_LBA - 1)
#define TEST_GPT_FIRST_USABLE_LBA (TEST_GPT_PRIMARY_ARRAY_LBA + 2)
#define TEST_GPT_LAST_USABLE_LBA (TEST_GPT_BACKUP_LBA - 2)
#define TEST_GPT_FLASH_GUID MAKE_EFI_GUID(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11)
#define TEST_GPT_ENTRY_SIZE 128

/* Test data. These are defined to be not fragmented */
#define TEST_GPT_FIRST_PARTITION_START TEST_GPT_FIRST_USABLE_LBA
#define TEST_GPT_FIRST_PARTITION_END (TEST_GPT_FIRST_PARTITION_START + 3)
#define TEST_GPT_SECOND_PARTITION_START (TEST_GPT_FIRST_PARTITION_END + 1)
#define TEST_GPT_SECOND_PARTITION_END (TEST_GPT_SECOND_PARTITION_START + 50)
#define TEST_GPT_THIRD_PARTITION_START (TEST_GPT_SECOND_PARTITION_END + 1)
#define TEST_GPT_THIRD_PARTITION_END (TEST_GPT_THIRD_PARTITION_START + 1)
#define TEST_GPT_FLASH_FREE_SPACE_START (TEST_GPT_THIRD_PARTITION_END + 1)

/* These macros make it clearer in the tests what is happening */
#define TEST_GPT_VALID_GUID(...) MAKE_EFI_GUID(__VA_ARGS__)
#define TEST_GPT_DUMMY_GUID NULL_GUID

#define TEST_GPT_VALID_TYPE(...) MAKE_EFI_GUID(__VA_ARGS__)
#define TEST_GPT_DUMMY_TYPE NULL_GUID

/* Valid MBR. Only signature is required to be valid */
static struct mbr_t default_mbr = {
    .partitions = {0},
    .sig = MBR_SIG,
};
static struct mbr_t test_mbr;

/* Default GPT header. CRC values need to be populated to be valid. */
static struct gpt_header_t default_header = {
    .signature = TEST_GPT_SIG_INITIALISER,
    .revision = TEST_GPT_REVISION,
    .size = TEST_GPT_HEADER_SIZE,
    .header_crc = TEST_GPT_CRC32,
    .reserved = 0,
    .current_lba = TEST_GPT_PRIMARY_LBA,
    .backup_lba = TEST_GPT_BACKUP_LBA,
    .first_lba = TEST_GPT_FIRST_USABLE_LBA,
    .last_lba = TEST_GPT_LAST_USABLE_LBA,
    .flash_guid = TEST_GPT_FLASH_GUID,
    .array_lba = TEST_GPT_PRIMARY_ARRAY_LBA,
    .num_partitions = TEST_MAX_PARTITIONS,
    .entry_size = TEST_GPT_ENTRY_SIZE,
    .array_crc = TEST_GPT_CRC32,
};

static struct gpt_t test_primary_gpt = {0};
static struct gpt_t test_backup_gpt = {0};

/* Mock flash memory */
static uint8_t test_mock_flash[TEST_BLOCK_SIZE * TEST_FLASH_NUM_BLOCKS];

/* Functions for mocked memory driver. */
static ssize_t test_driver_read(uint64_t lba, void *buf)
{
    if (lba >= TEST_FLASH_NUM_BLOCKS) {
        return GPT_FLASH_BAD_PARAM;
    }

    memcpy(buf, test_mock_flash + (lba * TEST_BLOCK_SIZE), TEST_BLOCK_SIZE);
    return TEST_BLOCK_SIZE;
}

static ssize_t test_driver_write(uint64_t lba, const void *buf)
{
    if (lba >= TEST_FLASH_NUM_BLOCKS) {
        return GPT_FLASH_BAD_PARAM;
    }

    memcpy(test_mock_flash + (lba * TEST_BLOCK_SIZE), buf, TEST_BLOCK_SIZE);
    return TEST_BLOCK_SIZE;
}

static ssize_t test_driver_erase(uint64_t lba, size_t num_blocks)
{
    if (num_blocks == 0 ||
            lba >= TEST_FLASH_NUM_BLOCKS ||
            num_blocks > TEST_FLASH_NUM_BLOCKS - lba) {
        return GPT_FLASH_BAD_PARAM;
    }

    memset(test_mock_flash + (lba * TEST_BLOCK_SIZE),
            TEST_FLASH_ERASE_VALUE,
            num_blocks * TEST_BLOCK_SIZE);
    return num_blocks;
}

/* LBA driver used in test module. */
static struct gpt_flash_driver_t mock_driver = {
    .init = NULL,
    .uninit = NULL,
    .read = test_driver_read,
    .write = test_driver_write,
    .erase = test_driver_erase,
};

/* Default entry array. This is valid, though fragmented. */
static struct gpt_entry_t default_partition_array[TEST_DEFAULT_NUM_PARTITIONS] = {
    {
        .partition_type = TEST_GPT_VALID_TYPE(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11),
        .unique_guid = TEST_GPT_VALID_GUID(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11),
        .start = TEST_GPT_FIRST_PARTITION_START,
        .end = TEST_GPT_FIRST_PARTITION_END,
        .attr = 0x1,
        .name = "First partition"
    },
    {
        .partition_type = TEST_GPT_VALID_TYPE(2, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11),
        .unique_guid = TEST_GPT_VALID_GUID(2, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11),
        .start = TEST_GPT_SECOND_PARTITION_START,
        .end = TEST_GPT_SECOND_PARTITION_END,
        .attr = 0x2,
        .name = "Second partition"
    },
    {
        .partition_type = TEST_GPT_VALID_TYPE(3, 3, 3, 4, 5, 6, 7, 8, 9, 10, 11),
        .unique_guid = TEST_GPT_VALID_GUID(3, 3, 3, 4, 5, 6, 7, 8, 9, 10, 11),
        .start = TEST_GPT_THIRD_PARTITION_START,
        .end = TEST_GPT_THIRD_PARTITION_END,
        .attr = 0x3,
        .name = "Third partition"
    }
};
static struct gpt_entry_t test_partition_array[TEST_MAX_PARTITIONS];

/* Return memory address of mocked flash LBA */
static inline uint8_t *lba2addr(uint64_t lba)
{
    return test_mock_flash + (lba * TEST_BLOCK_SIZE);
}

/* Write everything to the memory/flash to form a valid GPT layout. That would be
 *
 * MBR
 * Primary GPT header
 * Primary partition entry array
 * Start of usable space
 *
 * End of usable space
 * Backup partition entry array
 * Backup GPT header
 */
static void setup_test_gpt_layout(void)
{
    /* MBR. */
    memset(lba2addr(MBR_LBA), 0, MBR_UNUSED_BYTES);
    memcpy(lba2addr(MBR_LBA) + MBR_UNUSED_BYTES,
           &test_mbr,
           sizeof(test_mbr));

    /* Primary GPT header */
    memcpy(lba2addr(TEST_GPT_PRIMARY_LBA),
           &test_primary_gpt.header,
           GPT_HEADER_SIZE);

    /* Primary partition entry array */
    memcpy(lba2addr(TEST_GPT_PRIMARY_ARRAY_LBA),
           test_partition_array,
           sizeof(test_partition_array));

    /* Backup partition entry array */
    memcpy(lba2addr(TEST_GPT_BACKUP_ARRAY_LBA),
           test_partition_array,
           sizeof(test_partition_array));

    /* Backup GPT header */
    memcpy(lba2addr(TEST_GPT_BACKUP_LBA),
           &test_backup_gpt.header,
           GPT_HEADER_SIZE);
}

/* Read entry from partition array */
static struct gpt_entry_t *read_entry(uint32_t index, bool is_primary)
{
    const uint64_t array_lba = is_primary ? TEST_GPT_PRIMARY_ARRAY_LBA : TEST_GPT_BACKUP_ARRAY_LBA;

    struct gpt_entry_t *ent =
        (struct gpt_entry_t *)(lba2addr(array_lba) + sizeof(struct gpt_entry_t) * index);

    return ent;
}

/* Turn ascii string to unicode */
static void ascii_to_unicode(const char *ascii, char *unicode)
{
    for (int i = 0; i < strlen(ascii) + 1; ++i) {
        unicode[i << 1] = ascii[i];
        unicode[(i << 1) + 1] = '\0';
    }
}

static void make_backup_header(void)
{
    memcpy(&test_backup_gpt.header, &test_primary_gpt.header, GPT_HEADER_SIZE);
    test_backup_gpt.header.current_lba = test_primary_gpt.header.backup_lba;
    test_backup_gpt.header.backup_lba = test_primary_gpt.header.current_lba;
    test_backup_gpt.header.array_lba = TEST_GPT_BACKUP_ARRAY_LBA;
}

/* Helper for test_gpt_validate_should_failWhenBackupLbaNotAtEndOfDisk */
static void validate_backup_lba_not_at_end_of_disk(uint64_t invalid_lba, bool is_primary)
{
    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_init(&mock_driver, TEST_MAX_PARTITIONS));

    uint64_t old_lba;
    if (is_primary) {
        old_lba = test_primary_gpt.header.backup_lba;
        test_primary_gpt.header.backup_lba = invalid_lba;
    } else {
        old_lba = test_backup_gpt.header.current_lba;
        test_backup_gpt.header.current_lba = invalid_lba;
    }
    setup_test_gpt_layout();

    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_SIGNATURE, gpt_validate(is_primary));

    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_uninit());
    if (is_primary) {
        test_primary_gpt.header.backup_lba = old_lba;
    } else {
        test_backup_gpt.header.current_lba = old_lba;
    }
    setup_test_gpt_layout();
}

/* Helper for test_gpt_validate_should_failWhenBackupLbaNotAtEndOfDisk */
static void validate_partition_array_in_usable_disk_space(uint64_t invalid_lba, bool is_primary)
{
    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_init(&mock_driver, TEST_MAX_PARTITIONS));

    uint64_t old_lba;
    if (is_primary) {
        old_lba = test_primary_gpt.header.array_lba;
        test_primary_gpt.header.array_lba = invalid_lba;
    } else {
        old_lba = test_backup_gpt.header.array_lba;
        test_backup_gpt.header.array_lba = invalid_lba;
    }
    setup_test_gpt_layout();

    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_SIGNATURE, gpt_validate(is_primary));

    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_uninit());
    if (is_primary) {
        test_primary_gpt.header.array_lba = old_lba;
    } else {
        test_backup_gpt.header.array_lba = old_lba;
    }
    setup_test_gpt_layout();
}

void setUp(void)
{
    memset(&test_primary_gpt, 0, sizeof(test_primary_gpt));
    memset(&test_backup_gpt, 0, sizeof(test_backup_gpt));
    memset(&test_partition_array, 0, sizeof(test_partition_array));
    memset(test_mock_flash, TEST_FLASH_ERASE_VALUE, TEST_BLOCK_SIZE * TEST_FLASH_NUM_BLOCKS);

    /* Default starting points */
    test_mbr = default_mbr;
    test_primary_gpt.header = default_header;

    memcpy(&test_partition_array, &default_partition_array, sizeof(default_partition_array));
    for (size_t i = 0; i < TEST_DEFAULT_NUM_PARTITIONS; ++i) {
        char unicode_name[GPT_ENTRY_NAME_LENGTH] = {'\0'};
        ascii_to_unicode(test_partition_array[i].name, unicode_name);
        memcpy(test_partition_array[i].name, unicode_name, GPT_ENTRY_NAME_LENGTH);
    }

    make_backup_header();

    test_mbr.partitions[0].os_type = TEST_MBR_TYPE_GPT;

    /* Any time this is called, return the same number and ignore the arguments */
    efi_soft_crc32_update_IgnoreAndReturn(test_primary_gpt.header.header_crc);

    setup_test_gpt_layout();
}

void tearDown(void)
{
    memset(&test_primary_gpt, 0, sizeof(test_primary_gpt));
    memset(&test_backup_gpt, 0, sizeof(test_backup_gpt));
    memset(&test_partition_array, 0, sizeof(test_partition_array));
    memset(test_mock_flash, TEST_FLASH_ERASE_VALUE, TEST_BLOCK_SIZE * TEST_FLASH_NUM_BLOCKS);
}

void test_gpt_init_should_loadWhenGptGood(void)
{
    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_init(&mock_driver, TEST_MAX_PARTITIONS));
    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_uninit());
}

void test_gpt_init_should_overwriteOldGpt(void)
{
    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_init(&mock_driver, TEST_MAX_PARTITIONS));
    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_uninit());

    /* Use a different flash GUID */
    const struct efi_guid_t new_guid = TEST_GPT_VALID_GUID(1, 1, 3, 4, 5, 6, 7, 8, 9, 10, 11);
    test_primary_gpt.header.flash_guid = new_guid;
    setup_test_gpt_layout();

    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_init(&mock_driver, TEST_MAX_PARTITIONS));
    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_uninit());
}

void test_gpt_init_should_acceptPrimaryArrayLbaNotTwo(void)
{
    test_primary_gpt.header.array_lba++;
    setup_test_gpt_layout();

    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_init(&mock_driver, TEST_MAX_PARTITIONS));
    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_uninit());
}

void test_gpt_init_should_OnlyConsiderContiguousPartitionEntryArrays(void)
{
    /* Sparse array, where 2 partitions are contiguous */
    const uint32_t test_num_partitions = 2;

    memcpy(&(test_partition_array[test_num_partitions]),
            &(test_partition_array[test_num_partitions + 1]),
            sizeof(test_partition_array[test_num_partitions]));
    memset(&(test_partition_array[test_num_partitions]),
            0,
            sizeof(test_partition_array[test_num_partitions]));

    setup_test_gpt_layout();

    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_init(&mock_driver, TEST_MAX_PARTITIONS));
    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_uninit());
}

void test_gpt_init_should_failWhenMbrSigBad(void)
{
    test_mbr.sig--;
    setup_test_gpt_layout();

    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_SIGNATURE, gpt_init(&mock_driver, TEST_MAX_PARTITIONS));
    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_uninit());
}

void test_gpt_init_should_failWhenMbrTypeInvalid(void)
{
    test_mbr.partitions[0].os_type--;
    setup_test_gpt_layout();

    TEST_ASSERT_EQUAL(PSA_ERROR_NOT_SUPPORTED, gpt_init(&mock_driver, TEST_MAX_PARTITIONS));
    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_uninit());
}

void test_gpt_init_should_failWhenEntrySizeBad(void)
{
    test_primary_gpt.header.entry_size--;
    setup_test_gpt_layout();

    TEST_ASSERT_EQUAL(PSA_ERROR_NOT_SUPPORTED, gpt_init(&mock_driver, TEST_MAX_PARTITIONS));

    /* Now do the backup */
    test_primary_gpt.header.entry_size = default_header.entry_size;
    test_backup_gpt.header.entry_size = 0;

    TEST_ASSERT_EQUAL(PSA_ERROR_NOT_SUPPORTED, gpt_init(&mock_driver, TEST_MAX_PARTITIONS));
    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_uninit());
}

void test_gpt_init_should_failWhenFlashDriverNotFullyDefined(void)
{
    gpt_flash_read_t read_fn = mock_driver.read;
    mock_driver.read = NULL;
    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_ARGUMENT, gpt_init(&mock_driver, TEST_MAX_PARTITIONS));
    mock_driver.read = read_fn;

    gpt_flash_write_t write_fn = mock_driver.write;
    mock_driver.write = NULL;
    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_ARGUMENT, gpt_init(&mock_driver, TEST_MAX_PARTITIONS));
    mock_driver.write = write_fn;

    gpt_flash_erase_t erase_fn = mock_driver.erase;
    mock_driver.erase = NULL;
    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_ARGUMENT, gpt_init(&mock_driver, TEST_MAX_PARTITIONS));
    mock_driver.erase = erase_fn;

    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_uninit());
}

void test_gpt_validate_should_validateWhenGptGood(void)
{
    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_init(&mock_driver, TEST_MAX_PARTITIONS));

    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_validate(true));
    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_validate(false));

    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_uninit());
}

void test_gpt_validate_should_failWhenGptSigBad(void)
{
    test_primary_gpt.header.signature[0] = '\0';
    test_backup_gpt.header.signature[0] = '\0';
    setup_test_gpt_layout();
    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_init(&mock_driver, TEST_MAX_PARTITIONS));

    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_SIGNATURE, gpt_validate(true));
    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_SIGNATURE, gpt_validate(false));

    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_uninit());
}

void test_gpt_validate_should_failWhenHeaderCrcBad(void)
{
    test_primary_gpt.header.header_crc--;
    test_backup_gpt.header.header_crc--;
    setup_test_gpt_layout();
    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_init(&mock_driver, TEST_MAX_PARTITIONS));

    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_SIGNATURE, gpt_validate(true));
    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_SIGNATURE, gpt_validate(false));

    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_uninit());
}

void test_gpt_validate_should_failWhenLbaPointerBad(void)
{
    test_primary_gpt.header.current_lba--;
    test_backup_gpt.header.current_lba--;
    setup_test_gpt_layout();

    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_init(&mock_driver, TEST_MAX_PARTITIONS));

    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_SIGNATURE, gpt_validate(true));
    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_SIGNATURE, gpt_validate(false));

    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_uninit());
}

void test_gpt_validate_should_failWhenBackupEntrySizeInvalid(void)
{
    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_init(&mock_driver, TEST_MAX_PARTITIONS));

    test_primary_gpt.header.entry_size--;
    test_backup_gpt.header.entry_size--;
    setup_test_gpt_layout();

    TEST_ASSERT_EQUAL(PSA_ERROR_NOT_SUPPORTED, gpt_validate(true));
    TEST_ASSERT_EQUAL(PSA_ERROR_NOT_SUPPORTED, gpt_validate(false));

    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_uninit());
}

void test_gpt_validate_should_failWhenArrayCrcBad(void)
{
    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_init(&mock_driver, TEST_MAX_PARTITIONS));

    test_primary_gpt.header.array_crc--;
    test_backup_gpt.header.array_crc--;
    setup_test_gpt_layout();

    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_init(&mock_driver, TEST_MAX_PARTITIONS));

    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_SIGNATURE, gpt_validate(true));
    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_SIGNATURE, gpt_validate(false));

    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_uninit());
}

void test_gpt_validate_should_failWhenBackupLbaNotAtEndOfDisk(void)
{
    validate_backup_lba_not_at_end_of_disk(test_primary_gpt.header.first_lba - 1, true);
    validate_backup_lba_not_at_end_of_disk(test_primary_gpt.header.first_lba, true);
    validate_backup_lba_not_at_end_of_disk(test_primary_gpt.header.first_lba + 1, true);
    validate_backup_lba_not_at_end_of_disk(test_primary_gpt.header.last_lba - 1, true);
    validate_backup_lba_not_at_end_of_disk(test_primary_gpt.header.last_lba, true);
    validate_backup_lba_not_at_end_of_disk(test_primary_gpt.header.array_lba - 1, true);
    validate_backup_lba_not_at_end_of_disk(test_primary_gpt.header.array_lba, true);

    validate_backup_lba_not_at_end_of_disk(test_primary_gpt.header.first_lba - 1, false);
    validate_backup_lba_not_at_end_of_disk(test_primary_gpt.header.first_lba, false);
    validate_backup_lba_not_at_end_of_disk(test_primary_gpt.header.first_lba + 1, false);
    validate_backup_lba_not_at_end_of_disk(test_primary_gpt.header.last_lba - 1, false);
    validate_backup_lba_not_at_end_of_disk(test_primary_gpt.header.last_lba, false);
    validate_backup_lba_not_at_end_of_disk(TEST_GPT_BACKUP_ARRAY_LBA - 1, false);
    validate_backup_lba_not_at_end_of_disk(TEST_GPT_BACKUP_ARRAY_LBA, false);
}

void test_gpt_validate_should_failWhenPartitionArrayInUsableDiskSpace(void)
{
    validate_partition_array_in_usable_disk_space(test_primary_gpt.header.first_lba, true);
    validate_partition_array_in_usable_disk_space(test_primary_gpt.header.first_lba + 1, true);
    validate_partition_array_in_usable_disk_space(test_primary_gpt.header.last_lba - 1, true);
    validate_partition_array_in_usable_disk_space(test_primary_gpt.header.last_lba, true);
    validate_partition_array_in_usable_disk_space(test_primary_gpt.header.last_lba + 1, true);

    validate_partition_array_in_usable_disk_space(default_header.first_lba - 1, false);
    validate_partition_array_in_usable_disk_space(default_header.first_lba, false);
    validate_partition_array_in_usable_disk_space(default_header.first_lba + 1, false);
    validate_partition_array_in_usable_disk_space(default_header.last_lba - 1, false);
    validate_partition_array_in_usable_disk_space(default_header.last_lba, false);
}
void test_gpt_restore_should_restoreTableFromValidAlternateTable(void)
{
    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_init(&mock_driver, TEST_MAX_PARTITIONS));

    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_restore(true));
    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_restore(false));

    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_uninit());
}

void test_gpt_restore_should_failToRestoreWhenAlternateTableIsBad(void)
{
    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_init(&mock_driver, TEST_MAX_PARTITIONS));

    /* The backup table is read and checked for validity. Corrupt it in
     * various ways
     */

    /* Bad signature */
    test_backup_gpt.header.signature[0] = '\0';
    setup_test_gpt_layout();
    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_SIGNATURE, gpt_restore(true));
    test_backup_gpt.header.signature[0] = default_header.signature[0];
    setup_test_gpt_layout();

    /* Bad header CRC */
    test_backup_gpt.header.header_crc = 0;
    setup_test_gpt_layout();
    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_SIGNATURE, gpt_restore(true));
    test_backup_gpt.header.header_crc = default_header.header_crc;
    setup_test_gpt_layout();

    /* Bad LBA */
    test_backup_gpt.header.current_lba = 2;
    setup_test_gpt_layout();
    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_SIGNATURE, gpt_restore(true));
    test_backup_gpt.header.current_lba = default_header.backup_lba;
    setup_test_gpt_layout();

    /* Bad array CRC. Will involve reading array entries */
    test_backup_gpt.header.array_crc = 0;
    setup_test_gpt_layout();
    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_SIGNATURE, gpt_restore(true));
    test_backup_gpt.header.array_crc = default_header.array_crc;
    setup_test_gpt_layout();

    /* Now do the backup */

    /* Bad signature */
    test_primary_gpt.header.signature[0] = '\0';
    setup_test_gpt_layout();
    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_SIGNATURE, gpt_restore(false));
    test_primary_gpt.header.signature[0] = default_header.signature[0];
    setup_test_gpt_layout();

    /* Bad header CRC */
    test_primary_gpt.header.header_crc = 0;
    setup_test_gpt_layout();
    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_SIGNATURE, gpt_restore(false));
    test_primary_gpt.header.header_crc = default_header.header_crc;
    setup_test_gpt_layout();

    /* Bad LBA */
    test_primary_gpt.header.current_lba = 2;
    setup_test_gpt_layout();
    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_SIGNATURE, gpt_restore(false));
    test_primary_gpt.header.current_lba = default_header.current_lba;
    setup_test_gpt_layout();

    /* Bad array CRC. Will involve reading array entries */
    test_primary_gpt.header.array_crc = 0;
    setup_test_gpt_layout();
    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_SIGNATURE, gpt_restore(false));
    test_primary_gpt.header.array_crc = default_header.array_crc;
    setup_test_gpt_layout();
}

void test_gpt_defragment_should_succeedWhenNoIOFailure(void)
{
    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_init(&mock_driver, TEST_MAX_PARTITIONS));

    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_defragment());

    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_uninit());
}

void test_gpt_entry_duplicate_should_DuplicateOldEntry(void)
{
    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_init(&mock_driver, TEST_MAX_PARTITIONS));

    /* Duplicate an entry. It must not overlap with an existing entry and must also
     * fit on the storage device. The GUID should be populated with something.
     */
    struct gpt_entry_t *old_entry = &(test_partition_array[0]);
    struct efi_guid_t old_guid = old_entry->unique_guid;

    /* Mock out the call to create a new GUID */
    struct efi_guid_t expected_guid = TEST_GPT_VALID_GUID(5, 5, 5, 5, 5, 6, 7, 8, 9, 10, 11);

    efi_guid_generate_random_ExpectAnyArgsAndReturn(PSA_SUCCESS);
    efi_guid_generate_random_ReturnThruPtr_guid(&expected_guid);

    /* Ensure that a new GUID is assigned and that duplication was successful */
    struct efi_guid_t new_guid = TEST_GPT_DUMMY_GUID;

    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_entry_duplicate(
                &old_guid,
                TEST_GPT_FLASH_FREE_SPACE_START,
                &new_guid));
    TEST_ASSERT_EQUAL_MEMORY(&expected_guid, &new_guid, sizeof(new_guid));

    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_uninit());

    uint64_t old_entry_size = old_entry->end - old_entry->start + 1;

    /* Check primary array is updated */
    struct gpt_entry_t *new_entry = read_entry(TEST_DEFAULT_NUM_PARTITIONS, true);

    TEST_ASSERT_EQUAL_MEMORY((&old_entry->partition_type),
            &(new_entry->partition_type),
            sizeof(old_entry->partition_type));
    TEST_ASSERT_EQUAL(old_entry->attr, new_entry->attr);
    TEST_ASSERT_EQUAL(new_entry->start, TEST_GPT_FLASH_FREE_SPACE_START);
    TEST_ASSERT_EQUAL(new_entry->end, new_entry->start + old_entry_size - 1);
    TEST_ASSERT_EQUAL_MEMORY(old_entry->name, new_entry->name, sizeof(old_entry->name));

    /* Check backup array is updated */
    new_entry = read_entry(TEST_DEFAULT_NUM_PARTITIONS, false);

    TEST_ASSERT_EQUAL_MEMORY((&old_entry->partition_type),
            &(new_entry->partition_type),
            sizeof(old_entry->partition_type));
    TEST_ASSERT_EQUAL(old_entry->attr, new_entry->attr);
    TEST_ASSERT_EQUAL(new_entry->start, TEST_GPT_FLASH_FREE_SPACE_START);
    TEST_ASSERT_EQUAL(new_entry->end, new_entry->start + old_entry_size - 1);
    TEST_ASSERT_EQUAL_MEMORY(old_entry->name, new_entry->name, sizeof(old_entry->name));
}

void test_gpt_entry_duplicate_should_createNewEntryNextToLastEntry(void)
{
    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_init(&mock_driver, TEST_MAX_PARTITIONS));

    /* Duplicate an entry, allowing the library to choose the start LBA. The
     * GUID should be populated with something
     */
    struct gpt_entry_t *old_entry = &(test_partition_array[0]);
    struct efi_guid_t old_guid = old_entry->unique_guid;

    /* Mock out the call to create a new GUID */
    struct efi_guid_t expected_guid = TEST_GPT_VALID_GUID(5, 5, 5, 5, 5, 6, 7, 8, 9, 10, 11);

    efi_guid_generate_random_ExpectAnyArgsAndReturn(PSA_SUCCESS);
    efi_guid_generate_random_ReturnThruPtr_guid(&expected_guid);

    /* Ensure that a new GUID is assigned and that duplication was successful */
    struct efi_guid_t new_guid = TEST_GPT_DUMMY_GUID;

    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_entry_duplicate(
                &old_guid,
                0,
                &new_guid));
    TEST_ASSERT_EQUAL_MEMORY(&expected_guid, &new_guid, sizeof(new_guid));

    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_uninit());

    uint64_t old_entry_size = old_entry->end - old_entry->start + 1;

    /* Check primary array is updated */
    struct gpt_entry_t *new_entry = read_entry(TEST_DEFAULT_NUM_PARTITIONS, true);

    TEST_ASSERT_EQUAL_MEMORY((&old_entry->partition_type),
            &(new_entry->partition_type),
            sizeof(old_entry->partition_type));
    TEST_ASSERT_EQUAL(old_entry->attr, new_entry->attr);
    TEST_ASSERT_EQUAL(new_entry->start, TEST_GPT_FLASH_FREE_SPACE_START);
    TEST_ASSERT_EQUAL(new_entry->end, new_entry->start + old_entry_size - 1);
    TEST_ASSERT_EQUAL_MEMORY(old_entry->name, new_entry->name, sizeof(old_entry->name));

    /* Check backup array is updated */
    new_entry = read_entry(TEST_DEFAULT_NUM_PARTITIONS, false);

    TEST_ASSERT_EQUAL_MEMORY((&old_entry->partition_type),
            &(new_entry->partition_type),
            sizeof(old_entry->partition_type));
    TEST_ASSERT_EQUAL(old_entry->attr, new_entry->attr);
    TEST_ASSERT_EQUAL(new_entry->start, TEST_GPT_FLASH_FREE_SPACE_START);
    TEST_ASSERT_EQUAL(new_entry->end, new_entry->start + old_entry_size - 1);
    TEST_ASSERT_EQUAL_MEMORY(old_entry->name, new_entry->name, sizeof(old_entry->name));
}

void test_gpt_entry_duplicate_should_failToCreateEntryWhenLowestFreeLbaDoesNotHaveSpace(void)
{
    /* Duplicate an entry, allowing the library to choose the start LBA. Resize
     * the last partition to consume over half of the disk, such that duplicating
     * it won't be possible.
     */
    struct gpt_entry_t *old_entry =
        &(test_partition_array[TEST_DEFAULT_NUM_PARTITIONS - 1]);

    old_entry->end = TEST_GPT_THIRD_PARTITION_START + (TEST_FLASH_NUM_BLOCKS / 2) + 1;
    struct efi_guid_t old_guid = old_entry->unique_guid;

    setup_test_gpt_layout();

    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_init(&mock_driver, TEST_MAX_PARTITIONS));

    struct efi_guid_t new_guid;

    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_ARGUMENT, gpt_entry_duplicate(
                &old_guid,
                0,
                &new_guid));

    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_uninit());
}

void test_gpt_entry_duplicate_should_failWhenEntryNotExisting(void)
{
    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_init(&mock_driver, TEST_MAX_PARTITIONS));

    struct efi_guid_t old_guid = NULL_GUID;

    struct efi_guid_t new_guid;

    TEST_ASSERT_EQUAL(PSA_ERROR_DOES_NOT_EXIST, gpt_entry_duplicate(
                &old_guid,
                TEST_GPT_FLASH_FREE_SPACE_START,
                &new_guid));

    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_uninit());
}

void test_gpt_entry_duplicate_should_failWhenNewEntryOverlapping(void)
{
    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_init(&mock_driver, TEST_MAX_PARTITIONS));

    struct gpt_entry_t *old_entry = &(test_partition_array[0]);
    struct efi_guid_t old_guid = old_entry->unique_guid;
    struct efi_guid_t new_guid;

    /* Since the disk is not fragmented by default, there are two test cases:
     *   1. start in the middle of a partition and end in the middle of a partition
     *   2. start in the middle of a partition and end in free space
     */
    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_ARGUMENT, gpt_entry_duplicate(
                &old_guid,
                TEST_GPT_FIRST_PARTITION_START + 1,
                &new_guid));

    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_ARGUMENT, gpt_entry_duplicate(
                &old_guid,
                TEST_GPT_THIRD_PARTITION_START + 1,
                &new_guid));

    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_uninit());
}

void test_gpt_entry_duplicate_should_failWhenTableFull(void)
{
    /* Start with a full array of entries */
    const uint64_t new_entry_end = TEST_GPT_FLASH_FREE_SPACE_START;
    struct gpt_entry_t new_entry = {
        .partition_type = TEST_GPT_VALID_TYPE(4, 4, 4, 4, 5, 6, 7, 8, 9, 10, 11),
        .start = new_entry_end,
        .end = new_entry_end,
        .attr = 0,
        .unique_guid = TEST_GPT_VALID_GUID(4, 4, 4, 4, 5, 6, 7, 8, 9, 10, 11),
        .name = "Fourth partition"
    };
    test_partition_array[TEST_MAX_PARTITIONS - 1] = new_entry;
    setup_test_gpt_layout();

    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_init(&mock_driver, TEST_MAX_PARTITIONS));

    struct gpt_entry_t *old_entry = &(test_partition_array[0]);
    struct efi_guid_t old_guid = old_entry->unique_guid;
    struct efi_guid_t new_guid;

    TEST_ASSERT_EQUAL(PSA_ERROR_INSUFFICIENT_STORAGE, gpt_entry_duplicate(
                &old_guid,
                new_entry_end + 1,
                &new_guid));

    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_uninit());
}

void test_gpt_entry_duplicate_no_copy_should_DuplicateOldEntry(void)
{
    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_init(&mock_driver, TEST_MAX_PARTITIONS));

    /* Duplicate an entry. It must not overlap with an existing entry and must also
     * fit on the storage device. The GUID should be populated with something.
     */
    struct gpt_entry_t *old_entry = &(test_partition_array[0]);
    struct efi_guid_t old_guid = old_entry->unique_guid;

    /* Mock out the call to create a new GUID */
    struct efi_guid_t expected_guid = TEST_GPT_VALID_GUID(5, 5, 5, 5, 5, 6, 7, 8, 9, 10, 11);

    efi_guid_generate_random_ExpectAnyArgsAndReturn(PSA_SUCCESS);
    efi_guid_generate_random_ReturnThruPtr_guid(&expected_guid);

    /* Ensure that a new GUID is assigned and that duplication was successful */
    struct efi_guid_t new_guid = TEST_GPT_DUMMY_GUID;

    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_entry_duplicate_no_copy(
                &old_guid,
                TEST_GPT_FLASH_FREE_SPACE_START,
                &new_guid));
    TEST_ASSERT_EQUAL_MEMORY(&expected_guid, &new_guid, sizeof(new_guid));

    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_uninit());

    uint64_t old_entry_size = old_entry->end - old_entry->start + 1;

    /* Check primary array is updated */
    struct gpt_entry_t *new_entry = read_entry(TEST_DEFAULT_NUM_PARTITIONS, true);

    TEST_ASSERT_EQUAL_MEMORY((&old_entry->partition_type),
            &(new_entry->partition_type),
            sizeof(old_entry->partition_type));
    TEST_ASSERT_EQUAL(old_entry->attr, new_entry->attr);
    TEST_ASSERT_EQUAL(new_entry->start, TEST_GPT_FLASH_FREE_SPACE_START);
    TEST_ASSERT_EQUAL(new_entry->end, new_entry->start + old_entry_size - 1);
    TEST_ASSERT_EQUAL_MEMORY(old_entry->name, new_entry->name, sizeof(old_entry->name));

    /* Check backup array is updated */
    new_entry = read_entry(TEST_DEFAULT_NUM_PARTITIONS, false);

    TEST_ASSERT_EQUAL_MEMORY((&old_entry->partition_type),
            &(new_entry->partition_type),
            sizeof(old_entry->partition_type));
    TEST_ASSERT_EQUAL(old_entry->attr, new_entry->attr);
    TEST_ASSERT_EQUAL(new_entry->start, TEST_GPT_FLASH_FREE_SPACE_START);
    TEST_ASSERT_EQUAL(new_entry->end, new_entry->start + old_entry_size - 1);
    TEST_ASSERT_EQUAL_MEMORY(old_entry->name, new_entry->name, sizeof(old_entry->name));
}

void test_gpt_entry_duplicate_no_copy_should_createNewEntryNextToLastEntry(void)
{
    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_init(&mock_driver, TEST_MAX_PARTITIONS));

    /* Duplicate an entry, allowing the library to choose the start LBA. The
     * GUID should be populated with something
     */
    struct gpt_entry_t *old_entry = &(test_partition_array[0]);
    struct efi_guid_t old_guid = old_entry->unique_guid;

    /* Mock out the call to create a new GUID */
    struct efi_guid_t expected_guid = TEST_GPT_VALID_GUID(5, 5, 5, 5, 5, 6, 7, 8, 9, 10, 11);

    efi_guid_generate_random_ExpectAnyArgsAndReturn(PSA_SUCCESS);
    efi_guid_generate_random_ReturnThruPtr_guid(&expected_guid);

    /* Ensure that a new GUID is assigned and that duplication was successful */
    struct efi_guid_t new_guid = TEST_GPT_DUMMY_GUID;

    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_entry_duplicate_no_copy(
                &old_guid,
                0,
                &new_guid));
    TEST_ASSERT_EQUAL_MEMORY(&expected_guid, &new_guid, sizeof(new_guid));

    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_uninit());

    uint64_t old_entry_size = old_entry->end - old_entry->start + 1;

    /* Check primary array is updated */
    struct gpt_entry_t *new_entry = read_entry(TEST_DEFAULT_NUM_PARTITIONS, true);

    TEST_ASSERT_EQUAL_MEMORY((&old_entry->partition_type),
            &(new_entry->partition_type),
            sizeof(old_entry->partition_type));
    TEST_ASSERT_EQUAL(old_entry->attr, new_entry->attr);
    TEST_ASSERT_EQUAL(new_entry->start, TEST_GPT_FLASH_FREE_SPACE_START);
    TEST_ASSERT_EQUAL(new_entry->end, new_entry->start + old_entry_size - 1);
    TEST_ASSERT_EQUAL_MEMORY(old_entry->name, new_entry->name, sizeof(old_entry->name));

    /* Check backup array is updated */
    new_entry = read_entry(TEST_DEFAULT_NUM_PARTITIONS, false);

    TEST_ASSERT_EQUAL_MEMORY((&old_entry->partition_type),
            &(new_entry->partition_type),
            sizeof(old_entry->partition_type));
    TEST_ASSERT_EQUAL(old_entry->attr, new_entry->attr);
    TEST_ASSERT_EQUAL(new_entry->start, TEST_GPT_FLASH_FREE_SPACE_START);
    TEST_ASSERT_EQUAL(new_entry->end, new_entry->start + old_entry_size - 1);
    TEST_ASSERT_EQUAL_MEMORY(old_entry->name, new_entry->name, sizeof(old_entry->name));
}

void test_gpt_entry_duplicate_no_copy_should_failToCreateEntryWhenLowestFreeLbaDoesNotHaveSpace(void)
{
    /* Duplicate an entry, allowing the library to choose the start LBA. Resize
     * the last partition to consume over half of the disk, such that duplicating
     * it won't be possible.
     */
    struct gpt_entry_t *old_entry =
        &(test_partition_array[TEST_DEFAULT_NUM_PARTITIONS - 1]);

    old_entry->end = TEST_GPT_THIRD_PARTITION_START + (TEST_FLASH_NUM_BLOCKS / 2) + 1;
    struct efi_guid_t old_guid = old_entry->unique_guid;

    setup_test_gpt_layout();

    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_init(&mock_driver, TEST_MAX_PARTITIONS));

    struct efi_guid_t new_guid;

    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_ARGUMENT, gpt_entry_duplicate_no_copy(
                &old_guid,
                0,
                &new_guid));

    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_uninit());
}

void test_gpt_entry_duplicate_no_copy_should_failWhenEntryNotExisting(void)
{
    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_init(&mock_driver, TEST_MAX_PARTITIONS));

    struct efi_guid_t old_guid = NULL_GUID;

    struct efi_guid_t new_guid;

    TEST_ASSERT_EQUAL(PSA_ERROR_DOES_NOT_EXIST, gpt_entry_duplicate_no_copy(
                &old_guid,
                TEST_GPT_FLASH_FREE_SPACE_START,
                &new_guid));

    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_uninit());
}

void test_gpt_entry_duplicate_no_copy_should_failWhenNewEntryOverlapping(void)
{
    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_init(&mock_driver, TEST_MAX_PARTITIONS));

    struct gpt_entry_t *old_entry = &(test_partition_array[0]);
    struct efi_guid_t old_guid = old_entry->unique_guid;
    struct efi_guid_t new_guid;

    /* Since the disk is not fragmented by default, there are two test cases:
     *   1. start in the middle of a partition and end in the middle of a partition
     *   2. start in the middle of a partition and end in free space
     */
    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_ARGUMENT, gpt_entry_duplicate_no_copy(
                &old_guid,
                TEST_GPT_FIRST_PARTITION_START + 1,
                &new_guid));

    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_ARGUMENT, gpt_entry_duplicate_no_copy(
                &old_guid,
                TEST_GPT_THIRD_PARTITION_START + 1,
                &new_guid));

    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_uninit());
}

void test_gpt_entry_duplicate_no_copy_should_failWhenTableFull(void)
{
    /* Start with a full array of entries */
    const uint64_t new_entry_end = TEST_GPT_FLASH_FREE_SPACE_START;
    struct gpt_entry_t new_entry = {
        .partition_type = TEST_GPT_VALID_TYPE(4, 4, 4, 4, 5, 6, 7, 8, 9, 10, 11),
        .start = new_entry_end,
        .end = new_entry_end,
        .attr = 0,
        .unique_guid = TEST_GPT_VALID_GUID(4, 4, 4, 4, 5, 6, 7, 8, 9, 10, 11),
        .name = "Fourth partition"
    };
    test_partition_array[TEST_MAX_PARTITIONS - 1] = new_entry;
    setup_test_gpt_layout();

    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_init(&mock_driver, TEST_MAX_PARTITIONS));

    struct gpt_entry_t *old_entry = &(test_partition_array[0]);
    struct efi_guid_t old_guid = old_entry->unique_guid;
    struct efi_guid_t new_guid;

    TEST_ASSERT_EQUAL(PSA_ERROR_INSUFFICIENT_STORAGE, gpt_entry_duplicate_no_copy(
                &old_guid,
                new_entry_end + 1,
                &new_guid));

    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_uninit());
}

void test_gpt_entry_create_should_createNewEntry(void)
{
    /* Add an entry. It must not overlap with an existing entry and must also
     * fit on the storage device. The GUID should be populated with something.
     */
    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_init(&mock_driver, TEST_MAX_PARTITIONS));

    struct gpt_entry_t new_entry = {
        .partition_type = TEST_GPT_DUMMY_TYPE,
        .start = TEST_GPT_FLASH_FREE_SPACE_START,
        .end = TEST_GPT_FLASH_FREE_SPACE_START,
        .attr = 0,
        .name = "Fourth partition"
    };

    /* Mock out the call to create a new GUID */
    struct efi_guid_t expected_guid = TEST_GPT_VALID_GUID(5, 5, 5, 5, 5, 6, 7, 8, 9, 10, 11);
    efi_guid_generate_random_ExpectAnyArgsAndReturn(PSA_SUCCESS);
    efi_guid_generate_random_ReturnThruPtr_guid(&expected_guid);

    struct efi_guid_t new_guid = TEST_GPT_DUMMY_GUID;
    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_entry_create(
                &expected_guid,
                new_entry.start,
                new_entry.end - new_entry.start + 1,
                new_entry.attr,
                new_entry.name,
                &new_guid));
    TEST_ASSERT_EQUAL_MEMORY(&expected_guid, &new_guid, sizeof(new_guid));

    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_uninit());

    /* Check primary array is updated */
    struct gpt_entry_t *written_entry = read_entry(TEST_DEFAULT_NUM_PARTITIONS, true);

    TEST_ASSERT_EQUAL_MEMORY(&expected_guid, &(written_entry->partition_type),
            sizeof(expected_guid));
    TEST_ASSERT_EQUAL(new_entry.attr, written_entry->attr);
    TEST_ASSERT_EQUAL(new_entry.start, written_entry->start);
    TEST_ASSERT_EQUAL(new_entry.end, written_entry->end);
    TEST_ASSERT_EQUAL_MEMORY(new_entry.name, written_entry->name, sizeof(new_entry.name));

    /* Check backup array is updated */
    written_entry = read_entry(TEST_DEFAULT_NUM_PARTITIONS, false);

    TEST_ASSERT_EQUAL_MEMORY(&expected_guid, &(written_entry->partition_type),
            sizeof(expected_guid));
    TEST_ASSERT_EQUAL(new_entry.attr, written_entry->attr);
    TEST_ASSERT_EQUAL(new_entry.start, written_entry->start);
    TEST_ASSERT_EQUAL(new_entry.end, written_entry->end);
    TEST_ASSERT_EQUAL_MEMORY(new_entry.name, written_entry->name, sizeof(new_entry.name));
}

void test_gpt_entry_create_should_createNewEntryNextToLastEntry(void)
{
    /* Add an entry, allowing the library to choose the start LBA.
     * The GUID should be populated with something.
     */
    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_init(&mock_driver, TEST_MAX_PARTITIONS));

    struct gpt_entry_t new_entry = {
        .partition_type = TEST_GPT_DUMMY_TYPE,
        .start = TEST_GPT_FLASH_FREE_SPACE_START,
        .end = TEST_GPT_FLASH_FREE_SPACE_START,
        .attr = 0,
        .name = "Fourth partition"
    };

    /* Mock out the call to create a new GUID */
    struct efi_guid_t expected_guid = TEST_GPT_VALID_GUID(5, 5, 5, 5, 5, 6, 7, 8, 9, 10, 11);
    efi_guid_generate_random_ExpectAnyArgsAndReturn(PSA_SUCCESS);
    efi_guid_generate_random_ReturnThruPtr_guid(&expected_guid);

    struct efi_guid_t new_guid = TEST_GPT_DUMMY_GUID;
    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_entry_create(
                &expected_guid,
                new_entry.start,
                new_entry.end - new_entry.start + 1,
                new_entry.attr,
                new_entry.name,
                &new_guid));
    TEST_ASSERT_EQUAL_MEMORY(&expected_guid, &new_guid, sizeof(new_guid));

    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_uninit());

    /* Check primary array is updated */
    struct gpt_entry_t *written_entry = read_entry(TEST_DEFAULT_NUM_PARTITIONS, true);

    TEST_ASSERT_EQUAL_MEMORY(&expected_guid, &(written_entry->partition_type),
            sizeof(expected_guid));
    TEST_ASSERT_EQUAL(new_entry.attr, written_entry->attr);
    TEST_ASSERT_EQUAL(new_entry.start, written_entry->start);
    TEST_ASSERT_EQUAL(new_entry.end, written_entry->end);
    TEST_ASSERT_EQUAL_MEMORY(new_entry.name, written_entry->name, sizeof(new_entry.name));

    /* Check backup array is updated */
    written_entry = read_entry(TEST_DEFAULT_NUM_PARTITIONS, false);

    TEST_ASSERT_EQUAL_MEMORY(&expected_guid, &(written_entry->partition_type),
            sizeof(expected_guid));
    TEST_ASSERT_EQUAL(new_entry.attr, written_entry->attr);
    TEST_ASSERT_EQUAL(new_entry.start, written_entry->start);
    TEST_ASSERT_EQUAL(new_entry.end, written_entry->end);
    TEST_ASSERT_EQUAL_MEMORY(new_entry.name, written_entry->name, sizeof(new_entry.name));
}

void test_gpt_entry_create_should_failToCreateEntryWhenLowestFreeLbaDoesNotHaveSpace(void)
{
    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_init(&mock_driver, TEST_MAX_PARTITIONS));

    struct efi_guid_t type_guid = TEST_GPT_VALID_GUID(4, 4, 4, 4, 5, 6, 7, 8, 9, 10, 11);
    struct efi_guid_t new_guid;
    char name[GPT_ENTRY_NAME_LENGTH] = {'\0'};
    name[0] = 'a';

    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_ARGUMENT, gpt_entry_create(
                &(type_guid),
                0,
                TEST_FLASH_NUM_BLOCKS,
                0,
                name,
                &(new_guid)));

    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_uninit());
}

void test_gpt_entry_create_should_failWhenTableFull(void)
{
    /* Start with a full array of entries */
    const uint64_t new_entry_end = TEST_GPT_FLASH_FREE_SPACE_START;
    struct gpt_entry_t new_entry = {
        .partition_type = TEST_GPT_VALID_TYPE(4, 4, 4, 4, 5, 6, 7, 8, 9, 10, 11),
        .start = new_entry_end,
        .end = new_entry_end,
        .attr = 0,
        .unique_guid = TEST_GPT_VALID_GUID(4, 4, 4, 4, 5, 6, 7, 8, 9, 10, 11),
        .name = "Fourth partition"
    };
    test_partition_array[TEST_MAX_PARTITIONS - 1] = new_entry;

    setup_test_gpt_layout();
    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_init(&mock_driver, TEST_MAX_PARTITIONS));

    struct efi_guid_t type = TEST_GPT_VALID_TYPE(5, 5, 5, 5, 5, 6, 7, 8, 9, 10, 11);
    struct efi_guid_t guid;
    char name[GPT_ENTRY_NAME_LENGTH] = {'\0'};
    name[0] = 'a';
    const uint64_t new_free_space = new_entry_end + 1;

    TEST_ASSERT_EQUAL(PSA_ERROR_INSUFFICIENT_STORAGE, gpt_entry_create(
                &type,
                new_free_space,
                1,
                0,
                name,
                &guid));

    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_uninit());
}

void test_gpt_entry_create_should_failWhenLbaOffDisk(void)
{
    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_init(&mock_driver, TEST_MAX_PARTITIONS));

    /* First start on disk, then go off the disk */
    struct efi_guid_t type = TEST_GPT_DUMMY_TYPE;
    struct efi_guid_t guid;
    char name[GPT_ENTRY_NAME_LENGTH] = {'\0'};
    name[0] = 'a';
    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_ARGUMENT, gpt_entry_create(
                &type,
                TEST_GPT_FLASH_FREE_SPACE_START,
                1000,
                0,
                name,
                &guid));

    /* Second, start off the disk entirely */
    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_ARGUMENT, gpt_entry_create(
                &type,
                TEST_FLASH_NUM_BLOCKS + 100,
                1,
                0,
                name,
                &guid));

    /* Third, do the same but in the header area */
    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_ARGUMENT, gpt_entry_create(
                &type,
                TEST_GPT_PRIMARY_LBA,
                1,
                0,
                name,
                &guid));

    /* Fourth, start in the backup header area */
    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_ARGUMENT, gpt_entry_create(
                &type,
                TEST_GPT_BACKUP_LBA,
                1,
                0,
                name,
                &guid));

    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_uninit());
}

void test_gpt_entry_create_should_failWhenOverlapping(void)
{
    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_init(&mock_driver, TEST_MAX_PARTITIONS));

    /* Since the disk is not fragmented by default, there are two test cases:
     *   1. start in the middle of a partition and end in the middle of a partition
     *   2. start in the middle of a partition and end in free space
     */
    struct efi_guid_t type = TEST_GPT_DUMMY_TYPE;
    struct efi_guid_t guid;
    char name[GPT_ENTRY_NAME_LENGTH] = {'\0'};
    name[0] = 'a';

    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_ARGUMENT, gpt_entry_create(
                &type,
                TEST_GPT_FIRST_PARTITION_START,
                TEST_GPT_FIRST_PARTITION_END - TEST_GPT_FIRST_PARTITION_START + 1,
                0,
                name,
                &guid));

    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_ARGUMENT, gpt_entry_create(
                &type,
                TEST_GPT_FIRST_PARTITION_START,
                TEST_GPT_LAST_USABLE_LBA - TEST_GPT_FIRST_PARTITION_START,
                0,
                name,
                &guid));

    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_uninit());
}

void test_gpt_entry_create_should_failWhenNameIsEmpty(void)
{
    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_init(&mock_driver, TEST_MAX_PARTITIONS));

    struct efi_guid_t type = TEST_GPT_DUMMY_TYPE;
    struct gpt_entry_t new_entry = {
        .partition_type = type,
        .start = TEST_GPT_FLASH_FREE_SPACE_START,
        .end = TEST_GPT_FLASH_FREE_SPACE_START,
        .attr = 0,
    };

    /* Make an entry with an empty name */
    char name[GPT_ENTRY_NAME_LENGTH] = {'\0'};
    struct efi_guid_t new_guid;
    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_ARGUMENT, gpt_entry_create(
                &type,
                new_entry.start,
                1,
                0,
                name,
                &new_guid));

    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_uninit());
}

void test_gpt_entry_create_should_failWhenSizeIsZero(void)
{
    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_init(&mock_driver, TEST_MAX_PARTITIONS));

    struct efi_guid_t type = TEST_GPT_DUMMY_TYPE;

    /* Make the size zero */
    struct efi_guid_t new_guid;
    char name[GPT_ENTRY_NAME_LENGTH] = {'\0'};

    name[0] = 'a';
    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_ARGUMENT, gpt_entry_create(
                &type,
                TEST_GPT_FLASH_FREE_SPACE_START,
                0,
                0,
                name,
                &new_guid));

    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_uninit());
}

void test_gpt_entry_move_should_moveEntry(void)
{
    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_init(&mock_driver, TEST_MAX_PARTITIONS));

    const uint32_t test_entry_index = TEST_DEFAULT_NUM_PARTITIONS - 1;
    struct gpt_entry_t *test_entry = &(test_partition_array[test_entry_index]);
    struct efi_guid_t test_guid = test_entry->unique_guid;
    const uint32_t test_start = TEST_GPT_FLASH_FREE_SPACE_START;
    const uint32_t test_end = TEST_GPT_FLASH_FREE_SPACE_START;

    /* Do a valid move and resize in one */
    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_entry_move(
                &test_guid,
                test_start,
                test_end));

    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_uninit());

    /* Check primary array is updated. Everything other than start and end should remain */
    struct gpt_entry_t *written_entry = read_entry(test_entry_index, true);

    TEST_ASSERT_EQUAL_MEMORY((&test_entry->unique_guid),
            &(written_entry->unique_guid),
            sizeof(test_entry->unique_guid));
    TEST_ASSERT_EQUAL_MEMORY((&test_entry->partition_type),
            &(written_entry->partition_type),
            sizeof(test_entry->partition_type));
    TEST_ASSERT_EQUAL(test_entry->attr, written_entry->attr);
    TEST_ASSERT_EQUAL(written_entry->start, test_start);
    TEST_ASSERT_EQUAL(written_entry->end, test_end);
    TEST_ASSERT_EQUAL_MEMORY(test_entry->name, written_entry->name, sizeof(test_entry->name));

    /* Check backup array is updated */
    written_entry = read_entry(test_entry_index, false);

    TEST_ASSERT_EQUAL_MEMORY((&test_entry->unique_guid),
            &(written_entry->unique_guid),
            sizeof(test_entry->unique_guid));
    TEST_ASSERT_EQUAL_MEMORY((&test_entry->partition_type),
            &(written_entry->partition_type),
            sizeof(test_entry->partition_type));
    TEST_ASSERT_EQUAL(test_entry->attr, written_entry->attr);
    TEST_ASSERT_EQUAL(written_entry->start, test_start);
    TEST_ASSERT_EQUAL(written_entry->end, test_end);
    TEST_ASSERT_EQUAL_MEMORY(test_entry->name, written_entry->name, sizeof(test_entry->name));
}

void test_gpt_entry_move_should_failWhenEntryNotExisting(void)
{
    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_init(&mock_driver, TEST_MAX_PARTITIONS));

    struct efi_guid_t non_existing = NULL_GUID;
    TEST_ASSERT_EQUAL(PSA_ERROR_DOES_NOT_EXIST, gpt_entry_move(
                &non_existing,
                TEST_GPT_FLASH_FREE_SPACE_START,
                TEST_GPT_FLASH_FREE_SPACE_START));

    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_uninit());
}

void test_gpt_entry_move_should_failWhenEndLessThanStart(void)
{
    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_init(&mock_driver, TEST_MAX_PARTITIONS));

    struct efi_guid_t test_guid = test_partition_array[0].unique_guid;
    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_ARGUMENT, gpt_entry_move(
                &test_guid,
                TEST_GPT_FLASH_FREE_SPACE_START + 1,
                TEST_GPT_FLASH_FREE_SPACE_START));

    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_uninit());
}

void test_gpt_entry_move_should_failWhenLbaOverlapping(void)
{
    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_init(&mock_driver, TEST_MAX_PARTITIONS));

    /* Try to move the test entry into the middle of some other entry.
     * Starting at the same LBA
     */
    size_t test_index = 1;
    struct gpt_entry_t *test_entry = &(test_partition_array[test_index]);
    struct efi_guid_t test_guid = test_entry->unique_guid;

    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_ARGUMENT, gpt_entry_move(
                &test_guid,
                TEST_GPT_FIRST_PARTITION_START,
                TEST_GPT_SECOND_PARTITION_END));

    /* Try to move the test entry into the middle of some other entry.
     * Starting in the middle
     */
    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_ARGUMENT, gpt_entry_move(
                &test_guid,
                TEST_GPT_FIRST_PARTITION_START + 1,
                TEST_GPT_SECOND_PARTITION_END));

    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_ARGUMENT, gpt_entry_move(
                &test_guid,
                TEST_GPT_SECOND_PARTITION_START,
                TEST_GPT_THIRD_PARTITION_START));

    /* Try to move the test entry into the middle of the entry just read.
     * Starting and ending in the middle.
     */

    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_ARGUMENT, gpt_entry_move(
                &test_guid,
                TEST_GPT_FIRST_PARTITION_START + 1,
                TEST_GPT_FIRST_PARTITION_START + 1));

    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_uninit());
}

void test_gpt_entry_move_should_failWhenLbaOffDisk(void)
{
    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_init(&mock_driver, TEST_MAX_PARTITIONS));

    /* Try to move an entry. */
    size_t test_index = 1;
    struct gpt_entry_t *test_entry = &(test_partition_array[test_index]);
    struct efi_guid_t test_guid = test_entry->unique_guid;

    /* First start on disk, then go off the disk */
    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_ARGUMENT, gpt_entry_move(
                &test_guid,
                TEST_GPT_FLASH_FREE_SPACE_START,
                TEST_FLASH_NUM_BLOCKS + 1));

    /* Second, start off the disk entirely */
    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_ARGUMENT, gpt_entry_move(
                &test_guid,
                TEST_FLASH_NUM_BLOCKS + 1,
                TEST_FLASH_NUM_BLOCKS + 2));

    /* Third, do the same but in the header area */
    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_ARGUMENT, gpt_entry_move(
                &test_guid,
                TEST_GPT_PRIMARY_LBA,
                TEST_GPT_FLASH_FREE_SPACE_START + 1));

    /* Fourth, start in the backup header area */
    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_ARGUMENT, gpt_entry_move(
                &test_guid,
                TEST_GPT_BACKUP_LBA,
                TEST_GPT_BACKUP_LBA + 1));

    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_uninit());
}

void test_gpt_entry_move_no_copy_should_moveEntry(void)
{
    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_init(&mock_driver, TEST_MAX_PARTITIONS));

    const uint32_t test_entry_index = TEST_DEFAULT_NUM_PARTITIONS - 1;
    struct gpt_entry_t *test_entry = &(test_partition_array[test_entry_index]);
    struct efi_guid_t test_guid = test_entry->unique_guid;
    const uint32_t test_start = TEST_GPT_FLASH_FREE_SPACE_START;
    const uint32_t test_end = TEST_GPT_FLASH_FREE_SPACE_START;

    /* Do a valid move and resize in one */
    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_entry_move_no_copy(
                &test_guid,
                test_start,
                test_end));

    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_uninit());

    /* Check primary array is updated. Everything other than start and end should remain */
    struct gpt_entry_t *written_entry = read_entry(test_entry_index, true);

    TEST_ASSERT_EQUAL_MEMORY((&test_entry->unique_guid),
            &(written_entry->unique_guid),
            sizeof(test_entry->unique_guid));
    TEST_ASSERT_EQUAL_MEMORY((&test_entry->partition_type),
            &(written_entry->partition_type),
            sizeof(test_entry->partition_type));
    TEST_ASSERT_EQUAL(test_entry->attr, written_entry->attr);
    TEST_ASSERT_EQUAL(written_entry->start, test_start);
    TEST_ASSERT_EQUAL(written_entry->end, test_end);
    TEST_ASSERT_EQUAL_MEMORY(test_entry->name, written_entry->name, sizeof(test_entry->name));

    /* Check backup array is updated */
    written_entry = read_entry(test_entry_index, false);

    TEST_ASSERT_EQUAL_MEMORY((&test_entry->unique_guid),
            &(written_entry->unique_guid),
            sizeof(test_entry->unique_guid));
    TEST_ASSERT_EQUAL_MEMORY((&test_entry->partition_type),
            &(written_entry->partition_type),
            sizeof(test_entry->partition_type));
    TEST_ASSERT_EQUAL(test_entry->attr, written_entry->attr);
    TEST_ASSERT_EQUAL(written_entry->start, test_start);
    TEST_ASSERT_EQUAL(written_entry->end, test_end);
    TEST_ASSERT_EQUAL_MEMORY(test_entry->name, written_entry->name, sizeof(test_entry->name));
}

void test_gpt_entry_move_no_copy_should_failWhenEntryNotExisting(void)
{
    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_init(&mock_driver, TEST_MAX_PARTITIONS));

    struct efi_guid_t non_existing = NULL_GUID;
    TEST_ASSERT_EQUAL(PSA_ERROR_DOES_NOT_EXIST, gpt_entry_move_no_copy(
                &non_existing,
                TEST_GPT_FLASH_FREE_SPACE_START,
                TEST_GPT_FLASH_FREE_SPACE_START));

    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_uninit());
}

void test_gpt_entry_move_no_copy_should_failWhenEndLessThanStart(void)
{
    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_init(&mock_driver, TEST_MAX_PARTITIONS));

    struct efi_guid_t test_guid = test_partition_array[0].unique_guid;
    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_ARGUMENT, gpt_entry_move_no_copy(
                &test_guid,
                TEST_GPT_FLASH_FREE_SPACE_START + 1,
                TEST_GPT_FLASH_FREE_SPACE_START));

    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_uninit());
}

void test_gpt_entry_move_no_copy_should_failWhenLbaOverlapping(void)
{
    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_init(&mock_driver, TEST_MAX_PARTITIONS));

    /* Try to move the test entry into the middle of some other entry.
     * Starting at the same LBA
     */
    size_t test_index = 1;
    struct gpt_entry_t *test_entry = &(test_partition_array[test_index]);
    struct efi_guid_t test_guid = test_entry->unique_guid;

    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_ARGUMENT, gpt_entry_move_no_copy(
                &test_guid,
                TEST_GPT_FIRST_PARTITION_START,
                TEST_GPT_SECOND_PARTITION_END));

    /* Try to move the test entry into the middle of some other entry.
     * Starting in the middle
     */
    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_ARGUMENT, gpt_entry_move_no_copy(
                &test_guid,
                TEST_GPT_FIRST_PARTITION_START + 1,
                TEST_GPT_SECOND_PARTITION_END));

    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_ARGUMENT, gpt_entry_move_no_copy(
                &test_guid,
                TEST_GPT_SECOND_PARTITION_START,
                TEST_GPT_THIRD_PARTITION_START));

    /* Try to move the test entry into the middle of the entry just read.
     * Starting and ending in the middle.
     */

    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_ARGUMENT, gpt_entry_move_no_copy(
                &test_guid,
                TEST_GPT_FIRST_PARTITION_START + 1,
                TEST_GPT_FIRST_PARTITION_START + 1));

    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_uninit());
}

void test_gpt_entry_move_no_copy_should_failWhenLbaOffDisk(void)
{
    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_init(&mock_driver, TEST_MAX_PARTITIONS));

    /* Try to move an entry. */
    size_t test_index = 1;
    struct gpt_entry_t *test_entry = &(test_partition_array[test_index]);
    struct efi_guid_t test_guid = test_entry->unique_guid;

    /* First start on disk, then go off the disk */
    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_ARGUMENT, gpt_entry_move_no_copy(
                &test_guid,
                TEST_GPT_FLASH_FREE_SPACE_START,
                TEST_FLASH_NUM_BLOCKS + 1));

    /* Second, start off the disk entirely */
    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_ARGUMENT, gpt_entry_move_no_copy(
                &test_guid,
                TEST_FLASH_NUM_BLOCKS + 1,
                TEST_FLASH_NUM_BLOCKS + 2));

    /* Third, do the same but in the header area */
    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_ARGUMENT, gpt_entry_move_no_copy(
                &test_guid,
                TEST_GPT_PRIMARY_LBA,
                TEST_GPT_FLASH_FREE_SPACE_START + 1));

    /* Fourth, start in the backup header area */
    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_ARGUMENT, gpt_entry_move_no_copy(
                &test_guid,
                TEST_GPT_BACKUP_LBA,
                TEST_GPT_BACKUP_LBA + 1));

    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_uninit());
}
void test_gpt_attr_set_should_setAttributes(void)
{
    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_init(&mock_driver, TEST_MAX_PARTITIONS));

    const uint32_t test_entry_index = 0;
    struct gpt_entry_t *test_entry = &(test_partition_array[test_entry_index]);
    struct efi_guid_t test_guid = test_entry->unique_guid;
    const uint64_t test_attr = 0x00420042;

    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_attr_set(&test_guid, test_attr));

    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_uninit());

    /* Check primary array is updated. Everything other than attributes should remain */
    struct gpt_entry_t *written_entry = read_entry(test_entry_index, true);

    TEST_ASSERT_EQUAL_MEMORY((&test_entry->unique_guid),
            &(written_entry->unique_guid),
            sizeof(test_entry->unique_guid));
    TEST_ASSERT_EQUAL_MEMORY((&test_entry->partition_type),
            &(written_entry->partition_type),
            sizeof(test_entry->partition_type));
    TEST_ASSERT_EQUAL(test_attr, written_entry->attr);
    TEST_ASSERT_EQUAL(written_entry->start, test_entry->start);
    TEST_ASSERT_EQUAL(written_entry->end, test_entry->end);
    TEST_ASSERT_EQUAL_MEMORY(test_entry->name, written_entry->name, sizeof(test_entry->name));

    /* Check backup array is updated */
    written_entry = read_entry(test_entry_index, false);

    TEST_ASSERT_EQUAL_MEMORY((&test_entry->unique_guid),
            &(written_entry->unique_guid),
            sizeof(test_entry->unique_guid));
    TEST_ASSERT_EQUAL_MEMORY((&test_entry->partition_type),
            &(written_entry->partition_type),
            sizeof(test_entry->partition_type));
    TEST_ASSERT_EQUAL(test_attr, written_entry->attr);
    TEST_ASSERT_EQUAL(written_entry->start, test_entry->start);
    TEST_ASSERT_EQUAL(written_entry->end, test_entry->end);
    TEST_ASSERT_EQUAL_MEMORY(test_entry->name, written_entry->name, sizeof(test_entry->name));
}

void test_gpt_attr_set_should_failWhenEntryNotExisting(void)
{
    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_init(&mock_driver, TEST_MAX_PARTITIONS));

    struct efi_guid_t non_existing = NULL_GUID;

    TEST_ASSERT_EQUAL(PSA_ERROR_DOES_NOT_EXIST, gpt_attr_set(&non_existing, 0x1));

    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_uninit());
}

void test_gpt_attr_remove_should_removeAttributes(void)
{
    const uint32_t test_entry_index = 0;
    struct gpt_entry_t *test_entry = &(test_partition_array[test_entry_index]);
    struct efi_guid_t test_guid = test_entry->unique_guid;
    const uint64_t test_attr_rm = 0x1;
    const uint64_t test_attr = test_entry->attr & ~test_attr_rm;

    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_init(&mock_driver, TEST_MAX_PARTITIONS));

    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_attr_remove(&test_guid, test_attr_rm));

    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_uninit());

    /* Check primary array is updated. Everything other than attributes should remain */
    struct gpt_entry_t *written_entry = read_entry(test_entry_index, true);

    TEST_ASSERT_EQUAL_MEMORY((&test_entry->unique_guid),
            &(written_entry->unique_guid),
            sizeof(test_entry->unique_guid));
    TEST_ASSERT_EQUAL_MEMORY((&test_entry->partition_type),
            &(written_entry->partition_type),
            sizeof(test_entry->partition_type));
    TEST_ASSERT_EQUAL(test_attr, written_entry->attr);
    TEST_ASSERT_EQUAL(written_entry->start, test_entry->start);
    TEST_ASSERT_EQUAL(written_entry->end, test_entry->end);
    TEST_ASSERT_EQUAL_MEMORY(test_entry->name, written_entry->name, sizeof(test_entry->name));

    /* Check backup array is updated */
    written_entry = read_entry(test_entry_index, false);

    TEST_ASSERT_EQUAL_MEMORY((&test_entry->unique_guid),
            &(written_entry->unique_guid),
            sizeof(test_entry->unique_guid));
    TEST_ASSERT_EQUAL_MEMORY((&test_entry->partition_type),
            &(written_entry->partition_type),
            sizeof(test_entry->partition_type));
    TEST_ASSERT_EQUAL(test_attr, written_entry->attr);
    TEST_ASSERT_EQUAL(written_entry->start, test_entry->start);
    TEST_ASSERT_EQUAL(written_entry->end, test_entry->end);
    TEST_ASSERT_EQUAL_MEMORY(test_entry->name, written_entry->name, sizeof(test_entry->name));
}

void test_gpt_attr_remove_should_failWhenEntryNotExisting(void)
{
    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_init(&mock_driver, TEST_MAX_PARTITIONS));

    struct efi_guid_t non_existing = NULL_GUID;

    TEST_ASSERT_EQUAL(PSA_ERROR_DOES_NOT_EXIST, gpt_attr_remove(&non_existing, 0x1));

    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_uninit());
}

void test_gpt_attr_add_should_addAttributes(void)
{
    const uint32_t test_entry_index = 0;
    struct gpt_entry_t *test_entry = &(test_partition_array[test_entry_index]);
    struct efi_guid_t test_guid = test_entry->unique_guid;
    const uint64_t test_attr_add = 0x00420042;
    const uint64_t test_attr = test_entry->attr | test_attr_add;

    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_init(&mock_driver, TEST_MAX_PARTITIONS));

    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_attr_add(&test_guid, test_attr_add));

    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_uninit());

    /* Check primary array is updated. Everything other than attributes should remain */
    struct gpt_entry_t *written_entry = read_entry(test_entry_index, true);

    TEST_ASSERT_EQUAL_MEMORY((&test_entry->unique_guid),
            &(written_entry->unique_guid),
            sizeof(test_entry->unique_guid));
    TEST_ASSERT_EQUAL_MEMORY((&test_entry->partition_type),
            &(written_entry->partition_type),
            sizeof(test_entry->partition_type));
    TEST_ASSERT_EQUAL(test_attr, written_entry->attr);
    TEST_ASSERT_EQUAL(written_entry->start, test_entry->start);
    TEST_ASSERT_EQUAL(written_entry->end, test_entry->end);
    TEST_ASSERT_EQUAL_MEMORY(test_entry->name, written_entry->name, sizeof(test_entry->name));

    /* Check backup array is updated */
    written_entry = read_entry(test_entry_index, false);

    TEST_ASSERT_EQUAL_MEMORY((&test_entry->unique_guid),
            &(written_entry->unique_guid),
            sizeof(test_entry->unique_guid));
    TEST_ASSERT_EQUAL_MEMORY((&test_entry->partition_type),
            &(written_entry->partition_type),
            sizeof(test_entry->partition_type));
    TEST_ASSERT_EQUAL(test_attr, written_entry->attr);
    TEST_ASSERT_EQUAL(written_entry->start, test_entry->start);
    TEST_ASSERT_EQUAL(written_entry->end, test_entry->end);
    TEST_ASSERT_EQUAL_MEMORY(test_entry->name, written_entry->name, sizeof(test_entry->name));
}

void test_gpt_attr_add_should_failWhenEntryNotExisting(void)
{
    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_init(&mock_driver, TEST_MAX_PARTITIONS));

    struct efi_guid_t non_existing = NULL_GUID;

    TEST_ASSERT_EQUAL(PSA_ERROR_DOES_NOT_EXIST, gpt_attr_add(&non_existing, 0x1));

    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_uninit());
}

void test_gpt_entry_change_type_should_setNewType(void)
{
    const uint32_t test_entry_index = 0;
    struct gpt_entry_t *test_entry = &(test_partition_array[test_entry_index]);
    struct efi_guid_t test_guid = test_entry->unique_guid;
    const struct efi_guid_t test_type = TEST_GPT_VALID_TYPE(11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1);

    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_init(&mock_driver, TEST_MAX_PARTITIONS));

    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_entry_change_type(&test_guid, &test_type));

    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_uninit());

    /* Check primary array is updated. Everything other than type should remain */
    struct gpt_entry_t *written_entry = read_entry(test_entry_index, true);

    TEST_ASSERT_EQUAL_MEMORY((&test_entry->unique_guid),
            &(written_entry->unique_guid),
            sizeof(test_entry->unique_guid));
    TEST_ASSERT_EQUAL_MEMORY(&test_type,
            &(written_entry->partition_type),
            sizeof(test_type));
    TEST_ASSERT_EQUAL(test_entry->attr, written_entry->attr);
    TEST_ASSERT_EQUAL(written_entry->start, test_entry->start);
    TEST_ASSERT_EQUAL(written_entry->end, test_entry->end);
    TEST_ASSERT_EQUAL_MEMORY(test_entry->name, written_entry->name, sizeof(test_entry->name));

    /* Check backup array is updated */
    written_entry = read_entry(test_entry_index, false);

    TEST_ASSERT_EQUAL_MEMORY((&test_entry->unique_guid),
            &(written_entry->unique_guid),
            sizeof(test_entry->unique_guid));
    TEST_ASSERT_EQUAL_MEMORY(&test_type,
            &(written_entry->partition_type),
            sizeof(test_type));
    TEST_ASSERT_EQUAL(test_entry->attr, written_entry->attr);
    TEST_ASSERT_EQUAL(written_entry->start, test_entry->start);
    TEST_ASSERT_EQUAL(written_entry->end, test_entry->end);
    TEST_ASSERT_EQUAL_MEMORY(test_entry->name, written_entry->name, sizeof(test_entry->name));
}

void test_gpt_entry_change_type_should_failWhenEntryNotExisting(void)
{
    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_init(&mock_driver, TEST_MAX_PARTITIONS));

    struct efi_guid_t non_existing = NULL_GUID;
    struct efi_guid_t new_type = TEST_GPT_VALID_TYPE(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11);

    TEST_ASSERT_EQUAL(PSA_ERROR_DOES_NOT_EXIST, gpt_entry_change_type(&non_existing, &new_type));

    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_uninit());
}

void test_gpt_entry_change_type_should_failWhenSettingTypeToNullGuid(void)
{
    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_init(&mock_driver, TEST_MAX_PARTITIONS));

    struct efi_guid_t test_guid = test_partition_array[0].unique_guid;
    struct efi_guid_t new_type = NULL_GUID;

    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_ARGUMENT, gpt_entry_change_type(&test_guid, &new_type));

    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_uninit());
}

void test_gpt_entry_rename_should_renameEntry(void)
{
    const uint32_t test_entry_index = 0;
    struct gpt_entry_t *test_entry = &(test_partition_array[test_entry_index]);
    struct efi_guid_t test_guid = test_entry->unique_guid;
    char test_name[GPT_ENTRY_NAME_LENGTH];

    memcpy(test_name, test_entry->name, GPT_ENTRY_NAME_LENGTH);
    test_name[0] = 'a';

    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_init(&mock_driver, TEST_MAX_PARTITIONS));

    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_entry_rename(&test_guid, test_name));

    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_uninit());

    /* Check primary array is updated. Everything other than type should remain */
    struct gpt_entry_t *written_entry = read_entry(test_entry_index, true);

    TEST_ASSERT_EQUAL_MEMORY((&test_entry->unique_guid),
            &(written_entry->unique_guid),
            sizeof(test_entry->unique_guid));
    TEST_ASSERT_EQUAL_MEMORY(&test_entry->partition_type,
            &(written_entry->partition_type),
            sizeof(test_entry->partition_type));
    TEST_ASSERT_EQUAL(test_entry->attr, written_entry->attr);
    TEST_ASSERT_EQUAL(written_entry->start, test_entry->start);
    TEST_ASSERT_EQUAL(written_entry->end, test_entry->end);
    TEST_ASSERT_EQUAL_MEMORY(test_name, written_entry->name, sizeof(test_name));

    /* Check backup array is updated */
    written_entry = read_entry(test_entry_index, false);

    TEST_ASSERT_EQUAL_MEMORY((&test_entry->unique_guid),
            &(written_entry->unique_guid),
            sizeof(test_entry->unique_guid));
    TEST_ASSERT_EQUAL_MEMORY(&test_entry->partition_type,
            &(written_entry->partition_type),
            sizeof(test_entry->partition_type));
    TEST_ASSERT_EQUAL(test_entry->attr, written_entry->attr);
    TEST_ASSERT_EQUAL(written_entry->start, test_entry->start);
    TEST_ASSERT_EQUAL(written_entry->end, test_entry->end);
    TEST_ASSERT_EQUAL_MEMORY(test_name, written_entry->name, sizeof(test_name));
}

void test_gpt_entry_rename_should_failWhenNameIsEmpty(void)
{
    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_init(&mock_driver, TEST_MAX_PARTITIONS));

    /* Try to change name to an empty string */
    struct efi_guid_t test_guid = test_partition_array[0].unique_guid;
    char name[GPT_ENTRY_NAME_LENGTH] = {'\0'};
    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_ARGUMENT, gpt_entry_rename(&test_guid, name));

    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_uninit());
}

void test_gpt_entry_rename_should_failWhenEntryNotExisting(void)
{
    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_init(&mock_driver, TEST_MAX_PARTITIONS));

    struct efi_guid_t non_existing = NULL_GUID;
    char new_name[GPT_ENTRY_NAME_LENGTH] = {'\0'};
    new_name[0] = 'a';

    TEST_ASSERT_EQUAL(PSA_ERROR_DOES_NOT_EXIST, gpt_entry_rename(&non_existing, new_name));

    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_uninit());
}
void test_gpt_entry_remove_should_removeEntry(void)
{
    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_init(&mock_driver, TEST_MAX_PARTITIONS));

    const uint64_t removed_entry_index = TEST_DEFAULT_NUM_PARTITIONS - 1;
    struct gpt_entry_t *test_entry = &(test_partition_array[removed_entry_index]);
    struct efi_guid_t test_guid = test_entry->unique_guid;

    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_entry_remove(&test_guid));

    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_uninit());

    /* Ensure that the removed entry has been zero'd */
    struct gpt_entry_t *removed_entry = read_entry(removed_entry_index, true);
    const struct gpt_entry_t zero_entry = {0};

    TEST_ASSERT_EQUAL_MEMORY(&zero_entry, removed_entry, sizeof(struct gpt_entry_t));
}

void test_gpt_entry_remove_should_failWhenEntryNotExisting(void)
{
    /* Start by trying to remove from an empty table */
    memset(test_partition_array, 0, sizeof(test_partition_array));
    setup_test_gpt_layout();
    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_init(&mock_driver, TEST_MAX_PARTITIONS));

    struct efi_guid_t non_existing = NULL_GUID;

    TEST_ASSERT_EQUAL(PSA_ERROR_DOES_NOT_EXIST, gpt_entry_remove(&non_existing));

    /* Now, have a non-empty GPT but search for a non-existing GUID */
    memcpy(&test_partition_array, &default_partition_array, sizeof(default_partition_array));
    setup_test_gpt_layout();

    /* Each used entry should be read. */
    TEST_ASSERT_EQUAL(PSA_ERROR_DOES_NOT_EXIST, gpt_entry_remove(&non_existing));

    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_uninit());
}

void test_gpt_entry_read_should_populateEntry(void)
{
    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_init(&mock_driver, TEST_MAX_PARTITIONS));

    /* Ensure an entry is found */
    struct partition_entry_t entry;
    struct gpt_entry_t *desired = &(test_partition_array[TEST_DEFAULT_NUM_PARTITIONS - 1]);
    struct efi_guid_t test_guid = desired->unique_guid;
    struct efi_guid_t test_type = desired->partition_type;
    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_entry_read(&test_guid, &entry));

    /* Ensure this is the correct entry */
    TEST_ASSERT_EQUAL(0, efi_guid_cmp(&test_guid, &(entry.partition_guid)));
    TEST_ASSERT_EQUAL(0, efi_guid_cmp(&test_type, &(entry.type_guid)));
    TEST_ASSERT_EQUAL(desired->start, entry.start);

    /* Size is number of blocks, so subtract one */
    TEST_ASSERT_EQUAL(desired->end, entry.start + entry.size - 1);

    /* Name is unicode */
    TEST_ASSERT_EQUAL_MEMORY(desired->name, entry.name, GPT_ENTRY_NAME_LENGTH);

    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_uninit());
}

void test_gpt_entry_read_should_failWhenEntryNotExisting(void)
{
    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_init(&mock_driver, TEST_MAX_PARTITIONS));

    /* Start by trying to read from an empty table */
    memset(test_partition_array, 0, sizeof(test_partition_array));
    setup_test_gpt_layout();

    struct partition_entry_t entry;
    struct efi_guid_t non_existing = NULL_GUID;
    TEST_ASSERT_EQUAL(PSA_ERROR_DOES_NOT_EXIST, gpt_entry_read(&non_existing, &entry));

    /* Now, have a non-empty GPT but search for a non-existing GUID */
    memcpy(&test_partition_array, &default_partition_array, sizeof(default_partition_array));
    setup_test_gpt_layout();

    /* Try to read something */
    TEST_ASSERT_EQUAL(PSA_ERROR_DOES_NOT_EXIST, gpt_entry_read(&non_existing, &entry));

    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_uninit());
}

void test_gpt_entry_read_by_name_should_populateEntry(void)
{
    /* Ensure an entry is found, even with repeat names */
    struct partition_entry_t entry;
    struct gpt_entry_t *desired1 = &(test_partition_array[0]);
    struct efi_guid_t test_guid1 = desired1->unique_guid;
    struct efi_guid_t test_type1 = desired1->partition_type;

    /* Change the name of something else and ensure it is found */
    struct gpt_entry_t *desired2 = &(test_partition_array[1]);
    struct efi_guid_t test_guid2 = desired2->unique_guid;
    struct efi_guid_t test_type2 = desired2->partition_type;
    memcpy(desired2->name, desired1->name, GPT_ENTRY_NAME_LENGTH);

    setup_test_gpt_layout();

    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_init(&mock_driver, TEST_MAX_PARTITIONS));

    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_entry_read_by_name(desired1->name, 0, &entry));

    /* Ensure this is the correct entry */
    TEST_ASSERT_EQUAL(0, efi_guid_cmp(&test_guid1, &(entry.partition_guid)));
    TEST_ASSERT_EQUAL(0, efi_guid_cmp(&test_type1, &(entry.type_guid)));
    TEST_ASSERT_EQUAL(desired1->start, entry.start);
    TEST_ASSERT_EQUAL(desired1->end, entry.start + entry.size - 1);

    TEST_ASSERT_EQUAL_MEMORY(desired1->name, entry.name, GPT_ENTRY_NAME_LENGTH);

    /* Do again but the next entry */
    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_entry_read_by_name(desired1->name, 1, &entry));

    /* Ensure this is the correct entry */
    TEST_ASSERT_EQUAL(0, efi_guid_cmp(&test_guid2, &(entry.partition_guid)));
    TEST_ASSERT_EQUAL(0, efi_guid_cmp(&test_type2, &(entry.type_guid)));
    TEST_ASSERT_EQUAL(desired2->start, entry.start);
    TEST_ASSERT_EQUAL(desired2->end, entry.start + entry.size - 1);

    TEST_ASSERT_EQUAL_MEMORY(desired2->name, entry.name, GPT_ENTRY_NAME_LENGTH);

    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_uninit());
}

void test_gpt_entry_read_by_name_should_failWhenEntryNotExisting(void)
{
    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_init(&mock_driver, TEST_MAX_PARTITIONS));

    /* Start by trying to read from an empty table */
    memset(test_partition_array, 0, sizeof(test_partition_array));
    setup_test_gpt_layout();

    /* Try to read something */
    struct partition_entry_t entry;
    char test_name[GPT_ENTRY_NAME_LENGTH] = {'\0'};
    TEST_ASSERT_EQUAL(PSA_ERROR_DOES_NOT_EXIST, gpt_entry_read_by_name(test_name, 0, &entry));

    /* Now, have a non-empty GPT but search for a name that won't exist */
    setup_test_gpt_layout();
    memcpy(&test_partition_array, &default_partition_array, sizeof(default_partition_array));

    TEST_ASSERT_EQUAL(PSA_ERROR_DOES_NOT_EXIST, gpt_entry_read_by_name(test_name, 0, &entry));

    /* Finally, search for the second entry of a name that appears only once */
    memcpy(test_name, test_partition_array[0].name, GPT_ENTRY_NAME_LENGTH);
    TEST_ASSERT_EQUAL(PSA_ERROR_DOES_NOT_EXIST, gpt_entry_read_by_name(test_name, 1, &entry));
    TEST_ASSERT_EQUAL(PSA_ERROR_DOES_NOT_EXIST, gpt_entry_read_by_name(
                test_name,
                TEST_DEFAULT_NUM_PARTITIONS,
                &entry));

    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_uninit());
}

void test_gpt_entry_read_by_type_should_populateEntry(void)
{
    /* Ensure an entry is found, even with repeat types */
    struct partition_entry_t entry;
    struct gpt_entry_t *desired1 = &(test_partition_array[0]);
    struct efi_guid_t test_guid1 = desired1->unique_guid;
    struct efi_guid_t test_type1 = desired1->partition_type;

    struct gpt_entry_t *desired2 = &(test_partition_array[1]);
    struct efi_guid_t test_guid2 = desired2->unique_guid;
    struct efi_guid_t test_type2 = test_type1;

    desired2->partition_type = test_type2;

    setup_test_gpt_layout();

    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_init(&mock_driver, TEST_MAX_PARTITIONS));

    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_entry_read_by_type(&test_type1, 0, &entry));

    /* Ensure this is the correct entry */
    TEST_ASSERT_EQUAL(0, efi_guid_cmp(&test_guid1, &(entry.partition_guid)));
    TEST_ASSERT_EQUAL(0, efi_guid_cmp(&test_type1, &(entry.type_guid)));
    TEST_ASSERT_EQUAL(desired1->start, entry.start);
    TEST_ASSERT_EQUAL(desired1->end, entry.start + entry.size - 1);

    /* Name is unicode */
    TEST_ASSERT_EQUAL_MEMORY(desired1->name, entry.name, GPT_ENTRY_NAME_LENGTH);

    /* Do again but the next entry */
    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_entry_read_by_type(&test_type1, 1, &entry));

    /* Ensure this is the correct entry */
    TEST_ASSERT_EQUAL(0, efi_guid_cmp(&test_guid2, &(entry.partition_guid)));
    TEST_ASSERT_EQUAL(0, efi_guid_cmp(&test_type2, &(entry.type_guid)));
    TEST_ASSERT_EQUAL(desired2->start, entry.start);
    TEST_ASSERT_EQUAL(desired2->end, entry.start + entry.size - 1);

    TEST_ASSERT_EQUAL_MEMORY(desired2->name, entry.name, GPT_ENTRY_NAME_LENGTH);

    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_uninit());
}

void test_gpt_entry_read_by_type_should_failWhenEntryNotExisting(void)
{
    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_init(&mock_driver, TEST_MAX_PARTITIONS));

    /* Start by trying to read from an empty table */
    memset(test_partition_array, 0, sizeof(test_partition_array));
    setup_test_gpt_layout();

    /* Try to read something */
    struct partition_entry_t entry;
    struct efi_guid_t test_type = TEST_GPT_VALID_TYPE(11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1);
    TEST_ASSERT_EQUAL(PSA_ERROR_DOES_NOT_EXIST, gpt_entry_read_by_type(&test_type, 0, &entry));

    /* Now, have a non-empty GPT but search for a type that won't exist */
    setup_test_gpt_layout();
    memcpy(&test_partition_array, &default_partition_array, sizeof(default_partition_array));

    TEST_ASSERT_EQUAL(PSA_ERROR_DOES_NOT_EXIST, gpt_entry_read_by_type(&test_type, 0, &entry));

    /* Finally, search for the second entry of a type that appears only once */
    test_type = test_partition_array[0].partition_type;
    TEST_ASSERT_EQUAL(PSA_ERROR_DOES_NOT_EXIST, gpt_entry_read_by_type(&test_type, 1, &entry));
    TEST_ASSERT_EQUAL(PSA_ERROR_DOES_NOT_EXIST, gpt_entry_read_by_type(
                &test_type,
                TEST_DEFAULT_NUM_PARTITIONS,
                &entry));

    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_uninit());
}
