/*
 * Copyright (c) 2019, Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __TFM_CRYPTO_SIGNAL_H__
#define __TFM_CRYPTO_SIGNAL_H__

#define TFM_IPC_SIG_RESERVED_POS (4U)

#define TFM_CRYPTO_SIG_POS (TFM_IPC_SIG_RESERVED_POS+0U)

/**
 * \brief Definitions for the signals available in the Crypto partition
 *
 */
#define TFM_CRYPTO_SIG     (1U << TFM_CRYPTO_SIG_POS)

#endif /* __TFM_CRYPTO_SIGNAL_H__ */
