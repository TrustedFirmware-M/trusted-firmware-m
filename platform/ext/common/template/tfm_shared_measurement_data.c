/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "tfm_plat_shared_measurement_data.h"
#include "region_defs.h"

uintptr_t tfm_plat_get_shared_measurement_data_base(void)
{
    return SHARED_BOOT_MEASUREMENT_BASE;
}

size_t tfm_plat_get_shared_measurement_data_size(void)
{
    return SHARED_BOOT_MEASUREMENT_SIZE;
}
