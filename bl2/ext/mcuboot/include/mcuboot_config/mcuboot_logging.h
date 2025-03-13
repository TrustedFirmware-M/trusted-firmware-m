/*
 * Copyright (c) 2017 Linaro Limited
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef __MCUBOOT_LOGGING_H__
#define __MCUBOOT_LOGGING_H__

#include "bootutil/ignore.h"
#include "tfm_log.h"

#ifdef __cplusplus
extern "C" {
#endif

#define MCUBOOT_LOG_LEVEL_OFF       LOG_LEVEL_NONE
#define MCUBOOT_LOG_LEVEL_ERROR     LOG_LEVEL_ERROR
#define MCUBOOT_LOG_LEVEL_WARNING   LOG_LEVEL_WARNING
#define MCUBOOT_LOG_LEVEL_INFO      LOG_LEVEL_INFO
#define MCUBOOT_LOG_LEVEL_DEBUG     LOG_LEVEL_VERBOSE

#if defined(MCUBOOT_LOG_LEVEL) && (MCUBOOT_LOG_LEVEL != LOG_LEVEL)
#error "MCUBOOT_LOG_LEVEL does not match LOG_LEVEL"
#elif !defined(MCUBOOT_LOG_LEVEL)
#define MCUBOOT_LOG_LEVEL LOG_LEVEL
#endif

#define MCUBOOT_LOG_MODULE_DECLARE(domain)      /* Ignore */
#define MCUBOOT_LOG_MODULE_REGISTER(domain)     /* Ignore */

#define MCUBOOT_LOG_ERR(_fmt, ...) \
    ERROR(_fmt "\n", ##__VA_ARGS__)

#define MCUBOOT_LOG_WRN(_fmt, ...) \
    WARN(_fmt "\n", ##__VA_ARGS__)

#define MCUBOOT_LOG_INF(_fmt, ...) \
    INFO(_fmt "\n", ##__VA_ARGS__)

#define MCUBOOT_LOG_DBG(_fmt, ...) \
    VERBOSE(_fmt "\n", ##__VA_ARGS__)

#ifdef __cplusplus
}
#endif

#endif /* __MCUBOOT_LOGGING_H__ */
