/*
 * SPDX-License-Identifier: BSD-3-Clause
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 */

/**
 * \file  rse_expansion_device_definition.h
 * \brief The structure definitions in this file are exported based on the
 *        peripheral definitions from device_cfg.h.
 */

#ifndef __RSE_EXPANSION_DEVICE_DEFINITION_H__
#define __RSE_EXPANSION_DEVICE_DEFINITION_H__

#include "mhu_v3_x.h"
#include "rse_expansion_device_cfg.h"
#include "spi_strataflashj3_flash_lib.h"

#ifdef __cplusplus
extern "C" {
#endif

extern struct cfi_strataflashj3_dev_t SPI_STRATAFLASHJ3_DEV;
extern struct cfi_strataflashj3_dev_t SPI_STRATAFLASHJ3_AP_DEV;

#ifdef __cplusplus
}
#endif

#endif  /* __RSE_EXPANSION_DEVICE_DEFINITION_H__ */
