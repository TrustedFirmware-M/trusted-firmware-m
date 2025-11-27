/*
 * Copyright (c) 2024-2025 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "ifx_flash_driver_api.h"
#include "ifx_se_crc32.h"
#include "ifx_utils.h"
#include "nv_counters_rram_driver.h"
#include "project_memory_layout.h"
#include "tfm_plat_nv_counters.h"

#ifndef IFX_NV_COUNTERS_CMSIS_FLASH_INSTANCE
#error "ERROR: Flash driver instance (IFX_NV_COUNTERS_CMSIS_FLASH_INSTANCE) should be defined"
#endif

typedef uint32_t ifx_rram_counter_value_t;

typedef struct
{
    union
    {
        ifx_rram_counter_value_t value;
        uint8_t                   bytes[sizeof(ifx_rram_counter_value_t)];
    } data;
    uint32_t checksum;
} ifx_rram_counter_t;

/* Address of NV counters block, it is equal 0 as relative are used */
#define IFX_TFM_NV_COUNTERS_BASE                   (0UL)
/* Relative offset of counters area in NV counters area */
#define IFX_TFM_NV_COUNTERS_COUNTER_AREA_OFFSET    (0UL)
/* Relative offset of backup area in NV counters area */
#define IFX_TFM_NV_COUNTERS_BACKUP_AREA_OFFSET     (IFX_TFM_NV_COUNTERS_COUNTER_AREA_OFFSET \
                                                    + ((PLAT_NV_COUNTER_MAX) \
                                                       * sizeof(ifx_rram_counter_t)))
#define IFX_TFM_NV_COUNTERS_BACKUP_AREA_SIZE       (PLAT_NV_COUNTER_MAX \
                                                    * sizeof(ifx_rram_counter_t))

#define IFX_NVM_INIT_DONE_FLAG                           (0xAA5533CCUL)
/* Initialization done flag must be stored in separate sector because it must be never changed
 * or corrupted during any backup update */
/* Relative offset of initialization done flag area in NV counters area */
#define IFX_TFM_NV_COUNTERS_NVM_INIT_DONE_FLAG_OFFSET    (IFX_ALIGN_UP_TO((IFX_TFM_NV_COUNTERS_BACKUP_AREA_OFFSET + \
                                                                IFX_TFM_NV_COUNTERS_BACKUP_AREA_SIZE), \
                                                                          IFX_TFM_NV_COUNTERS_SECTOR_SIZE))

/* NV Counters stored in memory in the following way:
 * |1st counter value||1st counter checksum|2nd counter value| ...
 * ... |last counter checksum|1st backup value|1st backup checksum|...
 * ... |last backup checksum| fill to align sector | IFX_NVM_INIT_DONE_FLAG value| fill to align sector |
 * So total size is: PLAT_NV_COUNTER_MAX of ifx_rram_counter_t structures for counters,
 * the same for its backups and one separate sector for NVM_INIT_DONE_FLAG.
 * IFX_TFM_NV_COUNTERS_AREA_SIZE must be aligned to IFX_TFM_NV_COUNTERS_SECTOR_SIZE */
#define IFX_TFM_NV_COUNTERS_EXPECTED_AREA_SIZE           (IFX_ALIGN_UP_TO((sizeof(ifx_rram_counter_t) \
                                                                           * (2U * ((uint32_t)PLAT_NV_COUNTER_MAX))), \
                                                                          IFX_TFM_NV_COUNTERS_SECTOR_SIZE) \
                                                          + IFX_TFM_NV_COUNTERS_SECTOR_SIZE)


static ifx_rram_counter_t *tfm_nv_counters                  = (ifx_rram_counter_t*)(IFX_TFM_NV_COUNTERS_COUNTER_AREA_OFFSET +
                                                                                                    IFX_TFM_NV_COUNTERS_BASE);
static ifx_rram_counter_t *tfm_nv_counters_backup           = (ifx_rram_counter_t*)(IFX_TFM_NV_COUNTERS_BACKUP_AREA_OFFSET +
                                                                                                    IFX_TFM_NV_COUNTERS_BASE);
static ifx_rram_counter_t *tfm_nv_counters_init_done_flag   = (ifx_rram_counter_t*)(IFX_TFM_NV_COUNTERS_NVM_INIT_DONE_FLAG_OFFSET +
                                                                                                    IFX_TFM_NV_COUNTERS_BASE);

/*******************************************************************************
* Function Name: ifx_rram_counter_is_checksum_valid
********************************************************************************
* Checks if checksum of the counter or its backup is valid.
* Checksum is calculated over data and its address.
*
* \param counters   Pointer to the counter.
* \param address    Actual address where the counter is stored in RRAM
*
* \return           true if the checksum matches, false otherwise.
*******************************************************************************/
static bool ifx_rram_counter_is_checksum_valid(const ifx_rram_counter_t *counter, uint32_t address)
{
    bool valid = false;
    uint32_t checksum = ifx_se_crc32d6a(sizeof(counter->data.bytes), counter->data.bytes, address);

    if (checksum == counter->checksum) {
        valid = true;
    }

    return valid;
}

/*******************************************************************************
* Function Name: ifx_rram_read_nv_counter_or_backup
********************************************************************************
* Reads the given non-volatile (NV) counter or its backup.
*
* \param[in]  counter_idx   NV counter ID.
*
* \param[out] val           Pointer to store the current NV counter or backup value.
*
* \param[in]  is_backup     True if need to read given backup, false if need to read given counter
*
* \return           TFM_PLAT_ERR_SUCCESS       if the value is read correctly
*                   TFM_PLAT_ERR_INVALID_INPUT in case of invalid input
*                   TFM_PLAT_ERR_MAX_VALUE     in case of incorrect checksum
*                   TFM_PLAT_ERR_SYSTEM_ERR    in case of driver error.
*******************************************************************************/
static enum tfm_plat_err_t ifx_rram_read_nv_counter_or_backup(enum tfm_nv_counter_t counter_idx,
                                                              uint32_t *val,
                                                              bool is_backup)
{
    int32_t ret = ARM_DRIVER_ERROR;
    ifx_rram_counter_t counter;
    uint32_t counter_addr;

    /* Check that size is multiple of Driver bytes per word value */
    IFX_ASSERT((sizeof(counter) % IFX_TFM_NV_COUNTERS_PROGRAM_UNIT) == 0U);
    uint32_t cnt = sizeof(counter) / IFX_TFM_NV_COUNTERS_PROGRAM_UNIT;

    if (val == NULL) {
        return TFM_PLAT_ERR_INVALID_INPUT;
    }

    if (counter_idx >= PLAT_NV_COUNTER_MAX) {
        return TFM_PLAT_ERR_INVALID_INPUT;
    }

    if (is_backup) {
        counter_addr = (uint32_t)&tfm_nv_counters_backup[counter_idx];
    } else {
        counter_addr = (uint32_t)&tfm_nv_counters[counter_idx];
    }

    ret = IFX_NV_COUNTERS_CMSIS_FLASH_INSTANCE.ReadData(counter_addr, &counter, cnt);

    if ((ret < 0) || (ret != (int32_t)cnt)) {
        return TFM_PLAT_ERR_SYSTEM_ERR;
    }

    if (!ifx_rram_counter_is_checksum_valid(&counter, counter_addr)) {
        return TFM_PLAT_ERR_MAX_VALUE;
    }

    *val = counter.data.value;

    return TFM_PLAT_ERR_SUCCESS;
}

/*******************************************************************************
* Function Name: ifx_rram_program_nv_counter_or_backup
********************************************************************************
* Program the given non-volatile (NV) counter or its backup.
*
* \param[in]  counter_idx  NV counter ID.
* \param[in]  value        New value of the NV counter or its backup.
* \param[in]  is_backup    True to program given backup, false to program given counter
*
* \return           TFM_PLAT_ERR_SUCCESS if the value is program correctly.
*                   Otherwise, it returns TFM_PLAT_ERR_SYSTEM_ERR.
*******************************************************************************/
static enum tfm_plat_err_t ifx_rram_program_nv_counter_or_backup(enum tfm_nv_counter_t counter_idx,
                                            uint32_t value, bool is_backup)
{
    int32_t ret = ARM_DRIVER_ERROR;
    enum tfm_plat_err_t status = TFM_PLAT_ERR_SYSTEM_ERR;
    ifx_rram_counter_t counter = {0};
    uint32_t counter_addr;
    uint32_t new_value;

    /* Check that size is multiple of Driver bytes per word value */
    IFX_ASSERT((sizeof(counter) % IFX_TFM_NV_COUNTERS_PROGRAM_UNIT) == 0U);
    uint32_t cnt = sizeof(counter) / IFX_TFM_NV_COUNTERS_PROGRAM_UNIT;

    if (is_backup) {
        counter_addr = (uint32_t)&tfm_nv_counters_backup[counter_idx];
    } else {
        counter_addr = (uint32_t)&tfm_nv_counters[counter_idx];
    }

    counter.data.value = value;
    counter.checksum   = ifx_se_crc32d6a(sizeof(counter.data.bytes),
                                                counter.data.bytes,
                                                counter_addr);

    ret = IFX_NV_COUNTERS_CMSIS_FLASH_INSTANCE.ProgramData(counter_addr, &counter, cnt);

    if ((ret < 0) || (ret != (int32_t)cnt)) {
        return TFM_PLAT_ERR_SYSTEM_ERR;
    }

    /* Check that the NV counter or its backup write hasn't failed */
    status = ifx_rram_read_nv_counter_or_backup(counter_idx, &new_value, is_backup);

    if (status != TFM_PLAT_ERR_SUCCESS) {
        return status;
    }

    if (new_value != value) {
        return TFM_PLAT_ERR_SYSTEM_ERR;
    }

    return TFM_PLAT_ERR_SUCCESS;
}

/*******************************************************************************
* Function Name: ifx_rram_restore_counter_from_backup
********************************************************************************
* Copies backup value to its counter
*
* \return     TFM_PLAT_ERR_SUCCESS if successful.
*******************************************************************************/
static enum tfm_plat_err_t ifx_rram_restore_counter_from_backup(enum tfm_nv_counter_t counter_idx)
{
    enum tfm_plat_err_t status = TFM_PLAT_ERR_SYSTEM_ERR;
    uint32_t backup_val;

    /* Read backup */
    status = ifx_rram_read_nv_counter_or_backup(counter_idx, &backup_val, true);

    if (status != TFM_PLAT_ERR_SUCCESS) {
        return status;
    }

    /* Program counter */
    status = ifx_rram_program_nv_counter_or_backup(counter_idx, backup_val, false);

    return status;
}

/*******************************************************************************
* Function Name: ifx_rram_recover_tfm_nv_counters
********************************************************************************
* Checks for all counters if it need recovering from its backup
* and recovers it if needed.
* Recovery may be needed if a power failure occurs during counter update.
*
* \return         TFM_PLAT_ERR_SUCCESS if successful.
*******************************************************************************/
static enum tfm_plat_err_t ifx_rram_recover_tfm_nv_counters(void)
{
    enum tfm_plat_err_t status_counter = TFM_PLAT_ERR_SYSTEM_ERR;
    enum tfm_plat_err_t status_backup  = TFM_PLAT_ERR_SYSTEM_ERR;
    enum tfm_plat_err_t status         = TFM_PLAT_ERR_SYSTEM_ERR;
    uint32_t counter_val;
    uint32_t backup_val;

    for (uint32_t counter_idx = 0UL; counter_idx < (uint32_t)PLAT_NV_COUNTER_MAX; counter_idx++) {
        /* Read backup */
        status_backup = ifx_rram_read_nv_counter_or_backup((enum tfm_nv_counter_t)counter_idx,
                                                           &backup_val,
                                                           true);
        if ((status_backup != TFM_PLAT_ERR_SUCCESS) && (status_backup != TFM_PLAT_ERR_MAX_VALUE)) {
            /* Unexpected error */
            return status_backup;
        }

        /* Read counter */
        status_counter = ifx_rram_read_nv_counter_or_backup((enum tfm_nv_counter_t)counter_idx,
                                                            &counter_val,
                                                            false);
        if ((status_counter != TFM_PLAT_ERR_SUCCESS) && (status_counter != TFM_PLAT_ERR_MAX_VALUE)) {
            /* Unexpected error */
            return status_counter;
        }

        if (status_backup == TFM_PLAT_ERR_SUCCESS) {
            if (status_counter == TFM_PLAT_ERR_SUCCESS) {
                /* ((status_backup == TFM_PLAT_ERR_SUCCESS) && (status_counter == TFM_PLAT_ERR_SUCCESS)) */
                if (backup_val > counter_val) {
                    /* Set counter procedure was interrupted after writing of new value to backup
                     * but before writing it to counter */
                    status = ifx_rram_restore_counter_from_backup((enum tfm_nv_counter_t)counter_idx);

                    if (status != TFM_PLAT_ERR_SUCCESS) {
                        return status;
                    }
                } else {
                    /* If checksum of counter and its backup are correct and value of backup is
                     * not more than counter value,
                     * then there is no problem with this counter. Nothing to do */
                }
            } else {
                /* Set counter procedure was interrupted during writing of new value to counter */
                status = ifx_rram_restore_counter_from_backup((enum tfm_nv_counter_t)counter_idx);

                if (status != TFM_PLAT_ERR_SUCCESS) {
                    return status;
                }
            }
        } else {
            if (status_counter == TFM_PLAT_ERR_SUCCESS) {
                /* If counter has correct checksum and its backup has wrong checksum it means that
                 * set counter procedure was interrupted during writing of new value to backup
                 * In this case do nothing because the value to set into counter is unknown.
                 * It's ok that backup remains corrupted as it will be rewritten in next set
                 * counter operation */
                continue;
            } else {
                /* If both counter and its backup have wrong checksums it means some error or
                 * uninitialized counters */
                return TFM_PLAT_ERR_SYSTEM_ERR;
            }
        }
    }

    return TFM_PLAT_ERR_SUCCESS;
}

/*******************************************************************************
* Function Name: ifx_rram_clear_counters_and_backups
********************************************************************************
* Clears (writes 0 value) all NV counters and backups.
* Used only during provisioning or re-provisioning.
*
* \return         TFM_PLAT_ERR_SUCCESS if successful.
*******************************************************************************/
enum tfm_plat_err_t ifx_rram_clear_counters_and_backups(void)
{
    enum tfm_plat_err_t status = TFM_PLAT_ERR_SYSTEM_ERR;

    for (uint32_t counter_idx = 0UL; counter_idx < (uint32_t)PLAT_NV_COUNTER_MAX; counter_idx++) {

        /* Program backup */
        status = ifx_rram_program_nv_counter_or_backup((enum tfm_nv_counter_t)counter_idx,
                                                       0,
                                                       true);


        if (status != TFM_PLAT_ERR_SUCCESS) {
            return status;
        }

        /* Program counter */
        status = ifx_rram_program_nv_counter_or_backup((enum tfm_nv_counter_t)counter_idx,
                                                       0,
                                                       false);

        if (status != TFM_PLAT_ERR_SUCCESS) {
            return status;
        }
    }

    return TFM_PLAT_ERR_SUCCESS;
}

enum tfm_plat_err_t tfm_plat_init_nv_counter(void)
{
    int32_t ret = ARM_DRIVER_ERROR;
    ifx_rram_counter_t counter;
    uint32_t counter_addr;

    /* Check that size is multiple of Driver bytes per word value */
    IFX_ASSERT((sizeof(counter) % IFX_TFM_NV_COUNTERS_PROGRAM_UNIT) == 0U);
    uint32_t cnt = sizeof(counter) / IFX_TFM_NV_COUNTERS_PROGRAM_UNIT;

    IFX_ASSERT((uint32_t)IFX_TFM_NV_COUNTERS_AREA_SIZE
                          >= (uint32_t)IFX_TFM_NV_COUNTERS_EXPECTED_AREA_SIZE);

    ret = IFX_NV_COUNTERS_CMSIS_FLASH_INSTANCE.Initialize((ARM_Flash_SignalEvent_t)NULL);

    if (ret != ARM_DRIVER_OK) {
        return TFM_PLAT_ERR_SYSTEM_ERR;
    }

    counter_addr = (uint32_t)&tfm_nv_counters_init_done_flag[0];

    ret = IFX_NV_COUNTERS_CMSIS_FLASH_INSTANCE.ReadData(counter_addr, &counter, cnt);

    if ((ret < 0) || (ret != (int32_t)cnt)) {
        return TFM_PLAT_ERR_SYSTEM_ERR;
    }

    if (counter.data.value != IFX_NVM_INIT_DONE_FLAG) { /* NV Counters were not initialized */
        enum tfm_plat_err_t status = ifx_rram_clear_counters_and_backups();
        if (status != TFM_PLAT_ERR_SUCCESS) {
            return status;
        }

        counter.data.value = IFX_NVM_INIT_DONE_FLAG;
        ret = IFX_NV_COUNTERS_CMSIS_FLASH_INSTANCE.ProgramData(counter_addr, &counter, cnt);

        if ((ret < 0) || (ret != (int32_t)cnt)) {
            return TFM_PLAT_ERR_SYSTEM_ERR;
        }
    }

    return ifx_rram_recover_tfm_nv_counters();
}

enum tfm_plat_err_t tfm_plat_read_nv_counter(enum tfm_nv_counter_t counter_id,
                                             uint32_t size, uint8_t *val)
{
    /* This check ensure that we can treat val as a uint32_t * */
    if (size != sizeof(uint32_t)) {
        return TFM_PLAT_ERR_INVALID_INPUT;
    }

    /* Read counter */
    return ifx_rram_read_nv_counter_or_backup(counter_id, (uint32_t *) val, false);
}

enum tfm_plat_err_t tfm_plat_set_nv_counter(enum tfm_nv_counter_t counter_id,
                                            uint32_t value)
{
    enum tfm_plat_err_t status = TFM_PLAT_ERR_SYSTEM_ERR;
    uint32_t old_value;

    /* Read counter */
    status = ifx_rram_read_nv_counter_or_backup(counter_id, &old_value, false);

    if (status != TFM_PLAT_ERR_SUCCESS) {
        return status;
    }

    if (value < old_value) {
        return TFM_PLAT_ERR_INVALID_INPUT;
    }

    if (value == old_value) {
        /* Counter is already set to required value, no sense to update it again */
        return TFM_PLAT_ERR_SUCCESS;
    }

    if (old_value == UINT32_MAX) {
        return TFM_PLAT_ERR_MAX_VALUE;
    }

    /* Program backup */
    status = ifx_rram_program_nv_counter_or_backup(counter_id, value, true);

    if (status != TFM_PLAT_ERR_SUCCESS) {
        return status;
    }

    /* Program counter */
    status = ifx_rram_program_nv_counter_or_backup(counter_id, value, false);

    if (status != TFM_PLAT_ERR_SUCCESS) {
        return status;
    }

    return TFM_PLAT_ERR_SUCCESS;
}

enum tfm_plat_err_t tfm_plat_increment_nv_counter(enum tfm_nv_counter_t counter_id)
{
    uint32_t security_cnt;
    enum tfm_plat_err_t status;

    status = tfm_plat_read_nv_counter(counter_id, sizeof(security_cnt), (uint8_t *)&security_cnt);

    if (status != TFM_PLAT_ERR_SUCCESS) {
        return status;
    }

    if (security_cnt == UINT32_MAX) {
        return TFM_PLAT_ERR_MAX_VALUE;
    }

    return tfm_plat_set_nv_counter(counter_id, security_cnt + 1u);
}
