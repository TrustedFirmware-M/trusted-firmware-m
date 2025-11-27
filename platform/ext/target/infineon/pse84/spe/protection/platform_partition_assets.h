/*
 * Copyright (c) 2025 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef PLATFORM_PARTITION_ASSETS_H
#define PLATFORM_PARTITION_ASSETS_H

#include <stddef.h>

#include "array.h"
#include "load/asset_defs.h"
#include "region_defs.h"

/* This file exports custom partition assets for the platform.
 * IFX_{{partition.manifest.name|upper}}_CUSTOM_ASSETS and
 * IFX_{{partition.manifest.name|upper}}_CUSTOM_PERI_ASSETS patterns are used to
 * define custom assets for the partition. */

/* Define custom assets only if explicitly required by file that includes this
 * header. This is needed to avoid multiple definitions of the same assets in
 * different translation units. */
#ifdef IFX_PROVIDE_PARTITION_ASSETS

/********************************* Attestation ********************************/

#ifdef TFM_PARTITION_INITIAL_ATTESTATION
const cy_en_prot_region_t ifx_tfm_sp_initial_attestation_peri_assets[] = {
    PROT_PERI0_SRSS_GENERAL,
    PROT_PERI0_SRSS_MAIN,
};

#define IFX_TFM_SP_INITIAL_ATTESTATION_CUSTOM_PERI_ASSETS ifx_tfm_sp_initial_attestation_peri_assets
#endif /* TFM_PARTITION_INITIAL_ATTESTATION */

/****************************** IFX test service ******************************/

#ifdef IFX_PARTITION_TEST_SERVICE
const cy_en_prot_region_t ifx_ifx_test_service_partition_peri_assets[] = {
#if TEST_NS_IFX_ISOLATION_TEST
    PROT_PERI0_SRSS_GENERAL,
    PROT_PERI0_SRSS_MAIN,
    PROT_PERI0_SRSS_WDT,
#endif /* TEST_NS_IFX_ISOLATION_TEST */
};

#define IFX_IFX_TEST_SERVICE_PARTITION_CUSTOM_PERI_ASSETS ifx_ifx_test_service_partition_peri_assets
#endif /* IFX_PARTITION_TEST_SERVICE */

#endif /* IFX_PROVIDE_PARTITION_ASSETS */

#endif /* PLATFORM_PARTITION_ASSETS_H */
