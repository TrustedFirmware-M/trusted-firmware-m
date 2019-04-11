/*
 * Copyright (c) 2018-2019, Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <stdio.h>
#include "psa_client.h"
#include "secure_utilities.h"

/* These SID should be same with service manifest.*/
#define IPC_TEST_SERVICE1_SID        (0x1000)
#define IPC_TEST_SERVICE1_MIN_VER    (0x0001)

int ipc_client_init(void)
{
#if 0
    psa_handle_t handle;
    psa_status_t status;
    char str1[] = "123";
    char str2[] = "456";
    char str3[64], str4[64];
    struct psa_invec invecs[2] = {{str1, sizeof(str1)/sizeof(char)},
                                  {str2, sizeof(str2)/sizeof(char)}};
    struct psa_outvec outvecs[2] = {{str3, sizeof(str3)/sizeof(char)},
                                    {str4, sizeof(str4)/sizeof(char)}};


    LOG_MSG("hello! this is ipc client test sp!");

    handle = psa_connect(IPC_TEST_SERVICE1_SID, IPC_TEST_SERVICE1_MIN_VER);
    if (handle > 0) {
        LOG_MSG("Connect success!");
    } else {
        LOG_MSG("The RoT Service has refused the connection!");
    }

    status = psa_call(handle, invecs, 2, outvecs, 2);
    if (status >= 0) {
        LOG_MSG("Call success!");
    } else {
        LOG_MSG("Call failed!");
    }

    psa_close(handle);
#endif
    return 0;
}
