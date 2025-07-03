/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __BL1_1_DEBUG_H__
#define __BL1_1_DEBUG_H__

#include <stdint.h>
#include "tfm_plat_defs.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \brief                     Checks for valid conditions and applies
 *                            appropriate permissions DCU mask to open debug
 *
 * \return                    0 on success, non-zero on error.
 */
enum tfm_plat_err_t b1_1_platform_debug_init(void);

#ifdef __cplusplus
}
#endif

#endif /* __BL1_1_DEBUG_H__ */
