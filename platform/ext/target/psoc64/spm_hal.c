/*
 * Copyright (c) 2018-2019, Arm Limited. All rights reserved.
 * Copyright (c) 2019, Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <stdbool.h>
#include <stdio.h>

#include "platform/include/tfm_spm_hal.h"

#include "region_defs.h"
#include "secure_utilities.h"
#include "spe_ipc_config.h"
#include "spm_api.h"
#include "spm_db.h"
#include "target_cfg.h"
#include "tfm_multi_core.h"
#include "tfm_platform_core_api.h"

#include "cycfg.h"
#include "cy_device.h"
#include "cy_device_headers.h"
#include "cy_ipc_drv.h"
#include "cy_prot.h"
#include "cy_sysint.h"
#include "pc_config.h"

/* Get address of memory regions to configure MPU */
extern const struct memory_region_limits memory_regions;

enum tfm_plat_err_t tfm_spm_hal_init_isolation_hw(void)
{
    cy_en_prot_status_t ret;

    /* Ensure that CM0+ is in secure mode */
    ret = Cy_Prot_ConfigBusMaster(CPUSS_MS_ID_CM0, true, true, SECURE_PCS_MASK);
    if (ret != CY_PROT_SUCCESS) {
        return TFM_PLAT_ERR_SYSTEM_ERR;
    }
    smpu_init_cfg();
    ppu_init_cfg();
    bus_masters_cfg();

    return TFM_PLAT_ERR_SUCCESS;
}

void tfm_spm_hal_configure_default_isolation(
        const struct tfm_spm_partition_platform_data_t *platform_data)
{
    printf("In %s()\n", __func__);
    if (platform_data) {
        /* TBD */
    }
}

#if TFM_LVL != 1

#define MPU_REGION_TFM_UNPRIV_CODE   1
#define MPU_REGION_TFM_UNPRIV_DATA   2
#define MPU_REGION_NS_DATA           3
#define PARTITION_REGION_RO          4
#define PARTITION_REGION_RW_STACK    5
#define PARTITION_REGION_PERIPH      6
#define PARTITION_REGION_SHARE       7

REGION_DECLARE(Image$$, TFM_UNPRIV_CODE, $$RO$$Base);
REGION_DECLARE(Image$$, TFM_UNPRIV_CODE, $$RO$$Limit);
REGION_DECLARE(Image$$, TFM_UNPRIV_RO_DATA, $$RW$$Base);
REGION_DECLARE(Image$$, TFM_UNPRIV_RO_DATA, $$ZI$$Limit);
REGION_DECLARE(Image$$, TFM_UNPRIV_SCRATCH, $$ZI$$Base);
REGION_DECLARE(Image$$, TFM_UNPRIV_SCRATCH, $$ZI$$Limit);

static enum spm_err_t tfm_spm_mpu_init(void)
{
#if 0
    struct mpu_armv8m_region_cfg_t region_cfg;

    mpu_armv8m_clean(&dev_mpu_s);

    /* TFM Core unprivileged code region */
    region_cfg.region_nr = MPU_REGION_TFM_UNPRIV_CODE;
    region_cfg.region_base =
        (uint32_t)&REGION_NAME(Image$$, TFM_UNPRIV_CODE, $$RO$$Base);
    region_cfg.region_limit =
        (uint32_t)&REGION_NAME(Image$$, TFM_UNPRIV_CODE, $$RO$$Limit);
    region_cfg.attr_access = MPU_ARMV8M_AP_RO_PRIV_UNPRIV;
    region_cfg.attr_sh = MPU_ARMV8M_SH_NONE;
    region_cfg.attr_exec = MPU_ARMV8M_XN_EXEC_OK;
    if (mpu_armv8m_region_enable(&dev_mpu_s, &region_cfg) != MPU_ARMV8M_OK) {
        return SPM_ERR_INVALID_CONFIG;
    }

    /* TFM Core unprivileged data region */
    region_cfg.region_nr = MPU_REGION_TFM_UNPRIV_DATA;
    region_cfg.region_base =
        (uint32_t)&REGION_NAME(Image$$, TFM_UNPRIV_RO_DATA, $$RW$$Base);
    region_cfg.region_limit =
        (uint32_t)&REGION_NAME(Image$$, TFM_UNPRIV_RO_DATA, $$ZI$$Limit);
    region_cfg.attr_access = MPU_ARMV8M_AP_RO_PRIV_UNPRIV;
    region_cfg.attr_sh = MPU_ARMV8M_SH_NONE;
    region_cfg.attr_exec = MPU_ARMV8M_XN_EXEC_NEVER;
    if (mpu_armv8m_region_enable(&dev_mpu_s, &region_cfg) != MPU_ARMV8M_OK) {
        return SPM_ERR_INVALID_CONFIG;
    }

    /* TFM Core unprivileged non-secure data region */
    region_cfg.region_nr = MPU_REGION_NS_DATA;
    region_cfg.region_base = NS_DATA_START;
    region_cfg.region_limit = NS_DATA_LIMIT;
    region_cfg.attr_access = MPU_ARMV8M_AP_RW_PRIV_UNPRIV;
    region_cfg.attr_sh = MPU_ARMV8M_SH_NONE;
    region_cfg.attr_exec = MPU_ARMV8M_XN_EXEC_NEVER;
    if (mpu_armv8m_region_enable(&dev_mpu_s, &region_cfg) != MPU_ARMV8M_OK) {
        return SPM_ERR_INVALID_CONFIG;
    }

    mpu_armv8m_enable(&dev_mpu_s, PRIVILEGED_DEFAULT_ENABLE,
                      HARDFAULT_NMI_ENABLE);
#endif

    return SPM_ERR_OK;
}

enum spm_err_t tfm_spm_hal_partition_sandbox_config(
        const struct tfm_spm_partition_memory_data_t *memory_data,
        const struct tfm_spm_partition_platform_data_t *platform_data)
{
#if 0
    /* This function takes a partition id and enables the
     * SPM partition for that partition
     */

    struct mpu_armv8m_region_cfg_t region_cfg;

    mpu_armv8m_disable(&dev_mpu_s);

    /* Configure Regions */
    if (memory_data->ro_start) {
        /* RO region */
        region_cfg.region_nr = PARTITION_REGION_RO;
        region_cfg.region_base = memory_data->ro_start;
        region_cfg.region_limit = memory_data->ro_limit;
        region_cfg.attr_access = MPU_ARMV8M_AP_RO_PRIV_UNPRIV;
        region_cfg.attr_sh = MPU_ARMV8M_SH_NONE;
        region_cfg.attr_exec = MPU_ARMV8M_XN_EXEC_OK;

        if (mpu_armv8m_region_enable(&dev_mpu_s, &region_cfg)
            != MPU_ARMV8M_OK) {
            return SPM_ERR_INVALID_CONFIG;
        }
    }

    /* RW, ZI and stack as one region */
    region_cfg.region_nr = PARTITION_REGION_RW_STACK;
    region_cfg.region_base = memory_data->rw_start;
    region_cfg.region_limit = memory_data->stack_top;
    region_cfg.attr_access = MPU_ARMV8M_AP_RW_PRIV_UNPRIV;
    region_cfg.attr_sh = MPU_ARMV8M_SH_NONE;
    region_cfg.attr_exec = MPU_ARMV8M_XN_EXEC_NEVER;

    if (mpu_armv8m_region_enable(&dev_mpu_s, &region_cfg) != MPU_ARMV8M_OK) {
        return SPM_ERR_INVALID_CONFIG;
    }

    if (platform_data) {
        /* Peripheral */
        region_cfg.region_nr = PARTITION_REGION_PERIPH;
        region_cfg.region_base = platform_data->periph_start;
        region_cfg.region_limit = platform_data->periph_limit;
        region_cfg.attr_access = MPU_ARMV8M_AP_RW_PRIV_UNPRIV;
        region_cfg.attr_sh = MPU_ARMV8M_SH_NONE;
        region_cfg.attr_exec = MPU_ARMV8M_XN_EXEC_NEVER;
        if (mpu_armv8m_region_enable(&dev_mpu_s, &region_cfg)
            != MPU_ARMV8M_OK) {
            return SPM_ERR_INVALID_CONFIG;
        }

        ppc_en_secure_unpriv(platform_data->periph_ppc_bank,
                             platform_data->periph_ppc_loc);
    }

    mpu_armv8m_enable(&dev_mpu_s, PRIVILEGED_DEFAULT_ENABLE,
                      HARDFAULT_NMI_ENABLE);
#endif

    return SPM_ERR_OK;
}

enum tfm_plat_err_t tfm_spm_hal_setup_isolation_hw(void)
{
    if (tfm_spm_mpu_init() != SPM_ERR_OK) {
        ERROR_MSG("Failed to set up initial MPU configuration! Halting.");
        return TFM_PLAT_ERR_SYSTEM_ERR;
    }

    return TFM_PLAT_ERR_SUCCESS;
}
#endif /* TFM_LVL != 1 */

uint32_t tfm_spm_hal_get_ns_VTOR(void)
{
    return memory_regions.non_secure_code_start;
}

uint32_t tfm_spm_hal_get_ns_MSP(void)
{
    return *((uint32_t *)memory_regions.non_secure_code_start);
}

uint32_t tfm_spm_hal_get_ns_entry_point(void)
{
    return *((uint32_t *)(memory_regions.non_secure_code_start+ 4));
}

void tfm_spm_hal_boot_ns_cpu(uintptr_t start_addr)
{
    printf("Starting Cortex-M4 at 0x%x\r\n", start_addr);
    Cy_SysEnableCM4(start_addr);
}

void tfm_spm_hal_wait_for_ns_cpu_ready(void)
{
    uint32_t data;
    cy_en_ipcdrv_status_t status;

    Cy_IPC_Drv_SetInterruptMask(Cy_IPC_Drv_GetIntrBaseAddr(IPC_RX_INTR_STRUCT),
                                0, IPC_RX_INT_MASK);

    status = Cy_IPC_Drv_SendMsgWord(Cy_IPC_Drv_GetIpcBaseAddress(IPC_TX_CHAN),
                                 IPC_TX_NOTIFY_MASK, IPC_SYNC_MAGIC);
    while (1)
    {
        status = Cy_IPC_Drv_GetInterruptStatusMasked(
                        Cy_IPC_Drv_GetIntrBaseAddr(IPC_RX_INTR_STRUCT));
        status >>= CY_IPC_NOTIFY_SHIFT;
        if (status & IPC_RX_INT_MASK) {
            Cy_IPC_Drv_ClearInterrupt(Cy_IPC_Drv_GetIntrBaseAddr(
                                      IPC_RX_INTR_STRUCT),
                                      0, IPC_RX_INT_MASK);

            status = Cy_IPC_Drv_ReadMsgWord(Cy_IPC_Drv_GetIpcBaseAddress(
                                            IPC_RX_CHAN),
                                            &data);
            if (status == CY_IPC_DRV_SUCCESS) {
                Cy_IPC_Drv_ReleaseNotify(Cy_IPC_Drv_GetIpcBaseAddress(IPC_RX_CHAN),
                                         IPC_RX_RELEASE_MASK);
                if (data == ~IPC_SYNC_MAGIC) {
                    printf("Cores sync success.\r\n");
                    break;
                }
            }
        }
    }
}

enum tfm_plat_err_t tfm_spm_hal_set_secure_irq_priority(int32_t irq_line,
                                                        uint32_t priority)
{
    uint32_t quantized_priority = priority >> (8U - __NVIC_PRIO_BITS);
    NVIC_SetPriority(irq_line, quantized_priority);

    return TFM_PLAT_ERR_SUCCESS;
}

void tfm_spm_hal_get_mem_security_attr(const void *p, size_t s,
                                       struct security_attr_info_t *p_attr)
{
    /*
     * FIXME
     * Need to check if the memory region is valid according to platform
     * specific memory mapping.
     */

    /*
     * TODO
     * Currently only check static memory region layout to get security
     * information.
     * Check of hardware SMPU configuration can be added.
     */
    tfm_get_mem_region_security_attr(p, s, p_attr);
}

void tfm_spm_hal_get_secure_access_attr(const void *p, size_t s,
                                        struct mem_attr_info_t *p_attr)
{
    uint32_t pc;

    /*
     * FIXME
     * Need to check if the memory region is valid according to platform
     * specific memory mapping.
     */

    /*
     * TODO
     * Currently only check static memory region layout to get attributes.
     * Check of secure memory protection configuration from hardware can be
     * added.
     */
    tfm_get_secure_mem_region_attr(p, s, p_attr);

    pc = Cy_Prot_GetActivePC(CPUSS_MS_ID_CM0);
    /* Check whether the current active PC is configured as the expected one .*/
    if (pc == CY_PROT_SPM_DEFAULT) {
        p_attr->is_mpu_enabled = true;
    } else {
        p_attr->is_mpu_enabled = false;
    }
}

void tfm_spm_hal_get_ns_access_attr(const void *p, size_t s,
                                    struct mem_attr_info_t *p_attr)
{
    /*
     * FIXME
     * Need to check if the memory region is valid according to platform
     * specific memory mapping.
     */

    /*
     * TODO
     * Currently only check static memory region layout to get attributes.
     * Check of non-secure memory protection configuration from hardware can be
     * added.
     */
    tfm_get_ns_mem_region_attr(p, s, p_attr);
}

enum tfm_plat_err_t tfm_spm_hal_nvic_interrupt_enable(void)
{
    return nvic_interrupt_enable();
}

void tfm_spm_hal_clear_pending_irq(int32_t irq_line)
{
       (void)irq_line;
}

void tfm_spm_hal_enable_irq(int32_t irq_line)
{
    (void)irq_line;
}

void tfm_spm_hal_disable_irq(int32_t irq_line)
{
    (void)irq_line;
}

enum irq_target_state_t tfm_spm_hal_set_irq_target_state(
                                          int32_t irq_line,
                                          enum irq_target_state_t target_state)
{
    (void)irq_line;
    (void)target_state;

    return TFM_IRQ_TARGET_STATE_SECURE;
}

enum tfm_plat_err_t tfm_spm_hal_nvic_interrupt_target_state_cfg(void)
{
    return nvic_interrupt_target_state_cfg();
}

enum tfm_plat_err_t tfm_spm_hal_enable_fault_handlers(void)
{
    return TFM_PLAT_ERR_SUCCESS;
}

enum tfm_plat_err_t tfm_spm_hal_system_reset_cfg(void)
{
    return TFM_PLAT_ERR_SUCCESS;
}

enum tfm_plat_err_t tfm_spm_hal_init_debug(void)
{
    printf("%s()\n", __func__);

    return TFM_PLAT_ERR_SUCCESS;
}

enum tfm_plat_err_t tfm_spm_hal_post_platform_init(void)
{
    platform_init();
    __enable_irq();
    stdio_init();
    return TFM_PLAT_ERR_SUCCESS;
}
