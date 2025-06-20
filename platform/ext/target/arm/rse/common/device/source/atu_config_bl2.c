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
#include "atu_rse_drv.h"
#include "host_base_address.h"
#include "platform_base_address.h"
#ifdef RSE_BL2_ENABLE_IMAGE_STAGING
#include "staging_config.h"
#endif

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
#ifdef RSE_BL2_ENABLE_IMAGE_STAGING
    {
        .phys_addr = STAGING_AREA_FIP_A_BASE_S_PHYSICAL,
        .log_addr = STAGING_AREA_FIP_A_BASE_S,
        .size = HOST_FIP_MAX_SIZE,
        .out_bus_attr = ATU_ENCODE_ATTRIBUTES_NON_SECURE_PAS,
    },
    {
        .phys_addr = HOST_FLASH_FIP_A_BASE_S_PHYSICAL,
        .log_addr = HOST_FLASH_FIP_A_BASE_S,
        .size = HOST_FIP_MAX_SIZE,
        .out_bus_attr = ATU_ENCODE_ATTRIBUTES_NON_SECURE_PAS,
    },
#ifndef RSE_GPT_SUPPORT
    {
        .phys_addr = STAGING_AREA_FIP_B_BASE_S_PHYSICAL,
        .log_addr = STAGING_AREA_FIP_B_BASE_S,
        .size = HOST_FIP_MAX_SIZE,
        .out_bus_attr = ATU_ENCODE_ATTRIBUTES_NON_SECURE_PAS,
    },
    {
        .phys_addr = HOST_FLASH_FIP_B_BASE_S_PHYSICAL,
        .log_addr = HOST_FLASH_FIP_B_BASE_S,
        .size = HOST_FIP_MAX_SIZE,
        .out_bus_attr = ATU_ENCODE_ATTRIBUTES_NON_SECURE_PAS,
    },
#endif /* RSE_GPT_SUPPORT */
#endif /* RSE_BL2_ENABLE_IMAGE_STAGING */
#ifdef TFM_PARTITION_PROTECTED_STORAGE
    {
        .log_addr = HOST_ACCESS_PS_BASE_S,
        .phys_addr = HOST_FLASH0_PS_BASE,
        .size = HOST_FLASH0_PS_SIZE
    },
#endif /* TFM_PARTITION_PROTECTED_STORAGE */
#ifdef PLAT_DEP_STATIC_CFG
    PLAT_DEP_STATIC_CFG,
#endif /* PLAT_DEP_STATIC_CFG */
};

const uint8_t atu_stat_count = sizeof(atu_regions_static)/sizeof(atu_regions_static[0]);
