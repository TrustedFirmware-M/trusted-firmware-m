#include "tfm_plat_otp.h"
#include "platform_otp_ids.h"
#include "psa/crypto.h"
#include <bootutil/sign_key.h>
#include <bootutil/bootutil_log.h>
#include "rse_kmu_slot_ids.h"
#include "cc3xx_opaque_keys.h"


uint32_t get_enc_key_id_for_image(uint32_t image_id)
{
    psa_key_id_t res = PSA_KEY_ID_NULL;
    psa_status_t status;

    if (image_id == 0) {
        status = cc3xx_get_opaque_key(RSE_KMU_SLOT_SECURE_ENCRYPTION_KEY, &res);
    } else {
        status = cc3xx_get_opaque_key(RSE_KMU_SLOT_NON_SECURE_ENCRYPTION_KEY, &res);
    }

    if (status != PSA_SUCCESS) {
        return PSA_KEY_ID_NULL;
    }

    return res;
}
