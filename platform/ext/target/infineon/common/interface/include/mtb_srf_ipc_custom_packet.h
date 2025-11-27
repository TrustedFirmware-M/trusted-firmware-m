/*
 * Copyright (c) 2025 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef IFX_SRF_IPC_H
#define IFX_SRF_IPC_H

#include "mtb_srf.h"
#include "tfm_mailbox.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief MTB SRF IPC request structure suitable for TFM needs. This structure
 * overrides default mtb_srf_ipc_packet_t SRF structure.
 *
 * This structure is designed to be allocated in shared memory for inter-process
 * communication (IPC). All members are stored as values (not pointers) to
 * ensure the entire request is self-contained and can be safely copied into
 * and out of shared memory. Parameters required for the PSA client call are
 * copied directly into this structure, and the structure itself is allocated
 * in the shared memory region. This design ensures that all data needed for the
 * request is accessible to both communicating parties without relying on
 * process-specific pointers/memory.
 */
typedef struct _MTB_SRF_DATA_ALIGN {
    /* Following fields are TFM specific */
    uint32_t call_type;                /* PSA client call type */
    struct psa_client_params_t params; /* Contain parameters used in
                                        * PSA client call */
    struct mailbox_reply_t reply;      /* Reply value. */

    /* Following fields are used in TFM and also are required by SRF framework */
    uint16_t semaphore_idx;            /* Semaphore index used for synchronization */
} mtb_srf_ipc_packet_t;

#ifdef __cplusplus
}
#endif

#endif /* IFX_SRF_IPC_H */
