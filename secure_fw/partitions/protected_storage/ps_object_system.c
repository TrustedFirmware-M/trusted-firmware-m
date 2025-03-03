/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 * Copyright (c) 2024 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "ps_object_system.h"

#include <stdbool.h>
#include <stddef.h>
#include <string.h>

#include "cmsis_compiler.h"
#include "psa/internal_trusted_storage.h"
#ifdef PS_ENCRYPTION
#include "ps_encrypted_object.h"
#endif
#include "ps_object_defs.h"
#include "ps_object_table.h"
#include "ps_utils.h"
#include "tfm_ps_req_mngr.h"
#include "tfm_log_unpriv.h"
#include "utilities.h"

#ifndef PS_ENCRYPTION
/* Gets the size of object written to the object system below */
#define PS_OBJECT_SIZE(max_size) (PS_OBJECT_HEADER_SIZE + (max_size))
#define PS_OBJECT_START_POSITION  0
#endif /* PS_ENCRYPTION */

/* Allocate static variables to process objects */
static struct ps_object_t g_ps_object;
static struct ps_obj_table_info_t g_obj_tbl_info;

/**
 * \brief Initialize g_ps_object based on the input parameters and empty data.
 *
 * \param[in]  uid           Unique identifier for the data
 * \param[in]  client_id     Identifier of the asset's owner (client)
 * \param[in]  create_flags  Object create flags
 * \param[in]  size          Object size
 * \param[out] obj           Object to initialize
 *
 */
__attribute__ ((always_inline))
__STATIC_INLINE void ps_init_empty_object(
                                        psa_storage_uid_t uid,
                                        int32_t client_id,
                                        psa_storage_create_flags_t create_flags,
                                        uint32_t size,
                                        struct ps_object_t *obj)
{
    /* Set all object data to 0 */
    (void)memset(obj, PS_DEFAULT_EMPTY_BUFF_VAL, PS_MAX_OBJECT_SIZE);

#ifdef PS_ENCRYPTION
    obj->header.crypto.ref.uid = uid;
    obj->header.crypto.ref.client_id = client_id;
#if PS_AES_KEY_USAGE_LIMIT != 0
    obj->header.crypto.ref.key_gen_nr = ps_object_table_current_gen();
#endif
#else
    /* Initialize object version */
    obj->header.version = 0;
#endif /* PS_ENCRYPTION */

    /* Set object header based on input parameters */
    obj->header.info.max_size = size;
    obj->header.info.create_flags = create_flags;
}

/**
 * \brief Update the object table for the specified object with the content
 *        of g_obj_tbl_info. Also removes the old object table.
 *
 * \param[in] uid         Unique identifier for the data
 * \param[in] client_id   Identifier of the asset's owner (client)
 *
 * \return Returns error code as specified in \ref psa_status_t
 */
static psa_status_t ps_update_table(psa_storage_uid_t uid, int32_t client_id)
{
    psa_status_t err;

    /* Update the table with the new internal ID, etc for the object, and
     * store it in the persistent area.
     */
    err = ps_object_table_set_obj_tbl_info(uid, client_id, &g_obj_tbl_info);
    if (err == PSA_SUCCESS) {
        /* Delete old object table from the persistent area */
        err = ps_object_table_delete_old_table();
    } else {
        /* Remove object as object table is not persistent and propagate
         * object table manipulation error.
         */
        (void)psa_its_remove(g_obj_tbl_info.fid);
    }

    return err;
}

#ifdef PS_ENCRYPTION
#if PS_AES_KEY_USAGE_LIMIT != 0
/**
 * \brief Update the key generation number in g_ps_object and clear
 *        g_obj_tbl_info.num_blocks.
 */
static void ps_switch_key(void)
{
    if (g_ps_object.header.crypto.ref.key_gen_nr == UINT32_MAX) {
        /* We've run out of keys */
        tfm_core_panic();
    }
    g_ps_object.header.crypto.ref.key_gen_nr++;
    g_obj_tbl_info.num_blocks = 0;
}
#endif /* PS_AES_KEY_USAGE_LIMIT == 0 */

/**
 * \brief Check whether the encryption key usage limit (if any) would be
 *        reached after an operation encrypting/decrypting the specified
 *        number of blocks. If so, switch the encryption key.
 *
 * Note that if the key is switched then g_obj_tbl_info.num_blocks will be
 * changed. It is the caller's responsibility to write out the objects,
 * encrypted with the new key, and to ensure that any such change gets
 * reflected in the object table.
 *
 * \param[in] num_blocks  Number of encryption blocks used.
 *
 * \return Returns error code as specified in \ref psa_status_t
 */
static psa_status_t ps_switch_keys_if_necessary(uint32_t num_blocks)
{
    psa_status_t err = PSA_SUCCESS;

/* Only necessary if there's a key usage limit */
#if PS_AES_KEY_USAGE_LIMIT == 0
    (void)num_blocks;
#else
    /* Always need to be able to decrypt the object once more to read it back */
    if (g_obj_tbl_info.num_blocks + num_blocks > PS_AES_KEY_USAGE_LIMIT) {
        ps_switch_key();
        /* Re-store object, using new key */
        err = ps_encrypted_object_write(g_obj_tbl_info.fid, &g_ps_object);
        g_obj_tbl_info.num_blocks += num_blocks;
    }
#endif /* PS_AES_KEY_USAGE_LIMIT == 0 */
    return err;
}
#else
enum read_type_t {
    READ_HEADER_ONLY = 0,
    READ_ALL_OBJECT,
};

/**
 * \brief Reads and validates an object header based on its object table info
 *        stored in g_obj_tbl_info.
 *
 * \param[in] type  Read type as specified in \ref read_type_t
 *
 * \return Returns error code as specified in \ref psa_status_t
 */
static psa_status_t ps_read_object(enum read_type_t type)
{
    psa_status_t err;
    size_t data_length;

    /* Read object header */
    err = psa_its_get(g_obj_tbl_info.fid,
                      PS_OBJECT_START_POSITION,
                      PS_OBJECT_HEADER_SIZE,
                      (void *)&g_ps_object.header,
                      &data_length);
    if (err != PSA_SUCCESS) {
        return err;
    }

    /* As PS encryption support is not enabled, check file ID and version to
     * detect inconsistency after read the object header from flash.
     */
    if (g_ps_object.header.fid != g_obj_tbl_info.fid ||
        g_ps_object.header.version != g_obj_tbl_info.version) {
        return PSA_ERROR_DATA_CORRUPT;
    }

    /* Read object data if any */
    if (type == READ_ALL_OBJECT && g_ps_object.header.info.current_size > 0) {
        err = psa_its_get(g_obj_tbl_info.fid,
                          PS_OBJECT_HEADER_SIZE,
                          g_ps_object.header.info.current_size,
                          (void *)g_ps_object.data,
                          &data_length);
        if (err != PSA_SUCCESS) {
            return err;
        }
    }

    return PSA_SUCCESS;
}

/**
 * \brief Writes an object based on its object table info stored in
 *        g_obj_tbl_info and the input parameter.
 *
 * \param[in] wrt_size  Number of bytes to write
 *
 * \return Returns error code as specified in \ref psa_status_t
 */
static psa_status_t ps_write_object(uint32_t wrt_size)
{
    /* Add object identification and increase object version */
    g_ps_object.header.fid = g_obj_tbl_info.fid;
    g_ps_object.header.version++;

    /* Save object version to be stored in the object table */
    g_obj_tbl_info.version = g_ps_object.header.version;

    return psa_its_set(g_obj_tbl_info.fid, wrt_size,
                       (const void *)&g_ps_object,
                       PSA_STORAGE_FLAG_NONE);
}

#endif /* !PS_ENCRYPTION */

/**
 * \brief Writes g_ps_object, encrypting it if necessary. Also uses g_obj_tbl_info.
 *
 * \param[in]  uid       Unique identifier for the data
 * \param[in]  client_id Identifier of the asset's owner (client)
 * \param[out] p_blocks  New number of encryption blocks needed to read/write
 *                       the object, if changed.
 *
 * \return Returns error code as specified in \ref psa_status_t
 */
static psa_status_t ps_store_object(psa_storage_uid_t uid, int32_t client_id, uint32_t *p_blocks)
{
    psa_status_t err;
#ifndef PS_ENCRYPTION
    uint32_t wrt_size;
#endif

#ifdef PS_ENCRYPTION
#if PS_AES_KEY_USAGE_LIMIT == 0
    err = ps_encrypted_object_write(g_obj_tbl_info.fid, &g_ps_object);
#else
    uint32_t num_blocks = ps_encrypted_object_blocks(g_ps_object.header.info.current_size);

    /* Switch to new key if this write will not leave enough blocks to read the object */
    if (2 * num_blocks >= PS_AES_KEY_USAGE_LIMIT - g_obj_tbl_info.num_blocks) {
        ps_switch_key();
    }

    err = ps_encrypted_object_write(g_obj_tbl_info.fid, &g_ps_object);
    g_obj_tbl_info.num_blocks += num_blocks;
    /* If the write succeeded, the number of encryption blocks needed has changed */
    if (err == PSA_SUCCESS) {
        *p_blocks = num_blocks;
    }
#endif /* PS_AES_KEY_USAGE_LIMIT == 0 */
#else
    wrt_size = PS_OBJECT_SIZE(g_ps_object.header.info.current_size);

    /* Write g_ps_object */
    err = ps_write_object(wrt_size);
#endif /* PS_ENCRYPTION */

    return err;
}

psa_status_t ps_system_prepare(void)
{
    psa_status_t err;

    /* Reuse the allocated g_ps_object.data to store a temporary object table
     * data to be validate inside the function.
     * The stored date will be cleaned up when the g_ps_object.data will
     * be used for the first time in the object system.
     */
    err = ps_object_table_init(g_ps_object.data);

#ifdef PS_ENCRYPTION
#if PS_AES_KEY_USAGE_LIMIT != 0
    /* Sanity check that the largest allowed object can actually be written and read back */
    if (2 * ps_encrypted_object_blocks(PS_MAX_ASSET_SIZE) > PS_AES_KEY_USAGE_LIMIT) {
        ERROR_UNPRIV_RAW("Config error: PS_AES_KEY_USAGE_LIMIT prevents storing largest allowable PS object\n");
        return PSA_ERROR_GENERIC_ERROR;
    }
    /* Ensure that we can never overflow a uint32_t block counter */
    if (ps_encrypted_object_blocks(PS_MAX_ASSET_SIZE) > UINT32_MAX - PS_AES_KEY_USAGE_LIMIT) {
        ERROR_UNPRIV_RAW("Config error: PS_AES_KEY_USAGE_LIMIT too large to safely count key usage\n");
        return PSA_ERROR_GENERIC_ERROR;
    }
#endif
    g_obj_tbl_info.tag = g_ps_object.header.crypto.ref.tag;
#endif

    return err;
}

psa_status_t ps_object_read(psa_storage_uid_t uid, int32_t client_id,
                            uint32_t offset, uint32_t size,
                            size_t *p_data_length)
{
    psa_status_t err;
#ifdef PS_ENCRYPTION
    uint32_t num_blocks;
#endif

    /* Retrieve the object information from the object table if the object
     * exists.
     */
    err = ps_object_table_get_obj_tbl_info(uid, client_id, &g_obj_tbl_info);
    if (err != PSA_SUCCESS) {
        return err;
    }

    /* Read object */
#ifdef PS_ENCRYPTION
    g_ps_object.header.crypto.ref.uid = uid;
    g_ps_object.header.crypto.ref.client_id = client_id;

    err = ps_encrypted_object_read(g_obj_tbl_info.fid, &g_ps_object, &num_blocks);
#if PS_AES_KEY_USAGE_LIMIT != 0
    g_obj_tbl_info.num_blocks += num_blocks;
#endif
#else
    /* Read object header */
    err = ps_read_object(READ_ALL_OBJECT);
#endif /* PS_ENCRYPTION */
    if (err != PSA_SUCCESS) {
        goto update_table_and_return;
    }

    /* Boundary check the incoming request */
    if (offset > g_ps_object.header.info.current_size) {
       err = PSA_ERROR_INVALID_ARGUMENT;
       goto switch_keys_and_return;
    }

    size = PS_UTILS_MIN(size,
                        g_ps_object.header.info.current_size - offset);

    /* Copy the decrypted object data to the output buffer */
    ps_req_mngr_write_asset_data(g_ps_object.data + offset, size);

    *p_data_length = size;

switch_keys_and_return:
#ifdef PS_ENCRYPTION
    if (err == PSA_SUCCESS) {
        err = ps_switch_keys_if_necessary(num_blocks);
    } else {
        (void)ps_switch_keys_if_necessary(num_blocks);
    }
#endif

update_table_and_return:
#if defined(PS_ENCRYPTION) && (PS_AES_KEY_USAGE_LIMIT != 0)
    if (err == PSA_SUCCESS) {
        err = ps_update_table(uid, client_id);
    } else {
        (void)ps_update_table(uid, client_id);
    }
#endif

    /* Remove data stored in the object before leaving the function */
    (void)memset(&g_ps_object, PS_DEFAULT_EMPTY_BUFF_VAL,
                 PS_MAX_OBJECT_SIZE);

    return err;
}

psa_status_t ps_object_create(psa_storage_uid_t uid, int32_t client_id,
                              psa_storage_create_flags_t create_flags,
                              uint32_t size)
{
    psa_status_t err;
    uint32_t old_fid = PS_INVALID_FID;
    uint32_t fid_am_reserved = 1;
    uint32_t num_blocks;
    bool object_exists = false;

    /* Boundary check the incoming request */
    if (size > PS_MAX_ASSET_SIZE) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    /* Retrieve the object information from the object table if the object
     * exists.
     */
    err = ps_object_table_get_obj_tbl_info(uid, client_id, &g_obj_tbl_info);
    if (err == PSA_SUCCESS) {
        object_exists = true;
#ifdef PS_ENCRYPTION
        /* Read the object */
        g_ps_object.header.crypto.ref.uid = uid;
        g_ps_object.header.crypto.ref.client_id = client_id;

        err = ps_encrypted_object_read(g_obj_tbl_info.fid, &g_ps_object, &num_blocks);
#if PS_AES_KEY_USAGE_LIMIT != 0
        g_obj_tbl_info.num_blocks += num_blocks;
#endif /* PS_AES_KEY_USAGE_LIMIT */
#else
        /* Read the object header */
        err = ps_read_object(READ_HEADER_ONLY);
#endif /* PS_ENCRYPTION */
        if (err != PSA_SUCCESS) {
            goto update_table_and_return;
        }

        /* If the object exists and has the write once flag set, then it cannot
         * be modified.
         */
        if (g_ps_object.header.info.create_flags
            & PSA_STORAGE_FLAG_WRITE_ONCE) {
            err = PSA_ERROR_NOT_PERMITTED;
            goto switch_keys_and_return;
        }

        /* Update the create flags and max object size */
        g_ps_object.header.info.create_flags = create_flags;
        g_ps_object.header.info.max_size = size;

        /* Save old file ID */
        old_fid = g_obj_tbl_info.fid;
    } else if (err == PSA_ERROR_DOES_NOT_EXIST) {
        /* If the object does not exist, then initialize it based on the input
         * arguments and empty content. Requests 2 FIDs to prevent exhaustion.
         */
        fid_am_reserved = 2;
        ps_init_empty_object(uid, client_id, create_flags, size, &g_ps_object);
#if PS_AES_KEY_USAGE_LIMIT != 0
        g_obj_tbl_info.num_blocks = 0;
#endif
    } else {
        return err;
    }

    /* Update the object data */
    err = ps_req_mngr_read_asset_data(g_ps_object.data, size);
    if (err != PSA_SUCCESS) {
        goto switch_keys_and_return;
    }

    /* Get new file ID */
    err = ps_object_table_get_free_fid(fid_am_reserved,
                                       &g_obj_tbl_info.fid);
    if (err != PSA_SUCCESS) {
        goto switch_keys_and_return;
    }

    /* Update the current object size */
    g_ps_object.header.info.current_size = size;

    err = ps_store_object(uid, client_id, &num_blocks);
    if (err != PSA_SUCCESS) {
        /* If we failed to store the updated object, we need to keep the old version */
        if (old_fid != PS_INVALID_FID) {
            g_obj_tbl_info.fid = old_fid;
        }
        goto switch_keys_and_return;
    }

switch_keys_and_return:
#ifdef PS_ENCRYPTION
    /* In the normal case, we will switch keys before writing, if necessary.
     * This is here for the error path when we didn't already write the object
     */
    if ((old_fid != PS_INVALID_FID) && (err != PSA_SUCCESS)) {
        (void)ps_switch_keys_if_necessary(num_blocks);
    }
#endif /* PS_ENCRYPTION */

update_table_and_return:
    if (err == PSA_SUCCESS) {
        err = ps_update_table(uid, client_id);
    } else {
        /* If the object didn't already exist and we failed to add it, no need to update the table */
        if (object_exists) {
            (void)ps_update_table(uid, client_id);
        }
    }

    if ((err == PSA_SUCCESS) && (old_fid != PS_INVALID_FID)) {
        /* Remove old object */
        err = psa_its_remove(old_fid);
    }

    /* Remove data stored in the object before leaving the function */
    (void)memset(&g_ps_object, PS_DEFAULT_EMPTY_BUFF_VAL, PS_MAX_OBJECT_SIZE);

    return err;
}

psa_status_t ps_object_write(psa_storage_uid_t uid, int32_t client_id,
                             uint32_t offset, uint32_t size)
{
    psa_status_t err;
    uint32_t old_fid = PS_INVALID_FID;
    uint32_t num_blocks;

    /* Retrieve the object information from the object table if the object
     * exists.
     */
    err = ps_object_table_get_obj_tbl_info(uid, client_id, &g_obj_tbl_info);
    if (err != PSA_SUCCESS) {
        return err;
    }

    /* Read the object */
#ifdef PS_ENCRYPTION
    g_ps_object.header.crypto.ref.uid = uid;
    g_ps_object.header.crypto.ref.client_id = client_id;

    err = ps_encrypted_object_read(g_obj_tbl_info.fid, &g_ps_object, &num_blocks);
#if PS_AES_KEY_USAGE_LIMIT != 0
    g_obj_tbl_info.num_blocks += num_blocks;
#endif
#else
    err = ps_read_object(READ_ALL_OBJECT);
#endif /* PS_ENCRYPTION */
    if (err != PSA_SUCCESS) {
        goto update_table_and_return;
    }

    /* If the object has the write once flag set, then it cannot be modified. */
    if (g_ps_object.header.info.create_flags & PSA_STORAGE_FLAG_WRITE_ONCE) {
        err = PSA_ERROR_NOT_PERMITTED;
        goto switch_keys_and_return;
    }

    /* Offset must not be larger than the object's current size to prevent gaps
     * being created in the object data.
     */
    if (offset > g_ps_object.header.info.current_size) {
        err = PSA_ERROR_INVALID_ARGUMENT;
        goto switch_keys_and_return;
    }

    /* Boundary check the incoming request */
    err = ps_utils_check_contained_in(g_ps_object.header.info.max_size,
                                      offset, size);
    if (err != PSA_SUCCESS) {
        goto switch_keys_and_return;
    }

    /* Update the object data */
    err = ps_req_mngr_read_asset_data(g_ps_object.data + offset, size);
    if (err != PSA_SUCCESS) {
        goto switch_keys_and_return;
    }

    /* Save old file ID */
    old_fid = g_obj_tbl_info.fid;

    /* Get new file ID */
    err = ps_object_table_get_free_fid(1, &g_obj_tbl_info.fid);
    if (err != PSA_SUCCESS) {
        goto switch_keys_and_return;
    }

    /* Update the current object size if necessary */
    if ((offset + size) > g_ps_object.header.info.current_size) {
        g_ps_object.header.info.current_size = offset + size;
    }

    err = ps_store_object(uid, client_id, &num_blocks);
    if (err != PSA_SUCCESS) {
        /* We couldn't write the new data, so keep the old */
        g_obj_tbl_info.fid = old_fid;
        goto switch_keys_and_return;
    }

switch_keys_and_return:
#ifdef PS_ENCRYPTION
    /* In the normal case, we will switch keys before writing, if necessary.
     * This is here for the error path when we didn't already write the object
     */
    if (err != PSA_SUCCESS) {
        (void)ps_switch_keys_if_necessary(num_blocks);
    }
#endif /* PS_ENCRYPTION */

update_table_and_return:
    if (err == PSA_SUCCESS) {
        err = ps_update_table(uid, client_id);
    } else {
        (void)ps_update_table(uid, client_id);
    }

    if (err == PSA_SUCCESS) {
        /* Remove old object */
        err = psa_its_remove(old_fid);
    }

    /* Remove data stored in the object before leaving the function */
    (void)memset(&g_ps_object, PS_DEFAULT_EMPTY_BUFF_VAL,
                 PS_MAX_OBJECT_SIZE);

    return err;
}

psa_status_t ps_object_get_info(psa_storage_uid_t uid, int32_t client_id,
                                struct psa_storage_info_t *info)
{
    psa_status_t err;
#ifdef PS_ENCRYPTION
    uint32_t num_blocks;
#endif

    /* Retrieve the object information from the object table if the object
     * exists.
     */
    err = ps_object_table_get_obj_tbl_info(uid, client_id, &g_obj_tbl_info);
    if (err != PSA_SUCCESS) {
        return err;
    }

#ifdef PS_ENCRYPTION
    g_ps_object.header.crypto.ref.uid = uid;
    g_ps_object.header.crypto.ref.client_id = client_id;

    err = ps_encrypted_object_read(g_obj_tbl_info.fid, &g_ps_object, &num_blocks);
#if PS_AES_KEY_USAGE_LIMIT != 0
    g_obj_tbl_info.num_blocks += num_blocks;
#endif
#else
    err = ps_read_object(READ_HEADER_ONLY);
#endif /* PS_ENCRYPTION */
    if (err != PSA_SUCCESS) {
        goto update_table_and_return;
    }

    /* Copy PS object info to the PSA PS info struct */
    info->size = g_ps_object.header.info.current_size;
    info->capacity = g_ps_object.header.info.max_size;
    info->flags = g_ps_object.header.info.create_flags;

#ifdef PS_ENCRYPTION
    err = ps_switch_keys_if_necessary(num_blocks);
#endif /* PS_ENCRYPTION */

update_table_and_return:
#ifdef PS_ENCRYPTION
#if PS_AES_KEY_USAGE_LIMIT != 0
    if (err == PSA_SUCCESS) {
        err = ps_update_table(uid, client_id);
    } else {
        (void)ps_update_table(uid, client_id);
    }
#endif
#endif

    /* Remove data stored in the object before leaving the function */
    (void)memset(&g_ps_object, PS_DEFAULT_EMPTY_BUFF_VAL,
                 PS_MAX_OBJECT_SIZE);

    return err;
}

psa_status_t ps_object_delete(psa_storage_uid_t uid, int32_t client_id)
{
    psa_status_t err;
#ifdef PS_ENCRYPTION
    uint32_t num_blocks;
#endif

    /* Retrieve the object information from the object table if the object
     * exists.
     */
    err = ps_object_table_get_obj_tbl_info(uid, client_id, &g_obj_tbl_info);
    if (err != PSA_SUCCESS) {
        return err;
    }

#ifdef PS_ENCRYPTION
    g_ps_object.header.crypto.ref.uid = uid;
    g_ps_object.header.crypto.ref.client_id = client_id;

    err = ps_encrypted_object_read(g_obj_tbl_info.fid, &g_ps_object, &num_blocks);
#if PS_AES_KEY_USAGE_LIMIT != 0
    g_obj_tbl_info.num_blocks += num_blocks;
#endif
#else
    err = ps_read_object(READ_HEADER_ONLY);
#endif /* PS_ENCRYPTION */
    if (err != PSA_SUCCESS) {
        goto update_table_and_return;
    }

    /* Check that the write once flag is not set */
    if (g_ps_object.header.info.create_flags & PSA_STORAGE_FLAG_WRITE_ONCE) {
        err = PSA_ERROR_NOT_PERMITTED;
        goto switch_keys_and_return;
    }

    /* Delete object from the table and stores the table in the persistent
     * area.
     */
    err = ps_object_table_delete_object(uid, client_id);
    if (err != PSA_SUCCESS) {
        goto switch_keys_and_return;
    }

#if PS_AES_KEY_USAGE_LIMIT != 0
    /* Ensure that the key will change if this object is ever re-created */
    if (g_ps_object.header.crypto.ref.key_gen_nr >= ps_object_table_current_gen()) {
        ps_object_table_set_gen(g_ps_object.header.crypto.ref.key_gen_nr + 1);
    }
#endif

    /* Delete old object table from the persistent area */
    err = ps_object_table_delete_old_table();
    if (err != PSA_SUCCESS) {
        goto switch_keys_and_return;
    }

    /* Remove old object */
    err = psa_its_remove(g_obj_tbl_info.fid);

switch_keys_and_return:
#ifdef PS_ENCRYPTION
    /* If the object isn't actually deleted, we may need to switch keys */
    if (err != PSA_SUCCESS) {
        (void)ps_switch_keys_if_necessary(num_blocks);
    }
#endif

update_table_and_return:
#ifdef PS_ENCRYPTION
#if PS_AES_KEY_USAGE_LIMIT != 0
    if (err != PSA_SUCCESS) {
        (void)ps_update_table(uid, client_id);
    }
#endif
#endif

    /* Remove data stored in the object before leaving the function */
    (void)memset(&g_ps_object, PS_DEFAULT_EMPTY_BUFF_VAL,
                 PS_MAX_OBJECT_SIZE);

    return err;
}

psa_status_t ps_system_wipe_all(void)
{
    /* This function may get called as a corrective action
     * if a system level security violation is detected.
     * This could be asynchronous to normal system operation
     * and state of the ps system lock is unknown. Hence
     * this function doesn't block on the lock and directly
     * moves to erasing the flash instead.
     */
    return ps_object_table_create();
}
