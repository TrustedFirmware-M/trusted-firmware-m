/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
#include <string.h>
#include "psa/crypto.h"
#include "psa/error.h"
#include "tfm_bootloader_fwu_abstraction.h"

#include <stdint.h>
#include <string.h>
#include "fwu_agent.h"
#include "Driver_Flash.h"
#include "flash_layout.h"
#include "fip_parser/external/uuid.h"
#include "region_defs.h"
#include "flash_common.h"
#include "platform_base_address.h"
#include "platform_description.h"
#include "tfm_plat_nv_counters.h"
#include "tfm_plat_defs.h"
#include "uefi_fmp.h"
#include "uart_stdout.h"
#include "soft_crc.h"
#ifndef BL1_BUILD
#include "partition.h"
#include "platform.h"
#endif

#define FWU_METADATA_VERSION		2
#define FWU_FW_STORE_DESC_OFFSET	0x20
#define NR_OF_MAX_FW_BANKS		4

/* Size of a chunk transferred at once from one bank to another
 * This is used when bank consistency is maintained during partial capsule update
 */
#define FLASH_CHUNK_SIZE                512

/* Possible states of the bank.
 * Naming convention here matches the implementation in U-Boot 
 */
#define FWU_BANK_INVALID	(uint8_t)0xFF
#define FWU_BANK_VALID		(uint8_t)0xFE
#define FWU_BANK_ACCEPTED	(uint8_t)0xFC

/* The component number for the ESRT image.
 * The ESRT image is used to read ESRT entries for all the images in a bank
 */
#define FWU_IMAGE_INDEX_ESRT         FWU_COMPONENT_NUMBER - 1

/* Index count for fake images to be ignored
 * The image index for firmware images in capsule starts from 1.
 * So, the image at index 0 should be ignored */
#define FWU_FAKE_IMAGES_INDEX_COUNT    1
#define FWU_FAKE_IMAGE_INDEX           0

/*
 * Metadata version 2 data structures defined by PSA_FW update specification
 * at https://developer.arm.com/documentation/den0118/latest/
 */

/* Properties of image in a bank */
struct fwu_image_properties {

        /* The UUID of the image in this bank */
        uuid_t img_uuid;

        /* [0]: bit describing the image acceptance status –
         * status - 1 means the image is accepted
         * [31:1]: MBZ
         */
        uint32_t accepted;

        /* NOTE: using the reserved field */
        /* image version */
        uint32_t version;

} __packed;

/* Image entry information */
struct fwu_image_entry {

        /* The UUID identifying the image type */
        uuid_t img_type_uuid;

        /* The UUID of the storage volume where the image is located */
        uuid_t location_uuid;

        /* The Properties of images with img_type_uuid in the different FW banks */
        struct fwu_image_properties img_props[NR_OF_FW_BANKS];

} __packed;

struct fwu_fw_store_descriptor {

       /* The number of firmware banks in the Firmware Store */
       uint8_t num_banks;

       /* Reserved */
       uint8_t reserved;

       /* The number of images per bank. This should be the number of entries in the img_entry array */
       uint16_t num_images;

       /* The size of image_entry(all banks) in bytes */
       uint16_t img_entry_size;

       /* The size of image bank info structure in bytes */
       uint16_t bank_info_entry_size;

       /* Array of fwu_image_entry structs */
       struct fwu_image_entry img_entry[NR_OF_IMAGES_IN_FW_BANK];

} __packed;

struct fwu_metadata {

        /* The metadata CRC value */
        uint32_t crc_32;

        /* The metadata version */
        uint32_t version;

        /* The bank index with which device boots */
        uint32_t active_index;

        /* The previous bank index with which device booted successfully */
        uint32_t previous_active_index;

        /* The size of the entire metadata in bytes */
        uint32_t metadata_size;

        /* The offset of the image descriptor structure */
        uint16_t desc_offset;

        /* Reserved */
        uint16_t reserved1;

        /* The state of each bank 
         * Each bank_state entry can take one of the following values:
         *  • 0xFF: invalid – One or more images in the bank are corrupted or were partially overwritten.
         *  • 0xFE: valid – The bank contains a valid set of images, but some images are in an unaccepted state.
         *  • 0xFC: accepted – all of the images in the bank are valid and have been accepted.
        */
        uint8_t bank_state[NR_OF_MAX_FW_BANKS];

        /* Reserved */
        uint32_t reserved2;

        struct fwu_fw_store_descriptor fw_desc;

} __packed;

/* This is Corstone1000 speific metadata for OTA.
 * Private metadata is written at next sector following
 * FWU METADATA location */
struct fwu_private_metadata {

       /* The bank from which system is booted from */
       uint32_t boot_index;

       /* The tracking number of boot attempted so far */
       uint32_t boot_attempted;

       /* The temprary location of staged nv_counter before written to the otp */
       uint32_t nv_counter[NR_OF_IMAGES_IN_FW_BANK];

       /* The current FMP version of each image */
       uint32_t fmp_version[NR_OF_IMAGES_IN_FW_BANK];

       /* The last attempted FMP version of each image */
       uint32_t fmp_last_attempt_version[NR_OF_IMAGES_IN_FW_BANK];

       /* The last attempted FMP status of each image */
       uint32_t fmp_last_attempt_status[NR_OF_IMAGES_IN_FW_BANK];

} __packed;

/*
 * struct fwu_esrt_data_wrapper - Wrapper for the ESRT data
 * @data: The ESRT data
 * @entries: The ESRT image entries
 */
struct __attribute__((__packed__)) fwu_esrt_data_wrapper {
        /* The ESRT data */
        struct efi_system_resource_table  data;

        /* The ESRT image entries */
        struct efi_system_resource_entry entries[NR_OF_IMAGES_IN_FW_BANK];
};

#define MAX_BOOT_ATTEMPTS_PER_BANK 3

/*
 * GUIDs for capsule updatable firmware images
 *
 * The GUIDs are generating with the UUIDv5 format.
 * Namespace used for FVP GUIDs: 989f3a4e-46e0-4cd0-9877-a25c70c01329
 * Namespace used for MPS3 GUIDs: df1865d1-90fb-4d59-9c38-c9f2c1bba8cc
 * Names: the image names stated in the fw_name field
 */
fwu_bank_image_info_t fwu_image[NR_OF_IMAGES_IN_FW_BANK] = {
#if PLATFORM_IS_FVP
    // FVP payloads GUIDs
    // bl2_signed
    {
        .image_size = SE_BL2_PARTITION_SIZE,
        .image_offset = SE_BL2_PARTITION_BANK_OFFSET,
        .image_guid = {
            .time_low = 0xf1d883f9,
            .time_mid = 0xdfeb,
            .time_hi_and_version = 0x5363,
            .clock_seq_and_node = {0x98, 0xd8, 0x68, 0x6e, 0xe3, 0xb6, 0x9f, 0x4f}
        },
    },
    // tfm_s_signed
    {
        .image_size = TFM_PARTITION_SIZE,
        .image_offset = TFM_PARTITION_BANK_OFFSET,
        .image_guid = {
            .time_low = 0x7fad470e,
            .time_mid = 0x5ec5,
            .time_hi_and_version = 0x5c03,
            .clock_seq_and_node = {0xa2, 0xc1, 0x47, 0x56, 0xb4, 0x95, 0xde, 0x61}
        },
    },
    // signed_fip-corstone1000
    {
        .image_size = FIP_PARTITION_SIZE,
        .image_offset = FIP_PARTITION_BANK_OFFSET,
        .image_guid = {
            .time_low = 0xf1933675,
            .time_mid = 0x5a8c,
            .time_hi_and_version = 0x5b6d,
            .clock_seq_and_node = {0x9e, 0xf4, 0x84, 0x67, 0x39, 0xe8, 0x9b, 0xc8}
        },
    },
    // Image.gz-initramfs-corstone1000-fvp
    {
        .image_size = INITRAMFS_PARTITION_SIZE,
        .image_offset = INITRAMFS_PARTITION_BANK_OFFSET,
        .image_guid = {
            .time_low = 0xf771aff9,
            .time_mid = 0xc7e9,
            .time_hi_and_version = 0x5f99,
            .clock_seq_and_node = {0x9e, 0xda, 0x23, 0x69, 0xdd, 0x69, 0x4f, 0x61}
        },
    },
#else
    // MPS3 payloads GUIDs
    // bl2_signed payload GUID
    {
        .image_size = SE_BL2_PARTITION_SIZE,
        .image_offset = SE_BL2_PARTITION_BANK_OFFSET,
        .image_guid = {
            .time_low = 0xfbfbefaa,
            .time_mid = 0x0a56,
            .time_hi_and_version = 0x50d5,
            .clock_seq_and_node = {0xb6, 0x51, 0x74, 0x09, 0x1d, 0x3d, 0x62, 0xcf}
        },
    },
    // tfm_s_signed
    {
        .image_size = TFM_PARTITION_SIZE,
        .image_offset = TFM_PARTITION_BANK_OFFSET,
        .image_guid = {
            .time_low = 0xaf4cc7ad,
            .time_mid = 0xee2e,
            .time_hi_and_version = 0x5a39,
            .clock_seq_and_node = {0xaa, 0xd5, 0xfa, 0xc8, 0xa1, 0xe6, 0x17, 0x3c}
        },
    },
    // signed_fip-corstone1000
    {
        .image_size = FIP_PARTITION_SIZE,
        .image_offset = FIP_PARTITION_BANK_OFFSET,
        .image_guid = {
            .time_low = 0x55302f96,
            .time_mid = 0xc4f0,
            .time_hi_and_version = 0x5cf9,
            .clock_seq_and_node = {0x86, 0x24, 0xe7, 0xcc, 0x38, 0x8f, 0x2b, 0x68}
        },
    },
    // Image.gz-initramfs-corstone1000-mps3
    {
        .image_size = INITRAMFS_PARTITION_SIZE,
        .image_offset = INITRAMFS_PARTITION_BANK_OFFSET,
        .image_guid = {
            .time_low = 0x3e8ac972,
            .time_mid = 0xc33c,
            .time_hi_and_version = 0x5cc9,
            .clock_seq_and_node = {0x90, 0xa0, 0xcd, 0xd3, 0x15, 0x96, 0x83, 0xea}
        },
    },
#endif
};

struct fwu_metadata _metadata;

bool is_initialized = false;
bool is_installed = false;

fmp_header_image_info_t fmp_header_image_info[FWU_COMPONENT_NUMBER];
struct fwu_esrt_data_wrapper esrt;

#define IMAGE_ACCEPTED          (1)
#define IMAGE_NOT_ACCEPTED      (0)
#define BANK_0                  (0)
#define BANK_1                  (1)
#define INVALID_VERSION         (0xffffffff)
#define INVALID_IMAGE           (0xf)

#ifndef FWU_METADATA_FLASH_DEV
    #ifndef FLASH_DEV_NAME
    #error "FWU_METADATA_FLASH_DEV or FLASH_DEV_NAME must be defined in flash_layout.h"
    #else
    #define FWU_METADATA_FLASH_DEV FLASH_DEV_NAME
    #endif
#endif

/* Import the CMSIS flash device driver */
extern ARM_DRIVER_FLASH FWU_METADATA_FLASH_DEV;

#define SYSTICK_PER_MINUTE    60
#define BOOT_TIME_IN_MINUTES  6
#define HOST_ACK_SYSTICK_TIMEOUT    (BOOT_TIME_IN_MINUTES * SYSTICK_PER_MINUTE)  /* Number of system ticks to be precise.
                                                                                  * This is the value decided after monitoring the total time
                                                                                  * taken by the host to boot both on FVP and FPGA.
                                                                                  */

#ifdef BL1_BUILD
static psa_status_t private_metadata_read(
        struct fwu_private_metadata* priv_metadata)
{
    FWU_LOG_MSG("%s: enter\n\r", __func__);

    if (!priv_metadata) {
        FWU_LOG_MSG("%s: ERROR - Null pointer received\n\r", __func__);
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    int ret = FWU_METADATA_FLASH_DEV.ReadData(FWU_PRIVATE_METADATA_REPLICA_1_OFFSET, priv_metadata,
                                          sizeof(*priv_metadata));
    if (ret < 0) {
        FWU_LOG_MSG("%s: ERROR - Flash read failed (ret = %d)\n\r", __func__, ret);
        return PSA_ERROR_STORAGE_FAILURE;
    }

    if (ret != sizeof(*priv_metadata)) {
        FWU_LOG_MSG("%s: ERROR - Incomplete metadata read (expected %zu, got %d)\n\r", 
                    __func__, sizeof(*priv_metadata), ret);
        return PSA_ERROR_INSUFFICIENT_DATA;
    }

    FWU_LOG_MSG("%s: success: boot_index = %u\n\r", __func__,
                        priv_metadata->boot_index);

    return PSA_SUCCESS;
}
#else
static psa_status_t private_metadata_read(
        struct fwu_private_metadata* priv_metadata)
{
    partition_entry_t *part;
    uuid_t private_uuid = PRIVATE_METADATA_TYPE_UUID;

    FWU_LOG_MSG("%s: enter\n\r", __func__);

    if (!priv_metadata) {
        FWU_LOG_MSG("%s: ERROR - Null pointer received\n\r", __func__);
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    part = get_partition_entry_by_type(&private_uuid);
    if (!part) {
        FWU_LOG_MSG("Private metadata partition not found\n\r");
        return PSA_ERROR_GENERIC_ERROR;
    }

    int ret = FWU_METADATA_FLASH_DEV.ReadData(part->start, priv_metadata,
                                          sizeof(*priv_metadata));
    if (ret < 0) {
        FWU_LOG_MSG("%s: ERROR - Flash read failed (ret = %d)\n\r", __func__, ret);
        return PSA_ERROR_STORAGE_FAILURE;
    }

    if (ret != sizeof(*priv_metadata)) {
        FWU_LOG_MSG("%s: ERROR - Incomplete metadata read (expected %zu, got %d)\n\r", 
                    __func__, sizeof(*priv_metadata), ret);
        return PSA_ERROR_INSUFFICIENT_DATA;
    }

    FWU_LOG_MSG("%s: success: boot_index = %u\n\r", __func__,
                        priv_metadata->boot_index);

    return PSA_SUCCESS;
}
#endif

#ifdef BL1_BUILD
static psa_status_t private_metadata_write(
        struct fwu_private_metadata* priv_metadata)
{
    FWU_LOG_MSG("%s: enter: boot_index = %u\n\r", __func__,
                        priv_metadata->boot_index);

    if (!priv_metadata) {
        FWU_LOG_MSG("%s: ERROR - Null pointer received\n\r", __func__);
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    int ret = FWU_METADATA_FLASH_DEV.EraseSector(FWU_PRIVATE_METADATA_REPLICA_1_OFFSET);
    if (ret != ARM_DRIVER_OK) {
        FWU_LOG_MSG("%s: ERROR - Flash erase failed (ret = %d)\n\r", __func__, ret);
        return PSA_ERROR_STORAGE_FAILURE;
    }

    ret = FWU_METADATA_FLASH_DEV.ProgramData(FWU_PRIVATE_METADATA_REPLICA_1_OFFSET,
                                priv_metadata, sizeof(*priv_metadata));
    if (ret < 0) {
        FWU_LOG_MSG("%s: ERROR - Flash write failed (ret = %d)\n\r", __func__, ret);
        return PSA_ERROR_STORAGE_FAILURE;
    }

    if (ret != sizeof(*priv_metadata)) {
        FWU_LOG_MSG("%s: ERROR - Incomplete metadata write (expected %zu, written %d)\n\r", 
                    __func__, sizeof(*priv_metadata), ret);
        return PSA_ERROR_INSUFFICIENT_DATA;
    }

    FWU_LOG_MSG("%s: success\n\r", __func__);
    return PSA_SUCCESS;
}
#else
static psa_status_t private_metadata_write(
        struct fwu_private_metadata* priv_metadata)
{
    uuid_t private_uuid = PRIVATE_METADATA_TYPE_UUID;
    partition_entry_t *part;

    FWU_LOG_MSG("%s: enter: boot_index = %u\n\r", __func__,
                        priv_metadata->boot_index);

    if (!priv_metadata) {
        FWU_LOG_MSG("%s: ERROR - Null pointer received\n\r", __func__);
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    part = get_partition_entry_by_type(&private_uuid);
    if (!part) {
        FWU_LOG_MSG("Private metadata partition not found\n\r");
        return PSA_ERROR_GENERIC_ERROR;
    }

    int ret = FWU_METADATA_FLASH_DEV.EraseSector(part->start);
    if (ret != ARM_DRIVER_OK) {
        FWU_LOG_MSG("%s: ERROR - Flash erase failed (ret = %d)\n\r", __func__, ret);
        return PSA_ERROR_STORAGE_FAILURE;
    }

    ret = FWU_METADATA_FLASH_DEV.ProgramData(part->start,
                                priv_metadata, sizeof(*priv_metadata));
    if (ret < 0) {
        FWU_LOG_MSG("%s: ERROR - Flash write failed (ret = %d)\n\r", __func__, ret);
        return PSA_ERROR_STORAGE_FAILURE;
    }

    if (ret != sizeof(*priv_metadata)) {
        FWU_LOG_MSG("%s: ERROR - Incomplete metadata write (expected %zu, written %d)\n\r", 
                    __func__, sizeof(*priv_metadata), ret);
        return PSA_ERROR_INSUFFICIENT_DATA;
    }

    FWU_LOG_MSG("%s: success\n\r", __func__);
    return PSA_SUCCESS;
}
#endif

static psa_status_t metadata_validate(struct fwu_metadata *metadata)
{
    FWU_LOG_MSG("%s: enter:\n\r", __func__);

    if (!metadata) {
        FWU_LOG_MSG("%s: ERROR - Null pointer received\n\r", __func__);
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    uint32_t calculated_crc32 = crc32((uint8_t *)&(metadata->version),
                                      sizeof(*metadata) - sizeof(uint32_t));

    if (metadata->crc_32 != calculated_crc32) {
        FWU_LOG_MSG("%s: failed: crc32 calculated: 0x%x, given: 0x%x\n\r", __func__,
                    calculated_crc32, metadata->crc_32);
        return PSA_ERROR_GENERIC_ERROR;
    }

    FWU_LOG_MSG("%s: success\n\r", __func__);

    return PSA_SUCCESS;
}

#ifdef BL1_BUILD
static psa_status_t metadata_read_without_validation(struct fwu_metadata *metadata)
{
    FWU_LOG_MSG("%s: enter: flash addr = %u, size = %d\n\r", __func__,
                  FWU_METADATA_REPLICA_1_OFFSET, sizeof(*metadata));

    if (!metadata) {
        FWU_LOG_MSG("%s: ERROR - Null pointer received\n\r", __func__);
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    int ret = FWU_METADATA_FLASH_DEV.ReadData(FWU_METADATA_REPLICA_1_OFFSET,
                                metadata, sizeof(*metadata));
    if (ret < 0) {
        FWU_LOG_MSG("%s: ERROR - Flash read failed (ret = %d)\n\r", __func__, ret);
        return PSA_ERROR_STORAGE_FAILURE;
    }

    if (ret != sizeof(*metadata)) {
        FWU_LOG_MSG("%s: ERROR - Incomplete metadata read (expected %zu, got %d)\n\r", 
                    __func__, sizeof(*metadata), ret);
        return PSA_ERROR_INSUFFICIENT_DATA;
    }

    FWU_LOG_MSG("%s: success: active = %u, previous = %d\n\r", __func__,
                  metadata->active_index, metadata->previous_active_index);

    return PSA_SUCCESS;
}
#else
static psa_status_t metadata_read_without_validation(struct fwu_metadata *metadata)
{
    uuid_t metadata_uuid = FWU_METADATA_TYPE_UUID;
    partition_entry_t *part;

    if (!metadata) {
        FWU_LOG_MSG("%s: ERROR - Null pointer received\n\r", __func__);
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    part = get_partition_entry_by_type(&metadata_uuid);
    if (!part) {
        FWU_LOG_MSG("%s: FWU metadata partition not found\n\r", __func__);
        return PSA_ERROR_GENERIC_ERROR;
    }

    FWU_LOG_MSG("%s: enter: flash addr = %u, size = %d\n\r", __func__,
                  part->start, sizeof(*metadata));


    int ret = FWU_METADATA_FLASH_DEV.ReadData(part->start,
                                metadata, sizeof(*metadata));
    if (ret < 0) {
        FWU_LOG_MSG("%s: ERROR - Flash read failed (ret = %d)\n\r", __func__, ret);
        return PSA_ERROR_STORAGE_FAILURE;
    }

    if (ret != sizeof(*metadata)) {
        FWU_LOG_MSG("%s: ERROR - Incomplete metadata read (expected %zu, got %d)\n\r", 
                    __func__, sizeof(*metadata), ret);
        return PSA_ERROR_INSUFFICIENT_DATA;
    }

    FWU_LOG_MSG("%s: success: active = %u, previous = %d\n\r", __func__,
                  metadata->active_index, metadata->previous_active_index);

    return PSA_SUCCESS;
}
#endif

#ifdef BL1_BUILD
static psa_status_t metadata_read(struct fwu_metadata *metadata, uint8_t replica_num)
{
    uint32_t replica_offset = 0;

    FWU_LOG_MSG("%s: enter\n\r", __func__);

    if (!metadata) {
        FWU_LOG_MSG("%s: ERROR - Null pointer received\n\r", __func__);
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    if (replica_num == 1) {
        replica_offset = FWU_METADATA_REPLICA_1_OFFSET;
    } else if (replica_num == 2) {
        replica_offset = FWU_METADATA_REPLICA_2_OFFSET;
    } else {
        FWU_LOG_MSG("%s: replica_num must be 1 or 2\n\r", __func__);
        return PSA_ERROR_GENERIC_ERROR;
    }

    FWU_LOG_MSG("%s: flash addr = %u, size = %d\n\r", __func__,
                  replica_offset, sizeof(*metadata));


    int ret = FWU_METADATA_FLASH_DEV.ReadData(replica_offset,
                                metadata, sizeof(*metadata));
    if (ret < 0) {
        FWU_LOG_MSG("%s: ERROR - Flash read failed (ret = %d)\n\r", __func__, ret);
        return PSA_ERROR_STORAGE_FAILURE;
    }

    if (ret != sizeof(*metadata)) {
        FWU_LOG_MSG("%s: ERROR - Incomplete metadata read (expected %zu, got %d)\n\r", 
                    __func__, sizeof(*metadata), ret);
        return PSA_ERROR_INSUFFICIENT_DATA;
    }

    if (metadata_validate(metadata) != PSA_SUCCESS) {
        FWU_LOG_MSG("%s: ERROR - Metadata validation failed\n\r", __func__);
        return PSA_ERROR_GENERIC_ERROR;
    }

    FWU_LOG_MSG("%s: success: active = %u, previous = %d\n\r", __func__,
                  metadata->active_index, metadata->previous_active_index);

    return PSA_SUCCESS;
}
#else
static psa_status_t metadata_read(struct fwu_metadata *metadata, uint8_t replica_num)
{
    uuid_t metadata_uuid = FWU_METADATA_TYPE_UUID;
    partition_entry_t *part;

    FWU_LOG_MSG("%s: enter\n\r", __func__);

    if (!metadata) {
        FWU_LOG_MSG("%s: ERROR - Null pointer received\n\r", __func__);
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    if (replica_num == 1) {
        part = get_partition_entry_by_type(&metadata_uuid);
    } else if (replica_num == 2) {
        part = get_partition_replica_by_type(&metadata_uuid);
    } else {
        FWU_LOG_MSG("%s: replica_num must be 1 or 2\n\r", __func__);
        return PSA_ERROR_GENERIC_ERROR;
    }

    if (!part) {
        FWU_LOG_MSG("%s: FWU metadata partition not found\n\r", __func__);
        return PSA_ERROR_GENERIC_ERROR;
    }

    FWU_LOG_MSG("%s: enter: flash addr = %u, size = %d\n\r", __func__,
                  part->start, sizeof(*metadata));

    int ret = FWU_METADATA_FLASH_DEV.ReadData(part->start,
                                metadata, sizeof(*metadata));
    if (ret < 0) {
        FWU_LOG_MSG("%s: ERROR - Flash read failed (ret = %d)\n\r", __func__, ret);
        return PSA_ERROR_STORAGE_FAILURE;
    }

    if (ret != sizeof(*metadata)) {
        FWU_LOG_MSG("%s: ERROR - Incomplete metadata read (expected %zu, got %d)\n\r", 
                    __func__, sizeof(*metadata), ret);
        return PSA_ERROR_INSUFFICIENT_DATA;
    }

    if (metadata_validate(metadata) != PSA_SUCCESS) {
        FWU_LOG_MSG("%s: ERROR - Metadata validation failed\n\r", __func__);
        return PSA_ERROR_GENERIC_ERROR;
    }

    FWU_LOG_MSG("%s: success: active = %u, previous = %d\n\r", __func__,
                  metadata->active_index, metadata->previous_active_index);

    return PSA_SUCCESS;
}
#endif


#ifdef BL1_BUILD
static psa_status_t metadata_write(
                        struct fwu_metadata *metadata, uint8_t replica_num)
{
    uint32_t replica_offset = 0;

    FWU_LOG_MSG("%s: enter\n\r", __func__);

    if (!metadata) {
        FWU_LOG_MSG("%s: ERROR - Null pointer received\n\r", __func__);
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    if (replica_num == 1) {
        replica_offset = FWU_METADATA_REPLICA_1_OFFSET;
    } else if (replica_num == 2) {
        replica_offset = FWU_METADATA_REPLICA_2_OFFSET;
    } else {
        FWU_LOG_MSG("%s: replica_num must be 1 or 2\n\r", __func__);
        return PSA_ERROR_GENERIC_ERROR;
    }

    FWU_LOG_MSG("%s: enter: flash addr = %u, size = %d\n\r", __func__,
                  replica_offset, sizeof(*metadata));


    int ret = FWU_METADATA_FLASH_DEV.EraseSector(replica_offset);
    if (ret != ARM_DRIVER_OK) {
        FWU_LOG_MSG("%s: ERROR - Flash erase failed (ret = %d)\n\r", __func__, ret);
        return PSA_ERROR_STORAGE_FAILURE;
    }

    ret = FWU_METADATA_FLASH_DEV.ProgramData(replica_offset,
                                metadata, sizeof(*metadata));
    if (ret < 0) {
        FWU_LOG_MSG("%s: ERROR - Flash write failed (ret = %d)\n\r", __func__, ret);
        return PSA_ERROR_STORAGE_FAILURE;
    }

    if (ret != sizeof(*metadata)) {
        FWU_LOG_MSG("%s: ERROR - Incomplete metadata write (expected %zu, written %d)\n\r", 
                    __func__, sizeof(*metadata), ret);
        return PSA_ERROR_INSUFFICIENT_DATA;
    }

    FWU_LOG_MSG("%s: success: active = %u, previous = %d\n\r", __func__,
                  metadata->active_index, metadata->previous_active_index);
    return PSA_SUCCESS;
}
#else
static psa_status_t metadata_write(
                        struct fwu_metadata *metadata, uint8_t replica_num)
{
    uuid_t metadata_uuid = FWU_METADATA_TYPE_UUID;
    partition_entry_t *part;

    if (!metadata) {
        FWU_LOG_MSG("%s: ERROR - Null pointer received\n\r", __func__);
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    if (replica_num == 1) {
        part = get_partition_entry_by_type(&metadata_uuid);
    } else if (replica_num == 2) {
        part = get_partition_replica_by_type(&metadata_uuid);
    } else {
        FWU_LOG_MSG("%s: replica_num must be 1 or 2\n\r", __func__);
        return PSA_ERROR_GENERIC_ERROR;
    }

    if (!part) {
        FWU_LOG_MSG("%s: FWU metadata partition not found\n\r", __func__);
        return PSA_ERROR_GENERIC_ERROR;
    }

    FWU_LOG_MSG("%s: enter: flash addr = %u, size = %d\n\r", __func__,
                  part->start, sizeof(*metadata));

    int ret = FWU_METADATA_FLASH_DEV.EraseSector(part->start);
    if (ret != ARM_DRIVER_OK) {
        FWU_LOG_MSG("%s: ERROR - Flash erase failed (ret = %d)\n\r", __func__, ret);
        return PSA_ERROR_STORAGE_FAILURE;
    }

    ret = FWU_METADATA_FLASH_DEV.ProgramData(part->start,
                                metadata, sizeof(*metadata));
    if (ret < 0) {
        FWU_LOG_MSG("%s: ERROR - Flash write failed (ret = %d)\n\r", __func__, ret);
        return PSA_ERROR_STORAGE_FAILURE;
    }

    if (ret != sizeof(*metadata)) {
        FWU_LOG_MSG("%s: ERROR - Incomplete metadata write (expected %zu, written %d)\n\r", 
                    __func__, sizeof(*metadata), ret);
        return PSA_ERROR_INSUFFICIENT_DATA;
    }

    FWU_LOG_MSG("%s: success: active = %u, previous = %d\n\r", __func__,
                  metadata->active_index, metadata->previous_active_index);
    return PSA_SUCCESS;
}
#endif

static psa_status_t metadata_write_both_replica(
                        struct fwu_metadata *metadata)
{
    psa_status_t ret = PSA_ERROR_GENERIC_ERROR;

    ret = metadata_write(metadata, 1);
    if (ret) {
        return ret;
    }

    ret = metadata_write(metadata, 2);
    if (ret) {
        return ret;
    }

    return PSA_SUCCESS;
}

psa_status_t fwu_metadata_check_and_correct_integrity(void)
{
    psa_status_t ret_replica_1 = PSA_ERROR_GENERIC_ERROR;
    psa_status_t ret_replica_2 = PSA_ERROR_GENERIC_ERROR;

    /* Check integrity of both metadata replica */
    ret_replica_1 = metadata_read(&_metadata, 1);
    ret_replica_2 = metadata_read(&_metadata, 2);

    if (ret_replica_1 != PSA_SUCCESS && ret_replica_2 != PSA_SUCCESS) {
        return PSA_ERROR_GENERIC_ERROR;
    } else if (ret_replica_1 == PSA_SUCCESS && ret_replica_2 != PSA_SUCCESS) {
        metadata_read(&_metadata, 1);
        metadata_write(&_metadata, 2);
    } else if (ret_replica_1 != PSA_SUCCESS && ret_replica_2 == PSA_SUCCESS) {
        metadata_read(&_metadata, 2);
        metadata_write(&_metadata, 1);
    }

    return PSA_SUCCESS;
}

psa_status_t fwu_metadata_init(void)
{
    psa_status_t ret;
    ARM_FLASH_INFO* flash_info;

    if (is_initialized) {
        return PSA_SUCCESS;
    }

    #ifndef BL1_BUILD
    plat_io_storage_init();
    partition_init(PLATFORM_GPT_IMAGE);
    #endif

    /* Code assumes everything fits into a sector */
    if (sizeof(struct fwu_metadata) > FWU_METADATA_FLASH_SECTOR_SIZE) {
        return PSA_ERROR_GENERIC_ERROR;
    }

    if (sizeof(struct fwu_private_metadata) > FWU_METADATA_FLASH_SECTOR_SIZE) {
        return PSA_ERROR_GENERIC_ERROR;
    }

    ret = FWU_METADATA_FLASH_DEV.Initialize(NULL);
    if (ret != ARM_DRIVER_OK) {
        return PSA_ERROR_GENERIC_ERROR;
    }

    flash_info = FWU_METADATA_FLASH_DEV.GetInfo();
    if (flash_info->program_unit != 1) {
        FWU_METADATA_FLASH_DEV.Uninitialize();
        return PSA_ERROR_GENERIC_ERROR;
    }

    is_initialized = true;

    return PSA_SUCCESS;
}

static bool skip_metadata_provision(void)
{
    metadata_read(&_metadata, 1);
    return (((_metadata.active_index < 2) || (_metadata.previous_active_index < 2))
            && (_metadata.active_index ^ _metadata.previous_active_index)
           );
}

static psa_status_t fwu_metadata_configure(void)
{
    /* Provision FWU Agent Metadata */

    psa_status_t ret;
    uint32_t image_version = FWU_IMAGE_INITIAL_VERSION;

    memset(&_metadata, 0, sizeof(struct fwu_metadata));

    _metadata.version = FWU_METADATA_VERSION;
    _metadata.active_index = BANK_0;
    _metadata.previous_active_index = BANK_1;
    _metadata.desc_offset= FWU_FW_STORE_DESC_OFFSET;
    _metadata.metadata_size = sizeof(struct fwu_metadata);

    _metadata.fw_desc.num_banks = NR_OF_FW_BANKS;
    _metadata.fw_desc.num_images = NR_OF_IMAGES_IN_FW_BANK;
    _metadata.fw_desc.img_entry_size = sizeof(struct fwu_image_entry) * NR_OF_IMAGES_IN_FW_BANK;
    _metadata.fw_desc.bank_info_entry_size = sizeof(struct fwu_image_properties) * NR_OF_FW_BANKS;
    _metadata.bank_state[BANK_0] = FWU_BANK_ACCEPTED;
    _metadata.bank_state[BANK_1] = FWU_BANK_ACCEPTED;
    /* bank 0 is the place where images are located at the
     * start of device lifecycle */

    for (int i = 0; i < NR_OF_IMAGES_IN_FW_BANK; i++) {

        _metadata.fw_desc.img_entry[i].img_props[BANK_0].accepted = IMAGE_ACCEPTED;
        _metadata.fw_desc.img_entry[i].img_props[BANK_0].version = image_version;
        memcpy(&(_metadata.fw_desc.img_entry[i].img_props[BANK_0].img_uuid), (const void *)&fwu_image[i].image_guid, sizeof(struct efi_guid));

        _metadata.fw_desc.img_entry[i].img_props[BANK_1].accepted = INVALID_IMAGE;
        _metadata.fw_desc.img_entry[i].img_props[BANK_1].version = INVALID_VERSION;
        memcpy(&(_metadata.fw_desc.img_entry[i].img_props[BANK_1].img_uuid), (const void *)&fwu_image[i].image_guid, sizeof(struct efi_guid));
    }

    /* Calculate CRC32 for fwu metadata. The first filed in the _metadata has to be the crc_32.
     * This should be omited from the calculation. */
    _metadata.crc_32 = crc32((uint8_t *)&_metadata.version,
                             sizeof(struct fwu_metadata) - sizeof(uint32_t));

    ret = metadata_write_both_replica(&_metadata);
    if (ret) {
        return ret;
    }

    memset(&_metadata, 0, sizeof(_metadata));
    ret = metadata_read(&_metadata, 1);
    if (ret) {
        return ret;
    }
    FWU_LOG_MSG("%s: provisioned values: active = %u, previous = %d\n\r",
             __func__, _metadata.active_index, _metadata.previous_active_index);
    return PSA_SUCCESS;

}

static psa_status_t fwu_private_metadata_configure(void)
{
    /* Provision Private metadata for update agent which is shared
       beween BL1 and tf-m of secure enclave */

    psa_status_t ret;
    struct fwu_private_metadata priv_metadata;

    memset(&priv_metadata, 0, sizeof(struct fwu_private_metadata));

    priv_metadata.boot_index = BANK_0;
    priv_metadata.boot_attempted = 0;

    for (int i = 0; i < NR_OF_IMAGES_IN_FW_BANK; i++) {
        priv_metadata.fmp_version[i] = FWU_IMAGE_INITIAL_VERSION;
        priv_metadata.fmp_last_attempt_version[i] = FWU_IMAGE_INITIAL_VERSION;
        priv_metadata.fmp_last_attempt_status[i] = LAST_ATTEMPT_STATUS_SUCCESS;
    }
    ret = private_metadata_write(&priv_metadata);
    if (ret) {
        return ret;
    }

    memset(&priv_metadata, 0, sizeof(struct fwu_private_metadata));
    ret = private_metadata_read(&priv_metadata);
    if (ret) {
        return ret;
    }
    FWU_LOG_MSG("%s: provisioned values: boot_index = %u\n\r", __func__,
                        priv_metadata.boot_index);
    return PSA_SUCCESS;
}

psa_status_t fwu_metadata_provision(void)
{
    psa_status_t ret;

    FWU_LOG_MSG("%s: enter\n\r", __func__);

    ret = fwu_metadata_init();
    if (ret) {
        FWU_LOG_MSG("%s: ERROR FWU Metadata init failed \n\r", __func__);
        return ret;
    }

    /*
     * check by chance if the previous reboot
     * had a firmware data?. If yes, then don't initialize
     * metadata
     */
    if(skip_metadata_provision()) {
        FWU_LOG_MSG("%s: Skipping Metadata provisioning  \n\r", __func__);
        return PSA_SUCCESS;
    }

    ret = fwu_metadata_configure();
    if(ret) {
        FWU_LOG_MSG("%s: ERROR FWU Metadata configure failed \n\r", __func__);
        return ret;
    }

    ret = fwu_private_metadata_configure();
    if(ret) {
        FWU_LOG_MSG("%s: ERROR FWU Private Metadata configure failed \n\r", __func__);
        return ret;
    }

    FWU_LOG_MSG("%s: FWU METADATA PROVISIONED.\n\r", __func__);
    return PSA_SUCCESS;
}

static uint8_t get_fwu_image_state(
        struct fwu_metadata *metadata,
        struct fwu_private_metadata *priv_metadata,
	uint32_t fwu_image_index)
{
    FWU_LOG_MSG("%s: enter\n\r", __func__);

    if ((metadata->fw_desc.img_entry[fwu_image_index].img_props[metadata->active_index].accepted)
            == (IMAGE_NOT_ACCEPTED)) {
        FWU_LOG_MSG("%s: exit: Image %d PSA_FWU_TRIAL\n\r", __func__, fwu_image_index);
        return PSA_FWU_TRIAL;
    }

    FWU_LOG_MSG("%s: exit: Image %d PSA_FWU_READY\n\r", __func__, fwu_image_index);
    return PSA_FWU_READY;
}

static uint8_t get_fwu_agent_state(
        struct fwu_metadata *metadata,
        struct fwu_private_metadata *priv_metadata)
{
    FWU_LOG_MSG("%s: enter\n\r", __func__);

    if (priv_metadata->boot_index != metadata->active_index) {
        FWU_LOG_MSG("%s: exit: FWU Agent PSA_FWU_TRIAL (index mismatch)\n\r", __func__);
        return PSA_FWU_TRIAL;
    }

    for (int i=0; i < NR_OF_IMAGES_IN_FW_BANK; i++) {
        if(get_fwu_image_state(metadata, priv_metadata, i) == PSA_FWU_TRIAL) {
            FWU_LOG_MSG("%s: exit: FWU Agent PSA_FWU_TRIAL (an image still is in trial state)\n\r", __func__);
            return PSA_FWU_TRIAL;
        }
    }

    FWU_LOG_MSG("%s: exit: FWU Agent PSA_FWU_READY\n\r", __func__);
    return PSA_FWU_READY;
}

static psa_status_t erase_image(uint32_t image_offset, uint32_t image_size)
{
    int ret;
    uint32_t sectors;

    FWU_LOG_MSG("%s: enter\n\r", __func__);

    if ((image_offset % FWU_METADATA_FLASH_SECTOR_SIZE) != 0) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    if ((image_size % FWU_METADATA_FLASH_SECTOR_SIZE) != 0) {
        return PSA_ERROR_GENERIC_ERROR;
    }

    sectors = image_size / FWU_METADATA_FLASH_SECTOR_SIZE;

    FWU_LOG_MSG("%s: erasing sectors = %u, from offset = %u\n\r", __func__,
                     sectors, image_offset);

    for (int i = 0; i < sectors; i++) {
        ret = FWU_METADATA_FLASH_DEV.EraseSector(
                image_offset + (i * FWU_METADATA_FLASH_SECTOR_SIZE));
        if (ret != ARM_DRIVER_OK) {
            return PSA_ERROR_GENERIC_ERROR;
        }
    }

    FWU_LOG_MSG("%s: exit\n\r", __func__);
    return PSA_SUCCESS;
}

static psa_status_t fwu_select_previous(
        struct fwu_metadata *metadata,
        struct fwu_private_metadata *priv_metadata)
{
    psa_status_t ret;
    uint8_t current_state;
    uint32_t index;

    FWU_LOG_MSG("%s: enter\n\r", __func__);

    /* it is expected to receive this call only when
       in trial state */
    current_state = get_fwu_agent_state(metadata, priv_metadata);
    if (current_state != PSA_FWU_TRIAL) {
        return PSA_ERROR_BAD_STATE;
    }

    /* not expected to receive this call in this state, system
     * did not boot from previous active index */
    if (metadata->previous_active_index != priv_metadata->boot_index) {
        return PSA_ERROR_GENERIC_ERROR;
    }

    FWU_LOG_MSG("%s: trial state: active index = %u, previous active = %u\n\r",
            __func__, metadata->active_index, metadata->previous_active_index);

    index = metadata->previous_active_index;
    for (int i = 0; i < NR_OF_IMAGES_IN_FW_BANK; i++) {
        if (metadata->fw_desc.img_entry[i].img_props[index].accepted != IMAGE_ACCEPTED)
        {
            FWU_ASSERT(0);
        }
    }

    index = metadata->active_index;
    metadata->bank_state[index] = FWU_BANK_INVALID;
    metadata->active_index = metadata->previous_active_index;
    metadata->previous_active_index = index;

    priv_metadata->boot_attempted = 0;

    ret = private_metadata_write(priv_metadata);
    if (ret) {
        return ret;
    }
    metadata->crc_32 = crc32((uint8_t *)&metadata->version,
                              sizeof(struct fwu_metadata) - sizeof(uint32_t));

    ret = metadata_write_both_replica(metadata);
    if (ret) {
        return ret;
    }

    FWU_LOG_MSG("%s: in regular state by choosing previous active bank\n\r",
                 __func__);

    FWU_LOG_MSG("%s: exit: ret = %d\n\r", __func__, ret);
    return ret;

}

void bl1_get_active_bl2_image(uint32_t *offset)
{
    struct fwu_private_metadata priv_metadata;
    uint8_t current_state;
    uint32_t boot_attempted;
    uint32_t boot_index;

    FWU_LOG_MSG("%s: enter\n\r", __func__);

    if (fwu_metadata_init()) {
        FWU_ASSERT(0);
    }

    if (private_metadata_read(&priv_metadata)) {
        FWU_ASSERT(0);
    }

    if (metadata_read(&_metadata, 1)) {
        FWU_ASSERT(0);
    }

    current_state = get_fwu_agent_state(&_metadata, &priv_metadata);

    if (current_state == PSA_FWU_READY) {
        boot_index = _metadata.active_index;
        FWU_ASSERT(boot_index == priv_metadata.boot_index);
        boot_attempted = 0;
    } else if (current_state == PSA_FWU_TRIAL) {
        boot_attempted = (++priv_metadata.boot_attempted);
        FWU_LOG_MSG("%s: attempting boot number = %u\n\r",
                                        __func__, boot_attempted);
        if (boot_attempted <= MAX_BOOT_ATTEMPTS_PER_BANK) {
            boot_index = _metadata.active_index;
            FWU_LOG_MSG("%s: booting from trial bank: %u\n\r",
                                        __func__, boot_index);
        } else if (boot_attempted <= (2 * MAX_BOOT_ATTEMPTS_PER_BANK)) {
            boot_index = _metadata.previous_active_index;
            FWU_LOG_MSG("%s: gave up booting from trial bank\n\r", __func__);
            FWU_LOG_MSG("%s: booting from previous active bank: %u\n\r",
                                        __func__, boot_index);
        } else {
            FWU_LOG_MSG("%s: cannot boot system from any bank, halting...\n\r", __func__);
            FWU_ASSERT(0);
        }
    } else {
        FWU_ASSERT(0);
    }

    priv_metadata.boot_index = boot_index;
    if (private_metadata_write(&priv_metadata) < 0) {
        FWU_ASSERT(0);
    }

    if (boot_index == BANK_0) {
        *offset = SE_BL2_BANK_0_OFFSET;
    } else if (boot_index == BANK_1) {
        *offset = SE_BL2_BANK_1_OFFSET;
    } else {
        FWU_ASSERT(0);
    }

    FWU_LOG_MSG("%s: exit: booting from bank = %u, offset = 0x%x\n\r", __func__,
                        boot_index, *offset);

    return;
}

uint8_t bl2_get_boot_bank(void)
{
    uint8_t boot_index;
    struct fwu_private_metadata priv_metadata;
    FWU_LOG_MSG("%s: enter", __func__);
    if (fwu_metadata_init()) {
        FWU_ASSERT(0);
    }
    if (private_metadata_read(&priv_metadata)) {
        FWU_ASSERT(0);
    }
    boot_index = priv_metadata.boot_index;
    FWU_LOG_MSG("%s: exit: booting from bank = %u\r\n", __func__, boot_index);
    return boot_index;
}

static void disable_host_ack_timer(void)
{
    FWU_LOG_MSG("%s: timer to reset is disabled\n\r", __func__);
    SysTick->CTRL &= (~SysTick_CTRL_ENABLE_Msk);
}

static psa_status_t update_nv_counters(
                        struct fwu_private_metadata* priv_metadata)
{
    enum tfm_plat_err_t err;
    uint32_t security_cnt;
    enum tfm_nv_counter_t tfm_nv_counter_i;

    FWU_LOG_MSG("%s: enter\n\r", __func__);

    /* The FWU_BL2_NV_COUNTER (0) is not mirrored in the private metadata. It is
     * directly updated in the bl1_2_validate_image_at_addr() function, in
     * tfm/bl1/bl1_2/main.c.
     * Because of this, the index starts from FWU_TFM_NV_COUNTER (1). */
    for (int i = FWU_TFM_NV_COUNTER; i <= FWU_MAX_NV_COUNTER_INDEX; i++) {

        switch (i) {
            case FWU_TFM_NV_COUNTER:
                tfm_nv_counter_i = PLAT_NV_COUNTER_BL2_0;
                break;
            case FWU_TFA_NV_COUNTER:
                tfm_nv_counter_i = PLAT_NV_COUNTER_BL2_1;
                break;
            default:
                FWU_ASSERT(0);
                break;
        }

        err = tfm_plat_read_nv_counter(tfm_nv_counter_i,
                        sizeof(security_cnt), (uint8_t *)&security_cnt);
        if (err != TFM_PLAT_ERR_SUCCESS) {
            FWU_LOG_MSG("%s: couldn't read NV counter\n\r", __func__);
            return PSA_ERROR_GENERIC_ERROR;
        }

        if (priv_metadata->nv_counter[i] < security_cnt) {
            FWU_LOG_MSG("%s: staged NV counter is smaller than current value\n\r", __func__);
            return PSA_ERROR_GENERIC_ERROR;
        } else if (priv_metadata->nv_counter[i] > security_cnt) {
            FWU_LOG_MSG("%s: updating index = %u nv counter = %u->%u\n\r",
                        __func__, i, security_cnt,
                        priv_metadata->nv_counter[i]);
            err = tfm_plat_set_nv_counter(tfm_nv_counter_i,
                                    priv_metadata->nv_counter[i]);
            if (err != TFM_PLAT_ERR_SUCCESS) {
                FWU_LOG_MSG("%s: couldn't write NV counter\n\r", __func__);
                return PSA_ERROR_GENERIC_ERROR;
            }
        }

    }

    FWU_LOG_MSG("%s: exit\n\r", __func__);
    return PSA_SUCCESS;
}

psa_status_t corstone1000_fwu_host_ack(void)
{
    psa_status_t ret;
    struct fwu_private_metadata priv_metadata;
    uint8_t current_state;

    FWU_LOG_MSG("%s: enter\n\r", __func__);

    if (!is_initialized) {
        return PSA_ERROR_BAD_STATE;
    }

    Select_Write_Mode_For_Shared_Flash();

    /* This cannot be added to the fwu_metadata_init() because that function is
     * called before the logging is enabled by TF-M. */
    ret = fwu_metadata_check_and_correct_integrity();
    if (ret != PSA_SUCCESS) {
        FWU_LOG_MSG("fwu_metadata_check_and_correct_integrity failed\r\n");
        return ret;
    }

    if (metadata_read(&_metadata, 1)) {
        ret = PSA_ERROR_GENERIC_ERROR;
        goto out;
    }

    if (private_metadata_read(&priv_metadata)) {
        ret = PSA_ERROR_GENERIC_ERROR;
        goto out;
    }

    current_state = get_fwu_agent_state(&_metadata, &priv_metadata);
    if (current_state == PSA_FWU_READY) {

        ret = PSA_SUCCESS; /* nothing to be done */

	for (int i = 0; i < NR_OF_IMAGES_IN_FW_BANK; i++) {
            fmp_set_image_info(&fwu_image[i].image_guid,
                    priv_metadata.fmp_version[i],
                    priv_metadata.fmp_last_attempt_version[i],
                    priv_metadata.fmp_last_attempt_status[i]);
	}

        goto out;

    } else if (current_state != PSA_FWU_TRIAL) {
        FWU_ASSERT(0);
    }

    if (_metadata.active_index != priv_metadata.boot_index) {

        /* firmware update failed, revert back to previous bank */

	for (int i = 0; i < NR_OF_IMAGES_IN_FW_BANK; i++) {
            if(get_fwu_image_state(&_metadata, &priv_metadata, i) == PSA_FWU_TRIAL) {
                priv_metadata.fmp_last_attempt_version[i] =
                 _metadata.fw_desc.img_entry[i].img_props[_metadata.active_index].version;

                priv_metadata.fmp_last_attempt_status[i] = LAST_ATTEMPT_STATUS_ERROR_UNSUCCESSFUL;
	    }
        }
        ret = fwu_select_previous(&_metadata, &priv_metadata);

    }

    if (ret == PSA_SUCCESS) {
        disable_host_ack_timer();
        for (int i = 0; i < NR_OF_IMAGES_IN_FW_BANK; i++) {
            fmp_set_image_info(&fwu_image[i].image_guid,
                    priv_metadata.fmp_version[i],
                    priv_metadata.fmp_last_attempt_version[i],
                    priv_metadata.fmp_last_attempt_status[i]);
        }
    }

out:
    Select_XIP_Mode_For_Shared_Flash();

    FWU_LOG_MSG("%s: exit: ret = %d\n\r", __func__, ret);
    return ret;
}

static int systic_counter = 0;

void SysTick_Handler(void)
{
    systic_counter++;
    if (systic_counter % 10 == 0) {
        SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;
        stdio_output_string("*", 1);
        SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;
    }
    if (systic_counter == HOST_ACK_SYSTICK_TIMEOUT) {
        SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;
        stdio_output_string("timer expired!\n\r",
                           sizeof("timer expired!\n\r"));
        NVIC_SystemReset();
    }
}

/* When in trial state, start the timer for host to respond.
 * Diable timer when host responds back either by calling
 * corstone1000_fwu_accept_image or corstone1000_fwu_select_previous.
 * Otherwise, resets the system.
 */
void host_acknowledgement_timer_to_reset(void)
{
    struct fwu_private_metadata priv_metadata;
    uint8_t current_state;

    FWU_LOG_MSG("%s: enter\n\r", __func__);

    Select_Write_Mode_For_Shared_Flash();

    if (!is_initialized) {
        FWU_ASSERT(0);
    }

    if (private_metadata_read(&priv_metadata)) {
        FWU_ASSERT(0);
    }

    if (metadata_read(&_metadata, 1)) {
        FWU_ASSERT(0);
    }

    Select_XIP_Mode_For_Shared_Flash();

    current_state = get_fwu_agent_state(&_metadata, &priv_metadata);

    if (current_state == PSA_FWU_TRIAL) {
        FWU_LOG_MSG("%s: in trial state, starting host ack timer\n\r",
                        __func__);
        systic_counter = 0;
        if (SysTick_Config(SysTick_LOAD_RELOAD_Msk)) {
            FWU_LOG_MSG("%s: timer init failed\n\r", __func__);
            FWU_ASSERT(0);
        } else {
            FWU_LOG_MSG("%s: timer started: seconds to expire : %u\n\r",
                        __func__, HOST_ACK_SYSTICK_TIMEOUT);
        }
    }

    FWU_LOG_MSG("%s: exit\n\r", __func__);
    return;
}

/* stage nv counter into private metadata section of the flash.
 * staged nv counters are written to the otp when firmware update
 * is successful
 * the function assumes that the api is called in the boot loading
 * stage
 */
psa_status_t fwu_stage_nv_counter(enum fwu_nv_counter_index_t index,
        uint32_t img_security_cnt)
{
    struct fwu_private_metadata priv_metadata;

    FWU_LOG_MSG("%s: enter: index = %u, val = %u\n\r", __func__,
                                index, img_security_cnt);

    if (!is_initialized) {
        FWU_ASSERT(0);
    }

    if (index > FWU_MAX_NV_COUNTER_INDEX) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    if (private_metadata_read(&priv_metadata)) {
        FWU_ASSERT(0);
    }

    if (priv_metadata.nv_counter[index] != img_security_cnt) {
        priv_metadata.nv_counter[index] = img_security_cnt;
        if (private_metadata_write(&priv_metadata)) {
            FWU_ASSERT(0);
        }
    }

    FWU_LOG_MSG("%s: exit\n\r", __func__);
    return PSA_SUCCESS;
}

psa_status_t corstone1000_fwu_flash_image(void)
{
	return PSA_SUCCESS;
}

/* Verify if image index is valid or not */
bool is_image_index_valid(uint8_t fwu_image_index) {
    return (fwu_image_index != FWU_FAKE_IMAGE_INDEX &&
            fwu_image_index != FWU_IMAGE_INDEX_ESRT &&
	    fwu_image_index < FWU_COMPONENT_NUMBER);
}

static psa_status_t get_esrt_data(struct fwu_esrt_data_wrapper *esrt)
{
    FWU_LOG_MSG("%s: enter\n\r", __func__);

    if (!esrt)
    {
        FWU_LOG_MSG("%s: ERROR - Null pointer received\n\r", __func__);
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    psa_status_t ret;
    struct fwu_private_metadata priv_metadata;

    Select_Write_Mode_For_Shared_Flash();

    if (private_metadata_read(&priv_metadata)) {
        ret = PSA_ERROR_GENERIC_ERROR;
        goto out;
    }

    esrt->data.fw_resource_count = NR_OF_IMAGES_IN_FW_BANK;
    esrt->data.fw_resource_count_max = NR_OF_IMAGES_IN_FW_BANK;
    esrt->data.fw_resource_version = EFI_SYSTEM_RESOURCE_TABLE_FIRMWARE_RESOURCE_VERSION;

    for (int i = 0; i < NR_OF_IMAGES_IN_FW_BANK; i++)
    {
        memcpy(&esrt->entries[i].fw_class, &fwu_image[i].image_guid, sizeof(struct efi_guid));
        esrt->entries[i].fw_version = priv_metadata.fmp_version[i];
        esrt->entries[i].lowest_supported_fw_version = FWU_IMAGE_INITIAL_VERSION;
        esrt->entries[i].last_attempt_version = priv_metadata.fmp_last_attempt_version[i];
        esrt->entries[i].last_attempt_status = priv_metadata.fmp_last_attempt_status[i];
    }
    ret = PSA_SUCCESS;

out:
    Select_XIP_Mode_For_Shared_Flash();
    FWU_LOG_MSG("%s: exit: ret = %d\n\r", __func__, ret);
    return ret;
}

static psa_status_t fwu_accept_image(struct fwu_metadata *metadata,
        struct fwu_private_metadata *priv_metadata,
        const psa_fwu_component_t *trials,
        uint8_t number)
{
    uint8_t current_state;
    uint32_t image_bank_offset;
    uint32_t active_bank_index;
    uint32_t fwu_image_index;
    psa_status_t ret;

    FWU_LOG_MSG("%s: enter\n\r", __func__);


    /* booted from previous_active_bank, not expected
     * to receive this call in this state, rather host should
     * call corstone1000_fwu_select_previous */
    if (metadata->active_index != priv_metadata->boot_index) {
        return PSA_ERROR_BAD_STATE;
    }

    active_bank_index = metadata->active_index;
    metadata->bank_state[active_bank_index] = FWU_BANK_ACCEPTED;

    for (int i = 0; i < number; i++) {

        if (!is_image_index_valid(trials[i])) {
            FWU_LOG_MSG("%s: Invalid image index received \n\r", __func__);
            continue;
        }

        /* it is expected to receive this call only when
           in trial state */
        fwu_image_index = trials[i] - FWU_FAKE_IMAGES_INDEX_COUNT;

        current_state = get_fwu_image_state(metadata, priv_metadata, fwu_image_index);
        if (current_state != PSA_FWU_TRIAL) {
            return PSA_ERROR_BAD_STATE;
        }

        metadata->fw_desc.img_entry[fwu_image_index].img_props[active_bank_index].accepted =
                                                            IMAGE_ACCEPTED;
    }

    priv_metadata->boot_attempted = 0;

    ret = private_metadata_write(priv_metadata);
    if (ret) {
        return ret;
    }
    metadata->crc_32 = crc32((uint8_t *)&metadata->version,
                              sizeof(struct fwu_metadata) - sizeof(uint32_t));

    ret = metadata_write_both_replica(metadata);
    if (ret) {
        return ret;
    }

    FWU_LOG_MSG("%s: exit: fwu state is changed to regular, ret - %d\n\r", __func__, ret);
    return ret;
}

static psa_status_t uint_to_image_version(uint32_t ver_in, psa_fwu_image_version_t *ver_out)
{
    if (!ver_out) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    ver_out->major = (uint8_t)((ver_in >> 24) & 0xF);
    ver_out->minor = (uint8_t)((ver_in >> 16) & 0xF);
    ver_out->patch = (uint16_t)(ver_in & 0xFF);
    /* There's no room for the build number in the TS */
    return PSA_SUCCESS;
}

static void fmp_header_image_info_init()
{
    for (int i=0; i<FWU_COMPONENT_NUMBER; i++)
    {
        fmp_header_image_info[i].fmp_hdr_size_recvd = 0;
	fmp_header_image_info[i].image_size_recvd = 0;
	memset(&fmp_header_image_info[i].fmp_hdr, 0, sizeof(fmp_header_image_info[i].fmp_hdr));
    }
}

static psa_status_t erase_staging_area(struct fwu_metadata* metadata, psa_fwu_component_t component)
{
    if (!metadata) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    if (!is_image_index_valid(component)) {
        FWU_LOG_MSG("%s: Invalid Component received \n\r", __func__);
	return PSA_ERROR_GENERIC_ERROR;
    }

    uint32_t active_index = metadata->active_index;
    uint32_t bank_offset;
    uint32_t image_offset;
    uint8_t fwu_image_index = component - FWU_FAKE_IMAGES_INDEX_COUNT; /* Decrement to get the correct fwu image index */

    FWU_LOG_MSG("%s: enter\n\r", __func__);

    if (active_index == BANK_0) {
        bank_offset = BANK_1_PARTITION_OFFSET;
    } else if (active_index == BANK_1) {
        bank_offset = BANK_0_PARTITION_OFFSET;
    } else {
        FWU_LOG_MSG("ERROR: %s: active_index %d\n\r",__func__,active_index);
        return PSA_ERROR_GENERIC_ERROR;
    }

    image_offset = bank_offset + fwu_image[fwu_image_index].image_offset;
    if (erase_image(image_offset, fwu_image[fwu_image_index].image_size)) {
        return PSA_ERROR_GENERIC_ERROR;
    }

    FWU_LOG_MSG("%s: exit: Staging area erased succesfully \n\r", __func__);
    return PSA_SUCCESS;
}

psa_status_t fwu_bootloader_init(void)
{
    psa_status_t ret;

    FWU_LOG_MSG("%s: enter\n\r", __func__);

    ret = fwu_metadata_init();
    if (ret) {
        return ret;
    }

    /* Initialize the fmp_header_image_info object */
    fmp_header_image_info_init();

    FWU_LOG_MSG("%s: exit: Initialized\n\r", __func__);

    return PSA_SUCCESS;
}

psa_status_t fwu_bootloader_staging_area_init(psa_fwu_component_t component,
                                              const void *manifest,
                                              size_t manifest_size)
{
    if (component >= FWU_COMPONENT_NUMBER) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    if (!is_initialized) {
        return PSA_ERROR_BAD_STATE;
    }

    psa_status_t ret;

    FWU_LOG_MSG("%s: enter\n\r", __func__);

    Select_Write_Mode_For_Shared_Flash();

    if (metadata_read(&_metadata, 1)) {
        ret = PSA_ERROR_GENERIC_ERROR;
        goto out;
    }

    ret = erase_staging_area(&_metadata, component);

out:
    Select_XIP_Mode_For_Shared_Flash();

    FWU_LOG_MSG("%s: exit: ret = %d\n\r", __func__, ret);
    return ret;
}

psa_status_t parse_fmp_header(psa_fwu_component_t component, const void *block, size_t size)
{
    /* Parse the incoming block to make sure complete FMP header is received */
    if (sizeof(fmp_header_image_info[component].fmp_hdr) >= (fmp_header_image_info[component].fmp_hdr_size_recvd + size)) {
        memcpy(&fmp_header_image_info[component].fmp_hdr, block, size);
        fmp_header_image_info[component].fmp_hdr_size_recvd += size;
        return PSA_ERROR_INSUFFICIENT_DATA;
    }
    if (fmp_header_image_info[component].fmp_hdr_size_recvd != sizeof(fmp_header_image_info[component].fmp_hdr)) {
        memcpy(&fmp_header_image_info[component].fmp_hdr,
                block,
                (sizeof(fmp_header_image_info[component].fmp_hdr) - fmp_header_image_info[component].fmp_hdr_size_recvd));

        fmp_header_image_info[component].fmp_hdr_size_recvd = sizeof(fmp_header_image_info[component].fmp_hdr);
	return PSA_SUCCESS;
    }

}
psa_status_t fwu_bootloader_load_image(psa_fwu_component_t component,
                                       size_t block_offset,
                                       const void *block,
                                       size_t block_size)
{

    if (block == NULL) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    if (!is_initialized) {
        return PSA_ERROR_BAD_STATE;
    }

    if (!is_image_index_valid(component)) {
        FWU_LOG_MSG("%s: Invalid Component received \n\r", __func__);
        return PSA_ERROR_GENERIC_ERROR;
    }

    psa_status_t ret;
    int drv_ret;
    int image_index;
    uint32_t bank_offset;
    uint32_t active_index;
    uint32_t previous_active_index;
    uint32_t nr_images;
    uint32_t current_state;
    uint32_t image_offset;
    uint32_t fw_version;
    uint8_t fwu_image_index = component - FWU_FAKE_IMAGES_INDEX_COUNT;
    struct fwu_private_metadata priv_metadata;

    FWU_LOG_MSG("%s: enter: block_offset = %u, block = 0x%p, block_size = %u\n\r"
                , __func__, block_offset, block, block_size);

    /* Parse the incoming block to make sure complete FMP header is received */
    if (fmp_header_image_info[fwu_image_index].fmp_hdr_size_recvd != sizeof(fmp_header_image_info[fwu_image_index].fmp_hdr)) {
        ret = parse_fmp_header(fwu_image_index, block, block_size);
        if(ret == PSA_ERROR_INSUFFICIENT_DATA) {
            return PSA_SUCCESS;
        }
        if (ret == PSA_SUCCESS) {
            block_size -= fmp_header_image_info[fwu_image_index].fmp_hdr_size_recvd;
	    block += fmp_header_image_info[fwu_image_index].fmp_hdr_size_recvd;
        }
    }

    /* Store the version of new firmare */
    fw_version = fmp_header_image_info[fwu_image_index].fmp_hdr.fw_version;
    FWU_LOG_MSG("%s: Updated info after payload header parsing: block_offset = %u, block = 0x%p, block_size = %u\n\r"
                , __func__, block_offset, block, block_size);
    /* Check if it is the dummy FMP or not */
    if (!fmp_header_image_info[fwu_image_index].fmp_hdr.header_size)
    {
       FWU_LOG_MSG("%s: Dummy FMP received \n\r", __func__);
       /* Do something for dummy FMP's */
       return PSA_ERROR_GENERIC_ERROR;
    }

    /* Write the block containing actual image to flash */

    Select_Write_Mode_For_Shared_Flash();

    if (metadata_read(&_metadata, 1)) {
        ret =  PSA_ERROR_GENERIC_ERROR;
        goto out;
    }

    if (private_metadata_read(&priv_metadata)) {
        ret =  PSA_ERROR_GENERIC_ERROR;
        goto out;
    }

    active_index = _metadata.active_index;
    FWU_LOG_MSG("FMP version: 0x%d, metadata version : 0x%d\n", fw_version,
                                                                _metadata.fw_desc.img_entry[fwu_image_index].img_props[active_index].version);
    if (fw_version <=
                _metadata.fw_desc.img_entry[fwu_image_index].img_props[active_index].version)
    {
	/* Version is extracted from the fmp_payload_header */
        priv_metadata.fmp_last_attempt_version[fwu_image_index] = fmp_header_image_info[fwu_image_index].fmp_hdr.fw_version;
        priv_metadata.fmp_last_attempt_status[fwu_image_index] = LAST_ATTEMPT_STATUS_ERROR_UNSUCCESSFUL;
        private_metadata_write(&priv_metadata);

        fmp_set_image_info(&fwu_image[fwu_image_index].image_guid,
                priv_metadata.fmp_version[fwu_image_index],
                priv_metadata.fmp_last_attempt_version[fwu_image_index],
                priv_metadata.fmp_last_attempt_status[fwu_image_index]);

        FWU_LOG_MSG("ERROR: %s: version error\n\r",__func__);
	ret = PSA_OPERATION_INCOMPLETE;
	goto out;
    }

    if (active_index == BANK_0) {
        previous_active_index = BANK_1;
        bank_offset = BANK_1_PARTITION_OFFSET;
    } else if (active_index == BANK_1) {
        previous_active_index = BANK_0;
        bank_offset = BANK_0_PARTITION_OFFSET;
    } else {
        FWU_LOG_MSG("ERROR: %s: active_index %d\n\r",__func__,active_index);
        return PSA_ERROR_DATA_INVALID;
    }

    image_offset = bank_offset + fwu_image[fwu_image_index].image_offset;

    /* Firmware update process can only start in regular state. */
    current_state = get_fwu_image_state(&_metadata, &priv_metadata, fwu_image_index);
    if (current_state != PSA_FWU_READY) {
        ret =  PSA_ERROR_BAD_STATE;
        goto out;
    }

    FWU_LOG_MSG("%s: writing image to the flash at offset = %u...\n\r",
                      __func__, (image_offset + fmp_header_image_info[fwu_image_index].image_size_recvd));
    drv_ret = FWU_METADATA_FLASH_DEV.ProgramData(image_offset + fmp_header_image_info[fwu_image_index].image_size_recvd, block, block_size);
    FWU_LOG_MSG("%s: images are written to bank offset = %u\n\r", __func__,
                     image_offset);
    if (drv_ret < 0 || drv_ret != block_size) {
        FWU_LOG_MSG("Flashing image %d is not successful\n\r", component);

        /* Version is extracted from the fmp_payload_header */
        priv_metadata.fmp_last_attempt_version[fwu_image_index] = fmp_header_image_info[fwu_image_index].fmp_hdr.fw_version;
        priv_metadata.fmp_last_attempt_status[fwu_image_index] = LAST_ATTEMPT_STATUS_ERROR_UNSUCCESSFUL;

        private_metadata_write(&priv_metadata);

        fmp_set_image_info(&fwu_image[fwu_image_index].image_guid,
                priv_metadata.fmp_version[fwu_image_index],
                priv_metadata.fmp_last_attempt_version[fwu_image_index],
                priv_metadata.fmp_last_attempt_status[fwu_image_index]);
        ret = PSA_OPERATION_INCOMPLETE;
	goto out;
    }
    else {
        ret = PSA_SUCCESS;
    }
    FWU_LOG_MSG("%s: images are written to bank return status = %u\n\r", __func__,
                     ret);
    fmp_header_image_info[fwu_image_index].image_size_recvd += block_size;

out:
    Select_XIP_Mode_For_Shared_Flash();

    FWU_LOG_MSG("%s: exit: ret = %d\n\r", __func__, ret);
    return ret;
}

static psa_status_t fwu_update_metadata(const psa_fwu_component_t *candidates, uint8_t number)
{
    int ret;
    uint32_t active_index;
    uint32_t bank_offset;
    uint32_t previous_active_index;
    uint8_t fwu_image_index;

    FWU_LOG_MSG("%s: enter function\n\r", __func__);

    Select_Write_Mode_For_Shared_Flash();

    if (metadata_read(&_metadata, 1)) {
        ret =  PSA_ERROR_GENERIC_ERROR;
        goto out;
    }
    active_index = _metadata.active_index;

    if (active_index == BANK_0) {
        previous_active_index = BANK_1;
        bank_offset = BANK_1_PARTITION_OFFSET;
    } else if (active_index == BANK_1) {
        previous_active_index = BANK_0;
        bank_offset = BANK_0_PARTITION_OFFSET;
    } else {
        FWU_LOG_MSG("ERROR: %s: active_index %d\n\r",__func__,active_index);
        ret = PSA_ERROR_DATA_INVALID;
	goto out;
    }

    _metadata.active_index = previous_active_index;
    _metadata.previous_active_index = active_index;
    _metadata.bank_state[previous_active_index] = FWU_BANK_VALID;

    /* Change system state to trial bank state */
    for (int i = 0; i < number; i++) {
        /* Skip image with index 0 and ESRT image */
	if(!is_image_index_valid(candidates[i])) {
            FWU_LOG_MSG("%s: Invalid image index received \n\r", __func__);
            continue;
        }

        fwu_image_index = candidates[i] - FWU_FAKE_IMAGES_INDEX_COUNT;
        _metadata.fw_desc.img_entry[fwu_image_index].img_props[previous_active_index].accepted =
                                                        IMAGE_NOT_ACCEPTED;
        _metadata.fw_desc.img_entry[fwu_image_index].img_props[previous_active_index].version = fmp_header_image_info[fwu_image_index].fmp_hdr.fw_version;
    }

    _metadata.crc_32 = crc32((uint8_t *)&_metadata.version,
                              sizeof(struct fwu_metadata) - sizeof(uint32_t));

    ret = metadata_write_both_replica(&_metadata);
    if (ret) {
        goto out;
    }

    ret = PSA_SUCCESS;

out:
    Select_XIP_Mode_For_Shared_Flash();

    FWU_LOG_MSG("%s: exit: ret = %d\n\r", __func__, ret);
    return ret;
}

static psa_status_t copy_image_from_other_bank(int image_index,
                                               uint32_t active_index,
                                               uint32_t previous_active_index)
{
    uint32_t bank_offset[NR_OF_FW_BANKS] = {BANK_0_PARTITION_OFFSET, BANK_1_PARTITION_OFFSET};
    uint8_t data[FLASH_CHUNK_SIZE];
    size_t remaining_size = fwu_image[image_index].image_size;
    size_t data_size;
    size_t offset_read = bank_offset[active_index] + fwu_image[image_index].image_offset;
    size_t offset_write = bank_offset[previous_active_index] + fwu_image[image_index].image_offset;
    int data_transferred_count;

    FWU_LOG_MSG("%s: Enter \n\r", __func__);

    psa_status_t ret = erase_image(offset_write, fwu_image[image_index].image_size);
    if (ret != PSA_SUCCESS) {
        FWU_LOG_MSG("%s: ERROR - Flash erase failed for Image: %d\n\r", __func__, image_index);
        return ret;
    }

    while(remaining_size > 0) {
        data_size = (remaining_size > FLASH_CHUNK_SIZE) ? FLASH_CHUNK_SIZE : remaining_size;

        /* read image data from flash */
        data_transferred_count = FWU_METADATA_FLASH_DEV.ReadData(offset_read, data, data_size);
        if (data_transferred_count < 0) {
            FWU_LOG_MSG("%s: ERROR - Flash read failed (ret = %d)\n\r", __func__, data_transferred_count);
            return PSA_ERROR_STORAGE_FAILURE;
        }

        if (data_transferred_count != data_size) {
            FWU_LOG_MSG("%s: ERROR - Incomplete metadata read (expected %zu, got %d)\n\r",
                        __func__, data_size, data_transferred_count);
            return PSA_ERROR_INSUFFICIENT_DATA;
        }

        offset_read += data_size;
	
        /* write image data to flash */
        data_transferred_count = FWU_METADATA_FLASH_DEV.ProgramData(offset_write, data, data_size);
        if (data_transferred_count < 0) {
            FWU_LOG_MSG("%s: ERROR - Flash read failed (ret = %d)\n\r", __func__, data_transferred_count);
            return PSA_ERROR_STORAGE_FAILURE;
        }

        if (data_transferred_count != data_size) {
            FWU_LOG_MSG("%s: ERROR - Incomplete metadata write (expected %zu, written %d)\n\r",
                        __func__, data_size, data_transferred_count);
            return PSA_ERROR_INSUFFICIENT_DATA;
        }

        offset_write += data_size;
	remaining_size -= data_size;
    }

    FWU_LOG_MSG("%s: exit \n\r", __func__);
    return PSA_SUCCESS;
}

static psa_status_t maintain_bank_consistency(void)
{
    psa_status_t ret;
    uint32_t active_index;
    uint32_t previous_active_index;
    struct fwu_private_metadata priv_metadata;

    FWU_LOG_MSG("%s: Enter \n\r", __func__);
    Select_Write_Mode_For_Shared_Flash();

    if (metadata_read(&_metadata, 1) || private_metadata_read(&priv_metadata)) {
        ret =  PSA_ERROR_GENERIC_ERROR;
        goto out;
    }

    active_index = _metadata.active_index;
    if (active_index == BANK_0) {
        previous_active_index = BANK_1;
    } else if (active_index == BANK_1) {
        previous_active_index = BANK_0;
    } else {
        FWU_LOG_MSG("ERROR: %s: active_index %d\n\r",__func__,active_index);
        ret = PSA_ERROR_DATA_INVALID;
        goto out;
    }

    for (int i=0; i<NR_OF_IMAGES_IN_FW_BANK; i++)
    {
        /* Check if image is received from the FWU client */
        if (fmp_header_image_info[i].image_size_recvd) {
            continue;
        }

        ret = copy_image_from_other_bank(i, active_index, previous_active_index);
        if(ret) {
            FWU_LOG_MSG("ERROR: %s: copy_image_from_other_bank failed for Image : %d\n\r",__func__, i);
       	    return ret;
	}

        _metadata.fw_desc.img_entry[i].img_props[previous_active_index].version =
         _metadata.fw_desc.img_entry[i].img_props[active_index].version;
        _metadata.fw_desc.img_entry[i].img_props[previous_active_index].accepted = IMAGE_ACCEPTED;
        priv_metadata.fmp_version[i] =
         _metadata.fw_desc.img_entry[i].img_props[previous_active_index].version;
        priv_metadata.fmp_last_attempt_version[i] =
        _metadata.fw_desc.img_entry[i].img_props[previous_active_index].version;

        priv_metadata.fmp_last_attempt_status[i] = LAST_ATTEMPT_STATUS_SUCCESS;

        ret = private_metadata_write(&priv_metadata);
        if (ret) {
            goto out;
        }

        _metadata.crc_32 = crc32((uint8_t *)&_metadata.version,
                                  sizeof(struct fwu_metadata) - sizeof(uint32_t));

        ret = metadata_write_both_replica(&_metadata);
        if (ret) {
            goto out;
        }

    }
    ret = PSA_SUCCESS;

out:
    Select_XIP_Mode_For_Shared_Flash();
    FWU_LOG_MSG("%s: exit: ret = %d\n\r", __func__, ret);
    return ret;

}

psa_status_t fwu_bootloader_install_image(const psa_fwu_component_t *candidates, uint8_t number)
{
    if (!candidates) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }
    if (!is_initialized) {
        return PSA_ERROR_BAD_STATE;
    }

    psa_status_t ret;
    FWU_LOG_MSG("%s: enter function\n\r", __func__);

    /* Copy images from other bank which are not received by FWU client */
    ret = maintain_bank_consistency();
    if(ret) {
        FWU_LOG_MSG("%s: ERROR: Copying images from other bank failed, ret = %d\n\r", __func__, ret);
        return PSA_ERROR_INSUFFICIENT_DATA;
    }

    /* Update the metadata */
    ret = fwu_update_metadata(candidates, number);

    if (ret == PSA_SUCCESS) {
        is_installed = true;
    }

    FWU_LOG_MSG("%s: exit: ret = %d\n\r", __func__, ret);
    return ret;
}

psa_status_t fwu_bootloader_mark_image_accepted(const psa_fwu_component_t *trials,
                                                uint8_t number)
{    
    if (!trials) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    if (!is_initialized) {
        return PSA_ERROR_BAD_STATE;
    }

    psa_status_t ret;
    struct fwu_private_metadata priv_metadata;
    uint8_t current_state;
    uint8_t fwu_image_index;

    FWU_LOG_MSG("%s: enter\n\r", __func__);

    Select_Write_Mode_For_Shared_Flash();

    /* This cannot be added to the fwu_metadata_init() because that function is
     * called before the logging is enabled by TF-M. */
    ret = fwu_metadata_check_and_correct_integrity();
    if (ret != PSA_SUCCESS) {
        FWU_LOG_MSG("fwu_metadata_check_and_correct_integrity failed\r\n");
        return ret;
    }

    if (metadata_read(&_metadata, 1)) {
        ret = PSA_ERROR_GENERIC_ERROR;
        goto out;
    }

    if (private_metadata_read(&priv_metadata)) {
        ret = PSA_ERROR_GENERIC_ERROR;
        goto out;
    }

    /* firmware update successful */
    for (int i = 0; i < number; i++) {
	if(!is_image_index_valid(trials[i])) {
            FWU_LOG_MSG("%s: Invalid image index received \n\r", __func__);
            continue;
        }

        fwu_image_index = trials[i] - FWU_FAKE_IMAGES_INDEX_COUNT;

        current_state = get_fwu_image_state(&_metadata, &priv_metadata, fwu_image_index);
        if (current_state == PSA_FWU_READY) {
            fmp_set_image_info(&fwu_image[fwu_image_index].image_guid,
                    priv_metadata.fmp_version[fwu_image_index],
                    priv_metadata.fmp_last_attempt_version[fwu_image_index],
                    priv_metadata.fmp_last_attempt_status[fwu_image_index]);
            continue;

        } else if (current_state != PSA_FWU_TRIAL) {
            FWU_ASSERT(0);
        }

        priv_metadata.fmp_version[fwu_image_index] =
         _metadata.fw_desc.img_entry[fwu_image_index].img_props[_metadata.active_index].version;
        priv_metadata.fmp_last_attempt_version[fwu_image_index] =
        _metadata.fw_desc.img_entry[fwu_image_index].img_props[_metadata.active_index].version;

        priv_metadata.fmp_last_attempt_status[fwu_image_index] = LAST_ATTEMPT_STATUS_SUCCESS;
    }

    ret = fwu_accept_image(&_metadata,
                            &priv_metadata, trials, number);
    if (!ret) {
        ret = update_nv_counters(&priv_metadata);
    }

    if (ret == PSA_SUCCESS) {
        disable_host_ack_timer();
        for(int i = 0; i < number; i++) {

            if(!is_image_index_valid(trials[i])) {
                FWU_LOG_MSG("%s: Invalid image index received \n\r", __func__);
                continue;
            }

            fwu_image_index = trials[i] - FWU_FAKE_IMAGES_INDEX_COUNT;
            fmp_set_image_info(&fwu_image[fwu_image_index].image_guid,
                    priv_metadata.fmp_version[fwu_image_index],
                    priv_metadata.fmp_last_attempt_version[fwu_image_index],
                    priv_metadata.fmp_last_attempt_status[fwu_image_index]);
        }
    }

out:
    Select_XIP_Mode_For_Shared_Flash();
    FWU_LOG_MSG("%s: exit: ret = %d\n\r", __func__, ret);
    return ret;
}

/* Reject the staged image. */
psa_status_t fwu_bootloader_reject_staged_image(psa_fwu_component_t component)
{

    if (!is_image_index_valid(component)) {
        FWU_LOG_MSG("%s: Invalid image index received \n\r", __func__);
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    if (!is_initialized) {
        return PSA_ERROR_BAD_STATE;
    }

    int ret;
    uint32_t active_index;;
    uint32_t bank_offset;
    uint32_t image_offset;
    uint8_t image_index = component - FWU_FAKE_IMAGES_INDEX_COUNT;    /* Decrement to get the correct fwu image index */

    FWU_LOG_MSG("%s: enter\n\r", __func__);
    Select_Write_Mode_For_Shared_Flash();

    if (metadata_read(&_metadata, 1)) {
        ret =  PSA_ERROR_GENERIC_ERROR;
        goto out;
    }
    active_index = _metadata.active_index;

    if (active_index == BANK_0) {
        bank_offset = BANK_1_PARTITION_OFFSET;
    } else if (active_index == BANK_1) {
        bank_offset = BANK_0_PARTITION_OFFSET;
    } else {
        FWU_LOG_MSG("ERROR: %s: active_index %d\n\r",__func__,active_index);
        ret = PSA_ERROR_GENERIC_ERROR;
	goto out;
    }

    image_offset = bank_offset + fwu_image[image_index].image_offset;

    if (erase_image(image_offset, fwu_image[image_index].image_size)) {
        return PSA_ERROR_GENERIC_ERROR;
    }

out:
    Select_XIP_Mode_For_Shared_Flash();
    FWU_LOG_MSG("%s: exit: ret = %d\n\r", __func__, ret);
    return ret;
}

/* Reject the running image in trial state. */
psa_status_t fwu_bootloader_reject_trial_image(psa_fwu_component_t component)
{

    if (!is_image_index_valid(component)) {
        FWU_LOG_MSG("%s: Invalid image index received \n\r", __func__);
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    struct fwu_private_metadata priv_metadata;
    int ret;
    uint8_t fwu_image_index = component - FWU_FAKE_IMAGES_INDEX_COUNT;    /* Decrement to get the correct fwu image index */

    FWU_LOG_MSG("%s: enter\n\r", __func__);

    /* Disable host ackowledgement timer */
    disable_host_ack_timer();

    /* Update the metadata active index to previous active index as trial images have been rejected */

    Select_Write_Mode_For_Shared_Flash();
    if (metadata_read(&_metadata, 1) || private_metadata_read(&priv_metadata)) {
        ret =  PSA_ERROR_GENERIC_ERROR;
        goto out;
    }
    priv_metadata.fmp_last_attempt_version[fwu_image_index] =
     _metadata.fw_desc.img_entry[fwu_image_index].img_props[_metadata.active_index].version;

    priv_metadata.fmp_last_attempt_status[fwu_image_index] = LAST_ATTEMPT_STATUS_ERROR_UNSUCCESSFUL;

    ret = fwu_select_previous(&_metadata, &priv_metadata);

out:
    Select_XIP_Mode_For_Shared_Flash();
    FWU_LOG_MSG("%s: exit: ret = %d\n\r", __func__, ret);
    return ret;
}

psa_status_t fwu_bootloader_abort(psa_fwu_component_t component)
{
    /* Not to be implemented as PSA FWU Trusted-Services is not using this function */
    return PSA_SUCCESS;
}

psa_status_t fwu_bootloader_get_image_info(psa_fwu_component_t component,
                                           bool query_state,
                                           bool query_impl_info,
                                           psa_fwu_component_info_t *info)
{
    if (component >= FWU_COMPONENT_NUMBER) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    /* Skipping image at 0th index 
     * The image index in the capsule starts from 1 
     */
    if (!component) {
        if(query_state)
            info->state = PSA_FWU_READY;
        return PSA_SUCCESS;
    }

    struct fwu_private_metadata priv_metadata;
    uint32_t version;
    uint8_t fwu_image_index = component - 1;
    uint8_t current_state;
    psa_status_t ret;

    FWU_LOG_MSG("%s: enter\n\r", __func__);


    Select_Write_Mode_For_Shared_Flash();
    if (private_metadata_read(&priv_metadata)) {
        ret = PSA_ERROR_GENERIC_ERROR;
        goto out;
    }

    if (metadata_read(&_metadata, 1)) {
        ret = PSA_ERROR_GENERIC_ERROR;
        goto out;
    }

    if (component == FWU_IMAGE_INDEX_ESRT) {

        size_t esrt_size = TFM_FWU_MAX_DIGEST_SIZE;
        if (TFM_FWU_MAX_DIGEST_SIZE > sizeof(struct fwu_esrt_data_wrapper))
            esrt_size = sizeof(struct fwu_esrt_data_wrapper);

        /* Populate the ESRT */
        ret = get_esrt_data(&esrt);
        if (ret) {
            FWU_LOG_MSG("%s: ERROR : Unable to populate ESRT \n\r", __func__);
	    goto out;
        }

        memcpy(&info->impl.candidate_digest, &esrt, esrt_size);
	if (query_state) {
            info->state = PSA_FWU_READY;
        }
    }
    else {
        current_state = get_fwu_image_state(&_metadata, &priv_metadata, fwu_image_index);
        if (query_state) {
            info->state = current_state;
        }

        /* Fill the other required fields for component */
        info->max_size = fwu_image[fwu_image_index].image_size;

        version = _metadata.fw_desc.img_entry[fwu_image_index].img_props[_metadata.active_index].version;
        ret = uint_to_image_version(version, &info->version);
        if (ret) {
            FWU_LOG_MSG("%s: ERROR : Image version not found \n\r", __func__);
            goto out;
        }
    }

out:
    Select_XIP_Mode_For_Shared_Flash();
    FWU_LOG_MSG("%s: exit: ret = %d\n\r", __func__, ret);
    return ret;
}

psa_status_t fwu_bootloader_clean_component(psa_fwu_component_t component)
{
    return PSA_SUCCESS;
}
