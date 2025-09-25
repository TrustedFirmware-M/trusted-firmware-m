/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef _TEST_ATU_RSE_COMMON_H_
#define _TEST_ATU_RSE_COMMON_H_

#include "atu_rse_drv_internal.h"
#include "atu_rse_drv.h"

/* Dummy logical and physical addresses */
#define ATU_DUMMY_SLOT_LOG_ADDR 0x70000000
#define ATU_DUMMY_SLOT_PHY_ADDR 0x80000000
#define ATU_DUMMY_SLOT_SIZE 0x4000
#define ATU_DUMMY_OFFSET 0x1000000
#define ATU_SEC_OUT_ATTR (ATU_ROBA_SET_0 << ATU_ATUROBA_AXPROT1_OFF)
#define ATU_NONSEC_OUT_ATTR (ATU_ROBA_SET_1 << ATU_ATUROBA_AXPROT1_OFF)

#define NUM_REGIONS 32
#define PAGE_SIZE 4096

/* On platforms using host UART, region 0 is occupied so do not use it for testing! */
#define MIN_TEST_REGION 1

void deinit_test_regions(void);

#endif /* _TEST_ATU_RSE_COMMON_H_ */
