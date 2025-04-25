/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __RSE_ROTPK_REVOCATION_H__
#define __RSE_ROTPK_REVOCATION_H__

#include <stddef.h>

#include "tfm_plat_defs.h"

#ifdef __cplusplus
extern "C" {
#endif

enum tfm_plat_err_t rse_revoke_cm_rotpks(void);
enum tfm_plat_err_t rse_revoke_dm_rotpks(void);

enum tfm_plat_err_t rse_update_cm_rotpks(uint32_t policies, uint8_t *rotpks, size_t rotpks_len);
enum tfm_plat_err_t rse_update_dm_rotpks(uint32_t policies, uint8_t *rotpks, size_t rotpks_len);

#ifdef __cplusplus
}
#endif

#endif /* __RSE_ROTPK_REVOCATION_H__ */
