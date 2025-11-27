/*
 * Copyright (c) 2024-2025 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef IFX_FIH_H
#define IFX_FIH_H

#include "aapcs_local.h"
#include "fih.h"

#ifdef FIH_ENABLE_DOUBLE_VARS

#define IFX_FIH_TRUE                        ((fih_int)FIH_INT_INIT(FIH_POSITIVE_VALUE))
#define IFX_FIH_FALSE                       ((fih_int)FIH_INT_INIT(FIH_NEGATIVE_VALUE))
#define IFX_FIH_BOOL                        fih_int

/*
 * Type used to return fih_int to assembler code via registers for AAPCS ABI.
 * AAPCS_DUAL_U32_T is not working with gcc 11.3 when there are three arguments to function.
 */
typedef uint64_t ifx_aapcs_fih_int;

/* Converts fih_int to ifx_aapcs_fih_int */
static __attribute__((always_inline)) inline
uint64_t ifx_fih_to_aapcs_fih(fih_int x)
{
    AAPCS_DUAL_U32_T ret;
    AAPCS_DUAL_U32_SET(ret, x.val, x.msk);
    return ret.u64_val;
}

#define IFX_FIH_EQ(x, y)                                          \
        ( ((x).val == (y).val) &&                                 \
          fih_delay() &&                                          \
          ((y).val == (((uint32_t)(x).msk) ^ _FIH_MASK_VALUE)) && \
          fih_delay() &&                                          \
          (fih_int_validate(x), true) &&                          \
          (((x).msk) == ((y).msk))                                \
        )

#else /* FIH_ENABLE_DOUBLE_VARS */

#define IFX_FIH_TRUE                        true
#define IFX_FIH_FALSE                       false
#define IFX_FIH_BOOL                        bool

/*! Type used to return uint32_t to assembler code via registers for AAPCS ABI */
typedef uint32_t ifx_aapcs_fih_int;

/* Converts fih_int to ifx_aapcs_fih_int */
#define ifx_fih_to_aapcs_fih(x)             (x)

#define IFX_FIH_EQ(x, y)                    ((x) == (y))

#endif /* FIH_ENABLE_DOUBLE_VARS */

#define IFX_FIH_DECLARE(type, var, val) \
    FIH_RET_TYPE(type) var = val

#if !defined(FIH_NOT_EQ)
#define FIH_NOT_EQ(x, y)    fih_not_eq(x, y)

#define FIH_NEGATIVE_VALUE  (-1)

#define FIH_SET(var, val)   do { var = val; } while(0)
#endif

#endif /* IFX_FIH_H */
