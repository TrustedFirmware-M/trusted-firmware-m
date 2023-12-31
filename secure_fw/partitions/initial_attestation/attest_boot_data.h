/*
 * Copyright (c) 2022-2023, Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __ATTEST_BOOT_DATA_H__
#define __ATTEST_BOOT_DATA_H__

#include <stdint.h>
#include "attest.h"
#include "psa/initial_attestation.h"
#include "qcbor/qcbor.h"

#ifdef __cplusplus
extern "C" {
#endif

/*!
 * \brief  Function to encode all the software components
 *
 * The function creates a CBOR array in which 1 item is a SW component. The
 * encoded list of these software components makes up the SW components claim.
 * This encoded array can be stand-alone or part of a map, depending on the
 * \p map_label parameter. The CBOR array is only created if at least 1 SW
 * component has been found.
 *
 * \param[out]  encode_ctx  Pointer to the encoding context
 * \param[in]   map_label   Label/key of the map item to be added to the
 *                          context. If NULL, the SW components are added as a
 *                          stand-alone array
 * \param[out]  cnt         Number of SW component in the encoded array
 *
 * \return Returns error code as specified in \ref psa_attest_err_t
 */
enum psa_attest_err_t
attest_encode_sw_components_array(QCBOREncodeContext *encode_ctx,
                                  const int32_t *map_label,
                                  uint32_t *cnt);

/*!
 * \brief Gets the IAS TLV entries (boot data coming from boot loader) from
 *        shared memory area to service memory area
 *
 * \return Returns error code as specified in \ref psa_attest_err_t
 */
enum psa_attest_err_t attest_boot_data_init(void);

#ifdef __cplusplus
}
#endif

#endif /* __ATTEST_BOOT_DATA_H__ */
