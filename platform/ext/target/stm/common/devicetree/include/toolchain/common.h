/*
 * Copyright (c) 2010-2014 Wind River Systems, Inc.
 * Copyright (c) 2026, STMicroelectronics.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * fork from zephyr
 */

#ifndef INCLUDE_TOOLCHAIN_COMMON_H_
#define INCLUDE_TOOLCHAIN_COMMON_H_
/**
 * @file
 * @brief Common toolchain abstraction
 *
 * Macros to abstract compiler capabilities (common to all toolchains).
 */

#define _STRINGIFY(x) #x
#define STRINGIFY(s) _STRINGIFY(s)

/* concatenate the values of the arguments into one */
#define _DO_CONCAT(x, y) x ## y
#define _CONCAT(x, y) _DO_CONCAT(x, y)

#ifndef BUILD_ASSERT
/* Compile-time assertion that makes the build to fail.
 * Common implementation swallows the message.
 */
#define BUILD_ASSERT(EXPR, MSG...) \
	enum _CONCAT(__build_assert_enum, __COUNTER__) { \
		_CONCAT(__build_assert, __COUNTER__) = 1 / !!(EXPR) \
	}
#endif

/*
 * This is meant to be used in conjunction with __in_section() and similar
 * where scattered structure instances are concatenated together by the linker
 * and walked by the code at run time just like a contiguous array of such
 * structures.
 *
 * Assemblers and linkers may insert alignment padding by default whose
 * size is larger than the natural alignment for those structures when
 * gathering various section segments together, messing up the array walk.
 * To prevent this, we need to provide an explicit alignment not to rely
 * on the default that might just work by luck.
 *
 * Alignment statements in  linker scripts are not sufficient as
 * the assembler may add padding by itself to each segment when switching
 * between sections within the same file even if it merges many such segments
 * into a single section in the end.
 */
#define DECL_ALIGN(type) __aligned(__alignof__(type)) type

/* Check if a pointer is aligned for against a specific byte boundary  */
#define IS_PTR_ALIGNED_BYTES(ptr, bytes) ((((uintptr_t)ptr) % bytes) == 0)

/* Check if a pointer is aligned enough for a particular data type. */
#define IS_PTR_ALIGNED(ptr, type) IS_PTR_ALIGNED_BYTES(ptr, __alignof__(type))

/** @brief Tag a symbol (e.g. function) to be kept in the binary even though it is not used.
 *
 * It prevents symbol from being removed by the linker garbage collector. It
 * is achieved by adding a pointer to that symbol to the kept memory section.
 *
 * @param symbol Symbol to keep.
 */
#define LINKER_KEEP(symbol) \
	static const void * const symbol##_ptr  __used \
	__attribute__((__section__(".symbol_to_keep"))) = (void *)&symbol

#endif /* INCLUDE_TOOLCHAIN_COMMON_H_ */
