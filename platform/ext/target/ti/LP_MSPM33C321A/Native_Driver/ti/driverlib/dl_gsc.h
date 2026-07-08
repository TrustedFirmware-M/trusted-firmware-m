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
/*!****************************************************************************
 *  @file       dl_gsc.h
 *  @brief      GSC Driver
 *  @defgroup   GSC Global SECURITY Controller (GSC)
 *
 *  @anchor ti_dl_dl_gsc_Overview
 *  # Overview
 *
 *   The GSC Library allows full configuration of the SOC Security.
 *   The GSC Module, provides standard interfaces to configure
 *      - Flash Security
 *      - SRAM Security
 *      - Peripheral Security
 *
 *  <hr>
 ******************************************************************************
 */
/** @addtogroup GSC
 * @{
 */
#ifndef ti_dl_dl_gsc__include
#define ti_dl_dl_gsc__include

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include <ti/devices/msp/msp.h>
#include <ti/driverlib/dl_common.h>

#define __MSPM33_HAS_GSC__

#ifdef __MSPM33_HAS_GSC__

#ifdef __cplusplus
extern "C" {
#endif

/* GSC Lock/Commit Keys */
#define DL_GSC_LOCK_KEY ((uint32_t) 0xA551U)
#define DL_GSC_COMMIT_KEY ((uint32_t) 0xA442U)

/**
 * @brief Structure representing SRAM chunks within a 16KB page
 *
 * Memory layout within each 16KB page:
 * chunk_512B_0: First 512 bytes  (offset 0x000-0x1FF)
 * chunk_512B_1: Second 512 bytes (offset 0x200-0x3FF)
 * chunk_1KB:    1KB block        (offset 0x400-0x7FF)
 * chunk_2KB:    2KB block        (offset 0x800-0xFFF)
 * chunk_4KB_0:  First 4KB block  (offset 0x1000-0x1FFF)
 * chunk_4KB_1:  Second 4KB block (offset 0x2000-0x2FFF)
 * chunk_4KB_2:  Third 4KB block  (offset 0x3000-0x3FFF)
 *
 * For each chunk:
 * - 0: Non-secure access allowed
 * - 1: Secure access only
 */
typedef struct {
    uint32_t chunk_512B_0; /*!< First 512B chunk (0x000-0x1FF) */
    uint32_t chunk_512B_1; /*!< Second 512B chunk (0x200-0x3FF) */
    uint32_t chunk_1KB;    /*!< 1KB chunk (0x400-0x7FF) */
    uint32_t chunk_2KB;    /*!< 2KB chunk (0x800-0xFFF) */
    uint32_t chunk_4KB_0;  /*!< First 4KB chunk (0x1000-0x1FFF) */
    uint32_t chunk_4KB_1;  /*!< Second 4KB chunk (0x2000-0x2FFF) */
    uint32_t chunk_4KB_2;  /*!< Third 4KB chunk (0x3000-0x3FFF) */
} DL_GSC_SRAMPageConfig;

/**
 * @brief Structure representing SRAM security configuration for all pages
 *
 * The SRAM memory map starting from base address 0x20000000 is divided into 16 pages:
 * Page 0:  0x20000000 - 0x20003FFF (16KB)
 * Page 1:  0x20004000 - 0x20007FFF (16KB)
 * Page 2:  0x20008000 - 0x2000BFFF (16KB)
 * Page 3:  0x2000C000 - 0x2000FFFF (16KB)
 * Page 4:  0x20010000 - 0x20013FFF (16KB)
 * Page 5:  0x20014000 - 0x20017FFF (16KB)
 * Page 6:  0x20018000 - 0x2001BFFF (16KB)
 * Page 7:  0x2001C000 - 0x2001FFFF (16KB)
 * Page 8:  0x20020000 - 0x20023FFF (16KB)
 * Page 9:  0x20024000 - 0x20027FFF (16KB)
 * Page 10: 0x20028000 - 0x2002BFFF (16KB)
 * Page 11: 0x2002C000 - 0x2002FFFF (16KB)
 * Page 12: 0x20030000 - 0x20033FFF (16KB)
 * Page 13: 0x20034000 - 0x20037FFF (16KB)
 * Page 14: 0x20038000 - 0x2003BFFF (16KB)
 * Page 15: 0x2003C000 - 0x2003FFFF (16KB)
 *
 * Each 16KB page is further divided into chunks that can be individually configured:
 * - Two 512B chunks  (0x000-0x1FF, 0x200-0x3FF)
 * - One 1KB chunk    (0x400-0x7FF)
 * - One 2KB chunk    (0x800-0xFFF)
 * - Three 4KB chunks (0x1000-0x1FFF, 0x2000-0x2FFF, 0x3000-0x3FFF)
 *
 * For each chunk:
 * - false: Non-secure access allowed
 * - true: Secure access only
 */
typedef struct {
    DL_GSC_SRAMPageConfig
        pages[16]; /*!< Configuration for 16 SRAM pages of 16KB each */
} DL_GSC_SRAMSecurityConfig;

/**
 * @brief Flash Bank identifiers for write protection
 */
typedef enum {
    DL_GSC_MAIN_FLASH_BANK_A = 0, /*!< Main Flash Bank A */
    DL_GSC_MAIN_FLASH_BANK_B = 1  /*!< Main Flash Bank B */
} DL_GSC_MainFlashBank;

/**
 * @brief Main Flash Sectors (2KB each)
 * Each bit represents a 2KB sector in flash memory
 */
typedef enum {
    DL_GSC_MAIN_FLASH_SECTOR_0 =
        0x00000001U, /*!< Sector 0  (0x00000000-0x000007FF) */
    DL_GSC_MAIN_FLASH_SECTOR_1 =
        0x00000002U, /*!< Sector 1  (0x00000800-0x00000FFF) */
    DL_GSC_MAIN_FLASH_SECTOR_2 =
        0x00000004U, /*!< Sector 2  (0x00001000-0x000017FF) */
    DL_GSC_MAIN_FLASH_SECTOR_3 =
        0x00000008U, /*!< Sector 3  (0x00001800-0x00001FFF) */
    DL_GSC_MAIN_FLASH_SECTOR_4 =
        0x00000010U, /*!< Sector 4  (0x00002000-0x000027FF) */
    DL_GSC_MAIN_FLASH_SECTOR_5 =
        0x00000020U, /*!< Sector 5  (0x00002800-0x00002FFF) */
    DL_GSC_MAIN_FLASH_SECTOR_6 =
        0x00000040U, /*!< Sector 6  (0x00003000-0x000037FF) */
    DL_GSC_MAIN_FLASH_SECTOR_7 =
        0x00000080U, /*!< Sector 7  (0x00003800-0x00003FFF) */
    DL_GSC_MAIN_FLASH_SECTOR_8 =
        0x00000100U, /*!< Sector 8  (0x00004000-0x000047FF) */
    DL_GSC_MAIN_FLASH_SECTOR_9 =
        0x00000200U, /*!< Sector 9  (0x00004800-0x00004FFF) */
    DL_GSC_MAIN_FLASH_SECTOR_10 =
        0x00000400U, /*!< Sector 10 (0x00005000-0x000057FF) */
    DL_GSC_MAIN_FLASH_SECTOR_11 =
        0x00000800U, /*!< Sector 11 (0x00005800-0x00005FFF) */
    DL_GSC_MAIN_FLASH_SECTOR_12 =
        0x00001000U, /*!< Sector 12 (0x00006000-0x000067FF) */
    DL_GSC_MAIN_FLASH_SECTOR_13 =
        0x00002000U, /*!< Sector 13 (0x00006800-0x00006FFF) */
    DL_GSC_MAIN_FLASH_SECTOR_14 =
        0x00004000U, /*!< Sector 14 (0x00007000-0x000077FF) */
    DL_GSC_MAIN_FLASH_SECTOR_15 =
        0x00008000U, /*!< Sector 15 (0x00007800-0x00007FFF) */
    DL_GSC_MAIN_FLASH_SECTOR_16 =
        0x00010000U, /*!< Sector 16 (0x00008000-0x000087FF) */
    DL_GSC_MAIN_FLASH_SECTOR_17 =
        0x00020000U, /*!< Sector 17 (0x00008800-0x00008FFF) */
    DL_GSC_MAIN_FLASH_SECTOR_18 =
        0x00040000U, /*!< Sector 18 (0x00009000-0x000097FF) */
    DL_GSC_MAIN_FLASH_SECTOR_19 =
        0x00080000U, /*!< Sector 19 (0x00009800-0x00009FFF) */
    DL_GSC_MAIN_FLASH_SECTOR_20 =
        0x00100000U, /*!< Sector 20 (0x0000A000-0x0000A7FF) */
    DL_GSC_MAIN_FLASH_SECTOR_21 =
        0x00200000U, /*!< Sector 21 (0x0000A800-0x0000AFFF) */
    DL_GSC_MAIN_FLASH_SECTOR_22 =
        0x00400000U, /*!< Sector 22 (0x0000B000-0x0000B7FF) */
    DL_GSC_MAIN_FLASH_SECTOR_23 =
        0x00800000U, /*!< Sector 23 (0x0000B800-0x0000BFFF) */
    DL_GSC_MAIN_FLASH_SECTOR_24 =
        0x01000000U, /*!< Sector 24 (0x0000C000-0x0000C7FF) */
    DL_GSC_MAIN_FLASH_SECTOR_25 =
        0x02000000U, /*!< Sector 25 (0x0000C800-0x0000CFFF) */
    DL_GSC_MAIN_FLASH_SECTOR_26 =
        0x04000000U, /*!< Sector 26 (0x0000D000-0x0000D7FF) */
    DL_GSC_MAIN_FLASH_SECTOR_27 =
        0x08000000U, /*!< Sector 27 (0x0000D800-0x0000DFFF) */
    DL_GSC_MAIN_FLASH_SECTOR_28 =
        0x10000000U, /*!< Sector 28 (0x0000E000-0x0000E7FF) */
    DL_GSC_MAIN_FLASH_SECTOR_29 =
        0x20000000U, /*!< Sector 29 (0x0000E800-0x0000EFFF) */
    DL_GSC_MAIN_FLASH_SECTOR_30 =
        0x40000000U, /*!< Sector 30 (0x0000F000-0x0000F7FF) */
    DL_GSC_MAIN_FLASH_SECTOR_31 =
        0x80000000U, /*!< Sector 31 (0x0000F800-0x0000FFFF) */
    DL_GSC_MAIN_FLASH_ALL_SECTORS = 0xFFFFFFFFU /*!< All sectors */
} DL_GSC_MainFlashSector;

/**
 * @brief Helper macro to create sector ranges
 * @param start  Starting sector number (0-31)
 * @param end    Ending sector number (0-31)
 * @return Mask representing the sector range
 */
#define DL_GSC_MAIN_FLASH_SECTOR_RANGE(start, end) \
    ((DL_GSC_MAIN_FLASH_ALL_SECTORS << (start)) &  \
        (DL_GSC_MAIN_FLASH_ALL_SECTORS >> (31 - (end))))

/**
 * @brief Configure main flash write protection for specified bank
 *
 * Configures write protection for main flash memory sectors. Each sector is 2KB.
 * WEPROTA0/WEPROTB0 controls sectors 0-31
 * WEPROTA1/WEPROTB1 controls sectors 32-63
 *
 * @param[in] gsc       Pointer to the GSC peripheral register block
 * @param[in] bank      Main flash bank to configure (Bank A or Bank B)
 * @param[in] sector0   Write protection mask for sectors 0-31 (WEPROTA0/WEPROTB0)
 * @param[in] sector1   Write protection mask for sectors 32-63 (WEPROTA1/WEPROTB1)
 *
 * Each bit in the sector masks corresponds to one 2KB sector:
 * - 0: Sector is not write protected
 * - 1: Sector is write protected
 *
 * @note Once a sector is write protected, it cannot be written until device reset
 *
 * Example usage:
 * @code
 * // Protect sectors 0 and 1 in lower half
 * uint32_t lower = DL_GSC_MAIN_FLASH_SECTOR_0 | DL_GSC_MAIN_FLASH_SECTOR_1;
 * // Protect sector 32 in upper half
 * uint32_t upper = DL_GSC_MAIN_FLASH_SECTOR_0; // First sector in upper half
 * DL_GSC_configureMainFlashWriteProtect(gsc, DL_GSC_MAIN_FLASH_BANK_A, lower, upper);
 * @endcode
 */
void DL_GSC_configureMainFlashWriteProtect(GSC_Regs* gsc,
    DL_GSC_MainFlashBank bank, uint32_t sector0, uint32_t sector1);

/**
 * @brief Get main flash write protection status for specified bank
 *
 * @param[in] gsc       Pointer to the GSC peripheral register block
 * @param[in] bank      Main flash bank to check (Bank A or Bank B)
 * @param[out] sector0  Pointer to store sectors 0-31 protection status (WEPROTA0/WEPROTB0)
 * @param[out] sector1  Pointer to store sectors 32-63 protection status (WEPROTA1/WEPROTB1)
 *
 * For returned sector masks:
 * - 0: Sector is not write protected
 * - 1: Sector is write protected
 */
void DL_GSC_getMainFlashWriteProtectStatus(GSC_Regs* gsc,
    DL_GSC_MainFlashBank bank, uint32_t* sector0, uint32_t* sector1);

/**
 * @brief Configure write protection for NONMAIN flash region of a specific bank
 *
 * FPC_WEPROTNONMAIN0 protects BANK0 NONMAIN sectors (0x80100800-0x80101FFF).
 * FPC_WEPROTNONMAIN1 protects BANK1 NONMAIN sectors (0x80102800-0x80103FFF).
 * Each register has 4 bits, one per 2KB sector.
 *
 * @param[in] gsc       Pointer to the GSC peripheral register block
 * @param[in] bank      Flash bank to configure (Bank A or Bank B)
 * @param[in] sectors   Write protection mask for sectors [3:0], 1 bit per 2KB sector
 *
 * - 0: Sector is not write protected
 * - 1: Sector is write protected
 *
 * @note Once a sector is write protected, it cannot be written until device reset
 *
 * Example usage:
 * @code
 * // Protect first sector in NONMAIN region of Bank A
 * DL_GSC_configureNONMAINWriteProtect(gsc, DL_GSC_MAIN_FLASH_BANK_A, 0x1);
 * @endcode
 */
void DL_GSC_configureNONMAINWriteProtect(
    GSC_Regs* gsc, DL_GSC_MainFlashBank bank, uint32_t sectors);

/**
 * @brief Get write protection status for NONMAIN flash region of a specific bank
 *
 * @param[in] gsc   Pointer to the GSC peripheral register block
 * @param[in] bank  Flash bank to check (Bank A or Bank B)
 * @return uint32_t Sector protection mask [3:0], 1 bit per 2KB sector
 *
 * - 0: Sector is not write protected
 * - 1: Sector is write protected
 */
uint32_t DL_GSC_getNONMAINWriteProtectStatus(
    GSC_Regs* gsc, DL_GSC_MainFlashBank bank);

/**
 * @brief Configure write protection for Data Flash
 *
 * @param[in] gsc       Pointer to the GSC peripheral register block
 * @param[in] sectors   Write protection mask for data flash sectors
 */
__STATIC_INLINE void DL_GSC_configureDataFlashWriteProtect(
    GSC_Regs* gsc, uint32_t sectors)
{
    gsc->FPC_WEPROTA_DFLASH = sectors;
}

/**
 * @brief Configure security attributes for Data Flash
 *
 * @param[in] gsc       Pointer to the GSC peripheral register block
 * @param[in] secMask   Security attributes mask for data flash sectors
 */
__STATIC_INLINE void DL_GSC_configureDataFlashSecurity(
    GSC_Regs* gsc, uint32_t secMask)
{
    gsc->FPC_SECATTRIBA_DFLASH = secMask;
}

/**
 * @brief Configure security attributes for Data Flash ENGR region
 *
 * @param[in] gsc       Pointer to the GSC peripheral register block
 * @param[in] secMask   Security attributes mask for ENGR data flash sectors
 */
__STATIC_INLINE void DL_GSC_configureDataFlashENGRSecurity(
    GSC_Regs* gsc, uint32_t secMask)
{
    gsc->FPC_ENGR_SECATTRIB_DFLASH = secMask;
}

/**
 * @brief Configure security attributes for Data Flash NONMAIN region
 *
 * @param[in] gsc       Pointer to the GSC peripheral register block
 * @param[in] secMask   Security attributes mask for NONMAIN data flash sectors
 */
__STATIC_INLINE void DL_GSC_configureDataFlashNONMAINSecurity(
    GSC_Regs* gsc, uint32_t secMask)
{
    gsc->FPC_NONMAIN_SECATTRIB_DFLASH = secMask;
}

/**
 * @brief Configure security attributes for Non-Main Flash
 *
 * @param[in] gsc       Pointer to the GSC peripheral register block
 * @param[in] secMask   Security attributes mask for Non-Main Flash sectors (bits[3:0])
 */
__STATIC_INLINE void DL_GSC_configureNonMainFlashSecurity(
    GSC_Regs* gsc, uint32_t secMask)
{
    // Only lowest 4 bits are used since Non-Main Flash has 4 sectors
    gsc->FPC_NONMAIN_SECATTRIB0 = secMask & 0xFU;
}

/**
 * @brief Configure privilege attributes for Non-Main Flash
 *
 * @param[in] gsc       Pointer to the GSC peripheral register block
 * @param[in] privMask  Privilege attributes mask for Non-Main Flash sectors (bits[3:0])
 */
__STATIC_INLINE void DL_GSC_configureNonMainFlashPrivilege(
    GSC_Regs* gsc, uint32_t privMask)
{
    // Only lowest 4 bits are used since Non-Main Flash has 4 sectors
    gsc->FPC_NONMAIN_PRIVATTRIB0 = privMask & 0xFU;
}

/**
 * @brief Configure privilege attributes for Data Flash
 *
 * @param[in] gsc       Pointer to the GSC peripheral register block
 * @param[in] privMask  Privilege attributes mask for data flash sectors
 */
__STATIC_INLINE void DL_GSC_configureDataFlashPrivilege(
    GSC_Regs* gsc, uint32_t privMask)
{
    gsc->FPC_PRIVATTRIBA_DFLASH = privMask;
}

/**
 * @brief Configure privilege attributes for Data Flash NONMAIN region
 *
 * @param[in] gsc       Pointer to the GSC peripheral register block
 * @param[in] privMask  Privilege attributes mask for NONMAIN data flash sectors
 */
__STATIC_INLINE void DL_GSC_configureDataFlashNONMAINPrivilege(
    GSC_Regs* gsc, uint32_t privMask)
{
    gsc->FPC_NONMAIN_PRIVATTRIB_DFLASH = privMask;
}

/**
 * @brief Configure privilege attributes for Data Flash ENGR region
 *
 * @param[in] gsc       Pointer to the GSC peripheral register block
 * @param[in] privMask  Privilege attributes mask for ENGR data flash sectors
 */
__STATIC_INLINE void DL_GSC_configureDataFlashENGRPrivilege(
    GSC_Regs* gsc, uint32_t privMask)
{
    gsc->FPC_ENGR_PRIVATTRIB_DFLASH = privMask;
}

/**
 * @brief Configure write protection for Data Flash NONMAIN region
 *
 * @param[in] gsc       Pointer to the GSC peripheral register block
 * @param[in] sectors   Write protection mask for NONMAIN data flash sectors
 */
__STATIC_INLINE void DL_GSC_configureDataFlashNONMAINWriteProtect(
    GSC_Regs* gsc, uint32_t sectors)
{
    gsc->FPC_WEPROT_NONMAIN_DFLASH = sectors;
}

/**
 * @brief Configure write protection for Data Flash ENGR region
 *
 * @param[in] gsc       Pointer to the GSC peripheral register block
 * @param[in] sectors   Write protection mask for ENGR data flash sectors
 */
__STATIC_INLINE void DL_GSC_configureDataFlashENGRWriteProtect(
    GSC_Regs* gsc, uint32_t sectors)
{
    gsc->FPC_WEPROT_ENGR_DFLASH = sectors;
}

/**
 * @brief Get write protection status for Data Flash
 *
 * @param[in] gsc       Pointer to the GSC peripheral register block
 * @return uint32_t     Current write protection mask for data flash sectors
 */
__STATIC_INLINE uint32_t DL_GSC_getDataFlashWriteProtectStatus(GSC_Regs* gsc)
{
    return gsc->FPC_WEPROTA_DFLASH;
}

/**
 * @brief Get write protection status for Data Flash NONMAIN region
 *
 * @param[in] gsc       Pointer to the GSC peripheral register block
 * @return uint32_t     Current write protection mask for NONMAIN region
 */
__STATIC_INLINE uint32_t DL_GSC_getDataFlashNONMAINWriteProtectStatus(
    GSC_Regs* gsc)
{
    return gsc->FPC_WEPROT_NONMAIN_DFLASH;
}

/**
 * @brief Get write protection status for Data Flash ENGR region
 *
 * @param[in] gsc       Pointer to the GSC peripheral register block
 * @return uint32_t     Current write protection mask for ENGR region
 */
__STATIC_INLINE uint32_t DL_GSC_getDataFlashENGRWriteProtectStatus(
    GSC_Regs* gsc)
{
    return gsc->FPC_WEPROT_ENGR_DFLASH;
}

/**
 * @brief Configure security attributes for main flash regions
 *
 * @param[in] gsc       Pointer to the GSC peripheral register block
 * @param[in] bank      Main flash bank to configure (Bank A or Bank B)
 * @param[in] sector0   Security mask for first 64KB of bank (SECATTRIBxA: 32 sectors × 2KB, 1 bit/sector)
 * @param[in] sector1   Security mask for 64KB-512KB of bank (SECATTRIBxB: each bit covers 16KB)
 *
 * Each bit in the sector masks corresponds to one 2KB sector:
 * - 0: Non-secure access allowed
 * - 1: Secure access only
 */
void DL_GSC_configureMainFlashSecurity(GSC_Regs* gsc,
    DL_GSC_MainFlashBank bank, uint32_t sector0, uint32_t sector1);

/**
 * @brief Get security attributes status for main flash regions
 *
 * @param[in] gsc       Pointer to the GSC peripheral register block
 * @param[in] bank      Main flash bank to check (Bank A or Bank B)
 * @param[out] sector0  Pointer to store first 64KB security status (SECATTRIBxA: 32 sectors × 2KB)
 * @param[out] sector1  Pointer to store 64KB-512KB security status (SECATTRIBxB: coarser granularity)
 */
void DL_GSC_getMainFlashSecurityStatus(GSC_Regs* gsc,
    DL_GSC_MainFlashBank bank, uint32_t* sector0, uint32_t* sector1);

/**
 * @brief Configure privilege attributes for main flash regions
 *
 * @param[in] gsc       Pointer to the GSC peripheral register block
 * @param[in] bank      Main flash bank to configure (Bank A or Bank B)
 * @param[in] sector0   Privilege mask for sectors 0-31 (PRIVATTRIBA0/B0)
 * @param[in] sector1   Privilege mask for sectors 32-63 (PRIVATTRIBA1/B1)
 *
 * Each bit in the sector masks corresponds to one 2KB sector:
 * - 0: Unprivileged access allowed
 * - 1: Privileged access only
 */
void DL_GSC_configureMainFlashPrivilege(GSC_Regs* gsc,
    DL_GSC_MainFlashBank bank, uint32_t sector0, uint32_t sector1);

/**
 * @brief Get privilege attributes status for main flash regions
 *
 * @param[in] gsc       Pointer to the GSC peripheral register block
 * @param[in] bank      Main flash bank to check (Bank A or Bank B)
 * @param[out] sector0  Pointer to store sectors 0-31 privilege status
 * @param[out] sector1  Pointer to store sectors 32-63 privilege status
 */
void DL_GSC_getMainFlashPrivilegeStatus(GSC_Regs* gsc,
    DL_GSC_MainFlashBank bank, uint32_t* sector0, uint32_t* sector1);

/**
 * @brief GSC Lock/Commit Configuration Structure
 * Set field to true to lock/commit the corresponding configuration
 */
typedef struct {
    bool
        attribViolConfig; /*!< Lock/Commit attribute violation configuration */
    bool
        ppcAttrib; /*!< Lock/Commit PPC (Peripheral Protection Controller) attributes */
    bool
        spcAttrib; /*!< Lock/Commit SPC (SRAM Protection Controller) attributes */
    bool
        fppcAttrib; /*!< Lock/Commit FPPC (Flash Protection Controller) attributes */
    bool vtor; /*!< Lock/Commit Vector Table Offset Register configuration */
    bool dmaTrigSel; /*!< Lock/Commit DMA trigger selection */
    bool dtbMuxSel;  /*!< Lock/Commit DTB MUX selection */
} DL_GSC_LockConfig;

/**
 * @brief Configure hide protection region for flash
 *
 * Configures hide protection for a region of flash sectors. In single-bank mode,
 * only FPC_HDPPROT0_CONFIG is used. In dual-bank mode, both FPC_HDPPROT0_CONFIG
 * and FPC_HDPPROT1_CONFIG are available.
 *
 * Each sector is 2KB. Hide protection can be set at sector level but must be
 * managed carefully when overlapping with other protection mechanisms that
 * operate at 8KB (4-sector) page boundaries.
 *
 * @param[in] gsc       Pointer to the GSC peripheral
 * @param[in] startSec  Starting sector number (0-255) for hide protection
 * @param[in] endSec    Ending sector number (0-255) for hide protection
 * @param[in] bank      0: Configure Bank 0, 1: Configure Bank 1 (only valid in dual-bank mode)
 *
 * @note In single-bank mode, the bank parameter is ignored and FPC_HDPPROT0_CONFIG
 *       is always used.
 * @note It is the application's responsibility to ensure hide protection regions
 *       are properly aligned when overlapping with other protection mechanisms
 *       that operate at 8KB page boundaries.
 *
 * @return bool Returns true if configuration is valid, false otherwise
 */
bool DL_GSC_configureHDPRegion(
    GSC_Regs* gsc, uint8_t startSec, uint8_t endSec, uint8_t bank);

/**
 * @brief Enable/Disable HDP access for flash
 *
 * Controls access to hide protected regions. In single-bank mode, setting
 * access control affects both regions regardless of which control bit is used.
 *
 * @param[in] gsc     Pointer to the GSC peripheral
 * @param[in] enable  true: Enable HDP access, false: Disable HDP access
 * @param[in] bank    0: Configure Bank 0, 1: Configure Bank 1 (only valid in dual-bank mode)
 *
 * @note In single-bank mode, setting either bank's access control will affect both regions
 */
void DL_GSC_setHDPAccess(GSC_Regs* gsc, bool enable, uint8_t bank);

/**
 * @brief Enable Flash Hide Protection (HDP) mode
 *
 * @param[in] gsc  Pointer to the GSC peripheral
 */
__STATIC_INLINE void DL_GSC_enableHDPMode(GSC_Regs* gsc)
{
    gsc->FPC_HDPEN_CONTROL |= GSC_FPC_HDPEN_CONTROL_HDPEN_MASK;
}

/**
 * @brief Disable Flash Hide Protection (HDP) mode
 *
 * @param[in] gsc  Pointer to the GSC peripheral
 */
__STATIC_INLINE void DL_GSC_disableHDPMode(GSC_Regs* gsc)
{
    gsc->FPC_HDPEN_CONTROL &= ~GSC_FPC_HDPEN_CONTROL_HDPEN_MASK;
}

/**
 * @brief Enable HDP access to NONMAIN region in Bank 0
 *
 * @param[in] gsc  Pointer to the GSC peripheral
 */
__STATIC_INLINE void DL_GSC_enableNONMAINBank0HDPAccess(GSC_Regs* gsc)
{
    gsc->FPC_NONMAIN0_HDPPROT_CONTROL &=
        ~GSC_FPC_NONMAIN0_HDPPROT_CONTROL_HDPROTACCDIS_MASK;
}

/**
 * @brief Disable HDP access to NONMAIN region in Bank 0
 *
 * @param[in] gsc  Pointer to the GSC peripheral
 */
__STATIC_INLINE void DL_GSC_disableNONMAINBank0HDPAccess(GSC_Regs* gsc)
{
    gsc->FPC_NONMAIN0_HDPPROT_CONTROL |=
        GSC_FPC_NONMAIN0_HDPPROT_CONTROL_HDPROTACCDIS_MASK;
}

/**
 * @brief Enable HDP access to NONMAIN region in Bank 1
 *
 * @param[in] gsc  Pointer to the GSC peripheral
 */
__STATIC_INLINE void DL_GSC_enableNONMAINBank1HDPAccess(GSC_Regs* gsc)
{
    gsc->FPC_NONMAIN1_HDPPROT_CONTROL &=
        ~GSC_FPC_NONMAIN1_HDPPROT_CONTROL_HDPROTACCDIS_MASK;
}

/**
 * @brief Disable HDP access to NONMAIN region in Bank 1
 *
 * @param[in] gsc  Pointer to the GSC peripheral
 */
__STATIC_INLINE void DL_GSC_disableNONMAINBank1HDPAccess(GSC_Regs* gsc)
{
    gsc->FPC_NONMAIN1_HDPPROT_CONTROL |=
        GSC_FPC_NONMAIN1_HDPPROT_CONTROL_HDPROTACCDIS_MASK;
}

/**
 * @brief Enable HDP access to TRIM region in Bank 0
 *
 * @param[in] gsc  Pointer to the GSC peripheral
 */
__STATIC_INLINE void DL_GSC_enableTRIMBank0HDPAccess(GSC_Regs* gsc)
{
    gsc->FPC_TRIM0_HDPPROT_CONTROL &=
        ~GSC_FPC_TRIM0_HDPPROT_CONTROL_HDPROTACCDIS_MASK;
}

/**
 * @brief Disable HDP access to TRIM region in Bank 0
 *
 * @param[in] gsc  Pointer to the GSC peripheral
 */
__STATIC_INLINE void DL_GSC_disableTRIMBank0HDPAccess(GSC_Regs* gsc)
{
    gsc->FPC_TRIM0_HDPPROT_CONTROL |=
        GSC_FPC_TRIM0_HDPPROT_CONTROL_HDPROTACCDIS_MASK;
}

/**
 * @brief Enable HDP access to TRIM region in Bank 1
 *
 * @param[in] gsc  Pointer to the GSC peripheral
 */
__STATIC_INLINE void DL_GSC_enableTRIMBank1HDPAccess(GSC_Regs* gsc)
{
    gsc->FPC_TRIM1_HDPPROT_CONTROL &=
        ~GSC_FPC_TRIM1_HDPPROT_CONTROL_HDPROTACCDIS_MASK;
}

/**
 * @brief Disable HDP access to TRIM region in Bank 1
 *
 * @param[in] gsc  Pointer to the GSC peripheral
 */
__STATIC_INLINE void DL_GSC_disableTRIMBank1HDPAccess(GSC_Regs* gsc)
{
    gsc->FPC_TRIM1_HDPPROT_CONTROL |=
        GSC_FPC_TRIM1_HDPPROT_CONTROL_HDPROTACCDIS_MASK;
}

/**
 * @brief Enable HDP access to ENGR region in Bank 0
 *
 * @param[in] gsc  Pointer to the GSC peripheral
 */
__STATIC_INLINE void DL_GSC_enableENGRBank0HDPAccess(GSC_Regs* gsc)
{
    gsc->FPC_ENGR0_HDPPROT_CONTROL &=
        ~GSC_FPC_ENGR0_HDPPROT_CONTROL_HDPROTACCDIS_MASK;
}

/**
 * @brief Disable HDP access to ENGR region in Bank 0
 *
 * @param[in] gsc  Pointer to the GSC peripheral
 */
__STATIC_INLINE void DL_GSC_disableENGRBank0HDPAccess(GSC_Regs* gsc)
{
    gsc->FPC_ENGR0_HDPPROT_CONTROL |=
        GSC_FPC_ENGR0_HDPPROT_CONTROL_HDPROTACCDIS_MASK;
}

/**
 * @brief Enable HDP access to ENGR region in Bank 1
 *
 * @param[in] gsc  Pointer to the GSC peripheral
 */
__STATIC_INLINE void DL_GSC_enableENGRBank1HDPAccess(GSC_Regs* gsc)
{
    gsc->FPC_ENGR1_HDPPROT_CONTROL &=
        ~GSC_FPC_ENGR1_HDPPROT_CONTROL_HDPROTACCDIS_MASK;
}

/**
 * @brief Disable HDP access to ENGR region in Bank 1
 *
 * @param[in] gsc  Pointer to the GSC peripheral
 */
__STATIC_INLINE void DL_GSC_disableENGRBank1HDPAccess(GSC_Regs* gsc)
{
    gsc->FPC_ENGR1_HDPPROT_CONTROL |=
        GSC_FPC_ENGR1_HDPPROT_CONTROL_HDPROTACCDIS_MASK;
}

/**
 * @brief Configure hide protection region for data flash
 *
 * Configures hide protection for a region of data flash sectors.
 * Each sector is 2KB. Hide protection can be set at sector level but must be
 * managed carefully when overlapping with other protection mechanisms that
 * operate at 8KB (4-sector) page boundaries.
 *
 * @param[in] gsc       Pointer to the GSC peripheral
 * @param[in] startSec  Starting sector number for hide protection
 * @param[in] endSec    Ending sector number for hide protection
 *
 * @note It is the application's responsibility to ensure hide protection regions
 *       are properly aligned when overlapping with other protection mechanisms
 *       that operate at 8KB page boundaries.
 *
 * @return bool Returns true if configuration is valid, false otherwise
 */
bool DL_GSC_configureDataBankHDPRegion(
    GSC_Regs* gsc, uint8_t startSec, uint8_t endSec);

// Data Bank HDP Control
/**
 * @brief Enable HDP access to Data Bank region
 *
 * @param[in] gsc  Pointer to the GSC peripheral
 */
__STATIC_INLINE void DL_GSC_enableDataBankHDPAccess(GSC_Regs* gsc)
{
    gsc->FPC_HDPPROT_DBANK_CONTROL &=
        ~GSC_FPC_HDPPROT_DBANK_CONTROL_HDPPROTACCDIS_MASK;
}

/**
 * @brief Disable HDP access to Data Bank region
 *
 * @param[in] gsc  Pointer to the GSC peripheral
 */
__STATIC_INLINE void DL_GSC_disableDataBankHDPAccess(GSC_Regs* gsc)
{
    gsc->FPC_HDPPROT_DBANK_CONTROL |=
        GSC_FPC_HDPPROT_DBANK_CONTROL_HDPPROTACCDIS_MASK;
}

// Data Bank HDP Enable Control
/**
 * @brief Enable HDP mode for Data Bank
 *
 * @param[in] gsc  Pointer to the GSC peripheral
 */
__STATIC_INLINE void DL_GSC_enableDataBankHDPMode(GSC_Regs* gsc)
{
    gsc->FPC_HDPEN_DBANK_CONTROL |= GSC_FPC_HDPEN_DBANK_CONTROL_HDPEN_MASK;
}

/**
 * @brief Disable HDP mode for Data Bank
 *
 * @param[in] gsc  Pointer to the GSC peripheral
 */
__STATIC_INLINE void DL_GSC_disableDataBankHDPMode(GSC_Regs* gsc)
{
    gsc->FPC_HDPEN_DBANK_CONTROL &= ~GSC_FPC_HDPEN_DBANK_CONTROL_HDPEN_MASK;
}

// Data Bank NONMAIN HDP Control
/**
 * @brief Enable HDP access to NONMAIN region in Data Bank
 *
 * @param[in] gsc  Pointer to the GSC peripheral
 */
__STATIC_INLINE void DL_GSC_enableDataBankNONMAINHDPAccess(GSC_Regs* gsc)
{
    gsc->FPC_NONMAIN_HDPPROT_DBANK_CONTROL &=
        ~GSC_FPC_NONMAIN_HDPPROT_DBANK_CONTROL_HDPROTACCDIS_MASK;
}

/**
 * @brief Disable HDP access to NONMAIN region in Data Bank
 *
 * @param[in] gsc  Pointer to the GSC peripheral
 */
__STATIC_INLINE void DL_GSC_disableDataBankNONMAINHDPAccess(GSC_Regs* gsc)
{
    gsc->FPC_NONMAIN_HDPPROT_DBANK_CONTROL |=
        GSC_FPC_NONMAIN_HDPPROT_DBANK_CONTROL_HDPROTACCDIS_MASK;
}

// Data Bank TRIM HDP Control
/**
 * @brief Enable HDP access to TRIM region in Data Bank
 *
 * @param[in] gsc  Pointer to the GSC peripheral
 */
__STATIC_INLINE void DL_GSC_enableDataBankTRIMHDPAccess(GSC_Regs* gsc)
{
    gsc->FPC_TRIM_HDPPROT_DBANK_CONTROL &=
        ~GSC_FPC_TRIM_HDPPROT_DBANK_CONTROL_HDPROTACCDIS_MASK;
}

/**
 * @brief Disable HDP access to TRIM region in Data Bank
 *
 * @param[in] gsc  Pointer to the GSC peripheral
 */
__STATIC_INLINE void DL_GSC_disableDataBankTRIMHDPAccess(GSC_Regs* gsc)
{
    gsc->FPC_TRIM_HDPPROT_DBANK_CONTROL |=
        GSC_FPC_TRIM_HDPPROT_DBANK_CONTROL_HDPROTACCDIS_MASK;
}

// Data Bank ENGR HDP Control
/**
 * @brief Enable HDP access to ENGR region in Data Bank
 *
 * @param[in] gsc  Pointer to the GSC peripheral
 */
__STATIC_INLINE void DL_GSC_enableDataBankENGRHDPAccess(GSC_Regs* gsc)
{
    gsc->FPC_ENGR_HDPPROT_DBANK_CONTROL &=
        ~GSC_FPC_ENGR_HDPPROT_DBANK_CONTROL_HDPROTACCDIS_MASK;
}

/**
 * @brief Disable HDP access to ENGR region in Data Bank
 *
 * @param[in] gsc  Pointer to the GSC peripheral
 */
__STATIC_INLINE void DL_GSC_disableDataBankENGRHDPAccess(GSC_Regs* gsc)
{
    gsc->FPC_ENGR_HDPPROT_DBANK_CONTROL |=
        GSC_FPC_ENGR_HDPPROT_DBANK_CONTROL_HDPROTACCDIS_MASK;
}

/**
 *  @brief set VTOR for NS Application Image
 *
 *
 *  @param[in] gsc      Pointer to the register overlay for the peripheral
 *  @param[in] addr_ns  NS addr where NS applications Vector Table resides
 *
 *  @return    void
 */
__STATIC_INLINE void DL_GSC_setVTOR_NS(GSC_Regs* gsc, uint32_t addr_ns)
{
    (gsc->VTOR_NS = addr_ns);
}

/**
 *  @brief set VTOR for S Application Image
 *
 *
 *  @param[in] gsc      Pointer to the register overlay for the peripheral
 *  @param[in] addr_s   Secure addr where S applications Vector Table resides
 *
 *  @return    void
 */
__STATIC_INLINE void DL_GSC_setVTOR_S(GSC_Regs* gsc, uint32_t addr_s)
{
    (gsc->VTOR_S = addr_s);
}

/**
 * @brief Allow secure access to non-secure SRAM regions
 *
 * Configures SRAM protection control to allow secure code to access
 * non-secure SRAM regions by disabling bus fault and NMI generation on violations.
 *
 * @param[in] gsc  Pointer to the GSC peripheral
 */
__STATIC_INLINE void DL_GSC_allowSPCSecureAccessToNSRAM(GSC_Regs* gsc)
{
    gsc->SPC_ATTRIBVIOLS_CONFIG &= ~GSC_SPC_ATTRIBVIOLS_CONFIG_SECVIOL_MASK;
}

/**
 * @brief Block secure access to non-secure SRAM regions
 *
 * Configures SRAM protection control to block secure code from accessing
 * non-secure SRAM regions by enabling bus fault and NMI generation on violations.
 *
 * @param[in] gsc  Pointer to the GSC peripheral
 */
__STATIC_INLINE void DL_GSC_blockSPCSecureAccessToNSRAM(GSC_Regs* gsc)
{
    gsc->SPC_ATTRIBVIOLS_CONFIG |= GSC_SPC_ATTRIBVIOLS_CONFIG_SECVIOL_MASK;
}

/**
 * @brief Allow secure access to non-secure flash regions
 *
 * Configures flash protection control to allow secure code to access
 * non-secure flash regions by disabling bus fault and NMI generation on violations.
 *
 * @param[in] gsc  Pointer to the GSC peripheral
 */
__STATIC_INLINE void DL_GSC_allowFPCSecureAccessToNSFlash(GSC_Regs* gsc)
{
    gsc->FPC_ATTRIBVIOLS_CONFIG &= ~GSC_FPC_ATTRIBVIOLS_CONFIG_SECVIOL_MASK;
}

/**
 * @brief Block secure access to non-secure flash regions
 *
 * Configures flash protection control to block secure code from accessing
 * non-secure flash regions by enabling bus fault and NMI generation on violations.
 *
 * @param[in] gsc  Pointer to the GSC peripheral
 */
__STATIC_INLINE void DL_GSC_blockFPCSecureAccessToNSFlash(GSC_Regs* gsc)
{
    gsc->FPC_ATTRIBVIOLS_CONFIG |= GSC_FPC_ATTRIBVIOLS_CONFIG_SECVIOL_MASK;
}

/**
 * @brief Allow secure access to non-secure peripherals
 *
 * Configures peripheral protection control to allow secure code to access
 * non-secure peripherals by disabling bus fault and NMI generation on violations.
 *
 * @param[in] gsc  Pointer to the GSC peripheral
 */
__STATIC_INLINE void DL_GSC_allowPPCSecureAccessToNSPeripheral(GSC_Regs* gsc)
{
    gsc->PPC_ATTRIBVIOLS_CONFIG &= ~GSC_PPC_ATTRIBVIOLS_CONFIG_SECVIOL_MASK;
}

/**
 * @brief Block secure access to non-secure peripherals
 *
 * Configures peripheral protection control to block secure code from accessing
 * non-secure peripherals by enabling bus fault and NMI generation on violations.
 *
 * @param[in] gsc  Pointer to the GSC peripheral
 */
__STATIC_INLINE void DL_GSC_blockPPCSecureAccessToNSPeripheral(GSC_Regs* gsc)
{
    gsc->PPC_ATTRIBVIOLS_CONFIG |= GSC_PPC_ATTRIBVIOLS_CONFIG_SECVIOL_MASK;
}

/**
 * @brief Allow privileged access to non-privileged SRAM regions
 *
 * Configures SRAM protection control to allow privileged code to access
 * non-privileged SRAM regions by disabling bus fault generation on violations.
 *
 * @param[in] gsc  Pointer to the GSC peripheral
 */
__STATIC_INLINE void DL_GSC_allowSPCPrivilegeAccessToNPSRAM(GSC_Regs* gsc)
{
    gsc->SPC_ATTRIBVIOLP_CONFIG &= ~GSC_SPC_ATTRIBVIOLP_CONFIG_PRIVVIOL_MASK;
}

/**
 * @brief Block privileged access to non-privileged SRAM regions
 *
 * Configures SRAM protection control to block privileged code from accessing
 * non-privileged SRAM regions by enabling bus fault generation on violations.
 *
 * @param[in] gsc  Pointer to the GSC peripheral
 */
__STATIC_INLINE void DL_GSC_blockSPCPrivilegeAccessToNPSRAM(GSC_Regs* gsc)
{
    gsc->SPC_ATTRIBVIOLP_CONFIG |= GSC_SPC_ATTRIBVIOLP_CONFIG_PRIVVIOL_MASK;
}

/**
 * @brief Allow privileged access to non-privileged flash regions
 *
 * Configures flash protection control to allow privileged code to access
 * non-privileged flash regions by disabling bus fault generation on violations.
 *
 * @param[in] gsc  Pointer to the GSC peripheral
 */
__STATIC_INLINE void DL_GSC_allowFPCPrivilegeAccessToNPFlash(GSC_Regs* gsc)
{
    gsc->FPC_ATTRIBVIOLP_CONFIG &= ~GSC_FPC_ATTRIBVIOLP_CONFIG_PRIVVIOL_MASK;
}

/**
 * @brief Block privileged access to non-privileged flash regions
 *
 * Configures flash protection control to block privileged code from accessing
 * non-privileged flash regions by enabling bus fault generation on violations.
 *
 * @param[in] gsc  Pointer to the GSC peripheral
 */
__STATIC_INLINE void DL_GSC_blockFPCPrivilegeAccessToNPFlash(GSC_Regs* gsc)
{
    gsc->FPC_ATTRIBVIOLP_CONFIG |= GSC_FPC_ATTRIBVIOLP_CONFIG_PRIVVIOL_MASK;
}

/**
 * @brief Allow privileged access to non-privileged peripherals
 *
 * Configures peripheral protection control to allow privileged code to access
 * non-privileged peripherals by disabling bus fault generation on violations.
 *
 * @param[in] gsc  Pointer to the GSC peripheral
 */
__STATIC_INLINE void DL_GSC_allowPPCPrivilegeAccessToNPPeripheral(
    GSC_Regs* gsc)
{
    gsc->PPC_ATTRIBVIOLP_CONFIG &= ~GSC_PPC_ATTRIBVIOLP_CONFIG_PRIVVIOL_MASK;
}

/**
 * @brief Block privileged access to non-privileged peripherals
 *
 * Configures peripheral protection control to block privileged code from accessing
 * non-privileged peripherals by enabling bus fault generation on violations.
 *
 * @param[in] gsc  Pointer to the GSC peripheral
 */
__STATIC_INLINE void DL_GSC_blockPPCPrivilegeAccessToNPPeripheral(
    GSC_Regs* gsc)
{
    gsc->PPC_ATTRIBVIOLP_CONFIG |= GSC_PPC_ATTRIBVIOLP_CONFIG_PRIVVIOL_MASK;
}

/**
 * @brief UniComm Peripheral Secure Access Instance Selectors
 *
 * This enumeration defines the UniComm instances for configuring secure/non-secure access.
 * Each instance corresponds to a specific UniComm peripheral that can be configured
 * for secure or non-secure access.
 *
 * The values are mapped to the corresponding hardware register offsets defined in:
 * - GSC_PPC_SECATTRIB_UNICOMM register
 */
typedef enum {
    DL_GSC_SECURE_ACCESS_UNICOMM_UC1_0 =
        GSC_PPC_SECATTRIB_UNICOMM_SEC_UC1_0_OFS, /*!< UniComm UC1_0 secure access control */
    DL_GSC_SECURE_ACCESS_UNICOMM_UC1_1 =
        GSC_PPC_SECATTRIB_UNICOMM_SEC_UC1_1_OFS, /*!< UniComm UC1_1 secure access control */
    DL_GSC_SECURE_ACCESS_UNICOMM_UC2 =
        GSC_PPC_SECATTRIB_UNICOMM_SEC_UC2_OFS, /*!< UniComm UC2 secure access control */
    DL_GSC_SECURE_ACCESS_UNICOMM_UC15_0 =
        GSC_PPC_SECATTRIB_UNICOMM_SEC_UC15_0_OFS, /*!< UniComm UC15_0 secure access control */
    DL_GSC_SECURE_ACCESS_UNICOMM_UC15_1 =
        GSC_PPC_SECATTRIB_UNICOMM_SEC_UC15_1_OFS, /*!< UniComm UC15_1 secure access control */
    DL_GSC_SECURE_ACCESS_UNICOMM_UC12 =
        GSC_PPC_SECATTRIB_UNICOMM_SEC_UC12_OFS, /*!< UniComm UC12 secure access control */
    DL_GSC_SECURE_ACCESS_UNICOMM_UC13_0 =
        GSC_PPC_SECATTRIB_UNICOMM_SEC_UC13_0_OFS, /*!< UniComm UC13_0 secure access control */
    DL_GSC_SECURE_ACCESS_UNICOMM_UC13_1 =
        GSC_PPC_SECATTRIB_UNICOMM_SEC_UC13_1_OFS, /*!< UniComm UC13_1 secure access control */
    DL_GSC_SECURE_ACCESS_UNICOMM_UC13_2 =
        GSC_PPC_SECATTRIB_UNICOMM_SEC_UC13_2_OFS, /*!< UniComm UC13_2 secure access control */
    DL_GSC_SECURE_ACCESS_UNICOMM_UC13_3 =
        GSC_PPC_SECATTRIB_UNICOMM_SEC_UC13_3_OFS, /*!< UniComm UC13_3 secure access control */
    DL_GSC_SECURE_ACCESS_UNICOMM_UC14 =
        GSC_PPC_SECATTRIB_UNICOMM_SEC_UC14_OFS /*!< UniComm UC14 secure access control */
} DL_GSC_SECURE_ACCESS_UNICOMM;

/**
 *  @brief Allow UniComm peripheral access from secure context only
 *
 *  This function configures the specified UniComm peripheral instance to be
 *  accessible only from M33 secure execution context.
 *
 *  @param[in] gsc       Pointer to the register overlay for the GSC peripheral
 *  @param[in] instance  UniComm instance to configure context access for
 *
 *  @return    void
 */
__STATIC_INLINE void DL_GSC_allowUniCommSecureAccess(
    GSC_Regs* gsc, DL_GSC_SECURE_ACCESS_UNICOMM instance)
{
    uint32_t mask;
    switch (instance) {
        case DL_GSC_SECURE_ACCESS_UNICOMM_UC1_0:
            mask = GSC_PPC_SECATTRIB_UNICOMM_SEC_UC1_0_MASK;
            break;
        case DL_GSC_SECURE_ACCESS_UNICOMM_UC1_1:
            mask = GSC_PPC_SECATTRIB_UNICOMM_SEC_UC1_1_MASK;
            break;
        case DL_GSC_SECURE_ACCESS_UNICOMM_UC2:
            mask = GSC_PPC_SECATTRIB_UNICOMM_SEC_UC2_MASK;
            break;
        case DL_GSC_SECURE_ACCESS_UNICOMM_UC15_0:
            mask = GSC_PPC_SECATTRIB_UNICOMM_SEC_UC15_0_MASK;
            break;
        case DL_GSC_SECURE_ACCESS_UNICOMM_UC15_1:
            mask = GSC_PPC_SECATTRIB_UNICOMM_SEC_UC15_1_MASK;
            break;
        case DL_GSC_SECURE_ACCESS_UNICOMM_UC12:
            mask = GSC_PPC_SECATTRIB_UNICOMM_SEC_UC12_MASK;
            break;
        case DL_GSC_SECURE_ACCESS_UNICOMM_UC13_0:
            mask = GSC_PPC_SECATTRIB_UNICOMM_SEC_UC13_0_MASK;
            break;
        case DL_GSC_SECURE_ACCESS_UNICOMM_UC13_1:
            mask = GSC_PPC_SECATTRIB_UNICOMM_SEC_UC13_1_MASK;
            break;
        case DL_GSC_SECURE_ACCESS_UNICOMM_UC13_2:
            mask = GSC_PPC_SECATTRIB_UNICOMM_SEC_UC13_2_MASK;
            break;
        case DL_GSC_SECURE_ACCESS_UNICOMM_UC13_3:
            mask = GSC_PPC_SECATTRIB_UNICOMM_SEC_UC13_3_MASK;
            break;
        case DL_GSC_SECURE_ACCESS_UNICOMM_UC14:
            mask = GSC_PPC_SECATTRIB_UNICOMM_SEC_UC14_MASK;
            break;
        default:
            return;  // Invalid instance
    }
    gsc->PPC_SECATTRIB_UNICOMM |= mask;
}

/**
 * @brief Allow WDT peripheral access from secure context only
 *
 * @param[in] gsc      Pointer to the register overlay for the GSC peripheral
 */
__STATIC_INLINE void DL_GSC_allowWDTSecureAccess(GSC_Regs* gsc)
{
    gsc->PPC_SECATTRIB_WDT |= GSC_PPC_SECATTRIB_WDT_SEC_WWDT_MASK;
}

/**
 * @brief Allow WDT peripheral access from non-secure context
 *
 * @param[in] gsc      Pointer to the register overlay for the GSC peripheral
 */
__STATIC_INLINE void DL_GSC_allowWDTNonSecureAccess(GSC_Regs* gsc)
{
    gsc->PPC_SECATTRIB_WDT &= ~GSC_PPC_SECATTRIB_WDT_SEC_WWDT_MASK;
}

/**
 * @brief Check if WDT is configured for secure access
 *
 * @param[in] gsc      Pointer to the register overlay for the GSC peripheral
 * @return bool        Returns true if secure access is enabled, false for non-secure
 */
__STATIC_INLINE bool DL_GSC_isWDTSecureAccess(GSC_Regs* gsc)
{
    return (
        (gsc->PPC_SECATTRIB_WDT & GSC_PPC_SECATTRIB_WDT_SEC_WWDT_MASK) != 0);
}

/**
 *  @brief Allow UniComm peripheral access from non-secure context
 *
 *  This function configures the specified UniComm peripheral instance to be
 *  accessible from non-secure execution context.
 *
 *  @param[in] gsc       Pointer to the register overlay for the GSC peripheral
 *  @param[in] instance  UniComm instance to configure context access for
 *
 *  @return    void
 */
__STATIC_INLINE void DL_GSC_allowUniCommNonSecureAccess(
    GSC_Regs* gsc, DL_GSC_SECURE_ACCESS_UNICOMM instance)
{
    uint32_t mask;
    switch (instance) {
        case DL_GSC_SECURE_ACCESS_UNICOMM_UC1_0:
            mask = (GSC_PPC_SECATTRIB_UNICOMM_SEC_UC1_0_MASK);
            break;
        case DL_GSC_SECURE_ACCESS_UNICOMM_UC1_1:
            mask = GSC_PPC_SECATTRIB_UNICOMM_SEC_UC1_1_MASK;
            break;
        case DL_GSC_SECURE_ACCESS_UNICOMM_UC2:
            mask = GSC_PPC_SECATTRIB_UNICOMM_SEC_UC2_MASK;
            break;
        case DL_GSC_SECURE_ACCESS_UNICOMM_UC15_0:
            mask = GSC_PPC_SECATTRIB_UNICOMM_SEC_UC15_0_MASK;
            break;
        case DL_GSC_SECURE_ACCESS_UNICOMM_UC15_1:
            mask = GSC_PPC_SECATTRIB_UNICOMM_SEC_UC15_1_MASK;
            break;
        case DL_GSC_SECURE_ACCESS_UNICOMM_UC12:
            mask = GSC_PPC_SECATTRIB_UNICOMM_SEC_UC12_MASK;
            break;
        case DL_GSC_SECURE_ACCESS_UNICOMM_UC13_0:
            mask = GSC_PPC_SECATTRIB_UNICOMM_SEC_UC13_0_MASK;
            break;
        case DL_GSC_SECURE_ACCESS_UNICOMM_UC13_1:
            mask = GSC_PPC_SECATTRIB_UNICOMM_SEC_UC13_1_MASK;
            break;
        case DL_GSC_SECURE_ACCESS_UNICOMM_UC13_2:
            mask = GSC_PPC_SECATTRIB_UNICOMM_SEC_UC13_2_MASK;
            break;
        case DL_GSC_SECURE_ACCESS_UNICOMM_UC13_3:
            mask = GSC_PPC_SECATTRIB_UNICOMM_SEC_UC13_3_MASK;
            break;
        case DL_GSC_SECURE_ACCESS_UNICOMM_UC14:
            mask = GSC_PPC_SECATTRIB_UNICOMM_SEC_UC14_MASK;
            break;
        default:
            return;  // Invalid instance
    }
    gsc->PPC_SECATTRIB_UNICOMM &= ~mask;
}

/**
 * @brief ADC Peripheral Secure Context Access Selectors
 *
 * This enumeration defines the ADC instances for configuring secure/non-secure context access.
 * Each instance corresponds to a specific ADC peripheral that can be accessed from
 * either secure or non-secure execution context.
 */
typedef enum {
    DL_GSC_ADC_SECURE_ACCESS_ADC0 =
        GSC_PPC_SECATTRIB_ADC_SEC_ADC0_OFS, /*!< ADC0 M33 secure/non-secure context access control */
    DL_GSC_ADC_SECURE_ACCESS_ADC1 =
        GSC_PPC_SECATTRIB_ADC_SEC_ADC1_OFS /*!< ADC1 M33 secure/non-secure context access control */
} DL_GSC_ADC_SECURE_ACCESS;

/**
 * @brief Timer Peripheral Secure Context Access Selectors
 *
 * This enumeration defines the Timer instances for configuring M33 secure/non-secure context access.
 * Each instance corresponds to a specific Timer peripheral that can be accessed from
 * either secure or non-secure execution context.
 */
typedef enum {
    DL_GSC_TIMER_SECURE_ACCESS_TIMA0_0 =
        GSC_PPC_SECATTRIB_TIMER_SEC_TIMA0_0_OFS, /*!< TIMA0_0 M33 secure/non-secure context access control */
    DL_GSC_TIMER_SECURE_ACCESS_TIMA0_1 =
        GSC_PPC_SECATTRIB_TIMER_SEC_TIMA0_1_OFS, /*!< TIMA0_1 M33 secure/non-secure context access control */
    DL_GSC_TIMER_SECURE_ACCESS_TIMG4_0 =
        GSC_PPC_SECATTRIB_TIMER_SEC_TIMG4_0_OFS, /*!< TIMG4_0 M33 secure/non-secure context access control */
    DL_GSC_TIMER_SECURE_ACCESS_TIMG4_1 =
        GSC_PPC_SECATTRIB_TIMER_SEC_TIMG4_1_OFS, /*!< TIMG4_1 M33 secure/non-secure context access control */
    DL_GSC_TIMER_SECURE_ACCESS_TIMG4_2 =
        GSC_PPC_SECATTRIB_TIMER_SEC_TIMG4_2_OFS, /*!< TIMG4_2 M33 secure/non-secure context access control */
    DL_GSC_TIMER_SECURE_ACCESS_TIMG4_3 =
        GSC_PPC_SECATTRIB_TIMER_SEC_TIMG4_3_OFS, /*!< TIMG4_3 M33 secure/non-secure context access control */
    DL_GSC_TIMER_SECURE_ACCESS_TIMG12_0 =
        GSC_PPC_SECATTRIB_TIMER_SEC_TIMG12_0_OFS, /*!< TIMG12_0 M33 secure/non-secure context access control */
    DL_GSC_TIMER_SECURE_ACCESS_TIMG8_0 =
        GSC_PPC_SECATTRIB_TIMER_SEC_TIMG8_0_OFS, /*!< TIMG8_0 M33 secure/non-secure context access control */
    DL_GSC_TIMER_SECURE_ACCESS_TIMG8_1 =
        GSC_PPC_SECATTRIB_TIMER_SEC_TIMG8_1_OFS /*!< TIMG8_1 M33 secure/non-secure context access control */
} DL_GSC_TIMER_SECURE_ACCESS;

/**
 * @brief Allow ADC peripheral access from secure context only
 *
 * @param[in] gsc      Pointer to the register overlay for the GSC peripheral
 * @param[in] instance ADC instance to configure context access for
 */
__STATIC_INLINE void DL_GSC_allowADCSecureAccess(
    GSC_Regs* gsc, DL_GSC_ADC_SECURE_ACCESS instance)
{
    uint32_t mask;
    switch (instance) {
        case DL_GSC_ADC_SECURE_ACCESS_ADC0:
            mask = GSC_PPC_SECATTRIB_ADC_SEC_ADC0_MASK;
            break;
        case DL_GSC_ADC_SECURE_ACCESS_ADC1:
            mask = GSC_PPC_SECATTRIB_ADC_SEC_ADC1_MASK;
            break;
        default:
            return;
    }
    gsc->PPC_SECATTRIB_ADC |= mask;
}

/**
 * @brief Allow ADC peripheral access from non-secure context
 *
 * @param[in] gsc      Pointer to the register overlay for the GSC peripheral
 * @param[in] instance ADC instance to configure context access for
 */
__STATIC_INLINE void DL_GSC_allowADCNonSecureAccess(
    GSC_Regs* gsc, DL_GSC_ADC_SECURE_ACCESS instance)
{
    uint32_t mask;
    switch (instance) {
        case DL_GSC_ADC_SECURE_ACCESS_ADC0:
            mask = GSC_PPC_SECATTRIB_ADC_SEC_ADC0_MASK;
            break;
        case DL_GSC_ADC_SECURE_ACCESS_ADC1:
            mask = GSC_PPC_SECATTRIB_ADC_SEC_ADC1_MASK;
            break;
        default:
            return;
    }
    gsc->PPC_SECATTRIB_ADC &= ~mask;
}

/**
 * @brief Allow Timer peripheral access from secure context only
 *
 * @param[in] gsc      Pointer to the register overlay for the GSC peripheral
 * @param[in] instance Timer instance to configure context access for
 */
__STATIC_INLINE void DL_GSC_allowTimerSecureAccess(
    GSC_Regs* gsc, DL_GSC_TIMER_SECURE_ACCESS instance)
{
    uint32_t mask;
    switch (instance) {
        case DL_GSC_TIMER_SECURE_ACCESS_TIMA0_0:
            mask = GSC_PPC_SECATTRIB_TIMER_SEC_TIMA0_0_MASK;
            break;
        case DL_GSC_TIMER_SECURE_ACCESS_TIMA0_1:
            mask = GSC_PPC_SECATTRIB_TIMER_SEC_TIMA0_1_MASK;
            break;
        case DL_GSC_TIMER_SECURE_ACCESS_TIMG4_0:
            mask = GSC_PPC_SECATTRIB_TIMER_SEC_TIMG4_0_MASK;
            break;
        case DL_GSC_TIMER_SECURE_ACCESS_TIMG4_1:
            mask = GSC_PPC_SECATTRIB_TIMER_SEC_TIMG4_1_MASK;
            break;
        case DL_GSC_TIMER_SECURE_ACCESS_TIMG4_2:
            mask = GSC_PPC_SECATTRIB_TIMER_SEC_TIMG4_2_MASK;
            break;
        case DL_GSC_TIMER_SECURE_ACCESS_TIMG4_3:
            mask = GSC_PPC_SECATTRIB_TIMER_SEC_TIMG4_3_MASK;
            break;
        case DL_GSC_TIMER_SECURE_ACCESS_TIMG12_0:
            mask = GSC_PPC_SECATTRIB_TIMER_SEC_TIMG12_0_MASK;
            break;
        case DL_GSC_TIMER_SECURE_ACCESS_TIMG8_0:
            mask = GSC_PPC_SECATTRIB_TIMER_SEC_TIMG8_0_MASK;
            break;
        case DL_GSC_TIMER_SECURE_ACCESS_TIMG8_1:
            mask = GSC_PPC_SECATTRIB_TIMER_SEC_TIMG8_1_MASK;
            break;
        default:
            return;
    }
    gsc->PPC_SECATTRIB_TIMER |= mask;
}

/**
 * @brief Allow Timer peripheral access from non-secure context
 *
 * @param[in] gsc      Pointer to the register overlay for the GSC peripheral
 * @param[in] instance Timer instance to configure context access for
 */
__STATIC_INLINE void DL_GSC_allowTimerNonSecureAccess(
    GSC_Regs* gsc, DL_GSC_TIMER_SECURE_ACCESS instance)
{
    uint32_t mask;
    switch (instance) {
        case DL_GSC_TIMER_SECURE_ACCESS_TIMA0_0:
            mask = GSC_PPC_SECATTRIB_TIMER_SEC_TIMA0_0_MASK;
            break;
        case DL_GSC_TIMER_SECURE_ACCESS_TIMA0_1:
            mask = GSC_PPC_SECATTRIB_TIMER_SEC_TIMA0_1_MASK;
            break;
        case DL_GSC_TIMER_SECURE_ACCESS_TIMG4_0:
            mask = GSC_PPC_SECATTRIB_TIMER_SEC_TIMG4_0_MASK;
            break;
        case DL_GSC_TIMER_SECURE_ACCESS_TIMG4_1:
            mask = GSC_PPC_SECATTRIB_TIMER_SEC_TIMG4_1_MASK;
            break;
        case DL_GSC_TIMER_SECURE_ACCESS_TIMG4_2:
            mask = GSC_PPC_SECATTRIB_TIMER_SEC_TIMG4_2_MASK;
            break;
        case DL_GSC_TIMER_SECURE_ACCESS_TIMG4_3:
            mask = GSC_PPC_SECATTRIB_TIMER_SEC_TIMG4_3_MASK;
            break;
        case DL_GSC_TIMER_SECURE_ACCESS_TIMG12_0:
            mask = GSC_PPC_SECATTRIB_TIMER_SEC_TIMG12_0_MASK;
            break;
        case DL_GSC_TIMER_SECURE_ACCESS_TIMG8_0:
            mask = GSC_PPC_SECATTRIB_TIMER_SEC_TIMG8_0_MASK;
            break;
        case DL_GSC_TIMER_SECURE_ACCESS_TIMG8_1:
            mask = GSC_PPC_SECATTRIB_TIMER_SEC_TIMG8_1_MASK;
            break;
        default:
            return;
    }
    gsc->PPC_SECATTRIB_TIMER &= ~mask;
}

/**
 * @brief GPIO Peripheral Secure Context Access Selectors
 *
 * This enumeration defines the GPIO instances for configuring secure/non-secure context access.
 * Each instance corresponds to a specific GPIO peripheral that can be accessed from
 * either secure or non-secure execution context.
 */
typedef enum {
    DL_GSC_GPIO_SECURE_ACCESS_GPIOA =
        GSC_PPC_SECATTRIB_GPIO_SEC_GPIOA_OFS, /*!< GPIOA secure/non-secure context access control */
    DL_GSC_GPIO_SECURE_ACCESS_GPIOB =
        GSC_PPC_SECATTRIB_GPIO_SEC_GPIOB_OFS, /*!< GPIOB secure/non-secure context access control */
    DL_GSC_GPIO_SECURE_ACCESS_GPIOC =
        GSC_PPC_SECATTRIB_GPIO_SEC_GPIOC_OFS /*!< GPIOC secure/non-secure context access control */
} DL_GSC_GPIO_SECURE_ACCESS;

/**
 * @brief MCAN Peripheral Secure Context Access Selectors
 *
 * This enumeration defines the MCAN instances for configuring secure/non-secure context access.
 * Each instance corresponds to a specific MCAN peripheral that can be accessed from
 * either secure or non-secure execution context.
 */
typedef enum {
    DL_GSC_MCAN_SECURE_ACCESS_MCAN0 =
        GSC_PPC_SECATTRIB_MCAN_SEC_MCAN0_OFS, /*!< MCAN0 secure/non-secure context access control */
    DL_GSC_MCAN_SECURE_ACCESS_MCAN1 =
        GSC_PPC_SECATTRIB_MCAN_SEC_MCAN1_OFS /*!< MCAN1 secure/non-secure context access control */
} DL_GSC_MCAN_SECURE_ACCESS;

/**
 * @brief I2S Peripheral Secure Context Access Selectors
 *
 * This enumeration defines the I2S instances for configuring secure/non-secure context access.
 * Each instance corresponds to a specific I2S peripheral that can be accessed from
 * either secure or non-secure execution context.
 */
typedef enum {
    DL_GSC_I2S_SECURE_ACCESS_I2S0 =
        GSC_PPC_SECATTRIB_I2S_SEC_I2S0_OFS, /*!< I2S0 secure/non-secure context access control */
    DL_GSC_I2S_SECURE_ACCESS_I2S1 =
        GSC_PPC_SECATTRIB_I2S_SEC_I2S1_OFS /*!< I2S1 secure/non-secure context access control */
} DL_GSC_I2S_SECURE_ACCESS;

/**
 * @brief ACOMP Peripheral Secure Context Access Selectors
 *
 * This enumeration defines the ACOMP instances for configuring secure/non-secure context access.
 * Each instance corresponds to a specific Analog Comparator peripheral that can be accessed from
 * either secure or non-secure execution context.
 */
typedef enum {
    DL_GSC_ACOMP_SECURE_ACCESS_ACOMP0 =
        GSC_PPC_SECATTRIB_ACOMP_SEC_ACOMP0_OFS, /*!< ACOMP0 secure/non-secure context access control */
    DL_GSC_ACOMP_SECURE_ACCESS_ACOMP1 =
        GSC_PPC_SECATTRIB_ACOMP_SEC_ACOMP1_OFS /*!< ACOMP1 secure/non-secure context access control */
} DL_GSC_ACOMP_SECURE_ACCESS;

/**
 * @brief Allow GPIO peripheral access from secure context only
 *
 * @param[in] gsc      Pointer to the register overlay for the GSC peripheral
 * @param[in] instance GPIO instance to configure context access for
 */
__STATIC_INLINE void DL_GSC_allowGPIOSecureAccess(
    GSC_Regs* gsc, DL_GSC_GPIO_SECURE_ACCESS instance)
{
    uint32_t mask;
    switch (instance) {
        case DL_GSC_GPIO_SECURE_ACCESS_GPIOA:
            mask = GSC_PPC_SECATTRIB_GPIO_SEC_GPIOA_MASK;
            break;
        case DL_GSC_GPIO_SECURE_ACCESS_GPIOB:
            mask = GSC_PPC_SECATTRIB_GPIO_SEC_GPIOB_MASK;
            break;
        case DL_GSC_GPIO_SECURE_ACCESS_GPIOC:
            mask = GSC_PPC_SECATTRIB_GPIO_SEC_GPIOC_MASK;
            break;
        default:
            return;
    }
    gsc->PPC_SECATTRIB_GPIO |= mask;
}

/**
 * @brief Allow GPIO peripheral access from non-secure context
 *
 * @param[in] gsc      Pointer to the register overlay for the GSC peripheral
 * @param[in] instance GPIO instance to configure context access for
 */
__STATIC_INLINE void DL_GSC_allowGPIONonSecureAccess(
    GSC_Regs* gsc, DL_GSC_GPIO_SECURE_ACCESS instance)
{
    uint32_t mask;
    switch (instance) {
        case DL_GSC_GPIO_SECURE_ACCESS_GPIOA:
            mask = GSC_PPC_SECATTRIB_GPIO_SEC_GPIOA_MASK;
            break;
        case DL_GSC_GPIO_SECURE_ACCESS_GPIOB:
            mask = GSC_PPC_SECATTRIB_GPIO_SEC_GPIOB_MASK;
            break;
        case DL_GSC_GPIO_SECURE_ACCESS_GPIOC:
            mask = GSC_PPC_SECATTRIB_GPIO_SEC_GPIOC_MASK;
            break;
        default:
            return;
    }
    gsc->PPC_SECATTRIB_GPIO &= ~mask;
}

/**
 * @brief Allow MCAN peripheral access from secure context only
 *
 * @param[in] gsc      Pointer to the register overlay for the GSC peripheral
 * @param[in] instance MCAN instance to configure context access for
 */
__STATIC_INLINE void DL_GSC_allowMCANSecureAccess(
    GSC_Regs* gsc, DL_GSC_MCAN_SECURE_ACCESS instance)
{
    uint32_t mask;
    switch (instance) {
        case DL_GSC_MCAN_SECURE_ACCESS_MCAN0:
            mask = GSC_PPC_SECATTRIB_MCAN_SEC_MCAN0_MASK;
            break;
        case DL_GSC_MCAN_SECURE_ACCESS_MCAN1:
            mask = GSC_PPC_SECATTRIB_MCAN_SEC_MCAN1_MASK;
            break;
        default:
            return;
    }
    gsc->PPC_SECATTRIB_MCAN |= mask;
}

/**
 * @brief Allow MCAN peripheral access from non-secure context
 *
 * @param[in] gsc      Pointer to the register overlay for the GSC peripheral
 * @param[in] instance MCAN instance to configure context access for
 */
__STATIC_INLINE void DL_GSC_allowMCANNonSecureAccess(
    GSC_Regs* gsc, DL_GSC_MCAN_SECURE_ACCESS instance)
{
    uint32_t mask;
    switch (instance) {
        case DL_GSC_MCAN_SECURE_ACCESS_MCAN0:
            mask = GSC_PPC_SECATTRIB_MCAN_SEC_MCAN0_MASK;
            break;
        case DL_GSC_MCAN_SECURE_ACCESS_MCAN1:
            mask = GSC_PPC_SECATTRIB_MCAN_SEC_MCAN1_MASK;
            break;
        default:
            return;
    }
    gsc->PPC_SECATTRIB_MCAN &= ~mask;
}

/**
 * @brief Allow I2S peripheral access from secure context only
 *
 * @param[in] gsc      Pointer to the register overlay for the GSC peripheral
 * @param[in] instance I2S instance to configure context access for
 */
__STATIC_INLINE void DL_GSC_allowI2SSecureAccess(
    GSC_Regs* gsc, DL_GSC_I2S_SECURE_ACCESS instance)
{
    uint32_t mask;
    switch (instance) {
        case DL_GSC_I2S_SECURE_ACCESS_I2S0:
            mask = GSC_PPC_SECATTRIB_I2S_SEC_I2S0_MASK;
            break;
        case DL_GSC_I2S_SECURE_ACCESS_I2S1:
            mask = GSC_PPC_SECATTRIB_I2S_SEC_I2S1_MASK;
            break;
        default:
            return;
    }
    gsc->PPC_SECATTRIB_I2S |= mask;
}

/**
 * @brief Allow I2S peripheral access from non-secure context
 *
 * @param[in] gsc      Pointer to the register overlay for the GSC peripheral
 * @param[in] instance I2S instance to configure context access for
 */
__STATIC_INLINE void DL_GSC_allowI2SNonSecureAccess(
    GSC_Regs* gsc, DL_GSC_I2S_SECURE_ACCESS instance)
{
    uint32_t mask;
    switch (instance) {
        case DL_GSC_I2S_SECURE_ACCESS_I2S0:
            mask = GSC_PPC_SECATTRIB_I2S_SEC_I2S0_MASK;
            break;
        case DL_GSC_I2S_SECURE_ACCESS_I2S1:
            mask = GSC_PPC_SECATTRIB_I2S_SEC_I2S1_MASK;
            break;
        default:
            return;
    }
    gsc->PPC_SECATTRIB_I2S &= ~mask;
}

/**
 * @brief Allow ACOMP peripheral access from secure context only
 *
 * @param[in] gsc      Pointer to the register overlay for the GSC peripheral
 * @param[in] instance ACOMP instance to configure context access for
 */
__STATIC_INLINE void DL_GSC_allowACOMPSecureAccess(
    GSC_Regs* gsc, DL_GSC_ACOMP_SECURE_ACCESS instance)
{
    uint32_t mask;
    switch (instance) {
        case DL_GSC_ACOMP_SECURE_ACCESS_ACOMP0:
            mask = GSC_PPC_SECATTRIB_ACOMP_SEC_ACOMP0_MASK;
            break;
        case DL_GSC_ACOMP_SECURE_ACCESS_ACOMP1:
            mask = GSC_PPC_SECATTRIB_ACOMP_SEC_ACOMP1_MASK;
            break;
        default:
            return;
    }
    gsc->PPC_SECATTRIB_ACOMP |= mask;
}

/**
 * @brief Allow ACOMP peripheral access from non-secure context
 *
 * @param[in] gsc      Pointer to the register overlay for the GSC peripheral
 * @param[in] instance ACOMP instance to configure context access for
 */
__STATIC_INLINE void DL_GSC_allowACOMPNonSecureAccess(
    GSC_Regs* gsc, DL_GSC_ACOMP_SECURE_ACCESS instance)
{
    uint32_t mask;
    switch (instance) {
        case DL_GSC_ACOMP_SECURE_ACCESS_ACOMP0:
            mask = GSC_PPC_SECATTRIB_ACOMP_SEC_ACOMP0_MASK;
            break;
        case DL_GSC_ACOMP_SECURE_ACCESS_ACOMP1:
            mask = GSC_PPC_SECATTRIB_ACOMP_SEC_ACOMP1_MASK;
            break;
        default:
            return;
    }
    gsc->PPC_SECATTRIB_ACOMP &= ~mask;
}

/**
 * @brief Allow LFSS peripheral access from secure context only
 *
 * @param[in] gsc      Pointer to the register overlay for the GSC peripheral
 */
__STATIC_INLINE void DL_GSC_allowLFSSSecureAccess(GSC_Regs* gsc)
{
    gsc->PPC_SECATTRIB_LFSS |= GSC_PPC_SECATTRIB_LFSS_SEC_LFSS_MASK;
}

/**
 * @brief Allow LFSS peripheral access from non-secure context
 *
 * @param[in] gsc      Pointer to the register overlay for the GSC peripheral
 */
__STATIC_INLINE void DL_GSC_allowLFSSNonSecureAccess(GSC_Regs* gsc)
{
    gsc->PPC_SECATTRIB_LFSS &= ~GSC_PPC_SECATTRIB_LFSS_SEC_LFSS_MASK;
}

/**
 * @brief Allow CRC peripheral access from secure context only
 *
 * @param[in] gsc      Pointer to the register overlay for the GSC peripheral
 */
__STATIC_INLINE void DL_GSC_allowCRCSecureAccess(GSC_Regs* gsc)
{
    gsc->PPC_SECATTRIB_CRC |= GSC_PPC_SECATTRIB_CRC_SEC_CRC_MASK;
}

/**
 * @brief Allow CRC peripheral access from non-secure context
 *
 * @param[in] gsc      Pointer to the register overlay for the GSC peripheral
 */
__STATIC_INLINE void DL_GSC_allowCRCNonSecureAccess(GSC_Regs* gsc)
{
    gsc->PPC_SECATTRIB_CRC &= ~GSC_PPC_SECATTRIB_CRC_SEC_CRC_MASK;
}

/**
 * @brief Allow AES peripheral access from secure context only
 *
 * @param[in] gsc      Pointer to the register overlay for the GSC peripheral
 */
__STATIC_INLINE void DL_GSC_allowAESSecureAccess(GSC_Regs* gsc)
{
    gsc->PPC_SECATTRIB_AES |= GSC_PPC_SECATTRIB_AES_SEC_AES_MASK;
}

/**
 * @brief Allow AES peripheral access from non-secure context
 *
 * @param[in] gsc      Pointer to the register overlay for the GSC peripheral
 */
__STATIC_INLINE void DL_GSC_allowAESNonSecureAccess(GSC_Regs* gsc)
{
    gsc->PPC_SECATTRIB_AES &= ~GSC_PPC_SECATTRIB_AES_SEC_AES_MASK;
}

/**
 * @brief Allow SHA peripheral access from secure context only
 *
 * @param[in] gsc      Pointer to the register overlay for the GSC peripheral
 */
__STATIC_INLINE void DL_GSC_allowSHASecureAccess(GSC_Regs* gsc)
{
    gsc->PPC_SECATTRIB_SHA |= GSC_PPC_SECATTRIB_SHA_SEC_SHA_MASK;
}

/**
 * @brief Allow SHA peripheral access from non-secure context
 *
 * @param[in] gsc      Pointer to the register overlay for the GSC peripheral
 */
__STATIC_INLINE void DL_GSC_allowSHANonSecureAccess(GSC_Regs* gsc)
{
    gsc->PPC_SECATTRIB_SHA &= ~GSC_PPC_SECATTRIB_SHA_SEC_SHA_MASK;
}

/**
 * @brief Allow QSPI peripheral access from secure context only
 *
 * @param[in] gsc      Pointer to the register overlay for the GSC peripheral
 */
__STATIC_INLINE void DL_GSC_allowQSPISecureAccess(GSC_Regs* gsc)
{
    gsc->PPC_SECATTRIB_QSPI |= GSC_PPC_SECATTRIB_QSPI_SEC_QSPI_MASK;
}

/**
 * @brief Allow QSPI peripheral access from non-secure context
 *
 * @param[in] gsc      Pointer to the register overlay for the GSC peripheral
 */
__STATIC_INLINE void DL_GSC_allowQSPINonSecureAccess(GSC_Regs* gsc)
{
    gsc->PPC_SECATTRIB_QSPI &= ~GSC_PPC_SECATTRIB_QSPI_SEC_QSPI_MASK;
}

/**
 * @brief Allow TRNG peripheral access from secure context only
 *
 * @param[in] gsc      Pointer to the register overlay for the GSC peripheral
 */
__STATIC_INLINE void DL_GSC_allowTRNGSecureAccess(GSC_Regs* gsc)
{
    gsc->PPC_SECATTRIB_TRNG |= GSC_PPC_SECATTRIB_TRNG_SEC_TRNG_MASK;
}

/**
 * @brief Allow TRNG peripheral access from non-secure context
 *
 * @param[in] gsc      Pointer to the register overlay for the GSC peripheral
 */
__STATIC_INLINE void DL_GSC_allowTRNGNonSecureAccess(GSC_Regs* gsc)
{
    gsc->PPC_SECATTRIB_TRNG &= ~GSC_PPC_SECATTRIB_TRNG_SEC_TRNG_MASK;
}

/**
 * @brief Allow PKA peripheral access from secure context only
 *
 * @param[in] gsc      Pointer to the register overlay for the GSC peripheral
 */
__STATIC_INLINE void DL_GSC_allowPKASecureAccess(GSC_Regs* gsc)
{
    gsc->PPC_SECATTRIB_PKA |= GSC_PPC_SECATTRIB_PKA_SEC_PKA_MASK;
}

/**
 * @brief Allow PKA peripheral access from non-secure context
 *
 * @param[in] gsc      Pointer to the register overlay for the GSC peripheral
 */
__STATIC_INLINE void DL_GSC_allowPKANonSecureAccess(GSC_Regs* gsc)
{
    gsc->PPC_SECATTRIB_PKA &= ~GSC_PPC_SECATTRIB_PKA_SEC_PKA_MASK;
}

/**
 * @brief Allow IOMUX peripheral access from secure context only
 *
 * @param[in] gsc      Pointer to the register overlay for the GSC peripheral
 */
__STATIC_INLINE void DL_GSC_allowIOMUXSecureAccess(GSC_Regs* gsc)
{
    gsc->PPC_SECATTRIB_IOMUX |= GSC_PPC_SECATTRIB_IOMUX_SEC_IOMUX_MASK;
}

/**
 * @brief Allow IOMUX peripheral access from non-secure context
 *
 * @param[in] gsc      Pointer to the register overlay for the GSC peripheral
 */
__STATIC_INLINE void DL_GSC_allowIOMUXNonSecureAccess(GSC_Regs* gsc)
{
    gsc->PPC_SECATTRIB_IOMUX &= ~GSC_PPC_SECATTRIB_IOMUX_SEC_IOMUX_MASK;
}

/**
 * @brief Allow DEBUGSS peripheral access from secure context only
 *
 * @param[in] gsc      Pointer to the register overlay for the GSC peripheral
 */
__STATIC_INLINE void DL_GSC_allowDEBUGSSSecureAccess(GSC_Regs* gsc)
{
    gsc->PPC_SECATTRIB_DEBUGSS |= GSC_PPC_SECATTRIB_DEBUGSS_SEC_DEBUGSS_MASK;
}

/**
 * @brief Allow DEBUGSS peripheral access from non-secure context
 *
 * @param[in] gsc      Pointer to the register overlay for the GSC peripheral
 */
__STATIC_INLINE void DL_GSC_allowDEBUGSSNonSecureAccess(GSC_Regs* gsc)
{
    gsc->PPC_SECATTRIB_DEBUGSS &= ~GSC_PPC_SECATTRIB_DEBUGSS_SEC_DEBUGSS_MASK;
}

/**
 * @brief Allow VREF peripheral access from secure context only
 *
 * @param[in] gsc      Pointer to the register overlay for the GSC peripheral
 */
__STATIC_INLINE void DL_GSC_allowVREFSecureAccess(GSC_Regs* gsc)
{
    gsc->PPC_SECATTRIB_VREF |= GSC_PPC_SECATTRIB_VREF_SEC_VREF_MASK;
}

/**
 * @brief Allow VREF peripheral access from non-secure context
 *
 * @param[in] gsc      Pointer to the register overlay for the GSC peripheral
 */
__STATIC_INLINE void DL_GSC_allowVREFNonSecureAccess(GSC_Regs* gsc)
{
    gsc->PPC_SECATTRIB_VREF &= ~GSC_PPC_SECATTRIB_VREF_SEC_VREF_MASK;
}

/**
 * @brief Allow KEYSTORECTL peripheral access from secure context only
 *
 * @param[in] gsc      Pointer to the register overlay for the GSC peripheral
 */
__STATIC_INLINE void DL_GSC_allowKEYSTORECTLSecureAccess(GSC_Regs* gsc)
{
    gsc->PPC_SECATTRIB_KEYSTORECTL |=
        GSC_PPC_SECATTRIB_KEYSTORECTL_SEC_KEYSTORECTL_MASK;
}

/**
 * @brief Allow KEYSTORECTL peripheral access from non-secure context
 *
 * @param[in] gsc      Pointer to the register overlay for the GSC peripheral
 */
__STATIC_INLINE void DL_GSC_allowKEYSTORECTLNonSecureAccess(GSC_Regs* gsc)
{
    gsc->PPC_SECATTRIB_KEYSTORECTL &=
        ~GSC_PPC_SECATTRIB_KEYSTORECTL_SEC_KEYSTORECTL_MASK;
}

/**
 * @brief Allow EAM peripheral access from secure context only
 *
 * @param[in] gsc      Pointer to the register overlay for the GSC peripheral
 */
__STATIC_INLINE void DL_GSC_allowEAMSecureAccess(GSC_Regs* gsc)
{
    gsc->PPC_SECATTRIB_EAM |= GSC_PPC_SECATTRIB_EAM_SEC_EAM_MASK;
}

/**
 * @brief Allow EAM peripheral access from non-secure context
 *
 * @param[in] gsc      Pointer to the register overlay for the GSC peripheral
 */
__STATIC_INLINE void DL_GSC_allowEAMNonSecureAccess(GSC_Regs* gsc)
{
    gsc->PPC_SECATTRIB_EAM &= ~GSC_PPC_SECATTRIB_EAM_SEC_EAM_MASK;
}

/**
 * @brief Allow WUC peripheral access from secure context only
 *
 * @param[in] gsc      Pointer to the register overlay for the GSC peripheral
 */
__STATIC_INLINE void DL_GSC_allowWUCSecureAccess(GSC_Regs* gsc)
{
    gsc->PPC_SECATTRIB_WUC |= GSC_PPC_SECATTRIB_WUC_SEC_WUC_MASK;
}

/**
 * @brief Allow WUC peripheral access from non-secure context
 *
 * @param[in] gsc      Pointer to the register overlay for the GSC peripheral
 */
__STATIC_INLINE void DL_GSC_allowWUCNonSecureAccess(GSC_Regs* gsc)
{
    gsc->PPC_SECATTRIB_WUC &= ~GSC_PPC_SECATTRIB_WUC_SEC_WUC_MASK;
}

/**
 * @brief Allow FRIREGS peripheral access from secure context only
 *
 * @param[in] gsc      Pointer to the register overlay for the GSC peripheral
 */
__STATIC_INLINE void DL_GSC_allowFRIREGSSecureAccess(GSC_Regs* gsc)
{
    gsc->PPC_SECATTRIB_FRIREGS |= GSC_PPC_SECATTRIB_FRIREGS_SEC_FRIREGS_MASK;
}

/**
 * @brief Allow FRIREGS peripheral access from non-secure context
 *
 * @param[in] gsc      Pointer to the register overlay for the GSC peripheral
 */
__STATIC_INLINE void DL_GSC_allowFRIREGSNonSecureAccess(GSC_Regs* gsc)
{
    gsc->PPC_SECATTRIB_FRIREGS &= ~GSC_PPC_SECATTRIB_FRIREGS_SEC_FRIREGS_MASK;
}

/**
 * @brief Allow MEMCFG peripheral access from secure context only
 *
 * @param[in] gsc      Pointer to the register overlay for the GSC peripheral
 */
__STATIC_INLINE void DL_GSC_allowMEMCFGSecureAccess(GSC_Regs* gsc)
{
    gsc->PPC_SECATTRIB_MEMCFG |= GSC_PPC_SECATTRIB_MEMCFG_SEC_MEMCFG_MASK;
}

/**
 * @brief Allow MEMCFG peripheral access from non-secure context
 *
 * @param[in] gsc      Pointer to the register overlay for the GSC peripheral
 */
__STATIC_INLINE void DL_GSC_allowMEMCFGNonSecureAccess(GSC_Regs* gsc)
{
    gsc->PPC_SECATTRIB_MEMCFG &= ~GSC_PPC_SECATTRIB_MEMCFG_SEC_MEMCFG_MASK;
}

/**
 * @brief Allow SYSCTL peripheral access from secure context only
 *
 * @param[in] gsc      Pointer to the register overlay for the GSC peripheral
 */
__STATIC_INLINE void DL_GSC_allowSYSCTLSecureAccess(GSC_Regs* gsc)
{
    gsc->PPC_SECATTRIB_SYSCTL |= GSC_PPC_SECATTRIB_SYSCTL_SEC_SYSCTL_MASK;
}

/**
 * @brief Allow SYSCTL peripheral access from non-secure context
 *
 * @param[in] gsc      Pointer to the register overlay for the GSC peripheral
 */
__STATIC_INLINE void DL_GSC_allowSYSCTLNonSecureAccess(GSC_Regs* gsc)
{
    gsc->PPC_SECATTRIB_SYSCTL &= ~GSC_PPC_SECATTRIB_SYSCTL_SEC_SYSCTL_MASK;
}

/**
 * @brief Allow SYSCTL peripheral privileged access
 *
 * @param[in] gsc      Pointer to the register overlay for the GSC peripheral
 */
__STATIC_INLINE void DL_GSC_allowSYSCTLPrivilegeAccess(GSC_Regs* gsc)
{
    gsc->PPC_PRIVATTRIB_SYSCTL |= GSC_PPC_PRIVATTRIB_SYSCTL_PRIV_SYSCTL_MASK;
}

/**
 * @brief Allow SYSCTL peripheral non-privileged access
 *
 * @param[in] gsc      Pointer to the register overlay for the GSC peripheral
 */
__STATIC_INLINE void DL_GSC_allowSYSCTLNonPrivilegeAccess(GSC_Regs* gsc)
{
    gsc->PPC_PRIVATTRIB_SYSCTL &= ~GSC_PPC_PRIVATTRIB_SYSCTL_PRIV_SYSCTL_MASK;
}

/**
 * @brief Allow GSC peripheral access from secure context only
 *
 * @param[in] gsc      Pointer to the register overlay for the GSC peripheral
 */
__STATIC_INLINE void DL_GSC_allowGSCSecureAccess(GSC_Regs* gsc)
{
    gsc->PPC_SECATTRIB_GSC |= GSC_PPC_SECATTRIB_GSC_SEC_GSC_MASK;
}

/**
 * @brief Allow GSC peripheral access from non-secure context
 *
 * @param[in] gsc      Pointer to the register overlay for the GSC peripheral
 */
__STATIC_INLINE void DL_GSC_allowGSCNonSecureAccess(GSC_Regs* gsc)
{
    gsc->PPC_SECATTRIB_GSC &= ~GSC_PPC_SECATTRIB_GSC_SEC_GSC_MASK;
}

/**
 * @brief Allow GSC peripheral privileged access
 *
 * @param[in] gsc      Pointer to the register overlay for the GSC peripheral
 */
__STATIC_INLINE void DL_GSC_allowGSCPrivilegeAccess(GSC_Regs* gsc)
{
    gsc->PPC_PRIVATTRIB_GSC |= GSC_PPC_PRIVATTRIB_GSC_PRIV_GSC_MASK;
}

/**
 * @brief Allow GSC peripheral non-privileged access
 *
 * @param[in] gsc      Pointer to the register overlay for the GSC peripheral
 */
__STATIC_INLINE void DL_GSC_allowGSCNonPrivilegeAccess(GSC_Regs* gsc)
{
    gsc->PPC_PRIVATTRIB_GSC &= ~GSC_PPC_PRIVATTRIB_GSC_PRIV_GSC_MASK;
}

__STATIC_INLINE void DL_GSC_allowDMA0PrivilegeAccess(GSC_Regs* gsc)
{
    gsc->PPC_PRIVATTRIB_DMA |= GSC_PPC_PRIVATTRIB_DMA_PRIV_DMA0_MASK;
}

__STATIC_INLINE void DL_GSC_allowDMA0NonPrivilegeAccess(GSC_Regs* gsc)
{
    gsc->PPC_PRIVATTRIB_DMA &= ~GSC_PPC_PRIVATTRIB_DMA_PRIV_DMA0_MASK;
}

__STATIC_INLINE void DL_GSC_allowDMA1PrivilegeAccess(GSC_Regs* gsc)
{
    gsc->PPC_PRIVATTRIB_DMA |= GSC_PPC_PRIVATTRIB_DMA_PRIV_DMA1_MASK;
}

__STATIC_INLINE void DL_GSC_allowDMA1NonPrivilegeAccess(GSC_Regs* gsc)
{
    gsc->PPC_PRIVATTRIB_DMA &= ~GSC_PPC_PRIVATTRIB_DMA_PRIV_DMA1_MASK;
}

/**
 * @brief Allow DMA0 peripheral access from secure context only
 *
 * @param[in] gsc      Pointer to the register overlay for the GSC peripheral
 */
__STATIC_INLINE void DL_GSC_allowDMA0SecureAccess(GSC_Regs* gsc)
{
    gsc->PPC_SECATTRIB_DMA |= GSC_PPC_SECATTRIB_DMA_SEC_DMA0_MASK;
}

/**
 * @brief Allow DMA0 peripheral access from non-secure context
 *
 * @param[in] gsc      Pointer to the register overlay for the GSC peripheral
 */
__STATIC_INLINE void DL_GSC_allowDMA0NonSecureAccess(GSC_Regs* gsc)
{
    gsc->PPC_SECATTRIB_DMA &= ~GSC_PPC_SECATTRIB_DMA_SEC_DMA0_MASK;
}

/**
 * @brief Allow DMA1 peripheral access from secure context only
 *
 * @param[in] gsc      Pointer to the register overlay for the GSC peripheral
 */
__STATIC_INLINE void DL_GSC_allowDMA1SecureAccess(GSC_Regs* gsc)
{
    gsc->PPC_SECATTRIB_DMA |= GSC_PPC_SECATTRIB_DMA_SEC_DMA1_MASK;
}

/**
 * @brief Allow DMA1 peripheral access from non-secure context
 *
 * @param[in] gsc      Pointer to the register overlay for the GSC peripheral
 */
__STATIC_INLINE void DL_GSC_allowDMA1NonSecureAccess(GSC_Regs* gsc)
{
    gsc->PPC_SECATTRIB_DMA &= ~GSC_PPC_SECATTRIB_DMA_SEC_DMA1_MASK;
}

/**
 * @brief Enable PKA SRAM zeroization
 *
 * Enables zeroization functionality for PKA SRAM. When enabled,
 * the PKA SRAM content will be zeroed.
 *
 * @param[in] gsc      Pointer to the register overlay for the GSC peripheral
 */
__STATIC_INLINE void DL_GSC_enablePKASRAMZeroization(GSC_Regs* gsc)
{
    // Bit is active low - clearing enables zeroization
    gsc->PPC_SPARERW_GSC &= ~GSC_PPC_SPARERW_GSC_ZERO_PKASRAM_MASK;
}

/**
 * @brief Disable PKA SRAM zeroization
 *
 * Disables zeroization functionality for PKA SRAM. When disabled,
 * the PKA SRAM content will be preserved.
 *
 * @param[in] gsc      Pointer to the register overlay for the GSC peripheral
 */
__STATIC_INLINE void DL_GSC_disablePKASRAMZeroization(GSC_Regs* gsc)
{
    // Bit is active low - setting disables zeroization
    gsc->PPC_SPARERW_GSC |= GSC_PPC_SPARERW_GSC_ZERO_PKASRAM_MASK;
}

/** @brief DMA Fixed Trigger Sources */
typedef enum {
    DL_GSC_DMA_FIXED_TRIG_AES_PUB1   = 0,  /*!< AESADV.PUBLISHER_1 */
    DL_GSC_DMA_FIXED_TRIG_AES_PUB2   = 1,  /*!< AESADV.PUBLISHER_2 */
    DL_GSC_DMA_FIXED_TRIG_ADC0_TRIG1 = 2,  /*!< ADC0_DMA_TRIG1 */
    DL_GSC_DMA_FIXED_TRIG_ADC0_TRIG2 = 3,  /*!< ADC0_DMA_TRIG2 */
    DL_GSC_DMA_FIXED_TRIG_ADC0_TRIG3 = 4,  /*!< ADC0_DMA_TRIG3 */
    DL_GSC_DMA_FIXED_TRIG_ADC0_TRIG4 = 5,  /*!< ADC0_DMA_TRIG4 */
    DL_GSC_DMA_FIXED_TRIG_ADC1_TRIG1 = 6,  /*!< ADC1_DMA_TRIG1 */
    DL_GSC_DMA_FIXED_TRIG_ADC1_TRIG2 = 7,  /*!< ADC1_DMA_TRIG2 */
    DL_GSC_DMA_FIXED_TRIG_ADC1_TRIG3 = 8,  /*!< ADC1_DMA_TRIG3 */
    DL_GSC_DMA_FIXED_TRIG_ADC1_TRIG4 = 9,  /*!< ADC1_DMA_TRIG4 */
    DL_GSC_DMA_FIXED_TRIG_SHA_PUB1   = 10, /*!< SHA.PUBLISHER_1 */
} DL_GSC_DMA_FixedTrigger;

/** @brief DMA Regular Trigger Sources */
typedef enum {
    DL_GSC_DMA_TRIG_I2S0_PUB1 = 0,  /*!< I2S0.PUBLISHER_1 */
    DL_GSC_DMA_TRIG_I2S0_PUB2 = 1,  /*!< I2S0.PUBLISHER_2 */
    DL_GSC_DMA_TRIG_I2S1_PUB1 = 2,  /*!< I2S1.PUBLISHER_1 */
    DL_GSC_DMA_TRIG_I2S1_PUB2 = 3,  /*!< I2S1.PUBLISHER_2 */
    DL_GSC_DMA_TRIG_QSPI_PUB1 = 4,  /*!< QSPI.PUBLISHER_1 */
    DL_GSC_DMA_TRIG_QSPI_PUB2 = 5,  /*!< QSPI.PUBLISHER_2 */
    DL_GSC_DMA_TRIG_UC1_0_TX  = 6,  /*!< UC1_0_TX (DMA0 only) */
    DL_GSC_DMA_TRIG_UC1_0_RX  = 7,  /*!< UC1_0_RX (DMA0 only) */
    DL_GSC_DMA_TRIG_UC1_1_TX  = 8,  /*!< UC1_1_TX (DMA0 only) */
    DL_GSC_DMA_TRIG_UC1_1_RX  = 9,  /*!< UC1_1_RX (DMA0 only) */
    DL_GSC_DMA_TRIG_UC2_TX    = 10, /*!< UC2_TX */
    DL_GSC_DMA_TRIG_UC2_RX    = 11, /*!< UC2_RX */
    DL_GSC_DMA_TRIG_UC15_0_TX = 12, /*!< UC15_0_TX */
    DL_GSC_DMA_TRIG_UC15_0_RX = 13, /*!< UC15_0_RX */
    DL_GSC_DMA_TRIG_UC15_1_TX = 14, /*!< UC15_1_TX */
    DL_GSC_DMA_TRIG_UC15_1_RX = 15, /*!< UC15_1_RX */
    DL_GSC_DMA_TRIG_UC12_TX   = 16, /*!< UC12_TX */
    DL_GSC_DMA_TRIG_UC12_RX   = 17, /*!< UC12_RX */
    DL_GSC_DMA_TRIG_UC13_0_TX = 18, /*!< UC13_0_TX */
    DL_GSC_DMA_TRIG_UC13_0_RX = 19, /*!< UC13_0_RX */
    DL_GSC_DMA_TRIG_UC13_1_TX = 20, /*!< UC13_1_TX */
    DL_GSC_DMA_TRIG_UC13_1_RX = 21, /*!< UC13_1_RX */
    DL_GSC_DMA_TRIG_UC13_2_TX = 22, /*!< UC13_2_TX */
    DL_GSC_DMA_TRIG_UC13_2_RX = 23, /*!< UC13_2_RX */
    DL_GSC_DMA_TRIG_UC13_3_TX = 24, /*!< UC13_3_TX */
    DL_GSC_DMA_TRIG_UC13_3_RX = 25, /*!< UC13_3_RX */
    DL_GSC_DMA_TRIG_UC14_TX   = 26, /*!< UC14_TX */
    DL_GSC_DMA_TRIG_UC14_RX   = 27, /*!< UC14_RX */
} DL_GSC_DMA_RegularTrigger;

/** @brief DMA Instance selection */
typedef enum {
    DL_GSC_DMA_INSTANCE_0 = 0, /*!< Route trigger to DMA0 */
    DL_GSC_DMA_INSTANCE_1 = 1  /*!< Route trigger to DMA1 */
} DL_GSC_DMA_Instance;

/* Function prototypes */
void DL_GSC_setFixedTriggerDMAInstance(GSC_Regs* gsc,
    DL_GSC_DMA_FixedTrigger trigger, DL_GSC_DMA_Instance instance);
void DL_GSC_setRegularTriggerDMAInstance(GSC_Regs* gsc,
    DL_GSC_DMA_RegularTrigger trigger, DL_GSC_DMA_Instance instance);
DL_GSC_DMA_Instance DL_GSC_getFixedTriggerDMAInstance(
    GSC_Regs* gsc, DL_GSC_DMA_FixedTrigger trigger);
DL_GSC_DMA_Instance DL_GSC_getRegularTriggerDMAInstance(
    GSC_Regs* gsc, DL_GSC_DMA_RegularTrigger trigger);

typedef enum {
    DL_GSC_SPC_BLOCK_C0B0_512B = GSC_SPC_SECATTRIB0_C0B0_512B_MASK,
    DL_GSC_SPC_BLOCK_C0B1_512B = GSC_SPC_SECATTRIB0_C0B1_512B_MASK,
    DL_GSC_SPC_BLOCK_C0B0_1KB  = GSC_SPC_SECATTRIB0_C0B0_1KB_MASK,
    DL_GSC_SPC_BLOCK_C0B0_2KB  = GSC_SPC_SECATTRIB0_C0B0_2KB_MASK,
    DL_GSC_SPC_BLOCK_C0B0_4KB  = GSC_SPC_SECATTRIB0_C0B0_4KB_MASK,
    DL_GSC_SPC_BLOCK_C0B1_4KB  = GSC_SPC_SECATTRIB0_C0B1_4KB_MASK,
    DL_GSC_SPC_BLOCK_C0B2_4KB  = GSC_SPC_SECATTRIB0_C0B2_4KB_MASK,
    DL_GSC_SPC_BLOCK_C1B0_512B = GSC_SPC_SECATTRIB0_C1B0_512B_MASK,
    DL_GSC_SPC_BLOCK_C1B1_512B = GSC_SPC_SECATTRIB0_C1B1_512B_MASK,
    DL_GSC_SPC_BLOCK_C1B0_1KB  = GSC_SPC_SECATTRIB0_C1B0_1KB_MASK,
    DL_GSC_SPC_BLOCK_C1B0_2KB  = GSC_SPC_SECATTRIB0_C1B0_2KB_MASK,
    DL_GSC_SPC_BLOCK_C1B0_4KB  = GSC_SPC_SECATTRIB0_C1B0_4KB_MASK,
    DL_GSC_SPC_BLOCK_C1B1_4KB  = GSC_SPC_SECATTRIB0_C1B1_4KB_MASK,
    DL_GSC_SPC_BLOCK_C1B2_4KB  = GSC_SPC_SECATTRIB0_C1B2_4KB_MASK,
    DL_GSC_SPC_BLOCK_C2B0_512B = GSC_SPC_SECATTRIB0_C2B0_512B_MASK,
    DL_GSC_SPC_BLOCK_C2B1_512B = GSC_SPC_SECATTRIB0_C2B1_512B_MASK,
    DL_GSC_SPC_BLOCK_C2B0_1KB  = GSC_SPC_SECATTRIB0_C2B0_1KB_MASK,
    DL_GSC_SPC_BLOCK_C2B0_2KB  = GSC_SPC_SECATTRIB0_C2B0_2KB_MASK,
    DL_GSC_SPC_BLOCK_C2B0_4KB  = GSC_SPC_SECATTRIB0_C2B0_4KB_MASK,
    DL_GSC_SPC_BLOCK_C2B1_4KB  = GSC_SPC_SECATTRIB0_C2B1_4KB_MASK,
    DL_GSC_SPC_BLOCK_C2B2_4KB  = GSC_SPC_SECATTRIB0_C2B2_4KB_MASK,
    DL_GSC_SPC_BLOCK_C3B0_512B = GSC_SPC_SECATTRIB0_C3B0_512B_MASK,
    DL_GSC_SPC_BLOCK_C3B1_512B = GSC_SPC_SECATTRIB0_C3B1_512B_MASK,
    DL_GSC_SPC_BLOCK_C3B0_1KB  = GSC_SPC_SECATTRIB0_C3B0_1KB_MASK,
    DL_GSC_SPC_BLOCK_C3B0_2KB  = GSC_SPC_SECATTRIB0_C3B0_2KB_MASK,
    DL_GSC_SPC_BLOCK_C3B0_4KB  = GSC_SPC_SECATTRIB0_C3B0_4KB_MASK,
    DL_GSC_SPC_BLOCK_C3B1_4KB  = GSC_SPC_SECATTRIB0_C3B1_4KB_MASK,
    DL_GSC_SPC_BLOCK_C3B2_4KB  = GSC_SPC_SECATTRIB0_C3B2_4KB_MASK,
} DL_GSC_SPC_BLOCK;

/**
 *  @brief Set DICE Check SUM
 *
 *
 *  @param[in] gsc          Pointer to the register overlay for the peripheral
 *  @param[in] dice         DICE array of 8 32-bit integers
 *  @return    void
 */
__STATIC_INLINE
void DL_GSC_setDICECheckSum(GSC_Regs* gsc, const uint32_t* dice)
{
    uint32_t volatile* diceBaseAddr = (&(gsc->DICE_CHECKSUM0));
    const uint8_t diceLength        = 8U;
    for (uint8_t i = 0; i < diceLength; i++) {
        diceBaseAddr[i] = dice[i];
    }
}

/**
 * @brief Get the major revision number of GSC module
 *
 * @param gsc Pointer to GSC registers
 * @return uint8_t Major revision number
 */
static inline uint8_t DL_GSC_getMajorRevision(GSC_Regs* gsc)
{
    return ((gsc->GSC_REVISION & GSC_GSC_REVISION_MAJREV_MASK) >>
            GSC_GSC_REVISION_MAJREV_OFS);
}

/**
 * @brief Get the minor revision number of GSC module
 *
 * @param gsc Pointer to GSC registers
 * @return uint8_t Minor revision number
 */
static inline uint8_t DL_GSC_getMinorRevision(GSC_Regs* gsc)
{
    return ((gsc->GSC_REVISION & GSC_GSC_REVISION_MINREV_MASK) >>
            GSC_GSC_REVISION_MINREV_OFS);
}

/**
 * @brief Acquires flash semaphore and returns
 * @note  If the following conditions are met, a write of '1' to this bit causes the FLSEMSTAT register to its reset state: <br/>
 * @note  1) The FLSEMSTAT.SEC of the code performing the write is 0x1 and FLSEMSTAT.PRIV of the code performing the write is 0x1 (i.e. secure privilage code can force relinquishing of the semaphore) or
 * @note  2) FLSEMSTAT.ASSIGNED bit is set, and
 * @note      a) FLSEMSTAT.SEC matches security attribute of the code performing the write, and
 * @note      b) FLSEMSTAT.PRIV matches privilege attribute code performing the write.
 *
 *   If the above conditions are not met during the write, the write will be ignored with no error indicated. It is advised that the writing code perform a read of the FLSEMSTAT register to ensure it was cleared after writing to this bit.
 *
 * @note
 * @param  *gsc: GSC_Regs
 * @retval None
 */
__STATIC_INLINE void DL_GSC_acquireFlashSemaphore(GSC_Regs* gsc)
{
    while (!(((gsc->FPC_FLSEMSTAT & GSC_FPC_FLSEMSTAT_ASSIGNED_MASK) ==
                 GSC_FPC_FLSEMSTAT_ASSIGNED_MASK) &&
             ((gsc->FPC_FLSEMSTAT & GSC_FPC_FLSEMSTAT_MATCH_MASK) ==
                 GSC_FPC_FLSEMSTAT_MATCH_MASK))) {
        gsc->FPC_FLSEMREQ = GSC_FPC_FLSEMREQ_REQ_MASK;
    }
}

/**
 * @brief  Returns current Flash Semaphore Status
 *
 * @note Bits	Field Name	Description
 * @note
 * @note   31:31	ASSIGNED	SEC and PRIV fields are valid when this bit is set.
 * @note        0 : SEC and PRIV are unassigned and flash controller is not accessible
 * @note        1 : SEC and PRIV values are valid and the flash controller is currently assigned to them
 * @note
 * @note   30:30	MATCH	On a read, this bit will reflect whether the reader's SEC and PRIV matches the ownership of the flash controller.
 * @note        0 : Code performing read does not own the flash controller semaphore
 * @note        1 : Code performing read owns the flash controller semphore.
 * @note This avoids code from being required to know whether the current code segment owns the flash controller configuration.
 * @note
 * @note   29:17	Reserved_3	Reserved
 * @note
 * @note   16:16	DBGACC	Defines the flash controller semaphore owners debug access indication
 * @note        0x0 : functional access
 * @note        0x1 : Debug access
 * @note
 * @note   15:9	Reserved_2	Reserved
 * @note
 * @note   8:8	PRIV	Defines the flash controller semaphore owners privilage attribute
 * @note        0x0 : non-privilage
 * @note        0x1 :prvilage
 * @note
 * @note   7:1	Reserved_1	Reserved
 * @note
 * @note   0:0	SEC	Defines the flash controller semaphore owners security attribute
 * @note        0x0 : non-secure
 * @note        0x1 :secure
 * @param  *gsc: GSC_Regs
 * @return uint32_t Current flash semaphore status register value
 */
__STATIC_INLINE uint32_t DL_GSC_getFlashSemaphoreStatus(GSC_Regs* gsc)
{
    return gsc->FPC_FLSEMSTAT;
}

/**
 * @brief Request flash semaphore
 *
 * @param gsc         Pointer to the GSC register structure
 */
__STATIC_INLINE void DL_GSC_requestFlashSemaphore(GSC_Regs* gsc)
{
    gsc->FPC_FLSEMREQ = GSC_FPC_FLSEMREQ_REQ_MASK;
}

/**
 * @brief Clear/release flash semaphore
 *
 * @param gsc         Pointer to the GSC register structure
 */
__STATIC_INLINE void DL_GSC_clearFlashSemaphore(GSC_Regs* gsc)
{
    gsc->FPC_FLSEMCLR = GSC_FPC_FLSEMCLR_CLR_MASK;
}

/**
 * @brief Check if current requester owns the flash semaphore
 *
 * @param gsc         Pointer to the GSC register structure
 * @return true       Current requester owns the semaphore
 * @return false      Current requester does not own the semaphore
 *
 * @note The MATCH bit indicates whether the code reading the register owns
 *       the flash semaphore based on matching SEC and PRIV attributes
 */
__STATIC_INLINE bool DL_GSC_hasFlashSemaphoreMatch(GSC_Regs* gsc)
{
    return ((gsc->FPC_FLSEMSTAT & GSC_FPC_FLSEMSTAT_MATCH_MASK) != 0U);
}

/**
 * @brief Check if flash semaphore is assigned
 *
 * @param gsc         Pointer to the GSC register structure
 * @return bool       True if semaphore is assigned, false otherwise
 */
__STATIC_INLINE bool DL_GSC_isFlashSemaphoreAssigned(GSC_Regs* gsc)
{
    return (gsc->FPC_FLSEMSTAT & GSC_FPC_FLSEMSTAT_ASSIGNED_MASK);
}

/**
 * @brief Check if flash semaphore is in secure state
 *
 * @param gsc         Pointer to the GSC register structure
 * @return bool       True if in secure state, false otherwise
 */
__STATIC_INLINE bool DL_GSC_isFlashSemaphoreSecure(GSC_Regs* gsc)
{
    return (gsc->FPC_FLSEMSTAT & GSC_FPC_FLSEMSTAT_SEC_MASK);
}

/**
 * @brief Check if flash semaphore is in privileged state
 *
 * @param gsc         Pointer to the GSC register structure
 * @return bool       True if in privileged state, false otherwise
 */
__STATIC_INLINE bool DL_GSC_isFlashSemaphorePrivileged(GSC_Regs* gsc)
{
    return (gsc->FPC_FLSEMSTAT & GSC_FPC_FLSEMSTAT_PRIV_MASK);
}

/**
 * @brief Debug Access bit functionality in FPC_FLSEMSTAT
 *
 * FPC_FLSEMSTAT Register:
 * - DBGACC (Debug Access):
 *   1 = Semaphore held by debugger
 *   0 = Normal code execution access
 */

__STATIC_INLINE bool DL_GSC_isFlashSemaphoreDebugAccess(GSC_Regs* gsc)
{
    return (gsc->FPC_FLSEMSTAT & GSC_FPC_FLSEMSTAT_DBGACC_MASK);
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
    GSC_Regs* gsc, const DL_GSC_LockConfig* config);

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
void DL_GSC_getLockConfiguration(GSC_Regs* gsc, DL_GSC_LockConfig* config);

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
    GSC_Regs* gsc, const DL_GSC_LockConfig* config);

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
void DL_GSC_getCommitConfiguration(GSC_Regs* gsc, DL_GSC_LockConfig* config);

/**
 * @brief Configure SRAM security attributes for all memory regions
 *
 * Configures security access permissions for SRAM memory blocks. The memory is divided into
 * 16 pages of 16KB each, with each page further subdivided into configurable chunks.
 * Setting a chunk value to 1 restricts access to secure execution context only.
 * Setting a chunk value to 0 allows non-secure access.
 *
 * @param[in] gsc     Pointer to the GSC peripheral register block
 * @param[in] config  Pointer to SRAM security configuration structure
 *
 * Example usage:
 * @code
 * DL_GSC_SRAMSecurityConfig config = {0}; // Initialize all access as non-secure
 * config.pages[0].chunk_512B_0 = 1;       // Set first 512B chunk as secure
 * config.pages[0].chunk_4KB_0 = 1;        // Set first 4KB chunk as secure
 * DL_GSC_configureSRAMSecurity(gsc, &config);
 * @endcode
 */
void DL_GSC_configureSRAMSecurity(
    GSC_Regs* gsc, const DL_GSC_SRAMSecurityConfig* config);

/**
 * @brief Configure SRAM privilege attributes for all memory regions
 *
 * Configures privilege access permissions for SRAM memory blocks. The memory is divided into
 * 16 pages of 16KB each, with each page further subdivided into configurable chunks.
 * Setting a chunk value to 1 restricts access to privileged execution only.
 * Setting a chunk value to 0 allows non-privileged access.
 *
 * @param[in] gsc     Pointer to the GSC peripheral register block
 * @param[in] config  Pointer to SRAM security configuration structure
 *
 * Example usage:
 * @code
 * DL_GSC_SRAMSecurityConfig config = {0}; // Initialize all access as non-privileged
 * config.pages[0].chunk_512B_0 = 1;       // Set first 512B chunk as privileged
 * config.pages[0].chunk_4KB_0 = 1;        // Set first 4KB chunk as privileged
 * DL_GSC_configureSRAMPrivilege(gsc, &config);
 * @endcode
 */
void DL_GSC_configureSRAMPrivilege(
    GSC_Regs* gsc, const DL_GSC_SRAMSecurityConfig* config);

/**
 * @brief Get current SRAM privilege configuration
 *
 * Reads current privilege access permissions for all SRAM memory blocks.
 * For each chunk in the configuration, returns true if access is restricted
 * to privileged execution context only.
 *
 * @param[in] gsc     Pointer to the GSC peripheral register block
 * @param[out] config Pointer to structure to store current configuration
 *
 * Example usage:
 * @code
 * DL_GSC_SRAMSecurityConfig config;
 * DL_GSC_getSRAMPrivilegeConfig(gsc, &config);
 * if(config.pages[0].chunk_512B_0) {
 *     // First 512B chunk is privileged access only
 * }
 * @endcode
 */
void DL_GSC_getSRAMPrivilegeConfig(
    GSC_Regs* gsc, DL_GSC_SRAMSecurityConfig* config);

/**
 * @brief Get current SRAM security configuration
 *
 * Reads current security access permissions for all SRAM memory blocks.
 * For each chunk in the configuration, returns true if access is restricted
 * to secure execution context only.
 *
 * @param[in] gsc     Pointer to the GSC peripheral register block
 * @param[out] config Pointer to structure to store current configuration
 *
 * Example usage:
 * @code
 * DL_GSC_SRAMSecurityConfig config;
 * DL_GSC_getSRAMSecurityConfig(gsc, &config);
 * if(config.pages[0].chunk_512B_0) {
 *     // First 512B chunk is secure access only
 * }
 * @endcode
 */
void DL_GSC_getSRAMSecurityConfig(
    GSC_Regs* gsc, DL_GSC_SRAMSecurityConfig* config);

#ifdef __cplusplus
}
#endif

#endif /* __MSPM33_HAS_GSC__ */

#endif  // ti_dl_dl_gsc__include

/** @} */
