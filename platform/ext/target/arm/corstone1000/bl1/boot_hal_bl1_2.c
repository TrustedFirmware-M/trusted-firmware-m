/*
 * Copyright (c) 2019-2024, Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <stdio.h>
#include "tfm_hal_device_header.h"
#include "region.h"
#include "boot_hal.h"
#include "Driver_Flash.h"
#include "flash_layout.h"
#include "fih.h"
#include "firewall.h"
#include "watchdog.h"
#include "mpu_config.h"
#include "tfm_plat_otp.h"
#include "tfm_plat_provisioning.h"
#include "fwu_agent.h"
#include "uart_stdout.h"
#include "region_defs.h"
#include "tfm_log.h"
#include "cc3xx_init.h"

#ifdef CRYPTO_HW_ACCELERATOR
#include "cc3xx_dev.h"
#endif /* CRYPTO_HW_ACCELERATOR */

/* Flash device name must be specified by target */
extern ARM_DRIVER_FLASH FLASH_DEV_NAME;

extern ARM_DRIVER_FLASH FLASH_DEV_NAME_SE_SECURE_FLASH;

#define CORSTONE1000_HOST_ADDRESS_SPACE_SIZE  0x80000000U

uint32_t bl1_image_get_flash_offset(uint32_t image_id)
{
    /* SE BL2 Offset is equal to bank offset as it is the first think in the Bank */
    uint32_t se_bl2_offset = 0;
    bl1_get_active_bl2_image(&se_bl2_offset);
    switch (image_id) {
        case 0:
            return se_bl2_offset;
        case 1:
            return se_bl2_offset + SE_BL2_PARTITION_SIZE;
        default:
            FIH_PANIC;
    }
}

int32_t boot_platform_init(void)
{
#if (LOG_LEVEL > LOG_LEVEL_NONE) || defined(TEST_BL1_1) || defined(TEST_BL1_2)
    stdio_init();
#endif /* (LOG_LEVEL > LOG_LEVEL_NONE) || defined(TEST_BL1_1) || defined(TEST_BL1_2) */
    return 0;
}

int32_t boot_platform_post_init(void)
{
    int32_t result;
    result = FLASH_DEV_NAME.Initialize(NULL);
    if (result != ARM_DRIVER_OK) {
        return 1;
    }

    return 0;
}

void boot_platform_start_next_image(struct boot_arm_vector_table *vt)
{
    /* Clang at O0, stores variables on the stack with SP relative addressing.
     * When manually set the SP then the place of reset vector is lost.
     * Static variables are stored in 'data' or 'bss' section, change of SP has
     * no effect on them.
     */
    static struct boot_arm_vector_table *vt_cpy;
    int32_t result;

#ifdef CRYPTO_HW_ACCELERATOR
    result = cc3xx_lowlevel_uninit();
    if (result) {
        while (1);
    }

    fih_delay_init();
#endif /* CRYPTO_HW_ACCELERATOR */


#if (LOG_LEVEL > LOG_LEVEL_NONE) || defined(TEST_BL1_1) || defined(TEST_BL1_2)
    stdio_uninit();
#endif /* (LOG_LEVEL > LOG_LEVEL_NONE) || defined(TEST_BL1_1) || defined(TEST_BL1_2) */

    result = FLASH_DEV_NAME.Uninitialize();
    if (result != ARM_DRIVER_OK) {
        while (1);
    }

    result = corstone1000_watchdog_reset_timer();
    if (result != ARM_DRIVER_OK) {
        while (1);
    }

    vt_cpy = vt;

    __set_MSP(vt->msp);
    __DSB();
    __ISB();

    boot_jump_to_next_image(vt_cpy->reset);
}
