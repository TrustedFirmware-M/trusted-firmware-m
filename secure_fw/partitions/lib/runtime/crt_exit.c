/*
 * SPDX-License-Identifier: BSD-3-Clause
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 */

#include "psa/service.h"

#if defined(__ARMCC_VERSION)

void __rt_exit(int code)
{
    (void)code;

    psa_panic();
}

#else

__attribute__((noreturn)) void _exit(int code)
{
    (void)code;

    psa_panic();
}

__attribute__((noreturn)) void exit(int code)
{
    _exit(code);
}

#endif
