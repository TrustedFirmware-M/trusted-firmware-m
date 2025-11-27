/*
 * Copyright (c) 2023-2025 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef PROJECT_MEMORY_LAYOUT_H
#define PROJECT_MEMORY_LAYOUT_H

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
*********************************** Includes ***********************************
*******************************************************************************/

#include "cymem_memory_locations.h"
#include "ifx_tfm_image_config.h"
#include "mxs22.h"

#ifdef IFX_LINKER_SCRIPT
/* Include generated memory layout files with linker script compatible syntax */
#if defined(__ARMCC_VERSION)
#if DOMAIN_S
#include "cymem_armlink_CM33_0_S.sct"
#elif DOMAIN_NS
#if IFX_CORE == IFX_CM33
#include "cymem_armlink_CM33_0.sct"
#elif IFX_CORE == IFX_CM55
#include "cymem_armlink_CM55_0.sct"
#endif /* IFX_CORE == IFX_CM33 */
#endif /* DOMAIN_S */
#elif defined(__GNUC__)
#if DOMAIN_S
#include "cymem_gnu_CM33_0_S.ld"
#elif DOMAIN_NS
#if IFX_CORE == IFX_CM33
#include "cymem_gnu_CM33_0.ld"
#elif IFX_CORE == IFX_CM55
#include "cymem_gnu_CM55_0.ld"
#endif /* IFX_CORE == IFX_CM33 */
#endif /* DOMAIN_S */
#elif defined(__ICCARM__)
#if DOMAIN_S
#include "cymem_ilinkarm_CM33_0_S.icf"
#elif DOMAIN_NS
#if IFX_CORE == IFX_CM33
#include "cymem_ilinkarm_CM33_0.icf"
#elif IFX_CORE == IFX_CM55
#include "cymem_ilinkarm_CM55_0.icf"
#endif /* IFX_CORE == IFX_CM33 */
#endif /* DOMAIN_S */
#endif /* defined(__GNUC__) */
#else /* IFX_LINKER_SCRIPT */
/* Include generated memory layout files */
#include "cymem_CM33_0_S.h"
#include "cymem_CM33_0.h"
#include "cymem_CM55_0.h"
#endif /* IFX_LINKER_SCRIPT */


/*******************************************************************************
****************************** Helper definitions ******************************
*******************************************************************************/

#define IFX_RRAM_SBUS_BASE               IFX_UNSIGNED(0x22000000)
#define IFX_RRAM_CBUS_BASE               IFX_UNSIGNED(0x02000000)
/* IFX_RRAM_SIZE is 0x0006A000 (MAIN NVM + RECLAIMED NVM) for EPC2 but only
 * 0x00040000 (MAIN NVM) for ECP4 as it does not have RECLAIMED NVM. There is no
 * easy way to add condition here, thus IFX_RRAM_SIZE is defined as bigger one
 * (0x0006A000). */
#define IFX_RRAM_SIZE                    IFX_UNSIGNED(0x0006A000)

#define IFX_SOCMEM_RAM_SBUS_BASE         IFX_UNSIGNED(0x26000000)
#define IFX_SOCMEM_RAM_CBUS_BASE         IFX_UNSIGNED(0x06000000)
#define IFX_SOCMEM_RAM_SIZE              IFX_UNSIGNED(0x00500000)

#define IFX_XIP_PORT0_SBUS_BASE          IFX_UNSIGNED(0x60000000)
#define IFX_XIP_PORT0_CBUS_BASE          IFX_UNSIGNED(0x08000000)
#define IFX_XIP_PORT0_SIZE               IFX_UNSIGNED(0x04000000)

#define IFX_XIP_PORT1_SBUS_BASE          IFX_UNSIGNED(0x64000000)
#define IFX_XIP_PORT1_CBUS_BASE          IFX_UNSIGNED(0x0C000000)
#define IFX_XIP_PORT1_SIZE               IFX_UNSIGNED(0x04000000)

#define IFX_SRAM0_SBUS_BASE              IFX_UNSIGNED(0x24000000)
#define IFX_SRAM0_CBUS_BASE              IFX_UNSIGNED(0x04000000)
#define IFX_SRAM0_SIZE                   IFX_UNSIGNED(0x00080000)

#define IFX_SRAM1_SBUS_BASE              IFX_UNSIGNED(0x24080000)
#define IFX_SRAM1_CBUS_BASE              IFX_UNSIGNED(0x04080000)
#define IFX_SRAM1_SIZE                   IFX_UNSIGNED(0x00080000)


/*******************************************************************************
******************************** Memory layout *********************************
*******************************************************************************/


/* IMPORTANT NOTE: _OFFSET/_START/_SIZE provided by configurator are defines for
 * .h/.c files but linker symbols for .ld/.sct/.icf files, so #ifdef for memory
 * areas can not be based on them, thus _LOCATION (which is always a define)
 * should used.
 */


/*******************************************************************************
****************************** Partition regions *******************************
*******************************************************************************/


/******************************** TFM ITS area ********************************/
#define IFX_TFM_ITS_OFFSET                          CYMEM_CM33_0_S_TFM_ITS_OFFSET
#define IFX_TFM_ITS_ADDR                            CYMEM_CM33_0_S_TFM_ITS_S_START
#define IFX_TFM_ITS_SIZE                            CYMEM_CM33_0_S_TFM_ITS_SIZE
#define IFX_TFM_ITS_LOCATION                        CYMEM_CM33_0_S_TFM_ITS_LOCATION


/******************************** TFM PS area *********************************/
#define IFX_TFM_PS_OFFSET                           CYMEM_CM33_0_S_TFM_PS_OFFSET
#define IFX_TFM_PS_ADDR                             CYMEM_CM33_0_S_TFM_PS_S_START
#define IFX_TFM_PS_SIZE                             CYMEM_CM33_0_S_TFM_PS_SIZE
#define IFX_TFM_PS_LOCATION                         CYMEM_CM33_0_S_TFM_PS_LOCATION


/****************************** NV counters area ******************************/
#define IFX_TFM_NV_COUNTERS_AREA_OFFSET             CYMEM_CM33_0_S_TFM_NV_COUNTERS_OFFSET
#define IFX_TFM_NV_COUNTERS_AREA_ADDR               CYMEM_CM33_0_S_TFM_NV_COUNTERS_S_START
#define IFX_TFM_NV_COUNTERS_AREA_SIZE               CYMEM_CM33_0_S_TFM_NV_COUNTERS_SIZE
#define IFX_TFM_NV_COUNTERS_AREA_LOCATION           CYMEM_CM33_0_S_TFM_NV_COUNTERS_LOCATION


/*******************************************************************************
****************************** Execution regions *******************************
*******************************************************************************/


/************************* TFM image execution region *************************/
/**
 * Following macro are generated by Edge Protect solution personality:
 *  - IFX_TFM_IMAGE_EXECUTE_OFFSET
 *  - IFX_TFM_IMAGE_EXECUTE_ADDR
 *  - IFX_TFM_IMAGE_EXECUTE_SIZE
 *  - IFX_TFM_IMAGE_EXECUTE_LOCATION
 */


/*********************** CM33 NS image execution region ***********************/
/* C-Bus aliasing is used for code execution */
#define IFX_CM33_NS_IMAGE_EXECUTE_OFFSET            CYMEM_CM33_0_m33_nvm_OFFSET
#define IFX_CM33_NS_IMAGE_EXECUTE_ADDR              CYMEM_CM33_0_m33_nvm_C_START
#define IFX_CM33_NS_IMAGE_EXECUTE_SIZE              CYMEM_CM33_0_m33_nvm_SIZE
#define IFX_CM33_NS_IMAGE_EXECUTE_LOCATION          CYMEM_CM33_0_m33_nvm_LOCATION


/*********************** CM55 NS image execution region ***********************/
/* CM55 does not have C-Bus so use S-Bus for code execution */
#define IFX_CM55_NS_IMAGE_EXECUTE_OFFSET            CYMEM_CM55_0_m55_nvm_OFFSET
#define IFX_CM55_NS_IMAGE_EXECUTE_ADDR              CYMEM_CM55_0_m55_nvm_START
#define IFX_CM55_NS_IMAGE_EXECUTE_SIZE              CYMEM_CM55_0_m55_nvm_SIZE
#define IFX_CM55_NS_IMAGE_EXECUTE_LOCATION          CYMEM_CM55_0_m55_nvm_LOCATION


/*******************************************************************************
********************************* Data regions *********************************
*******************************************************************************/


/******************************* TFM data area ********************************/
#define IFX_TFM_DATA_OFFSET                         CYMEM_CM33_0_S_m33s_data_OFFSET
#define IFX_TFM_DATA_ADDR                           CYMEM_CM33_0_S_m33s_data_S_START
#define IFX_TFM_DATA_SIZE                           CYMEM_CM33_0_S_m33s_data_SIZE
#define IFX_TFM_DATA_LOCATION                       CYMEM_CM33_0_S_m33s_data_LOCATION


/***************************** CM33 NS data area ******************************/
#define IFX_CM33_NS_DATA_OFFSET                     CYMEM_CM33_0_m33_data_OFFSET
#define IFX_CM33_NS_DATA_ADDR                       CYMEM_CM33_0_m33_data_START
#define IFX_CM33_NS_DATA_SIZE                       CYMEM_CM33_0_m33_data_SIZE
#define IFX_CM33_NS_DATA_LOCATION                   CYMEM_CM33_0_m33_data_LOCATION


/***************************** CM55 NS data area ******************************/
#define IFX_CM55_NS_DATA_SIZE                       CYMEM_CM55_0_m55_data_SIZE
#define IFX_CM55_NS_DATA_LOCATION                   CYMEM_CM55_0_m55_data_LOCATION
#if (IFX_CM55_NS_DATA_LOCATION == IFX_MEMORY_TYPE_CM55_DTCM_INTERNAL) || (IFX_CM55_NS_DATA_LOCATION == IFX_MEMORY_TYPE_CM55_ITCM_INTERNAL)
/* When CM55 internal memory is used - use *_INTERNAL memory aliases */
#define IFX_CM55_NS_DATA_OFFSET                     CYMEM_CM55_0_m55_data_INTERNAL_OFFSET
#define IFX_CM55_NS_DATA_ADDR                       CYMEM_CM55_0_m55_data_INTERNAL_START
#else /* (IFX_CM55_NS_DATA_LOCATION == IFX_MEMORY_TYPE_CM55_DTCM_INTERNAL) || (IFX_CM55_NS_DATA_LOCATION == IFX_MEMORY_TYPE_CM55_ITCM_INTERNAL) */
/* Otherwise - use normal memory aliases */
#define IFX_CM55_NS_DATA_OFFSET                     CYMEM_CM55_0_m55_data_OFFSET
#define IFX_CM55_NS_DATA_ADDR                       CYMEM_CM55_0_m55_data_START
#endif /* (IFX_CM55_NS_DATA_LOCATION == IFX_MEMORY_TYPE_CM55_DTCM_INTERNAL) || (IFX_CM55_NS_DATA_LOCATION == IFX_MEMORY_TYPE_CM55_ITCM_INTERNAL) */


/*******************************************************************************
*************************** Boot shared data region ****************************
*******************************************************************************/


/************************** Boot shared data region ***************************/
#define IFX_TFM_BOOT_SHARED_DATA_OFFSET             CYMEM_CM33_0_S_m33s_shared_OFFSET
#define IFX_TFM_BOOT_SHARED_DATA_ADDR               CYMEM_CM33_0_S_m33s_shared_S_START
#define IFX_TFM_BOOT_SHARED_DATA_SIZE               CYMEM_CM33_0_S_m33s_shared_SIZE
#define IFX_TFM_BOOT_SHARED_DATA_LOCATION           CYMEM_CM33_0_S_m33s_shared_LOCATION


/*******************************************************************************
******************************** Shared memory *********************************
*******************************************************************************/


#define IFX_CM33_NS_SHARED_MEMORY_OFFSET            CYMEM_CM33_0_m33_allocatable_shared_OFFSET
#define IFX_CM33_NS_SHARED_MEMORY_ADDR              CYMEM_CM33_0_m33_allocatable_shared_START
#define IFX_CM33_NS_SHARED_MEMORY_SIZE              CYMEM_CM33_0_m33_allocatable_shared_SIZE
#define IFX_CM33_NS_SHARED_MEMORY_LOCATION          CYMEM_CM33_0_m33_allocatable_shared_LOCATION


#define IFX_CM55_NS_SHARED_MEMORY_OFFSET            CYMEM_CM55_0_m55_allocatable_shared_OFFSET
#define IFX_CM55_NS_SHARED_MEMORY_ADDR              CYMEM_CM55_0_m55_allocatable_shared_START
#define IFX_CM55_NS_SHARED_MEMORY_SIZE              CYMEM_CM55_0_m55_allocatable_shared_SIZE
#define IFX_CM55_NS_SHARED_MEMORY_LOCATION          CYMEM_CM55_0_m55_allocatable_shared_LOCATION


/*******************************************************************************
******************************** Tests regions *********************************
*******************************************************************************/


/***************** PSA arch tests - FF server partition memory ****************/
#define IFX_FF_TEST_SERVER_PARTITION_MMIO_OFFSET    CYMEM_CM33_0_S_FF_TEST_SERVER_PARTITION_MMIO_OFFSET
#define IFX_FF_TEST_SERVER_PARTITION_MMIO_ADDR      CYMEM_CM33_0_S_FF_TEST_SERVER_PARTITION_MMIO_S_START
#define IFX_FF_TEST_SERVER_PARTITION_MMIO_SIZE      CYMEM_CM33_0_S_FF_TEST_SERVER_PARTITION_MMIO_SIZE
#define IFX_FF_TEST_SERVER_PARTITION_MMIO_LOCATION  CYMEM_CM33_0_S_FF_TEST_SERVER_PARTITION_MMIO_LOCATION


/***************** PSA arch tests - FF driver partition memory ****************/
#define IFX_FF_TEST_DRIVER_PARTITION_MMIO_OFFSET    CYMEM_CM33_0_S_FF_TEST_DRIVER_PARTITION_MMIO_OFFSET
#define IFX_FF_TEST_DRIVER_PARTITION_MMIO_ADDR      CYMEM_CM33_0_S_FF_TEST_DRIVER_PARTITION_MMIO_S_START
#define IFX_FF_TEST_DRIVER_PARTITION_MMIO_SIZE      CYMEM_CM33_0_S_FF_TEST_DRIVER_PARTITION_MMIO_SIZE
#define IFX_FF_TEST_DRIVER_PARTITION_MMIO_LOCATION  CYMEM_CM33_0_S_FF_TEST_DRIVER_PARTITION_MMIO_LOCATION


/******************** Test memory region for isolation test *******************/
#define IFX_TEST_PROT_PARTITION_MEMORY_OFFSET       CYMEM_CM33_0_S_TEST_PROT_PARTITION_MEMORY_OFFSET
#define IFX_TEST_PROT_PARTITION_MEMORY_ADDR         CYMEM_CM33_0_S_TEST_PROT_PARTITION_MEMORY_S_START
#define IFX_TEST_PROT_PARTITION_MEMORY_SIZE         CYMEM_CM33_0_S_TEST_PROT_PARTITION_MEMORY_SIZE
#define IFX_TEST_PROT_PARTITION_MEMORY_LOCATION     CYMEM_CM33_0_S_TEST_PROT_PARTITION_MEMORY_LOCATION


/******************** Test memory region for isolation test *******************/
#define IFX_TEST_AROT_PARTITION_MEMORY_OFFSET       CYMEM_CM33_0_S_TEST_AROT_PARTITION_MEMORY_OFFSET
#define IFX_TEST_AROT_PARTITION_MEMORY_ADDR         CYMEM_CM33_0_S_TEST_AROT_PARTITION_MEMORY_S_START
#define IFX_TEST_AROT_PARTITION_MEMORY_SIZE         CYMEM_CM33_0_S_TEST_AROT_PARTITION_MEMORY_SIZE
#define IFX_TEST_AROT_PARTITION_MEMORY_LOCATION     CYMEM_CM33_0_S_TEST_AROT_PARTITION_MEMORY_LOCATION


#ifdef __cplusplus
}
#endif

#endif /* PROJECT_MEMORY_LAYOUT_H */
