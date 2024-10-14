/*
 * SPDX-License-Identifier: BSD-3-Clause
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 */

#include "bl2_image_id.h"
#include "boot_hal.h"
#include "bootutil/bootutil_log.h"
#include "crypto_hw.h"
#include "device_definition.h"
#include "fih.h"
#include "flash_layout.h"
#include "flash_map/flash_map.h"
#include "host_base_address.h"
#include "platform_base_address.h"
#include "platform_regs.h"

#include <string.h>

/*
 * ============================ INIT FUNCTIONS =================================
 */

int32_t boot_platform_post_init(void)
{
    int32_t result;

    result = crypto_hw_accelerator_init();
    if (result) {
        return 1;
    }

    (void)fih_delay_init();

    return 0;
}

/*
 * ========================= SECURE LOAD FUNCTIONS =============================
 */

static int boot_platform_pre_load_secure(void)
{
    return 0;
}

static int boot_platform_post_load_secure(void)
{
    return 0;
}

/*
 * ================================= VECTORS ==================================
 */

/*
 * Array of function pointers to call before each image is loaded indexed by
 * image id
 */
static int (*boot_platform_pre_load_vector[RSE_FIRMWARE_COUNT]) (void) = {
    [RSE_FIRMWARE_SECURE_ID]        = boot_platform_pre_load_secure,
};

/*
 * Array of function pointers to call after each image is loaded indexed by
 * image id
 */
static int (*boot_platform_post_load_vector[RSE_FIRMWARE_COUNT]) (void) = {
    [RSE_FIRMWARE_SECURE_ID]        = boot_platform_post_load_secure,
};

/*
 * ============================== LOAD FUNCTIONS ==============================
 */

int boot_platform_pre_load(uint32_t image_id)
{
    if (image_id >= RSE_FIRMWARE_COUNT) {
        BOOT_LOG_WRN("BL2: no pre load for image %u", image_id);
        return 0;
    }

    return boot_platform_pre_load_vector[image_id]();
}

int boot_platform_post_load(uint32_t image_id)
{
    if (image_id >= RSE_FIRMWARE_COUNT) {
        BOOT_LOG_WRN("BL2: no post load for image %u", image_id);
        return 0;
    }

    return boot_platform_post_load_vector[image_id]();
}

bool boot_platform_should_load_image(uint32_t image_id)
{
    if (image_id == RSE_FIRMWARE_NON_SECURE_ID) {
        return false;
    }

    if (image_id >= RSE_FIRMWARE_COUNT) {
        BOOT_LOG_WRN("BL2: Image %u beyond expected Firmware count: %d",
                image_id, RSE_FIRMWARE_COUNT);
        return false;
    }

    return true;
}
