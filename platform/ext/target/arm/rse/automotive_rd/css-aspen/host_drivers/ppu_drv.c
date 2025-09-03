/*
 * SPDX-License-Identifier: BSD-3-Clause
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 */

#include "ppu_drv.h"

#include <stddef.h>
#include <stdint.h>

#include "tfm_hal_device_header.h"

struct _ppu {
    __IOM uint32_t ppu_pwpr; /* 0x0 */
    __IOM uint32_t ppu_pmer; /* 0x4 */
    __IM  uint32_t ppu_pwsr; /* 0x8 */
    const uint8_t reserved0[0x1000 - 0xC];
};

struct _cluster_safety {
    const uint8_t reserved0[0x60];
    __OM uint32_t cluster_safety_key;
};

#define PPU_PWPR_PWR_POLICY_POS      (0)
#define PPU_PWPR_PWR_POLICY          (0xF << PPU_PWPR_PWR_POLICY_POS)
#define PPU_PWPR_PWR_POLICY_ON       (0x8 << PPU_PWPR_PWR_POLICY_POS)

#define PPU_PWSR_PWR_STATUS_POS      (0)
#define PPU_PWSR_PWR_STATUS          (0xF << PPU_PWSR_PWR_STATUS_POS)
#define PPU_PWSR_PWR_STATUS_ON       (0x8 << PPU_PWSR_PWR_STATUS_POS)

#define CLUSTER_SAFETY_KEY_VALUE     (0x000000BA)

enum ppu_error_t ppu_driver_power_on(const struct ppu_dev_t *dev)
{
    if (dev == NULL) {
        return PPU_ERR_INVALID_PARAM;
    }

    struct _ppu *ppu = (struct _ppu *)dev->ppu_base;
    struct _cluster_safety *cluster_safety = (struct _cluster_safety *)dev->cluster_safety_base;

    if (cluster_safety) {
        /* Unlock PPU registers write operation. */
        cluster_safety->cluster_safety_key = CLUSTER_SAFETY_KEY_VALUE;
    }

    ppu->ppu_pwpr = PPU_PWPR_PWR_POLICY_ON;
    while (ppu->ppu_pwsr != PPU_PWSR_PWR_STATUS_ON) {};

    return PPU_ERR_NONE;
}
