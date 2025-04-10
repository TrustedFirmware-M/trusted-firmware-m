/*
 * Copyright (c) 2024, Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __NOC_S3_UTIL_H__
#define __NOC_S3_UTIL_H__

#include "noc_s3_drv.h"
#include <stdint.h>

/* Pretty print log for NoC S3 */
#ifdef NOC_S3_PRETTY_PRINT_LOG_ENABLED
#include <stdio.h>
#include <stdbool.h>

/* Using stderr (unbuffered) instead of stdout (buffered) */
// TODO: Replace fprintf with common TF-M logging function
#define NOC_S3_DRV_LOG(fmt, ...)  fprintf(stderr, fmt, ##__VA_ARGS__)

#define NOC_S3_DRV_LOG_HEADING(fmt, ...)                                  \
        do {                                                              \
            NOC_S3_DRV_LOG("\r\n");                                       \
            NOC_S3_DRV_LOG(fmt, ##__VA_ARGS__);                          \
            NOC_S3_DRV_LOG("\r\n");                                       \
            for (int l = 0; l < sprintf(NULL, fmt,  ##__VA_ARGS__); ++l)  \
                NOC_S3_DRV_LOG("-");                                      \
        } while(0);

/* NoC S3 sorted region data structure */
struct noc_s3_sorted_region_data {
    /* Region Index */
    uint32_t region_idx;
    /* Address used to for sorting */
    uint64_t address;
};

/* NoC S3 sorted region list structure */
struct noc_s3_sorted_region_list {
    /* List of region data in ascending order of base address */
    struct noc_s3_sorted_region_data *sorted_regions;
    /* Number of regions in the sorted list */
    uint32_t sorted_region_count;
    /* Maximum possible number of sorted regions the list can accept */
    const uint32_t sorted_region_max;
};

/**
 * \brief Adds region index to the sorted list in ascending order sorted by
 *        the base address.
 *
 * \param[in] list     Pointer to the sorted region list
 *                     \ref noc_s3_sorted_region_list.
 * \param[in] region   Region Index to be added.
 * \param[in] address  Address used for sorting the list.
 *
 * \return Returns error code as specified in \ref noc_s3_err.
 */
enum noc_s3_err noc_s3_sorted_add_entry(
        struct noc_s3_sorted_region_list *list,
        uint32_t region,
        uint64_t address);

/**
 * \brief Check if a node type value is xSNI node.
 *
 * \param[in]   type   NoC S3 node type value enum
 *                     \ref noc_s3_node_type_value.
 *
 * \return Returns true if node type is a xSNI node, else false.
 */
static inline bool
noc_s3_type_is_xSNI(const enum noc_s3_node_type_value type)
{
    switch (type) {
    case NOC_S3_ASNI:
    case NOC_S3_HSNI:
        return true;
    default:
        return false;
    }
}

/**
 * \brief Check if a node type value is xMNI node.
 *
 * \param[in]   type   NoC S3 node type value enum
 *                     \ref noc_s3_node_type_value.
 *
 * \return Returns true if node type is a xMNI node, else false.
 */
static inline bool
noc_s3_type_is_xMNI(const enum noc_s3_node_type_value type)
{
    switch (type) {
    case NOC_S3_AMNI:
    case NOC_S3_HMNI:
    case NOC_S3_PMNI:
        return true;
    default:
        return false;
    }
}
#endif

/**
 * \brief Check if a region overlaps with another
 *
 * \param[in]   region_base_1   Region 1 base address.
 * \param[in]   region_end_1    Region 1 end address.
 * \param[in]   region_base_2   Region 2 base address.
 * \param[in]   region_end_2    Region 2 end address.
 *
 * \return Returns NOC_S3_ERR_REGION_OVERLAPS is the region overlaps, else
 * NOC_S3_SUCCESS as specified in \ref noc_s3_err
 */
enum noc_s3_err noc_s3_check_region_overlaps(uint64_t region_base_1,
                                             uint64_t region_end_1,
                                             uint64_t region_base_2,
                                             uint64_t region_end_2);


#endif /* __NOC_S3_UTIL_H__ */
