/*
 * Copyright (c) 2023 Arm Limited
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

#include "mhu_v3_x.h"

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

/**
 * \brief Postbox control page structure
 */
struct _mhu_v3_x_pbx_ctrl_reg_t {
    /* Offset: 0x000 (R/ ) Postbox Block Identifier */
    const volatile uint32_t mhu_blk_id;
    /* Offset: 0x004 (R/ ) Reserved */
    const volatile uint8_t reserved_0[0x10 - 0x04];
    /* Offset: 0x010 (R/ ) Postbox Feature Support 0 */
    const volatile uint32_t pbx_feat_spt0;
    /* Offset: 0x014 (R/ ) Postbox Feature Support 1 */
    const volatile uint32_t pbx_feat_spt1;
    /* Offset: 0x018 (R/ ) Reserved */
    const volatile uint8_t reserved_1[0x20 - 0x18];
    /* Offset: 0x020 (R/ ) Postbox Doorbell Channel Configuration 0 */
    const volatile uint32_t pbx_dbch_cfg0;
    /* Offset: 0x024 (R/ ) Reserved */
    const volatile uint8_t reserved_2[0x30 - 0x24];
    /* Offset: 0x030 (R/ ) Postbox FIFO Channel Configuration 0 */
    const volatile uint32_t pbx_ffch_cfg0;
    /* Offset: 0x034 (R/ ) Reserved */
    const volatile uint8_t reserved_3[0x40 - 0x34];
    /* Offset: 0x040 (R/ ) Postbox Fast Channel Configuration 0 */
    const volatile uint32_t pbx_fch_cfg0;
    /* Offset: 0x044 (R/ ) Reserved */
    const volatile uint8_t reserved_4[0x100 - 0x44];
    /* Offset: 0x100 (R/W) Postbox control */
    volatile uint32_t pbx_ctrl;
    /* Offset: 0x164 (R/ ) Reserved */
    const volatile uint8_t reserved_5[0x400 - 0x104];
    /*
     * Offset: 0x400 (R/ ) Postbox Doorbell Channel Interrupt Status n, where
     * n is 0 - 3.
     */
    const volatile uint32_t pbx_dbch_int_st[4];
    /*
     * Offset: 0x410 (R/ ) Postbox FIFO Channel <n> Interrupt Status n, where n
     * is 0 - 1.
     */
    const volatile uint32_t pbx_ffch_int_st[2];
    /* Offset: 0x418 (R/ ) Reserved */
    const uint8_t reserved_6[0xFC8 - 0x418];
    /* Offset: 0xFC8 (R/ ) Postbox Implementer Identification Register */
    const volatile uint32_t iidr;
    /* Offset: 0xFCC (R/ ) Postbox Architecture Identification Register */
    const volatile uint32_t aidr;
    /*
     * Offset: 0xFD0 (R/ ) Postbox Implementation Defined Identification
     * Register n, where n is 0 - 11.
     */
    const volatile uint32_t impl_def_id[12];
};

/**
 * \brief Postbox doorbell channel window page structure
 */
struct _mhu_v3_x_pbx_pdbcw_reg_t {
    /* Offset: 0x000 (R/ ) Postbox Doorbell Channel Window Status */
    const volatile uint32_t pdbcw_st;
    /* Offset: 0x004 (R/ ) Reserved */
    const uint8_t reserved_0[0xC - 0x4];
    /* Offset: 0x00C ( /W) Postbox Doorbell Channel Window Set */
    volatile uint32_t pdbcw_set;
    /* Offset: 0x010 (R/ ) Postbox Doorbell Channel Window Interrupt Status */
    const volatile uint32_t pdbcw_int_st;
    /* Offset: 0x014 ( /W) Postbox Doorbell Channel Window Interrupt Clear */
    volatile uint32_t pdbcw_int_clr;
    /* Offset: 0x018 (R/W) Postbox Doorbell Channel Window Interrupt Enable */
    volatile uint32_t pdbcw_int_en;
    /* Offset: 0x01C (R/W) Postbox Doorbell Channel Window Control */
    volatile uint32_t pdbcw_ctrl;
};

/**
 * \brief Postbox structure
 */
struct _mhu_v3_x_pbx {
    /* Postbox Control */
    struct _mhu_v3_x_pbx_ctrl_reg_t pbx_ctrl_page;
    /* Postbox Doorbell Channel Window */
    struct _mhu_v3_x_pbx_pdbcw_reg_t pdbcw_page;
};

/**
 * \brief Mailbox control page structure
 */
struct _mhu_v3_x_mbx_ctrl_reg_t {
    /* Offset: 0x000 (R/ ) Mailbox Block Identifier */
    const volatile uint32_t mhu_blk_id;
    /* Offset: 0x004 (R/ ) Reserved */
    const volatile uint8_t reserved_0[0x10 - 0x04];
    /* Offset: 0x010 (R/ ) Mailbox Feature Support 0 */
    const volatile uint32_t mbx_feat_spt0;
    /* Offset: 0x014 (R/ ) Mailbox Feature Support 1 */
    const volatile uint32_t mbx_feat_spt1;
    /* Offset: 0x018 (R/ ) Reserved */
    const volatile uint8_t reserved_1[0x20 - 0x18];
    /* Offset: 0x020 (R/ ) Mailbox Doorbell Channel Configuration 0 */
    const volatile uint32_t mbx_dbch_cfg0;
    /* Offset: 0x024 (R/ ) Reserved */
    const volatile uint8_t reserved_2[0x30 - 0x24];
    /* Offset: 0x030 (R/ ) Mailbox FIFO Channel Configuration 0 */
    const volatile uint32_t mbx_ffch_cfg0;
    /* Offset: 0x034 (R/ ) Reserved */
    const volatile uint8_t reserved_4[0x40 - 0x34];
    /* Offset: 0x040 (R/ ) Mailbox Fast Channel Configuration 0 */
    const volatile uint32_t mbx_fch_cfg0;
    /* Offset: 0x044 (R/ ) Reserved */
    const volatile uint8_t reserved_5[0x100 - 0x44];
    /* Offset: 0x100 (R/W) Mailbox control */
    volatile uint32_t mbx_ctrl;
    /* Offset: 0x104 (R/ ) Reserved */
    const volatile uint8_t reserved_6[0x140 - 0x104];
    /* Offset: 0x140 (R/W) Mailbox Fast Channel control */
    volatile uint32_t mbx_fch_ctrl;
    /* Offset: 0x144 (R/W) Mailbox Fast Channel Group Interrupt Enable */
    volatile uint32_t mbx_fcg_int_en;
    /* Offset: 0x148 (R/ ) Reserved */
    const volatile uint8_t reserved_7[0x400 - 0x148];
    /*
     * Offset: 0x400 (R/ ) Mailbox Doorbell Channel Interrupt Status n, where
     * n = 0 - 3.
     */
    const volatile uint32_t mbx_dbch_int_st[4];
    /*
     * Offset: 0x410 (R/ ) Mailbox FIFO Channel Interrupt Status n, where
     * n = 0 - 1.
     */
    const volatile uint32_t mbx_ffch_int_st[2];
    /* Offset: 0x418 (R/ ) Reserved */
    const volatile uint8_t reserved_8[0x470 - 0x418];
    /* Offset: 0x470 (R/ ) Mailbox Fast Channel Group Interrupt Status */
    const volatile uint32_t mbx_fcg_int_st;
    /* Offset: 0x474 (R/ ) Reserved */
    const volatile uint8_t reserved_9[0x480 - 0x474];
    /*
     * Offset: 0x480 (R/ ) Mailbox Fast Channel Group <n> Interrupt Status,
     * where n = 0 - 31.
     */
    const volatile uint32_t mbx_fch_grp_int_st[32];
    /* Offset: 0x500 (R/ ) Reserved */
    const volatile uint8_t reserved_10[0xFC8 - 0x500];
    /* Offset: 0xFC8 (R/ ) Mailbox Implementer Identification Register */
    const volatile uint32_t iidr;
    /* Offset: 0xFCC (R/ ) Mailbox Architecture Identification Register */
    const volatile uint32_t aidr;
    /*
     * Offset: 0xFD0 (R/ ) Mailbox Implementation Defined Identification
     * Register n, where n is 0 - 11.
     */
    const volatile uint32_t impl_def_id[12];
};

/**
 * \brief Mailbox doorbell channel window page structure
 */
struct _mhu_v3_x_mbx_mdbcw_reg_t {
    /* Offset: 0x000 (R/ ) Mailbox Doorbell Channel Window Status */
    const volatile uint32_t mdbcw_st;
    /* Offset: 0x004 (R/ ) Mailbox Doorbell Channel Window Status Masked */
    const volatile uint32_t mdbcw_st_msk;
    /* Offset: 0x008 ( /W) Mailbox Doorbell Channel Window Clear */
    volatile uint32_t mdbcw_clr;
    /* Offset: 0x00C (R/ ) Reserved */
    const volatile uint8_t reserved_0[0x10 - 0x0C];
    /* Offset: 0x010 (R/ ) Mailbox Doorbell Channel Window Mask Status */
    const volatile uint32_t mdbcw_msk_st;
    /* Offset: 0x014 ( /W) Mailbox Doorbell Channel Window Mask Set */
    volatile uint32_t mdbcw_msk_set;
    /* Offset: 0x018 ( /W) Mailbox Doorbell Channel Window Mask Clear */
    volatile uint32_t mdbcw_msk_clr;
    /* Offset: 0x01C (R/W) Mailbox Doorbell Channel Window Control */
    volatile uint32_t mdbcw_ctrl;
};

/**
 * \brief Mailbox structure
 */
struct _mhu_v3_x_mbx {
   /* Mailbox control */
   struct _mhu_v3_x_mbx_ctrl_reg_t mbx_ctrl_page;
   /* Mailbox Doorbell Channel Window */
   struct _mhu_v3_x_mbx_mdbcw_reg_t mdbcw_page;
};

/**
 * \brief MHUv3 frame type
 */
union _mhu_v3_x_frame_t {
    /* Postbox Frame */
    struct _mhu_v3_x_pbx pbx_frame;
    /* Mailbox Frame */
    struct _mhu_v3_x_mbx mbx_frame;
};

/**
 * \brief Enables the doorbell channel to contribute to combined interrupt
 *
 * \param[in] dev        MHU device struct \ref mhu_v3_x_dev_t
 * \param[in] channel    Channel number
 *
 * \return Nothing
 *
 * \note For sender channels, transfer acknowledge event interrupt is also
 *       enabled.
 */
static void _mhu_v3_x_doorbell_interrupt_enable(
    const struct mhu_v3_x_dev_t *dev, uint8_t channel)
{
    union _mhu_v3_x_frame_t *p_mhu;

    p_mhu = (union _mhu_v3_x_frame_t *)dev->base;

    if(dev->frame == MHU_V3_X_PBX_FRAME) {
        struct _mhu_v3_x_pbx_pdbcw_reg_t *pdbcw_reg;
        pdbcw_reg = (struct _mhu_v3_x_pbx_pdbcw_reg_t *)
            &(p_mhu->pbx_frame.pdbcw_page);

        /*
         * Enable this doorbell channel to generate interrupts for transfer
         * acknowledge events.
         */
        pdbcw_reg[channel].pdbcw_int_en = 0x1;

        /*
         * Enable this doorbell channel to contribute to the PBX combined
         * interrupt.
         */
        pdbcw_reg[channel].pdbcw_ctrl = 0x1;
    } else {
        struct _mhu_v3_x_mbx_mdbcw_reg_t *mdbcw_reg;
        mdbcw_reg = (struct _mhu_v3_x_mbx_mdbcw_reg_t *)
            &(p_mhu->mbx_frame.mdbcw_page);

        /*
         * Enable this doorbell channel to contribute to the MBX combined
         * interrupt.
         */
        mdbcw_reg[channel].mdbcw_ctrl = 0x1;
    }
}

/**
 * \brief Disables the doorbell channel from contributing to combined interrupt
 *
 * \param[in] dev        MHU device struct \ref mhu_v3_x_dev_t
 * \param[in] channel    Channel number
 *
 * \return Nothing
 *
 * \note For sender channels, transfer acknowledge event interrupt is also
 *       disabled.
 */
static void _mhu_v3_x_doorbell_interrupt_disable(
    const struct mhu_v3_x_dev_t *dev, uint8_t channel)
{
    union _mhu_v3_x_frame_t *p_mhu;

    p_mhu = (union _mhu_v3_x_frame_t *)dev->base;

    if(dev->frame == MHU_V3_X_PBX_FRAME) {
        struct _mhu_v3_x_pbx_pdbcw_reg_t *pdbcw_reg;
        pdbcw_reg = (struct _mhu_v3_x_pbx_pdbcw_reg_t *)
            &(p_mhu->pbx_frame.pdbcw_page);

        /* Clear channel transfer acknowledge event interrupt */
        pdbcw_reg[channel].pdbcw_int_clr = 0x1;

        /* Disable channel transfer acknowledge event interrupt */
        pdbcw_reg[channel].pdbcw_int_en &= ~(0x1);

        /*
         * Disable this doorbell channel from contributing to the PBX combined
         * interrupt.
         */
        pdbcw_reg[channel].pdbcw_ctrl &= ~(0x1);
    } else {
        struct _mhu_v3_x_mbx_mdbcw_reg_t *mdbcw_reg;
        mdbcw_reg = (struct _mhu_v3_x_mbx_mdbcw_reg_t *)
            &(p_mhu->mbx_frame.mdbcw_page);

        /*
         * Disable this doorbell channel from contributing to the MBX combined
         * interrupt.
         */
        mdbcw_reg[channel].mdbcw_ctrl &= ~(0x1);
    }
}

/**
 * \brief Clears the doorbell channel transfer acknowledge event interrupt
 *
 * \param[in] dev        MHU device struct \ref mhu_v3_x_dev_t
 * \param[in] channel    Channel number
 *
 * \return Nothing
 */
static void _mhu_v3_x_doorbell_interrupt_clear(
    const struct mhu_v3_x_dev_t *dev, uint8_t channel)
{
    union _mhu_v3_x_frame_t *p_mhu;
    struct _mhu_v3_x_pbx_pdbcw_reg_t *pdbcw_reg;

    p_mhu = (union _mhu_v3_x_frame_t *)dev->base;
    pdbcw_reg = (struct _mhu_v3_x_pbx_pdbcw_reg_t *)&(p_mhu->
            pbx_frame.pdbcw_page);

    /* Clear channel transfer acknowledge event interrupt */
    pdbcw_reg[channel].pdbcw_int_clr = 0x1;
}

enum mhu_v3_x_error_t mhu_v3_x_driver_init(struct mhu_v3_x_dev_t *dev)
{
    uint32_t aidr = 0;
    uint8_t mhu_major_rev;
    union _mhu_v3_x_frame_t *p_mhu;

    if (dev == NULL) {
        return MHU_V_3_X_ERR_INIT_INVALID_PARAM;
    }

    /* Return if already initialized */
    if (dev->is_initialized) {
        return MHU_V_3_X_ERR_NONE;
    }

    p_mhu = (union _mhu_v3_x_frame_t *)dev->base;

    /* Read revision from MHU hardware */
    if (dev->frame == MHU_V3_X_MBX_FRAME) {
        aidr = p_mhu->mbx_frame.mbx_ctrl_page.aidr;
    } else {
        aidr = p_mhu->pbx_frame.pbx_ctrl_page.aidr;
    }

    /* Read the MHU Architecture Major Revision */
    mhu_major_rev =
        ((aidr & MHU_ARCH_MAJOR_REV_MASK) >> MHU_ARCH_MAJOR_REV_OFF);

    /* Return error if the MHU major revision is not 3 */
    if (mhu_major_rev != MHU_MAJOR_REV_V3) {
        /* Unsupported MHU version */
        return MHU_V_3_X_ERR_INIT_UNSUPPORTED_VERSION;
    }

    /* Read the MHU Architecture Minor Revision */
    dev->subversion =
        ((aidr & MHU_ARCH_MINOR_REV_MASK) >> MHU_ARCH_MINOR_REV_OFF);

    /* Return error if the MHU minor revision is not 0 */
    if (dev->subversion != MHU_MINOR_REV_3_0) {
        /* Unsupported subversion */
        return MHU_V_3_X_ERR_INIT_UNSUPPORTED_VERSION;
    }

    /* Initialize the Postbox/Mailbox to remain in operational state */
    if (dev->frame == MHU_V3_X_MBX_FRAME) {
        p_mhu->mbx_frame.mbx_ctrl_page.mbx_ctrl |= MHU_V3_OP_REQ;
    } else{
        p_mhu->pbx_frame.pbx_ctrl_page.pbx_ctrl |= MHU_V3_OP_REQ;
    }

    dev->is_initialized = true;

    return MHU_V_3_X_ERR_NONE;
}

enum mhu_v3_x_error_t mhu_v3_x_get_num_channel_implemented(
    const struct mhu_v3_x_dev_t *dev,
    enum mhu_v3_x_channel_type_t ch_type, uint8_t *num_ch)
{
    union _mhu_v3_x_frame_t *p_mhu;

    if ((dev == NULL) || (num_ch == NULL)) {
        return MHU_V_3_X_ERR_GET_NUM_CHANNEL_INVALID_PARAM;
    }

    p_mhu = (union _mhu_v3_x_frame_t *)dev->base;

    /* Only doorbell channel is supported */
    if (ch_type != MHU_V3_X_CHANNEL_TYPE_DBCH) {
        return MHU_V_3_X_ERR_GET_NUM_CHANNEL_UNSUPPORTED;
    }

    /* Read the number of channels implemented in the MHU */
    if(dev->frame == MHU_V3_X_PBX_FRAME) {
        *num_ch = (p_mhu->pbx_frame.pbx_ctrl_page.pbx_dbch_cfg0 + 1);
    } else {
        *num_ch = (p_mhu->mbx_frame.mbx_ctrl_page.mbx_dbch_cfg0 + 1);
    }

    return MHU_V_3_X_ERR_NONE;
}

enum mhu_v3_x_error_t mhu_v3_x_doorbell_clear(struct mhu_v3_x_dev_t *dev,
    uint8_t channel, uint32_t mask)
{
    union _mhu_v3_x_frame_t *p_mhu;
    struct _mhu_v3_x_mbx_mdbcw_reg_t *mdbcw_reg;
    enum mhu_v3_x_error_t status;

    if (dev == NULL) {
        return MHU_V_3_X_ERR_DOORBELL_CLEAR_INVALID_PARAM;
    }

    /* Check if driver has been initialized */
    if (!(dev->is_initialized)) {
        status = mhu_v3_x_driver_init(dev);
        if (status != MHU_V_3_X_ERR_NONE) {
            return status;
        }
    }

    /* Only MBX can clear the Doorbell channel */
    if(dev->frame != MHU_V3_X_MBX_FRAME) {
        return MHU_V_3_X_ERR_DOORBELL_CLEAR_INVALID_PARAM;
    }

    p_mhu = (union _mhu_v3_x_frame_t *)dev->base;
    mdbcw_reg = (struct _mhu_v3_x_mbx_mdbcw_reg_t *)
        &(p_mhu->mbx_frame.mdbcw_page);

    /* Clear the bits in the doorbell channel */
    mdbcw_reg[channel].mdbcw_clr = mask;

    return MHU_V_3_X_ERR_NONE;
}

enum mhu_v3_x_error_t mhu_v3_x_doorbell_write(struct mhu_v3_x_dev_t *dev,
    uint8_t channel, uint32_t value)
{
    union _mhu_v3_x_frame_t *p_mhu;
    struct _mhu_v3_x_pbx_pdbcw_reg_t *pdbcw_reg;
    enum mhu_v3_x_error_t status;

    if (dev == NULL) {
        return MHU_V_3_X_ERR_DOORBELL_WRITE_INVALID_PARAM;
    }

    /* Check if driver has been initialized */
    if (!(dev->is_initialized)) {
        status = mhu_v3_x_driver_init(dev);
        if (status != MHU_V_3_X_ERR_NONE) {
            return status;
        }
    }

    /* Only PBX can set the Doorbell channel value */
    if (dev->frame != MHU_V3_X_PBX_FRAME) {
        return MHU_V_3_X_ERR_DOORBELL_WRITE_INVALID_PARAM;
    }

    p_mhu = (union _mhu_v3_x_frame_t *)dev->base;

    pdbcw_reg = (struct _mhu_v3_x_pbx_pdbcw_reg_t *)
        &(p_mhu->pbx_frame.pdbcw_page);

    /* Write the value to the doorbell channel */
    pdbcw_reg[channel].pdbcw_set = value;

    return MHU_V_3_X_ERR_NONE;
}

enum mhu_v3_x_error_t mhu_v3_x_doorbell_read(struct mhu_v3_x_dev_t *dev,
    uint8_t channel, uint32_t *value)
{
    union _mhu_v3_x_frame_t *p_mhu;
    enum mhu_v3_x_error_t status;

    if ((dev == NULL) || (value == NULL)) {
        return MHU_V_3_X_ERR_DOORBELL_READ_INVALID_PARAM;
    }

    /* Check if driver has been initialized */
    if (!(dev->is_initialized)) {
        status = mhu_v3_x_driver_init(dev);
        if (status != MHU_V_3_X_ERR_NONE) {
            return status;
        }
    }

    p_mhu = (union _mhu_v3_x_frame_t *)dev->base;

    if(dev->frame == MHU_V3_X_MBX_FRAME) {
        struct _mhu_v3_x_mbx_mdbcw_reg_t *mdbcw_reg;
        mdbcw_reg = (struct _mhu_v3_x_mbx_mdbcw_reg_t *)
            &(p_mhu->mbx_frame.mdbcw_page);

        /* Read the value from Mailbox Doorbell status register */
        *value = mdbcw_reg[channel].mdbcw_st;
    } else {
        struct _mhu_v3_x_pbx_pdbcw_reg_t *pdbcw_reg;
        pdbcw_reg = (struct _mhu_v3_x_pbx_pdbcw_reg_t *)
            &(p_mhu->pbx_frame.pdbcw_page);

        /* Read the value from Postbox Doorbell status register */
        *value = pdbcw_reg[channel].pdbcw_st;
    }

    return MHU_V_3_X_ERR_NONE;
}

enum mhu_v3_x_error_t mhu_v3_x_doorbell_mask_set(
    struct mhu_v3_x_dev_t *dev, uint8_t channel, uint32_t mask)
{
    union _mhu_v3_x_frame_t *p_mhu;
    struct _mhu_v3_x_mbx_mdbcw_reg_t *mdbcw_reg;
    enum mhu_v3_x_error_t status;

    if (dev == NULL) {
        return MHU_V_3_X_ERR_DOORBELL_MASK_SET_INVALID_PARAM;
    }

    /* Check if driver has been initialized */
    if (!(dev->is_initialized) ) {
        status = mhu_v3_x_driver_init(dev);
        if (status != MHU_V_3_X_ERR_NONE) {
            return status;
        }
    }

    /* Doorbell channel mask not applicable for PBX */
    if(dev->frame != MHU_V3_X_MBX_FRAME) {
        return MHU_V_3_X_ERR_DOORBELL_MASK_SET_INVALID_PARAM;
    }

    p_mhu = (union _mhu_v3_x_frame_t *)dev->base;

    mdbcw_reg = (struct _mhu_v3_x_mbx_mdbcw_reg_t *)
        &(p_mhu->mbx_frame.mdbcw_page);

    /* Set the Doorbell channel mask */
    mdbcw_reg[channel].mdbcw_msk_set = mask;

    return MHU_V_3_X_ERR_NONE;
}

enum mhu_v3_x_error_t mhu_v3_x_doorbell_mask_clear(
    struct mhu_v3_x_dev_t *dev, uint8_t channel, uint32_t mask)
{
    union _mhu_v3_x_frame_t *p_mhu;
    struct _mhu_v3_x_mbx_mdbcw_reg_t *mdbcw_reg;
    enum mhu_v3_x_error_t status;

    if (dev == NULL) {
        return MHU_V_3_X_ERR_DOORBELL_MASK_CLEAR_INVALID_PARAM;
    }

    /* Check if driver has been initialized */
    if (!(dev->is_initialized)) {
        status = mhu_v3_x_driver_init(dev);
        if (status != MHU_V_3_X_ERR_NONE) {
            return status;
        }
    }

    /* Doorbell channel mask not applicable for PBX */
    if(dev->frame != MHU_V3_X_MBX_FRAME) {
        return MHU_V_3_X_ERR_DOORBELL_MASK_CLEAR_INVALID_PARAM;
    }

    p_mhu = (union _mhu_v3_x_frame_t *)dev->base;

    mdbcw_reg = (struct _mhu_v3_x_mbx_mdbcw_reg_t *)
        &(p_mhu->mbx_frame.mdbcw_page);

    /* Clear the Doorbell channel mask */
    mdbcw_reg[channel].mdbcw_msk_clr = mask;

    return MHU_V_3_X_ERR_NONE;
}

enum mhu_v3_x_error_t mhu_v3_x_doorbell_mask_get(
    struct mhu_v3_x_dev_t *dev, uint8_t channel, uint32_t *mask_status)
{
    union _mhu_v3_x_frame_t *p_mhu;
    struct _mhu_v3_x_mbx_mdbcw_reg_t *mdbcw_reg;
    enum mhu_v3_x_error_t status;

    if ((dev == NULL) || (mask_status == NULL)) {
        return MHU_V_3_X_ERR_DOORBELL_MASK_GET_INVALID_PARAM;
    }

    /* Check if driver has been initialized */
    if (!(dev->is_initialized)) {
        status = mhu_v3_x_driver_init(dev);
        if (status != MHU_V_3_X_ERR_NONE) {
            return status;
        }
    }

    /* Doorbell channel mask not applicable for PBX */
    if(dev->frame != MHU_V3_X_MBX_FRAME) {
        return MHU_V_3_X_ERR_DOORBELL_MASK_GET_INVALID_PARAM;
    }

    p_mhu = (union _mhu_v3_x_frame_t *)dev->base;

    mdbcw_reg = (struct _mhu_v3_x_mbx_mdbcw_reg_t *)
        &(p_mhu->mbx_frame.mdbcw_page);

    /* Save the Doorbell channel mask status */
    *mask_status = mdbcw_reg[channel].mdbcw_msk_st;

    return MHU_V_3_X_ERR_NONE;
}

enum mhu_v3_x_error_t mhu_v3_x_channel_interrupt_enable(
    struct mhu_v3_x_dev_t *dev, uint8_t channel,
    enum mhu_v3_x_channel_type_t ch_type)
{
    enum mhu_v3_x_error_t status;

    if (dev == NULL) {
        return MHU_V_3_X_ERR_INTERRUPT_ENABLE_INVALID_PARAM;
    }

    /* Check if driver has been initialized */
    if (!(dev->is_initialized)) {
        status = mhu_v3_x_driver_init(dev);
        if (status != MHU_V_3_X_ERR_NONE) {
            return status;
        }
    }

    /* Only doorbell channel is supported */
    if (ch_type != MHU_V3_X_CHANNEL_TYPE_DBCH) {
        return MHU_V_3_X_ERR_INTERRUPT_ENABLE_UNSUPPORTED;
    }

    /* Enable the doorbell channel interrupt */
    _mhu_v3_x_doorbell_interrupt_enable(dev, channel);

    return MHU_V_3_X_ERR_NONE;
}

enum mhu_v3_x_error_t mhu_v3_x_channel_interrupt_disable(
    struct mhu_v3_x_dev_t *dev, uint8_t channel,
    enum mhu_v3_x_channel_type_t ch_type)
{
    enum mhu_v3_x_error_t status;

    if (dev == NULL) {
        return MHU_V_3_X_ERR_INTERRUPT_DISABLE_INVALID_PARAM;
    }

    /* Check if driver has been initialized */
    if (!(dev->is_initialized)) {
        status = mhu_v3_x_driver_init(dev);
        if (status != MHU_V_3_X_ERR_NONE) {
            return status;
        }
    }

    /* Only doorbell channel is supported */
    if (ch_type != MHU_V3_X_CHANNEL_TYPE_DBCH) {
        return MHU_V_3_X_ERR_INTERRUPT_DISABLE_UNSUPPORTED;
    }

    /* Disable the doorbell channel interrupt */
    _mhu_v3_x_doorbell_interrupt_disable(dev, channel);

    return MHU_V_3_X_ERR_NONE;
}

enum mhu_v3_x_error_t mhu_v3_x_channel_interrupt_clear(
    struct mhu_v3_x_dev_t *dev, uint8_t channel,
    enum mhu_v3_x_channel_type_t ch_type)
{
    enum mhu_v3_x_error_t status;

    if (dev == NULL) {
        return MHU_V_3_X_ERR_INTERRUPT_CLEAR_INVALID_PARAM;
    }

    /* Check if driver has been initialized */
    if (!(dev->is_initialized)) {
        status = mhu_v3_x_driver_init(dev);
        if (status != MHU_V_3_X_ERR_NONE) {
            return status;
        }
    }

    /* Only doorbell channel is supported */
    if (ch_type != MHU_V3_X_CHANNEL_TYPE_DBCH) {
        return MHU_V_3_X_ERR_INTERRUPT_CLEAR_UNSUPPORTED;
    }

    /*
     * Only postbox doorbell channel transfer acknowledge interrupt can be
     * cleared manually.
     */
    if(dev->frame != MHU_V3_X_PBX_FRAME) {
        return MHU_V_3_X_ERR_INTERRUPT_CLEAR_INVALID_PARAM;
    }

    /* Clear the postbox doorbell channel transfer acknowledge event */
    _mhu_v3_x_doorbell_interrupt_clear(dev, channel);

    return MHU_V_3_X_ERR_NONE;
}
