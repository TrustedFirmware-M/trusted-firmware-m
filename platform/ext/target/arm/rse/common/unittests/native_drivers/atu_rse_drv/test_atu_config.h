/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

/**
 * \file    test_atu_config.h
 * \brief   ATU configuration for BB24
 */

#ifndef _TEST_ATU_CONFIG_H_
#define _TEST_ATU_CONFIG_H_

#include "atu_rse_lib.h"
#include "platform_base_address.h"

extern const struct atu_region_map_t atu_regions_static[];

extern const uint8_t atu_stat_count;

#define ARRAY_SIZE(arr) (sizeof(arr)/sizeof((arr)[0]))

/* Dummy logical and physical addresses */
#define ATU_DUMMY_SLOT_LOG_ADDR 0x70000000
#define ATU_DUMMY_SLOT_PHY_ADDR 0x80000000
#define ATU_DUMMY_SLOT_SIZE 0x4000
#define ATU_DUMMY_OFFSET 0x1000000

/*
 * Referred from platform base address
 * Approximately 80 MB of logical address space is used for mapping the Host flash image.
 */

/* ATU Hardware usage for the platform */
#define ATU_STATIC_SLOT_START               11
#define ATU_STATIC_SLOT_COUNT               4
#define ATU_STATIC_NON_SEC_LOG_ADDR_START   (HOST_ACCESS_BASE_NS    + (0xC000000))
#define ATU_STATIC_NON_SEC_LOG_ADDR_SIZE    (0x4000000)
#define ATU_STATIC_SEC_LOG_ADDR_START       (HOST_ACCESS_BASE_S     + (0xC000000))
#define ATU_STATIC_SEC_LOG_ADDR_SIZE        (0x4000000)

#define ATU_DYN_SLOT_START                  7
#define ATU_DYN_SLOT_COUNT                  4
#define ATU_DYN_NON_SEC_LOG_ADDR_START      (HOST_ACCESS_BASE_NS    + (0x8000000))
#define ATU_DYN_NON_SEC_LOG_ADDR_SIZE       (0x4000000)
#define ATU_DYN_SEC_LOG_ADDR_START          (HOST_ACCESS_BASE_S     + (0x8000000))
#define ATU_DYN_SEC_LOG_ADDR_SIZE           (0x4000000)

#endif /* _TEST_ATU_CONFIG_H_ */
