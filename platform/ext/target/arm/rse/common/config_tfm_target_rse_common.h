/*
 * SPDX-License-Identifier: BSD-3-Clause
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 */

#ifndef __CONFIG_TFM_TARGET_COMMON_H__
#define __CONFIG_TFM_TARGET_COMMON_H__

/* The statically allocated internal buffer of the Crypto partition cannot be fully disabled,
 * a small buffer is still needed, as it is used as an internal heap.
 */
#define CRYPTO_ENGINE_BUF_SIZE              0x400

/* Disable PSA Crypto asymmetric key encryption module */
#define CRYPTO_ASYM_ENCRYPT_MODULE_ENABLED  0

#endif /* __CONFIG_TFM_TARGET_COMMON_H__ */
