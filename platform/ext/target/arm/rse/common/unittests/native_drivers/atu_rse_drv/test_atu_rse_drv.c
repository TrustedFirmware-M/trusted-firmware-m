/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include "atu_rse_lib.h"

#include "unity.h"

/*
 * RSE ATU build configuration values (atubc):
 *  ATUNTR  = 0x5 -> 32 translation regions
 *  ATUPS   = 0xD -> 8192 byte page size
 *  ATUPAW  = 0x5 -> 52 bit physical address width
 */
#define ATU_BC_RESET_VALUE 0x5D5u   /* Build configuration register */
#define ATU_C_RESET_VALUE 0x0u      /* Configuration register */
#define ATU_IS_RESET_VALUE 0x0u     /* Interrupt status register */
#define ATU_IE_RESET_VALUE 0x1u     /* Interrupt enable register */
#define ATU_IC_RESET_VALUE 0x0u     /* Interrupt clear register */
#define ATU_MA_RESET_VALUE 0x0u     /* Mismatched address register */
#define ATU_PIDR0_RESET_VALUE 0xC0u /* Peripheral ID 0 register */
#define ATU_PIDR1_RESET_VALUE 0xB3u /* Peripheral ID 1 register */
#define ATU_PIDR2_RESET_VALUE 0xBu  /* Peripheral ID 2 register */
#define ATU_PIDR3_RESET_VALUE 0x0u  /* Peripheral ID 3 register */
#define ATU_PIDR4_RESET_VALUE 0x4u  /* Peripheral ID 4 register */
#define ATU_CIDR0_RESET_VALUE 0xDu  /* Component ID 0 register */
#define ATU_CIDR1_RESET_VALUE 0xF0u /* Component ID 1 register */
#define ATU_CIDR2_RESET_VALUE 0x5u  /* Component ID 2 register */
#define ATU_CIDR3_RESET_VALUE 0xB1u /* Component ID 3 register */

/* ATU register map structure */
static struct _atu_reg_map_t {
    uint32_t atubc;
    /*!< Offset: 0x000 (R/O) ATU Build Configuration Register */
    uint32_t atuc;
    /*!< Offset: 0x004 (R/W) ATU Configuration Register */
    uint32_t atuis;
    /*!< Offset: 0x008 (R/O) ATU Interrupt Status Register */
    uint32_t atuie;
    /*!< Offset: 0x00C (R/W) ATU Interrupt Enable Register */
    uint32_t atuic;
    /*!< Offset: 0x010 (R/W) ATU Interrupt Clear Register */
    uint32_t atuma;
    /*!< Offset: 0x014 (R/O) ATU Mismatched Address Register */
    uint32_t reserved_0[2];
    /*!< Offset: 0x018-0x01C Reserved */
    uint32_t atursla[32];
    /*!< Offset: 0x020 (R/W) ATU Region Start Logical Address n
     *                       Register */
    uint32_t aturela[32];
    /*!< Offset: 0x0A0 (R/W) ATU Region End Logical Address n
     *                       Register */
    uint32_t aturav_l[32];
    /*!< Offset: 0x120 (R/W) ATU Region Add Value Low n Register */
    uint32_t aturav_m[32];
    /*!< Offset: 0x1A0 (R/W) ATU Region Add Value High n Register */
    uint32_t aturoba[32];
    /*!< Offset: 0x220 (R/W) ATU Region Output Bus Attributes n
     *                       Register */
    uint32_t aturgp[32];
    /*!< Offset: 0x2A0 (R/W) ATU Region General Purpose n
     *                       Register */
    uint32_t reserved_1[811]; /*!< Offset: 0x320-0xFCC Reserved */
    uint32_t pidr4;
    /*!< Offset: 0xFD0 (R/O) Peripheral ID 4 */
    uint32_t reserved_2[2];
    /*!< Offset: 0xFD4-0xFDC Reserved */
    uint32_t pidr0;
    /*!< Offset: 0xFE0 (R/O) Peripheral ID 0 */
    uint32_t pidr1;
    /*!< Offset: 0xFE4 (R/O) Peripheral ID 1 */
    uint32_t pidr2;
    /*!< Offset: 0xFE8 (R/O) Peripheral ID 2 */
    uint32_t pidr3;
    /*!< Offset: 0xFEC (R/O) Peripheral ID 3 */
    uint32_t cidr0;
    /*!< Offset: 0xFF0 (R/O) Component ID 0 */
    uint32_t cidr1;
    /*!< Offset: 0xFF4 (R/O) Component ID 1 */
    uint32_t cidr2;
    /*!< Offset: 0xFF8 (R/O) Component ID 2 */
    uint32_t cidr3;
    /*!< Offset: 0xFFC (R/O) Component ID 3 */
} regmap;

static const struct atu_dev_cfg_t ATU_DEV_CFG_S = {.base = (uintptr_t)&regmap};

static struct atu_dev_t ATU_DEV_S = {.cfg = &ATU_DEV_CFG_S};

/* Set ATU registers to their default reset values */
void set_default_register_values(void)
{
    regmap.atubc = ATU_BC_RESET_VALUE;
    regmap.atuc = ATU_C_RESET_VALUE;
    regmap.atuis = ATU_IS_RESET_VALUE;
    regmap.atuie = ATU_IE_RESET_VALUE;
    regmap.atuic = ATU_IC_RESET_VALUE;
    regmap.atuma = ATU_MA_RESET_VALUE;
    memset(regmap.reserved_0, 0x0u, sizeof(regmap.reserved_0));
    memset(regmap.atursla, 0x0u, sizeof(regmap.atursla));
    memset(regmap.aturela, 0x0u, sizeof(regmap.aturela));
    memset(regmap.aturav_l, 0x0u, sizeof(regmap.aturav_l));
    memset(regmap.aturav_m, 0x0u, sizeof(regmap.aturav_m));
    memset(regmap.aturoba, 0x0u, sizeof(regmap.aturoba));
    memset(regmap.aturgp, 0x0u, sizeof(regmap.aturgp));
    memset(regmap.reserved_1, 0x0u, sizeof(regmap.reserved_1));
    regmap.pidr4 = ATU_PIDR4_RESET_VALUE;
    memset(regmap.reserved_2, 0x0u, sizeof(regmap.reserved_2));
    regmap.pidr0 = ATU_PIDR0_RESET_VALUE;
    regmap.pidr1 = ATU_PIDR1_RESET_VALUE;
    regmap.pidr2 = ATU_PIDR2_RESET_VALUE;
    regmap.pidr3 = ATU_PIDR3_RESET_VALUE;
    regmap.cidr0 = ATU_CIDR0_RESET_VALUE;
    regmap.cidr1 = ATU_CIDR1_RESET_VALUE;
    regmap.cidr2 = ATU_CIDR2_RESET_VALUE;
    regmap.cidr3 = ATU_CIDR3_RESET_VALUE;
}

/* Verify that Read-Only registers have not been modified */
void verify_read_only_registers(void)
{
    TEST_ASSERT_EQUAL_UINT32_MESSAGE(ATU_BC_RESET_VALUE, regmap.atubc,
                                     "Read-Only register ATUBC was modified");
    TEST_ASSERT_EQUAL_UINT32_MESSAGE(ATU_IS_RESET_VALUE, regmap.atuis,
                                     "Read-Only register ATUIS was modified");
    TEST_ASSERT_EQUAL_UINT32_MESSAGE(ATU_MA_RESET_VALUE, regmap.atuma,
                                     "Read-Only register ATUMA was modified");
    TEST_ASSERT_EQUAL_UINT32_MESSAGE(ATU_PIDR4_RESET_VALUE, regmap.pidr4,
                                     "Read-Only register PIDR4 was modified");
    TEST_ASSERT_EQUAL_UINT32_MESSAGE(ATU_PIDR0_RESET_VALUE, regmap.pidr0,
                                     "Read-Only register PIDR0 was modified");
    TEST_ASSERT_EQUAL_UINT32_MESSAGE(ATU_PIDR1_RESET_VALUE, regmap.pidr1,
                                     "Read-Only register PIDR1 was modified");
    TEST_ASSERT_EQUAL_UINT32_MESSAGE(ATU_PIDR2_RESET_VALUE, regmap.pidr2,
                                     "Read-Only register PIDR2 was modified");
    TEST_ASSERT_EQUAL_UINT32_MESSAGE(ATU_PIDR3_RESET_VALUE, regmap.pidr3,
                                     "Read-Only register PIDR3 was modified");
    TEST_ASSERT_EQUAL_UINT32_MESSAGE(ATU_CIDR0_RESET_VALUE, regmap.cidr0,
                                     "Read-Only register CIDR0 was modified");
    TEST_ASSERT_EQUAL_UINT32_MESSAGE(ATU_CIDR1_RESET_VALUE, regmap.cidr1,
                                     "Read-Only register CIDR1 was modified");
    TEST_ASSERT_EQUAL_UINT32_MESSAGE(ATU_CIDR2_RESET_VALUE, regmap.cidr2,
                                     "Read-Only register CIDR2 was modified");
    TEST_ASSERT_EQUAL_UINT32_MESSAGE(ATU_CIDR3_RESET_VALUE, regmap.cidr3,
                                     "Read-Only register CIDR3 was modified");
}

void setUp(void) { set_default_register_values(); }

void tearDown(void) { verify_read_only_registers(); }

void test_get_page_size_ok(void)
{
    uint16_t page_size;
    uint16_t expected_page_size;

    /* Prepare */
    expected_page_size = 0x1u << ((ATU_BC_RESET_VALUE >> 4) & 0xFu);

    /* Act */
    page_size = get_page_size(&ATU_DEV_S);

    /* Assert */
    TEST_ASSERT_EQUAL_UINT16(expected_page_size, page_size);
}

void test_get_supported_region_count_ok(void)
{
    uint8_t supported_region;
    uint8_t expected_supported_region;

    /* Prepare */
    expected_supported_region = 0x20;

    /* Act */
    supported_region = get_supported_region_count(&ATU_DEV_S);

    /* Assert */
    TEST_ASSERT_EQUAL_UINT8(expected_supported_region, supported_region);
}
