/*
 * SPDX-License-Identifier: BSD-3-Clause
 *
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 */

#ifndef __RSE_CHIP_OUTPUT_DATA_H__
#define __RSE_CHIP_OUTPUT_DATA_H__

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include "rse_otp_layout.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifndef __PACKED_STRUCT
#define __PACKED_STRUCT struct __attribute__((packed))
#endif /* PACKED_STRUCT */

__PACKED_STRUCT rse_chip_output_data_fields_t {
    uint8_t  soc_uid[12];
    uint32_t soc_family_id;
    uint8_t  soc_ieee_ecid[16];
    uint32_t soc_die_id;
    uint8_t  rak_pub[RSE_OTP_COD_RAK_PUB_SIZE];
    uint32_t cm_prov_blob_version;
    uint8_t  bl1_2_hash[RSE_OTP_BL1_2_HASH_SIZE];
    uint8_t  dma_ics_hash[RSE_OTP_COD_DMA_ICS_HASH_SIZE];
};

__PACKED_STRUCT rse_chip_output_data_structure_t {
    uint8_t cod_cmac[RSE_OTP_COD_CMAC_SIZE];
    struct rse_chip_output_data_fields_t cod_fields;
};

/**
 * @brief Fill the COD data fields from OTP, optionally reading the CM fields as
 *        well, rse_chip_output_data_structure_t::rse_chip_output_data_fields_t
 *
 * @note  The reading of the CM provisioned fields from OTP is optinal because
 *        this function itself can be called during CM provisioning when those
 *        fields are not ready yet
 *
 * @param[out] cod_data                  COD data structure to fill with
 *                                       retrieved values
 * @param[in]  fetch_fields_from_cm_area Whether to read the CM area as well. It
 *                                       is expected that when calling this
 *                                       function during CM provisioning the CM
 *                                       area is not read
 *
 * \return Returns values as specified by the \ref enum tfm_plat_err_t
 */
enum tfm_plat_err_t rse_fetch_cod_data_fields_from_otp(
    struct rse_chip_output_data_fields_t *cod_fields,
    bool fetch_fields_from_cm_area);

/**
 * @brief Retrieves the COD data from OTP as specified by @ref
 *        rse_chip_output_data_structure_t
 *
 * @details During CM provisioning several OTP fields are populated and a CMAC
 *          authentication value is computed over them, which is known as COD
 *          (Chip Output Data)
 *
 * @param[out] cod_data The data structure which holds the retrieved COD data
 *                      and fields
 *
 * @return Returns values as specified by the \ref enum tfm_plat_err_t
 */
enum tfm_plat_err_t
    rse_get_chip_output_data(struct rse_chip_output_data_structure_t *cod_data);

/**
 * @brief Produces the CMAC-based authentication code over the COD fields which
 *        have to have been populated in the input already
 *
 * @note  The CMAC is computed on the \ref rse_chip_output_data_fields_t using
 *        KEXPORT_CM as key which must have been correctly setup at this point
 *
 * @param[in]  cod_fields    Structure that contains the data fields to
 *                           compute the CMAC on.
 * @param[out] cod_cmac      Buffer containing the COD, i.e. CMAC over fields
 * @param[in]  cod_cmac_size Size in bytes of the /p cod_cmac buffer
 *
 * @return Returns values as specified by the \ref enum tfm_plat_err_t
 *
 */
enum tfm_plat_err_t
rse_generate_chip_output_data(struct rse_chip_output_data_fields_t *cod_fields,
                              uint8_t *cod_cmac, size_t cod_cmac_size);

/**
 * @brief Sets up the key required for the generation of the COD data
 *
 * @details The COD data is a CMAC over a set of fields. To perform the CMAC
 *          operation the KEXPORT_CM key is required, which in turn derived
 *          from the KMASTER_CM
 *
 * @return Returns values as specified by the \ref enum tfm_plat_err_t. In
 *         case the key setup fails for any reason, an error message is printed
 */
enum tfm_plat_err_t rse_chip_output_data_setup_key(void);

#ifdef __cplusplus
}
#endif

#endif /* __RSE_CHIP_OUTPUT_DATA_H__ */
