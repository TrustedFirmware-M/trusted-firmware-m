/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <stdint.h>
#include <stdbool.h>
#include "fih.h"
#include "tfm_log.h"
#include "tfm_plat_crypto_keys.h"

static inline bool has_key(const int *verified_keys, size_t verified_cnt, int key_id)
{
    size_t i;
    for (i = 0; i < verified_cnt; i++) {
        if (verified_keys[i] == key_id) {
            return true;
        }
    }
    return false;
}

fih_ret boot_plat_check_key_policy(uint8_t image_index,
                                   const int *verified_keys,
                                   size_t verified_cnt)
{
    uint32_t key_slot, key_id;
#ifdef MCUBOOT_ROTPK_SIGN_POLICY
    uint32_t policies, bit;
#endif /* MCUBOOT_ROTPK_SIGN_POLICY */
    bool must = true; /* MUST unless policy says otherwise */

#ifdef MCUBOOT_ROTPK_SIGN_POLICY
    /* Policies are encoded bitwise: bit = image_index * MAX_KEYS_PER_IMAGE + key_slot */
    if (tfm_plat_get_bl2_rotpk_policies((uint8_t *)&policies, sizeof(policies)) != TFM_PLAT_ERR_SUCCESS) {
        INFO("Image=%u policy read FAILED", image_index);
        FIH_RET(FIH_FAILURE);
    }
#endif /* MCUBOOT_ROTPK_SIGN_POLICY */

    /* Go through the slots for this image */
    for (key_slot = 0; key_slot < MAX_KEYS_PER_IMAGE; key_slot++) {
        key_id = tfm_plat_get_key_id(image_index, key_slot);
        if (key_id == (uint32_t)PSA_KEY_ID_NULL) {
            INFO("slot: %u, \t No key\n", key_slot);
            /* unused slot */
            continue;
        }
        INFO("slot: %u, \t key_id=0x%08x, ", key_slot, key_id);

#ifdef MCUBOOT_ROTPK_SIGN_POLICY
        bit = (image_index * MAX_KEYS_PER_IMAGE) + key_slot;
        must = (policies & (1u << bit)) != 0u;
        INFO_RAW("\tpolicy: %s, ", must ? "MUST SIGN" : "MIGHT SIGN");
#endif /* MCUBOOT_ROTPK_SIGN_POLICY */

        if (must) {
            if (!has_key(verified_keys, verified_cnt, (int)key_id)) {
                INFO_RAW("\tStatus: Failed to verify\n");
                /* Required signer missing */
                FIH_RET(FIH_FAILURE);
            } else{
                INFO_RAW("\tStatus: Verified\n");
            }
        } else {
            INFO_RAW("\tStatus: Optional (Skipped)\n");
        }
    }

    FIH_RET(FIH_SUCCESS);
}
