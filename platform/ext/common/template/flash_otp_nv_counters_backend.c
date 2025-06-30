/*
 * Copyright (c) 2021-2023, Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

/* NOTE: For the security of the protected storage system, the bootloader
 * rollback protection, and the protection of cryptographic material it is
 * CRITICAL to use an internal (in-die) persistent memory for the implementation
 * of the OTP_NV_COUNTERS flash area.
 */

#include "flash_otp_nv_counters_backend.h"

#include "tfm_plat_defs.h"
#include "Driver_Flash.h"
#include "flash_layout.h"

#include <string.h>

#if defined(OTP_WRITEABLE)
static enum tfm_plat_err_t create_or_restore_layout(void);
#endif

#if OTP_NV_COUNTERS_RAM_EMULATION

static struct flash_otp_nv_counters_region_t otp_nv_ram_buf = {0};

enum tfm_plat_err_t read_otp_nv_counters_flash(uint32_t offset, void *data, uint32_t cnt)
{
    memcpy(data, ((uint8_t *)&otp_nv_ram_buf) + offset, cnt);

    return TFM_PLAT_ERR_SUCCESS;
}

enum tfm_plat_err_t init_otp_nv_counters_flash(void)
{
    enum tfm_plat_err_t err = TFM_PLAT_ERR_SUCCESS;

    if (otp_nv_ram_buf.init_value != OTP_NV_COUNTERS_INITIALIZED) {
#if defined(OTP_WRITEABLE)
        err = create_or_restore_layout();
#else
        err = TFM_PLAT_ERR_SYSTEM_ERR;
#endif
    }
    return err;
}

#if defined(OTP_WRITEABLE)
static enum tfm_plat_err_t create_or_restore_layout(void)
{
    memset(&otp_nv_ram_buf, 0, sizeof(otp_nv_ram_buf));
    otp_nv_ram_buf.init_value = OTP_NV_COUNTERS_INITIALIZED;
    return TFM_PLAT_ERR_SUCCESS;
}

enum tfm_plat_err_t write_otp_nv_counters_flash(uint32_t offset, const void *data, uint32_t cnt)
{
    memcpy(((uint8_t *)&otp_nv_ram_buf) + offset, data, cnt);

    return TFM_PLAT_ERR_SUCCESS;
}
#endif /* defined(OTP_WRITEABLE)*/

#else /* OTP_NV_COUNTERS_RAM_EMULATION */
/* Valid entries for data item width */
static const uint32_t data_width_byte[] = {
    sizeof(uint8_t),
    sizeof(uint16_t),
    sizeof(uint32_t),
};

#if defined(OTP_WRITEABLE)
static enum tfm_plat_err_t make_backup(void);
#endif

/* Compilation time checks to be sure the defines are well defined */
#ifndef TFM_OTP_NV_COUNTERS_AREA_ADDR
#error "TFM_OTP_NV_COUNTERS_AREA_ADDR must be defined in flash_layout.h"
#endif

#if defined(OTP_WRITEABLE)
    #ifndef TFM_OTP_NV_COUNTERS_BACKUP_AREA_ADDR
    #error "TFM_OTP_NV_COUNTERS_BACKUP_AREA_ADDR must be defined in flash_layout.h"
    #endif
#endif

#ifndef TFM_OTP_NV_COUNTERS_AREA_SIZE
#error "TFM_OTP_NV_COUNTERS_AREA_SIZE must be defined in flash_layout.h"
#endif

#if defined(OTP_WRITEABLE)
    #ifndef TFM_OTP_NV_COUNTERS_SECTOR_SIZE
    #error "TFM_OTP_NV_COUNTERS_SECTOR_SIZE must be defined in flash_layout.h"
    #endif
#endif
#ifndef OTP_NV_COUNTERS_FLASH_DEV
    #ifndef TFM_HAL_ITS_FLASH_DRIVER
    #error "OTP_NV_COUNTERS_FLASH_DEV or TFM_HAL_ITS_FLASH_DRIVER must be defined in flash_layout.h"
    #else
    #define OTP_NV_COUNTERS_FLASH_DEV TFM_HAL_ITS_FLASH_DRIVER
    #endif
#endif

/* Default flash block size is either the PROGRAM_UNIT if it is > 128, or if the
 * program unit is < 128, then it is the closest multiple of the PROGRAM_UNIT to
 * 128. The aim of this is to keep the block size reasonable, to avoid large
 * amounts of read/write calls, while also keeping sensible alignment.
 */
#ifndef OTP_NV_COUNTERS_WRITE_BLOCK_SIZE
#define OTP_NV_COUNTERS_WRITE_BLOCK_SIZE (TFM_HAL_ITS_PROGRAM_UNIT > 128 ? \
                                          TFM_HAL_ITS_PROGRAM_UNIT : \
                                          (128 / TFM_HAL_ITS_PROGRAM_UNIT) * TFM_HAL_ITS_PROGRAM_UNIT)
#endif /* OTP_NV_COUNTERS_WRITE_BLOCK_SIZE */

#if (TFM_OTP_NV_COUNTERS_SECTOR_SIZE % OTP_NV_COUNTERS_WRITE_BLOCK_SIZE != 0) || \
    (OTP_NV_COUNTERS_WRITE_BLOCK_SIZE % TFM_HAL_ITS_PROGRAM_UNIT != 0)
#error "OTP_NV_COUNTERS_WRITE_BLOCK_SIZE has wrong alignment"
#endif
/* End of compilation time checks to be sure the defines are well defined */

#if defined(OTP_WRITEABLE)
static uint8_t block[OTP_NV_COUNTERS_WRITE_BLOCK_SIZE];
#endif

/* Import the CMSIS flash device driver */
extern ARM_DRIVER_FLASH OTP_NV_COUNTERS_FLASH_DEV;

enum tfm_plat_err_t read_otp_nv_counters_flash(uint32_t offset, void *data, uint32_t cnt)
{
    int32_t err;
    ARM_FLASH_CAPABILITIES DriverCapabilities;
    uint8_t data_width;
    uint32_t remaining_cnt, read_cnt;
    uint8_t temp_buffer[sizeof(uint32_t)];

    DriverCapabilities = OTP_NV_COUNTERS_FLASH_DEV.GetCapabilities();
    data_width = data_width_byte[DriverCapabilities.data_width];

    if (offset % data_width) {
        return TFM_PLAT_ERR_INVALID_INPUT;
    }
    remaining_cnt = cnt;
    read_cnt = 0;
    if (remaining_cnt) {
        err = OTP_NV_COUNTERS_FLASH_DEV.ReadData(
                                        TFM_OTP_NV_COUNTERS_AREA_ADDR + offset,
                                        data,
                                        cnt / data_width);
        if (err < 0) {
            return TFM_PLAT_ERR_SYSTEM_ERR;
        }
    }
    read_cnt += (cnt / data_width) * data_width;
    remaining_cnt -= read_cnt;
    if (remaining_cnt) {
        err = OTP_NV_COUNTERS_FLASH_DEV.ReadData(
                            TFM_OTP_NV_COUNTERS_AREA_ADDR + offset + read_cnt,
                            temp_buffer,
                            1);
        if (err < 0) {
            return TFM_PLAT_ERR_SYSTEM_ERR;
        }
        memcpy((uint8_t *)data + read_cnt, temp_buffer, remaining_cnt);
    }
    return TFM_PLAT_ERR_SUCCESS;
}

enum tfm_plat_err_t init_otp_nv_counters_flash(void)
{
    enum tfm_plat_err_t err = TFM_PLAT_ERR_SUCCESS;
    uint32_t init_value;
    uint32_t swap_count;

    if ((TFM_OTP_NV_COUNTERS_AREA_SIZE) < sizeof(struct flash_otp_nv_counters_region_t)) {
        return TFM_PLAT_ERR_SYSTEM_ERR;
    }

    err = (enum tfm_plat_err_t)OTP_NV_COUNTERS_FLASH_DEV.Initialize(NULL);
    if (err != ARM_DRIVER_OK) {
        return TFM_PLAT_ERR_SYSTEM_ERR;
    }

    err = read_otp_nv_counters_flash(offsetof(struct flash_otp_nv_counters_region_t, init_value),
            &init_value, sizeof(init_value));
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return err;
    }

    err = read_otp_nv_counters_flash(offsetof(struct flash_otp_nv_counters_region_t, swap_count),
            &swap_count, sizeof(swap_count));
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return err;
    }


    if (init_value != OTP_NV_COUNTERS_INITIALIZED ||
        (swap_count == 0 || swap_count == UINT32_MAX)) {
#if defined(OTP_WRITEABLE)
        err = create_or_restore_layout();
    }
    else
    {
        uint32_t backup_swap_count;

        err = read_otp_nv_counters_flash(offsetof(struct flash_otp_nv_counters_region_t, swap_count)
                + TFM_OTP_NV_COUNTERS_AREA_SIZE,
                &backup_swap_count, sizeof(backup_swap_count));
        if (err != TFM_PLAT_ERR_SUCCESS) {
            return err;
        }

        if (backup_swap_count == 0 || backup_swap_count == UINT32_MAX ||
            backup_swap_count < swap_count ||
            (backup_swap_count == UINT32_MAX - 1 && swap_count == 1)) {
            err = make_backup();
            if (err != TFM_PLAT_ERR_SUCCESS) {
                return err;
            }
        }
#else
        err = TFM_PLAT_ERR_SYSTEM_ERR;
#endif
    }

    return err;
}

#if defined(OTP_WRITEABLE)
static inline uint32_t round_down(uint32_t num, uint32_t boundary)
{
    return num - (num % boundary);
}

static inline uint32_t round_up(uint32_t num, uint32_t boundary)
{
    return (num + boundary - 1) - ((num + boundary - 1) % boundary);
}

static enum tfm_plat_err_t erase_flash_region(size_t start, size_t size)
{
    enum tfm_plat_err_t err = TFM_PLAT_ERR_SUCCESS;
    size_t idx;

    if ((start % TFM_OTP_NV_COUNTERS_SECTOR_SIZE) != 0) {
        return TFM_PLAT_ERR_INVALID_INPUT;
    }

    for (idx = round_down(start, TFM_OTP_NV_COUNTERS_SECTOR_SIZE);
         idx < start + size;
         idx += TFM_OTP_NV_COUNTERS_SECTOR_SIZE) {
        err = (enum tfm_plat_err_t)OTP_NV_COUNTERS_FLASH_DEV.EraseSector(idx);
        if (err != ARM_DRIVER_OK) {
            return TFM_PLAT_ERR_SYSTEM_ERR;
        }
    }

    return err;
}

static enum tfm_plat_err_t copy_flash_region(size_t from, size_t to, size_t size)
{
    int32_t err;
    size_t copy_size;
    size_t idx;
    size_t end;

    end = size;
    ARM_FLASH_CAPABILITIES DriverCapabilities;
    uint8_t data_width;

    DriverCapabilities = OTP_NV_COUNTERS_FLASH_DEV.GetCapabilities();
    data_width = data_width_byte[DriverCapabilities.data_width];

    for(idx = 0; idx < end; idx += copy_size) {
        copy_size = (idx + sizeof(block)) <= end ? sizeof(block) : end - idx;

        err = OTP_NV_COUNTERS_FLASH_DEV.ReadData(from + idx, block, copy_size / data_width);
        if (err < 0) {
            return TFM_PLAT_ERR_SYSTEM_ERR;
        }

        err = OTP_NV_COUNTERS_FLASH_DEV.ProgramData(to + idx, block, copy_size / data_width);
        if (err < 0) {
            return TFM_PLAT_ERR_SYSTEM_ERR;
        }
    }
    return TFM_PLAT_ERR_SUCCESS;
}

static enum tfm_plat_err_t make_backup(void)
{
    enum tfm_plat_err_t err = TFM_PLAT_ERR_SUCCESS;

    err = erase_flash_region(TFM_OTP_NV_COUNTERS_BACKUP_AREA_ADDR,
                             TFM_OTP_NV_COUNTERS_AREA_SIZE);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return err;
    }

    err = copy_flash_region(TFM_OTP_NV_COUNTERS_AREA_ADDR,
                            TFM_OTP_NV_COUNTERS_BACKUP_AREA_ADDR,
                            TFM_OTP_NV_COUNTERS_AREA_SIZE);

    return err;
}

static enum tfm_plat_err_t copy_data_into_block(uint32_t data_offset,
                                                size_t data_size,
                                                const uint8_t *data,
                                                uint32_t block_offset,
                                                size_t block_size,
                                                uint8_t *block_ptr)
{
    uint32_t copy_start_offset;
    uint32_t copy_end_offset;

    /* Check if any of our data needs to be copied into this buf */
    if (data_offset + data_size > block_offset &&
        data_offset < block_offset + block_size) {
        if (data_offset > block_offset) {
            copy_start_offset = data_offset;
        } else {
            copy_start_offset = block_offset;
        }

        if (data_offset + data_size > block_offset + block_size) {
            copy_end_offset = block_offset + block_size;
        } else {
            copy_end_offset = data_offset + data_size;
        }

        memcpy(block_ptr + (copy_start_offset - block_offset),
               data + (copy_start_offset - data_offset),
               copy_end_offset - copy_start_offset);
    }

    return TFM_PLAT_ERR_SUCCESS;
}

enum tfm_plat_err_t write_otp_nv_counters_flash(uint32_t offset, const void *data, uint32_t cnt)
{
    enum tfm_plat_err_t err = TFM_PLAT_ERR_SUCCESS;
    size_t copy_size;
    size_t erase_start_offset;
    size_t erase_end_offset;
    size_t swap_count_erase_start_offset;
    size_t swap_count_program_block_start_offset;
    size_t idx;
    uint32_t swap_count;
    uint32_t swap_count_buf_size = TFM_HAL_ITS_PROGRAM_UNIT > sizeof(swap_count) ?
        TFM_HAL_ITS_PROGRAM_UNIT : sizeof(swap_count);

    erase_start_offset = round_down(offset, TFM_OTP_NV_COUNTERS_SECTOR_SIZE);
    erase_end_offset = round_up(offset + cnt, TFM_OTP_NV_COUNTERS_SECTOR_SIZE);

    swap_count_erase_start_offset =
        round_down(offsetof(struct flash_otp_nv_counters_region_t, swap_count),
                   TFM_OTP_NV_COUNTERS_SECTOR_SIZE);

    swap_count_program_block_start_offset =
        round_down(offsetof(struct flash_otp_nv_counters_region_t, swap_count),
                   TFM_HAL_ITS_PROGRAM_UNIT);

    if (erase_end_offset > TFM_OTP_NV_COUNTERS_AREA_SIZE) {
        /* Erase is beyond the TFM_OTP_NV_COUNTERS_AREA */
        return TFM_PLAT_ERR_SYSTEM_ERR;
    }

    ARM_FLASH_CAPABILITIES DriverCapabilities;
    uint8_t data_width;

    DriverCapabilities = OTP_NV_COUNTERS_FLASH_DEV.GetCapabilities();
    data_width = data_width_byte[DriverCapabilities.data_width];

    /* read the swap_count now, to make life easier when writing it later */
    err = (enum tfm_plat_err_t)OTP_NV_COUNTERS_FLASH_DEV.ReadData(
            TFM_OTP_NV_COUNTERS_BACKUP_AREA_ADDR +
            offsetof(struct flash_otp_nv_counters_region_t, swap_count),
            &swap_count, sizeof(swap_count) / data_width);
    if (err < 0) {
        return TFM_PLAT_ERR_SYSTEM_ERR;
    }

    swap_count += 1;
    if (swap_count == UINT32_MAX) {
        swap_count = 1;
    }

    /* If it's not part of the sectors that are being erased, first erase the
     * sector with the swap_count flag.
     */
    if (erase_end_offset <= swap_count_erase_start_offset) {
        err = erase_flash_region(TFM_OTP_NV_COUNTERS_AREA_ADDR +
                                 swap_count_erase_start_offset,
                                 TFM_OTP_NV_COUNTERS_SECTOR_SIZE);
        if (err != TFM_PLAT_ERR_SUCCESS) {
            return err;
        }
    }

    /* Erase the region we want to write */
    err = erase_flash_region(TFM_OTP_NV_COUNTERS_AREA_ADDR + erase_start_offset,
                             erase_end_offset - erase_start_offset);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return err;
    }

    /* Don't write the swap count, as this is done at the end */
    if (erase_end_offset > swap_count_program_block_start_offset) {
        erase_end_offset = swap_count_program_block_start_offset;
    }

    for (idx = erase_start_offset; idx < erase_end_offset; idx += copy_size) {
        if ((idx + sizeof(block)) <= erase_end_offset) {
            copy_size = sizeof(block);
        } else {
             copy_size = erase_end_offset - idx;
        }

        err = (enum tfm_plat_err_t)OTP_NV_COUNTERS_FLASH_DEV.ReadData(
                TFM_OTP_NV_COUNTERS_BACKUP_AREA_ADDR + idx, block,
                copy_size / data_width);
        if (err < 0) {
            return TFM_PLAT_ERR_SYSTEM_ERR;
        }

        err = copy_data_into_block(offset, cnt, data, idx, copy_size, block);
        if (err != TFM_PLAT_ERR_SUCCESS) {
            return err;
        }

        uint32_t num_items = copy_size / data_width;

        err = (enum tfm_plat_err_t)OTP_NV_COUNTERS_FLASH_DEV.ProgramData(
                TFM_OTP_NV_COUNTERS_AREA_ADDR + idx, block, num_items);
        if (err < 0) {
            return TFM_PLAT_ERR_SYSTEM_ERR;
        }

        /* When err is positive it contains the number of data items
         * successfully programmed. Check that every byte of
         * programming succeeded.
         */
        if (err > 0 && err != num_items) {
            return TFM_PLAT_ERR_SYSTEM_ERR;
        }
    }

    /* If we've not already restored most of the last sector (except the swap
     * count), do it now. */
    if (erase_end_offset < swap_count_program_block_start_offset) {
        err = copy_flash_region(
                TFM_OTP_NV_COUNTERS_BACKUP_AREA_ADDR + swap_count_erase_start_offset,
                TFM_OTP_NV_COUNTERS_AREA_ADDR + swap_count_erase_start_offset,
                swap_count_program_block_start_offset - swap_count_erase_start_offset);
        if (err != TFM_PLAT_ERR_SUCCESS) {
            return err;
        }
    }

    /* Copy the last program-unit. This _may_ contain the data that we needed to
     * write on platforms that have large program-units, so attempt to write
     * into the buffer still (and let copy_data_into_block() check if it needs
     * to actually copy).
     */
    err = (enum tfm_plat_err_t)OTP_NV_COUNTERS_FLASH_DEV.ReadData(
            TFM_OTP_NV_COUNTERS_BACKUP_AREA_ADDR + swap_count_program_block_start_offset,
            block, swap_count_buf_size / data_width);
    if (err < 0) {
        return TFM_PLAT_ERR_SYSTEM_ERR;
    }

    err = copy_data_into_block(offset, cnt, data,
                               swap_count_program_block_start_offset,
                               swap_count_buf_size, block);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return err;
    }

    err = copy_data_into_block(
            offsetof(struct flash_otp_nv_counters_region_t, swap_count),
            sizeof(swap_count), (uint8_t *)&swap_count,
            swap_count_program_block_start_offset, swap_count_buf_size, block);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return err;
    }

    uint32_t num_items = swap_count_buf_size / data_width;

    err = (enum tfm_plat_err_t)OTP_NV_COUNTERS_FLASH_DEV.ProgramData(
            TFM_OTP_NV_COUNTERS_AREA_ADDR + swap_count_program_block_start_offset,
            block, num_items);
    if (err < 0) {
        return TFM_PLAT_ERR_SYSTEM_ERR;
    }

    /* When err is positive it contains the number of data items
     * successfully programmed. Check that every byte of
     * programming succeeded.
     */
    if (err > 0 && err != num_items) {
        return TFM_PLAT_ERR_SYSTEM_ERR;
    }

    err = make_backup();
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return err;
    }
    return err;
}

static enum tfm_plat_err_t restore_backup(void)
{
    enum tfm_plat_err_t err = TFM_PLAT_ERR_SUCCESS;

    err = erase_flash_region(TFM_OTP_NV_COUNTERS_AREA_ADDR,
                             TFM_OTP_NV_COUNTERS_AREA_SIZE);
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return err;
    }

    err = copy_flash_region(TFM_OTP_NV_COUNTERS_BACKUP_AREA_ADDR,
                            TFM_OTP_NV_COUNTERS_AREA_ADDR,
                            TFM_OTP_NV_COUNTERS_AREA_SIZE);

    return err;
}

static enum tfm_plat_err_t create_or_restore_layout(void)
{
    enum tfm_plat_err_t err = TFM_PLAT_ERR_SUCCESS;
    uint32_t init_value;
    uint32_t swap_count;
    uint32_t backup_init_value;
    uint32_t backup_swap_count;
    size_t idx;
    size_t end;
    size_t copy_size;
    ARM_FLASH_CAPABILITIES DriverCapabilities;
    uint8_t data_width;

    DriverCapabilities = OTP_NV_COUNTERS_FLASH_DEV.GetCapabilities();
    data_width = data_width_byte[DriverCapabilities.data_width];

    err = read_otp_nv_counters_flash(offsetof(struct flash_otp_nv_counters_region_t, init_value)
            + TFM_OTP_NV_COUNTERS_AREA_SIZE,
            &backup_init_value, sizeof(init_value));
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return err;
    }
    err = read_otp_nv_counters_flash(offsetof(struct flash_otp_nv_counters_region_t, swap_count)
            + TFM_OTP_NV_COUNTERS_AREA_SIZE,
            &backup_swap_count, sizeof(swap_count));
    if (err != TFM_PLAT_ERR_SUCCESS) {
        return err;
    }

    if (backup_init_value == OTP_NV_COUNTERS_INITIALIZED &&
        /* valid backup, restore */
        backup_swap_count != 0 && backup_swap_count != UINT32_MAX)  {
        err = restore_backup();
        if (err != TFM_PLAT_ERR_SUCCESS) {
            return err;
        }
    } else {
        /* No valid layouts, create from scratch */
        err = erase_flash_region(TFM_OTP_NV_COUNTERS_AREA_ADDR,
                TFM_OTP_NV_COUNTERS_AREA_SIZE);
        if (err != TFM_PLAT_ERR_SUCCESS) {
            return err;
        }

        memset(block, 0, sizeof(block));
        end = TFM_OTP_NV_COUNTERS_AREA_SIZE;
        for(idx = 0; idx < end; idx += copy_size) {
            copy_size = (idx + sizeof(block)) <= end ? sizeof(block) : end - idx;

            err = (enum tfm_plat_err_t)OTP_NV_COUNTERS_FLASH_DEV.ProgramData(TFM_OTP_NV_COUNTERS_AREA_ADDR + idx,
                    block, copy_size / data_width);
            if (err < 0) {
                return TFM_PLAT_ERR_SYSTEM_ERR;
            }
        }

        err = make_backup();
        if (err != TFM_PLAT_ERR_SUCCESS) {
            return err;
        }

        init_value = OTP_NV_COUNTERS_INITIALIZED;
        err = write_otp_nv_counters_flash(offsetof(struct flash_otp_nv_counters_region_t, init_value),
                &init_value, sizeof(init_value));
        if (err != ARM_DRIVER_OK) {
            return TFM_PLAT_ERR_SYSTEM_ERR;
        }

        swap_count = 1;
        err = write_otp_nv_counters_flash(offsetof(struct flash_otp_nv_counters_region_t, swap_count),
                &swap_count, sizeof(swap_count));
        if (err != ARM_DRIVER_OK) {
            return TFM_PLAT_ERR_SYSTEM_ERR;
        }
    }
    return err;
}
#endif /*  OTP_WRITEABLE */

#endif /* OTP_NV_COUNTERS_RAM_EMULATION */
