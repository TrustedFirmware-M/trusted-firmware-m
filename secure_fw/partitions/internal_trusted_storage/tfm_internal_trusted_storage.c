/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
#include <string.h>
#include "psa/framework_feature.h"
#if PSA_FRAMEWORK_HAS_MM_IOVEC != 1
#include "cmsis_compiler.h"
#endif
#include "config_tfm.h"
#include "tfm_internal_trusted_storage.h"
#include "tfm_its_req_mngr.h"
#include "tfm_hal_its.h"
#ifdef TFM_PARTITION_PROTECTED_STORAGE
#include "tfm_hal_ps.h"
#endif
#include "flash/its_flash.h"
#include "flash_fs/its_flash_fs.h"
#include "psa_manifest/pid.h"
#include "tfm_its_defs.h"
#include "its_utils.h"
#include "tfm_log_unpriv.h"

#ifdef ITS_ENCRYPTION
#include "its_crypto_interface.h"
#endif

#ifdef TFM_PARTITION_PROTECTED_STORAGE
#include "ps_object_defs.h"
#endif

#ifndef TFM_PARTITION_INTERNAL_TRUSTED_STORAGE
extern uint8_t *p_psa_src_data;
extern uint8_t *p_psa_dest_data;
#endif /* !TFM_PARTITION_INTERNAL_TRUSTED_STORAGE */

static uint8_t g_fid[ITS_FILE_ID_SIZE];
static struct its_flash_fs_file_info_t g_file_info;

#if (PSA_FRAMEWORK_HAS_MM_IOVEC != 1) && defined(TFM_PARTITION_INTERNAL_TRUSTED_STORAGE)
/* Buffer to store asset data from the caller.
 * Note: size must be aligned to the max flash program unit to meet the
 * alignment requirement of the filesystem.
 */
#ifndef ITS_ENCRYPTION
static uint8_t __ALIGNED(4) asset_data[ITS_UTILS_ALIGN(ITS_BUF_SIZE,
                                          ITS_FLASH_MAX_ALIGNMENT)];
#else
static uint8_t __ALIGNED(4) asset_data[ITS_UTILS_ALIGN(ITS_MAX_ASSET_SIZE,
                                              ITS_FLASH_MAX_ALIGNMENT)];
#endif
#endif

#ifdef TFM_PARTITION_INTERNAL_TRUSTED_STORAGE
static struct its_flash_fs_ctx_t fs_ctx_its;
static struct its_flash_fs_config_t fs_cfg_its = {
    .flash_dev = &ITS_FLASH_DEV,
    .program_unit = ITS_FLASH_ALIGNMENT,
    .max_file_size = ITS_UTILS_ALIGN(ITS_MAX_ASSET_SIZE, ITS_FLASH_ALIGNMENT),
    .max_num_files = ITS_NUM_ASSETS + 1, /* Extra file for atomic replacement */
};
#endif /* TFM_PARTITION_INTERNAL_TRUSTED_STORAGE */

#ifdef TFM_PARTITION_PROTECTED_STORAGE
static struct its_flash_fs_ctx_t fs_ctx_ps;
static struct its_flash_fs_config_t fs_cfg_ps = {
    .flash_dev = &PS_FLASH_DEV,
    .program_unit = PS_FLASH_ALIGNMENT,
    .max_file_size = ITS_UTILS_ALIGN(PS_MAX_OBJECT_SIZE, PS_FLASH_ALIGNMENT),
    .max_num_files = PS_MAX_NUM_OBJECTS,
};
#endif

static struct its_flash_fs_ctx_t *get_fs_ctx(int32_t client_id)
{
#ifdef TFM_PARTITION_PROTECTED_STORAGE
#ifndef TFM_PARTITION_INTERNAL_TRUSTED_STORAGE
    (void)client_id;
    return &fs_ctx_ps;
#else
    return (client_id == TFM_SP_PS) ? &fs_ctx_ps : &fs_ctx_its;
#endif /* !TFM_PARTITION_INTERNAL_TRUSTED_STORAGE */
#else
    (void)client_id;
    return &fs_ctx_its;
#endif
}

#ifdef ITS_ENCRYPTION
/* Buffer to store the encrypted asset data and the authentication tag before it
 * is stored in the filesystem.
 */
static uint8_t __ALIGNED(4) enc_asset_data[ITS_UTILS_ALIGN(ITS_MAX_ASSET_SIZE +
                                           TFM_ITS_AUTH_TAG_LENGTH,
                                           ITS_FLASH_MAX_ALIGNMENT)];

static psa_status_t buffer_size_check(int32_t client_id, size_t buffer_size)
{
/* With protected storage no encryption is used */
#ifdef TFM_PARTITION_PROTECTED_STORAGE
    if (client_id != TFM_SP_PS) {
#else
    {
#endif /* TFM_PARTITION_PROTECTED_STORAGE */
        /* When encryption is enabled the whole file needs to fit in the
         * global buffer.
         */
        if (buffer_size > ITS_MAX_ASSET_SIZE) {
            return PSA_ERROR_INVALID_ARGUMENT;
        }
    }
    return PSA_SUCCESS;
}

static psa_status_t tfm_its_crypt_data(int32_t client_id,
                                uint8_t **input,
                                size_t input_size,
                                size_t offset)
{
    psa_status_t status;
#ifdef TFM_PARTITION_PROTECTED_STORAGE
    if (client_id != TFM_SP_PS) {
#else
    {
#endif /* TFM_PARTITION_PROTECTED_STORAGE */
        if (offset != 0) {
            /* If the data will be encrypted the whole file needs to be written */
            return PSA_ERROR_INVALID_ARGUMENT;
        }

        status = tfm_its_crypt_file(&g_file_info,
                                    g_fid,
                                    sizeof(g_fid),
                                    *input,
                                    input_size,
                                    enc_asset_data,
                                    sizeof(enc_asset_data),
                                    true);

        if (status != PSA_SUCCESS) {
            return status;
        }
        *input = enc_asset_data;
    }
    return PSA_SUCCESS;
}

static psa_status_t tfm_its_get_encrypted(int32_t client_id,
                         size_t data_offset,
                         size_t data_size,
                         size_t *p_data_length)
{
    psa_status_t status;

    if (g_file_info.size_max > sizeof(enc_asset_data)) {
            return PSA_ERROR_BUFFER_TOO_SMALL;
    }

    /* When encryption is enabled we need to read the whole file */
    status = its_flash_fs_file_read(get_fs_ctx(client_id),
                                    g_fid,
                                    g_file_info.size_current,
                                    0,
                                    enc_asset_data);
    if (status != PSA_SUCCESS) {
        *p_data_length = 0;
        return status;
    }

    status = tfm_its_crypt_file(&g_file_info,
                                g_fid,
                                sizeof(g_fid),
                                enc_asset_data,
                                g_file_info.size_current,
                                asset_data,
                                sizeof(asset_data),
                                false);
    if (status != PSA_SUCCESS) {
        *p_data_length = 0;
        return status;
    }

    #if (PSA_FRAMEWORK_HAS_MM_IOVEC == 1) /* PSA_FRAMEWORK_HAS_MM_IOVEC */
    memcpy(its_req_mngr_get_vec_base(), asset_data + data_offset, data_size);
    #else
    /* Write asset data to the caller in one go as due to buffer check before
     * it is ensured that all data fit into asset_data
     */
    its_req_mngr_write(asset_data + data_offset, data_size);
    #endif /* PSA_FRAMEWORK_HAS_MM_IOVEC */

    return PSA_SUCCESS;
}
#endif /* ITS_ENCRYPTION */

#ifdef TFM_PARTITION_INTERNAL_TRUSTED_STORAGE
/**
 * \brief Initialise the static ITS filesystem configurations.
 *
 * \return Returns PSA_ERROR_PROGRAMMER_ERROR if there is a configuration error,
 *         and PSA_SUCCESS otherwise.
 */
static psa_status_t init_its_fs_cfg(void)
{
    struct tfm_hal_its_fs_info_t its_fs_info;

    /* Check the compile-time program unit matches the runtime value */
    if (TFM_HAL_ITS_FLASH_DRIVER.GetInfo()->program_unit
        != TFM_HAL_ITS_PROGRAM_UNIT) {
        return PSA_ERROR_PROGRAMMER_ERROR;
    }

    /* Retrieve flash properties from the ITS flash driver */
    fs_cfg_its.sector_size = TFM_HAL_ITS_FLASH_DRIVER.GetInfo()->sector_size;
    fs_cfg_its.erase_val = TFM_HAL_ITS_FLASH_DRIVER.GetInfo()->erased_value;

    /* Retrieve FS parameters from the ITS HAL */
    if (tfm_hal_its_fs_info(&its_fs_info) != TFM_HAL_SUCCESS) {
        return PSA_ERROR_PROGRAMMER_ERROR;
    }

    /* Derive address, block_size and num_blocks from the HAL parameters */
    fs_cfg_its.flash_area_addr = its_fs_info.flash_area_addr;
    fs_cfg_its.block_size = fs_cfg_its.sector_size
                            * its_fs_info.sectors_per_block;
    fs_cfg_its.num_blocks = its_fs_info.flash_area_size / fs_cfg_its.block_size;

    return PSA_SUCCESS;
}
#endif /* TFM_PARTITION_INTERNAL_TRUSTED_STORAGE */

#ifdef TFM_PARTITION_PROTECTED_STORAGE
/**
 * \brief Initialise the static PS filesystem configurations.
 *
 * \return Returns PSA_ERROR_PROGRAMMER_ERROR if there is a configuration error,
 *         and PSA_SUCCESS otherwise.
 */
static psa_status_t init_ps_fs_cfg(void)
{
    struct tfm_hal_ps_fs_info_t ps_fs_info;

    /* Check the compile-time program unit matches the runtime value */
    if (TFM_HAL_PS_FLASH_DRIVER.GetInfo()->program_unit
        != TFM_HAL_PS_PROGRAM_UNIT) {
        return PSA_ERROR_PROGRAMMER_ERROR;
    }

    /* Retrieve flash properties from the PS flash driver */
    fs_cfg_ps.sector_size = TFM_HAL_PS_FLASH_DRIVER.GetInfo()->sector_size;
    fs_cfg_ps.erase_val = TFM_HAL_PS_FLASH_DRIVER.GetInfo()->erased_value;

    /* Retrieve FS parameters from the PS HAL */
    if (tfm_hal_ps_fs_info(&ps_fs_info) != TFM_HAL_SUCCESS) {
        return PSA_ERROR_PROGRAMMER_ERROR;
    }

    /* Derive address, block_size and num_blocks from the HAL parameters */
    fs_cfg_ps.flash_area_addr = ps_fs_info.flash_area_addr;
    fs_cfg_ps.block_size = fs_cfg_ps.sector_size * ps_fs_info.sectors_per_block;
    fs_cfg_ps.num_blocks = ps_fs_info.flash_area_size / fs_cfg_ps.block_size;

    return PSA_SUCCESS;
}
#endif /* TFM_PARTITION_PROTECTED_STORAGE */

psa_status_t tfm_its_init(void)
{
    psa_status_t status = PSA_SUCCESS;

#ifdef TFM_PARTITION_INTERNAL_TRUSTED_STORAGE
    status = init_its_fs_cfg();
    if (status != PSA_SUCCESS) {
        return status;
    }

    /* Initialise the ITS filesystem context */
    status = its_flash_fs_init_ctx(&fs_ctx_its, &fs_cfg_its, &ITS_FLASH_OPS);
    if (status != PSA_SUCCESS) {
        return status;
    }

    /* Prepare the ITS filesystem */
    status = its_flash_fs_prepare(&fs_ctx_its);
#if ITS_CREATE_FLASH_LAYOUT
    /* If ITS_CREATE_FLASH_LAYOUT is set to 1, it indicates that it is required to
     * create a ITS flash layout. ITS service will generate an empty and valid
     * ITS flash layout to store assets. It will erase all data located in the
     * assigned ITS memory area before generating the ITS layout.
     * This flag is required to be set if the ITS memory area is located in
     * non-persistent memory.
     * This flag can be set if the ITS memory area is located in persistent
     * memory without a previous valid ITS flash layout in it. That is the case
     * when it is the first time in the device life that the ITS service is
     * executed.
     */
     if (status != PSA_SUCCESS) {
        /* Remove all data in the ITS memory area and create a valid ITS flash
         * layout in that area.
         */
        INFO_UNPRIV_RAW("Creating an empty ITS flash layout.\n");
        status = its_flash_fs_wipe_all(&fs_ctx_its);
        if (status != PSA_SUCCESS) {
            return status;
        }

        /* Attempt to prepare again */
        status = its_flash_fs_prepare(&fs_ctx_its);
    }
#endif /* ITS_CREATE_FLASH_LAYOUT */
#endif /* TFM_PARTITION_INTERNAL_TRUSTED_STORAGE */

#ifdef TFM_PARTITION_PROTECTED_STORAGE
    /* Check status of ITS initialisation before continuing with PS */
    if (status != PSA_SUCCESS) {
        return status;
    }

    status = init_ps_fs_cfg();
    if (status != PSA_SUCCESS) {
        return status;
    }

    /* Initialise the PS filesystem context */
    status = its_flash_fs_init_ctx(&fs_ctx_ps, &fs_cfg_ps, &PS_FLASH_OPS);
    if (status != PSA_SUCCESS) {
        return status;
    }

    /* Prepare the PS filesystem */
    status = its_flash_fs_prepare(&fs_ctx_ps);
#if PS_CREATE_FLASH_LAYOUT
    /* If PS_CREATE_FLASH_LAYOUT is set to 1, it indicates that it is required to
     * create a PS flash layout. PS service will generate an empty and valid
     * PS flash layout to store assets. It will erase all data located in the
     * assigned PS memory area before generating the PS layout.
     * This flag is required to be set if the PS memory area is located in
     * non-persistent memory.
     * This flag can be set if the PS memory area is located in persistent
     * memory without a previous valid PS flash layout in it. That is the case
     * when it is the first time in the device life that the PS service is
     * executed.
     */
     if (status != PSA_SUCCESS) {
        /* Remove all data in the PS memory area and create a valid PS flash
         * layout in that area.
         */
        INFO_UNPRIV_RAW("Creating an empty PS flash layout.\n");
        status = its_flash_fs_wipe_all(&fs_ctx_ps);
        if (status != PSA_SUCCESS) {
            return status;
        }

        /* Attempt to prepare again */
        status = its_flash_fs_prepare(&fs_ctx_ps);
    }
#endif /* PS_CREATE_FLASH_LAYOUT */
#endif /* TFM_PARTITION_PROTECTED_STORAGE */

    return status;
}

static psa_status_t get_file_info(psa_storage_uid_t uid, int32_t client_id)
{
    /* Check that the UID is valid */
    if (uid == TFM_ITS_INVALID_UID) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    /* Set file id */
    memcpy(g_fid, (const void *)&client_id, sizeof(client_id));
    memcpy(g_fid + sizeof(client_id), (const void *)&uid, sizeof(uid));

    /* Read file info */
    return its_flash_fs_file_get_info(get_fs_ctx(client_id), g_fid,
                                      &g_file_info);
}


static psa_status_t tfm_its_write_data_to_fs(const int32_t client_id,
                                     const uint8_t *fid,
                                     struct its_flash_fs_file_info_t *finfo,
                                     const size_t data_size,
                                     const size_t offset,
                                     uint8_t *data)
{
    psa_status_t status;
    uint8_t *buffer_ptr = data;
#ifdef ITS_ENCRYPTION /* ITS_ENCRYPTION */
    status = tfm_its_crypt_data(client_id, &buffer_ptr, data_size, offset);
    if (status != PSA_SUCCESS) {
        return status;
    }
#endif /* ITS_ENCRYPTION */
    status = its_flash_fs_file_write(get_fs_ctx(client_id),
                                        fid,
                                        &g_file_info,
                                        data_size, offset, buffer_ptr);
    if (status != PSA_SUCCESS) {
        return status;
    }

    return PSA_SUCCESS;
}

psa_status_t tfm_its_set(int32_t client_id,
                         psa_storage_uid_t uid,
                         size_t data_length,
                         psa_storage_create_flags_t create_flags)
{
    psa_status_t status;
#if (PSA_FRAMEWORK_HAS_MM_IOVEC != 1) && defined(TFM_PARTITION_INTERNAL_TRUSTED_STORAGE)
    size_t write_size;
    size_t offset;
#endif

    /* Check that the UID is valid */
    if (uid == TFM_ITS_INVALID_UID) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    /* Check that the create_flags does not contain any unsupported flags */
    if (create_flags & ~(PSA_STORAGE_FLAG_WRITE_ONCE |
                         PSA_STORAGE_FLAG_NO_CONFIDENTIALITY |
                         PSA_STORAGE_FLAG_NO_REPLAY_PROTECTION)) {
        return PSA_ERROR_NOT_SUPPORTED;
    }

#if defined ITS_ENCRYPTION && defined TFM_PARTITION_INTERNAL_TRUSTED_STORAGE
    status = buffer_size_check(client_id, data_length);
    if (status != PSA_SUCCESS) {
        return status;
    }
#endif /* ITS_ENCRYPTION && TFM_PARTITION_INTERNAL_TRUSTED_STORAGE*/

    /* Read file info */
    status = get_file_info(uid, client_id);
    if (status == PSA_SUCCESS) {
        /* If the object exists and has the write once flag set, then it
         * cannot be modified.
         */
        if (g_file_info.flags & PSA_STORAGE_FLAG_WRITE_ONCE) {
            return PSA_ERROR_NOT_PERMITTED;
        }
    } else if (status != PSA_ERROR_DOES_NOT_EXIST) {
        /* If the file does not exist, then do nothing.
         * If other error occurred, return it
         */
        return status;
    }

    g_file_info.size_max = data_length;
    g_file_info.flags = (uint32_t)create_flags |
                        ITS_FLASH_FS_FLAG_CREATE | ITS_FLASH_FS_FLAG_TRUNCATE;


#ifndef TFM_PARTITION_INTERNAL_TRUSTED_STORAGE
    /* Write to the file in the file system
     * No encryption needed as this will be stored in the Protected Storage
     * Partition if ITS partition is not enabled.
     */
    status = its_flash_fs_file_write(get_fs_ctx(client_id), g_fid, &g_file_info,
                                     data_length, 0, p_psa_src_data);
#elif PSA_FRAMEWORK_HAS_MM_IOVEC == 1
    status = tfm_its_write_data_to_fs(client_id,
                                      g_fid,
                                      &g_file_info,
                                      data_length, 0,
                                      its_req_mngr_get_vec_base());
#else
    offset = 0;

    /* Iteratively read data from the caller and write it to the filesystem, in
     * chunks no larger than the size of the asset_data buffer.
     */
    do {
        /* Write as much of the data as will fit in the asset_data buffer */
        write_size = ITS_UTILS_MIN(data_length, sizeof(asset_data));

        /* Read asset data from the caller */
        (void)its_req_mngr_read(asset_data, write_size);

        status = tfm_its_write_data_to_fs(client_id, g_fid, &g_file_info,
                                          write_size, offset, asset_data);

        if (status != PSA_SUCCESS) {
                return status;
        }
        /* Do not create or truncate after the first iteration */
        g_file_info.flags &= ~(ITS_FLASH_FS_FLAG_CREATE | ITS_FLASH_FS_FLAG_TRUNCATE);

        offset += write_size;
        data_length -= write_size;
    } while (data_length > 0);
#endif

    return status;
}

#if (!defined(ITS_ENCRYPTION) || !defined(TFM_PARTITION_INTERNAL_TRUSTED_STORAGE)) || \
    (defined(ITS_ENCRYPTION) && defined(TFM_PARTITION_INTERNAL_TRUSTED_STORAGE) && defined(TFM_PARTITION_PROTECTED_STORAGE))
static psa_status_t tfm_its_get_plain(int32_t client_id,
                         size_t data_offset,
                         size_t data_size,
                         size_t *p_data_length)
{
    psa_status_t status;

#if (PSA_FRAMEWORK_HAS_MM_IOVEC != 1) && defined(TFM_PARTITION_INTERNAL_TRUSTED_STORAGE)
    size_t read_size;
#endif

#ifndef TFM_PARTITION_INTERNAL_TRUSTED_STORAGE
    /* Read file data from the filesystem */
    status = its_flash_fs_file_read(get_fs_ctx(client_id), g_fid, data_size,
                                    data_offset, p_psa_dest_data);
    if (status != PSA_SUCCESS) {
        *p_data_length = 0;
        return status;
    }

#elif (PSA_FRAMEWORK_HAS_MM_IOVEC == 1)
    /* Read file data from the filesystem */
    status = its_flash_fs_file_read(get_fs_ctx(client_id), g_fid, data_size,
                                    data_offset, its_req_mngr_get_vec_base());
    if (status != PSA_SUCCESS) {
        *p_data_length = 0;
        return status;
    }

#else

    /* Iteratively read data from the filesystem and write it to the caller, in
     * chunks no larger than the size of the asset_data buffer.
     */
    do {
        /* Read as much of the data as will fit in the asset_data buffer */
        read_size = ITS_UTILS_MIN(data_size, sizeof(asset_data));

        /* Read file data from the filesystem */
        status = its_flash_fs_file_read(get_fs_ctx(client_id), g_fid, read_size,
                                        data_offset, asset_data);
        if (status != PSA_SUCCESS) {
            *p_data_length = 0;
            return status;
        }

        /* Write asset data to the caller */
        its_req_mngr_write(asset_data, read_size);

        data_offset += read_size;
        data_size -= read_size;
    } while (data_size > 0);
#endif /* TFM_PARTITION_INTERNAL_TRUSTED_STORAGE & PSA_FRAMEWORK_HAS_MM_IOVEC */

    return PSA_SUCCESS;
}
#endif

psa_status_t tfm_its_get(int32_t client_id,
                         psa_storage_uid_t uid,
                         size_t data_offset,
                         size_t data_size,
                         size_t *p_data_length)
{
    psa_status_t status;

#ifdef TFM_PARTITION_TEST_PS
    /* The PS test partition can call tfm_its_get() through PS code. Treat it
     * as if it were PS.
     */
    if (client_id == TFM_SP_PS_TEST) {
        client_id = TFM_SP_PS;
    }
#endif

    /* Check that the UID is valid */
    if (uid == TFM_ITS_INVALID_UID) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

#if defined ITS_ENCRYPTION && defined TFM_PARTITION_INTERNAL_TRUSTED_STORAGE
    status = buffer_size_check(client_id, data_offset + data_size);
    if (status != PSA_SUCCESS) {
        return status;
    }
#endif /* ITS_ENCRYPTION && TFM_PARTITION_INTERNAL_TRUSTED_STORAGE */

    /* Read file info */
    status = get_file_info(uid, client_id);
    if (status != PSA_SUCCESS) {
        return status;
    }

    /* Boundary check the incoming request */
    if (data_offset > g_file_info.size_current) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    /* Copy the object data only from within the file boundary */
    data_size = ITS_UTILS_MIN(data_size,
                              g_file_info.size_current - data_offset);

    /* Update the size of the output data */
    *p_data_length = data_size;

#if defined ITS_ENCRYPTION && defined TFM_PARTITION_INTERNAL_TRUSTED_STORAGE
#if defined TFM_PARTITION_PROTECTED_STORAGE
    /* With protected storage no encryption is used */
    if (client_id == TFM_SP_PS) {
        return tfm_its_get_plain(client_id, data_offset, data_size, p_data_length);
    } else
#endif /* TFM_PARTITION_PROTECTED_STORAGE */
    {
        return tfm_its_get_encrypted(client_id, data_offset, data_size, p_data_length);
    }
#else
    {
        return tfm_its_get_plain(client_id, data_offset, data_size, p_data_length);
    }
#endif /* ITS_ENCRYPTION && TFM_PARTITION_INTERNAL_TRUSTED_STORAGE */
}

psa_status_t tfm_its_get_info(int32_t client_id, psa_storage_uid_t uid,
                              struct psa_storage_info_t *p_info)
{
    psa_status_t status;

    /* Validate and read file info */
    status = get_file_info(uid, client_id);
    if (status != PSA_SUCCESS) {
        return status;
    }

    /* Copy file info to the PSA info struct */
    p_info->capacity = g_file_info.size_current;
    p_info->size = g_file_info.size_current;
    p_info->flags = g_file_info.flags;

    return PSA_SUCCESS;
}

psa_status_t tfm_its_remove(int32_t client_id, psa_storage_uid_t uid)
{
    psa_status_t status;

#ifdef TFM_PARTITION_TEST_PS
    /* The PS test partition can call tfm_its_remove() through PS code. Treat
     * it as if it were PS.
     */
    if (client_id == TFM_SP_PS_TEST) {
        client_id = TFM_SP_PS;
    }
#endif

    /* Validate and read file info */
    status = get_file_info(uid, client_id);
    if (status != PSA_SUCCESS) {
        return status;
    }

    /* If the object exists and has the write once flag set, then it
     * cannot be deleted.
     */
    if (g_file_info.flags & PSA_STORAGE_FLAG_WRITE_ONCE) {
        return PSA_ERROR_NOT_PERMITTED;
    }

    /* Delete old file from the persistent area */
    return its_flash_fs_file_delete(get_fs_ctx(client_id), g_fid);
}
