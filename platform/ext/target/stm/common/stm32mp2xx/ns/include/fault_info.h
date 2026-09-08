/* SPDX-License-Identifier: BSD-3-Clause */
/*
 * Copyright (c) 2026, STMicroelectronics - All Rights Reserved
 * Author(s): Ludovic Barre, <ludovic.barre@foss.st.com> for STMicroelectronics.
 */

#ifndef _FAULT_INFO_H_
#define _FAULT_INFO_H_

/* Store context for an exception, then print the info.
 * Call FAULT_INFO() instead of calling this directly.
 */
void _fault_info(uint32_t MSP_in, uint32_t PSP_in, uint32_t LR_in, uint32_t *callee_saved);

/*
 * store {r4-r11} registers in current stack
 * call _fault_info with arguments
 * MSP, PSP, LR, SP (callee)
 */
#define FAULT_INFO()				\
	__ASM volatile(				\
		"MRS    R0, MSP\n"		\
		"MRS    R1, PSP\n"		\
		"PUSH   {R4-R11}\n"		\
		"MOV    R2, LR\n"		\
		"MOV    R3, SP\n"		\
		"BL     _fault_info\n"		\
		"ADD    SP, #32\n"		\
	)

int fault_init(void);

#endif /* _FAULT_INFO_H_ */
