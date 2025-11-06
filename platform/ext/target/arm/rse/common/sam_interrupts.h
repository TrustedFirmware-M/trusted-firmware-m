/*
 * SPDX-License-Identifier: BSD-3-Clause
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 */

#ifndef __SAM_INTERRUPTS_H__
#define __SAM_INTERRUPTS_H__

#ifdef __cplusplus
extern "C" {
#endif

void NMI_Handler(void);
void SAM_Critical_Sev_Fault_S_Handler(void);
void SAM_Sev_Fault_S_Handler(void);
void SRAM_TRAM_ECC_Err_S_Handler(void);
void SRAM_ECC_Partial_Write_S_Handler(void);

#ifdef __cplusplus
}
#endif

#endif /* __SAM_INTERRUPTS_H__ */
