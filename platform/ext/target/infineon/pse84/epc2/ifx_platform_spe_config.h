/*
 * Copyright (c) 2024-2025 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

/**
 * \file ifx_platform_spe_config.h
 * \brief This file contains platform specific configuration used to build secure image.
 *
 * This file is part of Infineon platform configuration files. It's expected
 * that this file provides platform dependent configuration used by Infineon common code.
 */

#ifndef IFX_PLATFORM_SPE_CONFIG_H
#define IFX_PLATFORM_SPE_CONFIG_H

#include "pse84_spe_config.h"

/* Those macro are used by inline assembler and must be in a 0x00UL hex format */
#define IFX_PC_SE_RT_ID                 0x01UL    /* Secure Enclave */
#define IFX_PC_TFM_SPM_ID               0x02UL    /* TFM SPM */
#define IFX_PC_TFM_PROT_ID              0x02UL    /* TFM PSA RoT */
#define IFX_PC_TFM_AROT_ID              0x02UL    /* TFM Application RoT */
#define IFX_PC_CM33_NSPE_ID             0x02UL    /* CM33 NSPE Application */
#define IFX_PC_TZ_NSPE_ID               IFX_PC_CM33_NSPE_ID
#define IFX_PC_CM55_NSPE_ID             0x06UL    /* CM55 NSPE Application */
#define IFX_PC_MAILBOX_NSPE_ID          IFX_PC_CM55_NSPE_ID
#define IFX_PC_DEBUGGER_ID              0x07UL    /* Debugger */

#define IFX_PC_NONE                     (0x00)   /* No PC, empty PC mask */
#define IFX_PC_SE_RT                    (1UL << IFX_PC_SE_RT_ID)
#define IFX_PC_TFM_SPM                  (1UL << IFX_PC_TFM_SPM_ID)
#define IFX_PC_TFM_PROT                 (1UL << IFX_PC_TFM_PROT_ID)
#define IFX_PC_TFM_AROT                 (1UL << IFX_PC_TFM_AROT_ID)
#define IFX_PC_CM33_NSPE                (1UL << IFX_PC_CM33_NSPE_ID)
#define IFX_PC_TZ_NSPE                  (1UL << IFX_PC_TZ_NSPE_ID)
#define IFX_PC_CM55_NSPE                (1UL << IFX_PC_CM55_NSPE_ID)
#define IFX_PC_MAILBOX_NSPE             (1UL << IFX_PC_MAILBOX_NSPE_ID)
#define IFX_PC_DEBUGGER                 (1UL << IFX_PC_DEBUGGER_ID)

/* Used to define set of Protection Context that always has access to peripheral
 * and memory resources of partitions. */
#define IFX_PC_DEFAULT                  (IFX_PC_SE_RT | IFX_PC_TFM_SPM)

/* Defines whether PSA RoT partitions run in privileged mode */
#define IFX_PSA_ROT_PRIVILEGED                              1

/* Defines whether Application RoT partitions run in privileged mode */
#define IFX_APP_ROT_PRIVILEGED                              0

/* Defines whether NS Agent TZ partition runs in privileged mode */
#define IFX_NS_AGENT_TZ_PRIVILEGED                          1

/* Defines whether Application RoT is protected via dynamic PPC isolation on L3 */
#define IFX_APP_ROT_PPC_DYNAMIC_ISOLATION                   1

/* Defines whether device has multiple types of IAK keys*/
#define IFX_MULTIPLE_IAK_KEY_TYPES                          0

#endif /* IFX_PLATFORM_SPE_CONFIG_H */
