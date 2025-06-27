/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __RSE_IAK_ENDORSEMENT_CERT_H__
#define __RSE_IAK_ENDORSEMENT_CERT_H__

#include <stdint.h>
#include "platform_error_codes.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \def ENDORESEMENT_CERT_SKI_LENGTH
 * \brief Required length (in bytes) of the endorsement certificate Subject Key Identifier (SKI).
 */
#define ENDORSEMENT_CERT_SKI_LENGTH (20)

/**
 * \struct rse_iak_endorsement_cert_dynamic_params_s
 * \brief Dynamic platform-specific parameters used during certificate generation.
 */
struct rse_iak_endorsement_cert_dynamic_params_s {
    /**
     * \brief Value read from the SOC_INFO_REG register.
     */
    uint32_t soc_info_reg_val;

    /**
     * \brief Pointer to buffer containing the unique SoC identifier (UID).
     */
    uint8_t *soc_uid;

    /**
     * \brief Size of the UID buffer in bytes.
     */
    size_t soc_uid_size;

    /**
     * \brief Pointer to the public key of the IAK.
     */
    uint8_t *rak_pub;

    /**
     * \brief Size of the IAK public key buffer in bytes.
     */
    size_t rak_pub_size;
};

/**
 * \struct rse_iak_endorsement_cert_provisioned_params_s
 * \brief Provisioned parameters required to generate the endorsement certificate.
 */
struct rse_iak_endorsement_cert_provisioned_params_s {
    /**
     * \brief Pointer to buffer containing the endorsement certificate's Subject Key Identifier (SKI).
     */
    uint8_t *endorsement_cert_ski;

    /**
     * \brief Size of the SKI buffer in bytes.
     */
    size_t endorsement_cert_ski_size;

    /**
     * \brief Pointer to the endorsement signature data.
     */
    uint8_t *signature;

    /**
     * \brief Size of the signature buffer in bytes.
     */
    size_t signature_size;
};

/**
 * \struct rse_iak_endorsement_cert_signing_pk_s
 * \brief Structure representing the signing public key used to verify the certificate.
 */
struct rse_iak_endorsement_cert_signing_pk_s {
    /**
     * \brief Pointer to the X-coordinate of the public key.
     */
    uint32_t *public_key_x;

    /**
     * \brief Size of the X-coordinate buffer in bytes.
     */
    size_t public_key_x_size;

    /**
     * \brief Pointer to the Y-coordinate of the public key.
     */
    uint32_t *public_key_y;

    /**
     * \brief Size of the Y-coordinate buffer in bytes.
     */
    size_t public_key_y_size;
};

/**
 * \brief Generates the IAK endorsement certificate using dynamic and provisioned parameters.
 *
 * \param[in] provisioned_params Pointer to the provisioned parameters.
 * \param[in] dynamic_params Pointer to the dynamic platform-specific parameters.
 *
 * \return  Returns a tfm_plat_err_t indicating success or failure.
 */
enum tfm_plat_err_t rse_iak_endorsement_cert_generate(
    struct rse_iak_endorsement_cert_provisioned_params_s *provisioned_params,
    struct rse_iak_endorsement_cert_dynamic_params_s *dynamic_params);

/**
 * \brief Verifies the endorsement certificate using a given signing public key.
 *
 * \param[in] signing_pk Pointer to the signing public key structure.
 *
 * \return  Returns a tfm_plat_err_t indicating success or failure.
 */
enum tfm_plat_err_t
rse_iak_endorsement_cert_verify(struct rse_iak_endorsement_cert_signing_pk_s *signing_pk);

/**
 * \brief Retrieves the generated endorsement certificate and its size.
 *
 * \param[out] cert Pointer to a buffer where the certificate address will be stored.
 * \param[out] cert_size Pointer to a variable where the certificate size will be stored.
 *
 * \return  Returns a tfm_plat_err_t indicating success or failure.
 */
enum tfm_plat_err_t rse_iak_endorsement_cert_get(const uint8_t **cert, size_t *cert_size);

#ifdef __cplusplus
}
#endif

#endif /* __RSE_IAK_ENDORSEMENT_CERT_H__ */
