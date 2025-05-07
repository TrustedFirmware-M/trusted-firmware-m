/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __TFM_PLAT_SHARED_MEASUREMENT_DATA_H__
#define __TFM_PLAT_SHARED_MEASUREMENT_DATA_H__

#include <stddef.h>
#include <stdint.h>

uintptr_t tfm_plat_get_shared_measurement_data_base(void);

size_t tfm_plat_get_shared_measurement_data_size(void);

#endif /* __TFM_PLAT_SHARED_MEASUREMENT_DATA_H__ */
