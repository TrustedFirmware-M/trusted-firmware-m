/*
 * Copyright (c) 2026, STMicroelectronics - All Rights Reserved
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef __BL2_IMAGE_ID_H__
#define __BL2_IMAGE_ID_H__

#define TFM_S_NS_ID		0
#if (MCUBOOT_IMAGE_NUMBER == 3)
#define CA35_FIRMWARE_ID	1
#define DDR_FIRMWARE_ID		2
#else
#define DDR_FIRMWARE_ID		1
#endif

#endif /* __BL2_IMAGE_ID_H__ */
