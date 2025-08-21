/*
 * SPDX-License-Identifier: BSD-3-Clause
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 */

#ifndef __BL1_2_CONFIG_H__
#define __BL1_2_CONFIG_H__

#ifndef TFM_BL1_2_SIG_MAX_SIZE
#define TFM_BL1_2_SIG_MAX_SIZE 1452
#endif

#ifndef TFM_BL1_2_SIGNER_AMOUNT
#define TFM_BL1_2_SIGNER_AMOUNT 1
#endif

#ifndef TFM_BL1_2_ROTPK_MAX_SIZE
#define TFM_BL1_2_ROTPK_MAX_SIZE 120
#endif

#ifndef TFM_BL1_2_ROTPK_HASH_MAX_SIZE
#define TFM_BL1_2_ROTPK_HASH_MAX_SIZE 48
#endif

/* These are defined by the build system, change them there */
/* #define TFM_BL1_2_EMBED_ROTPK_IN_IMAGE */
/* #define TFM_BL1_2_IMAGE_ENCRYPTION */
/* #define TFM_BL1_2_ENABLE_ROTPK_POLICIES */

/* #define TFM_BL1_2_ENABLE_LMS */
/* #define TFM_BL1_2_ENABLE_ECDSA */

/* #define TFM_BL1_ENABLE_SHA256 */
/* #define TFM_BL1_ENABLE_SHA384 */

#ifndef TFM_BL1_2_ECDSA_CURVE
#define TFM_BL1_2_ECDSA_CURVE TFM_BL1_CURVE_P256
#endif

#ifndef TFM_BL1_2_MEASUREMENT_HASH_ALG
#define TFM_BL1_2_MEASUREMENT_HASH_ALG TFM_BL1_HASH_ALG_SHA256
#endif

#ifndef TFM_BL1_2_MEASUREMENT_HASH_MAX_SIZE
#define TFM_BL1_2_MEASUREMENT_HASH_MAX_SIZE 48
#endif

/* This must be at minimum 0x100-byte aligned */
#ifndef TFM_BL1_2_HEADER_MAX_SIZE
#define TFM_BL1_2_HEADER_MAX_SIZE 0xD00
#endif

#endif /* __BL1_2_CONFIG_H__ */
