/*
 * Copyright (C) 2020, Intel Corporation
 * Copyright (C) 2023, Nordic Semiconductor ASA
 * Copyright (c) 2010-2014,2017 Wind River Systems, Inc.
 * Copyright (c) 2026, STMicroelectronics
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * fork from zephyr
*/

#ifndef INCLUDE_TOOLCHAIN_GCC_H_
#define INCLUDE_TOOLCHAIN_GCC_H_

/**
 * @file
 * @brief GCC toolchain abstraction
 *
 * Macros to abstract compiler capabilities for GCC toolchain.
 */
#include <toolchain/common.h>
#include <stdbool.h>

#ifndef __packed
#define __packed        __attribute__((__packed__))
#endif

#ifndef __aligned
#define __aligned(x)	__attribute__((__aligned__(x)))
#endif

#ifndef __used
#define __used		__attribute__((__used__))
#endif

#ifndef __maybe_unused
#define __maybe_unused	__attribute__((__unused__))
#endif

#ifndef __unused
#define __unused	__attribute__((__unused__))
#endif

#ifndef __weak
#define __weak		__attribute__((weak))
#endif
/**
 * @brief Defines a new element for an iterable section for a generic type.
 *
 * @details
 * Convenience helper combining __in_section() and Z_DECL_ALIGN().
 * The section name will be '.[SECNAME].static.[SECTION_POSTFIX]'
 *
 * In the linker script, create output sections for these using
 * ITERABLE_SECTION_ROM() or ITERABLE_SECTION_RAM().
 *
 * @note In order to store the element in ROM, a const specifier has to
 * be added to the declaration: const TYPE_SECTION_ITERABLE(...);
 *
 * @param[in]  type data type of variable
 * @param[in]  varname name of variable to place in section
 * @param[in]  secname type name of iterable section.
 * @param[in]  section_postfix postfix to use in section name
 */
#define TYPE_SECTION_ITERABLE(type, varname, secname, section_postfix) \
	DECL_ALIGN(type) varname \
	__in_section(_##secname, static, _CONCAT(section_postfix, _)) __used __noasan

/**
 * @brief Defines a new element for an iterable section with a custom name.
 *
 * The name can be used to customize how iterable section entries are sorted.
 * @see STRUCT_SECTION_ITERABLE()
 */
#define STRUCT_SECTION_ITERABLE_NAMED(struct_type, name, varname) \
	TYPE_SECTION_ITERABLE(struct struct_type, varname, struct_type, name)

#define ___in_section(a, b, c) \
	__attribute__((section("." STRINGIFY(a)			\
				"." STRINGIFY(b)			\
				"." STRINGIFY(c))))
#define __in_section(a, b, c) ___in_section(a, b, c)

#endif /* INCLUDE_TOOLCHAIN_GCC_H_ */
