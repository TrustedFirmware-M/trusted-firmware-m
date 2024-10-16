/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

/**
 * \file    atu_config.h
 * \brief   ATU configuration for RSE
 */

#ifndef _ATU_CONFIG_H_
#define _ATU_CONFIG_H_

#include "atu_rse_lib.h"
#include "platform_base_address.h"

extern const struct atu_region_map_t atu_regions_static[];
extern const uint8_t atu_stat_count;

/*
 * Referred from platform base address
 * Approximately 80 MB of logical address space is used for mapping the Host flash image.
 */

/* ATU Hardware usage for the platform */
#define ATU_STATIC_SLOT_START               0
#define ATU_STATIC_SLOT_COUNT               10
#define ATU_STATIC_NON_SEC_LOG_ADDR_START   (HOST_ACCESS_BASE_NS    + (0xC000000))
#define ATU_STATIC_NON_SEC_LOG_ADDR_SIZE    (0x4000000)
#define ATU_STATIC_SEC_LOG_ADDR_START       (HOST_ACCESS_BASE_S     + (0xC000000))
#define ATU_STATIC_SEC_LOG_ADDR_SIZE        (0x4000000)

#define ATU_NUMBER_OF_SLOTS                 32
#define ATU_DYN_SLOT_START                  (ATU_STATIC_SLOT_START + ATU_STATIC_SLOT_COUNT + 1)
#define ATU_DYN_SLOT_COUNT                  (ATU_NUMBER_OF_SLOTS - ATU_DYN_SLOT_START)
#define ATU_DYN_NON_SEC_LOG_ADDR_START      (HOST_ACCESS_BASE_NS)
#define ATU_DYN_NON_SEC_LOG_ADDR_SIZE       (0x4000000)
#define ATU_DYN_SEC_LOG_ADDR_START          (HOST_ACCESS_BASE_S)
#define ATU_DYN_SEC_LOG_ADDR_SIZE           (0x4000000)

#if ATU_STATIC_SLOT_COUNT > (ATU_NUMBER_OF_SLOTS - ATU_STATIC_SLOT_START)
#error "Exceeded maximum number of static slots"
#endif

#if ATU_DYN_SLOT_START > (ATU_NUMBER_OF_SLOTS - ATU_DYN_SLOT_COUNT)
#error "Exceeded maximum number of dynamic slots"
#endif

#endif /* _ATU_CONFIG_H_ */
