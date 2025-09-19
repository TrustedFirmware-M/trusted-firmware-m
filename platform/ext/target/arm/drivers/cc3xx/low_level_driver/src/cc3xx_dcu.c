/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef CC3XX_CONFIG_FILE
#include "cc3xx_config.h"
#else
#include CC3XX_CONFIG_FILE
#endif

#include <assert.h>
#include <string.h>

#include "cc3xx_dcu.h"
#include "cc3xx_dev.h"
#include "cc3xx_log.h"

#ifdef CC3XX_CONFIG_DCU_ICV_RESTRICTION_MASK_CHECK
/**
 * @brief Check that the requested permissions are in accordance with the
 *        hardware restriction mask
 *
 * @param[in] val Sets of permissions, i.e. host_dcu_en to check as an array of 4 words
 * @return cc3xx_err_t CC3XX_ERR_SUCCESS or CC3XX_ERR_DCU_MASK_MISMATCH
 */
static cc3xx_err_t check_dcu_icv_restriction_mask(const uint32_t *val)
{
    size_t idx;

    CC3XX_INFO("icv_dcu_restriction_mask: 0x%08x_%08x_%08x_%08x\r\n",
               P_CC3XX->ao.ao_icv_dcu_restriction_mask[0],
               P_CC3XX->ao.ao_icv_dcu_restriction_mask[1],
               P_CC3XX->ao.ao_icv_dcu_restriction_mask[2],
               P_CC3XX->ao.ao_icv_dcu_restriction_mask[3]);

    for (idx = 0; idx < sizeof(P_CC3XX->ao.ao_icv_dcu_restriction_mask) / sizeof(uint32_t); idx++) {
        if (val[idx] & ~P_CC3XX->ao.ao_icv_dcu_restriction_mask[idx]) {
            return CC3XX_ERR_DCU_MASK_MISMATCH;
        }
    }

    return CC3XX_ERR_SUCCESS;
}
#endif /* CC3XX_CONFIG_DCU_ICV_RESTRICTION_MASK_CHECK */

/**
 * @brief Check that the requested permissions are in accordance with the
 *        permanent disable mask. A 1 in the mask means disabled
 *
 * @param[in] val Sets of permissions, i.e. host_dcu_en to check as an array of 4 words
 * @return cc3xx_err_t CC3XX_ERR_SUCCESS or CC3XX_ERR_DCU_MASK_MISMATCH
 */
static cc3xx_err_t check_dcu_permanent_disable_mask(const uint32_t *val)
{
    size_t idx;

    CC3XX_INFO("permanent_disable_mask: 0x%08x_%08x_%08x_%08x\r\n",
               P_CC3XX->ao.ao_permanent_disable_mask[0],
               P_CC3XX->ao.ao_permanent_disable_mask[1],
               P_CC3XX->ao.ao_permanent_disable_mask[2],
               P_CC3XX->ao.ao_permanent_disable_mask[3]);

    for (idx = 0; idx < sizeof(P_CC3XX->ao.ao_permanent_disable_mask) / sizeof(uint32_t); idx++) {
        if (val[idx] & P_CC3XX->ao.ao_permanent_disable_mask[idx]) {
            return CC3XX_ERR_DCU_MASK_MISMATCH;
        }
    }

    return CC3XX_ERR_SUCCESS;
}

/**
 * @brief Check that the requested permissions are in accordance with the
 *        current status of the DCU locks
 *
 * @param[in] val Sets of permissions, i.e. host_dcu_en to check as an array of 4 words
 * @return cc3xx_err_t CC3XX_ERR_SUCCESS or CC3XX_ERR_DCU_LOCKED
 */
static cc3xx_err_t check_dcu_locks(const uint32_t *val)
{
    size_t idx;
    uint32_t dcu_has_to_change;

    CC3XX_INFO("Current host_dcu_en: 0x%08x_%08x_%08x_%08x\r\n",
               P_CC3XX->ao.host_dcu_en[0],
               P_CC3XX->ao.host_dcu_en[1],
               P_CC3XX->ao.host_dcu_en[2],
               P_CC3XX->ao.host_dcu_en[3]);

    CC3XX_INFO("host_dcu_lock: 0x%08x_%08x_%08x_%08x\r\n",
               P_CC3XX->ao.host_dcu_lock[0],
               P_CC3XX->ao.host_dcu_lock[1],
               P_CC3XX->ao.host_dcu_lock[2],
               P_CC3XX->ao.host_dcu_lock[3]);

    for (idx = 0; idx < sizeof(P_CC3XX->ao.host_dcu_en) / sizeof(uint32_t); idx++) {
        /* Check if the host_dcu_en has to change */
        dcu_has_to_change = P_CC3XX->ao.host_dcu_en[idx] ^ val[idx];
        /* If a DCU has to change value but it's locked, then return an error */
        if (dcu_has_to_change & P_CC3XX->ao.host_dcu_lock[idx]) {
            return CC3XX_ERR_DCU_LOCKED;
        }
    }

    return CC3XX_ERR_SUCCESS;
}

/** \defgroup cc3xx_dcu APIs to interface with the DCU registers in the AO block
 *
 *  This set of APIs is used by higher level software that requires to interface
 *  with DCU related components available in the AO block
 *
 *  @{
 */
cc3xx_err_t cc3xx_dcu_get_enabled(uint8_t *val, size_t len)
{
    uint32_t idx;
    uint32_t host_dcu_en[4];

    assert(len == sizeof(P_CC3XX->ao.host_dcu_en));
    assert(val != NULL);

    for (idx = 0; idx < sizeof(P_CC3XX->ao.host_dcu_en) / sizeof(uint32_t); idx++) {
        host_dcu_en[idx] = P_CC3XX->ao.host_dcu_en[idx];
        *((uint32_t *)(val + (idx*sizeof(uint32_t)))) = host_dcu_en[idx];
    }

    return CC3XX_ERR_SUCCESS;
}

cc3xx_err_t cc3xx_dcu_get_locked(uint8_t *val, size_t len)
{
    uint32_t idx;
    uint32_t host_dcu_lock[4];

    assert(len == sizeof(P_CC3XX->ao.host_dcu_lock));
    assert(val != NULL);

    for (idx = 0; idx < sizeof(P_CC3XX->ao.host_dcu_lock) / sizeof(uint32_t); idx++) {
        host_dcu_lock[idx] = P_CC3XX->ao.host_dcu_lock[idx];
        *((uint32_t *)(val + (idx*sizeof(uint32_t)))) = host_dcu_lock[idx];
    }

    return CC3XX_ERR_SUCCESS;
}

cc3xx_err_t cc3xx_dcu_set_locked(const uint8_t *val, size_t len)
{
    uint32_t idx;
    uint32_t host_dcu_lock[4];

    assert(len == sizeof(P_CC3XX->ao.host_dcu_lock));
    assert(val != NULL);

    for (idx = 0; idx < sizeof(P_CC3XX->ao.host_dcu_lock) / sizeof(uint32_t); idx++) {
        host_dcu_lock[idx] = *((const uint32_t *)(val + (idx*sizeof(uint32_t))));
        P_CC3XX->ao.host_dcu_lock[idx] = host_dcu_lock[idx];
    }

    return CC3XX_ERR_SUCCESS;
}

cc3xx_err_t cc3xx_dcu_set_enabled(const uint8_t *permissions_mask, size_t len)
{
    cc3xx_err_t err;
    uint32_t idx;
    uint32_t dcu_en_requested[4];

    assert(len == sizeof(P_CC3XX->ao.host_dcu_en));
    assert(permissions_mask != NULL);

    /* initialize the dcu_en_requested array to the values to be written */
    for (idx = 0; idx < sizeof(P_CC3XX->ao.host_dcu_en) / sizeof(uint32_t); idx++) {
        dcu_en_requested[idx] = *((uint32_t *)(permissions_mask + (idx*sizeof(uint32_t))));
    }

    CC3XX_INFO("Requested host_dcu_en: 0x%08x_%08x_%08x_%08x\r\n",
               dcu_en_requested[0],
               dcu_en_requested[1],
               dcu_en_requested[2],
               dcu_en_requested[3]);

    /* Check the permanent disable mask for the dcu_en */
    err = check_dcu_permanent_disable_mask(dcu_en_requested);
    if (err != CC3XX_ERR_SUCCESS) {
        return err;
    }

#ifdef CC3XX_CONFIG_DCU_ICV_RESTRICTION_MASK_CHECK
    /* Check the ICV restriction mask for the dcu_en */
    err = check_dcu_icv_restriction_mask(dcu_en_requested);
    if (err != CC3XX_ERR_SUCCESS) {
        return err;
    }
#endif /* CC3XX_CONFIG_DCU_ICV_RESTRICTION_MASK_CHECK */

    /* Check if any dcu_lock has been locked for the corresponding dcu_en */
    err = check_dcu_locks(dcu_en_requested);
    if (err != CC3XX_ERR_SUCCESS) {
        return err;
    }

    for (idx = 0; idx < sizeof(P_CC3XX->ao.host_dcu_en) / sizeof(uint32_t); idx++) {
        P_CC3XX->ao.host_dcu_en[idx] = dcu_en_requested[idx];
    }

    CC3XX_INFO("Requested host_dcu_en applied successfully\r\n");

    return CC3XX_ERR_SUCCESS;
}
/** @} */ // end of cc3xx_dcu
