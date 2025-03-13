/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <stddef.h>
#include <assert.h>
#include "tfm_log.h"
#include "fih.h"
#include "uart_stdout.h"

#ifndef __ARMCC_VERSION
void __assert_func(const char *file, int line, const char *func, const char *reason)
{
    if (stdio_is_initialized()) {
        ERROR("Assertion failed: (%s), file %s, line %d\n", reason, file, line);
    }

    FIH_PANIC;
}
#else /* __ARMCC_VERSION */
void __assert_puts(const char *msg)
{
    if (stdio_is_initialized()) {
        ERROR("%s\n", msg);
    }

    FIH_PANIC;
}
#endif /* __ARMCC_VERSION */
