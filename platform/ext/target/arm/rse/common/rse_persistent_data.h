/*
 * SPDX-License-Identifier: BSD-3-Clause
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 */

#ifndef __RSE_PERSISTENT_DATA_H__
#define __RSE_PERSISTENT_DATA_H__

/*
 * The persistent data region is for information that is expected to persist
 * resets. This is not expected to have a value on a cold boot. This can be
 * used to communicate between resets such as when debug is enabled or whether
 * the last boot was successful.
 */

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include "cmsis.h"
#include "region_defs.h"

#define RSE_PERSISTENT_DATA ((struct rse_persistent_data *)PERSISTENT_DATA_BASE)

/**
 * @brief RSE Persistent Data Flags Layout (retained until POR).
 *
 * @details
 * Persistent data flags capture reset-related state across reboots.
 * On systems that provide General Purpose Always-On (GPAON) registers,
 * these registers are used only if there are enough to cover the entire
 * persistent data flag section. If insufficient GPAON registers are
 * available, the flags are stored in SRAM instead. GPAON is generally
 * preferred as it is more reliable than SRAM for retaining state between
 * resets.
 *
 * @par Flag Register Map (flag_register[0])
 *   bit  | name                            | width | description
 *  ------+---------------------------------+-------+------------------------------------
 *    0   | IS_RESET_COOKIE_AVAILABLE       |   1   | Set early in boot before RST_SYN
 *    1   | IS_RESET_COOKIE_READ_AND_CLEARED|   1   | Indicates reset cookie was read & cleared
 *   3:2  | RESET_COOKIE                    |   2   | Encodes cause: external reset / SWRESETREQ
 *  11:4  | RESET_COOKIE_SWSYN              |   8   | Mirrors RESET_SYNDROME.SWSYN[31:28]
 *  20:12 | LAST_BOOT_DEBUG_CODE            |   8   | Captures debug code from last boot
 *  21:20 | IS_SRAM_INITIALIZED             |   1   | Indicates whether SRAM was initialized
 *
 * @par Reset Cookie Inference Table
 *   is_available | is_read_and_cleared | Inference
 *   ------------ | ------------------- | -----------------------------------------
 *       0        |         0           | Non-SW-initiated reset
 *       1        |         0           | Read reset_cookie from AON_REG
 *       0        |         1           | Read reset_cookie from SRAM
 *       1        |         1           | Read reset_cookie from AON_REG (unexpected case)
 *
 * @note
 * - Flags persist until a Power-On Reset (POR).
 * - Ensure this comment block stays synchronized with the bitmask/shift
 *   definitions below.
 */

#define RSE_PERSISTENT_DATA_FLAGS_IS_RESET_COOKIE_AVAILABLE_BITFIELD_POS 0
#define RSE_PERSISTENT_DATA_FLAGS_IS_RESET_COOKIE_AVAILABLE_BITFIELD_WIDTH 1
#define RSE_PERSISTENT_DATA_FLAGS_IS_RESET_COOKIE_AVAILABLE \
        RSE_PERSISTENT_DATA_FLAGS_IS_RESET_COOKIE_AVAILABLE_BITFIELD_POS, \
        RSE_PERSISTENT_DATA_FLAGS_IS_RESET_COOKIE_AVAILABLE_BITFIELD_WIDTH

#define RSE_PERSISTENT_DATA_FLAGS_IS_RESET_COOKIE_READ_AND_CLEARED_BITFIELD_POS 1
#define RSE_PERSISTENT_DATA_FLAGS_IS_RESET_COOKIE_READ_AND_CLEARED_BITFIELD_WIDTH 1
#define RSE_PERSISTENT_DATA_FLAGS_IS_RESET_COOKIE_READ_AND_CLEARED \
        RSE_PERSISTENT_DATA_FLAGS_IS_RESET_COOKIE_READ_AND_CLEARED_BITFIELD_POS, \
        RSE_PERSISTENT_DATA_FLAGS_IS_RESET_COOKIE_READ_AND_CLEARED_BITFIELD_WIDTH

#define RSE_PERSISTENT_DATA_FLAGS_RESET_COOKIE_BITFIELD_POS 2
#define RSE_PERSISTENT_DATA_FLAGS_RESET_COOKIE_BITFIELD_WIDTH 2
#define RSE_PERSISTENT_DATA_FLAGS_RESET_COOKIE \
        RSE_PERSISTENT_DATA_FLAGS_RESET_COOKIE_SWSWYN_BITFIELD_POS, \
        RSE_PERSISTENT_DATA_FLAGS_RESET_COOKIE_SWSWYN_BITFIELD_WIDTH

#define RSE_PERSISTENT_DATA_FLAGS_LAST_BOOT_DEBUG_CODE_BITFIELD_POS 12
#define RSE_PERSISTENT_DATA_FLAGS_LAST_BOOT_DEBUG_CODE_BITFIELD_WIDTH 8
#define RSE_PERSISTENT_DATA_FLAGS_LAST_BOOT_DEBUG_CODE \
        RSE_PERSISTENT_DATA_FLAGS_LAST_BOOT_DEBUG_CODE_BITFIELD_POS, \
        RSE_PERSISTENT_DATA_FLAGS_LAST_BOOT_DEBUG_CODE_BITFIELD_WIDTH

#define RSE_PERSISTENT_DATA_FLAGS_IS_SRAM_INITIALIZED_BITFIELD_POS 20
#define RSE_PERSISTENT_DATA_FLAGS_IS_SRAM_INITIALIZED_BITFIELD_WIDTH 1
#define RSE_PERSISTENT_DATA_FLAGS_IS_SRAM_INITIALIZED \
        RSE_PERSISTENT_DATA_FLAGS_IS_SRAM_INITIALIZED_BITFIELD_POS, \
        RSE_PERSISTENT_DATA_FLAGS_IS_SRAM_INITIALIZED_BITFIELD_WIDTH

/* Update below macro when new persistent data flag entry is added */
#define RSE_PERSISTENT_DATA_FLAGS_TOTAL_BIT_WIDTH \
    RSE_PERSISTENT_DATA_FLAGS_IS_SRAM_INITIALIZED_BITFIELD_POS + \
    RSE_PERSISTENT_DATA_FLAGS_IS_SRAM_INITIALIZED_BITFIELD_WIDTH

/* Bit-flip resistant enums */
enum LAST_BOOT_DEBUG_CODE {
    LAST_BOOT_DEBUG_CODE_APPLY_CERT_DEBUG = 0x5A,
    LAST_BOOT_DEBUG_CODE_BLOCK_CERT_DEBUG = 0xA5,
};

#ifndef NUM_OF_PERSISTENT_FLAG_REGS
#define NUM_OF_PERSISTENT_FLAG_REGS 0
#endif /* NUM_OF_PERSISTENT_FLAG_REGS */

/*
 * If there is a sufficient number of GPAON registers use these for persistent
 * data flags, else use SRAM.
 */
#if (NUM_OF_PERSISTENT_FLAG_REGS * 32) >= RSE_PERSISTENT_DATA_FLAGS_TOTAL_BIT_WIDTH
#define RSE_PERSISTENT_DATA_FLAGS_BASE ((uintptr_t)(RSE_PERSISTENT_DATA_FLAGS_GPAON_BASE))
#else
#define RSE_PERSISTENT_DATA_FLAGS_BASE ((uintptr_t)(RSE_PERSISTENT_DATA->shared_data.flags_data))
#endif /* (NUM_OF_PERSISTENT_FLAG_REGS * 32) >= RSE_PERSISTENT_DATA_FLAGS_TOTAL_BIT_WIDTH */

/*
 * Data in this struct is expected to persist over multiple RSE cold resets,
 * stored in SRAM.
 */
struct rse_persistent_data {
    /* Data in this part of the struct is used by ROM */
    struct rse_bl1_persistent_data {
        /* Provisioning blob buffer pointer */
        uint32_t *provisioning_blob_buf;
        size_t provisioning_blob_buf_size;
        /* Used to keep track of the provisioning message which is staged */
        uint8_t provisioning_staging_status;
    } bl1_data;

    /* Data shared between bootloaders and runtime */
    struct rse_persistent_shared_data {
        uint32_t shared_boot_measurement[SHARED_BOOT_MEASUREMENT_SIZE / sizeof(uint32_t)];
        uint32_t runtime_to_boot_data[RUNTIME_SERVICE_TO_BOOT_SHARED_REGION_SIZE / sizeof(uint32_t)];
#if (NUM_OF_PERSISTENT_FLAG_REGS * 32) < RSE_PERSISTENT_DATA_FLAGS_TOTAL_BIT_WIDTH
        /*
        * Persistent data flags if insufficient GPAON registers available
        */
        uint32_t flags_data[(RSE_PERSISTENT_DATA_FLAGS_TOTAL_BIT_WIDTH + 31)/32 ];
#endif /* (NUM_OF_PERSISTENT_FLAG_REGS * 32) < RSE_PERSISTENT_DATA_FLAGS_TOTAL_BIT_WIDTH */
    } shared_data;
};

void rse_setup_persistent_data(void);

static inline uint32_t get_persistent_data_flag(uint32_t bitfield_pos, uint32_t bitfield_width) {
    uint32_t word_aligned_base = (uint32_t)RSE_PERSISTENT_DATA_FLAGS_BASE +
        ((bitfield_pos/32)*4);
    uint32_t mask = (((1<<bitfield_width)-1) << (bitfield_pos%32));

    return (uint32_t)((*(volatile uint32_t*)word_aligned_base & mask) >> (bitfield_pos%32));
}

static inline void set_persistent_data_flag(uint32_t val, uint32_t bitfield_pos, uint32_t bitfield_width) {
    uint32_t word_aligned_base = (uint32_t)RSE_PERSISTENT_DATA_FLAGS_BASE +
        ((bitfield_pos/32)*4);
    uint32_t mask = (((1<<bitfield_width)-1) << (bitfield_pos%32));
    *(volatile uint32_t*)word_aligned_base &= ~mask;
    *(volatile uint32_t*)word_aligned_base |= ((val << (bitfield_pos%32)) & mask);
}

#endif /* __RSE_PERSISTENT_DATA_H__ */
