/*
 * Copyright (c) 2022-2025 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "ifx_regions.h"

bool ifx_is_region_inside_other(uintptr_t first_region_start,
                                uintptr_t first_region_limit,
                                uintptr_t second_region_start,
                                uintptr_t second_region_limit)
{
    /* Check parameters of the first region */
    if (first_region_start > first_region_limit) {
        return false;
    }

    /* Check parameters of the second region */
    if (second_region_start > second_region_limit) {
        return false;
    }

    /* Return the result */
    return (first_region_start >= second_region_start)
            && (first_region_limit <= second_region_limit);
}

bool ifx_is_region_overlap_other(uintptr_t first_region_start,
                                 uintptr_t first_region_limit,
                                 uintptr_t second_region_start,
                                 uintptr_t second_region_limit)
{
    /* Check parameters of the first region */
    if (first_region_start > first_region_limit) {
        return false;
    }

    /* Check parameters of the second region */
    if (second_region_start > second_region_limit) {
        return false;
    }

    /* Return the result */
    return (first_region_start <= second_region_limit)
            && (first_region_limit >= second_region_start);
}
