/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 * Copyright (c) 2023-2024 Cypress Semiconductor Corporation (an Infineon
 * company) or an affiliate of Cypress Semiconductor Corporation. All rights
 * reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <stdint.h>

#include "runtime_defs.h"
#include "sprt_partition_metadata_indicator.h"
#include "tfm_log_unpriv.h"

#include "psa/error.h"
#include "psa/service.h"

void common_sfn_thread(void *param)
{
    psa_signal_t sig_asserted, signal_mask, sig;
    psa_msg_t msg;
    struct runtime_metadata_t *meta;
    service_fn_t *p_sfn_table;
    sfn_init_fn_t sfn_init;
    psa_status_t status;

    meta = PART_METADATA();
    sfn_init = (sfn_init_fn_t)meta->entry;
    p_sfn_table = (service_fn_t *)meta->sfn_table;
    signal_mask = (1UL << meta->n_sfn) - 1;

    if (sfn_init && (sfn_init(param) != PSA_SUCCESS)) {
        ERROR_UNPRIV_RAW("Partition initialization FAILED in 0x%x\n", sfn_init);
        psa_panic();
    }

    while (1) {
        sig_asserted = psa_wait(signal_mask, PSA_BLOCK);
        /* Handle signals */
        for (int i = 0; (sig_asserted != 0) && (i < meta->n_sfn); i++) {
            sig = 1UL << i;
            if (sig_asserted & sig) {
                /* The i bit signal asserted, index of SFN is i as well */
                if (!p_sfn_table[i]) {
                    /* No corresponding SFN */
                    psa_panic();
                }

                status = psa_get(sig, &msg);
                if (status != PSA_SUCCESS) {
                    psa_panic();
                }
                psa_reply(msg.handle, ((service_fn_t)p_sfn_table[i])(&msg));
                sig_asserted &= ~sig;
            }
        }

        if (sig_asserted != 0) {
            /* Wrong signal asserted */
            psa_panic();
        }
    }
}
