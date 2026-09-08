/* SPDX-License-Identifier: BSD-3-Clause */
/*
 * Copyright (c) 2026, STMicroelectronics - All Rights Reserved
 * Author(s): Ludovic Barre, <ludovic.barre@foss.st.com> for STMicroelectronics.
 */
#ifndef __STM32_RIF_H
#define __STM32_RIF_H

#include <dt-bindings/rif/stm32mp25-rif.h>

/* Generic RIF utility */
#define _PERIPH_IDS_PER_REG	32
#define SEC_PRIV_X_OFFSET(_id)	(U(0x4) * (_id / _PERIPH_IDS_PER_REG))
#define SEC_PRIV_X_SHIFT(_id)	(_id % _PERIPH_IDS_PER_REG)
#define CID_SEM_X_OFFSET(_id)	(U(0x8) * (_id))

/* These macro and struct are used by rifsc and rif aware devices*/
#define RIFPROT_FLD(_field, _node_id, _prop, _idx) \
	_FLD_GET(_field, DT_PROP_BY_IDX(_node_id, _prop, _idx))

#define DT_RIFPROT_CFG(_node_id, _prop, _idx)			\
	{							\
		.id = RIFPROT_FLD(RIFPROT_PER_ID,		\
				  _node_id, _prop, _idx),	\
		.sec = RIFPROT_FLD(RIFPROT_SEC,			\
				   _node_id, _prop, _idx),	\
		.priv = RIFPROT_FLD(RIFPROT_PRIV,		\
				    _node_id, _prop, _idx),	\
		.lock = RIFPROT_FLD(RIFPROT_LOCK,		\
				    _node_id, _prop, _idx),	\
		.cid_attr = RIFPROT_FLD(RIFPROT_PERx_CID,	\
					_node_id, _prop, _idx),	\
	}

#define RIFPROT_CFG(arg)					\
	{							\
		.id = _FLD_GET(RIFPROT_PER_ID, arg),		\
		.sec = _FLD_GET(RIFPROT_SEC, arg),		\
		.priv = _FLD_GET(RIFPROT_PRIV, arg),		\
		.cid_attr = _FLD_GET(RIFPROT_PERx_CID, arg),	\
	}

struct rifprot_controller;

struct rifprot_config {
	uint32_t id;
	bool sec;
	bool priv;
	bool lock;
	uint32_t cid_attr;
};

/*
 * Loop over each element of rifprot_cfg table
 */
#define for_each_rifprot_cfg(rcfg_table, rcfg_elem, nrcfg, i)		\
	if (!rcfg_table) {} else					\
	for (i = 0, rcfg_elem = ((struct rifprot_config *)rcfg_table);	\
	     i < (nrcfg);						\
	     i++, rcfg_elem++)

#define RIFPROT_BASE(_sec, _priv, _cid, _sem, _lock)			\
	{								\
		.sec = _sec,						\
		.priv = _priv,						\
		.cid = _cid,						\
		.sem = _sem,						\
		.lock = _lock,						\
	}

struct rif_base {
	uintptr_t sec;
	uintptr_t priv;
	uintptr_t cid;
	uintptr_t sem;
	uintptr_t lock;
};

typedef int (*_rifprot_init_t)(const struct rifprot_controller *ctl);
typedef int (*_rifprot_set_conf_t)(const struct rifprot_controller *ctl,
				   struct rifprot_config *cfg);
typedef int (*_rifprot_release_conf_t)(const struct rifprot_controller *ctl, uint32_t id);
typedef int (*_rifprot_check_access_t)(const struct rifprot_controller *ctl, uint32_t id);
typedef int (*_rifprot_sem_t)(const struct rifprot_controller *ctl,
				  uint32_t id);
typedef int (*_rifprot_rel_sem_t)(const struct rifprot_controller *ctl,
				  uint32_t id);

struct rif_ops {
	_rifprot_init_t init;
	_rifprot_set_conf_t set_conf;
	_rifprot_release_conf_t release_conf;
	_rifprot_check_access_t check_access;
	_rifprot_sem_t acquire_sem;
	_rifprot_sem_t release_sem;
};

struct rifprot_controller {
	const struct device *dev;
        const struct rif_base *rbase;
	const struct rif_ops *ops;
	int nperipherals;
        const struct rifprot_config *rifprot_cfg;
        const int nrifprot;
};

/**
 * @brief Obtain the variable name storing rifprot config for the given DT node
 * identifier.
 *
 * @param node_id Node identifier.
 */
#define RIFPROT_CONFIG_NAME(node_id) \
	_CONCAT(__rifprot_cfg, DEVICE_DT_NAME_GET(node_id))

/**
 * @brief Obtain the variable name storing rifprot controller for the given DT node
 * identifier.
 *
 * @param node_id Node identifier.
 */
#define RIFPROT_CTRL_NAME(node_id) \
	_CONCAT(__rifprot_ctrl, DEVICE_DT_NAME_GET(node_id))

#define RIFPROT_CONFIG_INIT(node_id)								\
	COND_CODE_1(DT_NODE_HAS_PROP(node_id, st_protreg),					\
		    (DT_FOREACH_PROP_ELEM_SEP(node_id, st_protreg, DT_RIFPROT_CFG, (,))),	\
		    ())

/**
 * @brief Define all the rifprot configs for the given node identifier.
 *
 * @param node_id Node identifier.
 */
#define DT_RIFPROT_CONFIG_DEFINE(node_id)				\
	const struct rifprot_config RIFPROT_CONFIG_NAME(node_id)[] = {	\
		RIFPROT_CONFIG_INIT(node_id)				\
	}

#define DT_INST_RIFPROT_CONFIG_DEFINE(inst) \
	DT_RIFPROT_CONFIG_DEFINE(DT_DRV_INST(inst))

/**
 * @brief Obtain a reference to the rifprot configs given a node
 * identifier.
 *
 * @param node_id Node identifier.
 */
#define DT_RIFPROT_CONFIG_GET(node_id) RIFPROT_CONFIG_NAME(node_id)

/**
 * @brief Obtain a reference to the rifprot config given current
 * compatible instance number.
 *
 * @param inst Instance number.
 *
 * @see #DT_RIFPROT_CONFIG_GET
 */
#define DT_INST_RIFPROT_CONFIG_GET(inst) \
	DT_RIFPROT_CONFIG_GET(DT_DRV_INST(inst))

/**
 * @brief Helper macro to define rifprot controller for a given node identifier.
 *
 * @param node_id Node identifier.
 * @param _rbase reference on register adresses (sec, priv, cid, sem)
 * @param _ops reference on specific operating functions,
 * if NULL the default functions are used.
 * @param _nper number of peripherals managed by controller.
 */
#define DT_RIFPROT_CTRL_DEFINE(node_id, _rbase, _ops, _nper)			\
	COND_CODE_1(DT_NODE_HAS_PROP(node_id, st_protreg),(			\
	DT_RIFPROT_CONFIG_DEFINE(node_id);					\
	extern const struct rifprot_controller RIFPROT_CTRL_NAME(node_id);	\
	const struct rifprot_controller RIFPROT_CTRL_NAME(node_id) = {		\
		.dev = DEVICE_DT_GET_OR_NULL(node_id),				\
		.rbase = _rbase,						\
		.ops = _ops,							\
		.nperipherals = _nper,						\
		.rifprot_cfg = DT_RIFPROT_CONFIG_GET(node_id),			\
		.nrifprot = ARRAY_SIZE(DT_RIFPROT_CONFIG_GET(node_id)),		\
	}),())

/**
 * @brief Helper macro to define rifprot controller for a  given current
 * compatible instance number.
 *
 * @param inst Instance number.
 * @see #DT_RIFPROT_CTRL_DEFINE
 */
#define DT_INST_RIFPROT_CTRL_DEFINE(inst, _rbase, _ops, _nper) \
	DT_RIFPROT_CTRL_DEFINE(DT_DRV_INST(inst), _rbase, _ops, _nper)

/**
 * @brief Obtain a reference to the rifprot controller given a node
 * identifier.
 *
 * @param node_id Node identifier.
 *
 * @return a @ref on rifprot controller if exist else `NULL`.
 *
 */
#define DT_RIFPROT_CTRL_GET(node_id)				\
	COND_CODE_1(DT_NODE_HAS_PROP(node_id, st_protreg),	\
		    (&RIFPROT_CTRL_NAME(node_id)), (NULL))

/**
 * @brief Obtain a reference to the rifprot controller given current
 * compatible instance number.
 *
 * @param inst Instance number.
 *
 * @see #DT_RIFPROT_CTRL_GET
 */
#define DT_INST_RIFPROT_CTRL_GET(inst) \
	DT_RIFPROT_CTRL_GET(DT_DRV_INST(inst))

/**
 * @brief Helper macro to declare a external rifprot controller for a given node
 * identifier.
 *
 * @param node_id Node identifier.
 */
#define DT_RIFPROT_CTRL_EXTERN(node_id) \
	extern const struct rifprot_controller RIFPROT_CTRL_NAME(node_id)

/**
 * @brief Helper macro to declare a external rifprot controller for a given
 * current compatible instance number.
 *
 * @param inst Instance number.
 */
#define DT_INST_RIFPROT_CTRL_EXTERN(inst) \
	DT_RIFPROT_CTRL_EXTERN(DT_DRV_INST(inst))

#if (IS_ENABLED(STM32_NSEC))
static inline int stm32_rifprot_init(const struct rifprot_controller *ctl)
{
	return 0;
}

static inline int stm32_rifprot_release_conf(const struct rifprot_controller *ctl, uint32_t id)
{
	return 0;
}

static inline int stm32_rifprot_set_conf(const struct rifprot_controller *ctl,
					 struct rifprot_config *cfg)
{
	return 0;
}

static inline int stm32_rifprot_check_access(const struct rifprot_controller *ctl, uint32_t id)
{
	return 0;
}
#else
/**
 * @brief Initialize the rif controller
 *
 * On success, all the configurations found in st,protreg are applied
 *
 * @param ctl reference on rifprot controller.
 * @return 0 on success, negative errno on failure.
 */
int stm32_rifprot_init(const struct rifprot_controller *ctl);

/**
 * @brief Set one config of rif controller
 *
 * On success, the access is set and ready when this function
 * returns.
 *
 * @param ctl reference on rif controller.
 * @param cfg reference on rif config to set
 * @return 0 on success, negative errno on failure.
 */
int stm32_rifprot_set_conf(const struct rifprot_controller *ctl,
			   struct rifprot_config *cfg);

/**
 * @brief Release config id on rif controller default config
 *
 * On success, the default config of rif controller is set and ready.
 *
 * @param ctl reference on rif controller.
 * @param id  rif config id
 * @return 0 on success, negative errno on failure.
 */
int stm32_rifprot_release_conf(const struct rifprot_controller *ctl, uint32_t id);

/**
 * @brief only Check if the access is authorized for the consumer
 * according to the configuration of rif controller.
 *
 * @param ctl reference on rif controller.
 * @param id  rif config id
 * @return 0 on success, negative errno on failure.
 */
int stm32_rifprot_check_access(const struct rifprot_controller *ctl, uint32_t id);

/**
 * @brief Acquire semaphore id of rif controller
 *
 * On success, the semaphore is taken.
 *
 * @param ctl reference on rif controller.
 * @param id resource id of controller.
 * @return 0 on success, negative errno on failure.
 */
int stm32_rifprot_acquire_sem(const struct rifprot_controller *ctl,
			      uint32_t id);

/**
 * @brief Release semaphore id of rif controller
 *
 * On success, the semaphore is released.
 *
 * @param ctl reference on rif controller.
 * @param id resource id of controller.
 * @return 0 on success, negative errno on failure.
 */
int stm32_rifprot_release_sem(const struct rifprot_controller *ctl,
			      uint32_t id);

#endif
#endif /* __STM32_RIF_H */
