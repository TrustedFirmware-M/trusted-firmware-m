/******************************************************************************
 *
 * Copyright (C) 2024-2025 Analog Devices, Inc.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 ******************************************************************************/

#include "tfm_platform_api.h"
#include "psa/client.h"
#include "tfm_plat_defs.h"
#include "platform_retarget.h"
#include "flc.h"

#define IOCTL_OTP_INVEC_LEN 1

#define MXC_INFO_MEM_USN_ADDR FLASH_INFO_BASE
#define MXC_INFO_MEM_USN_PKG_CODE_ADDR (FLASH_INFO_BASE + 0x14)
#define MXC_INFO_MEM_LDO_TRIM_BB_ADDR (FLASH_INFO_BASE + 0x19C)
#define MXC_INFO_MEM_LDO_TRIM_RF_ADDR (FLASH_INFO_BASE + 0x1AC)
#define MXC_INFO_MEM_DBB_SETTINGS_ADDR0 (FLASH_INFO_BASE + 0x400)
#define MXC_INFO_MEM_DBB_SETTINGS_ADDR1 (FLASH_INFO_BASE + 0x440)

enum adi_otp_types_t {
    ADI_OTP_ID_USN = 0,
    ADI_OTP_ID_BLE_LDO_TRIM_BB,
    ADI_OTP_ID_BLE_LDO_TRIM_RF,
    ADI_OTP_ID_DBB_SETTINGS0,
    ADI_OTP_ID_DBB_SETTINGS1,
};


enum tfm_platform_err_t
tfm_platform_adi_hal_otp_service(const psa_invec *in_vec,
                             const psa_outvec *out_vec)
{
    if ( (in_vec == NULL) ||
        (out_vec == NULL) ||
        (in_vec->len != IOCTL_OTP_INVEC_LEN) )  {

        return TFM_PLATFORM_ERR_INVALID_PARAM;
    }

    enum adi_otp_types_t arg = *(enum adi_otp_types_t *)in_vec->base;
    int src;
    int len;
    switch (arg) {
    case ADI_OTP_ID_USN:
        len = 24;
        src = MXC_INFO_MEM_USN_ADDR;
        break;
    case ADI_OTP_ID_BLE_LDO_TRIM_BB:
        len = 4;
        src = MXC_INFO_MEM_LDO_TRIM_BB_ADDR;
        break;
    case ADI_OTP_ID_BLE_LDO_TRIM_RF:
        len = 4;
        src = MXC_INFO_MEM_LDO_TRIM_RF_ADDR;
        break;
    case ADI_OTP_ID_DBB_SETTINGS0:
        len = 64;
        src = MXC_INFO_MEM_DBB_SETTINGS_ADDR0;
        break;
    case ADI_OTP_ID_DBB_SETTINGS1:
        len = 64;
        src = MXC_INFO_MEM_DBB_SETTINGS_ADDR1;
        break;
    default:
        return TFM_PLATFORM_ERR_INVALID_PARAM;
    }

    MXC_FLC_UnlockInfoBlock(FLASH_INFO_BASE);
    MXC_FLC_Read(src, out_vec->base, len);
    MXC_FLC_LockInfoBlock(FLASH_INFO_BASE);

    return TFM_PLATFORM_ERR_SUCCESS;
}
