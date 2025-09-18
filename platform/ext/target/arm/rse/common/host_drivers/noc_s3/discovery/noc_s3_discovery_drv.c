/*
 * Copyright (c) 2023, Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
#include "noc_s3_discovery_drv.h"
#include "noc_s3_discovery_reg.h"
#ifdef NOC_S3_PRETTY_PRINT_LOG_ENABLED
#include "util/noc_s3_util.h"
#endif

#include <stdbool.h>
#include <stdlib.h>

#define FMU_CHECK(node_base) \
                (*(uint32_t *)((node_base) + FMU_CHECK_OFFSET_ADDRESS))

#define NOC_S3_NULL_COMP_TYPE       (NOC_S3_ASNI)
#define NOC_S3_NULL_COMP_ID         (0)
#define NOC_S3_NULL_SUBFEAT_TYPE    (0)

/**
 * \brief NoC S3 Discovery operations enumerations
 */
enum noc_s3_discovery_ops {
    NOC_S3_DISCOVER_SUBFEATURE,
    NOC_S3_DISCOVER_COMPONENT,
    NOC_S3_DISCOVER_FMU,
#ifdef NOC_S3_PRETTY_PRINT_LOG_ENABLED
    NOC_S3_DISCOVER_PRINT_TREE,
#endif
};

#ifdef NOC_S3_PRETTY_PRINT_LOG_ENABLED
#define NOC_S3_DISCOVER_SUBFEAT_TAB_SIZE  (5)
#define NOC_S3_DISCOVER_COMP_TAB_SIZE     (4)
#define NOC_S3_DISCOVER_TAB_SIZE(type)    (noc_s3_type_is_domain(type) ?    \
                                            (int)type :                     \
                                            NOC_S3_DISCOVER_COMP_TAB_SIZE)
#define NOC_S3_NULL_ID      (UINT32_MAX)

#define X(name) [NOC_S3_##name] = #name,
static const char * const noc_s3_discover_comp_node_string[] = {
    X(CFGNI)
    X(VD)
    X(PD)
    X(CD)
    X(ASNI)
    X(AMNI)
    X(PMU)
    X(HSNI)
    X(HMNI)
    X(PMNI)
};

static const char * const noc_s3_discover_subfeat_node_string[] = {
    X(APU)
    X(PSAM)
    X(FCU)
    X(IDM)
};

#undef X

static void noc_s3_discover_print_node(
    const int tab_size, const char *node_label,
    const uint32_t node_id, const uint32_t node_off_addr)
{
    for (int tab = 0; tab < tab_size; ++tab) {
        NOC_S3_DRV_LOG("    ");
    }

    NOC_S3_DRV_LOG("%s", node_label);

    if (node_id != NOC_S3_NULL_ID) {
        NOC_S3_DRV_LOG("[%d]", node_id);
    }

    NOC_S3_DRV_LOG(" @ 0x%lx\r\n", node_off_addr);
}
#endif

static inline bool noc_s3_type_is_domain(
    const enum noc_s3_node_type_value type)
{
    return ((type) == NOC_S3_CFGNI) || ((type) == NOC_S3_VD) ||
           ((type) == NOC_S3_PD) || ((type) == NOC_S3_CD);
}

static inline bool noc_s3_type_is_component(
    const enum noc_s3_node_type_value type)
{
    return ((type) == NOC_S3_ASNI) || ((type) == NOC_S3_AMNI) ||
           ((type) == NOC_S3_PMU) || ((type) == NOC_S3_HSNI) ||
           ((type) == NOC_S3_HMNI) || ((type) == NOC_S3_PMNI);
}

static inline bool noc_s3_type_is_subfeature(
    const enum noc_s3_subfeature_type_value type)
{
    return ((type) == NOC_S3_APU) || ((type) == NOC_S3_PSAM) ||
           ((type) == NOC_S3_FCU) || ((type) == NOC_S3_IDM);
}

static enum noc_s3_err noc_s3_check_interconnect_part_number(
    const struct noc_s3_dev *dev)
{
    struct noc_s3_global_reg_map* reg;
    if (dev != NULL && dev->periphbase == (uintptr_t)NULL) {
        return NOC_S3_ERR_INVALID_ARG;
    }

    reg = (struct noc_s3_global_reg_map*)dev->periphbase;

    if ((reg->peripheral_id0 & NOC_S3_GLOBAL_PERIPHERAL_ID0 &
                                            ~NOC_S3_PID0_PART_NUM) != 0 &&
        (reg->peripheral_id1 & NOC_S3_GLOBAL_PERIPHERAL_ID1 &
                                            ~NOC_S3_PID1_PART_NUM) != 0) {
        return NOC_S3_DEVICE_INVALID;
    }

    return NOC_S3_SUCCESS;
}

/* Initialize a discovery node variable to CFGNI root node. */
static enum noc_s3_err noc_s3_discovery_init(struct noc_s3_discovery_node *node)
{
    if (node == NULL) {
        return NOC_S3_ERR_INVALID_ARG;
    }

    node->node_type = NOC_S3_CFGNI;
    node->node_id = 0;
    node->node_off_addr = 0;

    return NOC_S3_SUCCESS;
}

/* Performs discovery of subfeatures for a given component node. */
static enum noc_s3_err noc_s3_discover_subfeature(
    const struct noc_s3_dev *dev,
    const enum noc_s3_discovery_ops mode,
    const uint32_t component_offset_address,
    const enum noc_s3_subfeature_type_value subfeature_node_type,
    uint32_t *ret_off_addr)
{
    uint32_t s_idx;
    struct noc_s3_component_cfg_hdr *component_hdr;
    enum noc_s3_subfeature_type_value s_type;

    if (dev == NULL || dev->periphbase == (uintptr_t)NULL) {
        return NOC_S3_ERR_INVALID_ARG;
    }

    if (!noc_s3_type_is_subfeature(subfeature_node_type)) {
        return NOC_S3_ERR_INVALID_ARG;
    }

    component_hdr = (struct noc_s3_component_cfg_hdr *)(dev->periphbase +
                                                    component_offset_address);

    for(s_idx = 0; s_idx < component_hdr->num_subfeatures; ++s_idx) {
        s_type = component_hdr->subfeature[s_idx].type;

        if (!noc_s3_type_is_subfeature(s_type)) {
            return NOC_S3_ERR_NOT_PERMITTED;
        }

        switch (mode) {
        case NOC_S3_DISCOVER_SUBFEATURE:
            if (s_type == subfeature_node_type) {
                *ret_off_addr = component_hdr->subfeature[s_idx].pointer;
                return NOC_S3_SUCCESS;
            }
            break;
#ifdef NOC_S3_PRETTY_PRINT_LOG_ENABLED
        case NOC_S3_DISCOVER_PRINT_TREE:
            noc_s3_discover_print_node(NOC_S3_DISCOVER_SUBFEAT_TAB_SIZE,
                noc_s3_discover_subfeat_node_string[s_type], NOC_S3_NULL_ID,
                component_hdr->subfeature[s_idx].pointer);
            break;
#endif
        default:
            return NOC_S3_ERR_INVALID_ARG;
        }
    }

    return NOC_S3_ERR_NOT_FOUND;
}

/*
 * Recursive discovery function which traverse through all node types to perform
 * a certain discovery operation.
 */
static enum noc_s3_err noc_s3_discover(
    const struct noc_s3_dev *dev,
    const struct noc_s3_discovery_node *cfg_node,
    const enum noc_s3_discovery_ops mode,
    const enum noc_s3_node_type_value component_node_type,
    const uint32_t component_node_id,
    const enum noc_s3_subfeature_type_value subfeature_node_type,
    uint32_t *ret_off_addr)
{
    enum noc_s3_err err;
    struct noc_s3_discovery_node node;
    struct noc_s3_domain_cfg_hdr *domain_cfg_ptr, *c_hdr;
    uint32_t c_off_addr, c_idx, s_idx;
    uint32_t hdr_base;
    bool should_skip_discovery;

    if (dev == NULL || dev->periphbase == (uintptr_t)NULL) {
        return NOC_S3_ERR_INVALID_ARG;
    }

    if (cfg_node == NULL) {
        return NOC_S3_ERR_INVALID_ARG;
    }

    hdr_base = (uint32_t)dev->periphbase + cfg_node->node_off_addr;

    if (!noc_s3_type_is_component(component_node_type) ||
        !noc_s3_type_is_subfeature(subfeature_node_type)) {
        return NOC_S3_ERR_INVALID_ARG;
    }

    /* Check interconnect part number */
    if (cfg_node->node_type == NOC_S3_CFGNI) {
        err = noc_s3_check_interconnect_part_number(dev);
        if (err != NOC_S3_SUCCESS) {
            return err;
        }
    }

    /*
     * FMU check requires the read at 0xFFE0 offset which can only be done
     * for 64KB config node granularity mode.
     */
    if (dev->config_node_granularity == NOC_S3_64KB_CONFIG_NODES) {
        if ((cfg_node->node_type != NOC_S3_CFGNI) &&
            FMU_CHECK(hdr_base) != 0) {
            if (mode == NOC_S3_DISCOVER_FMU) {
                *ret_off_addr = cfg_node->node_off_addr;
                return NOC_S3_SUCCESS;
            }
#ifdef NOC_S3_PRETTY_PRINT_LOG_ENABLED
            else if (mode == NOC_S3_DISCOVER_PRINT_TREE) {
                noc_s3_discover_print_node(NOC_S3_DISCOVER_COMP_TAB_SIZE,
                    "FMU", NOC_S3_NULL_ID, cfg_node->node_off_addr);
            }
#endif
            return NOC_S3_ERR_NOT_FOUND;
        }
    }

    switch (mode) {
    case NOC_S3_DISCOVER_COMPONENT:
        if (noc_s3_type_is_component(cfg_node->node_type)) {
            if (cfg_node->node_id == component_node_id &&
                cfg_node->node_type == component_node_type) {
                *ret_off_addr = cfg_node->node_off_addr;
                return NOC_S3_SUCCESS;
            }
        }
        break;
#ifdef NOC_S3_PRETTY_PRINT_LOG_ENABLED
        case NOC_S3_DISCOVER_PRINT_TREE:
            noc_s3_discover_print_node(
                NOC_S3_DISCOVER_TAB_SIZE(cfg_node->node_type),
                noc_s3_discover_comp_node_string[cfg_node->node_type],
                cfg_node->node_id, cfg_node->node_off_addr);
#endif
    default:
        /* Do nothing */
        break;
    }

    if (noc_s3_type_is_domain(cfg_node->node_type)) {
        domain_cfg_ptr = (struct noc_s3_domain_cfg_hdr *)hdr_base;
        for(c_idx = 0; c_idx < domain_cfg_ptr->child_node_info; ++c_idx) {
            /* Skip discovering node based on the skip node list */
            should_skip_discovery = false;
            if (dev->skip_discovery_list != NULL) {
                for (s_idx = 0;
                     s_idx < dev->skip_discovery_list->skip_node_count;
                     ++s_idx) {
                    if (dev->skip_discovery_list->skip_node_data[s_idx]
                         .parent_node->type == cfg_node->node_type &&
                        dev->skip_discovery_list->skip_node_data[s_idx]
                         .parent_node->id == cfg_node->node_id)
                    {
                        if (dev->skip_discovery_list->skip_node_data[s_idx]
                             .node_idx == c_idx) {
                            should_skip_discovery = true;
                            break;
                        }
                    }
                }
            }

            if (should_skip_discovery) {
                continue;
            }

            c_off_addr = domain_cfg_ptr->x_pointers[c_idx];
            c_hdr = (struct noc_s3_domain_cfg_hdr *)(dev->periphbase +
                                                                c_off_addr);
            /* Recursively discover child node */
            node = (struct noc_s3_discovery_node) {
               .node_type = (c_hdr->node_type &
                                            NOC_S3_DOMAIN_NODE_TYPE_MSK) >>
                            NOC_S3_DOMAIN_NODE_TYPE_POS,
               .node_id = (c_hdr->node_type & NOC_S3_DOMAIN_NODE_ID_MSK) >>
                          NOC_S3_DOMAIN_NODE_ID_POS,
               .node_off_addr = c_off_addr
            };

            err = noc_s3_discover(dev, &node, mode, component_node_type,
                                  component_node_id, subfeature_node_type,
                                  ret_off_addr);
            if (err != NOC_S3_ERR_NOT_FOUND) {
                return err;
            }
        }
    } else if (noc_s3_type_is_component(cfg_node->node_type)) {
#ifdef NOC_S3_PRETTY_PRINT_LOG_ENABLED
        /*
         * Don't skip any node and traverse completely to print discovery tree.
         */
        if (mode != NOC_S3_DISCOVER_PRINT_TREE) {
#endif
            /* Skip traversing of components which is not requested */
            if (cfg_node->node_id != component_node_id ||
                cfg_node->node_type != component_node_type) {
                return NOC_S3_ERR_NOT_FOUND;
            }
#ifdef NOC_S3_PRETTY_PRINT_LOG_ENABLED
        }
#endif
        /* Skip since PMU doesn't have children */
        if (cfg_node->node_type == NOC_S3_PMU) {
            return NOC_S3_ERR_NOT_FOUND;
        }

        return noc_s3_discover_subfeature(dev, mode, cfg_node->node_off_addr,
                                          subfeature_node_type, ret_off_addr);
    } else {
        return NOC_S3_ERR_INVALID_ARG;
    }

    return NOC_S3_ERR_NOT_FOUND;
}

enum noc_s3_err noc_s3_fetch_subfeature_offset(
    const struct noc_s3_dev *dev,
    const enum noc_s3_node_type_value component_node_type,
    const uint32_t component_node_id,
    const enum noc_s3_subfeature_type_value subfeature_node_type,
    uint32_t *ret_off_addr)
{
    enum noc_s3_err err;
    struct noc_s3_discovery_node root;

    err = noc_s3_discovery_init(&root);
    if (err != NOC_S3_SUCCESS) {
        return err;
    }


    return noc_s3_discover(dev, &root, NOC_S3_DISCOVER_SUBFEATURE,
                           component_node_type, component_node_id,
                           subfeature_node_type, ret_off_addr);
}

enum noc_s3_err noc_s3_fetch_component_offset(
    const struct noc_s3_dev *dev,
    const enum noc_s3_node_type_value component_node_type,
    const uint32_t component_node_id,
    uint32_t *ret_off_addr)
{
    enum noc_s3_err err;
    struct noc_s3_discovery_node root;

    err = noc_s3_discovery_init(&root);
    if (err != NOC_S3_SUCCESS) {
        return err;
    }

    return noc_s3_discover(dev, &root, NOC_S3_DISCOVER_COMPONENT,
                           component_node_type, component_node_id,
                           NOC_S3_NULL_SUBFEAT_TYPE, ret_off_addr);
}

enum noc_s3_err noc_s3_fetch_fmu_offset(
    const struct noc_s3_dev *dev, uint32_t *ret_off_addr)
{
    enum noc_s3_err err;
    struct noc_s3_discovery_node root;

    err = noc_s3_discovery_init(&root);
    if (err != NOC_S3_SUCCESS) {
        return err;
    }

    return noc_s3_discover(dev, &root, NOC_S3_DISCOVER_FMU,
                           NOC_S3_NULL_COMP_TYPE, NOC_S3_NULL_COMP_ID,
                           NOC_S3_NULL_SUBFEAT_TYPE, ret_off_addr);
}

#ifdef NOC_S3_PRETTY_PRINT_LOG_ENABLED
void noc_s3_print_discovery_tree(const struct noc_s3_dev *dev,
                                 const char *tree_label)
{
    enum noc_s3_err err;
    struct noc_s3_discovery_node root;

    err = noc_s3_discovery_init(&root);
    if (err != NOC_S3_SUCCESS) {
        return;
    }

    NOC_S3_DRV_LOG_HEADING("Discovery tree for %s", tree_label);
    NOC_S3_DRV_LOG("\r\n");

    /* Discard any error */
    noc_s3_discover(dev, &root, NOC_S3_DISCOVER_PRINT_TREE,
                    NOC_S3_NULL_COMP_TYPE, NOC_S3_NULL_COMP_ID,
                    NOC_S3_NULL_SUBFEAT_TYPE, NULL);
}
#endif
