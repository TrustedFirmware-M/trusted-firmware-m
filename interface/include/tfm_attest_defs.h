/*
 * Copyright (c) 2019, Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __TFM_ATTEST_DEFS_H__
#define __TFM_ATTEST_DEFS_H__

#ifdef __cplusplus
extern "C" {
#endif

#ifdef TFM_PSA_API
/*
 * Defines for SID and minor version number. These SIDs must align with the
 * value in service manifest file.
 */
#define TFM_ATTEST_GET_TOKEN_SID               (0x00000020)
#define TFM_ATTEST_GET_TOKEN_MINOR_VER         (0x0001)
#define TFM_ATTEST_GET_TOKEN_SIZE_SID          (0x00000021)
#define TFM_ATTEST_GET_TOKEN_SIZE_MINOR_VER    (0x0001)
#endif

#ifdef __cplusplus
}
#endif

#endif /* __TFM_ATTEST_DEFS_H__ */