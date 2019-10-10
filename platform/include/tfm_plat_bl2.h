/*
 * Copyright (c) 2018-2019, Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __TFM_PLAT_BL2_H__
#define __TFM_PLAT_BL2_H__

#include "Driver_Flash.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Flash device name must be specified by target */
extern ARM_DRIVER_FLASH FLASH_DEV_NAME;

/**
 * \brief Platform peripherals and devices initialization.
 *        Can be overridden for platform specific initialization.
 *
 * \return  ARM_DRIVER_OK if the initialization succeeds
*/
__WEAK uint32_t bl2_platform_init(void)
{
    return FLASH_DEV_NAME.Initialize(NULL);
}

#ifdef __cplusplus
}
#endif

#endif /* __TFM_PLAT_BL2_H__ */
