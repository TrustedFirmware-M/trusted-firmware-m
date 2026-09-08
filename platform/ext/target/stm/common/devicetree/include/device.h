/*
 * Copyright (c) 2015 Intel Corporation.
 * Copyright (c) 2026 STMicroelectronics.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * fork of zephyr
 */
#ifndef INCLUDE_DEVICE_H_
#define INCLUDE_DEVICE_H_

#include <stdint.h>

#include <devicetree.h>
#include <init.h>
#include <util_macro.h>
#include <toolchain.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Device Model
 * @defgroup device_model Device Model
 * @{
 */

/**
 * @brief Type used to represent a "handle" for a device.
 *
 * Every @ref device has an associated handle. You can get a pointer to a
 * @ref device from its handle and vice versa, but the handle uses less space
 * than a pointer. The device.h API mainly uses handles to store lists of
 * multiple devices in a compact way.
 *
 * The extreme values and zero have special significance. Negative values
 * identify functionality that does not correspond to a Zephyr device, such as
 * the system clock or a SYS_INIT() function.
 *
 * @see device_handle_get()
 * @see device_from_handle()
 */
typedef int16_t device_handle_t;

/**
 * @brief Flag value used in lists of device handles to separate distinct
 * groups.
 *
 * This is the minimum value for the device_handle_t type.
 */
#define DEVICE_HANDLE_SEP INT16_MIN

/**
 * @brief Flag value used in lists of device handles to indicate the end of the
 * list.
 *
 * This is the maximum value for the device_handle_t type.
 */
#define DEVICE_HANDLE_ENDS INT16_MAX

/** @brief Flag value used to identify an unknown device. */
#define DEVICE_HANDLE_NULL 0

/**
 * @brief Expands to the name of a global device object.
 *
 * Return the full name of a device object symbol created by DEVICE_DEFINE(),
 * using the `dev_id` provided to DEVICE_DEFINE(). This is the name of the
 * global variable storing the device structure, not a pointer to the string in
 * the @ref device.name field.
 *
 * It is meant to be used for declaring extern symbols pointing to device
 * objects before using the DEVICE_GET macro to get the device object.
 *
 * This macro is normally only useful within device driver source code. In other
 * situations, you are probably looking for device_get_binding().
 *
 * @param dev_id Device identifier.
 *
 * @return The full name of the device object defined by device definition
 * macros.
 */
#define DEVICE_NAME_GET(dev_id) _CONCAT(__device_, dev_id)

/* Node paths can exceed the maximum size supported by
 * device_get_binding() in user mode; this macro synthesizes a unique
 * dev_id from a devicetree node while staying within this maximum
 * size.
 *
 * The ordinal used in this name can be mapped to the path by
 * examining zephyr/include/generated/devicetree_generated.h.
 */
#define DEVICE_DT_DEV_ID(node_id) _CONCAT(dts_ord_, DT_DEP_ORD(node_id))

/**
 * @brief Create a device object and set it up for boot time initialization.
 *
 * This macro defines a @ref device that is automatically configured by the
 * kernel during system initialization. This macro should only be used when the
 * device is not being allocated from a devicetree node. If you are allocating a
 * device from a devicetree node, use DEVICE_DT_DEFINE() or
 * DEVICE_DT_INST_DEFINE() instead.
 *
 * @param dev_id A unique token which is used in the name of the global device
 * structure as a C identifier.
 * @param name A string name for the device, which will be stored in
 * @ref device.name. This name can be used to look up the device with
 * device_get_binding(). This must be less than DEVICE_MAX_NAME_LEN characters
 * (including terminating `NULL`) in order to be looked up from user mode.
 * @param init_fn Pointer to the device's initialization function, which will be
 * run by the kernel during system initialization. Can be `NULL`.
 * @param pm Reference to @ref pm_device_base associated with the device. (optional)
 * @param data Pointer to the device's private mutable data, which will be
 * stored in @ref device.data.
 * @param config Pointer to the device's private constant data, which will be
 * stored in @ref device.config.
 * @param level The device's initialization level. See @ref sys_init for
 * details.
 * @param prio The device's priority within its initialization level. See
 * SYS_INIT() for details.
 * @param api Pointer to the device's API structure. Can be `NULL`.
 */
#define DEVICE_DEFINE(dev_id, name, init_fn, pm, data, config, level, prio, api)\
	DEVICE_STATE_DEFINE(dev_id);						\
	__DEVICE_DEFINE(DT_INVALID_NODE, dev_id, name, init_fn, data,		\
			config, level, prio, api, pm,				\
			&DEVICE_STATE_NAME(dev_id))

/**
 * @brief Return a string name for a devicetree node.
 *
 * This macro returns a string literal usable as a device's name from a
 * devicetree node identifier.
 *
 * @param node_id The devicetree node identifier.
 *
 * @return The value of the node's `label` property, if it has one.
 * Otherwise, the node's full name in `node-name@unit-address` form.
 */
#define DEVICE_DT_NAME(node_id)                                                \
	DT_PROP_OR(node_id, label, DT_NODE_FULL_NAME(node_id))

/**
 * @brief Create a device object from a devicetree node identifier and set it up
 * for boot time initialization.
 *
 * This macro defines a @ref device that is automatically configured by the
 * kernel during system initialization. The global device object's name as a C
 * identifier is derived from the node's dependency ordinal. @ref device.name is
 * set to `DEVICE_DT_NAME(node_id)`.
 *
 * The device is declared with extern visibility, so a pointer to a global
 * device object can be obtained with `DEVICE_DT_GET(node_id)` from any source
 * file that includes `<zephyr/device.h>`. Before using the pointer, the
 * referenced object should be checked using device_is_ready().
 *
 * @param node_id The devicetree node identifier.
 * @param init_fn Pointer to the device's initialization function, which will be
 * run by the kernel during system initialization. Can be `NULL`.
 * @param pm Reference to @ref pm_device_base associated with the device. (optional)
 * @param data Pointer to the device's private mutable data, which will be
 * stored in @ref device.data.
 * @param config Pointer to the device's private constant data, which will be
 * stored in @ref device.config field.
 * @param level The device's initialization level. See SYS_INIT() for details.
 * @param prio The device's priority within its initialization level. See
 * SYS_INIT() for details.
 * @param api Pointer to the device's API structure. Can be `NULL`.
 */
#define DEVICE_DT_DEFINE(node_id, init_fn, pm, data, config, level,		\
			 prio, api, ...)					\
	DEVICE_STATE_DEFINE(DEVICE_DT_DEV_ID(node_id));				\
	__DEVICE_DEFINE(node_id, DEVICE_DT_DEV_ID(node_id),			\
			DEVICE_DT_NAME(node_id), init_fn, data, config,		\
			level, prio, api, pm,					\
			&DEVICE_STATE_NAME(DEVICE_DT_DEV_ID(node_id)),		\
			__VA_ARGS__)

/**
 * @brief Like DEVICE_DT_DEFINE(), but uses an instance of a `DT_DRV_COMPAT`
 * compatible instead of a node identifier.
 *
 * @param inst Instance number. The `node_id` argument to DEVICE_DT_DEFINE() is
 * set to `DT_DRV_INST(inst)`.
 * @param ... Other parameters as expected by DEVICE_DT_DEFINE().
 */
#define DEVICE_DT_INST_DEFINE(inst, ...)                                       \
	DEVICE_DT_DEFINE(DT_DRV_INST(inst), __VA_ARGS__)

/**
 * @brief The name of the global device object for @p node_id
 *
 * Returns the name of the global device structure as a C identifier. The device
 * must be allocated using DEVICE_DT_DEFINE() or DEVICE_DT_INST_DEFINE() for
 * this to work.
 *
 * This macro is normally only useful within device driver source code. In other
 * situations, you are probably looking for DEVICE_DT_GET().
 *
 * @param node_id Devicetree node identifier
 *
 * @return The name of the device object as a C identifier
 */
#define DEVICE_DT_NAME_GET(node_id) DEVICE_NAME_GET(DEVICE_DT_DEV_ID(node_id))

/**
 * @brief Get a @ref device reference from a devicetree node identifier.
 *
 * Returns a pointer to a device object created from a devicetree node, if any
 * device was allocated by a driver.
 *
 * If no such device was allocated, this will fail at linker time. If you get an
 * error that looks like `undefined reference to __device_dts_ord_<N>`, that is
 * what happened. Check to make sure your device driver is being compiled,
 * usually by enabling the Kconfig options it requires.
 *
 * @param node_id A devicetree node identifier
 *
 * @return A pointer to the device object created for that node
 */
#define DEVICE_DT_GET(node_id) (&DEVICE_DT_NAME_GET(node_id))

/**
 * @brief Get a @ref device reference for an instance of a `DT_DRV_COMPAT`
 * compatible.
 *
 * This is equivalent to `DEVICE_DT_GET(DT_DRV_INST(inst))`.
 *
 * @param inst `DT_DRV_COMPAT` instance number
 * @return A pointer to the device object created for that instance
 */
#define DEVICE_DT_INST_GET(inst) DEVICE_DT_GET(DT_DRV_INST(inst))

/**
 * @brief Get a @ref device reference from a devicetree compatible.
 *
 * If an enabled devicetree node has the given compatible and a device
 * object was created from it, this returns a pointer to that device.
 *
 * If there no such devices, this returns NULL.
 *
 * If there are multiple, this returns an arbitrary one.
 *
 * If this returns non-NULL, the device must be checked for readiness
 * before use, e.g. with device_is_ready().
 *
 * @param compat lowercase-and-underscores devicetree compatible
 * @return a pointer to a device, or NULL
 */
#define DEVICE_DT_GET_ANY(compat)                                              \
	COND_CODE_1(DT_HAS_COMPAT_STATUS_OKAY(compat),                         \
		    (DEVICE_DT_GET(DT_COMPAT_GET_ANY_STATUS_OKAY(compat))),    \
		    (NULL))

/**
 * @brief Get a @ref device reference from a devicetree compatible.
 *
 * If an enabled devicetree node has the given compatible and a device object
 * was created from it, this returns a pointer to that device.
 *
 * If there are no such devices, this will fail at compile time.
 *
 * If there are multiple, this returns an arbitrary one.
 *
 * If this returns non-NULL, the device must be checked for readiness before
 * use, e.g. with device_is_ready().
 *
 * @param compat lowercase-and-underscores devicetree compatible
 * @return a pointer to a device
 */
#define DEVICE_DT_GET_ONE(compat)                                              \
	COND_CODE_1(DT_HAS_COMPAT_STATUS_OKAY(compat),                         \
		    (DEVICE_DT_GET(DT_COMPAT_GET_ANY_STATUS_OKAY(compat))),    \
		    (ZERO_OR_COMPILE_ERROR(0)))

/**
 * @brief Utility macro to obtain an optional reference to a device.
 *
 * If the node identifier refers to a node with status `okay`, this returns
 * `DEVICE_DT_GET(node_id)`. Otherwise, it returns `NULL`.
 *
 * @param node_id devicetree node identifier
 *
 * @return a @ref device reference for the node identifier, which may be `NULL`.
 */
#define DEVICE_DT_GET_OR_NULL(node_id)                                         \
	COND_CODE_1(DT_NODE_HAS_STATUS(node_id, okay),                         \
		    (DEVICE_DT_GET(node_id)), (NULL))

/**
 * @brief Obtain a pointer to a device object by name
 *
 * @details Return the address of a device object created by
 * DEVICE_DEFINE(), using the dev_id provided to DEVICE_DEFINE().
 *
 * @param dev_id Device identifier.
 *
 * @return A pointer to the device object created by DEVICE_DEFINE()
 */
#define DEVICE_GET(dev_id) (&DEVICE_NAME_GET(dev_id))

/**
 * @brief Declare a static device object
 *
 * This macro can be used at the top-level to declare a device, such
 * that DEVICE_GET() may be used before the full declaration in
 * DEVICE_DEFINE().
 *
 * This is often useful when configuring interrupts statically in a
 * device's init or per-instance config function, as the init function
 * itself is required by DEVICE_DEFINE() and use of DEVICE_GET()
 * inside it creates a circular dependency.
 *
 * @param dev_id Device identifier.
 */
#define DEVICE_DECLARE(dev_id)                                                 \
	static const struct device DEVICE_NAME_GET(dev_id)

/**
 * @brief Get a @ref init_entry reference from a devicetree node.
 *
 * @param node_id A devicetree node identifier
 *
 * @return A pointer to the @ref init_entry object created for that node
 */
#define DEVICE_INIT_DT_GET(node_id)                                            \
	(&INIT_ENTRY_NAME(DEVICE_DT_NAME_GET(node_id)))

/**
 * @brief Get a @ref init_entry reference from a device identifier.
 *
 * @param dev_id Device identifier.
 *
 * @return A pointer to the init_entry object created for that device
 */
#define DEVICE_INIT_GET(dev_id) (&INIT_ENTRY_NAME(DEVICE_NAME_GET(dev_id)))

/**
 * @brief Runtime device dynamic structure (in RAM) per driver instance
 *
 * Fields in this are expected to be default-initialized to zero. The
 * kernel driver infrastructure and driver access functions are
 * responsible for ensuring that any non-zero initialization is done
 * before they are accessed.
 */
struct device_state {
	/**
	 * Device initialization return code (positive errno value).
	 *
	 * Device initialization functions return a negative errno code if they
	 * fail.
	 */
	int init_res;

	/** Indicates the device initialization function has been
	 * invoked.
	 */
	bool initialized : 1;
};

/**
 * @brief Runtime device structure (in ROM) per driver instance
 */
struct device {
	/** Name of the device instance */
	const char *name;
	/** Address of device instance config information */
	const void *config;
	/** Address of the API structure exposed by the device instance */
	const void *api;
	/** Address of the common device state */
	struct device_state *state;
	/** Address of the device instance private data */
	void *data;
	/** Reference to the device PM */
#if defined(CONFIG_PM_DEVICE)
	struct pm_device *pm;
#endif
	/**
	 * Optional pointer to handles associated with the device.
	 *
	 * This encodes a sequence of sets of device handles that have some
	 * relationship to this node. The individual sets are extracted with
	 * dedicated API, such as device_required_handles_get().
	 */
	const device_handle_t *handles;
};

static inline void *dev_get_data(const struct device *dev)
{
	return dev->data;
}

static inline const void *dev_get_config(const struct device *dev)
{
	return dev->config;
}

/**
 * @brief Get access to array of static devices.
 *
 * @param devices where to store the pointer to the array of statically
 * allocated devices. The array must not be mutated through this pointer.
 *
 * @return the number of statically allocated devices.
 */
size_t device_get_all(const struct device **devices);

/**
 * @brief Verify that a device is ready for use.
 *
 * This is the implementation underlying device_is_ready(), without the overhead
 * of a syscall wrapper.
 *
 * @param dev pointer to the device in question.
 *
 * @retval true If the device is ready for use.
 * @retval false If the device is not ready for use or if a NULL device pointer
 * is passed as argument.
 *
 * @see device_is_ready()
 */
bool device_is_ready(const struct device *dev);

/**
 * @}
 */

/** @cond INTERNAL_HIDDEN */

/**
 * @brief Synthesize a unique name for the device state associated with
 * @p dev_id.
 */
#define DEVICE_STATE_NAME(dev_id) _CONCAT(__devstate_, dev_id)

/**
 * @brief Utility macro to define and initialize the device state.
 *
 * @param dev_id Device identifier.
 */
#define DEVICE_STATE_DEFINE(dev_id)                                          \
	static DECL_ALIGN(struct device_state) DEVICE_STATE_NAME(dev_id)   \
		__attribute__((__section__(".devstate")))

/**
 * @brief Synthesize the name of the object that holds device ordinal and
 * dependency data.
 *
 * @param dev_id Device identifier.
 */
#define DEVICE_HANDLES_NAME(dev_id) _CONCAT(__devicehdl_, dev_id)

/**
 * @brief Expand extra handles with a comma in between.
 *
 * @param ... Extra handles
 */
#define DEVICE_EXTRA_HANDLES(...)                                            \
	FOR_EACH_NONEMPTY_TERM(IDENTITY, (,), __VA_ARGS__)

/** @brief Linker section were device handles are placed. */
#define DEVICE_HANDLES_SECTION                                               \
	__attribute__((__section__(".__device_handles_pass1")))

#ifdef __cplusplus
#define DEVICE_HANDLES_EXTERN extern
#else
#define DEVICE_HANDLES_EXTERN
#endif

/**
 * @brief Define device handles.
 *
 * Initial build provides a record that associates the device object with its
 * devicetree ordinal, and provides the dependency ordinals. These are provided
 * as weak definitions (to prevent the reference from being captured when the
 * original object file is compiled), and in a distinct pass1 section (which
 * will be replaced by postprocessing).
 *
 * Before processing in gen_handles.py, the array format is:
 * {
 *     DEVICE_ORDINAL (or DEVICE_HANDLE_NULL if not a devicetree node),
 *     List of devicetree dependency ordinals (if any),
 *     DEVICE_HANDLE_SEP,
 *     List of injected dependency ordinals (if any),
 *     DEVICE_HANDLE_SEP,
 *     List of devicetree supporting ordinals (if any),
 * }
 *
 * After processing in gen_handles.py, the format is updated to:
 * {
 *     List of existing devicetree dependency handles (if any),
 *     DEVICE_HANDLE_SEP,
 *     List of injected devicetree dependency handles (if any),
 *     DEVICE_HANDLE_SEP,
 *     List of existing devicetree support handles (if any),
 *     DEVICE_HANDLE_NULL
 * }
 *
 * It is also (experimentally) necessary to provide explicit alignment on each
 * object. Otherwise x86-64 builds will introduce padding between objects in the
 * same input section in individual object files, which will be retained in
 * subsequent links both wasting space and resulting in aggregate size changes
 * relative to pass2 when all objects will be in the same input section.
 */
#define DEVICE_HANDLES_DEFINE(node_id, dev_id, ...)                          \
	extern const device_handle_t DEVICE_HANDLES_NAME(   \
		dev_id)[];                                                     \
	const DECL_ALIGN(device_handle_t)                   \
	DEVICE_HANDLES_SECTION DEVICE_HANDLES_EXTERN __weak                \
		DEVICE_HANDLES_NAME(dev_id)[] = {                            \
		COND_CODE_1(                                                   \
			DT_NODE_EXISTS(node_id),                               \
			(DT_DEP_ORD(node_id), DT_REQUIRES_DEP_ORDS(node_id)),  \
			(DEVICE_HANDLE_NULL,)) /**/                            \
		DEVICE_HANDLE_SEP,                                             \
		DEVICE_EXTRA_HANDLES(__VA_ARGS__) /**/                       \
		DEVICE_HANDLE_SEP,                                             \
		COND_CODE_1(DT_NODE_EXISTS(node_id),                           \
			    (DT_SUPPORTS_DEP_ORDS(node_id)), ()) /**/          \
	}

/**
 * @brief Maximum device name length.
 *
 * The maximum length is set so that device_get_binding() can be used from
 * userspace.
 */
#define DEVICE_MAX_NAME_LEN 32

/**
 * @brief Compile time check for device name length
 *
 * @param name Device name.
 */
#define DEVICE_NAME_CHECK(name)							\
	BUILD_ASSERT(sizeof(STRINGIFY(name)) <= DEVICE_MAX_NAME_LEN,		\
			    STRINGIFY(name) " too long")


#define DEVICE_INIT_PM(pm_) (.pm = (pm_),)

/**
 * @brief Initializer for @ref device.
 *
 * @param name_ Name of the device.
 * @param data_ Reference to device data.
 * @param config_ Reference to device config.
 * @param api_ Reference to device API ops.
 * @param state_ Reference to device state.
 * @param handles_ Reference to device handles.
 */
#define DEVICE_INIT(name_, data_, config_, api_, pm_, state_, handles_, ...)	\
	{									\
		.name = name_,							\
		.config = (config_),						\
		.api = (api_),							\
		.state = (state_),						\
		.data = (data_),						\
		.handles = (handles_),						\
		IF_ENABLED(CONFIG_PM_DEVICE, DEVICE_INIT_PM(pm_))		\
	}

/**
 * @brief Device section name (used for sorting purposes).
 *
 * @param level Initialization level
 * @param prio Initialization priority
 */
#define DEVICE_SECTION_NAME(level, prio)					\
	_CONCAT(INIT_LEVEL_ORD(level), _##prio)

/**
 * @brief Define a @ref device
 *
 * @param node_id Devicetree node id for the device (DT_INVALID_NODE if a
 * software device).
 * @param dev_id Device identifier (used to name the defined @ref device).
 * @param name Name of the device.
 * @param data Reference to device data.
 * @param config Reference to device config.
 * @param level Initialization level.
 * @param prio Initialization priority.
 * @param api Reference to device API.
 * @param ... Optional dependencies, manually specified.
 */
#define DEVICE_BASE_DEFINE(node_id, dev_id, name, data, config, level,		\
			     prio, api, pm, state, handles)			\
	COND_CODE_1(DT_NODE_EXISTS(node_id), (), (static))			\
	const STRUCT_SECTION_ITERABLE_NAMED(device,				\
		DEVICE_SECTION_NAME(level, prio),				\
		DEVICE_NAME_GET(dev_id)) =					\
		DEVICE_INIT(name, data, config, api, pm, state, handles)

/**
 * @brief Define the init entry for a device.
 *
 * @param dev_id Device identifier.
 * @param init_fn_ Device init function.
 * @param level Initialization level.
 * @param prio Initialization priority.
 */
#define DEVICE_INIT_ENTRY_DEFINE(dev_id, init_fn_, level, prio)              \
	static const DECL_ALIGN(struct init_entry)                           \
		INIT_ENTRY_SECTION(level, prio) __used __noasan              \
		INIT_ENTRY_NAME(DEVICE_NAME_GET(dev_id)) = {                 \
			.init_fn = {.dev = (init_fn_)},                        \
			.dev = &DEVICE_NAME_GET(dev_id),                       \
	}

/**
 * @brief Define a @ref device and all other required objects.
 *
 * This is the common macro used to define @ref device objects. It can be used
 * to define both Devicetree and software devices.
 *
 * @param node_id Devicetree node id for the device (DT_INVALID_NODE if a
 * software device).
 * @param dev_id Device identifier (used to name the defined @ref device).
 * @param name Name of the device.
 * @param init_fn Device init function.
 * @param data Reference to device data.
 * @param config Reference to device config.
 * @param level Initialization level.
 * @param prio Initialization priority.
 * @param api Reference to device API.
 * @param state Reference to device state.
 * @param ... Optional dependencies, manually specified.
 */
#define __DEVICE_DEFINE(node_id, dev_id, name, init_fn, data, config,		\
			level, prio, api, pm, state, ...)			\
	DEVICE_NAME_CHECK(name);						\
										\
	DEVICE_HANDLES_DEFINE(node_id, dev_id, __VA_ARGS__);			\
										\
	DEVICE_BASE_DEFINE(node_id, dev_id, name, data, config, level, prio,	\
			   api, pm, state, DEVICE_HANDLES_NAME(dev_id));	\
										\
	DEVICE_INIT_ENTRY_DEFINE(dev_id, init_fn, level, prio)

/**
 * @brief Declare a device for each status "okay" devicetree node.
 *
 * @note Disabled nodes should not result in devices, so not predeclaring these
 * keeps drivers honest.
 *
 * This is only "maybe" a device because some nodes have status "okay", but
 * don't have a corresponding @ref device allocated. There's no way to figure
 * that out until after we've built the zephyr image, though.
 */
#define MAYBE_DEVICE_DECLARE_INTERNAL(node_id)                               \
	extern const struct device DEVICE_DT_NAME_GET(node_id);

DT_FOREACH_STATUS_OKAY_NODE(MAYBE_DEVICE_DECLARE_INTERNAL)

#ifdef __cplusplus
}
#endif

#endif /* INCLUDE_DEVICE_H_ */
