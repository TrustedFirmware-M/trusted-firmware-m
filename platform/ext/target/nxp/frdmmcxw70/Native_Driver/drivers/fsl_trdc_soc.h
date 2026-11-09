/*
 * Copyright 2026 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef _FSL_TRDC_SOC_H_
#define _FSL_TRDC_SOC_H_

#include "fsl_common.h"

/*!
 * @addtogroup trdc_soc
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/*! @name Driver version */
/*@{*/
/*! @brief Driver version 1.0.0. */
#define FSL_TRDC_SOC_DRIVER_VERSION (MAKE_VERSION(1, 0, 0))
/*@}*/

/*!
 * @brief Enumeration for TRDC master mapping
 *
 * Defines the enumeration for TRDC master resource collections.
 */
typedef enum _trdc_master
{
    kTRDC_MasterCM33         = 0U, /**< CM33 */
    kTRDC_MasterNBUAndLpcac1 = 1U, /**< NBU and LPCAC1 */
    kTRDC_MasterDMA          = 2U, /**< DMA */
    kTRDC_MasterRadioNBU     = 3U, /**< Radio NBU */
    kTRDC_MasterDSB          = 4U, /**< DSB */
    kTRDC_MasterNBU_M        = 5U, /**< NBU_M */
    kTRDC_MasterLCE          = 6U, /**< LCE */
} trdc_master_t;

/* @} */

/*!@brief TRDC base address convert macro */
#define TRDC_FLW_OFFSET               0x1E0UL
#define TRDC_DOMAIN_ERROR_OFFSET      0x1FCUL
#define TRDC_DOMAIN_ASSIGNMENT_OFFSET 0x700UL
#define TRDC_MBC_OFFSET(x)            0x1000UL
#define TRDC_MBC_ARRAY_STEP           0x1000UL

/*******************************************************************************
 * API
 ******************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
}
#endif

/*!
 * @}
 */

#endif /* _FSL_TRDC_SOC_H_ */
