/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 * Copyright (c) 2026 Texas Instruments Incorporated. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef __TARGET_CFG_H__
#define __TARGET_CFG_H__

#include <stdint.h>

/* USART driver aliases used by TF-M stdio */
#define TFM_DRIVER_STDIO    Driver_USART0
#define NS_DRIVER_STDIO     Driver_USART0

/*
 * ppc_bank_t required by common_target_cfg.h; GSC's PPC can't be
 * addressed by a generic bank/position scheme, so only the mandatory
 * sentinel value is defined.
 */
typedef enum {
    PPC_SP_DO_NOT_CONFIGURE = -1,
} ppc_bank_t;

/*
 * struct memory_region_limits and struct platform_data_t are defined by
 * platform/ext/common/common_target_cfg.h which includes this file.
 * Do NOT redefine them here.
 */

#endif /* __TARGET_CFG_H__ */
