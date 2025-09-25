/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <stdint.h>
#include <string.h>
#include "test_atu_rse_common.h"
#include "device_definition.h"

void deinit_test_regions(void)
{
    struct atu_dev_t *dev = &ATU_DEV_S;
    struct _atu_reg_map_t *p_atu = (struct _atu_reg_map_t *)dev->cfg->base;
    for (int i = MIN_TEST_REGION; i < NUM_REGIONS; i++) {
        p_atu->atuc &= ~(1u << i);
    }
}
