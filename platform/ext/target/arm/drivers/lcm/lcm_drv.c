/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 */

/**
 * \file lcm_drv.c
 * \brief Driver for Arm LCM.
 */

#include "lcm_drv.h"
#include "lcm_otp_layout.h"

#include "tfm_hal_device_header.h"
#include "device_definition.h"
#include "fatal_error.h"

#include <stddef.h>
#include <stdint.h>
#include <assert.h>

#ifdef LCM_DCU_PARITY
#define DCU_ENABLED_MASK  0x55555555
#define DCU_DISABLED_MASK 0xAAAAAAAA
#else
#define DCU_ENABLED_MASK  0xFFFFFFFF
#define DCU_DISABLED_MASK 0x00000000
#endif

#ifdef INTEGRITY_CHECKER_S
 __ALIGNED(INTEGRITY_CHECKER_REQUIRED_ALIGNMENT)
#endif
static const uint32_t dummy_key_value[] = {[0 ... 7] = 0x04030201UL};

struct _lcm_reg_map_t {
    volatile uint32_t lcs_value;
                /*!< Offset: 0x000 (R/ ) LCM Lifecycle state Register */
    volatile uint32_t key_err;
                /*!< Offset: 0x004 (R/ ) LCM zero count error status Register */
    volatile uint32_t tp_mode;
                /*!< Offset: 0x008 (R/ ) LCM TP Mode (TCI/PCI) Register */
    volatile uint32_t fatal_err;
                /*!< Offset: 0x00C (R/W) LCM Fatal Error mode Enable Register */
    volatile uint32_t dm_rma_lock;
                /*!< Offset: 0x010 (R/W) LCM DRM RMA Flag lock enable */
    volatile uint32_t sp_enable;
                /*!< Offset: 0x014 (R/W) LCM Secure Provisioning enable
                 *                       Register */
    volatile uint32_t otp_addr_width;
                /*!< Offset: 0x018 (R/ ) LCM OTP Address Width Register  */
    volatile uint32_t otp_size_in_bytes;
                /*!< Offset: 0x01C (R/ ) LCM OTP Size in bytes Register */
    volatile uint32_t gppc;
                /*!< Offset: 0x020 (R/ ) LCM General Purpose Persistent
                 *                       Configuration Register */
    volatile uint32_t reserved_0[55];
                /*!< Offset: 0x024-0x0FC Reserved */
    volatile uint32_t dcu_en[4];
                /*!< Offset: 0x100 (R/W) LCM DCU enable Registers */
    volatile uint32_t dcu_lock[4];
                /*!< Offset: 0x110 (R/W) LCM DCU lock Registers */
    volatile uint32_t dcu_sp_disable_mask[4];
                /*!< Offset: 0x120 (R/ ) LCM DCU SP disable mask Registers */
    volatile uint32_t dcu_disable_mask[4];
                /*!< Offset: 0x130 (R/ ) LCM DCU disable mask Registers */
    volatile uint32_t reserved_1[932];
                /*!< Offset: 0x140-0xFCC Reserved */
    volatile uint32_t pidr4;
                /*!< Offset: 0xFD0 (R/ ) Peripheral ID 4 */
    volatile uint32_t reserved_2[3];
                /*!< Offset: 0xFD4-0xFDC Reserved */
    volatile uint32_t pidr0;
                /*!< Offset: 0xFE0 (R/ ) Peripheral ID 0 */
    volatile uint32_t pidr1;
                /*!< Offset: 0xFE4 (R/ ) Peripheral ID 1 */
    volatile uint32_t pidr2;
                /*!< Offset: 0xFE8 (R/ ) Peripheral ID 2 */
    volatile uint32_t pidr3;
                /*!< Offset: 0xFEC (R/ ) Peripheral ID 3 */
    volatile uint32_t cidr0;
                /*!< Offset: 0xFF0 (R/ ) Component ID 0 */
    volatile uint32_t cidr1;
                /*!< Offset: 0xFF4 (R/ ) Component ID 1 */
    volatile uint32_t cidr2;
                /*!< Offset: 0xFF8 (R/ ) Component ID 2 */
    volatile uint32_t cidr3;
                /*!< Offset: 0xFFC (R/ ) Component ID 3 */
    union {
        volatile uint32_t raw_otp[16384];
                /*!< Offset: 0x1000 (R/W) OTP direct access */
        struct lcm_otp_layout_t otp;
    };
};

static int is_pointer_word_aligned(void *ptr) {
    return !((uintptr_t)ptr & (sizeof(uint32_t) - 1));
}

static void otp_write_unchecked(struct lcm_dev_t *dev, uint32_t offset,
                                uint32_t len, uint32_t *p_buf_word)
{
    uint32_t idx;
    struct _lcm_reg_map_t *p_lcm = (struct _lcm_reg_map_t *)dev->cfg->base;

    /* Perform the actual write */
    for (idx = 0; idx < len / sizeof(uint32_t); idx++) {
        p_lcm->raw_otp[(offset / sizeof(uint32_t)) + idx] = p_buf_word[idx];
    }
}

static void rma_erase_all_keys(struct lcm_dev_t *dev)
{
    uint32_t idx;
    uint32_t otp_overwrite_val = 0xFFFFFFFFu;

    /* Overwrite all secret keys with all-one words */
    for (idx = 0; idx < offsetof(struct lcm_otp_layout_t, rotpk);
         idx += sizeof(uint32_t)) {
        otp_write_unchecked(dev, idx, sizeof(otp_overwrite_val), &otp_overwrite_val);
    }
}

enum lcm_error_t lcm_init(struct lcm_dev_t *dev)
{
    struct _lcm_reg_map_t *p_lcm = (struct _lcm_reg_map_t *)dev->cfg->base;
    enum lcm_lcs_t lcs;
    enum lcm_error_t err;

    err = lcm_get_lcs(dev, &lcs);
    if (err != LCM_ERROR_NONE) {
        lcm_set_fatal_error(&LCM_DEV_S);
        return err;
    }

    if (lcs == LCM_LCS_SE) {
        if (p_lcm->key_err) {
            lcm_set_fatal_error(&LCM_DEV_S);
            FATAL_ERR(LCM_ERROR_INIT_INVALID_KEY);
            return LCM_ERROR_INIT_INVALID_KEY;
        }
    } else if (lcs == LCM_LCS_RMA) {
        rma_erase_all_keys(dev);
    }

    return LCM_ERROR_NONE;
}

enum lcm_error_t lcm_get_tp_mode(struct lcm_dev_t *dev, enum lcm_tp_mode_t *mode)
{
    struct _lcm_reg_map_t *p_lcm = (struct _lcm_reg_map_t *)dev->cfg->base;
    enum lcm_tp_mode_t double_check_mode;

    *mode = (enum lcm_tp_mode_t)p_lcm->tp_mode;

#ifdef KMU_S
        kmu_random_delay(&KMU_DEV_S, KMU_DELAY_LIMIT_32_CYCLES);
#endif /* KMU_S */

    double_check_mode = (enum lcm_tp_mode_t)p_lcm->tp_mode;

    if (*mode != double_check_mode) {
        return LCM_ERROR_GET_TP_MODE_CORRUPTION_DETECTED;
    }

    return LCM_ERROR_NONE;
}

enum lcm_error_t lcm_set_tp_mode(struct lcm_dev_t *dev, enum lcm_tp_mode_t mode)
{
    enum lcm_tp_mode_t curr_mode;
    enum lcm_lcs_t lcs;
    uint32_t mode_reg_value;
    uint32_t readback_reg_value;
    enum lcm_bool_t fatal_err;
    enum lcm_error_t err;

    err = lcm_get_lcs(dev, &lcs);
    if (err != LCM_ERROR_NONE) {
        return err;
    }

    if (lcs != LCM_LCS_CM) {
        FATAL_ERR(LCM_ERROR_SET_TP_MODE_INVALID_LCS);
        return LCM_ERROR_SET_TP_MODE_INVALID_LCS;
    }

    err = lcm_get_tp_mode(dev, &curr_mode);
    if (err != LCM_ERROR_NONE) {
        return err;
    }

    if(curr_mode != LCM_TP_MODE_VIRGIN) {
        FATAL_ERR(LCM_ERROR_SET_TP_MODE_INVALID_TRANSITION);
        return LCM_ERROR_SET_TP_MODE_INVALID_TRANSITION;
    }

    switch(mode) {
    case LCM_TP_MODE_TCI:
        /* High hamming-weight magic constant used to enable TCI mode */
        mode_reg_value = 0x0000FFFFu;
        break;
    case LCM_TP_MODE_PCI:
        /* High hamming-weight magic constant used to enable PCI mode */
        mode_reg_value = 0xFFFF0000u;
        break;
    default:
        FATAL_ERR(LCM_ERROR_SET_TP_MODE_INVALID_TRANSITION);
        return LCM_ERROR_SET_TP_MODE_INVALID_TRANSITION;
    }

    err = lcm_otp_write(dev, offsetof(struct lcm_otp_layout_t, tp_mode_config),
                        sizeof(uint32_t), (uint8_t *)&mode_reg_value);
    if (err != LCM_ERROR_NONE) {
        return err;
    }

    err = lcm_otp_read(dev, offsetof(struct lcm_otp_layout_t, tp_mode_config),
                       sizeof(uint32_t), (uint8_t *)&readback_reg_value);
    if (err != LCM_ERROR_NONE) {
        return err;
    }

    if (readback_reg_value != mode_reg_value) {
        FATAL_ERR(LCM_ERROR_SET_TP_MODE_INTERNAL_ERROR);
        return LCM_ERROR_SET_TP_MODE_INTERNAL_ERROR;
    }

    lcm_get_fatal_error(dev, &fatal_err);
    if (fatal_err == LCM_TRUE) {
        FATAL_ERR(LCM_ERROR_SET_TP_MODE_FATAL_ERROR);
        return LCM_ERROR_SET_TP_MODE_FATAL_ERROR;
    }

    return LCM_ERROR_NONE;
}

enum lcm_error_t lcm_get_sp_enabled(struct lcm_dev_t *dev, enum lcm_bool_t *enabled)
{
    struct _lcm_reg_map_t *p_lcm = (struct _lcm_reg_map_t *)dev->cfg->base;
    enum lcm_bool_t double_check_sp_mode;

    *enabled = (enum lcm_bool_t)p_lcm->sp_enable;

#ifdef KMU_S
    kmu_random_delay(&KMU_DEV_S, KMU_DELAY_LIMIT_32_CYCLES);
#endif /* KMU_S */

    double_check_sp_mode = (enum lcm_bool_t)p_lcm->sp_enable;

    if (double_check_sp_mode != *enabled) {
        return LCM_ERROR_GET_SP_ENABLED_CORRUPTION_DETECTED;
    }

    return LCM_ERROR_NONE;
}

static inline void mask_dcus_for_sp_enable(struct lcm_dev_t *dev)
{
    struct _lcm_reg_map_t *p_lcm = (struct _lcm_reg_map_t *)dev->cfg->base;
    size_t idx;
    uint32_t mask_enabled;
    uint32_t mask_disabled;
    uint32_t dcu_val;
    uint32_t mask_val;

    for (idx = 0; idx < LCM_DCU_WIDTH_IN_BYTES / sizeof(uint32_t); idx++) {
        mask_val = p_lcm->dcu_sp_disable_mask[idx];

        mask_enabled = mask_val & DCU_ENABLED_MASK;
        mask_disabled = mask_val & DCU_DISABLED_MASK;

        dcu_val = p_lcm->dcu_en[idx];

        dcu_val &= mask_enabled;
        dcu_val |= ((~dcu_val & DCU_ENABLED_MASK) << 1) & mask_disabled;

        p_lcm->dcu_en[idx] = dcu_val;
    }
}

enum lcm_error_t lcm_set_sp_enabled(struct lcm_dev_t *dev)
{
    struct _lcm_reg_map_t *p_lcm = (struct _lcm_reg_map_t *)dev->cfg->base;
    enum lcm_bool_t fatal_err;
    uint32_t idx;
    enum lcm_tp_mode_t tp_mode;
    enum lcm_error_t err;

    err = lcm_get_tp_mode(dev, &tp_mode);
    if (err != LCM_ERROR_NONE) {
        return err;
    }

    if (!((tp_mode == LCM_TP_MODE_PCI) || (tp_mode == LCM_TP_MODE_TCI))) {
        FATAL_ERR(LCM_ERROR_SET_LCS_INVALID_TP_MODE);
        return LCM_ERROR_SET_LCS_INVALID_TP_MODE;
    }

    mask_dcus_for_sp_enable(dev);

    /* High hamming-weight magic constant used to trigger secure provisioning
     * mode
     */
    p_lcm->sp_enable = 0x5EC10E1Eu;

    /* Perform a >2000 cycle wait in order for the secure provisioning reset to
     * happen, before checking if it has worked.
     */
    for (idx = 0; idx < 4000; idx++) {
        __NOP();
    }

    /* Put the CPU into an idle state so that the reset can occur */
    __WFI();

    while(p_lcm->sp_enable != LCM_TRUE) {}

    lcm_get_fatal_error(dev, &fatal_err);

    if (fatal_err == LCM_TRUE) {
        FATAL_ERR(LCM_ERROR_SET_SP_ENABLED_FATAL_ERROR);
        return LCM_ERROR_SET_SP_ENABLED_FATAL_ERROR;
    }

    return LCM_ERROR_NONE;
}

void lcm_get_fatal_error(struct lcm_dev_t *dev, enum lcm_bool_t *error)
{
    struct _lcm_reg_map_t *p_lcm = (struct _lcm_reg_map_t *)dev->cfg->base;

    *error = (enum lcm_bool_t)p_lcm->fatal_err;
}

void lcm_set_fatal_error(struct lcm_dev_t *dev)
{
    struct _lcm_reg_map_t *p_lcm = (struct _lcm_reg_map_t *)dev->cfg->base;

    /* High hamming-weight magic constant used to trigger fatal error state */
    p_lcm->fatal_err = 0xFA7A1EEEu;
}

void lcm_get_gppc(struct lcm_dev_t *dev, uint32_t *gppc)
{
    struct _lcm_reg_map_t *p_lcm = (struct _lcm_reg_map_t *)dev->cfg->base;

    *gppc = p_lcm->gppc;
}

void lcm_get_otp_size(struct lcm_dev_t *dev, uint32_t *size)
{
    struct _lcm_reg_map_t *p_lcm = (struct _lcm_reg_map_t *)dev->cfg->base;

    *size = p_lcm->otp_size_in_bytes;
}

enum lcm_error_t lcm_get_lcs(struct lcm_dev_t *dev, enum lcm_lcs_t *lcs)
{
    struct _lcm_reg_map_t *p_lcm = (struct _lcm_reg_map_t *)dev->cfg->base;
    enum lcm_bool_t fatal_err;
    enum lcm_lcs_t double_check_lcs;

    lcm_get_fatal_error(dev, &fatal_err);

    if (fatal_err == LCM_TRUE) {
        FATAL_ERR(LCM_ERROR_GET_LCS_FATAL_ERROR);
        return LCM_ERROR_GET_LCS_FATAL_ERROR;
    }

    *lcs = (enum lcm_lcs_t)p_lcm->lcs_value;

#ifdef KMU_S
    kmu_random_delay(&KMU_DEV_S, KMU_DELAY_LIMIT_32_CYCLES);
#endif /* KMU_S */

    double_check_lcs = (enum lcm_lcs_t)p_lcm->lcs_value;

    if (*lcs != double_check_lcs) {
        return LCM_ERROR_GET_LCS_CORRUPTION_DETECTED;
    }

    if (*lcs == LCM_LCS_INVALID) {
        return LCM_ERROR_GET_LCS_INVALID_LCS;
    }

    return LCM_ERROR_NONE;
}

#ifdef INTEGRITY_CHECKER_S
static enum lcm_error_t count_zero_bits(const uint32_t *addr, uint32_t len,
                                        uint32_t *zero_bits)
{
    enum integrity_checker_error_t ic_err;

    ic_err = integrity_checker_compute_value(&INTEGRITY_CHECKER_DEV_S,
                                             INTEGRITY_CHECKER_MODE_ZERO_COUNT,
                                             addr, len, zero_bits, sizeof(uint32_t),
                                             NULL);

    if (ic_err != INTEGRITY_CHECKER_ERROR_NONE) {
        FATAL_ERR(ic_err);
        return ic_err;
    }

    return LCM_ERROR_NONE;
}
#else
static enum lcm_error_t count_zero_bits(const uint32_t *addr, uint32_t len,
                                        uint32_t *zero_bits)
{
    uint32_t idx;
    uint32_t word;
    uint32_t bit_index;

    *zero_bits = 0;

    for (idx = 0; idx < len; idx += sizeof(uint32_t)) {
        word = addr[idx / sizeof(uint32_t)];

        for (bit_index = 0; bit_index < sizeof(word) * 8; bit_index++) {
            *zero_bits += 1 - ((word >> bit_index) & 1);
        }
    }

    return LCM_ERROR_NONE;
}
#endif /* INTEGRITY_CHECKER_DEV_S */

static enum lcm_error_t count_otp_zero_bits(struct lcm_dev_t *dev,
                                            uint32_t offset, uint32_t len,
                                            uint32_t *zero_bits)
{
    struct _lcm_reg_map_t *p_lcm = (struct _lcm_reg_map_t *)dev->cfg->base;

    return count_zero_bits((uint32_t *)(((uint8_t *)p_lcm->raw_otp) + offset),
                           len, zero_bits);
}

static enum lcm_error_t cm_to_dm(struct lcm_dev_t *dev, uint16_t gppc_val)
{
    enum lcm_error_t err;
    uint32_t config_val;
#ifdef INTEGRITY_CHECKER_S
 __ALIGNED(INTEGRITY_CHECKER_REQUIRED_ALIGNMENT)
#endif
    uint32_t zero_bits;

    config_val = LCM_TRUE;

    err = count_otp_zero_bits(dev, offsetof(struct lcm_otp_layout_t, huk), 32,
                              &zero_bits);
    if (err != LCM_ERROR_NONE) {
        return err;
    }
    if (zero_bits == 256) {
        err = lcm_otp_write(dev, offsetof(struct lcm_otp_layout_t, huk), 32,
                            (const uint8_t *)dummy_key_value);
        if (err != LCM_ERROR_NONE) {
            return err;
        }
    }

    err = count_otp_zero_bits(dev, offsetof(struct lcm_otp_layout_t, guk), 32,
                              &zero_bits);
    if (err != LCM_ERROR_NONE) {
        return err;
    }
    if (zero_bits == 256) {
        err = lcm_otp_write(dev, offsetof(struct lcm_otp_layout_t, guk), 32,
                            (const uint8_t *)dummy_key_value);
        if (err != LCM_ERROR_NONE) {
            return err;
        }
    }

    err = count_otp_zero_bits(dev, offsetof(struct lcm_otp_layout_t, kp_cm), 32,
                              &zero_bits);
    if (err != LCM_ERROR_NONE) {
        return err;
    }
    if (zero_bits == 256) {
        err = lcm_otp_write(dev, offsetof(struct lcm_otp_layout_t, kp_cm), 32,
                            (const uint8_t *)dummy_key_value);
        if (err != LCM_ERROR_NONE) {
            return err;
        }
    }

    err = count_otp_zero_bits(dev, offsetof(struct lcm_otp_layout_t, kce_cm), 32,
                              &zero_bits);
    if (err != LCM_ERROR_NONE) {
        return err;
    }
    if (zero_bits == 256) {
        err = lcm_otp_write(dev, offsetof(struct lcm_otp_layout_t, kce_cm), 32,
                            (const uint8_t *)dummy_key_value);
        if (err != LCM_ERROR_NONE) {
            return err;
        }
    }

    otp_write_unchecked(dev, offsetof(struct lcm_otp_layout_t, cm_config_1),
                        sizeof(uint32_t), &config_val);

    err = lcm_otp_read(dev, offsetof(struct lcm_otp_layout_t, cm_config_1),
                       sizeof(uint32_t), (uint8_t *)&config_val);
    if (err != LCM_ERROR_NONE) {
        return err;
    }

    if (config_val != 0) {
        return LCM_ERROR_CM_TO_DM_WRITE_VERIFY_FAIL;
    }

    config_val = 0;

    err = count_otp_zero_bits(dev, offsetof(struct lcm_otp_layout_t, rotpk),
                              32, &zero_bits);
    if (err != LCM_ERROR_NONE) {
        return err;
    }

    config_val |= (zero_bits & 0xFF) << 0;
    config_val |= ((uint32_t)gppc_val) << 8;
#if LCM_VERSION == 0
    /* The upper bit has been used to trigger the DM->CM transition already */
    config_val |= 0x800;
#endif /* LCM_VERSION == 0 */

    err = lcm_otp_write(dev, offsetof(struct lcm_otp_layout_t, cm_config_2),
                        sizeof(uint32_t), (uint8_t *)&config_val);
    if (err != LCM_ERROR_NONE) {
        return err;
    }

    return LCM_ERROR_NONE;
}

static enum lcm_error_t dm_to_se(struct lcm_dev_t *dev)
{
    enum lcm_error_t err;
    uint32_t config_val;
#ifdef INTEGRITY_CHECKER_S
 __ALIGNED(INTEGRITY_CHECKER_REQUIRED_ALIGNMENT)
#endif
    uint32_t zero_bits;

    err = count_otp_zero_bits(dev, offsetof(struct lcm_otp_layout_t, kp_dm), 32,
                              &zero_bits);
    if (err != LCM_ERROR_NONE) {
        return err;
    }
    if (zero_bits == 256) {
        err = lcm_otp_write(dev, offsetof(struct lcm_otp_layout_t, kp_dm), 32,
                            (const uint8_t *)dummy_key_value);
        if (err != LCM_ERROR_NONE) {
            return err;
        }
    }

    err = count_otp_zero_bits(dev, offsetof(struct lcm_otp_layout_t, kce_dm), 32,
                              &zero_bits);
    if (err != LCM_ERROR_NONE) {
        return err;
    }
    if (zero_bits == 256) {
        err = lcm_otp_write(dev, offsetof(struct lcm_otp_layout_t, kce_dm), 32,
                            (const uint8_t *)dummy_key_value);
        if (err != LCM_ERROR_NONE) {
            return err;
        }
    }

    config_val = LCM_TRUE;

    /* This OTP field doesn't read-back as written, but that isn't an error */
    err = lcm_otp_write(dev, offsetof(struct lcm_otp_layout_t, dm_config),
                        sizeof(uint32_t), (uint8_t *)&config_val);
    if (!(err == LCM_ERROR_NONE || err == LCM_ERROR_OTP_WRITE_WRITE_VERIFY_FAIL)) {
        FATAL_ERR(err);
        return err;
    }

    /* Manually check that the readback value is what we expect (0x0 means no
     * key bit count errors).
     */
    err = lcm_otp_read(dev, offsetof(struct lcm_otp_layout_t, dm_config),
                       sizeof(uint32_t), (uint8_t *)&config_val);
    if (err != LCM_ERROR_NONE) {
        return err;
    }

    if (config_val != 0) {
        FATAL_ERR(LCM_ERROR_DM_TO_SE_WRITE_VERIFY_FAIL);
        return LCM_ERROR_DM_TO_SE_WRITE_VERIFY_FAIL;
    }

    return LCM_ERROR_NONE;
}

static enum lcm_error_t any_to_rma(struct lcm_dev_t *dev)
{
    enum lcm_error_t err;
    uint32_t rma_flag = LCM_TRUE;

    /* Write the CM RMA flag */
    err = lcm_otp_write(dev, offsetof(struct lcm_otp_layout_t, cm_rma_flag),
                        sizeof(uint32_t), (uint8_t *)&rma_flag);
    if (err != LCM_ERROR_NONE) {
        return err;
    }

    /* Write the DM RMA flag */
    err = lcm_otp_write(dev, offsetof(struct lcm_otp_layout_t, dm_rma_flag),
                        sizeof(uint32_t), (uint8_t *)&rma_flag);
    if (err != LCM_ERROR_NONE) {
        return err;
    }

    return LCM_ERROR_NONE;
}

enum lcm_error_t lcm_set_lcs(struct lcm_dev_t *dev, enum lcm_lcs_t lcs,
                             uint16_t gppc_val)
{
    enum lcm_bool_t fatal_err;
    enum lcm_bool_t sp_enable;
    enum lcm_tp_mode_t tp_mode;
    enum lcm_error_t err;
    enum lcm_lcs_t curr_lcs;

    err = lcm_get_lcs(dev, &curr_lcs);
    if (err != LCM_ERROR_NONE) {
        return err;
    }
    if (lcs == curr_lcs) {
        return LCM_ERROR_NONE;
    }

    err = lcm_get_tp_mode(dev, &tp_mode);
    if (err != LCM_ERROR_NONE) {
        return err;
    }

    if (!(tp_mode == LCM_TP_MODE_PCI || tp_mode == LCM_TP_MODE_TCI)) {
        FATAL_ERR(LCM_ERROR_SET_LCS_INVALID_TP_MODE);
        return LCM_ERROR_SET_LCS_INVALID_TP_MODE;
    }

    /* Transition to RMA doesn't require Secure Provisioning mode enabled */
    if (lcs == LCM_LCS_RMA) {
        return any_to_rma(dev);
    }

    err = lcm_get_sp_enabled(dev, &sp_enable);
    if (err != LCM_ERROR_NONE) {
        return err;
    }
    if (sp_enable != LCM_TRUE) {
        err = lcm_set_sp_enabled(dev);
        if (err != LCM_ERROR_NONE) {
            return err;
        }
    }

    do {
        err = lcm_get_sp_enabled(dev, &sp_enable);
        if (err != LCM_ERROR_NONE) {
            return err;
        }
        lcm_get_fatal_error(dev, &fatal_err);
    } while (sp_enable == LCM_FALSE && fatal_err == LCM_FALSE);

    if (fatal_err == LCM_TRUE) {
        FATAL_ERR(LCM_ERROR_SET_LCS_FATAL_ERROR);
        return LCM_ERROR_SET_LCS_FATAL_ERROR;
    }

    switch (lcs) {
    case LCM_LCS_CM:
        /* There's no possible valid transition back to CM */
        FATAL_ERR(LCM_ERROR_SET_LCS_INVALID_TRANSITION);
        return LCM_ERROR_SET_LCS_INVALID_TRANSITION;
    case LCM_LCS_DM:
        if (curr_lcs != LCM_LCS_CM) {
            FATAL_ERR(LCM_ERROR_SET_LCS_INVALID_TRANSITION);
            return LCM_ERROR_SET_LCS_INVALID_TRANSITION;
        }

        return cm_to_dm(dev, gppc_val);

    case LCM_LCS_SE:
        if (curr_lcs != LCM_LCS_DM) {
            FATAL_ERR(LCM_ERROR_SET_LCS_INVALID_TRANSITION);
            return LCM_ERROR_SET_LCS_INVALID_TRANSITION;
        }

        return dm_to_se(dev);

    case LCM_LCS_INVALID:
        FATAL_ERR(LCM_ERROR_SET_LCS_INVALID_LCS);
        return LCM_ERROR_SET_LCS_INVALID_LCS;

    case LCM_LCS_RMA:
        /* Should never get here */
        break;
    }

    /* Should never get here */
    FATAL_ERR(LCM_ERROR_SET_LCS_INTERNAL_ERROR);
    return LCM_ERROR_SET_LCS_INTERNAL_ERROR;
}

static const struct lcm_hw_slot_zero_count_mapping {
    uint32_t offset;
    uint32_t size;
    uint32_t zero_count_offset;
    uint32_t shift;
    uint32_t bit_size;
} zero_count_mappings[] = {
#if (LCM_VERSION == 1)
    {
        offsetof(struct lcm_otp_layout_t, huk),
        sizeof(((struct lcm_otp_layout_t*)0)->huk),
        offsetof(struct lcm_otp_layout_t, cm_config_1),
        0,
        8,
    },
    {
        offsetof(struct lcm_otp_layout_t, guk),
        sizeof(((struct lcm_otp_layout_t*)0)->guk),
        offsetof(struct lcm_otp_layout_t, cm_config_1),
        8,
        8,
    },
    {
        offsetof(struct lcm_otp_layout_t, kp_cm),
        sizeof(((struct lcm_otp_layout_t*)0)->kp_cm),
        offsetof(struct lcm_otp_layout_t, cm_config_1),
        16,
        8,
    },
    {
        offsetof(struct lcm_otp_layout_t, kce_cm),
        sizeof(((struct lcm_otp_layout_t*)0)->kce_cm),
        offsetof(struct lcm_otp_layout_t, cm_config_1),
        24,
        8,
    },
#endif /* (LCM_VERSION == 1) */

    {
        offsetof(struct lcm_otp_layout_t, rotpk),
        sizeof(((struct lcm_otp_layout_t*)0)->rotpk),
        offsetof(struct lcm_otp_layout_t, cm_config_2),
        0,
        8,
    },

#if (LCM_VERSION == 1)
    {
        offsetof(struct lcm_otp_layout_t, kp_dm),
        sizeof(((struct lcm_otp_layout_t*)0)->kp_dm),
        offsetof(struct lcm_otp_layout_t, dm_config),
        0,
        8,
    },
    {
        offsetof(struct lcm_otp_layout_t, kce_dm),
        sizeof(((struct lcm_otp_layout_t*)0)->kce_dm),
        offsetof(struct lcm_otp_layout_t, dm_config),
        8,
        8,
    },
#endif /* (LCM_VERSION == 1) */
};

static enum lcm_error_t write_zero_count_if_needed(struct lcm_dev_t *dev,
                                                   uint32_t offset,
                                                   uint32_t len,
                                                   const uint8_t *buf)
{
    enum lcm_error_t err;
    uint32_t idx;
    uint32_t zero_bits = 0;
    uint32_t otp_word;
    const struct lcm_hw_slot_zero_count_mapping *mapping;
    bool zero_count_needed = false;

    for (idx = 0;
         idx < (sizeof(zero_count_mappings) / sizeof(zero_count_mappings[0]));
         idx++) {
        mapping = &zero_count_mappings[idx];
        if (offset == mapping->offset) {
            zero_count_needed = true;
            break;
        }
    }

    /* No zero count needed */
    if (!zero_count_needed) {
        return LCM_ERROR_NONE;
    }

    err = count_zero_bits((uint32_t *)buf, len, &zero_bits);
    if (err != LCM_ERROR_NONE) {
        return err;
    }

    /* sanity check that we don't overflow */
    assert((zero_bits & ~((1 << mapping->bit_size) - 1)) == 0);

    if (zero_bits & ~((1 << mapping->bit_size) - 1)) {
        return LCM_ERROR_ZERO_COUNT_INVALID;
    }

    err = lcm_otp_read(dev, mapping->zero_count_offset, sizeof(otp_word),
                        (uint8_t *)&otp_word);
    if (err != LCM_ERROR_NONE) {
        return err;
    }

    otp_word |= zero_bits << mapping->shift;

    otp_write_unchecked(dev, mapping->zero_count_offset,
                        sizeof(otp_word), &otp_word);

    return LCM_ERROR_NONE;
}

/* Armclang attempts to inline this function, which causes huge code size
 * increases. It is marked as __attribute__((noinline)) explicitly to prevent
 * this.
 */
__attribute__((noinline))
enum lcm_error_t lcm_otp_write(struct lcm_dev_t *dev, uint32_t offset, uint32_t len,
                               const uint8_t *buf)
{
    enum lcm_error_t err;
    struct _lcm_reg_map_t *p_lcm = (struct _lcm_reg_map_t *)dev->cfg->base;
    uint32_t *p_buf_word = (uint32_t *)buf;
    uint32_t otp_size;
    uint32_t idx;

    if (!is_pointer_word_aligned(p_buf_word)) {
        FATAL_ERR(LCM_ERROR_OTP_WRITE_INVALID_ALIGNMENT);
        return LCM_ERROR_OTP_WRITE_INVALID_ALIGNMENT;
    }

    if (offset & (sizeof(uint32_t) - 1)) {
        FATAL_ERR(LCM_ERROR_OTP_WRITE_INVALID_OFFSET);
        return LCM_ERROR_OTP_WRITE_INVALID_OFFSET;
    }

    if (len & (sizeof(uint32_t) - 1)) {
        FATAL_ERR(LCM_ERROR_OTP_WRITE_INVALID_LENGTH);
        return LCM_ERROR_OTP_WRITE_INVALID_LENGTH;
    }

    lcm_get_otp_size(dev, &otp_size);

    if (otp_size < (offset + len)) {
        FATAL_ERR(LCM_ERROR_OTP_WRITE_INVALID_OFFSET);
        return LCM_ERROR_OTP_WRITE_INVALID_OFFSET;
    }

    for (idx = 0; idx < len / sizeof(uint32_t); idx++) {
        if (p_buf_word[idx] != (p_buf_word[idx] | p_lcm->raw_otp[(offset / sizeof(uint32_t)) + idx])) {
            NONFATAL_ERR(LCM_ERROR_OTP_WRITE_INVALID_WRITE);
            return LCM_ERROR_OTP_WRITE_INVALID_WRITE;
        }
    }

    /* Write the zero count if needed */
    err = write_zero_count_if_needed(dev, offset, len, buf);
    if (err != LCM_ERROR_NONE) {
        return err;
    }

    /* Perform the actual write */
    otp_write_unchecked(dev, offset, len, p_buf_word);

    /* Verify the write is correct */
    for (idx = 0; idx < len / sizeof(uint32_t); idx++) {
        if (p_buf_word[idx] != p_lcm->raw_otp[(offset / sizeof(uint32_t)) + idx]) {
            NONFATAL_ERR(LCM_ERROR_OTP_WRITE_WRITE_VERIFY_FAIL);
            return LCM_ERROR_OTP_WRITE_WRITE_VERIFY_FAIL;
        }
    }

    return LCM_ERROR_NONE;
}


/* Armclang attempts to inline this function, which causes huge code size
 * increases. It is marked as __attribute__((noinline)) explicitly to prevent
 * this.
 */
__attribute__((noinline))
enum lcm_error_t lcm_otp_read(struct lcm_dev_t *dev, uint32_t offset,
                              uint32_t len, uint8_t *buf)
{
    struct _lcm_reg_map_t *p_lcm = (struct _lcm_reg_map_t *)dev->cfg->base;
    uint32_t *p_buf_word = (uint32_t *)buf;
    uint32_t validation_word;
    uint32_t otp_size;
    uint32_t idx;

    if (!is_pointer_word_aligned(p_buf_word)) {
        FATAL_ERR(LCM_ERROR_OTP_READ_INVALID_ALIGNMENT);
        return LCM_ERROR_OTP_READ_INVALID_ALIGNMENT;
    }

    if (offset & (sizeof(uint32_t) - 1)) {
        FATAL_ERR(LCM_ERROR_OTP_READ_INVALID_OFFSET);
        return LCM_ERROR_OTP_READ_INVALID_OFFSET;
    }

    if (len & (sizeof(uint32_t) - 1)) {
        FATAL_ERR(LCM_ERROR_OTP_READ_INVALID_LENGTH);
        return LCM_ERROR_OTP_READ_INVALID_LENGTH;
    }

    lcm_get_otp_size(dev, &otp_size);

    if (otp_size < (offset + len)) {
        FATAL_ERR(LCM_ERROR_OTP_READ_INVALID_OFFSET);
        return LCM_ERROR_OTP_READ_INVALID_OFFSET;
    }

    for (idx = 0; idx < len / sizeof(uint32_t); idx++) {
        p_buf_word[idx] = p_lcm->raw_otp[(offset / sizeof(uint32_t)) + idx];

#ifdef KMU_S
        kmu_random_delay(&KMU_DEV_S, KMU_DELAY_LIMIT_32_CYCLES);
#endif /* KMU_S */
        /* Double read verify is done in hardware for addresses outside of the
         * LCM OTP user area. In that case, don't perform a software check.
         */
        if (offset >= sizeof(struct lcm_otp_layout_t)) {
            validation_word = p_lcm->raw_otp[(offset / sizeof(uint32_t)) + idx];
            if (validation_word != p_buf_word[idx]) {
                FATAL_ERR(LCM_ERROR_OTP_READ_READ_VERIFY_FAIL);
                return LCM_ERROR_OTP_READ_READ_VERIFY_FAIL;
            }
        }
    }

    return LCM_ERROR_NONE;
}

enum lcm_error_t lcm_dcu_get_enabled(struct lcm_dev_t *dev, uint8_t *val)
{
    struct _lcm_reg_map_t *p_lcm = (struct _lcm_reg_map_t *)dev->cfg->base;
    uint32_t *p_val_word = (uint32_t *)val;
    uint32_t idx;

    if (!is_pointer_word_aligned(p_val_word)) {
        FATAL_ERR(LCM_ERROR_DCU_GET_ENABLED_INVALID_ALIGNMENT);
        return LCM_ERROR_DCU_GET_ENABLED_INVALID_ALIGNMENT;
    }

    for (idx = 0; idx < LCM_DCU_WIDTH_IN_BYTES / sizeof(uint32_t); idx++) {
        p_val_word[idx] = p_lcm->dcu_en[idx];
    }

    return LCM_ERROR_NONE;
}

static enum lcm_error_t check_dcu_mask(struct lcm_dev_t *dev, uint32_t *val)
{
    struct _lcm_reg_map_t *p_lcm = (struct _lcm_reg_map_t *)dev->cfg->base;
    size_t idx;

    for (idx = 0; idx < LCM_DCU_WIDTH_IN_BYTES / sizeof(uint32_t); idx++) {
        if (val[idx] & ~p_lcm->dcu_disable_mask[idx]) {
            return LCM_ERROR_DCU_CHECK_MASK_MISMATCH;
        }
    }

    return LCM_ERROR_NONE;
}

enum lcm_error_t lcm_dcu_set_enabled(struct lcm_dev_t *dev, uint8_t *val)
{
    struct _lcm_reg_map_t *p_lcm = (struct _lcm_reg_map_t *)dev->cfg->base;
    uint32_t *p_val_word = (uint32_t *)val;
    enum lcm_error_t err;
    uint32_t idx;

    if (!is_pointer_word_aligned(p_val_word)) {
        FATAL_ERR(LCM_ERROR_DCU_SET_ENABLED_INVALID_ALIGNMENT);
        return LCM_ERROR_DCU_SET_ENABLED_INVALID_ALIGNMENT;
    }

    err = check_dcu_mask(dev, p_val_word);
    if (err != LCM_ERROR_NONE) {
        return err;
    }

    for (idx = 0; idx < LCM_DCU_WIDTH_IN_BYTES / sizeof(uint32_t); idx++) {
        p_lcm->dcu_en[idx] = p_val_word[idx];
    }

    for (idx = 0; idx < LCM_DCU_WIDTH_IN_BYTES / sizeof(uint32_t); idx++) {
        if (p_lcm->dcu_en[idx] != p_val_word[idx]) {
            FATAL_ERR(LCM_ERROR_DCU_SET_ENABLED_WRITE_VERIFY_FAIL);
            return LCM_ERROR_DCU_SET_ENABLED_WRITE_VERIFY_FAIL;
        }
    }

    /* The __ISB() ensures a Context Synchronisation Event (CSE) happens
     * after all the memory accesses have completed using __DSB()
     */
    __DSB();
    __ISB();

    return LCM_ERROR_NONE;
}

enum lcm_error_t lcm_dcu_get_locked(struct lcm_dev_t *dev, uint8_t *val)
{
    struct _lcm_reg_map_t *p_lcm = (struct _lcm_reg_map_t *)dev->cfg->base;
    uint32_t *p_val_word = (uint32_t *)val;
    uint32_t idx;

    if (!is_pointer_word_aligned(p_val_word)) {
        FATAL_ERR(LCM_ERROR_DCU_GET_LOCKED_INVALID_ALIGNMENT);
        return LCM_ERROR_DCU_GET_LOCKED_INVALID_ALIGNMENT;
    }

    for (idx = 0; idx < LCM_DCU_WIDTH_IN_BYTES / sizeof(uint32_t); idx++) {
        p_val_word[idx] = p_lcm->dcu_lock[idx];
    }

    return LCM_ERROR_NONE;
}

enum lcm_error_t lcm_dcu_set_locked(struct lcm_dev_t *dev, uint8_t *val)
{
    struct _lcm_reg_map_t *p_lcm = (struct _lcm_reg_map_t *)dev->cfg->base;
    uint32_t *p_val_word = (uint32_t *)val;
    uint32_t idx;

    if (!is_pointer_word_aligned(p_val_word)) {
        FATAL_ERR(LCM_ERROR_DCU_SET_LOCKED_INVALID_ALIGNMENT);
        return LCM_ERROR_DCU_SET_LOCKED_INVALID_ALIGNMENT;
    }

    for (idx = 0; idx < LCM_DCU_WIDTH_IN_BYTES / sizeof(uint32_t); idx++) {
        p_lcm->dcu_lock[idx] = p_val_word[idx];
    }

    return LCM_ERROR_NONE;
}

enum lcm_error_t lcm_dcu_get_sp_disable_mask(struct lcm_dev_t *dev, uint8_t *val)
{
    struct _lcm_reg_map_t *p_lcm = (struct _lcm_reg_map_t *)dev->cfg->base;
    uint32_t *p_val_word = (uint32_t *)val;
    uint32_t idx;

    if (!is_pointer_word_aligned(p_val_word)) {
        FATAL_ERR(LCM_ERROR_DCU_GET_SP_DISABLE_MASK_INVALID_ALIGNMENT);
        return LCM_ERROR_DCU_GET_SP_DISABLE_MASK_INVALID_ALIGNMENT;
    }

    for (idx = 0; idx < LCM_DCU_WIDTH_IN_BYTES / sizeof(uint32_t); idx++) {
        p_val_word[idx] = p_lcm->dcu_sp_disable_mask[idx];
    }

    return LCM_ERROR_NONE;
}

enum lcm_error_t lcm_dcu_get_disable_mask(struct lcm_dev_t *dev, uint8_t *val)
{
    struct _lcm_reg_map_t *p_lcm = (struct _lcm_reg_map_t *)dev->cfg->base;
    uint32_t *p_val_word = (uint32_t *)val;
    uint32_t idx;

    if (!is_pointer_word_aligned(p_val_word)) {
        FATAL_ERR(LCM_ERROR_DCU_GET_DISABLE_MASK_INVALID_ALIGNMENT);
        return LCM_ERROR_DCU_GET_DISABLE_MASK_INVALID_ALIGNMENT;
    }

    for (idx = 0; idx < LCM_DCU_WIDTH_IN_BYTES / sizeof(uint32_t); idx++) {
         p_val_word[idx] = p_lcm->dcu_disable_mask[idx];
    }

    return LCM_ERROR_NONE;
}
