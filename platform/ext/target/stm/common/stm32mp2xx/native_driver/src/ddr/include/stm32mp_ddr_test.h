/* SPDX-License-Identifier: BSD-3-Clause */
/*
 * Copyright (c) 2026, STMicroelectronics - All Rights Reserved
 */

#ifndef STM32MP_DDR_TEST_H
#define STM32MP_DDR_TEST_H

#include <stdint.h>

uintptr_t stm32mp_ddr_test_data_bus(uintptr_t base);
uintptr_t stm32mp_ddr_test_addr_bus(uintptr_t base, size_t size);
size_t stm32mp_ddr_check_size(uintptr_t base, size_t size);

#endif /* STM32MP_DDR_TEST_H */
