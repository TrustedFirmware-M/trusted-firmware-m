/*
 * Copyright (c) 2024, Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
#include "noc_s3_util.h"

#include <stdbool.h>

#ifdef NOC_S3_PRETTY_PRINT_LOG_ENABLED
enum noc_s3_err noc_s3_sorted_add_entry(
        struct noc_s3_sorted_region_list *list,
        uint32_t region,
        uint64_t address)
{
    uint32_t r_idx;
    uint64_t temp_address;

    if (list->sorted_region_count == list->sorted_region_max) {
        return NOC_S3_ERR_NOT_PERMITTED;
    }

    for (r_idx = list->sorted_region_count; r_idx > 0; --r_idx) {
        temp_address = list->sorted_regions[r_idx - 1].address;

        if (temp_address <= address) {
            break;
        }

        list->sorted_regions[r_idx].region_idx =
                list->sorted_regions[r_idx - 1].region_idx;
    }

    list->sorted_regions[r_idx].region_idx = region;
    list->sorted_regions[r_idx].address = address;
    list->sorted_region_count += 1;

    return NOC_S3_SUCCESS;
}
#endif

enum noc_s3_err noc_s3_check_region_overlaps(uint64_t region_base_1,
                                             uint64_t region_end_1,
                                             uint64_t region_base_2,
                                             uint64_t region_end_2)
{
    if (region_base_2 > region_end_1) {
        return NOC_S3_SUCCESS;
    } else if (region_base_2 >= region_base_1) {
        return NOC_S3_ERR_REGION_OVERLAPS;
    } else if (region_end_2 >= region_base_1) {
        return NOC_S3_ERR_REGION_OVERLAPS;
    }

    return NOC_S3_SUCCESS;
}
