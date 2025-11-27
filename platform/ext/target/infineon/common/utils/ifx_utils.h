/*
 * Copyright (c) 2023-2025 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef IFX_UTILS_H
#define IFX_UTILS_H

/* This file is used for definitions that are common for all Infineon MCU family */

/* Align value to nearest `align` value which is equal or greater than `x` */
#define IFX_ALIGN_UP_TO(x, align) \
            ((((x) % (align)) == 0u) ? (x) : ((((x) / (align)) + 1u) * (align)))

#if __STDC_VERSION__ >= 201000L
#define IFX_ASSERT_STR2(s)         #s
#define IFX_ASSERT_STR(s)          IFX_ASSERT_STR2(s)
/* C11 static assertion */
#define IFX_ASSERT(condition)      _Static_assert(!!(condition) ? 1 : 0, IFX_ASSERT_STR(condition))
#else
/* Below C11, there is no built in assert, emulate it */
#define IFX_ASSERT(condition)      sizeof(char[!!(condition) ? 1 : -1])
#endif

/* Linker script can't handle unsigned suffix U, so it is
 * added for compiler and not added for linker script */
#ifdef IFX_LINKER_SCRIPT
#define IFX_UNSIGNED(x)    (x)
#else
#define IFX_UNSIGNED(x)    (x ## U)
#endif

/* Add unsigned suffix to value of macros */
#define IFX_UNSIGNED_TO_VALUE(x)   IFX_UNSIGNED(x)

/* Rounds the given number up to the desired multiple. */
#define IFX_ROUND_UP_TO_MULTIPLE(number, multiple) ((((number) + (multiple) - 1U) \
                                                     / (multiple)) * (multiple))
/* Rounds the given number down to the desired multiple. */
#define IFX_ROUND_DOWN_TO_MULTIPLE(number, multiple) (((number) / (multiple)) * (multiple))

#define IFX_UNUSED(x)  ((void)x)

#endif /* IFX_UTILS_H */
