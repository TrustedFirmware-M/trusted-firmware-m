/*
 * Copyright (c) 2018-2019, Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

/*********** WARNING: This is an auto-generated file. Do not edit! ***********/

#ifndef __TFM_SERVICE_LIST_INC__
#define __TFM_SERVICE_LIST_INC__

/******** TFM_SP_STORAGE ********/
{
        "TFM_SST_SET_SID",
        TFM_SP_STORAGE_ID,
        TFM_SST_SET_SIG,
        0x00002000,
        true,
        1,
        TFM_VERSION_POLICY_STRICT
},
{
        "TFM_SST_GET_SID",
        TFM_SP_STORAGE_ID,
        TFM_SST_GET_SIG,
        0x00002001,
        true,
        1,
        TFM_VERSION_POLICY_STRICT
},
{
        "TFM_SST_GET_INFO_SID",
        TFM_SP_STORAGE_ID,
        TFM_SST_GET_INFO_SIG,
        0x00002002,
        true,
        1,
        TFM_VERSION_POLICY_STRICT
},
{
        "TFM_SST_REMOVE_SID",
        TFM_SP_STORAGE_ID,
        TFM_SST_REMOVE_SIG,
        0x00002003,
        true,
        1,
        TFM_VERSION_POLICY_STRICT
},
{
        "TFM_SST_GET_SUPPORT_SID",
        TFM_SP_STORAGE_ID,
        TFM_SST_GET_SUPPORT_SIG,
        0x00002004,
        true,
        1,
        TFM_VERSION_POLICY_STRICT
},


/******** TFM_SP_CRYPTO ********/
{
        "TFM_CRYPTO_SID",
        TFM_SP_CRYPTO_ID,
        TFM_CRYPTO_SIG,
        0x00004000,
        true,
        1,
        TFM_VERSION_POLICY_STRICT
},


/******** TFM_SP_INITIAL_ATTESTATION ********/
{
        "TFM_ATTEST_GET_TOKEN_SID",
        TFM_SP_INITIAL_ATTESTATION_ID,
        PSA_ATTEST_GET_TOKEN_SIG,
        0x00000020,
        true,
        1,
        TFM_VERSION_POLICY_STRICT
},
{
        "TFM_ATTEST_GET_TOKEN_SIZE_SID",
        TFM_SP_INITIAL_ATTESTATION_ID,
        PSA_ATTEST_GET_TOKEN_SIZE_SIG,
        0x00000021,
        true,
        1,
        TFM_VERSION_POLICY_STRICT
},

#ifdef TFM_PARTITION_TEST_CORE
/******** TFM_SP_CORE_TEST ********/
{
        "SPM_CORE_TEST_INIT_SUCCESS_SID",
        TFM_SP_CORE_TEST_ID,
        SPM_CORE_TEST_INIT_SUCCESS_SIGNAL,
        0x00002100,
        true,
        1,
        TFM_VERSION_POLICY_STRICT
},
{
        "SPM_CORE_TEST_DIRECT_RECURSION_SID",
        TFM_SP_CORE_TEST_ID,
        SPM_CORE_TEST_DIRECT_RECURSION_SIGNAL,
        0x00002101,
        true,
        1,
        TFM_VERSION_POLICY_STRICT
},
{
        "SPM_CORE_TEST_MPU_ACCESS_SID",
        TFM_SP_CORE_TEST_ID,
        SPM_CORE_TEST_MPU_ACCESS_SIGNAL,
        0x00002102,
        true,
        1,
        TFM_VERSION_POLICY_STRICT
},
{
        "SPM_CORE_TEST_MEMORY_PERMISSIONS_SID",
        TFM_SP_CORE_TEST_ID,
        SPM_CORE_TEST_MEMORY_PERMISSIONS_SIGNAL,
        0x00002103,
        true,
        1,
        TFM_VERSION_POLICY_STRICT
},
{
        "SPM_CORE_TEST_SHARE_REDIRECTION_SID",
        TFM_SP_CORE_TEST_ID,
        SPM_CORE_TEST_SHARE_REDIRECTION_SIGNAL,
        0x00002104,
        true,
        1,
        TFM_VERSION_POLICY_STRICT
},
{
        "SPM_CORE_TEST_SS_TO_SS_SID",
        TFM_SP_CORE_TEST_ID,
        SPM_CORE_TEST_SS_TO_SS_SIGNAL,
        0x00002105,
        true,
        1,
        TFM_VERSION_POLICY_STRICT
},
{
        "SPM_CORE_TEST_SS_TO_SS_BUFFER_SID",
        TFM_SP_CORE_TEST_ID,
        SPM_CORE_TEST_SS_TO_SS_BUFFER_SIGNAL,
        0x00002106,
        true,
        1,
        TFM_VERSION_POLICY_STRICT
},
{
        "SPM_CORE_TEST_OUTVEC_WRITE_SID",
        TFM_SP_CORE_TEST_ID,
        SPM_CORE_TEST_OUTVEC_WRITE_SIGNAL,
        0x00002107,
        true,
        1,
        TFM_VERSION_POLICY_STRICT
},
{
        "SPM_CORE_TEST_PERIPHERAL_ACCESS_SID",
        TFM_SP_CORE_TEST_ID,
        SPM_CORE_TEST_PERIPHERAL_ACCESS_SIGNAL,
        0x00002108,
        true,
        1,
        TFM_VERSION_POLICY_STRICT
},
{
        "SPM_CORE_TEST_GET_CALLER_CLIENT_ID_SID",
        TFM_SP_CORE_TEST_ID,
        SPM_CORE_TEST_GET_CALLER_CLIENT_ID_SIGNAL,
        0x00002109,
        true,
        1,
        TFM_VERSION_POLICY_STRICT
},
{
        "SPM_CORE_TEST_SPM_REQUEST_SID",
        TFM_SP_CORE_TEST_ID,
        SPM_CORE_TEST_SPM_REQUEST_SIGNAL,
        0x0000210A,
        true,
        1,
        TFM_VERSION_POLICY_STRICT
},
{
        "SPM_CORE_TEST_BLOCK_SID",
        TFM_SP_CORE_TEST_ID,
        SPM_CORE_TEST_BLOCK_SIGNAL,
        0x0000210B,
        true,
        1,
        TFM_VERSION_POLICY_STRICT
},
{
        "SPM_CORE_TEST_NS_THREAD_SID",
        TFM_SP_CORE_TEST_ID,
        SPM_CORE_TEST_NS_THREAD_SIGNAL,
        0x0000210C,
        true,
        1,
        TFM_VERSION_POLICY_STRICT
},
#endif /* TFM_PARTITION_TEST_CORE */

#ifdef TFM_PARTITION_TEST_CORE
/******** TFM_SP_CORE_TEST_2 ********/
{
        "SPM_CORE_TEST_2_SLAVE_SERVICE_SID",
        TFM_SP_CORE_TEST_2_ID,
        SPM_CORE_TEST_2_SLAVE_SERVICE_SIGNAL,
        0x00002200,
        true,
        1,
        TFM_VERSION_POLICY_STRICT
},
{
        "SPM_CORE_TEST_2_CHECK_CALLER_CLIENT_ID_SID",
        TFM_SP_CORE_TEST_2_ID,
        SPM_CORE_TEST_2_CHECK_CALLER_CLIENT_ID_SIGNAL,
        0x00002201,
        true,
        1,
        TFM_VERSION_POLICY_STRICT
},
{
        "SPM_CORE_TEST_2_GET_EVERY_SECOND_BYTE_SID",
        TFM_SP_CORE_TEST_2_ID,
        SPM_CORE_TEST_2_GET_EVERY_SECOND_BYTE_SIGNAL,
        0x00002202,
        true,
        1,
        TFM_VERSION_POLICY_STRICT
},
{
        "SPM_CORE_TEST_2_INVERT_SID",
        TFM_SP_CORE_TEST_2_ID,
        SPM_CORE_TEST_2_INVERT_SIGNAL,
        0x00002203,
        true,
        1,
        TFM_VERSION_POLICY_STRICT
},
#endif /* TFM_PARTITION_TEST_CORE */

#ifdef TFM_PARTITION_TEST_SECURE_SERVICES
/******** TFM_SP_SECURE_TEST_PARTITION ********/
{
        "TFM_SECURE_CLIENT_SFN_RUN_TESTS_SID",
        TFM_SP_SECURE_TEST_PARTITION_ID,
        TFM_SECURE_CLIENT_SFN_RUN_TESTS_SIG,
        0x0000F000,
        true,
        1,
        TFM_VERSION_POLICY_STRICT
},
#endif /* TFM_PARTITION_TEST_SECURE_SERVICES */

#ifdef TFM_PARTITION_TEST_CORE_IPC
/******** TFM_SP_IPC_SERVICE_TEST ********/
{
        "IPC_SERVICE_TEST_BASIC_SID",
        TFM_SP_IPC_SERVICE_TEST_ID,
        IPC_SERVICE_TEST_BASIC_SIGNAL,
        0x00001000,
        true,
        1,
        TFM_VERSION_POLICY_STRICT
},
{
        "IPC_SERVICE_TEST_PSA_ACCESS_APP_MEM_SID",
        TFM_SP_IPC_SERVICE_TEST_ID,
        IPC_SERVICE_TEST_PSA_ACCESS_APP_MEM_SIGNAL,
        0x00001001,
        true,
        1,
        TFM_VERSION_POLICY_STRICT
},
{
        "IPC_SERVICE_TEST_PSA_ACCESS_APP_READ_ONLY_MEM_SID",
        TFM_SP_IPC_SERVICE_TEST_ID,
        IPC_SERVICE_TEST_PSA_ACCESS_APP_READ_ONLY_MEM_SIGNAL,
        0x00001002,
        true,
        1,
        TFM_VERSION_POLICY_STRICT
},
{
        "IPC_SERVICE_TEST_APP_ACCESS_PSA_MEM_SID",
        TFM_SP_IPC_SERVICE_TEST_ID,
        IPC_SERVICE_TEST_APP_ACCESS_PSA_MEM_SIGNAL,
        0x00001003,
        true,
        1,
        TFM_VERSION_POLICY_STRICT
},
#endif /* TFM_PARTITION_TEST_CORE_IPC */

#ifdef TFM_PARTITION_TEST_CORE_IPC
/******** TFM_SP_IPC_CLIENT_TEST ********/
{
        "IPC_CLIENT_TEST_BASIC_SID",
        TFM_SP_IPC_CLIENT_TEST_ID,
        IPC_CLIENT_TEST_BASIC_SIGNAL,
        0x00001100,
        true,
        1,
        TFM_VERSION_POLICY_STRICT
},
{
        "IPC_CLIENT_TEST_PSA_ACCESS_APP_MEM_SID",
        TFM_SP_IPC_CLIENT_TEST_ID,
        IPC_CLIENT_TEST_PSA_ACCESS_APP_MEM_SIGNAL,
        0x00001101,
        true,
        1,
        TFM_VERSION_POLICY_STRICT
},
{
        "IPC_CLIENT_TEST_PSA_ACCESS_APP_READ_ONLY_MEM_SID",
        TFM_SP_IPC_CLIENT_TEST_ID,
        IPC_CLIENT_TEST_PSA_ACCESS_APP_READ_ONLY_MEM_SIGNAL,
        0x00001102,
        true,
        1,
        TFM_VERSION_POLICY_STRICT
},
{
        "IPC_CLIENT_TEST_APP_ACCESS_PSA_MEM_SID",
        TFM_SP_IPC_CLIENT_TEST_ID,
        IPC_CLIENT_TEST_APP_ACCESS_PSA_MEM_SIGNAL,
        0x00001103,
        true,
        1,
        TFM_VERSION_POLICY_STRICT
},
{
        "IPC_CLIENT_TEST_MEM_CHECK_SID",
        TFM_SP_IPC_CLIENT_TEST_ID,
        IPC_CLIENT_TEST_MEM_CHECK_SIGNAL,
        0x00001104,
        true,
        1,
        TFM_VERSION_POLICY_STRICT
},
#endif /* TFM_PARTITION_TEST_CORE_IPC */

#endif /* __TFM_SERVICE_LIST_INC__ */
