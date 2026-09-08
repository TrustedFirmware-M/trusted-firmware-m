/*
 * Copyright (c) 2015 Intel Corporation.
 * Copyright (c) 2026 STMicroelectronics.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * fork from zephyr
 */

#ifndef INCLUDE_INIT_H_
#define INCLUDE_INIT_H_

#include <stdint.h>
#include <stddef.h>

#include <util_macro.h>
#include <toolchain.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @defgroup sys_init System Initialization
 * @ingroup os_services
 *
 * Init offers an infrastructure to call initialization code before `main`.
 * Such initialization calls can be registered using SYS_INIT() or
 * SYS_INIT_NAMED() macros. By using a combination of initialization levels and
 * priorities init sequence can be adjusted as needed. The available
 * initialization levels are described, in order, below:
 *
 * - `EARLY`: Used very early in the boot process, right after entering the C
 *   domain (``z_cstart()``). This can be used in architectures and SoCs that
 *   extend or implement architecture code and use drivers or system services
 *   that have to be initialized before the Kernel calls any architecture
 *   specific initialization code.
 * - `PRE_KERNEL_1`: Executed in Kernel's initialization context, which uses
 *   the interrupt stack. At this point Kernel services are not yet available.
 * - `PRE_KERNEL_2`: Same as `PRE_KERNEL_1`.
 * - `POST_KERNEL`: Executed after Kernel is alive. From this point on, Kernel
 *   primitives can be used.
 * - `APPLICATION`: Executed just before application code (`main`).
 * - `SMP`: Only available if @kconfig{CONFIG_SMP} is enabled, specific for
 *   SMP.
 *
 * Initialization priority can take a value in the range of 0 to 99.
 *
 * @note The same infrastructure is used by devices.
 * @{
 */

struct device;

/**
 * @brief Initialization function for init entries.
 *
 * Init entries support both the system initialization and the device
 * APIs. Each API has its own init function signature; hence, we have a
 * union to cover both.
 */
union init_function {
	/**
	 * System initialization function.
	 *
	 * @retval 0 On success
	 * @retval -errno If init fails.
	 */
	int (*sys)(void);
	/**
	 * Device initialization function.
	 *
	 * @param dev Device instance.
	 *
	 * @retval 0 On success
	 * @retval -errno If device initialization fails.
	 */
	int (*dev)(const struct device *dev);
};

/**
 * @brief Structure to store initialization entry information.
 *
 * @internal
 * Init entries need to be defined following these rules:
 *
 * - Their name must be set using INIT_ENTRY_NAME().
 * - They must be placed in a special init section, given by
 *   INIT_ENTRY_SECTION().
 * - They must be aligned, e.g. using DECL_ALIGN().
 *
 * See SYS_INIT_NAMED() for an example.
 * @endinternal
 */
struct init_entry {
	/** Initialization function. */
	union init_function init_fn;
	/**
	 * If the init entry belongs to a device, this fields stores a
	 * reference to it, otherwise it is set to NULL.
	 */
	const struct device *dev;
};

/** @cond INTERNAL_HIDDEN */

/* Helper definitions to evaluate level equality */
#define INIT_EARLY_EARLY		1
#define INIT_ARCH_ARCH			1
#define INIT_PRE_CORE_PRE_CORE		1
#define INIT_CORE_CORE			1
#define INIT_POST_CORE_POST_CORE	1
#define INIT_REST_REST			1

/* Init level */
#define INIT_ORD_EARLY			0
#define INIT_ORD_ARCH			1
#define INIT_ORD_PRE_CORE		2
#define INIT_ORD_CORE			3
#define INIT_ORD_POST_CORE		4
#define INIT_ORD_REST			5

/**
 * @brief Obtain init entry name.
 *
 * @param init_id Init entry unique identifier.
 */
#define INIT_ENTRY_NAME(init_id) _CONCAT(__init_, init_id)

/**
 * @brief Init entry section.
 *
 * Each init entry is placed in a section with a name crafted so that it allows
 * linker scripts to sort them according to the specified level/priority.
 */
#define INIT_ENTRY_SECTION(level, prio)                                      \
	__attribute__((__section__("._init_" #level STRINGIFY(prio)"_")))

/** @endcond */

/**
 * @brief Obtain the ordinal for an init level.
 *
 * @param level Init level (EARLY, PRE_KERNEL_1, PRE_KERNEL_2, POST_KERNEL,
 * APPLICATION, SMP).
 *
 * @return Init level ordinal.
 */
#define INIT_LEVEL_ORD(level)                                              \
	COND_CODE_1(INIT_EARLY_##level, (INIT_ORD_EARLY),                  \
	(COND_CODE_1(INIT_ARCH_##level, (INIT_ORD_ARCH),                   \
	(COND_CODE_1(INIT_PRE_CORE_##level, (INIT_ORD_PRE_CORE),           \
	(COND_CODE_1(INIT_CORE_##level, (INIT_ORD_CORE),                   \
	(COND_CODE_1(INIT_POST_CORE_##level, (INIT_ORD_POST_CORE),         \
	(COND_CODE_1(INIT_REST_##level, (INIT_ORD_REST),                   \
	(ZERO_OR_COMPILE_ERROR(0)))))))))))))

/**
 * @brief Register an initialization function.
 *
 * The function will be called during system initialization according to the
 * given level and priority.
 *
 * @param init_fn Initialization function.
 * @param level Initialization level. Allowed tokens: `EARLY`, `PRE_KERNEL_1`,
 * `PRE_KERNEL_2`, `POST_KERNEL`, `APPLICATION` and `SMP` if
 * @kconfig{CONFIG_SMP} is enabled.
 * @param prio Initialization priority within @p _level. Note that it must be a
 * decimal integer literal without leading zeroes or sign (e.g. `32`), or an
 * equivalent symbolic name (e.g. `#define MY_INIT_PRIO 32`); symbolic
 * expressions are **not** permitted (e.g.
 * `CONFIG_KERNEL_INIT_PRIORITY_DEFAULT + 5`).
 */
#define SYS_INIT(init_fn, level, prio)                                         \
	SYS_INIT_NAMED(init_fn, init_fn, level, prio)

/**
 * @brief Register an initialization function (named).
 *
 * @note This macro can be used for cases where the multiple init calls use the
 * same init function.
 *
 * @param name Unique name for SYS_INIT entry.
 * @param init_fn_ See SYS_INIT().
 * @param level See SYS_INIT().
 * @param prio See SYS_INIT().
 *
 * @see SYS_INIT()
 */
#define SYS_INIT_NAMED(name, init_fn_, level, prio)                            \
	static const DECL_ALIGN(struct init_entry)                           \
		INIT_ENTRY_SECTION(level, prio) __used __noasan              \
		INIT_ENTRY_NAME(name) = {                                    \
			.init_fn = {.sys = (init_fn_)},                        \
			.dev = NULL,                                           \
	}

/** @} */

enum init_level {
	INIT_LEVEL_EARLY = 0,
	INIT_LEVEL_ARCH,
	INIT_LEVEL_PRE_CORE,
	INIT_LEVEL_CORE,
	INIT_LEVEL_POST_CORE,
	INIT_LEVEL_REST,
};

/**
 * @brief Execute all the init entry initialization functions at a given level
 *
 * @details Invokes the initialization routine for each init entry object
 * created by the INIT_ENTRY_DEFINE() macro using the specified level.
 * The linker script places the init entry objects in memory in the order
 * they need to be invoked, with symbols indicating where one level leaves
 * off and the next one begins.
 *
 * @param level init level to run.
 */
void sys_init_run_level(enum init_level level);

/**
 * @brief Verify that a device is ready for use.
 *
 * @param dev pointer to the device in question.
 *
 * @retval true If the device is ready for use.
 * @retval false If the device is not ready for use or if a NULL device pointer
 * is passed as argument.
 */
bool device_is_ready(const struct device *dev);

#ifdef __cplusplus
}
#endif

#endif /* INCLUDE_INIT_H_ */
