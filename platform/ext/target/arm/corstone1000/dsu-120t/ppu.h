/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
#ifndef PPU_H
#define PPU_H

#include <stdbool.h>
#include <stdint.h>
#include "platform_base_address.h"

// Bit definition for PPU_PWPR register
#define PPU_PWPR_PWR_POLICY_Pos            (0U)                                // Power mode policy
#define PPU_PWPR_PWR_POLICY_Msk            (0xFUL << PPU_PWPR_PWR_POLICY_Pos)  // 4 bits
#define PPU_PWPR_PWR_POLICY_OFF            (0UL << PPU_PWPR_PWR_POLICY_Pos)    // Logic off and RAM off.
#define PPU_PWPR_PWR_POLICY_OFF_EMU        (1UL << PPU_PWPR_PWR_POLICY_Pos)    // Emulated Off. Logic on with RAM on. This mode is used to emulate the functional condition of OFF without removing
#define PPU_PWPR_PWR_POLICY_MEM_RET        (2UL << PPU_PWPR_PWR_POLICY_Pos)    // Memory Retention. Logic off with RAM retained.
#define PPU_PWPR_PWR_POLICY_MEM_RET_EMU    (3UL << PPU_PWPR_PWR_POLICY_Pos)    // Emulated Memory Retention. Logic on with RAM on. This mode is used to emulate the functional condition of
#define PPU_PWPR_PWR_POLICY_FULL_RET       (5UL << PPU_PWPR_PWR_POLICY_Pos)    // Full Retention. Slice logic off with RAM contents retained.
#define PPU_PWPR_PWR_POLICY_FUNC_RET       (7UL << PPU_PWPR_PWR_POLICY_Pos)    // Functional Retention. Logic on with L3 Cache and Snoop Filter retained.
#define PPU_PWPR_PWR_POLICY_ON             (8UL << PPU_PWPR_PWR_POLICY_Pos)    // Logic on with RAM on, cluster is functional.
#define PPU_PWPR_PWR_POLICY_WARM_RST       (9UL << PPU_PWPR_PWR_POLICY_Pos)    // Warm Reset. Warm reset application with logic and RAM on.
#define PPU_PWPR_PWR_POLICY_DBG_RECOV      (10UL << PPU_PWPR_PWR_POLICY_Pos)   // Debug Recovery Reset. Warm reset application with logic and RAM on.
#define PPU_PWPR_PWR_DYN_EN_Pos            (8U)                                // Power mode dynamic transition enable.
#define PPU_PWPR_PWR_DYN_EN_Msk            (0x1UL << PPU_PWPR_PWR_DYN_EN_Pos)  // 1 bit
#define PPU_PWPR_LOCK_EN_Pos               (12U)                               // Lock enable bit for OFF, OFF_EMU, MEM_RET and MEM_RET_EMU power modes.
#define PPU_PWPR_LOCK_EN_Msk               (0x1UL << PPU_PWPR_LOCK_EN_Pos)     // 1 bit
#define PPU_PWPR_OP_POLICY_Pos             (16U)                               // Operating mode policy
#define PPU_PWPR_OP_POLICY_Msk             (0xFUL << PPU_PWPR_OP_POLICY_Pos)   // 4 bits
#define PPU_PWPR_OP_POLICY_OPMODE_00       (0UL << PPU_PWPR_OP_POLICY_Pos)     // ONE_SLICE_SF_ONLY_ON: One L3 Cache slice is operational, the Cache RAM is powered down.
#define PPU_PWPR_OP_POLICY_OPMODE_01       (1UL << PPU_PWPR_OP_POLICY_Pos)     // ONE_SLICE_HALF_RAM_ON: One L3 Cache slice is operational, half of the Cache RAMs are powered on.
#define PPU_PWPR_OP_POLICY_OPMODE_03       (3UL << PPU_PWPR_OP_POLICY_Pos)     // ONE_SLICE_FULL_RAM_ON: One L3 Cache slice is operational, all of the Cache RAMs are powered on.
#define PPU_PWPR_OP_POLICY_OPMODE_04       (4UL << PPU_PWPR_OP_POLICY_Pos)     // ALL_SLICE_SF_ONLY_ON: All L3 Cache slices are operational, the Cache RAMs in each slice are powered down.
#define PPU_PWPR_OP_POLICY_OPMODE_05       (5UL << PPU_PWPR_OP_POLICY_Pos)     // ALL_SLICE_HALF_RAM_ON: All L3 Cache slices are operational, half of the Cache RAMs are powered on.
#define PPU_PWPR_OP_POLICY_OPMODE_07       (7UL << PPU_PWPR_OP_POLICY_Pos)     // ALL_SLICE_FULL_RAM_ON: All L3 Cache slices are operational, all of the Cache RAMs are powered on.
#define PPU_PWPR_OP_POLICY_OPMODE_08       (8UL << PPU_PWPR_OP_POLICY_Pos)     // HALF_SLICE_SF_ONLY_ON: Half L3 Cache slices are operational, the Cache RAMs in each slice are powered down.
#define PPU_PWPR_OP_POLICY_OPMODE_09       (9UL << PPU_PWPR_OP_POLICY_Pos)     // HALF_SLICE_HALF_RAM_ON: Half L3 Cache slices are operational, half of the Cache RAMs are powered on.
#define PPU_PWPR_OP_POLICY_OPMODE_0B       (11UL << PPU_PWPR_PWR_POLICY_Pos)   // HALF_SLICE_FULL_RAM_ON: Half L3 Cache slices are operational, all of the Cache RAMs are powered on.
#define PPU_PWPR_OP_DYN_EN_Pos             (24U)                               // Operating mode dynamic transition enable.
#define PPU_PWPR_OP_DYN_EN_Msk             (0x1UL << PPU_PWPR_OP_DYN_EN_Pos)   // 1 bit

// Bit definition for PPU_PWSR register
#define PPU_PWSR_PWR_STATUS_Pos            (0U)
#define PPU_PWSR_PWR_STATUS_Msk            (0xFUL << PPU_PWSR_PWR_STATUS_Pos)      // 4 bits
#define PPU_PWSR_PWR_STATUS_OFF            (0UL << PPU_PWSR_PWR_STATUS_Pos)        // Logic off and RAM off.
#define PPU_PWSR_PWR_STATUS_OFF_EMU        (1UL << PPU_PWSR_PWR_STATUS_Pos)        // Emulated Off. Logic on with RAM on. This mode is used to emulate the functional condition of OFF without removing
#define PPU_PWSR_PWR_STATUS_MEM_RET        (2UL << PPU_PWSR_PWR_STATUS_Pos)        // Memory Retention. Logic off with RAM retained.
#define PPU_PWSR_PWR_STATUS_MEM_RET_EMU    (3UL << PPU_PWSR_PWR_STATUS_Pos)        // Emulated Memory Retention. Logic on with RAM on. This mode is used to emulate the functional condition of
#define PPU_PWSR_PWR_STATUS_FULL_RET       (5UL << PPU_PWSR_PWR_STATUS_Pos)        // Full Retention. Slice logic off with RAM contents retained.
#define PPU_PWSR_PWR_STATUS_FUNC_RET       (7UL << PPU_PWSR_PWR_STATUS_Pos)        // Functional Retention. Logic on with L3 Cache and Snoop Filter retained.
#define PPU_PWSR_PWR_STATUS_ON             (8UL << PPU_PWSR_PWR_STATUS_Pos)        // Logic on with RAM on, cluster is functional.
#define PPU_PWSR_PWR_STATUS_WARM_RST       (9UL << PPU_PWSR_PWR_STATUS_Pos)        // Warm Reset. Warm reset application with logic and RAM on.
#define PPU_PWSR_PWR_STATUS_DBG_RECOV      (10UL << PPU_PWSR_PWR_STATUS_Pos)       // Debug Recovery Reset. Warm reset application with logic and RAM on.
#define PPU_PWSR_PWR_DYN_STATUS_Pos        (8U)                                    // Power mode dynamic transition enable.
#define PPU_PWSR_PWR_DYN_STATUS_Msk        (0x1UL << PPU_PWSR_PWR_DYN_STATUS_Pos)  // 1 bit
#define PPU_PWSR_LOCK_STATUS_Pos           (12U)                                   // Lock enable bit for OFF, OFF_EMU, MEM_RET and MEM_RET_EMU power modes.
#define PPU_PWSR_LOCK_STATUS_Msk           (0x1UL << PPU_PWSR_LOCK_STATUS_Pos)     // 1 bit
#define PPU_PWSR_OP_STATUS_Pos             (16U)                                   // Operating mode policy
#define PPU_PWSR_OP_STATUS_Msk             (0xFUL << PPU_PWSR_OP_STATUS_Pos)       // 4 bits
#define PPU_PWSR_OP_STATUS_OPMODE_00       (0UL << PPU_PWSR_OP_STATUS_Pos)         // ONE_SLICE_SF_ONLY_ON: One L3 Cache slice is operational, only the snoop filter RAM instances are active in the slice
#define PPU_PWSR_OP_STATUS_OPMODE_01       (1UL << PPU_PWSR_OP_STATUS_Pos)         // ONE_SLICE_HALF_RAM_ON: One L3 Cache slice is operational, half of the Cache RAMs are powered on.
#define PPU_PWSR_OP_STATUS_OPMODE_03       (3UL << PPU_PWSR_OP_STATUS_Pos)         // ONE_SLICE_FULL_RAM_ON: One L3 Cache slice is operational, all of the Cache RAMs are powered on.
#define PPU_PWSR_OP_STATUS_OPMODE_04       (4UL << PPU_PWSR_OP_STATUS_Pos)         // ALL_SLICE_SF_ONLY_ON: All L3 Cache slices are operational, the Cache RAMs in each slice are powered down.
#define PPU_PWSR_OP_STATUS_OPMODE_05       (5UL << PPU_PWSR_OP_STATUS_Pos)         // ALL_SLICE_HALF_RAM_ON: All L3 Cache slices are operational, half of the Cache RAMs are powered on.
#define PPU_PWSR_OP_STATUS_OPMODE_07       (7UL << PPU_PWSR_OP_STATUS_Pos)         // ALL_SLICE_FULL_RAM_ON: All L3 Cache slices are operational, all of the Cache RAMs are powered on.
#define PPU_PWSR_OP_STATUS_OPMODE_08       (8UL << PPU_PWSR_OP_STATUS_Pos)         // HALF_SLICE_SF_ONLY_ON: Half L3 Cache slices are operational, the Cache RAMs in each slice are powered down.
#define PPU_PWSR_OP_STATUS_OPMODE_09       (9UL << PPU_PWSR_OP_STATUS_Pos)         // HALF_SLICE_HALF_RAM_ON: Half L3 Cache slices are operational, half of the Cache RAMs are powered on.
#define PPU_PWSR_OP_STATUS_OPMODE_0B       (11UL << PPU_PWSR_OP_STATUS_Pos)        // HALF_SLICE_FULL_RAM_ON: Half L3 Cache slices are operational, all of the Cache RAMs are powered on.
#define PPU_PWSR_OP_DYN_STATUS_Pos         (24U)                                   // Operating mode dynamic transition enable.
#define PPU_PWSR_OP_DYN_STATUS_Msk         (0x1UL << PPU_PWSR_OP_DYN_STATUS_Pos)   // 1 bit

/*!< PPU memory offsets */
#define DSU_120T_CLUSTER_PPU_OFFSET  0x030000
#define DSU_120T_CORE0_PPU_OFFSET    0x080000
#define DSU_120T_CORE1_PPU_OFFSET    0x180000
#define DSU_120T_CORE2_PPU_OFFSET    0x280000
#define DSU_120T_CORE3_PPU_OFFSET    0x380000

/*!< PPU memory map */
#define CLUSTER_PPU_BASE (CORSTONE1000_HOST_DSU_120T_BASE + DSU_120T_CLUSTER_PPU_OFFSET)
#define CORE0_PPU_BASE (CORSTONE1000_HOST_DSU_120T_BASE + DSU_120T_CORE0_PPU_OFFSET)
#define CORE1_PPU_BASE (CORSTONE1000_HOST_DSU_120T_BASE + DSU_120T_CORE1_PPU_OFFSET)
#define CORE2_PPU_BASE (CORSTONE1000_HOST_DSU_120T_BASE + DSU_120T_CORE2_PPU_OFFSET)
#define CORE3_PPU_BASE (CORSTONE1000_HOST_DSU_120T_BASE + DSU_120T_CORE3_PPU_OFFSET)

/*!< PPU declarations */
#define CLUSTER_PPU ((PPU_TypeDef *) CLUSTER_PPU_BASE)
#define CORE0_PPU   ((PPU_TypeDef *) CORE0_PPU_BASE)
#define CORE1_PPU   ((PPU_TypeDef *) CORE1_PPU_BASE)
#define CORE2_PPU   ((PPU_TypeDef *) CORE2_PPU_BASE)
#define CORE3_PPU   ((PPU_TypeDef *) CORE3_PPU_BASE)

typedef struct
{
    volatile uint32_t PWPR;                      /*!< PPU Power Policy Register, Address offset: 0x00 */
    volatile uint32_t PMER;                      /*!< PPU Power Mode Emulation Enable Register, Address offset: 0x04 */
    volatile uint32_t PWSR;                      /*!< PPU Power Status Register, Address offset: 0x08 */
    volatile uint32_t RESERVED0;                 /*!< Reserved, Address offset: 0x0C */
    volatile uint32_t DISR;                      /*!< PPU Device Interface Input Current Status Register, Address offset: 0x10 */
    volatile uint32_t MISR;                      /*!< PPU Miscellaneous Input Current Status Register, Address offset: 0x14 */
    volatile uint32_t STSR;                      /*!< PPU Stored Status Register, Address offset: 0x18 */
    volatile uint32_t UNLK;                      /*!< PPU Unlock Register, Address offset: 0x1C */
    volatile uint32_t PWCR;                      /*!< PPU Power Configuration Register, Address offset: 0x20 */
    volatile uint32_t PTCR;                      /*!< PPU Power Mode Transition Register, Address offsets: 0x24 */
    volatile uint32_t RESERVED1[2];              /*!< Reserved: Address offsets 0x28 - 0x2C */
    volatile uint32_t IMR;                       /*!< PPU Interrupt Mask Register, Address offsets: 0x30 */
    volatile uint32_t AIMR;                      /*!< PPU Additional Interrupt Mask Register, Address offsets: 0x34 */
    volatile uint32_t ISR;                       /*!< PPU Interrupt Status Register, Address offsets: 0x38 */
    volatile uint32_t AISR;                      /*!< PPU Additional Interrupt Status Register, Address offsets: 0x3C */
    volatile uint32_t IESR;                      /*!< PPU Input Edge Sensitivity Register	Address offsets: 0x040 */
    volatile uint32_t OPSR;                      /*!< PPU Operating Mode Active Edge Sensitivity Register	Address offsets: 0x044 */
    volatile uint32_t RESERVED2[2];              /*!< Reserved: Address offsets 0x48 - 0x4C */
    volatile uint32_t FUNRR;                     /*!< Functional Retention RAM Configuration Register	Address offsets: 0x050 */
    volatile uint32_t FULRR;                     /*!< Full Retention RAM Configuration Register	Address offsets: 0x054 */
    volatile uint32_t MEMRR;                     /*!< Memory Retention RAM Configuration Register	Address offsets: 0x058 */
    volatile uint32_t RESERVED3[69];             /*!< Reserved: Address offsets 0x5C - 0x16C */
    volatile uint32_t DCDR0;                     /*!< Device Control Delay Configuration Register 0	Address offsets: 0x170 */
    volatile uint32_t DCDR1;                     /*!< Device Control Delay Configuration Register 1	Address offsets: 0x174 */
    volatile uint32_t RESERVED4[910];            /*!< Reserved, offsets 0x178 - 0xFAC */
    volatile uint32_t IDR0;                      /*!< PPU Identification Register 0, Address offsets: 0xFB0 */
    volatile uint32_t IDR1;                      /*!< PPU Identification Register 1, Address offsets: 0xFB4 */
    volatile uint32_t RESERVED5[4];             /*!< Reserved, offsets 0xFB8 - 0xFC4 */
    volatile uint32_t IIDR;                      /*!< PPU Implementation Identification Register, Address offsets: 0xFC8 */
    volatile uint32_t AIDR;                      /*!< PPU Architecture Identification Register, Address offsets: 0xFCC */
    volatile uint32_t PIDR4;                     /*!< PPU Peripheral Identification Register 4, Address offsets: 0xFD0 */
    volatile uint32_t PIDR5;                     /*!< PPU Peripheral Identification Register 5, Address offsets: 0xFD4 */
    volatile uint32_t PIDR6;                     /*!< PPU Peripheral Identification Register 6, Address offsets: 0xFD8 */
    volatile uint32_t PIDR7;                     /*!< PPU Peripheral Identification Register 7, Address offsets: 0xFDC */
    volatile uint32_t PIDR0;                     /*!< PPU Peripheral Identification Register 0, Address offsets: 0xFE0 */
    volatile uint32_t PIDR1;                     /*!< PPU Peripheral Identification Register 1, Address offsets: 0xFE4 */
    volatile uint32_t PIDR2;                     /*!< PPU Peripheral Identification Register 2, Address offsets: 0xFE8 */
    volatile uint32_t PIDR3;                     /*!< PPU Peripheral Identification Register 3, Address offsets: 0xFEC */
    volatile uint32_t CIDR0;                     /*!< PPU Component Identification Register 0,	Address offsets: 0xFF0 */
    volatile uint32_t CIDR1;                     /*!< PPU Component Identification Register 1,	Address offsets: 0xFF4 */
    volatile uint32_t CIDR2;                     /*!< PPU Component Identification Register 2,	Address offsets: 0xFF8 */
    volatile uint32_t CIDR3;                     /*!< PPU Component Identification Register 3,	Address offsets: 0xFFC */
} PPU_TypeDef;

typedef enum {
    PPU_PWR_MODE_OFF         = 0, // Logic off and RAM off.
    PPU_PWR_MODE_OFF_EMU     = 1, // Emulated Off. Logic on with RAM on. This mode is used to emulate the functional condition of OFF without removing
    PPU_PWR_MODE_MEM_RET     = 2, // Memory Retention. Logic off with RAM retained.
    PPU_PWR_MODE_MEM_RET_EMU = 3, // Emulated Memory Retention. Logic on with RAM on. This mode is used to emulate the functional condition of
    PPU_PWR_MODE_FULL_RET    = 5, // Full Retention. Slice logic off with RAM contents retained.
    PPU_PWR_MODE_FUNC_RET    = 7, // Functional Retention. Logic on with L3 Cache and Snoop Filter retained.
    PPU_PWR_MODE_ON          = 8, // Logic on with RAM on, cluster is functional.
    PPU_PWR_MODE_WARM_RST    = 9, // Warm Reset. Warm reset application with logic and RAM on.
    PPU_PWR_MODE_DBG_RECOV   = 10 // Debug Recovery Reset. Warm reset application with logic and RAM on.
} PPU_PowerPolicy_Type;

typedef enum {
    PPU_OP_MODE_ONE_SLICE_SF_ONLY_ON   = 0, // One L3 Cache slice is operational, only the snoop filter RAM instances are active in the slice
    PPU_OP_MODE_ONE_SLICE_HALF_RAM_ON  = 1, // One L3 Cache slice is operational, half of the Cache RAMs are powered on.
    PPU_OP_MODE_ONE_SLICE_FULL_RAM_ON  = 3, // One L3 Cache slice is operational, all of the Cache RAMs are powered on.
    PPU_OP_MODE_ALL_SLICE_SF_ONLY_ON   = 4, // All L3 Cache slices are operational, the Cache RAMs in each slice are powered down.
    PPU_OP_MODE_ALL_SLICE_HALF_RAM_ON  = 5, // All L3 Cache slices are operational, half of the Cache RAMs are powered on.
    PPU_OP_MODE_ALL_SLICE_FULL_RAM_ON  = 7, // All L3 Cache slices are operational, all of the Cache RAMs are powered on.
    PPU_OP_MODE_HALF_SLICE_SF_ONLY_ON  = 8, // Half L3 Cache slices are operational, the Cache RAMs in each slice are powered down.
    PPU_OP_MODE_HALF_SLICE_HALF_RAM_ON = 9, // Half L3 Cache slices are operational, half of the Cache RAMs are powered on.
    PPU_OP_MODE_HALF_SLICE_FULL_RAM_ON = 11 // Half L3 Cache slices are operational, all of the Cache RAMs are powered on.
} PPU_OperatingPolicy_Type;

/**
 * @brief  Set the power policy for a given PPU instance.
 *         Only modifies PWR_POLICY and PWR_DYN_EN bits.
 * @param  ppu: Pointer to the PPU instance (e.g., CLUSTER_PPU, CORE0_PPU1)
 * @param  policy: Power mode policy (e.g., PPU_PWR_MODE_ON)
 * @param  dynamic: Enable dynamic transitions enabled for power modes, allowing transitions to be initiated by changes on power mode DEVACTIVE inputs if non-zero
 * @retval None
 */
void PPU_SetPowerPolicy(PPU_TypeDef *ppu, PPU_PowerPolicy_Type policy, bool isDynamic);

/**
 * @brief  Set the operating mode policy for a given PPU instance.
*          Only modifies OP_POLICY and OP_DYN_EN bits.
 * @param  ppu: Pointer to the PPU instance (e.g., CLUSTER_PPU, CORE0_PPU)
 * @param  policy: Operating mode policy (e.g., PPU_OP_MODE_ONE_SLICE_SF_ONLY_ON)
 * @param  dynamic: Enable dynamic transitions enabled for operating modes, allowing transitions to be initiated by changes on operating mode DEVACTIVE inputs if non-zero
 * @retval None
 */
void PPU_SetOperatingPolicy(PPU_TypeDef *ppu, PPU_OperatingPolicy_Type policy, bool isDynamic);

#endif /* PPU_H */
