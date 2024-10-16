/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

/**
 * \file atu_rse_drv.h
 * \brief Driver for Arm Address Translation Unit (ATU).
 */

#ifndef __ATU_RSE_DRV_H__
#define __ATU_RSE_DRV_H__

#include <stdint.h>
#include <stdbool.h>
#include <limits.h>

#ifdef __cplusplus
extern "C" {
#endif

#if TFM_UNIQUE_ERROR_CODES == 1
#include "error_codes_mapping.h"
#else
#define ATU_ERROR_BASE 0x1u
#endif /* TFM_UNIQUE_ERROR_CODES */

/**
 * \brief Arm ATU error enumeration types
 */
enum atu_error_t {
    ATU_ERR_NONE = 0x0u,
    ATU_ERR_INVALID_REGION = ATU_ERROR_BASE,
    ATU_ERR_INVALID_LOGICAL_ADDRESS,
    ATU_ERR_INIT_REGION_INVALID_ADDRESS,
    ATU_ERR_INIT_REGION_INVALID_ARG,
    ATU_ERR_UNINIT_REGION_INVALID_ARG,
    /* Slot allocation related error */
    ATU_ERR_SLOT_NOT_AVAIL,
    /* Memory allocation related error */
    ATU_ERR_MEM_INIT,
    ATU_ERR_MEM_SEC_TYPE,
    ATU_ERR_MEM_SIZE_NOT_AVAILABLE,
    ATU_ERR_MEM_LOG_ADDR,
    ATU_ERR_MEM_INVALID_ARG,
    ATU_ERR_DYN_CFG_SAVE,
    ATU_ERR_DYN_CFG_CLEAR,
    /* Static configuration */
    ATU_ERR_STAT_CFG_OVRLP,
    ATU_ERR_STAT_CFG_COUNT,
    /* Dynamic mapping error codes */
    ATU_MAPPING_AVAIL,
    ATU_MAPPING_TOO_SMALL,
    ATU_MAPPING_NOT_AVAIL,
    ATU_MAPPING_INVALID,
    /* Unknown Error scenario */
    ATU_ERR_UNKNOWN,
    ATU_ERR_FORCE_UINT_SIZE = UINT_MAX,
};

/**
 * \brief Allowed output bus attribute options for ATU region
 */
enum atu_roba_t {
    ATU_ROBA_PASSTHROUGH   = (0x0u),
    ATU_ROBA_RESERVED      = (0x1u),
    ATU_ROBA_SET_0         = (0x2u),
    ATU_ROBA_SET_1         = (0x3u),
};

/*
 * ATU Hardware Macro
 */
#define ATU_ATUBC_PS_OFF                4u
    /*!< ATU Build Configuration Register Page Size bit field offset */
#define ATU_ATUBC_PS_MASK               (0xFu << ATU_ATUBC_PS_OFF)
    /*!< ATU Build Configuration Register Page Size bit field mask */
#define ATU_ATUBC_RC_OFF                0u
    /*!< ATU Build Configuration Register Region Count bit field offset */
#define ATU_ATUBC_RC_MASK               (0x7u << ATU_ATUBC_RC_OFF)
    /*!< ATU Build Configuration Register Region Count bit field mask */
#define ATU_ATUIS_ME_OFF                0u
    /*!< ATU Interrupt Status Register Mismatch Error bit field offset */
#define ATU_ATUIS_ME_MASK               (0x1u << ATU_ATUIS_ME_OFF)
    /*!< ATU Interrupt Status Register Mismatch Error bit field mask */
#define ATU_ATUIE_ME_OFF                0u
    /*!< ATU Interrupt Enable Register Mismatch Error bit field offset */
#define ATU_ATUIE_ME_MASK               (0x1u << ATU_ATUIE_ME_OFF)
    /*!< ATU Interrupt Enable Register Mismatch Error bit field mask */
#define ATU_ATUIC_ME_OFF                0u
    /*!< ATU Interrupt Clear Register Mismatch Error bit field offset */
#define ATU_ATUIC_ME_MASK               (0x1u << ATU_ATUIC_ME_OFF)
    /*!< ATU Interrupt Clear Register Mismatch Error bit field mask */
#define ATU_ATUROBA_AXNSE_OFF           14u
    /*!< ATU ROBA Register AxNSE bit field offset */
#define ATU_ATUROBA_AXNSE_MASK          (0x3u << ATU_ATUROBA_AXNSE_OFF)
    /*!< ATU ROBA Register AxNSE bit field mask */
#define ATU_ATUROBA_AXCACHE3_OFF        12u
    /*!< ATU ROBA Register AxCACHE3 bit field offset */
#define ATU_ATUROBA_AXCACHE3_MASK       (0x3u << ATU_ATUROBA_AXCACHE3_OFF)
    /*!< ATU ROBA Register AxCACHE3 bit field mask */
#define ATU_ATUROBA_AXCACHE2_OFF        10u
    /*!< ATU ROBA Register AxCACHE2 bit field offset */
#define ATU_ATUROBA_AXCACHE2_MASK       (0x3u << ATU_ATUROBA_AXCACHE2_OFF)
    /*!< ATU ROBA Register AxCACHE2 bit field mask */
#define ATU_ATUROBA_AXCACHE1_OFF        8u
    /*!< ATU ROBA Register AxCACHE1 bit field offset */
#define ATU_ATUROBA_AXCACHE1_MASK       (0x3u << ATU_ATUROBA_AXCACHE1_OFF)
    /*!< ATU ROBA Register AxCACHE1 bit field mask */
#define ATU_ATUROBA_AXCACHE0_OFF        6u
    /*!< ATU ROBA Register AxCACHE0 bit field offset */
#define ATU_ATUROBA_AXCACHE0_MASK       (0x3u << ATU_ATUROBA_AXCACHE0_OFF)
    /*!< ATU ROBA Register AxCACHE0 bit field mask */
#define ATU_ATUROBA_AXPROT2_OFF         4u
    /*!< ATU ROBA Register AxPROT2 bit field offset */
#define ATU_ATUROBA_AXPROT2_MASK        (0x3u << ATU_ATUROBA_AXPROT2_OFF)
    /*!< ATU ROBA Register AxPROT2 bit field mask */
#define ATU_ATUROBA_AXPROT1_OFF         2u
    /*!< ATU ROBA Register AxPROT1 bit field offset */
#define ATU_ATUROBA_AXPROT1_MASK        (0x3u << ATU_ATUROBA_AXPROT1_OFF)
    /*!< ATU ROBA Register AxPROT1 bit field mask */
#define ATU_ATUROBA_AXPROT0_OFF         0u
    /*!< ATU ROBA Register AxPROT0 bit field offset */
#define ATU_ATUROBA_AXPROT0_MASK        (0x3u << ATU_ATUROBA_AXPROT0_OFF)
    /*!< ATU ROBA Register AxPROT0 bit field mask */

/*
 * Mask for entire output bus attributes to be configured for the ATU
 * region.
 */
#define ATU_REGION_ROBA_MASK (0xFFFFu)

/*! Macro to encode the output bus attributes */
#define ATU_ENCODE_ATTRIBUTES( \
    AXNSE_VAL, \
    AXCACHE3_VAL, \
    AXCACHE2_VAL, \
    AXCACHE1_VAL, \
    AXCACHE0_VAL, \
    AXPROT2_VAL, \
    AXPROT1_VAL, \
    AXPROT0_VAL) \
    (AXPROT0_VAL | (AXPROT1_VAL << ATU_ATUROBA_AXPROT1_OFF) | \
     (AXPROT2_VAL << ATU_ATUROBA_AXPROT2_OFF) | \
     (AXCACHE0_VAL << ATU_ATUROBA_AXCACHE0_OFF) | \
     (AXCACHE1_VAL << ATU_ATUROBA_AXCACHE1_OFF) | \
     (AXCACHE2_VAL << ATU_ATUROBA_AXCACHE2_OFF) | \
     (AXCACHE3_VAL << ATU_ATUROBA_AXCACHE3_OFF) | \
     (AXNSE_VAL << ATU_ATUROBA_AXNSE_OFF))

/*
 * Encode ATU region output bus attributes for accessing Root PAS
 */
#define ATU_ENCODE_ATTRIBUTES_ROOT_PAS \
    (ATU_ENCODE_ATTRIBUTES( \
        ATU_ROBA_SET_1, \
        ATU_ROBA_SET_0, \
        ATU_ROBA_SET_0, \
        ATU_ROBA_SET_0, \
        ATU_ROBA_SET_0, \
        ATU_ROBA_SET_0, \
        ATU_ROBA_SET_0, \
        ATU_ROBA_SET_0))

/*
 * Encode ATU region output bus attributes for accessing Secure PAS
 */
#define ATU_ENCODE_ATTRIBUTES_SECURE_PAS \
    (ATU_ENCODE_ATTRIBUTES( \
        ATU_ROBA_SET_0, \
        ATU_ROBA_SET_0, \
        ATU_ROBA_SET_0, \
        ATU_ROBA_SET_0, \
        ATU_ROBA_SET_0, \
        ATU_ROBA_SET_0, \
        ATU_ROBA_SET_0, \
        ATU_ROBA_SET_0))

/*
 * Encode ATU region output bus attributes for accessing Non-Secure PAS
 */
#define ATU_ENCODE_ATTRIBUTES_NON_SECURE_PAS \
    (ATU_ENCODE_ATTRIBUTES( \
        ATU_ROBA_SET_0, \
        ATU_ROBA_SET_0, \
        ATU_ROBA_SET_0, \
        ATU_ROBA_SET_0, \
        ATU_ROBA_SET_0, \
        ATU_ROBA_SET_0, \
        ATU_ROBA_SET_1, \
        ATU_ROBA_SET_0))

/*
 * Encode ATU region output bus attributes for accessing Realm PAS
 */
#define ATU_ENCODE_ATTRIBUTES_REALM_PAS \
    (ATU_ENCODE_ATTRIBUTES( \
        ATU_ROBA_SET_1, \
        ATU_ROBA_SET_0, \
        ATU_ROBA_SET_0, \
        ATU_ROBA_SET_0, \
        ATU_ROBA_SET_0, \
        ATU_ROBA_SET_0, \
        ATU_ROBA_SET_1, \
        ATU_ROBA_SET_0))

#define ATU_GET_ATUPS(atu_base) (                                     \
    (uint8_t)(((atu_base)->atubc & ATU_ATUBC_PS_MASK) >> ATU_ATUBC_PS_OFF))

/**
 * \brief Arm ATU device configuration structure
 */
struct atu_dev_cfg_t {
    const uintptr_t base;                         /*!< ATU base address */
};

/**
 * \brief Arm ATU device structure
 */
struct atu_dev_t {
    const struct atu_dev_cfg_t *const cfg;      /*!< ATU configuration */
};

/*
 * @brief API to set the start address of the logical region
 *
 * @param[in]  dev      device
 * @param[in]  region   defines which region's data to read
 * @param[in]  address  logical address of the region
 *
 * @return  Returns whether error occured
 *
 */
enum atu_error_t atu_rse_set_start_logical_address(struct atu_dev_t *dev, uint8_t region,
                                                   uint32_t address);

/*
 * @brief API to get the start  address of the logical region
 *
 * @param[in]  dev      device
 * @param[in]  region   defines which region's data to read
 * @param[out] address  logical address of the region
 *
 * @return Returns whether error occured
 *
 */
enum atu_error_t atu_rse_get_start_logical_address(struct atu_dev_t *dev, uint8_t region,
                                                   uint32_t *address);

/*
 * @brief API to set the end address of the logical region
 *
 * @param[in]  dev      device
 * @param[in]  region   defines which region's data to read
 * @param[out] address  end address
 *
 * @return Returns whether error occured
 *
 */
enum atu_error_t atu_rse_set_end_logical_address(struct atu_dev_t *dev, uint8_t region,
                                                 uint32_t address);

/*
 * @brief API to get the end address of the logical region
 *
 * @param[in]  dev      device
 * @param[in]  region   defines which region's data to read
 * @param[out] address  end address
 *
 * @return Returns whether error occured
 *
 */
enum atu_error_t atu_rse_get_end_logical_address(struct atu_dev_t *dev, uint8_t region,
                                                 uint32_t *address);

/*
 * @brief API to set the offset of the pysical region
 *
 * @param[in]  dev      device
 * @param[in]  region   defines which region's data to read
 * @param[out] offset   size of the region
 *
 * @return None
 *
 */
void atu_rse_set_physical_region_offset(struct atu_dev_t *dev, uint8_t region, uint64_t offset);

/*
 * @brief API to get the offset of the pysical region
 *
 * @param[in]  dev      device
 * @param[in]  region   defines which region's data to read
 * @param[out] offset   size of the region
 *
 * @return Returns whether error occured
 *
 */
enum atu_error_t atu_rse_get_physical_region_offset(struct atu_dev_t *dev, uint8_t region,
                                                    uint64_t *offset);

/*
 * @brief API to program bus attributes of a region
 *
 * @param[in] dev       Pointer to ATU device structure
 * @param[in] region    ATU Region number
 * @param[in] val       Out bus attribute value
 *
 * @return atu_error_t  On success, ATU_ERR_NONE is returned.
 *                      On failure, appropriate error code is returned.
 *
 */
enum atu_error_t atu_rse_set_bus_attributes(struct atu_dev_t *dev, uint8_t region, uint32_t val);

/*
 * @brief API to get the bus attributes of a region
 *
 * @param[in] dev       Pointer to ATU device structure
 * @param[in] region    ATU Region number
 * @param[in] val       Out bus attribute value
 *
 * @return atu_error_t  On success, ATU_ERR_NONE is returned.
 *                      On failure, appropriate error code is returned.
 *
 */
enum atu_error_t atu_rse_get_bus_attributes(struct atu_dev_t *dev, uint8_t region, uint32_t *val);

/*
 * \brief Gets the number of ATU regions supported.
 *
 * \param[in] dev                ATU device struct \ref atu_dev_t
 *
 * \return Returns region count
 *
 * \note This function doesn't check if dev is NULL.
 */
uint8_t atu_rse_get_supported_region_count(struct atu_dev_t *dev);

/*
 * \brief Check if the region index is supported
 *
 * \param[in] dev                ATU device struct \ref atu_dev_t
 * \param[in] region             Region index
 *
 * \return Returns whether region is supported
 *
 * \note This function doesn't check if dev is NULL.
 */
enum atu_error_t atu_rse_check_supported_region(struct atu_dev_t *dev, uint8_t region);

/*
 * \brief Creates and enables an ATU region.
 *
 * \param[in] dev                ATU device struct \ref atu_dev_t
 * \param[in] region             ATU region number to be initialized
 * \param[in] log_addr           Logical address
 * \param[in] phys_addr          Physical address
 * \param[in] size               Region size
 *
 * \return Returns error code as specified in \ref atu_error_t
 */
enum atu_error_t atu_rse_initialize_region(struct atu_dev_t *dev, uint8_t region,
                                           uint32_t log_addr, uint64_t phys_addr,
                                           uint32_t size);

/*
* \brief Uninitializes an ATU region.
*
* \param[in] dev                ATU device struct \ref atu_dev_t
* \param[in] region             ATU region number to be uninitialized
*
* \return Returns error code as specified in \ref atu_error_t
*/
enum atu_error_t atu_rse_uninitialize_region(struct atu_dev_t *dev, uint8_t region);

#ifdef __cplusplus
}
#endif

#endif /* __ATU_RSE_DRV_H__ */
