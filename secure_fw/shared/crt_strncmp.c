/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "crt_impl_private.h"

int strncmp(const char *s1, const char *s2, size_t n)
{
    while (n--) {
        if (*s1 != *s2) {
            return (unsigned char)*s1 - (unsigned char)*s2;
        }
        if (*s1 == '\0') {
            return 0;
        }
        s1++;
        s2++;
    }
    return 0;
}
