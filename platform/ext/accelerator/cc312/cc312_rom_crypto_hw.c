/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
#include "crypto_hw.h"

#include <stdint.h>
#include <stddef.h>
#include "region_defs.h"
#include "cc3xx_init.h"
#include "device_definition.h"

int crypto_hw_accelerator_init(void)
{
    return cc3xx_lowlevel_init();
}

int crypto_hw_accelerator_finish(void)
{
    return cc3xx_lowlevel_uninit();
}
