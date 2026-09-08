/*
 * Copyright 2025 NXP
 * Copyright (c) 2026, STMicroelectronics - All Rights Reserved
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 * inspired by TF-A
 */
#ifndef MMIOPOLL_H
#define MMIOPOLL_H

#include <errno.h>
#include <stdbool.h>
#include <stdint.h>
#include <lib/mmio.h>
#include <lib/timeout.h>

/**
 * mmio_readx_poll_timeout - Poll an address until a condition is met or a
 * timeout occurs.
 * @op: accessor function (takes @addr as its only argument)
 * @addr: address to poll
 * @val: variable where the read value is stored
 * @cond: The condition used to stop polling, which can be a macro using @val.
 * @timeout_us: timeout in microseconds, 0 means never timeout
 *
 * The expiration state is sampled before each read, so a last read and
 * condition check are always performed after the timeout has elapsed. This
 * avoids reporting a false timeout when the caller is preempted between a
 * read and the expiration check. @cond is evaluated once per read.
 *
 * Return: 0 if @cond is met, -ETIMEDOUT otherwise. In either case, the last
 * read value is stored in @val.
 */
#define mmio_readx_poll_timeout(op, addr, val, cond, timeout_us)	\
({									\
	int _rv = -ETIMEDOUT;						\
	uint64_t _tout_us = (timeout_us);				\
	uint64_t _tout = timeout_init_us(_tout_us);			\
	bool _expired;							\
	do {								\
		_expired = (_tout_us != 0U) && timeout_elapsed(_tout);	\
		(val) = (op)(addr);					\
		if (cond) {						\
			_rv = 0;					\
			break;						\
		}							\
	} while (!_expired);						\
	_rv;								\
})

#define mmio_read8_poll_timeout(addr, val, cond, timeout_us) \
	mmio_readx_poll_timeout(mmio_read_8, addr, val, cond, timeout_us)

#define mmio_read16_poll_timeout(addr, val, cond, timeout_us) \
	mmio_readx_poll_timeout(mmio_read_16, addr, val, cond, timeout_us)

#define mmio_read32_poll_timeout(addr, val, cond, timeout_us) \
	mmio_readx_poll_timeout(mmio_read_32, addr, val, cond, timeout_us)

#define mmio_read64_poll_timeout(addr, val, cond, timeout_us) \
	mmio_readx_poll_timeout(mmio_read_64, addr, val, cond, timeout_us)

#endif /* MMIOPOLL_H */
