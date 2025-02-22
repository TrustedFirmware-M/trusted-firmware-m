/*
 * Copyright (c) 2024 Arm Limited. All rights reserved.
 *
 * Licensed under the Apache License Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing software
 * distributed under the License is distributed on an "AS IS" BASIS
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/**
 * \file host_device_definition.c
 * \brief This file defines exports the structures based on the peripheral
 * definitions from device_cfg.h.
 */

#include <stddef.h>

#include "host_device_definition.h"
#include "host_base_address.h"
#include "platform_base_address.h"

#ifdef PLATFORM_HAS_NOC_S3
/* System Control NoC S3 device */
struct noc_s3_dev SYSCTRL_NOC_S3_DEV = {
    .periphbase = HOST_NOC_S3_BASE,
    .config_node_granularity = NOC_S3_64KB_CONFIG_NODES,
    .skip_discovery_list = NULL,
    .chip_addr_offset = 0,
};

/* Peripheral NoC S3 device */
const struct noc_s3_dev PERIPH_NOC_S3_DEV = {
    .periphbase = HOST_NOC_S3_BASE,
    .config_node_granularity = NOC_S3_64KB_CONFIG_NODES,
    .skip_discovery_list = NULL,
    .chip_addr_offset = 0,
};

#endif /* PLATFORM_HAS_NOC_S3 */

#ifdef PLATFORM_HOST_HAS_SCP
struct mscp_dev_t HOST_SCP_DEV = {
    .init_ctrl_base = HOST_SCP_INIT_CTRL_BASE_S,
};
#endif /* PLATFORM_HOST_HAS_SCP */
