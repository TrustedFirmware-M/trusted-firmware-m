/*
 * SPDX-License-Identifier: BSD-3-Clause
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 */

#ifndef __SID_DRV_H__
#define __SID_DRV_H__

#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* SID device definition */
struct sid_dev_t {
    /* Base address of SID registers */
    const uintptr_t sid_base;
};

bool sid_is_cl1_present(const struct sid_dev_t *dev);

#ifdef __cplusplus
}
#endif

#endif /* __SID_DRV_H__ */
