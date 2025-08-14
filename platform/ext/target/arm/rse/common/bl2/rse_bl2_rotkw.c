#include "tfm_plat_otp.h"
#include "platform_otp_ids.h"
#include <bootutil/sign_key.h>
#include <bootutil/bootutil_log.h>
#include "rse_kmu_slot_ids.h"
#include "cc3xx_opaque_keys.h"


uint32_t get_enc_key_id_for_image(uint32_t image_id)
{
    uint32_t res;

    if (image_id == 0) {
        res = cc3xx_get_opaque_key(RSE_KMU_SLOT_SECURE_ENCRYPTION_KEY);
    } else {
        res = cc3xx_get_opaque_key(RSE_KMU_SLOT_NON_SECURE_ENCRYPTION_KEY);
    }

    return res;
}