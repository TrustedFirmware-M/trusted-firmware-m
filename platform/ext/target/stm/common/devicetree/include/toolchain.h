/*
 * Copyright (c) 2010-2014, Wind River Systems, Inc.
 * Copyright (c) 2026, STMicroelectronics.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * fork from zephyr
 */

/**
 * @file
 * @brief Macros to abstract toolchain specific capabilities
 *
 * This file contains various macros to abstract compiler capabilities that
 * utilize toolchain specific attributes and/or pragmas.
 */

#ifndef INCLUDE_TOOLCHAIN_H_
#define INCLUDE_TOOLCHAIN_H_

#if defined(__GNUC__) || (defined(_LINKER) && defined(__GCC_LINKER_CMD__))
#include <toolchain/gcc.h>
#else
#error "Invalid/unknown toolchain configuration"
#endif

/**
 * @def __noasan
 * @brief Disable address sanitizer
 *
 * When used in the definiton of a symbol, prevents that symbol (be it
 * a function or data) from being instrumented by the address
 * sanitizer feature of the compiler.  Most commonly, this is used to
 * prevent padding around data that will be treated specially by the
 * link (c.f. SYS_INIT records, STRUCT_SECTION_ITERABLE
 * definitions) in ways that don't understand the guard padding.
 */
#ifndef __noasan
#define __noasan /**/
#endif

#endif /* INCLUDE_TOOLCHAIN_H_ */
