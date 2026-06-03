/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "psa/crypto.h"
#include "tfm_plat_otp.h"
#include "rse_kmu_slot_ids.h"
#include "cc3xx_opaque_keys.h"
#include "rse_bl2_binding.h"

static inline uint16_t rse_bind_slot_for_img(int img_index)
{
    /* Image specific keys can be mapped, if required */
    (void)img_index;
    return RSE_KMU_SLOT_SECURE_BINDING_KEY;
}

psa_key_id_t rse_get_cmac_key_for_image(int img_index)
{
    psa_key_id_t kid = PSA_KEY_ID_NULL;
    psa_status_t status;
    uint16_t slot = rse_bind_slot_for_img(img_index);
    status = cc3xx_get_opaque_key(slot, &kid);

    if (status != PSA_SUCCESS) {
        return PSA_KEY_ID_NULL;
    }

    return kid;
}
