/*
 * SPDX-License-Identifier: BSD-3-Clause
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 */

#ifndef __RSE_SOC_UID_H__
#define __RSE_SOC_UID_H__

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include "tfm_plat_defs.h"

#ifdef __cplusplus
extern "C" {
#endif

enum tfm_plat_err_t rse_generate_soc_uid(void);

enum tfm_plat_err_t rse_lock_soc_uid(void);

#ifdef __cplusplus
}
#endif

#endif /* __RSE_SOC_UID_H__ */
