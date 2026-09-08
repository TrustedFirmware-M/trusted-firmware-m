/*
 * Copyright (C) 2026, STMicroelectronics
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef INCLUDE_MEMORY_REGION_H_
#define INCLUDE_MEMORY_REGION_H_

/**
 * @file
 * @brief Devicetree helper macros for the @p memory_region property.
 *
 * These macros provide convenience accessors for nodes having a
 * phandle-array-like @p memory_region property referencing memory region
 * nodes. They follow the same usage model as other devicetree helper
 * macros:
 *
 * - query whether the property exists
 * - query the number of referenced regions
 * - access a referenced region by index or by name
 * - retrieve the referenced region address and size
 * - provide fallback values when an entry does not exist
 * - iterate over all property elements
 *
 * Instance-based variants are also provided through @c DT_DRV_INST(inst).
 */

/**
 * @brief Get the number of entries in a node's @p memory_region property.
 *
 * This expands to the number of phandle entries in @p memory_region if the
 * property exists, and to @c 0 otherwise.
 *
 * @param node_id node identifier
 * @return Number of entries in @p memory_region
 */
#define DT_NUM_MEMORY_REGION(node_id) \
	DT_PROP_LEN_OR(node_id, memory_region, 0)

/**
 * @brief Test whether a node has a @p memory_region property.
 *
 * @param node_id node identifier
 * @return 1 if the property exists, 0 otherwise
 */
#define DT_MEMORY_REGION_HAS(node_id) \
	DT_NODE_HAS_PROP(node_id, memory_region)

/**
 * @brief Test whether @p memory_region contains an entry at index @p idx.
 *
 * @param node_id node identifier
 * @param idx logical index in the @p memory_region property
 * @return 1 if the index exists, 0 otherwise
 */
#define DT_MEMORY_REGION_HAS_IDX(node_id, idx) \
	DT_PROP_HAS_IDX(node_id, memory_region, idx)

/**
 * @brief Test whether @p memory_region contains an entry named @p name.
 *
 * This requires the node to define matching names for the property entries,
 * typically via a corresponding property such as @p memory_region-names.
 *
 * @param node_id node identifier
 * @param name lowercase-and-underscores name token for the entry
 * @return 1 if the named entry exists, 0 otherwise
 */
#define DT_MEMORY_REGION_HAS_NAME(node_id, name) \
	DT_PROP_HAS_NAME(node_id, memory_region, name)

/**
 * @brief Get the referenced memory region node at index @p idx.
 *
 * @param node_id node identifier
 * @param idx logical index in the @p memory_region property
 * @return node identifier for the referenced memory region
 */
#define DT_MEMORY_REGION_BY_IDX(node_id, idx) \
	DT_PHANDLE_BY_IDX(node_id, memory_region, idx)

/**
 * @brief Get the referenced memory region node named @p name.
 *
 * @param node_id node identifier
 * @param name lowercase-and-underscores name token for the entry
 * @return node identifier for the referenced memory region
 */
#define DT_MEMORY_REGION_BY_NAME(node_id, name) \
	DT_PHANDLE_BY_NAME(node_id, memory_region, name)

/**
 * @brief Get the address of the referenced memory region at index @p idx.
 *
 * This expands to the first register address of the referenced region node.
 *
 * @param node_id node identifier
 * @param idx logical index in the @p memory_region property
 * @return Address of the referenced memory region
 */
#define DT_MEMORY_REGION_ADDR_BY_IDX(node_id, idx) \
	DT_REG_ADDR(DT_MEMORY_REGION_BY_IDX(node_id, idx))

/**
 * @brief Get the address of the first referenced memory region.
 *
 * Equivalent to:
 * @code
 * DT_MEMORY_REGION_ADDR_BY_IDX(node_id, 0)
 * @endcode
 *
 * @param node_id node identifier
 * @return Address of the first referenced memory region
 */
#define DT_MEMORY_REGION_ADDR(node_id) \
	DT_MEMORY_REGION_ADDR_BY_IDX(node_id, 0)

/**
 * @brief Get the size of the referenced memory region at index @p idx.
 *
 * This expands to the first register size of the referenced region node.
 *
 * @param node_id node identifier
 * @param idx logical index in the @p memory_region property
 * @return Size of the referenced memory region
 */
#define DT_MEMORY_REGION_SIZE_BY_IDX(node_id, idx) \
	DT_REG_SIZE(DT_MEMORY_REGION_BY_IDX(node_id, idx))

/**
 * @brief Get the size of the first referenced memory region.
 *
 * Equivalent to:
 * @code
 * DT_MEMORY_REGION_SIZE_BY_IDX(node_id, 0)
 * @endcode
 *
 * @param node_id node identifier
 * @return Size of the first referenced memory region
 */
#define DT_MEMORY_REGION_SIZE(node_id) \
	DT_MEMORY_REGION_SIZE_BY_IDX(node_id, 0)

/**
 * @brief Get the address of the referenced memory region named @p name.
 *
 * @param node_id node identifier
 * @param name lowercase-and-underscores name token for the entry
 * @return Address of the referenced memory region
 */
#define DT_MEMORY_REGION_ADDR_BY_NAME(node_id, name) \
	DT_REG_ADDR(DT_MEMORY_REGION_BY_NAME(node_id, name))

/**
 * @brief Get the size of the referenced memory region named @p name.
 *
 * @param node_id node identifier
 * @param name lowercase-and-underscores name token for the entry
 * @return Size of the referenced memory region
 */
#define DT_MEMORY_REGION_SIZE_BY_NAME(node_id, name) \
	DT_REG_SIZE(DT_MEMORY_REGION_BY_NAME(node_id, name))

/**
 * @brief Get the address of the referenced memory region at index @p idx,
 *        or return a fallback value.
 *
 * @param node_id node identifier
 * @param idx logical index in the @p memory_region property
 * @param default_value value to expand to when the index does not exist
 * @return Address of the referenced memory region, or @p default_value
 */
#define DT_MEMORY_REGION_ADDR_BY_IDX_OR(node_id, idx, default_value)	\
	COND_CODE_1(DT_MEMORY_REGION_HAS_IDX(node_id, idx),		\
		    (DT_MEMORY_REGION_ADDR_BY_IDX(node_id, idx)),	\
		    (default_value))

/**
 * @brief Get the address of the first referenced memory region,
 *        or return a fallback value.
 *
 * Equivalent to:
 * @code
 * DT_MEMORY_REGION_ADDR_BY_IDX_OR(node_id, 0, default_value)
 * @endcode
 *
 * @param node_id node identifier
 * @param default_value value to expand to when the first entry does not exist
 * @return Address of the first referenced memory region, or @p default_value
 */
#define DT_MEMORY_REGION_ADDR_OR(node_id, default_value) \
	DT_MEMORY_REGION_ADDR_BY_IDX_OR(node_id, 0, default_value)

/**
 * @brief Get the size of the referenced memory region at index @p idx,
 *        or return a fallback value.
 *
 * @param node_id node identifier
 * @param idx logical index in the @p memory_region property
 * @param default_value value to expand to when the index does not exist
 * @return Size of the referenced memory region, or @p default_value
 */
#define DT_MEMORY_REGION_SIZE_BY_IDX_OR(node_id, idx, default_value)	\
	COND_CODE_1(DT_MEMORY_REGION_HAS_IDX(node_id, idx),		\
		    (DT_MEMORY_REGION_SIZE_BY_IDX(node_id, idx)),	\
		    (default_value))

/**
 * @brief Get the size of the first referenced memory region,
 *        or return a fallback value.
 *
 * Equivalent to:
 * @code
 * DT_MEMORY_REGION_SIZE_BY_IDX_OR(node_id, 0, default_value)
 * @endcode
 *
 * @param node_id node identifier
 * @param default_value value to expand to when the first entry does not exist
 * @return Size of the first referenced memory region, or @p default_value
 */
#define DT_MEMORY_REGION_SIZE_OR(node_id, default_value) \
	DT_MEMORY_REGION_SIZE_BY_IDX_OR(node_id, 0, default_value)

/**
 * @brief Get the address of the referenced memory region named @p name,
 *        or return a fallback value.
 *
 * @param node_id node identifier
 * @param name lowercase-and-underscores name token for the entry
 * @param default_value value to expand to when the named entry does not exist
 * @return Address of the named referenced memory region, or @p default_value
 */
#define DT_MEMORY_REGION_ADDR_BY_NAME_OR(node_id, name, default_value)	\
	COND_CODE_1(DT_MEMORY_REGION_HAS_NAME(node_id, name),		\
		    (DT_MEMORY_REGION_ADDR_BY_NAME(node_id, name)),	\
		    (default_value))

/**
 * @brief Get the size of the referenced memory region named @p name,
 *        or return a fallback value.
 *
 * @param node_id node identifier
 * @param name lowercase-and-underscores name token for the entry
 * @param default_value value to expand to when the named entry does not exist
 * @return Size of the named referenced memory region, or @p default_value
 */
#define DT_MEMORY_REGION_SIZE_BY_NAME_OR(node_id, name, default_value)	\
	COND_CODE_1(DT_MEMORY_REGION_HAS_NAME(node_id, name),		\
		    (DT_MEMORY_REGION_SIZE_BY_NAME(node_id, name)),	\
		    (default_value))

/**
 * @brief Instance equivalent of @ref DT_NUM_MEMORY_REGION().
 *
 * @param inst instance number
 * @return Number of entries in the instance @p memory_region property
 */
#define DT_INST_NUM_MEMORY_REGION(inst) \
	DT_NUM_MEMORY_REGION(DT_DRV_INST(inst))

/**
 * @brief Instance equivalent of @ref DT_MEMORY_REGION_HAS().
 *
 * @param inst instance number
 * @return 1 if the property exists, 0 otherwise
 */
#define DT_INST_MEMORY_REGION_HAS(inst) \
	DT_MEMORY_REGION_HAS(DT_DRV_INST(inst))

/**
 * @brief Instance equivalent of @ref DT_MEMORY_REGION_HAS_IDX().
 *
 * @param inst instance number
 * @param idx logical index in the @p memory_region property
 * @return 1 if the index exists, 0 otherwise
 */
#define DT_INST_MEMORY_REGION_HAS_IDX(inst, idx) \
	DT_MEMORY_REGION_HAS_IDX(DT_DRV_INST(inst), idx)

/**
 * @brief Instance equivalent of @ref DT_MEMORY_REGION_HAS_NAME().
 *
 * @param inst instance number
 * @param name lowercase-and-underscores name token for the entry
 * @return 1 if the named entry exists, 0 otherwise
 */
#define DT_INST_MEMORY_REGION_HAS_NAME(inst, name) \
	DT_MEMORY_REGION_HAS_NAME(DT_DRV_INST(inst), name)

/**
 * @brief Instance equivalent of @ref DT_MEMORY_REGION_BY_IDX().
 *
 * @param inst instance number
 * @param idx logical index in the @p memory_region property
 * @return node identifier for the referenced memory region
 */
#define DT_INST_MEMORY_REGION_BY_IDX(inst, idx) \
	DT_MEMORY_REGION_BY_IDX(DT_DRV_INST(inst), idx)

/**
 * @brief Instance equivalent of @ref DT_MEMORY_REGION_BY_NAME().
 *
 * @param inst instance number
 * @param name lowercase-and-underscores name token for the entry
 * @return node identifier for the referenced memory region
 */
#define DT_INST_MEMORY_REGION_BY_NAME(inst, name) \
	DT_MEMORY_REGION_BY_NAME(DT_DRV_INST(inst), name)

/**
 * @brief Instance equivalent of @ref DT_MEMORY_REGION_ADDR_BY_IDX().
 *
 * @param inst instance number
 * @param idx logical index in the @p memory_region property
 * @return Address of the referenced memory region
 */
#define DT_INST_MEMORY_REGION_ADDR_BY_IDX(inst, idx) \
	DT_MEMORY_REGION_ADDR_BY_IDX(DT_DRV_INST(inst), idx)

/**
 * @brief Instance equivalent of @ref DT_MEMORY_REGION_ADDR().
 *
 * @param inst instance number
 * @return Address of the first referenced memory region
 */
#define DT_INST_MEMORY_REGION_ADDR(inst) \
	DT_MEMORY_REGION_ADDR(DT_DRV_INST(inst))

/**
 * @brief Instance equivalent of @ref DT_MEMORY_REGION_SIZE_BY_IDX().
 *
 * @param inst instance number
 * @param idx logical index in the @p memory_region property
 * @return Size of the referenced memory region
 */
#define DT_INST_MEMORY_REGION_SIZE_BY_IDX(inst, idx) \
	DT_MEMORY_REGION_SIZE_BY_IDX(DT_DRV_INST(inst), idx)

/**
 * @brief Instance equivalent of @ref DT_MEMORY_REGION_SIZE().
 *
 * @param inst instance number
 * @return Size of the first referenced memory region
 */
#define DT_INST_MEMORY_REGION_SIZE(inst) \
	DT_MEMORY_REGION_SIZE(DT_DRV_INST(inst))

/**
 * @brief Instance equivalent of @ref DT_MEMORY_REGION_ADDR_BY_NAME().
 *
 * @param inst instance number
 * @param name lowercase-and-underscores name token for the entry
 * @return Address of the referenced memory region
 */
#define DT_INST_MEMORY_REGION_ADDR_BY_NAME(inst, name) \
	DT_MEMORY_REGION_ADDR_BY_NAME(DT_DRV_INST(inst), name)

/**
 * @brief Instance equivalent of @ref DT_MEMORY_REGION_SIZE_BY_NAME().
 *
 * @param inst instance number
 * @param name lowercase-and-underscores name token for the entry
 * @return Size of the referenced memory region
 */
#define DT_INST_MEMORY_REGION_SIZE_BY_NAME(inst, name) \
	DT_MEMORY_REGION_SIZE_BY_NAME(DT_DRV_INST(inst), name)

/**
 * @brief Instance equivalent of @ref DT_MEMORY_REGION_ADDR_BY_IDX_OR().
 *
 * @param inst instance number
 * @param idx logical index in the @p memory_region property
 * @param default_value value to expand to when the index does not exist
 * @return Address of the referenced memory region, or @p default_value
 */
#define DT_INST_MEMORY_REGION_ADDR_BY_IDX_OR(inst, idx, default_value) \
	DT_MEMORY_REGION_ADDR_BY_IDX_OR(DT_DRV_INST(inst), idx, default_value)

/**
 * @brief Instance equivalent of @ref DT_MEMORY_REGION_ADDR_OR().
 *
 * @param inst instance number
 * @param default_value value to expand to when the first entry does not exist
 * @return Address of the first referenced memory region, or @p default_value
 */
#define DT_INST_MEMORY_REGION_ADDR_OR(inst, default_value) \
	DT_INST_MEMORY_REGION_ADDR_BY_IDX_OR(inst, 0, default_value)

/**
 * @brief Instance equivalent of @ref DT_MEMORY_REGION_SIZE_BY_IDX_OR().
 *
 * @param inst instance number
 * @param idx logical index in the @p memory_region property
 * @param default_value value to expand to when the index does not exist
 * @return Size of the referenced memory region, or @p default_value
 */
#define DT_INST_MEMORY_REGION_SIZE_BY_IDX_OR(inst, idx, default_value) \
	DT_MEMORY_REGION_SIZE_BY_IDX_OR(DT_DRV_INST(inst), idx, default_value)

/**
 * @brief Instance equivalent of @ref DT_MEMORY_REGION_SIZE_OR().
 *
 * @param inst instance number
 * @param default_value value to expand to when the first entry does not exist
 * @return Size of the first referenced memory region, or @p default_value
 */
#define DT_INST_MEMORY_REGION_SIZE_OR(inst, default_value) \
	DT_INST_MEMORY_REGION_SIZE_BY_IDX_OR(inst, 0, default_value)

/**
 * @brief Instance equivalent of @ref DT_MEMORY_REGION_ADDR_BY_NAME_OR().
 *
 * @param inst instance number
 * @param name lowercase-and-underscores name token for the entry
 * @param default_value value to expand to when the named entry does not exist
 * @return Address of the named referenced memory region, or @p default_value
 */
#define DT_INST_MEMORY_REGION_ADDR_BY_NAME_OR(inst, name, default_value) \
	DT_MEMORY_REGION_ADDR_BY_NAME_OR(DT_DRV_INST(inst), name, default_value)

/**
 * @brief Instance equivalent of @ref DT_MEMORY_REGION_SIZE_BY_NAME_OR().
 *
 * @param inst instance number
 * @param name lowercase-and-underscores name token for the entry
 * @param default_value value to expand to when the named entry does not exist
 * @return Size of the named referenced memory region, or @p default_value
 */
#define DT_INST_MEMORY_REGION_SIZE_BY_NAME_OR(inst, name, default_value) \
	DT_MEMORY_REGION_SIZE_BY_NAME_OR(DT_DRV_INST(inst), name, default_value)

/**
 * @brief Invoke @p fn for each element in a node's @p memory_region property.
 *
 * This is a convenience wrapper around @ref DT_FOREACH_PROP_ELEM().
 *
 * @param node_id node identifier
 * @param fn macro to invoke for each property element
 */
#define DT_FOREACH_MEMORY_REGION(node_id, fn) \
	DT_FOREACH_PROP_ELEM(node_id, memory_region, fn)

/**
 * @brief Invoke @p fn for each element in a node's @p memory_region property,
 *        inserting @p sep between expansions.
 *
 * This is a convenience wrapper around @ref DT_FOREACH_PROP_ELEM_SEP().
 *
 * @param node_id node identifier
 * @param fn macro to invoke for each property element
 * @param sep separator inserted between expansions
 */
#define DT_FOREACH_MEMORY_REGION_SEP(node_id, fn, sep) \
	DT_FOREACH_PROP_ELEM_SEP(node_id, memory_region, fn, sep)

/**
 * @brief Invoke @p fn for each element in a node's @p memory_region property,
 *        passing additional variadic arguments.
 *
 * This is a convenience wrapper around @ref DT_FOREACH_PROP_ELEM_VARGS().
 *
 * @param node_id node identifier
 * @param fn macro to invoke for each property element
 * @param ... additional arguments forwarded to @p fn
 */
#define DT_FOREACH_MEMORY_REGION_VARGS(node_id, fn, ...) \
	DT_FOREACH_PROP_ELEM_VARGS(node_id, memory_region, fn, __VA_ARGS__)

/**
 * @brief Invoke @p fn for each element in a node's @p memory_region property,
 *        passing additional variadic arguments and inserting @p sep between
 *        expansions.
 *
 * This is a convenience wrapper around
 * @ref DT_FOREACH_PROP_ELEM_SEP_VARGS().
 *
 * @param node_id node identifier
 * @param fn macro to invoke for each property element
 * @param sep separator inserted between expansions
 * @param ... additional arguments forwarded to @p fn
 */
#define DT_FOREACH_MEMORY_REGION_SEP_VARGS(node_id, fn, sep, ...) \
	DT_FOREACH_PROP_ELEM_SEP_VARGS(node_id, memory_region, fn, sep, __VA_ARGS__)

/** @cond INTERNAL_HIDDEN */
#define Z_MEMORY_REGION_STATUS_OKAY_FN(node_id, prop, idx, fn)			\
	COND_CODE_1(DT_NODE_HAS_STATUS_OKAY(					\
			    DT_MEMORY_REGION_BY_IDX(node_id, idx)),		\
		    (fn(node_id, prop, idx)),					\
		    ())

#define Z_MEMORY_REGION_STATUS_OKAY_FN_VARGS(node_id, prop, idx, fn, ...)	\
	COND_CODE_1(DT_NODE_HAS_STATUS_OKAY(					\
			    DT_MEMORY_REGION_BY_IDX(node_id, idx)),		\
		    (fn(node_id, prop, idx, __VA_ARGS__)),			\
		    ())

/*
 * Separator handling cannot rely on DT_FOREACH_PROP_ELEM_SEP(): a skipped
 * entry expands to nothing but the separator is still emitted, which would
 * leave stray separators behind. Instead each entry is bracketed into a single
 * element of a comma separated list, so that a skipped one becomes an empty
 * element that LIST_DROP_EMPTY() removes. The surviving elements are then
 * unbracketed and joined by FOR_EACH() using the requested separator.
 *
 * Bracketing also protects the commas an entry may expand to, an array
 * initializer being the typical case.
 */
#define Z_MEMORY_REGION_DEBRACKET(...) __VA_ARGS__

#define Z_MEMORY_REGION_UNBRACKET(element)					\
	COND_CODE_1(IS_EMPTY(element), (), (Z_MEMORY_REGION_DEBRACKET element))

#define Z_MEMORY_REGION_STATUS_OKAY_ELEM(node_id, prop, idx, fn)		\
	COND_CODE_1(DT_NODE_HAS_STATUS_OKAY(					\
			    DT_MEMORY_REGION_BY_IDX(node_id, idx)),		\
		    ((fn(node_id, prop, idx))),					\
		    ())

#define Z_MEMORY_REGION_STATUS_OKAY_ELEM_VARGS(node_id, prop, idx, fn, ...)	\
	COND_CODE_1(DT_NODE_HAS_STATUS_OKAY(					\
			    DT_MEMORY_REGION_BY_IDX(node_id, idx)),		\
		    ((fn(node_id, prop, idx, __VA_ARGS__))),			\
		    ())
/** @endcond */

/**
 * @brief Invoke @p fn for each element in a node's @p memory_region property
 *        referencing a node with status @p okay.
 *
 * Entries referencing a disabled node are skipped, so @p fn is invoked with
 * the same @c (node_id, prop, idx) arguments as
 * @ref DT_FOREACH_MEMORY_REGION() but only for the enabled ones. Note that
 * @p idx remains the index in the property, hence the sequence of indexes
 * passed to @p fn may have holes.
 *
 * When a separator is needed, use
 * @ref DT_FOREACH_MEMORY_REGION_STATUS_OKAY_SEP(): here @p fn has to emit its
 * own trailing token, for instance a comma when building an array
 * initializer.
 *
 * As for @ref DT_FOREACH_MEMORY_REGION(), the property must exist. Use
 * @ref DT_MEMORY_REGION_HAS() to guard the call when it may be absent.
 *
 * @param node_id node identifier
 * @param fn macro to invoke for each enabled property element
 */
#define DT_FOREACH_MEMORY_REGION_STATUS_OKAY(node_id, fn)			\
	DT_FOREACH_PROP_ELEM_VARGS(node_id, memory_region,			\
				   Z_MEMORY_REGION_STATUS_OKAY_FN, fn)

/**
 * @brief Invoke @p fn for each element in a node's @p memory_region property
 *        referencing a node with status @p okay, passing additional variadic
 *        arguments.
 *
 * See @ref DT_FOREACH_MEMORY_REGION_STATUS_OKAY() for the filtering details.
 *
 * @param node_id node identifier
 * @param fn macro to invoke for each enabled property element
 * @param ... additional arguments forwarded to @p fn
 */
#define DT_FOREACH_MEMORY_REGION_STATUS_OKAY_VARGS(node_id, fn, ...)		\
	DT_FOREACH_PROP_ELEM_VARGS(node_id, memory_region,			\
				   Z_MEMORY_REGION_STATUS_OKAY_FN_VARGS,	\
				   fn, __VA_ARGS__)

/**
 * @brief Invoke @p fn for each element in a node's @p memory_region property
 *        referencing a node with status @p okay, inserting @p sep between
 *        expansions.
 *
 * Unlike @ref DT_FOREACH_MEMORY_REGION_SEP(), @p sep is only emitted between
 * two enabled entries: skipped ones leave no stray separator, whether they sit
 * at the beginning, in the middle or at the end of the property. The whole
 * expansion is empty when no entry is enabled.
 *
 * As for @ref DT_FOREACH_MEMORY_REGION_SEP(), @p sep must be parenthesized so
 * that a comma can be used, and the property must exist. Use
 * @ref DT_MEMORY_REGION_HAS() to guard the call when it may be absent.
 *
 * @param node_id node identifier
 * @param fn macro to invoke for each enabled property element
 * @param sep parenthesized separator inserted between expansions
 */
#define DT_FOREACH_MEMORY_REGION_STATUS_OKAY_SEP(node_id, fn, sep)		\
	FOR_EACH(Z_MEMORY_REGION_UNBRACKET, sep,				\
		 LIST_DROP_EMPTY(DT_FOREACH_PROP_ELEM_SEP_VARGS(		\
			 node_id, memory_region,				\
			 Z_MEMORY_REGION_STATUS_OKAY_ELEM, (,), fn)))

/**
 * @brief Invoke @p fn for each element in a node's @p memory_region property
 *        referencing a node with status @p okay, passing additional variadic
 *        arguments and inserting @p sep between expansions.
 *
 * See @ref DT_FOREACH_MEMORY_REGION_STATUS_OKAY_SEP() for the filtering and
 * separator details.
 *
 * @param node_id node identifier
 * @param fn macro to invoke for each enabled property element
 * @param sep parenthesized separator inserted between expansions
 * @param ... additional arguments forwarded to @p fn
 */
#define DT_FOREACH_MEMORY_REGION_STATUS_OKAY_SEP_VARGS(node_id, fn, sep, ...)	\
	FOR_EACH(Z_MEMORY_REGION_UNBRACKET, sep,				\
		 LIST_DROP_EMPTY(DT_FOREACH_PROP_ELEM_SEP_VARGS(		\
			 node_id, memory_region,				\
			 Z_MEMORY_REGION_STATUS_OKAY_ELEM_VARGS, (,),		\
			 fn, __VA_ARGS__)))

/**
 * @brief Instance equivalent of @ref DT_FOREACH_MEMORY_REGION().
 *
 * @param inst instance number
 * @param fn macro to invoke for each property element
 */
#define DT_INST_FOREACH_MEMORY_REGION(inst, fn) \
	DT_FOREACH_MEMORY_REGION(DT_DRV_INST(inst), fn)

/**
 * @brief Instance equivalent of @ref DT_FOREACH_MEMORY_REGION_SEP().
 *
 * @param inst instance number
 * @param fn macro to invoke for each property element
 * @param sep separator inserted between expansions
 */
#define DT_INST_FOREACH_MEMORY_REGION_SEP(inst, fn, sep) \
	DT_FOREACH_MEMORY_REGION_SEP(DT_DRV_INST(inst), fn, sep)

/**
 * @brief Instance equivalent of @ref DT_FOREACH_MEMORY_REGION_VARGS().
 *
 * @param inst instance number
 * @param fn macro to invoke for each property element
 * @param ... additional arguments forwarded to @p fn
 */
#define DT_INST_FOREACH_MEMORY_REGION_VARGS(inst, fn, ...) \
	DT_FOREACH_MEMORY_REGION_VARGS(DT_DRV_INST(inst), fn, __VA_ARGS__)

/**
 * @brief Instance equivalent of @ref DT_FOREACH_MEMORY_REGION_SEP_VARGS().
 *
 * @param inst instance number
 * @param fn macro to invoke for each property element
 * @param sep separator inserted between expansions
 * @param ... additional arguments forwarded to @p fn
 */
#define DT_INST_FOREACH_MEMORY_REGION_SEP_VARGS(inst, fn, sep, ...) \
	DT_FOREACH_MEMORY_REGION_SEP_VARGS(DT_DRV_INST(inst), fn, sep, __VA_ARGS__)

/**
 * @brief Instance equivalent of @ref DT_FOREACH_MEMORY_REGION_STATUS_OKAY().
 *
 * @param inst instance number
 * @param fn macro to invoke for each enabled property element
 */
#define DT_INST_FOREACH_MEMORY_REGION_STATUS_OKAY(inst, fn) \
	DT_FOREACH_MEMORY_REGION_STATUS_OKAY(DT_DRV_INST(inst), fn)

/**
 * @brief Instance equivalent of
 *        @ref DT_FOREACH_MEMORY_REGION_STATUS_OKAY_VARGS().
 *
 * @param inst instance number
 * @param fn macro to invoke for each enabled property element
 * @param ... additional arguments forwarded to @p fn
 */
#define DT_INST_FOREACH_MEMORY_REGION_STATUS_OKAY_VARGS(inst, fn, ...) \
	DT_FOREACH_MEMORY_REGION_STATUS_OKAY_VARGS(DT_DRV_INST(inst), fn, __VA_ARGS__)

/**
 * @brief Instance equivalent of
 *        @ref DT_FOREACH_MEMORY_REGION_STATUS_OKAY_SEP().
 *
 * @param inst instance number
 * @param fn macro to invoke for each enabled property element
 * @param sep parenthesized separator inserted between expansions
 */
#define DT_INST_FOREACH_MEMORY_REGION_STATUS_OKAY_SEP(inst, fn, sep) \
	DT_FOREACH_MEMORY_REGION_STATUS_OKAY_SEP(DT_DRV_INST(inst), fn, sep)

/**
 * @brief Instance equivalent of
 *        @ref DT_FOREACH_MEMORY_REGION_STATUS_OKAY_SEP_VARGS().
 *
 * @param inst instance number
 * @param fn macro to invoke for each enabled property element
 * @param sep parenthesized separator inserted between expansions
 * @param ... additional arguments forwarded to @p fn
 */
#define DT_INST_FOREACH_MEMORY_REGION_STATUS_OKAY_SEP_VARGS(inst, fn, sep, ...)	\
	DT_FOREACH_MEMORY_REGION_STATUS_OKAY_SEP_VARGS(DT_DRV_INST(inst), fn,	\
						       sep, __VA_ARGS__)

#endif /* INCLUDE_MEMORY_REGION_H_ */
