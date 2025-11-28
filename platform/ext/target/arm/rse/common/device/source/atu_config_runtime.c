/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

/**
 * \file atu_config_bl2.c
 * \brief This file defines the atu static configuration structure for BL2
 */

#include "atu_config.h"
#include "atu_rse_lib.h"
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
#endif /* RSE_USE_HOST_UART */
#ifdef TFM_PARTITION_PROTECTED_STORAGE
    {
        .log_addr = HOST_ACCESS_PS_BASE_S,
        .phys_addr = HOST_FLASH0_PS_BASE,
        .size = HOST_FLASH0_PS_SIZE
    },
#endif /* TFM_PARTITION_PROTECTED_STORAGE */
};

const uint8_t atu_stat_count = sizeof(atu_regions_static)/sizeof(atu_regions_static[0]);
