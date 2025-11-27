/*
 * Copyright (c) 2022-2025 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef IFX_REGIONS_H
#define IFX_REGIONS_H

#include <stdbool.h>
#include <stdint.h>
#include "region.h"

/**
 * \brief Check whether a first memory region is inside second memory region.
 *
 * \param[in] first_region_start   The start address of the first region
 * \param[in] first_region_limit   The end address of the first region
 * \param[in] second_region_start  The start address of the second region, which should
 *                                 contain the first region
 * \param[in] second_region_limit  The end address of the second region, which should
 *                                 contain the first region
 *
 * \return true if the second region contains the first region,
 *         false otherwise.
 */
bool ifx_is_region_inside_other(uintptr_t first_region_start,
                                uintptr_t first_region_limit,
                                uintptr_t second_region_start,
                                uintptr_t second_region_limit);

/**
 * \brief Check whether a memory region overlaps other memory region.
 *
 * \param[in] first_region_start   The start address of the first region
 * \param[in] first_region_limit   The end address of the first region
 * \param[in] second_region_start  The start address of the second region, which should
 *                                 overlap the first region
 * \param[in] second_region_limit  The end address of the second region, which should
 *                                 overlap the first region
 *
 * \return true if the second region overlaps the first region,
 *         false otherwise.
 */
bool ifx_is_region_overlap_other(uintptr_t first_region_start,
                                 uintptr_t first_region_limit,
                                 uintptr_t second_region_start,
                                 uintptr_t second_region_limit);

#ifdef CONFIG_TFM_PARTITION_META
REGION_DECLARE(Image$$, TFM_SPM_RW_OTHER_RO_START, $$Base);
REGION_DECLARE(Image$$, TFM_SPM_RW_OTHER_RO_END, $$Base);
#endif

#if TEST_NS_IFX_CODE_COVERAGE
REGION_DECLARE(Image$$, IFX_CODE_COVERAGE_START, $$Base);
REGION_DECLARE(Image$$, IFX_CODE_COVERAGE_END, $$Base);
#endif

#ifdef CONFIG_TFM_USE_TRUSTZONE
REGION_DECLARE(Image$$, ER_VENEER, $$Base);
REGION_DECLARE(Image$$, VENEER_ALIGN, $$Limit);
#endif

REGION_DECLARE(Image$$, PT_RO_START, $$Base);
REGION_DECLARE(Image$$, PT_RO_END, $$Base);

#ifdef TFM_ISOLATION_LEVEL
#if TFM_ISOLATION_LEVEL == 3
REGION_DECLARE(Image$$, PT_PRIV_RWZI_START, $$Base);
REGION_DECLARE(Image$$, PT_PRIV_RWZI_END, $$Base);

#elif TFM_ISOLATION_LEVEL == 2
REGION_DECLARE(Image$$, TFM_UNPRIV_CODE, $$RO$$Base);
REGION_DECLARE(Image$$, TFM_UNPRIV_CODE, $$RO$$Limit);
REGION_DECLARE(Image$$, TFM_APP_CODE_START, $$Base);
REGION_DECLARE(Image$$, TFM_APP_CODE_END, $$Base);
REGION_DECLARE(Image$$, TFM_APP_RW_STACK_START, $$Base);
REGION_DECLARE(Image$$, TFM_APP_RW_STACK_END, $$Base);
REGION_DECLARE(Image$$, TFM_PSA_RW_STACK_START, $$Base);
REGION_DECLARE(Image$$, TFM_PSA_RW_STACK_END, $$Base);
#endif
#endif

REGION_DECLARE(Image$$, TFM_UNPRIV_CODE_START, $$RO$$Base);
REGION_DECLARE(Image$$, TFM_UNPRIV_CODE_END, $$RO$$Limit);

REGION_DECLARE(Image$$, ARM_LIB_STACK, $$Base);
REGION_DECLARE(Image$$, ARM_LIB_STACK, $$Limit);


#endif /* IFX_REGIONS_H */
