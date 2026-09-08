/* SPDX-License-Identifier: BSD-3-Clause */
/*
 * Copyright (c) 2026, STMicroelectronics - All Rights Reserved
 */
#ifndef __STM32_RIFSC_H
#define __STM32_RIFSC_H

#include <stdint.h>

int stm32_rifsc_get_access_by_id(const struct device *dev, uint32_t id);

#endif /* __STM32_RIFSC_H */
