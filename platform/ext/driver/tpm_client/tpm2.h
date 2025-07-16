/*
 * Copyright (c) 2025, Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef TPM2_H
#define TPM2_H

#include <assert.h>
#include <errno.h>
#include <stdint.h>
#include "cmsis_compiler.h"

#include "tpm_client/tpm2_chip.h"

/* Return values */
enum tpm_ret_value {
	TPM_SUCCESS = 0,
	TPM_ERR_RESPONSE = -1,
	TPM_INVALID_PARAM = -2,
	TPM_ERR_TIMEOUT = -3,
	TPM_ERR_TRANSFER = -4,
};

/*
 * TPM FIFO register space address offsets
 */
#define TPM_FIFO_REG_ACCESS		0x00
#define TPM_FIFO_REG_INTR_ENABLE	0x08
#define TPM_FIFO_REG_INTR_VECTOR	0x0C
#define TPM_FIFO_REG_INTR_STS		0x10
#define TPM_FIFO_REG_INTF_CAPS		0x14
#define TPM_FIFO_REG_STATUS		0x18
#define TPM_FIFO_REG_BURST_COUNT_LO	0x19
#define TPM_FIFO_REG_BURST_COUNT_HI	0x20
#define TPM_FIFO_REG_DATA_FIFO		0x24
#define TPM_FIFO_REG_VENDID		0xF00
#define TPM_FIFO_REG_DEVID		0xF02
#define TPM_FIFO_REG_REVID		0xF04

#define TPM_ST_NO_SESSIONS		0x8001U
#define TPM_ST_SESSIONS			0x8002U

#define TPM_SU_CLEAR			0x0000U
#define TPM_SU_STATE			0x0001U

#define TPM_MIN_AUTH_SIZE		9
#define TPM_RS_PW			0x40000009
#define TPM_ZERO_NONCE_SIZE		0
#define TPM_ATTRIBUTES_DISABLE		0
#define TPM_ZERO_HMAC_SIZE		0
#define TPM_SINGLE_HASH_COUNT		1
#define TPM_PCR_SELECT			0x3 /* 24 PCRs bit-mask with 3 bytes */


#define TPM_CMD_STARTUP			0x0144U
#define TPM_CMD_PCR_READ		0x017EU
#define TPM_CMD_PCR_EXTEND		0x0182U

#define TPM_RESPONSE_SUCCESS		0x0000

#define TPM_ACCESS_ACTIVE_LOCALITY	(1 << 5)
#define TPM_ACCESS_VALID		(1 << 7)
#define TPM_ACCESS_RELINQUISH_LOCALITY	(1 << 5)
#define TPM_ACCESS_REQUEST_USE		(1 << 1)
#define TPM_ACCESS_REQUEST_PENDING	(1 << 2)

#define TPM_STAT_VALID			(1 << 7)
#define TPM_STAT_COMMAND_READY		(1 << 6)
#define TPM_STAT_GO			(1 << 5)
#define TPM_STAT_AVAIL			(1 << 4)
#define TPM_STAT_EXPECT			(1 << 3)

#define TPM_READ_HEADER			-1

#define TPM_HEADER_SIZE			10
#define MAX_SIZE_CMDBUF			256
#define MAX_DIGEST_SIZE			48 /* SHA384 */
#define MAX_CMD_DATA			(MAX_SIZE_CMDBUF - TPM_HEADER_SIZE)

/*
 * TPM_ALG_ID constants.
 * Ref. Table 9 - Definition of (UINT16) TPM_ALG_ID Constant
 * Trusted Platform Module Library. Part 2: Structures
 */
#define TPM_ALG_SHA256			0x000BU

typedef struct tpm_cmd_hdr {
	uint16_t tag;
	uint32_t cmd_size;
	uint32_t cmd_code;
}__PACKED tpm_cmd_hdr;

typedef struct tpm_cmd {
	tpm_cmd_hdr header;
	uint8_t data[MAX_CMD_DATA];
}__PACKED tpm_cmd;

typedef struct tpm_pcr_read_res {
	uint32_t pcr_update_ctr;
	uint32_t tpml_pcr_selection_count;
	uint16_t tpms_pcr_selection_hash;
	uint32_t tpms_pcr_selection_num_octate_bitmap;
	uint32_t tpml_digest_count;
	uint16_t tpml_digest_size;
	uint8_t digest[MAX_DIGEST_SIZE];
}__PACKED tpm_pcr_read_res;

int tpm_interface_init(struct tpm_chip_data *chip_data, uint8_t locality);

int tpm_interface_close(struct tpm_chip_data *chip_data, uint8_t locality);

int tpm_startup(struct tpm_chip_data *chip_data, uint16_t mode);

int tpm_pcr_extend(struct tpm_chip_data *chip_data, uint32_t index,
		   uint16_t algorithm, const uint8_t *digest,
		   uint32_t digest_len);

int tpm_pcr_read(struct tpm_chip_data *chip_data, uint32_t index,
		uint16_t algorithm, struct tpm_pcr_read_res *pcr_read_response);

#endif /* TPM2_H */
