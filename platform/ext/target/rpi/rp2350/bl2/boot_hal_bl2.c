/*
 * SPDX-License-Identifier: BSD-3-Clause
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 */

#include "boot_hal.h"

#include <string.h>
#include "bl2_image_id.h"

bool boot_platform_should_load_image(uint32_t image_id)
{
#ifndef TFM_LOAD_NS_IMAGE
    if (image_id == RP2350_BL2_IMAGE_NS) {
        return false;
    }
#endif /* TFM_LOAD_NS_IMAGE */

    return true;
}
