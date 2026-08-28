/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef __TFM_COPY_ZERO_TABLES_H__
#define __TFM_COPY_ZERO_TABLES_H__

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Initialise the RW data and bss regions described by the CMSIS scatter
 * __copy_table__/__zero_table__.  Needed by startups that enter a C library
 * whose own crt0 initialises only the single __data/__bss region, which is
 * what happens with CONFIG_TFM_INCLUDE_STDLIBC and picolibc.
 */
void tfm_copy_zero_tables(void);

#ifdef __cplusplus
}
#endif

#endif /* __TFM_COPY_ZERO_TABLES_H__ */
