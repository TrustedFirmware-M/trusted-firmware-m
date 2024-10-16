/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __ATU_RSE_DRV_INTERNAL_H__
#define __ATU_RSE_DRV_INTERNAL_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \brief ATU register map structure
 */
struct _atu_reg_map_t {
    volatile uint32_t atubc;
                /*!< Offset: 0x000 (R/ ) ATU Build Configuration Register */
    volatile uint32_t atuc;
                /*!< Offset: 0x004 (R/W) ATU Configuration Register */
    volatile uint32_t atuis;
                /*!< Offset: 0x008 (R/ ) ATU Interrupt Status Register */
    volatile uint32_t atuie;
                /*!< Offset: 0x00C (R/W) ATU Interrupt Enable Register */
    volatile uint32_t atuic;
                /*!< Offset: 0x010 (R/W) ATU Interrupt Clear Register */
    volatile uint32_t atuma;
                /*!< Offset: 0x014 (R/ ) ATU Mismatched Address Register */
    volatile uint32_t reserved_0[2];   /*!< Offset: 0x018-0x01C Reserved */
    volatile uint32_t atursla[32];
                /*!< Offset: 0x020 (R/W) ATU Region Start Logical Address n
                *                       Register */
    volatile uint32_t aturela[32];
                /*!< Offset: 0x0A0 (R/W) ATU Region End Logical Address n
                *                       Register */
    volatile uint32_t aturav_l[32];
                /*!< Offset: 0x120 (R/W) ATU Region Add Value Low n Register */
    volatile uint32_t aturav_m[32];
                /*!< Offset: 0x1A0 (R/W) ATU Region Add Value High n Register */
    volatile uint32_t aturoba[32];
                /*!< Offset: 0x220 (R/W) ATU Region Output Bus Attributes n
                *                       Register */
    volatile uint32_t aturgpv[32];
                /*!< Offset: 0x2A0 (R/W) ATU Region General Purpose n Register
                 * Used for storing usage counter for ATU regions */
    volatile uint32_t reserved_1[811]; /*!< Offset: 0x320-0xFCC Reserved */
    volatile uint32_t pidr4;
                /*!< Offset: 0xFD0 (R/ ) Peripheral ID 4 */
    volatile uint32_t reserved_2[2];   /*!< Offset: 0xFD4-0xFDC Reserved */
    volatile uint32_t pidr0;
                /*!< Offset: 0xFE0 (R/ ) Peripheral ID 0 */
    volatile uint32_t pidr1;
                /*!< Offset: 0xFE4 (R/ ) Peripheral ID 1 */
    volatile uint32_t pidr2;
                /*!< Offset: 0xFE8 (R/ ) Peripheral ID 2 */
    volatile uint32_t pidr3;
                /*!< Offset: 0xFEC (R/ ) Peripheral ID 3 */
    volatile uint32_t cidr0;
                /*!< Offset: 0xFF0 (R/ ) Component ID 0 */
    volatile uint32_t cidr1;
                /*!< Offset: 0xFF4 (R/ ) Component ID 1 */
    volatile uint32_t cidr2;
                /*!< Offset: 0xFF8 (R/ ) Component ID 2 */
    volatile uint32_t cidr3;
                /*!< Offset: 0xFFC (R/ ) Component ID 3 */
};

#ifdef __cplusplus
}
#endif

#endif /* __ATU_RSE_DRV_INTERNAL_H__ */
