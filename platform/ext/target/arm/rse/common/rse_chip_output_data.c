/*
 * SPDX-License-Identifier: BSD-3-Clause
 *
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 */

#include <assert.h>

#include "device_definition.h"
#include "fih.h"
#include "platform_error_codes.h"
#include "region_defs.h"
#include "rse_chip_output_data.h"
#include "rse_kmu_keys.h"
#include "rse_otp_dev.h"
#include "rse_otp_layout.h"
#include "rse_provisioning_message.h"
#include "rse_persistent_data.h"
#include "tfm_log.h"
#include "tfm_plat_defs.h"
#include "tfm_plat_otp.h"
#include "psa/crypto.h"
#include "rse_soc_uid.h"

/**
 * @brief Summary Checks that a OTP memory area is not all-zeros.
 *
 * @note  It directly accesses the OTP memory without going through the HAL
 *        to minimise the performance overhead
 *
 * @param[in] start  Base address for the OTP memory area to check. Must be
 *                   provided through the usage of OTP_OFFSET() usually
 * @param[in] length The length in bytes of the memory area to check
 *                   Must be a multiple of a word, which is a reasonable
 *                   assumption as fields in the OTP area are aligned
 *
 * @return true if the area is non-zero, false otherwise
 *
 */
static bool check_non_zero_area(uintptr_t start, size_t length)
{
    assert(!(length % sizeof(uint32_t)));
    const uintptr_t end = start + length;

    const uint32_t *ptr = (const uint32_t *)start;
    while (((uintptr_t)ptr < end) && (*ptr == 0x0UL)) {
        ptr++;
    }

    /* If ptr reaches the end it means it was all zeros */
    return !((uintptr_t)ptr == end);
}

static bool is_rse_chip_output_data_available_in_otp(void)
{
    if (!IS_RSE_OTP_AREA_VALID(CM)) {
        return false;
    }

    const bool is_cmac_available =
        check_non_zero_area((uintptr_t)OTP_OFFSET(P_RSE_OTP_CM->cod.cod_cmac),
                            sizeof(P_RSE_OTP_CM->cod.cod_cmac));

    if (is_cmac_available) {
        return check_non_zero_area(
            (uintptr_t)OTP_OFFSET(P_RSE_OTP_CM->cod.rak_pub),
            sizeof(P_RSE_OTP_CM->cod.rak_pub));
    } else {
        return false;
    }
}

#if defined(RSE_OTP_HAS_SOC_AREA)
static bool rse_soc_ieee_ecid_is_generated(void) {
    for (uint32_t idx = 0; idx < sizeof(P_RSE_OTP_SOC->soc_id_area.ieee_ecid) / sizeof(uint32_t); idx++) {
        if (0 != ((uint32_t *)P_RSE_OTP_SOC->soc_id_area.ieee_ecid)[idx]) {
            return true;
        }
    }

    return false;
}

static bool rse_soc_family_id_is_generated(void) {
    if (*((uint32_t *)P_RSE_OTP_SOC->soc_id_area.family_id) != 0) {
        return true;
    }

    return false;
}
#endif /* RSE_OTP_HAS_SOC_AREA */

enum tfm_plat_err_t rse_fetch_cod_data_fields_from_otp(
    struct rse_chip_output_data_fields_t *cod_fields,
    bool fetch_fields_from_cm_area)
{
    enum lcm_error_t lcm_err;
    enum tfm_plat_err_t plat_err;
    size_t hash_size;
    uint8_t otp_dma_ics[RSE_OTP_DMA_ICS_SIZE];
    psa_status_t status = PSA_ERROR_CORRUPTION_DETECTED;

#ifdef RSE_OTP_HAS_SOC_AREA
    lcm_err = lcm_otp_read(&LCM_DEV_S, OTP_OFFSET(P_RSE_OTP_SOC->
                                                    soc_id_area.unique_id),
                           sizeof(P_RSE_OTP_SOC->soc_id_area.unique_id),
                           (uint8_t *)cod_fields->soc_uid);
    if (lcm_err != LCM_ERROR_NONE) {
        return (enum tfm_plat_err_t)lcm_err;
    }

    lcm_err = lcm_otp_read(&LCM_DEV_S, OTP_OFFSET(P_RSE_OTP_SOC->
                                                    soc_id_area.ieee_ecid),
                           sizeof(P_RSE_OTP_SOC->soc_id_area.ieee_ecid),
                           (uint8_t *)cod_fields->soc_ieee_ecid);
    if (lcm_err != LCM_ERROR_NONE) {
        return (enum tfm_plat_err_t)lcm_err;
    }
#endif /* RSE_OTP_HAS_SOC_AREA */

    lcm_err = lcm_otp_read(&LCM_DEV_S, OTP_OFFSET(P_RSE_OTP_BL1_2->bl1_2_hash),
                           sizeof(P_RSE_OTP_BL1_2->bl1_2_hash),
                           (uint8_t *)cod_fields->bl1_2_hash);
    if (lcm_err != LCM_ERROR_NONE) {
        return (enum tfm_plat_err_t)lcm_err;
    }

    plat_err = tfm_plat_otp_read(PLAT_OTP_ID_DMA_ICS, sizeof(otp_dma_ics),
                                 otp_dma_ics);
    if (plat_err != TFM_PLAT_ERR_SUCCESS) {
        return plat_err;
    }

    /* Hash the DMA ICS just read from the OTP using SHA-384 */
    status = psa_hash_compute(PSA_ALG_SHA_384, otp_dma_ics, sizeof(otp_dma_ics),
                              cod_fields->dma_ics_hash,
                              sizeof(cod_fields->dma_ics_hash), &hash_size);

    if (status != PSA_SUCCESS) {
        return (enum tfm_plat_err_t)status;
    }

    assert(hash_size == 48);

    if (!fetch_fields_from_cm_area) {
        return TFM_PLAT_ERR_SUCCESS;
    } else if (!P_RSE_OTP_CM_IS_VALID) {
        return TFM_PLAT_ERR_COD_FIELDS_NOT_PROVISIONED;
    }

    lcm_err = lcm_otp_read(&LCM_DEV_S, OTP_OFFSET(P_RSE_OTP_CM->cod.rak_pub),
                           sizeof(P_RSE_OTP_CM->cod.rak_pub),
                           (uint8_t *)cod_fields->rak_pub);
    if (lcm_err != LCM_ERROR_NONE) {
        return (enum tfm_plat_err_t)lcm_err;
    }

    lcm_err = lcm_otp_read(&LCM_DEV_S, OTP_OFFSET(P_RSE_OTP_CM->
                                                    provisioning_blob_version),
                           sizeof(P_RSE_OTP_CM->provisioning_blob_version),
                           (uint8_t *)&(cod_fields->cm_prov_blob_version));
    if (lcm_err != LCM_ERROR_NONE) {
        return (enum tfm_plat_err_t)lcm_err;
    }

    return TFM_PLAT_ERR_SUCCESS;
}

enum tfm_plat_err_t
rse_generate_chip_output_data(struct rse_chip_output_data_fields_t *cod_fields,
                              uint8_t *cod_cmac, size_t cod_cmac_size)

{
    psa_status_t status = PSA_ERROR_CORRUPTION_DETECTED;
    size_t mac_length = 0;
    const psa_key_id_t key_id = cc3xx_get_opaque_key(RSE_KMU_SLOT_EXPORT_KEY);

    status = psa_mac_compute(key_id, PSA_ALG_CMAC,
                             (const uint8_t *)&cod_fields, sizeof(cod_fields),
                             cod_cmac, cod_cmac_size, &mac_length);

    if (status != PSA_SUCCESS) {
        return (enum tfm_plat_err_t)status;
    }

    assert(mac_length == 16);

    return TFM_PLAT_ERR_SUCCESS;
}

enum tfm_plat_err_t
rse_get_chip_output_data(struct rse_chip_output_data_structure_t *cod_data)
{
    enum lcm_error_t lcm_err;

    /* Check if we have COD data (rse_otp_cod_cm_area_t) in OTP */
    if (!is_rse_chip_output_data_available_in_otp()) {
        return TFM_PLAT_ERR_COD_DATA_NOT_PROVISIONED;
    }

#if defined(RSE_OTP_HAS_SOC_AREA)
    if (!rse_soc_uid_is_generated()) {
        ERROR("SoC UID not generated\r\n");
        return TFM_PLAT_ERR_SOC_UID_NOT_GENERATED;
    }

    if (!rse_soc_ieee_ecid_is_generated()) {
        ERROR("SoC IEEE ECID not generated");
        return TFM_PLAT_ERR_NOT_PERMITTED;
    }
#endif /* RSE_OTP_HAS_SOC_AREA */

    lcm_err = lcm_otp_read(&LCM_DEV_S, OTP_OFFSET(P_RSE_OTP_CM->cod.cod_cmac),
                           sizeof(P_RSE_OTP_CM->cod.cod_cmac),
                           (uint8_t *)cod_data->cod_cmac);
    if (lcm_err != LCM_ERROR_NONE) {
        return (enum tfm_plat_err_t)lcm_err;
    }

    return rse_fetch_cod_data_fields_from_otp(&(cod_data->cod_fields), true);
}

enum tfm_plat_err_t rse_chip_output_data_setup_key(void)
{
    enum tfm_plat_err_t err;
#ifdef RSE_OTP_HAS_SOC_AREA
    const uint32_t soc_family_id =
        P_RSE_OTP_SOC_IS_VALID
            ? *((uint32_t *)P_RSE_OTP_SOC->soc_id_area.family_id)
            : 0;
#else
    const uint32_t soc_family_id = 0;
#endif /* RSE_OTP_HAS_SOC_AREA */

    if (soc_family_id == 0) {
        ERROR("SoC Family ID is not valid\n");
        return TFM_PLAT_ERR_SOC_UID_NOT_GENERATED;
    }

    err = rse_setup_master_key((const uint8_t *)"KMASTER_CM",
                               sizeof("KMASTER_CM"), (const uint8_t *)"",
                               sizeof(""));

    if (err != TFM_PLAT_ERR_SUCCESS) {
        ERROR("CM Master key setup failed\n");
        return err;
    }

    /* This key is used for the CMAC operation and is derived from KMASTER */
    err = rse_setup_export_key((const uint8_t *)"KEXPORT_CM", sizeof("KEXPORT_CM"),
                               (const uint8_t *)soc_family_id, sizeof(uint32_t));
    if (err != TFM_PLAT_ERR_SUCCESS) {
        ERROR("CM Export key setup failed\n");
        return err;
    }

    return TFM_PLAT_ERR_SUCCESS;
}
