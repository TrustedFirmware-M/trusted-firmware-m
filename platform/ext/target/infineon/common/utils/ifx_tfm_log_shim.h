/*
 * Copyright (c) 2025 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

/*
 * Infineon platform legacy tfm_log.h — compatibility shim.
 * Detects TF-M version and provides appropriate logging interface:
 * - TF-M 2.2.1 (original): Legacy no-op logging macros (default)
 * - TF-M 2.2.1+ (future 2.3.0): Forward to core lib/tfm_log
 */

#ifndef IFX_TFM_LOG_SHIM_H
#define IFX_TFM_LOG_SHIM_H

/* Simple version detection based on LOG_LEVEL presence */
#if defined(LOG_LEVEL)
  #define IFX_TFM_VERSION_STR "v2.3.X"
#else
  #define IFX_TFM_VERSION_STR "v2.2.X"
#endif

/* Determine logging behavior based on version */
#if defined(LOG_LEVEL)
  /* TF-M 2.2.1+ (which becomes 2.3.0): Use core logging system */
  #include <tfm_log.h>
#else
  /* TF-M 2.2.1 (original): Legacy no-op logging for backward compatibility */
  #ifndef TFM_SPM_LOG_LEVEL
    #define TFM_SPM_LOG_LEVEL 2
  #endif

  /* Define *_RAW macros as no-ops for original 2.2.1 */
  #ifndef ERROR_RAW
    #define ERROR_RAW(...) do{}while(0)
  #endif
  #ifndef INFO_RAW
    #define INFO_RAW(...)  do{}while(0)
  #endif
  #ifndef WARN_RAW
    #define WARN_RAW(...)  do{}while(0)
  #endif
#endif

#endif /* IFX_TFM_LOG_SHIM_H */
