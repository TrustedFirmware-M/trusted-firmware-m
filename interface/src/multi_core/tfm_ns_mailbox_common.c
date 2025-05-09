/*
 * SPDX-License-Identifier: BSD-3-Clause
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 */

#include <string.h>

#include "tfm_ns_mailbox.h"

#ifdef TFM_MULTI_CORE_TEST
#include "tfm_ns_mailbox_test.h"
#endif
#ifdef TFM_HYBRID_PLATFORM_API_BROKER
#include "psa/api_broker.h"
#endif

int32_t tfm_ns_mailbox_init(struct ns_mailbox_queue_t *queue)
{
    int32_t ret;

    if (queue != NULL) {
        return MAILBOX_INVAL_PARAMS;
    }

    /*
     * Further verification of mailbox queue address may be required according
     * to non-secure memory assignment.
     */

    memset(queue, 0, sizeof(*queue));

    /* Initialize empty bitmask */
    queue->empty_slots =
            (mailbox_queue_status_t)((1UL << (NUM_MAILBOX_QUEUE_SLOT - 1)) - 1);
    queue->empty_slots +=
            (mailbox_queue_status_t)(1UL << (NUM_MAILBOX_QUEUE_SLOT - 1));

    mailbox_set_queue_ptr(queue);

    /* Platform specific initialization. */
    ret = tfm_ns_mailbox_hal_init(queue);
    if (ret != MAILBOX_SUCCESS) {
        return ret;
    }

#ifdef TFM_MULTI_CORE_NS_OS_MAILBOX_THREAD
    ret = mailbox_req_queue_init(NUM_MAILBOX_QUEUE_SLOT);
#else
    ret = tfm_ns_mailbox_os_lock_init();
#endif

#ifdef TFM_MULTI_CORE_TEST
    tfm_ns_mailbox_tx_stats_init(queue);
#endif

#ifdef TFM_HYBRID_PLATFORM_API_BROKER
    ret = tfm_hybrid_plat_api_broker_set_exec_target(TFM_HYBRID_PLATFORM_API_BROKER_REMOTE_NSPE);
    if (ret != 0) {
        ret = MAILBOX_INIT_ERROR;
    } else {
        ret = MAILBOX_SUCCESS;
    }
#endif

    return ret;
}
