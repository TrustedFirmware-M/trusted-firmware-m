/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 * Copyright (c) 2023 Cypress Semiconductor Corporation (an Infineon
 * company) or an affiliate of Cypress Semiconductor Corporation. All rights
 * reserved.
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

#include "tfm_hal_device_header.h"
#include "utilities.h"
#include "common_target_cfg.h"
#include "ppc_drv.h"
#include "Driver_MPC.h"
#include "region_defs.h"
#include "tfm_plat_defs.h"
#include "region.h"
#include "dma350_lib.h"
#include "device_definition.h"
#include "rse_sam_config.h"

/* Throw out bus error when an access causes security violation */
#define CMSDK_SECRESPCFG_BUS_ERR_MASK   (1UL)

#ifdef TFM_LOAD_NS_IMAGE
/* The section names come from the scatter file */
REGION_DECLARE(Load$$LR$$, LR_NS_PARTITION, $$Base);
#endif
#ifdef CONFIG_TFM_USE_TRUSTZONE
REGION_DECLARE(Image$$, ER_VENEER, $$Base);
REGION_DECLARE(Image$$, VENEER_ALIGN, $$Limit);
#endif

const struct memory_region_limits memory_regions = {
#ifdef TFM_LOAD_NS_IMAGE
#ifdef RSE_XIP
    .non_secure_code_start = RSE_RUNTIME_NS_XIP_BASE_NS,

    .non_secure_partition_base = RSE_RUNTIME_NS_XIP_BASE_NS,

    .non_secure_partition_limit = RSE_RUNTIME_NS_XIP_BASE_NS +
                                  NS_PARTITION_SIZE - 1,
#else
    .non_secure_code_start =
        (uint32_t)&REGION_NAME(Load$$LR$$, LR_NS_PARTITION, $$Base) +
        BL2_HEADER_SIZE,

    .non_secure_partition_base =
        (uint32_t)&REGION_NAME(Load$$LR$$, LR_NS_PARTITION, $$Base),

    .non_secure_partition_limit =
        (uint32_t)&REGION_NAME(Load$$LR$$, LR_NS_PARTITION, $$Base) +
        NS_PARTITION_SIZE - 1,
#endif /* RSE_XIP */
#endif /* TFM_LOAD_NS_IMAGE */

#ifdef CONFIG_TFM_USE_TRUSTZONE
    .veneer_base = (uint32_t)&REGION_NAME(Image$$, ER_VENEER, $$Base),
    .veneer_limit = (uint32_t)&REGION_NAME(Image$$, VENEER_ALIGN, $$Limit) - 1,
#endif
};

/* DMA350 checker layer has to know the TCM remaps */
/* Subordinate TCM Interface provides system access only to TCM internal to each
 * CPU. The memory map presented on the interface for TCM access are defined by
 * TRM. Below address remaps by adding offset provides access to respective
 * CPU instruction and data TCM.
 */

/* TCM memories addresses from perspective of cpu0
 * 0x0000_0000 .. 0x00ff_ffff    NS ITCM
 * 0x1000_0000 .. 0x10ff_ffff    S ITCM
 * 0x2000_0000 .. 0x20ff_ffff    NS DTCM
 * 0x3000_0000 .. 0x30ff_ffff    S DTCM
*/

const struct dma350_remap_range_t dma350_address_remap_list[] = {
    /* Non-secure CPU ITCM */
    {.begin = 0x00000000, .end = 0x00FFFFFF, .offset = 0x0A000000},
    /* Secure CPU ITCM */
    {.begin = 0x10000000, .end = 0x10FFFFFF, .offset = 0x0A000000},
    /* Non-secure CPU DTCM */
    {.begin = 0x20000000, .end = 0x20FFFFFF, .offset = 0x04000000},
    /* Secure CPU DTCM */
    {.begin = 0x30000000, .end = 0x30FFFFFF, .offset = 0x04000000}
};

const struct dma350_remap_list_t dma350_address_remap = {
    .size = sizeof(dma350_address_remap_list)/
            sizeof(dma350_address_remap_list[0]),
    .map = dma350_address_remap_list
};

/* Configures the RAM region to NS callable in sacfg block's nsccfg register */
#define RAMNSC  0x2
/* Configures the CODE region to NS callable in sacfg block's nsccfg register */
#define CODENSC  0x1

/* Import MPC drivers */
extern ARM_DRIVER_MPC Driver_VM0_MPC;
extern ARM_DRIVER_MPC Driver_VM1_MPC;
extern ARM_DRIVER_MPC Driver_SIC_MPC;

#ifdef TFM_LOAD_NS_IMAGE
/* Define Peripherals NS address range for the platform */
#define PERIPHERALS_BASE_NS_START      (0x40000000)
#define PERIPHERALS_BASE_NS_END        (0x4FFFFFFF)
#endif /* TFM_LOAD_NS_IMAGE */

/* Enable system reset request for CPU 0 */
#define ENABLE_CPU0_SYSTEM_RESET_REQUEST (1U << 8U)

/* To write into AIRCR register, 0x5FA value must be write to the VECTKEY field,
 * otherwise the processor ignores the write.
 */
#define SCB_AIRCR_WRITE_MASK ((0x5FAUL << SCB_AIRCR_VECTKEY_Pos))

/* Debug configuration flags */
#define SPNIDEN_SEL_STATUS (0x01u << 7)
#define SPNIDEN_STATUS     (0x01u << 6)
#define SPIDEN_SEL_STATUS  (0x01u << 5)
#define SPIDEN_STATUS      (0x01u << 4)
#define NIDEN_SEL_STATUS   (0x01u << 3)
#define NIDEN_STATUS       (0x01u << 2)
#define DBGEN_SEL_STATUS   (0x01u << 1)
#define DBGEN_STATUS       (0x01u << 0)

#define All_SEL_STATUS (SPNIDEN_SEL_STATUS | SPIDEN_SEL_STATUS | \
                        NIDEN_SEL_STATUS | DBGEN_SEL_STATUS)

static struct ppc_dev_t* const ppc_dev_bank[] = {
    &PPC_RSE_MAIN0_DEV_S,
    &PPC_RSE_MAIN_EXP0_DEV_S,
    &PPC_RSE_MAIN_EXP1_DEV_S,
    &PPC_RSE_MAIN_EXP2_DEV_S,
    &PPC_RSE_MAIN_EXP3_DEV_S,
    &PPC_RSE_PERIPH0_DEV_S,
    &PPC_RSE_PERIPH1_DEV_S,
    &PPC_RSE_PERIPH_EXP0_DEV_S,
    &PPC_RSE_PERIPH_EXP1_DEV_S,
    &PPC_RSE_PERIPH_EXP2_DEV_S,
    &PPC_RSE_PERIPH_EXP3_DEV_S
};

#define PPC_BANK_COUNT (sizeof(ppc_dev_bank)/sizeof(ppc_dev_bank[0]))

enum tfm_plat_err_t enable_fault_handlers(void)
{
    /* Explicitly set secure fault priority to the highest */
    NVIC_SetPriority(SecureFault_IRQn, 0);

    /* Enables BUS, MEM, USG and Secure faults */
    SCB->SHCSR |= SCB_SHCSR_USGFAULTENA_Msk
                  | SCB_SHCSR_BUSFAULTENA_Msk
                  | SCB_SHCSR_MEMFAULTENA_Msk
                  | SCB_SHCSR_SECUREFAULTENA_Msk;
    return TFM_PLAT_ERR_SUCCESS;
}

enum tfm_plat_err_t system_reset_cfg(void)
{
    struct rse_sysctrl_t *sysctrl = (struct rse_sysctrl_t *)RSE_SYSCTRL_BASE_S;
    uint32_t reg_value = SCB->AIRCR;

    /* Enable system reset request for CPU 0, to be triggered via
     * NVIC_SystemReset function.
     */
    sysctrl->reset_mask |= ENABLE_CPU0_SYSTEM_RESET_REQUEST;

    /* Clear SCB_AIRCR_VECTKEY value */
    reg_value &= ~(uint32_t)(SCB_AIRCR_VECTKEY_Msk);

    /* Enable system reset request only to the secure world */
    reg_value |= (uint32_t)(SCB_AIRCR_WRITE_MASK | SCB_AIRCR_SYSRESETREQS_Msk);

    SCB->AIRCR = reg_value;

    return TFM_PLAT_ERR_SUCCESS;
}

/*--------------------- NVIC interrupt NS/S configuration --------------------*/
enum tfm_plat_err_t nvic_interrupt_target_state_cfg(void)
{
    uint8_t i;

    /* Target every interrupt to NS; unimplemented interrupts will be WI */
    for (i = 0; i < (sizeof(NVIC->ITNS) / sizeof(NVIC->ITNS[0])); i++) {
        NVIC->ITNS[i] = 0xFFFFFFFF;
    }

    /* Make sure that MPC and PPC are targeted to S state */
    NVIC_ClearTargetState(MPC_IRQn);
    NVIC_ClearTargetState(PPC_IRQn);

    /* Make sure that SAM interrupts target S state */
    NVIC_ClearTargetState(SAM_Critical_Sec_Fault_S_IRQn);
    NVIC_ClearTargetState(SAM_Sec_Fault_S_IRQn);
    NVIC_ClearTargetState(SRAM_TRAM_ECC_Err_S_IRQn);
    NVIC_ClearTargetState(SRAM_ECC_Partial_Write_S_IRQn);

    return TFM_PLAT_ERR_SUCCESS;
}

/*----------------- NVIC interrupt enabling for S peripherals ----------------*/
enum tfm_plat_err_t nvic_interrupt_enable(void)
{
    int32_t ret = ARM_DRIVER_OK;
    int32_t i = 0;

    /* MPC interrupt enabling */
    mpc_clear_irq();

    ret = Driver_VM0_MPC.EnableInterrupt();
    if (ret != ARM_DRIVER_OK) {
        ERROR_MSG("Failed to Enable MPC interrupt for VM0!");
        return TFM_PLAT_ERR_SYSTEM_ERR;
    }

    ret = Driver_VM1_MPC.EnableInterrupt();
    if (ret != ARM_DRIVER_OK) {
        ERROR_MSG("Failed to Enable MPC interrupt for VM1!");
        return TFM_PLAT_ERR_SYSTEM_ERR;
    }

    NVIC_ClearPendingIRQ(MPC_IRQn);
    NVIC_EnableIRQ(MPC_IRQn);

    /* PPC interrupt enabling */
    ppc_clear_irq();

    for (i = 0; i < PPC_BANK_COUNT; i++) {
        ppc_irq_enable(ppc_dev_bank[i]);
    }

    NVIC_ClearPendingIRQ(PPC_IRQn);
    NVIC_EnableIRQ(PPC_IRQn);

    ret = rse_sam_init(RSE_SAM_INIT_SETUP_FULL);
    if (ret) {
        return TFM_PLAT_ERR_SYSTEM_ERR;
    }

    return TFM_PLAT_ERR_SUCCESS;
}

enum tfm_plat_err_t init_debug(void)
{
    struct rse_sysctrl_t *sysctrl = (struct rse_sysctrl_t *)RSE_SYSCTRL_BASE_S;

#if defined(DAUTH_NONE)
    /* Set all the debug enable selector bits to 1 */
    sysctrl->secdbgset = All_SEL_STATUS;
    /* Set all the debug enable bits to 0 */
    sysctrl->secdbgclr =
                   DBGEN_STATUS | NIDEN_STATUS | SPIDEN_STATUS | SPNIDEN_STATUS;
#elif defined(DAUTH_NS_ONLY)
    /* Set all the debug enable selector bits to 1 */
    sysctrl->secdbgset = All_SEL_STATUS;
    /* Set the debug enable bits to 1 for NS, and 0 for S mode */
    sysctrl->secdbgset = DBGEN_STATUS | NIDEN_STATUS;
    sysctrl->secdbgclr = SPIDEN_STATUS | SPNIDEN_STATUS;
#elif defined(DAUTH_FULL)
    /* Set all the debug enable selector bits to 1 */
    sysctrl->secdbgset = All_SEL_STATUS;
    /* Set all the debug enable bits to 1 */
    sysctrl->secdbgset =
                   DBGEN_STATUS | NIDEN_STATUS | SPIDEN_STATUS | SPNIDEN_STATUS;
#else

#if !defined(DAUTH_CHIP_DEFAULT)
#error "No debug authentication setting is provided."
#endif

    /* Set all the debug enable selector bits to 0 */
    sysctrl->secdbgclr = All_SEL_STATUS;

    /* No need to set any enable bits because the value depends on
     * input signals.
     */
#endif
    return TFM_PLAT_ERR_SUCCESS;
}

/*------------------- SAU/IDAU configuration functions -----------------------*/
void sau_and_idau_cfg(void)
{
    struct rse_sacfg_t *sacfg = (struct rse_sacfg_t *)RSE_SACFG_BASE_S;
    struct cpu0_secctrl_t *secctrl = (struct cpu0_secctrl_t *)CPU0_SECCTRL_BASE_S;

    /* Ensure all memory accesses are completed */
    __DMB();

    /* Enables SAU */
    TZ_SAU_Enable();

#ifdef TFM_LOAD_NS_IMAGE
    /* Configures SAU regions to be non-secure */
    SAU->RNR  = 0;
    SAU->RBAR = (memory_regions.non_secure_partition_base
                 & SAU_RBAR_BADDR_Msk);
    SAU->RLAR = (memory_regions.non_secure_partition_limit
                  & SAU_RLAR_LADDR_Msk) | SAU_RLAR_ENABLE_Msk;

    SAU->RNR  = 1;
    SAU->RBAR = (NS_DATA_START & SAU_RBAR_BADDR_Msk);
    SAU->RLAR = (NS_DATA_LIMIT & SAU_RLAR_LADDR_Msk) | SAU_RLAR_ENABLE_Msk;

#ifdef CONFIG_TFM_USE_TRUSTZONE
    /* Configures veneers region to be non-secure callable */
    SAU->RNR  = 2;
    SAU->RBAR = (memory_regions.veneer_base & SAU_RBAR_BADDR_Msk);
    SAU->RLAR = (memory_regions.veneer_limit & SAU_RLAR_LADDR_Msk)
                 | SAU_RLAR_ENABLE_Msk | SAU_RLAR_NSC_Msk;
#endif

    /* Configure the peripherals space */
    SAU->RNR  = 3;
    SAU->RBAR = (PERIPHERALS_BASE_NS_START & SAU_RBAR_BADDR_Msk);
    SAU->RLAR = (PERIPHERALS_BASE_NS_END & SAU_RLAR_LADDR_Msk)
                  | SAU_RLAR_ENABLE_Msk;

    /* Configure the host access space */
    SAU->RNR  = 4;
    SAU->RBAR = (HOST_ACCESS_BASE_NS & SAU_RBAR_BADDR_Msk);
    SAU->RLAR = (HOST_ACCESS_LIMIT_NS & SAU_RLAR_LADDR_Msk)
                  | SAU_RLAR_ENABLE_Msk;

    /* Allows SAU to define the CODE region as NSC when XIP is enabled or the
     * RAM region otherwise
     */
#ifdef RSE_XIP
    sacfg->nsccfg |= CODENSC;
#else
    sacfg->nsccfg |= RAMNSC;
#endif
#endif /* TFM_LOAD_NS_IMAGE */

    /* Configure MSC to enable secure accesses for the DMA */
    sacfg->nsmscexp = 0x0;

    /* Ensure the write is completed and flush pipeline */
    __DSB();
    __ISB();

    /* Lock down SAU registers to prevent further changes */
    secctrl->cpuseccfg |= CPUSECCFG_LOCKSAU_POS_MASK;
}

static int32_t init_mpc_region_for_required_vms(uintptr_t base, uintptr_t limit,
                                                enum _ARM_MPC_SEC_ATTR attr)
{
    int32_t ret = ARM_DRIVER_OK;
    const bool is_ns = (attr == ARM_MPC_ATTR_NONSECURE);
    const uintptr_t vm1_base = is_ns ? VM1_BASE_NS : VM1_BASE_S;

    /* Force the addresses to be S ones */
    if (is_ns) {
        if ((base & 0x10000000) != 0 || (limit & 0x10000000) != 0) {
            return ARM_DRIVER_ERROR_PARAMETER;
        }
    } else {
        if ((base & 0x10000000) == 0 || (limit & 0x10000000) == 0) {
            return ARM_DRIVER_ERROR_PARAMETER;
        }
    }

    const uintptr_t vm0_start = base < vm1_base ? base : 0;
    const uintptr_t vm0_end   = limit < vm1_base ? limit : vm1_base - 1;
    const uintptr_t vm1_start = base < vm1_base ? vm1_base : base;
    const uintptr_t vm1_end   = limit < vm1_base ? 0 : limit;

    if (vm0_start != 0) {
        ret = Driver_VM0_MPC.ConfigRegion(vm0_start, vm0_end, attr);
        if (ret != ARM_DRIVER_OK) {
            return ret;
        }
    }

    if (vm1_end != 0) {
        ret = Driver_VM1_MPC.ConfigRegion(vm1_start, vm1_end, attr);
        if (ret != ARM_DRIVER_OK) {
            return ret;
        }
    }

    return ret;
}

/*------------------- Memory configuration functions -------------------------*/
enum tfm_plat_err_t mpc_init_cfg(void)
{
    int32_t ret = ARM_DRIVER_OK;
    struct cpu0_secctrl_t *secctrl = (struct cpu0_secctrl_t *)CPU0_SECCTRL_BASE_S;

    /* TCM config is left as default (all Secure, faults enabled) */
    /* Lock down TCM config registers to prevent further changes */
    secctrl->cpuseccfg |= CPUSECCFG_LOCKTCM_POS_MASK |
                          CPUSECCFG_LOCKITGU_POS_MASK |
                          CPUSECCFG_LOCKDTGU_POS_MASK;

    ret = Driver_VM0_MPC.Initialize();
    if (ret != ARM_DRIVER_OK) {
        return TFM_PLAT_ERR_SYSTEM_ERR;
    }
    ret = Driver_VM1_MPC.Initialize();
    if (ret != ARM_DRIVER_OK) {
        return TFM_PLAT_ERR_SYSTEM_ERR;
    }
#ifdef RSE_XIP
    ret = Driver_SIC_MPC.Initialize();
    if (ret != ARM_DRIVER_OK) {
        return TFM_PLAT_ERR_SYSTEM_ERR;
    }
#endif /* RSE_XIP */

#ifdef TFM_LOAD_NS_IMAGE
    /* Configuring NS Data. It might be in VM0, VM1 or in spanning both. */
    ret = init_mpc_region_for_required_vms(NS_DATA_START, NS_DATA_LIMIT,
                                           ARM_MPC_ATTR_NONSECURE);

#ifdef RSE_XIP
    ret = Driver_SIC_MPC.ConfigRegion(memory_regions.non_secure_partition_base,
                                      memory_regions.non_secure_partition_limit,
                                      ARM_MPC_ATTR_NONSECURE);
#else
    /* Configuring NS Code. It might be in VM0, VM1 or in spanning both. */
    ret = init_mpc_region_for_required_vms(memory_regions.non_secure_partition_base,
                                           memory_regions.non_secure_partition_limit,
                                           ARM_MPC_ATTR_NONSECURE);
#endif /* !RSE_XIP */
    if (ret != ARM_DRIVER_OK) {
        return TFM_PLAT_ERR_SYSTEM_ERR;
    }
#endif /* TFM_LOAD_NS_IMAGE */

    /* Lock down the MPC configuration */
    ret = Driver_VM0_MPC.LockDown();
    if (ret != ARM_DRIVER_OK) {
        return ret;
    }

    ret = Driver_VM1_MPC.LockDown();
    if (ret != ARM_DRIVER_OK) {
        return ret;
    }
#ifdef RSE_XIP
    ret = Driver_SIC_MPC.LockDown();
    if (ret != ARM_DRIVER_OK) {
        return ret;
    }
#endif /* RSE_XIP */

    /* Add barriers to assure the MPC configuration is done before continue
     * the execution.
     */
    __DSB();
    __ISB();

    return TFM_PLAT_ERR_SUCCESS;
}

void mpc_clear_irq(void)
{
    Driver_VM0_MPC.ClearInterrupt();
    Driver_VM1_MPC.ClearInterrupt();
#ifdef RSE_XIP
    Driver_SIC_MPC.ClearInterrupt();
#endif /* RSE_XIP */
}

/*------------------- PPC configuration functions -------------------------*/
enum tfm_plat_err_t ppc_init_cfg(void)
{
    struct rse_sacfg_t *sacfg = (struct rse_sacfg_t *)RSE_SACFG_BASE_S;

    /*
     * Configure the response to a security violation as a
     * bus error instead of RAZ/WI
     */
    sacfg->secrespcfg |= CMSDK_SECRESPCFG_BUS_ERR_MASK;

    return TFM_PLAT_ERR_SUCCESS;
}

void ppc_configure_to_secure(ppc_bank_t bank, uint32_t pos)
{
    if (bank >= PPC_BANK_COUNT) {
        return;
    }

    if (ppc_dev_bank[bank]) {
        ppc_config_security(ppc_dev_bank[bank], pos, PPC_SECURE_ACCESS);
    }
}

void ppc_configure_to_non_secure(ppc_bank_t bank, uint32_t pos)
{
    if (bank >= PPC_BANK_COUNT) {
        return;
    }
     if (ppc_dev_bank[bank]) {
        ppc_config_security(ppc_dev_bank[bank], pos, PPC_NONSECURE_ACCESS);
    }
}

void ppc_en_secure_unpriv(ppc_bank_t bank, uint32_t pos)
{
    if (bank >= PPC_BANK_COUNT) {
        return;
    }

    if (ppc_dev_bank[bank]) {
        ppc_config_privilege(ppc_dev_bank[bank],
                             pos,
                             PPC_SECURE_ACCESS,
                             PPC_PRIV_AND_NONPRIV_ACCESS);
    }
}

void ppc_clr_secure_unpriv(ppc_bank_t bank, uint32_t pos)
{
    if (bank >= PPC_BANK_COUNT) {
        return;
    }

    if (ppc_dev_bank[bank]) {
        ppc_config_privilege(ppc_dev_bank[bank],
                             pos,
                             PPC_SECURE_ACCESS,
                             PPC_PRIV_ONLY_ACCESS);
    }
}

void ppc_clear_irq(void)
{
    int32_t i = 0;

    for (i = 0; i < PPC_BANK_COUNT; i++) {
        if (ppc_dev_bank[i]) {
            ppc_clr_irq(ppc_dev_bank[i]);
        }
    }
}

static struct dma350_ch_dev_t *const dma350_channel_list[DMA350_DMA0_CHANNEL_COUNT] = {
    &DMA350_DMA0_CH0_DEV_S,
    &DMA350_DMA0_CH1_DEV_S,
    &DMA350_DMA0_CH2_DEV_S,
    &DMA350_DMA0_CH3_DEV_S
};

/*------------------- DMA configuration functions -------------------------*/
enum tfm_plat_err_t dma_init_cfg(void)
{
    enum dma350_error_t dma_err;
    enum dma350_ch_error_t ch_err;
    struct dma350_ch_dev_t *dma_ch_ptr;
    int32_t i;

    dma_err = dma350_init(&DMA350_DMA0_DEV_S);
    if(dma_err != DMA350_ERR_NONE) {
        ERROR_MSG("DMA350_DMA0_DEV_S init failed!");
        return TFM_PLAT_ERR_SYSTEM_ERR;
    }

    /* Initialise and set all available DMA channels to privilege and secure */
    for (i = 0; i < DMA350_DMA0_CHANNEL_COUNT; i++) {
        dma_ch_ptr = dma350_channel_list[i];

        ch_err = dma350_ch_init(dma_ch_ptr);
        if(ch_err != DMA350_CH_ERR_NONE) {
            ERROR_MSG("DMA350 channel init failed");
            return TFM_PLAT_ERR_SYSTEM_ERR;
        }

        dma_err = dma350_set_ch_privileged(&DMA350_DMA0_DEV_S, i);
        if(dma_err != DMA350_ERR_NONE) {
            ERROR_MSG("Failed to set DMA350 channel privileged!");
            return TFM_PLAT_ERR_SYSTEM_ERR;
        }

        dma_err = dma350_set_ch_secure(&DMA350_DMA0_DEV_S, i);
        if(dma_err != DMA350_ERR_NONE) {
            ERROR_MSG("Failed to set DMA350 channel secure!");
            return TFM_PLAT_ERR_SYSTEM_ERR;
        }
    }

    /* FIXME: Use combined secure interrupt because there are no channel IRQs */
    DMA350_DMA0_DEV_S.cfg->dma_sec_ctrl->SEC_CTRL |= 0x1UL; /* INTREN_ANYCHINTR */
    DMA350_DMA0_DEV_S.cfg->dma_nsec_ctrl->NSEC_CTRL |= 0x1UL; /* INTREN_ANYCHINTR */

    return TFM_PLAT_ERR_SUCCESS;
}
