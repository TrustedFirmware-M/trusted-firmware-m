/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

/**
 * \file    staged_boot.c
 * \brief   Images loading from host flash to staging area.
 */

#include <stdint.h>
#include <string.h>

#include "atu_config.h"
#include "atu_rse_lib.h"
#include "bootutil/bootutil_log.h"
#include "device_definition.h"
#include "flash_map/flash_map.h"
#include "flash_layout.h"
#include "platform_base_address.h"
#include "staging_config.h"

#ifdef RSE_GPT_SUPPORT
/* Final patched GPT Image contain both FIPs */
#define FIP_COUNT 1
#else
#define FIP_COUNT 2
#endif

extern ARM_DRIVER_FLASH FLASH_DEV_NAME;

static uint64_t fip_reloc_addr[FIP_COUNT] = {
        STAGING_AREA_FIP_A_BASE_S, /* FIP_A staged logical address in DRAM */
#if FIP_COUNT > 1
        STAGING_AREA_FIP_B_BASE_S  /* FIP_B staged logical address in DRAM */
#endif /* FIP_COUNT > 1 */
};

static uint32_t fip_logical_addr[FIP_COUNT] = {
        HOST_FLASH_FIP_A_BASE_S,
#if FIP_COUNT > 1
        HOST_FLASH_FIP_B_BASE_S
#endif /* FIP_COUNT > 1 */
};

static struct flash_area fip_flash_map[FIP_COUNT] = {
    {
        .fa_id = 1, /* FIP A */
        .fa_device_id = FLASH_DEVICE_ID,
        .fa_driver = &FLASH_DEV_NAME,
        .fa_off = 0,   /* FIP A src addr */
        .fa_size = HOST_FIP_MAX_SIZE,
    },
#if FIP_COUNT > 1
    {
        .fa_id = 2, /* FIP B */
        .fa_device_id = FLASH_DEVICE_ID,
        .fa_driver = &FLASH_DEV_NAME,
        .fa_off = 0x800000,   /* FIP B src addr */
        .fa_size = HOST_FIP_MAX_SIZE,
    }
#endif /* FIP_COUNT > 1 */
};

int32_t run_staged_boot(void)
{
    int i, rc;
    struct flash_area *fap_src;

    for (i = 0; i < FIP_COUNT; i++) {
        fap_src = &fip_flash_map[i];
        if (fip_logical_addr[i] < HOST_ACCESS_BASE_S) {
            BOOT_LOG_ERR("Invalid fip_logical_addr[%d] = %x", i, fip_logical_addr[i]);
            return -1;
        }
        fap_src->fa_off = fip_logical_addr[i] - HOST_ACCESS_BASE_S;

        rc = flash_area_read(fap_src,
                             0,
                             (uint64_t *)fip_reloc_addr[i],
                             fap_src->fa_size);
        if (rc != 0) {
            return -1;
        }

        BOOT_LOG_INF("FIP: %d relocated to address 0x%x", i, fip_reloc_addr[i]);
    }

    return 0;
}
