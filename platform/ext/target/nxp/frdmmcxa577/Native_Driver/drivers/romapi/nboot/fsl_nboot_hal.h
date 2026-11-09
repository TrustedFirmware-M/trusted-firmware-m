/*
 * Copyright 2025-2026 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_NBOOT_HAL_H_
#define FSL_NBOOT_HAL_H_

/*! @addtogroup nboot_driver */
/*! @{ */

/*! @file */

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/*! @brief The size of the UUID. */
#define NBOOT_UUID_SIZE_IN_WORD (4)
#define NBOOT_UUID_SIZE_IN_BYTE (NBOOT_UUID_SIZE_IN_WORD * 4)

/*! @brief The size of the PUF activation code. */
#define NBOOT_PUF_AC_SIZE_IN_BYTE (1000u)
/*! @brief The size of the PUF key code. */
#define NBOOT_PUF_KC_SIZE_IN_BYTE (84)

/*! @brief The size of the key store. */
#define NBOOT_KEY_STORE_SIZE_IN_BYTE (NBOOT_PUF_AC_SIZE_IN_BYTE + 8)

/*! @brief The size of the root of trust key table hash. */
#define NBOOT_ROOT_ROTKH_SIZE_IN_WORD (12)
#define NBOOT_ROOT_ROTKH_SIZE_IN_BYTE (NBOOT_ROOT_ROTKH_SIZE_IN_WORD * 4)

/*! @brief The size of the blob with Part Common Key. */
#define NBOOT_KEY_BLOB_SIZE_IN_BYTE_256 (32)
#define NBOOT_KEY_BLOB_SIZE_IN_BYTE_384 (48)
#define NBOOT_KEY_BLOB_SIZE_IN_BYTE_MAX (NBOOT_KEY_BLOB_SIZE_IN_BYTE_384)

/*! @brief The mask of the value of the debug state . */
#define NBOOT_DBG_AUTH_DBG_STATE_MASK (0x0000FFFFu)
/*! @brief The shift inverted value of the debug state. */
#define NBOOT_DBG_AUTH_DBG_STATE_SHIFT (16)
/*! @brief The value with all debug feature disabled. */
#define NBOOT_DBG_AUTH_DBG_STATE_ALL_DISABLED (0xFFFF0000u)

#define NBOOT_DICE_CSR_SIZE_IN_WORD  (36)
#define NBOOT_DICE_CSR_SIZE_IN_BYTES (NBOOT_DICE_CSR_SIZE_IN_WORD * 4)
#define NBOOT_DICE_CSR_ADDRESS       (0x30000000u)
/*! @brief The offset for the PRCINE/IPED erase region return by nboot mem checker. */
#define NBOOT_IPED_IV_OFFSET (4U)

#define NBOOT_IMAGE_CMAC_UPDATE_NONE   (0u)
#define NBOOT_IMAGE_CMAC_UPDATE_INDEX0 (1u)
#define NBOOT_IMAGE_CMAC_UPDATE_INDEX1 (2u)
#define NBOOT_IMAGE_CMAC_UPDATE_BOTH   (3u)
#define NBOOT_IMAGE_CMAC_UPDATE_MASK   (3u)

#define NBOOT_CMPA_CMAC_UPDATE_MASK  (0x38000000u)
#define NBOOT_CMPA_CMAC_UPDATE_SHIFT (0x27u)

#define NBOOT_CMPA_UPDATE_CMAC_PFR                (0x2u)
#define NBOOT_CMPA_UPDATE_CMAC_PFR_OTP_OEM_SECURE (0x3u)
#define NBOOT_CMPA_UPDATE_CMAC_PFR_OTP_OEM_CLOSE  (0x5u)
#define NBOOT_CMPA_UPDATE_CMAC_PFR_OTP_OEM_LOCKED (0x6u)
#define EFUSE_PART_CFG_FUSE_INDEX                 (12U)

/*! @brief Algorithm used for nboot HASH operation */
typedef enum _nboot_hash_algo_t
{
    kHASH_Sha1   = 1, /*!< SHA_1   */
    kHASH_Sha256 = 2, /*!< SHA_256 */
    kHASH_Sha512 = 3, /*!< SHA_512 */
    kHASH_Aes    = 4, /*!< AES     */
    kHASH_AesIcb = 5, /*!< AES_ICB */
} nboot_hash_algo_t;

/*! @} */

#endif /*FSL_NBOOT_HAL_H_ */
