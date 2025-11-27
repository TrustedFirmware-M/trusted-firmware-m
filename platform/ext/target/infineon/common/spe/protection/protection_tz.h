/*
 * Copyright (c) 2024-2025 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef PROTECTION_TZ_H
#define PROTECTION_TZ_H

#include "fih.h"
#include "protection_types.h"
#include "tfm_hal_defs.h"

/**
 * \brief Check access to memory region by TrustZone (SAU, IDAU, MPU).
 *
 * \param[in]   p_info        Pointer to partition info
 * \param[in]   base          The base address of the region.
 * \param[in]   size          The size of the region.
 * \param[in]   access_type   The memory access types to be checked between
 *                            given memory and boundaries.
 * \param[in]   privileged    Is partition privileged.
 *
 * \return TFM_HAL_SUCCESS - The memory region has the access permissions by TrustZone.
 *         TFM_HAL_ERROR_MEM_FAULT - The memory region has not the access
 *                                   permissions by TrustZone.
 *         TFM_HAL_ERROR_INVALID_INPUT - Invalid inputs.
 */
FIH_RET_TYPE(enum tfm_hal_status_t) ifx_tz_memory_check(const ifx_partition_info_t *p_info,
                                                        uintptr_t base,
                                                        size_t size,
                                                        uint32_t access_type);

#endif /* PROTECTION_TZ_H */
