/*
 * Copyright (c) 2021-2024, Arm Limited. All rights reserved.
 * Copyright (c) 2022 Cypress Semiconductor Corporation (an Infineon
 * company) or an affiliate of Cypress Semiconductor Corporation. All rights
 * reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
#include <limits.h>
#include <stdint.h>
#include "config_impl.h"
#include "lists.h"
#include "memory_symbols.h"
#include "region_defs.h"
#include "spm.h"
#include "tfm_hal_interrupt.h"
#include "tfm_plat_defs.h"
#include "utilities.h"
#include "ffm/backend.h"
#include "load/partition_defs.h"
#include "load/spm_load_api.h"
#include "load/service_defs.h"
#include "psa/client.h"

static uintptr_t ldinf_sa     = PART_INFOLIST_START;
static uintptr_t ldinf_ea     = PART_INFOLIST_END;
static uintptr_t part_pool_sa = PART_INFORAM_START;
static uintptr_t part_pool_ea = PART_INFORAM_END;
static uintptr_t serv_pool_sa = SERV_INFORAM_START;
static uintptr_t serv_pool_ea = SERV_INFORAM_END;

/* Allocate runtime space for partition. Panic if pool runs out. */
static struct partition_t *tfm_allocate_partition_assuredly(void)
{
    struct partition_t *p_part_allocated = (struct partition_t *)part_pool_sa;

    part_pool_sa += sizeof(struct partition_t);
    if (part_pool_sa > part_pool_ea) {
        tfm_core_panic();
    }

    return p_part_allocated;
}

/* Allocate runtime space for services. Panic if pool runs out. */
static struct service_t *tfm_allocate_service_assuredly(uint32_t service_count)
{
    struct service_t *p_serv_allocated = (struct service_t *)serv_pool_sa;

    if (service_count == 0) {
        return NULL;
    }

    serv_pool_sa += service_count * sizeof(struct service_t);
    if (serv_pool_sa > serv_pool_ea) {
        tfm_core_panic();
    }

    return p_serv_allocated;
}

/*
 * Insert a partition into load list.
 * The load list is sorted according to partitions' loading order values.
 * In SFN backend, a partition with a smaller loading order value is loaded and
 * initialized earlier.
 */
static void insert_a_partition_load_list(struct partition_head_t *head,
                                         struct partition_t *partition)
{
    struct partition_t *p_part, *p_part_prev;

    if (UNI_LIST_IS_EMPTY(head, next)) {
        UNI_LIST_INSERT_AFTER(head, partition, next);
        return;
    }

    p_part_prev = NULL;
    UNI_LIST_FOREACH(p_part, head, next) {
        if (p_part->p_ldinf->load_order > partition->p_ldinf->load_order) {
            if (p_part_prev == NULL) {
                UNI_LIST_INSERT_AFTER(head, partition, next);
            } else {
                UNI_LIST_INSERT_AFTER(p_part_prev, partition, next);
            }
            return;
        }
        p_part_prev = p_part;
    }
    UNI_LIST_INSERT_AFTER(p_part_prev, partition, next);
}

struct partition_t *load_a_partition_assuredly(struct partition_head_t *head)
{
    const struct partition_load_info_t *p_ptldinf;
    struct partition_t                 *partition;
    int32_t client_id_base;
    int32_t client_id_limit;

    if (!head) {
        tfm_core_panic();
    }

    if (((UINTPTR_MAX - ldinf_sa) < sizeof(struct partition_load_info_t)) ||
        ((ldinf_sa + sizeof(struct partition_load_info_t)) >= ldinf_ea)) {
        return NO_MORE_PARTITION;
    }

    p_ptldinf = (const struct partition_load_info_t *)ldinf_sa;

    if (((UINTPTR_MAX - ldinf_sa) < (LOAD_INFSZ_BYTES(p_ptldinf))) ||
        ((ldinf_sa + (LOAD_INFSZ_BYTES(p_ptldinf))) > ldinf_ea))   {
        tfm_core_panic();
    }

    /* Magic ensures data integrity */
    if ((p_ptldinf->psa_ff_ver & PARTITION_INFO_MAGIC_MASK)
        != PARTITION_INFO_MAGIC) {
        tfm_core_panic();
    }

    if ((p_ptldinf->psa_ff_ver & PARTITION_INFO_VERSION_MASK)
        > PSA_FRAMEWORK_VERSION) {
        tfm_core_panic();
    }

    if (p_ptldinf->pid < 0) {
        /* 0 is the internal NS Agent, besides the normal positive PIDs */
        tfm_core_panic();
    }

    if (p_ptldinf->client_id_base > p_ptldinf->client_id_limit) {
        tfm_core_panic();
    }

    /* Client ID range checks */
    if (IS_NS_AGENT(p_ptldinf)) {
        /* Check that the base and limit are valid */
        if ((p_ptldinf->client_id_base >= 0) ||
            (p_ptldinf->client_id_limit >= 0) ||
            (p_ptldinf->client_id_base > p_ptldinf->client_id_limit)) {
            tfm_core_panic();
        }
        /* Check for overlaps between partitions */
        UNI_LIST_FOREACH(partition, head, next) {
            if (!IS_NS_AGENT(partition->p_ldinf)) {
                continue;
            }
            client_id_base = partition->p_ldinf->client_id_base;
            client_id_limit = partition->p_ldinf->client_id_limit;
            if ((p_ptldinf->client_id_limit >= client_id_base) &&
                (p_ptldinf->client_id_base <= client_id_limit)) {
                tfm_core_panic();
            }
        }
    }

    partition = tfm_allocate_partition_assuredly();
    partition->p_ldinf = p_ptldinf;

    ldinf_sa += LOAD_INFSZ_BYTES(p_ptldinf);

    insert_a_partition_load_list(head, partition);

    return partition;
}

uint32_t load_services_assuredly(struct partition_t *p_partition,
                                 struct service_head_t *services_listhead,
                                 struct service_t **stateless_services_ref_tbl,
                                 size_t ref_tbl_size)
{
    uint32_t i, serv_ldflags, hidx, service_setting = 0;
    struct service_t *services;
    const struct partition_load_info_t *p_ptldinf;
    const struct service_load_info_t *p_servldinf;

    if (!p_partition || !services_listhead) {
        tfm_core_panic();
    }

    p_ptldinf = p_partition->p_ldinf;
    p_servldinf = LOAD_INFO_SERVICE(p_ptldinf);

    /*
     * 'services' CAN be NULL when no services, which is a rational result.
     * The loop won't go in the NULL case.
     */
    services = tfm_allocate_service_assuredly(p_ptldinf->nservices);
    for (i = 0; (i < p_ptldinf->nservices) && services; i++) {
        services[i].p_ldinf = &p_servldinf[i];
        services[i].partition = p_partition;
        services[i].next = NULL;

        BACKEND_SERVICE_SET(service_setting, &p_servldinf[i]);

        /* Populate the stateless service reference table */
        serv_ldflags = p_servldinf[i].flags;
        if (SERVICE_IS_STATELESS(serv_ldflags)) {
            if ((stateless_services_ref_tbl == NULL) ||
                (ref_tbl_size == 0) ||
                (ref_tbl_size !=
                 (STATIC_HANDLE_NUM_LIMIT * sizeof(struct service_t *)))) {
                tfm_core_panic();
            }

            hidx = SERVICE_GET_STATELESS_HINDEX(serv_ldflags);

            if ((hidx >= STATIC_HANDLE_NUM_LIMIT) ||
                stateless_services_ref_tbl[hidx]) {
                tfm_core_panic();
            }
            stateless_services_ref_tbl[hidx] = &services[i];
        }

        UNI_LIST_INSERT_AFTER(services_listhead, &services[i], next);
    }

    return service_setting;
}

void load_irqs_assuredly(struct partition_t *p_partition)
{
#if (CONFIG_TFM_FLIH_API == 1) || (CONFIG_TFM_SLIH_API == 1)
    const struct irq_load_info_t *p_irq_info;
    const struct partition_load_info_t *p_ldinf;
    uint32_t i;

    if (!p_partition) {
        tfm_core_panic();
    }

    p_ldinf = p_partition->p_ldinf;
    p_irq_info = LOAD_INFO_IRQ(p_ldinf);

    for (i = 0; i < p_ldinf->nirqs; i++) {
        p_partition->signals_allowed |= p_irq_info->signal;

        /* The client ID range of the irq should not beyond that of the partition. */
        if (IS_NS_AGENT_MAILBOX(p_ldinf)) {
            if ((p_irq_info->client_id_base > p_irq_info->client_id_limit) ||
               (p_irq_info->client_id_base < p_ldinf->client_id_base) ||
               (p_irq_info->client_id_limit > p_ldinf->client_id_limit)) {
                tfm_core_panic();
            }
        }

        if (p_irq_info->init(p_partition, p_irq_info) != TFM_HAL_SUCCESS) {
            tfm_core_panic();
        }

        if ((p_ldinf->psa_ff_ver & PARTITION_INFO_VERSION_MASK) == 0x0100) {
            tfm_hal_irq_enable(p_irq_info->source);
        } else if ((p_ldinf->psa_ff_ver & PARTITION_INFO_VERSION_MASK)
                                                                    == 0x0101) {
            tfm_hal_irq_disable(p_irq_info->source);
        }
        p_irq_info++;
    }
#endif
}
