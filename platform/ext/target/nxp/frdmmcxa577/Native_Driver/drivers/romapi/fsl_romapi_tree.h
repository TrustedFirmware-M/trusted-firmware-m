/*
 * Copyright 2025-2026 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_ROMAPI_TREE_H_
#define FSL_ROMAPI_TREE_H_

#include "fsl_common.h"

/*
 * The ROM API tree layout is fixed by the boot ROM. Driver slots are kept
 * as generic pointers here and cast to concrete interface types by each driver.
 */
typedef struct bootloader_tree
{
    void (*runBootloader)(void *arg); /*!< Function to start the bootloader executing.*/
    const void *flashDriver;          /*!< Internal Flash driver API.*/
    const void *kbDriver;             /*!< KB API */
    const void *nbootDriver;          /*!< NBOOT driver */
    const void *flexspiNorDriver;     /*!< FlexSPI NOR FLASH Driver API.*/
    const void *lpspiFlashDriver;     /*!< LPSPI Flash driver API.*/
    uint32_t version;                 /*!< Bootloader version number.*/
    const char *copyright;            /*!< Copyright string.*/
} bootloader_tree_t;

#define ROMAPI_BOOTLOADER_API_TREE_ADDRESS (0x1303d800u)
#define BOOTLOADER_API_TREE_POINTER        ((const bootloader_tree_t *)ROMAPI_BOOTLOADER_API_TREE_ADDRESS)

#endif /* FSL_ROMAPI_TREE_H_ */