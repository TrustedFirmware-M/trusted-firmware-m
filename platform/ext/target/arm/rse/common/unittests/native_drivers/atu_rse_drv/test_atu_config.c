/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

/**
 * \file atu_config.c
 * \brief This file defines the atu static configuration structure
 */


#include "test_atu_config.h"
#include "atu_rse_drv.h"
#include "host_base_address.h"
#include "platform_base_address.h"

const struct atu_region_map_t atu_regions_static[] =
{
    /* Dummy slot 0*/
    {
        .phys_addr = ATU_DUMMY_SLOT_PHY_ADDR,
        .log_addr = ATU_DUMMY_SLOT_LOG_ADDR,
        .size = ATU_DUMMY_SLOT_SIZE,
        .out_bus_attr = ATU_ENCODE_ATTRIBUTES_NON_SECURE_PAS,
    },
    /* Dummy slot 1*/
    {
        .phys_addr = ATU_DUMMY_SLOT_PHY_ADDR + 1 * ATU_DUMMY_OFFSET,
        .log_addr = ATU_DUMMY_SLOT_LOG_ADDR + 1 * ATU_DUMMY_OFFSET,
        .size = ATU_DUMMY_SLOT_SIZE,
        .out_bus_attr = ATU_ENCODE_ATTRIBUTES_SECURE_PAS,
    },
    /* Dummy slot 2*/
    {
        .phys_addr = ATU_DUMMY_SLOT_PHY_ADDR + 2 * ATU_DUMMY_OFFSET,
        .log_addr = (ATU_DUMMY_SLOT_LOG_ADDR + 2 * ATU_DUMMY_OFFSET),
        .size = 3 * ATU_DUMMY_SLOT_SIZE,
        .out_bus_attr = ATU_ENCODE_ATTRIBUTES_SECURE_PAS,
    },
};

const uint8_t atu_stat_count = ARRAY_SIZE(atu_regions_static);
