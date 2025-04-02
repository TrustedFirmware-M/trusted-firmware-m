/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <assert.h>

#include "host_base_address.h"
#include "rse_comms_atu.h"
#include "sds.h"
#include "tfm_plat_defs.h"
#include "utilities.h"

/*!
 * \brief Aligns a value to the next multiple.
 *
 * \param VALUE     Value to be aligned.
 * \param INTERVAL  Multiple to align to.
 *
 * \return The nearest multiple which is greater than or equal to VALUE.
 */
#define ALIGN_NEXT(VALUE, INTERVAL) ((\
    ((VALUE) + (INTERVAL) - 1) / (INTERVAL)) * (INTERVAL))

/* Arbitrary, 16 bit value that indicates a valid SDS Memory Region */
#define REGION_SIGNATURE         0xAA7A
/* The minor version of the SDS schema supported by this implementation */
#define SUPPORTED_VERSION_MINOR  0x0
/* The major version of the SDS schema supported by this implementation */
#define SUPPORTED_VERSION_MAJOR  0x1

/*! Position of the major version field. */
#define SDS_ID_VERSION_MAJOR_POS 24

/* Minimum required byte alignment for fields within structures */
#define MIN_FIELD_ALIGNMENT      4
/* Minimum required byte alignment for structures within the region */
#define MIN_STRUCT_ALIGNMENT     8
/* Minimum structure size in bytes */
#define MIN_STRUCT_SIZE          4
/* Minimum structure size (including padding) in bytes */
#define MIN_ALIGNED_STRUCT_SIZE \
    ALIGN_NEXT(MIN_STRUCT_SIZE, MIN_STRUCT_ALIGNMENT)
/* Minimum region size in bytes */
#define MIN_REGION_SIZE (sizeof(struct region_descriptor) + \
                         MIN_ALIGNED_STRUCT_SIZE)

/* Header containing Shared Data Structure metadata */
struct structure_header {
    /*
     * Compound identifier value consisting of a linear structure ID, a major
     * version, and a minor version. Together these uniquely identify the
     * structure.
     */
    uint32_t id;

    /*
     * Flag indicating whether the structure's content is valid. Always false
     * initially, the flag is set to true when the structure is finalized.
     */
    bool valid : 1;

    /*
     * Size, in bytes, of the structure. The size of the header is not included,
     * only the structure content. If padding was used to maintain alignment
     * during the structure's creation then the additional space used for the
     * padding will be reflected in this value.
     */
    uint32_t size : 23;

    /* Reserved */
    uint32_t reserved : 8;
};

/* Region Descriptor describing the SDS Memory Region */
struct region_descriptor {
    /*
     * Field used to determine the presence, or absence, of an SDS Memory Region
     * and Region Descriptor. When the region is initialized the signature field
     * is given a fixed value according to the REGION_SIGNATURE definition.
     */
    uint16_t signature;

    /*
     * The total number of structures, finalized or otherwise, within the SDS
     * Memory Region.
     */
    uint16_t structure_count : 8;

    /* The minor version component of the implemented SDS specification */
    uint16_t version_minor : 4;

    /* The major version component of the implemented SDS specification */
    uint16_t version_major : 4;

    /*
     * The total size of the SDS Memory Region, in bytes. The value includes the
     * size of the Region Descriptor because the descriptor is located within
     * the region that it describes. This is in contrast to structure headers,
     * which are considered to be prepended to the memory allocated for the
     * structure content.
     */
    uint32_t region_size;
};


struct sds_region {
    uint64_t  host_addr;
    void     *mapped_addr;
    size_t    size;
    uint8_t   free_mem_offset;
    size_t    free_mem_size;
    bool      is_init;
};

static struct sds_region region_config = {.host_addr = PLAT_RSE_AP_SDS_BASE,
                                          .size = PLAT_RSE_AP_SDS_SIZE,
                                          .is_init = false};

/*
 * Perform some tests to determine whether any of the fields within a Structure
 * Header contain obviously invalid data.
 */
static bool header_is_valid(const volatile struct region_descriptor *region,
                            const volatile struct structure_header *header)
{
    const volatile char *region_tail, *struct_tail;

    if (header->id == 0) {
        return false; /* Zero is not a valid identifier */
    }

    if ((header->id >> SDS_ID_VERSION_MAJOR_POS) == 0) {
        return false; /* 0 is not a valid major version */
    }

    if (header->size < MIN_ALIGNED_STRUCT_SIZE) {
        return false; /* Padded structure size is less than the minimum */
    }

    region_tail = (const volatile char *)region + region->region_size;
    struct_tail = (const volatile char *)header
        + sizeof(struct structure_header)
        + header->size;
    if (struct_tail > region_tail) {
        /* Structure exceeds the capacity of the SDS Memory Region */
        return false;
    }

    if ((header->size % MIN_STRUCT_ALIGNMENT) != 0) {
        return false; /* Structure does not meet alignment requirements */
    }

    return true;
}

static int get_structure_info(uint32_t structure_id,
                              struct structure_header *header,
                              uint8_t **structure_base)
{
   volatile struct structure_header *current_header;
   size_t offset, region_size, struct_count, struct_idx;
   struct region_descriptor *region_desc;

    region_desc = (struct region_descriptor *)region_config.mapped_addr;
    region_size = region_desc->region_size;
    struct_count = region_desc->structure_count;
    offset = sizeof(struct region_descriptor);

    /* Iterate over structure headers to find one with a matching ID */
    for (struct_idx = 0; struct_idx < struct_count; struct_idx++) {
        current_header =
                (struct structure_header *)(region_config.mapped_addr + offset);
        if (!header_is_valid(region_desc, current_header)) {
            return -1;
        }
        if (current_header->id == structure_id) {
            if (structure_base != NULL) {
                *structure_base = ((uint8_t *)current_header
                                     + sizeof(struct structure_header));
            }

            *header = *current_header;
            return 0;
        }

        offset += sizeof(struct structure_header);
        offset += current_header->size;
        if (offset >= region_size) {
            return -1;
        }
    }

    /* Structure with structure_id does not exist yet */
    return -1;
}

/*
 * Search the SDS Memory Region to determine if a structure with the given ID
 * is present.
 */
static bool structure_exists(uint32_t structure_id)
{
    int status;
    struct structure_header header;

    status = get_structure_info(structure_id, &header, NULL);
    return status == 0;
}

static enum tfm_plat_err_t sds_region_map(uint8_t *atu_region)
{
    enum tfm_plat_err_t err;

    /* TODO: might replace the comms_atu_* calls with native ATU driver calls */
    err = comms_atu_alloc_region(region_config.host_addr,
                                 region_config.size,
                                 atu_region);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return err;
    }

    /* TODO: might replace the comms_atu_* calls with native ATU driver calls */
    err = comms_atu_get_rse_ptr_from_host_addr(*atu_region,
                                                region_config.host_addr,
                                               &region_config.mapped_addr);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return err;
    }

    return TFM_PLAT_ERR_SUCCESS;
}

static enum tfm_plat_err_t sds_region_unmap(uint8_t atu_region)
{
    /* TODO: might replace the comms_atu_* calls with native ATU driver calls */
    return comms_atu_free_region(atu_region);
}

static void sds_region_init(void)
{
    assert(PLAT_RSE_AP_SDS_SIZE > MIN_REGION_SIZE);

    struct region_descriptor *region_desc =
        (struct region_descriptor *)region_config.mapped_addr;

    if (region_config.is_init == false) {
        memset(region_config.mapped_addr, 0, region_config.size);

        region_desc->signature = REGION_SIGNATURE;
        region_desc->structure_count = 0;
        region_desc->version_major = SUPPORTED_VERSION_MAJOR;
        region_desc->version_minor = SUPPORTED_VERSION_MINOR;
        region_desc->region_size = region_config.size;

        region_config.free_mem_offset = sizeof(*region_desc);
        region_config.free_mem_size = region_config.size - sizeof(*region_desc);

        region_config.is_init = true;
    }
}

static enum tfm_plat_err_t
sds_struct_add_internal(const struct sds_structure_desc *struct_desc)
{
    struct structure_header *header;
    struct region_descriptor *region_desc =
        (struct region_descriptor *)region_config.mapped_addr;
    size_t padded_size = ALIGN_NEXT(struct_desc->size, MIN_STRUCT_ALIGNMENT);

    if (padded_size + sizeof(*header) > region_config.free_mem_size) {
        return TFM_PLAT_ERR_INVALID_INPUT;
    }

    if (struct_desc->payload == NULL) {
        return TFM_PLAT_ERR_INVALID_INPUT;
    }

    /* Create the Structure Header */
    header = (struct structure_header *)(region_config.mapped_addr +
                                         region_config.free_mem_offset);
    header->id = struct_desc->id;
    header->size = padded_size;
    header->valid = true; /* Set to always true */

    /* Adjust free memory data with the size of structure_header */
    region_config.free_mem_offset += sizeof(*header);
    region_config.free_mem_size   -= sizeof(*header);

    /* Copy data */
    memcpy(region_config.mapped_addr + region_config.free_mem_offset,
           struct_desc->payload, struct_desc->size);

    /* Adjust free memory data with padded_size to maintain alignment. */
    region_config.free_mem_offset += padded_size;
    region_config.free_mem_size   -= padded_size;

    /* Increment the structure count within the region descriptor */
    region_desc->structure_count++;

    return TFM_PLAT_ERR_SUCCESS;
}

enum tfm_plat_err_t
sds_struct_add(const struct sds_structure_desc *struct_desc)
{
    enum tfm_plat_err_t err, err2;
    uint8_t atu_region;

    err = sds_region_map(&atu_region);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return err;
    }

    sds_region_init();

   /* If the structure does not already exist, add it to the SDS region. */
    if (!structure_exists(struct_desc->id)) {
        err = sds_struct_add_internal(struct_desc);
    } else {
        /* Already added or other error */
        err = TFM_PLAT_ERR_INVALID_INPUT;
    }

    err2 = sds_region_unmap(1);
    if (err2 != TFM_PLAT_ERR_SUCCESS) {
        return err2;
    }

    return err;
}
