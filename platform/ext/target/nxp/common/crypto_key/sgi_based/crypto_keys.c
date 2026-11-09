/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 * Copyright 2026 NXP
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

#include <stdbool.h>
#include <string.h>
#include "tfm_plat_crypto_keys.h"
#include "tfm_builtin_key_ids.h"
#include "tfm_plat_otp.h"
#include "psa_manifest/pid.h"
#include "tfm_builtin_key_loader.h"

#if USE_SGI_HUK
#include "tfm_log.h"
#endif /* USE_SGI_HUK */

#if USE_SGI_HUK
#include <mcuxClSession.h>
#include <mcuxClKey.h>
#include <mcuxClKdfModes.h>
#include <mcuxClAes.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClCore_FunctionIdentifiers.h>
#include <mcuxClBuffer.h>
#include <mcuxClExample_Session_Helper.h>
#include <mcuxClRandom.h>
#include <mcuxClResource.h>
#endif /* USE_SGI_HUK */

#define NUMBER_OF_ELEMENTS_OF(x) sizeof(x)/sizeof(*x)
#define MAPPED_TZ_NS_AGENT_DEFAULT_CLIENT_ID -0x3c000000
#define TFM_NS_PARTITION_ID                  MAPPED_TZ_NS_AGENT_DEFAULT_CLIENT_ID

/* -------------------------------------------------------------------------- */
/* SGI low-level API placeholders                                              */
/* -------------------------------------------------------------------------- */
#if USE_SGI_HUK
static const uint8_t label[] = "NXP|TFM|HUK|CRYPTO|STORAGE";
static const uint8_t context[] = "HUK|AES-GCM-128";

/* -------------------------------------------------------------------------- */
/* Unprovisioned-DUK detection (optional)                                      */
/*                                                                             */
/* The HUK is derived from the DUK that the ROM leaves in SGI key slot 6.      */
/* That slot is write-only on this SoC family (SGI_KEY_WRITEONLY_START == 16,  */
/* so slot 6 maps to key index 24), it cannot be read back, and               */
/* mcuxClKey_loadCopro(..ALREADYLOADED) performs no HW access and therefore    */
/* always returns MCUXCLKEY_STATUS_OK. SGI also has no "key slot active" flag  */
/* (unlike ELS, where the els_based variant of this file can test              */
/* mcuxClEls_KeyProp_t.bits.kactv). So DUK presence cannot be proven in SW.    */
/*                                                                             */
/* What IS detectable is the dominant failure mode: a slot that was never      */
/* written still reads as all zeroes, in which case every such device derives  */
/* the SAME HUK - and therefore the same ITS/PS encryption keys.               */
/*                                                                             */
/* Build-time configuration:                                                   */
/*                                                                             */
/*   SGI_HUK_CHECK_UNPROVISIONED_DUK                                           */
/*       0 - compile the check out entirely (no code, no extra derivation).    */
/*       1 - run the check (default).                                          */
/*                                                                             */
/*   SGI_HUK_ENFORCE_PROVISIONED_DUK                                           */
/*       0 - report the problem and still return the HUK, so an unprovisioned  */
/*           bring-up board keeps working (default).                           */
/*       1 - fail closed: refuse to hand out a non-device-unique HUK.          */
/*                                                                             */
/* NOTE: with enforcement off, an unprovisioned device still receives a HUK    */
/* that is NOT device-unique. This is intended for bring-up/debug only; it     */
/* must be turned on for production, where secure objects would otherwise be   */
/* clonable between devices.                                                   */
/*                                                                             */
/* Reporting: the result is logged from here, directly after derivation. This  */
/* is safe because TFM_SP_CRYPTO is a PSA-ROT partition, which                 */
/* tfm_hal_isolation.c maps to privileged at both isolation levels, and        */
/* because tfm_hal_platform_init() - which runs stdio_init() - completes well  */
/* before the partitions are started, so the console is up by the time the HUK */
/* is derived. Verified on frdmkw43: the "[HUK] ..." line appears after        */
/* "Booting TF-M".                                                            */
/* -------------------------------------------------------------------------- */
#ifndef SGI_HUK_CHECK_UNPROVISIONED_DUK
#define SGI_HUK_CHECK_UNPROVISIONED_DUK 1
#endif

#ifndef SGI_HUK_ENFORCE_PROVISIONED_DUK
#define SGI_HUK_ENFORCE_PROVISIONED_DUK 0
#endif

#if (SGI_HUK_ENFORCE_PROVISIONED_DUK != 0) && (SGI_HUK_CHECK_UNPROVISIONED_DUK == 0)
#error "SGI_HUK_ENFORCE_PROVISIONED_DUK requires SGI_HUK_CHECK_UNPROVISIONED_DUK"
#endif

/* -------------------------------------------------------------------------- */
/* Derive HUK from the DUK held in SGI key slot 6                              */
/* -------------------------------------------------------------------------- */

/* Wipe that the compiler cannot elide (plain memset on a dying buffer can be
 * removed as a dead store). */
static void huk_secure_zeroize(void *p, size_t n)
{
    volatile uint8_t *v = (volatile uint8_t *)p;
    while (n-- > 0u) {
        *v++ = 0u;
    }
}

#if (SGI_HUK_CHECK_UNPROVISIONED_DUK != 0)
/* Constant-time all-zero test. Returns true if every byte is 0. */
static bool huk_buffer_is_all_zero(const uint8_t *p, size_t n)
{
    uint8_t acc = 0u;

    for (size_t i = 0u; i < n; i++) {
        acc |= p[i];
    }

    return (acc == 0u);
}

/*
 * Constant-time comparison. Returns true when the two buffers are equal.
 * Used on derived key material, so it must not leak via early exit.
 */
static bool huk_buffer_equal(const uint8_t *a, const uint8_t *b, size_t n)
{
    uint8_t diff = 0u;

    for (size_t i = 0u; i < n; i++) {
        diff |= (uint8_t)(a[i] ^ b[i]);
    }

    return (diff == 0u);
}

/*
 * Re-run the identical derivation (same mode, same label and context) over an
 * all-zero AES-256 key - i.e. what a never-written key slot would yield - and
 * compare it against the HUK we just derived.
 *
 * Sets *is_zero_duk to true when the two match, meaning the derivation was not
 * device-unique. Returns an error only if the check itself could not run.
 *
 * This is best-effort: a slot programmed with a non-zero but non-unique value
 * cannot be detected in software. Provisioning and lifecycle management remain
 * the authoritative control.
 */
static enum tfm_plat_err_t huk_is_derived_from_zero_duk(mcuxClSession_Handle_t session,
                                                        const uint8_t *derived_huk,
                                                        size_t derived_huk_len,
                                                        bool *is_zero_duk)
{
    enum tfm_plat_err_t err = TFM_PLAT_ERR_SYSTEM_ERR;

    /* An all-zero AES-256 key, representing an unwritten key slot. */
    const uint8_t zero_duk[MCUXCLAES_AES256_KEY_SIZE] = {0u};

    uint32_t zeroKeyDesc[MCUXCLKEY_DESCRIPTOR_SIZE_IN_WORDS] = {0u};
    uint32_t refKeyDesc[MCUXCLKEY_DESCRIPTOR_SIZE_IN_WORDS] = {0u};
    uint8_t refKeyBuf[MCUXCLAES_AES256_KEY_SIZE];

    MCUX_CSSL_ANALYSIS_START_PATTERN_REINTERPRET_MEMORY_OF_OPAQUE_TYPES()
    mcuxClKey_Handle_t zeroKey = (mcuxClKey_Handle_t) &zeroKeyDesc;
    mcuxClKey_Handle_t refKey  = (mcuxClKey_Handle_t) &refKeyDesc;
    MCUX_CSSL_ANALYSIS_STOP_PATTERN_REINTERPRET_MEMORY_OF_OPAQUE_TYPES()

    *is_zero_duk = false;

    if (derived_huk_len != sizeof(refKeyBuf)) {
        return TFM_PLAT_ERR_INVALID_INPUT;
    }

    /* Derivation key = all-zero AES-256 key, held in CPU memory (not a slot). */
    MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(zk_status, zk_token, mcuxClKey_init(
      /* mcuxClSession_Handle_t session: */ session,
      /* mcuxClKey_Handle_t key:         */ zeroKey,
      /* mcuxClKey_Type_t type:          */ mcuxClKey_Type_Aes256,
      /* uint8_t * pKeyData:            */ (uint8_t *) zero_duk,
      /* uint32_t keyDataLength:        */ sizeof(zero_duk)));
    if ((MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClKey_init) != zk_token) ||
        (MCUXCLKEY_STATUS_OK != zk_status)) {
        goto exit;
    }
    MCUX_CSSL_FP_FUNCTION_CALL_END();

    MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(rk_status, rk_token, mcuxClKey_init(
      /* mcuxClSession_Handle_t session: */ session,
      /* mcuxClKey_Handle_t key:         */ refKey,
      /* mcuxClKey_Type_t type:          */ mcuxClKey_Type_Aes256,
      /* uint8_t * pKeyData:            */ refKeyBuf,
      /* uint32_t keyDataLength:        */ sizeof(refKeyBuf)));
    if ((MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClKey_init) != rk_token) ||
        (MCUXCLKEY_STATUS_OK != rk_status)) {
        goto exit;
    }
    MCUX_CSSL_FP_FUNCTION_CALL_END();

    /* Same label/context/mode as the real derivation. */
    MCUXCLBUFFER_INIT_RO(refLabelBuf, session, label, sizeof(label));
    MCUXCLBUFFER_INIT_RO(refContextBuf, session, context, sizeof(context));
    struct mcuxClKey_DerivationInput refInputLabel   = {.input = refLabelBuf,
                                                        .size = sizeof(label) - 1u};
    struct mcuxClKey_DerivationInput refInputContext = {.input = refContextBuf,
                                                        .size = sizeof(context) - 1u};
    mcuxClKey_DerivationInput_t refInputs[] = {refInputLabel, refInputContext};

    MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(rd_status, rd_token, mcuxClKey_derivation(
      /* mcuxClSession_Handle_t pSession       */ session,
      /* mcuxClKey_Derivation_t derivationMode */ mcuxClKdfModes_SP800_108_CM_CMAC,
      /* mcuxClKey_Handle_t derivationKey      */ zeroKey,
      /* mcuxClKey_DerivationInput_t inputs[]  */ refInputs,
      /* uint32_t numberOfInputs              */ 2u,
      /* mcuxClKey_Handle_t derivedKey         */ refKey));
    if ((MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClKey_derivation) != rd_token) ||
        (MCUXCLKEY_STATUS_OK != rd_status)) {
        goto exit;
    }
    MCUX_CSSL_FP_FUNCTION_CALL_END();

    *is_zero_duk = huk_buffer_equal(derived_huk, refKeyBuf, sizeof(refKeyBuf));
    err = TFM_PLAT_ERR_SUCCESS;

exit:
    huk_secure_zeroize(refKeyBuf, sizeof(refKeyBuf));
    huk_secure_zeroize(refKeyDesc, sizeof(refKeyDesc));
    huk_secure_zeroize(zeroKeyDesc, sizeof(zeroKeyDesc));

    return err;
}

/*
 * Run the unprovisioned-DUK checks on a freshly derived HUK and report the
 * outcome on the console.
 *
 * Returns TFM_PLAT_ERR_SUCCESS when the HUK may be used; whether a detected
 * problem becomes a failure depends on SGI_HUK_ENFORCE_PROVISIONED_DUK.
 */
static enum tfm_plat_err_t huk_validate_provisioning(mcuxClSession_Handle_t session,
                                                     const uint8_t *derived_huk,
                                                     size_t derived_huk_len)
{
    bool is_zero_duk = false;
    enum tfm_plat_err_t chk_err;

    /* A sane KDF never returns all zeroes; if it does, the HW did not run.
     * This is a derivation failure, not a provisioning state, so it is always
     * fatal regardless of the enforcement setting. */
    if (huk_buffer_is_all_zero(derived_huk, derived_huk_len)) {
        ERROR("[HUK] SGI derivation produced an all-zero key\n");
        return TFM_PLAT_ERR_SYSTEM_ERR;
    }

    chk_err = huk_is_derived_from_zero_duk(session, derived_huk,
                                           derived_huk_len, &is_zero_duk);
    if (chk_err != TFM_PLAT_ERR_SUCCESS) {
        ERROR("[HUK] unprovisioned-DUK check could not be executed\n");
#if (SGI_HUK_ENFORCE_PROVISIONED_DUK != 0)
        return chk_err;
#else
        return TFM_PLAT_ERR_SUCCESS;
#endif
    }

    if (is_zero_duk) {
        ERROR("[HUK] SGI key slot 6 is empty - device is NOT provisioned, "
              "the derived HUK is NOT device-unique and secure objects are "
              "clonable between devices\n");
#if (SGI_HUK_ENFORCE_PROVISIONED_DUK != 0)
        return TFM_PLAT_ERR_NOT_PERMITTED;
#else
        ERROR("[HUK] continuing anyway (SGI_HUK_ENFORCE_PROVISIONED_DUK=0) - "
              "not suitable for production\n");
#endif
    } else {
        INFO("[HUK] DUK present in SGI key slot 6, HUK is device-unique\n");
    }

    return TFM_PLAT_ERR_SUCCESS;
}
#endif /* SGI_HUK_CHECK_UNPROVISIONED_DUK */

/*
 * NOTE: the MCUXCLEXAMPLE_* session/PRNG helper macros must NOT be used here.
 * On failure they execute `return MCUXCLEXAMPLE_STATUS_ERROR;` which is
 * `false` == 0 == TFM_PLAT_ERR_SUCCESS, i.e. a failed session/PRNG init would
 * be reported to tfm_builtin_key_loader as a successfully loaded HUK with an
 * uninitialised buffer and key length.
 *
 * NOTE: the DUK in SGI slot 6 is write-only and cannot be read back or
 * validated directly, and mcuxClKey_loadCopro(..ALREADYLOADED) only fills the
 * RAM descriptor and always returns OK. Device provisioning / lifecycle
 * remains the authoritative control for DUK presence and uniqueness. The
 * detectable subset (an all-zero, i.e. never written, key slot) is checked by
 * huk_validate_provisioning() when SGI_HUK_CHECK_UNPROVISIONED_DUK is enabled.
 */
static enum tfm_plat_err_t tfm_plat_get_huk_via_sgi(uint8_t *buf, size_t buf_len, size_t *key_len)
{
    enum tfm_plat_err_t err = TFM_PLAT_ERR_SYSTEM_ERR;
    bool session_initialized = false;

    mcuxClSession_Descriptor_t sessionDesc;
    mcuxClSession_Handle_t session = &sessionDesc;
    uint32_t cpuWaBuffer[MCUXCLEXAMPLE_ALLOCATE_CPUWA(MCUXCLKEY_DERIVATION_CPU_WA_SIZE)];
    uint32_t resCtx[MCUXCLRESOURCE_CONTEXT_SIZE / sizeof(uint32_t)];

    uint32_t keyHandleDesc[MCUXCLKEY_DESCRIPTOR_SIZE_IN_WORDS] = {0u};
    uint32_t derivedKeyDesc[MCUXCLKEY_DESCRIPTOR_SIZE_IN_WORDS] = {0u};
    uint8_t derivedKeyBuf[MCUXCLAES_AES256_KEY_SIZE];

    MCUX_CSSL_ANALYSIS_START_PATTERN_REINTERPRET_MEMORY_OF_OPAQUE_TYPES()
    mcuxClKey_Handle_t keyHandle  = (mcuxClKey_Handle_t) &keyHandleDesc;
    mcuxClKey_Handle_t derivedKey = (mcuxClKey_Handle_t) &derivedKeyDesc;
    MCUX_CSSL_ANALYSIS_STOP_PATTERN_REINTERPRET_MEMORY_OF_OPAQUE_TYPES()

    if ((buf == NULL) || (key_len == NULL) || (buf_len < sizeof(derivedKeyBuf))) {
        return TFM_PLAT_ERR_INVALID_INPUT;
    }

    /* Never leave a stale length behind on an error path. */
    *key_len = 0u;

    /**************************************************************************/
    /* Session + PRNG                                                         */
    /**************************************************************************/
    MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(si_status, si_token, mcuxClSession_init(
      /* mcuxClSession_Handle_t session: */ session,
      /* uint32_t * const cpuWaBuffer:  */ cpuWaBuffer,
      /* uint32_t cpuWaSize:            */ MCUXCLKEY_DERIVATION_CPU_WA_SIZE,
      MCUX_CSSL_ANALYSIS_START_SUPPRESS_DISCARD_CONST_QUALIFIER()
      /* uint32_t * const pkcWaBuffer:  */ (uint32_t *) PKC_RAM_ADDR,
      MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DISCARD_CONST_QUALIFIER()
      /* uint32_t pkcWaSize:            */ 0u));
    if ((MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_init) != si_token) ||
        (MCUXCLSESSION_STATUS_OK != si_status)) {
        goto exit;
    }
    MCUX_CSSL_FP_FUNCTION_CALL_END();
    session_initialized = true;

    if (!mcuxClExample_Session_InitAndSetResourceCtx(session, (mcuxClResource_Context_t *)resCtx)) {
        goto exit;
    }

    MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(prng_status, prng_token, mcuxClRandom_ncInit(session));
    if ((MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRandom_ncInit) != prng_token) ||
        (MCUXCLRANDOM_STATUS_OK != prng_status)) {
        goto exit;
    }
    MCUX_CSSL_FP_FUNCTION_CALL_END();

    /**************************************************************************/
    /* Key handle linked with SGI_KEY_SLOT 6 (DUK, already loaded by ROM)     */
    /**************************************************************************/
    MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(kiKwk_status, kiKwk_token, mcuxClKey_init(
      /* mcuxClSession_Handle_t session: */ session,
      /* mcuxClKey_Handle_t key:         */ keyHandle,
      /* mcuxClKey_Type_t type:          */ mcuxClKey_Type_Aes256,
      /* uint8_t * pKeyData:            */ (uint8_t *) NULL, /* key is already loaded */
      /* uint32_t keyDataLength:        */ 0u));
    if ((MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClKey_init) != kiKwk_token) ||
        (MCUXCLKEY_STATUS_OK != kiKwk_status)) {
        goto exit;
    }
    MCUX_CSSL_FP_FUNCTION_CALL_END();

    /* Only finishes the RAM descriptor; does not touch HW (cannot fail). */
    MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(klKwk_status, klKwk_token, mcuxClKey_loadCopro(
      /* mcuxClSession_Handle_t session: */ session,
      /* mcuxClKey_Handle_t key:         */ keyHandle,
      /* uint32_t loadOptions:          */ MCUXCLKEY_LOADOPTION_SLOT_SGI_KEY_6
                                           | MCUXCLKEY_LOADOPTION_ALREADYLOADED));
    if ((MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClKey_loadCopro) != klKwk_token) ||
        (MCUXCLKEY_STATUS_OK != klKwk_status)) {
        goto exit;
    }
    MCUX_CSSL_FP_FUNCTION_CALL_END();

    /**************************************************************************/
    /* Key Derivation: SP800-108 counter mode, CMAC                           */
    /**************************************************************************/
    MCUXCLBUFFER_INIT_RO(labelBuf, session, label, sizeof(label));
    MCUXCLBUFFER_INIT_RO(contextBuf, session, context, sizeof(context));
    /* exclude '\0', subtract 1 from total size */
    struct mcuxClKey_DerivationInput inputLabel   = {.input = labelBuf,   .size = sizeof(label) - 1u};
    struct mcuxClKey_DerivationInput inputContext = {.input = contextBuf, .size = sizeof(context) - 1u};
    mcuxClKey_DerivationInput_t inputs[] = {inputLabel, inputContext};

    MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(resultKeyInit2, tokenKeyInit2, mcuxClKey_init(
      /* mcuxClSession_Handle_t session */ session,
      /* mcuxClKey_Handle_t key         */ derivedKey,
      /* mcuxClKey_Type_t type          */ mcuxClKey_Type_Aes256,
      /* uint8_t * pKeyData            */ derivedKeyBuf,
      /* uint32_t keyDataLength        */ sizeof(derivedKeyBuf)));
    if ((MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClKey_init) != tokenKeyInit2) ||
        (MCUXCLKEY_STATUS_OK != resultKeyInit2)) {
        goto exit;
    }
    MCUX_CSSL_FP_FUNCTION_CALL_END();

    MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(resultDeriv, tokenDeriv, mcuxClKey_derivation(
      /* mcuxClSession_Handle_t pSession       */ session,
      /* mcuxClKey_Derivation_t derivationMode */ mcuxClKdfModes_SP800_108_CM_CMAC,
      /* mcuxClKey_Handle_t derivationKey      */ keyHandle,
      /* mcuxClKey_DerivationInput_t inputs[]  */ inputs,
      /* uint32_t numberOfInputs              */ 2u,
      /* mcuxClKey_Handle_t derivedKey         */ derivedKey));
    if ((MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClKey_derivation) != tokenDeriv) ||
        (MCUXCLKEY_STATUS_OK != resultDeriv)) {
        goto exit;
    }
    MCUX_CSSL_FP_FUNCTION_CALL_END();

#if (SGI_HUK_CHECK_UNPROVISIONED_DUK != 0)
    err = huk_validate_provisioning(session, derivedKeyBuf, sizeof(derivedKeyBuf));
    if (err != TFM_PLAT_ERR_SUCCESS) {
        goto exit;
    }
#endif /* SGI_HUK_CHECK_UNPROVISIONED_DUK */

    (void)memcpy(buf, derivedKeyBuf, sizeof(derivedKeyBuf));
    *key_len = sizeof(derivedKeyBuf);
    err = TFM_PLAT_ERR_SUCCESS;

exit:
    /* Wipe key material on ALL paths (success and error). Slot 6 is NOT
     * flushed on purpose: it holds the device DUK. */
    huk_secure_zeroize(derivedKeyBuf, sizeof(derivedKeyBuf));
    huk_secure_zeroize(derivedKeyDesc, sizeof(derivedKeyDesc));
    huk_secure_zeroize(cpuWaBuffer, sizeof(cpuWaBuffer));

    if (session_initialized) {
        MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(sd_status, sd_token, mcuxClSession_destroy(session));
        if ((MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_destroy) != sd_token) ||
            (MCUXCLSESSION_STATUS_OK != sd_status)) {
            err = TFM_PLAT_ERR_SYSTEM_ERR;
        }
        MCUX_CSSL_FP_FUNCTION_CALL_END();
    }

    if (err != TFM_PLAT_ERR_SUCCESS) {
        huk_secure_zeroize(buf, buf_len);
        ERROR("[HUK] derivation failed, err=0x%x\n", (unsigned int)err);
    }

    return err;
}
#endif /* USE_SGI_HUK */

/* ------------------------------------------------------------------------- */
/* HUK loader                                                                */
/* ------------------------------------------------------------------------- */
static enum tfm_plat_err_t tfm_plat_get_huk(const void *ctx,
                                            uint8_t *buf, size_t buf_len,
                                            size_t *key_len,
                                            psa_key_bits_t *key_bits,
                                            psa_algorithm_t *algorithm,
                                            psa_key_type_t *type)
{
    enum tfm_plat_err_t err;

    (void)ctx;

#if defined(PSA_CRYPTO_DRIVER_SGI) && USE_SGI_HUK
    err = tfm_plat_get_huk_via_sgi(buf, buf_len, key_len);
    if (err != TFM_PLAT_ERR_SUCCESS)
    {
        return err;
    }
#else
    err = tfm_plat_otp_read(PLAT_OTP_ID_HUK, buf_len, buf);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return err;
    }

    err = tfm_plat_otp_get_size(PLAT_OTP_ID_HUK, key_len);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return err;
    }
#endif

    *key_bits = *key_len * 8;
    *algorithm = PSA_ALG_HKDF(PSA_ALG_SHA_256);
    *type = PSA_KEY_TYPE_DERIVE;

    return TFM_PLAT_ERR_SUCCESS;
}

#ifdef TFM_PARTITION_INITIAL_ATTESTATION
static enum tfm_plat_err_t tfm_plat_get_iak(const void *ctx,
                                            uint8_t *buf, size_t buf_len,
                                            size_t *key_len,
                                            psa_key_bits_t *key_bits,
                                            psa_algorithm_t *algorithm,
                                            psa_key_type_t *type)
{
    enum tfm_plat_err_t err;
#ifndef SYMMETRIC_INITIAL_ATTESTATION
    psa_ecc_family_t curve_type;
#endif /* SYMMETRIC_INITIAL_ATTESTATION */

    (void)ctx;

    err = tfm_plat_otp_read(PLAT_OTP_ID_IAK_LEN,
                            sizeof(size_t), (uint8_t*)key_len);
    if(err != TFM_PLAT_ERR_SUCCESS) {
        return err;
    }
    *key_bits = *key_len * 8;

    if (buf_len < *key_len) {
        return TFM_PLAT_ERR_SYSTEM_ERR;
    }

#ifdef SYMMETRIC_INITIAL_ATTESTATION
    err = tfm_plat_otp_read(PLAT_OTP_ID_IAK_TYPE,
                            sizeof(psa_algorithm_t), (uint8_t*)algorithm);
    if(err != TFM_PLAT_ERR_SUCCESS) {
        return err;
    }

    *type = PSA_KEY_TYPE_HMAC;
#else /* SYMMETRIC_INITIAL_ATTESTATION */
    err = tfm_plat_otp_read(PLAT_OTP_ID_IAK_TYPE, sizeof(psa_ecc_family_t),
                            &curve_type);
    if(err != TFM_PLAT_ERR_SUCCESS) {
        return err;
    }

    *algorithm = PSA_ALG_ECDSA(PSA_ALG_SHA_256);
    *type = PSA_KEY_TYPE_ECC_KEY_PAIR(curve_type);
#endif /* SYMMETRIC_INITIAL_ATTESTATION */

    return tfm_plat_otp_read(PLAT_OTP_ID_IAK, *key_len, buf);
}
#endif /* TFM_PARTITION_INITIAL_ATTESTATION */

#ifdef TFM_PARTITION_INITIAL_ATTESTATION
/**
 * @brief Table describing per-user key policy for the IAK
 *
 */
static const tfm_plat_builtin_key_per_user_policy_t g_iak_per_user_policy[] = {
    {.user = TFM_SP_INITIAL_ATTESTATION,
#ifdef SYMMETRIC_INITIAL_ATTESTATION
        .usage = PSA_KEY_USAGE_SIGN_HASH | PSA_KEY_USAGE_EXPORT,
#else
        .usage = PSA_KEY_USAGE_SIGN_HASH,
#endif /* SYMMETRIC_INITIAL_ATTESTATION */
    },
#ifdef TEST_S_ATTESTATION
    {.user = TFM_SP_SECURE_TEST_PARTITION, .usage = PSA_KEY_USAGE_VERIFY_HASH},
#endif /* TEST_S_ATTESTATION */
#ifdef TEST_NS_ATTESTATION
    {.user = TFM_NS_PARTITION_ID, .usage = PSA_KEY_USAGE_VERIFY_HASH},
#endif /* TEST_NS_ATTESTATION */
};
#endif /* TFM_PARTITION_INITIAL_ATTESTATION */

/**
 * @brief Table describing per-key user policies
 *
 */
static const tfm_plat_builtin_key_policy_t g_builtin_keys_policy[] = {
    {.key_id = TFM_BUILTIN_KEY_ID_HUK, .per_user_policy = 0, .usage = PSA_KEY_USAGE_DERIVE},
#ifdef TFM_PARTITION_INITIAL_ATTESTATION
    {.key_id = TFM_BUILTIN_KEY_ID_IAK,
     .per_user_policy = NUMBER_OF_ELEMENTS_OF(g_iak_per_user_policy),
     .policy_ptr = g_iak_per_user_policy},
#endif /* TFM_PARTITION_INITIAL_ATTESTATION */
};

/**
 * @brief Table describing the builtin-in keys (platform keys) available in the platform. Note
 *        that to bind the keys to the tfm_builtin_key_loader driver, the lifetime must be
 *        explicitly set to the one associated to the driver, i.e. TFM_BUILTIN_KEY_LOADER_LIFETIME
 */
static const tfm_plat_builtin_key_descriptor_t g_builtin_keys_desc[] = {
    {.key_id = TFM_BUILTIN_KEY_ID_HUK,
     .slot_number = TFM_BUILTIN_KEY_SLOT_HUK,
     .lifetime = TFM_BUILTIN_KEY_LOADER_LIFETIME,
     .loader_key_func = tfm_plat_get_huk,
     .loader_key_ctx = NULL},
#ifdef TFM_PARTITION_INITIAL_ATTESTATION
    {.key_id = TFM_BUILTIN_KEY_ID_IAK,
     .slot_number = TFM_BUILTIN_KEY_SLOT_IAK,
     .lifetime = TFM_BUILTIN_KEY_LOADER_LIFETIME,
     .loader_key_func = tfm_plat_get_iak,
     .loader_key_ctx = NULL},
#endif /* TFM_PARTITION_INITIAL_ATTESTATION */
};

size_t tfm_plat_builtin_key_get_policy_table_ptr(const tfm_plat_builtin_key_policy_t *desc_ptr[])
{
    *desc_ptr = &g_builtin_keys_policy[0];
    return NUMBER_OF_ELEMENTS_OF(g_builtin_keys_policy);
}

size_t tfm_plat_builtin_key_get_desc_table_ptr(const tfm_plat_builtin_key_descriptor_t *desc_ptr[])
{
    *desc_ptr = &g_builtin_keys_desc[0];
    return NUMBER_OF_ELEMENTS_OF(g_builtin_keys_desc);
}
