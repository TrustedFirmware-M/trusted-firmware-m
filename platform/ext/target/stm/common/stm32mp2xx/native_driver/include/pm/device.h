/* SPDX-License-Identifier: BSD-3-Clause */
/*
 * Copyright (c) 2026, STMicroelectronics - All Rights Reserved
 */
#ifndef  TFM_PM_DEVICE_H
#define  TFM_PM_DEVICE_H

#include <stdbool.h>
#include <device.h>
#include <iterable_sections.h>
#include <lib/utils_def.h>

/** @brief Device PM actions. */
enum pm_device_action {
	/** Suspend. */
	PM_DEVICE_ACTION_SUSPEND,
	/** Resume. */
	PM_DEVICE_ACTION_RESUME,
};

/** @brief Device power states. */
enum pm_device_state {
	/** Device is in active or regular state. */
	PM_DEVICE_STATE_ACTIVE,
	/** Device is suspended. */
	PM_DEVICE_STATE_SUSPENDED,
};

/** @brief PM flags */
#define PM_DEVICE_F_NONE		0
#define PM_DEVICE_F_NO_SUSPEND		BIT(0)

#define PM_DEVICE_NAME(dev_id) _CONCAT(__pm_device_, dev_id)

#define PM_DEVICE_INIT(node_id, pm_action_cb, _flags)				\
	{									\
		.state = PM_DEVICE_STATE_ACTIVE,				\
		.action_cb = pm_action_cb,					\
		.flags = _flags							\
	}

#define PM_DEVICE_DEFINE_SLOT(dev_id)						\
	static STRUCT_SECTION_ITERABLE_ALTERNATE(pm_device_slots, device,	\
						 _CONCAT(__pm_slot_, dev_id))
#ifdef CONFIG_PM_DEVICE
/**
 * Define device PM resources for the given node identifier.
 *
 * @param node_id Node identifier (DT_INVALID_NODE if not a DT device).
 * @param dev_id Device id.
 * @param pm_action_cb PM control callback.
 * @param flags Initial value for the device PM flags field.
 */
#define PM_DEVICE_DEFINE(node_id, dev_id, pm_action_cb, _flags)			\
	PM_DEVICE_DEFINE_SLOT(dev_id);						\
	static struct pm_device PM_DEVICE_NAME(dev_id) =			\
		PM_DEVICE_INIT(node_id, pm_action_cb, _flags)

/**
 * Get a reference to the device PM resources.
 *
 * @param dev_id Device id.
 */
#define PM_DEVICE_GET(dev_id) ((struct pm_device *)&PM_DEVICE_NAME(dev_id))

#else
#define PM_DEVICE_DEFINE(node_id, dev_id, pm_action_cb, _flags)
#define PM_DEVICE_GET(dev_id) NULL

#endif /* CONFIG_PM_DEVICE */

#define PM_DEVICE_DT_DEFINE(node_id, pm_action_cb, _flags)			\
	PM_DEVICE_DEFINE(node_id, DEVICE_DT_DEV_ID(node_id), pm_action_cb, _flags)

#define PM_DEVICE_DT_INST_DEFINE(inst, pm_action_cb, _flags)			\
	PM_DEVICE_DT_DEFINE(DT_DRV_INST(inst), pm_action_cb, _flags)

#define PM_DEVICE_DT_GET(node_id)						\
	PM_DEVICE_GET(DEVICE_DT_DEV_ID(node_id))

#define PM_DEVICE_DT_INST_GET(idx)						\
	PM_DEVICE_DT_GET(DT_DRV_INST(idx))

/**
 * @brief Device PM action callback.
 *
 * @param dev Device instance.
 * @param action Requested action.
 * @param pm_hint Platform hints on targeted power state.
 *
 * @retval 0 If successful.
 * @retval -ENOTSUP If the requested action is not supported.
 * @retval Errno Other negative errno on failure.
 */
typedef int (*pm_device_action_cb_t)(const struct device *dev,
				     enum pm_device_action action,
				     uint32_t pm_hint);

/**
 * @brief Device PM info
 *
 * Structure holds fields for PM devices
 */
struct pm_device {
	/** Device power state */
	enum pm_device_state state;
	/** Device PM action callback */
	pm_device_action_cb_t action_cb;
	uint32_t flags;
};

#ifdef CONFIG_PM_DEVICE
bool pm_suspend_devices(uint32_t pm_hint);
void pm_resume_devices(uint32_t pm_hint);

static inline void pm_device_set_state(const struct device *dev, enum pm_device_state state)
{
	struct pm_device *pm = dev->pm;

	if (pm != NULL)
		pm->state = state;
}

static inline bool pm_device_is_active(const struct device *dev)
{
	struct pm_device *pm = dev->pm;
	return (pm == NULL) || (pm->state == PM_DEVICE_STATE_ACTIVE);
}

static inline void pm_device_flags_set(const struct device *dev, uint32_t flag)
{
	struct pm_device *pm = dev->pm;

	if (pm != NULL)
		pm->flags |= flag;
}

static inline bool pm_device_flags_has(const struct device *dev, uint32_t flags)
{
	struct pm_device *pm = dev->pm;

	if (pm == NULL)
		return false;

	return (pm->flags & flags) == flags;
}
#else
static inline bool pm_suspend_devices(uint32_t pm_hint __unused) {return true;}
static inline void pm_resume_devices(uint32_t pm_hint __unused) {}
static inline void pm_device_set_state(const struct device *dev, enum pm_device_state state) {}
static inline bool pm_device_is_active(const struct device *dev __unused) {return true;}
static inline void pm_device_flags_set(const struct device *dev __unused, uint32_t flag __unused) {}
static inline bool pm_device_flags_has(const struct device *dev __unused, uint32_t flags __unused)
{return false; }
#endif

#endif /* TFM_PM_DEVICE_H */
