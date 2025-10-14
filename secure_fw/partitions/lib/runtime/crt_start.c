/*
 * SPDX-License-Identifier: BSD-3-Clause
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 */

#include "utilities.h"

#if defined(__clang_major__) && defined(__GNUC__)

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

extern int main(int argc, char **argv);

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
#else
#error This startup file shall be used in ATfE toolchain only.
#endif
