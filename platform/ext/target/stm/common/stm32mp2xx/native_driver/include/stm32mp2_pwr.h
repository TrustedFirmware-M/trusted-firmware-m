/* SPDX-License-Identifier: BSD-3-Clause */
/*
 * Copyright (c) 2026, STMicroelectronics - All Rights Reserved
 * Author(s): Ludovic Barre, <ludovic.barre@st.com> for STMicroelectronics.
 */
#ifndef STM32MP2_PWR_H
#define STM32MP2_PWR_H

#include <stddef.h>
#include <stdbool.h>
#include <device.h>
#include <devicetree.h>

inline const struct device *stm32_pwr_dev(void)
{
	return DEVICE_GET(DEVICE_DT_DEV_ID(DT_NODELABEL(pwr)));
}

bool stm32_pwr_ddr_retention_get(const struct device *dev);
void stm32_pwr_ddr_retention_set(const struct device *dev, bool enable);

__weak void stm32_pwr_regulator_restore(void)
{
}

#endif /* STM32MP2_PWR_H */
