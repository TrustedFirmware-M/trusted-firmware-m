/* SPDX-License-Identifier: BSD-3-Clause */
/*
 * Copyright (c) 2026, STMicroelectronics - All Rights Reserved
 */
#ifndef STM32_DDR_H
#define STM32_DDR_H

struct stm32_ddr_platdata {
	uintptr_t base;
};

int stm32_ddr_init(void);

#endif /* STM32_DDR_H */
