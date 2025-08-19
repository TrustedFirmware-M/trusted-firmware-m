/*
 * SPDX-License-Identifier: BSD-3-Clause
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 */

#ifndef __HOST_DEVICE_DEFINITION_H__
#define __HOST_DEVICE_DEFINITION_H__

#include "host_device_cfg.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifdef RSE_USE_HOST_UART
#include "uart_pl011_drv.h"
extern struct uart_pl011_dev_t UART0_PL011_DEV_NS;
#endif /* RSE_USE_HOST_UART */

#ifdef PLATFORM_HOST_HAS_SI_CL0
#include "ppu_drv.h"
extern const struct ppu_dev_t HOST_SI_SYSTOP_PPU_DEV;
extern const struct ppu_dev_t HOST_SI_CL0_CLUS_PPU_DEV;
extern const struct ppu_dev_t HOST_SI_CL0_CORE0_PPU_DEV;
#endif /* PLATFORM_HOST_HAS_SI_CL0 */

#ifdef PLATFORM_RSE_HAS_ATU_OWNERSHIP
#include "atu_rse_drv.h"
extern struct atu_dev_t HOST_SI_ATU_DEV;
extern struct atu_dev_t HOST_AP_ATU_DEV;

/* Structure used to describe an ATU region */
struct atu_map {
    /* Logical start address */
    uint32_t log_addr;
    /* Physical start address */
    uint64_t phy_addr;
    /* Size of the ATU region */
    uint32_t size;
    /* Bus attributes */
    uint32_t bus_attr;
};

/* Indices for SI ATU regions */
enum SI_ATU_REGIONS {
    SI_ATU_REGION_IDX_CMN,
    SI_ATU_REGION_IDX_CLUSTER_UTILITY,
    SI_ATU_REGION_IDX_SMD_EXPANSION,
    SI_ATU_REGION_IDX_SYSTOP_PIK,
    SI_ATU_REGION_IDX_SYSTEM_ID,
    SI_ATU_REGION_IDX_CSS_COUNTERS_TIMERS,
    SI_ATU_REGION_IDX_SHARED_SRAM,
    SI_ATU_REGION_COUNT,
};

/* Indices for AP ATU regions */
enum AP_ATU_REGIONS {
    AP_ATU_REGION_IDX_GENERIC_TIMER,
    AP_ATU_REGION_IDX_PC_SI_MHU,
    AP_ATU_REGION_IDX_PC_RSE_MHU,
    AP_ATU_REGION_COUNT,
};

/* List of ATU regions configured by RSE in SI ATU */
extern struct atu_map si_atu_regions[SI_ATU_REGION_COUNT];
/* List of ATU regions configured by RSE in AP ATU */
extern const struct atu_map ap_atu_regions[AP_ATU_REGION_COUNT];
#endif /* PLATFORM_RSE_HAS_ATU_OWNERSHIP */

#ifdef __cplusplus
}
#endif

#endif  /* __HOST_DEVICE_DEFINITION_H__ */
