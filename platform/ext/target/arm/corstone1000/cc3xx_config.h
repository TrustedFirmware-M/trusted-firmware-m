/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef CC3XX_CONFIG_H
#define CC3XX_CONFIG_H

#ifndef CC3XX_CONFIG_BASE_ADDRESS
#include "platform_base_address.h"
#define CC3XX_CONFIG_BASE_ADDRESS (CC3XX_BASE_S)
#endif /* CC3XX_CONFIG_BASE_ADDRESS */

/* Whether the DCU apply permission function enforces ICV restriction mask */
/* #define CC3XX_CONFIG_DCU_ICV_RESTRICTION_MASK_CHECK */

/* Whether uint32_t accesses must be strictly 4-byte aligned */
/* CC3XX_CONFIG_STRICT_UINT32_T_ALIGNMENT */

/* Whether the SHA256 hash support is enabled */
#define CC3XX_CONFIG_HASH_SHA256_ENABLE

/* Whether the SHA224 hash support is enabled */
/* #define CC3XX_CONFIG_HASH_SHA224_ENABLE */

/* Whether the SHA1 hash support is enabled */
/* #define CC3XX_CONFIG_HASH_SHA1_ENABLE */

/* Whether the AES CTR support is enabled */
#define CC3XX_CONFIG_AES_CTR_ENABLE

/* Whether the AES ECB support is enabled */
#define CC3XX_CONFIG_AES_ECB_ENABLE

/* Whether the AES CBC support is enabled */
/* #define CC3XX_CONFIG_AES_CBC_ENABLE */

/* Whether the AES GCM support is enabled */
/* #define CC3XX_CONFIG_AES_GCM_ENABLE */
/* #define CC3XX_CONFIG_AES_GCM_VARIABLE_IV_ENABLE */

/* Whether the AES CMAC support is enabled */
#define CC3XX_CONFIG_AES_CMAC_ENABLE

/* Whether the AES CCM support is enabled */
/* #define CC3XX_CONFIG_AES_CCM_ENABLE */

/* Whether the AES tunnelling support is enabled. Without this, running CCM mode
 * AES will instead only run the CBC_MAC operation with the CCM IVs, with the
 * CTR decryption having to be done seperately. */
#define CC3XX_CONFIG_AES_TUNNELLING_ENABLE

/* Whether CHACHA is enabled */
/* #define CC3XX_CONFIG_CHACHA_ENABLE */

/* Whether CHACHA_POLY1305 is enabled */
/* #define CC3XX_CONFIG_CHACHA_POLY1305_ENABLE */

/* Whether DMA remapping is enabled */
#define CC3XX_CONFIG_DMA_REMAP_ENABLE

/* Whether DMA supports working on cached memories */
/* #define CC3XX_CONFIG_DMA_CACHE_FLUSH_ENABLE */

/* Whether CC will WFI instead of busy-wait looping while waiting for crypto
 * operations to complete.
 */
/* #define CC3XX_CONFIG_DMA_WFI_WAIT_ENABLE */

/* How many DMA remap regions are available */
#ifndef CC3XX_CONFIG_DMA_REMAP_REGION_AM
#define CC3XX_CONFIG_DMA_REMAP_REGION_AM 4
#endif /* CC3XX_CONFIG_DMA_REMAP_REGION_AM */

/* Whether RNG is enabled */
#define CC3XX_CONFIG_RNG_ENABLE

/* Collect TRNG error statistics */
/* #define CC3XX_CONFIG_TRNG_COLLECT_STATISTCS */

/* Generate entropy to RNG SRAM, and copy it to destination via DMA */
/* #define CC3XX_CONFIG_TRNG_DMA */

/* Whether RNG uses HMAC_DRBG when RNG_DRBG is selected */
#define CC3XX_CONFIG_RNG_DRBG_HMAC
/* Whether RNG uses CTR_DRBG when RNG_DRBG is selected */
/* #define CC3XX_CONFIG_RNG_DRBG_CTR */
/* Whether RNG uses HASH_DRBG when RNG_DRBG is selected */
/* #define CC3XX_CONFIG_RNG_DRBG_HASH */

#if ((defined(CC3XX_CONFIG_RNG_DRBG_HMAC) + \
     defined(CC3XX_CONFIG_RNG_DRBG_CTR)  + \
     defined(CC3XX_CONFIG_RNG_DRBG_HASH)) != 1)
#error "cc3xx_config: RNG config must select a single DRBG"
#endif /* CC3XX_CONFIG_RNG_DRBG_HMAC + CC3XX_CONFIG_RNG_DRBG_CTR + CC3XX_CONFIG_RNG_DRBG_HASH */

/* Whether an external TRNG should be used in place of the standard CC3XX TRNG */
/* #define CC3XX_CONFIG_RNG_EXTERNAL_TRNG */

/**
 * @brief The number of times the TRNG will be re-read after failing a statistical test
 *        before an error is returned.
 *
 *        The value is chosen to cover all combinations of ROSC IDs and subsampling rates.
 *        The driver doubles the subsampling rate for each ROSC ID, so the number of
 *        attempts is calculated as:
 *
 *            attempts = ceil(log2(ceil(UINT32_MAX / CC3XX_CONFIG_RNG_SUBSAMPLING_RATE))) * 4
 *
 *        Here:
 *        - "4" is the number of available ring oscillators (ROSCs).
 *        - Both the division and the log2 operation are ceiled to ensure full coverage.
 */
#ifndef CC3XX_CONFIG_RNG_MAX_ATTEMPTS
#define CC3XX_CONFIG_RNG_MAX_ATTEMPTS 100
#endif /* CC3XX_CONFIG_RNG_MAX_ATTEMPTS */

/* This is the number of cycles between consecutive samples of the oscillator
 * output. It needs to be set to a _reasonably_ large number, though It's
 * unclear exactly what sort of number is reasonable. In general, if the
 * statistical tests keep failing then increase it, if the RNG is too slow then
 * decrease it.  A sensible default is set here, and has worked correctly with a
 * variety of cc3xx implementations.
 */
#ifndef CC3XX_CONFIG_RNG_SUBSAMPLING_RATE
#define CC3XX_CONFIG_RNG_SUBSAMPLING_RATE 0x1337
#endif /* !CC_RNG_SUBSAMPLING_RATE */

/* Between 0 and 3 inclusive. 0 should be the fastest oscillator ring */
#ifndef CC3XX_CONFIG_RNG_RING_OSCILLATOR_ID
#define CC3XX_CONFIG_RNG_RING_OSCILLATOR_ID 0
#endif /* !CC_RNG_RING_OSCILLATOR_ID */

/* How many virtual registers can be allocated in the PKA engine */
#ifndef CC3XX_CONFIG_PKA_MAX_VIRT_REG_AMOUNT
#define CC3XX_CONFIG_PKA_MAX_VIRT_REG_AMOUNT 64
#endif /* CC3XX_CONFIG_PKA_MAX_VIRT_REG_AMOUNT */

/* Whether barrett tags will be calculated if they are not known. Note that
 * barrett tags are required for modular reduction. If disabled, this may
 * decrease code size.
 */
#define CC3XX_CONFIG_PKA_CALC_NP_ENABLE

/* Whether PKA operations will be inlined to increase performance at the cost of
 * code size
 */
#define CC3XX_CONFIG_PKA_INLINE_FOR_PERFORMANCE

/* Whether PKA variables will be aligned to word-size to increase performance at
 * the cost of code size
 */
#define CC3XX_CONFIG_PKA_ALIGN_FOR_PERFORMANCE

/* Whether various EC curve types are enabled */
#define CC3XX_CONFIG_EC_CURVE_TYPE_WEIERSTRASS_ENABLE
/* #define CC3XX_CONFIG_EC_CURVE_TYPE_MONTGOMERY_ENABLE */
/* #define CC3XX_CONFIG_EC_CURVE_TYPE_TWISTED_EDWARDS_ENABLE */

/* Whether various EC curves are enabled */
#define CC3XX_CONFIG_EC_CURVE_SECP_192_R1_ENABLE
#define CC3XX_CONFIG_EC_CURVE_SECP_224_R1_ENABLE
#define CC3XX_CONFIG_EC_CURVE_SECP_256_R1_ENABLE
#define CC3XX_CONFIG_EC_CURVE_SECP_384_R1_ENABLE
#define CC3XX_CONFIG_EC_CURVE_SECP_521_R1_ENABLE
#define CC3XX_CONFIG_EC_CURVE_SECP_192_K1_ENABLE
#define CC3XX_CONFIG_EC_CURVE_SECP_224_K1_ENABLE
#define CC3XX_CONFIG_EC_CURVE_SECP_256_K1_ENABLE
#define CC3XX_CONFIG_EC_CURVE_BRAINPOOLP_192_R1_ENABLE
#define CC3XX_CONFIG_EC_CURVE_BRAINPOOLP_224_R1_ENABLE
#define CC3XX_CONFIG_EC_CURVE_BRAINPOOLP_256_R1_ENABLE
#define CC3XX_CONFIG_EC_CURVE_BRAINPOOLP_320_R1_ENABLE
#define CC3XX_CONFIG_EC_CURVE_BRAINPOOLP_384_R1_ENABLE
#define CC3XX_CONFIG_EC_CURVE_BRAINPOOLP_512_R1_ENABLE
#define CC3XX_CONFIG_EC_CURVE_FRP_256_V1_ENABLE

/* #define CC3XX_CONFIG_EC_CURVE_25519_ENABLE */
/* #define CC3XX_CONFIG_EC_CURVE_448_ENABLE */

/* #define CC3XX_CONFIG_EC_CURVE_ED25519_ENABLE */
/* #define CC3XX_CONFIG_EC_CURVE_ED448_ENABLE */

/* What the maximum DPA countermeasure blinding multiple is for EC point-scalar
 * multiplication.
 */
#define CC3XX_CONFIG_EC_DPA_MAX_BLIND_MULTIPLE 32

/* Whether the Shamir trick will be used to improve performance of point-scalar
 * multiplication on non-secret data. Has a code-size penalty.
 */
#define CC3XX_CONFIG_EC_SHAMIR_TRICK_ENABLE

/* Whether various ECDSA features are enabled */
#define CC3XX_CONFIG_ECDSA_SIGN_ENABLE
#define CC3XX_CONFIG_ECDSA_VERIFY_ENABLE
#define CC3XX_CONFIG_ECDSA_KEYGEN_ENABLE

/* Whether DPA mitigations are enabled. Has a code-size and performance cost */
#define CC3XX_CONFIG_DPA_MITIGATIONS_ENABLE

/* Whether DFA mitigations are enabled. Has a code-size and performance cost */
#define CC3XX_CONFIG_DFA_MITIGATIONS_ENABLE

/* Whether an external secure word copying function (for copying keys etc) will
 * be provided by the platform
 */
#define CC3XX_CONFIG_STDLIB_EXTERNAL_SECURE_WORD_COPY

#ifndef CC3XX_CONFIG_STDLIB_LFSR_MAX_ATTEMPTS
#define CC3XX_CONFIG_STDLIB_LFSR_MAX_ATTEMPTS 128
#endif /* CC3XX_CONFIG_STDLIB_LFSR_MAX_ATTEMPTS */

/* Whether LCS logging is enabled */
#define CC3XX_CONFIG_LCS_LOG_ENABLE

/* Whether secure debug reset register logging is enabled */
#define CC3XX_CONFIG_SECURE_DEBUG_RESET_LOG_ENABLE

/* Whether General Purpose Persistent Configuration (GPPC) logging is enabled */
#define CC3XX_CONFIG_GPPC_LOG_ENABLE

#endif /* CC3XX_CONFIG_H */
