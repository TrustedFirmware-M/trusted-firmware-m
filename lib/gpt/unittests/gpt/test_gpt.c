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

static struct gpt_t test_primary_gpt = {
    .num_used_partitions = TEST_DEFAULT_NUM_PARTITIONS,
};
static struct gpt_t test_backup_gpt = {0};

static struct gpt_t *test_primary_gpt_ptr;
static struct gpt_t *test_backup_gpt_ptr;

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
    read_table_from_flash_ExpectAnyArgsAndReturn(ret);
    read_table_from_flash_ReturnThruPtr_table(&test_primary_gpt_ptr);
}

/* Expect a read of the backup table */
static void expect_read_backup_gpt(psa_status_t ret)
{
    test_backup_gpt_ptr = &test_backup_gpt;
    read_table_from_flash_ExpectAnyArgsAndReturn(ret);
    read_table_from_flash_ReturnThruPtr_table(&test_backup_gpt_ptr);
}

/* Stub to always return primary table */
static psa_status_t read_primary_gpt_from_flash(struct gpt_t **table,
                                                bool is_primary,
                                                int cmock_num_calls)
{
    UNUSED(is_primary);
    UNUSED(cmock_num_calls);

    test_primary_gpt_ptr = &test_primary_gpt;
    *table = test_primary_gpt_ptr;

    return PSA_SUCCESS;
}

/* Read only the primary table, never the backup */
static void expect_read_primary_gpt_only(void)
{
    read_table_from_flash_Stub(read_primary_gpt_from_flash);
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

    expect_read_backup_gpt(PSA_SUCCESS);
}

/* Uses the test MBR and GPT header to initialise for tests */
static psa_status_t setup_test_gpt(void)
{
    /* Expect first a valid MBR read */
    expect_mbr_load(PSA_SUCCESS);

    /* Expect a GPT header read second */
    expect_read_primary_gpt(PSA_SUCCESS);

    /* Expect third each partition is read to find the number in use (if the
     * number in the header is non-zero). Stops reading once a 0 entry is found
     */
    expect_read_all_entries(PSA_SUCCESS);

    /* Expect fourth the backup to be read */
    setup_backup_gpt();

    return gpt_init(&mock_driver, TEST_MAX_PARTITIONS);
}

/* Ensures a valid GPT populated with the default entries is initialised */
static void setup_valid_gpt(void)
{
    TEST_ASSERT_EQUAL(PSA_SUCCESS, setup_test_gpt());
}

/* Ensures a valid but empty GPT is initialised */
static void setup_empty_gpt(void)
{
    test_primary_gpt.header.num_partitions = 0;
    TEST_ASSERT_EQUAL(PSA_SUCCESS, setup_test_gpt());
}

/* Helper for test_gpt_validate_should_failWhenBackupLbaNotAtEndOfDisk */
static void validate_backup_lba_not_at_end_of_disk(uint64_t invalid_lba, bool is_primary)
{
    if (is_primary) {
        test_primary_gpt.header.backup_lba = invalid_lba;
        setup_test_gpt();

        expect_read_primary_gpt(PSA_SUCCESS);
    } else {
        test_primary_gpt.header.backup_lba = invalid_lba;
        setup_test_gpt();
        test_backup_gpt.header.current_lba = invalid_lba;

        expect_read_backup_gpt(PSA_SUCCESS);
    }

    /* Every entry read for CRC calculation */
    expect_read_all_entries(PSA_SUCCESS);

    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_SIGNATURE, gpt_validate(is_primary));
}

/* Helper for test_gpt_validate_should_failWhenBackupLbaNotAtEndOfDisk */
static void validate_partition_array_in_usable_disk_space(uint64_t invalid_lba, bool is_primary)
{
    if (is_primary) {
        test_primary_gpt.header.array_lba = invalid_lba;
        setup_test_gpt();

        expect_read_primary_gpt(PSA_SUCCESS);
    } else {
        test_primary_gpt.header.array_lba = default_header.array_lba;
        setup_test_gpt();

        MAKE_BACKUP_HEADER((test_backup_gpt.header), (test_primary_gpt.header));
        test_backup_gpt.header.array_lba = invalid_lba;

        expect_read_backup_gpt(PSA_SUCCESS);
    }

    /* Every entry read for CRC calculation */
    expect_read_all_entries(PSA_SUCCESS);

    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_SIGNATURE, gpt_validate(is_primary));
}

void setUp(void)
{
    /* Default starting points */
    test_mbr = default_mbr;
    test_primary_gpt.header = default_header;
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
    invalidate_primary_gpt_Ignore();
    set_write_buffered_Ignore();
    is_write_buffered_IgnoreAndReturn(true);
    flush_lba_buf_IgnoreAndReturn(PSA_SUCCESS);

    /* Ignore all write calls */
    write_to_flash_IgnoreAndReturn(PSA_SUCCESS);
    write_header_to_flash_IgnoreAndReturn(PSA_SUCCESS);
    write_headers_to_flash_IgnoreAndReturn(PSA_SUCCESS);
    write_entry_IgnoreAndReturn(PSA_SUCCESS);
    write_entries_to_flash_IgnoreAndReturn(PSA_SUCCESS);
    update_header_IgnoreAndReturn(PSA_SUCCESS);
}

void tearDown(void)
{
    memset(&test_partition_array, 0, sizeof(test_partition_array));
    gpt_uninit();
}

void test_gpt_init_should_loadWhenGptGood(void)
{
    setup_valid_gpt();
}

void test_gpt_init_should_overwriteOldGpt(void)
{
    setup_valid_gpt();
    gpt_uninit();

    /* Use a different flash GUID */
    const struct efi_guid_t new_guid = TEST_GPT_VALID_GUID(1, 1, 3, 4, 5, 6, 7, 8, 9, 10, 11);
    test_primary_gpt.header.flash_guid = new_guid;

    setup_valid_gpt();
}

void test_gpt_init_should_acceptPrimaryArrayLbaNotTwo(void)
{
    test_primary_gpt.header.array_lba++;
    setup_valid_gpt();
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

    /* Expect first a valid MBR read */
    expect_mbr_load(PSA_SUCCESS);

    /* Expect a GPT header read second */
    expect_read_primary_gpt(PSA_SUCCESS);

    /* Expect third only three partitions are read to find the number in use (if the
     * number in the header is non-zero). Third partition is read to find out it is
     * zero, and therefore ignored.
     */
    for (size_t i = 0; i < test_num_partitions + 1; ++i) {
        expect_read_entry(PSA_SUCCESS, &(test_partition_array[i]));
    }

    /* Expect fourth the backup to be read */
    setup_backup_gpt();

    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_init(&mock_driver, TEST_MAX_PARTITIONS));
    TEST_ASSERT_EQUAL(test_num_partitions, test_primary_gpt.num_used_partitions);
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
    expect_read_all_entries(PSA_SUCCESS);

    expect_read_backup_gpt(PSA_ERROR_STORAGE_FAILURE);

    TEST_ASSERT_EQUAL(PSA_ERROR_STORAGE_FAILURE, gpt_init(&mock_driver, TEST_MAX_PARTITIONS));
}

void test_gpt_init_should_failWhenUnableToReadEntry(void)
{
    expect_mbr_load(PSA_SUCCESS);
    expect_read_primary_gpt(PSA_SUCCESS);

    read_entry_from_flash_IgnoreAndReturn(PSA_ERROR_STORAGE_FAILURE);

    TEST_ASSERT_EQUAL(PSA_ERROR_STORAGE_FAILURE, gpt_init(&mock_driver, TEST_MAX_PARTITIONS));
}

void test_gpt_init_should_failWhenMbrSigBad(void)
{
    test_mbr.sig--;

    /* MBR signature validation lives in mbr_load(), which is mocked here. */
    expect_mbr_load(PSA_ERROR_INVALID_ARGUMENT);

    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_ARGUMENT, gpt_init(&mock_driver, TEST_MAX_PARTITIONS));
}

void test_gpt_init_should_failWhenMbrTypeInvalid(void)
{
    test_mbr.partitions[0].os_type--;

    expect_mbr_load(PSA_SUCCESS);

    TEST_ASSERT_EQUAL(PSA_ERROR_NOT_SUPPORTED, gpt_init(&mock_driver, TEST_MAX_PARTITIONS));
}

void test_gpt_init_should_failWhenEntrySizeBad(void)
{
    test_primary_gpt.header.entry_size--;

    expect_mbr_load(PSA_SUCCESS);

    expect_read_primary_gpt(PSA_SUCCESS);

    TEST_ASSERT_EQUAL(PSA_ERROR_NOT_SUPPORTED, gpt_init(&mock_driver, TEST_MAX_PARTITIONS));

    test_primary_gpt.header.entry_size = default_header.entry_size;

    expect_mbr_load(PSA_SUCCESS);

    expect_read_primary_gpt(PSA_SUCCESS);

    expect_read_all_entries(PSA_SUCCESS);

    MAKE_BACKUP_HEADER((test_backup_gpt.header), (test_primary_gpt.header));
    test_backup_gpt.header.entry_size = 0;
    expect_read_backup_gpt(PSA_SUCCESS);

    TEST_ASSERT_EQUAL(PSA_ERROR_NOT_SUPPORTED, gpt_init(&mock_driver, TEST_MAX_PARTITIONS));
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
}

void test_gpt_validate_should_validateWhenGptGood(void)
{
    setup_test_gpt();

    /* Each entry will be read in order to check the partition array CRC */
    expect_read_primary_gpt(PSA_SUCCESS);
    expect_read_all_entries(PSA_SUCCESS);

    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_validate(true));

    /* Now do the backup */
    setup_backup_gpt();
    expect_read_all_entries(PSA_SUCCESS);

    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_validate(false));
}

void test_gpt_validate_should_failWhenGptSigBad(void)
{
    test_primary_gpt.header.signature[0] = '\0';
    setup_test_gpt();

    expect_read_primary_gpt(PSA_SUCCESS);
    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_SIGNATURE, gpt_validate(true));

    /* Now do the backup */
    setup_backup_gpt();
    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_SIGNATURE, gpt_validate(false));
}

void test_gpt_validate_should_failWhenHeaderCrcBad(void)
{
    test_primary_gpt.header.header_crc--;
    setup_test_gpt();

    expect_read_primary_gpt(PSA_SUCCESS);
    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_SIGNATURE, gpt_validate(true));

    /* Now do the backup */
    MAKE_BACKUP_HEADER((test_backup_gpt.header), (test_primary_gpt.header));
    test_backup_gpt.header.header_crc--;
    expect_read_backup_gpt(PSA_SUCCESS);

    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_SIGNATURE, gpt_validate(false));
}

void test_gpt_validate_should_failWhenLbaPointerBad(void)
{
    test_primary_gpt.header.current_lba = 2;
    test_primary_gpt.header.backup_lba = 3;
    setup_test_gpt();

    expect_read_primary_gpt(PSA_SUCCESS);
    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_SIGNATURE, gpt_validate(true));

    /* Now set the backup LBA to be something different that what it should be
     * to force a mismatch
     */
    test_primary_gpt.header.current_lba = default_header.current_lba;
    test_primary_gpt.header.backup_lba = default_header.backup_lba - 1;

    /* Now do the backup */
    MAKE_BACKUP_HEADER((test_backup_gpt.header), (test_primary_gpt.header));
    expect_read_backup_gpt(PSA_SUCCESS);

    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_SIGNATURE, gpt_validate(false));
}

void test_gpt_validate_should_failWhenBackupEntrySizeInvalid(void)
{
    /* The entry size for the primary GPT is validated on gpt_init and kept
     * in memory. Therefore, the entry size can only be validated on gpt_validate
     * for the backup table, which is read
     */
    setup_test_gpt();

    MAKE_BACKUP_HEADER((test_backup_gpt.header), (test_primary_gpt.header));
    test_backup_gpt.header.entry_size--;
    expect_read_backup_gpt(PSA_SUCCESS);

    TEST_ASSERT_EQUAL(PSA_ERROR_NOT_SUPPORTED, gpt_validate(false));
}

void test_gpt_validate_should_failWhenArrayCrcBad(void)
{
    test_primary_gpt.header.array_crc--;
    setup_test_gpt();

    /* Each entry will be read in order to check the partition array CRC */
    expect_read_primary_gpt(PSA_SUCCESS);
    expect_read_all_entries(PSA_SUCCESS);

    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_SIGNATURE, gpt_validate(true));

    /* Now do the backup */
    MAKE_BACKUP_HEADER((test_backup_gpt.header), (test_primary_gpt.header));
    test_backup_gpt.header.array_crc--;
    expect_read_backup_gpt(PSA_SUCCESS);
    expect_read_all_entries(PSA_SUCCESS);

    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_SIGNATURE, gpt_validate(false));
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

void test_gpt_validate_should_failWhenUnableToReadGpt(void)
{
    /* Start with a valid GPT */
    setup_valid_gpt();

    expect_read_primary_gpt(PSA_ERROR_STORAGE_FAILURE);
    TEST_ASSERT_EQUAL(PSA_ERROR_STORAGE_FAILURE, gpt_validate(true));

    /* Now do the backup */
    expect_read_backup_gpt(PSA_ERROR_STORAGE_FAILURE);
    TEST_ASSERT_EQUAL(PSA_ERROR_STORAGE_FAILURE, gpt_validate(true));
}

void test_gpt_validate_should_failWhenUnableToReadEntry(void)
{
    /* Start with a valid GPT */
    setup_valid_gpt();

    /* Test primary GPT first. Fail on first entry read */
    expect_read_primary_gpt(PSA_SUCCESS);

    expect_read_entry(PSA_ERROR_STORAGE_FAILURE, &(test_partition_array[0]));

    TEST_ASSERT_EQUAL(PSA_ERROR_STORAGE_FAILURE, gpt_validate(true));

    /* Now do the backup table */
    expect_read_backup_gpt(PSA_SUCCESS);

    expect_read_entry(PSA_ERROR_STORAGE_FAILURE, &(test_partition_array[0]));

    TEST_ASSERT_EQUAL(PSA_ERROR_STORAGE_FAILURE, gpt_validate(false));
}

void test_gpt_restore_should_restorePrimaryFromBackup(void)
{
    /* Start with a valid GPT */
    setup_valid_gpt();

    /* The backup table is read and checked for validity, including taking
     * CRC32 of partition array and the number of used partitions
     */
    setup_backup_gpt();
    expect_read_all_entries(PSA_SUCCESS);
    expect_read_all_entries(PSA_SUCCESS);
    expect_read_primary_gpt(PSA_SUCCESS);
    read_from_flash_ExpectAnyArgsAndReturn(PSA_SUCCESS);
    expect_read_primary_gpt(PSA_SUCCESS);

    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_restore(true));
}

void test_gpt_restore_should_failToRestoreWhenBackupIsBad(void)
{
    /* Start with a valid GPT */
    setup_valid_gpt();

    /* The backup table is read and checked for validity. Corrupt it in
     * various ways
     */

    /* Bad signature */
    MAKE_BACKUP_HEADER((test_backup_gpt.header), (test_primary_gpt.header));
    test_backup_gpt.header.signature[0] = '\0';
    expect_read_backup_gpt(PSA_SUCCESS);
    expect_read_all_entries(PSA_SUCCESS);
    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_SIGNATURE, gpt_restore(true));

    /* Bad header CRC */
    MAKE_BACKUP_HEADER((test_backup_gpt.header), (test_primary_gpt.header));
    test_backup_gpt.header.header_crc = 0;
    expect_read_backup_gpt(PSA_SUCCESS);
    expect_read_all_entries(PSA_SUCCESS);
    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_SIGNATURE, gpt_restore(true));

    /* Bad LBA */
    test_primary_gpt.header.backup_lba = 2;
    MAKE_BACKUP_HEADER((test_backup_gpt.header), (test_primary_gpt.header));
    expect_read_backup_gpt(PSA_SUCCESS);
    expect_read_all_entries(PSA_SUCCESS);
    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_SIGNATURE, gpt_restore(true));
    test_primary_gpt.header.backup_lba = default_header.backup_lba;

    /* Bad array CRC. Will involve reading array entries */
    MAKE_BACKUP_HEADER((test_backup_gpt.header), (test_primary_gpt.header));
    test_backup_gpt.header.array_crc = 0;
    expect_read_backup_gpt(PSA_SUCCESS);
    expect_read_all_entries(PSA_SUCCESS);
    expect_read_all_entries(PSA_SUCCESS);
    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_SIGNATURE, gpt_restore(true));
}

void test_gpt_restore_should_failWhenUnableToReadRestoringGpt(void)
{
    setup_valid_gpt();

    /* Attempt to restore primary from backup */
    expect_read_backup_gpt(PSA_ERROR_STORAGE_FAILURE);
    TEST_ASSERT_EQUAL(PSA_ERROR_STORAGE_FAILURE, gpt_restore(true));

    /* Not attempt to restore backup from primary */
    expect_read_primary_gpt(PSA_ERROR_STORAGE_FAILURE);
    TEST_ASSERT_EQUAL(PSA_ERROR_STORAGE_FAILURE, gpt_restore(true));
}

void test_gpt_restore_should_failWhenUnableToReadEntry(void)
{
    /* Start with a valid GPT */
    setup_valid_gpt();

    /* Test restoring primary GPT first. Fail on first entry read */
    expect_read_backup_gpt(PSA_SUCCESS);
    expect_read_entry(PSA_ERROR_STORAGE_FAILURE, &(test_partition_array[0]));
    TEST_ASSERT_EQUAL(PSA_ERROR_STORAGE_FAILURE, gpt_restore(true));

    /* Now do the backup table */
    expect_read_primary_gpt(PSA_SUCCESS);
    expect_read_entry(PSA_ERROR_STORAGE_FAILURE, &(test_partition_array[0]));
    TEST_ASSERT_EQUAL(PSA_ERROR_STORAGE_FAILURE, gpt_restore(false));
}

void test_gpt_defragment_should_succeedWhenNoIOFailure(void)
{
    setup_valid_gpt();

    /* Always return primary GPT when reading a table in this test. If the
     * backup was read, it shouldn't end up mattering anyway since the same
     * partition entry's should be read in the end too
     */
    expect_read_primary_gpt_only();

    /* Always return the same entry for this test, as the number of times
     * each entry is read is complicated and could change easily with a
     * different implementation
     */
    expect_same_read_entry_from_flash();

    /* Do not worry when the partition data is being moved */
    read_from_flash_IgnoreAndReturn(PSA_SUCCESS);

    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_defragment());
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

void test_gpt_entry_duplicate_should_DuplicateOldEntry(void)
{
    /* Duplicate an entry. It must not overlap with an existing entry and must also
     * fit on the storage device. The GUID should be populated with something.
     */
    setup_valid_gpt();
    struct gpt_entry_t *old_entry = &(test_partition_array[0]);
    struct efi_guid_t old_guid = old_entry->unique_guid;

    /* Always return primary GPT when reading a table in this test. If the
     * backup was read, it shouldn't end up mattering anyway since the same
     * partition entry's should be read in the end too
     */
    expect_read_primary_gpt_only();

    /* Read the old entry */
    expect_read_entry(PSA_SUCCESS, old_entry);

    /* Check overlap with existing entries */
    expect_read_used_entries(PSA_SUCCESS);

    /* Move partition data */
    read_from_flash_IgnoreAndReturn(PSA_SUCCESS);

    /* Mock out the call to create a new GUID */
    struct efi_guid_t expected_guid = TEST_GPT_VALID_GUID(5, 5, 5, 5, 5, 6, 7, 8, 9, 10, 11);

    efi_guid_generate_random_ExpectAnyArgsAndReturn(PSA_SUCCESS);
    efi_guid_generate_random_ReturnThruPtr_guid(&expected_guid);

    /* Ensure that a new GUID is assigned. To test the duplication was successful
     * would require reading from flash, which would be mocked anyway and therefore
     * pointless
     */
    struct efi_guid_t new_guid = TEST_GPT_DUMMY_GUID;

    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_entry_duplicate(
                &old_guid,
                TEST_GPT_DISK_FREE_SPACE_START,
                &new_guid));
    TEST_ASSERT_EQUAL_MEMORY(&expected_guid, &new_guid, sizeof(new_guid));
}

void test_gpt_entry_duplicate_should_createNewEntryNextToLastEntry(void)
{
    /* Duplicate an entry, allowing the library to choose the start LBA. The
     * GUID should be populated with something
     */
    setup_valid_gpt();
    struct gpt_entry_t *old_entry = &(test_partition_array[0]);
    struct efi_guid_t old_guid = old_entry->unique_guid;

    /* Always return primary GPT when reading a table in this test. If the
     * backup was read, it shouldn't end up mattering anyway since the same
     * partition entry's should be read in the end too
     */
    expect_read_primary_gpt_only();

    expect_read_entry(PSA_SUCCESS, old_entry);

    /* Find the free space at the end of the test disk */
    expect_read_all_entries(PSA_SUCCESS);

    /* Check overlap with existing entries */
    expect_read_used_entries(PSA_SUCCESS);

    /* Move partition data */
    read_from_flash_IgnoreAndReturn(PSA_SUCCESS);

    /* Mock out the call to create a new GUID */
    struct efi_guid_t expected_guid = TEST_GPT_VALID_GUID(5, 5, 5, 5, 5, 6, 7, 8, 9, 10, 11);

    efi_guid_generate_random_ExpectAnyArgsAndReturn(PSA_SUCCESS);
    efi_guid_generate_random_ReturnThruPtr_guid(&expected_guid);

    /* Ensure that a new GUID is assigned. To test the duplication was successful
     * would require reading from flash, which would be mocked anyway and therefore
     * pointless
     */
    struct efi_guid_t new_guid = TEST_GPT_DUMMY_GUID;

    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_entry_duplicate(
                &old_guid,
                0,
                &new_guid));
    TEST_ASSERT_EQUAL_MEMORY(&expected_guid, &new_guid, sizeof(new_guid));
}

void test_gpt_entry_duplicate_should_failToCreateEntryWhenLowestFreeLbaDoesNotHaveSpace(void)
{
    /* Duplicate an entry, allowing the library to choose the start LBA. Resize
     * the last partition to consume over half of the disk, such that duplicating
     * it won't be possible.
     */
    struct gpt_entry_t *old_entry =
        &(test_partition_array[TEST_DEFAULT_NUM_PARTITIONS - 1]);

    old_entry->end = TEST_GPT_THIRD_PARTITION_START + (TEST_DISK_NUM_BLOCKS / 2) + 1;
    struct efi_guid_t old_guid = old_entry->unique_guid;

    setup_valid_gpt();

    /* Always return primary GPT when reading a table in this test. If the
     * backup was read, it shouldn't end up mattering anyway since the same
     * partition entry's should be read in the end too
     */
    expect_read_primary_gpt_only();

    expect_read_used_entries(PSA_SUCCESS);

    expect_read_all_entries(PSA_SUCCESS);

    struct efi_guid_t new_guid;

    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_ARGUMENT, gpt_entry_duplicate(
                &old_guid,
                0,
                &new_guid));
}

void test_gpt_entry_duplicate_should_failWhenEntryNotExisting(void)
{
    setup_valid_gpt();
    struct efi_guid_t old_guid = NULL_GUID;

    /* Always return primary GPT when reading a table in this test. If the
     * backup was read, it shouldn't end up mattering anyway since the same
     * partition entry's should be read in the end too
     */
    expect_read_primary_gpt_only();

    expect_read_used_entries(PSA_SUCCESS);

    struct efi_guid_t new_guid;

    TEST_ASSERT_EQUAL(PSA_ERROR_DOES_NOT_EXIST, gpt_entry_duplicate(
                &old_guid,
                TEST_GPT_DISK_FREE_SPACE_START,
                &new_guid));
}

void test_gpt_entry_duplicate_should_failNewEntryOverlapping(void)
{
    setup_valid_gpt();
    struct gpt_entry_t *old_entry = &(test_partition_array[0]);
    struct efi_guid_t old_guid = old_entry->unique_guid;
    struct efi_guid_t new_guid;

    /* Always return primary GPT when reading a table in this test. If the
     * backup was read, it shouldn't end up mattering anyway since the same
     * partition entry's should be read in the end too
     */
    expect_read_primary_gpt_only();

    expect_read_entry(PSA_SUCCESS, old_entry);

    expect_read_entry(PSA_SUCCESS, &(test_partition_array[0]));

    /* Since the disk is not fragmented by default, there are two test cases:
     *   1. start in the middle of a partition and end in the middle of a partition
     *   2. start in the middle of a partition and end in free space
     */
    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_ARGUMENT, gpt_entry_duplicate(
                &old_guid,
                TEST_GPT_FIRST_PARTITION_START + 1,
                &new_guid));

    expect_read_entry(PSA_SUCCESS, old_entry);

    expect_read_used_entries(PSA_SUCCESS);

    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_ARGUMENT, gpt_entry_duplicate(
                &old_guid,
                TEST_GPT_THIRD_PARTITION_START + 1,
                &new_guid));
}

void test_gpt_entry_duplicate_should_failWhenTableFull(void)
{
    /* Start with a full array of entries */
    const uint64_t new_entry_end = TEST_GPT_DISK_FREE_SPACE_START;
    struct gpt_entry_t new_entry = {
        .partition_type = TEST_GPT_VALID_TYPE(4, 4, 4, 4, 5, 6, 7, 8, 9, 10, 11),
        .start = new_entry_end,
        .end = new_entry_end,
        .attr = 0,
        .unique_guid = TEST_GPT_VALID_GUID(4, 4, 4, 4, 5, 6, 7, 8, 9, 10, 11),
        .name = "Fourth partition"
    };
    test_partition_array[TEST_MAX_PARTITIONS - 1] = new_entry;
    setup_valid_gpt();

    struct gpt_entry_t *old_entry = &(test_partition_array[0]);
    struct efi_guid_t old_guid = old_entry->unique_guid;
    struct efi_guid_t new_guid;

    /* Always return primary GPT when reading a table in this test. If the
     * backup was read, it shouldn't end up mattering anyway since the same
     * partition entry's should be read in the end too
     */
    expect_read_primary_gpt_only();

    expect_read_entry(PSA_SUCCESS, old_entry);

    TEST_ASSERT_EQUAL(PSA_ERROR_INSUFFICIENT_STORAGE, gpt_entry_duplicate(
                &old_guid,
                new_entry_end + 1,
                &new_guid));
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

void test_gpt_entry_duplicate_no_copy_should_DuplicateOldEntry(void)
{
    /* Duplicate an entry. It must not overlap with an existing entry and must also
     * fit on the storage device. The GUID should be populated with something.
     */
    setup_valid_gpt();
    struct gpt_entry_t *old_entry = &(test_partition_array[0]);
    struct efi_guid_t old_guid = old_entry->unique_guid;

    /* Always return primary GPT when reading a table in this test. If the
     * backup was read, it shouldn't end up mattering anyway since the same
     * partition entry's should be read in the end too
     */
    expect_read_primary_gpt_only();

    expect_read_entry(PSA_SUCCESS, old_entry);

    expect_read_used_entries(PSA_SUCCESS);

    /* Mock out the call to create a new GUID */
    struct efi_guid_t expected_guid = TEST_GPT_VALID_GUID(5, 5, 5, 5, 5, 6, 7, 8, 9, 10, 11);

    efi_guid_generate_random_ExpectAnyArgsAndReturn(PSA_SUCCESS);
    efi_guid_generate_random_ReturnThruPtr_guid(&expected_guid);

    /* Ensure that a new GUID is assigned. To test the duplication was successful
     * would require reading from flash, which would be mocked anyway and therefore
     * pointless
     */
    struct efi_guid_t new_guid = TEST_GPT_DUMMY_GUID;

    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_entry_duplicate_no_copy(
                &old_guid,
                TEST_GPT_DISK_FREE_SPACE_START,
                &new_guid));
    TEST_ASSERT_EQUAL_MEMORY(&expected_guid, &new_guid, sizeof(new_guid));
}

void test_gpt_entry_duplicate_no_copy_should_createNewEntryNextToLastEntry(void)
{
    /* Duplicate an entry, allowing the library to choose the start LBA. The
     * GUID should be populated with something
     */
    setup_valid_gpt();
    struct gpt_entry_t *old_entry = &(test_partition_array[0]);
    struct efi_guid_t old_guid = old_entry->unique_guid;

    /* Always return primary GPT when reading a table in this test. If the
     * backup was read, it shouldn't end up mattering anyway since the same
     * partition entry's should be read in the end too
     */
    expect_read_primary_gpt_only();

    expect_read_entry(PSA_SUCCESS, old_entry);

    expect_read_all_entries(PSA_SUCCESS);
    expect_read_used_entries(PSA_SUCCESS);

    /* Mock out the call to create a new GUID */
    struct efi_guid_t expected_guid = TEST_GPT_VALID_GUID(5, 5, 5, 5, 5, 6, 7, 8, 9, 10, 11);

    efi_guid_generate_random_ExpectAnyArgsAndReturn(PSA_SUCCESS);
    efi_guid_generate_random_ReturnThruPtr_guid(&expected_guid);

    /* Ensure that a new GUID is assigned. To test the duplication was successful
     * would require reading from flash, which would be mocked anyway and therefore
     * pointless
     */
    struct efi_guid_t new_guid = TEST_GPT_DUMMY_GUID;

    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_entry_duplicate_no_copy(
                &old_guid,
                0,
                &new_guid));
    TEST_ASSERT_EQUAL_MEMORY(&expected_guid, &new_guid, sizeof(new_guid));
}

void test_gpt_entry_duplicate_no_copy_should_failToCreateEntryWhenLowestFreeLbaDoesNotHaveSpace(void)
{
    /* Duplicate an entry, allowing the library to choose the start LBA. Resize
     * the last partition to consume over half of the disk, such that duplicating
     * it won't be possible.
     */
    struct gpt_entry_t *old_entry =
        &(test_partition_array[TEST_DEFAULT_NUM_PARTITIONS - 1]);

    old_entry->end = TEST_GPT_THIRD_PARTITION_START + (TEST_DISK_NUM_BLOCKS / 2) + 1;
    struct efi_guid_t old_guid = old_entry->unique_guid;

    setup_valid_gpt();

    /* Always return primary GPT when reading a table in this test. If the
     * backup was read, it shouldn't end up mattering anyway since the same
     * partition entry's should be read in the end too
     */
    expect_read_primary_gpt_only();

    expect_read_used_entries(PSA_SUCCESS);

    expect_read_all_entries(PSA_SUCCESS);

    struct efi_guid_t new_guid;

    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_ARGUMENT, gpt_entry_duplicate_no_copy(
                &old_guid,
                0,
                &new_guid));
}

void test_gpt_entry_duplicate_no_copy_should_failWhenEntryNotExisting(void)
{
    setup_valid_gpt();
    struct efi_guid_t old_guid = NULL_GUID;

    /* Always return primary GPT when reading a table in this test. If the
     * backup was read, it shouldn't end up mattering anyway since the same
     * partition entry's should be read in the end too
     */
    expect_read_primary_gpt_only();

    expect_read_used_entries(PSA_SUCCESS);

    struct efi_guid_t new_guid;

    TEST_ASSERT_EQUAL(PSA_ERROR_DOES_NOT_EXIST, gpt_entry_duplicate_no_copy(
                &old_guid,
                TEST_GPT_DISK_FREE_SPACE_START,
                &new_guid));
}

void test_gpt_entry_duplicate_no_copy_should_failNewEntryOverlapping(void)
{
    setup_valid_gpt();
    struct gpt_entry_t *old_entry = &(test_partition_array[0]);
    struct efi_guid_t old_guid = old_entry->unique_guid;
    struct efi_guid_t new_guid;

    /* Always return primary GPT when reading a table in this test. If the
     * backup was read, it shouldn't end up mattering anyway since the same
     * partition entry's should be read in the end too
     */
    expect_read_primary_gpt_only();

    expect_read_entry(PSA_SUCCESS, old_entry);

    expect_read_entry(PSA_SUCCESS, &(test_partition_array[0]));

    /* Since the disk is not fragmented by default, there are two test cases:
     *   1. start in the middle of a partition and end in the middle of a partition
     *   2. start in the middle of a partition and end in free space
     */
    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_ARGUMENT, gpt_entry_duplicate_no_copy(
                &old_guid,
                TEST_GPT_FIRST_PARTITION_START + 1,
                &new_guid));

    expect_read_entry(PSA_SUCCESS, old_entry);

    expect_read_used_entries(PSA_SUCCESS);

    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_ARGUMENT, gpt_entry_duplicate_no_copy(
                &old_guid,
                TEST_GPT_THIRD_PARTITION_START + 1,
                &new_guid));
}

void test_gpt_entry_duplicate_no_copy_should_failWhenTableFull(void)
{
    /* Start with a full array of entries */
    const uint64_t new_entry_end = TEST_GPT_DISK_FREE_SPACE_START;
    struct gpt_entry_t new_entry = {
        .partition_type = TEST_GPT_VALID_TYPE(4, 4, 4, 4, 5, 6, 7, 8, 9, 10, 11),
        .start = new_entry_end,
        .end = new_entry_end,
        .attr = 0,
        .unique_guid = TEST_GPT_VALID_GUID(4, 4, 4, 4, 5, 6, 7, 8, 9, 10, 11),
        .name = "Fourth partition"
    };
    test_partition_array[TEST_MAX_PARTITIONS - 1] = new_entry;
    setup_valid_gpt();

    struct gpt_entry_t *old_entry = &(test_partition_array[0]);
    struct efi_guid_t old_guid = old_entry->unique_guid;
    struct efi_guid_t new_guid;

    /* Always return primary GPT when reading a table in this test. If the
     * backup was read, it shouldn't end up mattering anyway since the same
     * partition entry's should be read in the end too
     */
    expect_read_primary_gpt_only();

    expect_read_entry(PSA_SUCCESS, old_entry);

    TEST_ASSERT_EQUAL(PSA_ERROR_INSUFFICIENT_STORAGE, gpt_entry_duplicate_no_copy(
                &old_guid,
                new_entry_end + 1,
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

void test_gpt_entry_create_should_createNewEntry(void)
{
    /* Add an entry. It must not overlap with an existing entry and must also
     * fit on the storage device. The GUID should be populated with something.
     */
    setup_valid_gpt();
    expect_read_primary_gpt_only();

    /* Each used entry will be read to check that it doesn't overlap. */
    expect_read_used_entries(PSA_SUCCESS);

    struct gpt_entry_t new_entry = {
        .partition_type = TEST_GPT_DUMMY_TYPE,
        .start = TEST_GPT_DISK_FREE_SPACE_START,
        .end = TEST_GPT_DISK_FREE_SPACE_START,
        .attr = 0,
        .name = "Fourth partition"
    };

    /* Mock out the call to create a new GUID */
    struct efi_guid_t expected_guid = TEST_GPT_VALID_GUID(5, 5, 5, 5, 5, 6, 7, 8, 9, 10, 11);
    efi_guid_generate_random_ExpectAnyArgsAndReturn(PSA_SUCCESS);
    efi_guid_generate_random_ReturnThruPtr_guid(&expected_guid);

    /* Ensure also the that a new GUID is assigned */
    struct efi_guid_t new_guid = TEST_GPT_DUMMY_GUID;
    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_entry_create(
                &expected_guid,
                new_entry.start,
                new_entry.end - new_entry.start + 1,
                new_entry.attr,
                new_entry.name,
                &new_guid));
    TEST_ASSERT_EQUAL_MEMORY(&expected_guid, &new_guid, sizeof(new_guid));
}

void test_gpt_entry_create_should_createNewEntryNextToLastEntry(void)
{
    /* Add an entry, allowing the library to choose the start LBA.
     * The GUID should be populated with something.
     */
    setup_valid_gpt();
    expect_read_primary_gpt_only();

    /* Find the lowest free LBA, then check overlap with existing entries. */
    expect_read_all_entries(PSA_SUCCESS);
    expect_read_used_entries(PSA_SUCCESS);

    struct gpt_entry_t new_entry = {
        .partition_type = TEST_GPT_DUMMY_TYPE,
        .start = TEST_GPT_DISK_FREE_SPACE_START,
        .end = TEST_GPT_DISK_FREE_SPACE_START,
        .attr = 0,
        .name = "Fourth partition"
    };

    /* Mock out the call to create a new GUID */
    struct efi_guid_t expected_guid = TEST_GPT_VALID_GUID(5, 5, 5, 5, 5, 6, 7, 8, 9, 10, 11);
    efi_guid_generate_random_ExpectAnyArgsAndReturn(PSA_SUCCESS);
    efi_guid_generate_random_ReturnThruPtr_guid(&expected_guid);

    /* Ensure also the that a new GUID is assigned */
    struct efi_guid_t new_guid = TEST_GPT_DUMMY_GUID;
    char name[GPT_ENTRY_NAME_LENGTH] = {'\0'};
    name[0] = 'a';

    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_entry_create(
                &expected_guid,
                0,
                1,
                new_entry.attr,
                name,
                &new_guid));
    TEST_ASSERT_EQUAL_MEMORY(&expected_guid, &new_guid, sizeof(new_guid));
}

void test_gpt_entry_create_should_failToCreateEntryWhenLowestFreeLbaDoesNotHaveSpace(void)
{
    /* Add an entry, allowing the library to choose the start LBA.
     * The GUID should be populated with something.
     */
    setup_valid_gpt();
    expect_read_primary_gpt_only();

    /* Find the lowest free LBA before discovering the requested size will not fit. */
    expect_read_all_entries(PSA_SUCCESS);

    struct efi_guid_t existing_guid = TEST_GPT_VALID_GUID(4, 4, 4, 4, 5, 6, 7, 8, 9, 10, 11);
    struct efi_guid_t new_guid;
    char name[GPT_ENTRY_NAME_LENGTH] = {'\0'};
    name[0] = 'a';
    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_ARGUMENT, gpt_entry_create(
                &(existing_guid),
                0,
                TEST_DISK_NUM_BLOCKS,
                0,
                name,
                &(new_guid)));
}

void test_gpt_entry_create_should_failWhenTableFull(void)
{
    /* Start with a full array of entries */
    const uint64_t new_entry_end = TEST_GPT_DISK_FREE_SPACE_START;
    struct gpt_entry_t new_entry = {
        .partition_type = TEST_GPT_VALID_TYPE(4, 4, 4, 4, 5, 6, 7, 8, 9, 10, 11),
        .start = new_entry_end,
        .end = new_entry_end,
        .attr = 0,
        .unique_guid = TEST_GPT_VALID_GUID(4, 4, 4, 4, 5, 6, 7, 8, 9, 10, 11),
        .name = "Fourth partition"
    };
    test_partition_array[TEST_MAX_PARTITIONS - 1] = new_entry;
    setup_valid_gpt();
    expect_read_primary_gpt_only();

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
}

void test_gpt_entry_create_should_failWhenLbaOffDisk(void)
{
    setup_valid_gpt();
    expect_read_primary_gpt_only();

    /* First start on disk, then go off the disk */
    struct efi_guid_t type = TEST_GPT_DUMMY_TYPE;
    struct efi_guid_t guid;
    char name[GPT_ENTRY_NAME_LENGTH] = {'\0'};
    name[0] = 'a';
    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_ARGUMENT, gpt_entry_create(
                &type,
                TEST_GPT_DISK_FREE_SPACE_START,
                1000,
                0,
                name,
                &guid));

    /* Second, start off the disk entirely */
    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_ARGUMENT, gpt_entry_create(
                &type,
                TEST_DISK_NUM_BLOCKS + 100,
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
}

void test_gpt_entry_create_should_failWhenOverlapping(void)
{
    setup_valid_gpt();
    expect_read_primary_gpt_only();

    /* Since the disk is not fragmented by default, there are two test cases:
     *   1. start in the middle of a partition and end in the middle of a partition
     *   2. start in the middle of a partition and end in free space
     */
    struct efi_guid_t type = TEST_GPT_DUMMY_TYPE;
    struct efi_guid_t guid;
    char name[GPT_ENTRY_NAME_LENGTH] = {'\0'};
    name[0] = 'a';

    /* Expect a read from the first entry, as that is the one overlapping */
    expect_read_entry(PSA_SUCCESS, &(test_partition_array[0]));

    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_ARGUMENT, gpt_entry_create(
                &type,
                TEST_GPT_FIRST_PARTITION_START,
                TEST_GPT_FIRST_PARTITION_END - TEST_GPT_FIRST_PARTITION_START + 1,
                0,
                name,
                &guid));

    /* Expect a read from the first entry, as that is the one overlapping */
    expect_read_entry(PSA_SUCCESS, &(test_partition_array[0]));

    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_ARGUMENT, gpt_entry_create(
                &type,
                TEST_GPT_FIRST_PARTITION_START,
                TEST_GPT_LAST_USABLE_LBA - TEST_GPT_FIRST_PARTITION_START,
                0,
                name,
                &guid));
}

void test_gpt_entry_create_should_failWhenNameIsEmpty(void)
{
    /* Start with a populated GPT */
    setup_valid_gpt();
    expect_read_primary_gpt_only();

    struct efi_guid_t type = TEST_GPT_DUMMY_TYPE;
    struct gpt_entry_t new_entry = {
        .partition_type = type,
        .start = TEST_GPT_DISK_FREE_SPACE_START,
        .end = TEST_GPT_DISK_FREE_SPACE_START,
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
}

void test_gpt_entry_create_should_failWhenSizeIsZero(void)
{
    /* Start with a populated GPT */
    setup_valid_gpt();
    expect_read_primary_gpt_only();

    struct efi_guid_t type = TEST_GPT_DUMMY_TYPE;

    /* Make the size zero */
    struct efi_guid_t new_guid;
    char name[GPT_ENTRY_NAME_LENGTH] = {'\0'};
    name[0] = 'a';
    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_ARGUMENT, gpt_entry_create(
                &type,
                TEST_GPT_DISK_FREE_SPACE_START,
                0,
                0,
                name,
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

void test_gpt_entry_move_should_moveEntry(void)
{
    /* Start with a populated GPT */
    setup_valid_gpt();
    struct gpt_entry_t *test_entry = &(test_partition_array[TEST_DEFAULT_NUM_PARTITIONS - 1]);
    struct efi_guid_t test_guid = test_entry->unique_guid;

    expect_read_primary_gpt_only();

    /* Find the entry, then check overlap with existing entries */
    expect_read_used_entries(PSA_SUCCESS);
    expect_read_used_entries(PSA_SUCCESS);

    /* Move partition data */
    read_from_flash_IgnoreAndReturn(PSA_SUCCESS);

    /* Do a valid move and resize in one */
    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_entry_move(
                &test_guid,
                TEST_GPT_DISK_FREE_SPACE_START,
                TEST_GPT_DISK_FREE_SPACE_START));
}

void test_gpt_entry_move_should_failWhenEntryNotExisting(void)
{
    setup_valid_gpt();
    expect_read_primary_gpt_only();

    /* Read every entry */
    expect_read_used_entries(PSA_SUCCESS);

    struct efi_guid_t non_existing = NULL_GUID;
    TEST_ASSERT_EQUAL(PSA_ERROR_DOES_NOT_EXIST, gpt_entry_move(
                &non_existing,
                TEST_GPT_DISK_FREE_SPACE_START,
                TEST_GPT_DISK_FREE_SPACE_START));
}

void test_gpt_entry_move_should_failWhenEndLessThanStart(void)
{
    setup_valid_gpt();
    expect_read_primary_gpt_only();

    struct efi_guid_t test_guid = test_partition_array[0].unique_guid;
    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_ARGUMENT, gpt_entry_move(
                &test_guid,
                TEST_GPT_DISK_FREE_SPACE_START + 1,
                TEST_GPT_DISK_FREE_SPACE_START));
}

void test_gpt_entry_move_should_failWhenLbaOverlapping(void)
{
    setup_valid_gpt();
    expect_read_primary_gpt_only();

    /* Try to move the test entry into the middle of some other entry.
     * Starting at the same LBA
     */
    size_t test_index = 1;
    struct gpt_entry_t *test_entry = &(test_partition_array[test_index]);
    struct efi_guid_t test_guid = test_entry->unique_guid;

    /* Find entry */
    expect_read_entry(PSA_SUCCESS, &(test_partition_array[0]));
    expect_read_entry(PSA_SUCCESS, test_entry);

    /* Check for overlap */
    expect_read_entry(PSA_SUCCESS, &(test_partition_array[0]));

    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_ARGUMENT, gpt_entry_move(
                &test_guid,
                TEST_GPT_FIRST_PARTITION_START,
                TEST_GPT_SECOND_PARTITION_END));

    /* Try to move the test entry into the middle of some other entry.
     * Starting in the middle
     */
    /* Find the second entry */
    expect_read_entry(PSA_SUCCESS, &(test_partition_array[0]));
    expect_read_entry(PSA_SUCCESS, test_entry);

    /* Overlap with the first */
    expect_read_entry(PSA_SUCCESS, &(test_partition_array[0]));

    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_ARGUMENT, gpt_entry_move(
                &test_guid,
                TEST_GPT_FIRST_PARTITION_START + 1,
                TEST_GPT_SECOND_PARTITION_END));

    /* Find the second entry */
    expect_read_entry(PSA_SUCCESS, &(test_partition_array[0]));
    expect_read_entry(PSA_SUCCESS, test_entry);

    /* Overlap with the third entry */
    expect_read_entry(PSA_SUCCESS, &(test_partition_array[0]));
    expect_read_entry(PSA_SUCCESS, test_entry);

    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_ARGUMENT, gpt_entry_move(
                &test_guid,
                TEST_GPT_SECOND_PARTITION_START,
                TEST_GPT_THIRD_PARTITION_START));

    /* Try to move the test entry into the middle of the entry just read.
     * Starting and ending in the middle.
     */
    expect_read_entry(PSA_SUCCESS, &(test_partition_array[0]));
    expect_read_entry(PSA_SUCCESS, test_entry);
    expect_read_entry(PSA_SUCCESS, &(test_partition_array[0]));

    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_ARGUMENT, gpt_entry_move(
                &test_guid,
                TEST_GPT_FIRST_PARTITION_START + 1,
                TEST_GPT_FIRST_PARTITION_START + 1));
}

void test_gpt_entry_move_should_failWhenLbaOffDisk(void)
{
    setup_valid_gpt();
    expect_read_primary_gpt_only();

    /* Try to move an entry. */
    size_t test_index = 1;
    struct gpt_entry_t *test_entry = &(test_partition_array[test_index]);
    struct efi_guid_t test_guid = test_entry->unique_guid;

    /* First start on disk, then go off the disk */
    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_ARGUMENT, gpt_entry_move(
                &test_guid,
                TEST_GPT_DISK_FREE_SPACE_START,
                TEST_DISK_NUM_BLOCKS + 1));

    /* Second, start off the disk entirely */
    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_ARGUMENT, gpt_entry_move(
                &test_guid,
                TEST_DISK_NUM_BLOCKS + 1,
                TEST_DISK_NUM_BLOCKS + 2));

    /* Third, do the same but in the header area */
    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_ARGUMENT, gpt_entry_move(
                &test_guid,
                TEST_GPT_PRIMARY_LBA,
                TEST_GPT_DISK_FREE_SPACE_START + 1));

    /* Fourth, start in the backup header area */
    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_ARGUMENT, gpt_entry_move(
                &test_guid,
                TEST_GPT_BACKUP_LBA,
                TEST_GPT_BACKUP_LBA + 1));
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

void test_gpt_entry_move_no_copy_should_moveEntry(void)
{
    /* Start with a populated GPT */
    setup_valid_gpt();
    struct gpt_entry_t *test_entry = &(test_partition_array[TEST_DEFAULT_NUM_PARTITIONS - 1]);
    struct efi_guid_t test_guid = test_entry->unique_guid;

    expect_read_primary_gpt_only();

    /* Find the entry, then check overlap with existing entries */
    expect_read_used_entries(PSA_SUCCESS);
    expect_read_used_entries(PSA_SUCCESS);

    /* Do a valid move and resize in one */
    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_entry_move_no_copy(
                &test_guid,
                TEST_GPT_DISK_FREE_SPACE_START,
                TEST_GPT_DISK_FREE_SPACE_START));
}

void test_gpt_entry_move_no_copy_should_failWhenEntryNotExisting(void)
{
    setup_valid_gpt();
    expect_read_primary_gpt_only();

    /* Read every entry */
    expect_read_used_entries(PSA_SUCCESS);

    struct efi_guid_t non_existing = NULL_GUID;

    TEST_ASSERT_EQUAL(PSA_ERROR_DOES_NOT_EXIST, gpt_entry_move_no_copy(
                &non_existing,
                TEST_GPT_DISK_FREE_SPACE_START,
                TEST_GPT_DISK_FREE_SPACE_START));
}

void test_gpt_entry_move_no_copy_should_failWhenEndLessThanStart(void)
{
    setup_valid_gpt();
    expect_read_primary_gpt_only();

    struct efi_guid_t test_guid = test_partition_array[0].unique_guid;

    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_ARGUMENT, gpt_entry_move_no_copy(
                &test_guid,
                TEST_GPT_DISK_FREE_SPACE_START + 1,
                TEST_GPT_DISK_FREE_SPACE_START));
}

void test_gpt_entry_move_no_copy_should_failWhenLbaOverlapping(void)
{
    setup_valid_gpt();
    expect_read_primary_gpt_only();

    /* Try to move an entry. Each entry is read to determine for overlap */
    size_t test_index = 1;
    struct gpt_entry_t *test_entry = &(test_partition_array[test_index]);
    struct efi_guid_t test_guid = test_entry->unique_guid;

    /* Try to move the test entry into the middle of the entry just read.
     * Starting at the same LBA
     */
    expect_read_entry(PSA_SUCCESS, &(test_partition_array[0]));
    expect_read_entry(PSA_SUCCESS, test_entry);
    expect_read_entry(PSA_SUCCESS, &(test_partition_array[0]));

    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_ARGUMENT, gpt_entry_move_no_copy(
                &test_guid,
                TEST_GPT_FIRST_PARTITION_START,
                TEST_GPT_SECOND_PARTITION_END));

    /* Try to move the test entry into the middle of the entry just read.
     * Starting in the middle
     */
    expect_read_entry(PSA_SUCCESS, &(test_partition_array[0]));
    expect_read_entry(PSA_SUCCESS, test_entry);
    expect_read_entry(PSA_SUCCESS, &(test_partition_array[0]));

    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_ARGUMENT, gpt_entry_move_no_copy(
                &test_guid,
                TEST_GPT_FIRST_PARTITION_START + 1,
                TEST_GPT_SECOND_PARTITION_END));

    expect_read_entry(PSA_SUCCESS, &(test_partition_array[0]));
    expect_read_entry(PSA_SUCCESS, test_entry);

    expect_read_entry(PSA_SUCCESS, &(test_partition_array[0]));
    expect_read_entry(PSA_SUCCESS, test_entry);

    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_ARGUMENT, gpt_entry_move_no_copy(
                &test_guid,
                TEST_GPT_SECOND_PARTITION_START,
                TEST_GPT_THIRD_PARTITION_START));

    /* Try to move the test entry into the middle of the entry just read.
     * Starting and ending in the middle.
     */
    expect_read_entry(PSA_SUCCESS, &(test_partition_array[0]));
    expect_read_entry(PSA_SUCCESS, test_entry);
    expect_read_entry(PSA_SUCCESS, &(test_partition_array[0]));

    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_ARGUMENT, gpt_entry_move_no_copy(
                &test_guid,
                TEST_GPT_FIRST_PARTITION_START + 1,
                TEST_GPT_FIRST_PARTITION_START + 1));
}

void test_gpt_entry_move_no_copy_should_failWhenLbaOffDisk(void)
{
    setup_valid_gpt();
    expect_read_primary_gpt_only();

    /* Try to move an entry. */
    size_t test_index = 1;
    struct gpt_entry_t *test_entry = &(test_partition_array[test_index]);
    struct efi_guid_t test_guid = test_entry->unique_guid;

    /* First start on disk, then go off the disk */
    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_ARGUMENT, gpt_entry_move_no_copy(
                &test_guid,
                TEST_GPT_DISK_FREE_SPACE_START,
                TEST_DISK_NUM_BLOCKS + 1));

    /* Second, start off the disk entirely */
    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_ARGUMENT, gpt_entry_move_no_copy(
                &test_guid,
                TEST_DISK_NUM_BLOCKS + 1,
                TEST_DISK_NUM_BLOCKS + 2));

    /* Third, do the same but in the header area */
    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_ARGUMENT, gpt_entry_move_no_copy(
                &test_guid,
                TEST_GPT_PRIMARY_LBA,
                TEST_GPT_DISK_FREE_SPACE_START + 1));

    /* Fourth, start in the backup header area */
    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_ARGUMENT, gpt_entry_move_no_copy(
                &test_guid,
                TEST_GPT_BACKUP_LBA,
                TEST_GPT_BACKUP_LBA + 1));
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

void test_gpt_attr_set_should_setAttributes(void)
{
    /* Start with a populated GPT */
    setup_valid_gpt();
    expect_read_primary_gpt_only();

    /* First entry is read */
    expect_read_entry(PSA_SUCCESS, &(test_partition_array[0]));

    struct efi_guid_t guid = test_partition_array[0].unique_guid;
    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_attr_set(&guid, 0x1));
}

void test_gpt_attr_set_should_failWhenEntryNotExisting(void)
{
    setup_valid_gpt();
    expect_read_primary_gpt_only();

    /* Read every used entry */
    expect_read_used_entries(PSA_SUCCESS);

    struct efi_guid_t non_existing = NULL_GUID;
    TEST_ASSERT_EQUAL(PSA_ERROR_DOES_NOT_EXIST, gpt_attr_set(&non_existing, 0x1));
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

void test_gpt_attr_remove_should_removeAttributes(void)
{
    /* Start with a populated GPT */
    struct gpt_entry_t *test_entry = &(test_partition_array[0]);
    uint64_t test_attr = 0x1;
    test_entry->attr = test_attr;
    setup_valid_gpt();
    expect_read_primary_gpt_only();

    /* First entry is read */
    expect_read_entry(PSA_SUCCESS, test_entry);

    struct efi_guid_t test_guid = test_entry->unique_guid;
    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_attr_remove(&test_guid, test_attr));
}

void test_gpt_attr_remove_should_failWhenEntryNotExisting(void)
{
    setup_valid_gpt();
    expect_read_primary_gpt_only();

    /* Read every used entry */
    expect_read_used_entries(PSA_SUCCESS);

    struct efi_guid_t non_existing = NULL_GUID;
    TEST_ASSERT_EQUAL(PSA_ERROR_DOES_NOT_EXIST, gpt_attr_remove(&non_existing, 0x1));
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

void test_gpt_attr_add_should_addAttributes(void)
{
    /* Start with a populated GPT */
    struct gpt_entry_t *test_entry = &(test_partition_array[0]);
    setup_valid_gpt();
    expect_read_primary_gpt_only();

    /* First entry is read */
    expect_read_entry(PSA_SUCCESS, test_entry);

    struct efi_guid_t test_guid = test_entry->unique_guid;
    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_attr_add(&test_guid, 0x1));
}

void test_gpt_attr_add_should_failWhenEntryNotExisting(void)
{
    setup_valid_gpt();
    expect_read_primary_gpt_only();

    /* Read every used entry */
    expect_read_used_entries(PSA_SUCCESS);

    struct efi_guid_t non_existing = NULL_GUID;
    TEST_ASSERT_EQUAL(PSA_ERROR_DOES_NOT_EXIST, gpt_attr_add(&non_existing, 0x1));
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

void test_gpt_entry_change_type_should_setNewType(void)
{
    /* Start with a populated GPT */
    struct gpt_entry_t *test_entry = &(test_partition_array[0]);
    setup_valid_gpt();
    expect_read_primary_gpt_only();

    /* First entry is read */
    expect_read_entry(PSA_SUCCESS, test_entry);

    struct efi_guid_t test_guid = test_entry->unique_guid;

    /* Type validation is not a function of the library, as this is OS
     * dependent, so anything will do here.
     */
    struct efi_guid_t new_type = TEST_GPT_VALID_TYPE(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11);
    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_entry_change_type(&test_guid, &new_type));
}

void test_gpt_entry_change_type_should_failWhenEntryNotExisting(void)
{
    setup_valid_gpt();
    expect_read_primary_gpt_only();

    /* Read every used entry */
    expect_read_used_entries(PSA_SUCCESS);

    struct efi_guid_t non_existing = NULL_GUID;
    struct efi_guid_t new_type = TEST_GPT_VALID_TYPE(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11);
    TEST_ASSERT_EQUAL(PSA_ERROR_DOES_NOT_EXIST, gpt_entry_change_type(&non_existing, &new_type));
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

void test_gpt_entry_change_type_should_failWhenSettingTypeToNullGuid(void)
{
    setup_valid_gpt();

    struct efi_guid_t test_guid = test_partition_array[0].unique_guid;
    struct efi_guid_t new_type = NULL_GUID;

    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_ARGUMENT, gpt_entry_change_type(&test_guid, &new_type));
}
void test_gpt_entry_rename_should_renameEntry(void)
{
    /* Start with a populated GPT */
    struct gpt_entry_t *test_entry = &(test_partition_array[0]);
    setup_valid_gpt();
    expect_read_primary_gpt_only();

    /* First entry is read */
    expect_read_entry(PSA_SUCCESS, test_entry);

    char new_name[GPT_ENTRY_NAME_LENGTH] = {'\0'};
    new_name[0] = 'a';
    struct efi_guid_t test_guid = test_entry->unique_guid;
    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_entry_rename(&test_guid, new_name));
}

void test_gpt_entry_rename_should_failWhenNameIsEmpty(void)
{
    /* Start with a populated GPT */
    setup_valid_gpt();

    /* Try to change name to an empty string */
    struct efi_guid_t test_guid = test_partition_array[0].unique_guid;
    char name[GPT_ENTRY_NAME_LENGTH] = {'\0'};
    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_ARGUMENT, gpt_entry_rename(&test_guid, name));
}

void test_gpt_entry_rename_should_failWhenEntryNotExisting(void)
{
    setup_valid_gpt();
    expect_read_primary_gpt_only();

    /* Read every used entry */
    expect_read_used_entries(PSA_SUCCESS);

    struct efi_guid_t non_existing = NULL_GUID;
    char new_name[GPT_ENTRY_NAME_LENGTH] = {'\0'};
    new_name[0] = 'a';
    TEST_ASSERT_EQUAL(PSA_ERROR_DOES_NOT_EXIST, gpt_entry_rename(&non_existing, new_name));
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
void test_gpt_entry_remove_should_removeEntry(void)
{
    /* Start with a populated GPT */
    setup_valid_gpt();
    expect_read_primary_gpt_only();

    /* Each used entry is read to find the target */
    expect_read_used_entries(PSA_SUCCESS);

    struct gpt_entry_t *test_entry = &(test_partition_array[TEST_DEFAULT_NUM_PARTITIONS - 1]);
    struct efi_guid_t test_guid = test_entry->unique_guid;

    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_entry_remove(&test_guid));
}

void test_gpt_entry_remove_should_failWhenEntryNotExisting(void)
{
    /* Start by trying to remove from an empty table */
    setup_empty_gpt();
    expect_read_primary_gpt(PSA_SUCCESS);

    struct efi_guid_t non_existing = NULL_GUID;
    TEST_ASSERT_EQUAL(PSA_ERROR_DOES_NOT_EXIST, gpt_entry_remove(&non_existing));

    /* Now, have a non-empty GPT but search for a non-existing GUID */
    test_primary_gpt.header.num_partitions = default_header.num_partitions;
    setup_valid_gpt();
    expect_read_primary_gpt_only();

    /* Each used entry should be read. */
    expect_read_used_entries(PSA_SUCCESS);
    TEST_ASSERT_EQUAL(PSA_ERROR_DOES_NOT_EXIST, gpt_entry_remove(&non_existing));
}

void test_gpt_entry_read_should_populateEntry(void)
{
    /* Start with a populated GPT */
    setup_valid_gpt();
    expect_read_primary_gpt_only();

    /* Ensure an entry is found */
    struct partition_entry_t entry;
    struct gpt_entry_t *desired = &(test_partition_array[TEST_DEFAULT_NUM_PARTITIONS - 1]);
    struct efi_guid_t test_guid = desired->unique_guid;
    struct efi_guid_t test_type = desired->partition_type;
    expect_read_used_entries(PSA_SUCCESS);
    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_entry_read(&test_guid, &entry));

    /* Ensure this is the correct entry */
    TEST_ASSERT_EQUAL(0, efi_guid_cmp(&test_guid, &(entry.partition_guid)));
    TEST_ASSERT_EQUAL(0, efi_guid_cmp(&test_type, &(entry.type_guid)));
    TEST_ASSERT_EQUAL(desired->start, entry.start);

    /* Size is number of blocks, so subtract one */
    TEST_ASSERT_EQUAL(desired->end, entry.start + entry.size - 1);

    /* Name is unicode */
    TEST_ASSERT_EQUAL_MEMORY(desired->name, entry.name, GPT_ENTRY_NAME_LENGTH);
}

void test_gpt_entry_read_should_failWhenEntryNotExisting(void)
{
    /* Start with an empty GPT */
    setup_empty_gpt();
    expect_read_primary_gpt(PSA_SUCCESS);

    /* Try to read something */
    struct partition_entry_t entry;
    struct efi_guid_t non_existing = NULL_GUID;
    TEST_ASSERT_EQUAL(PSA_ERROR_DOES_NOT_EXIST, gpt_entry_read(&non_existing, &entry));

    /* Now, have a non-empty GPT but search for a non-existing GUID */
    test_primary_gpt.header.num_partitions = default_header.num_partitions;
    setup_valid_gpt();
    expect_read_primary_gpt_only();

    /* Each used entry should be read */
    expect_read_used_entries(PSA_SUCCESS);
    TEST_ASSERT_EQUAL(PSA_ERROR_DOES_NOT_EXIST, gpt_entry_read(&non_existing, &entry));
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

void test_gpt_entry_read_by_name_should_populateEntry(void)
{
    /* Start with a populated GPT */
    setup_valid_gpt();
    expect_read_primary_gpt_only();

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

    expect_read_entry(PSA_SUCCESS, desired1);
    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_entry_read_by_name(desired1->name, 0, &entry));

    /* Ensure this is the correct entry */
    TEST_ASSERT_EQUAL(0, efi_guid_cmp(&test_guid1, &(entry.partition_guid)));
    TEST_ASSERT_EQUAL(0, efi_guid_cmp(&test_type1, &(entry.type_guid)));
    TEST_ASSERT_EQUAL(desired1->start, entry.start);
    TEST_ASSERT_EQUAL(desired1->end, entry.start + entry.size - 1);

    TEST_ASSERT_EQUAL_MEMORY(desired1->name, entry.name, GPT_ENTRY_NAME_LENGTH);

    /* Do again but the next entry */
    expect_read_entry(PSA_SUCCESS, desired1);
    expect_read_entry(PSA_SUCCESS, desired2);
    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_entry_read_by_name(desired1->name, 1, &entry));

    /* Ensure this is the correct entry */
    TEST_ASSERT_EQUAL(0, efi_guid_cmp(&test_guid2, &(entry.partition_guid)));
    TEST_ASSERT_EQUAL(0, efi_guid_cmp(&test_type2, &(entry.type_guid)));
    TEST_ASSERT_EQUAL(desired2->start, entry.start);
    TEST_ASSERT_EQUAL(desired2->end, entry.start + entry.size - 1);

    TEST_ASSERT_EQUAL_MEMORY(desired2->name, entry.name, GPT_ENTRY_NAME_LENGTH);
}

void test_gpt_entry_read_by_name_should_failWhenEntryNotExisting(void)
{
    /* Start with an empty GPT */
    setup_empty_gpt();
    expect_read_primary_gpt(PSA_SUCCESS);

    /* Try to read something */
    struct partition_entry_t entry;
    char test_name[GPT_ENTRY_NAME_LENGTH] = {'\0'};
    TEST_ASSERT_EQUAL(PSA_ERROR_DOES_NOT_EXIST, gpt_entry_read_by_name(test_name, 0, &entry));

    /* Now, have a non-empty GPT but search for a name that won't exist */
    test_primary_gpt.header.num_partitions = default_header.num_partitions;
    setup_valid_gpt();
    expect_read_primary_gpt_only();

    /* Each used entry should be read */
    expect_read_used_entries(PSA_SUCCESS);
    TEST_ASSERT_EQUAL(PSA_ERROR_DOES_NOT_EXIST, gpt_entry_read_by_name(test_name, 0, &entry));

    /* Finally, search for the second entry of a name that appears only once */
    memcpy(test_name, test_partition_array[0].name, GPT_ENTRY_NAME_LENGTH);
    expect_read_used_entries(PSA_SUCCESS);
    TEST_ASSERT_EQUAL(PSA_ERROR_DOES_NOT_EXIST, gpt_entry_read_by_name(test_name, 1, &entry));
    expect_read_used_entries(PSA_SUCCESS);
    TEST_ASSERT_EQUAL(PSA_ERROR_DOES_NOT_EXIST, gpt_entry_read_by_name(
                test_name,
                TEST_DEFAULT_NUM_PARTITIONS,
                &entry));
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

void test_gpt_entry_read_by_type_should_populateEntry(void)
{
    /* Start with a populated GPT */
    setup_valid_gpt();
    expect_read_primary_gpt_only();

    /* Ensure an entry is found, even with repeat types */
    struct partition_entry_t entry;
    struct gpt_entry_t *desired1 = &(test_partition_array[0]);
    struct efi_guid_t test_guid1 = desired1->unique_guid;
    struct efi_guid_t test_type1 = desired1->partition_type;

    struct gpt_entry_t *desired2 = &(test_partition_array[1]);
    struct efi_guid_t test_guid2 = desired2->unique_guid;
    struct efi_guid_t test_type2 = test_type1;
    desired2->partition_type = test_type2;

    expect_read_entry(PSA_SUCCESS, desired1);
    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_entry_read_by_type(&test_type1, 0, &entry));

    /* Ensure this is the correct entry */
    TEST_ASSERT_EQUAL(0, efi_guid_cmp(&test_guid1, &(entry.partition_guid)));
    TEST_ASSERT_EQUAL(0, efi_guid_cmp(&test_type1, &(entry.type_guid)));
    TEST_ASSERT_EQUAL(desired1->start, entry.start);
    TEST_ASSERT_EQUAL(desired1->end, entry.start + entry.size - 1);

    /* Name is unicode */
    TEST_ASSERT_EQUAL_MEMORY(desired1->name, entry.name, GPT_ENTRY_NAME_LENGTH);

    /* Do again but the next entry */
    expect_read_entry(PSA_SUCCESS, desired1);
    expect_read_entry(PSA_SUCCESS, desired2);
    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_entry_read_by_type(&test_type1, 1, &entry));

    /* Ensure this is the correct entry */
    TEST_ASSERT_EQUAL(0, efi_guid_cmp(&test_guid2, &(entry.partition_guid)));
    TEST_ASSERT_EQUAL(0, efi_guid_cmp(&test_type2, &(entry.type_guid)));
    TEST_ASSERT_EQUAL(desired2->start, entry.start);
    TEST_ASSERT_EQUAL(desired2->end, entry.start + entry.size - 1);

    TEST_ASSERT_EQUAL_MEMORY(desired2->name, entry.name, GPT_ENTRY_NAME_LENGTH);
}

void test_gpt_entry_read_by_type_should_failWhenEntryNotExisting(void)
{
    /* Start with an empty GPT */
    setup_empty_gpt();
    expect_read_primary_gpt(PSA_SUCCESS);

    /* Try to read something */
    struct partition_entry_t entry;
    struct efi_guid_t test_type = TEST_GPT_VALID_TYPE(11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1);
    TEST_ASSERT_EQUAL(PSA_ERROR_DOES_NOT_EXIST, gpt_entry_read_by_type(&test_type, 0, &entry));

    /* Now, have a non-empty GPT but search for a type that won't exist */
    test_primary_gpt.header.num_partitions = default_header.num_partitions;
    setup_valid_gpt();
    expect_read_primary_gpt_only();

    /* Each used entry should be read */
    expect_read_used_entries(PSA_SUCCESS);
    TEST_ASSERT_EQUAL(PSA_ERROR_DOES_NOT_EXIST, gpt_entry_read_by_type(&test_type, 0, &entry));

    /* Finally, search for the second entry of a type that appears only once */
    test_type = test_partition_array[0].partition_type;
    expect_read_used_entries(PSA_SUCCESS);
    TEST_ASSERT_EQUAL(PSA_ERROR_DOES_NOT_EXIST, gpt_entry_read_by_type(&test_type, 1, &entry));
    expect_read_used_entries(PSA_SUCCESS);
    TEST_ASSERT_EQUAL(PSA_ERROR_DOES_NOT_EXIST, gpt_entry_read_by_type(
                &test_type,
                TEST_DEFAULT_NUM_PARTITIONS,
                &entry));
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
