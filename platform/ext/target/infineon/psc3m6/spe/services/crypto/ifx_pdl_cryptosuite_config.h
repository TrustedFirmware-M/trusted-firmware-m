/*
 * (c) 2026, Infineon Technologies AG, or an affiliate of Infineon
 * Technologies AG. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef IFX_PDL_CRYPTOSUITE_CONFIG_H
#define IFX_PDL_CRYPTOSUITE_CONFIG_H

/** Enable AES-ECB (Electronic Code book) mode */
#if defined(PSA_WANT_ALG_ECB_NO_PADDING)
#define IFX_PSA_CRYPTOSUITE_AES_ECB
#endif

/** Enable AES-CBC (Cipher Block Chaining) mode */
#if defined(PSA_WANT_ALG_CBC_NO_PADDING)
#define IFX_PSA_CRYPTOSUITE_AES_CBC
#endif

/** Enable AES-CFB (Cipher Feedback) mode */
#if defined(PSA_WANT_ALG_CFB)
#define IFX_PSA_CRYPTOSUITE_AES_CFB
#endif

/** Enable AES-CTR (Counter) mode */
#if defined(PSA_WANT_ALG_CTR)
#define IFX_PSA_CRYPTOSUITE_AES_CTR
#endif

/**
 * \brief Master AES enable
 * 
 * \details
 *  Enabled if any AES cipher mode is configured. This controls the
 *  availability of AES cipher operations in the transparent driver.
 */
#if defined(IFX_PSA_CRYPTOSUITE_AES_ECB) || defined(IFX_PSA_CRYPTOSUITE_AES_CBC) \
  || defined(IFX_PSA_CRYPTOSUITE_AES_CFB) || defined(IFX_PSA_CRYPTOSUITE_AES_CTR)
#define IFX_PSA_CRYPTOSUITE_AES
#endif

/*******************************************************************************
 * AEAD Configuration
 ******************************************************************************/

/**
 * \brief Enable CCM (Counter with CBC-MAC) AEAD mode
 *
 * \details
 *  CCM provides authenticated encryption with associated data using AES.
 *  Requires IFX_PSA_CRYPTOSUITE_AES to be enabled.
 */
#if defined(PSA_WANT_ALG_CCM)
#define IFX_PSA_CRYPTOSUITE_CCM
#endif

/*******************************************************************************
 * MAC Configuration
 ******************************************************************************/

/**
 * \brief Enable CMAC (Cipher-based MAC) algorithm
 *
 * \details
 *  CMAC provides message authentication using AES.
 *  Requires IFX_PSA_CRYPTOSUITE_AES to be enabled.
 */
#if defined(PSA_WANT_ALG_CMAC) && !defined(PSA_WANT_ALG_SP800_108_COUNTER_CMAC)
#define IFX_PSA_CRYPTOSUITE_CMAC
#endif

/*******************************************************************************
 * Grouped Configuration Macros
 ******************************************************************************/
/** Enable cipher operation support (set if AES is enabled) */
#if defined(IFX_PSA_CRYPTOSUITE_AES)
#define IFX_PSA_CRYPTOSUITE_CIPHER
#endif

/** Enable MAC operation support (set if CMAC is enabled) */
#if defined(IFX_PSA_CRYPTOSUITE_CMAC)
#define IFX_PSA_CRYPTOSUITE_MAC
#endif

/** Enable AEAD operation support (set if CCM is enabled) */
#if defined(IFX_PSA_CRYPTOSUITE_CCM)
#define IFX_PSA_CRYPTOSUITE_AEAD
#endif


/*******************************************************************************
 * Configuration Validation
 ******************************************************************************/
/** Verify that at least one AES mode is selected when AES is enabled */
#if defined(IFX_PSA_CRYPTOSUITE_AES) && (!defined(IFX_PSA_CRYPTOSUITE_AES_ECB) \
  && !defined(IFX_PSA_CRYPTOSUITE_AES_CBC) && !defined(IFX_PSA_CRYPTOSUITE_AES_CFB) \
  && !defined(IFX_PSA_CRYPTOSUITE_AES_CTR))
#error "IFX_PSA_CRYPTOSUITE_AES is defined but no AES mode is selected"
#endif

/** Verify that AES is enabled when CCM is requested */
#if defined(IFX_PSA_CRYPTOSUITE_CCM) && !defined(IFX_PSA_CRYPTOSUITE_AES)
#error "IFX_PSA_CRYPTOSUITE_AES is required for CCM operation"
#endif

/** Verify that AES is enabled when CMAC is requested */
#if defined(IFX_PSA_CRYPTOSUITE_CMAC) && !defined(IFX_PSA_CRYPTOSUITE_AES)
#error "IFX_PSA_CRYPTOSUITE_AES is required for CMAC operation"
#endif

/* Memory Configuration */
#define IFX_MXCRYPTOSUITE_USE_STATIC_MEM
#endif /* IFX_PDL_CRYPTOSUITE_CONFIG_H */
