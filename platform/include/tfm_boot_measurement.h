/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __TFM_BOOT_MEASUREMENT_H__
#define __TFM_BOOT_MEASUREMENT_H__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include "stdint.h"

#if EVENT_LOG_LIB
#include "event_log.h"
#endif

#if defined(PLATFORM_DEFAULT_MEASUREMENT_SLOTS)
enum boot_measurement_slot_t {
    BOOT_MEASUREMENT_SLOT_BL1_2 = 0,
    BOOT_MEASUREMENT_SLOT_BL2,
    BOOT_MEASUREMENT_SLOT_RT_0,
    BOOT_MEASUREMENT_SLOT_RT_1,
    BOOT_MEASUREMENT_SLOT_RT_2,
    BOOT_MEASUREMENT_SLOT_MAX = 32,
    BOOT_MEASUREMENT_SLOT_MAX_THEORETICAL = 63,  /* Slot index is stored in
                                                  * 6 bits in the shared
                                                  * memory area.
                                                  */
    __BOOT_MEASUREMENT_MAX_VAL = UINT32_MAX
};

#else
#include "tfm_plat_boot_measurement.h"
#endif /* PLATFORM_DEFAULT_MEASUREMENT_SLOTS */

/**
 * \brief                               Initializes the PCR index mapping for
 *                                      boot measurement slots.
 *
 * \note                                This function sets all internal PCR index
 *                                      mappings to -1, then assigns specific PCR
 *                                      indices to predefined boot measurement
 *                                      slots using the SET_MBOOT_SLOT_PCR macro.
 *
 * \retval 0                            The PCR index mapping was initialized
 *                                      successfully.
 * \retval 1                            A slot or PCR index was out of range
 *                                      during initialization.
 */
int init_pcr_index_for_boot_measurement(void);

/**
 * \brief                               Retrieves the PCR index associated with
 *                                      a given boot measurement slot.
 *
 * \param[in]  slot                     Boot measurement slot identifier. Must be
 *                                      less than BOOT_MEASUREMENT_SLOT_MAX.
 *
 * \return                              The PCR index assigned to the specified
 *                                      slot, or -1 if uninitialized.
 */
int8_t get_pcr_index_for_boot_measurement(uint8_t slot);


#if EVENT_LOG_LIB
/**
 * \brief                               Retrieves event log metadata associated with
 *                                      a given boot measurement slot.
 *
 * \param[in]  slot                     Boot measurement slot identifier. Must be
 *                                      less than BOOT_MEASUREMENT_SLOT_MAX.
 *
 * \param[out] event_log_metadata       Event log metadata associated with given slot.
 *                                      NULL if slot out of range.
 *
 * \return                              0 on success. -1 if slot out of range.
 *
 */
int get_event_log_metadata_for_measurement_slot(uint8_t slot, event_log_metadata_t *event_log_metadata);
#endif

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __TFM_BOOT_MEASUREMENT_H__ */
