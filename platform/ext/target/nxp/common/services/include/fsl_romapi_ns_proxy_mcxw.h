/*
 * Copyright 2026 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

/*
 * ROM API NS proxy stub for MCXW/KW43 targets.
 *
 * ROMAPI_GetVersion and ROMAPI_RunBootloader are not supported on this
 * target family. Including this header produces a build-time warning to
 * alert integrators that the ROM API IOCTL service is unavailable.
 */

#ifndef FSL_ROMAPI_NS_PROXY_MCXW_H__
#define FSL_ROMAPI_NS_PROXY_MCXW_H__

#warning "fsl_romapi_ns_proxy_mcxw.h: ROMAPI_GetVersion and ROMAPI_RunBootloader are not supported on MCXW/KW43 targets."

#endif /* FSL_ROMAPI_NS_PROXY_MCXW_H__ */
