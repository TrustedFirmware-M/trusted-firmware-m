/*
 * Copyright (c) 2018-2020 Arm Limited
 * Copyright 2019-2023, 2025 NXP
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef __TARGET_CFG_H__
#define __TARGET_CFG_H__

#include "target_cfg_common.h"

#ifdef __cplusplus
extern "C" {
#endif

#define TFM_DRIVER_STDIO    Driver_LPUART
#define NS_DRIVER_STDIO     Driver_LPUART

/**
 * \brief Holds the data necessary to do isolation for a specific peripheral.
 */
struct platform_data_t
{
    uint32_t periph_start;
    uint32_t periph_limit;

	uint32_t trdc_base;
    uint32_t nseEnable;
    uint32_t mbcIdx;         /*!< The index of the MBC for this configuration to take effect. */
	uint32_t glbacIdx;
    uint32_t slaveMemoryIdx; /*!< The index of the slave memory for this configuration to take effect. */
    uint32_t memoryBlockIdx; /*!< The index of the memory block for this configuration to take effect. */
};

void ppc_configure_to_secure(struct platform_data_t *platform_data, bool privileged);

#ifdef __cplusplus
}
#endif

#endif /* __TARGET_CFG_H__ */
