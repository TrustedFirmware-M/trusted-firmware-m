/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __CONFIG_TFM_TARGET_H__
#define __CONFIG_TFM_TARGET_H__

#include "config_tfm_target_tc_common.h"

/* SCMI Comms SCP doorbell IRQ number and handler */
#define SCP_DOORBELL_IRQ         CMU_MHU5_Receiver_IRQn
#define SCP_DOORBELL_IRQ_HANDLER CMU_MHU5_Receiver_Handler

#endif /* __CONFIG_TFM_TARGET_H__ */
