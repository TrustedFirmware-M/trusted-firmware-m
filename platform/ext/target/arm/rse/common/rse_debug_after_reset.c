/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <stdint.h>
#include "platform_regs.h"
#include "rse_debug_after_reset.h"
#include "runtime_shared_data.h"
#include "tfm_hal_device_header.h"
#include "tfm_hal_platform.h"

int rse_debug_after_reset(const uint8_t *permissions_mask,
                          size_t mask_len)
{
    int rc;

    if (permissions_mask == NULL) {
        return -1;
    }

    /* Copy permissions to the the shared area before reset */
    rc = runtime_add_data_to_shared_area(TLV_RUNTIME_MAJOR_ADAC,
                                         0,
                                         permissions_mask,
                                         mask_len);
    if (rc != 0) {
        return -1;
    }

    tfm_hal_system_reset(RSE_SWSYN_ENTER_DEBUG_MASK);

    return 0;
}
