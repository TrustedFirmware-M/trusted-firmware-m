/*
 * Copyright (c) 2017-2019 Arm Limited. All rights reserved.
 * Copyright 2025 NXP
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/**
 * \file platform_base_address.h
 * \brief This file defines all the peripheral base addresses for platform.
 */

#ifndef __PLATFORM_BASE_ADDRESS_H__
#define __PLATFORM_BASE_ADDRESS_H__

#include "platform_regs.h"           /* Platform registers */

/* Internal Flash memory */
#define FLASH0_BASE_S            (0x10000000)
#define FLASH0_BASE_NS           (0x00000000)
#define FLASH0_SIZE              (FLASH_TOTAL_SIZE)             /* 2 MB */
#define FLASH0_SECTOR_SIZE       (FLASH_AREA_IMAGE_SECTOR_SIZE) /* Erase command is executed on sector (8K-byte), or whole chip */
#define FLASH0_PAGE_SIZE         (FLASH_AREA_PROGRAM_SIZE)      /* Page (128 bytes) basis, or word basis. */
#define FLASH0_PROGRAM_UNIT      (FLASH0_PAGE_SIZE)       	    /* Minimum write size. RM mentions this as 16 bytes but ROM API's need the writes to be aligned to page size*/


#define LPUART_BASE               LPUART4

#endif  /* __PLATFORM_BASE_ADDRESS_H__ */
