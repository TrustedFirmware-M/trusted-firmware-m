/* SPDX-License-Identifier: BSD-3-Clause */
/*
 * Copyright (c) 2026, STMicroelectronics - All Rights Reserved
 * Author(s): Ludovic Barre, <ludovic.barre@st.com> for STMicroelectronics.
 */
#ifndef STM32_BSEC3_H
#define STM32_BSEC3_H

#include <stddef.h>
#include <stdbool.h>
#include <lib/utils_def.h>
#include <tfm_plat_otp.h>

/* Debug permission mask */
#define STM32MP2_PERM_MASK_A35NSTO	BIT(0) /* A35 Non-Secure Trace-only */
#define STM32MP2_PERM_MASK_A35NSFD	BIT(1) /* A35 Non-Secure Full-Debug */
#define STM32MP2_PERM_MASK_A35STO	BIT(2) /* A35 Secure Trace-only */
#define STM32MP2_PERM_MASK_A35SFD	BIT(3) /* A35 Secure Full-Debug */
#define STM32MP2_PERM_MASK_M33NSTO	BIT(4) /* M33 Non-Secure Trace-only */
#define STM32MP2_PERM_MASK_M33NSFD	BIT(5) /* M33 Non-Secure Full-Debug */
#define STM32MP2_PERM_MASK_M33STO	BIT(6) /* M33 Secure Trace-only */
#define STM32MP2_PERM_MASK_M33SFD	BIT(7) /* M33 Secure Full-Debug */
#define STM32MP21_PERM_MASK_A35HDPL	BIT(8) /* A35 Minimal Debug level */
#define STM32MP21_PERM_MASK_A35HDP(lvl) (STM32MP21_PERM_MASK_A35HDPL << (lvl))
#define STM32MP21_PERM_MASK_M33HDPL	BIT(12) /* M33 Minimal Debug level */
#define STM32MP21_PERM_MASK_M33HDP(lvl) (STM32MP21_PERM_MASK_M33HDPL << (lvl))
#define STM32MP2_PERM_MASK_A35SDDIS	BIT(16) /* A35 Secure Debug Disabled */
#define STM32MP2_PERM_MASK_A35NSDDIS	BIT(17) /* A35 Non-Sec Debug Disabled */
#define STM32MP2_PERM_MASK_M33SDDIS	BIT(18) /* M33 Secure Debug Disabled */
#define STM32MP2_PERM_MASK_M33NSDDIS	BIT(19) /* M33 Non-Sec Debug Disabled */
#define STM32MP2_PERM_MASK_WAITATTACH	BIT(31) /* Wait for attach at boot time */

#define DBG_PERM_MASK_NS_ONLY_MP2	(STM32MP2_PERM_MASK_A35NSTO | STM32MP2_PERM_MASK_A35NSFD | \
					 STM32MP2_PERM_MASK_M33NSTO | STM32MP2_PERM_MASK_M33NSFD | \
					 STM32MP2_PERM_MASK_A35SDDIS | STM32MP2_PERM_MASK_M33SDDIS)

#define DBG_PERM_MASK_FULL_MP2		(STM32MP2_PERM_MASK_A35NSTO | STM32MP2_PERM_MASK_A35NSFD | \
					 STM32MP2_PERM_MASK_A35STO | STM32MP2_PERM_MASK_A35SFD |   \
					 STM32MP2_PERM_MASK_M33NSTO | STM32MP2_PERM_MASK_M33NSFD | \
					 STM32MP2_PERM_MASK_M33STO | STM32MP2_PERM_MASK_M33SFD)

#define DBG_PERM_MASK_NONE		(STM32MP2_PERM_MASK_A35SDDIS |  \
					 STM32MP2_PERM_MASK_A35NSDDIS | \
					 STM32MP2_PERM_MASK_M33SDDIS |  \
					 STM32MP2_PERM_MASK_M33NSDDIS)
#ifdef STM32MP21xxxx
#define DBG_PERM_MASK_NS_ONLY		(DBG_PERM_MASK_NS_ONLY_MP2 |	 \
					 STM32MP21_PERM_MASK_A35HDP(0) | \
					 STM32MP21_PERM_MASK_M33HDP(0))
#define DBG_PERM_MASK_FULL		(DBG_PERM_MASK_FULL_MP2 |	 \
					 STM32MP21_PERM_MASK_A35HDP(0) | \
					 STM32MP21_PERM_MASK_M33HDP(0))
#else
#define DBG_PERM_MASK_NS_ONLY		DBG_PERM_MASK_NS_ONLY_MP2
#define DBG_PERM_MASK_FULL		DBG_PERM_MASK_FULL_MP2
#endif

/* Magic use to indicated valid SHADOW = 'B' 'S' 'E' 'C' */
#define BSEC_MAGIC			0x42534543

/* state bitfield */
#define BSEC_STATE_SEC_CLOSED		U(0x0)
#define BSEC_STATE_SEC_OPEN		U(0x1)
#define BSEC_STATE_INVALID		U(0x2)
#define BSEC_STATE_MASK			GENMASK_32(1, 0)
#define BSEC_HARDWARE_KEY		BIT(8)

/* status bitfield */
#define LOCK_PERM			BIT(30)
#define LOCK_SHADOW_R			BIT(29)
#define LOCK_SHADOW_W			BIT(28)
#define LOCK_SHADOW_P			BIT(27)
#define LOCK_ERROR			BIT(26)
#define STATUS_PROVISIONING		BIT(1)
#define STATUS_SECURE			BIT(0)

int stm32_bsec_write_debug_conf(uint32_t perm_mask);
void stm32_bsec_restore_cortexa_debug_conf(void);
int stm32_bsec_increment_hdpl(void);
bool stm32_bsec_is_huk_ready(void);

/*
 * STM32 driver Interface
 */
int stm32_bsec_read_sw_lock(uint32_t otp, bool *value);

int stm32_bsec_write(uint32_t otp_num, uint32_t otp_val);

int stm32_bsec_get_otp_cell_by_label(char* label, uint32_t *cell_start,
				     uint32_t *cell_size);

#endif /* STM32_BSEC3_H */
