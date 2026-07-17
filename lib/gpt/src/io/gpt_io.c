/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
 * \file
 * Implementation of common I/O functionality
 */

#include <stdint.h>

#include "io/gpt_io.h"
#include "gpt_flash.h"

/* The flash driver, used to perform I/O */
static struct gpt_flash_driver_t *plat_flash_driver = NULL;

/* Buffer to use for LBA I/O */
static uint8_t lba_buf[TFM_GPT_BLOCK_SIZE] = {0};

/* LBA that is cached in the buffer. Zero is valid only for protective MBR, all
 * other GPT operations must have LBA of one or greater
 */
static uint64_t cached_lba = 0;

struct gpt_flash_driver_t *get_plat_flash_driver(void)
{
    return plat_flash_driver;
}

void set_plat_flash_driver(struct gpt_flash_driver_t *new_driver)
{
    plat_flash_driver = new_driver;
}

uint8_t *get_lba_buf(void)
{
    return lba_buf;
}

uint64_t get_cached_lba(void)
{
    return cached_lba;
}

void set_cached_lba(uint64_t new_value)
{
    cached_lba = new_value;
}
