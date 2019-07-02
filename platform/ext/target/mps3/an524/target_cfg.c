/*
 * Copyright (c) 2019 Arm Limited. All rights reserved.
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

#include "target_cfg.h"
#include "Driver_MPC.h"
#include "Driver_PPC.h"
#include "device_definition.h"
#include "platform_description.h"
#include "region_defs.h"
#include "tfm_secure_api.h"
#include "mpu_armv8m_drv.h"

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

static struct mpu_armv8m_dev_t dev_mpu = { MPU_BASE };

/* Allows software, via SAU, to define the code region as a NSC */
#define NSCCFG_CODENSC  1

/* Import MPC drivers */
extern ARM_DRIVER_MPC Driver_QSPI_MPC;
extern ARM_DRIVER_MPC Driver_ISRAM0_MPC;
extern ARM_DRIVER_MPC Driver_ISRAM1_MPC;
extern ARM_DRIVER_MPC Driver_ISRAM2_MPC;
extern ARM_DRIVER_MPC Driver_ISRAM3_MPC;

/* Import PPC drivers */
extern ARM_DRIVER_PPC Driver_AHB_PPCEXP0;
extern ARM_DRIVER_PPC Driver_APB_PPC0;
extern ARM_DRIVER_PPC Driver_APB_PPC1;
extern ARM_DRIVER_PPC Driver_APB_PPCEXP0;
extern ARM_DRIVER_PPC Driver_APB_PPCEXP1;
extern ARM_DRIVER_PPC Driver_APB_PPCEXP2;

/* Define Peripherals NS address range for the platform */
#define PERIPHERALS_BASE_NS_START      (0x40000000)
#define PERIPHERALS_BASE_NS_END        (0x4FFFFFFF)

/* Enable system reset request for CPU 0 */
#define ENABLE_CPU0_SYSTEM_RESET_REQUEST (1U << 4U)

/* To write into AIRCR register, 0x5FA value must be write to the VECTKEY field,
 * otherwise the processor ignores the write.
 */
#define SCB_AIRCR_WRITE_MASK ((0x5FAUL << SCB_AIRCR_VECTKEY_Pos))

struct tfm_spm_partition_platform_data_t tfm_peripheral_std_uart = {
        UART1_BASE_S,
        UART1_BASE_S + 0xFFF,
        PPC_SP_APB_PPC_EXP2,
        CMSDK_UART1_APB_PPC_POS
};

static ARM_DRIVER_PPC *const ppc_bank_drivers[] = {
    0,                      /* AHB PPC0 */
    0,                      /* Reserved */
    0,                      /* Reserved */
    0,                      /* Reserved */
    &Driver_AHB_PPCEXP0,    /* AHB PPCEXP0 */
    0,                      /* AHB PPCEXP1 */
    0,                      /* AHB PPCEXP2 */
    0,                      /* AHB PPCEXP3 */
    &Driver_APB_PPC0,       /* APB PPC0 */
    &Driver_APB_PPC1,       /* APB PPC1 */
    0,                      /* Reserved */
    0,                      /* Reserved */
    &Driver_APB_PPCEXP0,    /* APB PPCEXP0 */
    &Driver_APB_PPCEXP1,    /* APB PPCEXP1 */
    &Driver_APB_PPCEXP2,    /* APB PPCEXP2 */
};

#define PPC_BANK_COUNT (sizeof(ppc_bank_drivers)/sizeof(ppc_bank_drivers[0]))

void enable_fault_handlers(void)
{
    /* Enables BUS, MEM, USG and Secure faults */
    SCB->SHCSR |= (SCB_SHCSR_USGFAULTENA_Msk | SCB_SHCSR_BUSFAULTENA_Msk |
                   SCB_SHCSR_MEMFAULTENA_Msk | SCB_SHCSR_SECUREFAULTENA_Msk);
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

/*--------------------- NVIC interrupt NS/S configuration --------------------*/
void nvic_interrupt_target_state_cfg(void)
{
    uint8_t i;

    /* Target every interrupt to NS; unimplemented interrupts will be WI */
    for (i = 0; i < (sizeof(NVIC->ITNS) / sizeof(NVIC->ITNS[0])); i++) {
        NVIC->ITNS[i] = 0xFFFFFFFF;
    }

    /* Make sure that MPC and PPC are targeted to S state */
    NVIC_ClearTargetState(MPC_IRQn);
    NVIC_ClearTargetState(PPC_IRQn);
}

enum mpu_armv8m_error_t mpu_enable(uint32_t privdef_en, uint32_t hfnmi_en)
{
    return mpu_armv8m_enable(&dev_mpu, privdef_en, hfnmi_en);
}

enum mpu_armv8m_error_t mpu_disable(void)
{
    return mpu_armv8m_disable(&dev_mpu);
}

enum mpu_armv8m_error_t mpu_region_enable(
                                     struct mpu_armv8m_region_cfg_t *region_cfg)
{
    if (!region_cfg) {
        return MPU_ARMV8M_ERROR;
    }

    return mpu_armv8m_region_enable(&dev_mpu, region_cfg);
}

enum mpu_armv8m_error_t mpu_region_disable(uint32_t region_nr)
{
    return mpu_armv8m_region_disable(&dev_mpu, region_nr);
}

enum mpu_armv8m_error_t mpu_clean(void)
{
    return mpu_armv8m_clean(&dev_mpu);
}

/*----------------- NVIC interrupt enabling for S peripherals ----------------*/
void nvic_interrupt_enable(void)
{
    /* MPC interrupt enabling */
    Driver_QSPI_MPC.EnableInterrupt();
    Driver_ISRAM2_MPC.EnableInterrupt();
    Driver_ISRAM3_MPC.EnableInterrupt();
    NVIC_EnableIRQ(MPC_IRQn);

    /* PPC interrupt enabling */
    /* Clear pending PPC interrupts */
    /* In the PPC configuration function, we have used the Non-Secure
     * Privilege Control Block to grant unprivilged NS access to some
     * peripherals used by NS. That triggers a PPC0 exception as that
     * register is meant for NS privileged access only. Clear it here
     */
    Driver_APB_PPC0.ClearInterrupt();

    /* Enable PPC interrupts for APB PPC */
    Driver_APB_PPC0.EnableInterrupt();
    Driver_APB_PPC1.EnableInterrupt();
    Driver_APB_PPCEXP0.EnableInterrupt();
    Driver_APB_PPCEXP1.EnableInterrupt();
    Driver_APB_PPCEXP2.EnableInterrupt();

    NVIC_EnableIRQ(PPC_IRQn);
}

/*------------------- SAU/IDAU configuration functions -----------------------*/
void sau_and_idau_cfg(void)
{
    struct spctrl_def *spctrl = CMSDK_SPCTRL;

    /* Enables SAU */
    TZ_SAU_Enable();

    /* Configures SAU regions to be non-secure */
    SAU->RNR  = TFM_NS_REGION_CODE;
    SAU->RBAR = (memory_regions.non_secure_partition_base
                 & SAU_RBAR_BADDR_Msk);
    SAU->RLAR = (memory_regions.non_secure_partition_limit
                  & SAU_RLAR_LADDR_Msk) | SAU_RLAR_ENABLE_Msk;

    SAU->RNR  = TFM_NS_REGION_DATA;
    SAU->RBAR = (NS_DATA_START & SAU_RBAR_BADDR_Msk);
    SAU->RLAR = (NS_DATA_LIMIT & SAU_RLAR_LADDR_Msk) | SAU_RLAR_ENABLE_Msk;

    /* Configures veneers region to be non-secure callable */
    SAU->RNR  = TFM_NS_REGION_VENEER;
    SAU->RBAR = (memory_regions.veneer_base & SAU_RBAR_BADDR_Msk);
    SAU->RLAR = (memory_regions.veneer_limit & SAU_RLAR_LADDR_Msk)
                 | SAU_RLAR_ENABLE_Msk | SAU_RLAR_NSC_Msk;

    /* Configure the peripherals space */
    SAU->RNR  = TFM_NS_REGION_PERIPH_1;
    SAU->RBAR = (PERIPHERALS_BASE_NS_START & SAU_RBAR_BADDR_Msk);
    SAU->RLAR = (PERIPHERALS_BASE_NS_END & SAU_RLAR_LADDR_Msk)
                  | SAU_RLAR_ENABLE_Msk;
#ifdef BL2
    /* Secondary image partition */
    SAU->RNR = TFM_NS_SECONDARY_IMAGE_REGION;
    /* TODO */
    SAU->RBAR = (memory_regions.secondary_partition_base
                 & SAU_RBAR_BADDR_Msk);
    SAU->RLAR = (memory_regions.secondary_partition_limit
                 & SAU_RLAR_LADDR_Msk) | SAU_RLAR_ENABLE_Msk;
#endif /* BL2 */

    /* Allows SAU to define the code region as a NSC */
    spctrl->nsccfg |= NSCCFG_CODENSC;
}

/*------------------- Memory configuration functions -------------------------*/
void mpc_init_cfg(void)
{
    Driver_QSPI_MPC.Initialize();

    Driver_QSPI_MPC.ConfigRegion(
                    memory_regions.non_secure_partition_base,
                    memory_regions.non_secure_partition_limit,
                    ARM_MPC_ATTR_NONSECURE);
#ifdef BL2
    Driver_QSPI_MPC.ConfigRegion(
                    memory_regions.secondary_partition_base,
                    memory_regions.secondary_partition_limit,
                    ARM_MPC_ATTR_NONSECURE);
#endif /* BL2 */

    /* NSPE use the last 32KB(ISARM 3) */
    Driver_ISRAM3_MPC.Initialize();
    Driver_ISRAM3_MPC.ConfigRegion(
                        MPC_ISRAM3_RANGE_BASE_NS,
                        MPC_ISRAM3_RANGE_LIMIT_NS,
                        ARM_MPC_ATTR_NONSECURE);

    /* Lock down the MPC configuration */
    Driver_QSPI_MPC.LockDown();
    Driver_ISRAM2_MPC.LockDown();
    Driver_ISRAM3_MPC.LockDown();

    /* Add barriers to assure the MPC configuration is done before continue
     * the execution.
     */
    __DSB();
    __ISB();
}

void mpc_clear_irq(void)
{
    Driver_QSPI_MPC.ClearInterrupt();
    Driver_ISRAM0_MPC.ClearInterrupt();
    Driver_ISRAM1_MPC.ClearInterrupt();
    Driver_ISRAM2_MPC.ClearInterrupt();
    Driver_ISRAM3_MPC.ClearInterrupt();
}

/*------------------- PPC configuration functions -------------------------*/
void ppc_init_cfg(void)
{
    struct spctrl_def *spctrl = CMSDK_SPCTRL;

    /* Grant non-secure access to peripherals in the PPC0
     * (timer0 and 1, dualtimer, watchdog, mhu 0 and 1)
     */
    Driver_APB_PPC0.Initialize();
    Driver_APB_PPC0.ConfigPeriph(CMSDK_TIMER0_APB_PPC_POS,
                                    ARM_PPC_NONSECURE_ONLY,
                                    ARM_PPC_PRIV_ONLY);
    Driver_APB_PPC0.ConfigPeriph(CMSDK_TIMER1_APB_PPC_POS,
                                    ARM_PPC_NONSECURE_ONLY,
                                    ARM_PPC_PRIV_ONLY);
    Driver_APB_PPC0.ConfigPeriph(CMSDK_DTIMER_APB_PPC_POS,
                                    ARM_PPC_NONSECURE_ONLY,
                                    ARM_PPC_PRIV_ONLY);
    Driver_APB_PPC0.ConfigPeriph(CMSDK_MHU0_APB_PPC_POS,
                                    ARM_PPC_NONSECURE_ONLY,
                                    ARM_PPC_PRIV_ONLY);
    Driver_APB_PPC0.ConfigPeriph(CMSDK_MHU0_APB_PPC_POS,
                                    ARM_PPC_NONSECURE_ONLY,
                                    ARM_PPC_PRIV_ONLY);

    /* Grant non-secure access to S32K Timer in PPC1*/
    Driver_APB_PPC1.Initialize();
    Driver_APB_PPC1.ConfigPeriph(CMSDK_S32K_TIMER_PPC_POS,
                                    ARM_PPC_NONSECURE_ONLY,
                                    ARM_PPC_PRIV_ONLY);

    /* Grant non-secure access for APB peripherals on EXP1 */
    Driver_APB_PPCEXP1.Initialize();
    Driver_APB_PPCEXP1.ConfigPeriph(CMSDK_I2C0_APB_PPC_POS,
                                        ARM_PPC_NONSECURE_ONLY,
                                        ARM_PPC_PRIV_ONLY);
    Driver_APB_PPCEXP1.ConfigPeriph(CMSDK_I2C1_APB_PPC_POS,
                                        ARM_PPC_NONSECURE_ONLY,
                                        ARM_PPC_PRIV_ONLY);
    Driver_APB_PPCEXP1.ConfigPeriph(CMSDK_SPI0_APB_PPC_POS,
                                        ARM_PPC_NONSECURE_ONLY,
                                        ARM_PPC_PRIV_ONLY);
    Driver_APB_PPCEXP1.ConfigPeriph(CMSDK_SPI1_APB_PPC_POS,
                                        ARM_PPC_NONSECURE_ONLY,
                                        ARM_PPC_PRIV_ONLY);
    Driver_APB_PPCEXP1.ConfigPeriph(CMSDK_SPI2_APB_PPC_POS,
                                        ARM_PPC_NONSECURE_ONLY,
                                        ARM_PPC_PRIV_ONLY);
    Driver_APB_PPCEXP1.ConfigPeriph(CMSDK_I2C2_APB_PPC_POS,
                                        ARM_PPC_NONSECURE_ONLY,
                                        ARM_PPC_PRIV_ONLY);
    Driver_APB_PPCEXP1.ConfigPeriph(CMSDK_I2C3_APB_PPC_POS,
                                        ARM_PPC_NONSECURE_ONLY,
                                        ARM_PPC_PRIV_ONLY);
    Driver_APB_PPCEXP1.ConfigPeriph(CMSDK_I2C4_APB_PPC_POS,
                                        ARM_PPC_NONSECURE_ONLY,
                                        ARM_PPC_PRIV_ONLY);

    /* Grant non-secure access for APB peripherals on EXP2 */
    Driver_APB_PPCEXP2.Initialize();
    Driver_APB_PPCEXP2.ConfigPeriph(CMSDK_FPGA_SCC_PPC_POS,
                                        ARM_PPC_NONSECURE_ONLY,
                                        ARM_PPC_PRIV_ONLY);
    Driver_APB_PPCEXP2.ConfigPeriph(CMSDK_FPGA_AUDIO_PPC_POS,
                                        ARM_PPC_NONSECURE_ONLY,
                                        ARM_PPC_PRIV_ONLY);
    Driver_APB_PPCEXP2.ConfigPeriph(CMSDK_FPGA_IO_PPC_POS,
                                        ARM_PPC_NONSECURE_ONLY,
                                        ARM_PPC_PRIV_AND_NONPRIV);
    Driver_APB_PPCEXP2.ConfigPeriph(CMSDK_UART0_APB_PPC_POS,
                                        ARM_PPC_NONSECURE_ONLY,
                                        ARM_PPC_PRIV_ONLY);
    Driver_APB_PPCEXP2.ConfigPeriph(CMSDK_UART1_APB_PPC_POS,
                                        ARM_PPC_NONSECURE_ONLY,
                                        ARM_PPC_PRIV_ONLY);
    Driver_APB_PPCEXP2.ConfigPeriph(CMSDK_UART2_APB_PPC_POS,
                                        ARM_PPC_NONSECURE_ONLY,
                                        ARM_PPC_PRIV_ONLY);
    Driver_APB_PPCEXP2.ConfigPeriph(CMSDK_UART3_APB_PPC_POS,
                                        ARM_PPC_NONSECURE_ONLY,
                                        ARM_PPC_PRIV_ONLY);
    Driver_APB_PPCEXP2.ConfigPeriph(CMSDK_UART4_APB_PPC_POS,
                                        ARM_PPC_NONSECURE_ONLY,
                                        ARM_PPC_PRIV_ONLY);
    Driver_APB_PPCEXP2.ConfigPeriph(CMSDK_UART5_APB_PPC_POS,
                                        ARM_PPC_NONSECURE_ONLY,
                                        ARM_PPC_PRIV_ONLY);
    Driver_APB_PPCEXP2.ConfigPeriph(CMSDK_CLCD_APB_PPC_POS,
                                        ARM_PPC_NONSECURE_ONLY,
                                        ARM_PPC_PRIV_ONLY);
    Driver_APB_PPCEXP2.ConfigPeriph(CMSDK_RTC_APB_PPC_POS,
                                        ARM_PPC_NONSECURE_ONLY,
                                        ARM_PPC_PRIV_ONLY);

    /*
     * Grant non-secure access to all peripherals on AHB EXP0:
     * Make sure that all possible peripherals are enabled by default
     */
    Driver_AHB_PPCEXP0.Initialize();
    Driver_AHB_PPCEXP0.ConfigPeriph(CMSDK_GPIO0_PPC_POS,
                                        ARM_PPC_NONSECURE_ONLY,
                                        ARM_PPC_PRIV_ONLY);
    Driver_AHB_PPCEXP0.ConfigPeriph(CMSDK_GPIO1_PPC_POS,
                                        ARM_PPC_NONSECURE_ONLY,
                                        ARM_PPC_PRIV_ONLY);
    Driver_AHB_PPCEXP0.ConfigPeriph(CMSDK_GPIO2_PPC_POS,
                                        ARM_PPC_NONSECURE_ONLY,
                                        ARM_PPC_PRIV_ONLY);
    Driver_AHB_PPCEXP0.ConfigPeriph(CMSDK_GPIO3_PPC_POS,
                                        ARM_PPC_NONSECURE_ONLY,
                                        ARM_PPC_PRIV_ONLY);
    Driver_AHB_PPCEXP0.ConfigPeriph(CMSDK_USB_ETHERNET_PPC_POS,
                                        ARM_PPC_NONSECURE_ONLY,
                                        ARM_PPC_PRIV_ONLY);
    Driver_AHB_PPCEXP0.ConfigPeriph(CMSDK_USER0_PPC_POS,
                                        ARM_PPC_NONSECURE_ONLY,
                                        ARM_PPC_PRIV_ONLY);
    Driver_AHB_PPCEXP0.ConfigPeriph(CMSDK_USER1_PPC_POS,
                                        ARM_PPC_NONSECURE_ONLY,
                                        ARM_PPC_PRIV_ONLY);
    Driver_AHB_PPCEXP0.ConfigPeriph(CMSDK_USER2_PPC_POS,
                                        ARM_PPC_NONSECURE_ONLY,
                                        ARM_PPC_PRIV_ONLY);

    /*
     * Configure the response to a security violation as a
     * bus error instead of RAZ/WI
     */
    spctrl->secrespcfg |= CMSDK_SECRESPCFG_BUS_ERR_MASK;
}

void ppc_configure_to_secure_priv(enum ppc_bank_e bank, uint16_t pos)
{
    ARM_DRIVER_PPC *ppc_driver;

    if (bank >= PPC_BANK_COUNT) {
        return;
    }

    ppc_driver = ppc_bank_drivers[bank];
    if (ppc_driver) {
        ppc_driver->ConfigPeriph(pos, ARM_PPC_SECURE_ONLY,
                                    ARM_PPC_PRIV_ONLY);
    }
}

void ppc_en_secure_unpriv(enum ppc_bank_e bank, uint16_t pos)
{
    ARM_DRIVER_PPC *ppc_driver;

    if (bank >= PPC_BANK_COUNT) {
        return;
    }

    ppc_driver = ppc_bank_drivers[bank];
    if (ppc_driver) {
        ppc_driver->ConfigPeriph(pos, ARM_PPC_SECURE_ONLY,
                                    ARM_PPC_PRIV_AND_NONPRIV);
    }
}

void ppc_clear_irq(void)
{
    Driver_AHB_PPCEXP0.ClearInterrupt();
    Driver_APB_PPC0.ClearInterrupt();
    Driver_APB_PPC1.ClearInterrupt();
    Driver_APB_PPCEXP0.ClearInterrupt();
    Driver_APB_PPCEXP1.ClearInterrupt();
    Driver_APB_PPCEXP2.ClearInterrupt();
}
