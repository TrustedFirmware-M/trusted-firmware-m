/*
 * Copyright (c) 2017-2018 ARM Limited
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

#include "cmsis.h"
#include "target_cfg.h"
#include "Driver_MPC.h"
#include "platform_retarget_dev.h"
#include "region_defs.h"
#include "tfm_secure_api.h"

/* Macros to pick linker symbols */
#define REGION(a, b, c) a##b##c
#define REGION_NAME(a, b, c) REGION(a, b, c)
#define REGION_DECLARE(a, b, c) extern uint32_t REGION_NAME(a, b, c)

/* The section names come from the scatter file */
REGION_DECLARE(Load$$LR$$, LR_NS_PARTITION, $$Base);
REGION_DECLARE(Load$$LR$$, LR_VENEER, $$Base);
REGION_DECLARE(Load$$LR$$, LR_VENEER, $$Limit);
#ifdef BL2
REGION_DECLARE(Load$$LR$$, LR_SECONDARY_PARTITION, $$Base);
#endif /* BL2 */

const struct memory_region_limits memory_regions = {
    .non_secure_code_start =
        (uint32_t)&REGION_NAME(Load$$LR$$, LR_NS_PARTITION, $$Base) +
        BL2_HEADER_SIZE,

    .non_secure_partition_base =
        (uint32_t)&REGION_NAME(Load$$LR$$, LR_NS_PARTITION, $$Base),

    .non_secure_partition_limit =
        (uint32_t)&REGION_NAME(Load$$LR$$, LR_NS_PARTITION, $$Base) +
        NS_PARTITION_SIZE - 1,

    .veneer_base =
        (uint32_t)&REGION_NAME(Load$$LR$$, LR_VENEER, $$Base),

    .veneer_limit =
        (uint32_t)&REGION_NAME(Load$$LR$$, LR_VENEER, $$Limit),

#ifdef BL2
    .secondary_partition_base =
        (uint32_t)&REGION_NAME(Load$$LR$$, LR_SECONDARY_PARTITION, $$Base),

    .secondary_partition_limit =
        (uint32_t)&REGION_NAME(Load$$LR$$, LR_SECONDARY_PARTITION, $$Base) +
        SECONDARY_PARTITION_SIZE - 1,
#endif /* BL2 */
};

/* Allows software, via SAU, to define the code region as a NSC */
#define NSCCFG_CODENSC  1

/* Import MPC driver */
extern ARM_DRIVER_MPC Driver_SRAM1_MPC, Driver_SRAM2_MPC;

/* Define Peripherals NS address range for the platform */
#define PERIPHERALS_BASE_NS_START (0x40000000)
#define PERIPHERALS_BASE_NS_END   (0x4FFFFFFF)

/* Enable system reset request for CPU 0 */
#define ENABLE_CPU0_SYSTEM_RESET_REQUEST (1U << 4U)

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

struct tfm_spm_partition_platform_data_t tfm_peripheral_std_uart = {
        UART0_BASE_NS,
        UART0_BASE_NS + 0xFFF,
        PPC_SP_DO_NOT_CONFIGURE,
        -1
};

struct tfm_spm_partition_platform_data_t tfm_peripheral_uart1 = {
        UART1_BASE_S,
        UART1_BASE_S + 0xFFF,
        PPC_SP_APB_PPC_EXP1,
        CMSDK_UART1_APB_PPC_POS
};

struct tfm_spm_partition_platform_data_t tfm_peripheral_fpga_io = {
        MPS2_IO_FPGAIO_BASE_S,
        MPS2_IO_FPGAIO_BASE_S + 0xFFF,
        PPC_SP_APB_PPC_EXP2,
        CMSDK_FPGA_IO_PPC_POS
};

void enable_fault_handlers(void)
{
    /* Explicitly set secure fault priority to the highest */
    NVIC_SetPriority(SecureFault_IRQn, 0);

    /* Enables BUS, MEM, USG and Secure faults */
    SCB->SHCSR |= SCB_SHCSR_USGFAULTENA_Msk
                  | SCB_SHCSR_BUSFAULTENA_Msk
                  | SCB_SHCSR_MEMFAULTENA_Msk
                  | SCB_SHCSR_SECUREFAULTENA_Msk;
}

void system_reset_cfg(void)
{
    struct sysctrl_t *sysctrl = (struct sysctrl_t *)CMSDK_SYSCTRL_BASE_S;
    uint32_t reg_value = SCB->AIRCR;

    /* Enable system reset request for CPU 0, to be triggered via
     * NVIC_SystemReset function.
     */
    sysctrl->resetmask |= ENABLE_CPU0_SYSTEM_RESET_REQUEST;

    /* Clear SCB_AIRCR_VECTKEY value */
    reg_value &= ~(uint32_t)(SCB_AIRCR_VECTKEY_Msk);

    /* Enable system reset request only to the secure world */
    reg_value |= (uint32_t)(SCB_AIRCR_WRITE_MASK | SCB_AIRCR_SYSRESETREQS_Msk);

    SCB->AIRCR = reg_value;
}

void tfm_spm_hal_init_debug(void)
{
    volatile struct sysctrl_t *sys_ctrl =
                                       (struct sysctrl_t *)CMSDK_SYSCTRL_BASE_S;

#if defined(DAUTH_NONE)
    /* Set all the debug enable selector bits to 1 */
    sys_ctrl->secdbgset = All_SEL_STATUS;
    /* Set all the debug enable bits to 0 */
    sys_ctrl->secdbgclr =
                   DBGEN_STATUS | NIDEN_STATUS | SPIDEN_STATUS | SPNIDEN_STATUS;
#elif defined(DAUTH_NS_ONLY)
    /* Set all the debug enable selector bits to 1 */
    sys_ctrl->secdbgset = All_SEL_STATUS;
    /* Set the debug enable bits to 1 for NS, and 0 for S mode */
    sys_ctrl->secdbgset = DBGEN_STATUS | NIDEN_STATUS;
    sys_ctrl->secdbgclr = SPIDEN_STATUS | SPNIDEN_STATUS;
#elif defined(DAUTH_FULL)
    /* Set all the debug enable selector bits to 1 */
    sys_ctrl->secdbgset = All_SEL_STATUS;
    /* Set all the debug enable bits to 1 */
    sys_ctrl->secdbgset =
                   DBGEN_STATUS | NIDEN_STATUS | SPIDEN_STATUS | SPNIDEN_STATUS;
#else

#if !defined(DAUTH_CHIP_DEFAULT)
#error "No debug authentication setting is provided."
#endif

    /* Set all the debug enable selector bits to 0 */
    sys_ctrl->secdbgclr = All_SEL_STATUS;

    /* No need to set any enable bits because the value depends on
     * input signals.
     */
#endif
}

/*----------------- NVIC interrupt target state to NS configuration ----------*/
void nvic_interrupt_target_state_cfg()
{
    /* Target every interrupt to NS; unimplemented interrupts will be WI */
    for (uint8_t i=0; i<sizeof(NVIC->ITNS)/sizeof(NVIC->ITNS[0]); i++) {
        NVIC->ITNS[i] = 0xFFFFFFFF;
    }

    /* Make sure that MPC and PPC are targeted to S state */
    NVIC_ClearTargetState(MPC_IRQn);
    NVIC_ClearTargetState(PPC_IRQn);

#ifdef SECURE_UART1
    /* UART1 is a secure peripheral, so its IRQs have to target S state */
    NVIC_ClearTargetState(UARTRX1_IRQn);
    NVIC_ClearTargetState(UARTTX1_IRQn);
    NVIC_ClearTargetState(UART1_IRQn);
#endif
}

/*----------------- NVIC interrupt enabling for S peripherals ----------------*/
void nvic_interrupt_enable()
{
    struct spctrl_def* spctrl = CMSDK_SPCTRL;

    /* MPC interrupt enabling */
    Driver_SRAM1_MPC.EnableInterrupt();
    Driver_SRAM2_MPC.EnableInterrupt();
    NVIC_EnableIRQ(MPC_IRQn);

    /* PPC interrupt enabling */
    /* Clear pending PPC interrupts */
    /* In the PPC configuration function, we have used the Non-Secure
     * Privilege Control Block to grant unprivilged NS access to some
     * peripherals used by NS. That triggers a PPC0 exception as that
     * register is meant for NS privileged access only. Clear it here
     */
    spctrl->secppcintclr = CMSDK_APB_PPC0_INT_POS_MASK;

    /* Enable PPC interrupts for APB PPC */
    spctrl->secppcinten |= CMSDK_APB_PPC0_INT_POS_MASK;
    spctrl->secppcinten |= CMSDK_APB_PPC1_INT_POS_MASK;
    spctrl->secppcinten |= CMSDK_APB_PPCEXP0_INT_POS_MASK;
    spctrl->secppcinten |= CMSDK_APB_PPCEXP1_INT_POS_MASK;
    spctrl->secppcinten |= CMSDK_APB_PPCEXP2_INT_POS_MASK;
    spctrl->secppcinten |= CMSDK_APB_PPCEXP3_INT_POS_MASK;
    NVIC_EnableIRQ(PPC_IRQn);
}

/*------------------- SAU/IDAU configuration functions -----------------------*/

void sau_and_idau_cfg(void)
{
    /* Enables SAU */
    TZ_SAU_Enable();

    /* Configures SAU regions to be non-secure */
    SAU->RNR  = TFM_NS_REGION_CODE;
    SAU->RBAR = (memory_regions.non_secure_partition_base
                & SAU_RBAR_BADDR_Msk);
    SAU->RLAR = (memory_regions.non_secure_partition_limit
                & SAU_RLAR_LADDR_Msk)
                | SAU_RLAR_ENABLE_Msk;


    SAU->RNR  = TFM_NS_REGION_DATA;
    SAU->RBAR = (NS_DATA_START & SAU_RBAR_BADDR_Msk);
    SAU->RLAR = (NS_DATA_LIMIT & SAU_RLAR_LADDR_Msk) | SAU_RLAR_ENABLE_Msk;

    /* Configures veneers region to be non-secure callable */
    SAU->RNR  = TFM_NS_REGION_VENEER;
    SAU->RBAR = (memory_regions.veneer_base  & SAU_RBAR_BADDR_Msk);
    SAU->RLAR = (memory_regions.veneer_limit & SAU_RLAR_LADDR_Msk)
                | SAU_RLAR_ENABLE_Msk
                | SAU_RLAR_NSC_Msk;

    /* Configure the peripherals space */
    /* Only UART1 is configured as a secure peripheral */
    SAU->RNR  = TFM_NS_REGION_PERIPH_1;
    SAU->RBAR = (PERIPHERALS_BASE_NS_START & SAU_RBAR_BADDR_Msk);

#ifdef SECURE_UART1
    /* To statically configure a peripheral range as secure, close NS peripheral
     * region before range, and open a new NS region after the reserved space.
     */
    SAU->RLAR = ((UART1_BASE_NS-1) & SAU_RLAR_LADDR_Msk)
                | SAU_RLAR_ENABLE_Msk;

    SAU->RNR  = TFM_NS_REGION_PERIPH_2;
    SAU->RBAR = (UART2_BASE_NS & SAU_RBAR_BADDR_Msk);
#endif

    SAU->RLAR = (PERIPHERALS_BASE_NS_END & SAU_RLAR_LADDR_Msk)
                | SAU_RLAR_ENABLE_Msk;

#ifdef BL2
    /* Secondary image partition */
    SAU->RNR  = TFM_NS_SECONDARY_IMAGE_REGION;
    SAU->RBAR = (memory_regions.secondary_partition_base  & SAU_RBAR_BADDR_Msk);
    SAU->RLAR = (memory_regions.secondary_partition_limit & SAU_RLAR_LADDR_Msk)
                | SAU_RLAR_ENABLE_Msk;
#endif /* BL2 */

    /* Allows SAU to define the code region as a NSC */
    struct spctrl_def* spctrl = CMSDK_SPCTRL;
    spctrl->nsccfg |= NSCCFG_CODENSC;
}

/*------------------- Memory configuration functions -------------------------*/

void mpc_init_cfg(void)
{
    Driver_SRAM1_MPC.Initialize();
    Driver_SRAM1_MPC.ConfigRegion(memory_regions.non_secure_partition_base,
                                  memory_regions.non_secure_partition_limit,
                                  ARM_MPC_ATTR_NONSECURE);

#ifdef BL2
    /* Secondary image region */
    Driver_SRAM1_MPC.ConfigRegion(memory_regions.secondary_partition_base,
                                  memory_regions.secondary_partition_limit,
                                  ARM_MPC_ATTR_NONSECURE);
#endif /* BL2 */

    Driver_SRAM2_MPC.Initialize();
    Driver_SRAM2_MPC.ConfigRegion(NS_DATA_START, NS_DATA_LIMIT,
                                  ARM_MPC_ATTR_NONSECURE);

    /* Lock down the MPC configuration */
    Driver_SRAM1_MPC.LockDown();
    Driver_SRAM2_MPC.LockDown();

    /* Add barriers to assure the MPC configuration is done before continue
     * the execution.
     */
    __DSB();
    __ISB();
}

/*---------------------- PPC configuration functions -------------------------*/

void ppc_init_cfg(void)
{
    struct spctrl_def* spctrl = CMSDK_SPCTRL;
    struct nspctrl_def* nspctrl = CMSDK_NSPCTRL;

    /* Grant non-secure access to peripherals in the PPC0
     * (timer0 and 1, dualtimer, watchdog, mhu 0 and 1)
     */
    spctrl->apbnsppc0 |= (1U << CMSDK_TIMER0_APB_PPC_POS);
    spctrl->apbnsppc0 |= (1U << CMSDK_TIMER1_APB_PPC_POS);
    spctrl->apbnsppc0 |= (1U << CMSDK_DTIMER_APB_PPC_POS);
    spctrl->apbnsppc0 |= (1U << CMSDK_MHU0_APB_PPC_POS);
    spctrl->apbnsppc0 |= (1U << CMSDK_MHU1_APB_PPC_POS);
    /* Grant non-secure access to S32K Timer in PPC1*/
    spctrl->apbnsppc1 |= (1U << CMSDK_S32K_TIMER_PPC_POS);
    /* Grant non-secure access for APB peripherals on EXP1 */
    spctrl->apbnsppcexp1 |= (1U << CMSDK_SPI0_APB_PPC_POS);
    spctrl->apbnsppcexp1 |= (1U << CMSDK_SPI1_APB_PPC_POS);
    spctrl->apbnsppcexp1 |= (1U << CMSDK_SPI2_APB_PPC_POS);
    spctrl->apbnsppcexp1 |= (1U << CMSDK_SPI3_APB_PPC_POS);
    spctrl->apbnsppcexp1 |= (1U << CMSDK_SPI4_APB_PPC_POS);
    spctrl->apbnsppcexp1 |= (1U << CMSDK_UART0_APB_PPC_POS);
#ifdef SECURE_UART1
    /* To statically configure a peripheral as secure, skip PPC NS peripheral
     * configuration for the given device.
     */
#else
    spctrl->apbnsppcexp1 |= (1U << CMSDK_UART1_APB_PPC_POS);
#endif
    spctrl->apbnsppcexp1 |= (1U << CMSDK_UART2_APB_PPC_POS);
    spctrl->apbnsppcexp1 |= (1U << CMSDK_UART3_APB_PPC_POS);
    spctrl->apbnsppcexp1 |= (1U << CMSDK_UART4_APB_PPC_POS);
    spctrl->apbnsppcexp1 |= (1U << CMSDK_I2C0_APB_PPC_POS);
    spctrl->apbnsppcexp1 |= (1U << CMSDK_I2C1_APB_PPC_POS);
    spctrl->apbnsppcexp1 |= (1U << CMSDK_I2C2_APB_PPC_POS);
    spctrl->apbnsppcexp1 |= (1U << CMSDK_I2C3_APB_PPC_POS);
    /* Grant non-secure access for APB peripherals on EXP2 */
    spctrl->apbnsppcexp2 |= (1U << CMSDK_FPGA_SCC_PPC_POS);
    spctrl->apbnsppcexp2 |= (1U << CMSDK_FPGA_AUDIO_PPC_POS);
    spctrl->apbnsppcexp2 |= (1U << CMSDK_FPGA_IO_PPC_POS);

    /* Grant non-secure access to all peripherals on AHB EXP:
     * Make sure that all possible peripherals are enabled by default
     */
    spctrl->ahbnsppcexp0 |= (1U << CMSDK_VGA_PPC_POS);
    spctrl->ahbnsppcexp0 |= (1U << CMSDK_GPIO0_PPC_POS);
    spctrl->ahbnsppcexp0 |= (1U << CMSDK_GPIO1_PPC_POS);
    spctrl->ahbnsppcexp0 |= (1U << CMSDK_GPIO2_PPC_POS);
    spctrl->ahbnsppcexp0 |= (1U << CMSDK_GPIO3_PPC_POS);
    spctrl->ahbnsppcexp0 |= (1U << MPS2_ETHERNET_PPC_POS);

    spctrl->ahbnsppcexp1 |= (1U << CMSDK_DMA0_PPC_POS);
    spctrl->ahbnsppcexp1 |= (1U << CMSDK_DMA1_PPC_POS);
    spctrl->ahbnsppcexp1 |= (1U << CMSDK_DMA2_PPC_POS);
    spctrl->ahbnsppcexp1 |= (1U << CMSDK_DMA3_PPC_POS);

    /* in NS, grant un-privileged for UART0 */
    nspctrl->apbnspppcexp1 |= (1U << CMSDK_UART0_APB_PPC_POS);

    /* in NS, grant un-privileged access for LEDs */
    nspctrl->apbnspppcexp2 |= (1U << CMSDK_FPGA_SCC_PPC_POS);
    nspctrl->apbnspppcexp2 |= (1U << CMSDK_FPGA_IO_PPC_POS);

    /* Configure the response to a security violation as a
     * bus error instead of RAZ/WI
     */
    spctrl->secrespcfg |= 1U;
}

void ppc_configure_to_non_secure(enum ppc_bank_e bank, uint16_t pos)
{
    /* Setting NS flag for peripheral to enable NS access */
    struct spctrl_def* spctrl = CMSDK_SPCTRL;
    ((uint32_t*)&(spctrl->ahbnsppc0))[bank] |= (1U << pos);
}

void ppc_configure_to_secure(enum ppc_bank_e bank, uint16_t pos)
{
    /* Clear NS flag for peripheral to prevent NS access */
    struct spctrl_def* spctrl = CMSDK_SPCTRL;
    ((uint32_t*)&(spctrl->ahbnsppc0))[bank] &= ~(1U << pos);
}

void ppc_en_secure_unpriv(enum ppc_bank_e bank, uint16_t pos)
{
    struct spctrl_def* spctrl = CMSDK_SPCTRL;
    ((uint32_t*)&(spctrl->ahbspppc0))[bank] |= (1U << pos);
}

void ppc_clr_secure_unpriv(enum ppc_bank_e bank, uint16_t pos)
{
    struct spctrl_def* spctrl = CMSDK_SPCTRL;
    ((uint32_t*)&(spctrl->ahbspppc0))[bank] &= ~(1U << pos);
}

void ppc_clear_irq(void)
{
    struct spctrl_def* spctrl = CMSDK_SPCTRL;
    /* Clear APB PPC EXP2 IRQ */
    spctrl->secppcintclr = CMSDK_APB_PPCEXP2_INT_POS_MASK;
}
