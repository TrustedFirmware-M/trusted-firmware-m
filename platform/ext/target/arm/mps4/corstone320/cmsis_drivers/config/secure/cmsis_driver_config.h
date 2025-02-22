/*
 * Copyright (c) 2019-2024, Arm Limited. All rights reserved.
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

#ifndef __CMSIS_DRIVER_CONFIG_H__
#define __CMSIS_DRIVER_CONFIG_H__

#include "tfm_hal_device_header.h"
#include "platform_s_device_definition.h"
#include "RTE_Device.h"

#define UART0_CMSDK_DEV     UART0_CMSDK_DEV_NS

#define MPC_ISRAM0_DEV      MPC_ISRAM0_DEV_S
#define MPC_ISRAM1_DEV      MPC_ISRAM1_DEV_S
#define MPC_SRAM_DEV        MPC_SRAM_DEV_S
#define MPC_QSPI_DEV        MPC_QSPI_DEV_S
#define MPC_DDR4_DEV        MPC_DDR4_DEV_S

#define TGU_ARMV8_M_ITCM_DEV TGU_ARMV8_M_ITCM_DEV_S
#define TGU_ARMV8_M_DTCM_DEV TGU_ARMV8_M_DTCM_DEV_S

#define PPC_CORSTONE320_MAIN0_DEV            PPC_CORSTONE320_MAIN0_DEV_S
#define PPC_CORSTONE320_MAIN_EXP0_DEV        PPC_CORSTONE320_MAIN_EXP0_DEV_S
#define PPC_CORSTONE320_MAIN_EXP1_DEV        PPC_CORSTONE320_MAIN_EXP1_DEV_S
#define PPC_CORSTONE320_MAIN_EXP2_DEV        PPC_CORSTONE320_MAIN_EXP2_DEV_S
#define PPC_CORSTONE320_MAIN_EXP3_DEV        PPC_CORSTONE320_MAIN_EXP3_DEV_S
#define PPC_CORSTONE320_PERIPH0_DEV          PPC_CORSTONE320_PERIPH0_DEV_S
#define PPC_CORSTONE320_PERIPH1_DEV          PPC_CORSTONE320_PERIPH1_DEV_S
#define PPC_CORSTONE320_PERIPH_EXP0_DEV      PPC_CORSTONE320_PERIPH_EXP0_DEV_S
#define PPC_CORSTONE320_PERIPH_EXP1_DEV      PPC_CORSTONE320_PERIPH_EXP1_DEV_S
#define PPC_CORSTONE320_PERIPH_EXP2_DEV      PPC_CORSTONE320_PERIPH_EXP2_DEV_S
#define PPC_CORSTONE320_PERIPH_EXP3_DEV      PPC_CORSTONE320_PERIPH_EXP3_DEV_S

#endif  /* __CMSIS_DRIVER_CONFIG_H__ */
