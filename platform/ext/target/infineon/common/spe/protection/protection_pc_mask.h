/*
 * Copyright (c) 2026 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

 #ifndef PROTECTION_PC_MASK_H
#define PROTECTION_PC_MASK_H

#include <stdint.h>

/* Macro to get bit value for a given PC from a mask of bit values for each PC. */
#define IFX_GET_PC(mask, pc)        (((mask) >> ((uint32_t)(pc))) & 1UL)

/* Mask of bit values for each PC. */
typedef uint32_t ifx_pc_mask_t;

#endif /* PROTECTION_PC_MASK_H */
