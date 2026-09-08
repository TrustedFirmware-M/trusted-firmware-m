/* SPDX-License-Identifier: BSD-3-Clause */
/*
 * Copyright (c) 2026, STMicroelectronics - All Rights Reserved
 */

/**
 * stm32_tamp_bkpreg_write - Write a 32 bits value to a backup register
 * identified by its ID.
 *
 * @param dev TAMP device.
 * @param reg_id Backup register ID.
 * @param value 32 bits value to write in the backup register.
 */
int stm32_tamp_bkpreg_write(const struct device *dev, unsigned int reg_id,
			    uint32_t value);

/**
 * stm32_tamp_bkpreg_read - Read a 32 bits value from a backup register
 * identified by its ID.
 *
 * @param dev TAMP device.
 * @param reg_id Backup register ID.
 * @param value 32 bits value to be read from the backup register.
 */
int stm32_tamp_bkpreg_read(const struct device *dev, unsigned int reg_id,
			   uint32_t *value);

/**
 * stm32_tamp_bkpreg_zone1_rif1 - Modify the protection area on the backup
 * registers Zone1-Rif1; grant access for R2CID or restore access to R1CID
 *
 * @param dev TAMP device.
 * @param cpu2_grant_access true when zone1 is accessible by CPU2
 */
void stm32_tamp_bkpreg_zone1_rif1(const struct device *dev, bool cpu2_grant_access);
