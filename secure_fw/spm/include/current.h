/*
 * SPDX-FileCopyrightText: Copyright The TrustedFirmware-M Contributors
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
#ifndef __CURRENT_H__
#define __CURRENT_H__

#include <assert.h>
#include "thread.h"
#include "spm.h"

#if CONFIG_TFM_SPM_BACKEND_SFN != 1
/**
 * \brief Get and validate the current component.
 *
 * \return The current component.
 */
static inline struct partition_t *get_valid_current_comp(void);

static inline struct partition_t *get_valid_current_comp(void)
{
    struct partition_t *p = GET_CTX_OWNER(CURRENT_THREAD->p_context_ctrl);

    assert(p != NULL);
    return p;
}

/* Get current component */
#define GET_CURRENT_COMPONENT() get_valid_current_comp()
/* Set current component */
#define SET_CURRENT_COMPONENT(p) THRD_UPDATE_CUR_CTXCTRL(&(p)->ctx_ctrl)
#else
extern struct partition_t *p_current_partition;
/* Get current component */
#define GET_CURRENT_COMPONENT()  p_current_partition
/* Set current component */
#define SET_CURRENT_COMPONENT(p) p_current_partition = p
#endif

#endif /* __CURRENT_H__ */
