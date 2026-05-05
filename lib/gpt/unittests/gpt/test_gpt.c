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

/* Basic mocked disk layout and number of partitions */
#define TEST_BLOCK_SIZE 512
#define TEST_DISK_NUM_BLOCKS 128
#define TEST_MAX_PARTITIONS 4
#define TEST_DEFAULT_NUM_PARTITIONS TEST_MAX_PARTITIONS - 1

/* Maximum number of mocked reads per test */
#define TEST_MOCK_BUFFER_SIZE 512

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

/* MBR partition entry */
struct mbr_entry_t {
    /* Indicates if bootable */
    uint8_t status;
    /* For legacy MBR, not used by UEFI firmware. For protective MBR, set to
     * 0x000200
     */
    uint8_t first_sector[TEST_MBR_CHS_ADDRESS_LEN];
    /* Type of partition */
    uint8_t os_type;
    /* For legacy MBR, not used by UEFI firmware. For protective MBR, last
     * block on disk.
     */
    uint8_t last_sector[TEST_MBR_CHS_ADDRESS_LEN];
    /* For legacy MBR, starting LBA of partition. For protective MBR, set to
     * 0x00000001
     */
    uint32_t first_lba;
    /* For legacy MBR, size of partition. For protective MBR, size of disk
     * minus one
     */
    uint32_t size;
} __attribute__((packed));

/* Master Boot Record. */
struct mbr_t {
    /* Unused bytes */
    uint8_t unused[TEST_MBR_UNUSED_BYTES];
    /* Array of four MBR partition records. For protective MBR, only the first
     * is valid
     */
    struct mbr_entry_t partitions[TEST_MBR_NUM_PARTITIONS];
    /* 0xAA55 */
    uint16_t sig;
} __attribute__((packed));

/* A gpt partition entry */
struct gpt_entry_t {
    struct efi_guid_t type;             /* Partition type */
    struct efi_guid_t guid;             /* Unique GUID */
    uint64_t start;                     /* Starting LBA for partition */
    uint64_t end;                       /* Ending LBA for partition */
    uint64_t attr;                      /* Attribute bits */
    char name[GPT_ENTRY_NAME_LENGTH];   /* Human readable name for partition */
} __attribute__((packed));

/* The gpt header */
struct gpt_header_t {
    char signature[TEST_GPT_SIG_LEN];   /* "EFI PART" */
    uint32_t revision;                  /* Revision number. */
    uint32_t size;                      /* Size of this header */
    uint32_t header_crc;                /* CRC of this header */
    uint32_t reserved;                  /* Reserved */
    uint64_t current_lba;               /* LBA of this header */
    uint64_t backup_lba;                /* LBA of backup GPT header */
    uint64_t first_lba;                 /* First usable LBA */
    uint64_t last_lba;                  /* Last usable LBA */
    struct efi_guid_t disk_guid;        /* Disk GUID */
    uint64_t array_lba;                 /* First LBA of array of partition entries */
    uint32_t num_partitions;            /* Number of partition entries in array */
    uint32_t entry_size;                /* Size of a single partition entry */
    uint32_t array_crc;                 /* CRC of partition entry array */
} __attribute__((packed));

static void register_mocked_read(void *buf, size_t num_bytes);
static ssize_t test_driver_read(uint64_t lba, void *buf);
static ssize_t test_driver_write(uint64_t lba, const void *buf);
static ssize_t test_driver_erase(uint64_t lba, size_t num_blocks);

/* LBA driver used in test module */
static struct gpt_flash_driver_t mock_driver = {
    .init = NULL,
    .uninit = NULL,
    .read = test_driver_read,
    .write = test_driver_write,
    .erase = test_driver_erase,
};

/* Valid MBR. Only signature is required to be valid */
static struct mbr_t default_mbr = {
    .unused = {0},
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
    .disk_guid = TEST_GPT_DISK_GUID,
    .array_lba = TEST_GPT_ARRAY_LBA,
    .num_partitions = TEST_MAX_PARTITIONS,
    .entry_size = TEST_GPT_ENTRY_SIZE,
    .array_crc = TEST_GPT_CRC32
};
static struct gpt_header_t test_header;

/* Default entry array. This is valid, though fragmented. */
static struct gpt_entry_t default_partition_array[TEST_DEFAULT_NUM_PARTITIONS] = {
    {
        .type = TEST_GPT_VALID_TYPE(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11),
        .guid = TEST_GPT_VALID_GUID(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11),
        .start = TEST_GPT_FIRST_PARTITION_START,
        .end = TEST_GPT_FIRST_PARTITION_END,
        .attr = 0,
        .name = "First partition"
    },
    {
        .type = TEST_GPT_VALID_TYPE(2, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11),
        .guid = TEST_GPT_VALID_GUID(2, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11),
        .start = TEST_GPT_SECOND_PARTITION_START,
        .end = TEST_GPT_SECOND_PARTITION_END,
        .attr = 0,
        .name = "Second partition"
    },
    {
        .type = TEST_GPT_VALID_TYPE(3, 3, 3, 4, 5, 6, 7, 8, 9, 10, 11),
        .guid = TEST_GPT_VALID_GUID(3, 3, 3, 4, 5, 6, 7, 8, 9, 10, 11),
        .start = TEST_GPT_THIRD_PARTITION_START,
        .end = TEST_GPT_THIRD_PARTITION_END,
        .attr = 0,
        .name = "Third partition"
    }
};
static struct gpt_entry_t test_partition_array[TEST_MAX_PARTITIONS];

/* Set to determine what is "read" by the flash driver. Allows for the mocking
 * of multiple read calls
 */
static unsigned int num_mocked_reads = 0;
static unsigned int registered_mocked_reads = 0;
static uint8_t mock_read_buffer[TEST_MOCK_BUFFER_SIZE][TEST_BLOCK_SIZE] = {0};

/* Turn ascii string to unicode */
static void ascii_to_unicode(const char *ascii, char *unicode)
{
    for (int i = 0; i < strlen(ascii) + 1; ++i) {
        unicode[i << 1] = ascii[i];
        unicode[(i << 1) + 1] = '\0';
    }
}

/* Tell the test what to return from the next read call. This is very much
 * whitebox testing
 */
static void register_mocked_read(void *data, size_t num_bytes)
{
    memcpy(mock_read_buffer[registered_mocked_reads++], data, num_bytes);
}

/* Driver function that always succeeds in reading the data it has been given */
static ssize_t test_driver_read(uint64_t lba, void *buf)
{
    memcpy(buf, mock_read_buffer[num_mocked_reads++], TEST_BLOCK_SIZE);
    return TEST_BLOCK_SIZE;
}

/* Driver function that always succeeds in writing all data */
static ssize_t test_driver_write(uint64_t lba, const void *buf)
{
    return TEST_BLOCK_SIZE;
}

static ssize_t test_driver_erase(uint64_t lba, size_t num_blocks)
{
    return num_blocks;
}

/* Creates backup table from test table and registers a read for it */
static void setup_backup_gpt(void)
{
    struct gpt_header_t backup_header;
    MAKE_BACKUP_HEADER(backup_header, test_header);

    register_mocked_read(&backup_header, sizeof(backup_header));
}

/* Uses the test MBR and GPT header to initialise for tests */
static psa_status_t setup_test_gpt(void)
{
    /* Expect first a valid MBR read */
    register_mocked_read(&test_mbr, sizeof(test_mbr));

    /* Expect a GPT header read second */
    register_mocked_read(&test_header, sizeof(test_header));

    /* Expect third each partition is read to find the number in use (if the
     * number in the header is non-zero)
     */
    if (test_header.num_partitions != 0) {
        register_mocked_read(&test_partition_array, sizeof(test_partition_array));
    }

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
    test_header.num_partitions = 0;
    TEST_ASSERT_EQUAL(PSA_SUCCESS, setup_test_gpt());
}

void setUp(void)
{
    /* Default starting points */
    test_mbr = default_mbr;
    test_header = default_header;
    memcpy(&test_partition_array, &default_partition_array, sizeof(default_partition_array));
    for (size_t i = 0; i < TEST_DEFAULT_NUM_PARTITIONS; ++i) {
        char unicode_name[GPT_ENTRY_NAME_LENGTH] = {'\0'};
        ascii_to_unicode(test_partition_array[i].name, unicode_name);
        memcpy(test_partition_array[i].name, unicode_name, GPT_ENTRY_NAME_LENGTH);
    }

    test_mbr.partitions[0].os_type = TEST_MBR_TYPE_GPT;

    /* Any time this is called, return the same number and ignore the arguments */
    efi_soft_crc32_update_IgnoreAndReturn(test_header.header_crc);

    num_mocked_reads = 0;
    registered_mocked_reads = 0;
    memset(mock_read_buffer, 0, sizeof(mock_read_buffer));
}

void tearDown(void)
{
    num_mocked_reads = 0;
    registered_mocked_reads = 0;
    memset(mock_read_buffer, 0, sizeof(mock_read_buffer));
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

    /* Use a different disk GUID */
    const struct efi_guid_t new_guid = TEST_GPT_VALID_GUID(1, 1, 3, 4, 5, 6, 7 ,8, 9, 10, 11);
    test_header.disk_guid = new_guid;

    setup_valid_gpt();
}

void test_gpt_init_should_acceptPrimaryArrayLbaNotTwo(void)
{
    test_header.array_lba++;
    setup_valid_gpt();
}

void test_gpt_init_should_failWhenMbrSigBad(void)
{
    test_mbr.sig--;
    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_ARGUMENT, setup_test_gpt());
}

void test_gpt_init_should_failWhenMbrTypeInvalid(void)
{
    test_mbr.partitions[0].os_type--;
    TEST_ASSERT_EQUAL(PSA_ERROR_NOT_SUPPORTED, setup_test_gpt());
}

void test_gpt_init_should_failWhenEntrySizeBad(void)
{
    test_header.entry_size--;
    /* Expect first a valid MBR read */
    register_mocked_read(&test_mbr, sizeof(test_mbr));

    /* Expect a GPT header read second */
    register_mocked_read(&test_header, sizeof(test_header));

    TEST_ASSERT_EQUAL(PSA_ERROR_NOT_SUPPORTED, gpt_init(&mock_driver, TEST_MAX_PARTITIONS));
    test_header.entry_size = default_header.entry_size;

    /* Now do the backup. */
    register_mocked_read(&test_mbr, sizeof(test_mbr));
    register_mocked_read(&test_header, sizeof(test_header));
    register_mocked_read(&test_partition_array, sizeof(test_partition_array));

    /* Expect fourth the backup to be read. Make the entry size bad */
    test_header.entry_size = 0;
    setup_backup_gpt();

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
    register_mocked_read(&test_partition_array, sizeof(test_partition_array));

    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_validate(true));

    /* Now do the backup */
    setup_backup_gpt();
    register_mocked_read(&test_partition_array, sizeof(test_partition_array));

    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_validate(false));
}

void test_gpt_validate_should_failWhenGptSigBad(void)
{
    test_header.signature[0] = '\0';
    setup_test_gpt();

    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_SIGNATURE, gpt_validate(true));

    /* Now do the backup */
    setup_backup_gpt();
    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_SIGNATURE, gpt_validate(false));
}

void test_gpt_validate_should_failWhenHeaderCrcBad(void)
{
    test_header.header_crc--;
    setup_test_gpt();
    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_SIGNATURE, gpt_validate(true));

    /* Now do the backup */
    struct gpt_header_t backup_header;
    MAKE_BACKUP_HEADER(backup_header, test_header);
    backup_header.header_crc--;
    register_mocked_read(&backup_header, sizeof(backup_header));

    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_SIGNATURE, gpt_validate(false));
}

void test_gpt_validate_should_failWhenLbaPointerBad(void)
{
    test_header.current_lba = 2;
    test_header.backup_lba = 3;
    setup_test_gpt();
    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_SIGNATURE, gpt_validate(true));

    /* Now set the backup LBA to be something different that what it should be
     * to force a mismatch
     */
    test_header.current_lba = default_header.current_lba;
    test_header.backup_lba = default_header.backup_lba - 1;

    /* Now do the backup */
    struct gpt_header_t backup_header;
    MAKE_BACKUP_HEADER(backup_header, test_header);
    register_mocked_read(&backup_header, sizeof(backup_header));

    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_SIGNATURE, gpt_validate(false));
}

void test_gpt_validate_should_failWhenBackupEntrySizeInvalid(void)
{
    /* The entry size for the primary GPT is validated on gpt_init and kept
     * in memory. Therefore, the entry size can only be validated on gpt_validate
     * for the backup table, which is read
     */
    setup_test_gpt();
    struct gpt_header_t backup_header;
    MAKE_BACKUP_HEADER(backup_header, test_header);
    backup_header.entry_size--;
    register_mocked_read(&backup_header, sizeof(backup_header));
    register_mocked_read(&test_partition_array, sizeof(test_partition_array));

    TEST_ASSERT_EQUAL(PSA_ERROR_NOT_SUPPORTED, gpt_validate(false));
}

void test_gpt_validate_should_failWhenArrayCrcBad(void)
{
    test_header.array_crc--;
    setup_test_gpt();

    /* Each entry will be read in order to check the partition array CRC */
    register_mocked_read(&test_partition_array, sizeof(test_partition_array));

    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_SIGNATURE, gpt_validate(true));

    /* Now do the backup */
    struct gpt_header_t backup_header;
    MAKE_BACKUP_HEADER(backup_header, test_header);
    backup_header.array_crc--;
    register_mocked_read(&backup_header, sizeof(test_partition_array));
    register_mocked_read(&test_partition_array, sizeof(test_partition_array));

    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_SIGNATURE, gpt_validate(false));
}

void test_gpt_validate_should_failWhenBackupLbaNotAtEndOfDisk(void)
{
    /* First test when the backup lba is before usable disk */
    test_header.backup_lba = test_header.first_lba - 1;
    setup_test_gpt();

    /* Each entry will be read in order to check the partition array CRC */
    register_mocked_read(&test_partition_array, sizeof(test_partition_array));
    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_SIGNATURE, gpt_validate(true));

    /* Then test when the backup is before in usable disk space */
    test_header.backup_lba = test_header.first_lba;
    setup_test_gpt();
    register_mocked_read(&test_partition_array, sizeof(test_partition_array));
    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_SIGNATURE, gpt_validate(true));

    test_header.backup_lba = test_header.first_lba + 1;
    setup_test_gpt();
    register_mocked_read(&test_partition_array, sizeof(test_partition_array));
    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_SIGNATURE, gpt_validate(true));

    test_header.backup_lba = test_header.last_lba - 1;
    setup_test_gpt();
    register_mocked_read(&test_partition_array, sizeof(test_partition_array));
    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_SIGNATURE, gpt_validate(true));

    test_header.backup_lba = test_header.last_lba;
    setup_test_gpt();
    register_mocked_read(&test_partition_array, sizeof(test_partition_array));
    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_SIGNATURE, gpt_validate(true));

    /* Finally, test when the backup is before the end of the partition entry array */
    test_header.backup_lba = test_header.array_lba - 1;
    setup_test_gpt();
    register_mocked_read(&test_partition_array, sizeof(test_partition_array));
    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_SIGNATURE, gpt_validate(true));

    /* For this scenario, manually setup the backup header so that the array LBA
     * (also the backup header LBA) is valid on init and can then be validated
     * with gpt_validate
     */
    test_header.backup_lba = test_header.array_lba;

    /* Expect first a valid MBR read */
    register_mocked_read(&test_mbr, sizeof(test_mbr));

    /* Expect a GPT header read second */
    register_mocked_read(&test_header, sizeof(test_header));

    /* Expect third each partition is read to find the number in use. This is
     * also the backup header, which will be cached
     */
    setup_backup_gpt();

    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_init(&mock_driver, TEST_MAX_PARTITIONS));

    /* Backup partition array read for crc */
    register_mocked_read(&test_partition_array, sizeof(test_partition_array));
    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_SIGNATURE, gpt_validate(true));

    /* Now do the backup gpt header */
    struct gpt_header_t backup_header;
    test_header.backup_lba = test_header.first_lba - 1;
    MAKE_BACKUP_HEADER(backup_header, test_header);

    setup_test_gpt();
    register_mocked_read(&backup_header, sizeof(backup_header));
    register_mocked_read(&test_partition_array, sizeof(test_partition_array));
    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_SIGNATURE, gpt_validate(false));

    test_header.backup_lba = backup_header.first_lba;
    backup_header.current_lba = backup_header.first_lba;
    setup_test_gpt();
    register_mocked_read(&backup_header, sizeof(backup_header));
    register_mocked_read(&test_partition_array, sizeof(test_partition_array));
    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_SIGNATURE, gpt_validate(false));

    test_header.backup_lba = backup_header.first_lba + 1;
    backup_header.current_lba = backup_header.first_lba + 1;
    setup_test_gpt();
    register_mocked_read(&backup_header, sizeof(backup_header));
    register_mocked_read(&test_partition_array, sizeof(test_partition_array));
    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_SIGNATURE, gpt_validate(false));

    test_header.backup_lba = backup_header.last_lba - 1;
    backup_header.current_lba = backup_header.last_lba - 1;
    setup_test_gpt();
    register_mocked_read(&backup_header, sizeof(backup_header));
    register_mocked_read(&test_partition_array, sizeof(test_partition_array));
    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_SIGNATURE, gpt_validate(false));

    test_header.backup_lba = backup_header.last_lba;
    backup_header.current_lba = backup_header.last_lba;
    setup_test_gpt();
    register_mocked_read(&backup_header, sizeof(backup_header));
    register_mocked_read(&test_partition_array, sizeof(test_partition_array));
    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_SIGNATURE, gpt_validate(false));

    test_header.backup_lba = backup_header.array_lba - 1;
    backup_header.current_lba = backup_header.array_lba - 1;
    setup_test_gpt();
    register_mocked_read(&backup_header, sizeof(backup_header));
    register_mocked_read(&test_partition_array, sizeof(test_partition_array));
    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_SIGNATURE, gpt_validate(false));

    test_header.backup_lba = backup_header.array_lba;
    backup_header.current_lba = backup_header.array_lba;
    setup_test_gpt();
    register_mocked_read(&backup_header, sizeof(backup_header));
    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_SIGNATURE, gpt_validate(false));
}

void test_gpt_validate_should_failWhenPartitionArrayInUsableDiskSpace(void)
{
    /* First test when the primary partition array is in usable disk space */
    test_header.array_lba = test_header.first_lba;
    setup_test_gpt();

    /* Each entry will be read in order to check the partition array CRC */
    register_mocked_read(&test_partition_array, sizeof(test_partition_array));
    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_SIGNATURE, gpt_validate(true));

    test_header.array_lba = test_header.first_lba + 1;
    setup_test_gpt();
    register_mocked_read(&test_partition_array, sizeof(test_partition_array));
    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_SIGNATURE, gpt_validate(true));

    test_header.array_lba = test_header.last_lba - 1;
    setup_test_gpt();
    register_mocked_read(&test_partition_array, sizeof(test_partition_array));
    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_SIGNATURE, gpt_validate(true));

    test_header.array_lba = test_header.last_lba;
    setup_test_gpt();
    register_mocked_read(&test_partition_array, sizeof(test_partition_array));
    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_SIGNATURE, gpt_validate(true));

    /* Then test when the primary partition array is after usable disk space */
    test_header.array_lba = test_header.last_lba + 1;
    setup_test_gpt();
    register_mocked_read(&test_partition_array, sizeof(test_partition_array));
    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_SIGNATURE, gpt_validate(true));

    /* Now do the backup gpt header, ensuring it is always after usable space */
    struct gpt_header_t backup_header;
    MAKE_BACKUP_HEADER(backup_header, test_header);

    backup_header.array_lba = test_header.first_lba - 1;
    setup_test_gpt();
    register_mocked_read(&backup_header, sizeof(backup_header));
    register_mocked_read(&test_partition_array, sizeof(test_partition_array));
    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_SIGNATURE, gpt_validate(false));

    /* Then test that the backup partition array is after usable disk space */
    backup_header.array_lba = test_header.first_lba;
    setup_test_gpt();
    register_mocked_read(&backup_header, sizeof(backup_header));
    register_mocked_read(&test_partition_array, sizeof(test_partition_array));
    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_SIGNATURE, gpt_validate(false));

    backup_header.array_lba = test_header.first_lba + 1;
    setup_test_gpt();
    register_mocked_read(&backup_header, sizeof(backup_header));
    register_mocked_read(&test_partition_array, sizeof(test_partition_array));
    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_SIGNATURE, gpt_validate(false));

    backup_header.array_lba = test_header.last_lba - 1;
    setup_test_gpt();
    register_mocked_read(&backup_header, sizeof(backup_header));
    register_mocked_read(&test_partition_array, sizeof(test_partition_array));
    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_SIGNATURE, gpt_validate(false));

    backup_header.array_lba = test_header.last_lba;
    setup_test_gpt();
    register_mocked_read(&backup_header, sizeof(backup_header));
    register_mocked_read(&test_partition_array, sizeof(test_partition_array));
    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_SIGNATURE, gpt_validate(false));
}

void test_gpt_restore_should_restorePrimaryFromBackup(void)
{
    /* Start with a valid GPT */
    setup_valid_gpt();

    /* The backup table is read and checked for validity, including taking
     * CRC32 of partition array
     */
    setup_backup_gpt();
    register_mocked_read(&test_partition_array, sizeof(test_partition_array));

    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_restore(true));
}

void test_gpt_restore_should_failToRestoreWhenBackupIsBad(void)
{
    /* Start with a valid GPT */
    setup_valid_gpt();

    /* The backup table is read and checked for validity. Corrupt it in
     * various ways
     */
    struct gpt_header_t backup_header;

    /* Bad signature */
    MAKE_BACKUP_HEADER(backup_header, test_header);
    backup_header.signature[0] = '\0';
    register_mocked_read(&backup_header, sizeof(backup_header));
    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_SIGNATURE, gpt_restore(true));

    /* Bad header CRC */
    MAKE_BACKUP_HEADER(backup_header, test_header);
    backup_header.header_crc = 0;
    register_mocked_read(&backup_header, sizeof(backup_header));
    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_SIGNATURE, gpt_restore(true));

    /* Bad LBA */
    test_header.backup_lba = 2;
    MAKE_BACKUP_HEADER(backup_header, test_header);
    register_mocked_read(&backup_header, sizeof(backup_header));
    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_SIGNATURE, gpt_restore(true));
    test_header.backup_lba = default_header.backup_lba;

    /* Bad array CRC. Will involve reading array entries */
    MAKE_BACKUP_HEADER(backup_header, test_header);
    backup_header.array_crc = 0;
    register_mocked_read(&backup_header, sizeof(backup_header));
    register_mocked_read(&test_partition_array, sizeof(test_partition_array));
    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_SIGNATURE, gpt_restore(true));
}

void test_gpt_defragment_should_succeedWhenNoIOFailure(void)
{
    setup_valid_gpt();

    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_defragment());
}

void test_gpt_entry_duplicate_should_DuplicateOldEntry(void)
{
    /* Duplicate an entry. It must not overlap with an existing entry and must also
     * fit on the storage device. The GUID should be populated with something.
     */
    setup_valid_gpt();
    struct gpt_entry_t *old_entry = &(test_partition_array[0]);
    struct efi_guid_t old_guid = old_entry->guid;

    /* Each entry will be read to find the entry to be duplicated. */
    register_mocked_read(&test_partition_array, sizeof(test_partition_array));

    /* The partition data is moved: this means reading each block then writing.
     * It doesn't matter what the data is
     */
    char unused_read_data = 'X';

    register_mocked_read(&unused_read_data, sizeof(unused_read_data));

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
    struct efi_guid_t old_guid = old_entry->guid;

    /* Each entry will be read to find the entry to be duplicated. */
    register_mocked_read(&test_partition_array, sizeof(test_partition_array));

    /* The partition data is moved: this means reading each block then writing.
     * It doesn't matter what the data is
     */
    char unused_read_data = 'X';

    register_mocked_read(&unused_read_data, sizeof(unused_read_data));

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
    struct efi_guid_t old_guid = old_entry->guid;

    setup_valid_gpt();

    /* Each entry will be read to find the entry to be duplicated. */
    register_mocked_read(&test_partition_array, sizeof(test_partition_array));

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

    /* Each entry will be read to find the entry to be duplicated. */
    register_mocked_read(&test_partition_array, sizeof(test_partition_array));

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
    struct efi_guid_t old_guid = old_entry->guid;
    struct efi_guid_t new_guid;

    /* Each entry will be read to find the entry to be duplicated. */
    register_mocked_read(&test_partition_array, sizeof(test_partition_array));

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
}

void test_gpt_entry_duplicate_should_failWhenTableFull(void)
{
    /* Start with a full array of entries */
    const uint64_t new_entry_end = TEST_GPT_DISK_FREE_SPACE_START;
    struct gpt_entry_t new_entry = {
        .type = TEST_GPT_VALID_TYPE(4, 4, 4, 4, 5, 6, 7, 8, 9, 10, 11),
        .start = new_entry_end,
        .end = new_entry_end,
        .attr = 0,
        .guid = TEST_GPT_VALID_GUID(4, 4, 4, 4, 5, 6, 7, 8, 9, 10, 11),
        .name = "Fourth partition"
    };
    test_partition_array[TEST_MAX_PARTITIONS - 1] = new_entry;
    setup_valid_gpt();

    struct gpt_entry_t *old_entry = &(test_partition_array[0]);
    struct efi_guid_t old_guid = old_entry->guid;
    struct efi_guid_t new_guid;

    /* Each entry will be read to find the entry to be duplicated. */
    register_mocked_read(&test_partition_array, sizeof(test_partition_array));

    TEST_ASSERT_EQUAL(PSA_ERROR_INSUFFICIENT_STORAGE, gpt_entry_duplicate(
                &old_guid,
                new_entry_end + 1,
                &new_guid));
}

void test_gpt_entry_duplicate_no_copy_should_DuplicateOldEntry(void)
{
    /* Duplicate an entry. It must not overlap with an existing entry and must also
     * fit on the storage device. The GUID should be populated with something.
     */
    setup_valid_gpt();
    struct gpt_entry_t *old_entry = &(test_partition_array[0]);
    struct efi_guid_t old_guid = old_entry->guid;

    /* Each entry will be read to find the entry to be duplicated. */
    register_mocked_read(&test_partition_array, sizeof(test_partition_array));

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
    struct efi_guid_t old_guid = old_entry->guid;

    /* Each entry will be read to find the entry to be duplicated. */
    register_mocked_read(&test_partition_array, sizeof(test_partition_array));

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
    struct efi_guid_t old_guid = old_entry->guid;

    setup_valid_gpt();

    /* Each entry will be read to find the entry to be duplicated. */
    register_mocked_read(&test_partition_array, sizeof(test_partition_array));

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

    /* Each entry will be read to find the entry to be duplicated. */
    register_mocked_read(&test_partition_array, sizeof(test_partition_array));

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
    struct efi_guid_t old_guid = old_entry->guid;
    struct efi_guid_t new_guid;

    /* Each entry will be read to find the entry to be duplicated. */
    register_mocked_read(&test_partition_array, sizeof(test_partition_array));

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
}

void test_gpt_entry_duplicate_no_copy_should_failWhenTableFull(void)
{
    /* Start with a full array of entries */
    const uint64_t new_entry_end = TEST_GPT_DISK_FREE_SPACE_START;
    struct gpt_entry_t new_entry = {
        .type = TEST_GPT_VALID_TYPE(4, 4, 4, 4, 5, 6, 7, 8, 9, 10, 11),
        .start = new_entry_end,
        .end = new_entry_end,
        .attr = 0,
        .guid = TEST_GPT_VALID_GUID(4, 4, 4, 4, 5, 6, 7, 8, 9, 10, 11),
        .name = "Fourth partition"
    };
    test_partition_array[TEST_MAX_PARTITIONS - 1] = new_entry;
    setup_valid_gpt();

    struct gpt_entry_t *old_entry = &(test_partition_array[0]);
    struct efi_guid_t old_guid = old_entry->guid;
    struct efi_guid_t new_guid;

    /* Each entry will be read to find the entry to be duplicated. */
    register_mocked_read(&test_partition_array, sizeof(test_partition_array));

    TEST_ASSERT_EQUAL(PSA_ERROR_INSUFFICIENT_STORAGE, gpt_entry_duplicate_no_copy(
                &old_guid,
                new_entry_end + 1,
                &new_guid));
}

void test_gpt_entry_create_should_createNewEntry(void)
{
    /* Add an entry. It must not overlap with an existing entry and must also
     * fit on the storage device. The GUID should be populated with something.
     */
    setup_valid_gpt();

    /* Each entry will be read in order to check that it doesn't overlap with
     * any of them
     */
    register_mocked_read(&test_partition_array, sizeof(test_partition_array));

    /* Update header. Read each entry for CRC calculation. */
    struct gpt_entry_t new_entry = {
        .type = TEST_GPT_DUMMY_TYPE,
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

    /* Each entry will be read in order to check that it doesn't overlap with
     * any of them
     */
    register_mocked_read(&test_partition_array, sizeof(test_partition_array));

    /* Update header. Read each entry for CRC calculation. */
    struct gpt_entry_t new_entry = {
        .type = TEST_GPT_DUMMY_TYPE,
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

    /* Ensure also the that a new GUID is assigned */
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

    /* Each entry will be read in order to check that it doesn't overlap with
     * any of them
     */
    register_mocked_read(&test_partition_array, sizeof(test_partition_array));

    /* Ensure also the that a new GUID is assigned */
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
        .type = TEST_GPT_VALID_TYPE(4, 4, 4, 4, 5, 6, 7, 8, 9, 10, 11),
        .start = new_entry_end,
        .end = new_entry_end,
        .attr = 0,
        .guid = TEST_GPT_VALID_GUID(4, 4, 4, 4, 5, 6, 7, 8, 9, 10, 11),
        .name = "Fourth partition"
    };
    test_partition_array[TEST_MAX_PARTITIONS - 1] = new_entry;
    setup_valid_gpt();

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

    /* Since the disk is not fragmented by default, there are two test cases:
     *   1. start in the middle of a partition and end in the middle of a partition
     *   2. start in the middle of a partition and end in free space
     */
    register_mocked_read(&test_partition_array, sizeof(test_partition_array));
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

    register_mocked_read(&test_partition_array, sizeof(test_partition_array));
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

    struct efi_guid_t type = TEST_GPT_DUMMY_TYPE;
    struct gpt_entry_t new_entry = {
        .type = type,
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

void test_gpt_entry_move_should_moveEntry(void)
{
    /* Start with a populated GPT */
    setup_valid_gpt();
    struct gpt_entry_t *test_entry = &(test_partition_array[TEST_DEFAULT_NUM_PARTITIONS - 1]);
    struct efi_guid_t test_guid = test_entry->guid;

    /* First all entries are read to determine for overlap */
    register_mocked_read(&test_partition_array, sizeof(test_partition_array));

    /* Move the partition. Read each block to then write. It doesn't matter what
     * the data is
     */
    char unused_read_data = 'X';
    register_mocked_read(&unused_read_data, sizeof(unused_read_data));

    /* Header update - reads partition array to calculate crc32 and also then
     * reads the header to modify and write back
     */
    register_mocked_read(&test_partition_array, sizeof(test_partition_array));
    register_mocked_read(&test_header, sizeof(test_header));

    /* Do a valid move and resize in one */
    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_entry_move(
                &test_guid,
                TEST_GPT_DISK_FREE_SPACE_START,
                TEST_GPT_DISK_FREE_SPACE_START));
}

void test_gpt_entry_move_should_failWhenEntryNotExisting(void)
{
    setup_valid_gpt();

    /* Read every entry */
    register_mocked_read(&test_partition_array, sizeof(test_partition_array));

    struct efi_guid_t non_existing = NULL_GUID;
    TEST_ASSERT_EQUAL(PSA_ERROR_DOES_NOT_EXIST, gpt_entry_move(
                &non_existing,
                TEST_GPT_DISK_FREE_SPACE_START,
                TEST_GPT_DISK_FREE_SPACE_START));
}

void test_gpt_entry_move_should_failWhenEndLessThanStart(void)
{
    setup_valid_gpt();

    struct efi_guid_t test_guid = test_partition_array[0].guid;
    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_ARGUMENT, gpt_entry_move(
                &test_guid,
                TEST_GPT_DISK_FREE_SPACE_START + 1,
                TEST_GPT_DISK_FREE_SPACE_START));
}

void test_gpt_entry_move_should_failWhenLbaOverlapping(void)
{
    setup_valid_gpt();

    /* Try to move an entry. Each entry is read to determine for overlap */
    size_t test_index = 1;
    struct gpt_entry_t *test_entry = &(test_partition_array[test_index]);
    struct efi_guid_t test_guid = test_entry->guid;
    register_mocked_read(&test_partition_array, sizeof(test_partition_array));

    /* Try to move the test entry into the middle of the entry just read.
     * Starting at the same LBA
     */
    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_ARGUMENT, gpt_entry_move(
                &test_guid,
                TEST_GPT_FIRST_PARTITION_START,
                TEST_GPT_SECOND_PARTITION_END));

    /* Try to move the test entry into the middle of the entry just read.
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
}

void test_gpt_entry_move_should_failWhenLbaOffDisk(void)
{
    setup_valid_gpt();

    /* Try to move an entry. */
    size_t test_index = 1;
    struct gpt_entry_t *test_entry = &(test_partition_array[test_index]);
    struct efi_guid_t test_guid = test_entry->guid;

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

void test_gpt_entry_move_no_copy_should_moveEntry(void)
{
    /* Start with a populated GPT */
    setup_valid_gpt();
    struct gpt_entry_t *test_entry = &(test_partition_array[TEST_DEFAULT_NUM_PARTITIONS - 1]);
    struct efi_guid_t test_guid = test_entry->guid;

    /* First all entries are read to determine for overlap */
    register_mocked_read(&test_partition_array, sizeof(test_partition_array));

    /* Header update - reads partition array to calculate crc32 and also then
     * reads the header to modify and write back
     */
    register_mocked_read(&test_partition_array, sizeof(test_partition_array));
    register_mocked_read(&test_header, sizeof(test_header));

    /* Do a valid move and resize in one */
    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_entry_move_no_copy(
                &test_guid,
                TEST_GPT_DISK_FREE_SPACE_START,
                TEST_GPT_DISK_FREE_SPACE_START));
}

void test_gpt_entry_move_no_copy_should_failWhenEntryNotExisting(void)
{
    setup_valid_gpt();

    /* Read every entry */
    register_mocked_read(&test_partition_array, sizeof(test_partition_array));

    struct efi_guid_t non_existing = NULL_GUID;

    TEST_ASSERT_EQUAL(PSA_ERROR_DOES_NOT_EXIST, gpt_entry_move_no_copy(
                &non_existing,
                TEST_GPT_DISK_FREE_SPACE_START,
                TEST_GPT_DISK_FREE_SPACE_START));
}

void test_gpt_entry_move_no_copy_should_failWhenEndLessThanStart(void)
{
    setup_valid_gpt();

    struct efi_guid_t test_guid = test_partition_array[0].guid;

    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_ARGUMENT, gpt_entry_move_no_copy(
                &test_guid,
                TEST_GPT_DISK_FREE_SPACE_START + 1,
                TEST_GPT_DISK_FREE_SPACE_START));
}

void test_gpt_entry_move_no_copy_should_failWhenLbaOverlapping(void)
{
    setup_valid_gpt();

    /* Try to move an entry. Each entry is read to determine for overlap */
    size_t test_index = 1;
    struct gpt_entry_t *test_entry = &(test_partition_array[test_index]);
    struct efi_guid_t test_guid = test_entry->guid;

    register_mocked_read(&test_partition_array, sizeof(test_partition_array));

    /* Try to move the test entry into the middle of the entry just read.
     * Starting at the same LBA
     */
    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_ARGUMENT, gpt_entry_move_no_copy(
                &test_guid,
                TEST_GPT_FIRST_PARTITION_START,
                TEST_GPT_SECOND_PARTITION_END));

    /* Try to move the test entry into the middle of the entry just read.
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
}

void test_gpt_entry_move_no_copy_should_failWhenLbaOffDisk(void)
{
    setup_valid_gpt();

    /* Try to move an entry. */
    size_t test_index = 1;
    struct gpt_entry_t *test_entry = &(test_partition_array[test_index]);
    struct efi_guid_t test_guid = test_entry->guid;

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

void test_gpt_attr_set_should_setAttributes(void)
{
    /* Start with a populated GPT */
    setup_valid_gpt();

    /* Entries are read */
    register_mocked_read(&test_partition_array, sizeof(test_partition_array));

    struct efi_guid_t guid = test_partition_array[0].guid;
    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_attr_set(&guid, 0x1));
}

void test_gpt_attr_set_should_failWhenEntryNotExisting(void)
{
    setup_valid_gpt();

    /* Read every entry */
    register_mocked_read(&test_partition_array, sizeof(test_partition_array));

    struct efi_guid_t non_existing = NULL_GUID;
    TEST_ASSERT_EQUAL(PSA_ERROR_DOES_NOT_EXIST, gpt_attr_set(&non_existing, 0x1));
}

void test_gpt_attr_remove_should_removeAttributes(void)
{
    /* Start with a populated GPT */
    struct gpt_entry_t *test_entry = &(test_partition_array[0]);
    uint64_t test_attr = 0x1;
    test_entry->attr = test_attr;
    setup_valid_gpt();

    /* First entry is read */
    register_mocked_read(&test_partition_array, sizeof(test_partition_array));

    struct efi_guid_t test_guid = test_entry->guid;
    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_attr_set(&test_guid, test_attr));
}

void test_gpt_attr_remove_should_failWhenEntryNotExisting(void)
{
    setup_valid_gpt();

    /* Read every entry */
    register_mocked_read(&test_partition_array, sizeof(test_partition_array));

    struct efi_guid_t non_existing = NULL_GUID;
    TEST_ASSERT_EQUAL(PSA_ERROR_DOES_NOT_EXIST, gpt_attr_remove(&non_existing, 0x1));
}

void test_gpt_attr_add_should_addAttributes(void)
{
    /* Start with a populated GPT */
    struct gpt_entry_t *test_entry = &(test_partition_array[0]);
    setup_valid_gpt();

    /* First entry is read */
    register_mocked_read(&test_partition_array, sizeof(test_partition_array));

    struct efi_guid_t test_guid = test_entry->guid;
    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_attr_add(&test_guid, 0x1));
}

void test_gpt_attr_add_should_failWhenEntryNotExisting(void)
{
    setup_valid_gpt();

    /* Read every entry */
    register_mocked_read(&test_partition_array, sizeof(test_partition_array));

    struct efi_guid_t non_existing = NULL_GUID;
    TEST_ASSERT_EQUAL(PSA_ERROR_DOES_NOT_EXIST, gpt_attr_add(&non_existing, 0x1));
}

void test_gpt_entry_change_type_should_setNewType(void)
{
    /* Start with a populated GPT */
    struct gpt_entry_t *test_entry = &(test_partition_array[0]);
    setup_valid_gpt();

    /* First entry is read */
    register_mocked_read(&test_partition_array, sizeof(test_partition_array));

    struct efi_guid_t test_guid = test_entry->guid;

    /* Type validation is not a function of the library, as this is OS
     * dependent, so anything will do here.
     */
    struct efi_guid_t new_type = TEST_GPT_VALID_TYPE(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11);
    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_entry_change_type(&test_guid, &new_type));
}

void test_gpt_entry_change_type_should_failWhenEntryNotExisting(void)
{
    setup_valid_gpt();

    /* Read every entry */
    register_mocked_read(&test_partition_array, sizeof(test_partition_array));

    struct efi_guid_t non_existing = NULL_GUID;
    struct efi_guid_t new_type = TEST_GPT_VALID_TYPE(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11);
    TEST_ASSERT_EQUAL(PSA_ERROR_DOES_NOT_EXIST, gpt_entry_change_type(&non_existing, &new_type));
}

void test_gpt_entry_change_type_should_failWhenSettingTypeToNullGuid(void)
{
    setup_valid_gpt();

    struct gpt_entry_t *test_entry = &(test_partition_array[0]);

    /* First entry is read */
    register_mocked_read(&test_partition_array, sizeof(test_partition_array));

    struct efi_guid_t test_guid = test_entry->guid;
    struct efi_guid_t new_type = NULL_GUID;

    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_ARGUMENT, gpt_entry_change_type(&test_guid, &new_type));
}

void test_gpt_entry_rename_should_renameEntry(void)
{
    /* Start with a populated GPT */
    struct gpt_entry_t *test_entry = &(test_partition_array[0]);
    setup_valid_gpt();

    /* First entry is read */
    register_mocked_read(&test_partition_array, sizeof(test_partition_array));

    char new_name[GPT_ENTRY_NAME_LENGTH] = {'\0'};
    new_name[0] = 'a';
    struct efi_guid_t test_guid = test_entry->guid;
    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_entry_rename(&test_guid, new_name));
}

void test_gpt_entry_rename_should_failWhenNameIsEmpty(void)
{
    /* Start with a populated GPT */
    struct gpt_entry_t *test_entry = &(test_partition_array[0]);
    setup_valid_gpt();

    /* Try to change name to an empty string */
    struct efi_guid_t test_guid = test_entry->guid;
    char name[GPT_ENTRY_NAME_LENGTH] = {'\0'};
    TEST_ASSERT_EQUAL(PSA_ERROR_INVALID_ARGUMENT, gpt_entry_rename(&test_guid, name));
}

void test_gpt_entry_rename_should_failWhenEntryNotExisting(void)
{
    setup_valid_gpt();

    /* Read every entry */
    register_mocked_read(&test_partition_array, sizeof(test_partition_array));

    struct efi_guid_t non_existing = NULL_GUID;
    char new_name[GPT_ENTRY_NAME_LENGTH] = {'\0'};
    new_name[0] = 'a';
    TEST_ASSERT_EQUAL(PSA_ERROR_DOES_NOT_EXIST, gpt_entry_rename(&non_existing, new_name));
}

void test_gpt_entry_remove_should_removeEntry(void)
{
    /* Start with a populated GPT */
    setup_valid_gpt();

    /* Each entry is read */
    struct gpt_entry_t *test_entry = &(default_partition_array[TEST_DEFAULT_NUM_PARTITIONS - 1]);
    struct efi_guid_t test_guid = test_entry->guid;
    register_mocked_read(&test_partition_array, sizeof(test_partition_array));

    TEST_ASSERT_EQUAL(PSA_SUCCESS, gpt_entry_remove(&test_guid));
}

void test_gpt_entry_remove_should_failWhenEntryNotExisting(void)
{
    /* Start by trying to remove from an empty table */
    setup_empty_gpt();

    struct efi_guid_t non_existing = NULL_GUID;
    TEST_ASSERT_EQUAL(PSA_ERROR_DOES_NOT_EXIST, gpt_entry_remove(&non_existing));

    /* Now, have a non-empty GPT but search for a non-existing GUID */
    setup_valid_gpt();

    /* Each entry should be read. */
    register_mocked_read(&test_partition_array, sizeof(test_partition_array));
    TEST_ASSERT_EQUAL(PSA_ERROR_DOES_NOT_EXIST, gpt_entry_remove(&non_existing));
}

void test_gpt_entry_read_should_populateEntry(void)
{
    /* Start with a populated GPT */
    setup_valid_gpt();

    /* Ensure an entry is found */
    struct partition_entry_t entry;
    struct gpt_entry_t *desired = &(test_partition_array[TEST_DEFAULT_NUM_PARTITIONS - 1]);
    struct efi_guid_t test_guid = desired->guid;
    struct efi_guid_t test_type = desired->type;
    register_mocked_read(&test_partition_array, sizeof(test_partition_array));
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

    /* Try to read something */
    struct partition_entry_t entry;
    struct efi_guid_t non_existing = NULL_GUID;
    TEST_ASSERT_EQUAL(PSA_ERROR_DOES_NOT_EXIST, gpt_entry_read(&non_existing, &entry));

    /* Now, have a non-empty GPT but search for a non-existing GUID */
    setup_valid_gpt();

    /* Each entry should be read */
    register_mocked_read(&test_partition_array, sizeof(test_partition_array));
    TEST_ASSERT_EQUAL(PSA_ERROR_DOES_NOT_EXIST, gpt_entry_read(&non_existing, &entry));
}

void test_gpt_entry_read_by_name_should_populateEntry(void)
{
    /* Start with a populated GPT */
    setup_valid_gpt();

    /* Ensure an entry is found, even with repeat names */
    struct partition_entry_t entry;
    struct gpt_entry_t *desired1 = &(test_partition_array[0]);
    struct efi_guid_t test_guid1 = desired1->guid;
    struct efi_guid_t test_type1 = desired1->type;

    /* Change the name of something else and ensure it is found */
    struct gpt_entry_t *desired2 = &(test_partition_array[1]);
    struct efi_guid_t test_guid2 = desired2->guid;
    struct efi_guid_t test_type2 = desired2->type;
    memcpy(desired2->name, desired1->name, GPT_ENTRY_NAME_LENGTH);

    register_mocked_read(&test_partition_array, sizeof(test_partition_array));
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
}

void test_gpt_entry_read_by_name_should_failWhenEntryNotExisting(void)
{
    /* Start with an empty GPT */
    setup_empty_gpt();

    /* Try to read something */
    struct partition_entry_t entry;
    char test_name[GPT_ENTRY_NAME_LENGTH] = {'\0'};
    TEST_ASSERT_EQUAL(PSA_ERROR_DOES_NOT_EXIST, gpt_entry_read_by_name(test_name, 0, &entry));

    /* Now, have a non-empty GPT but search for a name that won't exist */
    setup_valid_gpt();

    /* Each entry should be read */
    register_mocked_read(&test_partition_array, sizeof(test_partition_array));
    TEST_ASSERT_EQUAL(PSA_ERROR_DOES_NOT_EXIST, gpt_entry_read_by_name(test_name, 0, &entry));

    /* Finally, search for the second entry of a name that appears only once */
    memcpy(test_name, test_partition_array[0].name, GPT_ENTRY_NAME_LENGTH);
    TEST_ASSERT_EQUAL(PSA_ERROR_DOES_NOT_EXIST, gpt_entry_read_by_name(test_name, 1, &entry));
    TEST_ASSERT_EQUAL(PSA_ERROR_DOES_NOT_EXIST, gpt_entry_read_by_name(test_name, TEST_DEFAULT_NUM_PARTITIONS, &entry));
}

void test_gpt_entry_read_by_type_should_populateEntry(void)
{
    /* Start with a populated GPT */
    setup_valid_gpt();

    /* Ensure an entry is found, even with repeat types */
    struct partition_entry_t entry;
    struct gpt_entry_t *desired1 = &(test_partition_array[0]);
    struct efi_guid_t test_guid1 = desired1->guid;
    struct efi_guid_t test_type1 = desired1->type;

    struct gpt_entry_t *desired2 = &(test_partition_array[1]);
    struct efi_guid_t test_guid2 = desired2->guid;
    struct efi_guid_t test_type2 = test_type1;
    desired2->type = test_type2;

    register_mocked_read(&test_partition_array, sizeof(test_partition_array));
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
}

void test_gpt_entry_read_by_type_should_failWhenEntryNotExisting(void)
{
    /* Start with an empty GPT */
    setup_empty_gpt();

    /* Try to read something */
    struct partition_entry_t entry;
    struct efi_guid_t test_type = TEST_GPT_VALID_TYPE(11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1);
    TEST_ASSERT_EQUAL(PSA_ERROR_DOES_NOT_EXIST, gpt_entry_read_by_type(&test_type, 0, &entry));

    /* Now, have a non-empty GPT but search for a type that won't exist */
    setup_valid_gpt();

    /* Each entry should be read */
    register_mocked_read(&test_partition_array, sizeof(test_partition_array));
    TEST_ASSERT_EQUAL(PSA_ERROR_DOES_NOT_EXIST, gpt_entry_read_by_type(&test_type, 0, &entry));

    /* Finally, search for the second entry of a type that appears only once */
    struct efi_guid_t existing_type = test_partition_array[0].type;
    efi_guid_cpy(&existing_type, &test_type);
    TEST_ASSERT_EQUAL(PSA_ERROR_DOES_NOT_EXIST, gpt_entry_read_by_type(&test_type, 1, &entry));
    TEST_ASSERT_EQUAL(PSA_ERROR_DOES_NOT_EXIST, gpt_entry_read_by_type(&test_type, TEST_DEFAULT_NUM_PARTITIONS, &entry));
}
