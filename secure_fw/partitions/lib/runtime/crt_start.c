/*
 * SPDX-License-Identifier: BSD-3-Clause
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 */

#if !defined(__GNUC__) || defined(__ARMCC_VERSION) || defined(__ICCARM__)
#error This startup file is compatible with GNUArm and ATfE toolchains only.
#endif

#include <stddef.h>
#include "cmsis_compiler.h"

#if !defined(CONFIG_TFM_INCLUDE_STDLIBC)

extern int main(int argc, char **argv);

#if defined(__clang_major__)  /* effectively ATfE */
/*
 * We can not use CMSIS support for ATfE toolchain because it's incompatible
 * with it. That's why we manually implement the startup routine below.
 */

typedef struct __copy_table {
    uint32_t const *src;
    uint32_t *dest;
    uint32_t wlen;
} __copy_table_t;

typedef struct __zero_table {
    uint32_t *dest;
    uint32_t wlen;
} __zero_table_t;

extern const __copy_table_t __copy_table_start__;
extern const __copy_table_t __copy_table_end__;
extern const __zero_table_t __zero_table_start__;
extern const __zero_table_t __zero_table_end__;

void _start(void)
{
    for (__copy_table_t const *pTable = &__copy_table_start__; pTable < &__copy_table_end__; ++pTable) {
        for (uint32_t i = 0u; i < pTable->wlen; ++i) {
            pTable->dest[i] = pTable->src[i];
        }
    }

    for (__zero_table_t const *pTable = &__zero_table_start__; pTable < &__zero_table_end__; ++pTable) {
        for (uint32_t i = 0u; i < pTable->wlen; ++i) {
            pTable->dest[i] = 0u;
        }
    }
    main(0, NULL);
    while (1)
        ;
}
#else /* defined(__clang_major__) */

void _start(void)
{
    main(0, NULL);
    while (1)
        ;
}
#endif /* defined(__clang_major__) */
#endif /* !defined(CONFIG_TFM_INCLUDE_STDLIBC) */
