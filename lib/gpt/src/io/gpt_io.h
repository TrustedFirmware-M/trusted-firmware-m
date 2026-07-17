/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/** \file
 * Common I/O functionality between read and write modules
 */

#ifndef __TFM_GPT_IO_H__
#define __TFM_GPT_IO_H__

#include <stdint.h>

#include "gpt_defs.h"
#include "gpt_flash.h"

/**
 * \brief Gets the platform flash driver used for GPT I/O.
 *
 * \return Platform flash driver, or NULL if not set.
 */
struct gpt_flash_driver_t *get_plat_flash_driver(void);

/**
 * \brief Sets the platform flash driver used for GPT I/O.
 *
 * \param[in] new_driver New platform flash driver.
 */
void set_plat_flash_driver(struct gpt_flash_driver_t *new_driver);

/**
 * \brief Gets the in-memory LBA I/O buffer.
 *
 * \return Pointer to the LBA buffer.
 */
uint8_t *get_lba_buf(void);

/**
 * \brief Gets the LBA currently cached in the LBA buffer.
 *
 * \return Cached LBA.
 */
uint64_t get_cached_lba(void);

/**
 * \brief Sets the LBA currently cached in the LBA buffer.
 *
 * \param[in] new_value New cached LBA.
 */
void set_cached_lba(uint64_t new_value);

#endif /* __TFM_GPT_IO_H__ */
