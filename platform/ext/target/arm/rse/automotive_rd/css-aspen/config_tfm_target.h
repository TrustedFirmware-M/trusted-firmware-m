/*
 * SPDX-License-Identifier: BSD-3-Clause
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 */

/**
 * \file flash_layout.h
 * \brief This file contains configurations for secure runtime partitions.
 */

#ifndef __CONFIG_TFM_TARGET_H__
#define __CONFIG_TFM_TARGET_H__

#include "config_tfm_target_rse_common.h"

/* Set the initial attestation token profile */
#define ATTEST_TOKEN_PROFILE_PSA_IOT_1           1

/* Use stored NV seed to provide entropy */
#define CRYPTO_NV_SEED                          0

/* Use external RNG to provide entropy */
#define CRYPTO_EXT_RNG                         1

/* The stack size of the NS Agent Mailbox Secure Partition */
#define NS_AGENT_MAILBOX_STACK_SIZE             0x1000

/* Run the scheduler after handling a secure interrupt if the NSPE was pre-empted */
#define CONFIG_TFM_SCHEDULE_WHEN_NS_INTERRUPTED 1

/* The maximum asset size to be stored in the Internal Trusted Storage */
#define ITS_MAX_ASSET_SIZE 4096

/*
 * The maximum number of assets to be stored in the Internal Trusted
 * Storage area.
 */
#define ITS_NUM_ASSETS 20

/* The maximum asset size to be stored in the Protected Storage */
#define PS_MAX_ASSET_SIZE 3456

/* The maximum number of assets to be stored in the Protected Storage area. */
#define PS_NUM_ASSETS 20

/* This is needed to be able to process the EFI variables during PS writes. */
#undef CRYPTO_ENGINE_BUF_SIZE
#define CRYPTO_ENGINE_BUF_SIZE                 0x5000

/* This is also has to be increased to fit the EFI variables into the iovecs. */
#undef CRYPTO_IOVEC_BUFFER_SIZE
#define CRYPTO_IOVEC_BUFFER_SIZE               7128

/* Default RSE SYSCLK/CPU0CLK value in Hz */
#define SYSCLK         100000000UL /* 100 MHz */

/* Clock configuration value to write to CLK_CFG1.SYSCLKCFG to drive SYSCLKCFG signal */
#define SYSCLKCFG_VAL  0

/* Maximum SFCP payload size using Embed protocol */
#define SFCP_PAYLOAD_MAX_SIZE (0x3FE0)

/* Allow NS client ID 0 */
#define MAILBOX_SUPPORT_NS_CLIENT_ID_ZERO 1

#endif /* __CONFIG_TFM_TARGET_H__ */
