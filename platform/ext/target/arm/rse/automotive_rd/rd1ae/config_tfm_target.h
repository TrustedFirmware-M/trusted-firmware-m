/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

/**
 * \file flash_layout.h
 * \brief This file contains configurations for secure runtime partitions.
 */

#ifndef __CONFIG_TFM_TARGET_H__
#define __CONFIG_TFM_TARGET_H__

#include "config_tfm_target_rse_common.h"

/* Use stored NV seed to provide entropy */
#define CRYPTO_NV_SEED                          0

/* Use external RNG to provide entropy */
#define CRYPTO_EXT_RNG                         1

/* The stack size of the NS Agent Mailbox Secure Partition */
#define NS_AGENT_MAILBOX_STACK_SIZE             0x1000

/* Run the scheduler after handling a secure interrupt if the NSPE was pre-empted */
#define CONFIG_TFM_SCHEDULE_WHEN_NS_INTERRUPTED 1

/*
 * tfm_hal_post_partition_init_hook is called if this option is enabled.
 * It's called by SPM right before starting scheduler.
 */
#define CONFIG_TFM_POST_PARTITION_INIT_HOOK     1

/* The maximum asset size to be stored in the Internal Trusted Storage */
#define ITS_MAX_ASSET_SIZE 4096

/*
 * The maximum number of assets to be stored in the Internal Trusted
 * Storage area.
 */
#define ITS_NUM_ASSETS 20

/* The maximum number of assets to be stored in the Protected Storage area. */
#define PS_NUM_ASSETS 20

/* Default RSE SYSCLK/CPU0CLK value in Hz */
#define SYSCLK         100000000UL /* 100 MHz */

/* Clock configuration value to write to CLK_CFG1.SYSCLKCFG to drive SYSCLKCFG signal */
#define SYSCLKCFG_VAL  0

/* Maximum RSE Comms payload size */
#define RSE_COMMS_PAYLOAD_MAX_SIZE (0x3FE0)

/* SCMI Comms SCP doorbell IRQ number and handler */
#define SCP_DOORBELL_IRQ         CMU_MHU4_Receiver_IRQn
#define SCP_DOORBELL_IRQ_HANDLER CMU_MHU4_Receiver_Handler

#endif /* __CONFIG_TFM_TARGET_H__ */
