/*
 * Copyright (c) 2026, STMicroelectronics - All Rights Reserved
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

#ifndef __CMSIS_H__
#define __CMSIS_H__

/* CMSIS wrapper for stm32mp2xx.h  */

#include "stm32mp2xx.h"

#if defined(STM32MP215Cxx) || defined(STM32MP213Cxx) || defined(STM32MP211Cxx) ||\
    defined(STM32MP215Fxx) || defined(STM32MP213Fxx) || defined(STM32MP211Fxx) ||\
    defined(STM32MP235Cxx) || defined(STM32MP233Cxx) || defined(STM32MP231Cxx) ||\
    defined(STM32MP235Fxx) || defined(STM32MP233Fxx) || defined(STM32MP231Fxx) ||\
    defined(STM32MP257Cxx) || defined(STM32MP255Cxx) || defined(STM32MP253Cxx) || defined(STM32MP251Cxx) ||\
    defined(STM32MP257Fxx) || defined(STM32MP255Fxx) || defined(STM32MP253Fxx) || defined(STM32MP251Fxx)
#define STM32MP2_HAS_CRYPTO
#endif

/**
  \brief Exception / Interrupt Handler Function Prototype
*/
typedef void(*VECTOR_TABLE_Type)(void);

#endif /*__CMSIS_H__*/
