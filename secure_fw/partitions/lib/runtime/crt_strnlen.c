/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <stddef.h>

size_t strnlen(const char *s, size_t maxlen)
{
    size_t idx;

    for (idx = 0; idx < maxlen; idx++) {
        if (s[idx] == '\0') {
            return idx;
        }
    }

    return idx;
}
