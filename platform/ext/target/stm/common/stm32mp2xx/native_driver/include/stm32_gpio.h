/* SPDX-License-Identifier: BSD-3-Clause */
/*
 * Copyright (c) 2026, STMicroelectronics - All Rights Reserved
 */
#ifndef STM32_GPIO_H
#define STM32_GPIO_H

#include <lib/utils_def.h>
#include <stdint.h>

#define STM32_GPIO_ALTERNATE_(_x)	U(_x)

#define STM32_GPIO_MODE_INPUT		0x00
#define STM32_GPIO_MODE_OUTPUT		0x01
#define STM32_GPIO_MODE_ALTERNATE	0x02
#define STM32_GPIO_MODE_ANALOG		0x03
#define STM32_GPIO_MODE_MASK		U(0x03)

#define STM32_GPIO_PUSH_PULL		0x00
#define STM32_GPIO_OPEN_DRAIN		0x01

#define STM32_GPIO_SPEED_LOW		0x00
#define STM32_GPIO_SPEED_MEDIUM		0x01
#define STM32_GPIO_SPEED_HIGH		0x02
#define STM32_GPIO_SPEED_VERY_HIGH	0x03
#define STM32_GPIO_SPEED_MASK		U(0x03)

#define STM32_GPIO_NO_PULL		0x00
#define STM32_GPIO_PULL_UP		0x01
#define STM32_GPIO_PULL_DOWN		0x02
#define STM32_GPIO_PULL_MASK		U(0x03)

struct stm32_gpio_cfg {
	uint32_t bank;
	uint32_t pin;
	uint32_t mode;
	uint32_t type;
	uint32_t speed;
	uint32_t pull;
	uint32_t alternate;
};

#endif /* STM32_GPIO_H */
