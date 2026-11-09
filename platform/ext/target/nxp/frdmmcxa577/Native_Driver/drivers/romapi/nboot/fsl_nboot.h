/*
 * Copyright 2025-2026 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef FSL_NBOOT_H_
#define FSL_NBOOT_H_

#include "fsl_common.h"
#include "fsl_nboot_hal.h"

/*!
 * @addtogroup nboot_driver
 * @{
 */
/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @name Driver version */
/*@{*/
/*! @brief ROMAPI_NBOOT driver version 2.0.0. */
#define FSL_ROMAPI_NBOOT_DRIVER_VERSION (MAKE_VERSION(2, 0, 0))
/*@}*/

#define NBOOT_SB4_MANIFEST_MAX_SIZE_IN_BYTES (16UL * 1024UL)
#define NBOOT_SB4_BLOCK_MAX_SIZE_IN_BYTES    (2UL * sizeof(uint32_t) + 48UL + 4UL * 1024UL)

/* size in bytes from start of the manifest, enough bytes that contain encoding of whole manifest size */
#define NBOOT_SB4_GET_INITIAL_FETCH_SIZE (0x90UL)

/* SB4 types */
#define NBOOT_SB4_FWTYPE_DEFAULT 0x123400a1u
#define NBOOT_SB4_FWTYPE_NXP_MFW 0x43215005u
#define NBOOT_SB4_FWTYPE_OEM_MFW 0x1423ccccu
typedef uint32_t nboot_sb4_fwtype_t;

/*!
 * @brief NBOOT type for the root key usage
 *
 * This type defines the NBOOT root key usage
 *
 */
#define kNBOOT_RootKeyUsage_DebugCA_ImageCA_FwCA_ImageKey_FwKey (0x0u)
#define kNBOOT_RootKeyUsage_DebugCA                             (0x1u)
#define kNBOOT_RootKeyUsage_ImageCA_FwCA                        (0x2u)
#define kNBOOT_RootKeyUsage_DebugCA_ImageCA_FwCA                (0x3u)
#define kNBOOT_RootKeyUsage_ImageKey_FwKey                      (0x4u)
#define kNBOOT_RootKeyUsage_ImageKey                            (0x5u)
#define kNBOOT_RootKeyUsage_FwKey                               (0x6u)
#define kNBOOT_RootKeyUsage_Unused                              (0x7u)

/* any other value means the root key is not valid (treat as if revoked) */
typedef uint32_t nboot_root_key_usage_t;

#define NBOOT_ROOT_CERT_COUNT (4u)

/*!
 * @brief NBOOT type for the root key revocation
 *
 * This type defines the NBOOT root key revocation
 *
 */
#define kNBOOT_RootKey_Enabled (0xAAu)
#define kNBOOT_RootKey_Revoked (0xBBu)
/* any other value means the root key is revoked */
typedef uint32_t nboot_root_key_revocation_t;

/*!
 * @brief NBOOT type specifying the elliptic curve to be used
 *
 * This type defines the elliptic curve type and length
 *
 */
#define kNBOOT_RootKey_Ecdsa_P256          (0x0000FE01u)
#define kNBOOT_RootKey_Ecdsa_P384          (0x0000FD02u)
#define kNBOOT_RootKey_MlDsa_87            (0x0000FD03u)
#define kNBOOT_RootKey_Ecdsa_P384_MlDsa_87 (0x0000FD04u)
typedef uint32_t nboot_root_key_type_and_length_t;

/*! @brief Enumeration for SoC Lifecycle. */
#define nboot_lc_nxpBlank       (0xFFFF0000u)
#define nboot_lc_nxpFab         (0xFFFE0001u)
#define nboot_lc_nxpDev         (0xFF0300FCu)
#define nboot_lc_nxpProvisioned (0xFFFC0003u)
#define nboot_lc_oemOpen        (0xFFFC0003u)
#define nboot_lc_oemSecureWorld (0xFFF80007u)
#define nboot_lc_oemClosed      (0xFFF0000Fu)
#define nboot_lc_oemLocked      (0xFF3000CFu)
#define nboot_lc_oemFieldReturn (0xFFE0001Fu)
#define nboot_lc_nxpFieldReturn (0xFF80007Fu)
#define nboot_lc_shredded       (0xFF0000FFu)
typedef uint32_t nboot_soc_lifecycle_t;

/*! @brief Type for nboot status codes */
typedef uint32_t nboot_status_t;

/*! @brief Type for nboot protected status codes */
typedef uint64_t nboot_status_protected_t;

/*! @brief Enumeration for MCUX_CSSL_FP_FUNCID */
#define MCUX_CSSL_FP_FUNCID_NBOOT_ContextInit                         (0x5DA1u)
#define MCUX_CSSL_FP_FUNCID_NBOOT_ContextDeinit                       (0x30DBu)
#define MCUX_CSSL_FP_FUNCID_NBOOT_ContextSetUuid                      (0x5E38u)
#define MCUX_CSSL_FP_FUNCID_NBOOT_Sb4LoadManifest                     (0x42E7u)
#define MCUX_CSSL_FP_FUNCID_NBOOT_Sb4LoadBlock                        (0x275Au)
#define MCUX_CSSL_FP_FUNCID_NBOOT_SB4CheckAuthenticityAndCompleteness (0x22E7u)
#define MCUX_CSSL_FP_FUNCID_NBOOT_ImgAuthenticate                     (0x2EA5u)
#define NBOOT_CONTEXT_RTF_OFFSET                                      (0x100u)

/**
 * \defgroup nbootStatusValues  This type defines status return values used by NBOOT functions that are not easily
 * disturbed by Fault Attacks
 * @{
 */
#define kStatus_NBOOT_Success                ((nboot_status_t)0x5A5A5A5Au) /*!< Operation completed successfully. */
#define kStatus_NBOOT_Fail                   ((nboot_status_t)0x5A5AA5A5u) /*!< Operation failed. */
#define kStatus_NBOOT_InvalidArgument        ((nboot_status_t)0x5A5AA5F0u) /*!< Invalid argument passed to the function. */
#define kStatus_NBOOT_RequestTimeout         ((nboot_status_t)0x5A5AA5E1u) /*!< Operation timed out. */
#define kStatus_NBOOT_KeyNotLoaded           ((nboot_status_t)0x5A5AA5E2u) /*!< The requested key is not loaded. */
#define kStatus_NBOOT_AuthFail               ((nboot_status_t)0x5A5AA5E4u) /*!< Authentication failed. */
#define kStatus_NBOOT_OperationNotAvaialable ((nboot_status_t)0x5A5AA5E5u) /*!< Operation not available on this HW. */
#define kStatus_NBOOT_KeyNotAvailable        ((nboot_status_t)0x5A5AA5E6u) /*!< Key is not avaialble. */
#define kStatus_NBOOT_IvCounterOverflow      ((nboot_status_t)0x5A5AA5E7u) /*!< Overflow of IV counter (PRINCE/IPED). */
#define kStatus_NBOOT_SelftestFail           ((nboot_status_t)0x5A5AA5E8u) /*!< FIPS self-test failure. */
#define kStatus_NBOOT_InvalidDataFormat      ((nboot_status_t)0x5A5AA5E9u) /*!< Invalid data format for example antipole */
#define kStatus_NBOOT_IskCertUserDataTooBig \
    ((nboot_status_t)0x5A5AA5EAu) /*!< Size of User data in ISK certificate is greater than 96 bytes */
#define kStatus_NBOOT_IskCertSignatureOffsetTooSmall \
    ((nboot_status_t)0x5A5AA5EBu) /*!< Signature offset in ISK certificate is smaller than expected */
#define kStatus_NBOOT_MemcpyFail     ((nboot_status_t)0x5A5A845A) /*!< Unexpected error detected during nboot_memcpy() */
#define kStatus_NBOOT_RegionIsLocked ((nboot_status_t)0x5A5AA5ECu) /*!< IPED/NPX region is locked */
#define kStatus_NBOOT_SB3_Hashing \
    ((nboot_status_t)0x5A2112CCu) /*!< nboot_sb3_load_block () background hashing started */
#define kStatus_NBOOT_SB3_Decrypting \
    ((nboot_status_t)0x5ACC1221u) /*!< nboot_sb3_load_block () background decrypting started */
#define kStatus_NBOOT_SB4_Hashing \
    ((nboot_status_t)0x5A2112CEu) /*!< nboot_sb4_load_block () background hashing started */
#define kStatus_NBOOT_SB4_Decrypting \
    ((nboot_status_t)0x5ACC122Eu) /*!< nboot_sb4_load_block () background decrypting started */
/**@}*/

#define NBOOT_RKTH_SIZE_IN_WORDS (12u)

/*! @brief Data structure holding secure counter value used by nboot library */
typedef struct _nboot_secure_counter
{
    uint32_t sc;
    uint32_t scAp;
} nboot_secure_counter_t;

typedef struct nboot_trng_cfg_load
{
    uint32_t configData[13];
} nboot_trng_cfg_load_t;

typedef struct nboot_context_struct
{
    uint8_t opaque[0x00000A94u];
} nboot_context_t;
/*!
 * @brief NBOOT type for the root of trust parameters
 *
 * This type defines the NBOOT root of trust parameters
 *
 */
typedef struct nboot_rot_auth_parms_
{
    /* trusted information originated from CFPA */
    nboot_root_key_revocation_t soc_rootKeyRevocation[NBOOT_ROOT_CERT_COUNT]; /*!< Provided by caller based on NVM
                                                                                 information in CFPA: ROTKH_REVOKE */
    uint32_t soc_imageKeyRevocation; /*!< Provided by caller based on NVM information in CFPA: IMAGE_KEY_REVOKE */

    /* trusted information originated from CMPA */
    uint32_t soc_rkh[NBOOT_RKTH_SIZE_IN_WORDS]; /*!< Provided by caller based on NVM information in CMPA: ROTKH (hash of
                                                   hashes) */
                                                /*!< In case of kNBOOT_RootKey_Ecdsa_P384, sock_rkh[0..11] are used */
                                                /*!< In case of kNBOOT_RootKey_Ecdsa_P256, sock_rkh[0..7] are used */
                                                /*!< In case of kNBOOT_RootKey_MlDsa_87, sock_rkh[0..11] are used */

    uint32_t soc_rkh_1[NBOOT_RKTH_SIZE_IN_WORDS]; /*!< Provided by caller based on NVM information in CMPA: ROTKH (hash
                                                     of hashes) */
                                                  /*!< In case of kNBOOT_RootKey_MlDsa_87, sock_rkh[0..11] are used */

    uint32_t soc_numberOfRootKeys;                /* unsigned int, must be 4 */
    nboot_root_key_usage_t soc_rootKeyUsage[NBOOT_ROOT_CERT_COUNT]; /* CMPA */
    nboot_root_key_type_and_length_t
        soc_rootKeyTypeAndLength; /* static selection between ECDSA P-256 or ECDSA P-384 based root keys */

    /* trusted information originated from OTP fuses */
    nboot_soc_lifecycle_t soc_lifecycle;
} nboot_rot_auth_parms_t;

/*
typedef struct nboot_prng_context
{
    uint32_t    ctxA;
    uint32_t    ctxB;
    uint32_t    ctxC;
    uint32_t    ctxD;
    uint32_t    status;
} nboot_prng_context_t;
*/

/*! @brief Data structure holding input arguments to POR secure boot (authentication) algorithm. Shall be read from SoC
 * trusted NVM or SoC fuses. */
typedef struct nboot_img_auth_parms_struct
{
    /* trusted information originated from CFPA and NMPA */
    nboot_rot_auth_parms_t soc_RoTNVM;

    uint32_t soc_trustedFirmwareVersion; /*!< Provided by caller based on NVM information in CFPA: Secure_FW_Version */
} nboot_img_auth_parms_t;

/*!
 * @brief  manifest loading parameters
 *
 * This type defines the NBOOT SB4 manifest loading parameters
 *
 */
typedef struct nboot_sb4_load_manifest_parms_struct
{
    nboot_rot_auth_parms_t soc_RoTNVM;   /*! trusted information originated from CFPA and NMPA */
    uint32_t soc_trustedFirmwareVersion; /*!< Provided by caller based on NVM information in CFPA: Secure_FW_Version */
    uint32_t maxBlockSize;               /*!< Provided by caller: supported maximal data block size (complete block)*/
    uint8_t pckBlob[48]; /* CUST_MK_SK rfc3394 blob. It is maximum size, that maps to RFC3394 for ELS S50 symmetric
                            256-bit key. */
} nboot_sb4_load_manifest_parms_t;

/*!
 * @brief Boolean type for the NBOOT functions
 *
 * This type defines boolean values used by NBOOT functions that are not easily disturbed by Fault Attacks
 */
typedef enum _nboot_bool
{
    kNBOOT_TRUE                = 0x3C5AC33CU, /*!< Value for TRUE.  */
    kNBOOT_TRUE256             = 0x3C5AC35AU, /*!< Value for TRUE when P256 was used to sign the image.  */
    kNBOOT_TRUE384             = 0x3C5AC3A5U, /*!< Value for TRUE when P384 was used to sign the image.  */
    kNBOOT_FALSE               = 0x5AA55AA5U, /*!< Value for FALSE. */
    kNBOOT_OperationAllowed    = 0x3c5a33ccU,
    kNBOOT_OperationDisallowed = 0x5aa5cc33U,
} nboot_bool_t;

typedef enum
{
    kNBOOT_MemCrypt12Rounds          = 0x3c5ac33cu,
    kNBOOT_MemCrypt22Rounds          = 0x5aa55aa5u,
    kNBOOT_MemCryptFullyPipelined    = 0x5a5a5a5au,
    kNBOOT_MemCryptNotFullyPipelined = 0xa5a5a5a5u,
} nboot_mem_crypt_iped_mode_select_t;

typedef uint32_t nboot_mem_crypt_region_t;
typedef uint32_t nboot_mem_crypt_operation_t;

typedef enum
{
    kNBOOT_MemCryptNpx  = 0x59595959u,
    kNBOOT_MemCryptIped = 0x95959595u,
} nboot_mem_crypt_engine_type_t;

typedef struct nboot_npx_region_config_struct
{
    nboot_mem_crypt_engine_type_t configId; /* Should be always set to kNBOOT_MemCryptNpx */
    uint32_t startAddress;                  /* used as input in nboot_mem_crypt_enable_encrypt_for_address_range() */
    uint32_t endAddress;                    /* used as input in nboot_mem_crypt_enable_encrypt_for_address_range() */
    uint64_t subregion; /* NPX_CTXx_WDx setting from CMPA (upper 32bits NPX_CTX0_WD1 lower 32bits NPX_CTX0_WD0). Used as
                        input in nboot_mem_crypt_configure() */
    uint32_t ivEraseCounter; /* MCTR_NPX_CTXx value from CFPA */
    uint8_t regionLock;      /* NPX_LOCK_CTXx value from CMPA, bits[1:0] 00 - not locked, 01,10,11 - region locked */
} nboot_npx_region_config_t;

typedef struct nboot_iped_region_config_struct
{
    nboot_mem_crypt_engine_type_t configId; /* Should be always set to kNBOOT_MemCryptIped */
    uint32_t startAddress;                  /* IPEDx_START value from CMPA (AHBERRDIS & GCM_MODE must be excluded) */
    uint32_t endAddress;                    /* IPEDx_END value from CMPA (LOCK_EN must be excluded) */
    uint32_t ivEraseCounter;                /* MCTR_IPED_CTXx value from CFPA */
    uint8_t
        regionFlags; /* val from CMPA(part of IPEDx_END), bits[1:0] - LOCK_EN; 00 - not locked, 01,10,11 - region locked
                     val from CMPA(part of IPEDx_START), bit[2] - GCM_MODE; 0 - CTR mode, 1 - GCM mode
                     val from CMPA(part of IPEDx_START), bit[3] - AHBERRDIS; 0 - bus err enabled, 1 - bus err
                     disabled */
    uint32_t aad;    /* Additional Authentication Data - value from CFPA (IPED_GCM_AAD_CTXx) */
} nboot_iped_region_config_t;

/* This union is used as an input to nboot_mem_crypt_enable_encrypt_for_address_range() function */
typedef union nboot_mem_crypt_region_config_union
{
    nboot_npx_region_config_t npxConfig;
    nboot_iped_region_config_t ipedConfig;
} nboot_mem_crypt_region_config_t;

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
 * API
 ******************************************************************************/

/*!
 * @brief The function is used for initializing of the nboot context data structure.
 *        It should be called prior to any other calls of nboot API.
 *
 * @param nbootCtx Pointer to nboot_context_t structure.
 *
 * @retval #kStatus_NBOOT_Success Operation successfully finished
 * @retval #kStatus_NBOOT_Fail Error occured during operation
 */
nboot_status_protected_t NBOOT_ContextInit(nboot_context_t *context);

/*!
 * @brief The function is used to deinitialize nboot context data structure.
 * Its contents are overwritten with random data so that any sensitive data does not remain in memory.
 *
 * @param context Pointer to nboot_context_t structure.

 * @retval #kStatus_NBOOT_Success Operation successfully finished
 * @retval #kStatus_NBOOT_Fail Error occured during operation
 */
nboot_status_protected_t NBOOT_ContextDeinit(nboot_context_t *context);

/*!
 * @brief Set UUID in the nboot context
 *
 * This function sets the UUID (Universally Unique Identifier) in the nboot context structure.
 * The NBOOT context has to be initialized by the function nboot_context_init before calling
 * this function.
 *
 * @param context Pointer to nboot_context_t structure.
 * @param uuid Pointer to 16-byte UUID array to be set in the context.
 *
 * @retval #kStatus_NBOOT_Success Operation successfully finished
 * @retval #kStatus_NBOOT_Fail Error occured during operation
 */
nboot_status_protected_t NBOOT_ContextSetUuid(nboot_context_t *context, const uint8_t uuid[16]);

/*!
 * @brief Load NBOOT SB4 manifest
 *
 * This function loads and processes an NBOOT SB4 manifest. The manifest contains metadata
 * and configuration information for the SB4 file processing. The NBOOT context has to be
 * initialized by the function nboot_context_init before calling this function.
 *
 * @param context Pointer to nboot_context_t structure.
 * @param manifest Pointer to the SB4 manifest data.
 * @param parms Pointer to a data structure in trusted memory, holding input parameters for the algorithm.
 *              The data structure shall be correctly filled before the function call.
 *
 * @retval #kStatus_NBOOT_Success Operation successfully finished
 * @retval #kStatus_NBOOT_Fail Error occured during operation
 */
nboot_status_protected_t NBOOT_Sb4LoadManifest(nboot_context_t *context,
                                               const uint32_t *manifest,
                                               nboot_sb4_load_manifest_parms_t *parms);

/*!
 * @brief Load NBOOT SB4 block
 *
 * This function loads and processes an NBOOT SB4 block. The NBOOT context has to be
 * initialized by the function nboot_context_init before calling this function.
 *
 * @param context Pointer to nboot_context_t structure.
 * @param block Pointer to the SB4 block data to be loaded.
 *
 * @retval #kStatus_NBOOT_Success Operation successfully finished
 * @retval #kStatus_NBOOT_Fail Error occured during operation
 */
nboot_status_protected_t NBOOT_Sb4LoadBlock(nboot_context_t *context, uint32_t *block);

/*!
 * @brief Check authenticity and completeness of NBOOT SB4 file
 *
 * This function verifies the authenticity and completeness of an NBOOT SB4 file.
 * The NBOOT context has to be initialized by the function nboot_context_init before calling this function.
 *
 * @param context Pointer to nboot_context_t structure.
 * @param address Pointer to the SB4 file data in memory.
 * @param parms Pointer to a data structure in trusted memory, holding input parameters for the algorithm.
 *              The data structure shall be correctly filled before the function call.
 *
 * @retval #kStatus_NBOOT_Success Operation successfully finished
 * @retval #kStatus_NBOOT_Fail Error occured during operation
 */
nboot_status_protected_t NBOOT_SB4CheckAuthenticityAndCompleteness(nboot_context_t *context,
                                                                   const uint32_t *address,
                                                                   nboot_sb4_load_manifest_parms_t *parms);

/*!
 * @brief Authenticate NBOOT image
 *
 * This function authenticates an NBOOT image by verifying its signature and integrity.
 * The NBOOT context has to be initialized by the function nboot_context_init before calling this function.
 *
 * @param context Pointer to nboot_context_t structure.
 * @param imageStartAddress Pointer to the start address of the image data to be authenticated.
 * @param isSignatureVerified Pointer to a boolean flag that will be set to indicate if the signature was verified.
 * @param parms Pointer to a data structure in trusted memory, holding input parameters for the algorithm.
 *              The data structure shall be correctly filled before the function call.
 *
 * @retval #kStatus_NBOOT_Success Operation successfully finished
 * @retval #kStatus_NBOOT_Fail Error occured during operation
 */
nboot_status_protected_t NBOOT_ImgAuthenticate(nboot_context_t *context,
                                               const uint8_t imageStartAddress[],
                                               nboot_bool_t *isSignatureVerified,
                                               nboot_img_auth_parms_t *parms);

/*!
 * @brief Enable memory encryption for address range
 *
 * This function enables memory encryption for a specified address range using the NBOOT
 * memory cryptography features. The NBOOT context has to be initialized by the function
 * nboot_context_init before calling this function.
 *
 * @param context Pointer to nboot_context_t structure.
 * @param regionNumber The memory region number to configure.
 * @param regionConfig Pointer to the region configuration structure.
 * @param ipedModeSelect IPED mode selection parameter.
 *
 * @retval #kStatus_NBOOT_Success Operation successfully finished
 * @retval #kStatus_NBOOT_Fail Error occured during operation
 */
nboot_status_protected_t NBOOT_MemCryptEnableEncryptForAddressRange(nboot_context_t *context,
                                                                    nboot_mem_crypt_region_t regionNumber,
                                                                    nboot_mem_crypt_region_config_t *regionConfig,
                                                                    nboot_mem_crypt_iped_mode_select_t ipedModeSelect);

/*!
 * @brief Memory cryptography range checker
 *
 * This function performs range checking for memory cryptography operations.
 * The NBOOT context has to be initialized by the function nboot_context_init before calling this function.
 *
 * @param context Pointer to nboot_context_t structure.
 * @param operation The memory cryptography operation type.
 * @param address The start address to check.
 * @param length The length of the memory range to check.
 * @param flags Pointer to flags output parameter.
 * @param npx_iv_erase_cntr Pointer to NPX IV erase counter output parameter.
 * @param iped_iv_erase_cntr Pointer to IPED IV erase counter output parameter.
 * @param npx_erase_check_en NPX erase check enable parameter.
 *
 * @retval #kStatus_NBOOT_Success Operation successfully finished
 * @retval #kStatus_NBOOT_Fail Error occured during operation
 */
nboot_status_protected_t NBOOT_MemCryptRangeChecker(nboot_context_t *context,
                                                    nboot_mem_crypt_operation_t operation,
                                                    uint32_t address,
                                                    uint32_t length,
                                                    uint8_t *flags,
                                                    uint32_t *npx_iv_erase_cntr,
                                                    uint32_t *iped_iv_erase_cntr,
                                                    uint32_t npx_erase_check_en);

/*!
 * @brief Enable background hash
 *
 * This function enables background hash functionality using the specified DMA channel.
 * The NBOOT context has to be initialized by the function nboot_context_init before calling this function.
 *
 * @param context Pointer to nboot_context_t structure.
 * @param hashDmaChannel The DMA channel to use for background hash operations.
 *
 * @retval #kStatus_NBOOT_Success Operation successfully finished
 * @retval #kStatus_NBOOT_Fail Error occured during operation
 */
nboot_status_protected_t NBOOT_BackgroundHashEnable(nboot_context_t *context, uint32_t hashDmaChannel);

#ifdef __cplusplus
}
#endif

/**
 * @}
 */

#endif /* FSL_NBOOT_H_ */
