/*
 * Copyright (c) 2025, Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdbool.h>
#include <stdint.h>

#ifndef TPM2_CHIP_H
#define TPM2_CHIP_H

#define BYTE		(0x1U)
#define WORD		(0x2U)
#define DWORD		(0x4U)

struct tpm_chip_data {
	uint8_t locality;
	unsigned long timeout_msec_a, timeout_msec_b;
	unsigned long timeout_msec_c, timeout_msec_d;
	uint16_t address;
};

#endif /* TPM2_CHIP_H */
