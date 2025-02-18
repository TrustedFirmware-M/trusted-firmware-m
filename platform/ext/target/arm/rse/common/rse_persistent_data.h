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
#include "config_tfm.h"
#include "region_defs.h"
#ifdef RSE_ENABLE_CHIP_OUTPUT_DATA
#include "rse_provisioning_message.h"
#endif /* RSE_ENABLE_CHIP_OUTPUT_DATA */

#define RSE_PERSISTENT_DATA ((struct rse_persistent_data *)PERSISTENT_DATA_BASE)

/**
 * @brief RSE Persistent Data Flags Layout (retained until POR).
 *
 * @details
 * Persistent data flags capture reset-related state across reboots.
 * On systems that provide General Purpose Always-On (GPAON) registers,
 * these registers are used.
 *
 * @par Flag Register Map (flag_register[0])
 *   bit  | name                            | width | description
 *  ------+---------------------------------+-------+------------------------------------
 *  20:12 | LAST_BOOT_DEBUG_CODE            |   8   | Captures debug code from last boot
 *  21:20 | IS_SRAM_INITIALIZED             |   1   | Indicates whether SRAM was initialized
 *   31   | PERSISTENT_DATA_INITIALIZED     |   1   | Indicates whether the persistent data is initialized
 *
 * @note
 * - Flags persist until a Power-On Reset (POR).
 * - Ensure this comment block stays synchronized with the bitmask/shift
 *   definitions below.
 */

#define RSE_PERSISTENT_DATA_FLAGS_LAST_BOOT_DEBUG_CODE_BITFIELD_POS 12
#define RSE_PERSISTENT_DATA_FLAGS_LAST_BOOT_DEBUG_CODE_BITFIELD_WIDTH 8

/* Bit-flip resistant enums */
enum LAST_BOOT_DEBUG_CODE {
    LAST_BOOT_DEBUG_CODE_APPLY_CERT_DEBUG = 0x5A,
    LAST_BOOT_DEBUG_CODE_BLOCK_CERT_DEBUG = 0xA5,
};

#define RSE_PERSISTENT_DATA_FLAGS_IS_SRAM_INITIALIZED_BITFIELD_POS 20
#define RSE_PERSISTENT_DATA_FLAGS_IS_SRAM_INITIALIZED_BITFIELD_WIDTH 1

#define RSE_PERSISTENT_DATA_FLAGS_PERSISTENT_DATA_INITIALIZED_BITFIELD_POS 31
#define RSE_PERSISTENT_DATA_FLAGS_PERSISTENT_DATA_INITIALIZED_BITFIELD_WIDTH 1

#ifdef RSE_PERSISTENT_DATA_FLAG_REG_ADDR
#define RSE_PERSISTENT_DATA_FLAG_BASE ((volatile uint32_t *)RSE_PERSISTENT_DATA_FLAG_REG_ADDR)
#else
/* If the platform does not have a defined register address for
 * the persistent data, make use of the field in the persistent
 * data structure
 */
#define RSE_PERSISTENT_DATA_FLAG_BASE ((volatile uint32_t *)&(RSE_PERSISTENT_DATA->flags_data))
#endif

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
        /*
         * Vector that to store debug vector for ROM to open for certified
         * debug open
         */
        uint32_t certified_debug_vector[4];
        /* Whether the KMU HW keys are initialized or not */
        bool is_hw_key_invalidated;
#ifdef RSE_ENABLE_CHIP_OUTPUT_DATA
        // FIXME: rse_provisioning_reply_t might not get resolved in BL2/runtime
        /* This stores ~200B of COD reply in SRAM instead of wasting BL1 DATA
         * region
         */
        struct {
            struct rse_provisioning_reply_t cod_reply; /*!< Stored COD reply in SRAM */
            bool cod_reply_is_valid;                   /*!< Whether COD reply is valid */
        };
#endif /* RSE_ENABLE_CHIP_OUTPUT_DATA */
    } bl1_data;

    /* Data shared between bootloaders and runtime */
    struct rse_persistent_shared_data {
        uint32_t shared_boot_measurement[SHARED_BOOT_MEASUREMENT_SIZE / sizeof(uint32_t)];
        uint32_t runtime_to_boot_data[RUNTIME_SERVICE_TO_BOOT_SHARED_REGION_SIZE / sizeof(uint32_t)];
    } shared_data;

#ifndef RSE_PERSISTENT_DATA_FLAG_REG_ADDR
    /*
     * Persistent data flags if register not available
     */
    uint32_t flags_data;
#endif /* RSE_PERSISTENT_DATA_FLAG_REG_ADDR */
};

void rse_setup_persistent_data(void);

static inline uint32_t __get_persistent_data_flag(uint32_t bitfield_pos, uint32_t bitfield_width)
{
    const uint32_t mask = (1 << bitfield_width) - 1;

    return (*RSE_PERSISTENT_DATA_FLAG_BASE >> bitfield_pos) & mask;
}

#define RSE_GET_PERSISTENT_DATA_FLAG(_flag) \
    (__get_persistent_data_flag(_flag##_BITFIELD_POS, _flag##_BITFIELD_WIDTH))

static inline void __set_persistent_data_flag(uint32_t bitfield_pos, uint32_t bitfield_width,
                                              uint32_t val)
{
    const uint32_t mask = ((1 << bitfield_width) - 1);

    *RSE_PERSISTENT_DATA_FLAG_BASE &= ~(mask << bitfield_pos);
    *RSE_PERSISTENT_DATA_FLAG_BASE |= (val & mask) << bitfield_pos;
}

#define RSE_SET_PERSISTENT_DATA_FLAG(_flag, _val) \
    (__set_persistent_data_flag(_flag##_BITFIELD_POS, _flag##_BITFIELD_WIDTH, _val))

/* Persistent data init flag must be in PoR domain. Therefore it is either
 * in the persistent data flag register if present, or passed between
 * boots via the RESET_SYNDROME
 */
#ifdef RSE_PERSISTENT_DATA_FLAG_REG_ADDR
#define RSE_GET_PERSISTENT_DATA_INITIALIZED_FLAG()                          \
    ((*RSE_PERSISTENT_DATA_FLAG_BASE >>                                     \
      RSE_PERSISTENT_DATA_FLAGS_PERSISTENT_DATA_INITIALIZED_BITFIELD_POS) & \
     0b1)

#define RSE_SET_PERSISTENT_DATA_INITIALISED_FLAG(_val) \
    RSE_SET_PERSISTENT_DATA_FLAG(RSE_PERSISTENT_DATA_FLAGS_PERSISTENT_DATA_INITIALIZED, _val)

#else
#define RSE_GET_PERSISTENT_DATA_INITIALIZED_FLAG()                            \
    ((((struct rse_sysctrl_t *)RSE_SYSCTRL_BASE_S)->reset_syndrome >>         \
      (RSE_PERSISTENT_DATA_FLAGS_PERSISTENT_DATA_INITIALIZED_BITFIELD_POS)) & \
     0b1)

/* Flag is set in tfm_hal_system_reset when we come to reset the system */
#define RSE_SET_PERSISTENT_DATA_INITIALISED_FLAG(_val) \
    do {                                               \
    } while (0)

#endif

#endif /* __RSE_PERSISTENT_DATA_H__ */
