/*
 * Copyright (c) 2023-2024 Arm Limited. All rights reserved.
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
 * \file host_base_address.h
 * \brief This file defines the host memory map addresses accessed by RSE.
 */

#ifndef __HOST_BASE_ADDRESS_H__
#define __HOST_BASE_ADDRESS_H__

#include "host_atu_base_address.h"
#include "host_clus_util_lcp_memory_map.h"
#include "host_css_memory_map.h"
#include "host_fw_memory_map.h"
#include "host_mscp_memory_map.h"
#include "platform_base_address.h"
#include "size_defs.h"

#define PLAT_DEP_STATIC_CFG \
    { \
        .log_addr = HOST_SCP_HDR_ATU_WINDOW_BASE_S, \
        .phys_addr = HOST_SCP_HDR_PHYS_BASE, \
        .size = RSE_IMG_HDR_ATU_WINDOW_SIZE, \
        .out_bus_attr = ATU_ENCODE_ATTRIBUTES_SECURE_PAS, \
    }, \
    { \
        .log_addr = HOST_SCP_IMG_CODE_BASE_S, \
        .phys_addr = HOST_SCP_PHYS_BASE, \
        .size = HOST_SCP_ATU_SIZE, \
        .out_bus_attr = ATU_ENCODE_ATTRIBUTES_SECURE_PAS, \
    }, \
    { \
        .log_addr = HOST_SCP_INIT_CTRL_BASE_S, \
        .phys_addr = HOST_SCP_INIT_CTRL_PHYS_BASE, \
        .size = HOST_SCP_INIT_CTRL_SIZE, \
        .out_bus_attr = ATU_ENCODE_ATTRIBUTES_SECURE_PAS, \
    }, \
    { \
        .log_addr = HOST_MCP_HDR_ATU_WINDOW_BASE_S, \
        .phys_addr = HOST_MCP_HDR_PHYS_BASE, \
        .size = RSE_IMG_HDR_ATU_WINDOW_SIZE, \
        .out_bus_attr = ATU_ENCODE_ATTRIBUTES_SECURE_PAS, \
    }, \
    { \
        .log_addr = HOST_MCP_IMG_CODE_BASE_S, \
        .phys_addr = HOST_MCP_PHYS_BASE, \
        .size = HOST_MCP_ATU_SIZE, \
        .out_bus_attr = ATU_ENCODE_ATTRIBUTES_SECURE_PAS, \
    }, \
    { \
        .log_addr = HOST_MCP_INIT_CTRL_BASE_S, \
        .phys_addr = HOST_MCP_INIT_CTRL_PHYS_BASE, \
        .size = HOST_MCP_INIT_CTRL_SIZE, \
        .out_bus_attr = ATU_ENCODE_ATTRIBUTES_SECURE_PAS, \
    }, \
    { \
        .log_addr = HOST_AP_BL1_HDR_ATU_WINDOW_BASE_S, \
        .phys_addr = HOST_AP_BL1_HDR_PHYS_BASE, \
        .size = RSE_IMG_HDR_ATU_WINDOW_SIZE, \
        .out_bus_attr = ATU_ENCODE_ATTRIBUTES_SECURE_PAS | \
                        ATU_ROBA_SET_1 << ATU_ATUROBA_AXNSE_OFF | \
                        ATU_ROBA_SET_0 << ATU_ATUROBA_AXPROT1_OFF, \
    }, \
    { \
        .log_addr = HOST_AP_BL1_IMG_CODE_BASE_S, \
        .phys_addr = HOST_AP_BL1_PHYS_BASE, \
        .size = HOST_AP_BL1_ATU_SIZE, \
        .out_bus_attr = ATU_ENCODE_ATTRIBUTES_SECURE_PAS | \
                        ATU_ROBA_SET_1 << ATU_ATUROBA_AXNSE_OFF | \
                        ATU_ROBA_SET_0 << ATU_ATUROBA_AXPROT1_OFF, \
    }

#endif  /* __HOST_BASE_ADDRESS_H__ */
