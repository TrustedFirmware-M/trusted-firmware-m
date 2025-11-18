/*
 * SPDX-License-Identifier: BSD-3-Clause
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 */

#ifndef __PPU_REG_MAP_H__
#define __PPU_REG_MAP_H__

#include <stdint.h>
#include <stddef.h>

#ifndef __IM
#define __IM volatile const /*! Defines 'read only' structure member permissions */
#endif /* __IM */

#ifndef __OM
#define __OM volatile /*! Defines 'write only' structure member permissions */
#endif /* __OM */

#ifndef __IOM
#define __IOM volatile /*! Defines 'read / write' structure member permissions */
#endif /* __IOM */

#ifndef __PACKED_STRUCT
#define __PACKED_STRUCT struct __attribute__((packed, aligned(1)))
#endif /* __PACKED_STRUCT */

#ifdef __cplusplus
extern "C" {
#endif

__PACKED_STRUCT ppu_reg_map_t {
    __IOM uint32_t pwpr;
                /*!< Offset: 0x000 (R/W) Power Policy Register */
    __IOM uint32_t pmer;
                /*!< Offset: 0x004 (R/W) Power Mode Emulation Register */
    __IM uint32_t pwsr;
                /*!< Offset: 0x008 (R/ ) Power Status Register */
    __IM uint32_t reserved0;
                /*!< Offset: 0x00C-0x00F (R/ ) Reserved */
    __IM uint32_t disr;
                /*!< Offset: 0x010 (R/ ) Device Interface Input Current Status Register */
    __IM uint32_t misr;
                /*!< Offset: 0x014 (R/ ) Miscellaneous Input Current Status Register */
    __IM uint32_t stsr;
                /*!< Offset: 0x018 (R/ ) Stored Status Register */
    __IOM uint32_t unlk;
                /*!< Offset: 0x01C (R/W) Unlock register */
    __IOM uint32_t pwcr;
                /*!< Offset: 0x020 (R/W) Power Configuration Register */
    __IOM uint32_t ptcr;
                /*!< Offset: 0x024 (R/W) Power Mode Transition Configuration Register */
    __IM uint32_t reserved1[2];
                /*!< Offset: 0x028-0x02F (R/ ) Reserved */
    __IOM uint32_t imr;
                /*!< Offset: 0x030 (R/W) Interrupt Mask Register */
    __IOM uint32_t aimr;
                /*!< Offset: 0x034 (R/W) Additional Interrupt Mask Register */
    __IOM uint32_t isr;
                /*!< Offset: 0x038 (R/W) Interrupt Status Register */
    __IOM uint32_t aisr;
                /*!< Offset: 0x03C (R/W) Additional Interrupt Status Register */
    __IOM uint32_t iesr;
                /*!< Offset: 0x040 (R/W) Input Edge Sensitivity Register */
    __IOM uint32_t opsr;
                /*!< Offset: 0x044 (R/W) Operating Mode Active Edge Sensitivity Register */
    __IM uint32_t reserved2[2];
                /*!< Offset: 0x048-0x04F (R/ ) Reserved */
    __IOM uint32_t funrr;
                /*!< Offset: 0x050 (R/W) Functional Retention RAM Configuration Register */
    __IOM uint32_t fulrr;
                /*!< Offset: 0x054 (R/W) Full Retention RAM Configuration Register */
    __IOM uint32_t memrr;
                /*!< Offset: 0x058 (R/W) Memory Retention RAM Configuration Register */
    __IM uint32_t reserved3[65];
                /*!< Offset: 0x05C-0x15F (R/ ) Reserved */
    __IOM uint32_t edtr[2];
                /*!< Offset: 0x160-0x167 (R/W) Power Mode Entry Delay Registers (0 and 1) */
    __IM uint32_t reserved4[2];
                /*!< Offset: 0x168-0x16F (R/ ) Reserved */
    __IOM uint32_t dcdr[2];
                /*!< Offset: 0x170-0x177 (R/W) Device Control Delay Configuration Registers (0 and 1) */
    __IM uint32_t reserved5[910];
                /*!< Offset: 0x178-0xFAF (R/ ) Reserved */
    __IM uint32_t idr[2];
                /*!< Offset: 0xFB0-0xFB7 (R/ ) PPU Identification Registers (0 and 1) */
    __IM uint32_t reserved6[4];
                /*!< Offset: 0xFB8-0xFC7 (R/ ) Reserved */
    __IM uint32_t iidr;
                /*!< Offset: 0xFC8 (R/ ) Implementation Identification Register */
    __IM uint32_t aidr;
                /*!< Offset: 0xFCC (R/ ) Architecture Identification Register */
    __IM uint32_t identification_registers[12];
                /*!< Offset: 0xFD0-0xFFF (R/ ) IMPLEMENTATION DEFINED Identification Registers */
};

#ifdef __cplusplus
}
#endif

#endif /* __PPU_REG_MAP_H__ */
