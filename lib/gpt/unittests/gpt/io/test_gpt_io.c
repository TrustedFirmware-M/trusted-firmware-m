/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <string.h>
#include <inttypes.h>

#include "unity.h"

#include "mock_gpt_io_read.h"
#include "mock_gpt_io_write.h"
#include "mock_efi_guid.h"
#include "mock_efi_soft_crc.h"

#include "efi_guid_structs.h"
#include "gpt_flash.h"
#include "gpt.h"
#include "psa/error.h"

/* Basic mocked disk layout and number of partitions */
#define TEST_BLOCK_SIZE 512
#define TEST_DISK_NUM_BLOCKS 128
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
#define TEST_GPT_BACKUP_LBA (TEST_DISK_NUM_BLOCKS - 1)
#define TEST_GPT_ARRAY_LBA (TEST_GPT_PRIMARY_LBA + 1)
#define TEST_GPT_BACKUP_ARRAY_LBA (TEST_GPT_BACKUP_LBA - 1)
#define TEST_GPT_FIRST_USABLE_LBA (TEST_GPT_ARRAY_LBA + 2)
#define TEST_GPT_LAST_USABLE_LBA (TEST_GPT_BACKUP_LBA - 2)
#define TEST_GPT_DISK_GUID MAKE_EFI_GUID(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11)
#define TEST_GPT_ENTRY_SIZE 128

/* Test data. These are defined to be not fragmented */
#define TEST_GPT_FIRST_PARTITION_START TEST_GPT_FIRST_USABLE_LBA
#define TEST_GPT_FIRST_PARTITION_END (TEST_GPT_FIRST_PARTITION_START + 3)
#define TEST_GPT_SECOND_PARTITION_START (TEST_GPT_FIRST_PARTITION_END + 1)
#define TEST_GPT_SECOND_PARTITION_END (TEST_GPT_SECOND_PARTITION_START + 50)
#define TEST_GPT_THIRD_PARTITION_START (TEST_GPT_SECOND_PARTITION_END + 1)
#define TEST_GPT_THIRD_PARTITION_END (TEST_GPT_THIRD_PARTITION_START + 1)
#define TEST_GPT_DISK_FREE_SPACE_START (TEST_GPT_THIRD_PARTITION_END + 1)

/* Populates a backup header from a primary header and calculates the new CRC32 */
#define MAKE_BACKUP_HEADER(backup, primary)              \
    do {                                                 \
        memcpy(&backup, &primary, TEST_GPT_HEADER_SIZE); \
        backup.header_crc = TEST_GPT_CRC32;              \
        backup.current_lba = primary.backup_lba;         \
        backup.backup_lba = primary.current_lba;         \
        backup.array_lba = TEST_GPT_BACKUP_ARRAY_LBA;    \
    } while (0)

/* These macros make it clearer in the tests what is happening */
#define TEST_GPT_VALID_GUID(...) MAKE_EFI_GUID(__VA_ARGS__)
#define TEST_GPT_DUMMY_GUID NULL_GUID

#define TEST_GPT_VALID_TYPE(...) MAKE_EFI_GUID(__VA_ARGS__)
#define TEST_GPT_DUMMY_TYPE NULL_GUID

/* Mark a parameter as unused */
#define UNUSED(x) (void)x

/* Valid MBR. Only signature is required to be valid */
static struct mbr_t default_mbr = {
    .partitions = {0},
    .sig = TEST_MBR_SIG,
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
    .flash_guid = TEST_GPT_DISK_GUID,
    .array_lba = TEST_GPT_ARRAY_LBA,
    .num_partitions = TEST_MAX_PARTITIONS,
    .entry_size = TEST_GPT_ENTRY_SIZE,
    .array_crc = TEST_GPT_CRC32
};

static struct gpt_t test_primary_gpt = {0};
static struct gpt_t test_backup_gpt = {0};

static struct gpt_t *test_primary_gpt_ptr;
static struct gpt_t *test_backup_gpt_ptr;

/* Whether gpt_init succeeds as part of the test. Used by the tearDown */
static bool test_gpt_init_success = false;

/* Functions for mocked driver, which need to be defined */
static ssize_t test_driver_read(uint64_t lba, void *buf)
{
    return TEST_BLOCK_SIZE;
}

static ssize_t test_driver_write(uint64_t lba, const void *buf)
{
    return TEST_BLOCK_SIZE;
}

static ssize_t test_driver_erase(uint64_t lba, size_t num_blocks)
{
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
        .attr = 0,
        .name = "First partition"
    },
    {
        .partition_type = TEST_GPT_VALID_TYPE(2, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11),
        .unique_guid = TEST_GPT_VALID_GUID(2, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11),
        .start = TEST_GPT_SECOND_PARTITION_START,
        .end = TEST_GPT_SECOND_PARTITION_END,
        .attr = 0,
        .name = "Second partition"
    },
    {
        .partition_type = TEST_GPT_VALID_TYPE(3, 3, 3, 4, 5, 6, 7, 8, 9, 10, 11),
        .unique_guid = TEST_GPT_VALID_GUID(3, 3, 3, 4, 5, 6, 7, 8, 9, 10, 11),
        .start = TEST_GPT_THIRD_PARTITION_START,
        .end = TEST_GPT_THIRD_PARTITION_END,
        .attr = 0,
        .name = "Third partition"
    }
};
static struct gpt_entry_t test_partition_array[TEST_MAX_PARTITIONS];

/* Turn ascii string to unicode */
static void ascii_to_unicode(const char *ascii, char *unicode)
{
    for (int i = 0; i < strlen(ascii) + 1; ++i) {
        unicode[i << 1] = ascii[i];
        unicode[(i << 1) + 1] = '\0';
    }
}

/* Expect a read of the MBR */
static void expect_mbr_load(psa_status_t ret)
{
    mbr_load_ExpectAndReturn(NULL, ret);
    mbr_load_IgnoreArg_mbr();
    if (ret == PSA_SUCCESS) {
        mbr_load_ReturnThruPtr_mbr(&test_mbr);
    }
}

/* Expect a read of the primary table */
static void expect_read_primary_gpt(psa_status_t ret)
{
    test_primary_gpt_ptr = &test_primary_gpt;
    read_table_ExpectAnyArgsAndReturn(ret);
    read_table_ReturnThruPtr_table(&test_primary_gpt_ptr);
}

/* Expect a read of the backup table */
static void expect_read_backup_gpt(psa_status_t ret)
{
    test_backup_gpt_ptr = &test_backup_gpt;
    read_table_ExpectAnyArgsAndReturn(ret);
    read_table_ReturnThruPtr_table(&test_backup_gpt_ptr);
}

/* Expect a read of a particular entry */
static void expect_read_entry(psa_status_t ret, struct gpt_entry_t *test_entry)
{
    read_entry_from_flash_ExpectAnyArgsAndReturn(ret);
    read_entry_from_flash_ReturnThruPtr_entry(test_entry);
}

/* Expect a read for every entry, used or unused */
static void expect_read_all_entries(psa_status_t ret)
{
    for (size_t i = 0; i < test_primary_gpt.header.num_partitions; ++i) {
        expect_read_entry(ret, &(test_partition_array[i]));
    }
}

/* Expect a read for every used entry */
static void expect_read_used_entries(psa_status_t ret)
{
    for (size_t i = 0; i < test_primary_gpt.num_used_partitions; ++i) {
        expect_read_entry(ret, &(test_partition_array[i]));
    }
}

/* Stub to always return the same entry */
static psa_status_t read_same_entry_from_flash(const struct gpt_t *table,
                                               uint32_t            array_index,
                                               struct gpt_entry_t *entry,
                                               int                 cmock_num_calls)
{
    UNUSED(table);
    UNUSED(array_index);
    UNUSED(cmock_num_calls);

    /* It doesn't matter what entry to return */
    memcpy(entry, &(test_partition_array[0]), sizeof(struct gpt_entry_t));

    return PSA_SUCCESS;
}

/* Always read the same entry */
static void expect_same_read_entry_from_flash(void)
{
    read_entry_from_flash_Stub(read_same_entry_from_flash);
}

/* Creates backup table from test table and registers a read for it */
static void setup_backup_gpt(void)
{
    MAKE_BACKUP_HEADER((test_backup_gpt.header), (test_primary_gpt.header));
    test_backup_gpt.num_used_partitions = test_primary_gpt.num_used_partitions;

    expect_read_backup_gpt(PSA_SUCCESS);
}

/* Uses the test MBR and GPT header to initialise for tests */
static psa_status_t setup_test_gpt(void)
{
    /* Expect first a valid MBR read */
    expect_mbr_load(PSA_SUCCESS);

    /* Expect a GPT header read second */
    expect_read_primary_gpt(PSA_SUCCESS);

    /* Expect third the backup to be read */
    setup_backup_gpt();

    /* Expect fourth the primary to be read again */
    expect_read_primary_gpt(PSA_SUCCESS);

    /* Expect finally each entry to be read */
    expect_read_all_entries(PSA_SUCCESS);

    psa_status_t ret = gpt_init(&mock_driver, TEST_MAX_PARTITIONS);

    test_gpt_init_success = (ret == PSA_SUCCESS);

    return ret;
}

/* Ensures a valid GPT populated with the default entries is initialised */
static void setup_valid_gpt(void)
{
    TEST_ASSERT_EQUAL(PSA_SUCCESS, setup_test_gpt());
}

void setUp(void)
{
    /* Default starting points */
    test_gpt_init_success = false;
    test_mbr = default_mbr;
    test_primary_gpt.header = default_header;
    test_primary_gpt.num_used_partitions = TEST_DEFAULT_NUM_PARTITIONS;
    memset(&test_backup_gpt, 0, sizeof(test_backup_gpt));
    memset(&test_partition_array, 0, sizeof(test_partition_array));
    memcpy(&test_partition_array, &default_partition_array, sizeof(default_partition_array));
    for (size_t i = 0; i < TEST_DEFAULT_NUM_PARTITIONS; ++i) {
        char unicode_name[GPT_ENTRY_NAME_LENGTH] = {'\0'};

        ascii_to_unicode(test_partition_array[i].name, unicode_name);
        memcpy(test_partition_array[i].name, unicode_name, GPT_ENTRY_NAME_LENGTH);
    }

    test_primary_gpt_ptr = &test_primary_gpt;
    test_backup_gpt_ptr = &test_backup_gpt;

    test_mbr.partitions[0].os_type = TEST_MBR_TYPE_GPT;

    /* Any time this is called, return the same number and ignore the arguments */
    efi_soft_crc32_update_IgnoreAndReturn(test_primary_gpt.header.header_crc);

    /* Ignore all cache control calls */
    invalidate_cached_gpt_Ignore();
    set_write_buffered_Ignore();
    is_write_buffered_IgnoreAndReturn(true);
    flush_lba_buf_IgnoreAndReturn(PSA_SUCCESS);

    /* Ignore all write calls */
    write_to_flash_IgnoreAndReturn(PSA_SUCCESS);
    write_header_to_flash_IgnoreAndReturn(PSA_SUCCESS);
    write_entry_IgnoreAndReturn(PSA_SUCCESS);
    write_entries_to_flash_IgnoreAndReturn(PSA_SUCCESS);
    update_header_IgnoreAndReturn(PSA_SUCCESS);
}

void tearDown(void)
{
    memset(&test_partition_array, 0, sizeof(test_partition_array));

    if (test_gpt_init_success) {
        /* Because is_write_buffered will always return true, expect that
         * the primary_gpt will be read
         */
        expect_read_primary_gpt(PSA_SUCCESS);
    }

    gpt_uninit();
}

void test_gpt_init_should_failWhenUnableToReadMbr(void)
{
    expect_mbr_load(PSA_ERROR_STORAGE_FAILURE);

    TEST_ASSERT_EQUAL(PSA_ERROR_STORAGE_FAILURE, gpt_init(&mock_driver, TEST_MAX_PARTITIONS));
}

void test_gpt_init_should_failWhenUnableToReadGpt(void)
{
    expect_mbr_load(PSA_SUCCESS);

    expect_read_primary_gpt(PSA_ERROR_STORAGE_FAILURE);

    TEST_ASSERT_EQUAL(PSA_ERROR_STORAGE_FAILURE, gpt_init(&mock_driver, TEST_MAX_PARTITIONS));

    /* Now do the backup */
    expect_mbr_load(PSA_SUCCESS);
    expect_read_primary_gpt(PSA_SUCCESS);

    expect_read_backup_gpt(PSA_ERROR_STORAGE_FAILURE);

    TEST_ASSERT_EQUAL(PSA_ERROR_STORAGE_FAILURE, gpt_init(&mock_driver, TEST_MAX_PARTITIONS));
}

void test_gpt_init_should_failWhenUnableToReadEntry(void)
{
    expect_mbr_load(PSA_SUCCESS);
    expect_read_primary_gpt(PSA_ERROR_STORAGE_FAILURE);

    TEST_ASSERT_EQUAL(PSA_ERROR_STORAGE_FAILURE, gpt_init(&mock_driver, TEST_MAX_PARTITIONS));
}

void test_gpt_validate_should_failWhenUnableToReadGpt(void)
{
    /* Start with a valid GPT */
    setup_test_gpt();

    /* Assume the read for the flush succeeds */
    expect_read_primary_gpt(PSA_SUCCESS);
    expect_read_primary_gpt(PSA_ERROR_STORAGE_FAILURE);
    TEST_ASSERT_EQUAL(PSA_ERROR_STORAGE_FAILURE, gpt_validate(true));

    /* Now do the backup */
    expect_read_primary_gpt(PSA_SUCCESS);
    expect_read_backup_gpt(PSA_ERROR_STORAGE_FAILURE);
    TEST_ASSERT_EQUAL(PSA_ERROR_STORAGE_FAILURE, gpt_validate(true));
}

void test_gpt_validate_should_failWhenUnableToReadEntry(void)
{
    /* Start with a valid GPT */
    setup_test_gpt();

    /* Test primary GPT first. Fail on first entry read */
    expect_read_primary_gpt(PSA_SUCCESS);
    expect_read_primary_gpt(PSA_SUCCESS);

    expect_read_entry(PSA_ERROR_STORAGE_FAILURE, &(test_partition_array[0]));

    TEST_ASSERT_EQUAL(PSA_ERROR_STORAGE_FAILURE, gpt_validate(true));

    /* Now do the backup table */
    expect_read_primary_gpt(PSA_SUCCESS);
    expect_read_backup_gpt(PSA_SUCCESS);

    expect_read_entry(PSA_ERROR_STORAGE_FAILURE, &(test_partition_array[0]));

    TEST_ASSERT_EQUAL(PSA_ERROR_STORAGE_FAILURE, gpt_validate(false));
}

void test_gpt_restore_should_failWhenUnableToReadRestoringGpt(void)
{
    setup_valid_gpt();

    /* Attempt to restore primary from backup */
    expect_read_primary_gpt(PSA_SUCCESS);
    expect_read_backup_gpt(PSA_ERROR_STORAGE_FAILURE);
    TEST_ASSERT_EQUAL(PSA_ERROR_STORAGE_FAILURE, gpt_restore(true));

    /* Not attempt to restore backup from primary */
    expect_read_primary_gpt(PSA_SUCCESS);
    expect_read_primary_gpt(PSA_ERROR_STORAGE_FAILURE);
    TEST_ASSERT_EQUAL(PSA_ERROR_STORAGE_FAILURE, gpt_restore(true));
}

void test_gpt_restore_should_failWhenUnableToReadEntry(void)
{
    /* Start with a valid GPT */
    setup_valid_gpt();

    /* Test restoring primary GPT first. Fail on first entry read */
    expect_read_primary_gpt(PSA_SUCCESS);
    expect_read_backup_gpt(PSA_SUCCESS);
    expect_read_entry(PSA_ERROR_STORAGE_FAILURE, &(test_partition_array[0]));
    TEST_ASSERT_EQUAL(PSA_ERROR_STORAGE_FAILURE, gpt_restore(true));

    /* Now do the backup table */
    expect_read_primary_gpt(PSA_SUCCESS);
    expect_read_primary_gpt(PSA_SUCCESS);
    expect_read_entry(PSA_ERROR_STORAGE_FAILURE, &(test_partition_array[0]));
    TEST_ASSERT_EQUAL(PSA_ERROR_STORAGE_FAILURE, gpt_restore(false));
}

void test_gpt_defragment_should_failWhenUnableToReadGpt(void)
{
    setup_valid_gpt();

    /* Always return primary GPT when reading a table in this test. If the
     * backup was read, it shouldn't end up mattering anyway since the same
     * partition entry's should be read in the end too
     */
    expect_read_primary_gpt(PSA_ERROR_STORAGE_FAILURE);

    TEST_ASSERT_EQUAL(PSA_ERROR_STORAGE_FAILURE, gpt_defragment());
}

void test_gpt_defragment_should_failWhenUnableToReadEntry(void)
{
    setup_valid_gpt();

    /* Always return primary GPT when reading a table in this test. If the
     * backup was read, it shouldn't end up mattering anyway since the same
     * partition entry's should be read in the end too
     */
    expect_read_primary_gpt(PSA_SUCCESS);
    expect_read_entry(PSA_ERROR_STORAGE_FAILURE, &(test_partition_array[0]));
    TEST_ASSERT_EQUAL(PSA_ERROR_STORAGE_FAILURE, gpt_defragment());
}

void test_gpt_entry_duplicate_should_failWhenUnableToReadTable(void)
{
    setup_valid_gpt();

    struct gpt_entry_t *old_entry = &(test_partition_array[0]);
    struct efi_guid_t old_guid = old_entry->unique_guid;
    struct efi_guid_t new_guid;

    expect_read_primary_gpt(PSA_ERROR_STORAGE_FAILURE);

    TEST_ASSERT_EQUAL(PSA_ERROR_STORAGE_FAILURE, gpt_entry_duplicate(
                &old_guid,
                TEST_GPT_DISK_FREE_SPACE_START,
                &new_guid));
}

void test_gpt_entry_duplicate_should_failWhenUnableToReadEntry(void)
{
    setup_valid_gpt();

    struct gpt_entry_t *old_entry = &(test_partition_array[0]);
    struct efi_guid_t old_guid = old_entry->unique_guid;
    struct efi_guid_t new_guid;

    expect_read_primary_gpt(PSA_SUCCESS);

    read_entry_from_flash_IgnoreAndReturn(PSA_ERROR_STORAGE_FAILURE);

    TEST_ASSERT_EQUAL(PSA_ERROR_STORAGE_FAILURE, gpt_entry_duplicate(
                &old_guid,
                TEST_GPT_DISK_FREE_SPACE_START,
                &new_guid));
}

void test_gpt_entry_duplicate_no_copy_should_failWhenUnableToReadTable(void)
{
    setup_valid_gpt();

    struct gpt_entry_t *old_entry = &(test_partition_array[0]);
    struct efi_guid_t old_guid = old_entry->unique_guid;
    struct efi_guid_t new_guid;

    expect_read_primary_gpt(PSA_ERROR_STORAGE_FAILURE);

    TEST_ASSERT_EQUAL(PSA_ERROR_STORAGE_FAILURE, gpt_entry_duplicate_no_copy(
                &old_guid,
                TEST_GPT_DISK_FREE_SPACE_START,
                &new_guid));
}

void test_gpt_entry_duplicate_no_copy_should_failWhenUnableToReadEntry(void)
{
    setup_valid_gpt();

    struct gpt_entry_t *old_entry = &(test_partition_array[0]);
    struct efi_guid_t old_guid = old_entry->unique_guid;
    struct efi_guid_t new_guid;

    expect_read_primary_gpt(PSA_SUCCESS);

    read_entry_from_flash_IgnoreAndReturn(PSA_ERROR_STORAGE_FAILURE);

    TEST_ASSERT_EQUAL(PSA_ERROR_STORAGE_FAILURE, gpt_entry_duplicate_no_copy(
                &old_guid,
                TEST_GPT_DISK_FREE_SPACE_START,
                &new_guid));
}

void test_gpt_entry_create_should_failWhenUnableToReadGpt(void)
{
    setup_valid_gpt();
    expect_read_primary_gpt(PSA_ERROR_STORAGE_FAILURE);

    struct efi_guid_t type = TEST_GPT_DUMMY_TYPE;
    struct gpt_entry_t new_entry = {
        .partition_type = TEST_GPT_DUMMY_TYPE,
        .start = TEST_GPT_DISK_FREE_SPACE_START,
        .end = TEST_GPT_DISK_FREE_SPACE_START,
        .attr = 0,
        .name = "Fourth partition"
    };

    struct efi_guid_t new_guid = TEST_GPT_DUMMY_GUID;

    TEST_ASSERT_EQUAL(PSA_ERROR_STORAGE_FAILURE, gpt_entry_create(
                &type,
                new_entry.start,
                new_entry.end - new_entry.start + 1,
                new_entry.attr,
                new_entry.name,
                &new_guid));
}

void test_gpt_entry_create_should_failWhenUnableToReadEntry(void)
{
    setup_valid_gpt();
    expect_read_primary_gpt(PSA_SUCCESS);

    read_entry_from_flash_IgnoreAndReturn(PSA_ERROR_STORAGE_FAILURE);

    struct efi_guid_t type = TEST_GPT_DUMMY_TYPE;
    struct gpt_entry_t new_entry = {
        .partition_type = TEST_GPT_DUMMY_TYPE,
        .start = TEST_GPT_DISK_FREE_SPACE_START,
        .end = TEST_GPT_DISK_FREE_SPACE_START,
        .attr = 0,
        .name = "Fourth partition"
    };
    struct efi_guid_t new_guid = TEST_GPT_DUMMY_GUID;

    TEST_ASSERT_EQUAL(PSA_ERROR_STORAGE_FAILURE, gpt_entry_create(
                &type,
                new_entry.start,
                new_entry.end - new_entry.start + 1,
                new_entry.attr,
                new_entry.name,
                &new_guid));
}

void test_gpt_entry_move_should_failWhenUnableToReadGpt(void)
{
    setup_valid_gpt();
    struct gpt_entry_t *test_entry = &(test_partition_array[0]);
    struct efi_guid_t test_guid = test_entry->unique_guid;

    expect_read_primary_gpt(PSA_ERROR_STORAGE_FAILURE);

    TEST_ASSERT_EQUAL(PSA_ERROR_STORAGE_FAILURE, gpt_entry_move(
                &test_guid,
                TEST_GPT_DISK_FREE_SPACE_START,
                TEST_GPT_DISK_FREE_SPACE_START));
}

void test_gpt_entry_move_should_failWhenUnableToReadEntry(void)
{
    setup_valid_gpt();
    struct gpt_entry_t *test_entry = &(test_partition_array[0]);
    struct efi_guid_t test_guid = test_entry->unique_guid;

    expect_read_primary_gpt(PSA_SUCCESS);

    read_entry_from_flash_IgnoreAndReturn(PSA_ERROR_STORAGE_FAILURE);

    TEST_ASSERT_EQUAL(PSA_ERROR_STORAGE_FAILURE, gpt_entry_move(
                &test_guid,
                TEST_GPT_DISK_FREE_SPACE_START,
                TEST_GPT_DISK_FREE_SPACE_START));
}

void test_gpt_entry_move_no_copy_should_failWhenUnableToReadGpt(void)
{
    setup_valid_gpt();
    struct gpt_entry_t *test_entry = &(test_partition_array[0]);
    struct efi_guid_t test_guid = test_entry->unique_guid;

    expect_read_primary_gpt(PSA_ERROR_STORAGE_FAILURE);

    TEST_ASSERT_EQUAL(PSA_ERROR_STORAGE_FAILURE, gpt_entry_move_no_copy(
                &test_guid,
                TEST_GPT_DISK_FREE_SPACE_START,
                TEST_GPT_DISK_FREE_SPACE_START));
}

void test_gpt_entry_move_no_copy_should_failWhenUnableToReadEntry(void)
{
    setup_valid_gpt();
    struct gpt_entry_t *test_entry = &(test_partition_array[0]);
    struct efi_guid_t test_guid = test_entry->unique_guid;

    expect_read_primary_gpt(PSA_SUCCESS);

    read_entry_from_flash_IgnoreAndReturn(PSA_ERROR_STORAGE_FAILURE);

    TEST_ASSERT_EQUAL(PSA_ERROR_STORAGE_FAILURE, gpt_entry_move_no_copy(
                &test_guid,
                TEST_GPT_DISK_FREE_SPACE_START,
                TEST_GPT_DISK_FREE_SPACE_START));
}

void test_gpt_attr_set_should_failWhenUnableToReadGpt(void)
{
    /* Start with a populated GPT */
    setup_valid_gpt();

    expect_read_primary_gpt(PSA_ERROR_STORAGE_FAILURE);

    struct efi_guid_t guid = test_partition_array[0].unique_guid;

    TEST_ASSERT_EQUAL(PSA_ERROR_STORAGE_FAILURE, gpt_attr_set(&guid, 0x1));
}

void test_gpt_attr_set_should_failWhenUnableToReadEntry(void)
{
    /* Start with a populated GPT */
    setup_valid_gpt();

    expect_read_primary_gpt(PSA_SUCCESS);

    read_entry_from_flash_IgnoreAndReturn(PSA_ERROR_STORAGE_FAILURE);

    struct efi_guid_t guid = test_partition_array[0].unique_guid;

    TEST_ASSERT_EQUAL(PSA_ERROR_STORAGE_FAILURE, gpt_attr_set(&guid, 0x1));
}

void test_gpt_attr_remove_should_failWhenUnableToReadGpt(void)
{
    setup_valid_gpt();

    expect_read_primary_gpt(PSA_ERROR_STORAGE_FAILURE);

    struct efi_guid_t guid = test_partition_array[0].unique_guid;

    TEST_ASSERT_EQUAL(PSA_ERROR_STORAGE_FAILURE, gpt_attr_remove(&guid, 0x1));
}

void test_gpt_attr_remove_should_failWhenUnableToReadEntry(void)
{
    setup_valid_gpt();

    expect_read_primary_gpt(PSA_SUCCESS);

    read_entry_from_flash_IgnoreAndReturn(PSA_ERROR_STORAGE_FAILURE);

    struct efi_guid_t guid = test_partition_array[0].unique_guid;

    TEST_ASSERT_EQUAL(PSA_ERROR_STORAGE_FAILURE, gpt_attr_remove(&guid, 0x1));
}

void test_gpt_attr_add_should_failWhenUnableToReadGpt(void)
{
    setup_valid_gpt();

    expect_read_primary_gpt(PSA_ERROR_STORAGE_FAILURE);

    struct efi_guid_t guid = test_partition_array[0].unique_guid;

    TEST_ASSERT_EQUAL(PSA_ERROR_STORAGE_FAILURE, gpt_attr_add(&guid, 0x1));
}

void test_gpt_attr_add_should_failWhenUnableToReadEntry(void)
{
    setup_valid_gpt();

    expect_read_primary_gpt(PSA_SUCCESS);

    read_entry_from_flash_IgnoreAndReturn(PSA_ERROR_STORAGE_FAILURE);

    struct efi_guid_t guid = test_partition_array[0].unique_guid;

    TEST_ASSERT_EQUAL(PSA_ERROR_STORAGE_FAILURE, gpt_attr_add(&guid, 0x1));
}

void test_gpt_entry_change_type_should_failWhenUnableToReadGpt(void)
{
    setup_valid_gpt();

    expect_read_primary_gpt(PSA_ERROR_STORAGE_FAILURE);

    struct efi_guid_t guid = test_partition_array[0].unique_guid;
    struct efi_guid_t new_type = TEST_GPT_VALID_TYPE(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11);

    TEST_ASSERT_EQUAL(PSA_ERROR_STORAGE_FAILURE, gpt_entry_change_type(&guid, &new_type));
}

void test_gpt_entry_change_type_should_failWhenUnableToReadEntry(void)
{
    setup_valid_gpt();

    expect_read_primary_gpt(PSA_SUCCESS);

    read_entry_from_flash_IgnoreAndReturn(PSA_ERROR_STORAGE_FAILURE);

    struct efi_guid_t guid = test_partition_array[0].unique_guid;
    struct efi_guid_t new_type = TEST_GPT_VALID_TYPE(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11);

    TEST_ASSERT_EQUAL(PSA_ERROR_STORAGE_FAILURE, gpt_entry_change_type(&guid, &new_type));
}

void test_gpt_entry_rename_should_failWhenUnableToReadGpt(void)
{
    setup_valid_gpt();

    expect_read_primary_gpt(PSA_ERROR_STORAGE_FAILURE);

    struct efi_guid_t guid = test_partition_array[0].unique_guid;
    char new_name[GPT_ENTRY_NAME_LENGTH] = {'\0'};

    new_name[0] = 'a';
    TEST_ASSERT_EQUAL(PSA_ERROR_STORAGE_FAILURE, gpt_entry_rename(&guid, new_name));
}

void test_gpt_entry_rename_should_failWhenUnableToReadEntry(void)
{
    setup_valid_gpt();

    expect_read_primary_gpt(PSA_SUCCESS);

    read_entry_from_flash_IgnoreAndReturn(PSA_ERROR_STORAGE_FAILURE);

    struct efi_guid_t guid = test_partition_array[0].unique_guid;
    char new_name[GPT_ENTRY_NAME_LENGTH] = {'\0'};

    new_name[0] = 'a';
    TEST_ASSERT_EQUAL(PSA_ERROR_STORAGE_FAILURE, gpt_entry_rename(&guid, new_name));
}

void test_gpt_entry_read_should_failWhenUnableToReadGpt(void)
{
    setup_valid_gpt();

    expect_read_primary_gpt(PSA_ERROR_STORAGE_FAILURE);

    struct partition_entry_t entry;
    struct efi_guid_t guid = test_partition_array[0].unique_guid;

    TEST_ASSERT_EQUAL(PSA_ERROR_STORAGE_FAILURE, gpt_entry_read(&guid, &entry));
}

void test_gpt_entry_read_should_failWhenUnableToReadEntry(void)
{
    setup_valid_gpt();

    expect_read_primary_gpt(PSA_SUCCESS);

    read_entry_from_flash_IgnoreAndReturn(PSA_ERROR_STORAGE_FAILURE);

    struct partition_entry_t entry;
    struct efi_guid_t guid = test_partition_array[0].unique_guid;

    TEST_ASSERT_EQUAL(PSA_ERROR_STORAGE_FAILURE, gpt_entry_read(&guid, &entry));
}

void test_gpt_entry_read_by_name_should_failWhenUnableToReadGpt(void)
{
    setup_valid_gpt();

    expect_read_primary_gpt(PSA_ERROR_STORAGE_FAILURE);

    struct partition_entry_t entry;
    char test_name[GPT_ENTRY_NAME_LENGTH] = {'\0'};

    memcpy(test_name, test_partition_array[0].name, GPT_ENTRY_NAME_LENGTH);
    TEST_ASSERT_EQUAL(PSA_ERROR_STORAGE_FAILURE, gpt_entry_read_by_name(test_name, 0, &entry));
}

void test_gpt_entry_read_by_name_should_failWhenUnableToReadEntry(void)
{
    setup_valid_gpt();

    expect_read_primary_gpt(PSA_SUCCESS);

    read_entry_from_flash_IgnoreAndReturn(PSA_ERROR_STORAGE_FAILURE);

    struct partition_entry_t entry;
    char test_name[GPT_ENTRY_NAME_LENGTH] = {'\0'};

    memcpy(test_name, test_partition_array[0].name, GPT_ENTRY_NAME_LENGTH);
    TEST_ASSERT_EQUAL(PSA_ERROR_STORAGE_FAILURE, gpt_entry_read_by_name(test_name, 0, &entry));
}

void test_gpt_entry_read_by_type_should_failWhenUnableToReadGpt(void)
{
    setup_valid_gpt();

    expect_read_primary_gpt(PSA_ERROR_STORAGE_FAILURE);

    struct partition_entry_t entry;
    struct efi_guid_t test_type = test_partition_array[0].partition_type;

    TEST_ASSERT_EQUAL(PSA_ERROR_STORAGE_FAILURE, gpt_entry_read_by_type(&test_type, 0, &entry));
}

void test_gpt_entry_read_by_type_should_failWhenUnableToReadEntry(void)
{
    setup_valid_gpt();

    expect_read_primary_gpt(PSA_SUCCESS);

    read_entry_from_flash_IgnoreAndReturn(PSA_ERROR_STORAGE_FAILURE);

    struct partition_entry_t entry;
    struct efi_guid_t test_type = test_partition_array[0].partition_type;

    TEST_ASSERT_EQUAL(PSA_ERROR_STORAGE_FAILURE, gpt_entry_read_by_type(&test_type, 0, &entry));
}
