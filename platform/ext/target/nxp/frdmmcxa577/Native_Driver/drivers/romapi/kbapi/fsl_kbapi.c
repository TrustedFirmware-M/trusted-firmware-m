/*
 * Copyright 2025-2026 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#include "fsl_kbapi.h"
#include "fsl_romapi_tree.h"

/*! @brief Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.romapi_kbapi"
#endif

/*! @brief Interface for bootloader API functions. */
typedef struct _kb_interface
{
    status_t (*kb_init)(kb_session_ref_t **session, const kb_options_t *options);
    status_t (*kb_deinit)(kb_session_ref_t *session);
    status_t (*kb_execute)(kb_session_ref_t *session, const uint8_t *data, uint32_t dataLength);
} kb_interface_t;

#define KB_DRIVER ((const kb_interface_t *)BOOTLOADER_API_TREE_POINTER->kbDriver)

/*******************************************************************************
 * API
 ******************************************************************************/

/* This API is used to initialize bootloader and nboot context necessary to process sb4 file format */
status_t KB_Init(kb_session_ref_t **session, const kb_options_t *options)
{
    assert(BOOTLOADER_API_TREE_POINTER);
    return KB_DRIVER->kb_init(session, options);
}

/* This API is used to release nboot context and finalize sb4 file processing */
status_t KB_Deinit(kb_session_ref_t *session)
{
    assert(BOOTLOADER_API_TREE_POINTER);
    return KB_DRIVER->kb_deinit(session);
}

/* This API is used to decrypt sb4 file and store signed image contents specified by loader command supported
 * while generating sb4 image through Json configuration */
status_t KB_Execute(kb_session_ref_t *session, const uint8_t *data, uint32_t dataLength)
{
    assert(BOOTLOADER_API_TREE_POINTER);
    return KB_DRIVER->kb_execute(session, data, dataLength);
}
