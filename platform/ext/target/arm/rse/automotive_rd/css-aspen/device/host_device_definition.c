/*
 * SPDX-License-Identifier: BSD-3-Clause
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 */

/**
 * \file host_device_definition.c
 * \brief This file defines exports the structures based on the peripheral
 * definitions from device_cfg.h.
 */

#include "platform_base_address.h"

#include "host_base_address.h"
#include "host_device_definition.h"

#ifdef RSE_USE_HOST_UART
static const struct uart_pl011_dev_cfg_t UART0_PL011_DEV_CFG_NS = {
    .base = HOST_UART0_BASE_NS,
    .def_baudrate = DEFAULT_UART_BAUDRATE,
    .def_wlen = UART_PL011_WLEN_8,
    .def_parity = UART_PL011_PARITY_DISABLED,
    .def_stopbit = UART_PL011_STOPBIT_1
};
static struct uart_pl011_dev_data_t UART0_PL011_DEV_DATA_NS = {
    .state = 0,
    .uart_clk = 0,
    .baudrate = 0
};
struct uart_pl011_dev_t UART0_PL011_DEV_NS = {
    &(UART0_PL011_DEV_CFG_NS),
    &(UART0_PL011_DEV_DATA_NS)
};
#endif /* RSE_USE_HOST_UART */

#ifdef PLATFORM_HOST_HAS_SI_CL0
const struct ppu_dev_t HOST_SI_SYSTOP_PPU_DEV = {
    .ppu_base = HOST_SI_PIK_ATU_WINDOW_BASE_S,
    .cluster_safety_base = NULL,
};

const struct ppu_dev_t HOST_SI_CL0_CLUS_PPU_DEV = {
    .ppu_base = HOST_SI_CL0_CUB_ATU_WINDOW_BASE_S + 0x10000,
    .cluster_safety_base = HOST_SI_CL0_CUB_ATU_WINDOW_BASE_S + 0x80000,
};
const struct ppu_dev_t HOST_SI_CL0_CORE0_PPU_DEV = {
    .ppu_base = HOST_SI_CL0_CUB_ATU_WINDOW_BASE_S + 0x40000,
    .cluster_safety_base = HOST_SI_CL0_CUB_ATU_WINDOW_BASE_S + 0x80000,
};
#endif /* PLATFORM_HOST_HAS_SI_CL0 */

#ifdef PLATFORM_RSE_HAS_ATU_OWNERSHIP
static const struct atu_dev_cfg_t HOST_SI_ATU_DEV_CFG = {
    .base = HOST_SI_ATU_BASE_S,
};
struct atu_dev_t HOST_SI_ATU_DEV = {
    .cfg = &HOST_SI_ATU_DEV_CFG,
};

struct atu_map si_atu_regions[SI_ATU_REGION_COUNT] = {
    [SI_ATU_REGION_IDX_CMN] = {
        .log_addr = 0x80000000UL,
        .phy_addr = 0x100000000ULL,
        .size = 0x40000000UL,
        .bus_attr = ATU_ENCODE_ATTRIBUTES_SECURE_PAS,
    },
    [SI_ATU_REGION_IDX_CLUSTER_UTILITY] = {
        .log_addr = 0xC0000000UL,
        .phy_addr = 0x140000000ULL,
        .size = 0x10000000UL,
        .bus_attr = ATU_ENCODE_ATTRIBUTES_SECURE_PAS,
    },
    [SI_ATU_REGION_IDX_SMD_EXPANSION] = {
        .log_addr = 0xD0000000UL,
        .phy_addr = 0x20000D8000000ULL,
        .size = 0x20000UL,
        .bus_attr = ATU_ENCODE_ATTRIBUTES_SECURE_PAS,
    },
    [SI_ATU_REGION_IDX_SYSTOP_PIK] = {
        .log_addr = 0xD0020000UL,
        .phy_addr = 0x20000D0200000ULL,
        .size = 0x10000UL,
        .bus_attr = ATU_ENCODE_ATTRIBUTES_SECURE_PAS,
    },
    [SI_ATU_REGION_IDX_SYSTEM_ID] = {
        .log_addr = 0xD0030000UL,
        .phy_addr = 0x20000D0400000ULL,
        .size = 0x10000UL,
        .bus_attr = ATU_ENCODE_ATTRIBUTES_SECURE_PAS,
    },
    [SI_ATU_REGION_IDX_CSS_COUNTERS_TIMERS] = {
        .log_addr = 0xD0040000UL,
        .phy_addr = 0x20000D0100000ULL,
        .size = 0x30000UL,
        .bus_attr = ATU_ENCODE_ATTRIBUTES_SECURE_PAS,
    },
    [SI_ATU_REGION_IDX_SHARED_SRAM] = {
        .log_addr = 0xE0030000UL,
        .phy_addr = 0x0ULL,
        .size = 0x2000UL,
        .bus_attr = ATU_ENCODE_ATTRIBUTES_SECURE_PAS,
    },
};

static const struct atu_dev_cfg_t HOST_AP_ATU_DEV_CFG = {
    .base = HOST_AP_ATU_BASE_S,
};
struct atu_dev_t HOST_AP_ATU_DEV = {
    .cfg = &HOST_AP_ATU_DEV_CFG,
};

const struct atu_map ap_atu_regions[AP_ATU_REGION_COUNT] = {
    [AP_ATU_REGION_IDX_GENERIC_TIMER] = {
        .log_addr = 0x40000000UL,
        .phy_addr = 0x20000D0100000ULL,
        .size = 0x20000UL,
        .bus_attr = ATU_ENCODE_ATTRIBUTES_SECURE_PAS,
    },
    [AP_ATU_REGION_IDX_PC_SI_MHU] = {
        .log_addr = 0x40020000UL,
        .phy_addr = 0x400003B000000ULL,
        .size = 0x600000UL,
        .bus_attr = ATU_ENCODE_ATTRIBUTES_SECURE_PAS,
    },
    [AP_ATU_REGION_IDX_PC_RSE_MHU] = {
        .log_addr = 0x40680000UL,
        .phy_addr = 0x0300001B600000ULL,
        .size = 0xC0000UL,
        .bus_attr = ATU_ENCODE_ATTRIBUTES_SECURE_PAS,
    },
};
#endif /* PLATFORM_RSE_HAS_ATU_OWNERSHIP */
