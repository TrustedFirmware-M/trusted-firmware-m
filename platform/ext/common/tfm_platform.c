/*
 * Copyright (c) 2019, Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "target_cfg.h"
#include "platform/include/tfm_spm_hal.h"

/**
 * \brief This function initializes platform peripherals.
 *
 * Contrarily to SystemInit() intended for a high-priority hw initialization
 * (for example clock and power subsystems), and called on a very early boot
 * stage from startup code, this function is called from C code, hence
 * variables and other drivers data are protected from being cleared up by the
 * C library init.
 * Implemented as a "weak" function, it can be overwritten by a platform
 * specific implementation.
 *
 * \return Returns values as specified by the \ref tfm_plat_err_t
 */

__WEAK enum tfm_plat_err_t tfm_spm_hal_post_platform_init(void)
{
    __enable_irq();
    stdio_init();
    return TFM_PLAT_ERR_SUCCESS;
}

