/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <stdlib.h>
#include <string.h>

#include "mhu_v3_x.h"

#include "unity.h"

/* Postbox Block Identifier reset value */
#define MHU_PBX_BLK_ID_RESET_VALUE 0x0u
/* Postbox Feature Support 0 reset value
 *   MHU implements Doorbell and FIFO extensions */
#define MHU_PBX_FEAT_SPT0_RESET_VALUE 0x101u
/* Postbox Feature Support 1 reset value
 *   MHU implements Auto Op(Full) protocol */
#define MHU_PBX_FEAT_SPT1_RESET_VALUE 0x1u
/* Postbox Doorbell Channel Configuration 0 reset value
 *   MHU implements 16 doorbell channels */
#define MHU_PBX_DBCH_CFG0_RESET_VALUE 0xFu
/* Postbox FIFO Channel Configuration 0 reset value
 *   MHU implements 2 FIFO channels
 *   MHU supports 32bit accesses
 *   MHU FIFO channels depth is 5-bytes
 */
#define MHU_PBX_FFCH_CFG0_RESET_VALUE 0x40401u
/* Postbox Fast Channel Configuration 0 reset value
 *   MHU Fast channels word size is 64-bits
 */
#define MHU_PBX_FCH_CFG0_RESET_VALUE 0x04000000u
/* Postbox control reset value */
#define MHU_PBX_CTRL_RESET_VALUE 0x0u
/* Postbox Doorbell Channel Interrupt Status reset value */
#define MHU_PBX_DBCH_INT_ST_RESET_VALUE 0x0u
/* Postbox FIFO Channel Interrupt Status reset value */
#define MHU_PBX_FFCH_INT_ST_RESET_VALUE 0x0u
/* Postbox Implementer Identification Register reset value */
#define MHU_PBX_IIDR_RESET_VALUE 0x0u
/* Postbox Architecture Identification Register reset value
 *   MHU architecture major revision is MHUv3
 *   MHU architecture minor revision is 0
 */
#define MHU_PBX_AIDR_RESET_VALUE 0x20u
/* Postbox Implementation Defined Identification Register reset value */
#define MHU_PBX_IMPL_DEF_ID_RESET_VALUE 0x0u
/* Postbox Doorbell Channel Window Status reset value */
#define MHU_PBX_DBCW_ST_RESET_VALUE 0x0u
/* Postbox Doorbell Channel Window Set reset value */
#define MHU_PBX_DBCW_SET_RESET_VALUE 0x0u
/* Postbox Doorbell Channel Window Interrupt Status reset value */
#define MHU_PBX_DBCW_INT_ST_RESET_VALUE 0x0u
/* Postbox Doorbell Channel Window Interrupt Clear reset value */
#define MHU_PBX_DBCW_INT_CLR_RESET_VALUE 0x0u
/* Postbox Doorbell Channel Window Interrupt Enable reset value */
#define MHU_PBX_DBCW_INT_EN_RESET_VALUE 0x0u
/* Postbox Doorbell Channel Window Control reset value
 *   MHU doorbell channel contributes to the Postbox
 *   Combined interrupt
 */
#define MHU_PBX_DBCW_CTRL_RESET_VALUE 0x1u

/* Postbox control page structure */
struct _mhu_v3_x_pbx_ctrl_reg_t {
    /* Offset: 0x000 (R/O) Postbox Block Identifier */
    volatile uint32_t mhu_blk_id;
    /* Offset: 0x004 (R/O) Reserved */
    volatile uint8_t reserved_0[0x10 - 0x04];
    /* Offset: 0x010 (R/O) Postbox Feature Support 0 */
    volatile uint32_t pbx_feat_spt0;
    /* Offset: 0x014 (R/O) Postbox Feature Support 1 */
    volatile uint32_t pbx_feat_spt1;
    /* Offset: 0x018 (R/O) Reserved */
    volatile uint8_t reserved_1[0x20 - 0x18];
    /* Offset: 0x020 (R/O) Postbox Doorbell Channel Configuration 0 */
    volatile uint32_t pbx_dbch_cfg0;
    /* Offset: 0x024 (R/O) Reserved */
    volatile uint8_t reserved_2[0x30 - 0x24];
    /* Offset: 0x030 (R/O) Postbox FIFO Channel Configuration 0 */
    volatile uint32_t pbx_ffch_cfg0;
    /* Offset: 0x034 (R/O) Reserved */
    volatile uint8_t reserved_3[0x40 - 0x34];
    /* Offset: 0x040 (R/O) Postbox Fast Channel Configuration 0 */
    volatile uint32_t pbx_fch_cfg0;
    /* Offset: 0x044 (R/O) Reserved */
    volatile uint8_t reserved_4[0x100 - 0x44];
    /* Offset: 0x100 (R/W) Postbox control */
    volatile uint32_t pbx_ctrl;
    /* Offset: 0x164 (R/O) Reserved */
    volatile uint8_t reserved_5[0x400 - 0x104];
    /* Offset: 0x400 (R/O) Postbox Doorbell Channel Interrupt Status n,
     *                     where n is 0 - 3 */
    volatile uint32_t pbx_dbch_int_st[4];
    /* Offset: 0x410 (R/O) Postbox FIFO Channel <n> Interrupt Status n,
     *                     where n is 0 - 1 */
    volatile uint32_t pbx_ffch_int_st[2];
    /* Offset: 0x418 (R/O) Reserved */
    volatile uint8_t reserved_6[0xFC8 - 0x418];
    /* Offset: 0xFC8 (R/O) Postbox Implementer Identification Register */
    volatile uint32_t iidr;
    /* Offset: 0xFCC (R/O) Postbox Architecture Identification Register */
    volatile uint32_t aidr;
    /* Offset: 0xFD0 (R/O) Postbox Implementation Defined Identification
     *                     Register n, where n is 0 - 11 */
    volatile uint32_t impl_def_id[12];
};

/* Postbox doorbell channel window page structure */
struct _mhu_v3_x_pbx_pdbcw_reg_t {
    /* Offset: 0x000 (R/O) Postbox Doorbell Channel Window Status */
    volatile uint32_t pdbcw_st;
    /* Offset: 0x004 (R/O) Reserved */
    volatile uint8_t reserved_0[0xC - 0x4];
    /* Offset: 0x00C (W/O) Postbox Doorbell Channel Window Set */
    volatile uint32_t pdbcw_set;
    /* Offset: 0x010 (R/O) Postbox Doorbell Channel Window Interrupt Status */
    volatile uint32_t pdbcw_int_st;
    /* Offset: 0x014 (W/O) Postbox Doorbell Channel Window Interrupt Clear */
    volatile uint32_t pdbcw_int_clr;
    /* Offset: 0x018 (R/W) Postbox Doorbell Channel Window Interrupt Enable */
    volatile uint32_t pdbcw_int_en;
    /* Offset: 0x01C (R/W) Postbox Doorbell Channel Window Control */
    volatile uint32_t pdbcw_ctrl;
};

/* Postbox structure */
struct _mhu_v3_x_pbx {
    /* Postbox Control */
    struct _mhu_v3_x_pbx_ctrl_reg_t pbx_ctrl_page;
    /* Postbox Doorbell Channel Window */
    struct _mhu_v3_x_pbx_pdbcw_reg_t pdbcw_page;
} mhu_pbx_frame;

/* Mailbox Block Identifier */
#define MHU_MBX_BLK_ID_RESET_VALUE 0x1u
/* Mailbox Feature Support 0
 *   MHU implements Doorbell and FIFO extensions */
#define MHU_MBX_FEAT_SPT0_RESET_VALUE 0x101u
/* Mailbox Feature Support 1
 *   MHU implements Auto Op(Full) protocol */
#define MHU_MBX_FEAT_SPT1_RESET_VALUE 0x1u
/* Mailbox Doorbell Channel Configuration 0
 *   MHU implements 16 doorbell channels */
#define MHU_MBX_DBCH_CFG0_RESET_VALUE 0xFu
/* Mailbox FIFO Channel Configuration 0
 *   MHU implements 2 FIFO channels
 *   MHU supports 32bit accesses
 *   MHU FIFO channels depth is 5-bytes
 */
#define MHU_MBX_FFCH_CFG0_RESET_VALUE 0x00040401u
/* Mailbox Fast Channel Configuration 0
 *   MHU Fast channels word size is 64-bits
 */
#define MHU_MBX_FCH_CFG0_RESET_VALUE 0x04000000u
/* Mailbox control */
#define MHU_MBX_CTRL_RESET_VALUE 0x0u
/* Mailbox Fast Channel control */
#define MHU_MBX_FCH_CTRL_RESET_VALUE 0x0u
/* Mailbox Fast Channel Group Interrupt Enable */
#define MHU_MBX_FCG_INT_EN_RESET_VALUE 0x0u
/* Mailbox Doorbell Channel Interrupt Status */
#define MHU_MBX_DBCH_INT_ST_RESET_VALUE 0x0u
/* Mailbox FIFO Channel Interrupt Status */
#define MHU_MBX_FFCH_INT_ST_RESET_VALUE 0x0u
/* Mailbox Fast Channel Group Interrupt Status */
#define MHU_MBX_FCG_INT_ST_RESET_VALUE 0x0u
/* Mailbox Fast Channel Group Interrupt Status*/
#define MBX_FCH_GRP_INT_ST_RESET_VALUE 0x0u
/* Mailbox Implementer Identification Register */
#define MHU_MBX_IIDR_RESET_VALUE 0x0u
/* Mailbox Architecture Identification Register
 *   MHU architecture major revision is MHUv3
 *   MHU architecture minor revision is 0
 */
#define MHU_MBX_AIDR_RESET_VALUE 0x20u
/* Mailbox Implementation Defined Identification Register */
#define MHU_MBX_IMPL_DEF_ID_RESET_VALUE 0x0u
/* Mailbox Doorbell Channel Window Status */
#define MHU_MBX_DBCW_ST_RESET_VALUE 0x0u
/*  Mailbox Doorbell Channel Window Status Masked */
#define MHU_MBX_DBCW_ST_MSK_RESET_VALUE 0x0u
/* Mailbox Doorbell Channel Window Clear */
#define MHU_MBX_DBCW_CLR_RESET_VALUE 0x0u
/* Mailbox Doorbell Channel Window Mask Status */
#define MHU_MBX_DBCW_MSK_ST_RESET_VALUE 0x0u
/* Mailbox Doorbell Channel Window Mask Set */
#define MHU_MBX_DBCW_MSK_SET_RESET_VALUE 0x0u
/* Mailbox Doorbell Channel Window Mask Clear */
#define MHU_MBX_DBCW_MSK_CLR_RESET_VALUE 0x0u
/* Mailbox Doorbell Channel Window Control
 *   MHU doorbell channel contributes to the Mailbox
 *   Combined interrupt
 */
#define MHU_MBX_DBCW_CTRL_RESET_VALUE 0x1u

/* Mailbox control page structure */
struct _mhu_v3_x_mbx_ctrl_reg_t {
    /* Offset: 0x000 (R/O) Mailbox Block Identifier */
    volatile uint32_t mhu_blk_id;
    /* Offset: 0x004 (R/O) Reserved */
    volatile uint8_t reserved_0[0x10 - 0x04];
    /* Offset: 0x010 (R/O) Mailbox Feature Support 0 */
    volatile uint32_t mbx_feat_spt0;
    /* Offset: 0x014 (R/O) Mailbox Feature Support 1 */
    volatile uint32_t mbx_feat_spt1;
    /* Offset: 0x018 (R/O) Reserved */
    volatile uint8_t reserved_1[0x20 - 0x18];
    /* Offset: 0x020 (R/O) Mailbox Doorbell Channel Configuration 0 */
    volatile uint32_t mbx_dbch_cfg0;
    /* Offset: 0x024 (R/O) Reserved */
    volatile uint8_t reserved_2[0x30 - 0x24];
    /* Offset: 0x030 (R/O) Mailbox FIFO Channel Configuration 0 */
    volatile uint32_t mbx_ffch_cfg0;
    /* Offset: 0x034 (R/O) Reserved */
    volatile uint8_t reserved_4[0x40 - 0x34];
    /* Offset: 0x040 (R/O) Mailbox Fast Channel Configuration 0 */
    volatile uint32_t mbx_fch_cfg0;
    /* Offset: 0x044 (R/O) Reserved */
    volatile uint8_t reserved_5[0x100 - 0x44];
    /* Offset: 0x100 (R/W) Mailbox control */
    volatile uint32_t mbx_ctrl;
    /* Offset: 0x104 (R/O) Reserved */
    volatile uint8_t reserved_6[0x140 - 0x104];
    /* Offset: 0x140 (R/W) Mailbox Fast Channel control */
    volatile uint32_t mbx_fch_ctrl;
    /* Offset: 0x144 (R/W) Mailbox Fast Channel Group Interrupt Enable */
    volatile uint32_t mbx_fcg_int_en;
    /* Offset: 0x148 (R/O) Reserved */
    volatile uint8_t reserved_7[0x400 - 0x148];
    /* Offset: 0x400 (R/O) Mailbox Doorbell Channel Interrupt Status n,
     *                     where n = 0 - 3 */
    volatile uint32_t mbx_dbch_int_st[4];
    /* Offset: 0x410 (R/O) Mailbox FIFO Channel Interrupt Status n,
     *                     where n = 0 - 1 */
    volatile uint32_t mbx_ffch_int_st[2];
    /* Offset: 0x418 (R/O) Reserved */
    volatile uint8_t reserved_8[0x470 - 0x418];
    /* Offset: 0x470 (R/O) Mailbox Fast Channel Group Interrupt Status */
    volatile uint32_t mbx_fcg_int_st;
    /* Offset: 0x474 (R/O) Reserved */
    volatile uint8_t reserved_9[0x480 - 0x474];
    /* Offset: 0x480 (R/O) Mailbox Fast Channel Group <n> Interrupt Status,
     *                     where n = 0 - 31 */
    volatile uint32_t mbx_fch_grp_int_st[32];
    /* Offset: 0x500 (R/O) Reserved */
    volatile uint8_t reserved_10[0xFC8 - 0x500];
    /* Offset: 0xFC8 (R/O) Mailbox Implementer Identification Register */
    volatile uint32_t iidr;
    /* Offset: 0xFCC (R/O) Mailbox Architecture Identification Register */
    volatile uint32_t aidr;
    /* Offset: 0xFD0 (R/O) Mailbox Implementation Defined Identification
     *                     Register n, where n is 0 - 11 */
    volatile uint32_t impl_def_id[12];
};

/* Mailbox doorbell channel window page structure */
struct _mhu_v3_x_mbx_mdbcw_reg_t {
    /* Offset: 0x000 (R/O) Mailbox Doorbell Channel Window Status */
    volatile uint32_t mdbcw_st;
    /* Offset: 0x004 (R/O) Mailbox Doorbell Channel Window Status Masked */
    volatile uint32_t mdbcw_st_msk;
    /* Offset: 0x008 (W/O) Mailbox Doorbell Channel Window Clear */
    volatile uint32_t mdbcw_clr;
    /* Offset: 0x00C (R/O) Reserved */
    volatile uint8_t reserved_0[0x10 - 0x0C];
    /* Offset: 0x010 (R/O) Mailbox Doorbell Channel Window Mask Status */
    volatile uint32_t mdbcw_msk_st;
    /* Offset: 0x014 (W/O) Mailbox Doorbell Channel Window Mask Set */
    volatile uint32_t mdbcw_msk_set;
    /* Offset: 0x018 (W/O) Mailbox Doorbell Channel Window Mask Clear */
    volatile uint32_t mdbcw_msk_clr;
    /* Offset: 0x01C (R/W) Mailbox Doorbell Channel Window Control */
    volatile uint32_t mdbcw_ctrl;
};

/* Mailbox structure */
struct _mhu_v3_x_mbx {
    /* Mailbox control */
    struct _mhu_v3_x_mbx_ctrl_reg_t mbx_ctrl_page;
    /* Mailbox Doorbell Channel Window */
    struct _mhu_v3_x_mbx_mdbcw_reg_t mdbcw_page;
} mhu_mbx_frame;

/* MHUv3 frame type */
union _mhu_v3_x_frame_t {
    /* Postbox Frame */
    struct _mhu_v3_x_pbx pbx_frame;
    /* Mailbox Frame */
    struct _mhu_v3_x_mbx mbx_frame;
};

struct mhu_v3_x_dev_t MHU_PBX_DEV = {.version = 3,
                                     .base = (uintptr_t)&mhu_pbx_frame,
                                     .frame = MHU_V3_X_PBX_FRAME,
                                     .subversion = 0};

struct mhu_v3_x_dev_t MHU_MBX_DEV = {.version = 3,
                                     .base = (uintptr_t)&mhu_mbx_frame,
                                     .frame = MHU_V3_X_MBX_FRAME,
                                     .subversion = 0};

/* Set MHUv3 registers to their default reset values */
void set_default_register_values(void)
{
    /* Set default MHU PBX register values */
    MHU_PBX_DEV.is_initialized = false;

    mhu_pbx_frame.pbx_ctrl_page.mhu_blk_id = MHU_PBX_BLK_ID_RESET_VALUE;
    memset((void *)mhu_pbx_frame.pbx_ctrl_page.reserved_0, 0x0u,
           sizeof(mhu_pbx_frame.pbx_ctrl_page.reserved_0));
    mhu_pbx_frame.pbx_ctrl_page.pbx_feat_spt0 = MHU_PBX_FEAT_SPT0_RESET_VALUE;
    mhu_pbx_frame.pbx_ctrl_page.pbx_feat_spt1 = MHU_PBX_FEAT_SPT1_RESET_VALUE;
    memset((void *)mhu_pbx_frame.pbx_ctrl_page.reserved_1, 0x0u,
           sizeof(mhu_pbx_frame.pbx_ctrl_page.reserved_1));
    mhu_pbx_frame.pbx_ctrl_page.pbx_dbch_cfg0 = MHU_PBX_DBCH_CFG0_RESET_VALUE;
    memset((void *)mhu_pbx_frame.pbx_ctrl_page.reserved_2, 0x0u,
           sizeof(mhu_pbx_frame.pbx_ctrl_page.reserved_2));
    mhu_pbx_frame.pbx_ctrl_page.pbx_ffch_cfg0 = MHU_PBX_FFCH_CFG0_RESET_VALUE;
    memset((void *)mhu_pbx_frame.pbx_ctrl_page.reserved_3, 0x0u,
           sizeof(mhu_pbx_frame.pbx_ctrl_page.reserved_3));
    mhu_pbx_frame.pbx_ctrl_page.pbx_fch_cfg0 = MHU_PBX_FCH_CFG0_RESET_VALUE;
    memset((void *)mhu_pbx_frame.pbx_ctrl_page.reserved_4, 0x0u,
           sizeof(mhu_pbx_frame.pbx_ctrl_page.reserved_4));
    mhu_pbx_frame.pbx_ctrl_page.pbx_ctrl = MHU_PBX_CTRL_RESET_VALUE;
    memset((void *)mhu_pbx_frame.pbx_ctrl_page.reserved_5, 0x0u,
           sizeof(mhu_pbx_frame.pbx_ctrl_page.reserved_5));
    memset((void *)mhu_pbx_frame.pbx_ctrl_page.pbx_dbch_int_st,
           MHU_PBX_DBCH_INT_ST_RESET_VALUE,
           sizeof(mhu_pbx_frame.pbx_ctrl_page.pbx_dbch_int_st));
    memset((void *)mhu_pbx_frame.pbx_ctrl_page.pbx_ffch_int_st,
           MHU_PBX_FFCH_INT_ST_RESET_VALUE,
           sizeof(mhu_pbx_frame.pbx_ctrl_page.pbx_ffch_int_st));
    memset((void *)mhu_pbx_frame.pbx_ctrl_page.reserved_6, 0x0u,
           sizeof(mhu_pbx_frame.pbx_ctrl_page.reserved_6));
    mhu_pbx_frame.pbx_ctrl_page.iidr = MHU_PBX_IIDR_RESET_VALUE;
    mhu_pbx_frame.pbx_ctrl_page.aidr = MHU_PBX_AIDR_RESET_VALUE;
    memset((void *)mhu_pbx_frame.pbx_ctrl_page.impl_def_id,
           MHU_PBX_IMPL_DEF_ID_RESET_VALUE,
           sizeof(mhu_pbx_frame.pbx_ctrl_page.impl_def_id));

    mhu_pbx_frame.pdbcw_page.pdbcw_st = MHU_PBX_DBCW_ST_RESET_VALUE;
    memset((void *)mhu_pbx_frame.pdbcw_page.reserved_0, 0x0u,
           sizeof(mhu_pbx_frame.pdbcw_page.reserved_0));
    mhu_pbx_frame.pdbcw_page.pdbcw_set = MHU_PBX_DBCW_SET_RESET_VALUE;
    mhu_pbx_frame.pdbcw_page.pdbcw_int_st = MHU_PBX_DBCW_INT_ST_RESET_VALUE;
    mhu_pbx_frame.pdbcw_page.pdbcw_int_clr = MHU_PBX_DBCW_INT_CLR_RESET_VALUE;
    mhu_pbx_frame.pdbcw_page.pdbcw_int_en = MHU_PBX_DBCW_INT_EN_RESET_VALUE;
    mhu_pbx_frame.pdbcw_page.pdbcw_ctrl = MHU_PBX_DBCW_CTRL_RESET_VALUE;

    /* Set default MHU MBX register values */
    MHU_MBX_DEV.is_initialized = false;

    mhu_mbx_frame.mbx_ctrl_page.mhu_blk_id = MHU_MBX_BLK_ID_RESET_VALUE;
    memset((void *)mhu_mbx_frame.mbx_ctrl_page.reserved_0, 0x0u,
           sizeof(mhu_mbx_frame.mbx_ctrl_page.reserved_0));
    mhu_mbx_frame.mbx_ctrl_page.mbx_feat_spt0 = MHU_MBX_FEAT_SPT0_RESET_VALUE;
    mhu_mbx_frame.mbx_ctrl_page.mbx_feat_spt1 = MHU_MBX_FEAT_SPT1_RESET_VALUE;
    memset((void *)mhu_mbx_frame.mbx_ctrl_page.reserved_1, 0x0u,
           sizeof(mhu_mbx_frame.mbx_ctrl_page.reserved_1));
    mhu_mbx_frame.mbx_ctrl_page.mbx_dbch_cfg0 = MHU_MBX_DBCH_CFG0_RESET_VALUE;
    memset((void *)mhu_mbx_frame.mbx_ctrl_page.reserved_4, 0x0u,
           sizeof(mhu_mbx_frame.mbx_ctrl_page.reserved_4));
    mhu_mbx_frame.mbx_ctrl_page.mbx_ffch_cfg0 = MHU_MBX_FFCH_CFG0_RESET_VALUE;
    memset((void *)mhu_mbx_frame.mbx_ctrl_page.reserved_5, 0x0u,
           sizeof(mhu_mbx_frame.mbx_ctrl_page.reserved_5));
    mhu_mbx_frame.mbx_ctrl_page.mbx_fch_cfg0 = MHU_MBX_FCH_CFG0_RESET_VALUE;
    memset((void *)mhu_mbx_frame.mbx_ctrl_page.reserved_6, 0x0u,
           sizeof(mhu_mbx_frame.mbx_ctrl_page.reserved_6));
    mhu_mbx_frame.mbx_ctrl_page.mbx_ctrl = MHU_MBX_CTRL_RESET_VALUE;
    mhu_mbx_frame.mbx_ctrl_page.mbx_fch_ctrl = MHU_MBX_FCH_CTRL_RESET_VALUE;
    mhu_mbx_frame.mbx_ctrl_page.mbx_fcg_int_en = MHU_MBX_FCG_INT_EN_RESET_VALUE;
    memset((void *)mhu_mbx_frame.mbx_ctrl_page.reserved_7, 0x0u,
           sizeof(mhu_mbx_frame.mbx_ctrl_page.reserved_7));
    memset((void *)mhu_mbx_frame.mbx_ctrl_page.mbx_dbch_int_st,
           MHU_MBX_DBCH_INT_ST_RESET_VALUE,
           sizeof(mhu_mbx_frame.mbx_ctrl_page.mbx_dbch_int_st));
    memset((void *)mhu_mbx_frame.mbx_ctrl_page.mbx_ffch_int_st,
           MHU_MBX_FFCH_INT_ST_RESET_VALUE,
           sizeof(mhu_mbx_frame.mbx_ctrl_page.mbx_ffch_int_st));
    memset((void *)mhu_mbx_frame.mbx_ctrl_page.reserved_8, 0x0u,
           sizeof(mhu_mbx_frame.mbx_ctrl_page.reserved_8));
    mhu_mbx_frame.mbx_ctrl_page.mbx_fcg_int_st = MHU_MBX_FCG_INT_ST_RESET_VALUE;
    memset((void *)mhu_mbx_frame.mbx_ctrl_page.reserved_9, 0x0u,
           sizeof(mhu_mbx_frame.mbx_ctrl_page.reserved_9));
    memset((void *)mhu_mbx_frame.mbx_ctrl_page.reserved_10, 0x0u,
           sizeof(mhu_mbx_frame.mbx_ctrl_page.reserved_10));
    mhu_mbx_frame.mbx_ctrl_page.iidr = MHU_MBX_IIDR_RESET_VALUE;
    mhu_mbx_frame.mbx_ctrl_page.aidr = MHU_MBX_AIDR_RESET_VALUE;
    memset((void *)mhu_mbx_frame.mbx_ctrl_page.impl_def_id,
           MHU_MBX_IMPL_DEF_ID_RESET_VALUE,
           sizeof(mhu_mbx_frame.mbx_ctrl_page.impl_def_id));
    mhu_mbx_frame.mdbcw_page.mdbcw_st = MHU_MBX_DBCW_ST_RESET_VALUE;
    mhu_mbx_frame.mdbcw_page.mdbcw_st_msk = MHU_MBX_DBCW_ST_MSK_RESET_VALUE;
    mhu_mbx_frame.mdbcw_page.mdbcw_clr = MHU_MBX_DBCW_CLR_RESET_VALUE;
    memset((void *)mhu_mbx_frame.mdbcw_page.reserved_0, 0x0u,
           sizeof(mhu_mbx_frame.mdbcw_page.reserved_0));
    mhu_mbx_frame.mdbcw_page.mdbcw_msk_st = MHU_MBX_DBCW_MSK_ST_RESET_VALUE;
    mhu_mbx_frame.mdbcw_page.mdbcw_msk_set = MHU_MBX_DBCW_MSK_SET_RESET_VALUE;
    mhu_mbx_frame.mdbcw_page.mdbcw_msk_clr = MHU_MBX_DBCW_MSK_CLR_RESET_VALUE;
    mhu_mbx_frame.mdbcw_page.mdbcw_ctrl = MHU_MBX_DBCW_CTRL_RESET_VALUE;
}

/* Verify that Read-Only registers have not been modified */
void verify_read_only_registers(void)
{
    /* Verify that Read-Only MHU PBX registers have not been modified */
    TEST_ASSERT_EQUAL_UINT32_MESSAGE(
        MHU_PBX_BLK_ID_RESET_VALUE, mhu_pbx_frame.pbx_ctrl_page.mhu_blk_id,
        "Read-Only register MHU_PBX_BLK_ID was modified");
    TEST_ASSERT_EQUAL_UINT32_MESSAGE(
        MHU_PBX_FEAT_SPT0_RESET_VALUE,
        mhu_pbx_frame.pbx_ctrl_page.pbx_feat_spt0,
        "Read-Only register MHU_PBX_FEAT_SPT0 was modified");
    TEST_ASSERT_EQUAL_UINT32_MESSAGE(
        MHU_PBX_FEAT_SPT1_RESET_VALUE,
        mhu_pbx_frame.pbx_ctrl_page.pbx_feat_spt1,
        "Read-Only register MHU_PBX_FEAT_SPT1 was modified");
    TEST_ASSERT_EQUAL_UINT32_MESSAGE(
        MHU_PBX_DBCH_CFG0_RESET_VALUE,
        mhu_pbx_frame.pbx_ctrl_page.pbx_dbch_cfg0,
        "Read-Only register MHU_PBX_DBCH_CFG0 was modified");
    TEST_ASSERT_EQUAL_UINT32_MESSAGE(
        MHU_PBX_FFCH_CFG0_RESET_VALUE,
        mhu_pbx_frame.pbx_ctrl_page.pbx_ffch_cfg0,
        "Read-Only register MHU_PBX_FFCH_CFG0 was modified");
    TEST_ASSERT_EQUAL_UINT32_MESSAGE(
        MHU_PBX_FCH_CFG0_RESET_VALUE, mhu_pbx_frame.pbx_ctrl_page.pbx_fch_cfg0,
        "Read-Only register MHU_PBX_FCH_CFG0 was modified");
    TEST_ASSERT_EQUAL_UINT32_MESSAGE(
        MHU_PBX_IIDR_RESET_VALUE, mhu_pbx_frame.pbx_ctrl_page.iidr,
        "Read-Only register MHU_PBX_IIDR was modified");
    TEST_ASSERT_EQUAL_UINT32_MESSAGE(
        MHU_PBX_AIDR_RESET_VALUE, mhu_pbx_frame.pbx_ctrl_page.aidr,
        "Read-Only register MHU_PBX_AIDR was modified");
    TEST_ASSERT_EQUAL_UINT32_MESSAGE(
        MHU_PBX_DBCW_ST_RESET_VALUE, mhu_pbx_frame.pdbcw_page.pdbcw_st,
        "Read-Only register MHU_PBX_DBCW_ST was modified");
    TEST_ASSERT_EQUAL_UINT32_MESSAGE(
        MHU_PBX_DBCW_INT_ST_RESET_VALUE, mhu_pbx_frame.pdbcw_page.pdbcw_int_st,
        "Read-Only register MHU_PBX_DBCW_INT_ST was modified");

    /* Verify that Read-Only MHU MBX registers have not been modified */
    TEST_ASSERT_EQUAL_UINT32_MESSAGE(
        MHU_MBX_BLK_ID_RESET_VALUE, mhu_mbx_frame.mbx_ctrl_page.mhu_blk_id,
        "Read-Only register MHU_MBX_BLK_ID was modified");
    TEST_ASSERT_EQUAL_UINT32_MESSAGE(
        MHU_MBX_FEAT_SPT0_RESET_VALUE,
        mhu_mbx_frame.mbx_ctrl_page.mbx_feat_spt0,
        "Read-Only register MHU_MBX_FEAT_SPT0 was modified");
    TEST_ASSERT_EQUAL_UINT32_MESSAGE(
        MHU_MBX_FEAT_SPT1_RESET_VALUE,
        mhu_mbx_frame.mbx_ctrl_page.mbx_feat_spt1,
        "Read-Only register MHU_MBX_FEAT_SPT1 was modified");
    TEST_ASSERT_EQUAL_UINT32_MESSAGE(
        MHU_MBX_DBCH_CFG0_RESET_VALUE,
        mhu_mbx_frame.mbx_ctrl_page.mbx_dbch_cfg0,
        "Read-Only register MHU_MBX_DBCH_CFG0 was modified");
    TEST_ASSERT_EQUAL_UINT32_MESSAGE(
        MHU_MBX_FFCH_CFG0_RESET_VALUE,
        mhu_mbx_frame.mbx_ctrl_page.mbx_ffch_cfg0,
        "Read-Only register MHU_MBX_FFCH_CFG0 was modified");
    TEST_ASSERT_EQUAL_UINT32_MESSAGE(
        MHU_MBX_FCH_CFG0_RESET_VALUE, mhu_mbx_frame.mbx_ctrl_page.mbx_fch_cfg0,
        "Read-Only register MHU_MBX_FCH_CFG0 was modified");
    TEST_ASSERT_EQUAL_UINT32_MESSAGE(
        MHU_MBX_FCG_INT_ST_RESET_VALUE,
        mhu_mbx_frame.mbx_ctrl_page.mbx_fcg_int_st,
        "Read-Only register MHU_MBX_FCG_INT_ST was modified");
    TEST_ASSERT_EQUAL_UINT32_MESSAGE(
        MHU_MBX_IIDR_RESET_VALUE, mhu_mbx_frame.mbx_ctrl_page.iidr,
        "Read-Only register MHU_MBX_IIDR was modified");
    TEST_ASSERT_EQUAL_UINT32_MESSAGE(
        MHU_MBX_AIDR_RESET_VALUE, mhu_mbx_frame.mbx_ctrl_page.aidr,
        "Read-Only register MHU_MBX_AIDR was modified");
    TEST_ASSERT_EQUAL_UINT32_MESSAGE(
        MHU_MBX_DBCW_ST_RESET_VALUE, mhu_mbx_frame.mdbcw_page.mdbcw_st,
        "Read-Only register MHU_MBX_DBCW_ST was modified");
    TEST_ASSERT_EQUAL_UINT32_MESSAGE(
        MHU_MBX_DBCW_ST_MSK_RESET_VALUE, mhu_mbx_frame.mdbcw_page.mdbcw_st_msk,
        "Read-Only register MHU_MBX_DBCW_ST_MSK was modified");
    TEST_ASSERT_EQUAL_UINT32_MESSAGE(
        MHU_MBX_DBCW_MSK_ST_RESET_VALUE, mhu_mbx_frame.mdbcw_page.mdbcw_msk_st,
        "Read-Only register MHU_MBX_DBCW_MSK_ST was modified");
}

void setUp(void) { set_default_register_values(); }

void tearDown(void) { verify_read_only_registers(); }

void test_mhu_v3_x_driver_init_invalid_dev_param(void)
{
    enum mhu_v3_x_error_t mhu_err;

    /* Act */
    mhu_err = mhu_v3_x_driver_init(NULL);

    /* Assert */
    TEST_ASSERT_EQUAL(MHU_V_3_X_ERR_INIT_INVALID_PARAM, mhu_err);
}

TEST_CASE(false, 0xf0u, 0x0u, false, MHU_V_3_X_ERR_INIT_UNSUPPORTED_VERSION)
TEST_CASE(false, 0x0fu, 0x0u, false, MHU_V_3_X_ERR_INIT_UNSUPPORTED_VERSION)
TEST_CASE(false, 0x0u, MHU_V3_OP_REQ, true, MHU_V_3_X_ERR_NONE)
TEST_CASE(true, 0x0u, 0x0u, true, MHU_V_3_X_ERR_NONE)
void test_mhu_v3_x_driver_init_pbx(bool mhu_init_st, uint32_t aidr_mask,
                                   uint32_t expected_pbx_ctrl,
                                   bool expected_mhu_init_st,
                                   enum mhu_v3_x_error_t expected_err)
{
    enum mhu_v3_x_error_t mhu_err;

    /* Prepare */
    MHU_PBX_DEV.is_initialized = mhu_init_st;
    mhu_pbx_frame.pbx_ctrl_page.aidr |= aidr_mask;

    /* Act */
    mhu_err = mhu_v3_x_driver_init(&MHU_PBX_DEV);

    /* Cleanup */
    mhu_pbx_frame.pbx_ctrl_page.aidr = MHU_PBX_AIDR_RESET_VALUE;

    /* Assert */
    TEST_ASSERT_EQUAL_UINT32(expected_pbx_ctrl,
                             mhu_pbx_frame.pbx_ctrl_page.pbx_ctrl);
    TEST_ASSERT_EQUAL_UINT32(expected_mhu_init_st, MHU_PBX_DEV.is_initialized);
    TEST_ASSERT_EQUAL(expected_err, mhu_err);
}

TEST_CASE(false, 0xf0u, 0x0u, false, MHU_V_3_X_ERR_INIT_UNSUPPORTED_VERSION)
TEST_CASE(false, 0x0fu, 0x0u, false, MHU_V_3_X_ERR_INIT_UNSUPPORTED_VERSION)
TEST_CASE(false, 0x0u, MHU_V3_OP_REQ, true, MHU_V_3_X_ERR_NONE)
void test_mhu_v3_x_driver_init_mbx(bool mhu_init_st, uint32_t aidr_mask,
                                   uint32_t expected_mbx_ctrl,
                                   bool expected_mhu_init_st,
                                   enum mhu_v3_x_error_t expected_err)
{
    enum mhu_v3_x_error_t mhu_err;

    /* Prepare */
    MHU_MBX_DEV.is_initialized = mhu_init_st;
    mhu_mbx_frame.mbx_ctrl_page.aidr |= aidr_mask;

    /* Act */
    mhu_err = mhu_v3_x_driver_init(&MHU_MBX_DEV);

    /* Cleanup */
    mhu_mbx_frame.mbx_ctrl_page.aidr = MHU_MBX_AIDR_RESET_VALUE;

    /* Assert */
    TEST_ASSERT_EQUAL_UINT32(expected_mbx_ctrl,
                             mhu_mbx_frame.mbx_ctrl_page.mbx_ctrl);
    TEST_ASSERT_EQUAL_UINT32(expected_mhu_init_st, MHU_MBX_DEV.is_initialized);
    TEST_ASSERT_EQUAL(expected_err, mhu_err);
}

void test_mhu_v3_x_get_num_channel_implemented_invalid_dev_param(void)
{
    enum mhu_v3_x_error_t mhu_err;
    enum mhu_v3_x_channel_type_t ch_type;
    uint8_t num_ch;

    /* Act */
    mhu_err = mhu_v3_x_get_num_channel_implemented(NULL, ch_type, &num_ch);

    /* Assert */
    TEST_ASSERT_EQUAL(MHU_V_3_X_ERR_GET_NUM_CHANNEL_INVALID_PARAM, mhu_err);
}

void test_mhu_v3_x_get_num_channel_implemented_pbx_invalid_num_ch_param(void)
{
    enum mhu_v3_x_error_t mhu_err;
    enum mhu_v3_x_channel_type_t ch_type;

    /* Act */
    mhu_err = mhu_v3_x_get_num_channel_implemented(&MHU_PBX_DEV, ch_type, NULL);

    /* Assert */
    TEST_ASSERT_EQUAL(MHU_V_3_X_ERR_GET_NUM_CHANNEL_INVALID_PARAM, mhu_err);
}

TEST_CASE(MHU_V3_X_CHANNEL_TYPE_COUNT, 0x00u,
          MHU_V_3_X_ERR_GET_NUM_CHANNEL_UNSUPPORTED)
TEST_CASE(MHU_V3_X_CHANNEL_TYPE_DBCH, 0x10u, MHU_V_3_X_ERR_NONE)
void test_mhu_v3_x_get_num_channel_implemented_pbx(
    enum mhu_v3_x_channel_type_t ch_type, uint8_t expected_num_ch,
    enum mhu_v3_x_error_t expected_err)
{
    enum mhu_v3_x_error_t mhu_err;
    uint8_t num_ch;

    /* Prepare */
    num_ch = 0;

    /* Act */
    mhu_err =
        mhu_v3_x_get_num_channel_implemented(&MHU_PBX_DEV, ch_type, &num_ch);

    /* Assert */
    TEST_ASSERT_EQUAL_UINT32(expected_num_ch, num_ch);
    TEST_ASSERT_EQUAL(expected_err, mhu_err);
}

TEST_CASE(MHU_V3_X_CHANNEL_TYPE_COUNT, 0x00u,
          MHU_V_3_X_ERR_GET_NUM_CHANNEL_UNSUPPORTED)
TEST_CASE(MHU_V3_X_CHANNEL_TYPE_DBCH, 0x10u, MHU_V_3_X_ERR_NONE)
void test_mhu_v3_x_get_num_channel_implemented_mbx(
    enum mhu_v3_x_channel_type_t ch_type, uint8_t expected_num_ch,
    enum mhu_v3_x_error_t expected_err)
{
    enum mhu_v3_x_error_t mhu_err;
    uint8_t num_ch;

    /* Prepare */
    num_ch = 0;

    /* Act */
    mhu_err =
        mhu_v3_x_get_num_channel_implemented(&MHU_MBX_DEV, ch_type, &num_ch);

    /* Assert */
    TEST_ASSERT_EQUAL_UINT32(expected_num_ch, num_ch);
    TEST_ASSERT_EQUAL(expected_err, mhu_err);
}

void test_mhu_v3_x_doorbell_clear_mbx_invalid_dev_param(void)
{
    enum mhu_v3_x_error_t mhu_err;
    uint32_t channel;
    uint32_t mask;

    /* Prepare */
    channel = 0;
    mask = 0xf;

    /* Act */
    mhu_err = mhu_v3_x_doorbell_clear(NULL, channel, mask);

    /* Assert */
    TEST_ASSERT_EQUAL(MHU_V_3_X_ERR_DOORBELL_CLEAR_INVALID_PARAM, mhu_err);
}

void test_mhu_v3_x_doorbell_clear_mbx_mhu_init_fails(void)
{
    enum mhu_v3_x_error_t mhu_err;
    uint32_t channel;
    uint32_t mask;

    /* Prepare */
    channel = 0;
    mask = 0xf;

    /* Prepare */
    mhu_mbx_frame.mbx_ctrl_page.aidr |= 0xff;

    /* Act */
    mhu_err = mhu_v3_x_doorbell_clear(&MHU_MBX_DEV, channel, mask);

    /* Cleanup */
    mhu_mbx_frame.mbx_ctrl_page.aidr = MHU_MBX_AIDR_RESET_VALUE;

    /* Assert */
    TEST_ASSERT_EQUAL(MHU_V_3_X_ERR_INIT_UNSUPPORTED_VERSION, mhu_err);
}

void test_mhu_v3_x_doorbell_clear_mbx_wrong_mhu_type(void)
{
    enum mhu_v3_x_error_t mhu_err;
    uint32_t channel;
    uint32_t mask;

    /* Prepare */
    channel = 0;
    mask = 0xf;

    /* Act */
    mhu_err = mhu_v3_x_doorbell_clear(&MHU_PBX_DEV, channel, mask);

    /* Assert */
    TEST_ASSERT_EQUAL(MHU_V_3_X_ERR_DOORBELL_CLEAR_INVALID_PARAM, mhu_err);
}

void test_mhu_v3_x_doorbell_clear_mbx_ok(void)
{
    enum mhu_v3_x_error_t mhu_err;
    uint32_t channel;
    uint32_t mask;

    /* Prepare */
    channel = 0;
    mask = 0xFAFAAFAF;

    /* Act */
    mhu_err = mhu_v3_x_doorbell_clear(&MHU_MBX_DEV, channel, mask);

    /* Assert */
    TEST_ASSERT_EQUAL_UINT32(mask, mhu_mbx_frame.mdbcw_page.mdbcw_clr);
    TEST_ASSERT_EQUAL(MHU_V_3_X_ERR_NONE, mhu_err);
}

void test_mhu_v3_x_doorbell_write_pbx_invalid_dev_param(void)
{
    enum mhu_v3_x_error_t mhu_err;
    uint32_t channel;
    uint32_t value;

    /* Prepare */
    channel = 0;

    /* Act */
    mhu_err = mhu_v3_x_doorbell_write(NULL, channel, value);

    /* Assert */
    TEST_ASSERT_EQUAL(MHU_V_3_X_ERR_DOORBELL_WRITE_INVALID_PARAM, mhu_err);
}

void test_mhu_v3_x_doorbell_write_pbx_mhu_init_fails(void)
{
    enum mhu_v3_x_error_t mhu_err;
    uint32_t channel;
    uint32_t value;

    /* Prepare */
    channel = 0;

    /* Prepare */
    mhu_pbx_frame.pbx_ctrl_page.aidr |= 0xff;

    /* Act */
    mhu_err = mhu_v3_x_doorbell_write(&MHU_PBX_DEV, channel, value);

    /* Cleanup */
    mhu_pbx_frame.pbx_ctrl_page.aidr = MHU_PBX_AIDR_RESET_VALUE;

    /* Assert */
    TEST_ASSERT_EQUAL(MHU_V_3_X_ERR_INIT_UNSUPPORTED_VERSION, mhu_err);
}

void test_mhu_v3_x_doorbell_write_pbx_wrong_mhu_type(void)
{
    enum mhu_v3_x_error_t mhu_err;
    uint32_t channel;
    uint32_t value;

    /* Prepare */
    channel = 0;

    /* Act */
    mhu_err = mhu_v3_x_doorbell_write(&MHU_MBX_DEV, channel, value);

    /* Assert */
    TEST_ASSERT_EQUAL(MHU_V_3_X_ERR_DOORBELL_WRITE_INVALID_PARAM, mhu_err);
}

void test_mhu_v3_x_doorbell_write_pbx_ok(void)
{
    enum mhu_v3_x_error_t mhu_err;
    uint32_t channel;
    uint32_t value;

    /* Prepare */
    channel = 0;
    value = 0xFAFAAFAF;

    /* Act */
    mhu_err = mhu_v3_x_doorbell_write(&MHU_PBX_DEV, channel, value);

    /* Assert */
    TEST_ASSERT_EQUAL_UINT32(value, mhu_pbx_frame.pdbcw_page.pdbcw_set);
    TEST_ASSERT_EQUAL(MHU_V_3_X_ERR_NONE, mhu_err);
}

void test_mhu_v3_x_doorbell_read_invalid_dev_param(void)
{
    enum mhu_v3_x_error_t mhu_err;
    uint32_t channel;
    uint32_t value;

    /* Prepare */
    channel = 0;

    /* Act */
    mhu_err = mhu_v3_x_doorbell_read(NULL, channel, &value);

    /* Assert */
    TEST_ASSERT_EQUAL(MHU_V_3_X_ERR_DOORBELL_READ_INVALID_PARAM, mhu_err);
}

void test_mhu_v3_x_doorbell_read_pbx_invalid_value_param(void)
{
    enum mhu_v3_x_error_t mhu_err;
    uint32_t channel;

    /* Prepare */
    channel = 0;

    /* Act */
    mhu_err = mhu_v3_x_doorbell_read(&MHU_PBX_DEV, channel, NULL);

    /* Assert */
    TEST_ASSERT_EQUAL(MHU_V_3_X_ERR_DOORBELL_READ_INVALID_PARAM, mhu_err);
}

void test_mhu_v3_x_doorbell_read_pbx_mhu_init_fails(void)
{
    enum mhu_v3_x_error_t mhu_err;
    uint32_t channel;
    uint32_t value;

    /* Prepare */
    channel = 0;

    /* Prepare */
    mhu_pbx_frame.pbx_ctrl_page.aidr |= 0xff;

    /* Act */
    mhu_err = mhu_v3_x_doorbell_read(&MHU_PBX_DEV, channel, &value);

    /* Cleanup */
    mhu_pbx_frame.pbx_ctrl_page.aidr = MHU_PBX_AIDR_RESET_VALUE;

    /* Assert */
    TEST_ASSERT_EQUAL(MHU_V_3_X_ERR_INIT_UNSUPPORTED_VERSION, mhu_err);
}

void test_mhu_v3_x_doorbell_read_pbx_ok(void)
{
    enum mhu_v3_x_error_t mhu_err;
    uint32_t channel;
    uint32_t value;
    uint32_t expected_value;

    /* Prepare */
    channel = 0;
    expected_value = 0xFAFAAFAF;
    mhu_pbx_frame.pdbcw_page.pdbcw_st = expected_value;

    /* Act */
    mhu_err = mhu_v3_x_doorbell_read(&MHU_PBX_DEV, channel, &value);

    /* Cleanup */
    mhu_pbx_frame.pdbcw_page.pdbcw_st = MHU_PBX_DBCW_ST_RESET_VALUE;

    /* Assert */
    TEST_ASSERT_EQUAL_UINT32(value, expected_value);
    TEST_ASSERT_EQUAL(MHU_V_3_X_ERR_NONE, mhu_err);
}

void test_mhu_v3_x_doorbell_read_mbx_ok(void)
{
    enum mhu_v3_x_error_t mhu_err;
    uint32_t channel;
    uint32_t value;
    uint32_t expected_value;

    /* Prepare */
    channel = 0;
    expected_value = 0xFAFAAFAF;
    mhu_mbx_frame.mdbcw_page.mdbcw_st = expected_value;

    /* Act */
    mhu_err = mhu_v3_x_doorbell_read(&MHU_MBX_DEV, channel, &value);

    /* Cleanup */
    mhu_mbx_frame.mdbcw_page.mdbcw_st = MHU_MBX_DBCW_ST_RESET_VALUE;

    /* Assert */
    TEST_ASSERT_EQUAL_UINT32(value, expected_value);
    TEST_ASSERT_EQUAL(MHU_V_3_X_ERR_NONE, mhu_err);
}

void test_mhu_v3_x_doorbell_mask_set_mbx_invalid_dev_param(void)
{
    enum mhu_v3_x_error_t mhu_err;
    uint32_t channel;
    uint32_t mask;

    /* Prepare */
    channel = 0;
    mask = 0xf;

    /* Act */
    mhu_err = mhu_v3_x_doorbell_mask_set(NULL, channel, mask);

    /* Assert */
    TEST_ASSERT_EQUAL(MHU_V_3_X_ERR_DOORBELL_MASK_SET_INVALID_PARAM, mhu_err);
}

void test_mhu_v3_x_doorbell_mask_set_mbx_mhu_init_fails(void)
{
    enum mhu_v3_x_error_t mhu_err;
    uint32_t channel;
    uint32_t mask;

    /* Prepare */
    channel = 0;
    mask = 0xf;
    mhu_mbx_frame.mbx_ctrl_page.aidr |= 0xff;

    /* Act */
    mhu_err = mhu_v3_x_doorbell_mask_set(&MHU_MBX_DEV, channel, mask);

    /* Cleanup */
    mhu_mbx_frame.mbx_ctrl_page.aidr = MHU_MBX_AIDR_RESET_VALUE;

    /* Assert */
    TEST_ASSERT_EQUAL(MHU_V_3_X_ERR_INIT_UNSUPPORTED_VERSION, mhu_err);
}

void test_mhu_v3_x_doorbell_mask_set_mbx_wrong_mhu_type(void)
{
    enum mhu_v3_x_error_t mhu_err;
    uint32_t channel;
    uint32_t mask;

    /* Prepare */
    channel = 0;
    mask = 0xf;

    /* Act */
    mhu_err = mhu_v3_x_doorbell_mask_set(&MHU_PBX_DEV, channel, mask);

    /* Assert */
    TEST_ASSERT_EQUAL(MHU_V_3_X_ERR_DOORBELL_MASK_SET_INVALID_PARAM, mhu_err);
}

void test_mhu_v3_x_doorbell_mask_set_mbx_ok(void)
{
    enum mhu_v3_x_error_t mhu_err;
    uint32_t channel;
    uint32_t mask;

    /* Prepare */
    channel = 0;
    mask = 0xFAFAAFAF;

    /* Act */
    mhu_err = mhu_v3_x_doorbell_mask_set(&MHU_MBX_DEV, channel, mask);

    /* Assert */
    TEST_ASSERT_EQUAL_UINT32(mask, mhu_mbx_frame.mdbcw_page.mdbcw_msk_set);
    TEST_ASSERT_EQUAL(MHU_V_3_X_ERR_NONE, mhu_err);
}

void test_mhu_v3_x_doorbell_mask_clear_mbx_invalid_dev_param(void)
{
    enum mhu_v3_x_error_t mhu_err;
    uint32_t channel;
    uint32_t mask;

    /* Prepare */
    channel = 0;
    mask = 0xf;

    /* Act */
    mhu_err = mhu_v3_x_doorbell_mask_clear(NULL, channel, mask);

    /* Assert */
    TEST_ASSERT_EQUAL(MHU_V_3_X_ERR_DOORBELL_MASK_CLEAR_INVALID_PARAM, mhu_err);
}

void test_mhu_v3_x_doorbell_mask_clear_mbx_mhu_init_fails(void)
{
    enum mhu_v3_x_error_t mhu_err;
    uint32_t channel;
    uint32_t mask;

    /* Prepare */
    channel = 0;
    mask = 0xf;
    mhu_mbx_frame.mbx_ctrl_page.aidr |= 0xff;

    /* Act */
    mhu_err = mhu_v3_x_doorbell_mask_clear(&MHU_MBX_DEV, channel, mask);

    /* Cleanup */
    mhu_mbx_frame.mbx_ctrl_page.aidr = MHU_MBX_AIDR_RESET_VALUE;

    /* Assert */
    TEST_ASSERT_EQUAL(MHU_V_3_X_ERR_INIT_UNSUPPORTED_VERSION, mhu_err);
}

void test_mhu_v3_x_doorbell_mask_clear_mbx_wrong_mhu_type(void)
{
    enum mhu_v3_x_error_t mhu_err;
    uint32_t channel;
    uint32_t mask;

    /* Prepare */
    channel = 0;
    mask = 0xf;

    /* Act */
    mhu_err = mhu_v3_x_doorbell_mask_clear(&MHU_PBX_DEV, channel, mask);

    /* Assert */
    TEST_ASSERT_EQUAL(MHU_V_3_X_ERR_DOORBELL_MASK_CLEAR_INVALID_PARAM, mhu_err);
}

void test_mhu_v3_x_doorbell_mask_clear_mbx_ok(void)
{
    enum mhu_v3_x_error_t mhu_err;
    uint32_t channel;
    uint32_t mask;

    /* Prepare */
    channel = 0;
    mask = 0xFAFAAFAF;

    /* Act */
    mhu_err = mhu_v3_x_doorbell_mask_clear(&MHU_MBX_DEV, channel, mask);

    /* Assert */
    TEST_ASSERT_EQUAL_UINT32(mask, mhu_mbx_frame.mdbcw_page.mdbcw_msk_clr);
    TEST_ASSERT_EQUAL(MHU_V_3_X_ERR_NONE, mhu_err);
}

void test_mhu_v3_x_doorbell_mask_get_mbx_invalid_dev_param(void)
{
    enum mhu_v3_x_error_t mhu_err;
    uint32_t channel;
    uint32_t mask_status;

    /* Prepare */
    channel = 0;

    /* Act */
    mhu_err = mhu_v3_x_doorbell_mask_get(NULL, channel, &mask_status);

    /* Assert */
    TEST_ASSERT_EQUAL(MHU_V_3_X_ERR_DOORBELL_MASK_GET_INVALID_PARAM, mhu_err);
}

void test_mhu_v3_x_doorbell_mask_get_mbx_mhu_init_fails(void)
{
    enum mhu_v3_x_error_t mhu_err;
    uint32_t channel;
    uint32_t mask_status;

    /* Prepare */
    channel = 0;
    mhu_mbx_frame.mbx_ctrl_page.aidr |= 0xff;

    /* Act */
    mhu_err = mhu_v3_x_doorbell_mask_get(&MHU_MBX_DEV, channel, &mask_status);

    /* Cleanup */
    mhu_mbx_frame.mbx_ctrl_page.aidr = MHU_MBX_AIDR_RESET_VALUE;

    /* Assert */
    TEST_ASSERT_EQUAL(MHU_V_3_X_ERR_INIT_UNSUPPORTED_VERSION, mhu_err);
}

void test_mhu_v3_x_doorbell_mask_get_mbx_wrong_mhu_type(void)
{
    enum mhu_v3_x_error_t mhu_err;
    uint32_t channel;
    uint32_t mask_status;

    /* Prepare */
    channel = 0;

    /* Act */
    mhu_err = mhu_v3_x_doorbell_mask_get(&MHU_PBX_DEV, channel, &mask_status);

    /* Assert */
    TEST_ASSERT_EQUAL(MHU_V_3_X_ERR_DOORBELL_MASK_GET_INVALID_PARAM, mhu_err);
}

void test_mhu_v3_x_doorbell_mask_get_mbx_ok(void)
{
    enum mhu_v3_x_error_t mhu_err;
    uint32_t channel;
    uint32_t expected_mask_status;
    uint32_t mask_status;

    /* Prepare */
    expected_mask_status = 0xFAFAAFAF;
    mhu_mbx_frame.mdbcw_page.mdbcw_msk_st = expected_mask_status;
    channel = 0;

    /* Act */
    mhu_err = mhu_v3_x_doorbell_mask_get(&MHU_MBX_DEV, channel, &mask_status);

    /* Cleanup */
    mhu_mbx_frame.mdbcw_page.mdbcw_msk_st = MHU_MBX_DBCW_MSK_ST_RESET_VALUE;

    /* Assert */
    TEST_ASSERT_EQUAL_UINT32(expected_mask_status, mask_status);
    TEST_ASSERT_EQUAL(MHU_V_3_X_ERR_NONE, mhu_err);
}

void test_mhu_v3_x_channel_interrupt_enable_invalid_dev_param(void)
{
    enum mhu_v3_x_error_t mhu_err;
    enum mhu_v3_x_channel_type_t ch_type;
    uint32_t channel;

    /* Prepare */
    channel = 0;
    ch_type = MHU_V3_X_CHANNEL_TYPE_DBCH;

    /* Act */
    mhu_err = mhu_v3_x_channel_interrupt_enable(NULL, channel, ch_type);

    /* Assert */
    TEST_ASSERT_EQUAL(MHU_V_3_X_ERR_INTERRUPT_ENABLE_INVALID_PARAM, mhu_err);
}

void test_mhu_v3_x_channel_interrupt_enable_pbx_mhu_init_fails(void)
{
    enum mhu_v3_x_error_t mhu_err;
    enum mhu_v3_x_channel_type_t ch_type;
    uint32_t channel;

    /* Prepare */
    channel = 0;
    ch_type = MHU_V3_X_CHANNEL_TYPE_DBCH;
    mhu_pbx_frame.pbx_ctrl_page.aidr |= 0xff;

    /* Act */
    mhu_err = mhu_v3_x_channel_interrupt_enable(&MHU_PBX_DEV, channel, ch_type);

    /* Cleanup */
    mhu_pbx_frame.pbx_ctrl_page.aidr = MHU_PBX_AIDR_RESET_VALUE;

    /* Assert */
    TEST_ASSERT_EQUAL(MHU_V_3_X_ERR_INIT_UNSUPPORTED_VERSION, mhu_err);
}

TEST_CASE(MHU_V3_X_CHANNEL_TYPE_COUNT, 0x0u, 0x01u,
          MHU_V_3_X_ERR_INTERRUPT_ENABLE_UNSUPPORTED)
TEST_CASE(MHU_V3_X_CHANNEL_TYPE_DBCH, 0x1u, 0x01u, MHU_V_3_X_ERR_NONE)
void test_mhu_v3_x_channel_interrupt_enable_pbx(
    enum mhu_v3_x_channel_type_t ch_type, uint32_t expected_pdbcw_int_en,
    uint32_t expected_pdbcw_ctrl, enum mhu_v3_x_error_t expected_err)
{
    enum mhu_v3_x_error_t mhu_err;
    uint32_t channel;

    /* Prepare */
    channel = 0;

    /* Act */
    mhu_err = mhu_v3_x_channel_interrupt_enable(&MHU_PBX_DEV, channel, ch_type);

    /* Assert */
    TEST_ASSERT_EQUAL_UINT32(expected_pdbcw_int_en,
                             mhu_pbx_frame.pdbcw_page.pdbcw_int_en);
    TEST_ASSERT_EQUAL_UINT32(expected_pdbcw_ctrl,
                             mhu_pbx_frame.pdbcw_page.pdbcw_ctrl);
    TEST_ASSERT_EQUAL(expected_err, mhu_err);
}

TEST_CASE(MHU_V3_X_CHANNEL_TYPE_COUNT, 0x1u,
          MHU_V_3_X_ERR_INTERRUPT_ENABLE_UNSUPPORTED)
TEST_CASE(MHU_V3_X_CHANNEL_TYPE_DBCH, 0x1u, MHU_V_3_X_ERR_NONE)
void test_mhu_v3_x_channel_interrupt_enable_mbx(
    enum mhu_v3_x_channel_type_t ch_type, uint32_t expected_mdbcw_ctrl,
    enum mhu_v3_x_error_t expected_err)
{
    enum mhu_v3_x_error_t mhu_err;
    uint32_t channel;

    /* Prepare */
    channel = 0;

    /* Act */
    mhu_err = mhu_v3_x_channel_interrupt_enable(&MHU_MBX_DEV, channel, ch_type);

    /* Assert */
    TEST_ASSERT_EQUAL_UINT32(expected_mdbcw_ctrl,
                             mhu_mbx_frame.mdbcw_page.mdbcw_ctrl);
    TEST_ASSERT_EQUAL(expected_err, mhu_err);
}

void test_mhu_v3_x_channel_interrupt_disable_invalid_dev_param(void)
{
    enum mhu_v3_x_error_t mhu_err;
    enum mhu_v3_x_channel_type_t ch_type;
    uint32_t channel;

    /* Act */
    mhu_err = mhu_v3_x_channel_interrupt_disable(NULL, channel, ch_type);

    /* Assert */
    TEST_ASSERT_EQUAL(MHU_V_3_X_ERR_INTERRUPT_DISABLE_INVALID_PARAM, mhu_err);
}

void test_mhu_v3_x_channel_interrupt_disable_pbx_mhu_init_fails(void)
{
    enum mhu_v3_x_error_t mhu_err;
    enum mhu_v3_x_channel_type_t ch_type;
    uint32_t channel;

    /* Prepare */
    channel = 0;
    mhu_pbx_frame.pbx_ctrl_page.aidr |= 0xff;

    /* Act */
    mhu_err =
        mhu_v3_x_channel_interrupt_disable(&MHU_PBX_DEV, channel, ch_type);

    /* Cleanup */
    mhu_pbx_frame.pbx_ctrl_page.aidr = MHU_PBX_AIDR_RESET_VALUE;

    /* Assert */
    TEST_ASSERT_EQUAL(MHU_V_3_X_ERR_INIT_UNSUPPORTED_VERSION, mhu_err);
}

TEST_CASE(MHU_V3_X_CHANNEL_TYPE_COUNT, 0x0u, 0x1u, 0x1u,
          MHU_V_3_X_ERR_INTERRUPT_DISABLE_UNSUPPORTED)
TEST_CASE(MHU_V3_X_CHANNEL_TYPE_DBCH, 0x1u, 0x0u, 0x0u, MHU_V_3_X_ERR_NONE)
void test_mhu_v3_x_channel_interrupt_disable_pbx(
    enum mhu_v3_x_channel_type_t ch_type, uint32_t expected_pdbcw_int_clr,
    uint32_t expected_pdbcw_int_en, uint32_t expected_pdbcw_ctrl,
    enum mhu_v3_x_error_t expected_err)
{
    enum mhu_v3_x_error_t mhu_err;
    uint32_t channel;

    /* Prepare */
    channel = 0;
    mhu_pbx_frame.pdbcw_page.pdbcw_int_en = 0x1;

    /* Act */
    mhu_err =
        mhu_v3_x_channel_interrupt_disable(&MHU_PBX_DEV, channel, ch_type);

    /* Assert */
    TEST_ASSERT_EQUAL_UINT32(expected_pdbcw_int_clr,
                             mhu_pbx_frame.pdbcw_page.pdbcw_int_clr);
    TEST_ASSERT_EQUAL_UINT32(expected_pdbcw_int_en,
                             mhu_pbx_frame.pdbcw_page.pdbcw_int_en);
    TEST_ASSERT_EQUAL_UINT32(expected_pdbcw_ctrl,
                             mhu_pbx_frame.pdbcw_page.pdbcw_ctrl);
    TEST_ASSERT_EQUAL(expected_err, mhu_err);
}

TEST_CASE(MHU_V3_X_CHANNEL_TYPE_COUNT, 0x1u,
          MHU_V_3_X_ERR_INTERRUPT_DISABLE_UNSUPPORTED)
TEST_CASE(MHU_V3_X_CHANNEL_TYPE_DBCH, 0x0u, MHU_V_3_X_ERR_NONE)
void test_mhu_v3_x_channel_interrupt_disable_mbx(
    enum mhu_v3_x_channel_type_t ch_type, uint32_t expected_mdbcw_ctrl,
    enum mhu_v3_x_error_t expected_err)
{
    enum mhu_v3_x_error_t mhu_err;
    uint32_t channel;

    /* Prepare */
    channel = 0;

    /* Act */
    mhu_err =
        mhu_v3_x_channel_interrupt_disable(&MHU_MBX_DEV, channel, ch_type);

    /* Assert */
    TEST_ASSERT_EQUAL_UINT32(expected_mdbcw_ctrl,
                             mhu_mbx_frame.mdbcw_page.mdbcw_ctrl);
    TEST_ASSERT_EQUAL(expected_err, mhu_err);
}

void test_mhu_v3_x_channel_interrupt_clear_invalid_dev_param(void)
{
    enum mhu_v3_x_error_t mhu_err;
    enum mhu_v3_x_channel_type_t ch_type;
    uint32_t channel;

    /* Prepare */
    channel = 0;

    /* Act */
    mhu_err = mhu_v3_x_channel_interrupt_clear(NULL, channel, ch_type);

    /* Assert */
    TEST_ASSERT_EQUAL(MHU_V_3_X_ERR_INTERRUPT_CLEAR_INVALID_PARAM, mhu_err);
}

void test_mhu_v3_x_channel_interrupt_clear_pbx_mhu_init_fails(void)
{
    enum mhu_v3_x_error_t mhu_err;
    enum mhu_v3_x_channel_type_t ch_type;
    uint32_t channel;

    /* Prepare */
    channel = 0;
    mhu_pbx_frame.pbx_ctrl_page.aidr |= 0xff;

    /* Act */
    mhu_err = mhu_v3_x_channel_interrupt_clear(&MHU_PBX_DEV, channel, ch_type);

    /* Cleanup */
    mhu_pbx_frame.pbx_ctrl_page.aidr = MHU_PBX_AIDR_RESET_VALUE;

    /* Assert */
    TEST_ASSERT_EQUAL(MHU_V_3_X_ERR_INIT_UNSUPPORTED_VERSION, mhu_err);
}

void test_mhu_v3_x_channel_interrupt_clear_pbx_wrong_mhu_type(void)
{
    enum mhu_v3_x_error_t mhu_err;
    enum mhu_v3_x_channel_type_t ch_type;
    uint32_t channel;

    /* Prepare */
    channel = 0;
    ch_type = MHU_V3_X_CHANNEL_TYPE_DBCH;

    /* Act */
    mhu_err = mhu_v3_x_channel_interrupt_clear(&MHU_MBX_DEV, channel, ch_type);

    /* Assert */
    TEST_ASSERT_EQUAL(MHU_V_3_X_ERR_INTERRUPT_CLEAR_INVALID_PARAM, mhu_err);
}

TEST_CASE(MHU_V3_X_CHANNEL_TYPE_COUNT, 0x0u,
          MHU_V_3_X_ERR_INTERRUPT_CLEAR_UNSUPPORTED)
TEST_CASE(MHU_V3_X_CHANNEL_TYPE_DBCH, 0x1u, MHU_V_3_X_ERR_NONE)
void test_mhu_v3_x_channel_interrupt_clear_pbx(
    enum mhu_v3_x_channel_type_t ch_type, uint32_t expected_pdbcw_int_clr,
    enum mhu_v3_x_error_t expected_err)
{
    enum mhu_v3_x_error_t mhu_err;
    uint32_t channel;

    /* Prepare */
    channel = 0;

    /* Act */
    mhu_err = mhu_v3_x_channel_interrupt_clear(&MHU_PBX_DEV, channel, ch_type);

    /* Assert */
    TEST_ASSERT_EQUAL_UINT32(expected_pdbcw_int_clr,
                             mhu_pbx_frame.pdbcw_page.pdbcw_int_clr);
    TEST_ASSERT_EQUAL(expected_err, mhu_err);
}
