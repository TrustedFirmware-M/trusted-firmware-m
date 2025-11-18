/*
 * SPDX-License-Identifier: BSD-3-Clause
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 */

#include <assert.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include "tfm_vprintf_priv.h"

#include "prix64.h"

struct write_state {
    size_t left;
    char *wpos;
};

static void prix64_write(void *priv, const char *str, uint32_t len)
{
    struct write_state *ws = priv;
    size_t count;

    count = ws->left < len ? ws->left : len;
    memcpy(ws->wpos, str, count);
    ws->left -= count;
    ws->wpos += count;
}

static char *prix64a_varargs(char *str, size_t size, ...)
{
    struct write_state ws;
    va_list ap;

    if (size == 0u) {
        return str;
    }
    assert(str != NULL);

    ws.left = size - 1u;
    ws.wpos = str;

    va_start(ap, size);
    tfm_vprintf(prix64_write, &ws, "0x%04X_%04X_%04X_%04X", ap, false);
    va_end(ap);

    *ws.wpos = '\0';

    return str;
}

char *prix64a(char *str, size_t size, uint64_t value)
{
    return prix64a_varargs(str, size,
                           (unsigned int)(uint16_t)(value >> 48u),
                           (unsigned int)(uint16_t)(value >> 32u),
                           (unsigned int)(uint16_t)(value >> 16u),
                           (unsigned int)(uint16_t)(value));
}

char *prix64(prix64_t *fmt, uint64_t value)
{
    return prix64a(*fmt, sizeof(*fmt), value);
}
