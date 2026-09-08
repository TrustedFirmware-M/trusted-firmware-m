/*
 * Copyright (c) 2026, STMicroelectronics - All Rights Reserved
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#include <arm_cmse.h>
#include <cmsis.h>
#include <lib/utils_def.h>
#include <region.h>
#include <target_cfg.h>
#include <tfm_arch.h>
#include <device_cfg.h>
#include <region_defs.h>
#include <string.h>
#include <tfm_hal_isolation.h>
#include <mmio_defs.h>
#include <init.h>

#include <mpu_armv8m_drv.h>

#define PROT_BOUNDARY_VAL \
    ((1U << HANDLE_ATTR_PRIV_POS) & HANDLE_ATTR_PRIV_MASK)

FIH_RET_TYPE(enum tfm_hal_status_t) tfm_hal_set_up_static_boundaries(uintptr_t *p_spm_boundary)
{
	/*
	 * Setup:
	 * - isolation boundaries between SPE and NSPE
	 * - mpu if activated
	 */
	sys_init_run_level(INIT_LEVEL_ARCH);

	*p_spm_boundary = (uintptr_t)PROT_BOUNDARY_VAL;

	FIH_RET(fih_int_encode(TFM_HAL_SUCCESS));
}

/*
 * Implementation of tfm_hal_bind_boundary() on STM:
 *
 * The API encodes some attributes into a handle and returns it to SPM.
 * The attributes include isolation boundaries, privilege, and MMIO information.
 * When scheduler switches running partitions, SPM compares the handle between
 * partitions to know if boundary update is necessary. If update is required,
 * SPM passes the handle to platform to do platform settings and update
 * isolation boundaries.
 *
 * The handle should be unique under isolation level 3. The implementation
 * encodes an index at the highest 8 bits to assure handle uniqueness. While
 * under isolation level 1/2, handles may not be unique.
 *
 * The encoding format assignment:
 * - For isolation level 3
 *      BIT | 31        24 | 23         20 | ... | 7           4 | 3        0 |
 *          | Unique Index | Region Attr 5 | ... | Region Attr 1 | Privileged |
 *
 *      In which the "Region Attr i" is:
 *      BIT |       3      | 2        0 |
 *          | 1: RW, 0: RO | MMIO Index |
 *
 * - For isolation level 1/2
 *      BIT | 31                           0 |
 *          | 1: privileged, 0: unprivileged |
 *
 * This is a reference implementation on STM, and may have some limitations.
 * 1. The maximum number of allowed MMIO regions is 5.
 * 2. Highest 8 bits are for index. It supports 256 unique handles at most.
 */
FIH_RET_TYPE(enum tfm_hal_status_t) tfm_hal_bind_boundary(const struct partition_load_info_t *p_ldinf,
                                                          uintptr_t *p_boundary)
{
	bool privileged;
	bool ns_agent;
	uint32_t partition_attrs = 0;

#if TFM_ISOLATION_LEVEL == 1
	privileged = true;
#else
	privileged = IS_PSA_ROT(p_ldinf);
#endif
	ns_agent = (!!((p_ldinf)->flags & PARTITION_NS_AGENT_TZ));

	partition_attrs = ((uint32_t)privileged << HANDLE_ATTR_PRIV_POS) & HANDLE_ATTR_PRIV_MASK;
	partition_attrs |= ((uint32_t)ns_agent << HANDLE_ATTR_NS_POS) & HANDLE_ATTR_NS_MASK;
	*p_boundary = (uintptr_t)partition_attrs;

	FIH_RET(fih_int_encode(TFM_HAL_SUCCESS));
}

FIH_RET_TYPE(enum tfm_hal_status_t) tfm_hal_activate_boundary(const struct partition_load_info_t *p_ldinf,
                                                              uintptr_t boundary)
{
	uint32_t local_handle = (uint32_t)boundary;
	bool privileged = !!(local_handle & HANDLE_ATTR_PRIV_MASK);

	/* Privileged level is required to be set always */
	__set_CONTROL_nPRIV(privileged ? 0 : 1);

	FIH_RET(fih_int_encode(TFM_HAL_SUCCESS));
}

FIH_RET_TYPE(enum tfm_hal_status_t) tfm_hal_memory_check(uintptr_t boundary, uintptr_t base,
                                                         size_t size, uint32_t access_type)
{
	int flags = 0;

	/* If size is zero, this indicates an empty buffer and base is ignored */
	if (size == 0)
		FIH_RET(fih_int_encode(TFM_HAL_SUCCESS));

	if (!base)
		FIH_RET(fih_int_encode(TFM_HAL_ERROR_INVALID_INPUT));

	if ((access_type & TFM_HAL_ACCESS_READWRITE) == TFM_HAL_ACCESS_READWRITE)
		flags |= CMSE_MPU_READWRITE;
	else if (access_type & TFM_HAL_ACCESS_READABLE)
		flags |= CMSE_MPU_READ;
	else
		FIH_RET(fih_int_encode(TFM_HAL_ERROR_INVALID_INPUT));

	if (access_type & TFM_HAL_ACCESS_NS)
		flags |= CMSE_NONSECURE;

	if (!((uint32_t)boundary & HANDLE_ATTR_PRIV_MASK))
		flags |= CMSE_MPU_UNPRIV;

	/* This check is only done for ns_agent_tz */
	if ((uint32_t)boundary & HANDLE_ATTR_NS_MASK) {
		CONTROL_Type ctrl;

		ctrl.w = __TZ_get_CONTROL_NS();
		if (ctrl.b.nPRIV == 1)
			flags |= CMSE_MPU_UNPRIV;
		else
			flags &= ~CMSE_MPU_UNPRIV;

		flags |= CMSE_NONSECURE;
	}

	if (cmse_check_address_range((void *)base, size, flags) == 0) {
		FIH_RET(fih_int_encode(TFM_HAL_ERROR_MEM_FAULT));
	}
	/* must be completed by rif check */

	FIH_RET(fih_int_encode(TFM_HAL_SUCCESS));
}

FIH_RET_TYPE(bool) tfm_hal_boundary_need_switch(uintptr_t boundary_from,
                                                uintptr_t boundary_to)
{
	if (boundary_from == boundary_to)
		FIH_RET(fih_int_encode(false));

	if (((uint32_t)boundary_from & HANDLE_ATTR_PRIV_MASK) &&
		((uint32_t)boundary_to & HANDLE_ATTR_PRIV_MASK))
		FIH_RET(fih_int_encode(false));

	FIH_RET(fih_int_encode(true));
}
