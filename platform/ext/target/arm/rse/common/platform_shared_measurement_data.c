/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "tfm_plat_shared_measurement_data.h"
#include "rse_persistent_data.h"

static struct rse_persistent_data *get_persistent_data(void)
{
    struct rse_persistent_data *persistent_data;

    rse_get_persistent_data(&persistent_data);

    return persistent_data;
}

uintptr_t tfm_plat_get_shared_measurement_data_base(void)
{
    return (uintptr_t)(get_persistent_data()->shared_data.shared_boot_measurement);
}

size_t tfm_plat_get_shared_measurement_data_size(void)
{
    return sizeof(get_persistent_data()->shared_data.shared_boot_measurement);
}
