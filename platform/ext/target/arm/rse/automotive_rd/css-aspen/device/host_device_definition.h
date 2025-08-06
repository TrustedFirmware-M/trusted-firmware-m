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
extern const struct ppu_dev_t HOST_SI_CL0_CLUS_PPU_DEV;
extern const struct ppu_dev_t HOST_SI_CL0_CORE0_PPU_DEV;
#endif /* PLATFORM_HOST_HAS_SI_CL0 */

#ifdef PLATFORM_RSE_HAS_ATU_OWNERSHIP
#include "atu_rse_drv.h"
enum ATU_ACCESS_TYPE {
    ATU_ACCESS_DEFAULT,
    ATU_ACCESS_SECURE,
    ATU_ACCESS_NON_SECURE,
};

/* Structure used to describe an ATU region */
struct atu_map {
    /* Logical start address */
    uint32_t log_addr;
    /* Physical start address */
    uint64_t phy_addr;
    /* Size of the ATU region */
    uint32_t size;
    /* Access Type */
    enum ATU_ACCESS_TYPE access_type;
};
#endif /* PLATFORM_RSE_HAS_ATU_OWNERSHIP */

#ifdef __cplusplus
}
#endif

#endif  /* __HOST_DEVICE_DEFINITION_H__ */
