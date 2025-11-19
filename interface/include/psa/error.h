/*
 * Copyright (c) 2019-2025, Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

/**
 * \file psa/error.h
 * \brief Standard error codes for the SPM and RoT Services
 */

#ifndef __PSA_ERROR_H__
#define __PSA_ERROR_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* If #PSA_SUCCESS is already defined, it means that #psa_status_t
 * is also defined in an external header, so prevent its multiple
 * definition.
 */
#ifndef PSA_SUCCESS
typedef int32_t psa_status_t;
#endif

/* >= 1 is reserved for Success error codes which are API-specific (RoT services) */
#define PSA_SUCCESS                     ((psa_status_t)0)
/* -1 to -128 is reserved for API-specific (RoT services) error codes */
#define PSA_ERROR_PROGRAMMER_ERROR      ((psa_status_t)-129)
#define PSA_ERROR_CONNECTION_REFUSED    ((psa_status_t)-130)
#define PSA_ERROR_CONNECTION_BUSY       ((psa_status_t)-131)
#define PSA_ERROR_GENERIC_ERROR         ((psa_status_t)-132)
#define PSA_ERROR_NOT_PERMITTED         ((psa_status_t)-133)
#define PSA_ERROR_NOT_SUPPORTED         ((psa_status_t)-134)
#define PSA_ERROR_INVALID_ARGUMENT      ((psa_status_t)-135)
#define PSA_ERROR_INVALID_HANDLE        ((psa_status_t)-136)
#define PSA_ERROR_BAD_STATE             ((psa_status_t)-137)
#define PSA_ERROR_BUFFER_TOO_SMALL      ((psa_status_t)-138)
#define PSA_ERROR_ALREADY_EXISTS        ((psa_status_t)-139)
#define PSA_ERROR_DOES_NOT_EXIST        ((psa_status_t)-140)
#define PSA_ERROR_INSUFFICIENT_MEMORY   ((psa_status_t)-141)
#define PSA_ERROR_INSUFFICIENT_STORAGE  ((psa_status_t)-142)
#define PSA_ERROR_INSUFFICIENT_DATA     ((psa_status_t)-143)
#define PSA_ERROR_SERVICE_FAILURE       ((psa_status_t)-144)
#define PSA_ERROR_COMMUNICATION_FAILURE ((psa_status_t)-145)
#define PSA_ERROR_STORAGE_FAILURE       ((psa_status_t)-146)
#define PSA_ERROR_HARDWARE_FAILURE      ((psa_status_t)-147)
/* -148 is reserved for PSA Certified APIs */
#define PSA_ERROR_INVALID_SIGNATURE     ((psa_status_t)-149)
/* -150 is reserved for PSA Certified APIs */
#define PSA_ERROR_CORRUPTION_DETECTED   ((psa_status_t)-151)
#define PSA_ERROR_DATA_CORRUPT          ((psa_status_t)-152)
#define PSA_ERROR_DATA_INVALID          ((psa_status_t)-153)
/* -154 to -247 is reserved for PSA Certified APIs */
#define PSA_OPERATION_INCOMPLETE ((psa_status_t) - 248)
/* -249 to -256 is reserved for the SPM implementation */
/* <= -257 is reserved for API-specific (RoT services) error codes */

#ifdef __cplusplus
}
#endif

#endif /* __PSA_ERROR_H__ */
