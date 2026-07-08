/*
 * Copyright (c) 2025, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**/

#include <ti/driverlib/dl_gsc.h>

bool DL_GSC_configureHDPRegion(
    GSC_Regs* gsc, uint8_t startSec, uint8_t endSec, uint8_t bank)
{
    // Validate sector range
    if (endSec < startSec) {
        return false;
    }

    // In single bank mode or bank 0 configuration, use HDPPROT0
    if (bank == 0) {
        gsc->FPC_HDPPROT0_CONFIG =
            ((uint32_t) startSec << GSC_FPC_HDPPROT0_CONFIG_HDPSTART_OFS) |
            ((uint32_t) endSec << GSC_FPC_HDPPROT0_CONFIG_HDPEND_OFS);
    }
    // In dual bank mode and bank 1 configuration
    else if (bank == 1) {
        gsc->FPC_HDPPROT1_CONFIG =
            ((uint32_t) startSec << GSC_FPC_HDPPROT1_CONFIG_HDPSTART_OFS) |
            ((uint32_t) endSec << GSC_FPC_HDPPROT1_CONFIG_HDPEND_OFS);
    } else {
        return false;
    }

    return true;
}

void DL_GSC_setHDPAccess(GSC_Regs* gsc, bool enable, uint8_t bank)
{
    // Read current control register value
    uint32_t val = gsc->FPC_HDPPROT_CONTROL;

    if (bank == 0) {
        // Clear current bank 0 access control bit
        val &= ~GSC_FPC_HDPPROT_CONTROL_HDPPROT0ACCDIS_MASK;

        // Set new access control value for bank 0
        // HDPPROT0ACCDIS = 0: Enable access to HDP region
        // HDPPROT0ACCDIS = 1: Disable access to HDP region
        val |=
            ((enable ? 0U : 1U) << GSC_FPC_HDPPROT_CONTROL_HDPPROT0ACCDIS_OFS);
    } else if (bank == 1) {
        // Clear current bank 1 access control bit
        val &= ~GSC_FPC_HDPPROT_CONTROL_HDPPROT1ACCDIS_MASK;

        // Set new access control value for bank 1
        // HDPPROT1ACCDIS = 0: Enable access to HDP region
        // HDPPROT1ACCDIS = 1: Disable access to HDP region
        // Note: In single-bank mode, setting either bank's access control
        // will affect both regions
        val |=
            ((enable ? 0U : 1U) << GSC_FPC_HDPPROT_CONTROL_HDPPROT1ACCDIS_OFS);
    }

    // Write updated control value back to register
    gsc->FPC_HDPPROT_CONTROL = val;
}

bool DL_GSC_configureDataBankHDPRegion(
    GSC_Regs* gsc, uint8_t startSec, uint8_t endSec)
{
    // Validate sector range
    if (endSec < startSec) {
        return false;
    }

    // Configure the HDP region for data bank
    gsc->FPC_HDPPROT_DBANK_CONFIG =
        ((uint32_t) startSec << GSC_FPC_HDPPROT_DBANK_CONFIG_HDPSTART_OFS) |
        ((uint32_t) endSec << GSC_FPC_HDPPROT_DBANK_CONFIG_HDPEND_OFS);

    return true;
}

void DL_GSC_setFixedTriggerDMAInstance(GSC_Regs* gsc,
    DL_GSC_DMA_FixedTrigger trigger, DL_GSC_DMA_Instance instance)
{
    uint32_t mask  = ~(1U << trigger);
    uint32_t value = gsc->DMA_FIX_TRIG_SEL & mask;
    value |= ((uint32_t) instance << trigger);
    gsc->DMA_FIX_TRIG_SEL = value;
}

void DL_GSC_setRegularTriggerDMAInstance(GSC_Regs* gsc,
    DL_GSC_DMA_RegularTrigger trigger, DL_GSC_DMA_Instance instance)
{
    // Check for triggers that can only go to DMA0
    if (instance == DL_GSC_DMA_INSTANCE_1 &&
        (trigger >= DL_GSC_DMA_TRIG_UC1_0_TX &&
            trigger <= DL_GSC_DMA_TRIG_UC1_1_RX)) {
        return;
    }

    uint32_t mask  = ~(1U << trigger);
    uint32_t value = gsc->DMA_TRIG_SEL & mask;
    value |= ((uint32_t) instance << trigger);
    gsc->DMA_TRIG_SEL = value;
}

DL_GSC_DMA_Instance DL_GSC_getFixedTriggerDMAInstance(
    GSC_Regs* gsc, DL_GSC_DMA_FixedTrigger trigger)
{
    return (DL_GSC_DMA_Instance)((gsc->DMA_FIX_TRIG_SEL >> trigger) & 0x1);
}

DL_GSC_DMA_Instance DL_GSC_getRegularTriggerDMAInstance(
    GSC_Regs* gsc, DL_GSC_DMA_RegularTrigger trigger)
{
    return (DL_GSC_DMA_Instance)((gsc->DMA_TRIG_SEL >> trigger) & 0x1);
}

/**
 * @brief Set lock configuration using configuration structure
 *
 * @param[in] gsc       Pointer to the GSC peripheral register block
 * @param[in] config    Pointer to lock configuration structure
 *
 * @note Once locked, configurations cannot be modified unless uncommitted
 * @note Writing lock requires valid key (0xA551)
 *
 * Example usage:
 * @code
 * DL_GSC_LockConfig lockCfg = {0};  // Initialize all to false
 * lockCfg.vtor = true;              // Lock VTOR configuration
 * lockCfg.dmaTrigSel = true;        // Lock DMA trigger selection
 * DL_GSC_setLockConfiguration(gsc, &lockCfg);
 * @endcode
 */
void DL_GSC_setLockConfiguration(
    GSC_Regs* gsc, const DL_GSC_LockConfig* config)
{
    uint32_t lockValue = 0;

    // Build lock value based on configuration structure
    if (config->attribViolConfig) {
        lockValue |= GSC_GSC_LOCK_ATTRIBVIOL_CONFIG_MASK;
    }
    if (config->ppcAttrib) {
        lockValue |= GSC_GSC_LOCK_PPC_AATRIB_MASK;
    }
    if (config->spcAttrib) {
        lockValue |= GSC_GSC_LOCK_SPC_AATRIB_MASK;
    }
    if (config->fppcAttrib) {
        lockValue |= GSC_GSC_LOCK_FPPC_AATRIB_MASK;
    }
    if (config->vtor) {
        lockValue |= GSC_GSC_LOCK_VTOR_MASK;
    }
    if (config->dmaTrigSel) {
        lockValue |= GSC_GSC_LOCK_DMA_TRIG_SEL_MASK;
    }
    if (config->dtbMuxSel) {
        lockValue |= GSC_GSC_LOCK_DTB_MUXSEL_MASK;
    }

    // Combine with key
    uint32_t value =
        ((DL_GSC_LOCK_KEY << GSC_GSC_LOCK_KEY_OFS) & GSC_GSC_LOCK_KEY_MASK) |
        (lockValue & ~GSC_GSC_LOCK_KEY_MASK);

    gsc->GSC_LOCK = value;
}

/**
 * @brief Get current lock configuration
 *
 * @param[in] gsc       Pointer to the GSC peripheral register block
 * @param[out] config   Pointer to structure to store current configuration
 *
 * Example usage:
 * @code
 * DL_GSC_LockConfig currentCfg;
 * DL_GSC_getLockConfiguration(gsc, &currentCfg);
 * if(currentCfg.vtor) {
 *     // VTOR configuration is locked
 * }
 * @endcode
 */
void DL_GSC_getLockConfiguration(GSC_Regs* gsc, DL_GSC_LockConfig* config)
{
    uint32_t currentValue = gsc->GSC_LOCK & ~GSC_GSC_LOCK_KEY_MASK;

    config->attribViolConfig =
        (currentValue & GSC_GSC_LOCK_ATTRIBVIOL_CONFIG_MASK) != 0;
    config->ppcAttrib  = (currentValue & GSC_GSC_LOCK_PPC_AATRIB_MASK) != 0;
    config->spcAttrib  = (currentValue & GSC_GSC_LOCK_SPC_AATRIB_MASK) != 0;
    config->fppcAttrib = (currentValue & GSC_GSC_LOCK_FPPC_AATRIB_MASK) != 0;
    config->vtor       = (currentValue & GSC_GSC_LOCK_VTOR_MASK) != 0;
    config->dmaTrigSel = (currentValue & GSC_GSC_LOCK_DMA_TRIG_SEL_MASK) != 0;
    config->dtbMuxSel  = (currentValue & GSC_GSC_LOCK_DTB_MUXSEL_MASK) != 0;
}

/**
 * @brief Set commit configuration using configuration structure
 *
 * @param[in] gsc       Pointer to the GSC peripheral register block
 * @param[in] config    Pointer to commit configuration structure
 *
 * @note Once committed, configurations cannot be modified until reset
 * @note Writing commit requires valid key (0xA442)
 *
 * Example usage:
 * @code
 * DL_GSC_LockConfig commitCfg = {0};  // Initialize all to false
 * commitCfg.vtor = true;              // Commit VTOR configuration
 * commitCfg.dmaTrigSel = true;        // Commit DMA trigger selection
 * DL_GSC_setCommitConfiguration(gsc, &commitCfg);
 * @endcode
 */
void DL_GSC_setCommitConfiguration(
    GSC_Regs* gsc, const DL_GSC_LockConfig* config)
{
    uint32_t commitValue = 0;

    // Build commit value based on configuration structure
    if (config->attribViolConfig) {
        commitValue |= GSC_GSC_COMMIT_ATTRIBVIOL_CONFIG_MASK;
    }
    if (config->ppcAttrib) {
        commitValue |= GSC_GSC_COMMIT_PPC_AATRIB_MASK;
    }
    if (config->spcAttrib) {
        commitValue |= GSC_GSC_COMMIT_SPC_AATRIB_MASK;
    }
    if (config->fppcAttrib) {
        commitValue |= GSC_GSC_COMMIT_FPPC_AATRIB_MASK;
    }
    if (config->vtor) {
        commitValue |= GSC_GSC_COMMIT_VTOR_MASK;
    }
    if (config->dmaTrigSel) {
        commitValue |= GSC_GSC_COMMIT_DMA_TRIG_SEL_MASK;
    }
    if (config->dtbMuxSel) {
        commitValue |= GSC_GSC_COMMIT_DTB_MUXSEL_MASK;
    }

    // Combine with key
    uint32_t value = ((DL_GSC_COMMIT_KEY << GSC_GSC_COMMIT_KEY_OFS) &
                         GSC_GSC_COMMIT_KEY_MASK) |
                     (commitValue & ~GSC_GSC_COMMIT_KEY_MASK);

    gsc->GSC_COMMIT = value;
}

/**
 * @brief Get current commit configuration
 *
 * @param[in] gsc       Pointer to the GSC peripheral register block
 * @param[out] config   Pointer to structure to store current configuration
 *
 * Example usage:
 * @code
 * DL_GSC_LockConfig currentCommitCfg;
 * DL_GSC_getCommitConfiguration(gsc, &currentCommitCfg);
 * if(currentCommitCfg.vtor) {
 *     // VTOR configuration is committed
 * }
 * @endcode
 */
void DL_GSC_getCommitConfiguration(GSC_Regs* gsc, DL_GSC_LockConfig* config)
{
    uint32_t currentValue = gsc->GSC_COMMIT & ~GSC_GSC_COMMIT_KEY_MASK;

    config->attribViolConfig =
        (currentValue & GSC_GSC_COMMIT_ATTRIBVIOL_CONFIG_MASK) != 0;
    config->ppcAttrib  = (currentValue & GSC_GSC_COMMIT_PPC_AATRIB_MASK) != 0;
    config->spcAttrib  = (currentValue & GSC_GSC_COMMIT_SPC_AATRIB_MASK) != 0;
    config->fppcAttrib = (currentValue & GSC_GSC_COMMIT_FPPC_AATRIB_MASK) != 0;
    config->vtor       = (currentValue & GSC_GSC_COMMIT_VTOR_MASK) != 0;
    config->dmaTrigSel =
        (currentValue & GSC_GSC_COMMIT_DMA_TRIG_SEL_MASK) != 0;
    config->dtbMuxSel = (currentValue & GSC_GSC_COMMIT_DTB_MUXSEL_MASK) != 0;
}

void DL_GSC_configureSRAMSecurity(
    GSC_Regs* gsc, const DL_GSC_SRAMSecurityConfig* config)
{
    uint32_t secAttrib0 = 0;
    uint32_t secAttrib1 = 0;
    uint32_t secAttrib2 = 0;
    uint32_t secAttrib3 = 0;

    // Process pages 0-3 for SECATTRIB0
    for (uint32_t page = 0; page < 4; page++) {
        uint32_t offset = page * 8;
        secAttrib0 |=
            ((config->pages[page].chunk_512B_0 & 1U) << (offset + 0));
        secAttrib0 |=
            ((config->pages[page].chunk_512B_1 & 1U) << (offset + 1));
        secAttrib0 |= ((config->pages[page].chunk_1KB & 1U) << (offset + 2));
        secAttrib0 |= ((config->pages[page].chunk_2KB & 1U) << (offset + 3));
        secAttrib0 |= ((config->pages[page].chunk_4KB_0 & 1U) << (offset + 4));
        secAttrib0 |= ((config->pages[page].chunk_4KB_1 & 1U) << (offset + 5));
        secAttrib0 |= ((config->pages[page].chunk_4KB_2 & 1U) << (offset + 6));
    }

    // Process pages 4-7 for SECATTRIB1
    for (uint32_t page = 4; page < 8; page++) {
        uint32_t offset = (page - 4) * 8;
        secAttrib1 |=
            ((config->pages[page].chunk_512B_0 & 1U) << (offset + 0));
        secAttrib1 |=
            ((config->pages[page].chunk_512B_1 & 1U) << (offset + 1));
        secAttrib1 |= ((config->pages[page].chunk_1KB & 1U) << (offset + 2));
        secAttrib1 |= ((config->pages[page].chunk_2KB & 1U) << (offset + 3));
        secAttrib1 |= ((config->pages[page].chunk_4KB_0 & 1U) << (offset + 4));
        secAttrib1 |= ((config->pages[page].chunk_4KB_1 & 1U) << (offset + 5));
        secAttrib1 |= ((config->pages[page].chunk_4KB_2 & 1U) << (offset + 6));
    }

    // Process pages 8-11 for SECATTRIB2
    for (uint32_t page = 8; page < 12; page++) {
        uint32_t offset = (page - 8) * 8;
        secAttrib2 |=
            ((config->pages[page].chunk_512B_0 & 1U) << (offset + 0));
        secAttrib2 |=
            ((config->pages[page].chunk_512B_1 & 1U) << (offset + 1));
        secAttrib2 |= ((config->pages[page].chunk_1KB & 1U) << (offset + 2));
        secAttrib2 |= ((config->pages[page].chunk_2KB & 1U) << (offset + 3));
        secAttrib2 |= ((config->pages[page].chunk_4KB_0 & 1U) << (offset + 4));
        secAttrib2 |= ((config->pages[page].chunk_4KB_1 & 1U) << (offset + 5));
        secAttrib2 |= ((config->pages[page].chunk_4KB_2 & 1U) << (offset + 6));
    }

    // Process pages 12-15 for SECATTRIB3
    for (uint32_t page = 12; page < 16; page++) {
        uint32_t offset = (page - 12) * 8;
        secAttrib3 |=
            ((config->pages[page].chunk_512B_0 & 1U) << (offset + 0));
        secAttrib3 |=
            ((config->pages[page].chunk_512B_1 & 1U) << (offset + 1));
        secAttrib3 |= ((config->pages[page].chunk_1KB & 1U) << (offset + 2));
        secAttrib3 |= ((config->pages[page].chunk_2KB & 1U) << (offset + 3));
        secAttrib3 |= ((config->pages[page].chunk_4KB_0 & 1U) << (offset + 4));
        secAttrib3 |= ((config->pages[page].chunk_4KB_1 & 1U) << (offset + 5));
        secAttrib3 |= ((config->pages[page].chunk_4KB_2 & 1U) << (offset + 6));
    }

    // Write configurations to registers
    gsc->SPC_SECATTRIB0 = secAttrib0;
    gsc->SPC_SECATTRIB1 = secAttrib1;
    gsc->SPC_SECATTRIB2 = secAttrib2;
    gsc->SPC_SECATTRIB3 = secAttrib3;
}

void DL_GSC_getSRAMSecurityConfig(
    GSC_Regs* gsc, DL_GSC_SRAMSecurityConfig* config)
{
    uint32_t secAttrib0 = gsc->SPC_SECATTRIB0;
    uint32_t secAttrib1 = gsc->SPC_SECATTRIB1;
    uint32_t secAttrib2 = gsc->SPC_SECATTRIB2;
    uint32_t secAttrib3 = gsc->SPC_SECATTRIB3;

    // Process pages 0-3 from SECATTRIB0
    for (uint32_t page = 0; page < 4; page++) {
        uint32_t offset = page * 8;
        config->pages[page].chunk_512B_0 =
            (secAttrib0 & (1U << (offset + 0))) ? 1U : 0U;
        config->pages[page].chunk_512B_1 =
            (secAttrib0 & (1U << (offset + 1))) ? 1U : 0U;
        config->pages[page].chunk_1KB =
            (secAttrib0 & (1U << (offset + 2))) ? 1U : 0U;
        config->pages[page].chunk_2KB =
            (secAttrib0 & (1U << (offset + 3))) ? 1U : 0U;
        config->pages[page].chunk_4KB_0 =
            (secAttrib0 & (1U << (offset + 4))) ? 1U : 0U;
        config->pages[page].chunk_4KB_1 =
            (secAttrib0 & (1U << (offset + 5))) ? 1U : 0U;
        config->pages[page].chunk_4KB_2 =
            (secAttrib0 & (1U << (offset + 6))) ? 1U : 0U;
    }

    // Process pages 4-7 from SECATTRIB1
    for (uint32_t page = 4; page < 8; page++) {
        uint32_t offset = (page - 4) * 8;
        config->pages[page].chunk_512B_0 =
            (secAttrib1 & (1U << (offset + 0))) ? 1U : 0U;
        config->pages[page].chunk_512B_1 =
            (secAttrib1 & (1U << (offset + 1))) ? 1U : 0U;
        config->pages[page].chunk_1KB =
            (secAttrib1 & (1U << (offset + 2))) ? 1U : 0U;
        config->pages[page].chunk_2KB =
            (secAttrib1 & (1U << (offset + 3))) ? 1U : 0U;
        config->pages[page].chunk_4KB_0 =
            (secAttrib1 & (1U << (offset + 4))) ? 1U : 0U;
        config->pages[page].chunk_4KB_1 =
            (secAttrib1 & (1U << (offset + 5))) ? 1U : 0U;
        config->pages[page].chunk_4KB_2 =
            (secAttrib1 & (1U << (offset + 6))) ? 1U : 0U;
    }

    // Process pages 8-11 from SECATTRIB2
    for (uint32_t page = 8; page < 12; page++) {
        uint32_t offset = (page - 8) * 8;
        config->pages[page].chunk_512B_0 =
            (secAttrib2 & (1U << (offset + 0))) ? 1U : 0U;
        config->pages[page].chunk_512B_1 =
            (secAttrib2 & (1U << (offset + 1))) ? 1U : 0U;
        config->pages[page].chunk_1KB =
            (secAttrib2 & (1U << (offset + 2))) ? 1U : 0U;
        config->pages[page].chunk_2KB =
            (secAttrib2 & (1U << (offset + 3))) ? 1U : 0U;
        config->pages[page].chunk_4KB_0 =
            (secAttrib2 & (1U << (offset + 4))) ? 1U : 0U;
        config->pages[page].chunk_4KB_1 =
            (secAttrib2 & (1U << (offset + 5))) ? 1U : 0U;
        config->pages[page].chunk_4KB_2 =
            (secAttrib2 & (1U << (offset + 6))) ? 1U : 0U;
    }

    // Process pages 12-15 from SECATTRIB3
    for (uint32_t page = 12; page < 16; page++) {
        uint32_t offset = (page - 12) * 8;
        config->pages[page].chunk_512B_0 =
            (secAttrib3 & (1U << (offset + 0))) ? 1U : 0U;
        config->pages[page].chunk_512B_1 =
            (secAttrib3 & (1U << (offset + 1))) ? 1U : 0U;
        config->pages[page].chunk_1KB =
            (secAttrib3 & (1U << (offset + 2))) ? 1U : 0U;
        config->pages[page].chunk_2KB =
            (secAttrib3 & (1U << (offset + 3))) ? 1U : 0U;
        config->pages[page].chunk_4KB_0 =
            (secAttrib3 & (1U << (offset + 4))) ? 1U : 0U;
        config->pages[page].chunk_4KB_1 =
            (secAttrib3 & (1U << (offset + 5))) ? 1U : 0U;
        config->pages[page].chunk_4KB_2 =
            (secAttrib3 & (1U << (offset + 6))) ? 1U : 0U;
    }
}

void DL_GSC_configureSRAMPrivilege(
    GSC_Regs* gsc, const DL_GSC_SRAMSecurityConfig* config)
{
    uint32_t privAttrib0 = 0;
    uint32_t privAttrib1 = 0;
    uint32_t privAttrib2 = 0;
    uint32_t privAttrib3 = 0;

    // Process pages 0-3 for PRIVATTRIB0
    for (uint32_t page = 0; page < 4; page++) {
        uint32_t offset = page * 8;
        privAttrib0 |=
            ((config->pages[page].chunk_512B_0 & 1U) << (offset + 0));
        privAttrib0 |=
            ((config->pages[page].chunk_512B_1 & 1U) << (offset + 1));
        privAttrib0 |= ((config->pages[page].chunk_1KB & 1U) << (offset + 2));
        privAttrib0 |= ((config->pages[page].chunk_2KB & 1U) << (offset + 3));
        privAttrib0 |=
            ((config->pages[page].chunk_4KB_0 & 1U) << (offset + 4));
        privAttrib0 |=
            ((config->pages[page].chunk_4KB_1 & 1U) << (offset + 5));
        privAttrib0 |=
            ((config->pages[page].chunk_4KB_2 & 1U) << (offset + 6));
    }

    // Process pages 4-7 for PRIVATTRIB1
    for (uint32_t page = 4; page < 8; page++) {
        uint32_t offset = (page - 4) * 8;
        privAttrib1 |=
            ((config->pages[page].chunk_512B_0 & 1U) << (offset + 0));
        privAttrib1 |=
            ((config->pages[page].chunk_512B_1 & 1U) << (offset + 1));
        privAttrib1 |= ((config->pages[page].chunk_1KB & 1U) << (offset + 2));
        privAttrib1 |= ((config->pages[page].chunk_2KB & 1U) << (offset + 3));
        privAttrib1 |=
            ((config->pages[page].chunk_4KB_0 & 1U) << (offset + 4));
        privAttrib1 |=
            ((config->pages[page].chunk_4KB_1 & 1U) << (offset + 5));
        privAttrib1 |=
            ((config->pages[page].chunk_4KB_2 & 1U) << (offset + 6));
    }

    // Process pages 8-11 for PRIVATTRIB2
    for (uint32_t page = 8; page < 12; page++) {
        uint32_t offset = (page - 8) * 8;
        privAttrib2 |=
            ((config->pages[page].chunk_512B_0 & 1U) << (offset + 0));
        privAttrib2 |=
            ((config->pages[page].chunk_512B_1 & 1U) << (offset + 1));
        privAttrib2 |= ((config->pages[page].chunk_1KB & 1U) << (offset + 2));
        privAttrib2 |= ((config->pages[page].chunk_2KB & 1U) << (offset + 3));
        privAttrib2 |=
            ((config->pages[page].chunk_4KB_0 & 1U) << (offset + 4));
        privAttrib2 |=
            ((config->pages[page].chunk_4KB_1 & 1U) << (offset + 5));
        privAttrib2 |=
            ((config->pages[page].chunk_4KB_2 & 1U) << (offset + 6));
    }

    // Process pages 12-15 for PRIVATTRIB3
    for (uint32_t page = 12; page < 16; page++) {
        uint32_t offset = (page - 12) * 8;
        privAttrib3 |=
            ((config->pages[page].chunk_512B_0 & 1U) << (offset + 0));
        privAttrib3 |=
            ((config->pages[page].chunk_512B_1 & 1U) << (offset + 1));
        privAttrib3 |= ((config->pages[page].chunk_1KB & 1U) << (offset + 2));
        privAttrib3 |= ((config->pages[page].chunk_2KB & 1U) << (offset + 3));
        privAttrib3 |=
            ((config->pages[page].chunk_4KB_0 & 1U) << (offset + 4));
        privAttrib3 |=
            ((config->pages[page].chunk_4KB_1 & 1U) << (offset + 5));
        privAttrib3 |=
            ((config->pages[page].chunk_4KB_2 & 1U) << (offset + 6));
    }

    // Write configurations to registers
    gsc->SPC_PRIVATTRIB0 = privAttrib0;
    gsc->SPC_PRIVATTRIB1 = privAttrib1;
    gsc->SPC_PRIVATTRIB2 = privAttrib2;
    gsc->SPC_PRIVATTRIB3 = privAttrib3;
}

void DL_GSC_getSRAMPrivilegeConfig(
    GSC_Regs* gsc, DL_GSC_SRAMSecurityConfig* config)
{
    uint32_t privAttrib0 = gsc->SPC_PRIVATTRIB0;
    uint32_t privAttrib1 = gsc->SPC_PRIVATTRIB1;
    uint32_t privAttrib2 = gsc->SPC_PRIVATTRIB2;
    uint32_t privAttrib3 = gsc->SPC_PRIVATTRIB3;

    // Process pages 0-3 from PRIVATTRIB0
    for (uint32_t page = 0; page < 4; page++) {
        uint32_t offset = page * 8;
        config->pages[page].chunk_512B_0 =
            (privAttrib0 & (1U << (offset + 0))) ? 1U : 0U;
        config->pages[page].chunk_512B_1 =
            (privAttrib0 & (1U << (offset + 1))) ? 1U : 0U;
        config->pages[page].chunk_1KB =
            (privAttrib0 & (1U << (offset + 2))) ? 1U : 0U;
        config->pages[page].chunk_2KB =
            (privAttrib0 & (1U << (offset + 3))) ? 1U : 0U;
        config->pages[page].chunk_4KB_0 =
            (privAttrib0 & (1U << (offset + 4))) ? 1U : 0U;
        config->pages[page].chunk_4KB_1 =
            (privAttrib0 & (1U << (offset + 5))) ? 1U : 0U;
        config->pages[page].chunk_4KB_2 =
            (privAttrib0 & (1U << (offset + 6))) ? 1U : 0U;
    }

    // Process pages 4-7 from PRIVATTRIB1
    for (uint32_t page = 4; page < 8; page++) {
        uint32_t offset = (page - 4) * 8;
        config->pages[page].chunk_512B_0 =
            (privAttrib1 & (1U << (offset + 0))) ? 1U : 0U;
        config->pages[page].chunk_512B_1 =
            (privAttrib1 & (1U << (offset + 1))) ? 1U : 0U;
        config->pages[page].chunk_1KB =
            (privAttrib1 & (1U << (offset + 2))) ? 1U : 0U;
        config->pages[page].chunk_2KB =
            (privAttrib1 & (1U << (offset + 3))) ? 1U : 0U;
        config->pages[page].chunk_4KB_0 =
            (privAttrib1 & (1U << (offset + 4))) ? 1U : 0U;
        config->pages[page].chunk_4KB_1 =
            (privAttrib1 & (1U << (offset + 5))) ? 1U : 0U;
        config->pages[page].chunk_4KB_2 =
            (privAttrib1 & (1U << (offset + 6))) ? 1U : 0U;
    }

    // Process pages 8-11 from PRIVATTRIB2
    for (uint32_t page = 8; page < 12; page++) {
        uint32_t offset = (page - 8) * 8;
        config->pages[page].chunk_512B_0 =
            (privAttrib2 & (1U << (offset + 0))) ? 1U : 0U;
        config->pages[page].chunk_512B_1 =
            (privAttrib2 & (1U << (offset + 1))) ? 1U : 0U;
        config->pages[page].chunk_1KB =
            (privAttrib2 & (1U << (offset + 2))) ? 1U : 0U;
        config->pages[page].chunk_2KB =
            (privAttrib2 & (1U << (offset + 3))) ? 1U : 0U;
        config->pages[page].chunk_4KB_0 =
            (privAttrib2 & (1U << (offset + 4))) ? 1U : 0U;
        config->pages[page].chunk_4KB_1 =
            (privAttrib2 & (1U << (offset + 5))) ? 1U : 0U;
        config->pages[page].chunk_4KB_2 =
            (privAttrib2 & (1U << (offset + 6))) ? 1U : 0U;
    }

    // Process pages 12-15 from PRIVATTRIB3
    for (uint32_t page = 12; page < 16; page++) {
        uint32_t offset = (page - 12) * 8;
        config->pages[page].chunk_512B_0 =
            (privAttrib3 & (1U << (offset + 0))) ? 1U : 0U;
        config->pages[page].chunk_512B_1 =
            (privAttrib3 & (1U << (offset + 1))) ? 1U : 0U;
        config->pages[page].chunk_1KB =
            (privAttrib3 & (1U << (offset + 2))) ? 1U : 0U;
        config->pages[page].chunk_2KB =
            (privAttrib3 & (1U << (offset + 3))) ? 1U : 0U;
        config->pages[page].chunk_4KB_0 =
            (privAttrib3 & (1U << (offset + 4))) ? 1U : 0U;
        config->pages[page].chunk_4KB_1 =
            (privAttrib3 & (1U << (offset + 5))) ? 1U : 0U;
        config->pages[page].chunk_4KB_2 =
            (privAttrib3 & (1U << (offset + 6))) ? 1U : 0U;
    }
}

void DL_GSC_configureMainFlashWriteProtect(GSC_Regs* gsc,
    DL_GSC_MainFlashBank bank, uint32_t sector0, uint32_t sector1)
{
    if (bank == DL_GSC_MAIN_FLASH_BANK_A) {
        gsc->FPC_WEPROTA0 = sector0;
        gsc->FPC_WEPROTB0 = sector1;
    } else {
        gsc->FPC_WEPROTA1 = sector0;
        gsc->FPC_WEPROTB1 = sector1;
    }
}

void DL_GSC_getMainFlashWriteProtectStatus(GSC_Regs* gsc,
    DL_GSC_MainFlashBank bank, uint32_t* sector0, uint32_t* sector1)
{
    if (bank == DL_GSC_MAIN_FLASH_BANK_A) {
        *sector0 = gsc->FPC_WEPROTA0;
        *sector1 = gsc->FPC_WEPROTB0;
    } else {
        *sector0 = gsc->FPC_WEPROTA1;
        *sector1 = gsc->FPC_WEPROTB1;
    }
}

void DL_GSC_configureNONMAINWriteProtect(
    GSC_Regs* gsc, DL_GSC_MainFlashBank bank, uint32_t sectors)
{
    if (bank == DL_GSC_MAIN_FLASH_BANK_A) {
        gsc->FPC_WEPROTNONMAIN0 =
            sectors & GSC_FPC_WEPROTNONMAIN0_WEPROT_PAGE_MASK;
    } else {
        gsc->FPC_WEPROTNONMAIN1 =
            sectors & GSC_FPC_WEPROTNONMAIN1_WEPROT_PAGE_MASK;
    }
}

uint32_t DL_GSC_getNONMAINWriteProtectStatus(
    GSC_Regs* gsc, DL_GSC_MainFlashBank bank)
{
    if (bank == DL_GSC_MAIN_FLASH_BANK_A) {
        return gsc->FPC_WEPROTNONMAIN0 &
               GSC_FPC_WEPROTNONMAIN0_WEPROT_PAGE_MASK;
    } else {
        return gsc->FPC_WEPROTNONMAIN1 &
               GSC_FPC_WEPROTNONMAIN1_WEPROT_PAGE_MASK;
    }
}

void DL_GSC_configureMainFlashSecurity(GSC_Regs* gsc,
    DL_GSC_MainFlashBank bank, uint32_t sector0, uint32_t sector1)
{
    if (bank == DL_GSC_MAIN_FLASH_BANK_A) {
        gsc->FPC_SECATTRIBA0 = sector0;
        gsc->FPC_SECATTRIBB0 = sector1;
    } else {
        gsc->FPC_SECATTRIBA1 = sector0;
        gsc->FPC_SECATTRIBB1 = sector1;
    }
}

void DL_GSC_getMainFlashSecurityStatus(GSC_Regs* gsc,
    DL_GSC_MainFlashBank bank, uint32_t* sector0, uint32_t* sector1)
{
    if (bank == DL_GSC_MAIN_FLASH_BANK_A) {
        *sector0 = gsc->FPC_SECATTRIBA0;
        *sector1 = gsc->FPC_SECATTRIBB0;
    } else {
        *sector0 = gsc->FPC_SECATTRIBA1;
        *sector1 = gsc->FPC_SECATTRIBB1;
    }
}

void DL_GSC_configureMainFlashPrivilege(GSC_Regs* gsc,
    DL_GSC_MainFlashBank bank, uint32_t sector0, uint32_t sector1)
{
    if (bank == DL_GSC_MAIN_FLASH_BANK_A) {
        gsc->FPC_PRIVATTRIBA0 = sector0;
        gsc->FPC_PRIVATTRIBB0 = sector1;
    } else {
        gsc->FPC_PRIVATTRIBA1 = sector0;
        gsc->FPC_PRIVATTRIBB1 = sector1;
    }
}

void DL_GSC_getMainFlashPrivilegeStatus(GSC_Regs* gsc,
    DL_GSC_MainFlashBank bank, uint32_t* sector0, uint32_t* sector1)
{
    if (bank == DL_GSC_MAIN_FLASH_BANK_A) {
        *sector0 = gsc->FPC_PRIVATTRIBA0;
        *sector1 = gsc->FPC_PRIVATTRIBB0;
    } else {
        *sector0 = gsc->FPC_PRIVATTRIBA1;
        *sector1 = gsc->FPC_PRIVATTRIBB1;
    }
}
