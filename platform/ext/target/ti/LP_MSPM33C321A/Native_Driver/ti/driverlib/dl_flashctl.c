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
 */

#include <stdbool.h>
#include <stdint.h>
#include <ti/devices/DeviceFamily.h>

#include <ti/driverlib/dl_flashctl.h>

static void DL_FlashCTL_programMemoryConfig(
    FLASHCTL_Regs *flashctl, uint32_t address, uint32_t cmd);

static DL_FLASHCTL_COMMAND_STATUS DL_FlashCTL_executeCommandFromRAM(
    FLASHCTL_Regs *flashctl);

static void DL_FlashCTL_programMemory8Config(
    FLASHCTL_Regs *flashctl, uint32_t address, uint32_t cmd, const uint8_t *data);

static void DL_FlashCTL_programMemory16Config(
    FLASHCTL_Regs *flashctl, uint32_t address, uint32_t cmd, const uint16_t *data);

static void DL_FlashCTL_programMemory32Config(
    FLASHCTL_Regs *flashctl, uint32_t address, uint32_t cmd, const uint32_t *data);

static void DL_FlashCTL_programMemory64Config(
    FLASHCTL_Regs *flashctl, uint32_t address, uint32_t cmd, const uint32_t *data);

static void DL_FlashCTL_programMemory96Config(
    FLASHCTL_Regs *flashctl, uint32_t address, uint32_t cmd, const uint32_t *data);

static void DL_FlashCTL_programMemory128Config(
    FLASHCTL_Regs *flashctl, uint32_t address, uint32_t cmd, const uint32_t *data);

static void DL_FlashCTL_readVerifyConfig(
    FLASHCTL_Regs *flashctl, uint32_t address, uint32_t cmd);

static void DL_FlashCTL_readVerify8Config(
    FLASHCTL_Regs *flashctl, uint32_t address, uint32_t cmd, const uint8_t *data);

static void DL_FlashCTL_readVerify16Config(
    FLASHCTL_Regs *flashctl, uint32_t address, uint32_t cmd, const uint16_t *data);

static void DL_FlashCTL_readVerify32Config(
    FLASHCTL_Regs *flashctl, uint32_t address, uint32_t cmd, const uint32_t *data);

static void DL_FlashCTL_readVerify64Config(
    FLASHCTL_Regs *flashctl, uint32_t address, uint32_t cmd, const uint32_t *data);

static void DL_FlashCTL_readVerify96Config(
    FLASHCTL_Regs *flashctl, uint32_t address, uint32_t cmd, const uint32_t *data);

static void DL_FlashCTL_readVerify128Config(
    FLASHCTL_Regs *flashctl, uint32_t address, uint32_t cmd, const uint32_t *data);


#if defined(__ti_version__) || defined(__TI_COMPILER_VERSION__)
#define RAMFUNC \
    __attribute__((section(".TI.ramfunc"))) __attribute__((noinline))
#elif defined(__GNUC__)
#define RAMFUNC __attribute__((section(".ramfunc"))) __attribute__((noinline))
#elif defined(__IAR_SYSTEMS_ICC__)
#define RAMFUNC __ramfunc __attribute__((noinline))
#else
#error "Compiler not supported for this function"
#endif
RAMFUNC static DL_FLASHCTL_COMMAND_STATUS DL_FlashCTL_executeCommandFromRAM(
    FLASHCTL_Regs *flashctl)
{
    volatile uint32_t status;
    /* Set bit to execute command */
    flashctl->GEN.CMDEXEC = FLASHCTL_CMDEXEC_VAL_EXECUTE;

    /*
     * After executing a flash operation, we will enter a do-while and read the
     * STATCMD register using the status variable. Within the loop it will
     * poll until DL_FLASHCTL_COMMAND_STATUS_PASSED or DL_FLASHCTL_COMMAND_STATUS_FAILED
     * is read from the STATCMD register. This is to ensure that it will properly poll
     * even when the CPU is running at maximum speeds.
     */
    do {
        status =
            flashctl->GEN.STATCMD &
            (FLASHCTL_STATCMD_CMDDONE_MASK | FLASHCTL_STATCMD_CMDPASS_MASK |
                FLASHCTL_STATCMD_CMDINPROGRESS_MASK |
                FLASHCTL_STATCMD_CMDPASS_STATFAIL);
    } while ((DL_FLASHCTL_COMMAND_STATUS) status !=
                 (DL_FLASHCTL_COMMAND_STATUS_PASSED) &&
             (DL_FLASHCTL_COMMAND_STATUS) status !=
                 (DL_FLASHCTL_COMMAND_STATUS_FAILED));

    return ((DL_FLASHCTL_COMMAND_STATUS) status);
}

void DL_FlashCTL_eraseMemory(FLASHCTL_Regs *flashctl, uint32_t address,
    DL_FLASHCTL_COMMAND_SIZE memorySize)
{
    /* Set command type and size */
    flashctl->GEN.CMDTYPE =
        (uint32_t) memorySize | DL_FLASHCTL_COMMAND_TYPE_ERASE;

    /* Set address, address should be in the desired bank or sector to erase */
    DL_FlashCTL_setCommandAddress(flashctl, address);

    /* Set bit to execute command */
    flashctl->GEN.CMDEXEC = FLASHCTL_CMDEXEC_VAL_EXECUTE;
}

DL_FLASHCTL_COMMAND_STATUS DL_FlashCTL_eraseMemoryFromRAM(
    FLASHCTL_Regs *flashctl, uint32_t address,
    DL_FLASHCTL_COMMAND_SIZE memorySize)
{
    /* Set command type and size */
    flashctl->GEN.CMDTYPE =
        (uint32_t) memorySize | DL_FLASHCTL_COMMAND_TYPE_ERASE;

    /* Set address, address should be in the desired bank or sector to erase */
    DL_FlashCTL_setCommandAddress(flashctl, address);

    /* Jump to RAM to execute command and wait for completion */
    return DL_FlashCTL_executeCommandFromRAM(flashctl);
}

bool DL_FlashCTL_massErase(FLASHCTL_Regs *flashctl)
{
    bool status;

    DL_FlashCTL_protectAllMemory(flashctl);
    DL_FlashCTL_unprotectMainMemory(flashctl);

    DL_FlashCTL_eraseMemory(
        flashctl, FLASHCTL_BANK0_MAIN_ADDRESS, DL_FLASHCTL_COMMAND_SIZE_BANK);
    status = DL_FlashCTL_waitForCmdDone(flashctl);

    if ((DL_FactoryRegion_getDATAFlashSize()!=0) && (status == true)) {
        status = DL_FlashCTL_eraseDataBank(flashctl);
    }
    return (status);
}

DL_FLASHCTL_COMMAND_STATUS DL_FlashCTL_massEraseFromRAM(
    FLASHCTL_Regs *flashctl)
{
    DL_FLASHCTL_COMMAND_STATUS status;

    DL_FlashCTL_protectAllMemory(flashctl);
    DL_FlashCTL_unprotectMainMemory(flashctl);

    status = DL_FlashCTL_eraseMemoryFromRAM(
        flashctl, FLASHCTL_BANK0_MAIN_ADDRESS, DL_FLASHCTL_COMMAND_SIZE_BANK);

    if ((DL_FactoryRegion_getDATAFlashSize()!=0) &&
        (status != DL_FLASHCTL_COMMAND_STATUS_FAILED)) {
        status = DL_FlashCTL_eraseDataBankFromRAM(flashctl);
    }

    return (status);
}

bool DL_FlashCTL_massEraseMultiBank(FLASHCTL_Regs *flashctl, DL_ERASE_DATABANK_COMMAND flag)
{
    bool status            = true;
    uint32_t bankStartAddr = 0x00000000U;
    uint8_t numBanks       = DL_FactoryRegion_getNumBanks();
    uint32_t flashSize     = DL_FactoryRegion_getMAINFlashSize();
    /* Assuming a sector size of 2KB */
    uint32_t bankSize = (((uint32_t) flashSize / (uint32_t) numBanks) * 1024U);

    DL_FLASHCTL_BANK_SELECT bankSelect = DL_FLASHCTL_BANK_SELECT_0;

    bool eraseFlag    = true;
    uint8_t bankIndex = 0U;
    while (bankIndex < numBanks && status != false) {
        /* If flash bank swap policy is enabled, the primary bank will be write
         * and erase protected. Thus, we will not attempt an erase of the
         * primary bank.
         */
        if (DL_SYSCTL_isFlashBankSwapEnabled()) {
            eraseFlag = (bankIndex < (numBanks / (uint8_t) 2)) ? false : true;
        } else {
            eraseFlag = true;
        }
        switch (bankIndex) {
            case 0:
                bankSelect = DL_FLASHCTL_BANK_SELECT_0;
                break;
            case 1:
                bankSelect = DL_FLASHCTL_BANK_SELECT_1;
                break;
            case 2:
                bankSelect = DL_FLASHCTL_BANK_SELECT_2;
                break;
            default:
                break;
        }

        bankStartAddr = (bankSize * bankIndex);

        if (eraseFlag == true) {
            DL_FlashCTL_enableAddressOverrideMode(flashctl);
            DL_FlashCTL_setBankSelect(flashctl, bankSelect);
            DL_FlashCTL_setRegionSelect(
                flashctl, DL_FLASHCTL_REGION_SELECT_MAIN);

            DL_FlashCTL_unprotectMainMemory(flashctl);
            DL_FlashCTL_protectNonMainMemory(flashctl);
            DL_FlashCTL_eraseMemory(
                flashctl, bankStartAddr, DL_FLASHCTL_COMMAND_SIZE_BANK);
            status = DL_FlashCTL_waitForCmdDone(flashctl);
        }
        bankIndex++;
    }
    DL_FlashCTL_disableAddressOverrideMode(flashctl);
    
    if ((DL_FactoryRegion_getDATAFlashSize()!=0) && (status != false) && (flag == DL_ERASE_WITH_DATABANK)) {
        status = DL_FlashCTL_eraseDataBank(flashctl);
    }

    return (status);
}

DL_FLASHCTL_COMMAND_STATUS DL_FlashCTL_massEraseMultiBankFromRAM(
    FLASHCTL_Regs *flashctl, DL_ERASE_DATABANK_COMMAND flag)
{
    DL_FLASHCTL_COMMAND_STATUS status = FLASHCTL_STATCMD_CMDPASS_STATPASS;
    uint32_t bankStartAddr = 0x00000000U;
    uint8_t numBanks       = DL_FactoryRegion_getNumBanks();
    uint32_t flashSize     = DL_FactoryRegion_getMAINFlashSize();
    /* Assuming a sector size of 2KB */
    uint32_t bankSize = (((uint32_t) flashSize / (uint32_t) numBanks) * 1024U);

    DL_FLASHCTL_BANK_SELECT bankSelect = DL_FLASHCTL_BANK_SELECT_0;

    bool eraseFlag    = true;
    uint8_t bankIndex = 0U;
    while ((bankIndex < numBanks) && (status != DL_FLASHCTL_COMMAND_STATUS_FAILED)) {
        /* If flash bank swap policy is enabled, the primary bank will be write
         * and erase protected. Thus, we will not attempt an erase of the
         * primary bank.
         */
        if (DL_SYSCTL_isFlashBankSwapEnabled()) {
            eraseFlag = (bankIndex < (numBanks / (uint8_t) 2)) ? false : true;
        } else {
            eraseFlag = true;
        }
        switch (bankIndex) {
            case 0:
                bankSelect = DL_FLASHCTL_BANK_SELECT_0;
                break;
            case 1:
                bankSelect = DL_FLASHCTL_BANK_SELECT_1;
                break;
            case 2:
                bankSelect = DL_FLASHCTL_BANK_SELECT_2;
                break;
            default:
                break;
        }

        bankStartAddr = (bankSize * bankIndex);

        if (eraseFlag == true) {
            DL_FlashCTL_enableAddressOverrideMode(flashctl);
            DL_FlashCTL_setBankSelect(flashctl, bankSelect);
            DL_FlashCTL_setRegionSelect(
                flashctl, DL_FLASHCTL_REGION_SELECT_MAIN);

            DL_FlashCTL_unprotectMainMemory(flashctl);
            DL_FlashCTL_protectNonMainMemory(flashctl);
            status = DL_FlashCTL_eraseMemoryFromRAM(
                flashctl, bankStartAddr, DL_FLASHCTL_COMMAND_SIZE_BANK);
        }
        bankIndex++;
    }
    DL_FlashCTL_disableAddressOverrideMode(flashctl);

    if ((DL_FactoryRegion_getDATAFlashSize()!=0) && (status != DL_FLASHCTL_COMMAND_STATUS_FAILED) && (flag == DL_ERASE_WITH_DATABANK)) {
        status = DL_FlashCTL_eraseDataBankFromRAM(flashctl);
    }

    return (status);
}

bool DL_FlashCTL_factoryReset(FLASHCTL_Regs *flashctl)
{
    bool status;

    /* Erase Main Memory */
    status = DL_FlashCTL_massErase(flashctl);

    /* Erase BANK-0 NONMAIN-3 Sector*/
    if (status == true) {
        DL_FlashCTL_unprotectNonMainMemory(flashctl);
            DL_FlashCTL_eraseMemory(flashctl,
                FLASHCTL_BANK0_NONMAIN_ADDRESS +
                    (3U * DL_FLASHCTL_SECTOR_SIZE),DL_FLASHCTL_COMMAND_SIZE_SECTOR);

        status = DL_FlashCTL_waitForCmdDone(flashctl);
    }
    return (status);
}

DL_FLASHCTL_COMMAND_STATUS DL_FlashCTL_factoryResetFromRAM(
    FLASHCTL_Regs *flashctl)
{
    DL_FLASHCTL_COMMAND_STATUS status;

    /* Erase Main Memory */
    status = DL_FlashCTL_massEraseFromRAM(flashctl);

    /* Erase BANK-0 NONMAIN-3 Sector*/
    if (status == DL_FLASHCTL_COMMAND_STATUS_PASSED) {
        DL_FlashCTL_unprotectNonMainMemory(flashctl);
            status = DL_FlashCTL_eraseMemoryFromRAM(flashctl,
                FLASHCTL_BANK0_NONMAIN_ADDRESS +
                    (3U * DL_FLASHCTL_SECTOR_SIZE),DL_FLASHCTL_COMMAND_SIZE_SECTOR);
    }
    return (status);
}

bool DL_FlashCTL_factoryResetMultiBank(FLASHCTL_Regs *flashctl, DL_ERASE_DATABANK_COMMAND flag)
{
    bool status;

    /* Erase Main Memory */
    status = DL_FlashCTL_massEraseMultiBank(flashctl,flag);

    /* Erase specific NONMAIN Sectors */
    if (status == true) {
        /* Erase BANK0 NONMAIN-3 Sector*/
        if (status == true) {
            DL_FlashCTL_unprotectNonMainMemory(flashctl);
            DL_FlashCTL_eraseMemory(flashctl,
                FLASHCTL_BANK0_NONMAIN_ADDRESS +
                    (3U * DL_FLASHCTL_SECTOR_SIZE),
                DL_FLASHCTL_COMMAND_SIZE_SECTOR);
            status = DL_FlashCTL_waitForCmdDone(flashctl);
        }

        /* Erase BANK1 NONMAIN-3 Sector*/
        if (status == true) {
            DL_FlashCTL_unprotectNonMainMemory(flashctl);
            DL_FlashCTL_eraseMemory(flashctl,
                FLASHCTL_BANK1_NONMAIN_ADDRESS +
                    (3U * DL_FLASHCTL_SECTOR_SIZE),
                DL_FLASHCTL_COMMAND_SIZE_SECTOR);
            status = DL_FlashCTL_waitForCmdDone(flashctl);
        }
    }
    return (status);
}

DL_FLASHCTL_COMMAND_STATUS DL_FlashCTL_factoryResetMultiBankFromRAM(
    FLASHCTL_Regs *flashctl, DL_ERASE_DATABANK_COMMAND flag)
{
    DL_FLASHCTL_COMMAND_STATUS status;

    /* Erase Main Memory */
    status = DL_FlashCTL_massEraseMultiBankFromRAM(flashctl,flag);

    /* Erase specific NONMAIN Sectors */
    if (status == DL_FLASHCTL_COMMAND_STATUS_PASSED) {
        /* Erase BANK0 NONMAIN-3 Sector*/
        if (status != DL_FLASHCTL_COMMAND_STATUS_FAILED) {
            DL_FlashCTL_unprotectNonMainMemory(flashctl);
            status = DL_FlashCTL_eraseMemoryFromRAM(flashctl,
                FLASHCTL_BANK0_NONMAIN_ADDRESS +
                    (3U * DL_FLASHCTL_SECTOR_SIZE),
                DL_FLASHCTL_COMMAND_SIZE_SECTOR);
        }

        /* Erase BANK1 NONMAIN-3 Sector*/
        if (status != DL_FLASHCTL_COMMAND_STATUS_FAILED) {
            DL_FlashCTL_unprotectNonMainMemory(flashctl);
            status = DL_FlashCTL_eraseMemoryFromRAM(flashctl,
                FLASHCTL_BANK1_NONMAIN_ADDRESS +
                    (3U * DL_FLASHCTL_SECTOR_SIZE),
                DL_FLASHCTL_COMMAND_SIZE_SECTOR);
        }
    }
    return (status);
}

static void DL_FlashCTL_programMemoryConfig(FLASHCTL_Regs *flashctl, uint32_t address, uint32_t cmd)
{
    flashctl->GEN.CMDTYPE = (uint32_t)DL_FLASHCTL_COMMAND_SIZE_ONE_WORD | DL_FLASHCTL_COMMAND_TYPE_PROGRAM;

    uint32_t cmd_data_en = cmd & 0x0000FFFF;
    uint32_t cmd_ecc_en  = cmd & 0xFFFF0000;

    cmd_data_en = cmd_data_en << (address % 0x10);

    // If programming to the second 64 bits in a flash word,
    // write the second ECC byte
    if ((address % 0x10) >= 0x8)
    {
        cmd_ecc_en = cmd_ecc_en << 1;
    }

    flashctl->GEN.CMDBYTEN = cmd_ecc_en | cmd_data_en;

    /* Set address, address should be in the sector that we want to erase */
    DL_FlashCTL_setCommandAddress(flashctl, address);
}

static void DL_FlashCTL_programMemory8Config(FLASHCTL_Regs *flashctl, uint32_t address, uint32_t cmd, const uint8_t *data)
{
    DL_FlashCTL_programMemoryConfig(flashctl, address, cmd);

    // Create a 32-bit word from our data
    uint32_t data_shifted = ((uint32_t)*data) << ((address % 4U) * 8U);

    // Set which flash word we are writing to
    flashctl->GEN.CMDDATAINDEX = (address >> 4U) & 3U;

    // Select the CMDDATA register for our address within the flash word,
    // then load it with our data
    uint32_t cmddata_select = (address / 4U) % 4U;
    if (cmddata_select == 0x0U)
    {
        flashctl->GEN.CMDDATA0 = data_shifted;
    }
    else if (cmddata_select == 0x1U)
    {
        flashctl->GEN.CMDDATA1 = data_shifted;
    }
    else if (cmddata_select == 0x2U)
    {
        flashctl->GEN.CMDDATA2 = data_shifted;
    }
    else
    {
        flashctl->GEN.CMDDATA3 = data_shifted;
    }
}

static void DL_FlashCTL_programMemory16Config(FLASHCTL_Regs *flashctl, uint32_t address, uint32_t cmd,
                                              const uint16_t *data)
{
    DL_FlashCTL_programMemoryConfig(flashctl, address, cmd);

    // Create a 32-bit word from our data
    uint32_t data_shifted = ((uint32_t)*data) << ((address % 4U) * 8U);

    // Set which flash word we are writing to
    flashctl->GEN.CMDDATAINDEX = (address >> 4U) & 3U;

    // Select the CMDDATA register for our address within the flash word,
    // then load it with our data
    uint32_t cmddata_select = (address / 4U) % 4U;
    if (cmddata_select == 0x0U)
    {
        flashctl->GEN.CMDDATA0 = data_shifted;
    }
    else if (cmddata_select == 0x1U)
    {
        flashctl->GEN.CMDDATA1 = data_shifted;
    }
    else if (cmddata_select == 0x2U)
    {
        flashctl->GEN.CMDDATA2 = data_shifted;
    }
    else
    {
        flashctl->GEN.CMDDATA3 = data_shifted;
    }
}

static void DL_FlashCTL_programMemory32Config(FLASHCTL_Regs *flashctl, uint32_t address, uint32_t cmd,
                                              const uint32_t *data)
{
    DL_FlashCTL_programMemoryConfig(flashctl, address, cmd);

    // Create a 32-bit word from our data
    uint32_t data_shifted = ((uint32_t)*data) << ((address % 4U) * 8U);

    // Set which flash word we are writing to
    flashctl->GEN.CMDDATAINDEX = (address >> 4U) & 3U;

    // Select the CMDDATA register for our address within the flash word,
    // then load it with our data
    uint32_t cmddata_select = (address / 4U) % 4U;
    if (cmddata_select == 0x0U)
    {
        flashctl->GEN.CMDDATA0 = data_shifted;
    }
    else if (cmddata_select == 0x1U)
    {
        flashctl->GEN.CMDDATA1 = data_shifted;
    }
    else if (cmddata_select == 0x2U)
    {
        flashctl->GEN.CMDDATA2 = data_shifted;
    }
    else
    {
        flashctl->GEN.CMDDATA3 = data_shifted;
    }
}

static void DL_FlashCTL_programMemory64Config(FLASHCTL_Regs *flashctl, uint32_t address, uint32_t cmd,
                                              const uint32_t *data)
{
    DL_FlashCTL_programMemoryConfig(flashctl, address, cmd);

    flashctl->GEN.CMDDATAINDEX = (address >> 4U) & 3U;
    if ((address % 0x10U) == 0x8U)
    {
        flashctl->GEN.CMDDATA2 = *data;
        flashctl->GEN.CMDDATA3 = *(data + 1U);
    }
    else
    {
        flashctl->GEN.CMDDATA0 = *data;
        flashctl->GEN.CMDDATA1 = *(data + 1U);
    }
}

static void DL_FlashCTL_programMemory96Config(FLASHCTL_Regs *flashctl, uint32_t address, uint32_t cmd,
                                              const uint32_t *data)
{
    DL_FlashCTL_programMemoryConfig(flashctl, address, cmd);

    /* Set data registers */
    flashctl->GEN.CMDDATAINDEX = (address >> 4U) & 3U;
    flashctl->GEN.CMDDATA0     = *data;
    flashctl->GEN.CMDDATA1     = *(data + 1);
    flashctl->GEN.CMDDATA2     = *(data + 2);
}

static void DL_FlashCTL_programMemory128Config(FLASHCTL_Regs *flashctl, uint32_t address, uint32_t cmd,
                                               const uint32_t *data)
{
    DL_FlashCTL_programMemoryConfig(flashctl, address, cmd);

    /* Set data registers */
    flashctl->GEN.CMDDATAINDEX = (address >> 4U) & 3U;
    flashctl->GEN.CMDDATA0     = *data;
    flashctl->GEN.CMDDATA1     = *(data + 1);
    flashctl->GEN.CMDDATA2     = *(data + 2);
    flashctl->GEN.CMDDATA3     = *(data + 3);
}

void DL_FlashCTL_programMemory8(
    FLASHCTL_Regs *flashctl, uint32_t address, const uint8_t *data)
{
    /* Only enable the bottom 8 bits for programming*/
    DL_FlashCTL_programMemory8Config(
        flashctl, address, DL_FLASHCTL_PROGRAM_8_WITHOUT_ECC, data);

    /* Set bit to execute command */
    flashctl->GEN.CMDEXEC = FLASHCTL_CMDEXEC_VAL_EXECUTE;
}

DL_FLASHCTL_COMMAND_STATUS DL_FlashCTL_programMemoryFromRAM8(
    FLASHCTL_Regs *flashctl, uint32_t address, const uint8_t *data)
{
    /* Only enable the bottom 8 bits for programming*/
    DL_FlashCTL_programMemory8Config(
        flashctl, address, DL_FLASHCTL_PROGRAM_8_WITHOUT_ECC, data);
    /* Jump to RAM to execute command and wait for completion */
    return DL_FlashCTL_executeCommandFromRAM(flashctl);
}

void DL_FlashCTL_programMemory16(
    FLASHCTL_Regs *flashctl, uint32_t address, const uint16_t *data)
{
    /* Enable 16 bits per data register for programming*/
    DL_FlashCTL_programMemory16Config(
        flashctl, address, DL_FLASHCTL_PROGRAM_16_WITHOUT_ECC, data);

    /* Set bit to execute command */
    flashctl->GEN.CMDEXEC = FLASHCTL_CMDEXEC_VAL_EXECUTE;
}

DL_FLASHCTL_COMMAND_STATUS DL_FlashCTL_programMemoryFromRAM16(
    FLASHCTL_Regs *flashctl, uint32_t address, const uint16_t *data)
{
    /* Enable 16 bits per data register for programming*/
    DL_FlashCTL_programMemory16Config(
        flashctl, address, DL_FLASHCTL_PROGRAM_16_WITHOUT_ECC, data);

    /* Jump to RAM to execute command and wait for completion */
    return DL_FlashCTL_executeCommandFromRAM(flashctl);
}

void DL_FlashCTL_programMemory32(
    FLASHCTL_Regs *flashctl, uint32_t address, const uint32_t *data)
{
    /* Enable 32 bits per data register for programming*/
    DL_FlashCTL_programMemory32Config(
        flashctl, address, DL_FLASHCTL_PROGRAM_32_WITHOUT_ECC, data);

    /* Set bit to execute command */
    flashctl->GEN.CMDEXEC = FLASHCTL_CMDEXEC_VAL_EXECUTE;
}

DL_FLASHCTL_COMMAND_STATUS DL_FlashCTL_programMemoryFromRAM32(
    FLASHCTL_Regs *flashctl, uint32_t address, const uint32_t *data)
{
    /* Enable 32 bits per data register for programming*/
    DL_FlashCTL_programMemory32Config(
        flashctl, address, DL_FLASHCTL_PROGRAM_32_WITHOUT_ECC, data);

    /* Jump to RAM to execute command and wait for completion */
    return DL_FlashCTL_executeCommandFromRAM(flashctl);
}

void DL_FlashCTL_programMemory64(
    FLASHCTL_Regs *flashctl, uint32_t address, const uint32_t *data)
{
    /* Enable 64 bits per data register for programming*/
    DL_FlashCTL_programMemory64Config(
        flashctl, address, DL_FLASHCTL_PROGRAM_64_WITHOUT_ECC, data);

    /* Set bit to execute command */
    flashctl->GEN.CMDEXEC = FLASHCTL_CMDEXEC_VAL_EXECUTE;
}

DL_FLASHCTL_COMMAND_STATUS DL_FlashCTL_programMemoryFromRAM64(
    FLASHCTL_Regs *flashctl, uint32_t address, const uint32_t *data)
{
    /* Enable 64 bits per data register for programming*/
    DL_FlashCTL_programMemory64Config(
        flashctl, address, DL_FLASHCTL_PROGRAM_64_WITHOUT_ECC, data);

    /* Jump to RAM to execute command and wait for completion */
    return DL_FlashCTL_executeCommandFromRAM(flashctl);
}

void DL_FlashCTL_programMemory96(
    FLASHCTL_Regs *flashctl, uint32_t address, const uint32_t *data)
{
    /* Enable 96 bits per data register for programming*/
    DL_FlashCTL_programMemory96Config(
        flashctl, address, DL_FLASHCTL_PROGRAM_96_WITHOUT_ECC, data);

    /* Set bit to execute command */
    flashctl->GEN.CMDEXEC = FLASHCTL_CMDEXEC_VAL_EXECUTE;
}

DL_FLASHCTL_COMMAND_STATUS DL_FlashCTL_programMemoryFromRAM96(
    FLASHCTL_Regs *flashctl, uint32_t address, const uint32_t *data)
{
    /* Enable 96 bits per data register for programming*/
    DL_FlashCTL_programMemory96Config(
        flashctl, address, DL_FLASHCTL_PROGRAM_96_WITHOUT_ECC, data);

    /* Jump to RAM to execute command and wait for completion */
    return DL_FlashCTL_executeCommandFromRAM(flashctl);
}

void DL_FlashCTL_programMemory128(
    FLASHCTL_Regs *flashctl, uint32_t address, const uint32_t *data)
{
    /* Enable 128 bits per data register for programming*/
    DL_FlashCTL_programMemory128Config(
        flashctl, address, DL_FLASHCTL_PROGRAM_128_WITHOUT_ECC, data);

    /* Set bit to execute command */
    flashctl->GEN.CMDEXEC = FLASHCTL_CMDEXEC_VAL_EXECUTE;
}

DL_FLASHCTL_COMMAND_STATUS DL_FlashCTL_programMemoryFromRAM128(
    FLASHCTL_Regs *flashctl, uint32_t address, const uint32_t *data)
{
    /* Enable 128 bits per data register for programming*/
    DL_FlashCTL_programMemory128Config(
        flashctl, address, DL_FLASHCTL_PROGRAM_128_WITHOUT_ECC, data);

    /* Jump to RAM to execute command and wait for completion */
    return DL_FlashCTL_executeCommandFromRAM(flashctl);
}

void DL_FlashCTL_programMemory8WithECCGenerated(
    FLASHCTL_Regs *flashctl, uint32_t address, const uint8_t *data)
{
    /* Only enable the bottom 8 bits for programming*/
    DL_FlashCTL_programMemory8Config(
        flashctl, address, DL_FLASHCTL_PROGRAM_8_WITH_ECC, data);

    /* Set bit to execute command */
    flashctl->GEN.CMDEXEC = FLASHCTL_CMDEXEC_VAL_EXECUTE;
}

DL_FLASHCTL_COMMAND_STATUS DL_FlashCTL_programMemoryFromRAM8WithECCGenerated(
    FLASHCTL_Regs *flashctl, uint32_t address, const uint8_t *data)
{
    /* Only enable the bottom 8 bits for programming*/
    DL_FlashCTL_programMemory8Config(
        flashctl, address, DL_FLASHCTL_PROGRAM_8_WITH_ECC, data);

    /* Jump to RAM to execute command and wait for completion */
    return DL_FlashCTL_executeCommandFromRAM(flashctl);
}

void DL_FlashCTL_programMemory16WithECCGenerated(
    FLASHCTL_Regs *flashctl, uint32_t address, const uint16_t *data)
{
    /* Enable 16 bits per data register for programming*/
    DL_FlashCTL_programMemory16Config(
        flashctl, address, DL_FLASHCTL_PROGRAM_16_WITH_ECC, data);

    /* Set bit to execute command */
    flashctl->GEN.CMDEXEC = FLASHCTL_CMDEXEC_VAL_EXECUTE;
}

DL_FLASHCTL_COMMAND_STATUS DL_FlashCTL_programMemoryFromRAM16WithECCGenerated(
    FLASHCTL_Regs *flashctl, uint32_t address, const uint16_t *data)
{
    /* Enable 16 bits per data register for programming*/
    DL_FlashCTL_programMemory16Config(
        flashctl, address, DL_FLASHCTL_PROGRAM_16_WITH_ECC, data);

    /* Jump to RAM to execute command and wait for completion */
    return DL_FlashCTL_executeCommandFromRAM(flashctl);
}

void DL_FlashCTL_programMemory32WithECCGenerated(
    FLASHCTL_Regs *flashctl, uint32_t address, const uint32_t *data)
{
    /* Enable 32 bits per data register for programming*/
    DL_FlashCTL_programMemory32Config(
        flashctl, address, DL_FLASHCTL_PROGRAM_32_WITH_ECC, data);
    /* Set bit to execute command */
    flashctl->GEN.CMDEXEC = FLASHCTL_CMDEXEC_VAL_EXECUTE;
}

DL_FLASHCTL_COMMAND_STATUS DL_FlashCTL_programMemoryFromRAM32WithECCGenerated(
    FLASHCTL_Regs *flashctl, uint32_t address, const uint32_t *data)
{
    /* Enable 32 bits per data register for programming*/
    DL_FlashCTL_programMemory32Config(
        flashctl, address, DL_FLASHCTL_PROGRAM_32_WITH_ECC, data);
    /* Jump to RAM to execute command and wait for completion */
    return DL_FlashCTL_executeCommandFromRAM(flashctl);
}

void DL_FlashCTL_programMemory64WithECCGenerated(
    FLASHCTL_Regs *flashctl, uint32_t address, const uint32_t *data)
{
    /* Enable 64 bits per data register for programming, with ECC enabled */
    DL_FlashCTL_programMemory64Config(
        flashctl, address, DL_FLASHCTL_PROGRAM_64_WITH_ECC, data);

    /* Set bit to execute command */
    flashctl->GEN.CMDEXEC = FLASHCTL_CMDEXEC_VAL_EXECUTE;
}

DL_FLASHCTL_COMMAND_STATUS DL_FlashCTL_programMemoryFromRAM64WithECCGenerated(
    FLASHCTL_Regs *flashctl, uint32_t address, const uint32_t *data)
{
    /* Enable 64 bits per data register for programming, with ECC enabled */
    DL_FlashCTL_programMemory64Config(
        flashctl, address, DL_FLASHCTL_PROGRAM_64_WITH_ECC, data);

    /* Jump to RAM to execute command and wait for completion */
    return DL_FlashCTL_executeCommandFromRAM(flashctl);
}

void DL_FlashCTL_programMemory96WithECCGenerated(
    FLASHCTL_Regs *flashctl, uint32_t address, const uint32_t *data)
{
    /* Enable 96 bits per data register for programming, with ECC enabled */
    DL_FlashCTL_programMemory96Config(
        flashctl, address, DL_FLASHCTL_PROGRAM_96_WITH_ECC, data);

    /* Set bit to execute command */
    flashctl->GEN.CMDEXEC = FLASHCTL_CMDEXEC_VAL_EXECUTE;
}

DL_FLASHCTL_COMMAND_STATUS DL_FlashCTL_programMemoryFromRAM96WithECCGenerated(
    FLASHCTL_Regs *flashctl, uint32_t address, const uint32_t *data)
{
    /* Enable 96 bits per data register for programming, with ECC enabled */
    DL_FlashCTL_programMemory96Config(
        flashctl, address, DL_FLASHCTL_PROGRAM_96_WITH_ECC, data);

    /* Jump to RAM to execute command and wait for completion */
    return DL_FlashCTL_executeCommandFromRAM(flashctl);
}

void DL_FlashCTL_programMemory128WithECCGenerated(
    FLASHCTL_Regs *flashctl, uint32_t address, const uint32_t *data)
{
    /* Enable 128 bits per data register for programming, with ECC enabled */
    DL_FlashCTL_programMemory128Config(
        flashctl, address, DL_FLASHCTL_PROGRAM_128_WITH_ECC, data);

    /* Set bit to execute command */
    flashctl->GEN.CMDEXEC = FLASHCTL_CMDEXEC_VAL_EXECUTE;
}

DL_FLASHCTL_COMMAND_STATUS DL_FlashCTL_programMemoryFromRAM128WithECCGenerated(
    FLASHCTL_Regs *flashctl, uint32_t address, const uint32_t *data)
{
    /* Enable 128 bits per data register for programming, with ECC enabled */
    DL_FlashCTL_programMemory128Config(
        flashctl, address, DL_FLASHCTL_PROGRAM_128_WITH_ECC, data);

    /* Jump to RAM to execute command and wait for completion */
    return DL_FlashCTL_executeCommandFromRAM(flashctl);
}

void DL_FlashCTL_programMemory8WithECCManual(FLASHCTL_Regs *flashctl,
    uint32_t address, const uint8_t *data, const uint8_t *eccCode)
{
    /* Enable 8 bits per data register for programming, with ECC enabled */
    DL_FlashCTL_programMemory8Config(
        flashctl, address, DL_FLASHCTL_PROGRAM_8_WITH_ECC, data);

    flashctl->GEN.CMDDATAINDEX = (address >> 4U) & 3U;
    if ((address % 0x10U) >= 0x8U)
    {
        flashctl->GEN.CMDDATAECC0 &= ~((uint32_t)FLASHCTL_CMDDATAECC0_VAL1_MASK);
        flashctl->GEN.CMDDATAECC0 |= (*eccCode) << FLASHCTL_CMDDATAECC0_VAL1_OFS;
    }
    else
    {
        flashctl->GEN.CMDDATAECC0 &= ~((uint32_t)FLASHCTL_CMDDATAECC0_VAL0_MASK);
        flashctl->GEN.CMDDATAECC0 |= (*eccCode) << FLASHCTL_CMDDATAECC0_VAL0_OFS;
    }

    /* Set bit to execute command */
    flashctl->GEN.CMDEXEC = FLASHCTL_CMDEXEC_VAL_EXECUTE;
}

DL_FLASHCTL_COMMAND_STATUS DL_FlashCTL_programMemoryFromRAM8WithECCManual(
    FLASHCTL_Regs *flashctl, uint32_t address, const uint8_t *data,
    const uint8_t *eccCode)
{
    /* Enable 8 bits per data register for programming, with ECC enabled */
    DL_FlashCTL_programMemory8Config(
        flashctl, address, DL_FLASHCTL_PROGRAM_8_WITH_ECC, data);

    flashctl->GEN.CMDDATAINDEX = (address >> 4U) & 3U;
    if ((address % 0x10U) >= 0x8U)
    {
        flashctl->GEN.CMDDATAECC0 &= ~((uint32_t)FLASHCTL_CMDDATAECC0_VAL1_MASK);
        flashctl->GEN.CMDDATAECC0 |= (*eccCode) << FLASHCTL_CMDDATAECC0_VAL1_OFS;
    }
    else
    {
        flashctl->GEN.CMDDATAECC0 &= ~((uint32_t)FLASHCTL_CMDDATAECC0_VAL0_MASK);
        flashctl->GEN.CMDDATAECC0 |= (*eccCode) << FLASHCTL_CMDDATAECC0_VAL0_OFS;
    }

    /* Jump to RAM to execute command and wait for completion */
    return DL_FlashCTL_executeCommandFromRAM(flashctl);
}

void DL_FlashCTL_programMemory16WithECCManual(FLASHCTL_Regs *flashctl,
    uint32_t address, const uint16_t *data, const uint8_t *eccCode)
{
    /* Enable 16 bits per data register for programming, with ECC enabled */
    DL_FlashCTL_programMemory16Config(
        flashctl, address, DL_FLASHCTL_PROGRAM_16_WITH_ECC, data);

    flashctl->GEN.CMDDATAINDEX = (address >> 4U) & 3U;
    if ((address % 0x10U) >= 0x8U)
    {
        flashctl->GEN.CMDDATAECC0 = (*eccCode) << FLASHCTL_CMDDATAECC0_VAL1_OFS;
    }
    else
    {
        flashctl->GEN.CMDDATAECC0 = *eccCode;
    }

    /* Set bit to execute command */
    flashctl->GEN.CMDEXEC = FLASHCTL_CMDEXEC_VAL_EXECUTE;
}

DL_FLASHCTL_COMMAND_STATUS DL_FlashCTL_programMemoryFromRAM16WithECCManual(
    FLASHCTL_Regs *flashctl, uint32_t address, const uint16_t *data,
    const uint8_t *eccCode)
{
    /* Enable 16 bits per data register for programming, with ECC enabled */
    DL_FlashCTL_programMemory16Config(
        flashctl, address, DL_FLASHCTL_PROGRAM_16_WITH_ECC, data);

    flashctl->GEN.CMDDATAINDEX = (address >> 4U) & 3U;
    if ((address % 0x10U) >= 0x8U)
    {
        flashctl->GEN.CMDDATAECC0 = (*eccCode) << FLASHCTL_CMDDATAECC0_VAL1_OFS;
    }
    else
    {
        flashctl->GEN.CMDDATAECC0 = *eccCode;
    }

    /* Jump to RAM to execute command and wait for completion */
    return DL_FlashCTL_executeCommandFromRAM(flashctl);
}

void DL_FlashCTL_programMemory32WithECCManual(FLASHCTL_Regs *flashctl,
    uint32_t address, const uint32_t *data, const uint8_t *eccCode)
{
    /* Enable 32 bits per data register for programming, with ECC enabled */
    DL_FlashCTL_programMemory32Config(
        flashctl, address, DL_FLASHCTL_PROGRAM_32_WITH_ECC, data);

    flashctl->GEN.CMDDATAINDEX = (address >> 4U) & 3U;
    if ((address % 0x10U) >= 0x8U)
    {
        flashctl->GEN.CMDDATAECC0 = (*eccCode) << FLASHCTL_CMDDATAECC0_VAL1_OFS;
    }
    else
    {
        flashctl->GEN.CMDDATAECC0 = *eccCode;
    }

    /* Set bit to execute command */
    flashctl->GEN.CMDEXEC = FLASHCTL_CMDEXEC_VAL_EXECUTE;
}

DL_FLASHCTL_COMMAND_STATUS DL_FlashCTL_programMemoryFromRAM32WithECCManual(
    FLASHCTL_Regs *flashctl, uint32_t address, const uint32_t *data,
    const uint8_t *eccCode)
{
    /* Enable 32 bits per data register for programming, with ECC enabled */
    DL_FlashCTL_programMemory32Config(
        flashctl, address, DL_FLASHCTL_PROGRAM_32_WITH_ECC, data);

    flashctl->GEN.CMDDATAINDEX = (address >> 4U) & 3U;
    if ((address % 0x10U) >= 0x8U)
    {
        flashctl->GEN.CMDDATAECC0 = (*eccCode) << FLASHCTL_CMDDATAECC0_VAL1_OFS;
    }
    else
    {
        flashctl->GEN.CMDDATAECC0 = *eccCode;
    }

    /* Jump to RAM to execute command and wait for completion */
    return DL_FlashCTL_executeCommandFromRAM(flashctl);
}

void DL_FlashCTL_programMemory64WithECCManual(FLASHCTL_Regs *flashctl,
    uint32_t address, const uint32_t *data, const uint8_t *eccCode)
{
    /* Enable 64 bits per data register for programming, with ECC enabled */
    DL_FlashCTL_programMemory64Config(
        flashctl, address, DL_FLASHCTL_PROGRAM_64_WITH_ECC, data);

    flashctl->GEN.CMDDATAINDEX = (address >> 4U) & 3U;
    if ((address % 0x10U) >= 0x8U)
    {
        flashctl->GEN.CMDDATAECC0 = (*eccCode) << FLASHCTL_CMDDATAECC0_VAL1_OFS;
    }
    else
    {
        flashctl->GEN.CMDDATAECC0 = *eccCode;
    } 

    /* Set bit to execute command */
    flashctl->GEN.CMDEXEC = FLASHCTL_CMDEXEC_VAL_EXECUTE;
}

DL_FLASHCTL_COMMAND_STATUS DL_FlashCTL_programMemoryFromRAM64WithECCManual(
    FLASHCTL_Regs *flashctl, uint32_t address, const uint32_t *data,
    const uint8_t *eccCode)
{
    /* Enable 64 bits per data register for programming, with ECC enabled */
    DL_FlashCTL_programMemory64Config(
        flashctl, address, DL_FLASHCTL_PROGRAM_64_WITH_ECC, data);

    flashctl->GEN.CMDDATAINDEX = (address >> 4U) & 3U;
    if ((address % 0x10U) >= 0x8U)
    {
        flashctl->GEN.CMDDATAECC0 = (*eccCode) << FLASHCTL_CMDDATAECC0_VAL1_OFS;
    }
    else
    {
        flashctl->GEN.CMDDATAECC0 = *eccCode;
    }

    /* Jump to RAM to execute command and wait for completion */
    return DL_FlashCTL_executeCommandFromRAM(flashctl);
}

void DL_FlashCTL_programMemory96WithECCManual(FLASHCTL_Regs *flashctl,
    uint32_t address, const uint32_t *data, const uint8_t *eccCode)
{
    /* Enable 96 bits per data register for programming, with ECC enabled */
    DL_FlashCTL_programMemory96Config(
        flashctl, address, DL_FLASHCTL_PROGRAM_96_WITH_ECC, data);

    flashctl->GEN.CMDDATAINDEX = (address >> 4U) & 3U;

    // Set the first ECC byte
    flashctl->GEN.CMDDATAECC0 &= ~((uint32_t)FLASHCTL_CMDDATAECC0_VAL0_MASK);
    flashctl->GEN.CMDDATAECC0 |= (*eccCode) << FLASHCTL_CMDDATAECC0_VAL0_OFS;

    // Set the second ECC byte
    flashctl->GEN.CMDDATAECC0 &= ~((uint32_t)FLASHCTL_CMDDATAECC0_VAL1_MASK);
    flashctl->GEN.CMDDATAECC0 |= (*(eccCode + 1)) << FLASHCTL_CMDDATAECC0_VAL1_OFS;

    /* Set bit to execute command */
    flashctl->GEN.CMDEXEC = FLASHCTL_CMDEXEC_VAL_EXECUTE;
}

DL_FLASHCTL_COMMAND_STATUS DL_FlashCTL_programMemoryFromRAM96WithECCManual(
    FLASHCTL_Regs *flashctl, uint32_t address, const uint32_t *data,
    const uint8_t *eccCode)
{
    /* Enable 96 bits per data register for programming, with ECC enabled */
    DL_FlashCTL_programMemory96Config(
        flashctl, address, DL_FLASHCTL_PROGRAM_96_WITH_ECC, data);

    flashctl->GEN.CMDDATAINDEX = (address >> 4U) & 3U;

    // Set the first ECC byte
    flashctl->GEN.CMDDATAECC0 &= ~((uint32_t)FLASHCTL_CMDDATAECC0_VAL0_MASK);
    flashctl->GEN.CMDDATAECC0 |= (*eccCode) << FLASHCTL_CMDDATAECC0_VAL0_OFS;

    // Set the second ECC byte
    flashctl->GEN.CMDDATAECC0 &= ~((uint32_t)FLASHCTL_CMDDATAECC0_VAL1_MASK);
    flashctl->GEN.CMDDATAECC0 |= (*(eccCode + 1)) << FLASHCTL_CMDDATAECC0_VAL1_OFS;

    /* Jump to RAM to execute command and wait for completion */
    return DL_FlashCTL_executeCommandFromRAM(flashctl);
}

void DL_FlashCTL_programMemory128WithECCManual(FLASHCTL_Regs *flashctl,
    uint32_t address, const uint32_t *data, const uint8_t *eccCode)
{
    /* Enable 128 bits per data register for programming, with ECC enabled */
    DL_FlashCTL_programMemory128Config(
        flashctl, address, DL_FLASHCTL_PROGRAM_128_WITH_ECC, data);

    flashctl->GEN.CMDDATAINDEX = (address >> 4U) & 3U;

    // Set the first ECC byte
    flashctl->GEN.CMDDATAECC0 &= ~((uint32_t)FLASHCTL_CMDDATAECC0_VAL0_MASK);
    flashctl->GEN.CMDDATAECC0 |= (*eccCode) << FLASHCTL_CMDDATAECC0_VAL0_OFS;

    // Set the second ECC byte
    flashctl->GEN.CMDDATAECC0 &= ~((uint32_t)FLASHCTL_CMDDATAECC0_VAL1_MASK);
    flashctl->GEN.CMDDATAECC0 |= (*(eccCode + 1)) << FLASHCTL_CMDDATAECC0_VAL1_OFS;

    /* Set bit to execute command */
    flashctl->GEN.CMDEXEC = FLASHCTL_CMDEXEC_VAL_EXECUTE;
}

DL_FLASHCTL_COMMAND_STATUS DL_FlashCTL_programMemoryFromRAM128WithECCManual(
    FLASHCTL_Regs *flashctl, uint32_t address, const uint32_t *data,
    const uint8_t *eccCode)
{
    /* Enable 128 bits per data register for programming, with ECC enabled */
    DL_FlashCTL_programMemory128Config(
        flashctl, address, DL_FLASHCTL_PROGRAM_128_WITH_ECC, data);

    flashctl->GEN.CMDDATAINDEX = (address >> 4U) & 3U;

    // Set the first ECC byte
    flashctl->GEN.CMDDATAECC0 &= ~((uint32_t)FLASHCTL_CMDDATAECC0_VAL0_MASK);
    flashctl->GEN.CMDDATAECC0 |= (*eccCode) << FLASHCTL_CMDDATAECC0_VAL0_OFS;

    // Set the second ECC byte
    flashctl->GEN.CMDDATAECC0 &= ~((uint32_t)FLASHCTL_CMDDATAECC0_VAL1_MASK);
    flashctl->GEN.CMDDATAECC0 |= (*(eccCode + 1)) << FLASHCTL_CMDDATAECC0_VAL1_OFS;

    /* Jump to RAM to execute command and wait for completion */
    return DL_FlashCTL_executeCommandFromRAM(flashctl);
}

bool DL_FlashCTL_programMemoryBlocking64WithECCGenerated(
    FLASHCTL_Regs *flashctl, uint32_t address, uint32_t *data,
    uint32_t dataSize, DL_FLASHCTL_REGION_SELECT regionSelect)
{
    bool status   = true;
    uint32_t size = dataSize;
    uint32_t *d   = data;
    uint32_t addr = address;

    /* Check for valid data size */
    if ((size == (uint32_t) 0) || ((size & (uint32_t) 1) == (uint32_t) 1)) {
        status = false;
    }

    while ((size != (uint32_t) 0) && status) {
        /* Clear STATCMD register before executing a flash operation */
        DL_FlashCTL_executeClearStatus(flashctl);

        /* Unprotect sector before every write */
        DL_FlashCTL_unprotectSector(flashctl, addr, regionSelect);

        DL_FlashCTL_programMemory64WithECCGenerated(flashctl, addr, d);
        size = size - (uint32_t) 2;
        d    = d + 2;
        addr = addr + (uint32_t) 8;

        status = DL_FlashCTL_waitForCmdDone(flashctl);
    }

    return (status);
}

DL_FLASHCTL_COMMAND_STATUS
DL_FlashCTL_programMemoryBlockingFromRAM64WithECCGenerated(
    FLASHCTL_Regs *flashctl, uint32_t address, uint32_t *data,
    uint32_t dataSize, DL_FLASHCTL_REGION_SELECT regionSelect)
{
    DL_FLASHCTL_COMMAND_STATUS status = DL_FLASHCTL_COMMAND_STATUS_IN_PROGRESS;
    uint32_t size                     = dataSize;
    uint32_t *d                       = data;
    uint32_t addr                     = address;

    /* Check for valid data size */
    if ((size == (uint32_t) 0) || ((size & (uint32_t) 1) == (uint32_t) 1)) {
        status = DL_FLASHCTL_COMMAND_STATUS_FAILED;
    }

    while ((size != (uint32_t) 0) &&
           (status != DL_FLASHCTL_COMMAND_STATUS_FAILED)) {
        /* Clear STATCMD register before executing a flash operation */
        DL_FlashCTL_executeClearStatus(flashctl);

        /* Unprotect sector before every write */
        DL_FlashCTL_unprotectSector(flashctl, addr, regionSelect);

        status = DL_FlashCTL_programMemoryFromRAM64WithECCGenerated(
            flashctl, addr, d);
        size = size - (uint32_t) 2;
        d    = d + 2;
        addr = addr + (uint32_t) 8;
    }

    return (status);
}

bool DL_FlashCTL_programMemoryBlocking64WithECCManual(FLASHCTL_Regs *flashctl,
    uint32_t address, uint32_t *data, uint8_t *eccCode, uint32_t dataSize,
    DL_FLASHCTL_REGION_SELECT regionSelect)
{
    bool status   = true;
    uint32_t size = dataSize;
    uint32_t *d   = data;
    uint32_t addr = address;
    uint8_t *ecc  = eccCode;

    /* Check for valid data size */
    if ((size == (uint32_t) 0) || ((size & (uint32_t) 1) == (uint32_t) 1)) {
        status = false;
    }

    while ((size != (uint32_t) 0) && status) {
        /* Clear STATCMD register before executing a flash operation */
        DL_FlashCTL_executeClearStatus(flashctl);

        /* Unprotect sector before every write */
        DL_FlashCTL_unprotectSector(flashctl, addr, regionSelect);

        DL_FlashCTL_programMemory64WithECCManual(flashctl, addr, d, ecc);
        size = size - (uint32_t) 2;
        d    = d + 2;
        ecc  = ecc + 1;
        addr = addr + (uint32_t) 8;

        status = DL_FlashCTL_waitForCmdDone(flashctl);
    }

    return (status);
}

DL_FLASHCTL_COMMAND_STATUS
DL_FlashCTL_programMemoryBlockingFromRAM64WithECCManual(
    FLASHCTL_Regs *flashctl, uint32_t address, uint32_t *data,
    uint8_t *eccCode, uint32_t dataSize,
    DL_FLASHCTL_REGION_SELECT regionSelect)
{
    DL_FLASHCTL_COMMAND_STATUS status = DL_FLASHCTL_COMMAND_STATUS_IN_PROGRESS;
    uint32_t size                     = dataSize;
    uint32_t *d                       = data;
    uint32_t addr                     = address;
    uint8_t *ecc                      = eccCode;
    /* Check for valid data size */
    if ((size == (uint32_t) 0) || ((size & (uint32_t) 1) == (uint32_t) 1)) {
        status = DL_FLASHCTL_COMMAND_STATUS_FAILED;
    }

    while ((size != (uint32_t) 0) &&
           (status != DL_FLASHCTL_COMMAND_STATUS_FAILED)) {
        /* Clear STATCMD register before executing a flash operation */
        DL_FlashCTL_executeClearStatus(flashctl);

        /* Unprotect sector before every write */
        DL_FlashCTL_unprotectSector(flashctl, addr, regionSelect);

        status = DL_FlashCTL_programMemoryFromRAM64WithECCManual(
            flashctl, addr, d, ecc);
        size = size - (uint32_t) 2;
        d    = d + 2;
        ecc  = ecc + 1;
        addr = addr + (uint32_t) 8;
    }

    return (status);
}

bool DL_FlashCTL_programMemoryBlocking128WithECCGenerated(
    FLASHCTL_Regs *flashctl, uint32_t address, uint32_t *data,
    uint32_t dataSize, DL_FLASHCTL_REGION_SELECT regionSelect)
{
    bool status   = true;
    uint32_t size = dataSize;
    uint32_t *d   = data;
    uint32_t addr = address;

    /* Check for valid data size */
    if ((size == (uint32_t) 0) || ((size % (uint32_t) 0x4) != (uint32_t) 0)) {
        status = false;
    }

    while ((size != (uint32_t) 0) && status) {
        /* Clear STATCMD register before executing a flash operation */
        DL_FlashCTL_executeClearStatus(flashctl);

        /* Unprotect sector before every write */
        DL_FlashCTL_unprotectSector(flashctl, addr, regionSelect);

        DL_FlashCTL_programMemory128WithECCGenerated(flashctl, addr, d);
        size = size - (uint32_t) 4;
        d    = d + 4;
        addr = addr + (uint32_t) 16;

        status = DL_FlashCTL_waitForCmdDone(flashctl);
    }

    return (status);
}

DL_FLASHCTL_COMMAND_STATUS
DL_FlashCTL_programMemoryBlockingFromRAM128WithECCGenerated(
    FLASHCTL_Regs *flashctl, uint32_t address, uint32_t *data,
    uint32_t dataSize, DL_FLASHCTL_REGION_SELECT regionSelect)
{
    DL_FLASHCTL_COMMAND_STATUS status = DL_FLASHCTL_COMMAND_STATUS_IN_PROGRESS;
    uint32_t size                     = dataSize;
    uint32_t *d                       = data;
    uint32_t addr                     = address;

    /* Check for valid data size */
    if ((size == (uint32_t) 0) || ((size % (uint32_t) 0x4) != (uint32_t) 0)) {
        status = DL_FLASHCTL_COMMAND_STATUS_FAILED;
    }

    while ((size != (uint32_t) 0) &&
           (status != DL_FLASHCTL_COMMAND_STATUS_FAILED)) {
        /* Clear STATCMD register before executing a flash operation */
        DL_FlashCTL_executeClearStatus(flashctl);

        /* Unprotect sector before every write */
        DL_FlashCTL_unprotectSector(flashctl, addr, regionSelect);

        status = DL_FlashCTL_programMemoryFromRAM128WithECCGenerated(
            flashctl, addr, d);
        size = size - (uint32_t) 4;
        d    = d + 4;
        addr = addr + (uint32_t) 16;
    }

    return (status);
}

bool DL_FlashCTL_programMemoryBlocking128WithECCManual(FLASHCTL_Regs *flashctl,
    uint32_t address, uint32_t *data, uint8_t *eccCode, uint32_t dataSize,
    DL_FLASHCTL_REGION_SELECT regionSelect)
{
    bool status   = true;
    uint32_t size = dataSize;
    uint32_t *d   = data;
    uint32_t addr = address;
    uint8_t *ecc  = eccCode;

    /* Check for valid data size */
    if ((size == (uint32_t) 0) || ((size % (uint32_t) 0x4) != (uint32_t) 0)) {
        status = false;
    }

    while ((size != (uint32_t) 0) && status) {
        /* Clear STATCMD register before executing a flash operation */
        DL_FlashCTL_executeClearStatus(flashctl);

        /* Unprotect sector before every write */
        DL_FlashCTL_unprotectSector(flashctl, addr, regionSelect);

        DL_FlashCTL_programMemory128WithECCManual(flashctl, addr, d, ecc);
        size = size - (uint32_t) 4;
        d    = d + 4;
        ecc  = ecc + 2;
        addr = addr + (uint32_t) 16;

        status = DL_FlashCTL_waitForCmdDone(flashctl);
    }

    return (status);
}

DL_FLASHCTL_COMMAND_STATUS
DL_FlashCTL_programMemoryBlockingFromRAM128WithECCManual(
    FLASHCTL_Regs *flashctl, uint32_t address, uint32_t *data,
    uint8_t *eccCode, uint32_t dataSize,
    DL_FLASHCTL_REGION_SELECT regionSelect)
{
    DL_FLASHCTL_COMMAND_STATUS status = DL_FLASHCTL_COMMAND_STATUS_IN_PROGRESS;
    uint32_t size                     = dataSize;
    uint32_t *d                       = data;
    uint32_t addr                     = address;
    uint8_t *ecc                      = eccCode;

    /* Check for valid data size */
    if ((size == (uint32_t) 0) || ((size % (uint32_t) 0x4) != (uint32_t) 0)) {
        status = DL_FLASHCTL_COMMAND_STATUS_FAILED;
    }

    while ((size != (uint32_t) 0) &&
           (status != DL_FLASHCTL_COMMAND_STATUS_FAILED)) {
        /* Clear STATCMD register before executing a flash operation */
        DL_FlashCTL_executeClearStatus(flashctl);

        /* Unprotect sector before every write */
        DL_FlashCTL_unprotectSector(flashctl, addr, regionSelect);

        status = DL_FlashCTL_programMemoryFromRAM128WithECCManual(
            flashctl, addr, d, ecc);
        size = size - (uint32_t) 4;
        d    = d + 4;
        ecc  = ecc + 2;
        addr = addr + (uint32_t) 16;
    }

    return (status);
}

bool DL_FlashCTL_programMemoryBlocking(FLASHCTL_Regs *flashctl,
    uint32_t address, uint32_t *data, uint32_t dataSize,
    DL_FLASHCTL_REGION_SELECT regionSelect)
{
    bool status   = true;
    uint32_t size = dataSize;
    uint32_t *d   = data;
    uint32_t addr = address;

    /* Check for valid data size */
    if (size == (uint32_t) 0) {
        status = false;
    }

    while ((size != (uint32_t) 0) && status) {
        /* Clear STATCMD register before executing a flash operation */
        DL_FlashCTL_executeClearStatus(flashctl);

        /* Unprotect sector before every write */
        DL_FlashCTL_unprotectSector(flashctl, addr, regionSelect);

        /* 32-bit case */
        if (size == (uint32_t) 1) {
            DL_FlashCTL_programMemory32(flashctl, addr, d);

            size = size - (uint32_t) 1;
            d    = d + 1;
            addr = addr + (uint32_t) 4;
        } else if (size == (uint32_t) 2) {
            /* 64-bit case */
            DL_FlashCTL_programMemory64(flashctl, addr, d);

            size = size - (uint32_t) 2;
            d    = d + 2;
            addr = addr + (uint32_t) 8;
        } else if (size == (uint32_t) 3) {
            /* 96-bit case */
            DL_FlashCTL_programMemory96(flashctl, addr, d);

            size = size - (uint32_t) 3;
            d    = d + 3;
            addr = addr + (uint32_t) 12;
        } else {
            /* 128-bit case */
            DL_FlashCTL_programMemory128(flashctl, addr, d);
            size = size - (uint32_t) 4;
            d    = d + 4;
            addr = addr + (uint32_t) 16;
        }

        status = DL_FlashCTL_waitForCmdDone(flashctl);
    }

    return (status);
}

DL_FLASHCTL_COMMAND_STATUS DL_FlashCTL_programMemoryFromRAM(
    FLASHCTL_Regs *flashctl, uint32_t address, uint32_t *data,
    uint32_t dataSize, DL_FLASHCTL_REGION_SELECT regionSelect)
{
    DL_FLASHCTL_COMMAND_STATUS status = DL_FLASHCTL_COMMAND_STATUS_IN_PROGRESS;
    uint32_t size                     = dataSize;
    uint32_t *d                       = data;
    uint32_t addr                     = address;

    /* Check for valid data size */
    if (size == (uint32_t) 0) {
        status = DL_FLASHCTL_COMMAND_STATUS_FAILED;
    }

    while ((size != (uint32_t) 0) &&
           (status != DL_FLASHCTL_COMMAND_STATUS_FAILED)) {
        /* Clear STATCMD register before executing a flash operation */
        DL_FlashCTL_executeClearStatus(flashctl);

        /* Unprotect sector before every write */
        DL_FlashCTL_unprotectSector(flashctl, addr, regionSelect);

        /* 32-bit case */
        if (size == (uint32_t) 1) {
            status = DL_FlashCTL_programMemoryFromRAM32(flashctl, addr, d);

            size = size - (uint32_t) 1;
            d    = d + 1;
            addr = addr + (uint32_t) 8;
        } else if (size == (uint32_t) 2) {
            /* 64-bit case */
            status = DL_FlashCTL_programMemoryFromRAM64(flashctl, addr, d);

            size = size - (uint32_t) 2;
            d    = d + 2;
            addr = addr + (uint32_t) 8;
        } else if (size == (uint32_t) 3) {
            /* 96-bit case */
            status = DL_FlashCTL_programMemoryFromRAM96(flashctl, addr, d);

            size = size - (uint32_t) 3;
            d    = d + 3;
            addr = addr + (uint32_t) 16;
        } else {
            /* 128-bit case */
            status = DL_FlashCTL_programMemoryFromRAM128(flashctl, addr, d);
            size   = size - (uint32_t) 4;
            d      = d + 4;
            addr   = addr + (uint32_t) 16;
        }
    }

    return (status);
}

void DL_FlashCTL_unprotectMainMemory(FLASHCTL_Regs *flashctl)
{
    flashctl->GEN.CMDWEPROTA = 0;
    flashctl->GEN.CMDWEPROTB = 0;
}

void DL_FlashCTL_unprotectDataMemory(FLASHCTL_Regs *flashctl)
{
    flashctl->GEN.CMDWEPROTA = 0;
    flashctl->GEN.CMDWEPROTB = 0;
}

void DL_FlashCTL_protectMainMemory(FLASHCTL_Regs *flashctl)
{
    flashctl->GEN.CMDWEPROTA = FLASHCTL_CMDWEPROTA_VAL_MAXIMUM;
    flashctl->GEN.CMDWEPROTB = FLASHCTL_CMDWEPROTB_VAL_MAXIMUM;
}

void DL_FlashCTL_unprotectNonMainMemory(FLASHCTL_Regs *flashctl)
{
    flashctl->GEN.CMDWEPROTNM = 0;
}

void DL_FlashCTL_protectNonMainMemory(FLASHCTL_Regs *flashctl)
{
    flashctl->GEN.CMDWEPROTNM = FLASHCTL_CMDWEPROTNM_VAL_MAXIMUM;
}

void DL_FlashCTL_unprotectAllMemory(FLASHCTL_Regs *flashctl)
{
    flashctl->GEN.CMDWEPROTA  = 0;
    flashctl->GEN.CMDWEPROTB  = 0;
    flashctl->GEN.CMDWEPROTNM = 0;
    flashctl->GEN.CMDWEPROTTR = 0;
    flashctl->GEN.CMDWEPROTEN = 0;
}

void DL_FlashCTL_protectAllMemory(FLASHCTL_Regs *flashctl)
{
    flashctl->GEN.CMDWEPROTA  = FLASHCTL_CMDWEPROTA_VAL_MAXIMUM;
    flashctl->GEN.CMDWEPROTB  = FLASHCTL_CMDWEPROTB_VAL_MAXIMUM;
    flashctl->GEN.CMDWEPROTNM = FLASHCTL_CMDWEPROTNM_VAL_MAXIMUM;
    flashctl->GEN.CMDWEPROTTR = FLASHCTL_CMDWEPROTTR_VAL_MAXIMUM;
    flashctl->GEN.CMDWEPROTEN = FLASHCTL_CMDWEPROTEN_VAL_MAXIMUM;
}

void DL_FlashCTL_unprotectSector(FLASHCTL_Regs *flashctl, uint32_t addr,
    DL_FLASHCTL_REGION_SELECT regionSelect)
{
    uint32_t sectorNumber = DL_FlashCTL_getFlashSectorNumber(flashctl, addr);
    uint32_t sectorInBank =
        DL_FlashCTL_getFlashSectorNumberInBank(flashctl, addr);
    uint32_t sectorMask;

    if ((uint32_t) regionSelect == FLASHCTL_CMDCTL_REGIONSEL_MAIN) {
        
        if (sectorInBank < (uint32_t) 32) {
            /* Use CMDWEPROTA */
            sectorMask = (uint32_t) 1 << sectorInBank;
            flashctl->GEN.CMDWEPROTA &= ~sectorMask;
        } else {
            /* Use CMDWEPROTB */
            sectorMask = (uint32_t) 1
                         << ((sectorInBank / (uint32_t) 8) - (uint32_t) 4);
            flashctl->GEN.CMDWEPROTB &= ~sectorMask;
        }
    } else if ((uint32_t) regionSelect == FLASHCTL_CMDCTL_REGIONSEL_NONMAIN) {
        sectorMask = (uint32_t) 1 << (sectorNumber % (uint32_t) 4);
        flashctl->GEN.CMDWEPROTNM &= ~sectorMask;
    } else {
        //not expected to come here.
    }
}

void DL_FlashCTL_protectSector(FLASHCTL_Regs *flashctl, uint32_t addr,
    DL_FLASHCTL_REGION_SELECT regionSelect)
{
    uint32_t sectorNumber = DL_FlashCTL_getFlashSectorNumber(flashctl, addr);
    uint32_t sectorInBank =
        DL_FlashCTL_getFlashSectorNumberInBank(flashctl, addr);
    uint32_t sectorMask;

    if ((uint32_t) regionSelect == FLASHCTL_CMDCTL_REGIONSEL_MAIN) {

        if (sectorInBank < (uint32_t) 32) {
            /* Use CMDWEPROTA */
            sectorMask = (uint32_t) 1 << sectorInBank;
            flashctl->GEN.CMDWEPROTA |= sectorMask;
        } else {
            /* Use CMDWEPROTB */
            sectorMask = (uint32_t) 1
                         << ((sectorInBank / (uint32_t) 8) - (uint32_t) 4);
            flashctl->GEN.CMDWEPROTB |= sectorMask;
        }
    } else if ((uint32_t) regionSelect == FLASHCTL_CMDCTL_REGIONSEL_NONMAIN) {
        sectorMask = (uint32_t) 1 << (sectorNumber % (uint32_t) 4);
        flashctl->GEN.CMDWEPROTNM |= sectorMask;
    } else {
        //not expected to come here.
    }
}

static void DL_FlashCTL_readVerifyConfig(FLASHCTL_Regs *flashctl, uint32_t address, uint32_t cmd)
{
    flashctl->GEN.CMDTYPE = (uint32_t)DL_FLASHCTL_COMMAND_SIZE_ONE_WORD | DL_FLASHCTL_COMMAND_TYPE_READ_VERIFY;

    uint32_t cmd_data_en = cmd & 0x0000FFFF;
    uint32_t cmd_ecc_en  = cmd & 0xFFFF0000;

    cmd_data_en = cmd_data_en << (address % 0x10);

    // If programming to the second 64 bits in a flash word,
    // write the second ECC byte
    if ((address % 0x10) >= 0x8)
    {
        cmd_ecc_en = cmd_ecc_en << 1;
    }

    flashctl->GEN.CMDBYTEN = cmd_ecc_en | cmd_data_en;

    /* Set address, address should be in the sector that we want to erase */
    DL_FlashCTL_setCommandAddress(flashctl, address);
}

static void DL_FlashCTL_readVerify8Config(FLASHCTL_Regs *flashctl, uint32_t address, uint32_t cmd, const uint8_t *data)
{
    DL_FlashCTL_readVerifyConfig(flashctl, address, cmd);

    // Create a 32-bit word from our data
    uint32_t data_shifted = ((uint32_t)*data) << ((address % 4U) * 8U);

    // Set which flash word we are writing to
    flashctl->GEN.CMDDATAINDEX = (address >> 4U) & 3U;

    // Select the CMDDATA register for our address within the flash word,
    // then load it with our data
    uint32_t cmddata_select = (address / 4U) % 4U;
    if (cmddata_select == 0x0U)
    {
        flashctl->GEN.CMDDATA0 = data_shifted;
    }
    else if (cmddata_select == 0x1U)
    {
        flashctl->GEN.CMDDATA1 = data_shifted;
    }
    else if (cmddata_select == 0x2U)
    {
        flashctl->GEN.CMDDATA2 = data_shifted;
    }
    else
    {
        flashctl->GEN.CMDDATA3 = data_shifted;
    }
}

static void DL_FlashCTL_readVerify16Config(FLASHCTL_Regs *flashctl, uint32_t address, uint32_t cmd, const uint16_t *data)
{
    DL_FlashCTL_readVerifyConfig(flashctl, address, cmd);

    // Create a 32-bit word from our data
    uint32_t data_shifted = ((uint32_t)*data) << ((address % 4U) * 8U);

    // Set which flash word we are writing to
    flashctl->GEN.CMDDATAINDEX = (address >> 4U) & 3U;

    // Select the CMDDATA register for our address within the flash word,
    // then load it with our data
    uint32_t cmddata_select = (address / 4U) % 4U;
    if (cmddata_select == 0x0U)
    {
        flashctl->GEN.CMDDATA0 = data_shifted;
    }
    else if (cmddata_select == 0x1U)
    {
        flashctl->GEN.CMDDATA1 = data_shifted;
    }
    else if (cmddata_select == 0x2U)
    {
        flashctl->GEN.CMDDATA2 = data_shifted;
    }
    else
    {
        flashctl->GEN.CMDDATA3 = data_shifted;
    }
}

static void DL_FlashCTL_readVerify32Config(FLASHCTL_Regs *flashctl, uint32_t address, uint32_t cmd, const uint32_t *data)
{
    DL_FlashCTL_readVerifyConfig(flashctl, address, cmd);

    // Create a 32-bit word from our data
    uint32_t data_shifted = ((uint32_t)*data) << ((address % 4U) * 8U);

    // Set which flash word we are writing to
    flashctl->GEN.CMDDATAINDEX = (address >> 4U) & 3U;

    // Select the CMDDATA register for our address within the flash word,
    // then load it with our data
    uint32_t cmddata_select = (address / 4U) % 4U;
    if (cmddata_select == 0x0U)
    {
        flashctl->GEN.CMDDATA0 = data_shifted;
    }
    else if (cmddata_select == 0x1U)
    {
        flashctl->GEN.CMDDATA1 = data_shifted;
    }
    else if (cmddata_select == 0x2U)
    {
        flashctl->GEN.CMDDATA2 = data_shifted;
    }
    else
    {
        flashctl->GEN.CMDDATA3 = data_shifted;
    }
}

static void DL_FlashCTL_readVerify64Config(FLASHCTL_Regs *flashctl, uint32_t address, uint32_t cmd, const uint32_t *data)
{
    DL_FlashCTL_readVerifyConfig(flashctl, address, cmd);

    flashctl->GEN.CMDDATAINDEX = (address >> 4U) & 3U;
    if ((address % 0x10U) == 0x8U)
    {
        flashctl->GEN.CMDDATA2 = *data;
        flashctl->GEN.CMDDATA3 = *(data + 1U);
    }
    else
    {
        flashctl->GEN.CMDDATA0 = *data;
        flashctl->GEN.CMDDATA1 = *(data + 1U);
    }
}

static void DL_FlashCTL_readVerify96Config(FLASHCTL_Regs *flashctl, uint32_t address, uint32_t cmd, const uint32_t *data)
{
    DL_FlashCTL_readVerifyConfig(flashctl, address, cmd);

    /* Set data registers */
    flashctl->GEN.CMDDATAINDEX = (address >> 4U) & 3U;
    flashctl->GEN.CMDDATA0     = *data;
    flashctl->GEN.CMDDATA1     = *(data + 1);
    flashctl->GEN.CMDDATA2     = *(data + 2);
}

static void DL_FlashCTL_readVerify128Config(FLASHCTL_Regs *flashctl, uint32_t address, uint32_t cmd, const uint32_t *data)
{
    DL_FlashCTL_readVerifyConfig(flashctl, address, cmd);

    /* Set data registers */
    flashctl->GEN.CMDDATAINDEX = (address >> 4U) & 3U;
    flashctl->GEN.CMDDATA0     = *data;
    flashctl->GEN.CMDDATA1     = *(data + 1);
    flashctl->GEN.CMDDATA2     = *(data + 2);
    flashctl->GEN.CMDDATA3     = *(data + 3);
}

void DL_FlashCTL_readVerify8(
    FLASHCTL_Regs *flashctl, uint32_t address, const uint8_t *data)
{
    DL_FlashCTL_readVerify8Config(
        flashctl, address, DL_FLASHCTL_READ_VERIFY_8_WITHOUT_ECC, data);

    /* Set bit to execute command */
    flashctl->GEN.CMDEXEC = FLASHCTL_CMDEXEC_VAL_EXECUTE;
}

void DL_FlashCTL_readVerify16(
    FLASHCTL_Regs *flashctl, uint32_t address, const uint16_t *data)
{
    DL_FlashCTL_readVerify16Config(
        flashctl, address, DL_FLASHCTL_READ_VERIFY_16_WITHOUT_ECC, data);

    /* Set bit to execute command */
    flashctl->GEN.CMDEXEC = FLASHCTL_CMDEXEC_VAL_EXECUTE;
}

void DL_FlashCTL_readVerify32(
    FLASHCTL_Regs *flashctl, uint32_t address, const uint32_t *data)
{
    DL_FlashCTL_readVerify32Config(
        flashctl, address, DL_FLASHCTL_READ_VERIFY_32_WITHOUT_ECC, data);

    /* Set bit to execute command */
    flashctl->GEN.CMDEXEC = FLASHCTL_CMDEXEC_VAL_EXECUTE;
}

void DL_FlashCTL_readVerify64(
    FLASHCTL_Regs *flashctl, uint32_t address, const uint32_t *data)
{
    DL_FlashCTL_readVerify64Config(
        flashctl, address, DL_FLASHCTL_READ_VERIFY_64_WITHOUT_ECC, data);

    /* Set bit to execute command */
    flashctl->GEN.CMDEXEC = FLASHCTL_CMDEXEC_VAL_EXECUTE;
}

void DL_FlashCTL_readVerify96(
    FLASHCTL_Regs *flashctl, uint32_t address, const uint32_t *data)
{
    DL_FlashCTL_readVerify96Config(
        flashctl, address, DL_FLASHCTL_READ_VERIFY_96_WITHOUT_ECC, data);

    /* Set bit to execute command */
    flashctl->GEN.CMDEXEC = FLASHCTL_CMDEXEC_VAL_EXECUTE;
}

void DL_FlashCTL_readVerify128(
    FLASHCTL_Regs *flashctl, uint32_t address, const uint32_t *data)
{
    DL_FlashCTL_readVerify128Config(
        flashctl, address, DL_FLASHCTL_READ_VERIFY_128_WITHOUT_ECC, data);

    /* Set bit to execute command */
    flashctl->GEN.CMDEXEC = FLASHCTL_CMDEXEC_VAL_EXECUTE;
}

DL_FLASHCTL_COMMAND_STATUS DL_FlashCTL_readVerifyFromRAM8(
    FLASHCTL_Regs *flashctl, uint32_t address, const uint8_t *data)
{
    DL_FlashCTL_readVerify8Config(
        flashctl, address, DL_FLASHCTL_READ_VERIFY_8_WITHOUT_ECC, data);

    /* Jump to RAM to execute command and wait for completion */
    return DL_FlashCTL_executeCommandFromRAM(flashctl);
}

DL_FLASHCTL_COMMAND_STATUS DL_FlashCTL_readVerifyFromRAM16(
    FLASHCTL_Regs *flashctl, uint32_t address, const uint16_t *data)
{
    DL_FlashCTL_readVerify16Config(
        flashctl, address, DL_FLASHCTL_READ_VERIFY_16_WITHOUT_ECC, data);

    /* Jump to RAM to execute command and wait for completion */
    return DL_FlashCTL_executeCommandFromRAM(flashctl);
}

DL_FLASHCTL_COMMAND_STATUS DL_FlashCTL_readVerifyFromRAM32(
    FLASHCTL_Regs *flashctl, uint32_t address, const uint32_t *data)
{
    DL_FlashCTL_readVerify32Config(
        flashctl, address, DL_FLASHCTL_READ_VERIFY_32_WITHOUT_ECC, data);

    /* Jump to RAM to execute command and wait for completion */
    return DL_FlashCTL_executeCommandFromRAM(flashctl);
}

DL_FLASHCTL_COMMAND_STATUS DL_FlashCTL_readVerifyFromRAM64(
    FLASHCTL_Regs *flashctl, uint32_t address, const uint32_t *data)
{
    DL_FlashCTL_readVerify64Config(
        flashctl, address, DL_FLASHCTL_READ_VERIFY_64_WITHOUT_ECC, data);

    /* Jump to RAM to execute command and wait for completion */
    return DL_FlashCTL_executeCommandFromRAM(flashctl);
}

DL_FLASHCTL_COMMAND_STATUS DL_FlashCTL_readVerifyFromRAM96(
    FLASHCTL_Regs *flashctl, uint32_t address, const uint32_t *data)
{
    DL_FlashCTL_readVerify96Config(
        flashctl, address, DL_FLASHCTL_READ_VERIFY_96_WITHOUT_ECC, data);

    /* Jump to RAM to execute command and wait for completion */
    return DL_FlashCTL_executeCommandFromRAM(flashctl);
}

DL_FLASHCTL_COMMAND_STATUS DL_FlashCTL_readVerifyFromRAM128(
    FLASHCTL_Regs *flashctl, uint32_t address, const uint32_t *data)
{
    DL_FlashCTL_readVerify128Config(
        flashctl, address, DL_FLASHCTL_READ_VERIFY_128_WITHOUT_ECC, data);

    /* Jump to RAM to execute command and wait for completion */
    return DL_FlashCTL_executeCommandFromRAM(flashctl);
}
DL_FLASHCTL_COMMAND_STATUS DL_FlashCTL_readVerifyFromRAM8WithECCGenerated(
    FLASHCTL_Regs *flashctl, uint32_t address, const uint8_t *data)
{
    DL_FlashCTL_readVerify8Config(
        flashctl, address, DL_FLASHCTL_READ_VERIFY_8_WITH_ECC, data);

    /* Jump to RAM to execute command and wait for completion */
    return DL_FlashCTL_executeCommandFromRAM(flashctl);
}

DL_FLASHCTL_COMMAND_STATUS DL_FlashCTL_readVerifyFromRAM16WithECCGenerated(
    FLASHCTL_Regs *flashctl, uint32_t address, const uint16_t *data)
{
    DL_FlashCTL_readVerify16Config(
        flashctl, address, DL_FLASHCTL_READ_VERIFY_16_WITH_ECC, data);

    /* Jump to RAM to execute command and wait for completion */
    return DL_FlashCTL_executeCommandFromRAM(flashctl);
}

DL_FLASHCTL_COMMAND_STATUS DL_FlashCTL_readVerifyFromRAM32WithECCGenerated(
    FLASHCTL_Regs *flashctl, uint32_t address, const uint32_t *data)
{
    DL_FlashCTL_readVerify32Config(
        flashctl, address, DL_FLASHCTL_READ_VERIFY_32_WITH_ECC, data);

    /* Jump to RAM to execute command and wait for completion */
    return DL_FlashCTL_executeCommandFromRAM(flashctl);
}

DL_FLASHCTL_COMMAND_STATUS DL_FlashCTL_readVerifyFromRAM64WithECCGenerated(
    FLASHCTL_Regs *flashctl, uint32_t address, const uint32_t *data)
{
    DL_FlashCTL_readVerify64Config(
        flashctl, address, DL_FLASHCTL_READ_VERIFY_64_WITH_ECC, data);
    /* Jump to RAM to execute command and wait for completion */
    return DL_FlashCTL_executeCommandFromRAM(flashctl);
}

DL_FLASHCTL_COMMAND_STATUS DL_FlashCTL_readVerifyFromRAM96WithECCGenerated(
    FLASHCTL_Regs *flashctl, uint32_t address, const uint32_t *data)
{
    DL_FlashCTL_readVerify96Config(
        flashctl, address, DL_FLASHCTL_READ_VERIFY_96_WITH_ECC, data);

    /* Jump to RAM to execute command and wait for completion */
    return DL_FlashCTL_executeCommandFromRAM(flashctl);
}

DL_FLASHCTL_COMMAND_STATUS DL_FlashCTL_readVerifyFromRAM128WithECCGenerated(
    FLASHCTL_Regs *flashctl, uint32_t address, const uint32_t *data)
{
    DL_FlashCTL_readVerify128Config(
        flashctl, address, DL_FLASHCTL_READ_VERIFY_128_WITH_ECC, data);

    /* Jump to RAM to execute command and wait for completion */
    return DL_FlashCTL_executeCommandFromRAM(flashctl);
}

DL_FLASHCTL_COMMAND_STATUS DL_FlashCTL_readVerifyFromRAM8WithECCManual(
    FLASHCTL_Regs *flashctl, uint32_t address, const uint8_t *data,
    const uint8_t *eccCode)
{
    DL_FlashCTL_readVerify8Config(
        flashctl, address, DL_FLASHCTL_READ_VERIFY_8_WITH_ECC, data);

    flashctl->GEN.CMDDATAINDEX = (address >> 4U) & 3U;
    if ((address % 0x10U) >= 0x8U)
    {
        flashctl->GEN.CMDDATAECC0 &= ~((uint32_t)FLASHCTL_CMDDATAECC0_VAL1_MASK);
        flashctl->GEN.CMDDATAECC0 |= (*eccCode) << FLASHCTL_CMDDATAECC0_VAL1_OFS;
    }
    else
    {
        flashctl->GEN.CMDDATAECC0 &= ~((uint32_t)FLASHCTL_CMDDATAECC0_VAL0_MASK);
        flashctl->GEN.CMDDATAECC0 |= (*eccCode) << FLASHCTL_CMDDATAECC0_VAL0_OFS;
    }

    /* Jump to RAM to execute command and wait for completion */
    return DL_FlashCTL_executeCommandFromRAM(flashctl);
}

DL_FLASHCTL_COMMAND_STATUS DL_FlashCTL_readVerifyFromRAM16WithECCManual(
    FLASHCTL_Regs *flashctl, uint32_t address, const uint16_t *data,
    const uint8_t *eccCode)
{
    DL_FlashCTL_readVerify16Config(
        flashctl, address, DL_FLASHCTL_READ_VERIFY_16_WITH_ECC, data);

    flashctl->GEN.CMDDATAINDEX = (address >> 4U) & 3U;
    if ((address % 0x10U) >= 0x8U)
    {
        flashctl->GEN.CMDDATAECC0 &= ~((uint32_t)FLASHCTL_CMDDATAECC0_VAL1_MASK);
        flashctl->GEN.CMDDATAECC0 |= (*eccCode) << FLASHCTL_CMDDATAECC0_VAL1_OFS;
    }
    else
    {
        flashctl->GEN.CMDDATAECC0 &= ~((uint32_t)FLASHCTL_CMDDATAECC0_VAL0_MASK);
        flashctl->GEN.CMDDATAECC0 |= (*eccCode) << FLASHCTL_CMDDATAECC0_VAL0_OFS;
    }

    /* Jump to RAM to execute command and wait for completion */
    return DL_FlashCTL_executeCommandFromRAM(flashctl);
}

DL_FLASHCTL_COMMAND_STATUS DL_FlashCTL_readVerifyFromRAM32WithECCManual(
    FLASHCTL_Regs *flashctl, uint32_t address, const uint32_t *data,
    const uint8_t *eccCode)
{
    DL_FlashCTL_readVerify32Config(
        flashctl, address, DL_FLASHCTL_READ_VERIFY_32_WITH_ECC, data);

    flashctl->GEN.CMDDATAINDEX = (address >> 4U) & 3U;
    if ((address % 0x10U) >= 0x8U)
    {
        flashctl->GEN.CMDDATAECC0 &= ~((uint32_t)FLASHCTL_CMDDATAECC0_VAL1_MASK);
        flashctl->GEN.CMDDATAECC0 |= (*eccCode) << FLASHCTL_CMDDATAECC0_VAL1_OFS;
    }
    else
    {
        flashctl->GEN.CMDDATAECC0 &= ~((uint32_t)FLASHCTL_CMDDATAECC0_VAL0_MASK);
        flashctl->GEN.CMDDATAECC0 |= (*eccCode) << FLASHCTL_CMDDATAECC0_VAL0_OFS;
    }

    /* Jump to RAM to execute command and wait for completion */
    return DL_FlashCTL_executeCommandFromRAM(flashctl);
}

DL_FLASHCTL_COMMAND_STATUS DL_FlashCTL_readVerifyFromRAM64WithECCManual(
    FLASHCTL_Regs *flashctl, uint32_t address, const uint32_t *data,
    const uint8_t *eccCode)
{
    DL_FlashCTL_readVerify64Config(
        flashctl, address, DL_FLASHCTL_READ_VERIFY_64_WITH_ECC, data);

    flashctl->GEN.CMDDATAINDEX = (address >> 4U) & 3U;
    if ((address % 0x10U) >= 0x8U)
    {
        flashctl->GEN.CMDDATAECC0 &= ~((uint32_t)FLASHCTL_CMDDATAECC0_VAL1_MASK);
        flashctl->GEN.CMDDATAECC0 |= (*eccCode) << FLASHCTL_CMDDATAECC0_VAL1_OFS;
    }
    else
    {
        flashctl->GEN.CMDDATAECC0 &= ~((uint32_t)FLASHCTL_CMDDATAECC0_VAL0_MASK);
        flashctl->GEN.CMDDATAECC0 |= (*eccCode) << FLASHCTL_CMDDATAECC0_VAL0_OFS;
    }

    /* Jump to RAM to execute command and wait for completion */
    return DL_FlashCTL_executeCommandFromRAM(flashctl);
}

DL_FLASHCTL_COMMAND_STATUS DL_FlashCTL_readVerifyFromRAM96WithECCManual(
    FLASHCTL_Regs *flashctl, uint32_t address, const uint32_t *data,
    const uint8_t *eccCode)
{
    DL_FlashCTL_readVerify96Config(
        flashctl, address, DL_FLASHCTL_READ_VERIFY_96_WITH_ECC, data);

    flashctl->GEN.CMDDATAINDEX = (address >> 4U) & 3U;

    // Set the first ECC byte
    flashctl->GEN.CMDDATAECC0 &= ~((uint32_t)FLASHCTL_CMDDATAECC0_VAL0_MASK);
    flashctl->GEN.CMDDATAECC0 |= (*eccCode) << FLASHCTL_CMDDATAECC0_VAL0_OFS;

    // Set the second ECC byte
    flashctl->GEN.CMDDATAECC0 &= ~((uint32_t)FLASHCTL_CMDDATAECC0_VAL1_MASK);
    flashctl->GEN.CMDDATAECC0 |= (*(eccCode + 1)) << FLASHCTL_CMDDATAECC0_VAL1_OFS;

    /* Jump to RAM to execute command and wait for completion */
    return DL_FlashCTL_executeCommandFromRAM(flashctl);
}

DL_FLASHCTL_COMMAND_STATUS DL_FlashCTL_readVerifyFromRAM128WithECCManual(
    FLASHCTL_Regs *flashctl, uint32_t address, const uint32_t *data,
    const uint8_t *eccCode)
{
    DL_FlashCTL_readVerify128Config(
        flashctl, address, DL_FLASHCTL_READ_VERIFY_128_WITH_ECC, data);

    flashctl->GEN.CMDDATAINDEX = (address >> 4U) & 3U;

    // Set the first ECC byte
    flashctl->GEN.CMDDATAECC0 &= ~((uint32_t)FLASHCTL_CMDDATAECC0_VAL0_MASK);
    flashctl->GEN.CMDDATAECC0 |= (*eccCode) << FLASHCTL_CMDDATAECC0_VAL0_OFS;

    // Set the second ECC byte
    flashctl->GEN.CMDDATAECC0 &= ~((uint32_t)FLASHCTL_CMDDATAECC0_VAL1_MASK);
    flashctl->GEN.CMDDATAECC0 |= (*(eccCode + 1)) << FLASHCTL_CMDDATAECC0_VAL1_OFS;

    /* Jump to RAM to execute command and wait for completion */
    return DL_FlashCTL_executeCommandFromRAM(flashctl);
}

void DL_FlashCTL_readVerify8WithECCGenerated(
    FLASHCTL_Regs *flashctl, uint32_t address, const uint8_t *data)
{
    DL_FlashCTL_readVerify8Config(
        flashctl, address, DL_FLASHCTL_READ_VERIFY_8_WITH_ECC, data);

    /* Set bit to execute command */
    flashctl->GEN.CMDEXEC = FLASHCTL_CMDEXEC_VAL_EXECUTE;
}

void DL_FlashCTL_readVerify16WithECCGenerated(
    FLASHCTL_Regs *flashctl, uint32_t address, const uint16_t *data)
{
    DL_FlashCTL_readVerify16Config(
        flashctl, address, DL_FLASHCTL_READ_VERIFY_16_WITH_ECC, data);

    /* Set bit to execute command */
    flashctl->GEN.CMDEXEC = FLASHCTL_CMDEXEC_VAL_EXECUTE;
}

void DL_FlashCTL_readVerify32WithECCGenerated(
    FLASHCTL_Regs *flashctl, uint32_t address, const uint32_t *data)
{
    DL_FlashCTL_readVerify32Config(
        flashctl, address, DL_FLASHCTL_READ_VERIFY_32_WITH_ECC, data);

    /* Set bit to execute command */
    flashctl->GEN.CMDEXEC = FLASHCTL_CMDEXEC_VAL_EXECUTE;
}

void DL_FlashCTL_readVerify64WithECCGenerated(
    FLASHCTL_Regs *flashctl, uint32_t address, const uint32_t *data)
{
    DL_FlashCTL_readVerify64Config(
        flashctl, address, DL_FLASHCTL_READ_VERIFY_64_WITH_ECC, data);

    /* Set bit to execute command */
    flashctl->GEN.CMDEXEC = FLASHCTL_CMDEXEC_VAL_EXECUTE;
}

void DL_FlashCTL_readVerify96WithECCGenerated(
    FLASHCTL_Regs *flashctl, uint32_t address, const uint32_t *data)
{
    DL_FlashCTL_readVerify96Config(
        flashctl, address, DL_FLASHCTL_READ_VERIFY_96_WITH_ECC, data);

    /* Set bit to execute command */
    flashctl->GEN.CMDEXEC = FLASHCTL_CMDEXEC_VAL_EXECUTE;
}

void DL_FlashCTL_readVerify128WithECCGenerated(
    FLASHCTL_Regs *flashctl, uint32_t address, const uint32_t *data)
{
    DL_FlashCTL_readVerify128Config(
        flashctl, address, DL_FLASHCTL_READ_VERIFY_128_WITH_ECC, data);

    /* Set bit to execute command */
    flashctl->GEN.CMDEXEC = FLASHCTL_CMDEXEC_VAL_EXECUTE;
}

void DL_FlashCTL_readVerify8WithECCManual(
    FLASHCTL_Regs *flashctl, uint32_t address, const uint8_t *data, const uint8_t *eccCode)
{
    DL_FlashCTL_readVerify8Config(
        flashctl, address, DL_FLASHCTL_READ_VERIFY_8_WITH_ECC, data);

    flashctl->GEN.CMDDATAINDEX = (address >> 4U) & 3U;
    if ((address % 0x10U) >= 0x8U)
    {
        flashctl->GEN.CMDDATAECC0 &= ~((uint32_t)FLASHCTL_CMDDATAECC0_VAL1_MASK);
        flashctl->GEN.CMDDATAECC0 |= (*eccCode) << FLASHCTL_CMDDATAECC0_VAL1_OFS;
    }
    else
    {
        flashctl->GEN.CMDDATAECC0 &= ~((uint32_t)FLASHCTL_CMDDATAECC0_VAL0_MASK);
        flashctl->GEN.CMDDATAECC0 |= (*eccCode) << FLASHCTL_CMDDATAECC0_VAL0_OFS;
    }

    /* Set bit to execute command */
    flashctl->GEN.CMDEXEC = FLASHCTL_CMDEXEC_VAL_EXECUTE;
}

void DL_FlashCTL_readVerify16WithECCManual(FLASHCTL_Regs *flashctl,
    uint32_t address, const uint16_t *data, const uint8_t *eccCode)
{
    DL_FlashCTL_readVerify16Config(
        flashctl, address, DL_FLASHCTL_READ_VERIFY_16_WITH_ECC, data);

    flashctl->GEN.CMDDATAINDEX = (address >> 4U) & 3U;
    if ((address % 0x10U) >= 0x8U)
    {
        flashctl->GEN.CMDDATAECC0 &= ~((uint32_t)FLASHCTL_CMDDATAECC0_VAL1_MASK);
        flashctl->GEN.CMDDATAECC0 |= (*eccCode) << FLASHCTL_CMDDATAECC0_VAL1_OFS;
    }
    else
    {
        flashctl->GEN.CMDDATAECC0 &= ~((uint32_t)FLASHCTL_CMDDATAECC0_VAL0_MASK);
        flashctl->GEN.CMDDATAECC0 |= (*eccCode) << FLASHCTL_CMDDATAECC0_VAL0_OFS;
    }

    /* Set bit to execute command */
    flashctl->GEN.CMDEXEC = FLASHCTL_CMDEXEC_VAL_EXECUTE;
}

void DL_FlashCTL_readVerify32WithECCManual(FLASHCTL_Regs *flashctl,
    uint32_t address, const uint32_t *data, const uint8_t *eccCode)
{
    DL_FlashCTL_readVerify32Config(
        flashctl, address, DL_FLASHCTL_READ_VERIFY_32_WITH_ECC, data);

    flashctl->GEN.CMDDATAINDEX = (address >> 4U) & 3U;
    if ((address % 0x10U) >= 0x8U)
    {
        flashctl->GEN.CMDDATAECC0 &= ~((uint32_t)FLASHCTL_CMDDATAECC0_VAL1_MASK);
        flashctl->GEN.CMDDATAECC0 |= (*eccCode) << FLASHCTL_CMDDATAECC0_VAL1_OFS;
    }
    else
    {
        flashctl->GEN.CMDDATAECC0 &= ~((uint32_t)FLASHCTL_CMDDATAECC0_VAL0_MASK);
        flashctl->GEN.CMDDATAECC0 |= (*eccCode) << FLASHCTL_CMDDATAECC0_VAL0_OFS;
    }

    /* Set bit to execute command */
    flashctl->GEN.CMDEXEC = FLASHCTL_CMDEXEC_VAL_EXECUTE;
}

void DL_FlashCTL_readVerify64WithECCManual(FLASHCTL_Regs *flashctl,
    uint32_t address, const uint32_t *data, const uint8_t *eccCode)
{
    DL_FlashCTL_readVerify64Config(
        flashctl, address, DL_FLASHCTL_READ_VERIFY_64_WITH_ECC, data);

    flashctl->GEN.CMDDATAINDEX = (address >> 4U) & 3U;
    if ((address % 0x10U) >= 0x8U)
    {
        flashctl->GEN.CMDDATAECC0 &= ~((uint32_t)FLASHCTL_CMDDATAECC0_VAL1_MASK);
        flashctl->GEN.CMDDATAECC0 |= (*eccCode) << FLASHCTL_CMDDATAECC0_VAL1_OFS;
    }
    else
    {
        flashctl->GEN.CMDDATAECC0 &= ~((uint32_t)FLASHCTL_CMDDATAECC0_VAL0_MASK);
        flashctl->GEN.CMDDATAECC0 |= (*eccCode) << FLASHCTL_CMDDATAECC0_VAL0_OFS;
    }

    /* Set bit to execute command */
    flashctl->GEN.CMDEXEC = FLASHCTL_CMDEXEC_VAL_EXECUTE;
}

void DL_FlashCTL_readVerify96WithECCManual(FLASHCTL_Regs *flashctl,
    uint32_t address, const uint32_t *data, const uint8_t *eccCode)
{
    DL_FlashCTL_readVerify96Config(
        flashctl, address, DL_FLASHCTL_READ_VERIFY_96_WITH_ECC, data);

    flashctl->GEN.CMDDATAINDEX = (address >> 4U) & 3U;

    // Set the first ECC byte
    flashctl->GEN.CMDDATAECC0 &= ~((uint32_t)FLASHCTL_CMDDATAECC0_VAL0_MASK);
    flashctl->GEN.CMDDATAECC0 |= (*eccCode) << FLASHCTL_CMDDATAECC0_VAL0_OFS;

    // Set the second ECC byte
    flashctl->GEN.CMDDATAECC0 &= ~((uint32_t)FLASHCTL_CMDDATAECC0_VAL1_MASK);
    flashctl->GEN.CMDDATAECC0 |= (*(eccCode + 1)) << FLASHCTL_CMDDATAECC0_VAL1_OFS;

    /* Set bit to execute command */
    flashctl->GEN.CMDEXEC = FLASHCTL_CMDEXEC_VAL_EXECUTE;
}

void DL_FlashCTL_readVerify128WithECCManual(FLASHCTL_Regs *flashctl,
    uint32_t address, const uint32_t *data, const uint8_t *eccCode)
{
    DL_FlashCTL_readVerify128Config(
        flashctl, address, DL_FLASHCTL_READ_VERIFY_128_WITH_ECC, data);

    flashctl->GEN.CMDDATAINDEX = (address >> 4U) & 3U;

    // Set the first ECC byte
    flashctl->GEN.CMDDATAECC0 &= ~((uint32_t)FLASHCTL_CMDDATAECC0_VAL0_MASK);
    flashctl->GEN.CMDDATAECC0 |= (*eccCode) << FLASHCTL_CMDDATAECC0_VAL0_OFS;

    // Set the second ECC byte
    flashctl->GEN.CMDDATAECC0 &= ~((uint32_t)FLASHCTL_CMDDATAECC0_VAL1_MASK);
    flashctl->GEN.CMDDATAECC0 |= (*(eccCode + 1)) << FLASHCTL_CMDDATAECC0_VAL1_OFS;

    /* Set bit to execute command */
    flashctl->GEN.CMDEXEC = FLASHCTL_CMDEXEC_VAL_EXECUTE;
}

void DL_FlashCTL_blankVerify(FLASHCTL_Regs *flashctl, uint32_t address)
{
    /* BLANKVERIFY command is not supported on MSPM33 devices */
    return;
}

DL_FLASHCTL_COMMAND_STATUS DL_FlashCTL_blankVerifyFromRAM(
    FLASHCTL_Regs *flashctl, uint32_t address)
{
    /* BLANKVERIFY command is not supported on MSPM33 devices */
    return DL_FLASHCTL_COMMAND_STATUS_FAILED;
}

bool DL_FlashCTL_eraseDataBank(FLASHCTL_Regs *flashctl)
{
    bool status      = true;
    uint32_t address = FLASHCTL_BANK2_MAIN_ADDRESS;

    DL_FlashCTL_protectAllMemory(flashctl);
    DL_FlashCTL_unprotectMainMemory(flashctl);
    DL_FlashCTL_eraseMemory(flashctl, address, DL_FLASHCTL_COMMAND_SIZE_BANK);
    status = DL_FlashCTL_waitForCmdDone(flashctl);

    return (status);
}

DL_FLASHCTL_COMMAND_STATUS DL_FlashCTL_eraseDataBankFromRAM(
    FLASHCTL_Regs *flashctl)
{
    DL_FLASHCTL_COMMAND_STATUS status = DL_FLASHCTL_COMMAND_STATUS_PASSED;
    uint32_t address                  = FLASHCTL_BANK2_MAIN_ADDRESS;

    DL_FlashCTL_protectAllMemory(flashctl);
    DL_FlashCTL_unprotectMainMemory(flashctl);
    status = DL_FlashCTL_eraseMemoryFromRAM(
        flashctl, address, DL_FLASHCTL_COMMAND_SIZE_BANK);

    return (status);
}
