/*
 * Copyright (c) 2024-2025 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

/**
 * \file pse84_spe_config.h
 * \brief This file contains PSE84 family specific configuration used to build secure image.
 *
 * This file is part of Infineon platform configuration files. It's expected
 * that this file provides platform dependent configuration used by Infineon common code.
 */

#ifndef PSE84_SPE_CONFIG_H
#define PSE84_SPE_CONFIG_H

/* \brief Platform configure MPC to provide memory protection*/
#define IFX_MPC_CONFIGURED_BY_TFM                           1

/* \brief Platform has memory protection controller (MPC) */
#define IFX_PLATFORM_MPC_PRESENT                            1

/* \brief Use HW MPC driver with ROT config */
#define IFX_MPC_DRIVER_HW_MPC_WITH_ROT                      1

/* \brief Use HW MPC driver without ROT config */
#define IFX_MPC_DRIVER_HW_MPC_WITHOUT_ROT                   0

/* \brief Use MPC to configure CM55 core */
#define IFX_MPC_CM55_MPC                                    1

/* Maximum number of different MPCs that are protecting one memory region.
 * For example RRAM is protected by 1 MPC and same SMIF address is protected
 * by 2 MPCs (one for CM33 and one for CM55 bus master) */
#define IFX_REGION_MAX_MPC_COUNT                            (2U)
#define IFX_MPC_NOT_CONTROLLED_BY_TFM                       (NULL)

/* The size of RRAM MPC block size controlled by SE RT Services */
#define IFX_SE_RT_RRAM_BLOCK_SIZE                           4096u
/* The default attributes used to initialize ifx_mpc_se_rt_rram_attr.
 * PC2/S - has read access to RRAM by default while PC0, PC1 are ignored. */
#define IFX_SE_RT_RRAM_MPC_DEFAULT_ATTRIBUTES               0x00000400u

/* \brief Platform has peripheral protection controller (PPC) */
#define IFX_PLATFORM_PPC_PRESENT                            1

/* \brief Response configuration for ACG and MSC for the referenced bus master */
#define IFX_MSC_ACG_RESP_CONFIG                             1

/* \brief Response configuration for ACG and MSC for the referenced bus master in CAT1D devices */
#define IFX_MSC_ACG_RESP_CONFIG_V1                          1

/* Bus master ID of core running TF-M */
#define IFX_MSC_TFM_CORE_BUS_MASTER_ID                      CY_MS_CTL_ID_CM33_0

#endif /* PSE84_SPE_CONFIG_H */
