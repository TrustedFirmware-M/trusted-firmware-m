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

#ifndef __DRIVER_DAP_H__
#define __DRIVER_DAP_H__

/* DAPControl SysCall opcode */
#define DAPCONTROL_SYSCALL_OPCODE       (0x3AUL << 24UL)

/* PSA crypto SysCall return codes */
#define CY_FB_SYSCALL_SUCCESS           (0xA0000000UL)

/* SysCall timeout value */
#define SYSCALL_TIMEOUT                 (15000UL)

/* DAPControl SysCall parameter: access port state */
typedef enum
{
    CY_AP_DIS = 0,
    CY_AP_EN = 1
}cy_ap_control_t;

/* DAPControl SysCall parameter: access port name */
typedef enum
{
    CY_CM0_AP = 0,
    CY_CM4_AP = 1,
    CY_SYS_AP = 2
}cy_ap_name_t;

/* API functions */
int cy_access_port_control(cy_ap_name_t ap, cy_ap_control_t en);

#endif /* __DRIVER_DAP_H__ */
