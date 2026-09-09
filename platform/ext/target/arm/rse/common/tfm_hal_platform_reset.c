/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <assert.h>
#include "tfm_hal_device_header.h"
#include "rse_persistent_data.h"
#ifdef RSE_PERSISTENT_DATA_FLAG_REG_ADDR
#include "device_definition.h"
#include "ppu_reg_map.h"
#endif /* RSE_PERSISTENT_DATA_FLAG_REG_ADDR */

#ifdef RSE_PERSISTENT_DATA_FLAG_REG_ADDR
#define DMA_350_CMD_TIMEOUT 200

static void ack_dma_trigger(uint32_t trigger_number)
{
    struct dma350_ch_dev_t *ch0 = &DMA350_DMA0_CH0_DEV_S;
    size_t counter = 0;

    /* Clear DMA Channel registers to reset channel state */
    dma350_ch_cmd_and_wait_until_done(ch0, DMA350_CH_CMD_CLEARCMD);

    /* Enable source trigger so DMA can respond to it */
    dma350_ch_enable_source_trigger(ch0);

    /* Select the selected HW trigger */
    dma350_ch_set_srctriginsel(ch0, trigger_number);
    dma350_ch_set_srctrigintype(ch0, DMA350_CH_SRCTRIGINTYPE_HW);

    dma350_ch_cmd(ch0, DMA350_CH_CMD_ENABLECMD);
    while (!!(dma350_ch_get_cmd(ch0) & DMA350_CH_CMD_ENABLECMD)
           && (counter++<DMA_350_CMD_TIMEOUT));
    if (counter >= DMA_350_CMD_TIMEOUT) {
        /* Stop DMA Channel */
        dma350_ch_cmd_and_wait_until_done(ch0, DMA350_CH_CMD_STOPCMD);
    }

    /* Clear DMA Channel registers to reset channel state */
    dma350_ch_cmd_and_wait_until_done(ch0, DMA350_CH_CMD_CLEARCMD);
}

static void ack_all_dma_triggers(void)
{
    struct dma350_dev_t *dev = &DMA350_DMA0_DEV_S;
    enum lcm_lcs_t lcs;

    /*Poll until lcs is valid */
    while (lcm_get_lcs(&LCM_DEV_S, &lcs) != LCM_ERROR_NONE);

    /* Stop all DMA channels to deallocate triggers from channels
     *
     * TODO: use dma350_stop_all_channels() when FVP supports init
     */
    for(size_t idx=0; idx<dma350_get_num_channels(dev); idx++) {
        struct dma350_ch_dev_t ch = {
            .cfg = {.ch_base = (DMACH_TypeDef*) (DMA_350_BASE_S + 0x1000UL + 0x100*idx),
                    .channel = idx},
        };
        dma350_ch_cmd_and_wait_until_done(&ch, DMA350_CH_CMD_STOPCMD);
    }

    /* Ack all triggers */
    for(size_t idx=0; idx<dma350_get_num_triggers_in(dev); idx++) {
        ack_dma_trigger(idx);
    }

    dma350_enable_retention(dev);
}
#endif /* RSE_PERSISTENT_DATA_FLAG_REG_ADDR */

uint32_t tfm_hal_get_reset_syndrome(void)
{
    return ((struct rse_sysctrl_t *)RSE_SYSCTRL_BASE_S)->reset_syndrome;
}

void tfm_hal_clear_reset_syndrome_bit(uint8_t bit_pos)
{
    ((struct rse_sysctrl_t *)RSE_SYSCTRL_BASE_S)->reset_syndrome &= ~(1 << bit_pos);
}

__NO_RETURN void tfm_hal_system_reset(uint32_t sw_reset_syn_value)
{
#ifndef RSE_PERSISTENT_DATA_FLAG_REG_ADDR
    struct rse_sysctrl_t *rse_sysctrl = (struct rse_sysctrl_t *)RSE_SYSCTRL_BASE_S;

    sw_reset_syn_value |=
        (0b1U << RSE_PERSISTENT_DATA_FLAGS_PERSISTENT_DATA_INITIALIZED_BITFIELD_POS);

    __DSB();
    rse_sysctrl->swreset = SYSCTRL_SWRESET_SWRESETREQ_MASK |
                               (sw_reset_syn_value & SYSCTRL_SWRESET_SWSYN_MASK);
    __DSB();

    while(1) {
        __NOP();
    }
#else /* !RSE_PERSISTENT_DATA_FLAG_REG_ADDR */
    struct rse_sysctrl_t *rse_sysctrl = (void *)RSE_SYSCTRL_BASE_S;
    struct ppu_reg_map_t *rse_sys_ppu = (void *)RSE_SYSPPU_BASE_S;
    struct ppu_reg_map_t *rse_cpu_ppu = (void *)RSE_CPU0PPU_BASE_S;
    uint32_t val;

    (void)sw_reset_syn_value;

    /* Persistent data should be initialised before the first reset */
    assert(RSE_GET_PERSISTENT_DATA_INITIALIZED_FLAG());

    /* The RSE requires a special cold reset sequence in order to prevent data
     * loss in the SRAMs, which is required to be retained for the persistent
     * data area and the provisioning messages flows to work.
     */

    /* Disable all non-maskable interrupts */
    __disable_irq();


    /* Clear DMA trigger caused by LCS init after reset */
    ack_all_dma_triggers();

    /* Disable CPU caches and verify */

    SCB_DisableICache();
    SCB_DisableDCache();

    /* Set MSCR to disable I and D cache */
    MEMSYSCTL->MSCR &= ~((0b1 << MEMSYSCTL_MSCR_DCACTIVE_Pos)
                       | (0b1 << MEMSYSCTL_MSCR_ICACTIVE_Pos));

    /*  set PPU PWCR to enable PPU register setting by unsetting
     *  PPU_ACCESS_FILTER
     */
    rse_sysctrl->pwrctrl &= ~(0b1);

    /*  Set PPU SYS to mask the device active (prepare for PD SYS to enter
     *  target power state)
     *
     *  [18:8]=0 PWCR.DEVACTIVEEN disable.
     *  [10] enable = MEM_RET allow.
     */
    rse_sys_ppu->pwcr &= ~(0x7FB << 8);

    /* Set VM0 PD to RET */
    val = rse_sysctrl->pdcm_pd_vmr0_sense;
    val &= 0x3fffffff;   //min pwr: off, sensitivity: none, ignore PDCM_Q
    val |= (0x1 << 30);  //min pwr: ret, sensitivity: none, ignore PDCM_Q
    rse_sysctrl->pdcm_pd_vmr0_sense = val;

    /* Set VM1 PD to RET */
    val = rse_sysctrl->pdcm_pd_vmr1_sense;
    val &= 0x3fffffff;   //min pwr: off, sensitivity: none, ignore PDCM_Q
    val |= (0x1 << 30);  //min pwr: ret, sensitivity: none, ignore PDCM_Q
    rse_sysctrl->pdcm_pd_vmr1_sense = val;

    /* Set SYS PD to OFF */
    val = rse_sysctrl->pdcm_pd_sys_sense;
    val &= 0x3fffffff;   //min pwr: off, sensitivity: none, ignore PDCM_Q
    rse_sysctrl->pdcm_pd_vmr1_sense = val;

    /* Enable deep sleep for CPU0 */
    SCB->SCR |= 0x4;

    /* All Co-processor(s) can accept UNKNOWN state which allows CPU to enter
     * OFF state
     */
    ICB->CPPWR = 0xFFFFFFFF;

    /* Set minimum power state for CPU to OFF */
    PWRMODCTL->CPDLPSTATE = 0x333;

    /* CPU PPU PWCR.DEVACTIVEEN disable */
    rse_cpu_ppu->pwcr &= ~(0x7FF << 8);

    __DSB();
    __ISB();

    /* Now set up the watchdog to reset the system in 500 cycles */
    arm_watchdog_init(&SLOWCLK_WATCHDOG_DEV_S, 500);
    arm_watchdog_unlock(&SLOWCLK_WATCHDOG_DEV_S);
    arm_watchdog_enable(&SLOWCLK_WATCHDOG_DEV_S);

    /* And fully shut down the CPU */
    while(1) {
        __WFI();
    }
#endif /* !RSE_PERSISTENT_DATA_FLAG_REG_ADDR */
}

__NO_RETURN void tfm_hal_system_halt(void)
{
    /*
     * Disable IRQs to stop all threads, not just the thread that
     * halted the system.
     */
    __disable_irq();

    /*
     * Enter sleep to reduce power consumption and do it in a loop in
     * case a signal wakes up the CPU.
     */
    while (1) {
        __WFE();
    }
}
