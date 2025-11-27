/*
 * Copyright (c) 2024-2025 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

/**
 * \file protection_mpc_sw_policy.h
 * \brief This file contains types/API used by MPC SW Policy driver.
 *
 * \note Don't include this file directly, include protection_types.h instead !!!
 * It's expected that this file is included by protection_types.h if platform is configured
 * to use MPC SW Policy driver via IFX_MPC_DRIVER_SW_POLICY option.
 */

#ifndef PROTECTION_MPC_SW_POLICY_H
#define PROTECTION_MPC_SW_POLICY_H

/* MPC SW Policy driver has no configuration for named MMIO */
#define IFX_MPC_NAMED_MMIO_SPM_ROT_CFG

/* MPC SW Policy driver has no configuration for named MMIO */
#define IFX_MPC_NAMED_MMIO_PSA_ROT_CFG

/* MPC SW Policy driver has no configuration for named MMIO */
#define IFX_MPC_NAMED_MMIO_APP_ROT_CFG

#ifdef TFM_PARTITION_NS_AGENT_TZ
/* MPC SW Policy driver has no configuration for named MMIO */
#define IFX_MPC_NAMED_MMIO_NS_AGENT_TZ_CFG
#endif /* TFM_PARTITION_NS_AGENT_TZ */

#if TFM_ISOLATION_LEVEL == 3
/* MPC SW Policy driver has no configuration for named MMIO */
#define IFX_MPC_NAMED_MMIO_L3_DISABLED_CFG
#endif

#endif /* PROTECTION_MPC_SW_POLICY_H */
