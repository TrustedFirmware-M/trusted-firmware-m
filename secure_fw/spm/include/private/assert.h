/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
#ifndef __TFM_PRIV_ASSERT_H__
#define __TFM_PRIV_ASSERT_H__

#include <string.h>
#include "tfm_log.h"

#ifndef NDEBUG
#define SPM_ASSERT(cond)                                                \
            do {                                                        \
                if (!(cond)) {                                          \
                    INFO_RAW("Assert: %s, %d\n", __func__, __LINE__);   \
                    while (1) {                                         \
                        ;                                               \
                    }                                                   \
                }                                                       \
            } while (0)
#else
#define SPM_ASSERT(cond)
#endif

#define assert(cond) SPM_ASSERT(cond)

#endif /* __TFM_PRIV_ASSERT_H__ */
