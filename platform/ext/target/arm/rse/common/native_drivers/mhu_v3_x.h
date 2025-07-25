/*
 * Copyright (c) 2023-2024 Arm Limited
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/**
 * \file mhu_v3_x.h
 * \brief Driver for ARM Message Handling Unit version 3.0
 */

#ifndef __MHU_V3_X_H__
#define __MHU_V3_X_H__

#include <stdint.h>
#include <stdbool.h>
#include <limits.h>

#ifdef __cplusplus
extern "C" {
#endif

#if TFM_UNIQUE_ERROR_CODES == 1
#include "error_codes_mapping.h"
#else
#define MHU_V_3_X_ERROR_BASE 0x1u
#endif /* TFM_UNIQUE_ERROR_CODES */

/* MHU Architecture Major Revision 3 */
#define MHU_MAJOR_REV_V3 (0x2u)
/* MHU Architecture Minor Revision 0 */
#define MHU_MINOR_REV_3_0 (0x0u)

/* MHU Architecture Major Revision offset */
#define MHU_ARCH_MAJOR_REV_OFF (0x4u)
/* MHU Architecture Major Revision mask */
#define MHU_ARCH_MAJOR_REV_MASK (0xfu << MHU_ARCH_MAJOR_REV_OFF)

/* MHU Architecture Minor Revision offset */
#define MHU_ARCH_MINOR_REV_OFF (0x0u)
/* MHU Architecture Minor Revision mask */
#define MHU_ARCH_MINOR_REV_MASK (0xfu << MHU_ARCH_MINOR_REV_OFF)

/* MHUv3 PBX/MBX Operational Request offset */
#define MHU_V3_OP_REQ_OFF (0u)
/* MHUv3 PBX/MBX Operational Request */
#define MHU_V3_OP_REQ (1u << MHU_V3_OP_REQ_OFF)

/**
 * \brief MHUv3 error enumeration types
 */
enum mhu_v3_x_error_t {
    /* No error */
    MHU_V_3_X_ERR_NONE = 0x0u,
    /* Invalid input param in init function */
    MHU_V_3_X_ERR_INIT_INVALID_PARAM = MHU_V_3_X_ERROR_BASE,
    /* MHU Revision not supported error */
    MHU_V_3_X_ERR_INIT_UNSUPPORTED_VERSION,
    /* Invalid input param in get_num_channel function */
    MHU_V_3_X_ERR_GET_NUM_CHANNEL_INVALID_PARAM,
    /* Operation not supported in get_num_channel function */
    MHU_V_3_X_ERR_GET_NUM_CHANNEL_UNSUPPORTED,
    /* Invalid input param in doorbell_clear function */
    MHU_V_3_X_ERR_DOORBELL_CLEAR_INVALID_PARAM,
    /* Invalid input param in doorbell_write function */
    MHU_V_3_X_ERR_DOORBELL_WRITE_INVALID_PARAM,
    /* Invalid input param in doorbell_read function */
    MHU_V_3_X_ERR_DOORBELL_READ_INVALID_PARAM,
    /* Invalid input param in doorbell_mask_set function */
    MHU_V_3_X_ERR_DOORBELL_MASK_SET_INVALID_PARAM,
    /* Invalid input param in doorbell_mask_clear function */
    MHU_V_3_X_ERR_DOORBELL_MASK_CLEAR_INVALID_PARAM,
    /* Invalid input param in doorbell_mask_get function */
    MHU_V_3_X_ERR_DOORBELL_MASK_GET_INVALID_PARAM,
    /* Invalid input param in channel_interrupt_enable function */
    MHU_V_3_X_ERR_INTERRUPT_ENABLE_INVALID_PARAM,
    /* Operation not supported in channel_interrupt_enable function */
    MHU_V_3_X_ERR_INTERRUPT_ENABLE_UNSUPPORTED,
    /* Invalid input param in channel_interrupt_disable function */
    MHU_V_3_X_ERR_INTERRUPT_DISABLE_INVALID_PARAM,
    /* Operation not supported in channel_interrupt_disable function */
    MHU_V_3_X_ERR_INTERRUPT_DISABLE_UNSUPPORTED,
    /* Invalid input param in channel_interrupt_clear function */
    MHU_V_3_X_ERR_INTERRUPT_CLEAR_INVALID_PARAM,
    /* Operation not supported in channel_interrupt_clear function */
    MHU_V_3_X_ERR_INTERRUPT_CLEAR_UNSUPPORTED,
    /* Following entry is to ensure the error code size */
    MHU_V_3_X_ERR_FORCE_UINT_SIZE = UINT_MAX,
};

/**
 * \brief MHUv3 channel types
 */
enum mhu_v3_x_channel_type_t {
    /* Doorbell channel */
    MHU_V3_X_CHANNEL_TYPE_DBCH,
    /* Channel type count */
    MHU_V3_X_CHANNEL_TYPE_COUNT,
};

/**
 * \brief MHUv3 frame types
 */
enum mhu_v3_x_frame_t {
    /* MHUv3 postbox frame */
    MHU_V3_X_PBX_FRAME,
    /* MHUv3 mailbox frame */
    MHU_V3_X_MBX_FRAME,
};

/**
 * \brief MHUv3 device structure
 */
struct mhu_v3_x_dev_t {
    /* Hardware version: 3, must be the first field in the structure */
    uint32_t version;
    /* Base address of the MHUv3 frame */
    const uintptr_t base;
    /* Type of the MHUv3 frame */
    enum mhu_v3_x_frame_t frame;
    /* Minor revision of the MHUv3 */
    uint32_t subversion;
    /* Flag to indicate if the MHUv3 is initialized */
    bool is_initialized;
};

/**
 * \brief Initializes the MHUv3
 *
 * \param[in] dev    MHU device struct \ref mhu_v3_x_dev_t
 *
 * \return Returns error code as specified in \ref mhu_v3_x_error_t
 */
enum mhu_v3_x_error_t mhu_v3_x_driver_init(struct mhu_v3_x_dev_t *dev);

/**
 * \brief Returns the number of channels implemented
 *
 * \param[in]  dev        MHU device struct \ref mhu_v3_x_dev_t
 * \param[in]  ch_type    MHU channel type \ref mhu_v3_x_channel_type_t
 * \param[out] num_ch     Pointer to the variable that will store the value
 *
 * \return Returns error code as specified in \ref mhu_v3_x_error_t
 */
enum mhu_v3_x_error_t mhu_v3_x_get_num_channel_implemented(
     const struct mhu_v3_x_dev_t *dev,
     enum mhu_v3_x_channel_type_t ch_type, uint8_t *num_ch);

/**
 * \brief Clears the doorbell channel
 *
 * \param[in] dev        MHU device struct \ref mhu_v3_x_dev_t
 * \param[in] channel    Channel number
 * \param[in] mask       Mask to be used when clearing the channel
 *
 * \return Returns error code as specified in \ref mhu_v3_x_error_t
 */
enum mhu_v3_x_error_t mhu_v3_x_doorbell_clear(struct mhu_v3_x_dev_t *dev,
     uint8_t channel, uint32_t mask);

/**
 * \brief Write value to a doorbell channel
 *
 * \param[in] dev        MHU device struct \ref mhu_v3_x_dev_t
 * \param[in] channel    Doorbell channel number
 * \param[in] value      Value to be written to the channel
 *
 * \return Returns error code as specified in \ref mhu_v3_x_error_t
 */
enum mhu_v3_x_error_t mhu_v3_x_doorbell_write(struct mhu_v3_x_dev_t *dev,
     uint8_t channel, uint32_t value);

/**
 * \brief Read value from a doorbell channel
 *
 * \param[in]  dev        MHU device struct \ref mhu_v3_x_dev_t
 * \param[in]  channel    Doorbell channel number
 * \param[out] value      Pointer to the variable that will store the value
 *
 * \return Returns error code as specified in \ref mhu_v3_x_error_t
 */
enum mhu_v3_x_error_t mhu_v3_x_doorbell_read(struct mhu_v3_x_dev_t *dev,
     uint8_t channel, uint32_t *value);

/**
 * \brief Set bits in a doorbell channel mask
 *
 * \param[in] dev        MHU device struct \ref mhu_v3_x_dev_t
 * \param[in] channel    Doorbell channel number
 * \param[in] mask       Mask to be set over the doorbell channel
 *
 * \return Returns error code as specified in \ref mhu_v3_x_error_t
 */
enum mhu_v3_x_error_t mhu_v3_x_doorbell_mask_set(
     struct mhu_v3_x_dev_t *dev, uint8_t channel, uint32_t mask);

/**
 * \brief Clear bits in a doorbell channel mask
 *
 * \param[in] dev        MHU device struct \ref mhu_v3_x_dev_t
 * \param[in] channel    Doorbell channel number
 * \param[in] mask       Mask to be cleared over the doorbell channel
 *
 * \return Returns error code as specified in \ref mhu_v3_x_error_t
 */
enum mhu_v3_x_error_t mhu_v3_x_doorbell_mask_clear(
     struct mhu_v3_x_dev_t *dev, uint8_t channel, uint32_t mask);

/**
 * \brief Get the mask of a doorbell channel
 *
 * \param[in]  dev            MHU device struct \ref mhu_v3_x_dev_t
 * \param[in]  channel        Doorbell channel number
 * \param[out] mask_status    Pointer to the variable that will store the value
 *
 * \return Returns error code as specified in \ref mhu_v3_x_error_t
 */
enum mhu_v3_x_error_t mhu_v3_x_doorbell_mask_get(
     struct mhu_v3_x_dev_t *dev, uint8_t channel, uint32_t *mask_status);

/**
 * \brief Enable the channel interrupt
 *
 * \param[in]  dev        MHU device struct \ref mhu_v3_x_dev_t
 * \param[in]  channel    Channel number
 * \param[in]  ch_type    MHU channel type \ref mhu_v3_x_channel_type_t
 *
 * \return Returns error code as specified in \ref mhu_v3_x_error_t
 */
enum mhu_v3_x_error_t mhu_v3_x_channel_interrupt_enable(
     struct mhu_v3_x_dev_t *dev, uint8_t channel,
     enum mhu_v3_x_channel_type_t ch_type);

/**
 * \brief Disable the channel interrupt
 *
 * \param[in]  dev        MHU device struct \ref mhu_v3_x_dev_t
 * \param[in]  channel    Channel number
 * \param[in]  ch_type    MHU channel type \ref mhu_v3_x_channel_type_t
 *
 * \return Returns error code as specified in \ref mhu_v3_x_error_t
 */
enum mhu_v3_x_error_t mhu_v3_x_channel_interrupt_disable(
     struct mhu_v3_x_dev_t *dev, uint8_t channel,
     enum mhu_v3_x_channel_type_t ch_type);

/**
 * \brief Clear the channel interrupt
 *
 * \param[in]  dev        MHU device struct \ref mhu_v3_x_dev_t
 * \param[in]  channel    Channel number
 * \param[in]  ch_type    MHU channel type \ref mhu_v3_x_channel_type_t
 *
 * \return Returns error code as specified in \ref mhu_v3_x_error_t
 */
enum mhu_v3_x_error_t mhu_v3_x_channel_interrupt_clear(
     struct mhu_v3_x_dev_t *dev, uint8_t channel,
     enum mhu_v3_x_channel_type_t ch_type);

#ifdef __cplusplus
}
#endif

#endif /* __MHU_V3_X_H__ */
