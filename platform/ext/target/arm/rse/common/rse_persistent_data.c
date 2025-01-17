/*
 * SPDX-License-Identifier: BSD-3-Clause
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 */

#include "rse_persistent_data.h"

#include <stdbool.h>
#include <string.h>
#include "region_defs.h"

/*
 * Magic value used to check if the persistent region is initialized.
 *
 * This can also be used to avoid versioning issues. If a change is made to the
 * struct that would break compatibility with older ROMs then the magic value
 * can be changed to make it clear that it is no longer compatible with old
 * ROMs.
 */
#define RSE_PERSISTENT_DATA_MAGIC 0xDA1ABA5E

static bool is_persistent_data_initialized(struct rse_persistent_data *persistent_data)
{
    return persistent_data->bl1_data.initialized_magic == RSE_PERSISTENT_DATA_MAGIC;
}

static void initialize_rse_persistent_data(struct rse_persistent_data *persistent_data)
{
    memset(persistent_data, 0, sizeof(struct rse_persistent_data));
    persistent_data->bl1_data.initialized_magic = RSE_PERSISTENT_DATA_MAGIC;
}

void rse_setup_persistent_data(void)
{
    struct rse_persistent_data *rse_persistent_data;

    assert(sizeof(struct rse_persistent_data) <= PERSISTENT_DATA_SIZE);
    assert(PERSISTENT_DATA_BASE % __alignof__(struct rse_persistent_data) == 0);

    rse_get_persistent_data(&rse_persistent_data);

    /*
     * If initialization magic is wrong then assume the persistent data is not
     * initialized or corrupted so initialize the persistent data to 0.
     */
    if (!is_persistent_data_initialized(rse_persistent_data)) {
        initialize_rse_persistent_data(rse_persistent_data);
    }
}

void rse_get_persistent_data(struct rse_persistent_data **persistent_data)
{
    *persistent_data = (struct rse_persistent_data *)PERSISTENT_DATA_BASE;
}
