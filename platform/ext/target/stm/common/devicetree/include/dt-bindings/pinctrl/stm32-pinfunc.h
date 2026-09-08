/* SPDX-License-Identifier: (GPL-2.0-only OR BSD-3-Clause) */
/*
 * Copyright (c) 2026, STMicroelectronics - All Rights Reserved
 */

#ifndef _DT_BINDINGS_STM32_PINFUNC_H
#define _DT_BINDINGS_STM32_PINFUNC_H

/*  define PIN modes */
#define GPIO	0x0
#define AF0	0x1
#define AF1	0x2
#define AF2	0x3
#define AF3	0x4
#define AF4	0x5
#define AF5	0x6
#define AF6	0x7
#define AF7	0x8
#define AF8	0x9
#define AF9	0xa
#define AF10	0xb
#define AF11	0xc
#define AF12	0xd
#define AF13	0xe
#define AF14	0xf
#define AF15	0x10
#define ANALOG	0x11
#define RSVD	0x12

/* define pinmux*/
#define _PINMUX_FUNC_MASK	(0xFF) //GENMASK(7, 0)
#define _PINMUX_FUNC_SHIFT	0
#define _PINMUX_PIN_MASK	(0xF00) //GENMASK(11, 8)
#define _PINMUX_PIN_SHIFT	8
#define _PINMUX_BANK_MASK	(0x1F000) //GENMASK(16, 12)
#define _PINMUX_BANK_SHIFT	12
#define _PINMUX_PINNO_MASK	(_PINMUX_PIN_MASK | _PINMUX_BANK_MASK)
#define _PINMUX_PINNO_SHIFT	_PINMUX_PIN_SHIFT

#define _PINMUX_BANK(bank)	((((bank) - 'A') << _PINMUX_BANK_SHIFT) & _PINMUX_BANK_MASK)
#define _PINMUX_PIN(pin)	((pin << _PINMUX_PIN_SHIFT) & _PINMUX_PIN_MASK)
#define _PINMUX_FUNC(func)	((func << _PINMUX_FUNC_SHIFT) & _PINMUX_FUNC_MASK)

#define _PIN_NO(bank, pin)	(_PINMUX_BANK(bank) | _PINMUX_PIN(pin))

#define STM32_PINMUX(bank, pin, func) (_PIN_NO(bank, pin) | _PINMUX_FUNC(func))

/*  package information */
#define STM32MP_PKG_AA	0x1
#define STM32MP_PKG_AB	0x2
#define STM32MP_PKG_AC	0x4
#define STM32MP_PKG_AD	0x8

#endif /* _DT_BINDINGS_STM32_PINFUNC_H */

