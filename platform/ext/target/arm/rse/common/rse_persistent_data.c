/*
 * SPDX-License-Identifier: BSD-3-Clause
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 */

#include "rse_persistent_data.h"

#include <assert.h>
#include <stdbool.h>
#include <string.h>
#include "region_defs.h"
#include "device_definition.h"
#include "rse_gretreg.h"

static bool is_persistent_data_initialized(struct rse_persistent_data *persistent_data)
{
    return rse_gretreg_flag_is_set(RSE_GRETREG_BIT_OFFSET_PERSISTENT_DATA_VALID);
}

static void initialize_rse_persistent_data(struct rse_persistent_data *persistent_data)
{
    memset(persistent_data, 0, sizeof(struct rse_persistent_data));
    rse_gretreg_set_flag(RSE_GRETREG_BIT_OFFSET_PERSISTENT_DATA_VALID);

    set_persistent_data_flag(LAST_BOOT_DEBUG_CODE_BLOCK_CERT_DEBUG,
        RSE_PERSISTENT_DATA_FLAGS_LAST_BOOT_DEBUG_CODE);
}

void rse_setup_persistent_data(void)
{
    assert(sizeof(struct rse_persistent_data) <= PERSISTENT_DATA_SIZE);
    assert((uintptr_t)RSE_PERSISTENT_DATA % __alignof__(struct rse_persistent_data) == 0);

    /*
     * If initialization magic is wrong then assume the persistent data is not
     * initialized or corrupted so initialize the persistent data to 0.
     */
    if (!is_persistent_data_initialized(RSE_PERSISTENT_DATA)) {
        initialize_rse_persistent_data(RSE_PERSISTENT_DATA);
    }
}

