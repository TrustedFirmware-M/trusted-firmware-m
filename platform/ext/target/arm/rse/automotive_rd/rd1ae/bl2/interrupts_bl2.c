/*
 * Copyright (c) 2024, Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "interrupts_bl2.h"

#include "device_definition.h"
#include "host_system.h"
#include "mhu_v3_x.h"
#include "tfm_hal_device_header.h"

#include <stdint.h>

/* Enum for id of each doorbell channel of the scp to rse MHU */
enum mhu_scp_rse_doorbell_channel {
    MHU_SCP_RSE_SYSTOP_ON_CHANNEL_ID = 0,
    MHU_SCP_RSE_CHANNEL_COUNT,
};

#define MHU_SCP_SYSTOP_FLAG 0x1

static int mhu_scp_rse_systop_on_doorbell_handler(uint32_t value)
{
    /* Only flag 0 is used to indicate SYSTOP ON */
    if ((value & MHU_SCP_SYSTOP_FLAG) != MHU_SCP_SYSTOP_FLAG) {
        return 1;
    }

    host_system_scp_signal_ap_ready();

    return 0;
}

/* Function prototype to use for mhu channel vector pointers */
typedef int (*mhu_vector_t) (uint32_t);

/* Array of function pointers to call if a message is received on a channel */
static mhu_vector_t mhu_scp_rse_doorbell_vector[MHU_SCP_RSE_CHANNEL_COUNT] = {
    [MHU_SCP_RSE_SYSTOP_ON_CHANNEL_ID] = mhu_scp_rse_systop_on_doorbell_handler,
};

/* Function to handle the SCP to RSE MHUv3 combined MBX interrupt */
void CMU_MHU4_Receiver_Handler(void)
{
    uint32_t ch, value, mask = 0;
    enum mhu_v3_x_error_t status;

    for (ch = 0; ch < MHU_SCP_RSE_CHANNEL_COUNT; ch++) {
        /* Read the doorbell channel value */
        status = mhu_v3_x_doorbell_read(&MHU_SCP_TO_RSE_DEV, ch, &value);
        if (status != MHU_V_3_X_ERR_NONE) {
            break;
        }

        /* If this channel has a message (non zero value) */
        if (value != 0) {

            /* If no handler for channel then enter error state. */
            if (mhu_scp_rse_doorbell_vector[ch] == NULL) {
                while (1) {};
            }
            /* Call the vector function for this channel */
            status = mhu_scp_rse_doorbell_vector[ch](value);
            if (status != 0){
                while (1) {};
            }

            /* Update mask value to clear the doorbell */
            mask = value;
            break;
        }
    }

    /* Clear the pending interrupt */
    mhu_v3_x_doorbell_clear(&MHU_SCP_TO_RSE_DEV, ch, mask);
}

int32_t interrupts_bl2_init(void) {
    /* Register interrupt handler for SCP to RSE MHUv3 */
    NVIC_SetVector(CMU_MHU4_Receiver_IRQn, (uintptr_t)CMU_MHU4_Receiver_Handler);
    if (NVIC_GetVector(CMU_MHU4_Receiver_IRQn) != CMU_MHU4_Receiver_Handler) {
        return 1;
    }
    return 0;
}
