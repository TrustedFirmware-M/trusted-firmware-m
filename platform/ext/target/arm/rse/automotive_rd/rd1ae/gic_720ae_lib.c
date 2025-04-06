/*
 * Copyright (c) 2024, Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
#include "gic_720ae_lib.h"
#include "array.h"
#include "bootutil/bootutil_log.h"
#include "gic_720ae_drv.h"

#include <stddef.h>

/* RD1AE has view-0/1/2/3 for Safety Island */
#define GIC_MV_MAX_VIEW_NUM     4
/*
 * RD1AE GIC View-0 has a contiguous region for all
 * Safety Island GIC re-distributors:
 * SI CL0: 1 re-distributors for 1 PE
 * SI CL1: 2 re-distributors for 2 PE
 * SI CL2: 4 re-distributors for 4 PE
 */
#define GIC_MV_MAX_REDIST_NUM   7

static struct gic_mv_dev_t gic_view0;

/* GIC Multiple View, Safety Island Cluster PE to view mapping table */
static const struct gic_mv_p2v_map view_pe_map[] = {
    /* SI CL0 PE for View 1 */
    {0x0, 1},
    /* SI CL1 PE for View 2 */
    {0x10000, 2},
    {0x10100, 2},
    /* SI CL2 PE for View 3 */
    {0x20000, 3},
    {0x20100, 3},
    {0x20200, 3},
    {0x20300, 3}
};

static const struct gic_mv_i2v_map view_spi_map[] = {
    /* Safety Island CL0 SPI for view 1 */
    {34, 1}, /* System Timer for SI CL0 */
    {37, 1}, /* 1st interrupt of System Watchdog for SI CL0 */
    {40, 1}, /* UART for SI CL0 */
    {88, 1}, /* MHU PC NS <- SI CL0 */
    {89, 1},
    {90, 1},
    {91, 1},
    {92, 1}, /* MHU PC NS -> SI CL0 */
    {93, 1},
    {94, 1},
    {95, 1},
    {96, 1}, /* MHU PC S <- SI CL0 */
    {97, 1},
    {98, 1},
    {99, 1},
    {100, 1}, /* MHU PC S -> SI CL0 */
    {101, 1},
    {102, 1},
    {103, 1},
    {104, 1}, /* MHU RSE S <- SI CL0 */
    {105, 1},
    {106, 1},
    {107, 1},
    {108, 1},
    {109, 1},
    {110, 1},
    {111, 1}, /* MHU RSE S -> SI CL0 */
    {112, 1}, /* MHU SI CL1 <- SI CL0 */
    {114, 1}, /* MHU SI CL2 <- SI CL0 */
    {117, 1}, /* MHU SI CL1 -> SI CL0 */
    {121, 1}, /* MHU SI CL2 -> SI CL0 */
    {130, 1}, /* PC STC 1 */
    {131, 1}, /* PC STC 0 */
    {132, 1}, /* PC PIK  */
    {133, 1}, /* QSPI */
    {136, 1}, /* Ethernet 1 */
    {137, 1}, /* Ethernet 0 */
    {138, 1}, /* DMA 0 */
    {141, 1}, /* ATU Interrupt SI CL0 */
    {143, 1}, /* NCI main */
    {151, 1}, /* MHU SCP -> SI CL0 */
    {152, 1}, /* MHU SCP <- SI CL0 */
    {160, 1}, /* PPU Interrupt for SI CL0 Core 0 */
    {164, 1}, /* PPU Interrupt for SI CL0 */
    {165, 1}, /* PMU Interrupt for SI CL0 */

    /* Safety Island CL1 SPI for view 2 */
    {33, 2}, /* System Timer for SI CL1 */
    {36, 2}, /* 1st interrupt of System Watchdog for SI CL1 */
    {39, 2}, /* UART for SI CL1 */
    {72, 2}, /* MHU PC NS <- SI CL1 */
    {73, 2},
    {74, 2},
    {75, 2},
    {76, 2}, /* MHU PC NS -> SI CL1 */
    {77, 2},
    {78, 2},
    {79, 2},
    {80, 2}, /* MHU PC S <- SI CL1 */
    {81, 2},
    {82, 2},
    {83, 2},
    {84, 2}, /* MHU PC S -> SI CL1 */
    {85, 2},
    {86, 2},
    {87, 2},
    {113, 2}, /* MHU SI CL0 -> SI CL1 */
    {116, 2}, /* MHU SI CL0 <- SI CL1 */
    {118, 2}, /* MHU SI CL2 <- SI CL1 */
    {123, 2}, /* MHU SI CL2 -> SI CL1 */
    {124, 2}, /* MHU RSE S <- SI CL1 */
    {125, 2}, /* MHU RSE S -> SI CL1 */
    {128, 2}, /* FMU */
    {129, 2}, /* SSU */
    {134, 2}, /* FMU Non-Critical */
    {139, 2}, /* DMA 1 */
    {145, 2}, /* ATU Interrupt SI CL1 */
    {153, 2}, /* MHU SCP -> SI CL1 */
    {154, 2}, /* MHU SCP <- SI CL1 */
    {168, 2}, /* PPU Interrupt for SI CL1 Core 0 */
    {169, 2}, /* PPU Interrupt for SI CL1 Core 1 */
    {172, 2}, /* PPU Interrupt for SI CL1 */
    {173, 2}, /* PMU Interrupt for SI CL1 */

    /* Safety Island CL2 SPI for view 3 */
    {32, 3}, /* System Timer for SI CL2 */
    {35, 3}, /* 1st interrupt of System Watchdog for SI CL2 */
    {38, 3}, /* UART for SI CL2 */
    {48, 3}, /* MHU PC NS <- SI CL2 */
    {49, 3},
    {50, 3},
    {51, 3},
    {52, 3}, /* MHU PC NS -> SI CL2 */
    {53, 3},
    {54, 3},
    {55, 3},
    {56, 3}, /* MHU PC S <- SI CL2 */
    {57, 3},
    {58, 3},
    {59, 3},
    {60, 3}, /* MHU PC S -> SI CL2 */
    {61, 3},
    {62, 3},
    {63, 3},
    {64, 3}, /* MHU RSE S <- SI CL2 */
    {65, 3},
    {66, 3},
    {67, 3},
    {68, 3}, /* MHU RSE S -> SI CL2 */
    {69, 3},
    {70, 3},
    {71, 3},
    {115, 3}, /* MHU SI CL0 -> SI CL2 */
    {119, 3}, /* MHU SI CL1 -> SI CL2 */
    {120, 3}, /* MHU SI CL0 <- SI CL2 */
    {122, 3}, /* MHU SI CL1 <- SI CL2 */
    {140, 3}, /* DMA 2 */
    {146, 3}, /* ATU Interrupt SI CL2 */
    {155, 3}, /* MHU SCP -> SI CL2 */
    {156, 3}, /* MHU SCP <- SI CL2 */
    {176, 3}, /* PPU Interrupt for SI CL2 Core 0 */
    {177, 3}, /* PPU Interrupt for SI CL2 Core 1 */
    {178, 3}, /* PPU Interrupt for SI CL2 Core 2 */
    {179, 3}, /* PPU Interrupt for SI CL2 Core 3 */
    {180, 3}, /* PPU Interrupt for SI CL2 */
    {181, 3}, /* PMU Interrupt for SI CL2 */
};

int gic_multiple_view_programming(void)
{
    int ret;

    BOOT_LOG_INF("GIC: Multiple Views configure PE ...");
    ret = gic_multiple_view_config_pe(&gic_view0,
                                      view_pe_map,
                                      ARRAY_SIZE(view_pe_map));
    if (ret) {
        BOOT_LOG_ERR("GIC: configure PE views failed!");
        return ret;
    }

    BOOT_LOG_INF("GIC: Multiple Views configure SPI ...");
    ret = gic_multiple_view_config_spi(&gic_view0,
                                       view_spi_map,
                                       ARRAY_SIZE(view_spi_map));
    if (ret) {
        BOOT_LOG_ERR("GIC: configure SPI views failed!");
        return ret;
    }

    BOOT_LOG_INF("GIC: Multiple Views configuration done!");

    return 0;
}

int gic_multiple_view_probe(uint32_t view0_base)
{
    int ret;

    ret = gic_multiple_view_device_probe(&gic_view0, view0_base,
                                         GIC_MV_MAX_VIEW_NUM,
                                         GIC_MV_MAX_REDIST_NUM);
    if (ret) {
        BOOT_LOG_ERR("Probe Multiple View GIC device failed!");
        return ret;
    }

    return 0;
}
