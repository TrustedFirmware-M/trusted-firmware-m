/*
 * Copyright (c) 2024, Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
#include "gic_720ae_drv.h"
#include "bootutil/bootutil_log.h"
#include "gic_720ae_reg.h"

#include <stdint.h>

/* Definitions to access GICD and GICR registers. */
#define GICD_READ_REG(dev, ofs) \
    *(volatile uint32_t *)((dev)->gicd_base + (ofs))

#define GICD_WRITE_REG(dev, ofs, val) \
    (*(volatile uint32_t *)((dev)->gicd_base + (ofs))) = (uint32_t)(val)

#define GICR_READ_REG(dev, cpu, ofs) \
    *(volatile uint32_t *)((dev)->gicr_base + (dev)->rdist_sz * (cpu) + (ofs))

#define GICR_WRITE_REG(dev, cpu, ofs, val) \
    (*(volatile uint32_t *) \
    ((dev)->gicr_base + (dev)->rdist_sz * (cpu) + (ofs))) = (uint32_t)(val)

/* Definitions to calculate SPI register index and bit offset. */
#define SPI_TO_IVIEWRn_IDX(spi)     ((spi) >> 4)
#define SPI_TO_IVIEWRnE_IDX(spi)    (((spi) - 4096) >> 4)
#define SPI_TO_IVIEWRn_BIT(spi)     (((spi) % 16) << 1)
#define SPI_IS_VALID(spi)           ((spi) >= 32 && (spi) < 992)
#define SPI_IS_VALID_EXT(spi)       ((spi) >= 4096 && (spi) < 5120)

static int assign_pe_to_view(struct gic_mv_dev_t *dev,
                             uint32_t mpid, uint8_t view)
{
    uint32_t val;
    uint32_t rdist_id;

    if (view >= dev->view_num) {
        BOOT_LOG_ERR("GIC: Error assigning PE to invalid View:%d", view);
        return -1;
    }

    for (rdist_id = 0; rdist_id < dev->rdist_num; rdist_id++) {
        val = GICR_READ_REG(dev, rdist_id, GICR_TYPER + 4);
        if (val == mpid)
            break;
    }

    if (rdist_id >= dev->rdist_num) {
        BOOT_LOG_ERR("GIC: Error could not find re-dist for PE:%x", mpid);
        return -1;
    }

    /* Update MPID corresponding GICR_VIEWR to view-id */
    GICR_WRITE_REG(dev, rdist_id, GICR_VIEWR, view);

    return 0;
}

static int assign_spi_to_view(struct gic_mv_dev_t *dev,
                              uint16_t spi, uint8_t view)
{
    uint32_t val, offset;
    uint32_t nreg, nbit;

    if (view >= dev->view_num) {
        BOOT_LOG_ERR("GIC: Error assigning SPI to invalid View:%d", view);
        return -1;
    }

    if (SPI_IS_VALID(spi)) {
        nreg = SPI_TO_IVIEWRn_IDX(spi);
        offset = GICD_IVIEWnR + 4 * nreg;
    } else if (SPI_IS_VALID_EXT(spi)) {
        nreg = SPI_TO_IVIEWRnE_IDX(spi);
        offset = GICD_IVIEWnRE + 4 * nreg;
    } else {
        BOOT_LOG_ERR("GIC: Error assigning invalid SPI:5d to View:%d", spi, view);
        return -1;
    }
    nbit = SPI_TO_IVIEWRn_BIT(spi);

    /* Update SPI corresponding GICD_VIEWR to view-id */
    val = GICD_READ_REG(dev, offset);
    val &= (~(GICR_VIEWR_MASK << nbit));
    val |= (view << nbit);
    GICD_WRITE_REG(dev, offset, val);

    return 0;
}

int gic_multiple_view_config_pe(struct gic_mv_dev_t *dev,
                                struct gic_mv_p2v_map *pe_map,
                                uint32_t num)
{
    int ret;
    uint32_t idx;

    for (idx = 0; idx < num; idx++) {
        ret = assign_pe_to_view(dev, pe_map[idx].mpid, pe_map[idx].view);
        if (ret)
            return ret;
    }

    return 0;
}

int gic_multiple_view_config_spi(struct gic_mv_dev_t *dev,
                                 struct gic_mv_i2v_map *spi_map,
                                 uint32_t num)
{
    int ret;
    uint32_t idx, val;

    for (idx = 0; idx < num; idx++) {
        ret = assign_spi_to_view(dev, spi_map[idx].spi, spi_map[idx].view);
        if (ret)
            return ret;
    }

    /*
     * The final GICD_CTLR result of each view is the LOGICAL AND of
     * the GICD_CTLR from view-0 and the GICD_CTLR from each view.
     * Therefore in the multiview initialization, set the EnableGrp0 and
     * EnableGrp1 of view-0's GICD_CTLR from firmware so that the software
     * in each view can control the EnableGrp from their side.
     * Note that in Safety Island, there is only a single security state.
     */
    val = GICD_READ_REG(dev, GICD_CTLR);
    val |= 0x03;
    GICD_WRITE_REG(dev, GICD_CTLR, val);

    return 0;
}

static void gicr_wait_group_not_in_transit(struct gic_mv_dev_t *dev, uint8_t rdist_id)
{
    uint32_t pwrr;

    do {
        pwrr = GICR_READ_REG(dev, rdist_id, GICR_PWRR);

    /* Check group not transitioning: RDGPD == RDGPO */
    } while (((pwrr & GICR_PWRR_RDGPD) >> GICR_PWRR_RDGPD_SHIFT) !=
             ((pwrr & GICR_PWRR_RDGPO) >> GICR_PWRR_RDGPO_SHIFT));
}

static int gic_rdist_pwr_on(struct gic_mv_dev_t *dev, uint8_t rdist_id)
{
    /* Check if redistributor needs power management */
    if (GICR_READ_REG(dev, rdist_id, GICR_IIDR) < GICR_IIDR_ARM_GIC_720AE)
        return -1;

    do {
        /* Wait until group not transitioning */
        gicr_wait_group_not_in_transit(dev, rdist_id);

        /* Power on redistributor */
        GICR_WRITE_REG(dev, rdist_id, GICR_PWRR, GICR_PWRR_ON);

        /*
         * Wait until the power on state is reflected.
         * If RDPD == 0 then powered on.
         */
    } while ((GICR_READ_REG(dev, rdist_id, GICR_PWRR) & GICR_PWRR_RDPD)
             != GICR_PWRR_ON);

    return 0;
}

int gic_multiple_view_device_probe(struct gic_mv_dev_t *dev,
                                   uintptr_t base_addr,
                                   uint16_t view_num,
                                   uint16_t rdist_num)
{
    uint32_t val;

    dev->view_num  = view_num;
    dev->rdist_num = rdist_num;
    dev->gicd_base = base_addr;
    dev->gicr_base = base_addr + SI_GICR_OFFSET;

    /* Check the GIC version to decide GICR frame size. */
    val = GICD_READ_REG(dev, GICD_PIDR2) & GICD_PIDR2_ARCH_MASK;
    val >>= 4;
    if (val == GICD_PIDR2_ARCH_GICv3)
        dev->rdist_sz = SI_GICR_FRAME_SZ_v3;
    else if (val == GICD_PIDR2_ARCH_GICv4)
        dev->rdist_sz = SI_GICR_FRAME_SZ_v4;
    else {
        BOOT_LOG_ERR("GIC: Un-supported GIC version:%d", val);
        return -1;
    }

    /* Read GICD_CFGID bit-53 to detect multiple view feature. */
    val = GICD_READ_REG(dev, GICD_CFGID + 4);
    if (!(val & GICD_CFGID_HI_MV)) {
        BOOT_LOG_ERR("GIC: Could not detect Multiple Views Support!");
        return -1;
    }

    BOOT_LOG_INF("GIC: Multiple Views Support detected!");

    if (gic_rdist_pwr_on(dev, GICR_CLUS0_ID) ||
        gic_rdist_pwr_on(dev, GICR_CLUS1_ID) ||
        gic_rdist_pwr_on(dev, GICR_CLUS2_ID)) {
        BOOT_LOG_ERR("GIC: Could not power on redistributor!");
        return -1;
    }

    return 0;
}
