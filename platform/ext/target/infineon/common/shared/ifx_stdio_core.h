/*
 * Copyright (c) 2026 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

/**
 * \file ifx_stdio_core.h
 * \brief STDIO core prefix configuration for all Infineon platforms.
 *
 * This file provides STDIO core identification macros for platforms with
 * CM33 and optionally CM55 cores. It defines:
 * - Core ID enumeration
 * - Core prefix strings for secure CM33, non-secure CM33, and non-secure CM55 output
 * - Macros to select core ID and prefix string at compile time
 *
 * This header works for both single-core (CM33 only) and dual-core (CM33+CM55)
 * platforms. On single-core platforms, the CM55 definitions are present but unused.
 */

#ifndef IFX_STDIO_CORE_H
#define IFX_STDIO_CORE_H

#ifndef IFX_LINKER_SCRIPT
typedef enum
{
    IFX_STDIO_CORE_S33,  /* CM33 secure */
    IFX_STDIO_CORE_N33,  /* CM33 non-secure */
    IFX_STDIO_CORE_N55,  /* CM55 non-secure */
    IFX_STDIO_CORE_MAX_COUNT
} ifx_stdio_core_id_t;
#endif /* IFX_LINKER_SCRIPT */

#if DOMAIN_S && (IFX_CORE == IFX_CM33)
#define IFX_STDIO_CORE_ID   IFX_STDIO_CORE_S33
#elif DOMAIN_NS && (IFX_CORE == IFX_CM33)
#define IFX_STDIO_CORE_ID   IFX_STDIO_CORE_N33
#elif DOMAIN_NS && (IFX_CORE == IFX_CM55)
#define IFX_STDIO_CORE_ID   IFX_STDIO_CORE_N55
#endif

#define IFX_STDIO_CORE_S_ID IFX_STDIO_CORE_S33

#if IFX_PRINT_CORE_PREFIX

#ifndef IFX_STDIO_S_CM33_PREFIX
#define IFX_STDIO_S_CM33_PREFIX                 "$S33$"
#endif

#ifndef IFX_STDIO_NS_CM33_PREFIX
#define IFX_STDIO_NS_CM33_PREFIX                "$N33$"
#endif

#ifndef IFX_STDIO_NS_CM55_PREFIX
#define IFX_STDIO_NS_CM55_PREFIX                "$N55$"
#endif

#define IFX_STDIO_CORE_STR(core_id) \
        (((core_id) == IFX_STDIO_CORE_S33) ? IFX_STDIO_S_CM33_PREFIX : \
         ((core_id) == IFX_STDIO_CORE_N33) ? IFX_STDIO_NS_CM33_PREFIX : \
         ((core_id) == IFX_STDIO_CORE_N55) ? IFX_STDIO_NS_CM55_PREFIX : \
         "$?$")

#endif /* IFX_PRINT_CORE_PREFIX */

#endif /* IFX_STDIO_CORE_H */
