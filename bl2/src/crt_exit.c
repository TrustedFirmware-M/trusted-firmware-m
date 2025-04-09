/*
 * SPDX-License-Identifier: BSD-3-Clause
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 */

#if defined(__ARMCC_VERSION)

void __rt_exit(void)
{
    while (1)
        ;
}

#else

void _exit(void)
{
    while (1)
        ;
}

#endif
