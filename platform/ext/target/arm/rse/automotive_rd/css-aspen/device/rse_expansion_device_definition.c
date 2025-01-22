/*
 * SPDX-License-Identifier: BSD-3-Clause
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 */

/**
 * \file  rse_expansion_device_definition.c
 * \brief This file defines exports the structures based on the peripheral
 *        definitions from device_cfg.h.
 */

#include "host_atu_base_address.h"
#include "rse_expansion_device_definition.h"
#include "platform_base_address.h"
#include "host_si_memory_map.h"

static const struct cfi_dev_cfg_t CFI_DEV_CFG_S = {
    .base = BOOT_FLASH_BASE_S,
};
static struct cfi_dev_t CFI_DEV_S = {
    .cfg = &CFI_DEV_CFG_S,
};

struct cfi_strataflashj3_dev_t SPI_STRATAFLASHJ3_DEV = {
    .controller = &CFI_DEV_S,
    .total_sector_cnt = 0,
    .page_size = 0,
    .sector_size = 0,
    .program_unit = 0,
    .is_initialized = false
};

static const struct cfi_dev_cfg_t CFI_DEV_CFG_S_AP = {
    .base = HOST_AP_FLASH_BASE,
};

static struct cfi_dev_t CFI_DEV_S_AP = {
    .cfg = &CFI_DEV_CFG_S_AP,
};

struct cfi_strataflashj3_dev_t SPI_STRATAFLASHJ3_AP_DEV = {
    .controller = &CFI_DEV_S_AP,
    .total_sector_cnt = 0,
    .page_size = 0,
    .sector_size = 0,
    .program_unit = 1U,
    .is_initialized = false,
};

struct mhu_v3_x_dev_t MHU_SI_CL0_SENDER_DEV_S = {
    .version = 3,
    .base = HOST_RSE_SI_MHU_ATU_BASE_S + RSE_MHU_FRAME_OFFSET(RSE_MHU_SI_CL0_SND_IDX),
    .frame = MHU_V3_X_PBX_FRAME,
    .subversion = 0,
};

struct mhu_v3_x_dev_t MHU_SI_CL0_RECEIVER_DEV_S = {
    .version = 3,
    .base = HOST_RSE_SI_MHU_ATU_BASE_S + RSE_MHU_FRAME_OFFSET(RSE_MHU_SI_CL0_RCV_IDX),
    .frame = MHU_V3_X_MBX_FRAME,
    .subversion = 0,
};
