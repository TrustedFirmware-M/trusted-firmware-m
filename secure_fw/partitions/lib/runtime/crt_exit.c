/*
 * SPDX-License-Identifier: BSD-3-Clause
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 */
#include "psa/service.h"

#if defined(__ARMCC_VERSION)

void __rt_exit(void)
{
    psa_panic();
}

#else

void exit(void)
{
    psa_panic();
}

#endif
