/* SPDX-License-Identifier: (GPL-2.0-only OR BSD-3-Clause) */
/*
 * Copyright (c) 2026, STMicroelectronics - All Rights Reserved
 * Author(s): Ludovic Barre, <ludovic.barre@foss.st.com> for STMicroelectronics.
 */
#ifndef _DT_BINDINGS_STM32MP25_TAMP_GPIO_H
#define _DT_BINDINGS_STM32MP25_TAMP_GPIO_H

#define _TAMP_IN1RMP_PC4		_TAMP_MUX(0, 0)
#define _TAMP_IN1RMP_PI8		_TAMP_MUX(1, 0)
#define _TAMP_IN2RMP_PF7		_TAMP_NOMUX
#define _TAMP_IN3RMP_PC3		_TAMP_MUX(0, 1)
#define _TAMP_IN3RMP_PZ2		_TAMP_MUX(1, 1)
#define _TAMP_IN4RMP_PG1		_TAMP_NOMUX
#define _TAMP_IN5RMP_PF6		_TAMP_MUX(0, 2)
#define _TAMP_IN5RMP_PZ4		_TAMP_MUX(1, 2)
#define _TAMP_IN6RMP_PC5		_TAMP_NOMUX
#define _TAMP_IN7RMP_PG3		_TAMP_NOMUX
#define _TAMP_IN8RMP_PZ6		_TAMP_NOMUX

#define _TAMP_OUT1RMP_PC13		_TAMP_NOMUX
#define _TAMP_OUT2RMP_PI8		_TAMP_MUX(0, 0)
#define _TAMP_OUT3RMP_PZ0		_TAMP_NOMUX
#define _TAMP_OUT4RMP_PZ3		_TAMP_NOMUX
#define _TAMP_OUT5RMP_PZ1		_TAMP_NOMUX
#define _TAMP_OUT6RMP_PZ4		_TAMP_MUX(0, 2)
#define _TAMP_OUT7RMP_PZ2		_TAMP_MUX(0, 1)
#define _TAMP_OUT8RMP_PZ5		_TAMP_NOMUX

#define _TAMP_INRMP_MASK		GENMASK_32(2, 0)
#define _TAMP_INRMP_SHIFT		0

#define STM32_TAMP_GPIO_IN(id, rmp) ((_TAMP_IN##id##RMP_##rmp) << _TAMP_INRMP_SHIFT)
#define STM32_TAMP_GPIO_OUT(id, rmp) ((_TAMP_OUT##id##RMP_##rmp) << _TAMP_INRMP_SHIFT)

#endif /* _DT_BINDINGS_STM32MP25_TAMP_GPIO_H */
