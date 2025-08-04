/*
 * SPDX-License-Identifier: BSD-3-Clause
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 */

#include <string.h>

#include "boot_hal.h"
#include "bl2_image_id.h"
#include "tfm_plat_shared_measurement_data.h"

bool boot_platform_should_load_image(uint32_t image_id)
{
#ifndef TFM_LOAD_NS_IMAGE
    if (image_id == RP2350_BL2_IMAGE_NS) {
        return false;
    }
#endif /* TFM_LOAD_NS_IMAGE */

    return true;
}

int32_t boot_platform_post_init(void)
{
    /* Clear boot data area */
    memset((void *)tfm_plat_get_shared_measurement_data_base(), 0,
           tfm_plat_get_shared_measurement_data_size());

    return 0;
}
