/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __CONFIG_TFM_TARGET_H__
#define __CONFIG_TFM_TARGET_H__

#include "config_tfm_target_rse_common.h"

/* Use stored NV seed to provide entropy */
#undef CRYPTO_NV_SEED
#define CRYPTO_NV_SEED                         0

/* Use external RNG to provide entropy */
#define CRYPTO_EXT_RNG                         1

#define NS_AGENT_MAILBOX_STACK_SIZE            0xC00

/* Run the scheduler after handling a secure interrupt if the NSPE was pre-empted */
#define CONFIG_TFM_SCHEDULE_WHEN_NS_INTERRUPTED 1

/*
 * tfm_hal_post_partition_init_hook is called if this option is enabled.
 * It's called by SPM right before starting scheduler.
 */
#define CONFIG_TFM_POST_PARTITION_INIT_HOOK     1

/* Default RSE SYSCLK/CPU0CLK value in Hz */
#define SYSCLK         100000000UL /* 100 MHz */

/* Clock configuration value to write to CLK_CFG1.SYSCLKCFG to drive SYSCLKCFG signal */
#define SYSCLKCFG_VAL  0

/* Maximum RSE Comms payload size */
#define RSE_COMMS_PAYLOAD_MAX_SIZE (0x40 + 0x800)

#endif /* __CONFIG_TFM_TARGET_H__ */
