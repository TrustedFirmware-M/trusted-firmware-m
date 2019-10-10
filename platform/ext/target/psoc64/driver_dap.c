/*
 * Copyright (c) 2019, Cypress Semiconductor Corporation. All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include <stdio.h>

#include "driver_dap.h"

#include "cycfg.h"
#include "cy_device.h"
#include "cy_device_headers.h"
#include "cy_ipc_drv.h"
#include "cy_prot.h"
#include "cy_sysint.h"
#include "driver_dap.h"
#include "pc_config.h"


int cy_access_port_control(cy_ap_name_t ap, cy_ap_control_t en)
{
    int rc = -1;
    volatile uint32_t syscallCmd = 0;
    uint32_t timeout = 0;

    syscallCmd |= DAPCONTROL_SYSCALL_OPCODE;
    syscallCmd |= (uint8_t)en << 16;
    syscallCmd |= (uint8_t)ap << 8;
    syscallCmd |= 1;

    IPC->STRUCT[CY_IPC_CHAN_SYSCALL].DATA = syscallCmd;

    while(((IPC->STRUCT[CY_IPC_CHAN_SYSCALL].ACQUIRE &
            IPC_STRUCT_ACQUIRE_SUCCESS_Msk) == 0) &&
            (timeout < SYSCALL_TIMEOUT))
    {
        ++timeout;
    }

    if(timeout < SYSCALL_TIMEOUT)
    {
        timeout = 0;

        IPC->STRUCT[CY_IPC_CHAN_SYSCALL].NOTIFY = 1;

        while(((IPC->STRUCT[CY_IPC_CHAN_SYSCALL].LOCK_STATUS &
                IPC_STRUCT_ACQUIRE_SUCCESS_Msk) != 0) &&
                (timeout < SYSCALL_TIMEOUT))
        {
            ++timeout;
        }

        if(timeout < SYSCALL_TIMEOUT)
        {
            syscallCmd = IPC->STRUCT[CY_IPC_CHAN_SYSCALL].DATA;
            if(CY_FB_SYSCALL_SUCCESS != syscallCmd)
            {
                rc = syscallCmd;
            }
            else
            {
                rc = 0;
            }
        }
    }
    return rc;
}