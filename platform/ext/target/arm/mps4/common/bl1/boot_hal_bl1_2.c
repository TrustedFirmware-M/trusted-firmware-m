/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
#include <string.h>
#include "boot_hal.h"
#include "region.h"
#include "platform_s_device_definition.h"
#include "Driver_Flash.h"
#include "flash_layout.h"
#include "region_defs.h"
#include "platform_base_address.h"
#include "uart_stdout.h"
#include "tfm_plat_otp.h"
#include "kmu_drv.h"
#include "platform_regs.h"
#include "cmsis_compiler.h"
#include "tfm_plat_nv_counters.h"
#include "mpu_armv8m_drv.h"
#include "tfm_hal_device_header.h"
#include "tfm_log.h"

struct mpu_armv8m_dev_t dev_mpu_s = { MPU_BASE };

/* Flash device name must be specified by target */
extern ARM_DRIVER_FLASH FLASH_DEV_NAME_BL1;

REGION_DECLARE(Image$$, ARM_LIB_STACK, $$ZI$$Base);


/* only one bl2 image at the moment */
uint32_t bl1_image_get_flash_offset(uint32_t image_id)
{
    switch (image_id) {
    case 0:
    case 1:
        return BL2_IMAGE_LOAD_ADDRESS - FLASH_BL1_BASE_ADDRESS;
    default:
        while(1){}
    }
}

/* bootloader platform-specific hw initialization */
int32_t boot_platform_init(void)
{
    int32_t result;
    enum tfm_plat_err_t plat_err;

    /* Initialize stack limit register */
    uint32_t msp_stack_bottom =
            (uint32_t)&REGION_NAME(Image$$, ARM_LIB_STACK, $$ZI$$Base);

    __set_MSPLIM(msp_stack_bottom);

    plat_err = tfm_plat_init_nv_counter();
    if (plat_err != TFM_PLAT_ERR_SUCCESS) {
        return 1;
    }


#if (LOG_LEVEL > LOG_LEVEL_NONE) || defined(TEST_BL1_1) || defined(TEST_BL1_2)
    stdio_init();
#endif /* (LOG_LEVEL > LOG_LEVEL_NONE) || defined(TEST_BL1_1) || defined(TEST_BL1_2) */

    result = FLASH_DEV_NAME_BL1.Initialize(NULL);
    if (result != ARM_DRIVER_OK) {
        return 1;
    }

    return 0;
}

int32_t boot_platform_post_init(void)
{
    return 0;
}

static int disable_rom_execution(void)
{
    int rc;

    struct mpu_armv8m_region_cfg_t rom_region_config = {
        0,
        BOOT_ROM_BASE_S,
        BOOT_ROM_BASE_S + BOOT_ROM_SIZE - 1,
        MPU_ARMV8M_MAIR_ATTR_CODE_IDX,
        MPU_ARMV8M_XN_EXEC_NEVER,
        MPU_ARMV8M_AP_RO_PRIV_ONLY,
        MPU_ARMV8M_SH_NONE,
#ifdef TFM_PXN_ENABLE
        MPU_ARMV8M_PRIV_EXEC_NEVER,
#endif
    };

    rc = mpu_armv8m_region_enable(&dev_mpu_s, &rom_region_config);
    if (rc != 0) {
        return rc;
    }

    return mpu_armv8m_enable(&dev_mpu_s, PRIVILEGED_DEFAULT_ENABLE,
                             HARDFAULT_NMI_ENABLE);
}

void boot_platform_start_next_image(struct boot_arm_vector_table *vt)
{
    /* Clang at O0, stores variables on the stack with SP relative addressing.
     * When manually set the SP then the place of reset vector is lost.
     * Static variables are stored in 'data' or 'bss' section, change of SP has
     * no effect on them.
     */
    static struct boot_arm_vector_table *vt_cpy;
    int32_t result;

    result = kmu_invalidate_hardware_keys(&KMU_DEV_S);
    if (result) {
        while(1){}
    }

    result = FLASH_DEV_NAME_BL1.Uninitialize();
    if (result != ARM_DRIVER_OK) {
        while (1){}
    }

#if (LOG_LEVEL > LOG_LEVEL_NONE) || defined(TEST_BL1_1) || defined(TEST_BL1_2)
    stdio_uninit();
#endif /* (LOG_LEVEL > LOG_LEVEL_NONE) || defined(TEST_BL1_1) || defined(TEST_BL1_2) */

    fih_delay();

    result = disable_rom_execution();
    if (result) {
        while (1);
    }

    vt_cpy = vt;
#if defined(__ARM_ARCH_8M_MAIN__) || defined(__ARM_ARCH_8M_BASE__) \
 || defined(__ARM_ARCH_8_1M_MAIN__)
    /* Restore the Main Stack Pointer Limit register's reset value
     * before passing execution to runtime firmware to make the
     * bootloader transparent to it.
     */
    __set_MSPLIM(0);
#endif /* defined(__ARM_ARCH_8M_MAIN__) || defined(__ARM_ARCH_8M_BASE__) \
       || defined(__ARM_ARCH_8_1M_MAIN__) */

    __set_MSP(vt_cpy->msp);
    __DSB();
    __ISB();

    boot_jump_to_next_image(vt_cpy->reset);
}

int boot_platform_pre_load(uint32_t image_id)
{
    fih_delay();

    return 0;
}

int boot_platform_post_load(uint32_t image_id)
{
    int rc;

    rc = kmu_invalidate_hardware_keys(&KMU_DEV_S);
    if (rc) {
        return rc;
    }

    return 0;
}
