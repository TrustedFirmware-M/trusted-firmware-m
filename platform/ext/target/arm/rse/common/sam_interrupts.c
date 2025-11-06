/*
 * Copyright (c) 2023, Arm Limited. All rights reserved.
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

#include "device_definition.h"
#include "rse_sam_config.h"

void NMI_Handler(void)
{
    sam_handle_nmi_event();
}

void SAM_Critical_Sev_Fault_S_Handler(void)
{
    sam_handle_critical_serverity_event();
}

void SAM_Sev_Fault_S_Handler(void)
{
    sam_handle_all_events(&SAM_DEV_S);
}

void SRAM_TRAM_ECC_Err_S_Handler(void)
{
    sam_handle_all_events(&SAM_DEV_S);
}

void SRAM_ECC_Partial_Write_S_Handler(void)
{
    sam_handle_all_events(&SAM_DEV_S);
}
