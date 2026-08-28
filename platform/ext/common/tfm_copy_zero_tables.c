/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdint.h>

#include "tfm_copy_zero_tables.h"

/*
 * The CMSIS scatter tables.  These are declared here rather than in the
 * header because CMSIS declares the same symbols inside __cmsis_start() with
 * types local to that function, and a second declaration of them anywhere in
 * the same translation unit conflicts with it.  Keeping them in this file lets
 * a startup that includes both the CMSIS device header and the header below
 * compile.  They are declared as single objects and compared by address, the
 * form CMSIS itself uses, so that static analysis does not read the walk as a
 * comparison between pointers into two different arrays.  They are weak so an
 * image whose linker script emits no tables links and skips the walk.
 */
typedef struct {
    uint32_t const *src;
    uint32_t       *dest;
    uint32_t        wlen;
} copy_table_t;

typedef struct {
    uint32_t *dest;
    uint32_t  wlen;
} zero_table_t;

extern const copy_table_t __copy_table_start__ __attribute__((weak));
extern const copy_table_t __copy_table_end__   __attribute__((weak));
extern const zero_table_t __zero_table_start__ __attribute__((weak));
extern const zero_table_t __zero_table_end__   __attribute__((weak));

void tfm_copy_zero_tables(void)
{
    const copy_table_t *ct;
    const zero_table_t *zt;
    uint32_t i;

    // cppcheck-suppress comparePointers ; the linker brackets one region
    for (ct = &__copy_table_start__; ct < &__copy_table_end__; ct++) {
        for (i = 0u; i < ct->wlen; i++) {
            ct->dest[i] = ct->src[i];
        }
    }

    // cppcheck-suppress comparePointers ; the linker brackets one region
    for (zt = &__zero_table_start__; zt < &__zero_table_end__; zt++) {
        for (i = 0u; i < zt->wlen; i++) {
            zt->dest[i] = 0u;
        }
    }
}
