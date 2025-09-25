/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <stdbool.h>
#include <string.h>
#include "bl1_1_debug.h"
#include "device_definition.h"
#include "lcm_drv.h"
#include "platform_base_address.h"
#include "platform_dcu.h"
#include "platform_regs.h"
#include "region_defs.h"
#include "runtime_shared_data.h"
#include "soft_crc.h"
#include "tfm_hal_platform.h"

#ifdef PLATFORM_PSA_ADAC_SECURE_DEBUG
static bool read_saved_debug_state(void)
{
    return (tfm_hal_get_reset_syndrome() & RSE_SWSYN_ENTER_DEBUG_MASK);
}

static void clear_debug_state(void)
{
    tfm_hal_clear_reset_syndrome_bit(RSE_SWSYN_DEBUG_STATE_IN_BOOT_BIT_POS);
}

static int get_permissions_mask_from_shared_sram_area(uint8_t *permissions_mask,
                                                      size_t mask_len)
{
    if (permissions_mask == NULL) {
        return -1;
    }

    return get_runtime_shared_data(TLV_RUNTIME_MAJOR_ADAC,
                                   0,
                                   permissions_mask,
                                   mask_len);
}

static int32_t tfm_plat_apply_debug_permissions(uint8_t *permissions_mask)
{
    return lcm_dcu_set_enabled(&LCM_DEV_S, permissions_mask);
}
#endif /* PLATFORM_PSA_ADAC_SECURE_DEBUG */

int32_t b1_1_platform_debug_init(void)
{
#ifdef PLATFORM_PSA_ADAC_SECURE_DEBUG
    int32_t rc;
    bool is_debug_requested;
    uint8_t permissions_mask[LCM_DCU_WIDTH_IN_BYTES];

    /* Read debug state from reset syndrome register */
    is_debug_requested = read_saved_debug_state();

    if (is_debug_requested) {
        /* Copy the permissions vector from shared area */
        rc = get_permissions_mask_from_shared_sram_area(permissions_mask,
                                                        sizeof(permissions_mask));
        if (rc != 0) {
            return rc;
        }

        /* Clear debug state notification once mask is read */
        clear_debug_state();

        /* Apply required debug permissions */
        rc = tfm_plat_apply_debug_permissions(permissions_mask);
        if (rc != 0) {
            return rc;
        }
    }
#endif /* PLATFORM_PSA_ADAC_SECURE_DEBUG */
    return 0;
}

