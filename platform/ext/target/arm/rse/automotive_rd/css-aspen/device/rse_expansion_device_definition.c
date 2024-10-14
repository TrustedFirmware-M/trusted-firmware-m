/*
 * SPDX-License-Identifier: BSD-3-Clause
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 */

/**
 * \file  rse_expansion_device_definition.c
 * \brief This file defines exports the structures based on the peripheral
 *        definitions from device_cfg.h.
 */

#include "rse_expansion_device_definition.h"
#include "platform_base_address.h"

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
