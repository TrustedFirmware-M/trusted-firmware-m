/*
 * SPDX-License-Identifier: BSD-3-Clause
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 */

#if defined(__ARMCC_VERSION)

void __rt_exit(int code)
{
    (void)code;

    while (1)
        ;
}

#else

__attribute__((noreturn)) void _exit(int code)
{
    (void)code;

    while (1)
        ;
}

#endif
