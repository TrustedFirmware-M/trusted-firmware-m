/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __COMPILER_EXT_DEFS_H__
#define __COMPILER_EXT_DEFS_H__

#ifndef __naked
#define __naked __attribute__((naked))
#endif

#ifndef __section
#define __section(x) __attribute__((section(x)))
#endif

#ifndef __aligned
#define __aligned(x) __attribute__((aligned(x)))
#endif

#ifndef __used
#define __used __attribute__((used))
#endif

#ifndef __deprecated
#define __deprecated __attribute__((deprecated("may be removed in future releases")))
#endif

#if !defined(__ICCARM__)
#define SYNTAX_UNIFIED    ".syntax unified \n"
#else
#define SYNTAX_UNIFIED
#endif /* SYNTAX_UNIFIED */

#endif /* __COMPILER_EXT_DEFS_H__ */
