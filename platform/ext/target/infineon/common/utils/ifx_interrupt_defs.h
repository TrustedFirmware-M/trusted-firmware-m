/*
 * Copyright (c) 2023-2025 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef IFX_INTERRUPT_DEFS_H
#define IFX_INTERRUPT_DEFS_H

#ifdef __cplusplus
extern "C" {
#endif

#define IFX_CONCAT(x, y) x##y
#define IFX_IRQ_NAME_TO_HANDLER(irq) IFX_CONCAT(irq, _Handler)

#ifdef __cplusplus
}
#endif

#endif /* IFX_INTERRUPT_DEFS_H */
