/*
 * Copyright (c) 2025, The TrustedFirmware-M Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __CC3XX_LOG_H__
#define __CC3XX_LOG_H__

#ifdef CC3XX_PLATFORM_LOG
/* Allow for platforms to provide their own implementation of the
 * CC3XX_INFO and CC3XX_INFO_RAW macros
 */
#include CC3XX_PLATFORM_LOG_FILE
#else

#ifdef CC3XX_LOG_STDIO
#include <stdio.h>
#elif CC3XX_LOG_TFM
#include "tfm_log.h"
#endif /* CC3XX_LOG_STDIO */

#ifdef CC3XX_LOG_NONE
#define CC3XX_INFO(...)
#elif CC3XX_LOG_STDIO
#define CC3XX_INFO(...)     printf(__VA_ARGS__)
#define CC3XX_INFO_RAW(...) printf(__VA_ARGS__)
#elif CC3XX_LOG_TFM
#define CC3XX_INFO(...)     INFO(__VA_ARGS__)
#define CC3XX_INFO_RAW(...) INFO_RAW(__VA_ARGS__)
#endif /* CC3XX_LOG_NONE */

#endif /* CC3XX_PLATFORM_LOG */

#endif /* __CC3XX_LOG_H__ */
