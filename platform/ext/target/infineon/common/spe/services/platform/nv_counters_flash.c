/*
 * Copyright (c) 2024-2025 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "ifx_se_crc32.h"
#include "ifx_utils.h"
#include "nv_counters_flash_driver.h"
#include "coverity_check.h"
#include "tfm_plat_nv_counters.h"

#include <limits.h>
#include <stddef.h>

/* Compilation time checks to be sure the defines are well defined */
#ifndef IFX_TFM_NV_COUNTERS_SECTOR_SIZE
#error "Flash driver sector size (IFX_TFM_NV_COUNTERS_SECTOR_SIZE) must be defined"
#endif

#ifndef IFX_NV_COUNTERS_CMSIS_FLASH_INSTANCE
#error "Flash driver instance (IFX_NV_COUNTERS_CMSIS_FLASH_INSTANCE) must be defined"
#endif
/* End of compilation time checks to be sure the defines are well defined */

#define IFX_NV_COUNTER_SIZE  sizeof(uint32_t)
#define IFX_INIT_VALUE_SIZE  sizeof(uint32_t)
#define IFX_CHECKSUM_SIZE    sizeof(uint32_t)
#define IFX_NUM_NV_COUNTERS  ((IFX_TFM_NV_COUNTERS_SECTOR_SIZE \
                               - IFX_INIT_VALUE_SIZE \
                               - IFX_CHECKSUM_SIZE) / IFX_NV_COUNTER_SIZE)

#define IFX_NV_COUNTERS_INITIALIZED 0xC0DE0042U

#define IFX_TFM_NV_COUNTERS_AREA_OFFSET     (0U)
#define IFX_TFM_NV_COUNTERS_BACKUP_OFFSET   (IFX_TFM_NV_COUNTERS_AREA_OFFSET \
                                             + IFX_TFM_NV_COUNTERS_SECTOR_SIZE)

#define IFX_NV_COUNTERS_CRC_INIT            (0)

/**
 * \brief Struct representing the NV counter data in flash.
 */
typedef struct ifx_nv_counters {
    uint32_t checksum;
    uint32_t init_value; /* Watermark to indicate if the NV counters have been initialised */
    union {
        uint32_t    counters[IFX_NUM_NV_COUNTERS]; /**< Array of NV counters */
        uint8_t     bytes[IFX_NUM_NV_COUNTERS * sizeof(uint32_t)];
    } nv_cnt;
} ifx_nv_counters_t;

/*******************************************************************************
* Function Name: ifx_flash_counters_valid
********************************************************************************
* Checks if checksum and initial value of the counter or its backup is valid.
* Checksum is calculated over data and its address.
*
* \param nv_counters    Pointer to the counters.
*
* \return               true if the checksum matches, false otherwise.
*******************************************************************************/
static bool ifx_flash_counters_valid(const ifx_nv_counters_t *nv_counters)
{
    bool valid = false;
    uint32_t checksum = ifx_se_crc32d6a(sizeof(nv_counters->nv_cnt.bytes),
                                        nv_counters->nv_cnt.bytes,
                                        IFX_NV_COUNTERS_CRC_INIT);

    if ((nv_counters->init_value == IFX_NV_COUNTERS_INITIALIZED) &&
        (checksum == nv_counters->checksum)) {
        valid = true;
    }

    return valid;
}

static void ifx_flash_counter_set_checksum(ifx_nv_counters_t *nv_counters)
{
    nv_counters->checksum = ifx_se_crc32d6a(sizeof(nv_counters->nv_cnt.bytes),
                                            nv_counters->nv_cnt.bytes,
                                            IFX_NV_COUNTERS_CRC_INIT);
}


enum tfm_plat_err_t tfm_plat_init_nv_counter(void)
{
    TFM_COVERITY_DEVIATE_LINE(MISRA_C_2023_Rule_2_2, "This code is added to perform compile time check")
    IFX_ASSERT(IFX_NUM_NV_COUNTERS >= PLAT_NV_COUNTER_MAX);

    ifx_nv_counters_t nv_counters;
    int32_t ret = IFX_NV_COUNTERS_CMSIS_FLASH_INSTANCE.Initialize(NULL);
    if (ret != ARM_DRIVER_OK) {
        return TFM_PLAT_ERR_SYSTEM_ERR;
    }

    ret = IFX_NV_COUNTERS_CMSIS_FLASH_INSTANCE.ReadData(IFX_TFM_NV_COUNTERS_AREA_OFFSET,
                                                        &nv_counters,
                                                        sizeof(nv_counters));
    if ((ret < 0) || (ret != (int32_t)sizeof(nv_counters))) {
        return TFM_PLAT_ERR_SYSTEM_ERR;
    }

    if (ifx_flash_counters_valid(&nv_counters)) {
        return TFM_PLAT_ERR_SUCCESS;
    }

    ret = IFX_NV_COUNTERS_CMSIS_FLASH_INSTANCE.ReadData(IFX_TFM_NV_COUNTERS_BACKUP_OFFSET,
                                                        &nv_counters,
                                                        sizeof(nv_counters));
    if ((ret < 0) || (ret != (int32_t)sizeof(nv_counters))) {
        return TFM_PLAT_ERR_SYSTEM_ERR;
    }

    /* Erase sector before writing to it */
    ret = IFX_NV_COUNTERS_CMSIS_FLASH_INSTANCE.EraseSector(IFX_TFM_NV_COUNTERS_AREA_OFFSET);
    if (ret != ARM_DRIVER_OK) {
        return TFM_PLAT_ERR_SYSTEM_ERR;
    }

    TFM_COVERITY_DEVIATE_LINE(MISRA_C_2023_Rule_15_7, "No need for an else statement here. This adds counters if they are invalid, if they are good - we just proceed.")
    if (nv_counters.init_value != IFX_NV_COUNTERS_INITIALIZED) {
        /* Main and backup area are invalid.
         * Add watermark to indicate that NV counters have been initialized. */
        nv_counters.init_value = IFX_NV_COUNTERS_INITIALIZED;

        /* Initialize all counters to 0 */
        for (uint32_t i = 0; i < IFX_NUM_NV_COUNTERS; i++) {
            nv_counters.nv_cnt.counters[i] = 0;
        }

        ifx_flash_counter_set_checksum(&nv_counters);
    }
    else if (!ifx_flash_counters_valid(&nv_counters)) {
        /* It's unexpected that backup area has valid watermark while both
         * blocks are invalid */
        return TFM_PLAT_ERR_SYSTEM_ERR;
    }

    /* Write the in-memory block content after modification to flash */
    ret = IFX_NV_COUNTERS_CMSIS_FLASH_INSTANCE.ProgramData(IFX_TFM_NV_COUNTERS_AREA_OFFSET,
                                                           &nv_counters,
                                                           sizeof(nv_counters));
    if ((ret < 0) || (ret != (int32_t)sizeof(nv_counters))) {
        return TFM_PLAT_ERR_SYSTEM_ERR;
    }

    return TFM_PLAT_ERR_SUCCESS;
}

enum tfm_plat_err_t tfm_plat_read_nv_counter(enum tfm_nv_counter_t counter_id,
                                             uint32_t size, uint8_t *val)
{
    uint32_t nv_counter_id = (uint32_t)counter_id;
    if (nv_counter_id >= IFX_NUM_NV_COUNTERS) {
        return TFM_PLAT_ERR_INVALID_INPUT;
    }

    if (size != IFX_NV_COUNTER_SIZE) {
        return TFM_PLAT_ERR_SYSTEM_ERR;
    }

    uint32_t flash_addr = IFX_TFM_NV_COUNTERS_AREA_OFFSET + \
                          offsetof(ifx_nv_counters_t, nv_cnt.counters) + \
                          (nv_counter_id * IFX_NV_COUNTER_SIZE);

    int32_t ret = IFX_NV_COUNTERS_CMSIS_FLASH_INSTANCE.ReadData(flash_addr,
                                                                val,
                                                                IFX_NV_COUNTER_SIZE);
    if ((ret < 0) || (ret != (int32_t)IFX_NV_COUNTER_SIZE)) {
        return TFM_PLAT_ERR_SYSTEM_ERR;
    }

    return TFM_PLAT_ERR_SUCCESS;
}

enum tfm_plat_err_t tfm_plat_set_nv_counter(enum tfm_nv_counter_t counter_id,
                                            uint32_t value)
{
    ifx_nv_counters_t nv_counters;
    uint32_t nv_counter_id = (uint32_t)counter_id;

    if (nv_counter_id >= IFX_NUM_NV_COUNTERS) {
        return TFM_PLAT_ERR_INVALID_INPUT;
    }

    /* Read the whole sector so we can write it back to flash later */
    int32_t ret = IFX_NV_COUNTERS_CMSIS_FLASH_INSTANCE.ReadData(IFX_TFM_NV_COUNTERS_AREA_OFFSET,
                                                                &nv_counters,
                                                                sizeof(nv_counters));
    if ((ret < 0) || (ret != (int32_t)sizeof(nv_counters))) {
        return TFM_PLAT_ERR_SYSTEM_ERR;
    }

    if (value == nv_counters.nv_cnt.counters[nv_counter_id]) {
        return TFM_PLAT_ERR_SUCCESS;
    }

    if (value < nv_counters.nv_cnt.counters[nv_counter_id]) {
        return TFM_PLAT_ERR_INVALID_INPUT;
    }

    /* Erase backup sector */
    ret = IFX_NV_COUNTERS_CMSIS_FLASH_INSTANCE.EraseSector(IFX_TFM_NV_COUNTERS_BACKUP_OFFSET);
    if (ret != ARM_DRIVER_OK) {
        return TFM_PLAT_ERR_SYSTEM_ERR;
    }

    nv_counters.nv_cnt.counters[nv_counter_id] = value;

    ifx_flash_counter_set_checksum(&nv_counters);

    /* write sector data to backup sector */
    ret = IFX_NV_COUNTERS_CMSIS_FLASH_INSTANCE.ProgramData(IFX_TFM_NV_COUNTERS_BACKUP_OFFSET,
                                                           &nv_counters,
                                                           sizeof(nv_counters));
    if ((ret < 0) || (ret != (int32_t)sizeof(nv_counters))) {
        return TFM_PLAT_ERR_SYSTEM_ERR;
    }

    /* Erase sector before writing to it */
    ret = IFX_NV_COUNTERS_CMSIS_FLASH_INSTANCE.EraseSector(IFX_TFM_NV_COUNTERS_AREA_OFFSET);
    if (ret != ARM_DRIVER_OK) {
        return TFM_PLAT_ERR_SYSTEM_ERR;
    }

    /* Write the in-memory block content after modification to flash */
    ret = IFX_NV_COUNTERS_CMSIS_FLASH_INSTANCE.ProgramData(IFX_TFM_NV_COUNTERS_AREA_OFFSET,
                                                           &nv_counters,
                                                           sizeof(nv_counters));
    if ((ret < 0) || (ret != (int32_t)sizeof(nv_counters))) {
        return TFM_PLAT_ERR_SYSTEM_ERR;
    }

    return TFM_PLAT_ERR_SUCCESS;
}

enum tfm_plat_err_t tfm_plat_increment_nv_counter(enum tfm_nv_counter_t counter_id)
{
    uint32_t security_cnt;

    enum tfm_plat_err_t err = tfm_plat_read_nv_counter(counter_id,
                                                       sizeof(security_cnt),
                                                       (uint8_t *)&security_cnt);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return err;
    }

    if (security_cnt == UINT32_MAX) {
        return TFM_PLAT_ERR_MAX_VALUE;
    }

    return tfm_plat_set_nv_counter(counter_id, security_cnt + 1U);
}
