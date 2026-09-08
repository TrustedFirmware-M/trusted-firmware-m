/* SPDX-License-Identifier: BSD-3-Clause */
/*
 * Copyright (c) 2026, STMicroelectronics - All Rights Reserved
 */

#ifndef DDRPHY_WRAPPER_H
#define DDRPHY_WRAPPER_H

static inline long long fmodll(long long x, long long y)
{
	return x - ((x / y) * y);
}

static inline int fmodi(int x, int y)
{
	return (int)fmodll((long long)x, (long long)y);
}

#endif /* DDRPHY_WRAPPER_H */
