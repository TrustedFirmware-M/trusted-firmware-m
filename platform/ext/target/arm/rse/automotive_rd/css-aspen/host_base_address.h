/*
 * SPDX-License-Identifier: BSD-3-Clause
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 */

/**
 * \file host_base_address.h
 * \brief This file defines the host memory map addresses accessed by RSE.
 */

#ifndef __HOST_BASE_ADDRESS_H__
#define __HOST_BASE_ADDRESS_H__

#include "host_ap_memory_map.h"
#include "host_atu_base_address.h"
#include "host_si_memory_map.h"
#include "host_smd_memory_map.h"
#include "image_size_defs.h"
#include "platform_base_address.h"

#define PLAT_DEP_STATIC_CFG \
    { \
        .log_addr = HOST_AP_RSE_MAILBOX_BASE_S, \
        .phys_addr = HOST_AP_RSE_MAILBOX_PHYS_BASE, \
        .size = HOST_AP_RSE_MAILBOX_ATU_SIZE, \
        .out_bus_attr = ATU_ENCODE_ATTRIBUTES_SECURE_PAS, \
    }

#endif  /* __HOST_BASE_ADDRESS_H__ */
