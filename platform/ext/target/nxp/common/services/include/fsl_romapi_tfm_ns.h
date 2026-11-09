/*
 * Copyright 2026 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause.
 *
 */

#ifndef FSL_ROMAPI_TFM_NS_H__
#define FSL_ROMAPI_TFM_NS_H__

#if defined(ROMAPI_PROXY_HAL_MCXL) || defined(ROMAPI_PROXY_HAL_MCXA)
#include "fsl_romapi_ns_proxy_mcxl_mcxa.h"

#elif defined(ROMAPI_PROXY_HAL_MCXW)
#include "fsl_romapi_ns_proxy_mcxw.h"

#else
#error "fsl_romapi_tfm_ns.h: no target selected. Define ROMAPI_PROXY_HAL_MCXL, ROMAPI_PROXY_HAL_MCXA, or ROMAPI_PROXY_HAL_MCXW."

#endif

#endif /* FSL_ROMAPI_TFM_NS_H__ */
