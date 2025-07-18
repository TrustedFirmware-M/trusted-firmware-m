/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
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

#ifndef __RSE_MEMORY_SIZES_H__
#define __RSE_MEMORY_SIZES_H__

#define VM0_SIZE           0x80000 /* 512 KiB */
#define VM1_SIZE           0x80000 /* 512 KiB */

/* The uppermost RETAINED_RAM_SIZE bytes of VM1 are retained after cold reset */
#define RETAINED_RAM_SIZE                0x00020000 /* 128 KiB */

#define BOOT_FLASH_SIZE    0x800000 /* 8MB */

#define OTP_DMA_ICS_SIZE   0x400 /* 1 KiB*/

#define ROM_DMA_ICS_SIZE   0x1000 /* 4 KiB */

/*
 * The size of the SRAM which is allocated to NS. This may be increased
 * depending on the layout.
 */
#define NS_DATA_SIZE (0x5000)

#endif /* __RSE_MEMORY_SIZES_H__ */
