/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
/**
 * \note Stub functions for the MbedCrypto library, used when the
 *       standard C library is excluded.
 */
#include <assert.h>
#include <stdlib.h>

void *calloc(size_t nmemb, size_t size)
{
    assert(!"not implemented");
    return NULL;
};

void free(void *mem)
{
    assert(!"not implemented");
}

__attribute__((noreturn)) void exit(int code)
{
    (void)code;
    while (1)
        ;
}
