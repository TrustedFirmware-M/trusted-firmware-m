/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <stdbool.h>
#include <string.h>
#include "bl1_1_debug.h"
#include "device_definition.h"
#include "lcm_drv.h"
#include "rse_persistent_data.h"
#include "tfm_plat_defs.h"
#include "platform_dcu.h"
#include "fih.h"

enum tfm_plat_err_t b1_1_platform_debug_init(void)
{
#ifdef PLATFORM_PSA_ADAC_SECURE_DEBUG
    volatile uint32_t res;
    volatile uint32_t check_variable;

    enum lcm_lcs_t lcs;
    enum lcm_bool_t sp_enabled;

    uint32_t dcu_vector[LCM_DCU_WIDTH_IN_BYTES / sizeof(uint32_t)];
    uint32_t rse_dcu_vector_pos;
    uint32_t debug_perm_mask[LCM_DCU_WIDTH_IN_BYTES / sizeof(uint32_t)];
    uint32_t rse_debug_force_open_mask;
    uint32_t rse_debug_force_close_mask;
    uint32_t rse_certified_debug_vector_pos;

    struct rse_bl1_persistent_data *rse_sram_persistent_data;

    res = FIH_NEGATIVE_VALUE;
    check_variable = FIH_NEGATIVE_VALUE;

    rse_sram_persistent_data = &RSE_PERSISTENT_DATA->bl1_data;

    /* If these checks fail then we should assume debug should not be opened. */
    if (lcm_get_lcs(&LCM_DEV_S, &lcs) != TFM_PLAT_ERR_SUCCESS) {
        return;
    }
    if (lcm_get_sp_enabled(&LCM_DEV_S, &sp_enabled) != TFM_PLAT_ERR_SUCCESS) {
        return;
    }
    /*
     * In CM and RMA state debug is always open so no need to open further
     * If SP Mode is Enabled then debug is always closed and shouldn't be opened
     *
     * This is to prevent debug being closed in these states so is not part of
     * the secure path so does not need glitch protection.
     */
    if ((lcs == LCM_LCS_CM)
            || (lcs == LCM_LCS_RMA)
            || (sp_enabled == LCM_TRUE)) {
        return;
    }

    /* Read current DCU Vector */
    lcm_dcu_get_enabled(&LCM_DEV_S, (uint8_t *)&dcu_vector);

    /*
     * Get a version of the dcu vector with all bits positive.
     * This makes logic easer and will be flipped back before writing.
     */
    rse_dcu_vector_pos = dcu_vector[0] ^ DCU_NEG_MASK_REG0;

    /* ----------------------- Apply Certified Debug ----------------------- */

    /*
    * further open debug based on certified debug vector if syndrome debug
    * flag set
    */
    if (FIH_COND_CHECK_SAFE_SKIP(
            RSE_GET_PERSISTENT_DATA_FLAG(RSE_PERSISTENT_DATA_FLAGS_LAST_BOOT_DEBUG_CODE) ==
            LAST_BOOT_DEBUG_CODE_APPLY_CERT_DEBUG)) {
        /*
        * Get the certified debug vector for RSE with all bits positive by
        * inverting the negative bits.
        * This makes logic easer to follow and will be flipped back before
        * writing.
        */
        rse_certified_debug_vector_pos =
                rse_sram_persistent_data->certified_debug_vector[0] ^ DCU_NEG_MASK_REG0;
        /*
         * OR dcu vector with certified debug vector:
         * certified debug can open dcu if it was closed by default but can't
         * close it if it was open by default.
         *                            dcu vector
         *                        | closed | open |
         *                        +--------+------+
         * certified debug  close | close  | open |
         *                  open  | open   | open |
         */
        rse_dcu_vector_pos |= rse_certified_debug_vector_pos;
        dcu_vector[1] |= rse_sram_persistent_data->certified_debug_vector[1];
        dcu_vector[2] |= rse_sram_persistent_data->certified_debug_vector[2];
        dcu_vector[3] |= rse_sram_persistent_data->certified_debug_vector[3];

        /* Clear certified debug vector to ensure it is not set next boot */
        RSE_SET_PERSISTENT_DATA_FLAG(RSE_PERSISTENT_DATA_FLAGS_LAST_BOOT_DEBUG_CODE,
                                     LAST_BOOT_DEBUG_CODE_BLOCK_CERT_DEBUG);
        rse_sram_persistent_data->certified_debug_vector[0] = 0;
        rse_sram_persistent_data->certified_debug_vector[1] = 0;
        rse_sram_persistent_data->certified_debug_vector[2] = 0;
        rse_sram_persistent_data->certified_debug_vector[3] = 0;
    }

    /* ----------------------- Apply Permanent Mask ------------------------ */

    lcm_dcu_get_disable_mask(&LCM_DEV_S, (uint8_t *) &debug_perm_mask);

    /*
     * For RSE dcu vector due to the positive and negative bit pairs is is possible for
     * the permanent mask to cause an invalid vector.
     *
     * For any bit pair if there is a 0 in the mask then there is only one valid
     * value for the dcu pair.
     *
     *                              permanent mask
     *                         | pass | close | open
     *                       & | 11   | 10    | 01
     *              -----------+------+-------+------
     *   dcu pair   open    01 | 01   | 00    | 01
     *              closed  10 | 10   | 10    | 00
     */

    /*
     * Force open mask is a vector where a 1 represents bits that should be
     * forced open. This will be applied to the positive only rse dcu vector.
     */

    /*
     * A 1 for every negative bit in the mask that had a 0 value
     * If the negative bit is zero the positive bit must be 1 so debug open.
     */
    rse_debug_force_open_mask = ~debug_perm_mask[0] & DCU_NEG_MASK_REG0;
    /* Copy the negative bits to positive bits by shift right */
    rse_debug_force_open_mask |= (rse_debug_force_open_mask >> 1) & DCU_NEG_MASK_REG0;

    /*
     * Apply force open mask with OR to force open
     *      force open
     *               | no| yes|
     *               | 0 | 1  |
     *       --------+---+----+
     * dcu   close 0 | 0 | 1  |
     *       open  1 | 1 | 1  |
     */
    rse_dcu_vector_pos |= rse_debug_force_open_mask;

    /*
     * Force close mask is a vector where a 1 represents bits that should be
     * forced closed. This will be applied to the positive only rse dcu vector.
     */

    /*
     * A 1 for every positive bit in the mask that had a 0 value
     * If the positive bit is zero the negative bit must be 1 so debug closed.
     */
    rse_debug_force_close_mask = ~debug_perm_mask[0] & ~DCU_NEG_MASK_REG0;
    /* Copy the positive bits to negative bits by shift left */
    rse_debug_force_close_mask |= (rse_debug_force_close_mask << 1) & DCU_NEG_MASK_REG0;

    /*
     * Apply force close mask inverted with AND to force closed
     *      force close
     *               | no| yes|
     *               | 0 | 1  |
     *       --------+---+----+
     * dcu   close 0 | 0 | 0  |
     *       open  1 | 1 | 0  |
     */
    rse_dcu_vector_pos &= ~rse_debug_force_close_mask;

    /*
     * AND dcu vector with permanent mask:
     * opening a region that is disable by permanent mask will not do anything
     * so don't open anything closed by permanent mask.
     *
     *                             dcu vector
     *                         | closed | open  |
     *                         +--------+-------+
     * perm mask        closed | close  | close |
     *                  open   | close  | open  |
     */
    dcu_vector[1] &= debug_perm_mask[1];
    dcu_vector[2] &= debug_perm_mask[2];
    dcu_vector[3] &= debug_perm_mask[3];

    /* If RSE debug open invalidate hardware keys */
    /*
     * Perform check twice with short delay if debug is going to be opened
     * This is required to prevent glitching on this check so the invalidate
     * cannot be skipped.
     * Ideally the delay should be random but KMU is not initialized at this
     * point.
     */
    check_variable = rse_dcu_vector_pos;
    rse_sram_persistent_data->is_hw_key_invalidated = false;
    if (FIH_COND_CHECK_SAFE_ENTER(check_variable > 0)) {
        res = kmu_invalidate_hardware_keys(&KMU_DEV_S);

        if (FIH_COND_CHECK_SAFE_ENTER(res != 0)) {
            /*
             * If hardware keys could not be invalidated do not open rse
             * debug. Clear all vector flags that would open RSE debug.
             * Other debug can still be opened so proceed with boot.
             */
            rse_dcu_vector_pos = 0;
        } else {
            rse_sram_persistent_data->is_hw_key_invalidated = true;
        }
    }

    /* Flip negative bits back so they are once again negated */
    dcu_vector[0] = rse_dcu_vector_pos ^ DCU_NEG_MASK_REG0;

    /* Set DCU registers */
    lcm_dcu_set_enabled(&LCM_DEV_S, (uint8_t *)&dcu_vector);

#endif /* PLATFORM_PSA_ADAC_SECURE_DEBUG */
    return TFM_PLAT_ERR_SUCCESS;
}
