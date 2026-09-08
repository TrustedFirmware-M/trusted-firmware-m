/*
 * Copyright (c) 2024, ARM Limited and Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <errno.h>
#include <inttypes.h>
#include <stdio.h>
#include <string.h>
#include <efi.h>
#include <gpt.h>
#include <mbr.h>
#include <partition.h>
#include <soft_crc.h>
#include <debug.h>
#include <flash_layout.h>
#include <Driver_Flash.h>
#include <device.h>

static uint8_t mbr_sector[PLAT_PARTITION_BLOCK_SIZE];
static partition_entry_list_t list;

extern ARM_DRIVER_FLASH FLASH_DEV_NAME;

#if STM32_PARTITION_DEBUG
static void dump_entries(int num) {
	char name[EFI_NAMELEN];
	int i, j, len;

	INFO("Partition table with %d entries:\n", num);
	for (i = 0; i < num; i++) {
		len = snprintf(name, EFI_NAMELEN, "%s", list.list[i].name);
		for (j = 0; j < EFI_NAMELEN - len - 1; j++) {
			name[len + j] = ' ';
		}
		name[EFI_NAMELEN - 1] = '\0';
		INFO("%d: %s %x%x %d\n", i + 1, name,
		     (uint32_t)(list.list[i].start >> 32),
		     (uint32_t)list.list[i].start,
		     (uint32_t)(list.list[i].start + list.list[i].length - 4));
	}
}
#else
#define dump_entries(num) ((void)num)
#endif

/*
 * Load the first sector that carries MBR header.
 * The MBR boot signature should be always valid whether it's MBR or GPT.
 */
static int load_mbr_header(mbr_entry_t *mbr_entry) {
	size_t bytes_read;
	uintptr_t offset;

	if (mbr_entry == NULL) {
		return -EINVAL;
	}

	/* MBR partition table is in LBA0. */
	bytes_read = FLASH_DEV_NAME.ReadData(MBR_OFFSET, &mbr_sector,
					     PLAT_PARTITION_BLOCK_SIZE);
	if (bytes_read != PLAT_PARTITION_BLOCK_SIZE) {
		WARN("Failed to read data (%i)\n", bytes_read);
		return -EINVAL;
	}

	/* Check MBR boot signature. */
	if ((mbr_sector[LEGACY_PARTITION_BLOCK_SIZE - 2] != MBR_SIGNATURE_FIRST) ||
	    (mbr_sector[LEGACY_PARTITION_BLOCK_SIZE - 1] != MBR_SIGNATURE_SECOND)) {
		ERROR("MBR signature isn't correct\n");
		return -ENOENT;
	}

	offset = (uintptr_t)&mbr_sector + MBR_PRIMARY_ENTRY_OFFSET;
	memcpy(mbr_entry, (void *)offset, sizeof(mbr_entry_t));

	return 0;
}

/*
 * Load GPT header and check the GPT signature and header CRC.
 * If partition numbers could be found, check & update it.
 */
static int load_gpt_header(void) {
	gpt_header_t header;
	size_t bytes_read;
	uint32_t header_crc, calc_crc;

	bytes_read = FLASH_DEV_NAME.ReadData(GPT_HEADER_OFFSET, &header,
					     sizeof(gpt_header_t));
	if (bytes_read != sizeof(gpt_header_t)) {
		WARN("Failed to read data (%i)\n", bytes_read);
		return -EINVAL;
	}

	if (memcmp(header.signature, GPT_SIGNATURE, sizeof(header.signature)) != 0) {
		return -EINVAL;
	}

	/*
	 * UEFI Spec 2.8 March 2019 Page 119: HeaderCRC32 value is
	 * computed by setting this field to 0, and computing the
	 * 32-bit CRC for HeaderSize bytes.
	*/
	header_crc = header.header_crc;
	header.header_crc = 0U;

	calc_crc = crc32((uint8_t *)&header, DEFAULT_GPT_HEADER_SIZE);
	if (header_crc != calc_crc) {
		ERROR("Invalid GPT Header CRC: Expected 0x%x but got 0x%x.\n",
		      header_crc, calc_crc);
		return -EINVAL;
	}

	header.header_crc = header_crc;

	/* partition numbers can't exceed PLAT_PARTITION_MAX_ENTRIES */
	list.entry_count = header.list_num;
	if (list.entry_count > PLAT_PARTITION_MAX_ENTRIES) {
		list.entry_count = PLAT_PARTITION_MAX_ENTRIES;
	}

	return 0;
}

static int load_mbr_entry(mbr_entry_t *mbr_entry, int part_number) {
	size_t bytes_read;
	uintptr_t offset;

	if (mbr_entry == NULL) {
		return -EINVAL;
	}

	/* MBR partition table is in LBA0. */
	bytes_read = FLASH_DEV_NAME.ReadData(MBR_OFFSET, &mbr_sector,
					     PLAT_PARTITION_BLOCK_SIZE);
	if (bytes_read != PLAT_PARTITION_BLOCK_SIZE) {
		WARN("Failed to read data (%i)\n", bytes_read);
		return -EINVAL;
	}

	/* Check MBR boot signature. */
	if ((mbr_sector[LEGACY_PARTITION_BLOCK_SIZE - 2] != MBR_SIGNATURE_FIRST) ||
	    (mbr_sector[LEGACY_PARTITION_BLOCK_SIZE - 1] != MBR_SIGNATURE_SECOND)) {
		return -ENOENT;
	}

	offset = (uintptr_t)&mbr_sector + MBR_PRIMARY_ENTRY_OFFSET +
		 MBR_PRIMARY_ENTRY_SIZE * part_number;
	memcpy(mbr_entry, (void *)offset, sizeof(mbr_entry_t));

	return 0;
}

static int load_mbr_entries(void) {
	mbr_entry_t mbr_entry;
	int i;

	list.entry_count = MBR_PRIMARY_ENTRY_NUMBER;

	for (i = 0; i < list.entry_count; i++) {
		load_mbr_entry(&mbr_entry, i);
		list.list[i].start = mbr_entry.first_lba * 512;
		list.list[i].length = mbr_entry.sector_nums * 512;
		list.list[i].name[0] = mbr_entry.type;
	}

	return 0;
}

static int unicode_to_ascii(unsigned short *str_in, unsigned char *str_out) {
	uint8_t *name;
	int i;

	if ((str_in == NULL) || (str_out == NULL)) {
		return -EINVAL;
	}

	name = (uint8_t *)str_in;
	if (name[0] == '\0') {
		return -EINVAL;
	}

	/* check whether the unicode string is valid */
	for (i = 1; i < (EFI_NAMELEN << 1); i += 2) {
		if (name[i] != '\0') {
			return -EINVAL;
		}
	}

	/* convert the unicode string to ascii string */
	for (i = 0; i < (EFI_NAMELEN << 1); i += 2) {
		str_out[i >> 1] = name[i];
		if (name[i] == '\0') {
			break;
		}
	}

	return 0;
}

int parse_gpt_entry(gpt_entry_t *gpt_entry, partition_entry_t *entry) {
	int result;

	if ((gpt_entry == NULL) || (entry == NULL)) {
		return -EINVAL;
	}

	if ((gpt_entry->first_lba == 0) && (gpt_entry->last_lba == 0)) {
		return -EINVAL;
	}

	memset(entry, 0, sizeof(partition_entry_t));
	result = unicode_to_ascii(gpt_entry->name, (uint8_t *)entry->name);
	if (result != 0) {
		return result;
	}

	entry->start = (uint64_t)gpt_entry->first_lba * PLAT_PARTITION_BLOCK_SIZE;
	entry->length = (uint64_t)(gpt_entry->last_lba - gpt_entry->first_lba + 1) *
			PLAT_PARTITION_BLOCK_SIZE;
	guidcpy(&entry->part_guid, &gpt_entry->unique_uuid);
	guidcpy(&entry->type_guid, &gpt_entry->type_uuid);

	return 0;
}

static int verify_partition_gpt(void) {
	size_t bytes_read;
	gpt_entry_t entry;
	int i;

	for (i = 0; i < list.entry_count; i++) {
		bytes_read = FLASH_DEV_NAME.ReadData(GPT_ENTRY_OFFSET +
						     i * sizeof(gpt_entry_t),
						     &entry,
						     sizeof(gpt_entry_t));
		if (bytes_read != sizeof(gpt_entry_t)) {
			WARN("Failed to read data (%i)\n", bytes_read);
			return -EINVAL;
		}

		if (parse_gpt_entry(&entry, &list.list[i]) != 0) {
			break;
		}
	}

	if (i == 0) {
		ERROR("No Valid GPT Entries found\n");
		return -EINVAL;
	}

	list.entry_count = i;
	dump_entries(list.entry_count);

	return 0;
}

static int load_partition_table(void) {
	mbr_entry_t mbr_entry;
	int result;

	if (FLASH_DEV_NAME.Initialize(NULL) != ARM_DRIVER_OK) {
		return -EINVAL;
	}

	result = load_mbr_header(&mbr_entry);
	if (result != 0) {
		ERROR("Loading mbr header failed with image id=%u (%i)\n",
		      result);
		return result;
	}

	if (mbr_entry.type == PARTITION_TYPE_GPT) {
		INFO("Loading gpt header\n");
		result = load_gpt_header();
		if (result != 0) {
			ERROR("Failed load gpt header! %i\n", result);
			return result;
		}

		result = verify_partition_gpt();
		if (result != 0) {
			ERROR("Failed verify gpt partition %i\n", result);
		}
	} else {
		result = load_mbr_entries();
	}

	return result;
}

const partition_entry_t *get_partition_entry(const char *name) {
	int i;

	for (i = 0; i < list.entry_count; i++) {
		if (strcmp(name, list.list[i].name) == 0) {
			return &list.list[i];
		}
	}

	return NULL;
}

const partition_entry_t *get_partition_entry_by_type(const uuid_t *type_uuid) {
	int i;

	for (i = 0; i < list.entry_count; i++) {
		if (guidcmp(type_uuid, &list.list[i].type_guid) == 0) {
			return &list.list[i];
		}
	}

	return NULL;
}

const partition_entry_t *get_partition_replica_by_type(const uuid_t *type_uuid) {
	int count = 0;
	int i;

	for (i = 0; i < list.entry_count; i++) {
		if (guidcmp(type_uuid, &list.list[i].type_guid) == 0) {
			if (++count == 2) {
				return &list.list[i];
			}
		}
	}

	return NULL;
}

const partition_entry_t *get_partition_entry_by_uuid(const uuid_t *part_uuid) {
	int i;

	for (i = 0; i < list.entry_count; i++) {
		if (guidcmp(part_uuid, &list.list[i].part_guid) == 0) {
			return &list.list[i];
		}
	}

	return NULL;
}

const partition_entry_list_t *get_partition_entry_list(void) {
	return &list;
}

SYS_INIT(load_partition_table, CORE, 14);
