/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "cmsis.h"
#include "sfcp_encryption_hal.h"

/* Interrupt control is required even when SFCP encryption is disabled. */
uint32_t sfcp_encryption_hal_save_disable_irq(void)
{
    uint32_t primask = __get_PRIMASK();
    __disable_irq();
    return primask;
}

void sfcp_encryption_hal_enable_irq(uint32_t cookie)
{
    __set_PRIMASK(cookie);
}
