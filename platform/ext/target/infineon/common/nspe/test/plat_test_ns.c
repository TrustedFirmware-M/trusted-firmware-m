/*
 * Copyright (c) 2023-2024 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <stdbool.h>
#include <stdint.h>
#include "cy_tcpwm_counter.h"
#include "device_definition.h"
#include "tfm_plat_defs.h"
#include "tfm_plat_test.h"
#include "tfm_peripherals_def.h"

#ifdef TFM_PARTITION_CRYPTO
#include "tfm_builtin_key_ids.h"
#endif

#if defined(IFX_IRQ_TEST_TIMER_NS)
/* Currently tfm_plat_test_non_secure_* functions are not used, but they are kept for possible use
 * in future */
void tfm_plat_test_non_secure_timer_stop(void)
{
    Cy_TCPWM_Counter_Disable(
        IFX_IRQ_TEST_TIMER_DEV_NS.tcpwm_base,
        IFX_IRQ_TEST_TIMER_DEV_NS.tcpwm_counter_num
    );
    Cy_TCPWM_ClearInterrupt(IFX_IRQ_TEST_TIMER_DEV_NS.tcpwm_base,
                            IFX_IRQ_TEST_TIMER_DEV_NS.tcpwm_counter_num,
                            IFX_IRQ_TEST_TIMER_DEV_NS.tcpwm_config->interruptSources);
}
#endif /* defined(IFX_IRQ_TEST_TIMER_NS) */

#if defined(TFM_PARTITION_CRYPTO) && defined(PSA_API_TEST_ENABLED)
int32_t tfm_initial_attest_get_public_key(uint8_t *public_key_buff,
                                          size_t public_key_buf_size,
                                          size_t  *public_key_len,
                                          psa_ecc_family_t *elliptic_family_type)
{
    psa_key_attributes_t attr;
#ifdef TFM_BUILTIN_KEY_ID_IAK_PUB
    /* Use public IAK directly if it is available */
    psa_key_id_t key_id = TFM_BUILTIN_KEY_ID_IAK_PUB;
#else /* TFM_BUILTIN_KEY_ID_IAK_PUB */
    /* Derive public IAK from private one */
    psa_key_id_t key_id = TFM_BUILTIN_KEY_ID_IAK;
#endif /* TFM_BUILTIN_KEY_ID_IAK_PUB */
    psa_key_type_t key_type;

    if (psa_get_key_attributes(key_id, &attr) != PSA_SUCCESS) {
        return PSA_ERROR_NOT_SUPPORTED;
    }

    key_type = psa_get_key_type(&attr);
    *elliptic_family_type = PSA_KEY_TYPE_ECC_GET_FAMILY(key_type);

    /* psa_export_public_key will either export the public key directly
     * (in case of KEY_ID_IAK_PUB) or derive public key from private one
     * (in case of KEY_ID_IAK) */
    return psa_export_public_key(key_id, public_key_buff, public_key_buf_size, public_key_len);
}
#endif
