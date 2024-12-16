/*
 * Copyright (c) 2016-2017 ARM Limited
 * Portions Copyright (C) 2024 Analog Devices, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include "Driver_MPC.h"

#include "mxc_device.h"
#include "platform_retarget.h"
#include "RTE_Device.h"
#include "mpc_sie200_drv.h"

/* ARM MPC SSE 200 driver structures */
#ifdef RTE_SRAM0_MPC
static const struct mpc_sie200_dev_cfg_t MPC_SRAM0_DEV_CFG_S = {
    .base = MPC_SRAM0_BASE_S};
static struct mpc_sie200_dev_data_t MPC_SRAM0_DEV_DATA_S = {
    .range_list = 0,
    .nbr_of_ranges = 0,
    .state = 0,
    .reserved = 0};
struct mpc_sie200_dev_t MPC_SRAM0_DEV_S = {
    &(MPC_SRAM0_DEV_CFG_S),
    &(MPC_SRAM0_DEV_DATA_S)};
#endif

#ifdef RTE_SRAM1_MPC
static const struct mpc_sie200_dev_cfg_t MPC_SRAM1_DEV_CFG_S = {
    .base = MPC_SRAM1_BASE_S};
static struct mpc_sie200_dev_data_t MPC_SRAM1_DEV_DATA_S = {
    .range_list = 0,
    .nbr_of_ranges = 0,
    .state = 0,
    .reserved = 0};
struct mpc_sie200_dev_t MPC_SRAM1_DEV_S = {
    &(MPC_SRAM1_DEV_CFG_S),
    &(MPC_SRAM1_DEV_DATA_S)};
#endif

#ifdef RTE_SRAM2_MPC
static const struct mpc_sie200_dev_cfg_t MPC_SRAM2_DEV_CFG_S = {
    .base = MPC_SRAM2_BASE_S};
static struct mpc_sie200_dev_data_t MPC_SRAM2_DEV_DATA_S = {
    .range_list = 0,
    .nbr_of_ranges = 0,
    .state = 0,
    .reserved = 0};
struct mpc_sie200_dev_t MPC_SRAM2_DEV_S = {
    &(MPC_SRAM2_DEV_CFG_S),
    &(MPC_SRAM2_DEV_DATA_S)};
#endif

#ifdef RTE_SRAM3_MPC
static const struct mpc_sie200_dev_cfg_t MPC_SRAM3_DEV_CFG_S = {
    .base = MPC_SRAM3_BASE_S};
static struct mpc_sie200_dev_data_t MPC_SRAM3_DEV_DATA_S = {
    .range_list = 0,
    .nbr_of_ranges = 0,
    .state = 0,
    .reserved = 0};
struct mpc_sie200_dev_t MPC_SRAM3_DEV_S = {
    &(MPC_SRAM3_DEV_CFG_S),
    &(MPC_SRAM3_DEV_DATA_S)};
#endif

#ifdef RTE_SRAM4_MPC
static const struct mpc_sie200_dev_cfg_t MPC_SRAM4_DEV_CFG_S = {
    .base = MPC_SRAM4_BASE_S};
static struct mpc_sie200_dev_data_t MPC_SRAM4_DEV_DATA_S = {
    .range_list = 0,
    .nbr_of_ranges = 0,
    .state = 0,
    .reserved = 0};
struct mpc_sie200_dev_t MPC_SRAM4_DEV_S = {
    &(MPC_SRAM4_DEV_CFG_S),
    &(MPC_SRAM4_DEV_DATA_S)};
#endif

#ifdef RTE_FLASH_MPC
static const struct mpc_sie200_dev_cfg_t MPC_FLASH_DEV_CFG_S = {
    .base = MPC_FLASH_BASE_S};
static struct mpc_sie200_dev_data_t MPC_FLASH_DEV_DATA_S = {
    .range_list = 0,
    .nbr_of_ranges = 0,
    .state = 0,
    .reserved = 0};
struct mpc_sie200_dev_t MPC_FLASH_DEV_S = {
    &(MPC_FLASH_DEV_CFG_S),
    &(MPC_FLASH_DEV_DATA_S)};
#endif

/* driver version */
#define ARM_MPC_DRV_VERSION ARM_DRIVER_VERSION_MAJOR_MINOR(1, 0)

/* Driver Version */
static const ARM_DRIVER_VERSION DriverVersion = {
    ARM_MPC_API_VERSION,
    ARM_MPC_DRV_VERSION};

static ARM_DRIVER_VERSION ARM_MPC_GetVersion(void)
{
    return DriverVersion;
}

/*
 * \brief Translates error codes from native API to CMSIS API.
 *
 * \param[in] err  Error code to translate (\ref mpc_sie200_error_t).
 *
 * \return Returns CMSIS error code.
 */
static int32_t error_trans(enum mpc_sie200_error_t err)
{
    switch (err)
    {
    case MPC_SIE200_ERR_NONE:
        return ARM_DRIVER_OK;
    case MPC_SIE200_INVALID_ARG:
        return ARM_DRIVER_ERROR_PARAMETER;
    case MPC_SIE200_NOT_INIT:
        return ARM_MPC_ERR_NOT_INIT;
    case MPC_SIE200_ERR_NOT_IN_RANGE:
        return ARM_MPC_ERR_NOT_IN_RANGE;
    case MPC_SIE200_ERR_NOT_ALIGNED:
        return ARM_MPC_ERR_NOT_ALIGNED;
    case MPC_SIE200_ERR_INVALID_RANGE:
        return ARM_MPC_ERR_INVALID_RANGE;
    case MPC_SIE200_ERR_RANGE_SEC_ATTR_NON_COMPATIBLE:
        return ARM_MPC_ERR_RANGE_SEC_ATTR_NON_COMPATIBLE;
        /* default:  The default is not defined intentionally to force the
         *           compiler to check that all the enumeration values are
         *           covered in the switch.
         */
    }
}

#if (RTE_SRAM0_MPC)
/* Ranges controlled by this SRAM0_MPC */
static struct mpc_sie200_memory_range_t MPC_SRAM0_RANGE_S = {
    .base = MPC_SRAM0_RANGE_BASE_S,
    .limit = MPC_SRAM0_RANGE_LIMIT_S,
    .attr = MPC_SIE200_SEC_ATTR_SECURE};

static struct mpc_sie200_memory_range_t MPC_SRAM0_RANGE_NS = {
    .base = MPC_SRAM0_RANGE_BASE_NS,
    .limit = MPC_SRAM0_RANGE_LIMIT_NS,
    .attr = MPC_SIE200_SEC_ATTR_NONSECURE};

#define MPC_SRAM0_RANGE_LIST_LEN 2u
static const struct mpc_sie200_memory_range_t *MPC_SRAM0_RANGE_LIST[MPC_SRAM0_RANGE_LIST_LEN] =
    {&MPC_SRAM0_RANGE_S, &MPC_SRAM0_RANGE_NS};

/* SRAM0_MPC Driver wrapper functions */
static int32_t SRAM0_MPC_Initialize(void)
{
    enum mpc_sie200_error_t ret;

    ret = mpc_sie200_init(&MPC_SRAM0_DEV_S,
                          MPC_SRAM0_RANGE_LIST,
                          MPC_SRAM0_RANGE_LIST_LEN);

    return error_trans(ret);
}

static int32_t SRAM0_MPC_Uninitialize(void)
{
    /* Nothing to be done */
    return ARM_DRIVER_OK;
}

static int32_t SRAM0_MPC_GetBlockSize(uint32_t *blk_size)
{
    enum mpc_sie200_error_t ret;

    ret = mpc_sie200_get_block_size(&MPC_SRAM0_DEV_S, blk_size);

    return error_trans(ret);
}

static int32_t SRAM0_MPC_GetCtrlConfig(uint32_t *ctrl_val)
{
    enum mpc_sie200_error_t ret;

    ret = mpc_sie200_get_ctrl(&MPC_SRAM0_DEV_S, ctrl_val);

    return error_trans(ret);
}

static int32_t SRAM0_MPC_SetCtrlConfig(uint32_t ctrl)
{
    enum mpc_sie200_error_t ret;

    ret = mpc_sie200_set_ctrl(&MPC_SRAM0_DEV_S, ctrl);

    return error_trans(ret);
}

static int32_t SRAM0_MPC_GetRegionConfig(uintptr_t base,
                                         uintptr_t limit,
                                         ARM_MPC_SEC_ATTR *attr)
{
    enum mpc_sie200_error_t ret;

    ret = mpc_sie200_get_region_config(&MPC_SRAM0_DEV_S, base, limit,
                                       (enum mpc_sie200_sec_attr_t *)attr);

    return error_trans(ret);
}

static int32_t SRAM0_MPC_ConfigRegion(uintptr_t base,
                                      uintptr_t limit,
                                      ARM_MPC_SEC_ATTR attr)
{
    enum mpc_sie200_error_t ret;

    ret = mpc_sie200_config_region(&MPC_SRAM0_DEV_S, base, limit,
                                   (enum mpc_sie200_sec_attr_t)attr);

    return error_trans(ret);
}

static int32_t SRAM0_MPC_EnableInterrupt(void)
{
    enum mpc_sie200_error_t ret;

    ret = mpc_sie200_irq_enable(&MPC_SRAM0_DEV_S);

    return error_trans(ret);
}

static void SRAM0_MPC_DisableInterrupt(void)
{
    mpc_sie200_irq_disable(&MPC_SRAM0_DEV_S);
}

static void SRAM0_MPC_ClearInterrupt(void)
{
    mpc_sie200_clear_irq(&MPC_SRAM0_DEV_S);
}

static uint32_t SRAM0_MPC_InterruptState(void)
{
    return mpc_sie200_irq_state(&MPC_SRAM0_DEV_S);
}

static int32_t SRAM0_MPC_LockDown(void)
{
    return mpc_sie200_lock_down(&MPC_SRAM0_DEV_S);
}

/* SRAM0_MPC Driver CMSIS access structure */
extern ARM_DRIVER_MPC Driver_SRAM0_MPC;
ARM_DRIVER_MPC Driver_SRAM0_MPC = {
    .GetVersion = ARM_MPC_GetVersion,
    .Initialize = SRAM0_MPC_Initialize,
    .Uninitialize = SRAM0_MPC_Uninitialize,
    .GetBlockSize = SRAM0_MPC_GetBlockSize,
    .GetCtrlConfig = SRAM0_MPC_GetCtrlConfig,
    .SetCtrlConfig = SRAM0_MPC_SetCtrlConfig,
    .ConfigRegion = SRAM0_MPC_ConfigRegion,
    .GetRegionConfig = SRAM0_MPC_GetRegionConfig,
    .EnableInterrupt = SRAM0_MPC_EnableInterrupt,
    .DisableInterrupt = SRAM0_MPC_DisableInterrupt,
    .ClearInterrupt = SRAM0_MPC_ClearInterrupt,
    .InterruptState = SRAM0_MPC_InterruptState,
    .LockDown = SRAM0_MPC_LockDown,
};
#endif /* RTE_SRAM0_MPC */

#if (RTE_SRAM1_MPC)
/* Ranges controlled by this SRAM1_MPC */
static struct mpc_sie200_memory_range_t MPC_SRAM1_RANGE_S = {
    .base = MPC_SRAM1_RANGE_BASE_S,
    .limit = MPC_SRAM1_RANGE_LIMIT_S,
    .attr = MPC_SIE200_SEC_ATTR_SECURE};

static struct mpc_sie200_memory_range_t MPC_SRAM1_RANGE_NS = {
    .base = MPC_SRAM1_RANGE_BASE_NS,
    .limit = MPC_SRAM1_RANGE_LIMIT_NS,
    .attr = MPC_SIE200_SEC_ATTR_NONSECURE};

#define MPC_SRAM1_RANGE_LIST_LEN 2u
static const struct mpc_sie200_memory_range_t *MPC_SRAM1_RANGE_LIST[MPC_SRAM1_RANGE_LIST_LEN] =
    {&MPC_SRAM1_RANGE_S, &MPC_SRAM1_RANGE_NS};

/* SRAM1_MPC Driver wrapper functions */
static int32_t SRAM1_MPC_Initialize(void)
{
    enum mpc_sie200_error_t ret;

    ret = mpc_sie200_init(&MPC_SRAM1_DEV_S,
                          MPC_SRAM1_RANGE_LIST,
                          MPC_SRAM1_RANGE_LIST_LEN);

    return error_trans(ret);
}

static int32_t SRAM1_MPC_Uninitialize(void)
{
    /* Nothing to be done */
    return ARM_DRIVER_OK;
}

static int32_t SRAM1_MPC_GetBlockSize(uint32_t *blk_size)
{
    enum mpc_sie200_error_t ret;

    ret = mpc_sie200_get_block_size(&MPC_SRAM1_DEV_S, blk_size);

    return error_trans(ret);
}

static int32_t SRAM1_MPC_GetCtrlConfig(uint32_t *ctrl_val)
{
    enum mpc_sie200_error_t ret;

    ret = mpc_sie200_get_ctrl(&MPC_SRAM1_DEV_S, ctrl_val);

    return error_trans(ret);
}

static int32_t SRAM1_MPC_SetCtrlConfig(uint32_t ctrl)
{
    enum mpc_sie200_error_t ret;

    ret = mpc_sie200_set_ctrl(&MPC_SRAM1_DEV_S, ctrl);

    return error_trans(ret);
}

static int32_t SRAM1_MPC_GetRegionConfig(uintptr_t base,
                                         uintptr_t limit,
                                         ARM_MPC_SEC_ATTR *attr)
{
    enum mpc_sie200_error_t ret;

    ret = mpc_sie200_get_region_config(&MPC_SRAM1_DEV_S, base, limit,
                                       (enum mpc_sie200_sec_attr_t *)attr);

    return error_trans(ret);
}

static int32_t SRAM1_MPC_ConfigRegion(uintptr_t base,
                                      uintptr_t limit,
                                      ARM_MPC_SEC_ATTR attr)
{
    enum mpc_sie200_error_t ret;

    ret = mpc_sie200_config_region(&MPC_SRAM1_DEV_S, base, limit,
                                   (enum mpc_sie200_sec_attr_t)attr);

    return error_trans(ret);
}

static int32_t SRAM1_MPC_EnableInterrupt(void)
{
    enum mpc_sie200_error_t ret;

    ret = mpc_sie200_irq_enable(&MPC_SRAM1_DEV_S);

    return error_trans(ret);
}

static void SRAM1_MPC_DisableInterrupt(void)
{
    mpc_sie200_irq_disable(&MPC_SRAM1_DEV_S);
}

static void SRAM1_MPC_ClearInterrupt(void)
{
    mpc_sie200_clear_irq(&MPC_SRAM1_DEV_S);
}

static uint32_t SRAM1_MPC_InterruptState(void)
{
    return mpc_sie200_irq_state(&MPC_SRAM1_DEV_S);
}

static int32_t SRAM1_MPC_LockDown(void)
{
    return mpc_sie200_lock_down(&MPC_SRAM1_DEV_S);
}

/* SRAM1_MPC Driver CMSIS access structure */
extern ARM_DRIVER_MPC Driver_SRAM1_MPC;
ARM_DRIVER_MPC Driver_SRAM1_MPC = {
    .GetVersion = ARM_MPC_GetVersion,
    .Initialize = SRAM1_MPC_Initialize,
    .Uninitialize = SRAM1_MPC_Uninitialize,
    .GetBlockSize = SRAM1_MPC_GetBlockSize,
    .GetCtrlConfig = SRAM1_MPC_GetCtrlConfig,
    .SetCtrlConfig = SRAM1_MPC_SetCtrlConfig,
    .ConfigRegion = SRAM1_MPC_ConfigRegion,
    .GetRegionConfig = SRAM1_MPC_GetRegionConfig,
    .EnableInterrupt = SRAM1_MPC_EnableInterrupt,
    .DisableInterrupt = SRAM1_MPC_DisableInterrupt,
    .ClearInterrupt = SRAM1_MPC_ClearInterrupt,
    .InterruptState = SRAM1_MPC_InterruptState,
    .LockDown = SRAM1_MPC_LockDown,
};
#endif /* RTE_SRAM1_MPC */

#if (RTE_SRAM2_MPC)
/* Ranges controlled by this SRAM2_MPC */
static struct mpc_sie200_memory_range_t MPC_SRAM2_RANGE_S = {
    .base = MPC_SRAM2_RANGE_BASE_S,
    .limit = MPC_SRAM2_RANGE_LIMIT_S,
    .attr = MPC_SIE200_SEC_ATTR_SECURE};

static struct mpc_sie200_memory_range_t MPC_SRAM2_RANGE_NS = {
    .base = MPC_SRAM2_RANGE_BASE_NS,
    .limit = MPC_SRAM2_RANGE_LIMIT_NS,
    .attr = MPC_SIE200_SEC_ATTR_NONSECURE};

#define MPC_SRAM2_RANGE_LIST_LEN 2u
static const struct mpc_sie200_memory_range_t *MPC_SRAM2_RANGE_LIST[MPC_SRAM2_RANGE_LIST_LEN] =
    {&MPC_SRAM2_RANGE_S, &MPC_SRAM2_RANGE_NS};

/* SRAM2_MPC Driver wrapper functions */
static int32_t SRAM2_MPC_Initialize(void)
{
    enum mpc_sie200_error_t ret;

    ret = mpc_sie200_init(&MPC_SRAM2_DEV_S,
                          MPC_SRAM2_RANGE_LIST,
                          MPC_SRAM2_RANGE_LIST_LEN);

    return error_trans(ret);
}

static int32_t SRAM2_MPC_Uninitialize(void)
{
    /* Nothing to be done */
    return ARM_DRIVER_OK;
}

static int32_t SRAM2_MPC_GetBlockSize(uint32_t *blk_size)
{
    enum mpc_sie200_error_t ret;

    ret = mpc_sie200_get_block_size(&MPC_SRAM2_DEV_S, blk_size);

    return error_trans(ret);
}

static int32_t SRAM2_MPC_GetCtrlConfig(uint32_t *ctrl_val)
{
    enum mpc_sie200_error_t ret;

    ret = mpc_sie200_get_ctrl(&MPC_SRAM2_DEV_S, ctrl_val);

    return error_trans(ret);
}

static int32_t SRAM2_MPC_SetCtrlConfig(uint32_t ctrl)
{
    enum mpc_sie200_error_t ret;

    ret = mpc_sie200_set_ctrl(&MPC_SRAM2_DEV_S, ctrl);

    return error_trans(ret);
}

static int32_t SRAM2_MPC_GetRegionConfig(uintptr_t base,
                                         uintptr_t limit,
                                         ARM_MPC_SEC_ATTR *attr)
{
    enum mpc_sie200_error_t ret;

    ret = mpc_sie200_get_region_config(&MPC_SRAM2_DEV_S, base, limit,
                                       (enum mpc_sie200_sec_attr_t *)attr);

    return error_trans(ret);
}

static int32_t SRAM2_MPC_ConfigRegion(uintptr_t base,
                                      uintptr_t limit,
                                      ARM_MPC_SEC_ATTR attr)
{
    enum mpc_sie200_error_t ret;

    ret = mpc_sie200_config_region(&MPC_SRAM2_DEV_S, base, limit,
                                   (enum mpc_sie200_sec_attr_t)attr);

    return error_trans(ret);
}

static int32_t SRAM2_MPC_EnableInterrupt(void)
{
    enum mpc_sie200_error_t ret;

    ret = mpc_sie200_irq_enable(&MPC_SRAM2_DEV_S);

    return error_trans(ret);
}

static void SRAM2_MPC_DisableInterrupt(void)
{
    mpc_sie200_irq_disable(&MPC_SRAM2_DEV_S);
}

static void SRAM2_MPC_ClearInterrupt(void)
{
    mpc_sie200_clear_irq(&MPC_SRAM2_DEV_S);
}

static uint32_t SRAM2_MPC_InterruptState(void)
{
    return mpc_sie200_irq_state(&MPC_SRAM2_DEV_S);
}

static int32_t SRAM2_MPC_LockDown(void)
{
    return mpc_sie200_lock_down(&MPC_SRAM2_DEV_S);
}

/* SRAM2_MPC Driver CMSIS access structure */
extern ARM_DRIVER_MPC Driver_SRAM2_MPC;
ARM_DRIVER_MPC Driver_SRAM2_MPC = {
    .GetVersion = ARM_MPC_GetVersion,
    .Initialize = SRAM2_MPC_Initialize,
    .Uninitialize = SRAM2_MPC_Uninitialize,
    .GetBlockSize = SRAM2_MPC_GetBlockSize,
    .GetCtrlConfig = SRAM2_MPC_GetCtrlConfig,
    .SetCtrlConfig = SRAM2_MPC_SetCtrlConfig,
    .ConfigRegion = SRAM2_MPC_ConfigRegion,
    .GetRegionConfig = SRAM2_MPC_GetRegionConfig,
    .EnableInterrupt = SRAM2_MPC_EnableInterrupt,
    .DisableInterrupt = SRAM2_MPC_DisableInterrupt,
    .ClearInterrupt = SRAM2_MPC_ClearInterrupt,
    .InterruptState = SRAM2_MPC_InterruptState,
    .LockDown = SRAM2_MPC_LockDown,
};
#endif /* RTE_SRAM2_MPC */

#if (RTE_SRAM3_MPC)
/* Ranges controlled by this SRAM3_MPC */
static struct mpc_sie200_memory_range_t MPC_SRAM3_RANGE_S = {
    .base = MPC_SRAM3_RANGE_BASE_S,
    .limit = MPC_SRAM3_RANGE_LIMIT_S,
    .attr = MPC_SIE200_SEC_ATTR_SECURE};

static struct mpc_sie200_memory_range_t MPC_SRAM3_RANGE_NS = {
    .base = MPC_SRAM3_RANGE_BASE_NS,
    .limit = MPC_SRAM3_RANGE_LIMIT_NS,
    .attr = MPC_SIE200_SEC_ATTR_NONSECURE};

#define MPC_SRAM3_RANGE_LIST_LEN 2u
static const struct mpc_sie200_memory_range_t *MPC_SRAM3_RANGE_LIST[MPC_SRAM3_RANGE_LIST_LEN] =
    {&MPC_SRAM3_RANGE_S, &MPC_SRAM3_RANGE_NS};

/* SRAM3_MPC Driver wrapper functions */
static int32_t SRAM3_MPC_Initialize(void)
{
    enum mpc_sie200_error_t ret;

    ret = mpc_sie200_init(&MPC_SRAM3_DEV_S,
                          MPC_SRAM3_RANGE_LIST,
                          MPC_SRAM3_RANGE_LIST_LEN);

    return error_trans(ret);
}

static int32_t SRAM3_MPC_Uninitialize(void)
{
    /* Nothing to be done */
    return ARM_DRIVER_OK;
}

static int32_t SRAM3_MPC_GetBlockSize(uint32_t *blk_size)
{
    enum mpc_sie200_error_t ret;

    ret = mpc_sie200_get_block_size(&MPC_SRAM3_DEV_S, blk_size);

    return error_trans(ret);
}

static int32_t SRAM3_MPC_GetCtrlConfig(uint32_t *ctrl_val)
{
    enum mpc_sie200_error_t ret;

    ret = mpc_sie200_get_ctrl(&MPC_SRAM3_DEV_S, ctrl_val);

    return error_trans(ret);
}

static int32_t SRAM3_MPC_SetCtrlConfig(uint32_t ctrl)
{
    enum mpc_sie200_error_t ret;

    ret = mpc_sie200_set_ctrl(&MPC_SRAM3_DEV_S, ctrl);

    return error_trans(ret);
}

static int32_t SRAM3_MPC_GetRegionConfig(uintptr_t base,
                                         uintptr_t limit,
                                         ARM_MPC_SEC_ATTR *attr)
{
    enum mpc_sie200_error_t ret;

    ret = mpc_sie200_get_region_config(&MPC_SRAM3_DEV_S, base, limit,
                                       (enum mpc_sie200_sec_attr_t *)attr);

    return error_trans(ret);
}

static int32_t SRAM3_MPC_ConfigRegion(uintptr_t base,
                                      uintptr_t limit,
                                      ARM_MPC_SEC_ATTR attr)
{
    enum mpc_sie200_error_t ret;

    ret = mpc_sie200_config_region(&MPC_SRAM3_DEV_S, base, limit,
                                   (enum mpc_sie200_sec_attr_t)attr);

    return error_trans(ret);
}

static int32_t SRAM3_MPC_EnableInterrupt(void)
{
    enum mpc_sie200_error_t ret;

    ret = mpc_sie200_irq_enable(&MPC_SRAM3_DEV_S);

    return error_trans(ret);
}

static void SRAM3_MPC_DisableInterrupt(void)
{
    mpc_sie200_irq_disable(&MPC_SRAM3_DEV_S);
}

static void SRAM3_MPC_ClearInterrupt(void)
{
    mpc_sie200_clear_irq(&MPC_SRAM3_DEV_S);
}

static uint32_t SRAM3_MPC_InterruptState(void)
{
    return mpc_sie200_irq_state(&MPC_SRAM3_DEV_S);
}

static int32_t SRAM3_MPC_LockDown(void)
{
    return mpc_sie200_lock_down(&MPC_SRAM3_DEV_S);
}

/* SRAM3_MPC Driver CMSIS access structure */
extern ARM_DRIVER_MPC Driver_SRAM3_MPC;
ARM_DRIVER_MPC Driver_SRAM3_MPC = {
    .GetVersion = ARM_MPC_GetVersion,
    .Initialize = SRAM3_MPC_Initialize,
    .Uninitialize = SRAM3_MPC_Uninitialize,
    .GetBlockSize = SRAM3_MPC_GetBlockSize,
    .GetCtrlConfig = SRAM3_MPC_GetCtrlConfig,
    .SetCtrlConfig = SRAM3_MPC_SetCtrlConfig,
    .ConfigRegion = SRAM3_MPC_ConfigRegion,
    .GetRegionConfig = SRAM3_MPC_GetRegionConfig,
    .EnableInterrupt = SRAM3_MPC_EnableInterrupt,
    .DisableInterrupt = SRAM3_MPC_DisableInterrupt,
    .ClearInterrupt = SRAM3_MPC_ClearInterrupt,
    .InterruptState = SRAM3_MPC_InterruptState,
    .LockDown = SRAM3_MPC_LockDown,
};
#endif /* RTE_SRAM3_MPC */

#if (RTE_SRAM4_MPC)
/* Ranges controlled by this SRAM4_MPC */
static struct mpc_sie200_memory_range_t MPC_SRAM4_RANGE_S = {
    .base = MPC_SRAM4_RANGE_BASE_S,
    .limit = MPC_SRAM4_RANGE_LIMIT_S,
    .attr = MPC_SIE200_SEC_ATTR_SECURE};

static struct mpc_sie200_memory_range_t MPC_SRAM4_RANGE_NS = {
    .base = MPC_SRAM4_RANGE_BASE_NS,
    .limit = MPC_SRAM4_RANGE_LIMIT_NS,
    .attr = MPC_SIE200_SEC_ATTR_NONSECURE};

#define MPC_SRAM4_RANGE_LIST_LEN 2u
static const struct mpc_sie200_memory_range_t *MPC_SRAM4_RANGE_LIST[MPC_SRAM4_RANGE_LIST_LEN] =
    {&MPC_SRAM4_RANGE_S, &MPC_SRAM4_RANGE_NS};

/* SRAM4_MPC Driver wrapper functions */
static int32_t SRAM4_MPC_Initialize(void)
{
    enum mpc_sie200_error_t ret;

    ret = mpc_sie200_init(&MPC_SRAM4_DEV_S,
                          MPC_SRAM4_RANGE_LIST,
                          MPC_SRAM4_RANGE_LIST_LEN);

    return error_trans(ret);
}

static int32_t SRAM4_MPC_Uninitialize(void)
{
    /* Nothing to be done */
    return ARM_DRIVER_OK;
}

static int32_t SRAM4_MPC_GetBlockSize(uint32_t *blk_size)
{
    enum mpc_sie200_error_t ret;

    ret = mpc_sie200_get_block_size(&MPC_SRAM4_DEV_S, blk_size);

    return error_trans(ret);
}

static int32_t SRAM4_MPC_GetCtrlConfig(uint32_t *ctrl_val)
{
    enum mpc_sie200_error_t ret;

    ret = mpc_sie200_get_ctrl(&MPC_SRAM4_DEV_S, ctrl_val);

    return error_trans(ret);
}

static int32_t SRAM4_MPC_SetCtrlConfig(uint32_t ctrl)
{
    enum mpc_sie200_error_t ret;

    ret = mpc_sie200_set_ctrl(&MPC_SRAM4_DEV_S, ctrl);

    return error_trans(ret);
}

static int32_t SRAM4_MPC_GetRegionConfig(uintptr_t base,
                                         uintptr_t limit,
                                         ARM_MPC_SEC_ATTR *attr)
{
    enum mpc_sie200_error_t ret;

    ret = mpc_sie200_get_region_config(&MPC_SRAM4_DEV_S, base, limit,
                                       (enum mpc_sie200_sec_attr_t *)attr);

    return error_trans(ret);
}

static int32_t SRAM4_MPC_ConfigRegion(uintptr_t base,
                                      uintptr_t limit,
                                      ARM_MPC_SEC_ATTR attr)
{
    enum mpc_sie200_error_t ret;

    ret = mpc_sie200_config_region(&MPC_SRAM4_DEV_S, base, limit,
                                   (enum mpc_sie200_sec_attr_t)attr);

    return error_trans(ret);
}

static int32_t SRAM4_MPC_EnableInterrupt(void)
{
    enum mpc_sie200_error_t ret;

    ret = mpc_sie200_irq_enable(&MPC_SRAM4_DEV_S);

    return error_trans(ret);
}

static void SRAM4_MPC_DisableInterrupt(void)
{
    mpc_sie200_irq_disable(&MPC_SRAM4_DEV_S);
}

static void SRAM4_MPC_ClearInterrupt(void)
{
    mpc_sie200_clear_irq(&MPC_SRAM4_DEV_S);
}

static uint32_t SRAM4_MPC_InterruptState(void)
{
    return mpc_sie200_irq_state(&MPC_SRAM4_DEV_S);
}

static int32_t SRAM4_MPC_LockDown(void)
{
    return mpc_sie200_lock_down(&MPC_SRAM4_DEV_S);
}

/* SRAM4_MPC Driver CMSIS access structure */
extern ARM_DRIVER_MPC Driver_SRAM4_MPC;
ARM_DRIVER_MPC Driver_SRAM4_MPC = {
    .GetVersion = ARM_MPC_GetVersion,
    .Initialize = SRAM4_MPC_Initialize,
    .Uninitialize = SRAM4_MPC_Uninitialize,
    .GetBlockSize = SRAM4_MPC_GetBlockSize,
    .GetCtrlConfig = SRAM4_MPC_GetCtrlConfig,
    .SetCtrlConfig = SRAM4_MPC_SetCtrlConfig,
    .ConfigRegion = SRAM4_MPC_ConfigRegion,
    .GetRegionConfig = SRAM4_MPC_GetRegionConfig,
    .EnableInterrupt = SRAM4_MPC_EnableInterrupt,
    .DisableInterrupt = SRAM4_MPC_DisableInterrupt,
    .ClearInterrupt = SRAM4_MPC_ClearInterrupt,
    .InterruptState = SRAM4_MPC_InterruptState,
    .LockDown = SRAM4_MPC_LockDown,
};
#endif /* RTE_SRAM4_MPC */

#if (RTE_FLASH_MPC)
/* Ranges controlled by this FLASH_MPC */
static struct mpc_sie200_memory_range_t MPC_FLASH_RANGE_S = {
    .base = FLASH0_BASE_S,
    .limit = FLASH0_BASE_S + FLASH0_SIZE - 1,
    .attr = MPC_SIE200_SEC_ATTR_SECURE};

static struct mpc_sie200_memory_range_t MPC_FLASH_RANGE_NS = {
    .base = FLASH0_BASE_NS,
    .limit = FLASH0_BASE_NS + FLASH0_SIZE - 1,
    .attr = MPC_SIE200_SEC_ATTR_NONSECURE};

#define MPC_FLASH_RANGE_LIST_LEN 2u
static const struct mpc_sie200_memory_range_t *MPC_FLASH_RANGE_LIST[MPC_FLASH_RANGE_LIST_LEN] =
    {&MPC_FLASH_RANGE_S, &MPC_FLASH_RANGE_NS};

/* FLASH_MPC Driver wrapper functions */
static int32_t FLASH_MPC_Initialize(void)
{
    enum mpc_sie200_error_t ret;

    ret = mpc_sie200_init(&MPC_FLASH_DEV_S,
                          MPC_FLASH_RANGE_LIST,
                          MPC_FLASH_RANGE_LIST_LEN);

    return error_trans(ret);
}

static int32_t FLASH_MPC_Uninitialize(void)
{
    /* Nothing to be done */
    return ARM_DRIVER_OK;
}

static int32_t FLASH_MPC_GetBlockSize(uint32_t *blk_size)
{
    enum mpc_sie200_error_t ret;

    ret = mpc_sie200_get_block_size(&MPC_FLASH_DEV_S, blk_size);

    return error_trans(ret);
}

static int32_t FLASH_MPC_GetCtrlConfig(uint32_t *ctrl_val)
{
    enum mpc_sie200_error_t ret;

    ret = mpc_sie200_get_ctrl(&MPC_FLASH_DEV_S, ctrl_val);

    return error_trans(ret);
}

static int32_t FLASH_MPC_SetCtrlConfig(uint32_t ctrl)
{
    enum mpc_sie200_error_t ret;

    ret = mpc_sie200_set_ctrl(&MPC_FLASH_DEV_S, ctrl);

    return error_trans(ret);
}

static int32_t FLASH_MPC_GetRegionConfig(uintptr_t base,
                                         uintptr_t limit,
                                         ARM_MPC_SEC_ATTR *attr)
{
    enum mpc_sie200_error_t ret;

    ret = mpc_sie200_get_region_config(&MPC_FLASH_DEV_S, base, limit,
                                       (enum mpc_sie200_sec_attr_t *)attr);

    return error_trans(ret);
}

static int32_t FLASH_MPC_ConfigRegion(uintptr_t base,
                                      uintptr_t limit,
                                      ARM_MPC_SEC_ATTR attr)
{
    enum mpc_sie200_error_t ret;

    ret = mpc_sie200_config_region(&MPC_FLASH_DEV_S, base, limit,
                                   (enum mpc_sie200_sec_attr_t)attr);

    return error_trans(ret);
}

static int32_t FLASH_MPC_EnableInterrupt(void)
{
    enum mpc_sie200_error_t ret;

    ret = mpc_sie200_irq_enable(&MPC_FLASH_DEV_S);

    return error_trans(ret);
}

static void FLASH_MPC_DisableInterrupt(void)
{
    mpc_sie200_irq_disable(&MPC_FLASH_DEV_S);
}

static void FLASH_MPC_ClearInterrupt(void)
{
    mpc_sie200_clear_irq(&MPC_FLASH_DEV_S);
}

static uint32_t FLASH_MPC_InterruptState(void)
{
    return mpc_sie200_irq_state(&MPC_FLASH_DEV_S);
}

static int32_t FLASH_MPC_LockDown(void)
{
    return mpc_sie200_lock_down(&MPC_FLASH_DEV_S);
}

/* FLASH_MPC Driver CMSIS access structure */
extern ARM_DRIVER_MPC Driver_FLASH_MPC;
ARM_DRIVER_MPC Driver_FLASH_MPC = {
    .GetVersion = ARM_MPC_GetVersion,
    .Initialize = FLASH_MPC_Initialize,
    .Uninitialize = FLASH_MPC_Uninitialize,
    .GetBlockSize = FLASH_MPC_GetBlockSize,
    .GetCtrlConfig = FLASH_MPC_GetCtrlConfig,
    .SetCtrlConfig = FLASH_MPC_SetCtrlConfig,
    .ConfigRegion = FLASH_MPC_ConfigRegion,
    .GetRegionConfig = FLASH_MPC_GetRegionConfig,
    .EnableInterrupt = FLASH_MPC_EnableInterrupt,
    .DisableInterrupt = FLASH_MPC_DisableInterrupt,
    .ClearInterrupt = FLASH_MPC_ClearInterrupt,
    .InterruptState = FLASH_MPC_InterruptState,
    .LockDown = FLASH_MPC_LockDown,
};
#endif /* RTE_FLASH_MPC */
