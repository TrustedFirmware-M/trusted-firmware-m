/*
 * Copyright (c) 2023-2025 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

/*
 * \file This file provides private types/functions for platform specific IOCTL requests.
 */

#ifndef IFX_PLATFORM_PRIVATE
#define IFX_PLATFORM_PRIVATE

#include "config_tfm.h"
#include "tfm_platform_api.h"

#if DOMAIN_S
#include "tfm_plat_defs.h"
#endif /* DOMAIN_S */


#ifdef __cplusplus
extern "C" {
#endif

/**
 * \brief Log message to SPM UART for the first core id
 */
#define IFX_PLATFORM_IOCTL_LOG_MSG_MIN  0x00000000

/**
 * \brief Log message to SPM UART for the last core id
 */
#define IFX_PLATFORM_IOCTL_LOG_MSG_MAX  (IFX_PLATFORM_IOCTL_LOG_MSG_MIN + IFX_STDIO_CORE_COUNT - 1)

/**
 * \brief MTB SRF
 */
#define IFX_PLATFORM_API_ID_MTB_SRF     2001

#ifndef IFX_CUSTOM_PLATFORM_HAL_IOCTL
#define IFX_CUSTOM_PLATFORM_HAL_IOCTL   0
#endif

#if defined(DOMAIN_S)
#if IFX_CUSTOM_PLATFORM_HAL_IOCTL == 1
/*!
 * \brief Performs an application specific IOCTL request for platform-specific service.
 *
 * Override this function to implement application specific IOCTL requests for your project.
 *
 * \note There is default implementation with weak linkage.
 *
 * \param[in]  request      Request identifier (valid values vary
 *                          based on the platform)
 * \param[in]  in_vec       Input buffer to the requested service (or NULL)
 * \param[out] out_vec      Output buffer to the requested service (or NULL)
 *
 * \return Returns values as specified by the \ref tfm_platform_err_t
 */
TFM_LINK_SET_RO_IN_PARTITION_SECTION("TFM_SP_PLATFORM", "PSA-ROT")
enum tfm_platform_err_t ifx_platform_hal_ioctl(tfm_platform_ioctl_req_t request,
                                               psa_invec  *in_vec,
                                               psa_outvec *out_vec);
#endif /* IFX_CUSTOM_PLATFORM_HAL_IOCTL == 1 */
#endif /* DOMAIN_S */


#ifdef __cplusplus
}
#endif

#endif /* IFX_PLATFORM_PRIVATE */
