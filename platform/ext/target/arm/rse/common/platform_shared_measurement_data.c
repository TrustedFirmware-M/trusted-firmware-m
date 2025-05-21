/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "tfm_plat_shared_measurement_data.h"
#include "rse_persistent_data.h"

uintptr_t tfm_plat_get_shared_measurement_data_base(void)
{
    return (uintptr_t)(RSE_PERSISTENT_DATA->shared_data.shared_boot_measurement);
}

size_t tfm_plat_get_shared_measurement_data_size(void)
{
    return sizeof(RSE_PERSISTENT_DATA->shared_data.shared_boot_measurement);
}
