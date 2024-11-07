/*
 * SPDX-License-Identifier: BSD-3-Clause
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 */

#ifndef __DCSU_REG_DEFS_H__
#define __DCSU_REG_DEFS_H__

#include <stdint.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

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

#ifndef __PACKED_UNION
#define __PACKED_UNION union __attribute__((packed, aligned(1)))
#endif /* __PACKED_UNION */

#ifndef __ALIGNED
#define __ALIGNED(x) __attribute__((aligned(x)))
#endif /* __ALIGNED */

__PACKED_STRUCT __ALIGNED(4) _dcsu_reg_map_t {
__IOM uint32_t soc_unique_id[2];
            /*!< offset: 0x000 - 0x004 (RW)
             *   SoC Unique ID value.
             *   This register is written once at boot time by the DMA which copy the value from the SoC area OTP fields of RSE OTP.
             *   This register is Write Once from the Control APB after the write it becomes __IM.
             *   This register is __OM to the Diagnostics APB.
             */
__IOM uint32_t soc_family_id[2];
            /*!< offset: 0x008 - 0x00C (RW)
             *   SoC Family ID value.
             *   This register is written once at boot time by the DMA which copy the value from the SoC area OTP fields of RSE OTP.
             *   This register is Write Once from the Control APB after the write it becomes __IM.
             *   This register is __OM to the Diagnostics APB.
             */
__IOM uint32_t soc_serial_number[2];
            /*!< offset: 0x010 - 0x014 (RW)
             *   SoC serial number value.
             *   This register is written once at boot time by the DMA which copy the value from the SoC area OTP fields of RSE OTP.
             *   This register is Write Once from the Control APB after the write it becomes __IM.
             *   This register is __OM to the Diagnostics APB.
             */
__IM uint32_t die_id;
            /*!< offset: 0x018 (WO)
             *   Die ID register.
             *   This register is __OM to both Control APB and the Diagnostics APB.
             */
uint8_t _reserved_0[0x030 - 0x01C];
            /*!< Offset: 0x01C - 0x02C Reserved */
__IOM uint32_t reset_syndrome_immediate;
            /*!< offset: 0x030 (RW)
             *   This register is written once at boot time by the DMA which copy the value from the RESET_SYNDROME system register in RSE.
             *   This register is Write Once from the Control APB after the write it becomes __OM.
             *   This register is __OM to the Diagnostics APB.
             */
__IM uint32_t status[10];
            /*!< offset: 0x034 - 0x05C (WO)
             *   Diagnostics Status 0 register.
             *   This register is __OM to both Control APB and the Diagnostics APB.
             */
uint8_t _reserved_1[0x080 - 0x05C];
            /*!< Offset: 0x05C - 0x07C Reserved */
__IM uint32_t diag_cmd_irq_status;
            /*!< offset: 0x080 (WO)
             *   Diagnostic command IRQ status register.
             *   This register is __OM to the Diagnostics APB and to the Control APB.
             */
__IOM uint32_t diag_cmd_irq_en;
            /*!< offset: 0x084 (RW)
             *   Diagnostic command IRQ enable register.
             *   This register is RW to the Control APB and is __IM to the Diagnostics APB.
             */
__IOM uint32_t diag_cmd_irq_clear;
            /*!< offset: 0x088 (RW)
             *   Diagnostic command IRQ clear register.
             *   This register is RAZW1C to the Control APB and is __IM to the Diagnostics APB.
             */
uint8_t _reserved_2[0x090 - 0x08C];
            /*!< Offset: 0x08C Reserved */
__IOM uint32_t diag_rx_command;
            /*!< offset: 0x090 (RW)
             *   RX Diagnostic command register.
             */
__IOM uint32_t diag_rx_large_param;
            /*!< offset: 0x094 (RW)
             *   RX Diagnostic command large parameter register.
             *   This register is RW to the Diagnostics APB and is __IM to the Control APB.
             */
__IOM uint32_t diag_rx_data[4];
            /*!< offset: 0x098 - 0x0A4 (RW)
             *   RX Diagnostic command Data 0 register.
             *   This register is RW to the Diagnostics APB and is __IM to the Control APB.
             */
uint8_t _reserved_3[0x0C0 - 0x0A8];
            /*!< Offset: 0x0A8 - 0x0BC Reserved */
__IOM uint32_t diag_tx_command;
            /*!< offset: 0x0C0 (RW)
             *   TX Diagnostic command register.
             */
__IOM uint32_t diag_tx_large_param;
            /*!< offset: 0x0C4 (RW)
             *   TX Diagnostic command large parameter register.
             *   This register is RW to the Control APB and is read only to the Diagnostics APB.
             */
__IOM uint32_t diag_tx_data[4];
            /*!< offset: 0x0C8 0x0D4 (RW)
             *   TX Diagnostic command Data 0 register.
             *   This register is RW to the Control APB and is __IM to the Diagnostics APB.
             */
uint8_t _reserved_4[0x0F0 - 0x0D8];
            /*!< Offset: 0x0D8 - 0x0EC Reserved */
__IOM uint32_t device_status;
            /*!< offset: 0x0F0 (RW)
             *   Device Status value.
             *   This register is written once at boot time by the DMA which copy the value from the Dynamic area OTP fields of RSE OTP.
             *   This register is Write Once from the Control APB after the write it
             */
__IOM uint32_t boot_info;
            /*!< offset: 0x0F4 (RW)
             *   Boot information registers.
             *   This register is programmed by RSE bootloaders and firmware to mark successfully passed boot stages.
             *   This register is RW to the Control APB and is __IM to the Diagnostics APB.
             */
__IOM uint32_t sw_defined[2];
            /*!< offset: 0x0F8 - 0x0FC (RW)
             *   Software defined status registers.
             *   This register is set by RSE bootloaders and firmware per their needs with non secret information they want to share with the external world.
             *   This register is RW to the Control APB and is __IM to the Diagnostics APB.
             */
uint8_t _reserved_5[0x120 - 0x100];
            /*!< Offset: 0x0100 - 0x011C Reserved */
__OM uint32_t prst_reset_synd__imme;
            /*!< offset: 0x120 (RO) This register captures the pre reset value of the RESET_SYNDROME register at the transition of nCOLDRESETAON to 0.
             */
__IM uint32_t prst_status0[10];
            /*!< offset: 0x124 - 0x14C (WO)
             *   This register captures the pre reset value of the input signals of the STATUS0 register at the transition of nCOLDRESETAON to 0.
             */
__IM uint32_t prst_custom_status0;
            /*!< offset: 0x150 (WO)
             *   This register captures the pre reset value of the input signals of the CUSTOM_STATUS0 register at the transition of nCOLDRESETAON to 0.
             */
uint8_t _reserved_6[0xF00 - 0x154];
            /*!< Offset: 0x0154 - 0x0EFC Reserved */
uint8_t _reserved_7[0xFD0 - 0xF00];
            /*!< offset: 0xF00 - 0x0FCC (WO)
             *   Reserved.
             *   Read as 0s to provide CoreSight component look and feel compatibility.
             */
__IM uint32_t pidr4;
            /*!< offset: 0xFD0 (WO)
             *   Peripheral ID 4
             */
uint8_t _reserved_8[0xFE0 - 0xFD4];
            /*!< Offset: 0x0FD4 - 0x0FDC Reserved */
__IM uint32_t pidr0;
            /*!< offset: 0xFE0 (WO)
             *   Peripheral ID 0
             */
__IM uint32_t pidr1;
            /*!< offset: 0xFE4 (WO)
             *   Peripheral ID 1
             */
__IM uint32_t pidr2;
            /*!< offset: 0xFE8 (WO)
             *   Peripheral ID 2
             */
__IM uint32_t pidr3;
            /*!< offset: 0xFEC (WO)
             *   Peripheral ID 3
             */
__IM uint32_t cidr0;
            /*!< offset: 0xFF0 (WO)
             *   Component ID 0
             */
__IM uint32_t cidr1;
            /*!< offset: 0xFF4 (WO)
             *   Component ID 1 */
__IM uint32_t cidr2;
            /*!< offset: 0xFF8 (WO)
             *   Component ID 2
             */
__IM uint32_t cidr3;
            /*!< offset: 0xFFC (WO)
             *   Component ID 3
             */
};

#ifdef __cplusplus
}
#endif

#endif /* __DCSU_REG_DEFS_H__ */
