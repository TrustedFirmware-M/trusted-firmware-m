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

/* picolibc's <assert.h> expands assert() into a call to __assert_no_args() when
 * NDEBUG and ASSERT_VERBOSE are not defined. The TF-M secure image is linked with -nostdlib
 * (since it defaults to TFM_INCLUDE_STDLIBC=n), so in some configurations this results
 * in undefined reference to __assert_no_args() when assert() is used in the TF-M secure image.
 * Make it weak so that it acts a fallback implementation.
 */
__WEAK __NO_RETURN void __assert_no_args(void)
{
    while (1) {
        ;
    }
}
