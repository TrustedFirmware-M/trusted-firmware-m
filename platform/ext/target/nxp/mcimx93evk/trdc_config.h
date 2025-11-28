/*
 * Copyright 2022-2023, 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "imx_trdc.h"

#define TRDC_A_BASE TRDC1_BASE
#define TRDC_W_BASE TRDC2_BASE
#define TRDC_N_BASE TRDC4_BASE

#define TCM_CODE_START          (0x0FFE0000u)
#define TCM_CODE_END            (0x0FFFFFFFu)
#define TCM_DATA_START          (0x20000000u)
#define TCM_DATA_END            (0x2001FFFFu)
#define OCRAM_START             (0x20480000u)
#define OCRAM_END               (0x2051FFFFu)

#define TCM_MBC_IDX                 1u
#define TCM_CODE_SLV_IDX            0u
#define TCM_DATA_SLV_IDX            0u
#define TCM_GLBAC_ALL_PERM_IDX      2u
#define TCM_SUBREGION_SZ            (0x1000u)

#define OCRAM_MBC_IDX                 3u
#define OCRAM_SLV_IDX1                0u
#define OCRAM_SLV_IDX2                1u
#define OCRAM_GLBAC_ALL_PERM_IDX      1u
#define OCRAM_SUBREGION_SZ            (0x4000u)

/* GLBAC7 is used for TRDC only, any setting to GLBAC7 will be ignored */
/* GLBAC6 is used for fused modules, any setting to GLBAC6 will be ignored */

/* aonmix */
struct trdc_glbac_config trdc_a_mbc_glbac[] = {
	/* MBC0 */
	{ 0, 0, SP(RW)  | SU(RW)   | NP(RW)  | NU(RW) },
	/* MBC1 */
	{ 1, 0, SP(RW)  | SU(RW)   | NP(RW)  | NU(RW) },
	{ 1, 1, SP(RW)  | SU(R)    | NP(RW)  | NU(R)  },
	{ 1, 2, SP(RWX) | SU(RWX)  | NP(RWX) | NU(RWX)  },
};

/*
 * These are only for Cortex M33 domain. Same structure as used in TF-A in format
 * { mbc_id, dom_id, mem_id, blk_id, glbac_id, secure }
 */
struct trdc_mbc_config trdc_a_mbc[] = {
    { 0, 2, 0, MBC_BLK_ALL, 0, false }, /* MBC0 AIPS1 for M33 DID2 */
    { 0, 2, 0, 79, 0, true }, /* MBC0 AIPS1 for M33 DID2 */

    { 0, 2, 1, MBC_BLK_ALL, 0, false }, /* MBC0 Sentinel_SOC_In for M33 DID2 */
    { 0, 2, 2, MBC_BLK_ALL, 0, false }, /* MBC0 GPIO1 for M33 DID2 */

    /*
     * MBC1 CM33 code and system TCM is configured secure by TF-A.
     * Leave it as it is. Later required regions will be configured non-secure based on TF-M region symbols
     */
    { 1, 2, 0, MBC_BLK_ALL, 2, true  }, /* MBC1 CM33 code TCM for M33 DID2 */
    { 1, 2, 1, MBC_BLK_ALL, 2, true  }, /* MBC1 CM33 system TCM for M33 DID2 */
};

/* wakeupmix */
struct trdc_glbac_config trdc_w_mbc_glbac[] = {
	/* MBC0 */
	{ 0, 0, SP(RW) | SU(RW) | NP(RW) | NU(RW) },
	/* MBC1 */
	{ 1, 0, SP(RW) | SU(RW) | NP(RW) | NU(RW) },
};

/*
 * These are only for Cortex M33 domain. Same structure as used in TF-A in format
 * { mbc_id, dom_id, mem_id, blk_id, glbac_id, secure }
 */
struct trdc_mbc_config trdc_w_mbc[] = {
    { 0, 2, 0, MBC_BLK_ALL, 0, false}, /* MBC0 AIPS2 for M33 DID2 */
    { 0, 2, 1, MBC_BLK_ALL, 0, false}, /* MBC0 GPIO2_In for M33 DID2 */
    { 0, 2, 2, MBC_BLK_ALL, 0, false}, /* MBC0 GPIO3 for M33 DID2 */
    { 0, 2, 3, MBC_BLK_ALL, 0, false}, /* MBC0 DAP  for M33 DID2 */
    { 1, 2, 0, MBC_BLK_ALL, 0, false}, /* MBC1 AIPS3 for M33 DID2 */
    { 1, 2, 1, MBC_BLK_ALL, 0, false}, /* MBC1 AHB_ISPAP for M33 DID2 */
    { 1, 2, 2, MBC_BLK_ALL, 0, true },  /* MBC1 NIC_MAIN_GPV for M33 DID2 */
    { 1, 2, 3, MBC_BLK_ALL, 0, false}, /* MBC1 GPIO4 for M33 DID2 */
};
/* nicmix */
struct trdc_glbac_config trdc_n_mbc_glbac[] = {
	/* MBC0 */
	{ 0, 0, SP(RW) | SU(RW) | NP(RW) | NU(RW) },
	/* MBC1 */
	{ 1, 0, SP(RW) | SU(RW) | NP(RW) | NU(RW) },
	/* MBC2 */
	{ 2, 0, SP(RW) | SU(RW) | NP(RW) | NU(RW) },
	{ 2, 1, SP(R) | SU(R) | NP(R) | NU(R) },
	/* MBC3 */
	{ 3, 0, SP(RW) | SU(RW) | NP(RW) | NU(RW) },
	{ 3, 1, SP(RWX) | SU(RWX) | NP(RWX) | NU(RWX) },
};

/*
 * These are only for Cortex M33 domain. Same structure as used in TF-A in format
 * { mbc_id, dom_id, mem_id, blk_id, glbac_id, secure }
 */
struct trdc_mbc_config trdc_n_mbc[] = {

    { 0, 2, 0, MBC_BLK_ALL, 0, false}, /* MBC0 DDRCFG for M33 DID2 */
    { 0, 2, 1, MBC_BLK_ALL, 0, false}, /* MBC0 AIPS4 for M33 DID2 */
    { 0, 2, 2, MBC_BLK_ALL, 0, false}, /* MBC0 MEDIAMIX for M33 DID2 */
    { 0, 2, 3, MBC_BLK_ALL, 0, false}, /* MBC0 HSIOMIX for M33 DID2 */
    { 1, 2, 0, MBC_BLK_ALL, 0, false}, /* MBC1 MTR_DCA, TCU, TROUT for M33 DID2 */
    { 1, 2, 1, MBC_BLK_ALL, 0, false}, /* MBC1 MTR_DCA, TCU, TROUT for M33 DID2 */
    { 1, 2, 2, MBC_BLK_ALL, 0, false}, /* MBC1 MLMIX for M33 DID2 */
    { 1, 2, 3, MBC_BLK_ALL, 0, false}, /* MBC1 MLMIX for M33 DID2 */
    { 2, 2, 0, MBC_BLK_ALL, 1, false}, /* MBC2 GIC for M33 DID2 */
    { 2, 2, 1, MBC_BLK_ALL, 1, false}, /* MBC2 GIC for M33 DID2 */

    /* OCRAM is configured secure by TF-A. Leave it as it is.
     * Later required regions will be configured non-secure based on TF-M region symbols
     */
    { 3, 2, 0, MBC_BLK_ALL, 1, true}, /* MBC3 OCRAM for M33 DID2 */
    { 3, 2, 1, MBC_BLK_ALL, 1, true}, /* MBC3 OCRAM for M33 DID2 */
};
