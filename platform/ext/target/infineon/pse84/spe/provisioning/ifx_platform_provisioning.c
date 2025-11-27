/*
 * Copyright (c) 2025 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "cmsis.h"
#include "provisioning.h"
#include "cy_device.h"

/* Debug port access control bitfields as specified by BootROM */
#define IFX_DEBUG_POLICY_CM33_AP_CTL_Pos            (0UL)
#define IFX_DEBUG_POLICY_CM33_AP_CTL_Msk            (0x007UL)
#define IFX_DEBUG_POLICY_CM55_AP_CTL_Pos            (3UL)
#define IFX_DEBUG_POLICY_CM55_AP_CTL_Msk            (0x038UL)
#define IFX_DEBUG_POLICY_SYS_AP_CTL_Pos             (6UL)
#define IFX_DEBUG_POLICY_SYS_AP_CTL_Msk             (0x1C0UL)

/* Debug port access configuration values as specified by BootROM */
#define IFX_DEBUG_POLICY_AP_DISABLE                 (0U)
#define IFX_DEBUG_POLICY_AP_ENABLE                  (1U)
#define IFX_DEBUG_POLICY_AP_ALLOW_FW                (2U)
#define IFX_DEBUG_POLICY_AP_ALLOW_CERT              (3U)
#define IFX_DEBUG_POLICY_AP_ALLOW_OPEN              (4U)

/* Key length in bytes. The length is fixed because only 256-bit ECDSA keys are
 * supported. Note the 1st byte defines key format, the following bytes are X
 * and Y points 32 bytes each.
 * As specified by BootROM.
 */
#define IFX_OEM_POLICY_PUB_KEY_SIZE                 (65U)

/* Address where ifx_oem_policy_t is stored as specified by BootROM */
#define IFX_OEM_POLICY_ADDR                         (0x12001100u)

/* Debug policy structure as specified by BootROM */
typedef struct
{
    /* Debug port access control and access restrictions for SYS-AP */
    uint32_t access_cfg;
    /* AP_CTL register values that reflect debug policy */
    uint32_t syscpuss_ap_ctl;  /* CM33-AP and SYS-AP control */
    uint32_t reserved;
} ifx_debug_policy_t;

/* OEM policy structure to keep OEM debug restrictions, debug key to open access port
 * using certificate and flag that indicates possibility to move to RMA LCS.
 * As specified by BootROM.
 */
typedef struct
{
    ifx_debug_policy_t dbg_policy;
    uint32_t rma;
    uint8_t debug_key[IFX_OEM_POLICY_PUB_KEY_SIZE];
    uint8_t padding[3];
    uint32_t boundary_scan;
    uint32_t warm_boot;
    uint32_t reserved;
} ifx_oem_policy_t;

ifx_dap_state_t ifx_get_dap_state(void)
{
    ifx_oem_policy_t* policy = (ifx_oem_policy_t*)IFX_OEM_POLICY_ADDR;

    /* Get state of CM33 DAP */
    uint32_t cm33_acc_cfg = _FLD2VAL(IFX_DEBUG_POLICY_CM33_AP_CTL, policy->dbg_policy.access_cfg);

    switch (cm33_acc_cfg) {
        case IFX_DEBUG_POLICY_AP_DISABLE:
            return IFX_DAP_DISABLED;
        case IFX_DEBUG_POLICY_AP_ENABLE:
        case IFX_DEBUG_POLICY_AP_ALLOW_FW:
        case IFX_DEBUG_POLICY_AP_ALLOW_CERT:
        case IFX_DEBUG_POLICY_AP_ALLOW_OPEN:
            /* DAP ALLOW states are treated as DAP ENABLED as port might already
             * have been opened (e.g. using certificate) and TFM has no way to
             * check it. Policy does not provide S/NS debug details, thus assume
             * both S and NS debug is enabled */
            return IFX_DAP_ENABLED_S_NS;
        default:
            return IFX_DAP_UNKNOWN;
    }
}
