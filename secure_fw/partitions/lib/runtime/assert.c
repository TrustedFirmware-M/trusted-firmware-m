/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <stddef.h>
#include <assert.h>
#include "tfm_log.h"
#include "tfm_log_unpriv.h"
#include "uart_stdout.h"
#include "tfm_arch.h"

#ifndef __ARMCC_VERSION
void __assert_func(const char *file, int line, const char *func, const char *reason)
{
    if (!tfm_arch_is_priv()) {
        ERROR_UNPRIV("Assertion failed: (%s), file %s, line %d\n", reason, file, line);
    } else if (stdio_is_initialized()) {
        ERROR("Assertion failed: (%s), file %s, line %d\n", reason, file, line);
    }

    while (1) {
        ;
    }
}
#else /* __ARMCC_VERSION */
void __assert_puts(const char *msg)
{
    if (!tfm_arch_is_priv()) {
        ERROR_UNPRIV("%s\n", msg);
    } else if (stdio_is_initialized()) {
        ERROR("%s\n", msg);
    }

    while (1) {
        ;
    }
}
#endif /* __ARMCC_VERSION*/
