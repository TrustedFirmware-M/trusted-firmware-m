/*
 * Copyright (c) 2023-2025 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <string.h>
#include "config_tfm.h"
#include "cmsis.h"
#include "ifx_s_peripherals_def.h" /* Early because it has macro used to include other files */
#if defined(IFX_NON_SECURE_SFLASH_BASE)
#include "ifx_assets_rram.h"
#endif /* defined(IFX_NON_SECURE_SFLASH_BASE) */
#include "tfm_plat_device_id.h"

#define IFX_ADD_TO_IMPLEMENTATION_ID(buffer, val)       (void)memcpy((buffer), \
                                                                     (const void*)(&(val)), \
                                                                     sizeof((val))); \
                                                        (buffer) += sizeof((val));

#ifndef IFX_ATTESTATION_HW_VERSION
/**
 * Default value of H/W version for Initial Attestation service.
 */
#define IFX_ATTESTATION_HW_VERSION "0123456789012-12345"
#endif

enum tfm_plat_err_t tfm_plat_get_implementation_id(uint32_t *size, uint8_t  *buf)
{
#if IFX_INITIAL_ATTESTATION_SE_RT
    /* In case of SERT attestation - implementation ID is calculated by SERT */
    return TFM_PLAT_ERR_SYSTEM_ERR;
#else /* IFX_INITIAL_ATTESTATION_SE_RT */
    /* Validate parameters */
    if ((size == NULL) || (buf == NULL)) {
        return TFM_PLAT_ERR_INVALID_INPUT;
    }

    (void)memset(buf, 0, *size);

#if defined(IFX_NON_SECURE_SFLASH_BASE)
    int32_t status = ARM_DRIVER_ERROR;
    uint8_t die_id[sizeof(IFX_NON_SECURE_SFLASH_BASE->DIE_ID) - IFX_ASSETS_RRAM_CHECKSUM_SIZE];
    uint8_t device_id_to[sizeof(IFX_NON_SECURE_SFLASH_BASE->DEVICE_ID_TO)
                         - IFX_ASSETS_RRAM_CHECKSUM_SIZE];
    uint8_t device_id_mpn[sizeof(IFX_NON_SECURE_SFLASH_BASE->DEVICE_ID_MPN)
                          - IFX_ASSETS_RRAM_CHECKSUM_SIZE];

    if (*size < (sizeof(die_id) + sizeof(device_id_to) + sizeof(device_id_mpn))) {
        return TFM_PLAT_ERR_SYSTEM_ERR;
    }

    status = ifx_assets_rram_read_asset((uint32_t)IFX_NON_SECURE_SFLASH_BASE->DIE_ID,
                                        die_id,
                                        sizeof(die_id));
    if (status != ARM_DRIVER_OK) {
        return TFM_PLAT_ERR_SYSTEM_ERR;
    }

    status = ifx_assets_rram_read_asset((uint32_t)IFX_NON_SECURE_SFLASH_BASE->DEVICE_ID_TO,
                                        device_id_to,
                                        sizeof(device_id_to));
    if (status != ARM_DRIVER_OK) {
        return TFM_PLAT_ERR_SYSTEM_ERR;
    }

    status = ifx_assets_rram_read_asset((uint32_t)IFX_NON_SECURE_SFLASH_BASE->DEVICE_ID_MPN,
                                        device_id_mpn,
                                        sizeof(device_id_mpn));
    if (status != ARM_DRIVER_OK) {
        return TFM_PLAT_ERR_SYSTEM_ERR;
    }

    /* Set Implementation ID as die_id (LOT + WAFER + X + Y + SORT + DAY + MONTH + YEAR ) +
     * device_id_to (FAMILY_ID + SI_REVISION_ID) + device_id_mpn (SILICON_ID) */
    IFX_ADD_TO_IMPLEMENTATION_ID(buf, die_id);
    IFX_ADD_TO_IMPLEMENTATION_ID(buf, device_id_to);
    IFX_ADD_TO_IMPLEMENTATION_ID(buf, device_id_mpn);
#elif defined(IFX_SFLASH)
    if (*size < (sizeof(IFX_SFLASH->SI_REVISION_ID) + sizeof(IFX_SFLASH->SILICON_ID) +
                 sizeof(IFX_SFLASH->FAMILY_ID)      + sizeof(IFX_SFLASH->SFLASH_SVN) +
                 sizeof(IFX_SFLASH->DIE_LOT)        + sizeof(IFX_SFLASH->DIE_WAFER)  +
                 sizeof(IFX_SFLASH->DIE_X)          + sizeof(IFX_SFLASH->DIE_Y)      +
                 sizeof(IFX_SFLASH->DIE_SORT)       + sizeof(IFX_SFLASH->DIE_MINOR)  +
                 sizeof(IFX_SFLASH->DIE_DAY)        + sizeof(IFX_SFLASH->DIE_MONTH)  +
                 sizeof(IFX_SFLASH->DIE_YEAR))) {
        return TFM_PLAT_ERR_SYSTEM_ERR;
    }

    /* Set Implementation ID as SI_REVISION_ID + SILICON_ID + FAMILY_ID +
     * SFLASH_SVN + DIE_LOT + DIE_WAFER + DIE_X + DIE_Y + DIE_SORT + DIE_MINOR +
     * DIE_DAY + DIE_MONTH + DIE_YEAR */
    IFX_ADD_TO_IMPLEMENTATION_ID(buf, IFX_SFLASH->SI_REVISION_ID);
    IFX_ADD_TO_IMPLEMENTATION_ID(buf, IFX_SFLASH->SILICON_ID);
    IFX_ADD_TO_IMPLEMENTATION_ID(buf, IFX_SFLASH->FAMILY_ID);
    IFX_ADD_TO_IMPLEMENTATION_ID(buf, IFX_SFLASH->SFLASH_SVN);
    IFX_ADD_TO_IMPLEMENTATION_ID(buf, IFX_SFLASH->DIE_LOT);
    IFX_ADD_TO_IMPLEMENTATION_ID(buf, IFX_SFLASH->DIE_WAFER);
    IFX_ADD_TO_IMPLEMENTATION_ID(buf, IFX_SFLASH->DIE_X);
    IFX_ADD_TO_IMPLEMENTATION_ID(buf, IFX_SFLASH->DIE_Y);
    IFX_ADD_TO_IMPLEMENTATION_ID(buf, IFX_SFLASH->DIE_SORT);
    IFX_ADD_TO_IMPLEMENTATION_ID(buf, IFX_SFLASH->DIE_MINOR);
    IFX_ADD_TO_IMPLEMENTATION_ID(buf, IFX_SFLASH->DIE_DAY);
    IFX_ADD_TO_IMPLEMENTATION_ID(buf, IFX_SFLASH->DIE_MONTH);
    IFX_ADD_TO_IMPLEMENTATION_ID(buf, IFX_SFLASH->DIE_YEAR);
#else /* defined(IFX_NON_SECURE_SFLASH_BASE) */
#error "Unsupported implementation or invalid configuration"
#endif /* defined(IFX_NON_SECURE_SFLASH_BASE) */

    return TFM_PLAT_ERR_SUCCESS;
#endif /* IFX_INITIAL_ATTESTATION_SE_RT */
}

enum tfm_plat_err_t tfm_plat_get_cert_ref(uint32_t *size, uint8_t *buf)
{
    /* Recommended to use the European Article Number format: EAN-13+5 */
    static const char value[] = IFX_ATTESTATION_HW_VERSION;

    /* Validate parameters */
    if ((size == NULL) || (buf == NULL)) {
        return TFM_PLAT_ERR_INVALID_INPUT;
    }

    if (*size < (sizeof(value) - 1U)) {
        return TFM_PLAT_ERR_SYSTEM_ERR;
    }

    /* Prepare result */
    *size = sizeof(value) - 1U;
    (void)memcpy(buf, value, *size);

    return TFM_PLAT_ERR_SUCCESS;
}
