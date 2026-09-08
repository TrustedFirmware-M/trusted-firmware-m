/* SPDX-License-Identifier: BSD-3-Clause */
/*
 * Copyright (c) 2026, STMicroelectronics - All Rights Reserved
 * Author(s): Ludovic Barre, <ludovic.barre@foss.st.com> for STMicroelectronics.
 */
#include <stdint.h>
#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <cmsis.h>

#define EXPT_HARDFAULT	3
#define EXPT_MMFAULT	4
#define EXPT_BFAULT	5
#define EXPT_UFAULT	6

typedef struct {
	uint32_t r0;
	uint32_t r1;
	uint32_t r2;
	uint32_t r3;
	uint32_t r12;
	uint32_t lr;
	uint32_t pc;
	uint32_t psr;
} stack_frame_t;

typedef struct {
	uint32_t r4;
	uint32_t r5;
	uint32_t r6;
	uint32_t r7;
	uint32_t r8;
	uint32_t r9;
	uint32_t r10;
	uint32_t r11;
} stack_callee_t;

typedef struct {
	uint32_t icsr;
	uint32_t shcrs;
	uint32_t cfsr;
	uint32_t hfsr;
	uint32_t mmfar;
	uint32_t bfar;
} scb_t;

typedef struct {
	uint32_t msp;
	uint32_t psp;
	uint32_t exc_return;
	uint32_t control;
	uintptr_t frame_ptr;
	stack_frame_t stack_frame;
	stack_callee_t stack_callee;
	scb_t scb;
} fault_info_t;

static fault_info_t fault;

static inline void scb_dump(scb_t *scb)
{
	scb->icsr = SCB->ICSR;
	scb->shcrs = SCB->SHCSR;
	scb->cfsr = SCB->CFSR;
	scb->hfsr = SCB->HFSR;
	scb->mmfar = SCB->MMFAR;
	scb->bfar = SCB->BFAR;
}

static void _register_print(uintptr_t frame_ptr, stack_frame_t *frame, stack_callee_t *callee)
{
	printf("[NS] [FAULT] Exception frame: 0x%08" PRIxPTR "\r\n", frame_ptr);
	printf("[NS] [FAULT]   r0:   0x%lx\r\n", frame->r0);
	printf("[NS] [FAULT]   r1:   0x%lx\r\n", frame->r1);
	printf("[NS] [FAULT]   r2:   0x%lx\r\n", frame->r2);
	printf("[NS] [FAULT]   r3:   0x%lx\r\n", frame->r3);
	printf("[NS] [FAULT]   r4:   0x%lx\r\n", callee->r4);
	printf("[NS] [FAULT]   r5:   0x%lx\r\n", callee->r5);
	printf("[NS] [FAULT]   r6:   0x%lx\r\n", callee->r6);
	printf("[NS] [FAULT]   r7:   0x%lx\r\n", callee->r7);
	printf("[NS] [FAULT]   r8:   0x%lx\r\n", callee->r8);
	printf("[NS] [FAULT]   r9:   0x%lx\r\n", callee->r9);
	printf("[NS] [FAULT]   r10:  0x%lx\r\n", callee->r10);
	printf("[NS] [FAULT]   r11:  0x%lx\r\n", callee->r11);
	printf("[NS] [FAULT]   r12:  0x%lx\r\n", frame->r12);
	printf("[NS] [FAULT]   lr:   0x%lx\r\n", frame->lr);
	printf("[NS] [FAULT]   pc:   0x%lx\r\n", frame->pc);
	printf("[NS] [FAULT]   xpsr: 0x%lx\r\n", frame->psr);
}

static void _scb_print(scb_t *scb)
{
	uint32_t vectactive = scb->icsr & SCB_ICSR_VECTACTIVE_Msk;
	uint32_t mmfsr = (scb->cfsr & SCB_CFSR_MEMFAULTSR_Msk) >> SCB_CFSR_MEMFAULTSR_Pos;
	uint32_t bfsr = (scb->cfsr & SCB_CFSR_BUSFAULTSR_Msk) >> SCB_CFSR_BUSFAULTSR_Pos;
	uint32_t ufsr = (scb->cfsr & SCB_CFSR_USGFAULTSR_Msk) >> SCB_CFSR_USGFAULTSR_Pos;

	switch (vectactive) {
	case EXPT_HARDFAULT:
		printf("[NS] [FAULT] Hard fault\r\n");
		break;
	case EXPT_MMFAULT:
		printf("[NS] [FAULT] Mem manage fault\r\n");
		break;
	case EXPT_BFAULT:
		printf("[NS] [FAULT] Bus fault\r\n");
		break;
	case EXPT_UFAULT:
		printf("[NS] [FAULT] Usage fault\r\n");
		break;
	default:
		printf("[NS] [FAULT] Exception number: %ld\r\n", vectactive);
	}

	printf("[NS] [FAULT] Fault status hfsr: 0x%lx\r\n", scb->hfsr);
	if (scb->hfsr & SCB_HFSR_FORCED_Msk)
		printf("[NS] [FAULT]   -> Forced HardFault\r\n");

	printf("[NS] [FAULT] Fault status cfsr: 0x%lx\r\n", scb->cfsr);

	if (mmfsr) {
		printf("[NS] [FAULT]   Mem fault:\r\n");
		if (scb->cfsr & SCB_CFSR_IACCVIOL_Msk)
			printf("[NS] [FAULT]     -> Instruction access violation\r\n");
		if (scb->cfsr & SCB_CFSR_DACCVIOL_Msk)
			printf("[NS] [FAULT]     -> Data access violation\r\n");
		if (scb->cfsr & SCB_CFSR_MUNSTKERR_Msk)
			printf("[NS] [FAULT]     -> on unstacking for a return from exception\r\n");
		if (scb->cfsr & SCB_CFSR_MSTKERR_Msk)
			printf("[NS] [FAULT]     -> on stacking for exception entry\r\n");
		if (scb->cfsr & SCB_CFSR_MLSPERR_Msk)
			printf("[NS] [FAULT]     -> occurred during floating-point\r\n");
		if (scb->cfsr & SCB_CFSR_MMARVALID_Msk)
			printf("[NS] [FAULT]     -> address: 0x%lx\r\n", scb->mmfar);
	}

	if (bfsr) {
		printf("[NS] [FAULT]   Bus fault:\r\n");
		if (scb->cfsr & SCB_CFSR_IBUSERR_Msk)
			printf("[NS] [FAULT]     -> Instruction bus error\r\n");
		if (scb->cfsr & SCB_CFSR_PRECISERR_Msk)
			printf("[NS] [FAULT]     -> Precise data bus error\r\n");
		if (scb->cfsr & SCB_CFSR_UNSTKERR_Msk)
			printf("[NS] [FAULT]     -> on unstacking for a return from exception\r\n");
		if (scb->cfsr & SCB_CFSR_STKERR_Msk)
			printf("[NS] [FAULT]     -> on stacking for exception entry\r\n");
		if (scb->cfsr & SCB_CFSR_LSPERR_Msk)
			printf("[NS] [FAULT]     -> occurred during floating-point\r\n");
		if (scb->cfsr & SCB_CFSR_BFARVALID_Msk)
			printf("[NS] [FAULT]     -> address: 0x%lx\r\n", scb->bfar);
	}

	if (ufsr) {
		printf("[NS] [FAULT]   Usage fault:\r\n");
		if (scb->cfsr & SCB_CFSR_UNDEFINSTR_Msk)
			printf("[NS] [FAULT]     -> Undefined instruction\r\n");
		if (scb->cfsr & SCB_CFSR_INVSTATE_Msk)
			printf("[NS] [FAULT]     -> Invalid state flag\r\n");
		if (scb->cfsr & SCB_CFSR_INVPC_Msk)
			printf("[NS] [FAULT]     -> Invalid PC flag\r\n");
		if (scb->cfsr & SCB_CFSR_NOCP_Msk)
			printf("[NS] [FAULT]     -> No coprocessor flag\r\n");
		if (scb->cfsr & SCB_CFSR_STKOF_Msk)
			printf("[NS] [FAULT]     -> Stack overflow\r\n");
		if (scb->cfsr & SCB_CFSR_UNALIGNED_Msk)
			printf("[NS] [FAULT]     -> Unaligned access flag\r\n");
		if (scb->cfsr & SCB_CFSR_DIVBYZERO_Msk)
			printf("[NS] [FAULT]     -> Divide by zero\r\n");
	}
}

static void fault_print(fault_info_t *f)
{
	_scb_print(&f->scb);

	printf("[NS] [FAULT] Exception context:\r\n");
	printf("[NS] [FAULT]   exc_return (lr): 0x%lx\r\n", f->exc_return);
	printf("[NS] [FAULT]   MSP: 0x%lx\r\n", f->msp);
	printf("[NS] [FAULT]   PSP: 0x%lx\r\n", f->psp);

	/* EXC return 0=Handler mode 1=Thread mode */
	if (f->exc_return & EXC_RETURN_MODE)
		printf("[NS] [FAULT]   thread mode\r\n");
	else
		printf("[NS] [FAULT]   handler mode\r\n");

	_register_print(f->frame_ptr, &f->stack_frame, &f->stack_callee);
}

void _fault_info(uint32_t MSP_in, uint32_t PSP_in, uint32_t LR_in, uint32_t *callee_saved)
{
	fault.msp = MSP_in;
	fault.psp = PSP_in;
	fault.exc_return = LR_in;
	fault.control = __get_CONTROL();

	/* if thread mode get frame from psp */
	if (LR_in & EXC_RETURN_SPSEL)
		fault.frame_ptr = (uintptr_t)PSP_in;
	else
		fault.frame_ptr = (uintptr_t)MSP_in;

	memcpy(&(fault.stack_frame), (uint32_t *)(fault.frame_ptr), sizeof(fault.stack_frame));

	if (callee_saved)
		memcpy(&(fault.stack_callee), callee_saved, sizeof(fault.stack_callee));

	scb_dump(&fault.scb);

	fault_print(&fault);
}

int fault_init(void)
{
	SCB->SHCSR |= SCB_SHCSR_USGFAULTENA_Msk
		| SCB_SHCSR_BUSFAULTENA_Msk
		| SCB_SHCSR_MEMFAULTENA_Msk;

	SCB->CCR |= SCB_CCR_DIV_0_TRP_Msk;

	return 0;
}
