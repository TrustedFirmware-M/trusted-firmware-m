/*
 * Copyright (c) 2026, STMicroelectronics - All Rights Reserved
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef INCLUDE_DEVICETREE_NVMEM_H_
#define INCLUDE_DEVICETREE_NVMEM_H_

#ifdef __cplusplus
extern "C" {
#endif

struct nvmem_dt_spec {
	/** NVMEM device controller */
	const struct device *dev;
	/** Name of the NVMEM cell */
	const char *name;
};

/**
 * @defgroup devicetree-nvmem Devicetree NVMEM API
 * @ingroup devicetree
 * @{
 */

/**
 * @brief Get the node identifier for the NVMEM controller from a nvmem-cell
 *	  property by name
 *
 * Example devicetree fragment:
 *
 *     nvmem1: efuse@... {
 *		otp1: otp1@1c0 {
 *			reg = <0x1c0 0x4>;
 *		};
 *		otp2: otp2@1c4 {
 *			reg = <0x1c4 0x8>;
 *		};
 *     };
 *
 *     n: node {
 *             nvmem-cells = <&otp1>, <&otp2>;
 *             nvmem-cell-names = "key1", "key2";
 *     };
 *
 * Example usage:
 *
 *     DT_NVMEM_CTLR_BY_NAME(DT_NODELABEL(n), key1) // DT_NODELABEL(otp1)
 *
 * @param node_id node identifier for a node with a nvmem-cells property
 * @param name lowercase-and-underscores name of a nvmem-cells element
 *             as defined by the node's nvmem-cell-names property
 *
 * @return the node identifier for the NVMEM controller in the named element
 *
 * @see DT_PHANDLE_BY_NAME()
 */
#define DT_NVMEM_CTLR_BY_NAME(node_id, name) \
	DT_PHANDLE_BY_NAME(node_id, nvmem_cells, name)

/**
 * @brief Get a nvmem device from a nvmem-cell
 *	  property by name
 *
 * Example devicetree fragment:
 *
 *     nvmem1: efuse@... {
 *		otp1: otp1@1c0 {
 *			reg = <0x1c0 0x4>;
 *		};
 *		otp2: otp2@1c4 {
 *			reg = <0x1c4 0x8>;
 *		};
 *     };
 *
 *     n: node {
 *             nvmem-cells = <&otp1>, <&otp2>;
 *             nvmem-cell-names = "key1", "key2";
 *     };
 *
 * Example usage:
 *
 *     DT_DEV_NVMEM(DT_NODELABEL(n), key1) // DT_NODELABEL(otp1)
 *
 * @param node_id node identifier for a node with a nvmem-cells property
 * @param name lowercase-and-underscores name of a nvmem-cells element
 *             as defined by the node's nvmem-cell-names property
 *
 * @return reference on regulator device or 0 if optional
 */
#define DT_DEV_NVMEM(node_id, name)						\
	COND_CODE_1(DT_PROP_HAS_NAME(node_id, nvmem_cells, name),		\
		    (DEVICE_DT_GET(DT_NVMEM_CTLR_BY_NAME(node_id, name))),	\
		    (0))
/**
 * @brief Get a DT_DRV_COMPAT instance's nvmem-cell device from nvmem-cell-names
 *
 * @param inst DT_DRV_COMPAT instance number
 * @param name lowercase-and-underscores name of a nvmem-cells element
 *             as defined by the node's nvmem-cell-names property
 *
 * @return reference on regulator device or 0 if optional
 */
#define DT_INST_DEV_NVMEM(inst, name)						\
	DT_DEV_NVMEM(DT_DRV_INST(inst), name)

/**
 * @brief Get the node identifier for the NVMEM controller from a nvmem-cell
 *	  property by name with the driver instance
 *
 * @param inst instance number
 * @param name lowercase-and-underscores name of a nvmem-cells element
 *             as defined by the node's nvmem-cell-names property
 *
 * @return the node identifier for the NVMEM controller in the named element
 */

#define DT_INST_NVMEM_CTLR_BY_NAME(inst, name) \
	DT_PHANDLE_BY_NAME(DT_DRV_INST(inst), nvmem_cells, name)

/**
 * @brief Get the node identifier for the NVMEM controller from a nvmem-cell
 *	  property by index
 *
 * Example devicetree fragment:
 *
 *     nvmem1: efuse@... {
 *		otp1: otp1@1c0 {
 *			reg = <0x1c0 0x4>;
 *		};
 *		otp2: otp2@1c4 {
 *			reg = <0x1c4 0x8>;
 *		};
 *     };
 *
 *     n: node {
 *             nvmem-cells = <&otp1>, <&otp2>;
 *             nvmem-cell-names = "key1", "key2";
 *     };
 *
 * Example usage:
 *
 *     DT_NVMEM_CTLR_BY_IDX(DT_NODELABEL(n), 1) // DT_NODELABEL(otp2)
 *
 * @param node_id node identifier for a node with a nvmem-cells property
 * @param idx logical index into nvmem-cells property
 *
 * * @return the node identifier for the NVMEM controller in the indexed element
 *
 * @see DT_PHANDLE_BY_IDX()
 */

#define DT_NVMEM_CTLR_BY_IDX(node_id, idx) \
	DT_PHANDLE_BY_IDX(node_id, nvmem_cells, idx)

/**
 * @brief Get the node identifier for the NVMEM controller from a nvmem-cell
 *	  property by index with driver instance
 *
 * @param inst instance number
 * @param idx logical index into nvmem-cells property
 *
 * @return the node identifier for the NVMEM controller in the indexed element
 */

#define DT_INST_NVMEM_CTLR_BY_IDX(inst, idx) \
	DT_PHANDLE_BY_IDX(DT_DRV_INST(inst), nvmem_cells, idx)

/**
 * @brief Get the offset for a nvmem-cell property by name
 *
 * Example devicetree fragment:
 *
 *     nvmem1: efuse@... {
 *		otp1: otp1@1c0 {
 *			reg = <0x1c0 0x4>;
 *		};
 *		otp2: otp2@1c4 {
 *			reg = <0x1c4 0x8>;
 *		};
 *     };
 *
 *     n: node {
 *             nvmem-cells = <&otp1>, <&otp2>;
 *             nvmem-cell-names = "key1", "key2";
 *     };
 *
 * Example usage:
 *
 *     DT_NVMEM_OFFSET_BY_NAME(DT_NODELABEL(n), key1) // 0x1c0
 *
 * @param node_id node identifier for a node with a nvmem-cells property
 * @param name lowercase-and-underscores name of a nvmem-cells element
 *             as defined by the node's nvmem-cell-names property
 *
 * @return the nvmem-cell offset
 *
 * @see DT_PHANDLE_BY_NAME(), DT_REG_ADDR()
 */
#define DT_NVMEM_CELL_OFFSET_BY_NAME(node_id, name) \
	DT_REG_ADDR(DT_PHANDLE_BY_NAME(node_id, nvmem_cells, name))

/**
 * @brief Get the offset for a nvmem-cell property by name with driver instance
 *
 * @param inst instance number
 * @param name lowercase-and-underscores name of a nvmem-cells element
 *             as defined by the node's nvmem-cell-names property
 *
 * @return the nvmem-cell offset
 */
#define DT_INST_NVMEM_CELL_OFFSET_BY_NAME(inst, name) \
	DT_REG_ADDR(DT_PHANDLE_BY_NAME(DT_DRV_INST(inst), nvmem_cells, name))

/**
 * @brief Get the offset for a nvmem-cell property by index
 *
 * Example devicetree fragment:
 *
 *     nvmem1: efuse@... {
 *		otp1: otp1@1c0 {
 *			reg = <0x1c0 0x4>;
 *		};
 *		otp2: otp2@1c4 {
 *			reg = <0x1c4 0x8>;
 *		};
 *     };
 *
 *     n: node {
 *             nvmem-cells = <&otp1>, <&otp2>;
 *             nvmem-cell-names = "key1", "key2";
 *     };
 *
 * Example usage:
 *
 *     DT_NVMEM_OFFSET_BY_IDX(DT_NODELABEL(n), 1) // 0x1c4
 *
 * @param node_id node identifier for a node with a nvmem-cells property
 * @param idx logical index into nvmem-cells property
 *
 * @return the nvmem-cell offset
 *
 * @see DT_PHANDLE_BY_IDX(), DT_REG_ADDR()
 */
#define DT_NVMEM_CELL_OFFSET_BY_IDX(node_id, idx) \
	DT_REG_ADDR(DT_PHANDLE_BY_IDX(node_id, nvmem_cells, idx))

/**
 * @brief Get the offset for a nvmem-cell property by index with driver instance
 *
 * @param inst instance number
 * @param idx logical index into nvmem-cells property
 *
 * @return the nvmem-cell offset
 */
#define DT_INST_NVMEM_CELL_OFFSET_BY_IDX(inst, idx) \
	DT_REG_ADDR(DT_PHANDLE_BY_IDX(DT_DRV_INST(inst), nvmem_cells, idx))

/**
 * @brief Get the size for a nvmem-cell property by name
 *
 * Example devicetree fragment:
 *
 *     nvmem1: efuse@... {
 *		otp1: otp1@1c0 {
 *			reg = <0x1c0 0x4>;
 *		};
 *		otp2: otp2@1c4 {
 *			reg = <0x1c4 0x8>;
 *		};
 *     };
 *
 *     n: node {
 *             nvmem-cells = <&otp1>, <&otp2>;
 *             nvmem-cell-names = "key1", "key2";
 *     };
 *
 * Example usage:
 *
 *     DT_NVMEM_SIZE_BY_NAME(DT_NODELABEL(n), key1) // 0x4
 *
 * @param node_id node identifier for a node with a nvmem-cells property
 * @param name lowercase-and-underscores name of a nvmem-cells element
 *             as defined by the node's nvmem-cell-names property
 *
 * @return the nvmem-cell size
 *
 * @see DT_PHANDLE_BY_NAME(), DT_REG_ADDR()
 */
#define DT_NVMEM_CELL_SIZE_BY_NAME(node_id, name) \
	DT_REG_SIZE(DT_PHANDLE_BY_NAME(node_id, nvmem_cells, name))

/**
 * @brief Get the size for a nvmem-cell property by name with driver instance
 *
 * @param inst instance number
 * @param name lowercase-and-underscores name of a nvmem-cells element
 *             as defined by the node's nvmem-cell-names property
 *
 * @return the nvmem-cell size
 */
#define DT_INST_NVMEM_CELL_SIZE_BY_NAME(inst, name) \
	DT_REG_SIZE(DT_PHANDLE_BY_NAME(DT_DRV_INST(inst), nvmem_cells, name))

/**
 * @brief Get the size for a nvmem-cell property by index
 *
 * Example devicetree fragment:
 *
 *     nvmem1: efuse@... {
 *		otp1: otp1@1c0 {
 *			reg = <0x1c0 0x4>;
 *		};
 *		otp2: otp2@1c4 {
 *			reg = <0x1c4 0x8>;
 *		};
 *     };
 *
 *     n: node {
 *             nvmem-cells = <&otp1>, <&otp2>;
 *             nvmem-cell-names = "key1", "key2";
 *     };
 *
 * Example usage:
 *
 *     DT_NVMEM_SIZE_BY_IDX(DT_NODELABEL(n), 1) // 0x8
 *
 * @param node_id node identifier for a node with a nvmem-cells property
 * @param idx logical index into nvmem-cells property
 *
 * @return the nvmem-cell size
 *
 * @see DT_PHANDLE_BY_IDX(), DT_REG_ADDR()
 */
#define DT_NVMEM_CELL_SIZE_BY_IDX(node_id, idx) \
	DT_REG_SIZE(DT_PHANDLE_BY_IDX(node_id, nvmem_cells, idx))

/**
 * @brief Get the size for a nvmem-cell property by index with driver instance
 *
 * @param inst instance number
 * @param idx logical index into nvmem-cells property
 *
 * @return the nvmem-cell size
 */
#define DT_INST_NVMEM_CELL_SIZE_BY_IDX(inst, idx) \
	DT_REG_SIZE(DT_PHANDLE_BY_IDX(DT_DRV_INST(inst), nvmem_cells, idx))

/**
 * @brief Static initializer for a @p nvmem_dt_spec
 *
 * This returns a static initializer for a @p nvmem_dt_spec structure given a
 * devicetree node identifier, a property specifying a NVMEM driver phandler
 * the name of the nvmem-cell (in nvmem-cell-names).
 *
 * Example devicetree fragment:
 *
 *     nvmem1: efuse@... {
 *		otp1: otp1@1c0 {
 *			reg = <0x1c0 0x4>;
 *		};
 *		otp2: otp2@1c4 {
 *			reg = <0x1c4 0x8>;
 *		};
 *     };
 *
 *     n: node {
 *             nvmem-cells = <&otp1>, <&otp2>;
 *             nvmem-cell-names = "key1", "key2";
 *     };
 *
 * Example usage:
 *
 *	const struct nvmem_dt_spec spec = DT_NVMEM_SPEC_GET_BY_IDX(DT_NODELABEL(n), 1);
 *	// Initializes 'spec' to:
 *	// {
 *	//         .dev = DEVICE_DT_GET(DT_NODELABEL(otp1)),
 *	//         .name = "key1",
 *	// }
 *
 *
 * @param node_id devicetree node identifier
 * @param idx logical index into "nvmem-cells"
 * @return static initializer for a struct nvmem_dt_spec for the property
 */
#define DT_NVMEM_SPEC_GET_BY_IDX(node_id, idx)						\
	{										\
		.dev = DEVICE_DT_GET(DT_NVMEM_CTLR_BY_IDX(node_id, idx)),		\
		.name = DT_STRINGIFY_INTERNAL(DT_STRING_TOKEN_BY_IDX(node_id,		\
								     nvmem_cell_names,	\
								     idx)),		\
	}

/**
 * @brief Static initializer for a @p nvmem_dt_spec by driver instance
 *
 * @param inst instance number
 * @param idx logical index into "nvmem-cells"
 * @return static initializer for a struct nvmem_dt_spec for the property
 */
#define DT_INST_NVMEM_SPEC_GET_BY_IDX(inst, idx)					\
	DT_NVMEM_SPEC_GET_BY_IDX(DT_DRV_INST(inst))
/**
 * @}
 */

#ifdef __cplusplus
}
#endif

#endif  /* INCLUDE_DEVICETREE_NVMEM_H_ */
