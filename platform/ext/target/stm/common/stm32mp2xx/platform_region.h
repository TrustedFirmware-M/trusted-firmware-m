/* SPDX-License-Identifier: BSD-3-Clause */
/*
 * Copyright (c) 2026, STMicroelectronics - All Rights Reserved
 */
#ifndef __PLATFORM_H__
#define __PLATFORM_H__

#include <dt-bindings/memory-attr/memory-attr-arm.h>
#include <mpu_armv8m_drv.h>
#include <sau_armv8m_drv.h>
#include <region.h>

/*
 * limit point of view:
 * Linker script: the limit is the address of next element => base + sizeof(section)
 * Arm register: the limit is the address of the last element => base + sizeof(section) - 1
 */
#define END_2_LIMIT(end) ((end) - 1)

#ifdef STM32_SEC

REGION_DECLARE(Image$$, ER_VENEER, $$Base);
REGION_DECLARE(Image$$, VENEER_ALIGN, $$Limit);
REGION_DECLARE(Image$$, TFM_UNPRIV_CODE_START, $$RO$$Base);
REGION_DECLARE(Image$$, TFM_UNPRIV_CODE_END, $$RO$$Limit);
REGION_DECLARE(Image$$, TFM_APP_CODE_START, $$Base);
REGION_DECLARE(Image$$, TFM_APP_CODE_END, $$Base);
REGION_DECLARE(Image$$, TFM_APP_RW_STACK_START, $$Base);
REGION_DECLARE(Image$$, TFM_APP_RW_STACK_END, $$Base);

/*
 * Allows platform to define MPU regions based on linker definition.
 * MPU driver take account this macro and devicetree meomory attributes
 */
#ifdef CONFIG_TFM_PARTITION_META
REGION_DECLARE(Image$$, TFM_SP_META_PTR, $$ZI$$Base);
REGION_DECLARE(Image$$, TFM_SP_META_PTR, $$ZI$$Limit);
#define MPU_BUILTIN_SP_META()										\
	MPU_REGION((uint32_t)&REGION_NAME(Image$$, TFM_SP_META_PTR, $$ZI$$Base),			\
		   END_2_LIMIT((uint32_t)&REGION_NAME(Image$$, TFM_SP_META_PTR, $$ZI$$Limit)),		\
		   DT_MEM_ARM_MPU(MAIR_ATTR_DATA_IDX, SH_NONE, AP_P_RW_U_RW, EXEC_NEVER)),
#else
#define MPU_BUILTIN_SP_META()
#endif

/*
 * If the board does not define a specific mpu, the platform's default definition is used.
 */
#ifndef MPU_PLAT_BUILTIN
#define MPU_PLAT_BUILTIN()										\
	MPU_REGION((uint32_t)&REGION_NAME(Image$$, ER_VENEER, $$Base),					\
		   END_2_LIMIT((uint32_t)&REGION_NAME(Image$$, VENEER_ALIGN, $$Limit)),			\
		   DT_MEM_ARM_MPU(MAIR_ATTR_CODE_IDX, SH_NONE, AP_P_RO_U_RO, EXEC_OK)),			\
	MPU_REGION((uint32_t)&REGION_NAME(Image$$, TFM_UNPRIV_CODE_START, $$RO$$Base),			\
		   END_2_LIMIT((uint32_t)&REGION_NAME(Image$$, TFM_UNPRIV_CODE_END, $$RO$$Limit)),	\
		   DT_MEM_ARM_MPU(MAIR_ATTR_CODE_IDX, SH_NONE, AP_P_RO_U_RO, EXEC_OK)),			\
	MPU_REGION((uint32_t)&REGION_NAME(Image$$, TFM_APP_CODE_START, $$Base),				\
		   END_2_LIMIT((uint32_t)&REGION_NAME(Image$$, TFM_APP_CODE_END, $$Base)),		\
		   DT_MEM_ARM_MPU(MAIR_ATTR_CODE_IDX, SH_NONE, AP_P_RO_U_RO, EXEC_OK)),			\
	MPU_REGION((uint32_t)&REGION_NAME(Image$$, TFM_APP_RW_STACK_START, $$Base),			\
		   END_2_LIMIT((uint32_t)&REGION_NAME(Image$$, TFM_APP_RW_STACK_END, $$Base)),		\
		   DT_MEM_ARM_MPU(MAIR_ATTR_DATA_IDX, SH_NONE, AP_P_RW_U_RW, EXEC_NEVER)),		\
	MPU_BUILTIN_SP_META()
#endif

#ifndef SAU_PLAT_BUILTIN
#define SAU_PLAT_BUILTIN()										\
	SAU_REGION((uint32_t)&REGION_NAME(Image$$, ER_VENEER, $$Base),					\
		   END_2_LIMIT((uint32_t)&REGION_NAME(Image$$, VENEER_ALIGN, $$Limit)),			\
		   DT_MEM_ARM_SAU(NSC_EN)),
#endif

#endif /* STM32_SEC */

#endif /* __PLATFORM_H__ */
