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

#include "atu_config.h"
#include "atu_rse_drv.h"
#include "host_base_address.h"
#include "platform_base_address.h"

const struct atu_region_map_t atu_regions_static[] =
{
#ifdef RSE_USE_HOST_UART
    /* Non-Secure Uart Slot*/
    {
        .phys_addr = HOST_UART_BASE,
        .log_addr = HOST_UART0_BASE_NS,
        .size = HOST_UART_SIZE,
        .out_bus_attr = ATU_ENCODE_ATTRIBUTES_NON_SECURE_PAS,
    },
#endif
};

const uint8_t atu_stat_count = sizeof(atu_regions_static)/sizeof(atu_regions_static[0]);
