/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <stdint.h>
#include "tfm_utils.h"
#include "ns_mailbox_client_id.h"
#include "platform_locality.h"
#include "tfm_peripherals_def.h"

static int32_t get_locality_from_irq_source(uint32_t irq_source)
{
    switch (irq_source) {
    case MAILBOX_IRQ:
        return LOCALITY_AP_S;
    case MAILBOX_IRQ_1:
        return LOCALITY_AP_NS;
    default:
        return LOCALITY_NONE;
    }
}

int32_t tfm_plat_get_mailbox_locality(int32_t client_id)
{
    size_t i;

    for (i = 0; i < ARRAY_SIZE(ns_mailbox_client_id_info); i++) {
        if ((client_id >= ns_mailbox_client_id_info[i].client_id_base) &&
            (client_id <= ns_mailbox_client_id_info[i].client_id_limit)) {

            return get_locality_from_irq_source(ns_mailbox_client_id_info[i].source);
        }
    }

    /* If client id is not within registered range, return default locality */
    return LOCALITY_NONE;
}
