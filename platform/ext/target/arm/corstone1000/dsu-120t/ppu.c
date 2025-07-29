/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <stdint.h>
#include "ppu.h"

void PPU_SetPowerPolicy(PPU_TypeDef *ppu, PPU_PowerPolicy_Type policy, bool isDynamic)
{
    uint32_t regval = ppu->PWPR;

    regval &= ~(PPU_PWPR_PWR_POLICY_Msk | PPU_PWPR_PWR_DYN_EN_Msk);

    regval |= ((policy << PPU_PWPR_PWR_POLICY_Pos) & PPU_PWPR_PWR_POLICY_Msk);

    if (isDynamic) {
        regval |= PPU_PWPR_PWR_DYN_EN_Msk;
    }

    ppu->PWPR = regval;
}

void PPU_SetOperatingPolicy(PPU_TypeDef *ppu, PPU_OperatingPolicy_Type policy, bool isDynamic)
{
    uint32_t regval = ppu->PWPR;

    regval &= ~(PPU_PWPR_OP_POLICY_Msk | PPU_PWPR_OP_DYN_EN_Msk);

    regval |= ((policy << PPU_PWPR_OP_POLICY_Pos) & PPU_PWPR_OP_POLICY_Msk);

    if (isDynamic) {
        regval |= PPU_PWPR_OP_DYN_EN_Msk;
    }

    ppu->PWPR = regval;
}

