/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "bl1_random.h"
#include "tfm_log.h"
#include "cc3xx_entropy.h"
#include "cc3xx_rng.h"
/* For direct reading of the noise source */
#include "cc3xx_noise_source.h"
#include "tfm_plat_defs.h"
#include "device_definition.h"
#include "rse_otp_dev.h"

#define ARRAY_LEN(x) (sizeof(x)/sizeof(x[0]))

/* If the von Neumann balancer is bypassed, the minimum value for sample
 * counter must not be less than decimal seventeen.
 */
#define MINIMUM_ALLOWED_ROSC_SAMPLE_COUNT (17)

int32_t bl1_random_generate_fast(uint8_t *output, size_t output_size)
{
    return cc3xx_lowlevel_rng_get_random(output, output_size, CC3XX_RNG_LFSR);
}

int32_t bl1_random_generate_noise(uint8_t *output, size_t output_size)
{
    uint32_t buf[CC3XX_TRNG_SAMPLE_SIZE / sizeof(uint32_t)];
    cc3xx_err_t err;

    struct cc3xx_noise_source_ctx_t ctx = CC3XX_NOISE_SOURCE_CONTEXT_INIT;
    cc3xx_lowlevel_noise_source_context_init(&ctx);

    err = cc3xx_lowlevel_noise_source_init(&ctx);
    if (err != CC3XX_ERR_SUCCESS) {
        return (int32_t)err;
    }

    for (size_t counter = 0; counter < output_size; counter++) {
        if ((counter % CC3XX_TRNG_SAMPLE_SIZE) == 0) {
            err = cc3xx_lowlevel_noise_source_get_sample(
                    &ctx, buf, sizeof(buf) / sizeof(uint32_t));
            if (err != CC3XX_ERR_SUCCESS) {
                return 1;
            }
        }
        output[counter] = ((uint8_t *)buf)[counter % CC3XX_TRNG_SAMPLE_SIZE];
    }

    cc3xx_lowlevel_noise_source_finish();

    return 0;
}

void bl1_random_set_noise_source_config(void)
{
    cc3xx_err_t cc_err = CC3XX_ERR_RNG_INVALID_TRNG_CONFIG;
    enum lcm_error_t lcm_err;
    struct rse_otp_cc_trng_config_t cc_trng_config = {
      .trng_rosc_sc = {CC3XX_CONFIG_RNG_SUBSAMPLING_RATE},
      .trng_in_use = CC3XX_CONFIG_RNG_RING_OSCILLATOR_ID
    };

    /* Return if OTP CM area don't exist */
    if (!IS_RSE_OTP_AREA_VALID(CM)) {
        return;
    }

    lcm_err = lcm_otp_read(&LCM_DEV_S, OTP_OFFSET(P_RSE_OTP_CM->cc_trng_config),
                           sizeof(cc_trng_config), (uint8_t *)&cc_trng_config);

    if ((lcm_err == LCM_ERROR_NONE) &&
        (cc_trng_config.trng_in_use < ARRAY_LEN(cc_trng_config.trng_rosc_sc))) {

        const enum cc3xx_noise_source_rosc_id_t rosc_id =
            (enum cc3xx_noise_source_rosc_id_t)cc_trng_config.trng_in_use;
        const uint32_t rosc_sc =
            (cc_trng_config.trng_rosc_sc[cc_trng_config.trng_in_use] <
             MINIMUM_ALLOWED_ROSC_SAMPLE_COUNT)
                ? MINIMUM_ALLOWED_ROSC_SAMPLE_COUNT
                : cc_trng_config.trng_rosc_sc[cc_trng_config.trng_in_use];

        struct cc3xx_noise_source_ctx_t *ctx =
            (struct cc3xx_noise_source_ctx_t *)
                cc3xx_lowlevel_entropy_get_noise_source_ctx();

        cc_err = cc3xx_lowlevel_noise_source_set_config(ctx, rosc_id, rosc_sc);
        if (cc_err == CC3XX_ERR_SUCCESS) {
            INFO("Noise Source config set to (%d, 0x%x)\r\n", rosc_id, rosc_sc);
        }
    }

    if ((lcm_err != LCM_ERROR_NONE) || (cc_err != CC3XX_ERR_SUCCESS)) {
        WARN("Can't set CC TRNG config from OTP, lcm_err: 0x%08x, cc_err: 0x%08x\r\n",
             lcm_err, cc_err);
    }
}
