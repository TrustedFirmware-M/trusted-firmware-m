/*
 * Copyright (c) 2017-2019, Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __TFM_SST_DEFS_H__
#define __TFM_SST_DEFS_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Invalid UID */
#define TFM_SST_INVALID_UID 0

#ifdef TFM_PSA_API
/*
 * Defines for SID and minor version number. These SIDs should align with the
 * value in service manifest file.
 */
#define TFM_SST_SET_SID              (0x00002000)
#define TFM_SST_SET_MIN_VER          (0x0001)
#define TFM_SST_GET_SID              (0x00002001)
#define TFM_SST_GET_MIN_VER          (0x0001)
#define TFM_SST_GET_INFO_SID         (0x00002002)
#define TFM_SST_GET_INFO_MIN_VER     (0x0001)
#define TFM_SST_REMOVE_SID           (0x00002003)
#define TFM_SST_REMOVE_MIN_VER       (0x0001)
#define TFM_SST_GET_SUPPORT_SID      (0x00002004)
#define TFM_SST_GET_SUPPORT_MIN_VER  (0x0001)
#endif

#ifdef __cplusplus
}
#endif

#endif /* __TFM_SST_DEFS_H__ */
