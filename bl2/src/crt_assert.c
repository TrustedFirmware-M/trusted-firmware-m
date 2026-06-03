/*
 * SPDX-License-Identifier: BSD-3-Clause
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 */

#include <stdlib.h>
#include "cmsis_compiler.h"

/* picolibc's <assert.h> expands assert() into a call to __assert_no_args() when
 * NDEBUG and ASSERT_VERBOSE are not defined.
 */
__WEAK __NO_RETURN void __assert_no_args(void)
{
    while (1)
        ;
}
