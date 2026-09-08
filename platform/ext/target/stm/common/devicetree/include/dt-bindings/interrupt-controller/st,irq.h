/* SPDX-License-Identifier: GPL-2.0-only OR BSD-3-Clause */
/*
 * Copyright (c) 2026, STMicroelectronics - All Rights Reserved
 * Author(s): Ludovic Barre <ludovic.barre@foss.st.com>
 */

#ifndef _DT_BINDINGS_INTERRUPT_CONTROLLER_ST_IRQ_H_
#define _DT_BINDINGS_INTERRUPT_CONTROLLER_ST_IRQ_H_

#define IRQ_TYPE_NONE		0
#define IRQ_TYPE_EDGE_RISING	1
#define IRQ_TYPE_EDGE_FALLING	2
#define IRQ_TYPE_EDGE_BOTH	(IRQ_TYPE_EDGE_FALLING | IRQ_TYPE_EDGE_RISING)
#define IRQ_TYPE_LEVEL_HIGH	4
#define IRQ_TYPE_LEVEL_LOW	8

#endif /* _DT_BINDINGS_INTERRUPT_CONTROLLER_ST_IRQ_H_ */
