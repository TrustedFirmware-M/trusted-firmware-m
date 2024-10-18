/*
 * SPDX-License-Identifier: BSD-3-Clause
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 */

#ifndef __PPU_DRV_H__
#define __PPU_DRV_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

enum ppu_error_t {
    /* No Error */
    PPU_ERR_NONE,
    /* Invalid parameter */
    PPU_ERR_INVALID_PARAM,
    /* Error accessing PPU */
    PPU_ERR_ACCESS,
    /* General error with driver */
    PPU_ERR_GENERAL,
};

struct ppu_dev_t {
    /* Base address of the PPU registers */
    const uintptr_t ppu_base;

    /* Base address of the Cluster safety register */
    const uintptr_t cluster_safety_base;
};

enum ppu_error_t ppu_driver_power_on(const struct ppu_dev_t *dev);

#ifdef __cplusplus
}
#endif

#endif /* __PPU_DRV_H__ */
