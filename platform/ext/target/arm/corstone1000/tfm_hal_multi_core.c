/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "device_definition.h"
#include "flash_common.h"
#include "platform_base_address.h"
#include "tfm_hal_multi_core.h"
#include "fwu_agent.h"

#ifdef CORSTONE1000_DSU_120T
#include "ppu.h"
#endif

#define HOST_SYS_RST_CTRL_OFFSET     0x000
#define HOST_CPU_PE0_CONFIG_OFFSET   0x010
#define HOST_CPU_PE1_CONFIG_OFFSET   0x020
#define HOST_CPU_PE2_CONFIG_OFFSET   0x030
#define HOST_CPU_PE3_CONFIG_OFFSET   0x040
#define HOST_CPU_BOOT_MASK_OFFSET    0x300
#define HOST_CPU_CORE0_WAKEUP_OFFSET 0x308

#define AA64nAA32_MASK (1 << 3)

#ifdef EXTERNAL_SYSTEM_SUPPORT
void tfm_external_system_boot()
{
    volatile uint32_t *ext_sys_reset_ctl_reg = (uint32_t *)(CORSTONE1000_EXT_SYS_RESET_REG);

    /* de-assert CPU_WAIT signal*/
    *ext_sys_reset_ctl_reg = 0x0;
}
#endif

void tfm_hal_boot_ns_cpu(uintptr_t start_addr)
{
    /* Switch the shared flash to XiP mode for the host */
    Select_XIP_Mode_For_Shared_Flash();

#ifndef TFM_S_REG_TEST
    volatile uint32_t *bir_base = (uint32_t *)CORSTONE1000_HOST_BIR_BASE;

    /* Program Boot Instruction Register to jump to BL2 (TF-A) base address
     * at 0x02354000, corresponding assembler instructions are as below.
     * 0x58000040     ldr       x0, Label
     * 0xD61F0000     br        x0
     * 0x02354000     Label:    .dword 0x020d3000
     */
    bir_base[0] = 0x58000040;
    bir_base[1] = 0xD61F0000;
    bir_base[2] = 0x02354000;

    volatile uint32_t *reset_ctl_reg = (uint32_t *)(CORSTONE1000_BASE_SCR_BASE
                                                    + HOST_SYS_RST_CTRL_OFFSET);
    volatile uint32_t *reset_ctl_wakeup_reg =
                        (uint32_t *)(CORSTONE1000_HOST_BASE_SYSTEM_CONTROL_BASE
                                     + HOST_CPU_CORE0_WAKEUP_OFFSET);

    volatile uint32_t *PE0_CONFIG =
                        (uint32_t *)(CORSTONE1000_HOST_BASE_SYSTEM_CONTROL_BASE
                                     + HOST_CPU_PE0_CONFIG_OFFSET);
#if CORSTONE1000_FVP_MULTICORE
    volatile uint32_t *PE1_CONFIG =
                        (uint32_t *)(CORSTONE1000_HOST_BASE_SYSTEM_CONTROL_BASE
                                     + HOST_CPU_PE1_CONFIG_OFFSET);
    volatile uint32_t *PE2_CONFIG =
                        (uint32_t *)(CORSTONE1000_HOST_BASE_SYSTEM_CONTROL_BASE
                                     + HOST_CPU_PE2_CONFIG_OFFSET);
    volatile uint32_t *PE3_CONFIG =
                        (uint32_t *)(CORSTONE1000_HOST_BASE_SYSTEM_CONTROL_BASE
                                     + HOST_CPU_PE3_CONFIG_OFFSET);
    volatile uint32_t *CPU_BOOT_MASK =
                        (uint32_t *)(CORSTONE1000_HOST_BASE_SYSTEM_CONTROL_BASE
                                     + HOST_CPU_BOOT_MASK_OFFSET);

    *CPU_BOOT_MASK = 0xf;
#endif
    /* Select host CPU architecture as AArch64 */
    *PE0_CONFIG |= AA64nAA32_MASK; /* 0b1 – AArch64 */
#if CORSTONE1000_FVP_MULTICORE
    *PE1_CONFIG |= AA64nAA32_MASK; /* 0b1 – AArch64 */
    *PE2_CONFIG |= AA64nAA32_MASK; /* 0b1 – AArch64 */
    *PE3_CONFIG |= AA64nAA32_MASK; /* 0b1 – AArch64 */
#endif

    /* wakeup CORE0 before bringing it out of reset */
    *reset_ctl_wakeup_reg = 0x1;

    /* Clear HOST_SYS_RST_CTRL register to bring host out of RESET */
    *reset_ctl_reg = 0;

#if CORSTONE1000_FVP_MULTICORE
    /* Wake up secondary cores.
     * This should be done after bringing the primary core out of reset.*/
    for (int core_index=1; core_index < PLATFORM_HOST_MAX_CORE_COUNT; core_index++) {
	    *reset_ctl_wakeup_reg = (0x1 << core_index);
    }
#endif

    (void) start_addr;

#ifdef CORSTONE1000_DSU_120T
    /* Power on DSU-120T cluster */
    PPU_SetOperatingPolicy(CLUSTER_PPU, PPU_OP_MODE_ONE_SLICE_SF_ONLY_ON, false);
    PPU_SetPowerPolicy(CLUSTER_PPU, PPU_PWR_MODE_ON, false);

    /* Power on Cortex-A320 core0 in DSU-120T Cluster */
    PPU_SetOperatingPolicy(CORE0_PPU, PPU_OP_MODE_ONE_SLICE_SF_ONLY_ON, false);
    PPU_SetPowerPolicy(CORE0_PPU, PPU_PWR_MODE_ON, false);

#if CORSTONE1000_FVP_MULTICORE
    /* Power on all Cortex-A320 cores in DSU-120T Cluster */
    PPU_SetOperatingPolicy(CORE1_PPU, PPU_OP_MODE_ONE_SLICE_SF_ONLY_ON, false);
    PPU_SetPowerPolicy(CORE1_PPU, PPU_PWR_MODE_ON, false);

    PPU_SetOperatingPolicy(CORE2_PPU, PPU_OP_MODE_ONE_SLICE_SF_ONLY_ON, false);
    PPU_SetPowerPolicy(CORE2_PPU, PPU_PWR_MODE_ON, false);

    PPU_SetOperatingPolicy(CORE3_PPU, PPU_OP_MODE_ONE_SLICE_SF_ONLY_ON, false);
    PPU_SetPowerPolicy(CORE3_PPU, PPU_PWR_MODE_ON, false);
#endif
#endif

#ifdef EXTERNAL_SYSTEM_SUPPORT
    /*release EXT SYS out of reset*/
    tfm_external_system_boot();
#endif
#endif /* !TFM_S_REG_TEST */
}

void tfm_hal_wait_for_ns_cpu_ready(void)
{
#if !(PLATFORM_IS_FVP)
    /* start the reset timer if firwmare update process is ongoing */
    host_acknowledgement_timer_to_reset();
#endif
}
