/*
 * (c) 2026, Infineon Technologies AG, or an affiliate of Infineon
 * Technologies AG. All rights reserved.
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

/* Those macro are used by inline assembler and must be in a 0x00UL hex format */

#define IFX_PC_TFM_SPM_ID               0x03UL    /* TFM SPM */
#define IFX_PC_TFM_PROT_ID              0x03UL    /* TFM PSA RoT */
#define IFX_PC_TFM_AROT_ID              0x03UL    /* TFM Application RoT */
#define IFX_PC_CM33_NSPE_ID             0x03UL    /* CM33 NSPE Application */
#define IFX_PC_TZ_NSPE_ID               0x03UL    /* NSPE Application */
#define IFX_PC_DEBUGGER_ID              0x07UL    /* Debugger */

#define IFX_PC_NONE                     (0x00)   /* No PC, empty PC mask */
#define IFX_PC_TFM_SPM                  (1UL << IFX_PC_TFM_SPM_ID)
#define IFX_PC_TFM_PROT                 (1UL << IFX_PC_TFM_PROT_ID)
#define IFX_PC_TFM_AROT                 (1UL << IFX_PC_TFM_AROT_ID)
#define IFX_PC_CM33_NSPE                (1UL << IFX_PC_CM33_NSPE_ID)
#define IFX_PC_TZ_NSPE                  (1UL << IFX_PC_TZ_NSPE_ID)
#define IFX_PC_DEBUGGER                 (1UL << IFX_PC_DEBUGGER_ID)

#define IFX_NOT_ROT_CONFIGURATION       (0x00)

#define IFX_REGION_MAX_MPC_COUNT                            (1U)

/* Used to define set of Protection Context that always has access to peripheral
 * and memory resources of partitions. */
#define IFX_PC_DEFAULT                  IFX_PC_TFM_SPM

/* \brief Platform does not configure MPC to provide memory protection*/
#define IFX_MPC_CONFIGURED_BY_TFM                           1

/* \brief Platform has memory protection controller (MPC) */
#define IFX_PLATFORM_MPC_PRESENT                            1

/* \brief Use HW MPC driver with ROT config */
#define IFX_MPC_DRIVER_HW_MPC_WITH_ROT                      1

/* \brief Use HW MPC driver without ROT config */
#define IFX_MPC_DRIVER_HW_MPC_WITHOUT_ROT                   1

/* \brief Use MPC to configure CM55 core */
#define IFX_MPC_CM55_MPC                                    0

/* \brief Use SW Policy MPC driver */
#define IFX_MPC_DRIVER_SW_POLICY                            0

/* \brief Platform has peripheral protection controller (PPC) */
#define IFX_PLATFORM_PPC_PRESENT                            1

/* \brief Response configuration for ACG and MSC for the referenced bus master */
#define IFX_MSC_ACG_RESP_CONFIG                             1

/* \brief Doesn't use response configuration for ACG and MSC for the referenced bus master in CAT1D devices */
#define IFX_MSC_ACG_RESP_CONFIG_V1                          0

/* Bus master ID of core running TF-M */
#define IFX_MSC_TFM_CORE_BUS_MASTER_ID                      CY_MS_CTL_ID_CM33_0

/* Defines whether PSA RoT partitions run in privileged mode */
#define IFX_PSA_ROT_PRIVILEGED                              1

/* Defines whether Application RoT partitions run in privileged mode */
#define IFX_APP_ROT_PRIVILEGED                              0

/* Defines whether NS Agent TZ partition runs in privileged mode */
#define IFX_NS_AGENT_TZ_PRIVILEGED                          1

/* Defines whether Application RoT is protected via dynamic PPC isolation on L3 */
#define IFX_APP_ROT_PPC_DYNAMIC_ISOLATION                   1

/* Defines whether device has multiple types of IAK keys*/
#define IFX_MULTIPLE_IAK_KEY_TYPES                          1

/* Maximum number of MPC regions a memory region can span.
 * It is 2 for this device, as SRAM0 and SRAM1 are two consecutive memories. */
#define IFX_MAX_SPLIT_REGIONS_COUNT                         (2U)

#endif /* IFX_PLATFORM_SPE_CONFIG_H */
