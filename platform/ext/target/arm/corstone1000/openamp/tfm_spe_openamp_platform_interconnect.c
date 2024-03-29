/*
 * Copyright (c) 2021-2024, Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "tfm_spe_openamp_platform_interface.h"
#include "tfm_spe_dual_core_psa_client_secure_lib.h"
#include "tfm_rpc.h"
#include "tfm_spe_openamp_interface.h"
#include "tfm_multi_core.h"
#include "tfm_spm_log.h"
#include "utilities.h"

/* Process call from the other core. */
void callback_from_openamp(const void *ns_msg, size_t len)
{
    int32_t ret = OPENAMP_SUCCESS;
    void *priv = NULL;

    ret = register_msg_to_spe_and_verify(&priv, ns_msg, len);
    if (ret != OPENAMP_SUCCESS) {
        return;
    }

    /*
     * priv will be used as the client_data parameter of tfm_rpc_psa_call() so
     * that it will be sent back in the RPC reply callback.
     */
    deliver_msg_to_tfm_spe(priv);
}

/* RPC reply() callback */
static void service_reply(const void *priv, int32_t ret)
{
    send_service_reply_to_non_secure(ret, (void*)priv);
}

/* Openamp specific operations callback for TF-M RPC */
static const struct tfm_rpc_ops_t openamp_rpc_ops = {
    .handle_req = tfm_to_openamp_notify, /* notify openamp for pendsv/irq
                                          * received from the non-secure */
    .reply      = service_reply,
};

void notify_request_from_openamp(void)
{
    int32_t ret;

    ret = tfm_hal_notify_peer();
    if (ret) {
        SPMLOG_ERRMSGVAL("tfm_hal_notify_peer failed ", ret);
    }
    return;
}

/* Openmap initialization */
static int32_t tfm_spe_openamp_lib_init(void)
{
    int32_t ret;

    ret = tfm_dual_core_hal_init();
    if (ret) {
        SPMLOG_ERRMSGVAL("tfm_dual_core_hal_init failed ", ret);
        return OPENAMP_INIT_ERROR;
    }

    ret = tfm_to_openamp_init(callback_from_openamp,
                              notify_request_from_openamp);
    if (ret) {
        SPMLOG_ERRMSGVAL("tfm_to_openamp_init failed ", ret);
        return OPENAMP_INIT_ERROR;
    }

    init_dual_core_psa_client_secure_lib();

    /* Register RPC callbacks */
    ret = tfm_rpc_register_ops(&openamp_rpc_ops);
    if (ret) {
        SPMLOG_ERRMSGVAL("tfm_rpc_register_ops failed ", ret);
        return OPENAMP_CALLBACK_REG_ERROR;
    }

    SPMLOG_INFMSG("tfm_spe_openamp_lib_init initialized success.\r\n");
    return OPENAMP_SUCCESS;
}

int32_t tfm_inter_core_comm_init(void)
{
    if (tfm_spe_openamp_lib_init()) {
        return TFM_PLAT_ERR_SYSTEM_ERR;
    }

    return TFM_PLAT_ERR_SUCCESS;
}
