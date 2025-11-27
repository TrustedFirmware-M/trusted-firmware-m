/*
 * Copyright (c) 2023-2025 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef MXS22_H
#define MXS22_H

#include "ifx_utils.h"

/* This file is used for definitions that are common for all MSX22 MCU family */

#define IFX_IDAU_SECURE_ADDRESS_MASK    (IFX_UNSIGNED(0x10000000))

/* ARMClang linker has different syntax for bitwise operations */
#ifdef IFX_ARM_CLANG_LINKER_SCRIPT
/* Convert address to Secure alias by setting 28-bit of address (IDAU as part of TrustZone) */
#define IFX_S_ADDRESS_ALIAS(x)          ((x) or IFX_IDAU_SECURE_ADDRESS_MASK)

/* Convert address to Non-Secure alias by clearing 28-bit of address (IDAU as part of TrustZone) */
#define IFX_NS_ADDRESS_ALIAS(x)         ((x) and ~IFX_IDAU_SECURE_ADDRESS_MASK)
#else
/* Convert address to Secure alias by setting 28-bit of address (IDAU as part of TrustZone) */
#define IFX_S_ADDRESS_ALIAS(x)          ((x) | IFX_IDAU_SECURE_ADDRESS_MASK)

/* Convert address to Non-Secure alias by clearing 28-bit of address (IDAU as part of TrustZone) */
#define IFX_NS_ADDRESS_ALIAS(x)         ((x) & ~IFX_IDAU_SECURE_ADDRESS_MASK)
#endif /* IFX_ARM_CLANG_LINKER_SCRIPT */

/* Convert address to Secure alias and typecast */
#define IFX_S_ADDRESS_ALIAS_T(t, x)          ((t)(IFX_S_ADDRESS_ALIAS((uint32_t)(x))))

/* Convert address to Non-Secure alias and typecast */
#define IFX_NS_ADDRESS_ALIAS_T(t, x)         ((t)(IFX_NS_ADDRESS_ALIAS((uint32_t)(x))))

#endif /* MXS22_H */
