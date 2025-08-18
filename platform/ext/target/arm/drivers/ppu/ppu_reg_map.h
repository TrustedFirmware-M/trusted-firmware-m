/*
 * SPDX-License-Identifier: BSD-3-Clause
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 */

#ifndef __PPU_REG_MAP_H__
#define __PPU_REG_MAP_H__

#include <stdint.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

struct ppu_reg_map_t {
    volatile uint32_t pwpr;
                /*!< Offset: 0x000 (R/W) Power Policy Register */
    volatile uint32_t pwps;
                /*!< Offset: 0x004 (R/ ) Power Policy Status Register */
    volatile uint32_t pwsr;
                /*!< Offset: 0x008 (R/ ) Power Status Register */
    volatile uint32_t pwcr;
                /*!< Offset: 0x00C (R/W) Power Control Register */
    volatile uint32_t pwnsleep;
                /*!< Offset: 0x010 (R/W) Power Non-sleep Register */
    volatile uint32_t pwreset;
                /*!< Offset: 0x014 (R/W) Power Reset Register */
    volatile uint32_t reserved0[2];
                /*!< Offset: 0x018–0x01C Reserved */
    volatile uint32_t pwpr_devactive;
                /*!< Offset: 0x020 (R/W) Device Active Enable Register */
    volatile uint32_t reserved1[55];
                /*!< Offset: 0x024–0x0FC Reserved */
    volatile uint32_t pidr4;
                /*!< Offset: 0xFD0 (R/ ) Peripheral ID4 */
    volatile uint32_t reserved2[3];
                /*!< Offset: 0xFD4–0xFDC Reserved */
    volatile uint32_t pidr0;
                /*!< Offset: 0xFE0 (R/ ) Peripheral ID0 */
    volatile uint32_t pidr1;
                /*!< Offset: 0xFE4 (R/ ) Peripheral ID1 */
    volatile uint32_t pidr2;
                /*!< Offset: 0xFE8 (R/ ) Peripheral ID2 */
    volatile uint32_t pidr3;
                /*!< Offset: 0xFEC (R/ ) Peripheral ID3 */
    volatile uint32_t cidr0;
                /*!< Offset: 0xFF0 (R/ ) Component ID0 */
    volatile uint32_t cidr1;
                /*!< Offset: 0xFF4 (R/ ) Component ID1 */
    volatile uint32_t cidr2;
                /*!< Offset: 0xFF8 (R/ ) Component ID2 */
    volatile uint32_t cidr3;
                /*!< Offset: 0xFFC (R/ ) Component ID3 */
};

#ifdef __cplusplus
}
#endif

#endif /* __PPU_REG_MAP_H__ */
