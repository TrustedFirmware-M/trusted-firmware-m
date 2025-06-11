/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __RSE_GET_RSE_ID_H__
#define __RSE_GET_RSE_ID_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

enum tfm_plat_err_t rse_get_rse_id(uint32_t *rse_id);

#ifdef __cplusplus
}
#endif

#endif /* __RSE_GET_RSE_ID_H__ */
