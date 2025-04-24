/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __RSE_KMU_SLOT_IDS_H__
#define __RSE_KMU_SLOT_IDS_H__

#include "kmu_drv.h"

#ifdef __cplusplus
extern "C" {
#endif

enum rse_kmu_slot_id_t {
    RSE_KMU_SLOT_TRAM_KEY = KMU_USER_SLOT_MIN,
    RSE_KMU_SLOT_VHUK,
    RSE_KMU_SLOT_IAK_SEED,
#ifdef RSE_BOOT_KEYS_CCA
    RSE_KMU_SLOT_DAK_SEED,
#endif
#ifdef RSE_BOOT_KEYS_DPE
    RSE_KMU_SLOT_ROT_CDI,
#endif
    /* The session key is used for AEAD, so requires two contiguous slots. Only
     * the first should be used for calls, the key loader and derivation code
     * will transparently use the second where necessary.
     */
    RSE_KMU_SLOT_SESSION_KEY_0,
    _RSE_KMU_AEAD_RESERVED_SLOT_SESSION_KEY,
    RSE_KMU_SLOT_MASTER_KEY,
    /* The provisioning key is used for AEAD, so requires two contiguous
     * slots. Only the first should be used for calls, the key loader and
     * derivation code will transparently use the second where necessary.
     */
    RSE_KMU_SLOT_PROVISIONING_KEY,
    _RSE_KMU_AEAD_RESERVED_SLOT_PROVISIONING_KEY,
    RSE_KMU_SLOT_SECURE_ENCRYPTION_KEY,
    RSE_KMU_SLOT_NON_SECURE_ENCRYPTION_KEY,
    RSE_KMU_SLOT_CC3XX_PKA_SRAM_ENCRYPTION_KEY,
};

#ifdef __cplusplus
}
#endif

#endif /* __RSE_KMU_SLOT_IDS_H__ */
