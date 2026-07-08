/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 * Copyright (c) 2026 Texas Instruments Incorporated. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
 * \file target_cfg.c
 * \brief SAU / security configuration for LP_MSPM33C321A TF-M platform.
 *
 * The ARMv8-M SAU performs TrustZone address-space partitioning. The GSC
 * (Global Security Controller) provides the MPC/PPC-equivalent memory and
 * peripheral protection: its FPC/SPC sub-units gate flash and SRAM access
 * by security state, while its PPC sub-unit gates peripheral access on a
 * per-peripheral basis rather than the generic bank/position scheme TF-M's
 * PPC interface assumes.
 */

#include "common_target_cfg.h"
#include "Driver_Common.h"
#include "region_defs.h"
#include <ti/driverlib/dl_gsc.h>
#include "tfm_hal_device_header.h"
#include "tfm_plat_defs.h"
#include "tfm_peripherals_def.h"

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))

extern const struct memory_region_limits memory_regions;

/* Peripheral data objects referenced by tfm_peripherals_def.h.
 * Addresses are Secure aliases (0x5xxxxxxx) from platform_base_address.h. */
struct platform_data_t tfm_peripheral_std_uart = {
    .periph_start    = 0x50608000UL,           /* UC12_UART_BASE_S */
    .periph_limit    = 0x50608000UL + 0xFFFUL,
    .periph_ppc_bank = PPC_SP_DO_NOT_CONFIGURE,
    .periph_ppc_mask = 0
};

struct platform_data_t tfm_peripheral_timer0 = {
    .periph_start    = 0x50010000UL,           /* TIMA0_0_BASE_S */
    .periph_limit    = 0x50010000UL + 0xFFFUL,
    .periph_ppc_bank = PPC_SP_DO_NOT_CONFIGURE,
    .periph_ppc_mask = 0
};

/*------------------- SAU / IDAU configuration ----------------------------*/

void sau_and_idau_cfg(void)
{
    /* Ensure all pending memory accesses complete before reconfiguring SAU */
    __DMB();

    /* Disable SAU while programming regions */
    SAU->CTRL = 0U;

    /*
     * Region 0 — Non-Secure code (NS flash partition).
     * The NS code window is opened by TF-M after the secure image has loaded.
     */
    SAU->RNR  = 0U;
    SAU->RBAR = (memory_regions.non_secure_partition_base & SAU_RBAR_BADDR_Msk);
    SAU->RLAR = (memory_regions.non_secure_partition_limit & SAU_RLAR_LADDR_Msk)
                | SAU_RLAR_ENABLE_Msk;

    /*
     * Region 1 — Non-Secure data (NS SRAM).
     */
    SAU->RNR  = 1U;
    SAU->RBAR = (NS_DATA_START & SAU_RBAR_BADDR_Msk);
    SAU->RLAR = (NS_DATA_LIMIT  & SAU_RLAR_LADDR_Msk)
                | SAU_RLAR_ENABLE_Msk;

    /*
     * Region 2 — Non-Secure Callable veneer region (NSC).
     * NSC bit set so NS code can branch into this region via SG instructions.
     */
    SAU->RNR  = 2U;
    SAU->RBAR = (memory_regions.veneer_base & SAU_RBAR_BADDR_Msk);
    SAU->RLAR = (memory_regions.veneer_limit & SAU_RLAR_LADDR_Msk)
                | SAU_RLAR_ENABLE_Msk
                | SAU_RLAR_NSC_Msk;

    /*
     * Region 3 — Non-Secure peripheral alias space.
     * MSPM33C321A NS peripheral aliases are at 0x4xxxxxxx.
     * Secure aliases are at 0x5xxxxxxx (used by the secure image).
     * Map 0x40000000 – 0x4FFFFFFF as NS so NS apps can access peripherals.
     */
    SAU->RNR  = 3U;
    SAU->RBAR = (0x40000000UL & SAU_RBAR_BADDR_Msk);
    SAU->RLAR = (0x4FFFFFFFUL & SAU_RLAR_LADDR_Msk)
                | SAU_RLAR_ENABLE_Msk;

#ifdef BL2
    /* Region 4 — Secondary (upgrade) image partition (NS) */
    SAU->RNR  = 4U;
    SAU->RBAR = (memory_regions.secondary_partition_base & SAU_RBAR_BADDR_Msk);
    SAU->RLAR = (memory_regions.secondary_partition_limit & SAU_RLAR_LADDR_Msk)
                | SAU_RLAR_ENABLE_Msk;
#endif /* BL2 */

    /* Enable SAU */
    SAU->CTRL = SAU_CTRL_ENABLE_Msk;

    /* Flush pipeline and ensure writes are visible */
    __DSB();
    __ISB();
}

/*------------------- Memory configuration (MPC-equivalent) ---------------*/
/* GSC's FPC/SPC sub-units are the MPC equivalent: they gate Secure vs.
 * Non-Secure access to flash and SRAM at sector/chunk granularity. */

enum tfm_plat_err_t mpc_init_cfg(void)
{
    /* Ensure all pending memory accesses complete before reconfiguring GSC */
    __DMB();

    /*
     * Configure GSC flash security attributes to match the SAU partition.
     * MSPM33C321A has 1MB flash in two 512KB banks:
     *   Bank 0 (0x000000-0x07FFFF): Secure partition
     *   Bank 1 (0x080000-0x0FFFFF): NS partition
     *
     * SECATTRIBA0/B0 control Bank 0 sectors.
     * SECATTRIBA1/B1 control Bank 1 sectors.
     * Bit=1: Secure, Bit=0: Non-Secure.
     */
    /* Bank 0: entirely Secure */
    DL_GSC_configureMainFlashSecurity(GSC_S, DL_GSC_MAIN_FLASH_BANK_A,
                                       0xFFFFFFFFUL, 0xFFFFFFF0UL);

    /* Bank 1: entirely Non-Secure (NS application partition) */
    DL_GSC_configureMainFlashSecurity(GSC_S, DL_GSC_MAIN_FLASH_BANK_B,
                                       0x00000000UL, 0x00000000UL);

    /*
     * Configure GSC SRAM security attributes.
     * 256KB SRAM = 16 pages × 16KB.
     * Pages 0-7  (0x20000000-0x2001FFFF, 128KB): Secure partition
     * Pages 8-15 (0x20020000-0x2003FFFF, 128KB): NS partition
     *
     * For each page, set all chunks to true (Secure) for Secure pages,
     * and false (Non-Secure) for NS pages.
     */
    DL_GSC_SRAMSecurityConfig sramCfg = {0};  /* default: all Non-Secure */

    /* Mark pages 0-7 as Secure */
    for (int i = 0; i < 8; i++) {
        sramCfg.pages[i].chunk_512B_0 = true;
        sramCfg.pages[i].chunk_512B_1 = true;
        sramCfg.pages[i].chunk_1KB    = true;
        sramCfg.pages[i].chunk_2KB    = true;
        sramCfg.pages[i].chunk_4KB_0  = true;
        sramCfg.pages[i].chunk_4KB_1  = true;
        sramCfg.pages[i].chunk_4KB_2  = true;
    }
    /* Pages 8-15 remain false (Non-Secure) from zero-init */

    DL_GSC_configureSRAMSecurity(GSC_S, &sramCfg);

    /* Flush pipeline and ensure writes are visible */
    __DSB();
    __ISB();

    return TFM_PLAT_ERR_SUCCESS;
}

/*------------------- Peripheral configuration (PPC stubs) ----------------*/
/* GSC's PPC sub-unit grants secure access per named peripheral through
 * dedicated registers (e.g. DL_GSC_allowUARTSecureAccess()), not the
 * generic bank + bit-position array these hooks expect. Neither named
 * MMIO peripheral on this platform needs per-partition PPC reconfiguration
 * (both use PPC_SP_DO_NOT_CONFIGURE), so these remain no-ops. */

enum tfm_plat_err_t ppc_init_cfg(void)
{
    return TFM_PLAT_ERR_SUCCESS;
}

void ppc_configure_to_secure(ppc_bank_t bank, uint32_t pos)
{
    (void)bank; (void)pos;
}

void ppc_configure_to_non_secure(ppc_bank_t bank, uint32_t pos)
{
    (void)bank; (void)pos;
}

void ppc_en_secure_unpriv(ppc_bank_t bank, uint32_t pos)
{
    (void)bank; (void)pos;
}

void ppc_clr_secure_unpriv(ppc_bank_t bank, uint32_t pos)
{
    (void)bank; (void)pos;
}

/* Only called from platform/ext/common/mpc_ppc_faults.c, which this
 * platform's CMakeLists.txt does not build; unreachable at runtime. */
void mpc_clear_irq(void) {}
void ppc_clear_irq(void) {}

/* Named MMIO peripherals exposed to partitions (required by secure test
 * partition which claims TFM_PERIPHERAL_STD_UART as a named MMIO asset). */
static const uintptr_t partition_named_mmio_list[] = {
    (uintptr_t)TFM_PERIPHERAL_STD_UART,
    (uintptr_t)TFM_PERIPHERAL_TIMER0,
};

void get_partition_named_mmio_list(const uintptr_t **list, size_t *length)
{
    *list   = partition_named_mmio_list;
    *length = ARRAY_SIZE(partition_named_mmio_list);
}
