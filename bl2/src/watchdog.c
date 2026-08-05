/*
 * SPDX-License-Identifier: BSD-3-Clause
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 */

#include "cmsis_compiler.h"

/*
 * This is a stub implementation.
 * Platforms can supply their own implementation to feed
 * a watchdog during boot.
 */
__WEAK void mcuboot_watchdog_feed(void)
{
}
