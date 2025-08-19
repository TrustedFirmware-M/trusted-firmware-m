/*
 * SPDX-License-Identifier: BSD-3-Clause
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 */

#ifndef __RSE_GRETREG_H__
#define __RSE_GRETREG_H__

#include <stdbool.h>
#include "device_definition.h"

#ifdef RSE_SUBPLATFORM_GRETREG_BITS
#include "rse_subplatform_gretreg.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

enum rse_gretreg_bit_offset {
    /* Reserved for legacy use releasing SCP, will be reused once tc3 and kronos
     * are deprecated.
     */
    _RSE_GRETREG_BIT_OFFSET_RESERVED = 0,
    RSE_GRETREG_BIT_OFFSET_PERSISTENT_DATA_VALID = 1,
#ifdef RSE_SUBPLATFORM_GRETREG_BITS
    _RSE_GRETREG_BITS_MAX = _RSE_GRETREG_BITS_SUBPLATFORM_MAX,
#else
    _RSE_GRETREG_BITS_MAX,
#endif
};

static inline bool rse_gretreg_flag_is_set(enum rse_gretreg_bit_offset offset)
{
    return (((struct rse_sysctrl_t *)RSE_SYSCTRL_BASE_S)->gretreg >> offset) & 0b1;
}

static inline void rse_gretreg_set_flag(enum rse_gretreg_bit_offset offset)
{
    volatile uint32_t *gretreg = &((struct rse_sysctrl_t *)RSE_SYSCTRL_BASE_S)->gretreg;
    *gretreg = *gretreg | (0b1 << offset);
}

#ifdef __cplusplus
}
#endif

#endif /* __RSE_GRETREG_H__ */
